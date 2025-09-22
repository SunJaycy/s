



























namespace rw
{
    namespace core
    {
        namespace thread
        {
























            struct RwBarrierData
            {
                sys_cond_t mCV;
                sys_mutex_t mMutex;
                int mnHeight;
                int mnCurrent;
                unsigned int mnCycle;
                bool mbValid;

                RwBarrierData();
            };



































            struct BarrierParameters
            {
                int mHeight;
                bool mbIntraProcess;
                char mName[16];

                BarrierParameters(int height = 0, bool bIntraProcess = true, const char* pName = 0);
            };

























            class Barrier
            {
            public:













                enum Result{
                    kResultPrimary = 0,
                    kResultSecondary = 1,
                    kResultError = -1,
                    kResultTimeout = -2
                };












                Barrier(const BarrierParameters* pBarrierParameters = 0, bool bDefaultParameters = true);










                Barrier(int height);







                ~Barrier();












                bool Init(const BarrierParameters* pBarrierParameters);













                Result Wait(const ThreadTime& timeoutAbsolute = kTimeoutNone);







                void* GetPlatformData()
                {
                    ;
                    return &mBarrierData;
                }

            protected:







                RwBarrierData mBarrierData;




            private:





                Barrier(const Barrier&)
                {
                    ;
                    return;
                }




                Barrier& operator=(const Barrier&)
                {
                    ;
                    return *this;
                }
            };

        }
    }
}
