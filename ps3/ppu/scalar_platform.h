




#include <rw/math/fpu/constants.h>
#include <rw/math/fpu/vec_float.h>

namespace rw {
namespace math {
namespace fpu {

inline bool IsNaN(double value)
{






    bool result;
    asm volatile (
            "fcmpu  7, %1, %1\n"
            "mfcr   %0\n"
            "rlwinm %0,%0,31,1\n"
            : "=r" (result)
            : "f" (value)
            : "cc"
            );
    return !result;
}

inline bool IsNaN(float value) { return IsNaN((double)value); }

}}}
