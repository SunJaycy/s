


















namespace rw
{
namespace core
{
namespace debug
{

class Channel;
class IFormatter;















class Device
{
public:





    enum
    {
        FLAG_NONE = 0x0,
        FLAG_THREADSAFE = 0x1
    };

    Device();
    explicit Device(unsigned int flags);
    Device(unsigned int bufLen, unsigned int flags);
    virtual ~Device();






    void Enable()
    {
        ;
        mEnabled = true;
        return;
    }







    void Disable()
    {
        ;
        mEnabled = false;
        return;
    }





    bool IsEnabled() const
    {
        ;
        return mEnabled;
    }







    virtual void OutputData(const void *data, unsigned int dataLen);







    virtual void Flush();

    void SetFormatter(IFormatter *formatter);

    char *GetBuffer() const;

    void Print(Channel *channel, const char *format, va_list args);






    void EnterCritical()
    {
        ;
        mCriticalSection.Enter();
        return;
    }







    void LeaveCritical()
    {
        ;
        mCriticalSection.Leave();
        return;
    }

    static void *operator new(size_t);
    static void operator delete(void *);

    static void SetBufLen(unsigned int bufLen);

private:
    void DeviceInit(unsigned int msgBufLen, unsigned int flags);
    void FlushOutputBuffer();








    virtual void Output(const void *data, unsigned int dataLen) = 0;






    bool mEnabled;




    IFormatter *mFormatter;





    char *mMsgBuffer;






    unsigned int mMsgBufLen;






    char *mOutBuffer;




    char *mOutBufP;




    unsigned int mOutBufLen;




    rw::core::debug::detail::DebugCriticalSection mCriticalSection;

    static unsigned int sMsgBufLen;


    Device(const Device& rhs);
    Device& operator=(const Device& rhs);
};

}
}
}
