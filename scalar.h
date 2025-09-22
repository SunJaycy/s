




#include <rw/math/fpu/constants.h>
#include <rw/math/fpu/scalar_platform.h>

#include <rw/math/fpu/maskscalar_operation.h>



#include <rw/math/fpu/detail/ps3/ppu/ppu_math_intrinsics.h>


namespace rw {
namespace math {
namespace fpu {

template <class T> inline int32_t FastFloatToInt32(T a)
{
    return (int32_t)a;
}

template <class T> inline T Floor(T a)
{
    return (T)Floor(static_cast<double>(a));
}

template <> inline __attribute__ ((always_inline)) float Floor<float>(float a)
{



    const double maxMantissa = 4503599627370496.0;
    const double doubleInput = a;
    double c = __fsel((doubleInput), (-maxMantissa), (maxMantissa));
    double result = (doubleInput-c) + c;
    result -= __fsel((doubleInput-result), (0.0), (1.0));
    return static_cast<float>(result);



}

template <> inline double Floor<double>(double a)
{


    const double maxMantissa = 4503599627370496.0;
    double c = __fsel((a), (-maxMantissa), (maxMantissa));
    double result = (a-c) + c;
    result -= __fsel((a-result), (0.0), (1.0));
    return result;



}

template <class T> inline int32_t IntFloor(T a)
{
    return (int) Floor(a);
}

template <class T> inline T Ceil(T a)
{
    return Ceil(a);
}
template <> inline float Ceil<float>(float a) { return ceilf(a); }
template <> inline double Ceil<double>(double a) { return ceil(a); }

template <class T> inline int32_t IntCeil(T a)
{
    return (int) Ceil(a);
}

template <class T> inline T Round(T a)
{
    return Floor(a + 0.5f);
}
template <class T> inline int32_t IntRound(T a)
{
    return IntFloor(a + 0.5f);
}

template <class T> inline T Modulo(T a, T modulus)
{
    ;
    T modulo = a - ( (T)( (int)( ( a / modulus ) ) ) * modulus );
    return modulo;
}

template <class T> inline T Abs(const T& a) { return a >= static_cast<T>(0.0f) ? a : -a; }
template <> inline float Abs<float>(const float& a)
{






        float r;
        __asm__ ("fabs %0, %1" : "=f" (r) : "f" (a));
        return r;








}
template <> inline double Abs<double>(const double& a)
{






        float r;
        __asm__ ("fabs %0, %1" : "=f" (r) : "f" (a));
        return r;









}

template <class T> inline __attribute__ ((always_inline)) T Min(const T& a, const T& b)
{
    return (a < b? a : b);
}

template <> inline __attribute__ ((always_inline)) float Min(const float& a, const float& b)
{






        float test = a - b;
        float r;
        __asm__ ("fsel %0, %1, %2, %3" : "=f" (r) : "f" (test), "f" (b), "f" (a));
        return r;














}

template <> inline __attribute__ ((always_inline)) double Min(const double& a, const double& b)
{






        float test = a - b;
        float r;
        __asm__ ("fsel %0, %1, %2, %3" : "=f" (r) : "f" (test), "f" (b), "f" (a));
        return r;















}

template <class T> inline __attribute__ ((always_inline)) T Min(const T& a, const T& b, const T& c)
{
    return Min(Min(a, b), c);
}

template <class T> inline __attribute__ ((always_inline)) T Max(const T& a, const T& b)
{
    return (a > b? a : b);
}

template <> inline __attribute__ ((always_inline)) float Max(const float& a, const float& b)
{






        float test = a - b;
        float r;
        __asm__ ("fsel %0, %1, %2, %3" : "=f" (r) : "f" (test), "f" (a), "f" (b));
        return r;















}

template <> inline __attribute__ ((always_inline)) double Max(const double& a, const double& b)
{






        float test = a - b;
        float r;
        __asm__ ("fsel %0, %1, %2, %3" : "=f" (r) : "f" (test), "f" (a), "f" (b));
        return r;















}

template <class T> inline __attribute__ ((always_inline)) T Max(const T& a, const T& b, const T& c) { return Max(Max(a, b), c); }

template <class T> inline T Lerp(T a, T b, T t)
{
    ;
    return a + (b-a) * t;
}

template <class T> inline T Reciprocal(T a)
{
    return 1.0f / a;
}

template <class T> inline T ReciprocalFast(T a)
{
    return Reciprocal(a);
}

template <class T> inline T SqrtFast(T a)
{
    return Sqrt(a);
}

template <class T> inline T Sqrt(T a)
{
    return Sqrt(a);
}
template <> inline float Sqrt<float>(float a)
{

    return __fsqrts(a);



}

template <> inline double Sqrt<double>(double a)
{

    return __fsqrt(a);



}

template <class T> inline T InvSqrt(T a)
{
    return InvSqrt(a);
}
template <> inline float InvSqrt<float>(float a) { return 1.0f/Sqrt(a); }
template <> inline double InvSqrt<double>(double a) { return 1.0f/Sqrt(a); }

template <class T> inline T InvSqrtFast(T a)
{
    return InvSqrt(a);
}
template <class T> inline T DivSqrt(T a, T dividend)
{
    ;
    return dividend / Sqrt( a );
}
template <class T> inline T DivSqrtFast(T a, T dividend)
{
    return DivSqrt(a, dividend);
}
template <class T> inline T Pow(T base, T exponant);
template <> inline float Pow<float>(float base, float exponant) { return powf(base, exponant); }
template <> inline double Pow<double>(double base, double exponant) { return pow(base, exponant); }

template <class T> inline T Clamp(T value, T min, T max)
{
    return Min(max, Max(min, value));
}

template <class T> inline T Log(T a)
{

    return static_cast<T>(Log(static_cast<float>(a)));

}
template <> inline float Log<float>(float a) { return logf(a); }
template <> inline double Log<double>(double a) { return log(a); }


template <class T> inline T Exp(T a)
{

    return static_cast<T>(Exp(static_cast<float>(a)));
}
template <> inline float Exp<float>(float a) { return expf(a); }
template <> inline double Exp<double>(double a) { return exp(a); }


template <class T> inline T Sgn(T a)
{
    if( a == 0.0f )
    {
        return 0.0f;
    }
    else if( a >= 0.0f )
    {
        return 1.0f;
    }
    else
    {
        return -1.0f;
    }
}

template <class T> inline T SgnNonZero(T a)
{
    if( a >= 0.0f )
    {
        return 1.0f;
    }
    else
    {
        return -1.0f;
    }
}

inline bool IsValid(float value) { return !IsNaN(value); }
inline bool IsValid(double value) { return !IsNaN(value); }

inline bool IsZero(float value, float tolerance = EPSILON) { return (value <= tolerance) && (value >= -tolerance); }
inline bool IsZero(double value, double tolerance = EPSILON) { return (value <= tolerance) && (value >= -tolerance); }

inline bool IsSimilar(float a, float b, float epsilon = SMALL_FLOAT)
{
    return Abs(a-b) < epsilon;
}

inline bool IsSimilar(double a, double b, double epsilon = SMALL_FLOAT)
{
    return Abs(a-b) < epsilon;
}

inline __attribute__ ((always_inline)) float MultAdd(float a, float b, float c)
{


    return a * b + c;
}

inline __attribute__ ((always_inline)) double MultAdd(double a, double b, double c)
{


    return a * b + c;
}

template <class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompLessEqual(T a, T b)
{
    return MaskScalarTemplate<T>(b-a);
}

template <class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompGreaterEqual(T a, T b)
{
    return MaskScalarTemplate<T>(a-b);
}

template <class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompLessThan(T a, T b)
{
    return Not(CompGreaterEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompGreaterThan(T a, T b)
{
    return Not(CompLessEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompEqual(T a, T b)
{
    return And(CompLessEqual(a, b), CompGreaterEqual(a,b));
}

template <class T>
inline __attribute__ ((always_inline)) MaskScalarTemplate<T> CompNotEqual(T a, T b)
{
    return Not(And(CompLessEqual(a, b), CompGreaterEqual(a,b)));
}

template <class T>
inline __attribute__ ((always_inline)) T Select(typename MaskScalarTemplate<T>::InParam mask, T trueValue, T falseValue )
{
    return (T)__fsel((mask.mS), (trueValue), (falseValue));
}

}

}

}
