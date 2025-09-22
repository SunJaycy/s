







#include <rw/math/fpu/mask3_operation.h>

namespace rw {
namespace math {
namespace fpu {

template<class T>
Vector3Template<T>& operator +=(Vector3Template<T>& vec, const T& scalar)
{
    vec.Set(vec.x+scalar, vec.y+scalar, vec.z+scalar);
    return vec;
}

template<class T>
Vector3Template<T>& operator -=(Vector3Template<T>& vec, const T& scalar)
{
    vec.Set(vec.x-scalar, vec.y-scalar, vec.z-scalar);
    return vec;
}

template<class T>
Vector3Template<T>& operator *=(Vector3Template<T>& vec, const T& scalar)
{
    vec.Set(vec.x*scalar, vec.y*scalar, vec.z*scalar);
    return vec;
}

template<class T>
Vector3Template<T>& operator /=(Vector3Template<T>& vec, const T& scalar)
{
    T scalarInv= static_cast<T>(1.)/scalar;
    vec.Set(vec.x*scalarInv, vec.y*scalarInv, vec.z*scalarInv);
    return vec;
}

template<class T>
Vector3Template<T>& operator +=(Vector3Template<T>& a, const Vector3Template<T>& b)
{
    a.Set(a.x+b.x, a.y+b.y, a.z+b.z);
    return a;
}

template<class T>
Vector3Template<T>& operator -=(Vector3Template<T>& a, const Vector3Template<T>& b)
{
    a.Set(a.x-b.x, a.y-b.y, a.z-b.z);
    return a;
}

template<class T>
Vector3Template<T>& operator *=(Vector3Template<T>& a, const Vector3Template<T>& b)
{
    a.Set(a.x*b.x, a.y*b.y, a.z*b.z);
    return a;
}

template<class T>
Vector3Template<T>& operator /=(Vector3Template<T>& a, const Vector3Template<T>& b)
{
    a.Set(a.x/b.x, a.y/b.y, a.z/b.z);
    return a;
}

template<class T>
Vector3Template<T> operator - (const Vector3Template<T>& vec)
{
    Vector3Template<T> r(-vec.x, -vec.y, -vec.z);
    return r;
}

template<class T>
Vector3Template<T> operator * (const Vector3Template<T> a, const Vector3Template<T>& b)
{
    Vector3Template<T> r(a.x*b.x, a.y*b.y, a.z*b.z);
    return r;
}

template<class T>
Vector3Template<T> operator / (const Vector3Template<T> a, const Vector3Template<T>& b)
{
    Vector3Template<T> r(a.x/b.x, a.y/b.y, a.z/b.z);
    return r;
}

template<class T>
Vector3Template<T> operator * (const Vector3Template<T>& vec, const T& scalar)
{
    Vector3Template<T> r(vec.x*scalar, vec.y*scalar, vec.z*scalar);
    return r;
}

template<class T>
Vector3Template<T> operator * (const T& scalar, const Vector3Template<T>& vec)
{
    Vector3Template<T> r(vec.x*scalar, vec.y*scalar, vec.z*scalar);
    return r;
}

template<class T>
Vector3Template<T> operator / (const Vector3Template<T>& vec, const T& scalar)
{
    T scalarInv= static_cast<T>(1.)/scalar;
    Vector3Template<T> r(vec.x*scalarInv, vec.y*scalarInv, vec.z*scalarInv);
    return r;
}

template<class T>
Vector3Template<T> operator + (const Vector3Template<T>& a, const Vector3Template<T>& b)
{
    return Vector3Template<T>(a.x+b.x, a.y+b.y, a.z+b.z);
}

template<class T>
Vector3Template<T> operator + (const Vector3Template<T>& a, const T& s)
{
    Vector3Template<T> r(a.x+s, a.y+s, a.z+s);
    return r;
}

template<class T>
Vector3Template<T> operator + (const T& s, const Vector3Template<T>& a)
{
    Vector3Template<T> r(a.x+s, a.y+s, a.z+s);
    return r;
}

template<class T>
Vector3Template<T> operator - (const Vector3Template<T>& a, const Vector3Template<T>& b)
{
    Vector3Template<T> r(a.x-b.x, a.y-b.y, a.z-b.z);
    return r;
}

template<class T>
Vector3Template<T> operator - (const Vector3Template<T>& a, const T& s)
{
    Vector3Template<T> r(a.x-s, a.y-s, a.z-s);
    return r;
}

template<class T>
Vector3Template<T> operator - (const T& s, const Vector3Template<T>& a)
{
    Vector3Template<T> r(s-a.x, s-a.y, s-a.z);
    return r;
}

template<class T>
bool operator ==(const Vector3Template<T>& a, const Vector3Template<T>& b)
{
    return (a.x==b.x && a.y==b.y && a.z==b.z);
}

template<class T>
bool operator !=(const Vector3Template<T>& a, const Vector3Template<T>& b)
{
    return (a.x!=b.x || a.y!=b.y || a.z!=b.z);
}

template<class T>
bool IsSimilar(const Vector3Template<T>& a, const Vector3Template<T>& b, T epsilon = SMALL_FLOAT)
{
    return (Abs(a.x-b.x) <= epsilon &&
            Abs(a.y-b.y) <= epsilon &&
            Abs(a.z-b.z) <= epsilon);
}

template<class T>
T Magnitude(const Vector3Template<T>& vec)
{
    return Sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
}

template<class T>
T MagnitudeSquared(const Vector3Template<T>& vec)
{
    return vec.x*vec.x + vec.y*vec.y + vec.z*vec.z;
}

template<class T>
T MagnitudeRecip(const Vector3Template<T>& vec)
{
    return static_cast<T>(1.0f)/Sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
}

template<class T>
T Dot(const Vector3Template<T>& a, const Vector3Template<T>& b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}



template<class T>
Vector3Template<T> Cross(const Vector3Template<T>& v0, const Vector3Template<T>& v1)
{
    Vector3Template<T> r;
    r.x =v0.y*v1.z - v1.y*v0.z;
    r.y =v0.z*v1.x - v0.x*v1.z;
    r.z =v0.x*v1.y - v0.y*v1.x;
    return r;
}

template<class T>
T NormalizeReturnMagnitude(const Vector3Template<T>& vec, Vector3Template<T>& r)
{
    T l = MagnitudeSquared(vec);

    if (l > static_cast<T>(SMALL_FLOAT))
    {
        T invl = InvSqrt(l);
        r = Mult(vec, invl);
        return l*invl;
    }

    return static_cast<T>(0.0f);
}

template<class T>
T CosAngleBetweenNormalizedVectors(const Vector3Template<T> &v0, const Vector3Template<T> &v1)
{
    T cosAngle;
    cosAngle = Dot(v0, v1);
    cosAngle = Clamp(cosAngle, static_cast<T>(-1.0f), static_cast<T>(1.0f));
    return cosAngle;
}




template<class T>
Vector3Template<T> Negate(const Vector3Template<T>& vec)
{
    Vector3Template<T> r(-vec.x, -vec.y, -vec.z);
    return r;
}

template<class T>
Vector3Template<T> Mult(const Vector3Template<T>& vec, T scalar)
{
    Vector3Template<T> r(vec.x*scalar, vec.y*scalar, vec.z*scalar);
    return r;
}

template<class T>
Vector3Template<T> Divide(const Vector3Template<T>& vec, T scalar)
{
    T scalarInv= static_cast<T>(1.)/scalar;
    Vector3Template<T> r(vec.x*scalarInv, vec.y*scalarInv, vec.z*scalarInv);
    return r;
}

template<class T>
Vector3Template<T> Add(const Vector3Template<T>& a, const Vector3Template<T>& b)
{
    Vector3Template<T> r(a.x+b.x, a.y+b.y, a.z+b.z);
    return r;
}

template<class T>
Vector3Template<T> Subtract(const Vector3Template<T>& a, const Vector3Template<T>& b)
{
    Vector3Template<T> r(a.x-b.x, a.y-b.y, a.z-b.z);
    return r;
}



template<class T>
Vector3Template<T> NormalizeFast(const Vector3Template<T>& vec)
{
    Vector3Template<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}



template<class T>
Vector3Template<T> NormalizeEstimate(const Vector3Template<T>& vec)
{
    Vector3Template<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}

template<class T>
Vector3Template<T> Normalize(const Vector3Template<T>& vec)
{
    Vector3Template<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}

template<class T>
Vector3Template<T> Normalize(const Vector3Template<T>& vec, T &result)
{
    result = Magnitude(vec);
    Vector3Template<T> r(Mult(vec, static_cast<T>(1.0f)/result));
    return r;
}

template<class T>
Vector3Template<T> Mult(const Vector3Template<T>& a, const Vector3Template<T>& b)
{
    Vector3Template<T> r(a.x*b.x, a.y*b.y, a.z*b.z);
    return r;
}

template<class T>
Vector3Template<T> Lerp(const Vector3Template<T>& v0, const Vector3Template<T>& v1, T t)
{
    Vector3Template<T> r(Subtract(v1, v0));
    r = Mult(r, t);
    return Add(v0, r);
}

template<class T>
Vector3Template<T> NLerpEstimate(const Vector3Template<T>& v0, const Vector3Template<T>& v1, T t)
{
    return NormalizeEstimate(Lerp(v0, v1, t));
}

template<class T>
Vector3Template<T> NLerpFast(const Vector3Template<T>& v0, const Vector3Template<T>& v1, T t)
{
    return NormalizeFast(Lerp(v0, v1, t));
}

template<class T>
Vector3Template<T> NLerp(const Vector3Template<T>& v0, const Vector3Template<T>& v1, T t)
{
    return Normalize(Lerp(v0, v1, t));
}

template<class T>
Vector3Template<T> SLerp(const Vector3Template<T>& v0, const Vector3Template<T>& v1, T t)
{
    T dp = Dot(v0, v1);

    if (dp > Cos(VECTOR_MIN_SLERP_ANGLE))
    {
        return NLerp(v0, v1, t);
    }

    T theta = ACos(dp);
    Vector3Template<T> a, b;

    a = Mult(v0, Sin((static_cast<T>(1.0f)-t)*theta)/Sin(theta));
    b = Mult(v1, Sin(t*theta)/Sin(theta));
    return Add(a, b);
}

template<class T>
void Cross(const Vector3Template<T>& v0, const Vector3Template<T>& v1, Vector3Template<T>& r)
{
    r = Vector3Template<T>(
            v0.y*v1.z - v1.y*v0.z,
            v0.z*v1.x - v0.x*v1.z,
            v0.x*v1.y - v0.y*v1.x
        );
}

template<class T>
bool IsValid(const Vector3Template<T>& v)
{
    return (IsValid(v.x) && IsValid(v.y) && IsValid(v.z));
}

template<class T>
bool IsZero(const Vector3Template<T>& v, T tolerance = EPSILON)
{
    return (IsZero(v.x, tolerance) && IsZero(v.y, tolerance) && IsZero(v.z, tolerance));
}

template<class T>
bool IsAnyNaN(const Vector3Template<T>& v)
{
    return (bool)(IsNaN(v.x) | IsNaN(v.y) | IsNaN(v.z));
}

template<class T>
Vector3Template<T> Min(const Vector3Template<T>& v0, const Vector3Template<T>& v1)
{
    Vector3Template<T> retVec(Min(v0.x, v1.x), Min(v0.y, v1.y), Min(v0.z, v1.z));
    return retVec;
}

template<class T>
Vector3Template<T> Max(const Vector3Template<T>& v0, const Vector3Template<T>& v1)
{
    Vector3Template<T> retVec(Max(v0.x, v1.x), Max(v0.y, v1.y), Max(v0.z, v1.z));
    return retVec;
}

template<class T>
Vector3Template<T> Clamp(const Vector3Template<T>& vecToClamp, const Vector3Template<T>& minVecValue, const Vector3Template<T>& maxVecValue )
{
    Vector3Template<T> retVec(Clamp(vecToClamp.x, minVecValue.x, maxVecValue.x), Clamp(vecToClamp.y, minVecValue.y, maxVecValue.y), Clamp(vecToClamp.z, minVecValue.z, maxVecValue.z));
    return retVec;
}

template<class T>
Vector3Template<T> Abs(const Vector3Template<T>& v)
{
    Vector3Template<T> retVec(Abs(v.x), Abs(v.y), Abs(v.z));
    return retVec;
}

template<class T>
T AngleBetweenVectors(const Vector3Template<T>& v0, const Vector3Template<T>& v1)
{
    Vector3Template<T> nv0, nv1;
    nv0 = NormalizeFast(v0);
    nv1 = NormalizeFast(v1);
    T angle = CosAngleBetweenNormalizedVectors(nv0, nv1);
    return ACos(angle);
}

template<class T>
T AngleBetweenVectors(const Vector3Template<T>& v0, const Vector3Template<T>& v1, const Vector3Template<T> &windAxis)
{
    Vector3Template<T> nv0 = NormalizeFast(v0);
    Vector3Template<T> nv1 = NormalizeFast(v1);
    T angle;
    Vector3Template<T> norm;
    angle = ACos(CosAngleBetweenNormalizedVectors(nv0, nv1));
    norm = Cross(nv0, nv1);
    if(Dot(norm, windAxis) < static_cast<T>(0.0f))
    {
        return(static_cast<T>(TWO_PI) - angle);
    }
    return(angle);
}

template <class T>
inline __attribute__ ((always_inline)) Mask3Template<T> CompLessEqual(const Vector3Template<T> &a, const Vector3Template<T> &b)
{
    return Mask3Template<T>(
            b.x-a.x,
            b.y-a.y,
            b.z-a.z
            );
}

template <class T>
inline __attribute__ ((always_inline)) Mask3Template<T> CompGreaterEqual(const Vector3Template<T> &a, const Vector3Template<T> &b)
{
    return Mask3Template<T>(
            a.x-b.x,
            a.y-b.y,
            a.z-b.z
            );
}

template <class T>
inline __attribute__ ((always_inline)) Mask3Template<T> CompLessThan(const Vector3Template<T> &a, const Vector3Template<T> &b)
{
    return Not(CompGreaterEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask3Template<T> CompGreaterThan(const Vector3Template<T> &a, const Vector3Template<T> &b)
{
    return Not(CompLessEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask3Template<T> CompEqual(const Vector3Template<T> &a, const Vector3Template<T> &b)
{
    return And(CompLessEqual(a, b), CompGreaterEqual(a,b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask3Template<T> CompNotEqual(const Vector3Template<T> &a, const Vector3Template<T> &b)
{
    return Not(And(CompLessEqual(a, b), CompGreaterEqual(a,b)));
}

template <class T>
inline __attribute__ ((always_inline)) Vector3Template<T> Select(const MaskScalarTemplate<T> &mask, const Vector3Template<T> &trueValue, const Vector3Template<T> &falseValue )
{
    return Vector3Template<T>(
            (T)__fsel((mask.mS), (trueValue.x), (falseValue.x)),
            (T)__fsel((mask.mS), (trueValue.y), (falseValue.y)),
            (T)__fsel((mask.mS), (trueValue.z), (falseValue.z))
        );
}

template <class T>
inline __attribute__ ((always_inline)) Vector3Template<T> Select(const Mask3Template<T> &mask, const Vector3Template<T> &trueValue, const Vector3Template<T> &falseValue )
{
    return Vector3Template<T>(
            (T)__fsel((mask.mX), (trueValue.x), (falseValue.x)),
            (T)__fsel((mask.mY), (trueValue.y), (falseValue.y)),
            (T)__fsel((mask.mZ), (trueValue.z), (falseValue.z))
        );
}






template<class T>
void Negate(const Vector3Template<T>& vec, Vector3Template<T> &r)
{
    r.Set(-vec.x, -vec.y, -vec.z);
}


template<class T>
void Mult(const Vector3Template<T>& vec, T scalar, Vector3Template<T>& r)
{
    r.Set(vec.x*scalar, vec.y*scalar, vec.z*scalar);
}


template<class T>
void Divide(const Vector3Template<T>& vec, T scalar, Vector3Template<T>& r)
{
    r.Set(vec.x/scalar, vec.y/scalar, vec.z/scalar);
}


template<class T>
void Add(const Vector3Template<T>& a, const Vector3Template<T>& b, Vector3Template<T>& r)
{
    r.Set(a.x+b.x, a.y+b.y, a.z+b.z);
}


template<class T>
void Subtract(const Vector3Template<T>& a, const Vector3Template<T>& b, Vector3Template<T>& r)
{
    r.Set(a.x-b.x, a.y-b.y, a.z-b.z);
}


template<class T>
void Normalize(const Vector3Template<T>& vec, Vector3Template<T>& r)
{
    Mult(vec, MagnitudeRecip(vec), r);
}


template<class T>
void Mult(const Vector3Template<T>& a, const Vector3Template<T>& b, Vector3Template<T>& r)
{
    r.Set(a.x*b.x, a.y*b.y, a.z*b.z);
}


template<class T>
void Lerp(const Vector3Template<T>& v0, const Vector3Template<T>& v1, T t, Vector3Template<T>& r)
{
    Subtract(v1, v0, r);
    Mult(r, t,r );
    Add(v0, r,r );
}


template<class T>
void NLerp(const Vector3Template<T>& v0, const Vector3Template<T>& v1, T t, Vector3Template<T>& r)
{
    Subtract(v1, v0, r);
    Mult(r, t, r);
    Add(v0, r, r);
    Normalize(r, r);
}


template<class T>
void SLerp(const Vector3Template<T>& v0, const Vector3Template<T>& v1, T t, Vector3Template<T>& r)
{
    ;
    ;
    ;

    T dp = Dot(v0, v1);

    if (dp > Cos(VECTOR_MIN_SLERP_ANGLE))
    {
        NLerp(v0, v1, t, r);
    }
    else
    {
        T theta = ACos(dp);
        Vector3Template<T> a, b;

        Mult(v0, Sin((static_cast<T>(1.0f)-t)*theta)/Sin(theta), a);
        Mult(v1, Sin(t*theta)/Sin(theta), b);
        Add(a, b, r);
    }
}



}

}

}
