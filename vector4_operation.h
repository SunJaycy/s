








#include <rw/math/fpu/mask4_operation.h>

namespace rw {
namespace math {
namespace fpu {

template<class T>
Vector4Template<T>& operator +=(Vector4Template<T>& vec, const T& scalar)
{
    vec.Set(vec.x+scalar, vec.y+scalar, vec.z+scalar, vec.w+scalar);
    return vec;
}

template<class T>
Vector4Template<T>& operator -=(Vector4Template<T>& vec, const T& scalar)
{
    vec.Set(vec.x-scalar, vec.y-scalar, vec.z-scalar, vec.w-scalar);
    return vec;
}

template<class T>
Vector4Template<T>& operator *=(Vector4Template<T>& vec, const T& scalar)
{
    vec.Set(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);
    return vec;
}

template<class T>
Vector4Template<T>& operator /=(Vector4Template<T>& vec, const T& scalar)
{
    T scalarInv= static_cast<T>(1.)/scalar;
    vec.Set(vec.x *scalarInv, vec.y *scalarInv, vec.z *scalarInv, vec.w *scalarInv);
    return vec;
}

template<class T>
Vector4Template<T>& operator +=(Vector4Template<T>& a, const Vector4Template<T>& b)
{
    a.Set(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w);
    return a;
}

template<class T>
Vector4Template<T>& operator -=(Vector4Template<T>& a, const Vector4Template<T>& b)
{
    a.Set(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w);
    return a;
}

template<class T>
Vector4Template<T>& operator *=(Vector4Template<T>& a, const Vector4Template<T>& b)
{
    a.Set(a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w);
    return a;
}

template<class T>
Vector4Template<T>& operator /=(Vector4Template<T>& a, const Vector4Template<T>& b)
{
    a.Set(a.x/b.x, a.y/b.y, a.z/b.z, a.w/b.w);
    return a;
}

template<class T>
Vector4Template<T> operator - (const Vector4Template<T>& vec)
{
    Vector4Template<T> r(-vec.x, -vec.y, -vec.z, -vec.w);
    return r;
}

template<class T>
Vector4Template<T> operator * (const Vector4Template<T> a, const Vector4Template<T>& b)
{
    Vector4Template<T> r(a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w);
    return r;
}

template<class T>
Vector4Template<T> operator / (const Vector4Template<T> a, const Vector4Template<T>& b)
{
    Vector4Template<T> r(a.x/b.x, a.y/b.y, a.z/b.z, a.w/b.w);
    return r;
}

template<class T>
Vector4Template<T> operator * (const Vector4Template<T>& vec, const T& scalar)
{
    Vector4Template<T> r(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);
    return r;
}

template<class T>
Vector4Template<T> operator * (const T& scalar, const Vector4Template<T>& vec)
{
    Vector4Template<T> r(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);
    return r;
}

template<class T>
Vector4Template<T> operator / (const Vector4Template<T>& vec, const T& scalar)
{
    T scalarInv= static_cast<T>(1.)/scalar;
    Vector4Template<T> r(vec.x*scalarInv, vec.y*scalarInv, vec.z*scalarInv, vec.w*scalarInv);
    return r;
}

template<class T>
Vector4Template<T> operator + (const Vector4Template<T>& a, const Vector4Template<T>& b)
{
    Vector4Template<T> r(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w);
    return r;
}

template<class T>
Vector4Template<T> operator + (const Vector4Template<T>& a, const T& s)
{
    Vector4Template<T> r(a.x+s, a.y+s, a.z+s, a.w+s);
    return r;
}

template<class T>
Vector4Template<T> operator + (const T& s, const Vector4Template<T>& a)
{
    Vector4Template<T> r(a.x+s, a.y+s, a.z+s, a.w+s);
    return r;
}

template<class T>
Vector4Template<T> operator - (const Vector4Template<T>& a, const Vector4Template<T>& b)
{
    Vector4Template<T> r(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w);
    return r;
}

template<class T>
Vector4Template<T> operator - (const Vector4Template<T>& a, const T& s)
{
    Vector4Template<T> r(a.x-s, a.y-s, a.z-s, a.w-s);
    return r;
}

template<class T>
Vector4Template<T> operator - (const T& s, const Vector4Template<T>& a)
{
    Vector4Template<T> r(s-a.x, s-a.y, s-a.z, s-a.w);
    return r;
}

template<class T>
bool operator ==(const Vector4Template<T>& a, const Vector4Template<T>& b)
{
    return (a.x==b.x && a.y==b.y && a.z==b.z && a.w==b.w);
}

template<class T>
bool operator !=(const Vector4Template<T>& a, const Vector4Template<T>& b)
{
    return (a.x!=b.x || a.y!=b.y || a.z!=b.z || a.w!=b.w);
}

template<class T>
bool IsSimilar(const Vector4Template<T>& a, const Vector4Template<T>& b, T epsilon = SMALL_FLOAT)
{
    return (Abs(a.x-b.x) <= epsilon &&
            Abs(a.y-b.y) <= epsilon &&
            Abs(a.z-b.z) <= epsilon &&
            Abs(a.w-b.w) <= epsilon);
}

template<class T>
T Magnitude(const Vector4Template<T>& vec)
{
    return Sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w*vec.w);
}

template<class T>
T MagnitudeSquared(const Vector4Template<T>& vec)
{
    return vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w*vec.w;
}

template<class T>
T MagnitudeRecip(const Vector4Template<T>& vec)
{
    return static_cast<T>(1.0f) / Sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w*vec.w);
}

template<class T>
T Dot(const Vector4Template<T>& a, const Vector4Template<T>& b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

template<class T>
T NormalizeReturnMagnitude(const Vector4Template<T>& vec, Vector4Template<T>& r)
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
Vector4Template<T> Negate(const Vector4Template<T>& vec)
{
    Vector4Template<T> r(-vec.x, -vec.y, -vec.z, -vec.w);
    return r;
}

template<class T>
Vector4Template<T> Mult(const Vector4Template<T>& vec, T scalar)
{
    Vector4Template<T> r(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);
    return r;
}

template<class T>
Vector4Template<T> Divide(const Vector4Template<T>& vec, T scalar)
{
    T scalarInv= static_cast<T>(1.)/scalar;
    Vector4Template<T> r(vec.x*scalarInv, vec.y*scalarInv, vec.z*scalarInv, vec.w*scalarInv);
    return r;
}

template<class T>
Vector4Template<T> Add(const Vector4Template<T>& a, const Vector4Template<T>& b)
{
    Vector4Template<T> r(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w);
    return r;
}

template<class T>
Vector4Template<T> Subtract(const Vector4Template<T>& a, const Vector4Template<T>& b)
{
    Vector4Template<T> r(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w);
    return r;
}



template<class T>
Vector4Template<T> NormalizeFast(const Vector4Template<T>& vec)
{
    Vector4Template<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}



template<class T>
Vector4Template<T> NormalizeEstimate(const Vector4Template<T>& vec)
{
    Vector4Template<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}

template<class T>
Vector4Template<T> Normalize(const Vector4Template<T>& vec)
{
    Vector4Template<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}

template<class T>
Vector4Template<T> Mult(const Vector4Template<T>& a, const Vector4Template<T>& b)
{
    Vector4Template<T> r(a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w);
    return r;
}




template<class T>
Vector4Template<T> DivideByW(const Vector4Template<T>& v)
{
    T factor= static_cast<T>(1.)/v.w;
    Vector4Template<T> ret;
    ret.Set(v.x*factor, v.y*factor, v.z*factor, v.w*factor);
    return ret;
}

template<class T>
Vector4Template<T> Lerp(const Vector4Template<T>& v0, const Vector4Template<T>& v1, T t)
{
    Vector4Template<T> r(Subtract(v1, v0));
    r = Mult(r, t);
    return Add(v0, r);
}

template<class T>
Vector4Template<T> NLerpEstimate(const Vector4Template<T>& v0, const Vector4Template<T>& v1, T t)
{
    return NormalizeEstimate(Lerp(v0, v1, t));
}

template<class T>
Vector4Template<T> NLerpFast(const Vector4Template<T>& v0, const Vector4Template<T>& v1, T t)
{
    return NormalizeFast(Lerp(v0, v1, t));
}

template<class T>
Vector4Template<T> NLerp(const Vector4Template<T>& v0, const Vector4Template<T>& v1, T t)
{
    return Normalize(Lerp(v0, v1, t));
}

template<class T>
Vector4Template<T> SLerp(const Vector4Template<T>& v0, const Vector4Template<T>& v1, T t)
{
    T dp = Dot(v0, v1);

    if (dp > Cos(VECTOR_MIN_SLERP_ANGLE))
    {
        return NLerp(v0, v1, t);
    }

    T theta = ACos(dp);
    Vector4Template<T> a, b;

    a = Mult(v0, Sin((static_cast<T>(1.0f)-t)*theta)/Sin(theta));
    b = Mult(v1, Sin(t*theta)/Sin(theta));
    return Add(a, b);
}

template<class T>
void SetXYZ(Vector4Template<T>& v, T x, T y, T z)
{
    v.x = x;
    v.y = y;
    v.z = z;
}


template<class T>
const Vector3Template<T>& GetXYZ(const Vector4Template<T>& v)
{
    return reinterpret_cast<const Vector3Template<T> &>(v);
}


template<class T>
T MagnitudeXYZ(const Vector4Template<T>& v)
{
    return Sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}


template<class T>
T MagnitudeSquaredXYZ(const Vector4Template<T>& v)
{
    return v.x*v.x + v.y*v.y + v.z*v.z;
}


template<class T>
T MagnitudeRecipXYZ(const Vector4Template<T>& v)
{
    return static_cast<T>(1.0f)/Sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}


template<class T>
T DotXYZ(const Vector4Template<T>& v0, const Vector4Template<T>& v1)
{
    return v0.x*v1.x + v0.y*v1.y + v0.z*v1.z;
}



template<class T>
Vector4Template<T> CrossXYZ(const Vector4Template<T>& v0, const Vector4Template<T>& v1)
{
    Vector4Template<T> r;
    r.x =v0.y*v1.z - v1.y*v0.z;
    r.y =v0.z*v1.x - v0.x*v1.z;
    r.z =v0.x*v1.y - v0.y*v1.x;
    r.w =static_cast<T>(0.0f);
    return r;
}

template<class T>
bool IsValid(const Vector4Template<T>& v)
{
    return (IsValid(v.x) && IsValid(v.y) && IsValid(v.z) && IsValid(v.w));
}

template<class T>
bool IsZero(const Vector4Template<T>& v, T tolerance = EPSILON)
{
    return (IsZero(v.x, tolerance) && IsZero(v.y, tolerance) && IsZero(v.z, tolerance) && IsZero(v.w, tolerance));
}

template<class T>
bool IsAnyNaN(const Vector4Template<T>& v)
{
    return (bool)(IsNaN(v.x) | IsNaN(v.y) | IsNaN(v.z) | IsNaN(v.w));
}

template<class T>
Vector4Template<T> Min(const Vector4Template<T>& v0, const Vector4Template<T>& v1)
{
    return Vector4Template<T>(Min(v0.x, v1.x), Min(v0.y, v1.y), Min(v0.z, v1.z), Min(v0.w, v1.w));
}

template<class T>
Vector4Template<T> Max(const Vector4Template<T>& v0, const Vector4Template<T>& v1)
{
    return Vector4Template<T>(Max(v0.x, v1.x), Max(v0.y, v1.y), Max(v0.z, v1.z), Max(v0.w, v1.w));
}

template<class T>
Vector4Template<T> Clamp(const Vector4Template<T>& vecToClamp, const Vector4Template<T>& minVecValue, const Vector4Template<T>& maxVecValue )
{
    Vector4Template<T> retVec(Clamp(vecToClamp.x, minVecValue.x, maxVecValue.x), Clamp(vecToClamp.y, minVecValue.y, maxVecValue.y), Clamp(vecToClamp.z, minVecValue.z, maxVecValue.z), Clamp(vecToClamp.w, minVecValue.w, maxVecValue.w));
    return retVec;
}

template<class T>
Vector4Template<T> Abs(const Vector4Template<T>& v)
{
    return Vector4Template<T>(Abs(v.x), Abs(v.y), Abs(v.z), Abs(v.w));
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompLessEqual(const Vector4Template<T> &a, const Vector4Template<T> &b)
{
    return Mask4Template<T>(
            b.x-a.x,
            b.y-a.y,
            b.z-a.z,
            b.w-a.w
            );
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompGreaterEqual(const Vector4Template<T> &a, const Vector4Template<T> &b)
{
    return Mask4Template<T>(
            a.x-b.x,
            a.y-b.y,
            a.z-b.z,
            a.w-b.w
            );
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompLessThan(const Vector4Template<T> &a, const Vector4Template<T> &b)
{
    return Not(CompGreaterEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompGreaterThan(const Vector4Template<T> &a, const Vector4Template<T> &b)
{
    return Not(CompLessEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompEqual(const Vector4Template<T> &a, const Vector4Template<T> &b)
{
    return And(CompLessEqual(a, b), CompGreaterEqual(a,b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompNotEqual(const Vector4Template<T> &a, const Vector4Template<T> &b)
{
    return Not(And(CompLessEqual(a, b), CompGreaterEqual(a,b)));
}

template <class T>
inline __attribute__ ((always_inline)) Vector4Template<T> Select(const MaskScalarTemplate<T> &mask, const Vector4Template<T> &trueValue, const Vector4Template<T> &falseValue )
{
    return Vector4Template<T>(
            (T)__fsel((mask.mS), (trueValue.x), (falseValue.x)),
            (T)__fsel((mask.mS), (trueValue.y), (falseValue.y)),
            (T)__fsel((mask.mS), (trueValue.z), (falseValue.z)),
            (T)__fsel((mask.mS), (trueValue.w), (falseValue.w))
        );
}

template <class T>
inline __attribute__ ((always_inline)) Vector4Template<T> Select(const Mask4Template<T> &mask, const Vector4Template<T> &trueValue, const Vector4Template<T> &falseValue )
{
    return Vector4Template<T>(
            (T)__fsel((mask.mX), (trueValue.x), (falseValue.x)),
            (T)__fsel((mask.mY), (trueValue.y), (falseValue.y)),
            (T)__fsel((mask.mZ), (trueValue.z), (falseValue.z)),
            (T)__fsel((mask.mW), (trueValue.w), (falseValue.w))
        );
}





template<class T>
void Negate(const Vector4Template<T>& vec, Vector4Template<T>& r)
{
    r.Set(-vec.x, -vec.y, -vec.z, -vec.w);
}


template<class T>
void Mult(const Vector4Template<T>& vec, T scalar, Vector4Template<T>& r)
{
    r.Set(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);
}


template<class T>
void Divide(const Vector4Template<T>& vec, T scalar, Vector4Template<T>& r)
{
    T scalarInv= static_cast<T>(1.)/scalar;
    r.Set(vec.x*scalarInv, vec.y*scalarInv, vec.z*scalarInv, vec.w*scalarInv);
}


template<class T>
void Add(const Vector4Template<T>& a, const Vector4Template<T>& b, Vector4Template<T>& r)
{
    r.Set(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w);
}


template<class T>
void Subtract(const Vector4Template<T>& a, const Vector4Template<T>& b, Vector4Template<T>& r)
{
    r.Set(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w);
}


template<class T>
void Normalize(const Vector4Template<T>& vec, Vector4Template<T>& r)
{
    Mult(vec, MagnitudeRecip(vec), r);
}


template<class T>
void Mult(const Vector4Template<T>& a, const Vector4Template<T>& b, Vector4Template<T>& r)
{
    r.Set(a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w);
}


template<class T>
void Lerp(const Vector4Template<T>& v0, const Vector4Template<T>& v1, T t, Vector4Template<T>& r)
{
    Subtract(v1, v0, r);
    Mult(r, t,r );
    Add(v0, r,r );
}


template<class T>
void NLerp(const Vector4Template<T>& v0, const Vector4Template<T>& v1, T t, Vector4Template<T>& r)
{
    Subtract(v1, v0, r);
    Mult(r, t, r);
    Add(v0, r, r);
    Normalize(r, r);
}


template<class T>
void SLerp(const Vector4Template<T>& v0, const Vector4Template<T>& v1, T t, Vector4Template<T>& r)
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
        Vector4Template<T> a, b;

        Mult(v0, Sin((static_cast<T>(1.0f)-t)*theta)/Sin(theta), a);
        Mult(v1, Sin(t*theta)/Sin(theta), b);
        Add(a, b, r);
    }
}


template<class T>
void CrossXYZ(const Vector4Template<T>& v0, const Vector4Template<T>& v1, Vector4Template<T>& r)
{
    r = Vector4Template<T>(
            v0.y*v1.z - v1.y*v0.z,
            v0.z*v1.x - v0.x*v1.z,
            v0.x*v1.y - v0.y*v1.x,
            static_cast<T>(0.0f)
        );
}




}

}

}
