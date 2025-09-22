

















namespace rw
{
    namespace core
    {
        namespace thread
        {










        struct ThreadPoolParameters{
            unsigned mnMinCount;
            unsigned mnMaxCount;
            unsigned mnInitialCount;
            unsigned mnIdleTimeoutMilliseconds;
            ThreadParameters mDefaultThreadParameters;

            ThreadPoolParameters();


        private:
            ThreadPoolParameters(const ThreadPoolParameters& rhs);
            ThreadPoolParameters& operator=(const ThreadPoolParameters& rhs);
     };










        class ThreadPool
        {
        public:











            enum Default
            {
                kDefaultMinCount = 0,
                kDefaultMaxCount = 4,
                kDefaultInitialCount = 0,
                kDefaultIdleTimeout = 60000
            };











            enum Result
            {
                kResultOK = 0,
                kResultError = -1,
                kResultTimeout = -2,
                kResultDeferred = -3
            };










            enum JobWait
            {
                kJobWaitNone,
                kJobWaitCurrent,
                kJobWaitAll
            };












            ThreadPool(const ThreadPoolParameters* pThreadPoolParameters = 0, bool bDefaultParameters = true);






            ~ThreadPool();











            bool Init(const ThreadPoolParameters* pThreadPoolParameters);














            bool Shutdown(JobWait jobWait = kJobWaitAll, const ThreadTime& timeoutAbsolute = kTimeoutNone);
















            int Begin(IRunnable* pRunnable, void* pContext = 0, Thread** ppThread = 0, bool bEnableDeferred = false);
















            int Begin(RunnableFunction pFunction, void* pContext = 0, Thread** ppThread = 0, bool bEnableDeferred = false);

















            int WaitForJobCompletion(int nJob = -1, JobWait jobWait = kJobWaitAll, const ThreadTime& timeoutAbsolute = kTimeoutNone);








            void Pause(bool bPause);

        protected:




            struct Job{
                int mnJobID;
                IRunnable* mpRunnable;
                RunnableFunction mpFunction;
                void* mpContext;

                Job();
            };
            typedef rw::core::thread::simple_list<Job> JobList;


            struct ThreadInfo{
                bool mbActive;
                volatile bool mbQuit;
                Thread* mpThread;
                ThreadPool* mpThreadPool;
                Job mCurrentJob;

                ThreadInfo();
            };
            typedef rw::core::thread::simple_list<ThreadInfo*> ThreadInfoList;


            static intptr_t ThreadFunction(void* pContext);
            void AdjustThreadCount(unsigned nCount);
            Result QueueJob(const Job& job, Thread** ppThread, bool bEnableDeferred);
            void AddThread(ThreadInfo* pThreadInfo);
            void RemoveThread(ThreadInfo* pThreadInfo);
            void FixThreads();


            bool mbInitialized;
            unsigned mnMinCount;
            unsigned mnMaxCount;






            AtomicInt32 mnCurrentCount;
            AtomicInt32 mnActiveCount;
            unsigned mnIdleTimeoutMilliseconds;
            AtomicInt32 mnPauseCount;
            AtomicInt32 mnLastJobID;
            ThreadParameters mDefaultThreadParameters;
            Condition mThreadCondition;
            Mutex mThreadMutex;
            ThreadInfoList mThreadInfoList;
            JobList mJobList;






        private:
            ThreadPool(const ThreadPool& rhs);
            ThreadPool& operator=(const ThreadPool& rhs);
        };

        }
    }
}
