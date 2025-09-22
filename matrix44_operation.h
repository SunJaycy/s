











#include <rw/math/fpu/vector4_operation.h>
#include <rw/math/fpu/matrix33_operation.h>

namespace rw {
namespace math {
namespace fpu {


template<class T>
bool operator ==(const Matrix44Template<T> &a, const Matrix44Template<T> &b)
{
    return a.xAxis == b.xAxis &&
            a.yAxis == b.yAxis &&
            a.zAxis == b.zAxis &&
            a.wAxis == b.wAxis;
}


template<class T>
bool operator !=(const Matrix44Template<T> &a,const Matrix44Template<T> &b)
{
    return !(a==b);
}


template<class T>
bool IsValid(const Matrix44Template<T> &a)
{
    return IsValid(a.XAxis()) &&
           IsValid(a.YAxis()) &&
           IsValid(a.ZAxis()) &&
           IsValid(a.WAxis());
}


template<class T>
bool IsValid3x3(const Matrix44Template<T> &a)
{
    return IsValid(GetXYZ(a.XAxis())) &&
           IsValid(GetXYZ(a.YAxis())) &&
           IsValid(GetXYZ(a.ZAxis()));
}


template<class T>
bool IsSimilar(const Matrix44Template<T> &a, const Matrix44Template<T> &b, T epsilon = SMALL_FLOAT)
{
    return IsSimilar( a.xAxis, b.xAxis, epsilon ) &&
           IsSimilar( a.yAxis, b.yAxis, epsilon ) &&
           IsSimilar( a.zAxis, b.zAxis, epsilon ) &&
           IsSimilar( a.wAxis, b.wAxis, epsilon );
}




template<class T> bool IsAnyNaN(const Matrix44Template<T> &m)
{
    return IsAnyNaN(m.xAxis) || IsAnyNaN(m.yAxis) || IsAnyNaN(m.zAxis) || IsAnyNaN(m.wAxis);
}


template<class T>
Matrix44Template<T> SLerp(const Matrix44Template<T> &lFrom, const Matrix44Template<T> &lTo, T lrParam, T &lprAngle)
{
    Matrix44Template<T> lReturnmatrix;
    Matrix44Template<T> lScratch;
    Vector3Template<T> axis;
    Vector3Template<T> lCentre;
    T lrAngle;


    if(lrParam <= static_cast<T>(0.0f))
    {
        lprAngle = AngleBetweenVectors( GetXYZ(lFrom.ZAxis()), GetXYZ(lTo.ZAxis()) );
        return lFrom;
    }
    else if(lrParam >= static_cast<T>(1.0f))
    {
        lprAngle = static_cast<T>(0.0f);
        return lTo;
    }


    lScratch = Mult( InverseOrthonormal(lFrom), lTo );

    QueryRotate(lScratch, axis, lrAngle, lCentre );


    if( lrAngle < static_cast<T>(MATRIX_MIN_SLERP_ANGLE) )
    {

        Matrix44Template<T> lLerpmat;

        lLerpmat.XAxis() = lTo.XAxis() - lFrom.XAxis();
        lLerpmat.YAxis() = lTo.YAxis() - lFrom.YAxis();
        lLerpmat.ZAxis() = lTo.ZAxis() - lFrom.ZAxis();
        lLerpmat.WAxis() = lTo.WAxis() - lFrom.WAxis();


        lLerpmat *= lrParam;

        lReturnmatrix.XAxis() = Normalize(lFrom.XAxis() + lLerpmat.XAxis());
        lReturnmatrix.YAxis() = Normalize(lFrom.YAxis() + lLerpmat.YAxis());
        lReturnmatrix.ZAxis() = Normalize(lFrom.ZAxis() + lLerpmat.ZAxis());
        lReturnmatrix.WAxis() = lFrom.WAxis() + lLerpmat.WAxis();
    }
    else

    {
        Matrix44Template<T> lRotatematrix;


        lReturnmatrix = lFrom;
        lReturnmatrix.WAxis() = GetVector4_WAxisTemplate<T>() ;


        lRotatematrix = Matrix44FromAxisRotationAngle( axis, ( lrAngle * lrParam ) );
        lReturnmatrix = Mult( lReturnmatrix, lRotatematrix );


        lReturnmatrix.WAxis() = (lTo.WAxis() - lFrom.WAxis()) * lrParam + lFrom.WAxis();
    }

    lprAngle = lrAngle - (lrAngle * lrParam);
    return lReturnmatrix;

}


template<class T>
Matrix44Template<T> SLerpByAngle(const Matrix44Template<T> &lFrom, const Matrix44Template<T> &lTo, T lrMaxAngle, T &lprAngle)
{
    Matrix44Template<T> lReturnmatrix;
    Matrix44Template<T> lRotatematrix;
    Vector3Template<T> axis;
    Vector3Template<T> lCentre;
    T lrAngle;
    T lrDeltaAngle;


    Matrix44Template<T> lScratch = InverseOrthonormal(lFrom);
    lScratch = Mult( lScratch, lTo );

    QueryRotate(lScratch, axis, lrAngle, lCentre );
    if( IsZero(axis) )
    {
        lprAngle = 0.0f;
        return lTo;
    }


    Vector4Template<T> lPosBackup = lFrom.WAxis();
    lReturnmatrix = lFrom;
    lReturnmatrix.WAxis() = GetVector4_WAxisTemplate<T>() ;


    lrDeltaAngle = Min(lrAngle, lrMaxAngle);

    lRotatematrix = Matrix44FromAxisRotationAngle( axis, lrDeltaAngle );
    lReturnmatrix = Mult( lReturnmatrix, lRotatematrix );


    lReturnmatrix.WAxis() = lPosBackup ;

    lprAngle = lrAngle - lrDeltaAngle;

    return lReturnmatrix;
}


template<class T>
void SelfAdd(Matrix44Template<T> &a, const Matrix44Template<T> &b)
{
    a = Add(a, b);
}


template<class T>
void SelfSubtract(Matrix44Template<T> &a, const Matrix44Template<T> &b)
{
    a = Subtract(a, b);
}


template<class T>
void SelfMult(Matrix44Template<T> &m, T a)
{
    m = Mult(m, a);
}


template<class T>
void SelfDivide(Matrix44Template<T> &m, T a)
{
    m = Divide(m, a);
}


template<class T>
T Determinant(const Matrix44Template<T> &m)
{
    return
        m.xAxis.x * (
                m.yAxis.y * ( m.zAxis.z*m.wAxis.w - m.zAxis.w*m.wAxis.z ) +
                m.yAxis.z * ( m.wAxis.y*m.zAxis.w - m.zAxis.y*m.wAxis.w ) +
                m.yAxis.w * ( m.zAxis.y*m.wAxis.z - m.wAxis.y*m.zAxis.z )
                ) +
        m.xAxis.y * (
                m.yAxis.x * ( m.zAxis.w*m.wAxis.z - m.zAxis.z*m.wAxis.w ) +
                m.yAxis.z * ( m.zAxis.x*m.wAxis.w - m.wAxis.x*m.zAxis.w ) +
                m.yAxis.w * ( m.wAxis.x*m.zAxis.z - m.zAxis.x*m.wAxis.z )
                ) +
        m.xAxis.z * (
                m.yAxis.x * ( m.zAxis.y*m.wAxis.w - m.wAxis.y*m.zAxis.w ) +
                m.yAxis.y * ( m.wAxis.x*m.zAxis.w - m.zAxis.x*m.wAxis.w ) +
                m.yAxis.w * ( m.zAxis.x*m.wAxis.y - m.wAxis.x*m.zAxis.y )
                ) +
        m.xAxis.w * (
                m.yAxis.x * ( m.wAxis.y*m.zAxis.z - m.zAxis.y*m.wAxis.z ) +
                m.yAxis.y * ( m.zAxis.x*m.wAxis.z - m.wAxis.x*m.zAxis.z ) +
                m.yAxis.z * ( m.wAxis.x*m.zAxis.y - m.zAxis.x*m.wAxis.y )
                );
}




template<class T>
Matrix44Template<T> Negate(const Matrix44Template<T> &m)
{
    return Mult(m, static_cast<T>(-1.0f));
}


template<class T>
Matrix44Template<T> Mult(const Matrix44Template<T> &m, T a)
{
    Matrix44Template<T> rm(
            a * m.xAxis,
            a * m.yAxis,
            a * m.zAxis,
            a * m.wAxis
            );
    return rm;
}


template<class T>
Vector4Template<T> Mult(const Vector4Template<T> &v, const Matrix44Template<T> &m)
{
    Vector4Template<T> rv(
            m.xAxis.x * v.x + m.yAxis.x * v.y + m.zAxis.x * v.z + m.wAxis.x * v.w,
            m.xAxis.y * v.x + m.yAxis.y * v.y + m.zAxis.y * v.z + m.wAxis.y * v.w,
            m.xAxis.z * v.x + m.yAxis.z * v.y + m.zAxis.z * v.z + m.wAxis.z * v.w,
            m.xAxis.w * v.x + m.yAxis.w * v.y + m.zAxis.w * v.z + m.wAxis.w * v.w
            );
    return rv;
}


template<class T>
Matrix44Template<T> Mult(const Matrix44Template<T> &m, const Matrix44Template<T> &b)
{
    Matrix44Template<T> rm(
                Mult(m.xAxis, b),
                Mult(m.yAxis, b),
                Mult(m.zAxis, b),
                Mult(m.wAxis, b)
                );
    return rm;
}


template<class T>
Matrix44Template<T> Divide(const Matrix44Template<T> &m, T a)
{
    Matrix44Template<T> rm(
            m.xAxis / a,
            m.yAxis / a,
            m.zAxis / a,
            m.wAxis / a
            );
    return rm;
}


template<class T>
Matrix44Template<T> Add(const Matrix44Template<T> &a, const Matrix44Template<T> &b)
{
    Matrix44Template<T> m(
                Add(a.xAxis, b.xAxis),
                Add(a.yAxis, b.yAxis),
                Add(a.zAxis, b.zAxis),
                Add(a.wAxis, b.wAxis)
                );
    return m;
}


template<class T>
Matrix44Template<T> Subtract(const Matrix44Template<T> &a, const Matrix44Template<T> &b)
{
    Matrix44Template<T> m(
                Subtract(a.xAxis, b.xAxis),
                Subtract(a.yAxis, b.yAxis),
                Subtract(a.zAxis, b.zAxis),
                Subtract(a.wAxis, b.wAxis)
                );
    return m;
}


template<class T>
Matrix44Template<T> Transpose(const Matrix44Template<T> &m)
{
    Matrix44Template<T> result;
    for (int row=0; row<4; ++row)
    {
        for (int column=0; column<4; ++column)
        {
            result.SetElem(row, column, m.GetRow(column).GetComponent( row) );
        }
    }
    return result;
}


template<class T>
Matrix44Template<T> Inverse(const Matrix44Template<T> &m)
{
    T determinant;
    return Inverse(m, determinant);
}


template<class T>
Matrix44Template<T> Inverse(const Matrix44Template<T> &m, T& determinant)
{
    determinant = Determinant(m);
    ;
    if (determinant == static_cast<T>(0.0f))
    {
        return GetMatrix44_ZeroTemplate<T>();
    }
    else
    {
        Matrix44Template<T> rm(
            ((m.yAxis.y*(m.zAxis.z*m.wAxis.w-m.zAxis.w*m.wAxis.z)+m.yAxis.z*(m.wAxis.y*m.zAxis.w-m.zAxis.y*m.wAxis.w)+m.yAxis.w*(m.zAxis.y*m.wAxis.z-m.wAxis.y*m.zAxis.z))/determinant),
            ((m.zAxis.y*(m.xAxis.z*m.wAxis.w-m.xAxis.w*m.wAxis.z)+m.zAxis.z*(m.xAxis.w*m.wAxis.y-m.xAxis.y*m.wAxis.w)+m.zAxis.w*(m.xAxis.y*m.wAxis.z-m.xAxis.z*m.wAxis.y))/determinant),
            ((m.wAxis.y*(m.xAxis.z*m.yAxis.w-m.xAxis.w*m.yAxis.z)+m.wAxis.z*(m.xAxis.w*m.yAxis.y-m.xAxis.y*m.yAxis.w)+m.wAxis.w*(m.xAxis.y*m.yAxis.z-m.xAxis.z*m.yAxis.y))/determinant),
            ((m.xAxis.y*(m.yAxis.w*m.zAxis.z-m.yAxis.z*m.zAxis.w)+m.xAxis.z*(m.yAxis.y*m.zAxis.w-m.yAxis.w*m.zAxis.y)+m.xAxis.w*(m.yAxis.z*m.zAxis.y-m.yAxis.y*m.zAxis.z))/determinant),
            ((m.yAxis.z*(m.zAxis.x*m.wAxis.w-m.wAxis.x*m.zAxis.w)+m.yAxis.w*(m.wAxis.x*m.zAxis.z-m.zAxis.x*m.wAxis.z)+m.yAxis.x*(m.zAxis.w*m.wAxis.z-m.zAxis.z*m.wAxis.w))/determinant),
            ((m.zAxis.z*(m.xAxis.x*m.wAxis.w-m.wAxis.x*m.xAxis.w)+m.zAxis.w*(m.wAxis.x*m.xAxis.z-m.xAxis.x*m.wAxis.z)+m.zAxis.x*(m.xAxis.w*m.wAxis.z-m.xAxis.z*m.wAxis.w))/determinant),
            ((m.wAxis.z*(m.xAxis.x*m.yAxis.w-m.yAxis.x*m.xAxis.w)+m.wAxis.w*(m.yAxis.x*m.xAxis.z-m.xAxis.x*m.yAxis.z)+m.wAxis.x*(m.xAxis.w*m.yAxis.z-m.xAxis.z*m.yAxis.w))/determinant),
            ((m.xAxis.z*(m.zAxis.x*m.yAxis.w-m.yAxis.x*m.zAxis.w)+m.xAxis.w*(m.yAxis.x*m.zAxis.z-m.zAxis.x*m.yAxis.z)+m.xAxis.x*(m.yAxis.z*m.zAxis.w-m.yAxis.w*m.zAxis.z))/determinant),
            ((m.yAxis.w*(m.zAxis.x*m.wAxis.y-m.wAxis.x*m.zAxis.y)+m.yAxis.x*(m.zAxis.y*m.wAxis.w-m.wAxis.y*m.zAxis.w)+m.yAxis.y*(m.wAxis.x*m.zAxis.w-m.zAxis.x*m.wAxis.w))/determinant),
            ((m.zAxis.w*(m.xAxis.x*m.wAxis.y-m.wAxis.x*m.xAxis.y)+m.zAxis.x*(m.xAxis.y*m.wAxis.w-m.xAxis.w*m.wAxis.y)+m.zAxis.y*(m.wAxis.x*m.xAxis.w-m.xAxis.x*m.wAxis.w))/determinant),
            ((m.wAxis.w*(m.xAxis.x*m.yAxis.y-m.yAxis.x*m.xAxis.y)+m.wAxis.x*(m.xAxis.y*m.yAxis.w-m.xAxis.w*m.yAxis.y)+m.wAxis.y*(m.yAxis.x*m.xAxis.w-m.xAxis.x*m.yAxis.w))/determinant),
            ((m.xAxis.w*(m.zAxis.x*m.yAxis.y-m.yAxis.x*m.zAxis.y)+m.xAxis.x*(m.yAxis.w*m.zAxis.y-m.yAxis.y*m.zAxis.w)+m.xAxis.y*(m.yAxis.x*m.zAxis.w-m.zAxis.x*m.yAxis.w))/determinant),
            ((m.yAxis.x*(m.wAxis.y*m.zAxis.z-m.zAxis.y*m.wAxis.z)+m.yAxis.y*(m.zAxis.x*m.wAxis.z-m.wAxis.x*m.zAxis.z)+m.yAxis.z*(m.wAxis.x*m.zAxis.y-m.zAxis.x*m.wAxis.y))/determinant),
            ((m.zAxis.x*(m.xAxis.z*m.wAxis.y-m.xAxis.y*m.wAxis.z)+m.zAxis.y*(m.xAxis.x*m.wAxis.z-m.wAxis.x*m.xAxis.z)+m.zAxis.z*(m.wAxis.x*m.xAxis.y-m.xAxis.x*m.wAxis.y))/determinant),
            ((m.wAxis.x*(m.xAxis.z*m.yAxis.y-m.xAxis.y*m.yAxis.z)+m.wAxis.y*(m.xAxis.x*m.yAxis.z-m.yAxis.x*m.xAxis.z)+m.wAxis.z*(m.yAxis.x*m.xAxis.y-m.xAxis.x*m.yAxis.y))/determinant),
            ((m.xAxis.x*(m.yAxis.y*m.zAxis.z-m.yAxis.z*m.zAxis.y)+m.xAxis.y*(m.zAxis.x*m.yAxis.z-m.yAxis.x*m.zAxis.z)+m.xAxis.z*(m.yAxis.x*m.zAxis.y-m.zAxis.x*m.yAxis.y))/determinant)
             );
        return rm;
    }
}


template<class T>
Matrix44Template<T> Matrix44FromQuaternion(const QuaternionTemplate<T> &q)
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

