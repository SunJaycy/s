



























namespace rw
{
namespace core
{
namespace thread
{



struct RWReadWriteMutexData
{
    sys_rwlock_t mRWMutex;
    rw::core::thread::AtomicInt32 mnLockCount;
    int mLockType;

    RWReadWriteMutexData();
};





































struct RWMutexParameters
{
    bool mbIntraProcess;
    char mName[16];

    RWMutexParameters(bool bIntraProcess = true, const char* pName = 0);
};














class RWMutex
{
public:









    enum Result{
        kResultError = -1,
        kResultTimeout = -2
    };










    enum LockType{
        kLockTypeNone = 0,
        kLockTypeRead = 1,
        kLockTypeWrite = 2
    };












    RWMutex(const RWMutexParameters* pRWMutexParameters = 0, bool bDefaultParameters = true);







    ~RWMutex();












    bool Init(const RWMutexParameters* pRWMutexParameters);




















    int Lock(LockType lockType, const ThreadTime& timeoutAbsolute = rw::core::thread::kTimeoutNone);









    int Unlock();

















    int GetLockCount(LockType lockType);







    void* GetPlatformData()
    {
        ;
        return &mRWMutexData;
    }

protected:





    RWReadWriteMutexData mRWMutexData;





private:




    RWMutex(const RWMutex&)
    {
        ;
        return;
    }



    RWMutex& operator=(const RWMutex&)
    {
        ;
        return *this;
    }
};








class AutoRWMutex
{
public:
    AutoRWMutex(RWMutex& mutex, RWMutex::LockType lockType)
        : mMutex(mutex)
    {
        ;
        mMutex.Lock(lockType);
        return;
    }

    ~AutoRWMutex()
    {
        ;
        mMutex.Unlock();
        return;
    }

protected:
    RWMutex& mMutex;





    AutoRWMutex(const AutoRWMutex&);




    const AutoRWMutex& operator=(const AutoRWMutex&);
};

}
}
}
