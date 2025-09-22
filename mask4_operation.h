




#include <rw/math/fpu/mask4.h>



namespace rw
{
namespace math
{
namespace fpu
{


template<class T>
inline __attribute__ ((always_inline)) Mask4Template<T> Not(const Mask4Template<T> &a)
{
    return Mask4Template<T>(
            T(__fsel((a.mX), (T(-1.0f)), (T(1.0f)))),
            T(__fsel((a.mY), (T(-1.0f)), (T(1.0f)))),
            T(__fsel((a.mZ), (T(-1.0f)), (T(1.0f)))),
            T(__fsel((a.mW), (T(-1.0f)), (T(1.0f))))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask4Template<T> And(const Mask4Template<T> &a, const Mask4Template<T> &b)
{
    return Mask4Template<T>(
            T(__fsel((a.mX), (b.mX), (T(-1.0f)))),
            T(__fsel((a.mY), (b.mY), (T(-1.0f)))),
            T(__fsel((a.mZ), (b.mZ), (T(-1.0f)))),
            T(__fsel((a.mW), (b.mW), (T(-1.0f))))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask4Template<T> Or(const Mask4Template<T> &a, const Mask4Template<T> &b)
{
    return Mask4Template<T>(
            T(__fsel((a.mX), (a.mX), (b.mX))),
            T(__fsel((a.mY), (a.mY), (b.mY))),
            T(__fsel((a.mZ), (a.mZ), (b.mZ))),
            T(__fsel((a.mW), (a.mW), (b.mW)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask4Template<T> Xor(const Mask4Template<T> &a, const Mask4Template<T> &b)
{
    Mask4Template<T> notB(Not(b));
    return Mask4Template<T>(
            T(__fsel((a.mX), (notB.mX), (b.mX))),
            T(__fsel((a.mY), (notB.mY), (b.mY))),
            T(__fsel((a.mZ), (notB.mZ), (b.mZ))),
            T(__fsel((a.mW), (notB.mW), (b.mW)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompEqual(const Mask4Template<T> &a, const Mask4Template<T> &b)
{
    Mask4Template<T> notB(Not(b));
    return Mask4Template<T>(
            T(__fsel((a.mX), (b.mX), (notB.mX))),
            T(__fsel((a.mY), (b.mY), (notB.mY))),
            T(__fsel((a.mZ), (b.mZ), (notB.mZ))),
            T(__fsel((a.mW), (b.mW), (notB.mW)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompNotEqual(const Mask4Template<T> &a, const Mask4Template<T> &b)
{
    Mask4Template<T> notB(Not(b));
    return Mask4Template<T>(
            T(__fsel((a.mX), (notB.mX), (b.mX))),
            T(__fsel((a.mY), (notB.mY), (b.mY))),
            T(__fsel((a.mZ), (notB.mZ), (b.mZ))),
            T(__fsel((a.mW), (notB.mW), (b.mW)))
            );
}


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompAnyTrue(const Mask4Template<T> &a)
{

    T tempResult1 = T(__fsel((a.mX), (a.mX), (a.mY)));
    T tempResult2 = T(__fsel((a.mZ), (a.mZ), (a.mW)));
    return MaskScalarTemplate<T>(T(__fsel((tempResult1), (tempResult1), (tempResult2))));
}


template<class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompAllTrue(const Mask4Template<T> &a)
{

    T tempResult1 = T(__fsel((a.mX), (a.mY), (T(-1.0f))));
    T tempResult2 = T(__fsel((a.mZ), (a.mW), (T(-1.0f))));
    return MaskScalarTemplate<T>(T(__fsel((tempResult1), (tempResult2), (T(-1.0f)))));
}

}
}
}
