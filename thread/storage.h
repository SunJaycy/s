


































































































namespace rw
{
    namespace core
    {
        namespace thread
        {















































            struct RwThreadLocalStorageData
            {
                struct ThreadToDataPair{
                    rw::core::thread::ThreadId mThreadID;
                    const void* mpData;
                };
                ThreadToDataPair* GetTLSEntry(bool bCreateIfNotFound);
                ThreadToDataPair mDataArray[16];
                int mDataArrayCount;
            };










































            class ThreadLocalStorage
            {
            public:
                ThreadLocalStorage();
                ~ThreadLocalStorage();







                void* GetValue();
















                bool SetValue(const void* pData);







                void* GetPlatformData()
                {
                    ;
                    return &mTLSData;
                }

            protected:



                RwThreadLocalStorageData mTLSData;
            };



































        }
    }
}
