




#include <rw/math/fpu/mask3.h>



namespace rw
{
namespace math
{
namespace fpu
{


template<class T>
inline __attribute__ ((always_inline)) Mask3Template<T> Not(const Mask3Template<T> &a)
{
    return Mask3Template<T>(
            T(__fsel((a.mX), (T(-1.0f)), (T(1.0f)))),
            T(__fsel((a.mY), (T(-1.0f)), (T(1.0f)))),
            T(__fsel((a.mZ), (T(-1.0f)), (T(1.0f))))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask3Template<T> And(const Mask3Template<T> &a, const Mask3Template<T> &b)
{
    return Mask3Template<T>(
            T(__fsel((a.mX), (b.mX), (T(-1.0f)))),
            T(__fsel((a.mY), (b.mY), (T(-1.0f)))),
            T(__fsel((a.mZ), (b.mZ), (T(-1.0f))))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask3Template<T> Or(const Mask3Template<T> &a, const Mask3Template<T> &b)
{
    return Mask3Template<T>(
            T(__fsel((a.mX), (a.mX), (b.mX))),
            T(__fsel((a.mY), (a.mY), (b.mY))),
            T(__fsel((a.mZ), (a.mZ), (b.mZ)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask3Template<T> Xor(const Mask3Template<T> &a, const Mask3Template<T> &b)
{
    Mask3Template<T> notB(Not(b));
    return Mask3Template<T>(
            T(__fsel((a.mX), (notB.mX), (b.mX))),
            T(__fsel((a.mY), (notB.mY), (b.mY))),
            T(__fsel((a.mZ), (notB.mZ), (b.mZ)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask3Template<T> CompEqual(const Mask3Template<T> &a, const Mask3Template<T> &b)
{
    Mask3Template<T> notB(Not(b));
    return Mask3Template<T>(
            T(__fsel((a.mX), (b.mX), (notB.mX))),
            T(__fsel((a.mY), (b.mY), (notB.mY))),
            T(__fsel((a.mZ), (b.mZ), (notB.mZ)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask3Template<T> CompNotEqual(const Mask3Template<T> &a, const Mask3Template<T> &b)
{
    Mask3Template<T> notB(Not(b));
    return Mask3Template<T>(
            T(__fsel((a.mX), (notB.mX), (b.mX))),
            T(__fsel((a.mY), (notB.mY), (b.mY))),
            T(__fsel((a.mZ), (notB.mZ), (b.mZ)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompAnyTrue(const Mask3Template<T> &a)
{

    T tempResult1 = T(__fsel((a.mX), (a.mX), (a.mY)));
    return MaskScalarTemplate<T>(T(__fsel((tempResult1), (tempResult1), (a.mZ))));
}


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompAllTrue(const Mask3Template<T> &a)
{

    T tempResult1 = T(__fsel((a.mX), (a.mY), (T(-1.0f))));
    return MaskScalarTemplate<T>(T(__fsel((tempResult1), (a.mZ), (T(-1.0f)))));
}

}
}
}
