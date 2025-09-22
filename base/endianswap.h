




#include <rw/core/base/ostypes.h>




































































































namespace rw
{

template <typename T>
inline void ForcedEndianSwap16(T & _x)
{
    ((*((uint16_t *)(&(_x)))) = (uint16_t)
     (((*((uint16_t *)(&(_x)))) >> 8) |
      ((*((uint16_t *)(&(_x)))) << 8)));
}

template <typename T>
inline void ForcedEndianSwap32(T & _x)
{
    (((*(uint32_t *)(&(_x)))) =
     ((((*(uint32_t *)(&(_x))) >> 24)) |
      (((*(uint32_t *)(&(_x))) >> 8) & 0xff00UL) |
      (((*(uint32_t *)(&(_x))) << 8) & 0xff0000UL) |
      (((*(uint32_t *)(&(_x))) << 24))));
}

template <typename T>
inline void ForcedEndianSwap64(T & _x)
{
    RwChar *endianSwap64begin = (RwChar *)&(_x);
    RwChar *endianSwap64end = endianSwap64begin + 7;
    while (endianSwap64begin < endianSwap64end)
    {
        const RwChar endianSwap64temp = *endianSwap64begin;
        *endianSwap64begin = *endianSwap64end;
        *endianSwap64end = endianSwap64temp;
        endianSwap64begin++;
        endianSwap64end--;
    }
}

template <typename T>
inline void ForcedEndianSwap128(T & _x)
{
    RwChar *endianSwap128begin = (RwChar *)&(_x);
    RwChar *endianSwap128end = endianSwap128begin + 15;
    while (endianSwap128begin < endianSwap128end)
    {
        const RwChar endianSwap128temp = *endianSwap128begin;
        *endianSwap128begin = *endianSwap128end;
        *endianSwap128end = endianSwap128temp;
        endianSwap128begin++;
        endianSwap128end--;
    }
}

template <typename T>
inline void ForcedEndianSwap16_Array(T _m, int32_t _n, size_t _s)
{
    uint16_t *_mem;
    int32_t _i;

    _mem = reinterpret_cast<uint16_t *>(_m);

    _i = (_n);
    while (_i--)
    {
        rw::ForcedEndianSwap16(*_mem);
        _mem = reinterpret_cast<uint16_t *>(((uint8_t *)_mem) + (_s));
    }
}

template <typename T>
inline void ForcedEndianSwap32_Array(T _m, int32_t _n, size_t _s)
{
    uint32_t *_mem;
    int32_t _i;

    _mem = reinterpret_cast<uint32_t *>(_m);

    _i = (_n);
    while (_i--)
    {
        rw::ForcedEndianSwap32(*_mem);
        _mem = reinterpret_cast<uint32_t *>(((uint8_t *)_mem) + (_s));
    }
}

template <typename T>
inline void ForcedEndianSwap64_Array(T _m, int32_t _n, size_t _s)
{
    uint64_t *_mem;
    int32_t _i;

    _mem = reinterpret_cast<uint64_t *>(_m);

    _i = (_n);
    while (_i--)
    {
        rw::ForcedEndianSwap64(*_mem);
        _mem = reinterpret_cast<uint64_t *>(((uint8_t *)_mem) + (_s));
    }
}

inline void EndianSwap(int16_t& )
{
    ;
}

inline void EndianSwap(uint16_t& )
{
    ;
}

inline void EndianSwap(int32_t& )
{
    ;
}

inline void EndianSwap(uint32_t& )
{
    ;
}

inline void EndianSwap(float32_t& )
{
    ;
}

inline void EndianSwap(int64_t& )
{
    ;
}

inline void EndianSwap(uint64_t& )
{
    ;
}

inline void EndianSwap(float64_t& )
{
    ;
}

inline void EndianSwap(int128_t& )
{
    ;
}

inline void EndianSwap(uint128_t& )
{
    ;
}

template <typename T>
inline void EndianSwap(T*& ptr)
{
    EndianSwap(*reinterpret_cast<rw::HostPtr*>(&ptr));
}

template <typename T>
inline void EndianSwapArray(T* , uint32_t )
{






}



inline void ForcedEndianSwap(int16_t& t)
{
    rw::ForcedEndianSwap16(t);
}

inline void ForcedEndianSwap(uint16_t& t)
{
    rw::ForcedEndianSwap16(t);
}

inline void ForcedEndianSwap(int32_t& t)
{
    rw::ForcedEndianSwap32(t);
}

inline void ForcedEndianSwap(uint32_t& t)
{
    rw::ForcedEndianSwap32(t);
}

inline void ForcedEndianSwap(float32_t& t)
{
    rw::ForcedEndianSwap32(t);
}

inline void ForcedEndianSwap(int64_t& t)
{




    rw::ForcedEndianSwap64(t);



}

inline void ForcedEndianSwap(uint64_t& t)
{




    rw::ForcedEndianSwap64(t);



}

inline void ForcedEndianSwap(float64_t& t)
{




    rw::ForcedEndianSwap64(t);



}

inline void ForcedEndianSwap(int128_t& t)
{




    rw::ForcedEndianSwap128(t);



}

inline void ForcedEndianSwap(uint128_t& t)
{




    rw::ForcedEndianSwap128(t);



}

template <typename T>
inline void ForcedEndianSwap(T*& ptr)
{
    ForcedEndianSwap(reinterpret_cast<rw::HostPtr&>(ptr));
}

template <typename T>
inline void ForcedEndianSwapArray(T* array, uint32_t size)
{
    for (uint32_t i = 0; i < size; ++i)
    {
        ForcedEndianSwap(*(array + i));
    }
}


}
