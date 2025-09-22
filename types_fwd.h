









#include <rw/math/vpu/vector_intrinsic.h>
#include <rw/math/vpu/vector_axis.h>
#include <rw/math/version.h>

namespace rw {
namespace math {
namespace fpu {

    template <class T> class MaskScalarTemplate;
    template <class T> class Mask2Template;
    template <class T> class Mask3Template;
    template <class T> class Mask4Template;
    template <class T> class Vector2Template;
    template <class T> class Vector3Template;
    template <class T> class Vector4Template;
    template <class T> class Vector3PlusTemplate;
    template <class T> class QuaternionTemplate;
    template <class T> class QuatPosTemplate;
    template <class T> class PlaneTemplate;
    template <class T> class Matrix33Template;
    template <class T> class Matrix44Template;
    template <class T> class Matrix44AffineTemplate;
    template <class T> class Matrix44AffinePackedTemplate;

    typedef MaskScalarTemplate<float> MaskScalar;
    typedef Mask2Template<float> Mask2;
    typedef Mask3Template<float> Mask3;
    typedef Mask4Template<float> Mask4;
    typedef Vector2Template<float> Vector2;
    typedef Vector3Template<float> Vector3;
    typedef Vector4Template<float> Vector4;
    typedef Vector3PlusTemplate<float> Vector3Plus;
    typedef QuaternionTemplate<float> Quaternion;
    typedef QuatPosTemplate<float> QuatPos;
    typedef PlaneTemplate<float> Plane;
    typedef Matrix33Template<float> Matrix33;
    typedef Matrix44Template<float> Matrix44;
    typedef Matrix44AffineTemplate<float> Matrix44Affine;
    typedef Matrix44AffinePackedTemplate<float> Matrix44AffinePacked;
}

namespace vpu
{

    class VecFloat;
    class VecFloatRefIndex;
    template<VectorAxis INDEX> class VecFloatRef;

    class MaskScalar;
    class Mask2;
    class Mask3;
    class Mask4;
    class Vector2;
    class Vector3;
    class Vector4;
    class Vector3Plus;
    class Quaternion;
    class QuatPos;
    class Plane;

    class Matrix33;
    class Matrix44;
    class Matrix44Affine;
    class Matrix44AffinePacked;
}

using namespace ::rw::math::vpu;

}}
