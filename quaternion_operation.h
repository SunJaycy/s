








#include <rw/math/fpu/constants_operation.h>











namespace rw {
namespace math {
namespace fpu {

template<class T>
QuaternionTemplate<T>& operator +=(QuaternionTemplate<T>& vec, const T& scalar)
{
    vec.Set(vec.x+scalar, vec.y+scalar, vec.z+scalar, vec.w+scalar);
    return vec;
}

template<class T>
QuaternionTemplate<T>& operator -=(QuaternionTemplate<T>& vec, const T& scalar)
{
    vec.Set(vec.x-scalar, vec.y-scalar, vec.z-scalar, vec.w-scalar);
    return vec;
}

template<class T>
QuaternionTemplate<T>& operator *=(QuaternionTemplate<T>& vec, const T& scalar)
{
    vec.Set(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);
    return vec;
}
template<class T>
QuaternionTemplate<T>& operator /=(QuaternionTemplate<T>& vec, const T& scalar)
{
    T scalarInv= static_cast<T>(1.0f)/scalar;
    vec.Set(vec.x*scalarInv, vec.y*scalarInv, vec.z*scalarInv, vec.w*scalarInv);
    return vec;
}
template<class T>
QuaternionTemplate<T>& operator +=(QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b)
{
    a.Set(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w);
    return a;
}
template<class T>
QuaternionTemplate<T>& operator -=(QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b)
{
    a.Set(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w);
    return a;
}




template<class T>
QuaternionTemplate<T> operator - (const QuaternionTemplate<T>& vec)
{
    QuaternionTemplate<T> r(-vec.x, -vec.y, -vec.z, -vec.w);
    return r;
}








template<class T>
QuaternionTemplate<T> operator * (const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b)
{
    return Mult(a, b);
}

template<class T>
QuaternionTemplate<T> operator * (const QuaternionTemplate<T>& vec, const T& scalar)
{
    QuaternionTemplate<T> r(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);
    return r;
}

template<class T>
QuaternionTemplate<T> operator * (const T& scalar, const QuaternionTemplate<T>& vec)
{
    QuaternionTemplate<T> r(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);
    return r;
}

template<class T>
QuaternionTemplate<T> operator / (const QuaternionTemplate<T>& vec, const T& scalar)
{
    T scalarInv= static_cast<T>(1.0f)/scalar;
    QuaternionTemplate<T> r(vec.x*scalarInv, vec.y*scalarInv, vec.z*scalarInv, vec.w*scalarInv);
    return r;
}

template<class T>
QuaternionTemplate<T> operator + (const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b)
{
    QuaternionTemplate<T> r(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w);
    return r;
}

template<class T>
QuaternionTemplate<T> operator + (const QuaternionTemplate<T>& a, const T& s)
{
    QuaternionTemplate<T> r(a.x+s, a.y+s, a.z+s, a.w+s);
    return r;
}

template<class T>
QuaternionTemplate<T> operator + (const T& s, const QuaternionTemplate<T>& a)
{
    QuaternionTemplate<T> r(a.x+s, a.y+s, a.z+s, a.w+s);
    return r;
}

template<class T>
QuaternionTemplate<T> operator - (const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b)
{
    QuaternionTemplate<T> r(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w);
    return r;
}

template<class T>
QuaternionTemplate<T> operator - (const QuaternionTemplate<T>& a, const T& s)
{
    QuaternionTemplate<T> r(a.x-s, a.y-s, a.z-s, a.w-s);
    return r;
}

template<class T>
QuaternionTemplate<T> operator - (const T& s, const QuaternionTemplate<T>& a)
{
    QuaternionTemplate<T> r(s-a.x, s-a.y, s-a.z, s-a.w);
    return r;
}

template<class T>
T MagnitudeSquared(const QuaternionTemplate<T>& vec)
{
    return vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w*vec.w;
}

template<class T>
bool IsAnyNaN(const QuaternionTemplate<T>& q)
{
    return (bool)(IsNaN(q.x) | IsNaN(q.y) | IsNaN(q.z) | IsNaN(q.w));
}

template<class T>
bool IsValid(const QuaternionTemplate<T>&q)
{
    return (IsValid(q.x) && IsValid(q.y) && IsValid(q.z) && IsValid(q.w));
}

template<class T>
bool IsIdentity(const QuaternionTemplate<T>&q, T tolerance = EPSILON)
{
    return IsSimilar( q, GetQuaternion_IdentityTemplate<T>(), tolerance );
}

template<class T>
bool IsUnit(const QuaternionTemplate<T>&q)
{
    return IsSimilar( MagnitudeSquared<T>(q), static_cast<T>(1.0f), static_cast<T>(SMALL_FLOAT) );
}

template<class T>
bool IsPure(const QuaternionTemplate<T>&q)
{
    bool result = IsZero(q.w);
    return result;
}

template<class T>
QuaternionTemplate<T> Min(const QuaternionTemplate<T>& v0, const QuaternionTemplate<T>& v1)
{
    return QuaternionTemplate<T>(Min(v0.x, v1.x), Min(v0.y, v1.y), Min(v0.z, v1.z), Min(v0.w, v1.w));
}

template<class T>
QuaternionTemplate<T> Max(const QuaternionTemplate<T>& v0, const QuaternionTemplate<T>& v1)
{
    return QuaternionTemplate<T>(Max(v0.x, v1.x), Max(v0.y, v1.y), Max(v0.z, v1.z), Max(v0.w, v1.w));
}

template<class T>
QuaternionTemplate<T> Clamp(const QuaternionTemplate<T>& quatToClamp, const QuaternionTemplate<T>& minQuatValue, const QuaternionTemplate<T>& maxQuatValue )
{
    QuaternionTemplate<T> retVec(Clamp(quatToClamp.x, minQuatValue.x, maxQuatValue.x), Clamp(quatToClamp.y, minQuatValue.y, maxQuatValue.y), Clamp(quatToClamp.z, minQuatValue.z, maxQuatValue.z), Clamp(quatToClamp.w, minQuatValue.w, maxQuatValue.w));
    return retVec;
}

template<class T>
QuaternionTemplate<T> Abs(const QuaternionTemplate<T>& v)
{
    return QuaternionTemplate<T>(Abs(v.x), Abs(v.y), Abs(v.z), Abs(v.w));
}

template<class T>
bool operator ==(const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b)
{
    return (a.x==b.x && a.y==b.y && a.z==b.z && a.w==b.w);
}

template<class T>
bool operator !=(const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b)
{
    return (a.x!=b.x || a.y!=b.y || a.z!=b.z || a.w!=b.w);
}

template<class T>
bool IsSimilar(const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b, T epsilon = (T)(SMALL_FLOAT))
{
    return (Abs(a.x-b.x) <= epsilon &&
            Abs(a.y-b.y) <= epsilon &&
            Abs(a.z-b.z) <= epsilon &&
            Abs(a.w-b.w) <= epsilon);
}

template<class T>
T Magnitude(const QuaternionTemplate<T>& vec)
{
    return Sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w*vec.w);
}

template<class T>
T MagnitudeRecip(const QuaternionTemplate<T>& vec)
{
    return static_cast<T>(1.0f) / Sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w*vec.w);
}

template<class T>
T Dot(const QuaternionTemplate<T>& a, const QuaternionTemplate<T> b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}



template<class T>
QuaternionTemplate<T> Negate(const QuaternionTemplate<T>& vec)
{
    QuaternionTemplate<T> r(-vec.x, -vec.y, -vec.z, -vec.w);
    return r;
}

template<class T>
QuaternionTemplate<T> Mult(const QuaternionTemplate<T>& vec, T scalar)
{
    QuaternionTemplate<T> r(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);
    return r;
}

template<class T>
QuaternionTemplate<T> Divide(const QuaternionTemplate<T>& vec, T scalar)
{
    T scalarInv= static_cast<T>(1.0f)/scalar;
    QuaternionTemplate<T> r(vec.x*scalarInv, vec.y*scalarInv, vec.z*scalarInv, vec.w*scalarInv);
    return r;
}

template<class T>
QuaternionTemplate<T> Add(const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b)
{
    QuaternionTemplate<T> r(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w);
    return r;
}

template<class T>
QuaternionTemplate<T> Subtract(const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b)
{
    QuaternionTemplate<T> r(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w);
    return r;
}



template<class T>
QuaternionTemplate<T> NormalizeFast(const QuaternionTemplate<T>& vec)
{
    QuaternionTemplate<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}



template<class T>
QuaternionTemplate<T> NormalizeEstimate(const QuaternionTemplate<T>& vec)
{
    QuaternionTemplate<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}

template<class T>
QuaternionTemplate<T> Normalize(const QuaternionTemplate<T>& vec)
{
    QuaternionTemplate<T> r(Mult(vec, MagnitudeRecip(vec)));
    return r;
}

template<class T>
QuaternionTemplate<T> Normalize(const QuaternionTemplate<T>& q, T &magnitude)
{
    magnitude = Magnitude(q);
    return QuaternionTemplate<T> (Mult(q, static_cast<T>(1.0f)/magnitude));
}

template<class T>
T NormalizeReturnMagnitude(const QuaternionTemplate<T> &q, QuaternionTemplate<T> &result)
{
    T magnitude = Magnitude(q);
    result = Mult(q, static_cast<T>(1.0f)/magnitude);
    return magnitude;
}

template<class T>
QuaternionTemplate<T> Mult(const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b)
{
    Vector3Template<T> v1(a.x, a.y, a.z);
    Vector3Template<T> v2(b.x, b.y, b.z);
    Vector3Template<T> lImaginary(v2*a.w + v1*b.w + Cross(v1, v2));
    T lrReal = a.w*b.w - Dot(v1, v2);
    return QuaternionTemplate<T>(lImaginary.x, lImaginary.y, lImaginary.z, lrReal);

}








template<class T>
QuaternionTemplate<T> Lerp(const QuaternionTemplate<T>& q0, const QuaternionTemplate<T>& q1, T t)
{

    if (Dot(q0,q1) > static_cast<T>(0.0f))
    {
        return Add(Mult(Subtract(q1,q0),t),q0);
    }
    else
    {
        return Add(Mult(Add(q1,q0),-t), q0);
    }

}
template<class T>
QuaternionTemplate<T> SLerp(const QuaternionTemplate<T>& v0, const QuaternionTemplate<T>& v1, T t)
{
    ;
    ;
    ;





    QuaternionTemplate<T> v0temp(v0);

    T dp = Dot(v0temp,v1);

    if(dp < static_cast<T>(0.0f))
    {


        v0temp = Negate(v0temp);
        dp = -dp;
    }

    if(dp > Cos(static_cast<T>(VECTOR_MIN_SLERP_ANGLE)))
    {
        return NLerp(v0temp,v1,t);
    }

    T theta = ACos(dp);

    v0temp = Mult(v0temp, Sin((static_cast<T>(1.0f)-t)*theta)/Sin(theta));
    return Add(v0temp,
            Mult(v1, Sin(t*theta)/Sin(theta))
            );
}








template<class T>
QuaternionTemplate<T> SLerpNoCheck(const QuaternionTemplate<T>& quat1, const QuaternionTemplate<T>& quat2, T ratio)
{
    QuaternionTemplate<T> lQuatResult;
    T alpha;
    T beta;
    T cosTheta;

    ;
    ;
    ;

    alpha = ratio;
    beta = static_cast<T>(1.0f) - alpha;


    cosTheta = Dot( quat1, quat2 );



    if( cosTheta < QUATERNION_SLERP_DOT_TOLERANCE )
    {
        T lrTheta;
        T lrCosecTheta;

        lrTheta = ACos(cosTheta);
        lrCosecTheta = Sin(lrTheta);
        lrCosecTheta = static_cast<T>(1.0f) / lrCosecTheta;

        beta *= lrTheta;
        beta = Sin(beta);
        beta *= lrCosecTheta;

        alpha *= lrTheta;
        alpha = Sin(alpha);
        alpha *= lrCosecTheta;
    }


    lQuatResult.x = beta * quat1.x + alpha * quat2.x ;
    lQuatResult.y = beta * quat1.y + alpha * quat2.y ;
    lQuatResult.z = beta * quat1.z + alpha * quat2.z ;
    lQuatResult.w = beta * quat1.w + alpha * quat2.w ;

    return lQuatResult;
}


template<class T>
QuaternionTemplate<T> NLerpEstimate(const QuaternionTemplate<T>& q0, const QuaternionTemplate<T>& q1, T t)
{
    return NormalizeEstimate( Lerp(q0,q1,t) );
}

template<class T>
QuaternionTemplate<T> NLerpFast(const QuaternionTemplate<T>& q0, const QuaternionTemplate<T>& q1, T t)
{
    return NormalizeFast( Lerp(q0,q1,t) );
}

template<class T>
QuaternionTemplate<T> NLerp(const QuaternionTemplate<T>& q0, const QuaternionTemplate<T>& q1, T t)
{
    return Normalize( Lerp(q0,q1,t) );
}












template<class T>
QuaternionTemplate<T> Concat(const QuaternionTemplate<T>& q0, const QuaternionTemplate<T>& q1)
{

    QuaternionTemplate<T> result = Normalize(q0*q1);

    return result;
}


















template<class T>
uint32_t CompressRotation(const QuaternionTemplate<T>& quat)
{

    ;

    uint32_t coord;
    uint32_t row;
    uint32_t col;
    uint32_t colCount;
    uint32_t result;
    T rowAngle;
    T colAngle;
    Vector4Template<T> absQuat(Abs(quat.x), Abs(quat.y), Abs(quat.z), Abs(quat.w));
    Vector3Template<T> axis;
    T length;
    const uint32_t wBits = 10;
    const uint32_t maxW = (1 << wBits) - 1;



    result = (uint32_t) (absQuat.w * static_cast<T>(1023.0f));
    if(result > maxW)
    {
        result = maxW;
    }


    if( quat.x < static_cast<T>(0.0f) ) result |= (1 << 10);
    if( quat.y < static_cast<T>(0.0f) ) result |= (1 << 11);
    if( quat.z < static_cast<T>(0.0f) ) result |= (1 << 12);
    if( quat.w < static_cast<T>(0.0f) ) result |= (1 << 13);


    axis.Set(absQuat.x, absQuat.y, absQuat.z);
    length = Magnitude(axis);
    if(length < static_cast<T>(0.001))
    {



        rowAngle = HALF_PI;
        colAngle = ZERO_FLOAT;
    }
    else
    {

        axis *= static_cast<T>(1.0f) / length;



        axis.x = Clamp( axis.x, static_cast<T>(-1.0f), static_cast<T>(1.0f) ) ;
        axis.y = Clamp( axis.y, static_cast<T>(-1.0f), static_cast<T>(1.0f) ) ;
        axis.z = Clamp( axis.z, static_cast<T>(-1.0f), static_cast<T>(1.0f) ) ;


        rowAngle = ACos( axis.y );
        colAngle = ASin( axis.x );
    }


    row = (uint32_t)(((rowAngle) / HALF_PI) * static_cast<T>(511.0f));

    ;


    colCount = row * 2;


    col = (uint32_t)((colAngle / HALF_PI) * colCount);


    coord = (row * row) + col;



    ;


    result |= (coord << 14);


    return result;
}









template<class T>
QuaternionTemplate<T> UnCompressRotation(uint32_t rotation)
{
    int32_t e;
    int32_t w;
    int32_t row;
    int32_t col;
    int32_t colCount;
    T rowAngle;
    T colAngle;
    T squaredZ;
    T axisScale;
    QuaternionTemplate<T> result;


    e = static_cast<int32_t>(rotation >> 14);


    row = (int32_t) Sqrt( static_cast<T>( e) );
    col = e - (row * row);


    colCount = 2 * row;


    rowAngle = ( static_cast<T>(row) / static_cast<T>(511.0f) ) * HALF_PI;
    if(colCount > 0)
    {
        colAngle = ( static_cast<T>(col) / static_cast<T>(colCount) ) * HALF_PI;
    }
    else
    {
        colAngle = static_cast<T>(0.0f);
    }


    result.y =Cos( rowAngle );
    result.x =Sin( colAngle );


    w = static_cast<int32_t>(rotation & 1023 );
    result.w =static_cast<T>(w) / static_cast<T>(1023.0f);


    axisScale = Sqrt(static_cast<T>(1.0f) - (result.w * result.w));
    if(axisScale > static_cast<T>(0.001))
    {
        result.x =result.x * axisScale;
        result.y =result.y * axisScale;
    }
    else
    {

        result.x =static_cast<T>(0.0f);
        result.y =static_cast<T>(0.0f);
        result.z =static_cast<T>(0.0f);
        return result;
    }




    squaredZ = static_cast<T>(1.0f) - result.x*result.x -
                result.y*result.y - result.w*result.w;
    if(squaredZ > static_cast<T>(0.0f))
    {
        result.z =Sqrt( squaredZ );
    }
    else
    {
        result.z =static_cast<T>(0.0f);
    }


    if( rotation & (1 << 10) ) result.x =-result.x;
    if( rotation & (1 << 11) ) result.y =-result.y;
    if( rotation & (1 << 12) ) result.z =-result.z;
    if( rotation & (1 << 13) ) result.w =-result.w;

    return result;
}

template<class T>
QuaternionTemplate<T> Inverse(const QuaternionTemplate<T>& q)
{
    T scalarInv= static_cast<T>(1.0f)/Dot(q, q);
    QuaternionTemplate<T> r(-q.x*scalarInv, -q.y*scalarInv, -q.z*scalarInv, q.w*scalarInv);
    return r;
}

template<class T>
QuaternionTemplate<T> Conj(const QuaternionTemplate<T>& q)
{
    QuaternionTemplate<T> r(-q.x, -q.y, -q.z, q.w);
    return r;
}

template<class T>
QuaternionTemplate<T> QuaternionFromAxisRotationAngle(const Vector3Template<T>& v, T angle_radians)
{
    ;

    T s, c;

    SinCos(angle_radians/static_cast<T>(2.0f), s, c);

    QuaternionTemplate<T> r(v.x*s, v.y*s, v.z*s, c);
    return r;
}
template<class T>
void AxisAngleFromQuaternion(const QuaternionTemplate<T>& q, Vector3Template<T>& axis_out, T& angle_out)
{
    T s;
    angle_out = ACos(q.w) * static_cast<T>(2.0f);

    T sinSquared = 1.0f - q.w * q.w;
    if( sinSquared < SMALL_FLOAT )
    {
        s = 0.0f;
    }
    else
    {















        s = InvSqrt( sinSquared );
    }

    axis_out.Set(q.x*s, q.y*s, q.z*s );
}











template<class T>
Vector3Template<T> EulerXYZFromQuaternion(const QuaternionTemplate<T>& q)
{
    return EulerXYZFromMatrix33(Matrix33FromQuaternion(q));
}

template<class T>
Vector3Template<T> TransformVector(const Vector3Template<T>& v, const QuaternionTemplate<T>& q)
{
    T xx = q.x * q.x;
    T yy = q.y * q.y;
    T zz = q.z * q.z;
    T xy = q.x * q.y;
    T xz = q.x * q.z;
    T yz = q.y * q.z;
    T wx = q.w * q.x;
    T wy = q.w * q.y;
    T wz = q.w * q.z;

    const T one(1.0f);
    const T two(2.0f);
    return Vector3Template<T>(
            v.x *(one-two*(yy+zz)) + v.y * two*(xy-wz) + v.z * two*(xz+wy),
            v.x * two*(xy+wz) + v.y * (one-two*(xx+zz)) + v.z * two*(yz-wx),
            v.x * two*(xz-wy) + v.y * two*(yz+wx) + v.z * (one-two*(xx+yy))
        );

}

template<class T>
QuaternionTemplate<T> QuaternionFromMatrix44(const Matrix44Template<T>& m, T epsilon = (T)(0.0f))
{
    Matrix33Template<T> mat33(GetXYZ(m.XAxis()), GetXYZ(m.YAxis()), GetXYZ(m.ZAxis()));

    return QuaternionFromMatrix33( mat33, epsilon );
}

template<class T>
QuaternionTemplate<T> QuaternionFromMatrix44Affine(const Matrix44AffineTemplate<T>& m, T epsilon = (T)(0.0f))
{
    Matrix33Template<T> mat33(m.XAxis(), m.YAxis(), m.ZAxis());

    return QuaternionFromMatrix33( mat33, epsilon );
}

template<class T>
QuaternionTemplate<T> QuaternionFromMatrix33(const Matrix33Template<T>& m, T epsilon = (T)(0.0f))
{
    T tr = m.xAxis.x + m.yAxis.y + m.zAxis.z;

    if (tr > epsilon)
    {
        T s = Sqrt(tr + static_cast<T>(1.0f));
        T s2 = static_cast<T>(0.5f) / s;
        return QuaternionTemplate<T>(
                (m.yAxis.z - m.zAxis.y) * s2,
                (m.zAxis.x - m.xAxis.z) * s2,
                (m.xAxis.y - m.yAxis.x) * s2,
                static_cast<T>(0.5f) * s
            );
    }
    else
    {
        if ((m.xAxis.x > m.yAxis.y) && (m.xAxis.x > m.zAxis.z))
        {
            T s = Sqrt((m.xAxis.x - (m.yAxis.y + m.zAxis.z)) + static_cast<T>(1.0f));
            T s2 = static_cast<T>(0.5f) / s;
            return QuaternionTemplate<T>(
                    static_cast<T>(0.5f) * s,
                    (m.yAxis.x + m.xAxis.y) * s2,
                    (m.xAxis.z + m.zAxis.x) * s2,
                    (m.yAxis.z - m.zAxis.y) * s2
                );
        }
        else if (m.yAxis.y > m.zAxis.z)
        {
            T s = Sqrt((m.yAxis.y - (m.zAxis.z + m.xAxis.x)) + static_cast<T>(1.0f));
            T s2 = static_cast<T>(0.5f) / s;
            return QuaternionTemplate<T>(
                    (m.yAxis.x + m.xAxis.y) * s2,
                    static_cast<T>(0.5f) * s,
                    (m.zAxis.y + m.yAxis.z) * s2,
                    (m.zAxis.x - m.xAxis.z) * s2
                );
        }
        else
        {
            T s = Sqrt((m.zAxis.z - (m.xAxis.x + m.yAxis.y)) + static_cast<T>(1.0f));
            T s2 = static_cast<T>(0.5f) / s;
            return QuaternionTemplate<T>(
                    (m.xAxis.z + m.zAxis.x) * s2,
                    (m.zAxis.y + m.yAxis.z) * s2,
                    static_cast<T>(0.5f) * s,
                    (m.xAxis.y - m.yAxis.x) * s2
                );
        }
    }
}

template<class T>
QuaternionTemplate<T> QuaternionFromEulerXYZ(const Vector3Template<T>& euler)
{
    T ci, cj, ch, si, sj, sh;

    T ti = euler.x * static_cast<T>(0.5f);
    T tj = euler.y * static_cast<T>(0.5f);
    T th = euler.z * static_cast<T>(0.5f);

    SinCos(ti, si, ci);
    SinCos(tj, sj, cj);
    SinCos(th, sh, ch);

    T cc = ci * ch;
    T cs = ci * sh;
    T sc = si * ch;
    T ss = si * sh;

    return QuaternionTemplate<T>(
        cj * sc - sj * cs,
        cj * ss + sj * cc,
        cj * cs - sj * sc,
        cj * cc + sj * ss
    );
}

template<class T>
QuaternionTemplate<T> QuaternionFromLookDirection(const Vector3Template<T>& lookDirection, const Vector3Template<T>& up)
{
    Matrix44Template<T> matrix = Matrix44FromLookAt( lookDirection, up, GetVector3_ZeroTemplate<T>() );
    return QuaternionFromMatrix44(matrix);
}

template<class T>
QuaternionTemplate<T> QuaternionFromLookAt(const Vector3Template<T>& lookAt, const Vector3Template<T>& up, const Vector3Template<T>& eyePosition)
{
    return QuaternionFromLookDirection( Subtract(lookAt, eyePosition), up );
}

template<class T>
Vector3Template<T> QuaternionGetMatrix44AffineRowX(QuaternionTemplate<T>& quat)
{
    QuaternionTemplate<T> quatTemp = quat * T(SQRT_2);
    T twoXY = quatTemp.x * quatTemp.y;
    T twoXZ = quatTemp.x * quatTemp.z;
    T twoYY = quatTemp.y * quatTemp.y;
    T twoZZ = quatTemp.z * quatTemp.z;
    T twoWY = quatTemp.w * quatTemp.y;
    T twoWZ = quatTemp.w * quatTemp.z;
    return Vector3Template<T>(
       T(1.0f) - twoYY - twoZZ,
                         twoXY + twoWZ,
                         twoXZ - twoWY
           );
}

template<class T>
Vector3Template<T> QuaternionGetMatrix44AffineRowY(QuaternionTemplate<T>& quat)
{
    QuaternionTemplate<T> quatTemp = quat * T(SQRT_2);
    T twoXX = quatTemp.x * quatTemp.x;
    T twoXY = quatTemp.x * quatTemp.y;
    T twoYZ = quatTemp.y * quatTemp.z;
    T twoZZ = quatTemp.z * quatTemp.z;
    T twoWX = quatTemp.w * quatTemp.x;
    T twoWZ = quatTemp.w * quatTemp.z;
    return Vector3Template<T>(
                              twoXY - twoWZ,
            T(1.0f) - twoXX - twoZZ,
                              twoYZ + twoWX
            );
}

template<class T>
Vector3Template<T> QuaternionGetMatrix44AffineRowZ(QuaternionTemplate<T>& quat)
{
    QuaternionTemplate<T> quatTemp = quat * T(SQRT_2);
    T twoXX = quatTemp.x * quatTemp.x;
    T twoXZ = quatTemp.x * quatTemp.z;
    T twoYY = quatTemp.y * quatTemp.y;
    T twoYZ = quatTemp.y * quatTemp.z;
    T twoWX = quatTemp.w * quatTemp.x;
    T twoWY = quatTemp.w * quatTemp.y;
    return Vector3Template<T>(
                                 twoXZ + twoWY,
                                 twoYZ - twoWX,
               T(1.0f) - twoXX - twoYY
            );
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompLessEqual(const QuaternionTemplate<T> &a, const QuaternionTemplate<T> &b)
{
    return Mask4Template<T>(
            b.x-a.x,
            b.y-a.y,
            b.z-a.z,
            b.w-a.w
            );
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompGreaterEqual(const QuaternionTemplate<T> &a, const QuaternionTemplate<T> &b)
{
    return Mask4Template<T>(
            a.x-b.x,
            a.y-b.y,
            a.z-b.z,
            a.w-b.w
            );
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompLessThan(const QuaternionTemplate<T> &a, const QuaternionTemplate<T> &b)
{
    return Not(CompGreaterEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompGreaterThan(const QuaternionTemplate<T> &a, const QuaternionTemplate<T> &b)
{
    return Not(CompLessEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompEqual(const QuaternionTemplate<T> &a, const QuaternionTemplate<T> &b)
{
    return And(CompLessEqual(a, b), CompGreaterEqual(a,b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompNotEqual(const QuaternionTemplate<T> &a, const QuaternionTemplate<T> &b)
{
    return Not(And(CompLessEqual(a, b), CompGreaterEqual(a,b)));
}

template <class T>
inline __attribute__ ((always_inline)) QuaternionTemplate<T> Select(const MaskScalarTemplate<T> &mask, const QuaternionTemplate<T> &trueValue, const QuaternionTemplate<T> &falseValue )
{
    return QuaternionTemplate<T>(
            (T)__fsel((mask.mS), (trueValue.x), (falseValue.x)),
            (T)__fsel((mask.mS), (trueValue.y), (falseValue.y)),
            (T)__fsel((mask.mS), (trueValue.z), (falseValue.z)),
            (T)__fsel((mask.mS), (trueValue.w), (falseValue.w))
        );
}

template <class T>
inline __attribute__ ((always_inline)) QuaternionTemplate<T> Select(const Mask4Template<T> &mask, const QuaternionTemplate<T> &trueValue, const QuaternionTemplate<T> &falseValue )
{
    return QuaternionTemplate<T>(
            (T)__fsel((mask.mX), (trueValue.x), (falseValue.x)),
            (T)__fsel((mask.mY), (trueValue.y), (falseValue.y)),
            (T)__fsel((mask.mZ), (trueValue.z), (falseValue.z)),
            (T)__fsel((mask.mW), (trueValue.w), (falseValue.w))
        );
}





 template<class T>
void Negate(const QuaternionTemplate<T>& vec, QuaternionTemplate<T> &r)
{
    r.Set(-vec.x, -vec.y, -vec.z, -vec.w);

}

 template<class T>
void Mult(const QuaternionTemplate<T>& vec, T scalar, QuaternionTemplate<T>& r)
{
    r.Set(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);

}

 template<class T>
void Divide(const QuaternionTemplate<T>& vec, T scalar, QuaternionTemplate<T>& r)
{
    T scalarInv= static_cast<T>(1.0f)/scalar;
    r.Set(vec.x*scalarInv, vec.y*scalarInv, vec.z*scalarInv, vec.w*scalarInv);

}

 template<class T>
void Add(const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b, QuaternionTemplate<T>& r)
{
    r.Set(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w);
}

 template<class T>
void Subtract(const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b, QuaternionTemplate<T>& r)
{
    r.Set(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w);
}

 template<class T>
void Normalize(const QuaternionTemplate<T>& vec, QuaternionTemplate<T>& r)
{
    r= Mult(vec, MagnitudeRecip(vec));
}

 template<class T>
void Mult(const QuaternionTemplate<T>& a, const QuaternionTemplate<T>& b, QuaternionTemplate<T>& r)
{
    r.Set(a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y,
        a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x,
        a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w,
        a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z
        );

}

 template<class T>
void Lerp(const QuaternionTemplate<T>& v0, const QuaternionTemplate<T>& v1, T t, QuaternionTemplate<T>& r)
{
    r= Lerp(v0, v1, t);
}
 template<class T>
void SLerp(const QuaternionTemplate<T>& v0, const QuaternionTemplate<T>& v1, T t, QuaternionTemplate<T>& r)
{
    r= SLerp(v0, v1, t);
}

 template<class T>
void NLerp(const QuaternionTemplate<T>& v0, const QuaternionTemplate<T>& v1, T t, QuaternionTemplate<T>& r)
{
    r= NLerp(v0, v1, t);
}


 template<class T>
void Inverse(const QuaternionTemplate<T>& q, QuaternionTemplate<T>& r)
{
    r = Inverse(q);
}

 template<class T>
void Conj(const QuaternionTemplate<T>& q, QuaternionTemplate<T>& r)
{
    r = Conj(q);
}

 template<class T>
void QuaternionFromAxisAngle(const Vector3Template<T>& v, T angle_radians, QuaternionTemplate<T>& r)
{
    r = QuaternionFromAxisRotationAngle( v, angle_radians );
}

 template<class T>
void EulerXYZFromQuaternion(const QuaternionTemplate<T>& q, Vector3Template<T> &r)
{
    r = EulerXYZFromQuaternion(q);
}

 template<class T>
void Vector3Transform(const QuaternionTemplate<T>& q, const Vector3Template<T>& v, Vector3Template<T>& r)
{
    r = TransformVector(v, q);
}

 template<class T>
void QuaternionFromMatrix44(const Matrix44Template<T>& m, QuaternionTemplate<T>& q, T epsilon = (T)(0.0f))
{
    q = QuaternionFromMatrix44(m, epsilon);
}

 template<class T>
void QuaternionFromMatrix33(const Matrix33Template<T>& m, QuaternionTemplate<T>& q, T epsilon = (T)(0.0f))
{
    q = QuaternionFromMatrix33(m, epsilon);
}

 template<class T>
void QuaternionFromEulerXYZ(const Vector3Template<T>& euler, QuaternionTemplate<T>& r)
{
    r = QuaternionFromEulerXYZ(euler);
}



}

}

}
