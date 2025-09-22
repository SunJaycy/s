






#include <stddef.h>
#include <inttypes.h>
#include <sdk_version.h>






















typedef signed char RwInt8;
typedef unsigned char RwUInt8;
typedef signed short RwInt16;
typedef unsigned short RwUInt16;
typedef signed int RwInt32;
typedef unsigned int RwUInt32;





typedef signed long long RwInt64;
typedef unsigned long long RwUInt64;

typedef RwUInt32 RwBool;
typedef float RwReal32;
typedef double RwReal64;
typedef unsigned long RwSizet;






typedef RwUInt32 RwHostPointer;
typedef RwUInt32 RwHostPtr;
typedef RwInt32 RwHostOffset;


typedef signed int RwInt128 __attribute__((vector_size(16)));
typedef unsigned int RwUInt128 __attribute__((vector_size(16)));


















#include <inttypes.h>
#include <stdint.h>
#include <float.h>
#include <math.h>































    typedef char char8_t;
    typedef wchar_t char16_t;
    typedef uint32_t char32_t;







namespace rw
{





    typedef uint32_t HostPtr;
    typedef uint32_t HostOffset;



    typedef signed int int128_t __attribute__((vector_size(16)));
    typedef unsigned int uint128_t __attribute__((vector_size(16)));




}























struct RwRGBTag
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

typedef struct RwRGBTag RwRGB;


struct RwRGBATag
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

typedef struct RwRGBATag RwRGBA;


namespace rw
{
class RGBA
{
 public:

    inline
    RGBA()
    {
        ;

        return;
    }

    inline explicit RGBA(RwRGBA rgba)
    {
        ;
        *reinterpret_cast<RwRGBA *>(&m_rgba) = rgba;
        return;
    }

    inline
    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a=0xff)
    {
        ;
        m_rgba = (uint32_t)r << 24;
        m_rgba |= (uint32_t)g << 16;
        m_rgba |= (uint32_t)b << 8;
        m_rgba |= (uint32_t)a << 0;
        return;
    }

    inline
    RGBA(RwRGB rgb, unsigned char a=0xff)
    {
        ;
        m_rgba = (uint32_t)rgb.red << 24;
        m_rgba |= (uint32_t)rgb.green << 16;
        m_rgba |= (uint32_t)rgb.blue << 8;
        m_rgba |= (uint32_t)a << 0;
        return;
    }

    inline RwRGBA
    GetRwRGBA() const
    {
        ;
        RwRGBA rgba;
        rgba = *(reinterpret_cast<const RwRGBA *>(&m_rgba));
        return rgba;
    }

    inline void
    Set(RwRGBA rgba)
    {
        ;
        *(reinterpret_cast<RwRGBA *>(&m_rgba)) = rgba;
        return;
    }


    inline uint8_t
    GetRed() const
    {
        ;
        return (uint8_t)(m_rgba >> 24);
    }

    inline void
    SetRed(uint8_t value)
    {
        ;
        m_rgba &= ~(0xff << 24);
        m_rgba |= ((uint32_t)value << 24);
        return;
    }

    inline uint8_t
    GetGreen() const
    {
        ;
        return (uint8_t)(m_rgba >> 16);
    }

    inline void
    SetGreen(uint8_t value)
    {
        ;
        m_rgba &= ~(0xff << 16);
        m_rgba |= ((uint32_t)value << 16);
        return;
    }

    inline uint8_t
    GetBlue() const
    {
        ;
        return (uint8_t)(m_rgba >> 8);
    }

    inline void
    SetBlue(uint8_t value)
    {
        ;
        m_rgba &= ~(0xff << 8);
        m_rgba |= ((uint32_t)value << 8);
        return;
    }

    inline uint8_t
    GetAlpha() const
    {
        ;
        return (uint8_t)(m_rgba >> 0);
    }

    inline void
    SetAlpha(uint8_t value)
    {
        ;
        m_rgba &= ~(0xff << 0);
        m_rgba |= ((uint32_t)value << 0);
        return;
    }

    bool operator==(const RGBA &other) const
    {
        return (m_rgba == other.m_rgba);
    }

 private:
    uint32_t m_rgba;
};

}
