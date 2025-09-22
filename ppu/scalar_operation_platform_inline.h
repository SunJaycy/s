




#include <rw/math/vpu/vec_float_operation.h>

namespace rw
{

namespace math
{

namespace vpu
{

template <>
inline __attribute__ ((always_inline)) float Min<float>(const float& a, const float& b)
{
    float test = a - b;
    float r;
    __asm__ ("fsel %0, %1, %2, %3" : "=f" (r) : "f" (test), "f" (b), "f" (a));
    return r;
}

template <>
inline __attribute__ ((always_inline)) float Max<float>(const float& a, const float& b)
{
    float test = a - b;
    float r;
    __asm__ ("fsel %0, %1, %2, %3" : "=f" (r) : "f" (test), "f" (a), "f" (b));
    return r;
}

template <>
inline __attribute__ ((always_inline)) double Min<double>(const double& a, const double& b)
{
    double test = a - b;
    double r;
    __asm__ ("fsel %0, %1, %2, %3" : "=f" (r) : "f" (test), "f" (b), "f" (a));
    return r;
}

template <>
inline __attribute__ ((always_inline)) double Max<double>(const double& a, const double& b)
{
    double test = a - b;
    double r;
    __asm__ ("fsel %0, %1, %2, %3" : "=f" (r) : "f" (test), "f" (a), "f" (b));
    return r;
}



template <>
inline __attribute__ ((always_inline)) float Abs<float>(const float& a)
{
    float r;
    __asm__ ("fabs %0, %1" : "=f" (r) : "f" (a));
    return r;
}


template <>
inline __attribute__ ((always_inline)) double Abs<double>(const double& a)
{
    float r;
    __asm__ ("fabs %0, %1" : "=f" (r) : "f" (a));
    return r;
}


inline bool IsNaN(VecFloat::InParam value)
{





    return !_asmIsEqualV4( value.mV, value.mV );
}

inline int32_t FastFloatToInt32(float a)
{
    return (int32_t)a;
}

inline VecFloat Sgn(VecFloat::InParam a)
{

    VectorIntrinsic zero = ((::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(0)));
    VectorIntrinsic one = ((::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vcfsx((__attribute__((altivec(vector__))) signed int)((::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(1))), (0)));
    VectorIntrinsic negOne = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vsubfp( zero, one );


    VectorIntrinsic greaterThanZeroMask = (__attribute__((altivec(vector__))) float)__builtin_altivec_vcmpgtfp((a.mV), (zero));

    VectorIntrinsic result0 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vsel_4sf((__attribute__((altivec(vector__))) float)(zero), (__attribute__((altivec(vector__))) float)(one), (__attribute__((altivec(vector__))) signed int)(greaterThanZeroMask));

    VectorIntrinsic greaterEqualThanZeroMask = (__attribute__((altivec(vector__))) float)__builtin_altivec_vcmpgefp((a.mV), (zero));

    return VecFloat((::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vsel_4sf((__attribute__((altivec(vector__))) float)(negOne), (__attribute__((altivec(vector__))) float)(result0), (__attribute__((altivec(vector__))) signed int)(greaterEqualThanZeroMask)));
}

inline __attribute__ ((always_inline)) bool IsZero(VecFloat::InParam v, VecFloat::InParam tolerance)
{
    return (bool)__builtin_altivec_vcmpgefp_p(2, (__attribute__((altivec(vector__))) float)(tolerance.mV), (__attribute__((altivec(vector__))) float)(Abs(v).mV));
}

template<VectorAxis INDEX>
inline bool IsZero(VecFloatRef<INDEX> value, VecFloat::InParam tolerance)
{
    return IsZero(VecFloat(value), tolerance);
}

inline __attribute__ ((always_inline)) bool IsSimilar(VecFloatRefIndex::InParam a, VecFloat::InParam b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

inline bool IsSimilar(VecFloat::InParam a, VecFloat::InParam b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

template<VectorAxis INDEX>
inline __attribute__ ((always_inline)) bool IsSimilar(VecFloat::InParam a, VecFloatRef<INDEX> b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

inline __attribute__ ((always_inline)) bool IsSimilar(VecFloat::InParam a, VecFloatRefIndex::InParam b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

inline __attribute__ ((always_inline)) bool IsSimilar(VecFloat::InParam a, const float& b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}



template<VectorAxis INDEX>
inline __attribute__ ((always_inline)) bool IsSimilar(VecFloatRef<INDEX> a, VecFloat::InParam b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

template<VectorAxis INDEX1, VectorAxis INDEX2>
inline __attribute__ ((always_inline)) bool IsSimilar(VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

template<VectorAxis INDEX>
inline __attribute__ ((always_inline)) bool IsSimilar(VecFloatRef<INDEX> a, VecFloatRefIndex::InParam b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

template<VectorAxis INDEX>
inline __attribute__ ((always_inline)) bool IsSimilar(VecFloatRef<INDEX> a, const float& b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}



template<VectorAxis INDEX>
inline __attribute__ ((always_inline)) bool IsSimilar(VecFloatRefIndex::InParam a, VecFloatRef<INDEX> b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

inline __attribute__ ((always_inline)) bool IsSimilar(VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

inline __attribute__ ((always_inline)) bool IsSimilar(VecFloatRefIndex::InParam a, const float& b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}


inline __attribute__ ((always_inline)) bool IsSimilar(const float& a, VecFloat::InParam b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

template<VectorAxis INDEX>
inline __attribute__ ((always_inline)) bool IsSimilar(const float& a, VecFloatRef<INDEX> b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

inline __attribute__ ((always_inline)) bool IsSimilar(const float& a, VecFloatRefIndex::InParam b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

inline __attribute__ ((always_inline)) bool IsSimilar(const float& a, const float& b, VecFloat::InParam epsilon)
{
    return IsZero(Subtract(a, b), epsilon);
}

}

}

}
