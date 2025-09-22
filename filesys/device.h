

































namespace rw
{
    namespace core
    {
        namespace filesys
        {

            class Device;
            class Handle;





            enum
            {
                MAX_DEVICE_NAME_LENGTH = 16
            };























            class DeviceDriver
            {
            public:





                explicit DeviceDriver(const char *name);


                virtual ~DeviceDriver()
                {
                    ;
                    return;
                };







                enum SeekWhence
                {
                    FSEEK_BEGIN,
                    FSEEK_CURRENT,
                    FSEEK_END
                };







                virtual bool Init()
                {
                    ;
                    return true;
                }






                virtual void Restore()
                {
                    ;
                    return;
                }























                virtual void * Open(const char *name, unsigned int oflags, Handle **pParentFileHandle) = 0;









                virtual void Close(void * h) = 0;
















                virtual unsigned int Read(void *h, void *buf, unsigned int bufsize,
                    DeviceDriver *ddParent, void * ddFileHandle) = 0;









                virtual unsigned int Write(void *, const void *, unsigned int,
                    DeviceDriver *, void *)
                {
                    ;
                    return 0;
                }
















                virtual uint64_t Seek(void *h, uint64_t offset, int whence,
                    DeviceDriver *ddParent, void *ddFileHandle) = 0;






                virtual uint64_t GetSize(void *h) = 0;









                virtual bool Resize(void *, uint64_t)
                {
                    ;
                    return false;
                }









                virtual uint64_t QueryLocation(void *)
                {
                    ;
                    return 0;
                }











                virtual unsigned int GetMaxReadSize()
                {


                    ;
                    return 0xffffffffu;
                }








                virtual bool Delete(const char *)
                {
                    ;
                    return false;
                }








                virtual bool Move(const char *, const char *)
                {
                    ;
                    return false;
                }













                struct FindData
                {
                    unsigned int mFlags;
                    uint64_t mCreationTime;
                    uint64_t mAccessTime;
                    uint64_t mModificationTime;
                    uint64_t mSize;
                    char mName[FILESYS_MAX_PATH];
                };








                virtual void* FindBegin(const char *, FindData *)
                {
                    ;
                    return 0;
                }







                virtual bool FindNext(void *, FindData *)
                {
                    ;
                    return false;
                }








                virtual bool FindEnd(void *)
                {
                    ;
                    return false;
                }






                virtual bool DirectoryCreate(const char *)
                {
                    ;
                    return false;
                }






                virtual bool DirectoryRemove(const char *)
                {
                    ;
                    return false;
                }








                const char * GetName() const
                {
                    ;
                    return mDeviceName;
                }

            protected:
                char mDeviceName[MAX_DEVICE_NAME_LENGTH];
            };
        }
    }
}
