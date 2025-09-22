


namespace rw
{
namespace core {
namespace endian {

inline uint32_t ConvertLittle(const uint32_t x)
{
    ;

    return ((x&0xff)<<24) | ((x&0xff00)<<8) | ((x>>8)&0xff00) | ((x>>24)&0xff);







}

inline uint16_t ConvertLittle(const uint16_t x)
{
    ;

    return (uint16_t) ( ((x&0xff)<<8) | ((x>>8)&0xff) );






}

inline int32_t ConvertLittle(const int32_t x)
{
    ;

    return ((x&0xff)<<24) | ((x&0xff00)<<8) | ((x>>8)&0xff00) | ((x>>24)&0xff);







}

inline int16_t ConvertLittle(const int16_t x)
{
    ;

    return (int16_t) ( ((x&0xff)<<8) | ((x>>8)&0xff) );






}

inline uint64_t ConvertLittle(const uint64_t x)
{
    ;

    return ((x&0xff)<<56) | ((x&0xff00)<<40) | ((x&0xff0000)<<24) | ((x&0xff000000)<<8) | ((x>>8)&0xff000000) | ((x>>24)&0xff0000) | ((x>>40)&0xff00) | ((x>>56)&0xff);











}

inline int64_t ConvertLittle(const int64_t x)
{
    ;

    return ((x&0xff)<<56) | ((x&0xff00)<<40) | ((x&0xff0000)<<24) | ((x&0xff000000)<<8) | ((x>>8)&0xff000000) | ((x>>24)&0xff0000) | ((x>>40)&0xff00) | ((x>>56)&0xff);











}

inline uint32_t ConvertBig(const uint32_t x)
{
    ;

    return x;







}

inline uint16_t ConvertBig(const uint16_t x)
{
    ;

    return x;






}

inline int32_t ConvertBig(const int32_t x)
{
    ;

    return x;







}

inline int16_t ConvertBig(const int16_t x)
{
    ;

    return x;






}

inline uint64_t ConvertBig(const uint64_t x)
{
    ;

    return x;











}

inline int64_t ConvertBig(const int64_t x)
{
    ;

    return x;











}

inline uint32_t make_id32(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    ;

    return (static_cast<uint32_t>(a) << 24) | (static_cast<uint32_t>(b) << 16) | (static_cast<uint32_t>(c) << 8) | static_cast<uint32_t>(d);



}

inline void PutBig(void* dst, uint32_t data, int32_t n)
{
    ;

    if (n==1)
    {
        ((uint8_t*)dst)[0] = (uint8_t)data;
    }
    else if (n==2)
    {
        ((uint16_t*)dst)[0] = (uint16_t)data;
    }
    else if (n==4)
    {
        ((uint32_t*)dst)[0] = (uint32_t)data;
    }
    else if (n==3)
    {
        ((uint8_t*)dst)[0] = (uint8_t)(data>>16);
        ((uint8_t*)dst)[1] = (uint8_t)(data>>8);
        ((uint8_t*)dst)[2] = (uint8_t)data;
    }
























    return;
}

inline void PutLittle(void *dst, uint32_t data, int32_t n)
{
    ;

    if (n==1)
    {
        ((uint8_t*)dst)[0] = (uint8_t)data;
    }
    else if (n==2)
    {
        ((uint8_t*)dst)[0] = (uint8_t)data;
        ((uint8_t*)dst)[1] = (uint8_t)(data>>8);
    }
    else if (n==4)
    {
        ((uint8_t*)dst)[0] = (uint8_t)data;
        ((uint8_t*)dst)[1] = (uint8_t)(data>>8);
        ((uint8_t*)dst)[2] = (uint8_t)(data>>16);
        ((uint8_t*)dst)[3] = (uint8_t)(data>>24);
    }
    else if (n==3)
    {
        ((uint8_t*)dst)[0] = (uint8_t)data;
        ((uint8_t*)dst)[1] = (uint8_t)(data>>8);
        ((uint8_t*)dst)[2] = (uint8_t)(data>>16);
    }





































    return;
}

inline uint32_t GetBig(const void* src, int32_t n)
{
    ;

    if (n==1)
    {
        return (uint32_t)*(const uint8_t*)src;
    }
    else if (n==2)
    {
        return (uint32_t)*(const uint16_t*)src;
    }
    else if (n==3)
    {
        return (uint32_t)*(const uint32_t*)src>>8;
    }
    else if (n==4)
    {
        return (uint32_t)*(const uint32_t*)src;
    }




























    return 0;
}

inline uint32_t GetLittle(const void* src, int32_t n)
{
    ;






    if (n==1)
    {
        return (uint32_t)*(const uint8_t*)src;
    }
    else if (n==2)
    {
        return ((uint32_t)*((const uint8_t*)src+1))<<8 |

            (((uint32_t)*(const uint8_t*)src+0));
    }
    else if (n==3)
    {
        return ((uint32_t)*((const uint8_t*)src+2))<<16 |

            (((uint32_t)*((const uint8_t*)src+1))<<8) |
            (((uint32_t)*(const uint8_t*)src+0));
    }
    else if (n==4)
    {
        return ((uint32_t)*((const uint8_t*)src+3))<<24 |

            (((uint32_t)*((const uint8_t*)src+2))<<16) |
            (((uint32_t)*((const uint8_t*)src+1))<<8) |
            (((uint32_t)*(const uint8_t*)src+0));
    }



















    return 0;
}

inline void PutBig64(void* dst, uint64_t data, int32_t n)
{
    ;
    while (n--)
    {
        ((uint8_t*)dst)[n]=(uint8_t)data;
        data>>=8;
    }
    return;
}

inline void PutLittle64(void *dst, uint64_t data, int32_t n)
{
    ;
    for (int32_t i=0; i<n; i++)
    {
        ((uint8_t*)dst)[i]=(uint8_t)data;
        data>>=8;
    }
    return;
}

inline uint64_t GetBig64(const void* src, int32_t n)
{
    ;
    uint64_t result=0;

    for (int32_t i=0; i<n; i++)
    {
        result<<=8;
        result|=((const uint8_t*)src)[i];
    }

    return result;
}

inline uint64_t GetLittle64(const void* src, int32_t n)
{
    ;
    uint64_t result=0;

    while (n--)
    {
        result<<=8;
        result|=((const uint8_t*)src)[n];
    }

    return result;
}

}
}
}
