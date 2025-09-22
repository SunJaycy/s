
































#include <rw/core/debug/detail/debugcriticalsection.h>


namespace rw
{
    class IResourceAllocator;

    namespace core
    {

        namespace debug
        {



            enum
            {
                MAXNAMELEN = 32
            };

            extern const char *SYSTEMCHANNEL;
            extern const char *ASSERTFORMAT;

            class Channel;
            class Device;
            class IFormatter;
            class IAssertHandler;












            class PrintOpts
            {
            public:
                PrintOpts() :
                    mDate(false),
                    mTime(false),
                    mFile(false),
                    mLine(false),
                    mName(false),
                    mNewLine(false)
                {
                    ;
                    return;
                }

                bool mDate;
                bool mTime;
                bool mFile;
                bool mLine;
                bool mName;
                bool mNewLine;
            };
























































































































































            class Manager
            {
            public:
                static Manager *CreateInstance(rw::IResourceAllocator *allocator);
                static void DestroyInstance();
                static rw::IResourceAllocator *GetAllocator();
                static bool IsInitialized()
                {
                    ;
                    return rw::core::debug::Manager::sAllocator != 0 && rw::core::debug::Manager::sFormatter != 0;

                }

                static IFormatter *GetFormatter()
                {
                    ;
                    return sFormatter;
                }
            private:
                static rw::IResourceAllocator *sAllocator;
                static IFormatter *sFormatter;
            };











            class IFormatter
            {
            public:
                static void *operator new(size_t);
                static void operator delete(void *);










                virtual bool
                    Format(char *buffer, unsigned int bufLen, Channel *channel,
                           const char *format, va_list args) = 0;


                IFormatter() {}
                virtual ~IFormatter() {}
            };
        }
    }
}
