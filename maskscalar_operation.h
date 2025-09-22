





#include <rw/math/fpu/detail/float_intrinsic_operation.h>


namespace rw
{
namespace math
{
namespace fpu
{


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> Not(const MaskScalarTemplate<T> &a)
{
    return MaskScalarTemplate<T>(T(__fsel((a.mS), (T(-1.0f)), (T(1.0f)))));
}


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> And(const MaskScalarTemplate<T> &a, const MaskScalarTemplate<T> &b)
{
    return MaskScalarTemplate<T>(T(__fsel((a.mS), (b.mS), (T(-1.0f)))));
}


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> Or(const MaskScalarTemplate<T> &a, const MaskScalarTemplate<T> &b)
{
    return MaskScalarTemplate<T>(T(__fsel((a.mS), (a.mS), (b.mS))));
}


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> Xor(const MaskScalarTemplate<T> &a, const MaskScalarTemplate<T> &b)
{
    return MaskScalarTemplate<T>(T(__fsel((a.mS), (Not(b).mS), (b.mS))));
}


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompEqual(const MaskScalarTemplate<T> &a, const MaskScalarTemplate<T> &b)
{
    return MaskScalarTemplate<T>(T(__fsel((a.mS), (b.mS), (Not(b).mS))));
}


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompNotEqual(const MaskScalarTemplate<T> &a, const MaskScalarTemplate<T> &b)
{
    return MaskScalarTemplate<T>(T(__fsel((a.mS), (Not(b).mS), (b.mS))));
}

}
}
}
