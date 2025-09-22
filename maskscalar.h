








#include <rw/math/detail/base.h>

#include <rw/math/fpu/vec_float.h>

namespace rw
{
namespace math
{
namespace fpu
{


template <class T>
class MaskScalarTemplate
{
public:
    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfElement = 1 };
    typedef const MaskScalarTemplate<T>& InParam;
    typedef T FloatType;
    typedef T FastFloatType;

public:
    inline __attribute__ ((always_inline)) MaskScalarTemplate()
    {
    }

    inline __attribute__ ((always_inline)) MaskScalarTemplate(const MaskScalarTemplate<T> &v)
        :mS(v.mS)
    {
    }

    inline __attribute__ ((always_inline)) MaskScalarTemplate<T>& operator =(const MaskScalarTemplate<T> &v)
    {
        this->mS = v.mS;
        return *this;
    }






    inline __attribute__ ((always_inline)) explicit MaskScalarTemplate(T v)
        :mS(v)
    {
    }

    inline __attribute__ ((always_inline)) explicit MaskScalarTemplate(bool v)
        :mS( v ? T(1.0f) : T(-1.0f) )
    {
    }

    inline __attribute__ ((always_inline)) bool GetBool() const
    {
        return ( mS >= T(0.0f) );
    }

public:
    T mS;
};

typedef MaskScalarTemplate<float> MaskScalar;
typedef MaskScalarTemplate<float> MaskScalar_32;
typedef MaskScalarTemplate<double> MaskScalar_64;

}
}
}
