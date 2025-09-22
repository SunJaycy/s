
















namespace rw
{
namespace core
{
namespace codec
{





class ICodec
{
public:

    virtual ~ICodec();







    enum Status
    {
        STREAM_OK,
        STREAM_END,
        STREAM_ERROR
    };













    enum DeflateInitFlags
    {
        DEFLATE_NONE = 0,
        DEFLATE_BEST_SPEED = 1,
        DEFLATE_BEST_SIZE = 9
    };







    enum InflateInitFlags
    {
        INFLATE_TEMP_BUFFER_NOT_NEEDED = 0
    };




    enum ExecFlags
    {
        NO_FLUSH = 0,
        FLUSH = 1,
        FINISH = 2
    };

    void SetOutputBuffer(void *outputbuf, unsigned int outputbufsize);
    void SetInputBuffer(const void *in, unsigned int InputBufSize);





    unsigned int GetInputBytesAvailable() const
    {
        ;
        return mInputBytesAvailable;
    }





    unsigned int GetOutputBytesAvailable() const
    {
        ;
        return mOutputBytesAvailable;
    }




    uint64_t GetTotalOut() const
    {
        ;
        return mOutputBytes;
    }






    virtual void Init(unsigned int level) = 0;




    virtual void End() = 0;




    virtual void Reset() = 0;













    virtual Status Exec(
        unsigned int flags
        ) = 0;

protected:
    explicit ICodec(rw::IResourceAllocator *allocator);

    void ClearValues();

    rw::IResourceAllocator * mAllocator;
    bool mReady;

    unsigned int mInputBytesAvailable;
    unsigned int mOutputBytesAvailable;
    uint64_t mOutputBytes;

    const void * mInputBuffer;
    void * mOutputBuffer;
};


class IBufCodec
{
public:






    virtual unsigned int Decompress(void *outputBuf, const void *inputBuf) = 0;





    virtual unsigned int GetDecompressedSize(const void *inputBuf) = 0;


    IBufCodec() {}
    virtual ~IBufCodec() {}
};

}
}
}
