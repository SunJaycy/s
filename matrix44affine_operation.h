


















namespace rw
{
namespace math
{
namespace fpu
{

template<class T>
Matrix44AffineTemplate<T>& operator *=(Matrix44AffineTemplate<T>& m, const T& a)
{
    m = Mult(m, a);
    return m;
}

template<class T>
Matrix44AffineTemplate<T>& operator /=(Matrix44AffineTemplate<T>& m, const T& a)
{
    m = Divide(m, a);
    return m;
}

template<class T>
Matrix44AffineTemplate<T> operator * (const Matrix44AffineTemplate<T>& m, const T& a)
{
    return Mult(m, a);
}

template<class T>
Matrix44AffineTemplate<T> operator * (const T& a, const Matrix44AffineTemplate<T>& b)
{
    return Mult(b, a);
}

template<class T>
Matrix44AffineTemplate<T> operator / (const Matrix44AffineTemplate<T>& m, const T& a)
{
    return Divide(m, a);
}

template<class T>
Vector4Template<T> operator * (const Vector4Template<T>& v, const Matrix44AffineTemplate<T>& m)
{
    return Mult(v, m);
}

template<class T>
Matrix44AffineTemplate<T>& operator *=(Matrix44AffineTemplate<T>& m, const Matrix44AffineTemplate<T>& b)
{
    m = Mult(m, b);
    return m;
}

template<class T>
Matrix44AffineTemplate<T>& operator +=(Matrix44AffineTemplate<T>& m, const Matrix44AffineTemplate<T>& b)
{
    m = Add(m, b);
    return m;
}

template<class T>
Matrix44AffineTemplate<T>& operator -=(Matrix44AffineTemplate<T>& m, const Matrix44AffineTemplate<T>& b)
{
    m = Subtract(m, b);
    return m;
}

template<class T>
Matrix44AffineTemplate<T> operator - (const Matrix44AffineTemplate<T>& m)
{
    return Negate(m);
}

template<class T>
Matrix44AffineTemplate<T> operator + (const Matrix44AffineTemplate<T>& a, const Matrix44AffineTemplate<T>& b)
{
    return Add(a, b);
}

template<class T>
Matrix44AffineTemplate<T> operator - (const Matrix44AffineTemplate<T>& a, const Matrix44AffineTemplate<T>& b)
{
    return Subtract(a, b);
}


template<class T>
Matrix44AffineTemplate<T> operator * (const Matrix44AffineTemplate<T>& a, const Matrix44AffineTemplate<T>& b)
{
    return Mult(a, b);
}

template<class T>
bool operator ==(const Matrix44AffineTemplate<T>& a, const Matrix44AffineTemplate<T>& b)
{
    return a.xAxis == b.xAxis &&
            a.yAxis == b.yAxis &&
            a.zAxis == b.zAxis &&
            a.wAxis == b.wAxis;
}

template<class T>
bool operator !=(const Matrix44AffineTemplate<T>& a, const Matrix44AffineTemplate<T>& b)
{
    return !(a==b);
}

template<class T>
bool IsSimilar(const Matrix44AffineTemplate<T>& a, const Matrix44AffineTemplate<T>& b, T epsilon = SMALL_FLOAT)
{
    return IsSimilar( a.xAxis, b.xAxis, epsilon ) &&
            IsSimilar( a.yAxis, b.yAxis, epsilon ) &&
            IsSimilar( a.zAxis, b.zAxis, epsilon ) &&
            IsSimilar( a.wAxis, b.wAxis, epsilon );
}




template<class T> bool IsAnyNaN(const Matrix44AffineTemplate<T> &m)
{
    return IsAnyNaN(m.xAxis) || IsAnyNaN(m.yAxis) || IsAnyNaN(m.zAxis) || IsAnyNaN(m.wAxis);
}

template<class T>
T GetOrthogonalError3x3(const Matrix44AffineTemplate<T>& matrix)
{
    Matrix33Template<T> m33(
        matrix.GetElem(0), matrix.GetElem(1), matrix.GetElem(2),
        matrix.GetElem(3), matrix.GetElem(4), matrix.GetElem(5),
        matrix.GetElem(6), matrix.GetElem(7), matrix.GetElem(8));
    return GetOrthogonalError( m33 );
}

template<class T>
T GetOrthogonalRowSetError3x3(const Matrix44AffineTemplate<T>& matrix)
{
    Matrix33Template<T> m33(
        matrix.GetElem(0), matrix.GetElem(1), matrix.GetElem(2),
        matrix.GetElem(3), matrix.GetElem(4), matrix.GetElem(5),
        matrix.GetElem(6), matrix.GetElem(7), matrix.GetElem(8));
    return GetOrthogonalRowSetError( m33 );
}

template<class T>
T GetNormalError(const Matrix44AffineTemplate<T>& matrix)
{
    Vector4Template<T> errorVec( MagnitudeSquared( matrix.XAxis() ) - T(1.0f),
                                                MagnitudeSquared( matrix.YAxis() ) - T(1.0f),
                                                MagnitudeSquared( matrix.ZAxis() ) - T(1.0f),
                                                MagnitudeSquared( matrix.WAxis() ) );
    T error = MagnitudeSquared(errorVec);
    return error;
}

template<class T>
bool IsValid(const Matrix44AffineTemplate<T>& a)
{
    return IsValid(a.XAxis()) &&
            IsValid(a.YAxis()) &&
            IsValid(a.ZAxis()) &&
            IsValid(a.WAxis());
}

template<class T>
bool IsNormal(const Matrix44AffineTemplate<T>& a, T tolerance = EPSILON)
{
    return IsZero( GetNormalError(a), tolerance );
}

template<class T>
bool IsOrthogonal(const Matrix44AffineTemplate<T>& a, T tolerance = EPSILON)
{
    return IsZero( GetOrthogonalError(a), tolerance );
}

template<class T>
bool IsOrthogonalRowSet(const Matrix44AffineTemplate<T>& a, T tolerance = EPSILON)
{
    return IsZero( GetOrthogonalRowSetError(a), tolerance );
}

template<class T>
void SelfAdd(Matrix44AffineTemplate<T>& a, const Matrix44AffineTemplate<T>& b)
{
    a = Add(a, b);
}

template<class T>
void SelfSubtract(Matrix44AffineTemplate<T>& a, const Matrix44AffineTemplate<T>& b)
{
    a = Subtract(a, b);
}

template<class T>
void SelfMult(Matrix44AffineTemplate<T>& m, T a)
{
    m = Mult(m, a);
}

template<class T>
void SelfDivide(Matrix44AffineTemplate<T>& m, T a)
{
    m = Divide(m, a);
}

template<class T>
T Determinant(const Matrix44AffineTemplate<T>& m)
{
    return
        m.xAxis.x * (
        m.yAxis.y * m.zAxis.z -
        m.yAxis.z * m.zAxis.y
        ) +
        m.xAxis.y * (
        m.yAxis.z * m.zAxis.x -
        m.yAxis.x * m.zAxis.z
        ) +
        m.xAxis.z * (
        m.yAxis.x * m.zAxis.y -
        m.yAxis.y * m.zAxis.x
        );
}

template<class T>
Matrix44AffineTemplate<T> Negate(const Matrix44AffineTemplate<T>& m)
{
    return Mult(m, T(-1.0f));
}

template<class T>
Matrix44AffineTemplate<T> Mult(const Matrix44AffineTemplate<T>& m, T a)
{
    return Matrix44AffineTemplate<T>(
        a * m.xAxis,
        a * m.yAxis,
        a * m.zAxis,
        a * m.wAxis
        );
}

template<class T>
Matrix44AffineTemplate<T> Divide(const Matrix44AffineTemplate<T>& m, T a)
{
    return Matrix44AffineTemplate<T>(
        m.xAxis / a,
        m.yAxis / a,
        m.zAxis / a,
        m.wAxis / a
        );
}

template<class T>
Vector4Template<T> Mult(const Vector4Template<T>& v, const Matrix44AffineTemplate<T>& m)
{
    return Vector4Template<T>(
        m.xAxis.x * v.x + m.yAxis.x * v.y + m.zAxis.x * v.z + m.wAxis.x * v.w,
        m.xAxis.y * v.x + m.yAxis.y * v.y + m.zAxis.y * v.z + m.wAxis.y * v.w,
        m.xAxis.z * v.x + m.yAxis.z * v.y + m.zAxis.z * v.z + m.wAxis.z * v.w,
        v.w
        );
}

template<class T>
Matrix44AffineTemplate<T> Mult(const Matrix44AffineTemplate<T>& m, const Matrix44AffineTemplate<T>& b)
{
    return Matrix44AffineTemplate<T>(
        TransformVector(m.xAxis, b),
        TransformVector(m.yAxis, b),
        TransformVector(m.zAxis, b),
        TransformPoint(m.wAxis, b)
        );
}

template<class T>
Matrix44AffineTemplate<T> Add(const Matrix44AffineTemplate<T>& a, const Matrix44AffineTemplate<T>& b)
{
    return Matrix44AffineTemplate<T>(
        Add(a.xAxis, b.xAxis),
        Add(a.yAxis, b.yAxis),
        Add(a.zAxis, b.zAxis),
        Add(a.wAxis, b.wAxis)
        );
}

template<class T>
Matrix44AffineTemplate<T> Subtract(const Matrix44AffineTemplate<T>& a, const Matrix44AffineTemplate<T>& b)
{
    return Matrix44AffineTemplate<T>(
        Subtract(a.xAxis, b.xAxis),
        Subtract(a.yAxis, b.yAxis),
        Subtract(a.zAxis, b.zAxis),
        Subtract(a.wAxis, b.wAxis)
        );
}

template<class T>
Matrix44AffineTemplate<T> Transpose(const Matrix44AffineTemplate<T>& m)
{
    Matrix44AffineTemplate<T> result;

    for(int row=0; row<3; ++row)
    {
        for(int column=0; column<3; ++column)
        {
            result.SetElem(row, column, m.GetRow(column).GetComponent( row) );
        }
    }



    result.WAxis() = Vector3Template<T>(0.0f, 0.0f, 0.0f) ;
    return result;
}

template<class T>
Matrix44AffineTemplate<T> OrthoNormalize(const Matrix44AffineTemplate<T>& m)
{




    Matrix44AffineTemplate<T> result;



    result.WAxis() =Vector3Template<T>(0.0f, 0.0f, 0.0f);


    for( int row = 2; row >= 0; --row )
    {

        const Vector3Template<T> &inputRow = m.GetRow(row);
        Vector3Template<T> tempResult = inputRow;


















        for( int i = 2; i > row; --i )
        {
            tempResult -= result.GetRow(i) * Dot(result.GetRow(i), inputRow );
        }
        result.SetRow( row, Normalize(tempResult) );
    }
    return result;
}

template<class T>
Matrix44AffineTemplate<T> InverseOrthonormal(const Matrix44AffineTemplate<T>& m)
{
    ;
    return Transpose(m);
}

template<class T>
Matrix44AffineTemplate<T> Inverse(const Matrix44AffineTemplate<T>& m)
{
    T determinant;
    return Inverse(m, determinant);
}

template<class T>
Matrix44AffineTemplate<T> Inverse(const Matrix44AffineTemplate<T>& m, T& determinant)
{
    determinant = Determinant(m);
    ;
    if(determinant==T(0.0f))
    {
        return Matrix44AffineTemplate<T>();
    }
    else
    {

        T determinantRecip = Reciprocal( determinant );
        return Matrix44AffineTemplate<T>(
                ((m.yAxis.y*(m.zAxis.z)+m.yAxis.z*(-m.zAxis.y))*determinantRecip),
                ((m.zAxis.y*(m.xAxis.z)+m.zAxis.z*(-m.xAxis.y))*determinantRecip),
                ((m.xAxis.y*m.yAxis.z-m.xAxis.z*m.yAxis.y)*determinantRecip),

                ((m.yAxis.z*(m.zAxis.x)+m.yAxis.x*(-m.zAxis.z))*determinantRecip),
                ((m.zAxis.z*(m.xAxis.x)+m.zAxis.x*(-m.xAxis.z))*determinantRecip),
                ((m.yAxis.x*m.xAxis.z-m.xAxis.x*m.yAxis.z)*determinantRecip),

                ((m.yAxis.x*(m.zAxis.y)+m.yAxis.y*(-m.zAxis.x))*determinantRecip),
                ((m.zAxis.x*(m.xAxis.y)+m.zAxis.y*(-m.xAxis.x))*determinantRecip),
                ((m.xAxis.x*m.yAxis.y-m.yAxis.x*m.xAxis.y)*determinantRecip),

                ((m.yAxis.x*(m.wAxis.y*m.zAxis.z-m.zAxis.y*m.wAxis.z)+m.yAxis.y*(m.zAxis.x*m.wAxis.z-m.wAxis.x*m.zAxis.z)+m.yAxis.z*(m.wAxis.x*m.zAxis.y-m.zAxis.x*m.wAxis.y))*determinantRecip),
                ((m.zAxis.x*(m.xAxis.z*m.wAxis.y-m.xAxis.y*m.wAxis.z)+m.zAxis.y*(m.xAxis.x*m.wAxis.z-m.wAxis.x*m.xAxis.z)+m.zAxis.z*(m.wAxis.x*m.xAxis.y-m.xAxis.x*m.wAxis.y))*determinantRecip),
                ((m.wAxis.x*(m.xAxis.z*m.yAxis.y-m.xAxis.y*m.yAxis.z)+m.wAxis.y*(m.xAxis.x*m.yAxis.z-m.yAxis.x*m.xAxis.z)+m.wAxis.z*(m.yAxis.x*m.xAxis.y-m.xAxis.x*m.yAxis.y))*determinantRecip)
            );
    }
}

template<class T>
Vector3Template<T> TransformPoint(const Vector3Template<T>& pt, const Matrix44AffineTemplate<T>& matrix)
{
    return Vector3Template<T>(matrix.xAxis.x * pt.x + matrix.yAxis.x * pt.y + matrix.zAxis.x * pt.z + matrix.wAxis.x,
                              matrix.xAxis.y * pt.x + matrix.yAxis.y * pt.y + matrix.zAxis.y * pt.z + matrix.wAxis.y,
                              matrix.xAxis.z * pt.x + matrix.yAxis.z * pt.y + matrix.zAxis.z * pt.z + matrix.wAxis.z);
}

template<class T>
void TransformPoints(const Vector3Template<T>* const pts, int numPoints, const Matrix44AffineTemplate<T>& matrix, Vector3Template<T>* transformedPts)
{
    for( int point = 0; point < numPoints; point++ )
    {
        transformedPts[point] = TransformPoint(pts[point], matrix);
    }
}

template<class T>
Vector3Template<T> TransformVector(const Vector3Template<T>& vec, const Matrix44AffineTemplate<T>& matrix)
{
    Vector3Template<T>transformedPoint = matrix.XAxis() * vec.x;
    transformedPoint += matrix.YAxis() * vec.y;
    transformedPoint += matrix.ZAxis() * vec.z;
    return transformedPoint;
}

template<class T>
void TransformVectors(const Vector3Template<T>* const vecs, int numVectors, const Matrix44AffineTemplate<T>& matrix, Vector3Template<T> * transformedVecs)
{
    for( int vecIndex = 0; vecIndex < numVectors; vecIndex++ )
    {
        transformedVecs[vecIndex] = TransformVector(vecs[vecIndex], matrix);
    }
}

template<class T>
Vector3Template<T> Transform(const Vector4Template<T>& vec, const Matrix44AffineTemplate<T>& matrix)
{
    Vector3Template<T> transformedVector = matrix.XAxis() * vec.x;
    transformedVector += matrix.YAxis() * vec.y;
    transformedVector += matrix.ZAxis() * vec.z;
    transformedVector += matrix.WAxis() * vec.w;;
    return transformedVector;
}

template<class T>
void Transform(const Vector4Template<T>* const vecs, int numVectors, const Matrix44AffineTemplate<T>& matrix, Vector3Template<T> * transformedVecs)
{
    for( int vecIndex = 0; vecIndex < numVectors; vecIndex++ )
    {
        transformedVecs[vecIndex] = Transform(vecs[vecIndex], matrix);
    }
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromQuaternion(const QuaternionTemplate<T>&q)
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

    const T zero(0.0f);
    const T one(1.0f);
    const T two(2.0f);
    return Matrix44AffineTemplate<T>(
        one-two*(yy+zz), two*(xy+wz), two*(xz-wy),
        two*(xy-wz), one-two*(xx+zz), two*(yz+wx),
        two*(xz+wy), two*(yz-wx), one-two*(xx+yy),
        zero, zero, zero
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromEulerXYZ(const Vector3Template<T>& euler)
{
    T ci, cj, ch, si, sj, sh;

    SinCos(euler.x, si, ci);
    SinCos(euler.y, sj, cj);
    SinCos(euler.z, sh, ch);

    T cc = ci * ch;
    T cs = ci * sh;
    T sc = si * ch;
    T ss = si * sh;

    const T zero(0.0f);
    return Matrix44AffineTemplate<T>(
        cj * ch , cj * sh , -sj ,
        sj * sc - cs, sj * ss + cc, cj * si ,
        sj * cc + ss, sj * cs - sc, cj * ci ,
        zero, zero, zero
        );
}

template<class T>
Vector3Template<T> EulerXYZFromMatrix44Affine(const Matrix44AffineTemplate<T>& matrix)
{
    Matrix33Template<T> m33(
        matrix.GetElem(0), matrix.GetElem(1), matrix.GetElem(2),
        matrix.GetElem(3), matrix.GetElem(4), matrix.GetElem(5),
        matrix.GetElem(6), matrix.GetElem(7), matrix.GetElem(8));
    return EulerXYZFromMatrix33( m33 );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromAxisRotationAngle(const Vector3Template<T>& axis, T angle)
{
    T s, c;

    SinCos(angle, s, c);
    T t = T(1.0f) - c;
    T tx = t * axis.x;
    T ty = t * axis.y;
    T tz = t * axis.z;
    T sx = s * axis.x;
    T sy = s * axis.y;
    T sz = s * axis.z;

    const T zero(0.0f);
    return Matrix44AffineTemplate<T>(
        tx * axis.x + c ,
        tx * axis.y + sz,
        tx * axis.z - sy,

        ty * axis.x - sz,
        ty * axis.y + c ,
        ty * axis.z + sx,

        tz * axis.x + sy,
        tz * axis.y - sx,
        tz * axis.z + c,

        zero,
        zero,
        zero
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromXRotationAngle(T angle)
{
    T s,c;
    SinCos(angle,s,c);
    const T zero(0.0f);
    const T one(1.0f);
    return Matrix44AffineTemplate<T>(
        one, zero, zero,
        zero, c, s,
        zero, -s, c,
        zero, zero, zero
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromYRotationAngle(T angle)
{
    T s,c;
    SinCos(angle,s,c);
    const T zero(0.0f);
    const T one(1.0f);
    return Matrix44AffineTemplate<T>(
        c, zero, -s,
        zero, one, zero,
        s, zero, c,
        zero, zero, zero );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromZRotationAngle(T angle)
{
    T s,c;
    SinCos(angle,s,c);
    const T zero(0.0f);
    const T one(1.0f);
    return Matrix44AffineTemplate<T>(
        c, s, zero,
        -s, c, zero,
        zero, zero, one,
        zero, zero, zero);
}

template<class T>
Matrix44AffineTemplate<T> RotateAroundXAxis(const Matrix44AffineTemplate<T>& m, T angle)
{








    T s,c;
    SinCos(angle, s, c);


    return Matrix44AffineTemplate<T>(
        m.XAxis(),
        m.ZAxis() * s + m.YAxis() * c,
        m.ZAxis() * c - m.YAxis() * s,
        m.WAxis()
    );
}

template<class T>
Matrix44AffineTemplate<T> RotateAroundYAxis(const Matrix44AffineTemplate<T>& m, T angle)
{








    T s,c;

    SinCos(angle, s, c);


    return Matrix44AffineTemplate<T>(
        m.XAxis() * c - m.ZAxis() * s,
        m.YAxis(),
        m.XAxis() * s + m.ZAxis() * c,
        m.WAxis()
    );
}

template<class T>
Matrix44AffineTemplate<T> RotateAroundZAxis(const Matrix44AffineTemplate<T>& m, T angle)
{








    T s,c;

    SinCos(angle, s, c);


    return Matrix44AffineTemplate<T>(
        m.YAxis() * s + m.XAxis() * c,
        m.YAxis() * c - m.XAxis() * s,
        m.ZAxis(),
        m.WAxis()
    );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineTransposeRotationalComponent(const Matrix44AffineTemplate<T>& m)
{
    Matrix44AffineTemplate<T> result = m;


    result.SetElem(1, m.GetElem(3));
    result.SetElem(3, m.GetElem(1));

    result.SetElem(2, m.GetElem(6));
    result.SetElem(6, m.GetElem(2));

    result.SetElem(5, m.GetElem(7));
    result.SetElem(7, m.GetElem(5));
    return result;
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineTranslate(const Matrix44AffineTemplate<T>& m, const Vector3Template<T>& trans)
{

    Vector3Template<T> translationVector(
        (trans.x * m.GetElem(0)) + (trans.y * m.GetElem(3)) + (trans.z * m.GetElem(6)),
        (trans.x * m.GetElem(1)) + (trans.y * m.GetElem(4)) + (trans.z * m.GetElem(7)),
        (trans.x * m.GetElem(2)) + (trans.y * m.GetElem(5)) + (trans.z * m.GetElem(8))
        );


    return Matrix44AffineTemplate<T>(
        m.xAxis,
        m.yAxis,
        m.zAxis,
        m.wAxis + translationVector
        );
}

template<class T>
Matrix44AffineTemplate<T> ScaleRow(const Matrix44AffineTemplate<T>& m, T r0, T r1, T r2)
{
    Vector3Template<T> row0Scale( r0, r0, r0 );
    Vector3Template<T> row1Scale( r1, r1, r1 );
    Vector3Template<T> row2Scale( r2, r2, r2 );
    return Matrix44AffineTemplate<T>(
        Mult( row0Scale, m.xAxis ),
        Mult( row1Scale, m.yAxis ),
        Mult( row2Scale, m.zAxis ),
        m.wAxis
        );
}

template<class T>
Matrix44AffineTemplate<T> ScaleColumn(const Matrix44AffineTemplate<T>& m, T c0, T c1, T c2)
{
    Vector3Template<T> rowMultiplier(c0, c1, c2);
    return Matrix44AffineTemplate<T>(
        Mult( m.xAxis, rowMultiplier ),
        Mult( m.yAxis, rowMultiplier ),
        Mult( m.zAxis, rowMultiplier ),
        m.wAxis
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromDiagonal(T a)
{
    return Matrix44AffineTemplate<T>(
        a,0,0,
        0,a,0,
        0,0,a,
        0,0,0
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromScale(const Vector3Template<T>& scale)
{
    const T zero(0.0f);
    return Matrix44AffineTemplate<T>(
        scale.x, zero, zero,
        zero, scale.y, zero,
        zero, zero, scale.z,
        zero, zero, zero
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromTranslation(const Vector3Template<T>& trans)
{
    const T zero(0.0f);
    const T one(1.0f);
    return Matrix44AffineTemplate<T>(
        one, zero, zero,
        zero, one, zero,
        zero, zero, one,
        trans.x, trans.y, trans.z
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromScaleQuaternion(const Vector3Template<T>& scale, const QuaternionTemplate<T>&q)
{
    const T zero(0.0f);
    const T one(1.0f);
    const T two(2.0f);
    T xx = q.x * q.x;
    T yy = q.y * q.y;
    T zz = q.z * q.z;
    T xy = q.x * q.y;
    T xz = q.x * q.z;
    T yz = q.y * q.z;
    T wx = q.w * q.x;
    T wy = q.w * q.y;
    T wz = q.w * q.z;
    return Matrix44AffineTemplate<T>(
        scale.x * (one-two*(yy+zz)), scale.x *two*(xy+wz), scale.x *two*(xz-wy),
        scale.y *two*(xy-wz), scale.y * (one-two*(xx+zz)), scale.y *two*(yz+wx),
        scale.z *two*(xz+wy), scale.z *two*(yz-wx), scale.z * (one-two*(xx+yy)),
        zero, zero, zero
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromScaleTranslation(const Vector3Template<T>& scale, const Vector3Template<T>& trans)
{
    const T zero(0.0f);
    return Matrix44AffineTemplate<T>(
        scale.x, zero, zero,
        zero, scale.y, zero,
        zero, zero, scale.z,
        trans.x, trans.y, trans.z
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromOrtho(T w, T h, T zn, T zf)
{
    const T zero(0.0f);
    const T one(1.0f);
    const T two(2.0f);
    return Matrix44AffineTemplate<T>(
        two/w, zero, zero,
        zero, two/h, zero,
        zero, zero, one/(zn-zf),
        zero, zero, zn/(zn-zf)
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromOrthoOffCenter(T l, T r, T b, T t, T zn, T zf)
{
    const T zero(0.0f);
    const T one(1.0f);
    const T two(2.0f);
    return Matrix44AffineTemplate<T>(
        two/(r-l), zero, zero,
        zero, two/(t-b), zero,
        zero, zero, one/(zn-zf),
        (l+r)/(l-r), (t+b)/(b-t), zn/(zn-zf)
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromQuaternionTranslation(const QuaternionTemplate<T>&q, const Vector3Template<T>& trans)
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
    return Matrix44AffineTemplate<T>(
        one-two*(yy+zz), two*(xy+wz), two*(xz-wy),
        two*(xy-wz), one-two*(xx+zz), two*(yz+wx),
        two*(xz+wy), two*(yz-wx), one-two*(xx+yy),
        trans.x, trans.y, trans.z
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromScaleQuaternionTranslation(const Vector3Template<T>& scale, const QuaternionTemplate<T>&q, const Vector3Template<T>& trans)
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
    return Matrix44AffineTemplate<T>(
        scale.x*(one-two*(yy+zz)), scale.x*two*(xy+wz), scale.x*two*(xz-wy),
        scale.y*two*(xy-wz), scale.y*(one-two*(xx+zz)), scale.y*two*(yz+wx),
        scale.z*two*(xz+wy), scale.z*two*(yz-wx), scale.z*(one-two*(xx+yy)),
        trans.x, trans.y, trans.z
        );
}

template<class T>
Matrix44AffineTemplate<T> Matrix44AffineFromLookAt(const Vector3Template<T>& lookAt, const Vector3Template<T>& up, const Vector3Template<T>& eyePosition)
{

    Vector3Template<T> zaxis = Normalize(Subtract(eyePosition, lookAt));
    Vector3Template<T> xaxis = Normalize(Cross(up, zaxis));
    Vector3Template<T> yaxis = Cross(zaxis, xaxis);

    return Matrix44AffineTemplate<T> (
        xaxis.x, yaxis.x, zaxis.x,
        xaxis.y, yaxis.y, zaxis.y,
        xaxis.z, yaxis.z, zaxis.z,
        -Dot(xaxis, eyePosition), -Dot(yaxis, eyePosition), -Dot(zaxis, eyePosition)
        );
}

template<class T>
Vector3Template<T> QueryRotateDegenerateUnitAxis(const Matrix44AffineTemplate<T>& matrix)
{
    Matrix33Template<T> m33(
        matrix.GetElem(0), matrix.GetElem(1), matrix.GetElem(2),
        matrix.GetElem(3), matrix.GetElem(4), matrix.GetElem(5),
        matrix.GetElem(6), matrix.GetElem(7), matrix.GetElem(8));
    return QueryRotateDegenerateUnitAxis( m33 );
}

template<class T>
void QueryRotate(const Matrix44AffineTemplate<T>& matrix, Vector3Template<T>& unitAxis, T& angle, Vector3Template<T>& center)
{
    Vector3Template<T> twoSinThetaAxis;
    T twoCosTheta = matrix.XAxis().x + matrix.YAxis().y + matrix.ZAxis().z - T(1.0f);
    twoSinThetaAxis.x =matrix.YAxis().z - matrix.ZAxis().y;
    twoSinThetaAxis.y =matrix.ZAxis().x - matrix.XAxis().z;
    twoSinThetaAxis.z =matrix.XAxis().y - matrix.YAxis().x;
    T twoSinTheta = Magnitude(twoSinThetaAxis);
    if(twoSinTheta > T(0.0f))
    {
        const T lrRecipLength = T(1.0f) / twoSinTheta;
        unitAxis = twoSinThetaAxis * lrRecipLength;
    }
    else
    {
        unitAxis = Vector3Template<T>(0.0f, 0.0f, 0.0f);
    }
    angle = ATan2(twoSinTheta, twoCosTheta);
    if((twoSinTheta <= T(MINIMUM_RECIPROCAL)) && (twoCosTheta <= T(0.0f)))
    {
        unitAxis = QueryRotateDegenerateUnitAxis(matrix);
    }
    Vector3Template<T> axisXpos = Cross(unitAxis, matrix.WAxis());
    center = Cross(axisXpos, unitAxis) * T(0.5f);
    center += axisXpos * (T(0.5f) * twoSinTheta / (T(2.0f) - twoCosTheta));
}

template<class T>
Matrix44AffineTemplate<T> SLerp(const Matrix44AffineTemplate<T>& lFrom, const Matrix44AffineTemplate<T>& lTo, T lrParam, T& lprAngle)
{
    Matrix44AffineTemplate<T> lReturnmatrix;
    Matrix44AffineTemplate<T> lScratch;
    Vector3Template<T> axis;
    Vector3Template<T> lCentre;
    T lrAngle;


    if(lrParam <= T(0.0f))
    {
        lprAngle = AngleBetweenVectors( lFrom.ZAxis(), lTo.ZAxis() );
        return lFrom;
    }
    else if(lrParam >= T(1.0f))
    {
        lprAngle = T(0.0f);
        return lTo;
    }


    lScratch = Mult( InverseOrthonormal(lFrom), lTo );

    QueryRotate(lScratch, axis, lrAngle, lCentre );


    if( lrAngle < T(MATRIX_MIN_SLERP_ANGLE) )
    {

        Matrix44AffineTemplate<T> lLerpmat;

        lLerpmat.XAxis() = lTo.XAxis() - lFrom.XAxis();
        lLerpmat.YAxis() = lTo.YAxis() - lFrom.YAxis();
        lLerpmat.ZAxis() = lTo.ZAxis() - lFrom.ZAxis();
        lLerpmat.WAxis() = lTo.WAxis() - lFrom.WAxis();


        lLerpmat = Mult( lLerpmat, lrParam);

        lReturnmatrix.XAxis() = Normalize(lFrom.XAxis() + lLerpmat.XAxis());
        lReturnmatrix.YAxis() = Normalize(lFrom.YAxis() + lLerpmat.YAxis());
        lReturnmatrix.ZAxis() = Normalize(lFrom.ZAxis() + lLerpmat.ZAxis());
        lReturnmatrix.WAxis() = lFrom.WAxis() + lLerpmat.WAxis();
    }
    else

    {
        Matrix44AffineTemplate<T> lRotatematrix;

        Vector3Template<T> lStartPos = lFrom.WAxis();
        Vector3Template<T> lEndPos = lTo.WAxis();


        lReturnmatrix = lFrom;
        lReturnmatrix.WAxis() =GetVector3_ZeroTemplate<T>();


        lRotatematrix = Matrix44AffineFromAxisRotationAngle( axis, ( lrAngle * lrParam ) );
        lReturnmatrix = Mult( lReturnmatrix, lRotatematrix );


        lReturnmatrix.WAxis() = (lEndPos - lStartPos) * lrParam + lStartPos;
    }

    lprAngle = lrAngle - (lrAngle * lrParam);
    return lReturnmatrix;
}

template<class T>
Matrix44AffineTemplate<T> SLerpByAngle(const Matrix44AffineTemplate<T>& lFrom, const Matrix44AffineTemplate<T>& lTo, T lrMaxAngle, T& lprAngle)
{
    Matrix44AffineTemplate<T> lReturnmatrix;
    Matrix44AffineTemplate<T> lRotatematrix;
    Vector3Template<T> axis;
    Vector3Template<T> lCentre;
    T lrAngle;
    T lrDeltaAngle;


    Matrix44AffineTemplate<T> lScratch = InverseOrthonormal(lFrom);
    lScratch = Mult( lScratch, lTo );

    QueryRotate(lScratch, axis, lrAngle, lCentre );
    if( IsZero(axis) )
    {
        lprAngle = 0.0f;
        return lTo;
    }


    Vector3Template<T> lPosBackup = lFrom.WAxis();
    lReturnmatrix = lFrom;
    lReturnmatrix.WAxis() = GetVector3_ZeroTemplate<T>() ;


    lrDeltaAngle = Min(lrAngle, lrMaxAngle);

    lRotatematrix = Matrix44AffineFromAxisRotationAngle( axis, lrDeltaAngle );
    lReturnmatrix = Mult( lReturnmatrix, lRotatematrix );


    lReturnmatrix.WAxis() = lPosBackup ;

    lprAngle = lrAngle - lrDeltaAngle;

    return lReturnmatrix;
}


template<class T>
bool IsValid3x3(const Matrix44AffineTemplate<T>& a)
{
    Matrix33Template<T> m33(
        a.GetElem(0), a.GetElem(1), a.GetElem(2),
        a.GetElem(3), a.GetElem(4), a.GetElem(5),
        a.GetElem(6), a.GetElem(7), a.GetElem(8));
    return IsValid( m33 );
}

template<class T>
bool IsNormal3x3(const Matrix44AffineTemplate<T>& a, T tolerance = EPSILON)
{
    return IsZero( GetNormalError3x3(a), tolerance );
}

template<class T>
bool IsOrthogonal3x3(const Matrix44AffineTemplate<T>& a, T tolerance = EPSILON)
{
    return IsZero( GetOrthogonalError3x3(a), tolerance );
}

template<class T>
bool IsOrthogonalRowSet3x3(const Matrix44AffineTemplate<T>& a, T tolerance = EPSILON)
{
    return IsZero( GetOrthogonalRowSetError3x3(a), tolerance );
}

template<class T>
T Determinant3x3(const Matrix44AffineTemplate<T>& m)
{
    Matrix33Template<T> m33(
        m.GetElem(0), m.GetElem(1), m.GetElem(2),
        m.GetElem(3), m.GetElem(4), m.GetElem(5),
        m.GetElem(6), m.GetElem(7), m.GetElem(8));
    return Determinant( m33 );
}

template<class T>
Vector4Template<T> Mult3x3(const Vector4Template<T>& v, const Matrix44AffineTemplate<T>& m)
{
    Vector3Template<T> v3_arg(v.x, v.y, v.z);
    Vector3Template<T> v3 = Mult3x3(v3_arg, m);
    return Vector4Template<T>( v3.x, v3.y, v3.z, v.w );
}

template<class T>
Vector3Template<T> Mult3x3(const Vector3Template<T>& v, const Matrix44AffineTemplate<T>& m)
{
    Matrix33Template<T> m33(
        m.GetElem(0), m.GetElem(1), m.GetElem(2),
        m.GetElem(3), m.GetElem(4), m.GetElem(5),
        m.GetElem(6), m.GetElem(7), m.GetElem(8));
    return Mult(v,m33);
}

template<class T>
Matrix44AffineTemplate<T> Inverse3x3(const Matrix44AffineTemplate<T>& m, T& determinant)
{
    determinant = Determinant(m);
    if(determinant==T(0.0f))
    {
        return Matrix44AffineTemplate<T>();
    }
    else
    {
        Matrix44AffineTemplate<T> result;
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
            result.SetElem(3,i, T(0.0f));
        }
        return result;
    }
}

template<class T>
Matrix44AffineTemplate<T> OrthoNormalize3x3(const Matrix44AffineTemplate<T>& matrix)
{
    Vector3Template<T> *vpU, *vpV, *vpW;

    Vector3Template<T> right = Normalize(matrix.XAxis());
    Vector3Template<T> up = Normalize(matrix.YAxis());
    Vector3Template<T> at = Normalize(matrix.ZAxis());
    const Vector3Template<T> &pos = matrix.WAxis();

    Vector3Template<T> vInner( Magnitude(matrix.XAxis()),
        Magnitude(matrix.YAxis()),
        Magnitude(matrix.ZAxis()) );

    if (vInner.x > T(0.0f))
    {
        if (vInner.y > T(0.0f))
        {
            if (vInner.z > T(0.0f))
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
    Matrix44AffineTemplate<T> result(
        right,
        up,
        at,
        pos
        );
    return result;
}

template<class T>
Matrix44AffineTemplate<T> InverseGeneric3x3(const Matrix44AffineTemplate<T>& in)
{




    Matrix44AffineTemplate<T> out;
    out.XAxis().x =( (in.YAxis().y) * (in.ZAxis().z) - (in.YAxis().z) * (in.ZAxis().y) );
    out.XAxis().y =-( (in.XAxis().y) * (in.ZAxis().z) - (in.XAxis().z) * (in.ZAxis().y) );
    out.XAxis().z =( (in.XAxis().y) * (in.YAxis().z) - (in.XAxis().z) * (in.YAxis().y) );
    T determinant = ((out.XAxis().x) * (in.XAxis().x) +
        (out.XAxis().y) * (in.YAxis().x) +
        (out.XAxis().z) * (in.ZAxis().x) );
    T normalize;
    if (IsZero(determinant))
    {
        normalize = T(1.0f);
    }
    else
    {
        normalize = T(1.0f) / determinant;
    }

    out.XAxis() *= normalize;
    out.YAxis().x =-( (in.YAxis().x) * (in.ZAxis().z) - (in.YAxis().z) * (in.ZAxis().x) ) * normalize;
    out.YAxis().y = ( (in.XAxis().x) * (in.ZAxis().z) - (in.XAxis().z) * (in.ZAxis().x) ) * normalize;
    out.YAxis().z =-( (in.XAxis().x) * (in.YAxis().z) - (in.XAxis().z) * (in.YAxis().x) ) * normalize;
    out.ZAxis().x = ( (in.YAxis().x) * (in.ZAxis().y) - (in.YAxis().y) * (in.ZAxis().x) ) * normalize;
    out.ZAxis().y =-( (in.XAxis().x) * (in.ZAxis().y) - (in.XAxis().y) * (in.ZAxis().x) ) * normalize;
    out.ZAxis().z = ( (in.XAxis().x) * (in.YAxis().y) - (in.XAxis().y) * (in.YAxis().x) ) * normalize;
    out.WAxis().x =-((in.WAxis().x * out.XAxis().x) +
        (in.WAxis().y * out.XAxis().y) +
        (in.WAxis().z * out.XAxis().z));
    out.WAxis().y =-((in.WAxis().x * out.YAxis().x) +
        (in.WAxis().y * out.YAxis().y) +
        (in.WAxis().z * out.YAxis().z));
    out.WAxis().z =-((in.WAxis().x * out.ZAxis().x) +
        (in.WAxis().y * out.ZAxis().y) +
        (in.WAxis().z * out.ZAxis().z));
    return out;

}

template<class T>
Matrix44AffineTemplate<T> InverseOfMatrixWithOrthonormal3x3(const Matrix44AffineTemplate<T>& in)
{
    Matrix44AffineTemplate<T> out;
    out.XAxis().Set(in.XAxis().x, in.YAxis().x, in.ZAxis().x);
    out.YAxis().Set(in.XAxis().y, in.YAxis().y, in.ZAxis().y);
    out.ZAxis().Set(in.XAxis().z, in.YAxis().z, in.ZAxis().z);
    out.WAxis().x =-((in.WAxis().x * in.XAxis().x) +
        (in.WAxis().y * in.XAxis().y) +
        (in.WAxis().z * in.XAxis().z));
    out.WAxis().y =-((in.WAxis().x * in.YAxis().x) +
        (in.WAxis().y * in.YAxis().y) +
        (in.WAxis().z * in.YAxis().z));
    out.WAxis().z =-((in.WAxis().x * in.ZAxis().x) +
        (in.WAxis().y * in.ZAxis().y) +
        (in.WAxis().z * in.ZAxis().z));
    return out;
}

template<class T>
T GetNormalError3x3(const Matrix44AffineTemplate<T>& matrix)
{
    Matrix33Template<T> m33(
        matrix.GetElem(0), matrix.GetElem(1), matrix.GetElem(2),
        matrix.GetElem(3), matrix.GetElem(4), matrix.GetElem(5),
        matrix.GetElem(6), matrix.GetElem(7), matrix.GetElem(8));
    return GetNormalError( m33 );
}


template<class T>
T GetOrthogonalError(const Matrix44AffineTemplate<T>& matrix)
{
    Matrix44AffineTemplate<T> identity;
    identity.SetIdentity();

    Matrix44AffineTemplate<T> result = Mult(matrix, Transpose(matrix));
    SelfSubtract(result, identity);

    Vector4Template<T> errorVec( MagnitudeSquared( result.XAxis() ),
                                 MagnitudeSquared( result.YAxis() ),
                                 MagnitudeSquared( result.ZAxis() ),
                                 MagnitudeSquared( result.WAxis() ) );

    T error = MagnitudeSquared(errorVec);
    return error;
}

template<class T>
T GetOrthogonalRowSetError(const Matrix44AffineTemplate<T>& matrix)
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

template <class T>
inline Matrix44AffineTemplate<T> Select(const MaskScalarTemplate<T> &mask, const Matrix44AffineTemplate<T> &trueValue, const Matrix44AffineTemplate<T> &falseValue )
{
    return Matrix44AffineTemplate<T>(
            Select( mask, trueValue.xAxis, falseValue.xAxis ),
            Select( mask, trueValue.yAxis, falseValue.yAxis ),
            Select( mask, trueValue.zAxis, falseValue.zAxis ),
            Select( mask, trueValue.wAxis, falseValue.wAxis )
        );
}

}
}
}
