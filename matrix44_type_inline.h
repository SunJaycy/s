












#include <rw/math/fpu/matrix44.h>
#include <rw/math/fpu/matrix44affinepacked.h>
#include <rw/math/fpu/matrix44affine.h>

namespace rw
{
namespace math
{
namespace fpu
{

    template <class T>
    template <class INPUT_T>
    Matrix44Template<T>::Matrix44Template(const Matrix44AffineTemplate<INPUT_T> &_v)
        :xAxis( Vector4Template<T>(_v.xAxis, static_cast<T>(0.0f)) )
        ,yAxis( Vector4Template<T>(_v.yAxis, static_cast<T>(0.0f)) )
        ,zAxis( Vector4Template<T>(_v.zAxis, static_cast<T>(0.0f)) )
        ,wAxis( Vector4Template<T>(_v.wAxis, static_cast<T>(1.0f)) )
    {
    }

    template <class T>
    template <class INPUT_T>
    Matrix44Template<T>::Matrix44Template(const Matrix44AffinePackedTemplate<INPUT_T> &m)
        :xAxis( Vector4Template<T>(static_cast<T>(m.xAxis.x), static_cast<T>(m.yAxis.x), static_cast<T>(m.zAxis.x), static_cast<T>(0.0f)) )
        ,yAxis( Vector4Template<T>(static_cast<T>(m.xAxis.y), static_cast<T>(m.yAxis.y), static_cast<T>(m.zAxis.y), static_cast<T>(0.0f)) )
        ,zAxis( Vector4Template<T>(static_cast<T>(m.xAxis.z), static_cast<T>(m.yAxis.z), static_cast<T>(m.zAxis.z), static_cast<T>(0.0f)) )
        ,wAxis( Vector4Template<T>(static_cast<T>(m.xAxis.w), static_cast<T>(m.yAxis.w), static_cast<T>(m.zAxis.w), static_cast<T>(1.0f)) )
    {
    }

}
}
}