    const T zero(static_cast<T>(0.0f));
    const T one(static_cast<T>(1.0f));
    const T two(static_cast<T>(2.0f));

    Matrix44Template<T> m(
        one-two*(yy+zz), two*(xy+wz), two*(xz-wy), zero,
        two*(xy-wz), one-two*(xx+zz), two*(yz+wx), zero,
        two*(xz+wy), two*(yz-wx), one-two*(xx+yy), zero,
        zero, zero, zero, one
        );
    return m;
}


template<class T>
Matrix44Template<T> Matrix44FromEulerXYZ(const Vector3Template<T> &euler)
{
    T ci, cj, ch, si, sj, sh;

    SinCos(euler.x, si, ci);
    SinCos(euler.y, sj, cj);
    SinCos(euler.z, sh, ch);

    T cc = ci * ch;
    T cs = ci * sh;
    T sc = si * ch;
    T ss = si * sh;

    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);

    Matrix44Template<T> m(
        cj * ch , cj * sh , -sj , zero,
        sj * sc - cs, sj * ss + cc, cj * si , zero,
        sj * cc + ss, sj * cs - sc, cj * ci , zero,
        zero, zero, zero, one
        );
    return m;
}


template<class T>
Vector3Template<T> EulerXYZFromMatrix44(const Matrix44Template<T>& m)
{
    Matrix33Template<T> m33(GetXYZ(m.XAxis()), GetXYZ(m.YAxis()), GetXYZ(m.ZAxis()));
    return EulerXYZFromMatrix33( m33 );
}









template<class T>
Matrix44Template<T> Matrix44InverseRotationalComponent(const Matrix44Template<T> &m)
{
    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);

