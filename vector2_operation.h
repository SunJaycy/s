




#include <rw/math/fpu/trig.h>
#include <rw/math/fpu/scalar.h>

#include <rw/math/fpu/mask2_operation.h>

namespace rw {
namespace math {
namespace fpu {

template<class T>
Vector2Template<T>& operator +=(Vector2Template<T>& vec, const T& scalar)
{
    vec.Set(vec.x+scalar, vec.y+scalar);
    return vec;
}

template<class T>
Vector2Template<T>& operator -=(Vector2Template<T>& vec, const T& scalar)
{
    vec.Set(vec.x-scalar, vec.y-scalar);
    return vec;
}

template<class T>
Vector2Template<T>& operator *=(Vector2Template<T>& vec, const T& scalar)
{
    vec.Set(vec.x*scalar, vec.y*scalar);
    return vec;
}

template<class T>
Vector2Template<T>& operator /=(Vector2Template<T>& vec, const T& scalar)
{
    vec.Set(vec.x/scalar, vec.y/scalar);
    return vec;
}

template<class T>
Vector2Template<T>& operator +=(Vector2Template<T>& a, const Vector2Template<T>& b)
{
    a.Set(a.x+b.x, a.y+b.y);
    return a;
}

template<class T>
Vector2Template<T>& operator -=(Vector2Template<T>& a, const Vector2Template<T>& b)
{
    a.Set(a.x-b.x, a.y-b.y);
    return a;
}


template<class T>
Vector2Template<T>& operator *=(Vector2Template<T>& a, const Vector2Template<T>& b)
{
    a.Set(a.x*b.x, a.y*b.y);
    return a;
}

template<class T>
Vector2Template<T>& operator /=(Vector2Template<T>& a, const Vector2Template<T>& b)
{
    a.Set(a.x/b.x, a.y/b.y);
    return a;
}

template<class T>
Vector2Template<T> operator - (const Vector2Template<T>& vec)
{
    Vector2Template<T> r(-vec.x, -vec.y);
    return r;
}

template<class T>
Vector2Template<T> operator * (const Vector2Template<T>& vec, const T& scalar)
{
    Vector2Template<T> r(vec.x*scalar, vec.y*scalar);
    return r;
}

template<class T>
Vector2Template<T> operator * (const T& scalar, const Vector2Template<T>& vec)
{
    Vector2Template<T> r(vec.x*scalar, vec.y*scalar);
    return r;
}

template<class T>
Vector2Template<T> operator * (const Vector2Template<T> a, const Vector2Template<T>& b)
{
    Vector2Template<T> r(a.x*b.x, a.y*b.y);
    return r;
}

template<class T>
Vector2Template<T> operator / (const Vector2Template<T> a, const Vector2Template<T>& b)
{
    Vector2Template<T> r(a.x/b.x, a.y/b.y);
    return r;
}

template<class T>
Vector2Template<T> operator / (const Vector2Template<T>& vec, const T& scalar)
{
    Vector2Template<T> r(vec.x/scalar, vec.y/scalar);
    return r;
}

template<class T>
Vector2Template<T> operator + (const Vector2Template<T>& a, const Vector2Template<T>& b)
{
    Vector2Template<T> r(a.x+b.x, a.y+b.y);
    return r;
}

template<class T>
Vector2Template<T> operator + (const Vector2Template<T>& a, const T& s)
{
    Vector2Template<T> r(a.x+s, a.y+s);
    return r;
}

template<class T>
Vector2Template<T> operator + (const T& s, const Vector2Template<T>& a)
{
    Vector2Template<T> r(a.x+s, a.y+s);
    return r;
}

template<class T>
Vector2Template<T> operator - (const Vector2Template<T>& a, const Vector2Template<T>& b)
{
    Vector2Template<T> r(a.x-b.x, a.y-b.y);
    return r;
}

template<class T>
Vector2Template<T> operator - (const Vector2Template<T>& a, const T& s)
{
    Vector2Template<T> r(a.x-s, a.y-s);
    return r;
}

template<class T>
Vector2Template<T> operator - (const T& s, const Vector2Template<T>& a)
{
    Vector2Template<T> r(s-a.x, s-a.y);
    return r;
}

template<class T>
bool operator ==(const Vector2Template<T>& a, const Vector2Template<T>& b)
{
    return (a.x==b.x && a.y==b.y);
}

template<class T>
bool operator !=(const Vector2Template<T>& a, const Vector2Template<T>& b)
{
    return (a.x!=b.x || a.y!=b.y);
}

template<class T>
bool IsSimilar(const Vector2Template<T>& a, const Vector2Template<T>& b, T epsilon = SMALL_FLOAT)
{
    return (Abs(a.x-b.x) <= epsilon && Abs(a.y-b.y) <= epsilon);
}


template<class T>
T Magnitude(const Vector2Template<T>& vec)
{
    return Sqrt(vec.x*vec.x+vec.y*vec.y);
}

template<class T>
T MagnitudeSquared(const Vector2Template<T>& vec)
{
    return vec.x*vec.x+vec.y*vec.y;
}

template<class T>
T MagnitudeRecip(const Vector2Template<T>& vec)
{
    return static_cast<T>(1.0f)/Sqrt(vec.x*vec.x+vec.y*vec.y);
}

template<class T>
T Dot(const Vector2Template<T>& a, const Vector2Template<T>& b)
{
     return a.x*b.x + a.y*b.y;
}

template<class T>
T Cross(const Vector2Template<T>& a, const Vector2Template<T>& b)
{
     return a.x*b.y - a.y*b.x;
}

template<class T>
T NormalizeReturnMagnitude(const Vector2Template<T>& vec, Vector2Template<T>& r)
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
T CosAngleBetweenNormalizedVectors(const Vector2Template<T> &v0, const Vector2Template<T> &v1)
{
    T cosAngle;
    cosAngle = Dot(v0, v1);
    cosAngle = Clamp(cosAngle, static_cast<T>(-1.0f), static_cast<T>(1.0f));
    return cosAngle;
}



template<class T>
Vector2Template<T> Negate(const Vector2Template<T>& vec)
{
    Vector2Template<T> r(-vec.x, -vec.y);
    return r;
}

template<class T>
Vector2Template<T> Mult(const Vector2Template<T>& vec, T scalar)
{
    Vector2Template<T> r(vec.x*scalar, vec.y*scalar);
    return r;
}

template<class T>
Vector2Template<T> Divide(const Vector2Template<T>& vec, T scalar)
{
    Vector2Template<T> r(vec.x/scalar, vec.y/scalar);
    return r;
}

template<class T>
Vector2Template<T> Add(const Vector2Template<T>& a, const Vector2Template<T>& b)
{
    Vector2Template<T> r(a.x+b.x, a.y+b.y);
    return r;
}

template<class T>
Vector2Template<T> Subtract(const Vector2Template<T>& a, const Vector2Template<T>& b)
{
    Vector2Template<T> r(a.x-b.x, a.y-b.y);
    return r;
}




template<class T>
Vector2Template<T> NormalizeFast(const Vector2Template<T>& vec)
{
    Vector2Template<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}



template<class T>
Vector2Template<T> NormalizeEstimate(const Vector2Template<T>& vec)
{
    Vector2Template<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}

template<class T>
Vector2Template<T> Normalize(const Vector2Template<T>& vec)
{
    Vector2Template<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}

template<class T>
Vector2Template<T> Normalize(const Vector2Template<T>& vec, T& magnitude_out)
{
    T l = MagnitudeRecip(vec);
    magnitude_out = Reciprocal(l);
    return Mult(vec, l);
}

template<class T>
Vector2Template<T> Mult(const Vector2Template<T>& a, const Vector2Template<T>& b)
{
    Vector2Template<T> r(a.x*b.x, a.y*b.y);
    return r;
}

template<class T>
Vector2Template<T> Lerp(const Vector2Template<T>& v0, const Vector2Template<T>& v1, T t)
{
    Vector2Template<T> r(Subtract(v1, v0));
    r = Mult(r, t);
    return Add(v0, r);
}

template<class T>
Vector2Template<T> NLerpEstimate(const Vector2Template<T>& v0, const Vector2Template<T>& v1, T t)
{
    return NormalizeEstimate(Lerp(v0, v1, t));
}

template<class T>
Vector2Template<T> NLerpFast(const Vector2Template<T>& v0, const Vector2Template<T>& v1, T t)
{
    return NormalizeFast(Lerp(v0, v1, t));
}

template<class T>
Vector2Template<T> NLerp(const Vector2Template<T>& v0, const Vector2Template<T>& v1, T t)
{
    return Normalize(Lerp(v0, v1, t));
}

template<class T>
Vector2Template<T> SLerp(const Vector2Template<T>& v0, const Vector2Template<T>& v1, T t)
{
    ;
    ;
    ;

    T dp = Dot(v0, v1);

    if (dp > Cos(VECTOR_MIN_SLERP_ANGLE))
    {
        return NLerp(v0, v1, t);
    }

    T theta = ACos(dp);
    Vector2Template<T> a, b;

    a = Mult(v0, Sin((static_cast<T>(1.0f)-t)*theta)/Sin(theta));
    b = Mult(v1, Sin(t*theta)/Sin(theta));
    return Add(a, b);
}

template<class T>
bool IsValid(const Vector2Template<T>& v)
{
    return (IsValid(v.x) && IsValid(v.y));
}


template<class T>
bool IsZero(const Vector2Template<T>& v, T tolerance = EPSILON)
{
    return (IsZero(v.x, tolerance) && IsZero(v.y, tolerance));
}

template<class T>
bool IsAnyNaN(const Vector2Template<T>& v)
{
    return (bool)(IsNaN(v.x) | IsNaN(v.y));
}

template<class T>
Vector2Template<T> Min(const Vector2Template<T>& v0, const Vector2Template<T>& v1)
{
    Vector2Template<T> retVec(Min(v0.x, v1.x), Min(v0.y, v1.y));
    return retVec;
}

template<class T>
Vector2Template<T> Max(const Vector2Template<T>& v0, const Vector2Template<T>& v1)
{
    Vector2Template<T> retVec(Max(v0.x, v1.x), Max(v0.y, v1.y));
    return retVec;
}

template<class T>
Vector2Template<T> Clamp(const Vector2Template<T>& vecToClamp, const Vector2Template<T>& minVecValue, const Vector2Template<T>& maxVecValue )
{
    Vector2Template<T> retVec(Clamp(vecToClamp.x, minVecValue.x, maxVecValue.x), Clamp(vecToClamp.y, minVecValue.y, maxVecValue.y));
    return retVec;
}

template<class T>
Vector2Template<T> Abs(const Vector2Template<T>& v)
{
    Vector2Template<T> retVec(Abs(v.x), Abs(v.y));
    return retVec;
}

template<class T>
T AngleBetweenVectors(const Vector2Template<T>& v0, const Vector2Template<T>& v1)
{
    Vector2Template<T> nv0, nv1;
    nv0 = Normalize(v0);
    nv1 = Normalize(v1);
    T angle = CosAngleBetweenNormalizedVectors(nv0, nv1);
    return ACos(angle);
}

template<class T>
T AngleBetweenVectorsFast(const Vector2Template<T>& v0, const Vector2Template<T>& v1)
{
    Vector2Template<T> nv0, nv1;
    nv0 = NormalizeFast(v0);
    nv1 = NormalizeFast(v1);
    T angle = CosAngleBetweenNormalizedVectors(nv0, nv1);
    return ACos(angle);
}

template <class T>
inline __attribute__ ((always_inline)) Mask2Template<T> CompLessEqual(const Vector2Template<T> &a, const Vector2Template<T> &b)
{
    return Mask2Template<T>(
            b.x-a.x,
            b.y-a.y
            );
}

template <class T>
inline __attribute__ ((always_inline)) Mask2Template<T> CompGreaterEqual(const Vector2Template<T> &a, const Vector2Template<T> &b)
{
    return Mask2Template<T>(
            a.x-b.x,
            a.y-b.y
            );
}

template <class T>
inline __attribute__ ((always_inline)) Mask2Template<T> CompLessThan(const Vector2Template<T> &a, const Vector2Template<T> &b)
{
    return Not(CompGreaterEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask2Template<T> CompGreaterThan(const Vector2Template<T> &a, const Vector2Template<T> &b)
{
    return Not(CompLessEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask2Template<T> CompEqual(const Vector2Template<T> &a, const Vector2Template<T> &b)
{
    return And(CompLessEqual(a, b), CompGreaterEqual(a,b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask2Template<T> CompNotEqual(const Vector2Template<T> &a, const Vector2Template<T> &b)
{
    return Not(And(CompLessEqual(a, b), CompGreaterEqual(a,b)));
}

template <class T>
inline __attribute__ ((always_inline)) Vector2Template<T> Select(const MaskScalarTemplate<T> &mask, const Vector2Template<T> &trueValue, const Vector2Template<T> &falseValue )
{
    return Vector2Template<T>(
            (T)__fsel((mask.mS), (trueValue.x), (falseValue.x)),
            (T)__fsel((mask.mS), (trueValue.y), (falseValue.y))
        );
}

template <class T>
inline __attribute__ ((always_inline)) Vector2Template<T> Select(const Mask2Template<T> &mask, const Vector2Template<T> &trueValue, const Vector2Template<T> &falseValue )
{
    return Vector2Template<T>(
            (T)__fsel((mask.mX), (trueValue.x), (falseValue.x)),
            (T)__fsel((mask.mY), (trueValue.y), (falseValue.y))
        );
}






template<class T>
void Negate(const Vector2Template<T>& vec, Vector2Template<T>& r)
{
    r.Set(-vec.x, -vec.y);
}


template<class T>
void Mult(const Vector2Template<T>& vec, T scalar, Vector2Template<T>& r)
{
    r.Set(vec.x*scalar, vec.y*scalar);
}


template<class T>
void Divide(const Vector2Template<T>& vec, T scalar, Vector2Template<T>& r)
{
    r.Set(vec.x/scalar, vec.y/scalar);
}


template<class T>
void Add(const Vector2Template<T>& a, const Vector2Template<T>& b, Vector2Template<T>& r)
{
    r.Set(a.x+b.x, a.y+b.y);
}


template<class T>
void Subtract(const Vector2Template<T>& a, const Vector2Template<T>& b, Vector2Template<T>& r)
{
    r.Set(a.x-b.x, a.y-b.y);
}



template<class T>
void Normalize(const Vector2Template<T>& vec, Vector2Template<T>& r)
{
    Mult(vec, MagnitudeRecip(vec), r);
}


template<class T>
void Mult(const Vector2Template<T>& a, const Vector2Template<T>& b, Vector2Template<T>& r)
{
    r.Set(a.x*b.x, a.y*b.y);
}


template<class T>
void Lerp(const Vector2Template<T>& v0, const Vector2Template<T>& v1, T t, Vector2Template<T>& r)
{
    Subtract(v1, v0, r);
    Mult(r, t, r);
    Add(v0, r, r);
}


template<class T>
void NLerp(const Vector2Template<T>& v0, const Vector2Template<T>& v1, T t, Vector2Template<T>& r)
{
    Subtract(v1, v0, r);
    Mult(r, t, r);
    Add(v0, r, r);
    Normalize(r, r);
}


template<class T>
void SLerp(const Vector2Template<T>& v0, const Vector2Template<T>& v1, T t, Vector2Template<T>& r)
{
    T dp = Dot(v0, v1);

    if (dp > Cos(VECTOR_MIN_SLERP_ANGLE))
    {
        NLerp(v0, v1, t, r);
    }
    else
    {
        T theta = ACos(dp);
        Vector2Template<T> a, b;

        Mult(v0, Sin((static_cast<T>(1.0f)-t)*theta)/Sin(theta), a);
        Mult(v1, Sin(t*theta)/Sin(theta), b);
        Add(a, b, r);
    }
}



}

}

}
