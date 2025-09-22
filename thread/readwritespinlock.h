



















namespace rw
{
    namespace core
    {
        namespace thread
        {






















































            class RWSpinLock
            {
            protected:








                enum Value{
                    kValueUnlocked = 0x01000000
                };





                AtomicInt32 mAI;




            public:



                RWSpinLock() : mAI(kValueUnlocked)
                {
                    ;
                    return;
                }










                void ReadLock()
                {
Top:
                    ;



                    if((unsigned)mAI.Decrement() < kValueUnlocked)
                        return;

                    mAI.Increment();
                    while(mAI.GetValueRaw() <= 0)
                    {




                        ThreadSleep();







                    }
                    goto Top;
                }











                bool ReadTryLock()
                {
                    ;
                    const unsigned nNewValue = (unsigned)mAI.Decrement();
                    if(nNewValue < kValueUnlocked)
                        return true;
                    mAI.Increment();
                    return false;
                }







                bool IsReadLocked()
                {
                    ;
                    const unsigned nNewValue = (unsigned)mAI.GetValue();




                    return (nNewValue - 1) < (kValueUnlocked - 1);
                }




                void ReadUnlock()
                {
                    ;
                    ;
                    mAI.Increment();
                    return;
                }










                void WriteLock()
                {
Top:
                    ;
                    if(mAI.Add(-kValueUnlocked) == 0)
                        return;
                    mAI.Add(kValueUnlocked);
                    while(mAI.GetValueRaw() != kValueUnlocked)
                    {




                        ThreadSleep();







                    }
                    goto Top;
                }












                bool WriteTryLock()
                {
                    ;
                    if(mAI.Add(-kValueUnlocked) == 0)
                        return true;
                    mAI.Add(kValueUnlocked);
                    return false;
                }






                bool IsWriteLocked()
                {
                    ;
                    return (unsigned)mAI.GetValueRaw() <= 0;
                }




                void WriteUnlock()
                {
                    ;
                    ;
                    mAI.Add(kValueUnlocked);
                    return;
                }







                void* GetPlatformData()
                {
                    ;
                    return &mAI;
                }
            };








            class AutoRWSpinLock
            {
            public:








                enum LockType
                {
                    kLockTypeRead,
                    kLockTypeWrite
                };

                AutoRWSpinLock(RWSpinLock& spinLock, LockType lockType)
                    : mSpinLock(spinLock), mLockType(lockType)
                {
                    ;
                    if(mLockType == kLockTypeRead)
                        mSpinLock.ReadLock();
                    else
                        mSpinLock.WriteLock();
                    return;
                }

                ~AutoRWSpinLock()
                {
                    ;
                    if(mLockType == kLockTypeRead)
                        mSpinLock.ReadUnlock();
                    else
                        mSpinLock.WriteUnlock();
                    return;
                }

            protected:
                RWSpinLock& mSpinLock;
                LockType mLockType;





                AutoRWSpinLock(const AutoRWSpinLock&);




                const AutoRWSpinLock& operator=(const AutoRWSpinLock&);
            };

        }
    }
}