    Matrix44Template<T> rm(
        m.xAxis.x , m.yAxis.x , m.zAxis.x, zero,
        m.xAxis.y , m.yAxis.y , m.zAxis.y, zero,
        m.xAxis.z , m.yAxis.z , m.zAxis.z, zero,
           -m.wAxis.x*m.xAxis.x-m.wAxis.y*m.xAxis.y-m.wAxis.z*m.xAxis.z,
           -m.wAxis.x*m.yAxis.x-m.wAxis.y*m.yAxis.y-m.wAxis.z*m.yAxis.z,
           -m.wAxis.x*m.zAxis.x-m.wAxis.y*m.zAxis.y-m.wAxis.z*m.zAxis.z,
        one );
    return rm;
}


template<class T>
Matrix44Template<T> Matrix44FromScale(const Vector3Template<T> &scale)
{
    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);

    Matrix44Template<T> m(
        scale.x, zero, zero, zero,
        zero, scale.y, zero, zero,
        zero, zero, scale.z, zero,
        zero, zero, zero, one
    );
    return m;
}


template<class T>
Matrix44Template<T> Matrix44FromTranslation(const Vector3Template<T> &trans)
{
    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);

    Matrix44Template<T> m(
        one, zero, zero, zero,
        zero, one, zero, zero,
        zero, zero, one, zero,
        trans.x, trans.y, trans.z, one
        );
    return m;
}


template<class T>
Matrix44Template<T> Matrix44FromScaleQuaternion(const Vector3Template<T> &scale, const QuaternionTemplate<T> &q)
{
    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);
    const T two = static_cast<T>(2.0f);
    T xx = q.x * q.x;
    T yy = q.y * q.y;
    T zz = q.z * q.z;
    T xy = q.x * q.y;
    T xz = q.x * q.z;
    T yz = q.y * q.z;
    T wx = q.w * q.x;
    T wy = q.w * q.y;
    T wz = q.w * q.z;

    Matrix44Template<T> m(
            scale.x * (one-two*(yy+zz)), scale.x *two*(xy+wz), scale.x *two*(xz-wy), zero,
            scale.y *two*(xy-wz), scale.y * (one-two*(xx+zz)), scale.y *two*(yz+wx), zero,
            scale.z *two*(xz+wy), scale.z *two*(yz-wx), scale.z * (one-two*(xx+yy)), zero,
                    zero, zero, zero, one
    );
    return m;
}


template<class T>
Matrix44Template<T> Matrix44FromScaleTranslation(const Vector3Template<T> &scale, const Vector3Template<T> &trans)
{
    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);

    Matrix44Template<T> m(
        scale.x, zero, zero, zero,
        zero, scale.y, zero, zero,
        zero, zero, scale.z, zero,
        trans.x, trans.y, trans.z, one
    );
    return m;
}


template<class T>
Matrix44Template<T> Matrix44TransposeRotationalComponent(const Matrix44Template<T> &m)
{
    Matrix44Template<T> result = m;


    result.SetElem(1, m.GetElem(4));
    result.SetElem(4, m.GetElem(1));

    result.SetElem(2, m.GetElem(8));
    result.SetElem(8, m.GetElem(2));

    result.SetElem(6, m.GetElem(9));
    result.SetElem(9, m.GetElem(6));
    return result;
}


template<class T>
Matrix44Template<T> Matrix44Translate(const Matrix44Template<T> &m, const Vector3Template<T> &trans)
{

    Vector4Template<T> translationVector(
        (trans.x * m.GetElem( 0)) + (trans.y * m.GetElem( 4)) + (trans.z * m.GetElem( 8)),
        (trans.x * m.GetElem( 1)) + (trans.y * m.GetElem( 5)) + (trans.z * m.GetElem( 9)),
        (trans.x * m.GetElem( 2)) + (trans.y * m.GetElem( 6)) + (trans.z * m.GetElem(10)),
        static_cast<T>(0.0f)
        );


    Matrix44Template<T> rm(
        m.xAxis,
        m.yAxis,
        m.zAxis,
        m.wAxis + translationVector
        );
    return rm;
}


