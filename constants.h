










namespace rw
{
namespace math
{
namespace fpu
{

#include <rw/math/detail/define_constants.h>


const int32_t TOP_BIT32 = 0x80000000;


const int32_t NOT_TOP_BIT32 = ~TOP_BIT32;


const int64_t TOP_BIT64 = (int64_t(1) << 63);


const int64_t NOT_TOP_BIT64 = ~TOP_BIT64;


const int32_t MAX_INT32 = (1u << 31) - 1;


const int32_t MIN_INT32 = -MAX_INT32 - 1;


const float MIN_FLOAT = 1.17549435e-38f;


const float MAX_FLOAT = 3.402823466e+38f;









const float SMALL_FLOAT = (1.0f/65536.0f);


const float DEGREES_TO_RADIANS = 0.01745329252f;


const float RADIANS_TO_DEGREES = 57.29577951f;


const float E = 2.7182818284590452354f;


const float PI = 3.14159265358979323846f;


const float TWO_PI = 2.0f * 3.14159265358979323846f;


const float HALF_PI = 1.57079632679489661923f;


const float QUARTER_PI = 0.78539816339744830962f;


const float SQRT_PI = 1.77245385090551602792981f;


const float INV_PI = 0.31830988618379067154f;


const float SQRT_2 = 1.41421356237309504880f;


const float SQRT_HALF = 0.70710678118654752440f;


const float SQRT_3 = 1.73205080756887719000f;


const float ZERO_FLOAT = 0.0f;


const uint32_t FLOAT_ONE_AS_UINT32 = 0x3800000;








const float VECTOR_MIN_SLERP_ANGLE = ((5.0f * 3.14159265358979323846f) / 180.0f);








const float MATRIX_MIN_SLERP_ANGLE = 2.0f * 0.01745329252f;


const float QUATERNION_SLERP_DOT_TOLERANCE = 0.999f;











const float MINIMUM_RECIPROCAL = 1.0f / 3.402823466e+38f;


const float EPSILON = 1.192092896e-07f;


const float ONE_MINUS_EPSILON = 1.0f - 1.192092896e-07f;


const float TOLERANCE = 0.001f;

#include <rw/math/detail/undefine_constants.h>

}
}
}
