

















namespace rw
{
    namespace core
    {
        namespace debug
        {
            namespace detail
            {





                const int HOST_CRITICAL_SECTION_SIZE = 32;





                class DebugCriticalSection
                {
                public:
                    DebugCriticalSection() : mValid(false) {}
                    ~DebugCriticalSection() {}






                    void Create();
                    void Destroy();



                    void Enter();
                    void Leave();

                private:

                    int32_t mValid;



                    char mData[HOST_CRITICAL_SECTION_SIZE];
                };
            }
        }
    }
}