template<class T>
Matrix44Template<T> Matrix44FromQuaternionTranslation(const QuaternionTemplate<T> &q, const Vector3Template<T> &trans)
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

    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);
    const T two = static_cast<T>(2.0f);

    Matrix44Template<T> m(
            one-two*(yy+zz), two*(xy+wz), two*(xz-wy), zero,
            two*(xy-wz), one-two*(xx+zz), two*(yz+wx), zero,
            two*(xz+wy), two*(yz-wx), one-two*(xx+yy), zero,
            trans.x, trans.y, trans.z, one
            );
    return m;
}


template<class T>
inline __attribute__ ((always_inline)) Matrix44Template<T> Matrix44FromScaleQuaternionTranslation(const Vector3Template<T> &scale, const QuaternionTemplate<T> &q, const Vector3Template<T> &trans);

template<class T>
Matrix44Template<T> Matrix44FromScaleQuaternionTranslation(const Vector3Template<T> &scale, const QuaternionTemplate<T> &q, const Vector3Template<T> &trans)
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

    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);
    const T two = static_cast<T>(2.0f);

    Matrix44Template<T> m(
            scale.x*(one-two*(yy+zz)), scale.x*two*(xy+wz), scale.x*two*(xz-wy), zero,
            scale.y*two*(xy-wz), scale.y*(one-two*(xx+zz)), scale.y*two*(yz+wx), zero,
            scale.z*two*(xz+wy), scale.z*two*(yz-wx), scale.z*(one-two*(xx+yy)), zero,
            trans.x, trans.y, trans.z, one
            );
    return m;
}


template<class T>
Vector4Template<T> Mult3x3(const Vector4Template<T> &v, const Matrix44Template<T> &m)
{
    Matrix33Template<T> m33(GetXYZ(m.XAxis()), GetXYZ(m.YAxis()), GetXYZ(m.ZAxis()));
    Vector3Template<T> v3 = Mult(GetXYZ(v), m33);
    Vector4Template<T> v4( v3.x, v3.y, v3.z, v.w );
    return v4;
}


template<class T>
Vector3Template<T> Mult3x3(const Vector3Template<T> &v, const Matrix44Template<T> &m)
{
    Matrix33Template<T> m33(GetXYZ(m.XAxis()), GetXYZ(m.YAxis()), GetXYZ(m.ZAxis()));
    Vector3Template<T> v3 = Mult(v, m33);
    return v3;
}


template<class T>
Matrix44Template<T> Inverse3x3(const Matrix44Template<T> &m)
{
    T determinant;
    return Inverse3x3(m, determinant);
}


template<class T>
Matrix44Template<T> Inverse3x3(const Matrix44Template<T> &m, T &determinant)
{
    determinant = Determinant3x3(m);
    ;
    if(determinant==static_cast<T>(0.0f))
    {
        return GetMatrix44_ZeroTemplate<T>();
    }
    else
    {
        Matrix44Template<T> result;
        for(int i=0; i<3; ++i)
        {
            for(int j=0; j<3; ++j)
            {
                int32_t i1=(i+1)%3;
                int32_t i2=(i+2)%3;
                int32_t j1=(j+1)%3;
                int32_t j2=(j+2)%3;
                result.SetElem(j,i,
                        (m.GetRow(i1).GetComponent( j1)*m.GetRow(i2).GetComponent( j2)-m.GetRow(i2).GetComponent( j1)*m.GetRow(i1).GetComponent( j2)) / determinant
                        );
            }
            result.SetElem(i,3, m.GetRow(i).w);
        }
        result.WAxis() = m.WAxis();
        return result;
    }
}


template<class T>
T Determinant3x3(const Matrix44Template<T> &m)
{
    Matrix33Template<T> m33(GetXYZ(m.XAxis()), GetXYZ(m.YAxis()), GetXYZ(m.ZAxis()));
    return Determinant( m33 );
}


template<class T>
Vector3Template<T> TransformPoint(const Vector3Template<T>& pt, const Matrix44Template<T>& matrix)
{
    return Vector3Template<T>(matrix.xAxis.x * pt.x + matrix.yAxis.x * pt.y + matrix.zAxis.x * pt.z + matrix.wAxis.x,
                              matrix.xAxis.y * pt.x + matrix.yAxis.y * pt.y + matrix.zAxis.y * pt.z + matrix.wAxis.y,
                              matrix.xAxis.z * pt.x + matrix.yAxis.z * pt.y + matrix.zAxis.z * pt.z + matrix.wAxis.z);
}


template<class T>
void TransformPoints(const Vector3Template<T>* const pts, int numPoints, Matrix44Template<T> matrix, Vector3Template<T>* transformedPts)
{
    for( int point = 0; point < numPoints; point++ )
    {
        transformedPts[point] = TransformPoint(pts[point], matrix);
    }
}


template<class T>
Vector3Template<T> TransformVector(const Vector3Template<T>& vec, const Matrix44Template<T>& matrix)
{
    Vector4Template<T> transformedPoint;
    transformedPoint = matrix.XAxis() * vec.x;
    transformedPoint += matrix.YAxis() * vec.y;
    transformedPoint += matrix.ZAxis() * vec.z;
    return Vector3Template<T>(*reinterpret_cast<Vector3Template<T>*>(&transformedPoint));
}


template<class T>
Matrix44Template<T> Mult(const Matrix44AffineTemplate<T> &m, const Matrix44Template<T> &b)
{
















    return Matrix44Template<T>(
                Vector4Template<T>( b.xAxis.x * m.xAxis.x + b.yAxis.x * m.xAxis.y + b.zAxis.x * m.xAxis.z, b.xAxis.y * m.xAxis.x + b.yAxis.y * m.xAxis.y + b.zAxis.y * m.xAxis.z, b.xAxis.z * m.xAxis.x + b.yAxis.z * m.xAxis.y + b.zAxis.z * m.xAxis.z, b.xAxis.w * m.xAxis.x + b.yAxis.w * m.xAxis.y + b.zAxis.w * m.xAxis.z ),
                Vector4Template<T>( b.xAxis.x * m.yAxis.x + b.yAxis.x * m.yAxis.y + b.zAxis.x * m.yAxis.z, b.xAxis.y * m.yAxis.x + b.yAxis.y * m.yAxis.y + b.zAxis.y * m.yAxis.z, b.xAxis.z * m.yAxis.x + b.yAxis.z * m.yAxis.y + b.zAxis.z * m.yAxis.z, b.xAxis.w * m.yAxis.x + b.yAxis.w * m.yAxis.y + b.zAxis.w * m.yAxis.z ),
                Vector4Template<T>( b.xAxis.x * m.zAxis.x + b.yAxis.x * m.zAxis.y + b.zAxis.x * m.zAxis.z, b.xAxis.y * m.zAxis.x + b.yAxis.y * m.zAxis.y + b.zAxis.y * m.zAxis.z, b.xAxis.z * m.zAxis.x + b.yAxis.z * m.zAxis.y + b.zAxis.z * m.zAxis.z, b.xAxis.w * m.zAxis.x + b.yAxis.w * m.zAxis.y + b.zAxis.w * m.zAxis.z ),
                Vector4Template<T>( b.xAxis.x * m.wAxis.x + b.yAxis.x * m.wAxis.y + b.zAxis.x * m.wAxis.z + b.wAxis.x, b.xAxis.y * m.wAxis.x + b.yAxis.y * m.wAxis.y + b.zAxis.y * m.wAxis.z + b.wAxis.y, b.xAxis.z * m.wAxis.x + b.yAxis.z * m.wAxis.y + b.zAxis.z * m.wAxis.z + b.wAxis.z, b.xAxis.w * m.wAxis.x + b.yAxis.w * m.wAxis.y + b.zAxis.w * m.wAxis.z + b.wAxis.w )
                );



}


