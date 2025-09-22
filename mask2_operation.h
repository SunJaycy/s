




#include <rw/math/fpu/mask2.h>



namespace rw
{
namespace math
{
namespace fpu
{


template<class T>
inline __attribute__ ((always_inline)) Mask2Template<T> Not(const Mask2Template<T> &a)
{
    return Mask2Template<T>(
            T(__fsel((a.mX), (T(-1.0f)), (T(1.0f)))),
            T(__fsel((a.mY), (T(-1.0f)), (T(1.0f))))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask2Template<T> And(const Mask2Template<T> &a, const Mask2Template<T> &b)
{
    return Mask2Template<T>(
            T(__fsel((a.mX), (b.mX), (T(-1.0f)))),
            T(__fsel((a.mY), (b.mY), (T(-1.0f))))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask2Template<T> Or(const Mask2Template<T> &a, const Mask2Template<T> &b)
{
    return Mask2Template<T>(
            T(__fsel((a.mX), (a.mX), (b.mX))),
            T(__fsel((a.mY), (a.mY), (b.mY)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask2Template<T> Xor(const Mask2Template<T> &a, const Mask2Template<T> &b)
{
    Mask2Template<T> notB(Not(b));
    return Mask2Template<T>(
            T(__fsel((a.mX), (notB.mX), (b.mX))),
            T(__fsel((a.mY), (notB.mY), (b.mY)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask2Template<T> CompEqual(const Mask2Template<T> &a, const Mask2Template<T> &b)
{
    Mask2Template<T> notB(Not(b));
    return Mask2Template<T>(
            T(__fsel((a.mX), (b.mX), (notB.mX))),
            T(__fsel((a.mY), (b.mY), (notB.mY)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask2Template<T> CompNotEqual(const Mask2Template<T> &a, const Mask2Template<T> &b)
{
    Mask2Template<T> notB(Not(b));
    return Mask2Template<T>(
            T(__fsel((a.mX), (notB.mX), (b.mX))),
            T(__fsel((a.mY), (notB.mY), (b.mY)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompAnyTrue(const Mask2Template<T> &a)
{

    return MaskScalarTemplate<T>(T(__fsel((a.mX), (a.mX), (a.mY))));
}


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompAllTrue(const Mask2Template<T> &a)
{

    return MaskScalarTemplate<T>(T(__fsel((a.mX), (a.mY), (T(-1.0f)))));
}

}
}
}
