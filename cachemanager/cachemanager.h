














namespace rw
{
namespace cachemanager
{




static const uint32_t DEFAULTBATCHSIZE = 1024;




static const size_t LINESIZE = 128;




inline void HintRead(const void *address, size_t size)
{
    for (uint32_t i = 0; i < size; i += 128)
    {
        asm ("dcbt %0, %1" : : "r" (i), "b" (address));
    }
}




inline void HintRewrite(void *address, size_t size)
{
    for (uint32_t i = 0; i < size; i += 128)
    {
        asm ("dcbt %0, %1" : : "r" (i), "b" (address));
    }
}




inline void HintWrite(void *address, size_t size)
{
    for (uint32_t i = 0; i < size; i += 128)
    {
        asm ("dcbz %0, %1" : : "r" (i), "b" (address));
    }
}




inline void HintWritePrefetch(void *, size_t )
{
}


}
}
