












namespace rw
{
namespace math
{
namespace fpu
{


template <class T>
class Mask3Template
{
public:
    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfElement = 3 };
    typedef const Mask3Template<T>& InParam;
    typedef T FloatType;
    typedef T FastFloatType;

public:
    inline __attribute__ ((always_inline)) Mask3Template()
    {
    }

    inline __attribute__ ((always_inline)) Mask3Template(const Mask3Template &v)
        :mX(v.mX)
        ,mY(v.mY)
        ,mZ(v.mZ)
    {
    }

    inline __attribute__ ((always_inline)) Mask3Template<T>& operator =(const Mask3Template<T> &v)
    {
        this->mX = v.mX;
        this->mY = v.mY;
        this->mZ = v.mZ;
        return *this;
    }










    inline __attribute__ ((always_inline)) explicit Mask3Template(T x, T y, T z)
        :mX(x)
        ,mY(y)
        ,mZ(z)
    {
    }

    inline __attribute__ ((always_inline)) explicit Mask3Template(const MaskScalarTemplate<T> &x, const MaskScalarTemplate<T> &y, const MaskScalarTemplate<T> &z)
        :mX(x.mS)
        ,mY(y.mS)
        ,mZ(z.mS)
    {
    }

    inline __attribute__ ((always_inline)) explicit Mask3Template(bool x, bool y, bool z)
        :mX(x ? T(1.0f) : T(-1.0f))
        ,mY(y ? T(1.0f) : T(-1.0f))
        ,mZ(z ? T(1.0f) : T(-1.0f))
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

public:
    T mX;
    T mY;
    T mZ;
};

typedef Mask3Template<float> Mask3;
typedef Mask3Template<float> Mask3_32;
typedef Mask3Template<double> Mask3_64;

}
}
}
