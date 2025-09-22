












namespace rw
{
namespace math
{
namespace fpu
{


template <class T>
class Mask2Template
{
public:
    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfElement = 2 };
    typedef const Mask2Template<T>& InParam;
    typedef T FloatType;
    typedef T FastFloatType;

public:
    inline __attribute__ ((always_inline)) Mask2Template()
    {
    }

    inline __attribute__ ((always_inline)) Mask2Template(const Mask2Template &v)
        :mX(v.mX)
        ,mY(v.mY)
    {
    }

    inline __attribute__ ((always_inline)) Mask2Template<T>& operator =(const Mask2Template<T> &v)
    {
        this->mX = v.mX;
        this->mY = v.mY;
        return *this;
    }









    inline __attribute__ ((always_inline)) explicit Mask2Template(T x, T y)
        :mX(x)
        ,mY(y)
    {
    }

    inline __attribute__ ((always_inline)) explicit Mask2Template(const MaskScalarTemplate<T> &x, const MaskScalarTemplate<T> &y)
        :mX(x.mS)
        ,mY(y.mS)
    {
    }

    inline __attribute__ ((always_inline)) explicit Mask2Template(bool x, bool y)
        :mX(x ? T(1.0f) : T(-1.0f))
        ,mY(y ? T(1.0f) : T(-1.0f))
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

    void SetX( typename MaskScalarTemplate<T>::InParam v )
    {
        mX = v.mS;
    }

    void SetY( typename MaskScalarTemplate<T>::InParam v )
    {
        mY = v.mS;
    }

public:
    T mX;
    T mY;
};

typedef Mask2Template<float> Mask2;
typedef Mask2Template<float> Mask2_32;
typedef Mask2Template<double> Mask2_64;

}
}
}