template<class T>
void TransformVectors(const Vector3Template<T>* const vecs, int numVectors, Matrix44Template<T> matrix, Vector3Template<T> * transformedVecs)
{
    for( int vecIndex = 0; vecIndex < numVectors; vecIndex++ )
    {
        transformedVecs[vecIndex] = TransformVector(vecs[vecIndex], matrix);
    }
}


template<class T>
Vector3Template<T> Transform(const Vector4Template<T>& vec, const Matrix44Template<T>& matrix)
{
    Vector4Template<T> transformedVector;
    transformedVector = matrix.XAxis() * vec.x;
    transformedVector += matrix.YAxis() * vec.y;
    transformedVector += matrix.ZAxis() * vec.z;
    transformedVector += matrix.WAxis() * vec.w;;
    return Vector3Template<T>(*reinterpret_cast<Vector3Template<T>*>(&transformedVector));
}


template<class T>
void Transform(const Vector4Template<T>* const vecs, int numVectors, const Matrix44Template<T>& matrix, Vector3Template<T> * transformedVecs)
{
    for( int vecIndex = 0; vecIndex < numVectors; vecIndex++ )
    {
        transformedVecs[vecIndex] = Transform(vecs[vecIndex], matrix);
    }
}


template<class T>
Matrix44Template<T> Matrix44FromAxisRotationAngle(const Vector3Template<T>& axis, T angle)
{
    T s, c;

    SinCos(angle, s, c);
    T t = static_cast<T>(1.0f) - c;
    T tx = t * axis.x;
    T ty = t * axis.y;
    T tz = t * axis.z;
    T sx = s * axis.x;
    T sy = s * axis.y;
    T sz = s * axis.z;

    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);

    Matrix44Template<T> rm(
        tx * axis.x + c ,
        tx * axis.y + sz,
        tx * axis.z - sy,
        zero,

        ty * axis.x - sz,
        ty * axis.y + c ,
        ty * axis.z + sx,
        zero,

        tz * axis.x + sy,
        tz * axis.y - sx,
        tz * axis.z + c,
        zero,

        zero,
        zero,
        zero,
        one
        );
    return rm;
}


template<class T>
Matrix44Template<T> Matrix44FromDiagonal(T a)
{
    Matrix44Template<T> rm(
         a,0,0,0,
         0,a,0,0,
         0,0,a,0,
         0,0,0,a
         );
    return rm;
}


template<class T>
Matrix44Template<T> Matrix44FromXRotationAngle(T angle)
{
    T s,c;
    SinCos(angle,s,c);
    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);
    Matrix44Template<T> rm(
         one, zero, zero, zero,
         zero, c, s, zero,
         zero, -s, c, zero,
         zero, zero, zero, one
         );
    return rm;
}


template<class T>
Matrix44Template<T> Matrix44FromYRotationAngle(T angle)
{
    T s,c;
    SinCos(angle,s,c);
    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);
    Matrix44Template<T> rm(
         c, zero, -s, zero,
         zero, one, zero, zero,
         s, zero, c, zero,
         zero, zero, zero, one
         );
    return rm;
}


template<class T>
Matrix44Template<T> Matrix44FromZRotationAngle(T angle)
{
    T s,c;
    SinCos(angle,s,c);
    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);
    Matrix44Template<T> rm(
         c, s, zero, zero,
        -s, c, zero, zero,
         zero, zero, one, zero,
         zero, zero, zero, one );
    return rm;
}


template<class T>
Matrix44Template<T> OrthoNormalize(const Matrix44Template<T>& m)
{




    Matrix44Template<T> result;
    const int numRows = 4;
    for( int row = 0; row < numRows; ++row )
    {

        const Vector4Template<T> &inputRow = m.GetRow(row);
        Vector4Template<T> tempResult = inputRow;

        for( int i = 0; i < row; ++i )
        {
            tempResult -= result.GetRow(i) * Dot(result.GetRow(i), inputRow );
        }
        result.SetRow( row, Normalize(tempResult) );
    }
    return result;
}


template<class T>
T GetOrthogonalError(const Matrix44Template<T>& matrix)
{
    Matrix44Template<T> identity;
    identity.SetIdentity();

    Matrix44Template<T> result = Mult(matrix, Transpose(matrix));
    SelfSubtract(result, identity);

    Vector4Template<T> errorVec( MagnitudeSquared( result.XAxis() ),
                                 MagnitudeSquared( result.YAxis() ),
                                 MagnitudeSquared( result.ZAxis() ),
                                 MagnitudeSquared( result.WAxis() ) );

    T error = MagnitudeSquared(errorVec);
    return error;
}


template<class T>
T GetOrthogonalRowSetError(const Matrix44Template<T>& matrix)
{


    Vector3Template<T> errorVec1( Dot( matrix.XAxis(), matrix.YAxis() ),
                                                    Dot( matrix.XAxis(), matrix.ZAxis() ),
                                                    Dot( matrix.XAxis(), matrix.WAxis() ) );
    Vector3Template<T> errorVec2( Dot( matrix.YAxis(), matrix.ZAxis() ),
                                                    Dot( matrix.YAxis(), matrix.WAxis() ),
                                                    Dot( matrix.ZAxis(), matrix.WAxis() ) );
    T error = MagnitudeSquared(errorVec1) + MagnitudeSquared(errorVec2);
    return error;
}


template<class T>
bool IsOrthogonal(Matrix44Template<T> a, T tolerance=EPSILON)
{
    return IsZero( GetOrthogonalError(a), tolerance );
}


template<class T>
bool IsOrthogonalRowSet(Matrix44Template<T> a, T tolerance=EPSILON)
{
    return IsZero( GetOrthogonalRowSetError(a), tolerance );
}


template<class T>
T GetNormalError(const Matrix44Template<T>& matrix)
{
    Vector4Template<T> errorVec( MagnitudeSquared( matrix.XAxis() ) - static_cast<T>(1.0f),
                                                MagnitudeSquared( matrix.YAxis() ) - static_cast<T>(1.0f),
                                                MagnitudeSquared( matrix.ZAxis() ) - static_cast<T>(1.0f),
                                                MagnitudeSquared( matrix.WAxis() ) - static_cast<T>(1.0f) );
    T error = MagnitudeSquared(errorVec);
    return error;
}


template<class T>
bool IsNormal(const Matrix44Template<T>& a, T tolerance=EPSILON)
{
    return IsZero( GetNormalError(a), tolerance );
}


template<class T>
Matrix44Template<T> InverseOrthonormal(const Matrix44Template<T>& m)
{
    ;
    return Transpose(m);
}


template<class T>
Matrix44Template<T> RotateAroundXAxis(const Matrix44Template<T>& m, T angle)
{








    T s,c;
    SinCos(angle, s, c);


    return Matrix44Template<T>(
        m.XAxis(),
        m.ZAxis() * s + m.YAxis() * c,
        m.ZAxis() * c - m.YAxis() * s,
        m.WAxis()
    );
}


template<class T>
Matrix44Template<T> RotateAroundYAxis(const Matrix44Template<T>& m, T angle)
{








    T s,c;

    SinCos(angle, s, c);


    return Matrix44Template<T>(
        m.XAxis() * c - m.ZAxis() * s,
        m.YAxis(),
        m.XAxis() * s + m.ZAxis() * c,
        m.WAxis()
    );
}


