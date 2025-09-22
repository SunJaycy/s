















namespace rw
{
namespace core
{
namespace codec
{



















class RefpackDeflate : public ICodec
{
public:
    RefpackDeflate(rw::IResourceAllocator *allocator, unsigned int level);
    virtual ~RefpackDeflate();

    virtual void Reset();
    virtual void Init(unsigned int level);
    virtual void End();

    virtual Status Exec(unsigned int flags);

private:

    unsigned int MatchLength(const unsigned char *s, const unsigned char *d, unsigned int maxmatch) const;
    inline unsigned int GetHash(const unsigned char *cptr) const;
    int Compress(unsigned char *dest, int destBufSize, const unsigned char *src, int srcBufSize, int MaxLookBack, unsigned int *hashtbl, unsigned int *link) const;



    unsigned int mLevel;
};













class RefpackInflate : public ICodec
{
public:
    explicit RefpackInflate(rw::IResourceAllocator *allocator);
    virtual ~RefpackInflate();

    virtual void Reset();
    virtual void Init(unsigned int level);
    virtual void End();

    virtual Status Exec(unsigned int flags);

private:

    enum DecompressState
    {
        GET_TYPE,
        GET_LENGTH,
        GET_CONTROL_BYTE,
        TEST_CONTROL_BYTE,
        GET_CONTROL_BYTES,
        GET_SHORT_RUN_BYTES,
        GET_LONG_RUN_BYTES,
        GET_VERY_LONG_RUN_BYTES,
        GET_SHORT_REF_BYTES,
        GET_LONG_REF_BYTES,
        GET_VERY_LONG_REF_BYTES,
        COPY_LITERAL,
        COPY_REFERENCE,
        SETUPFLUSH,
        FLUSHWINDOW
    };


    const unsigned char * mNextIn;

    unsigned char * mNextOut;

    DecompressState mState;

    DecompressState mNextState;

    int mBytesNeeded;

    int mOriginalLength;

    unsigned int mRunLength;
    unsigned int mControl;

    unsigned char * mRefPtr;

    unsigned char * mRefWindowBase;

    unsigned char * mRefWindowPtr;
    int64_t mNumBytesDecompressed;

    int mWindowSize;

    Status mStatus;

    ICodec::Status Decompress();
};

class RefpackBuf : public IBufCodec
{
public:
    virtual unsigned int Decompress(void *outputBuf, const void *inputBuf);

    virtual unsigned int GetDecompressedSize(const void *inputBuf);


    RefpackBuf() {}
    virtual ~RefpackBuf() {}
};

}
}
}
