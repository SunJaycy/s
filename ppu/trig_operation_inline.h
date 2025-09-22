




#include <math.h>


#include <rw/math/vpu/constants.h>
#include <rw/math/vpu/constants_operation.h>
#include <rw/math/vpu/vector4.h>
#include <bits/sce_math.h>

namespace rw {
namespace math {
namespace vpu {

inline VecFloat DegToRad(VecFloat::InParam angle_degrees)
{
    return Mult(angle_degrees, DEGREES_TO_RADIANS);
}

inline VecFloat RadToDeg(VecFloat::InParam angle_radians)
{
    return Mult(angle_radians, RADIANS_TO_DEGREES);
}

inline VecFloat Sin(VecFloat::InParam a)
{
    return VecFloat(sinf4(a.mV));
}

inline VecFloat Cos(VecFloat::InParam a)
{
    return VecFloat(cosf4(a.mV));
}

inline VecFloat Tan(VecFloat::InParam a)
{
    return VecFloat(tanf4(a.mV));
}

inline VecFloat ASin(VecFloat::InParam a)
{
    return VecFloat(asinf4(a.mV));
}

inline VecFloat ACos(VecFloat::InParam a)
{
    return VecFloat(acosf4(a.mV));
}

inline VecFloat ATan(VecFloat::InParam a)
{
    return VecFloat(atanf4(a.mV));
}

inline VecFloat ATan2(VecFloat::InParam a, VecFloat::InParam b)
{
    VectorIntrinsic result;
    { VectorIntrinsic zeroVec = (::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(0)); VectorIntrinsic signBit; signBit = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(static_cast<signed char>(-1))); signBit = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vslw((__attribute__((altivec(vector__))) signed int)(signBit),(__attribute__((altivec(vector__))) signed int)(signBit));; VectorIntrinsic a_signBit = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vand((__attribute__((altivec(vector__))) signed int)((__attribute__((altivec(vector__))) signed int)a.mV), (__attribute__((altivec(vector__))) signed int)(signBit)); VectorIntrinsic bNeg = (__attribute__((altivec(vector__))) float)__builtin_altivec_vcmpgtfp((zeroVec), (b.mV)); VectorIntrinsic bZero = (__attribute__((altivec(vector__))) float)__builtin_altivec_vcmpeqfp((__attribute__((altivec(vector__))) float)(zeroVec), (__attribute__((altivec(vector__))) float)(b.mV)); VectorIntrinsic res1 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vor((__attribute__((altivec(vector__))) signed int)((__attribute__((altivec(vector__))) signed int)::rw::math::vpu::detail::gHalfPI), (__attribute__((altivec(vector__))) signed int)(a_signBit)); VectorIntrinsic bRecip; { ::rw::math::vpu::VectorIntrinsic estimate, vOne; estimate = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vrefp((__attribute__((altivec(vector__))) float)(b.mV));; vOne = (::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vcfsx((__attribute__((altivec(vector__))) signed int)((::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(1))), (0)); ; bRecip = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((estimate), ((::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vnmsubfp((estimate), (b.mV), (vOne))), (estimate)); }; VectorIntrinsic res2 = atanf4( (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((a.mV), (bRecip), (zeroVec)) ); VectorIntrinsic b_signBit = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vand((__attribute__((altivec(vector__))) signed int)((__attribute__((altivec(vector__))) signed int)a.mV), (__attribute__((altivec(vector__))) signed int)(signBit)); VectorIntrinsic newRes = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vaddfp((::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vor((__attribute__((altivec(vector__))) signed int)((__attribute__((altivec(vector__))) signed int)::rw::math::vpu::detail::gPI), (__attribute__((altivec(vector__))) signed int)(b_signBit)), res2); res2 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vsel_4sf((__attribute__((altivec(vector__))) float)(res2), (__attribute__((altivec(vector__))) float)(newRes), (__attribute__((altivec(vector__))) signed int)(bNeg)); result = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vsel_4sf((__attribute__((altivec(vector__))) float)(res2), (__attribute__((altivec(vector__))) float)(res1), (__attribute__((altivec(vector__))) signed int)(bZero)); };
    return VecFloat(result);
}

inline VecFloat NormalizeAngle(VecFloat::InParam a)
{
    VectorIntrinsic floorScaledAngle, scaledAngle, angle, valueToSubtract, scaledAngleGreaterMask;
    scaledAngle = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((a.mV), (rw::math::vpu::detail::g2PIReciprocal), ((::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(0))));;
    floorScaledAngle = __builtin_altivec_vrfim((__attribute__((altivec(vector__))) float)(scaledAngle));
    scaledAngle = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vsubfp( scaledAngle, floorScaledAngle );






    scaledAngleGreaterMask = (__attribute__((altivec(vector__))) float)__builtin_altivec_vcmpgtfp((scaledAngle), (((::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vcfsx((__attribute__((altivec(vector__))) signed int)((::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(1))), (1)))));
    valueToSubtract = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vand((__attribute__((altivec(vector__))) signed int)(scaledAngleGreaterMask), (__attribute__((altivec(vector__))) signed int)(((::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vcfsx((__attribute__((altivec(vector__))) signed int)((::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(1))), (0)))));
    scaledAngle = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vsubfp( scaledAngle, valueToSubtract );

    angle = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((scaledAngle), (rw::math::vpu::detail::g2PI), ((::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(0))));
    return VecFloat(angle);
}

inline void SinCos(VecFloat::InParam a, VecFloat& s_out, VecFloat& c_out)
{
    return sincosf4(a.mV, (VectorIntrinsic *)&s_out, (VectorIntrinsic *)&c_out);
}

inline Vector4 SinCos(VecFloat::InParam a)
{

    return Vector4( Sin(a), Cos(a), GetVecFloat_Zero(), GetVecFloat_Zero() );
}

inline Vector4 SinCosFast(VecFloat::InParam a)
{

    return SinCos(a);
}


inline Vector4 SinCosFast2(VecFloat::InParam a, VecFloat::InParam b)
{

    return Vector4( Sin(a), Cos(a), Sin(b), Cos(b) );
}

}}}
