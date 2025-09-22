























namespace rw
{
    namespace core
    {
        namespace filesys
        {
            class ScatterLoadFile;
            struct ScatterLoadFilePrivate;














            typedef void (ScatterLoadFileCallback)( ScatterLoadFile *file, void *context);





            class ScatterLoadFile
            {
            public:





                ScatterLoadFile()
                    : mFilePath(0),mCallback(0),mContext(0),
                    mAddr(0),mFileSize(0),mDoneState(false),mModeFlags(0),
                    mAlign(4)
                {
                    ;
                    return;
                }


                explicit ScatterLoadFile(const char * filePath) :
                    mFilePath(filePath),mCallback(0),mContext(0),
                    mAddr(0),mFileSize(0),mDoneState(false),
                    mModeFlags(0), mAlign(4)
                {
                    ;
                    return;
                }


                ScatterLoadFile(const char * filePath, unsigned int modeflags) :
                    mFilePath(filePath),mCallback(0),mContext(0),
                    mAddr(0),mFileSize(0),mDoneState(false),
                    mModeFlags(modeflags), mAlign(4)
                {
                    ;
                    return;
                }


                ScatterLoadFile(const char * filePath, unsigned int bufAlign, unsigned int modeflags) :
                    mFilePath(filePath),mCallback(0),mContext(0),
                    mAddr(0),mFileSize(0),mDoneState(false),
                    mModeFlags(modeflags), mAlign(bufAlign)
                {
                    ;
                    return;
                }


                ScatterLoadFile(const char *filePath, void *addr,
                    uint64_t buffersize, unsigned int modeflags) :
                        mFilePath(filePath),mCallback(0),mContext(0),
                        mAddr(addr),mFileSize(buffersize),mDoneState(false),
                        mModeFlags(modeflags), mAlign(4)
                {
                    ;
                    return;
                }






                const char* GetFilePath() const
                {
                    ;
                    return mFilePath;
                }




                unsigned int GetFlags() const
                {
                    ;
                    return mModeFlags;
                }




                unsigned int GetAlignment() const
                {
                    ;
                    return mAlign;
                }




                ScatterLoadFileCallback* GetCallback() const
                {
                    ;
                    return mCallback;
                }




                void* GetContext() const
                {
                    ;
                    return mContext;
                }




                void* GetAddress() const
                {
                    ;
                    return mAddr;
                }




                uint64_t GetFileSize() const
                {
                    ;
                    return mFileSize;
                }




                bool AreAllLoadsComplete() const
                {
                    ;
                    return mDoneState;
                }




                void SetFilePath(const char* path)
                {
                    ;
                    mFilePath = path;
                    return;
                }




                void SetFlags(unsigned int flags)
                {
                    ;
                    mModeFlags = flags;
                    return;
                }




                void SetAlignment(unsigned int align)
                {
                    ;
                    mAlign = align;
                    return;
                }




                void SetCallback(ScatterLoadFileCallback * callback)
                {
                    ;
                    mCallback = callback;
                    return;
                }




                void SetContext(void* context)
                {
                    ;
                    mContext = context;
                    return;
                }







                void SetAddress(void* address)
                {
                    ;
                    mAddr = address;
                    return;
                }






                void SetFileSize(uint64_t fileSize)
                {
                    ;
                    mFileSize = fileSize;
                    return;
                }




                void SetDone()
                {
                    ;
                    mDoneState = true;
                    return;
                }

            private:
                const char * mFilePath;
                ScatterLoadFileCallback * mCallback;
                void * mContext;
                void * mAddr;
                uint64_t mFileSize;
                bool mDoneState;
                unsigned int mModeFlags;
                unsigned int mAlign;
            };


            class ScatterLoad
            {
            public:
















                ScatterLoad(ScatterLoadFile *filelist, unsigned int listsize,
                    unsigned int flags = 0, rw::IResourceAllocator *pAllocator = 0);





                ~ScatterLoad();

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
                    OPSTATUS_PENDING,
                    OPSTATUS_COMPLETE
                };

                OpStatus GetStatus(const thread::ThreadTime& timeoutAbsolute = thread::kTimeoutImmediate);

            private:

                static void OpDoneCallback(AsyncOp *op);


                enum ScatterLoaderState
                {
                    ALS_OPEN,
                    ALS_READ,
                    ALS_CLOSE
                };

                ScatterLoaderState mState;
                unsigned int mNumFiles;
                Handle * mFileHandle;
                AsyncOp mOp;
                ScatterLoadFilePrivate *mCurr;
                ScatterLoadFilePrivate *mAipList;
                thread::Semaphore mComplete;



                ScatterLoad(const ScatterLoad& rhs);
                ScatterLoad& operator=(const ScatterLoad& rhs);
            };
        }
    }
}
