





#include <rw/math/vpu/vector_axis.h>

namespace rw {
namespace math {
namespace vpu {



inline __attribute__ ((always_inline)) bool _asmIsEqualV4(VectorIntrinsicInParam v0, VectorIntrinsicInParam v1);
inline __attribute__ ((always_inline)) bool _asmIsEqualV3(VectorIntrinsicInParam v0, VectorIntrinsicInParam v1);
inline __attribute__ ((always_inline)) bool _asmIsEqualV2(VectorIntrinsicInParam v0, VectorIntrinsicInParam v1);

inline __attribute__ ((always_inline)) VectorIntrinsic _asmIsGreaterEqual(VectorIntrinsicInParam v0, VectorIntrinsicInParam v1);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmSelect(VectorIntrinsicInParam v0, VectorIntrinsicInParam v1, VectorIntrinsicInParam mask);

inline __attribute__ ((always_inline)) bool _asmIsZeroV4(VectorIntrinsicInParam v,
                                VectorIntrinsicInParam tolerance);
inline __attribute__ ((always_inline)) bool _asmIsZeroV4(VectorIntrinsicInParam x,
                                VectorIntrinsicInParam y,
                                VectorIntrinsicInParam z,
                                VectorIntrinsicInParam w,
                                VectorIntrinsicInParam tolerance);
inline __attribute__ ((always_inline)) bool _asmIsZeroV2(VectorIntrinsicInParam v,
                                VectorIntrinsicInParam tolerance);
inline __attribute__ ((always_inline)) bool _asmIsZeroV3(VectorIntrinsicInParam x,
                                VectorIntrinsicInParam y,
                                VectorIntrinsicInParam z,
                                VectorIntrinsicInParam tolerance);
inline __attribute__ ((always_inline)) bool _asmIsSimilarV4(VectorIntrinsicInParam v0,
                                   VectorIntrinsicInParam v1,
                                   VectorIntrinsicInParam tolerance);
inline __attribute__ ((always_inline)) bool _asmIsSimilarV2(VectorIntrinsicInParam v0,
                                   VectorIntrinsicInParam v1,
                                   VectorIntrinsicInParam tolerance);
inline __attribute__ ((always_inline)) bool _asmIsSimilarV3(VectorIntrinsicInParam v0,
                                   VectorIntrinsicInParam v1,
                                   VectorIntrinsicInParam tolerance);
inline __attribute__ ((always_inline)) bool _asmIsSimilarV3(VectorIntrinsicInParam x0,
                                   VectorIntrinsicInParam y0,
                                   VectorIntrinsicInParam z0,
                                   VectorIntrinsicInParam x1,
                                   VectorIntrinsicInParam y1,
                                   VectorIntrinsicInParam z1,
                                   VectorIntrinsicInParam tolerance);
inline __attribute__ ((always_inline)) bool _asmIsSimilarV3(VectorIntrinsicInParam x0,
                                   VectorIntrinsicInParam y0,
                                   VectorIntrinsicInParam z0,
                                   VectorIntrinsicInParam w0,
                                   VectorIntrinsicInParam x1,
                                   VectorIntrinsicInParam y1,
                                   VectorIntrinsicInParam z1,
                                   VectorIntrinsicInParam w1,
                                   VectorIntrinsicInParam tolerance);
template<VectorAxis INDEX_DEST, VectorAxis INDEX_SRC>
inline __attribute__ ((always_inline)) VectorIntrinsic _asmSwizzleStore(VectorIntrinsicInParam dest, VectorIntrinsicInParam src);
template<VectorAxis INDEX_DEST>
inline __attribute__ ((always_inline)) VectorIntrinsic _asmSwizzleStore(VectorIntrinsicInParam dest, VectorIntrinsicInParam src, VectorAxis srcIndex);
template<VectorAxis INDEX_SRC>
inline __attribute__ ((always_inline)) VectorIntrinsic _asmSwizzleStore(VectorIntrinsicInParam dest, VectorAxis destIndex, VectorIntrinsicInParam src);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmSwizzleStore(VectorIntrinsicInParam dest, VectorAxis destIndex, VectorIntrinsicInParam src, VectorAxis srcIndex);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmMultAdd(VectorIntrinsicInParam a, VectorIntrinsicInParam b, VectorIntrinsicInParam c);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmMult(VectorIntrinsicInParam a, VectorIntrinsicInParam b);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmSubtract(VectorIntrinsicInParam a, VectorIntrinsicInParam b);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmGetZero();
inline __attribute__ ((always_inline)) VectorIntrinsic _asmGetOne();
template<VectorAxis INDEX>
inline __attribute__ ((always_inline)) VectorIntrinsic _asmSplat(VectorIntrinsicInParam v );
inline __attribute__ ((always_inline)) VectorIntrinsic _asmSplat(VectorIntrinsicInParam v, VectorAxis index );
inline __attribute__ ((always_inline)) VectorIntrinsic _asmReciprocalSquareRootEstimate(VectorIntrinsicInParam v);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmReciprocalEstimate(VectorIntrinsicInParam in);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmReciprocalFast(VectorIntrinsicInParam in);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmReciprocal(VectorIntrinsicInParam in);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmDot(VectorIntrinsicInParam v0, VectorIntrinsicInParam v1);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmDotV3(VectorIntrinsicInParam v0, VectorIntrinsicInParam v1);
inline __attribute__ ((always_inline)) VectorIntrinsic _asmDotV2(VectorIntrinsicInParam v0, VectorIntrinsicInParam v1);


}

using namespace rw::math::vpu;

}}



#include <rw/math/vpu/detail/vector_intrinsic_operation_inline.h>
