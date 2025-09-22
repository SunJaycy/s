












#include <rw/math/fpu/matrix44affine.h>



namespace rw
{
namespace math
{
namespace fpu
{

    template <class T>
    template <class INPUT_T>
    Matrix44AffineTemplate<T>::Matrix44AffineTemplate(const Matrix44AffinePackedTemplate<INPUT_T> &m)
        :xAxis(Vector3Template<T>(static_cast<T>(m.xAxis.x), static_cast<T>(m.yAxis.x), static_cast<T>(m.zAxis.x)))
        ,yAxis(Vector3Template<T>(static_cast<T>(m.xAxis.y), static_cast<T>(m.yAxis.y), static_cast<T>(m.zAxis.y)))
        ,zAxis(Vector3Template<T>(static_cast<T>(m.xAxis.z), static_cast<T>(m.yAxis.z), static_cast<T>(m.zAxis.z)))
        ,wAxis(Vector3Template<T>(static_cast<T>(m.xAxis.w), static_cast<T>(m.yAxis.w), static_cast<T>(m.zAxis.w)))
    {
    }

    template <class T>
    template <class INPUT_T>
    Matrix44AffineTemplate<T>::Matrix44AffineTemplate(const Matrix44Template<INPUT_T> &m)
        :xAxis(Vector3Template<T>(static_cast<T>(m.xAxis.x), static_cast<T>(m.xAxis.y), static_cast<T>(m.xAxis.z)))
        ,yAxis(Vector3Template<T>(static_cast<T>(m.yAxis.x), static_cast<T>(m.yAxis.y), static_cast<T>(m.yAxis.z)))
        ,zAxis(Vector3Template<T>(static_cast<T>(m.zAxis.x), static_cast<T>(m.zAxis.y), static_cast<T>(m.zAxis.z)))
        ,wAxis(Vector3Template<T>(static_cast<T>(m.wAxis.x), static_cast<T>(m.wAxis.y), static_cast<T>(m.wAxis.z)))
    {
        ;





    }


}
}
}

#include <rw/math/fpu/detail/matrix44affine_type_inline.h>
