















namespace rw
{
namespace core
{
namespace debug
{





class ConsoleDevice : public Device
{
public:
    ConsoleDevice() : Device(0, Device::FLAG_NONE) {}
    explicit ConsoleDevice(unsigned int flags) : Device(0, flags) {}
    ConsoleDevice(unsigned int bufSize, unsigned int flags) : Device(bufSize, flags) {}
    virtual ~ConsoleDevice() {}

private:
    virtual void Output(const void *data, unsigned int dataLen);


    ConsoleDevice(const ConsoleDevice& rhs);
    ConsoleDevice& operator=(const ConsoleDevice& rhs);
};

}
}
}
