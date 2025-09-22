































namespace rw
{
    namespace core
    {
        namespace filesys
        {

            class AsyncOp;
            class Handle;
            class Device;




            const int FILESYS_MAX_PATH = 256;









            typedef void (AsyncOpCallback)(AsyncOp *op);

            class AsyncOp : public rw::core::filesys::detail::ListNodeS
            {
            public:




























                AsyncOp();
                ~AsyncOp();

                static void *operator new(size_t size, const char *, unsigned int)
                {
                    ;
                    return Manager::GetAllocator()->Allocate( ResourceDescriptor(size, 4), 0).GetMemoryResource();


                }

                static void *operator new(size_t size)
                {
                    ;
                    return Manager::GetAllocator()->Allocate( ResourceDescriptor(size, 4), 0).GetMemoryResource();


                }

                static void operator delete(void *p)
                {
                    ;
                    return Manager::GetAllocator()->Free(p);
                }









                enum OpStatus
                {
                    OPSTATUS_NEW = -3,
                    OPSTATUS_FAILED = -2,
                    OPSTATUS_CANCELLED = -1,
                    OPSTATUS_PENDING = 0,
                    OPSTATUS_COMPLETE = 1
                };
























                enum OpenFlags
                {
                    FOPEN_READONLY = 0x00,
                    FOPEN_READWRITE = 0x01,
                    FOPEN_CREATE = 0x02,
                    FOPEN_OVERWRITE = 0x04,
                    FOPEN_SEQUENTIAL = 0x08,
                    FOPEN_NOBUFFERING = 0x10,
                    FOPEN_READWHOLEFILE = 0x20
                };

                void Open(
                    const char *FilePath,
                    unsigned int modeflags = FOPEN_READONLY,
                    AsyncOpCallback *OpDoneCallback = 0,
                    void *context = 0,
                    int priority = 0);

                void Close(
                    Handle *FileHandle,
                    AsyncOpCallback *OpDoneCallback = 0,
                    void *context = 0,
                    int priority = 0);

                void Read(
                    Handle *FileHandle,
                    void * buffer,
                    uint64_t offset,
                    uint64_t bytes,
                    AsyncOpCallback *OpDoneCallback = 0,
                    void *context = 0,
                    int priority = 0);

                void Write(
                    Handle *FileHandle,
                    const void *buffer,
                    uint64_t offset,
                    uint64_t bytes,
                    AsyncOpCallback *OpDoneCallback = 0,
                    void *context = 0,
                    int priority = 0);

                void SetPriority(int priority);





                int GetPriority() const
                {
                    ;
                    return mPriority;
                }

                void Cancel();

                OpStatus GetStatus(const thread::ThreadTime& timeoutAbsolute = thread::kTimeoutImmediate);

                Handle * GetResultHandle() const;

                uint64_t GetResultSize() const;




                void * GetContext() const
                {
                    ;
                    return mContext;
                }




                void Wait()
                {
                    ;
                    GetStatus((0x7fffffff * 2U + 1));
                    return;
                }

            private:
                static OpStatus DoOpen(AsyncOp *op);
                static OpStatus DoClose(AsyncOp *op);
                static OpStatus DoRead(AsyncOp *op);
                static OpStatus DoWrite(AsyncOp *op);


                OpStatus volatile mStatus;
                bool mCancelled;
                bool mIsRead;
                volatile int mPriority;
                Handle * mFileHandle;
                void * mContext;
                AsyncOpCallback * mCallbackFunc;
                uint64_t mValue;
                uint64_t mAmount;
                void * mData;
                uint64_t mTotalBytes;
                Device * mDevice;
                OpStatus (*mExecFunc)(AsyncOp *);



                friend class Device;
            };

            bool Exists(const char *FilePath);
            uint64_t GetSize(const char *FilePath);
            bool GetLocationAndSize(const char *FilePath, uint64_t *location, uint64_t *size);
            uint64_t GetSize(const Handle *FileHandle);
            bool Resize(Handle *FileHandle, uint64_t size);
            uint64_t GetLocation(const Handle *FileHandle);
        }
    }
}
