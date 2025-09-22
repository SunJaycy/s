

















#include <rw/core/debug/detail/debugcriticalsection.h>

namespace rw
{
    namespace core
    {
        namespace debug
        {
            class Device;













            class Channel
            {
            public:



                enum
                {
                    MAXDEVICES = 16
                };




                enum
                {
                    FLAG_THREADSAFE = 0x1
                };

                static void *operator new(size_t);
                static void operator delete(void *);

                Channel(const char *name, Device *device = 0, unsigned int flags = 0);
                ~Channel();

                const char *GetName() const;
                const char *GetFileName() const;
                unsigned int GetLine() const;
                void SetInfo(const char *fileName, unsigned int line);
                bool HaveInfo() const;

                const PrintOpts &GetPrintOpts() const;
                void SetPrintOpts(const PrintOpts &opts);

                void Enable();
                void Disable();
                bool IsEnabled() const;

                bool AddDevice(Device *device);
                bool RemoveDevice(const Device *device);


                void Print(const char *format, ...);
                void Vprint(const char *format, va_list args);

                void OutputData(const void *data, unsigned int dataLen);

                void Flush();

                void EnterCritical()
                { mCriticalSection.Enter(); }

                void LeaveCritical()
                { mCriticalSection.Leave(); }

                Device *GetFirstDevice();
                Device *GetNextDevice();

            private:
                unsigned int mDeviceCount;
                unsigned int mIndex;
                bool mEnabled;
                bool mHaveInfo;
                char mName[debug::MAXNAMELEN];

                Device *mDeviceList[MAXDEVICES];

                const char *mFileName;
                unsigned int mLine;

                detail::DebugCriticalSection mCriticalSection;


                PrintOpts mPrintOpts;


                Channel(const Channel& rhs);
                Channel& operator=(const Channel& rhs);
            };
        }
    }
}
