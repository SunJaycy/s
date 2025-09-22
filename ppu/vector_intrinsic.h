




#include <rw/math/detail/base.h>


namespace rw {
namespace math {
namespace vpu {

typedef __attribute__((altivec(vector__))) float VectorIntrinsic;
typedef VectorIntrinsic VectorIntrinsicInParam;

namespace detail
{
    extern const VectorIntrinsic gQuatFromMat_xSigns;
    extern const VectorIntrinsic gQuatFromMat_ySigns;
    extern const VectorIntrinsic gQuatFromMat_zSigns;
    extern const VectorIntrinsic gXYZMask;
    extern const VectorIntrinsic gGatherMostSignificantBytesV3;
    extern const VectorIntrinsic gGatherMostSignificantBytesV4;
    extern const VectorIntrinsic gSqrt2s;
    extern const VectorIntrinsic gIVector;
    extern const VectorIntrinsic gJVector;
    extern const VectorIntrinsic gKVector;
    extern const VectorIntrinsic gLVector;
    extern const VectorIntrinsic gCrossProductPermuteConstant;
    extern const VectorIntrinsic gHalfPI;
    extern const VectorIntrinsic gPI;
    extern const VectorIntrinsic g2PI;
    extern const VectorIntrinsic g2PIReciprocal;


    const size_t NUM_SWIZZLE_STORE_CONSTANTS = 16;
    extern const VectorIntrinsic gSwizzleStoreConstants[NUM_SWIZZLE_STORE_CONSTANTS];
    extern const VectorIntrinsic gBooleanConstants[2];

}

}}}
