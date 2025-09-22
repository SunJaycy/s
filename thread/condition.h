











































namespace rw
{
    namespace core
    {
        namespace thread
        {















            struct RwConditionData
            {
                rw::core::thread::AtomicInt32 mnInitValue;
                bool mbIntraProcess;
                sys_cond_t mCV;
                char mName[16];
                RwConditionData();
            };




































            struct ConditionParameters{
                bool mbIntraProcess;
                char mName[16];

                ConditionParameters(bool bIntraProcess = true, const char* pName = 0);
            };





















            class Condition
            {
            public:









                enum Result
                {
                    kResultOK = 0,
                    kResultError = -1,
                    kResultTimeout = -2
                };












                Condition(const ConditionParameters* pConditionParameters = 0, bool bDefaultParameters = true);







                ~Condition();











                bool Init(const ConditionParameters* pConditionParameters);


































                Result Wait(Mutex* pMutex, const ThreadTime& timeoutAbsolute = kTimeoutNone);









                bool Signal(bool bBroadcast = false);







                void* GetPlatformData()
                {
                    ;
                    return &mConditionData;
                }

            protected:




                RwConditionData mConditionData;




            private:




                Condition(const Condition&)
                {
                    ;
                    return;
                }




                Condition& operator=(const Condition&)
                {
                    ;
                    return *this;
                }
            };

        }
    }
}
