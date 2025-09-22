

















namespace rw
{
    namespace core
    {
        namespace thread
        {



            struct RwMutexData
            {
                sys_mutex_t mMutex;
                int mnLockCount;

                rw::core::thread::ThreadId mThreadId;

                RwMutexData();
            };












































































            struct MutexParameters
            {
                bool mbIntraProcess;
                char mName[16];

                MutexParameters(bool bIntraProcess = true, const char* pName = 0);
            };












            class Mutex
            {
            public:









                enum Result{
                    kResultError = -1,
                    kResultTimeout = -2
                };












                Mutex(const MutexParameters* pMutexParameters = 0, bool bDefaultParameters = true);






                ~Mutex();











                bool Init(const MutexParameters* pMutexParameters);

















                int Lock(const ThreadTime& timeoutAbsolute = rw::core::thread::kTimeoutNone);









                int Unlock();















                int GetLockCount() const;







                void* GetPlatformData()
                {
                    ;
                    return &mMutexData;
                }

            protected:





                RwMutexData mMutexData;




            private:




                Mutex(const Mutex&)
                {
                    ;
                    return;
                }



                Mutex& operator=(const Mutex&)
                {
                    ;
                    return *this;
                }
            };








            class AutoMutex
            {
            public:
                AutoMutex(Mutex& mutex)
                    : mMutex(mutex)
                {
                    ;
                    mMutex.Lock();
                    return;
                }

                ~AutoMutex()
                {
                    ;
                    mMutex.Unlock();
                    return;
                }

            protected:



                Mutex& mMutex;





                AutoMutex(const AutoMutex&);




                const AutoMutex& operator=(const AutoMutex&);
            };

        }
    }
}