template<class T>
Matrix44Template<T> RotateAroundZAxis(Matrix44Template<T> m, T angle)
{








    T s,c;

    SinCos(angle, s, c);


    return Matrix44Template<T>(
        m.YAxis() * s + m.XAxis() * c,
        m.YAxis() * c - m.XAxis() * s,
        m.ZAxis(),
        m.WAxis()
    );
}


template<class T>
Matrix44Template<T> Matrix44FromPerspective(T w, T h, T zn, T zf)
{
    const T zero = static_cast<T>(0.0f);
    const T negOne = static_cast<T>(-1.0f);
    const T two = static_cast<T>(2.0f);
    Matrix44Template<T> rm(
        two*zn/w, zero, zero, zero,
            zero, two*zn/h, zero, zero,
            zero, zero, zf/(zn-zf), negOne,
            zero, zero, zn*zf/(zn-zf), zero );
    return rm;
}


template<class T>
Matrix44Template<T> Matrix44FromOrtho(T w, T h, T zn, T zf)
{
    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);
    const T two = static_cast<T>(2.0f);
    Matrix44Template<T> rm(
        two/w, zero, zero, zero,
        zero, two/h, zero, zero,
        zero, zero, one/(zn-zf), zero,
        zero, zero, zn/(zn-zf), one
        );
    return rm;
}


template<class T>
Matrix44Template<T> Matrix44FromOrthoOffCenter(T l, T r, T b, T t, T zn, T zf)
{
    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);
    const T two = static_cast<T>(2.0f);
    Matrix44Template<T> rm(
        two/(r-l), zero, zero, zero,
        zero, two/(t-b), zero, zero,
        zero, zero, one/(zn-zf), zero,
        (l+r)/(l-r), (t+b)/(b-t), zn/(zn-zf), one
      );
    return rm;
}


template<class T>
Matrix44Template<T> Matrix44FromPerspectiveFov(T fov, T aspect, T zn, T zf)
{

    T h = Tan(fov/static_cast<T>(2.0f));
    T w = h * aspect;

    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);
    const T negOne = static_cast<T>(-1.0f);
    Matrix44Template<T> rm(
          one/w, zero, zero, zero,
          zero, one/h, zero, zero,
          zero, zero, zf/(zn-zf), negOne,
          zero, zero, zn*zf/(zn-zf), zero
          );
    return rm;
}


template<class T>
Matrix44Template<T> Matrix44FromLookAt(const Vector3Template<T>& lookAt, const Vector3Template<T>& up, const Vector3Template<T>& eyePosition)
{

    Vector3Template<T> zaxis = Normalize(Subtract(eyePosition, lookAt));
    Vector3Template<T> xaxis = Normalize(Cross(up, zaxis));
    Vector3Template<T> yaxis = Cross(zaxis, xaxis);

    const T zero = static_cast<T>(0.0f);
    const T one = static_cast<T>(1.0f);
    Matrix44Template<T> rm(
        xaxis.x, yaxis.x, zaxis.x, zero,
        xaxis.y, yaxis.y, zaxis.y, zero,
        xaxis.z, yaxis.z, zaxis.z, zero,
        -Dot(xaxis, eyePosition), -Dot(yaxis, eyePosition), -Dot(zaxis, eyePosition), one
        );
    return rm;
}


template<class T>
Matrix44Template<T> Matrix44FromPerspectiveOffCenter(T l, T r, T b, T t, T zn, T zf)
{

    const T zero = static_cast<T>(0.0f);
    const T negOne = static_cast<T>(-1.0f);
    const T two = static_cast<T>(2.0f);
    Matrix44Template<T> rm(
        two*zn/(r-l), zero, zero, zero,
        zero, two*zn*(t-b), zero, zero,
        (l+r)/(r-l), (t+b)/(t-b), zf/(zn-zf), negOne,
        zero, zero, zn*zf/(zn-zf), zero
        );
    return rm;
}


template<class T>
T GetNormalError3x3(const Matrix44Template<T>& matrix)
{
    Matrix33Template<T> m33(
                                            matrix.GetElem(0), matrix.GetElem(1), matrix.GetElem(2),
                                            matrix.GetElem(4), matrix.GetElem(5), matrix.GetElem(6),
                                            matrix.GetElem(8), matrix.GetElem(9), matrix.GetElem(10));
    return GetNormalError<T>( m33 );
}


template<class T>
bool IsNormal3x3(const Matrix44Template<T>& matrix, T tolerance=EPSILON)
{
    return IsZero( GetNormalError3x3(matrix), tolerance );
}


template<class T>
T GetOrthogonalRowSetError3x3(const Matrix44Template<T>& matrix)
{
    Matrix33Template<T> m33(
                                            matrix.GetElem(0), matrix.GetElem(1), matrix.GetElem(2),
                                            matrix.GetElem(4), matrix.GetElem(5), matrix.GetElem(6),
                                            matrix.GetElem(8), matrix.GetElem(9), matrix.GetElem(10));
    return GetOrthogonalRowSetError<T>( m33 );
}


template<class T>
T GetOrthogonalError3x3(const Matrix44Template<T>& matrix)
{
    Matrix33Template<T> m33(
                                            matrix.GetElem(0), matrix.GetElem(1), matrix.GetElem(2),
                                            matrix.GetElem(4), matrix.GetElem(5), matrix.GetElem(6),
                                            matrix.GetElem(8), matrix.GetElem(9), matrix.GetElem(10));
    return GetOrthogonalError<T>( m33 );
}


template<class T>
Vector3Template<T> QueryRotateDegenerateUnitAxis(const Matrix44Template<T>& matrix)
{
    Vector3Template<T> unitAxis;
    if(matrix.XAxis().x > matrix.YAxis().y)
    {
        if(matrix.XAxis().x > matrix.ZAxis().z)
        {
            T xVal = static_cast<T>(1.0f) + matrix.XAxis().x;
            unitAxis.x =xVal*xVal;
            unitAxis.y =matrix.XAxis().y + matrix.YAxis().x;
            unitAxis.z =matrix.XAxis().z + matrix.ZAxis().x;
        }
        else
        {
            T zVal = static_cast<T>(1.0f) + matrix.ZAxis().z;
            unitAxis.z =zVal*zVal;
            unitAxis.x =matrix.ZAxis().x + matrix.XAxis().z;
            unitAxis.y =matrix.ZAxis().y + matrix.YAxis().z;
        }
    }
    else
    {
        if(matrix.YAxis().y > matrix.ZAxis().z)
        {
            T yVal = static_cast<T>(1.0f) + matrix.YAxis().y;
            unitAxis.y =yVal*yVal;
            unitAxis.z =matrix.YAxis().z + matrix.ZAxis().y;
            unitAxis.x =matrix.YAxis().x + matrix.XAxis().y;
        }
        else
        {
            T zVal = static_cast<T>(1.0f) + matrix.ZAxis().z;
            unitAxis.z =zVal*zVal;
            unitAxis.x =matrix.ZAxis().x + matrix.XAxis().z;
            unitAxis.y =matrix.ZAxis().y + matrix.YAxis().z;
        }
    }
    unitAxis = Normalize( unitAxis );
    return unitAxis;
}


