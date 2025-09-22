

















#include <rw/core/thread/atomicptr.h>







namespace rw
{
    namespace core
    {
        namespace thread
        {


















            struct RwSemaphoreData
            {
                sys_cond_t mCV;
                sys_mutex_t mMutex;
                rw::core::thread::AtomicInt32 mnCount;
                bool mbValid;
                RwSemaphoreData();
            };























































































            struct SemaphoreParameters
            {
                int mInitialCount;
                bool mbIntraProcess;
                char mName[16];

                SemaphoreParameters(int initialCount = 0, bool bIntraProcess = true, const char* pName = 0);
            };















            class Semaphore
            {
            public:








                enum Result{
                    kResultError = -1,
                    kResultTimeout = -2
                };












                Semaphore(const SemaphoreParameters* pSemaphoreParameters = 0, bool bDefaultParameters = true);











                Semaphore(int initialCount);






                ~Semaphore();











                bool Init(const SemaphoreParameters* pSemaphoreParameters);















                int Wait(const ThreadTime& timeoutAbsolute = kTimeoutNone);











                int Post(int count = 1);













                int GetCount() const;







                void* GetPlatformData()
                {
                    ;
                    return &mSemaphoreData;
                }

            protected:




                RwSemaphoreData mSemaphoreData;



            private:




                Semaphore(const Semaphore&)
                {
                    ;
                    return;
                }



                Semaphore& operator=(const Semaphore&)
                {
                    ;
                    return *this;
                }
            };








            class AutoSemaphore
            {
            public:
                AutoSemaphore(Semaphore& semaphore)
                    : mSemaphore(semaphore)
                {
                    ;
                    mSemaphore.Wait();
                    return;
                }

                ~AutoSemaphore()
                {
                    ;
                    mSemaphore.Post(1);
                    return;
                }

            protected:



                Semaphore& mSemaphore;





                AutoSemaphore(const AutoSemaphore&);




                const AutoSemaphore& operator=(const AutoSemaphore&);
            };

        }
    }
}
