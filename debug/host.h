


























namespace rw
{
    namespace core
    {
        namespace debug
        {
            namespace host
            {















                enum HostMode
                {
                    HOST_READONLY = 1,
                    HOST_WRITEONLY = 2,
                    HOST_READWRITE = 4,
                    HOST_APPEND = 8,
                    HOST_CREATE = 16,
                    HOST_TRUNCATE = 32,
                    HOST_BINARY = 64
                };






                int Open(const char *path, unsigned int mode);




                void Close(int handle);







                unsigned int Read(int handle, void *p, unsigned int count);







                unsigned int Write(int handle, const void *p, unsigned int count);

                void PrintDebugString(const char *s);

                void BreakToDebugger();
            }
        }
    }
}
