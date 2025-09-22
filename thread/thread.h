







































namespace rw
{
    namespace core
    {
        namespace thread
        {

























            struct RwThreadDynamicData{
                RwThreadDynamicData();
                ~RwThreadDynamicData();
                void AddRef();
                void Release();

                rw::core::thread::ThreadId mThreadId;
                int mnStatus;
                intptr_t mnReturnValue;
                void* mpStartContext[2];
                bool mbFunctionOrRunnable;
                bool mbAttached;
                void* mpStack;
                void* mpAllocatedStack;
                void* mpBeginThreadUserWrapper;
                rw::core::thread::AtomicInt32 mnRefCount;
                char mName[32];
            };

            struct RwThreadData{
                RwThreadDynamicData* mpData;
            };
































































































            typedef intptr_t (*RunnableFunction)(void* pContext);





            struct IRunnable
            {




                virtual intptr_t Run(void* pContext = 0) = 0;

                virtual ~IRunnable() {}
            };



















































            typedef intptr_t (*RunnableFunctionUserWrapper)(RunnableFunction defaultRunnableFunction, void* pContext);




















































            typedef intptr_t (*RunnableClassUserWrapper)(IRunnable* defaultRunnableClass, void* pContext);















            struct ThreadParameters{
                void* mpStack;
                size_t mnStackSize;
                int mnPriority;
                int mnProcessor;
                bool mbSuspended;
                const char* mpName;

                ThreadParameters();
            };



















            class Thread
            {
            public:









                enum Status{
                    kStatusNone,
                    kStatusRunning,
                    kStatusEnded
                };




                Thread();








                ~Thread();









                static RunnableFunctionUserWrapper GetGlobalRunnableFunctionUserWrapper();










                static void SetGlobalRunnableFunctionUserWrapper(RunnableFunctionUserWrapper pUserWrapper);









                static RunnableClassUserWrapper GetGlobalRunnableClassUserWrapper();










                static void SetGlobalRunnableClassUserWrapper(RunnableClassUserWrapper pUserWrapper);





















                ThreadId Begin(RunnableFunction pFunction, void* pContext = 0, const ThreadParameters* pThreadParameters = 0, RunnableFunctionUserWrapper pUserWrapper = GetGlobalRunnableFunctionUserWrapper());



















                ThreadId Begin(IRunnable* pRunnable, void* pContext = 0, const ThreadParameters* pThreadParameters = 0, RunnableClassUserWrapper pUserWrapper = GetGlobalRunnableClassUserWrapper());
















                Status WaitForEnd(const ThreadTime& timeoutAbsolute = kTimeoutNone, intptr_t* pThreadReturnValue = 0);
















                Status GetStatus(intptr_t* pThreadReturnValue = 0) const;













                ThreadId GetId() const;















                int GetPriority() const;
























                bool SetPriority(int priority);





















                void SetProcessor(int nProcessor);






















                void Wake();







                const char* GetName() const;















                void SetName(const char* pName);













                static void SetDefaultProcessor(int nProcessor) { sDefaultProcessor = nProcessor; };




                static int GetDefaultProcessor() {return sDefaultProcessor;}







                void* GetPlatformData()
                {
                    ;
                    return &mThreadData;
                }

            protected:

                static RunnableFunctionUserWrapper sGlobalRunnableFunctionUserWrapper;
                static RunnableClassUserWrapper sGlobalRunnableClassUserWrapper;
                static int sDefaultProcessor;
                RwThreadData mThreadData;
            };

        }
    }
}
