










#include <rw/math/fpu/maskscalar.h>

namespace rw
{
namespace math
{
namespace fpu
{


template <class T>
class Mask4Template
{
public:
    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfElement = 4 };
    typedef const Mask4Template<T>& InParam;
    typedef T FloatType;
    typedef T FastFloatType;

public:
    inline __attribute__ ((always_inline)) Mask4Template()
    {
    }

    inline __attribute__ ((always_inline)) Mask4Template(const Mask4Template &v)
        :mX(v.mX)
        ,mY(v.mY)
        ,mZ(v.mZ)
        ,mW(v.mW)
    {
    }

    inline __attribute__ ((always_inline)) Mask4Template<T>& operator =(const Mask4Template<T> &v)
    {
        this->mX = v.mX;
        this->mY = v.mY;
        this->mZ = v.mZ;
        this->mW = v.mW;
        return *this;
    }











    inline __attribute__ ((always_inline)) explicit Mask4Template(T x, T y, T z, T w)
        :mX(x)
        ,mY(y)
        ,mZ(z)
        ,mW(w)
    {
    }

    inline __attribute__ ((always_inline)) explicit Mask4Template(const MaskScalarTemplate<T> &x, const MaskScalarTemplate<T> &y, const MaskScalarTemplate<T> &z, const MaskScalarTemplate<T> &w)
        :mX(x.mS)
        ,mY(y.mS)
        ,mZ(z.mS)
        ,mW(w.mS)
    {
    }

    inline __attribute__ ((always_inline)) explicit Mask4Template(bool x, bool y, bool z, bool w)
        :mX(x ? T(1.0f) : T(-1.0f))
        ,mY(y ? T(1.0f) : T(-1.0f))
        ,mZ(z ? T(1.0f) : T(-1.0f))
        ,mW(w ? T(1.0f) : T(-1.0f))
    {
    }

    MaskScalarTemplate<T> GetX() const
    {
        return MaskScalarTemplate<T>(mX);
    }

    MaskScalarTemplate<T> GetY() const
    {
        return MaskScalarTemplate<T>(mY);
    }

    MaskScalarTemplate<T> GetZ() const
    {
        return MaskScalarTemplate<T>(mZ);
    }

    MaskScalarTemplate<T> GetW() const
    {
        return MaskScalarTemplate<T>(mW);
    }

    void SetX( typename MaskScalarTemplate<T>::InParam v )
    {
        mX = v.mS;
    }

    void SetY( typename MaskScalarTemplate<T>::InParam v )
    {
        mY = v.mS;
    }

    void SetZ( typename MaskScalarTemplate<T>::InParam v )
    {
        mZ = v.mS;
    }

    void SetW( typename MaskScalarTemplate<T>::InParam v )
    {
        mW = v.mS;
    }

public:
    T mX;
    T mY;
    T mZ;
    T mW;
};

typedef Mask4Template<float> Mask4;
typedef Mask4Template<float> Mask4_32;
typedef Mask4Template<double> Mask4_64;

}
}
}
