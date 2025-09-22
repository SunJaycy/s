


































































































#include <rw/core/base/targtype.h>


































































#include <rw/core/base/detail/hosttype.h>






typedef char RwChar;






















typedef float float32_t;
typedef double float64_t;





        typedef int8_t bool8_t;










typedef int32_t bool32_t;

namespace rw
{












    typedef uint32_t TargetPtr;
    typedef int32_t TargetOffset;








}


typedef rw::TargetPtr RwTargetPtr;
typedef rw::TargetOffset RwTargetOffset;








namespace rw
{

typedef uint32_t GlobalAddress;



}


























































































































































































































namespace rw
{






inline RwBool IsMemAligned(const void* ptr, uint32_t align)
{
    if (align <= 1)
    {
        return (!0);
    }

    const rw::HostPtr alignMask = align - 1;
    return (RwBool)((reinterpret_cast<rw::HostPtr>(ptr) & alignMask) == 0);
}








inline uint32_t SizeAlign(uint32_t size, uint32_t align)
{
    if (align <= 1)
    {
        return static_cast<uint32_t>(size);
    }

    const uint32_t alignMask = align - 1;
    return static_cast<uint32_t>( (size + alignMask) & ~alignMask);
}








inline uint32_t SizeAlignDown(uint32_t size, uint32_t align)
{

    return static_cast<uint32_t>((0 - align) & size);
}








template <typename T>
inline T* MemAlign(T* ptr, uint32_t align)
{
    if (align <= 1)
    {
        return ptr;
    }

    const rw::HostPtr alignMask = align - 1;
    return reinterpret_cast<T *>((reinterpret_cast<rw::HostPtr>(ptr) + alignMask) & ~alignMask);
}








template <typename T>
inline T* MemAlignDown(T* ptr, uint32_t align)
{

    return reinterpret_cast<T *>((0 - align) & reinterpret_cast<rw::HostPtr>(ptr));
}








template <typename ValueType>
inline ValueType* MemAddOffset(ValueType* ptr, rw::HostPtr offset)
{
    return reinterpret_cast<ValueType*>(reinterpret_cast<rw::HostPtr>(ptr) + offset);
}








template <typename ValueType>
inline ValueType* MemSubtractOffset(ValueType* ptr, rw::HostPtr offset)
{
    return reinterpret_cast<ValueType*>(reinterpret_cast<rw::HostPtr>(ptr) - offset);
}







inline rw::HostPtr MemCalculateOffset(const void* first, const void* second)
{
    return reinterpret_cast<rw::HostPtr>(first) - reinterpret_cast<rw::HostPtr>(second);
}








template <typename ValueType, typename OtherValueType>
inline ValueType* MemAddBasePtr(ValueType* ptr, OtherValueType* base)
{
    return reinterpret_cast<ValueType*>(reinterpret_cast<rw::HostPtr>(ptr) + reinterpret_cast<rw::HostPtr>(base));
}








template <typename ValueType, typename OtherValueType>
inline ValueType* MemSubtractBasePtr(ValueType* ptr, OtherValueType* base)
{
    return reinterpret_cast<ValueType*>(reinterpret_cast<rw::HostPtr>(ptr) - reinterpret_cast<rw::HostPtr>(base));
}

}



#include <rw/core/base/endianswap.h>












#include <rw/core/base/rwptr/ptrnative.h>
#include <rw/core/base/rwptr/ptrcross32to64.h>
#include <rw/core/base/rwptr/ptrcross64to32.h>


namespace rw
{






template <typename T>
class LargeTypeSerializer
{
public:
    LargeTypeSerializer(T& t)
       : m_t(&t)
    {
    }







    uint8_t &
    operator[](size_t i)
    {
        ;

        return ((uint8_t *)(m_t))[Sizeof()-i-1];



    }







    const uint8_t&
    operator[](size_t i) const
    {
        ;

        return ((const uint8_t *)(m_t))[Sizeof()-i-1];



    }




    static size_t Sizeof()
    {
        ;
        return sizeof(T);
    }

private:
    T *m_t;
};










template <typename T>
LargeTypeSerializer<T> SerializeLargeType(T& largeType)
{
    ;
    return LargeTypeSerializer<T>(largeType);
}


}









struct RwRect32Tag
{
    float32_t x;
    float32_t y;
    float32_t w;
    float32_t h;
};


typedef struct RwRect32Tag RwRect32;













typedef struct RwRGBTag RwRGB;














typedef struct RwRGBATag RwRGBA;





















































































































































struct RwRGBA16Tag
{
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    uint16_t alpha;
};


typedef struct RwRGBA16Tag RwRGBA16;





struct RwRGBRealTag
{
    float32_t red;
    float32_t green;
    float32_t blue;
};


typedef struct RwRGBRealTag RwRGBReal;





struct RwRGBARealTag
{
    float32_t red;
    float32_t green;
    float32_t blue;
    float32_t alpha;
    bool operator==(const RwRGBARealTag &other) const
    {
        return red == other.red && green == other.green && blue == other.blue && alpha == other.alpha;
    }
};


typedef struct RwRGBARealTag RwRGBAReal;


namespace rw
{




template <typename TYPE> class Point2Template
{
 public:
    inline
    Point2Template(void) {}

    inline
    Point2Template(TYPE x, TYPE y) : m_x(x), m_y(y) { }

    inline TYPE
    X() const
    {
        return m_x;
    }

    inline TYPE
    Y() const
    {
        return m_y;
    }

    inline TYPE
    GetX() const
    {
        return m_x;
    }

    inline TYPE
    GetY() const
    {
        return m_y;
    }

    inline void
    SetX(TYPE x)
    {
        m_x = x;
    }

    inline void
    SetY(TYPE y)
    {
        m_y = y;
    }

    inline void
    Set(TYPE x, TYPE y)
    {
        m_x = x;
        m_y = y;
    }

private:
    TYPE m_x;
    TYPE m_y;
};


typedef Point2Template<uint16_t> Point2_16;
}




namespace rw
{
typedef union SplitBits SplitBits;
union SplitBits
{
    float32_t nReal;
    volatile int32_t nInt;
    volatile uint32_t nUInt;
};
}


typedef rw::SplitBits RwSplitBits;



namespace rw
{
typedef union MutablePointer MutablePointer;
union MutablePointer
{
    const void *cptr;
    void *ptr;
};
}


typedef rw::MutablePointer RwMutablePointer;

namespace rw
{








enum Status
{
    STATUS_NA = -2,

    STATUS_FAIL = false,
    STATUS_SUCCESS = true,

    STATUS_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
}
