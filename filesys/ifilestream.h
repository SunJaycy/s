
























namespace rw
{
namespace core
{
namespace filesys
{








class IFileStream
{
public:







    enum SeekOrigin
    {

        SEEKORIGIN_CURRENT,

        SEEKORIGIN_BEGINNING,

        SEEKORIGIN_END,

        SEEKORIGIN_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    virtual ~IFileStream()
    {
        ;
        return;
    }








    virtual uint64_t Read(void * buffer, size_t count) = 0;








    virtual uint64_t Write(const void * buffer, size_t count) = 0;





    virtual uint64_t Tell() = 0;










    virtual int Seek(uint64_t offset, SeekOrigin origin) = 0;





    virtual uint64_t Size() = 0;
};










class DefaultFileStream : public IFileStream
{
 public:

    DefaultFileStream();
    int Open(const char * filename,unsigned int modeflags);
    void Close();


    virtual ~DefaultFileStream();
    virtual uint64_t Read(void * buffer, size_t count);
    virtual uint64_t Write(const void * buffer, size_t count);
    virtual uint64_t Tell();
    virtual int Seek(uint64_t offset, IFileStream::SeekOrigin origin);
    virtual uint64_t Size();
 private:
    rw::core::filesys::AsyncOp mFileOp;
    rw::core::filesys::Handle * mFileHandle;
    uint64_t mPos;
};

}
}
}
