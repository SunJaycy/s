










































namespace rw
{
    namespace core
    {
        namespace thread
        {


























            class SpinLock
            {
            protected:








                AtomicInt32 mAI;




            public:
                SpinLock() : mAI(0)
                {
                    ;
                    return;
                }






                void Lock()
                {
Top:
                    ;



                    if(mAI.SetValueConditional(1, 0))
                        return;





                    while(mAI.GetValue() != 0)
                    {

                        ThreadSleep();







                    }
                    goto Top;
                }







                bool TryLock()
                {
                    ;
                    return mAI.SetValueConditional(1, 0);
                }

                bool IsLocked()
                {
                    ;
                    return mAI.GetValueRaw() != 0;
                }

                void Unlock()
                {
                    ;
                    ;
                    mAI.SetValue(0);
                    return;
                }







                void* GetPlatformData()
                {
                    ;
                    return &mAI;
                }
            };








            class AutoSpinLock
            {
            public:
                AutoSpinLock(SpinLock& spinLock)
                    : mSpinLock(spinLock)
                {
                    ;
                    mSpinLock.Lock();
                    return;
                }

                ~AutoSpinLock()
                {
                    ;
                    mSpinLock.Unlock();
                    return;
                }

            protected:



                SpinLock& mSpinLock;





                AutoSpinLock(const AutoSpinLock&);




                const AutoSpinLock& operator=(const AutoSpinLock&);
            };

        }
    }
}