template<class T>
void QueryRotate(const Matrix44Template<T>& matrix, Vector3Template<T>& unitAxis, T& angle, Vector3Template<T>& center)
{
    Vector3Template<T> twoSinThetaAxis;
    T twoCosTheta = matrix.XAxis().x + matrix.YAxis().y + matrix.ZAxis().z - static_cast<T>(1.0f);
    twoSinThetaAxis.x =matrix.YAxis().z - matrix.ZAxis().y;
    twoSinThetaAxis.y =matrix.ZAxis().x - matrix.XAxis().z;
    twoSinThetaAxis.z =matrix.XAxis().y - matrix.YAxis().x;
    T twoSinTheta = Magnitude(twoSinThetaAxis);
    if(twoSinTheta > static_cast<T>(0.0f))
    {
        const T lrRecipLength = static_cast<T>(1.0f) / twoSinTheta;
        unitAxis = twoSinThetaAxis * lrRecipLength;
    }
    else
    {
        unitAxis = Vector3Template<T>(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
    }
    angle = ATan2(twoSinTheta, twoCosTheta);
    if((twoSinTheta <= T(MINIMUM_RECIPROCAL)) && (twoCosTheta <= static_cast<T>(0.0f)))
    {
        unitAxis = QueryRotateDegenerateUnitAxis(matrix);
    }
    Vector3Template<T> axisXpos = Cross(unitAxis, GetXYZ(matrix.WAxis()));
    center = Cross(axisXpos, unitAxis) * static_cast<T>(0.5f);
    center += axisXpos * (static_cast<T>(0.5f) * twoSinTheta / (static_cast<T>(2.0f) - twoCosTheta));
}


template<class T>
bool IsOrthogonal3x3(const Matrix44Template<T>& matrix, T tolerance=EPSILON)
{
    return IsZero( GetOrthogonalError3x3(matrix), tolerance );
}


template<class T>
bool IsOrthogonalRowSet3x3(const Matrix44Template<T>& matrix, T tolerance=EPSILON)
{
    return IsZero( GetOrthogonalRowSetError3x3(matrix), tolerance );
}


template<class T>
Matrix44Template<T> OrthoNormalize3x3(const Matrix44Template<T>& matrix)
{
    Vector3Template<T> *vpU, *vpV, *vpW;

    Vector3Template<T> right = Normalize(GetXYZ(matrix.XAxis()));
    Vector3Template<T> up = Normalize(GetXYZ(matrix.YAxis()));
    Vector3Template<T> at = Normalize(GetXYZ(matrix.ZAxis()));
    const Vector4Template<T> &pos = matrix.WAxis();

    Vector3Template<T> vInner( Magnitude(GetXYZ(matrix.XAxis())),
                                              Magnitude(GetXYZ(matrix.YAxis())),
                                              Magnitude(GetXYZ(matrix.ZAxis())) );

    if (vInner.x > static_cast<T>(0.0f))
    {
        if (vInner.y > static_cast<T>(0.0f))
        {
            if (vInner.z > static_cast<T>(0.0f))
            {
                Vector3Template<T> vOuter(Abs(Dot(up, at)), Abs(Dot(at,right)), Abs(Dot(right, up)));
                if (vOuter.x < vOuter.y)
                {
                    if (vOuter.x < vOuter.z)
                    {
                        vpU = &up;
                        vpV = &at;
                        vpW = &right;
                    }
                    else
                    {
                        vpU = &right;
                        vpV = &up;
                        vpW = &at;
                    }
                }
                else
                {
                    if (vOuter.y < vOuter.z)
                    {
                        vpU = &at;
                        vpV = &right;
                        vpW = &up;
                    }
                    else
                    {
                        vpU = &right;
                        vpV = &up;
                        vpW = &at;
                    }
                }
            }
            else
            {
                vpU = &right;
                vpV = &up;
                vpW = &at;
            }
        }
        else
        {
            vpU = &at;
            vpV = &right;
            vpW = &up;
        }
    }
    else
    {
        vpU = &up;
        vpV = &at;
        vpW = &right;
    }
    *vpW = Normalize(Cross(*vpU, *vpV));
    *vpV = Normalize(Cross(*vpW, *vpU));
    Matrix44Template<T> result;
    result.XAxis() = Vector4Template<T>(right, static_cast<T>(0.0f));
    result.YAxis() = Vector4Template<T>(up, static_cast<T>(0.0f));
    result.ZAxis() = Vector4Template<T>(at, static_cast<T>(0.0f));
    result.WAxis() = pos;


    result.WAxis().w = static_cast<T>(1.0f);
    return result;
}


template<class T>
Matrix44Template<T> ScaleRow(const Matrix44Template<T>& m, T r0, T r1, T r2)
{
    Vector4Template<T> row0Scale = Vector4Template<T>( r0, r0, r0, static_cast<T>(1.0f) );
    Vector4Template<T>row1Scale = Vector4Template<T>( r1, r1, r1, static_cast<T>(1.0f) );
    Vector4Template<T> row2Scale = Vector4Template<T>( r2, r2, r2, static_cast<T>(1.0f) );
    Matrix44Template<T> rm(
        Mult( row0Scale, m.xAxis ),
        Mult( row1Scale, m.yAxis ),
        Mult( row2Scale, m.zAxis ),
        m.wAxis
        );
    return rm;
}


template<class T>
Matrix44Template<T> ScaleColumn(const Matrix44Template<T>& m, T c0, T c1, T c2 )
{
    Vector4Template<T> rowMultiplier(c0, c1, c2, static_cast<T>(1.0f));
    Matrix44Template<T> rm(
        Mult( m.xAxis, rowMultiplier ),
        Mult( m.yAxis, rowMultiplier ),
        Mult( m.zAxis, rowMultiplier ),
        m.wAxis
        );
    return rm;
}


template<class T>
Matrix44Template<T>& operator *=(Matrix44Template<T> &m, T a)
{
    m = Mult(m, a);
    return m;
}


template<class T>
Matrix44Template<T>& operator /=(Matrix44Template<T> &m, T a)
{
    m = Divide(m, a);
    return m;
}


template<class T>
Matrix44Template<T>& operator *=(Matrix44Template<T> &m, const Matrix44Template<T> &b)
{
    m = Mult(m, b);
    return m;
}


template<class T>
Matrix44Template<T>& operator +=(Matrix44Template<T> &m, const Matrix44Template<T> &b)
{
    m = Add(m, b);
    return m;
}


template<class T>
Matrix44Template<T>& operator -=(Matrix44Template<T> &m, const Matrix44Template<T> &b)
{
    m = Subtract(m, b);
    return m;
}


template<class T>
Matrix44Template<T> operator - (const Matrix44Template<T> &m)
{
    return Negate(m);
}


template<class T>
Matrix44Template<T> operator * (const Matrix44Template<T> &m, T a)
{
    return Mult(m, a);
}


template<class T>
Matrix44Template<T> operator * (T a, const Matrix44Template<T> &b)
{
    return Mult(b, a);
}


template<class T>
Matrix44Template<T> operator / (const Matrix44Template<T> &m, T a)
{
    return Divide(m, a);
}


template<class T>
Matrix44Template<T> operator + (const Matrix44Template<T> &a, const Matrix44Template<T> &b)
{
    return Add(a, b);
}


template<class T>
Matrix44Template<T> operator - (const Matrix44Template<T> &a, const Matrix44Template<T> &b)
{
    return Subtract(a, b);
}


template<class T>
Matrix44Template<T> operator * (const Matrix44Template<T> &a, const Matrix44Template<T> &b)
{
    return Mult(a, b);
}


template<class T>
Vector4Template<T> operator * (const Vector4Template<T> &v, const Matrix44Template<T> &m)
{
    return Mult(v, m);
}

template <class T>
inline Matrix44Template<T> Select(const MaskScalarTemplate<T> &mask, const Matrix44Template<T> &trueValue, const Matrix44Template<T> &falseValue )
{
    return Matrix44Template<T>(
            Select( mask, trueValue.xAxis, falseValue.xAxis ),
            Select( mask, trueValue.yAxis, falseValue.yAxis ),
            Select( mask, trueValue.zAxis, falseValue.zAxis ),
            Select( mask, trueValue.wAxis, falseValue.wAxis )
        );
}




template<class T>
void Negate(const Matrix44Template<T> &m, Matrix44Template<T> &result)
{
    result = Negate(m);
}


template<class T>
void Mult(const Matrix44Template<T> &m, T a, Matrix44Template<T> &result)
{
    result = Mult(m, a);
}


template<class T>
void Mult(const Vector4Template<T> &v, const Matrix44Template<T> &m, Vector4Template<T> &result)
{
    result = Mult(v, m);
}


template<class T>
void Mult(const Matrix44Template<T> &m, const Matrix44Template<T> &b, Matrix44Template<T> &result)
{
    result = Mult(m, b);
}


template<class T>
void Divide(const Matrix44Template<T> &m, T a, Matrix44Template<T> &result)
{
    result = Divide(m, a);
}


template<class T>
void Add(const Matrix44Template<T> &a, const Matrix44Template<T> &b, Matrix44Template<T> &result)
{
    result = Add(a, b);
}


template<class T>
void Subtract(const Matrix44Template<T> &a, const Matrix44Template<T> &b, Matrix44Template<T> &result)
{
    result = Subtract(a, b);
}


template<class T>
void Transpose(const Matrix44Template<T> &m, Matrix44Template<T> &result)
{
    result = Transpose(m);
}


template<class T>
T Inverse(const Matrix44Template<T> &m, Matrix44Template<T> &result)
{
    T determinant;
    result = Inverse(m, determinant);
    return determinant;
}


template<class T>
void Matrix44FromQuaternion(const QuaternionTemplate<T> &q, Matrix44Template<T> &result)
{
    result = Matrix44FromQuaternion<T>(q);
}


template<class T>
void Matrix44FromAxisAngle(const Vector3Template<T> &axis, T angle, Matrix44Template<T> &result)
{
    result = Matrix44FromAxisRotationAngle(axis, angle);
}


template<class T>
void Matrix44FromEulerXYZ(const Vector3Template<T> &euler, Matrix44Template<T> &result)
{
    result = Matrix44FromEulerXYZ(euler);
}


template<class T>
void EulerXYZFromMatrix44(const Matrix44Template<T>& m, Vector3Template<T> &result)
{
    result = EulerXYZFromMatrix44(m);
}


template<class T>
void Matrix44InverseRotTrans(const Matrix44Template<T> &m, Matrix44Template<T> &result)
{
    result = Matrix44InverseRotationalComponent(m);
}


template<class T>
void Matrix44FromScale(const Vector3Template<T> &scale, Matrix44Template<T> &result)
{
    result = Matrix44FromScale(scale);
}


template<class T>
void Matrix44FromTranslation(const Vector3Template<T> &trans, Matrix44Template<T> &result)
{
    result = Matrix44FromTranslation(trans);
}


template<class T>
void Matrix44FromScaleQuaternion(const Vector3Template<T> &scale, const QuaternionTemplate<T> &q, Matrix44Template<T> &result)
{
    result = Matrix44FromScaleQuaternion(scale, q);
}


template<class T>
void Matrix44FromScaleTranslation(const Vector3Template<T> &scale, const Vector3Template<T> &trans, Matrix44Template<T> &result)
{
    result = Matrix44FromScaleTranslation(scale, trans);
}


template<class T>
void Matrix44Diagonal(T a, Matrix44Template<T> &result)
{
    result = Matrix44FromDiagonal<T>(a);
}


template<class T>
void Matrix44RotationX(T angle, Matrix44Template<T> &result)
{
    result = Matrix44FromXRotationAngle<T>(angle);
}


template<class T>
void Matrix44RotationY(T angle, Matrix44Template<T> &result)
{
    result = Matrix44FromYRotationAngle<T>(angle);
}


template<class T>
void Matrix44RotationZ(T angle, Matrix44Template<T> &result)
{
    result = Matrix44FromZRotationAngle<T>(angle);
}


template<class T>
void Matrix44RotateX(T angle,Matrix44Template<T> &m)
{
    m = RotateAroundXAxis<T>(m, angle);

}


template<class T>
void Matrix44RotateY(T angle,Matrix44Template<T> &m)
{
     m = RotateAroundYAxis<T>(m, angle);
}


template<class T>
void Matrix44RotateZ(T angle,Matrix44Template<T> &m)
{
     m = RotateAroundZAxis<T>(m, angle);
}


template<class T>
void Matrix44TransposeRotation(Matrix44Template<T> &m)
{
    m = Matrix44TransposeRotationalComponent(m);
}


template<class T>
void Matrix44Translate(const Vector3Template<T> &trans, Matrix44Template<T> &m)
{
    m = Matrix44Translate(m, trans);
}


template<class T>
void Matrix44ScaleRow(T r0, T r1, T r2, Matrix44Template<T> &m)
{
    m = ScaleRow(m, r0, r1, r2);
}


template<class T>
void Matrix44ScaleColumn(T c0, T c1, T c2, Matrix44Template<T> &m)
{
    m = ScaleColumn(m, c0, c1, c2);
}


template<class T>
void Matrix44Perspective(T w, T h, T zn,T zf, Matrix44Template<T> &result)
{
    result = Matrix44FromPerspective<T>( w, h, zn, zf );
}


template<class T>
void Matrix44Ortho(T w, T h, T zn,T zf, Matrix44Template<T> &result)
{
    result = Matrix44FromOrtho<T>(w, h, zn, zf);
}


template<class T>
void Matrix44OrthoOffCenter(T l, T r, T b, T t, T zn, T zf, Matrix44Template<T> &result)
{
    result = Matrix44FromOrthoOffCenter<T>(l, r, b, t, zn, zf);
}


template<class T>
void Matrix44FromQuaternionTranslation(const QuaternionTemplate<T> &q, const Vector3Template<T> &trans, Matrix44Template<T> &result)
{
    result = Matrix44FromQuaternionTranslation(q, trans);
}


template<class T>
void Matrix44FromScaleQuaternionTranslation(const Vector3Template<T> &scale, const QuaternionTemplate<T> &q, const Vector3Template<T> &trans, Matrix44Template<T> &result)
{
    result = Matrix44FromScaleQuaternionTranslation(scale, q, trans);
}


template<class T>
void Matrix44PerspectiveFov(T fov, T aspect, T zn, T zf, Matrix44Template<T> &result)
{
    result = Matrix44FromPerspectiveFov<T>(fov, aspect, zn, zf);
}


template<class T>
void Matrix44LookAt(const Vector3Template<T> &eye,const Vector3Template<T> &focal,const Vector3Template<T> &up, Matrix44Template<T> &result)
{
    result = Matrix44FromLookAt(focal, up, eye);
}


template<class T>
void Matrix44PerspectiveOffCenter(T l, T r, T b, T t, T zn, T zf, Matrix44Template<T> &result)
{
    result = Matrix44FromPerspectiveOffCenter<T>(l, r, b, t, zn, zf);
}


template<class T>
void Mult3x3(const Vector4Template<T> &v, const Matrix44Template<T> &m, Vector4Template<T> &result)
{
    result = Mult3x3(v, m);
}


template<class T>
void Mult3x3(const Vector3Template<T> &v, const Matrix44Template<T> &m, Vector3Template<T> &result)
{
    result = Mult3x3(v, m);
}


template<class T>
T Matrix44Inverse3x3(const Matrix44Template<T> &m, Matrix44Template<T> &result)
{
    T determinant;
    result = Inverse3x3(m, determinant);
    return determinant;
}



}}}
