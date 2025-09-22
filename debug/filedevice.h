















namespace rw
{
namespace core
{
namespace debug
{





 class FileDevice : public Device
{
public:






    enum OpenMode
    {
        OPEN_MODE_TEXT,
        OPEN_MODE_BINARY
    };

    explicit FileDevice(const char *fileName, OpenMode mode = OPEN_MODE_TEXT, unsigned int flags = 0);
    FileDevice(const char *fileName, unsigned int bufSize, OpenMode mode = OPEN_MODE_TEXT, unsigned int flags = 0);

    virtual ~FileDevice();

    virtual void Flush();

private:
    void Init(const char *fileName, OpenMode mode);
    virtual void Output(const void *data, unsigned int dataLen);

    int mHandle;


    FileDevice(const FileDevice& rhs);
    FileDevice& operator=(const FileDevice& rhs);
};

}
}
}
