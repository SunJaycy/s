












namespace rw {
namespace math {
namespace fpu {








template<class T> Matrix33Template<T> Negate(const Matrix33Template<T> &m)
{
    return Mult( m, (T)-1.0f);
}









template<class T> Matrix33Template<T> Mult(const Matrix33Template<T> &m, T a)
{
    return Matrix33Template<T>(
        a * m.xAxis,
        a * m.yAxis,
        a * m.zAxis
        );
}









template<class T> Vector3Template<T> Mult(const Vector3Template<T> &v, const Matrix33Template<T> &m)
{
    return Vector3Template<T>(
        m.xAxis.x * v.x + m.yAxis.x * v.y + m.zAxis.x * v.z,
        m.xAxis.y * v.x + m.yAxis.y * v.y + m.zAxis.y * v.z,
        m.xAxis.z * v.x + m.yAxis.z * v.y + m.zAxis.z * v.z
        );
}









template<class T> Matrix33Template<T> Mult(const Matrix33Template<T> &m, const Matrix33Template<T> &b)
{
    Matrix33Template<T> result;
    for (int i = 0; i < 3; ++i)
    {
        result.SetElem(i, 0, m.GetRow(i).x * b.xAxis.x + m.GetRow(i).y * b.yAxis.x + m.GetRow(i).z * b.zAxis.x );
        result.SetElem(i, 1, m.GetRow(i).x * b.xAxis.y + m.GetRow(i).y * b.yAxis.y + m.GetRow(i).z * b.zAxis.y );
        result.SetElem(i, 2, m.GetRow(i).x * b.xAxis.z + m.GetRow(i).y * b.yAxis.z + m.GetRow(i).z * b.zAxis.z );
    }
    return result;
}









template<class T> Matrix33Template<T> Divide(const Matrix33Template<T> &m, T a)
{
    return Matrix33Template<T>(
        Divide(m.xAxis, a),
        Divide(m.yAxis, a),
        Divide(m.zAxis, a)
        );
}









template<class T> Matrix33Template<T> Add(const Matrix33Template<T> &a, const Matrix33Template<T> &b)
{
    return Matrix33Template<T>(
        Add(a.xAxis, b.xAxis),
        Add(a.yAxis, b.yAxis),
        Add(a.zAxis, b.zAxis)
        );
}









template<class T> Matrix33Template<T> Subtract(const Matrix33Template<T> &a, const Matrix33Template<T> &b)
{
    return Matrix33Template<T>(
        Subtract(a.xAxis, b.xAxis),
        Subtract(a.yAxis, b.yAxis),
        Subtract(a.zAxis, b.zAxis)
        );
}









template<class T> bool operator ==(const Matrix33Template<T> &a, const Matrix33Template<T> &b)
{
    return a.xAxis == b.xAxis &&
        a.yAxis == b.yAxis &&
        a.zAxis == b.zAxis;
}









template<class T> bool operator !=(const Matrix33Template<T> &a,const Matrix33Template<T> &b)
{
    return !(a==b);
}










template<class T> bool IsSimilar(const Matrix33Template<T> &a, const Matrix33Template<T> &b, T epsilon = SMALL_FLOAT)
{
    return IsSimilar( a.xAxis, b.xAxis, epsilon ) &&
        IsSimilar( a.yAxis, b.yAxis, epsilon ) &&
        IsSimilar( a.zAxis, b.zAxis, epsilon );
}




template<class T> bool IsAnyNaN(const Matrix33Template<T> &m)
{
    return (bool)(IsAnyNaN(m.xAxis) | IsAnyNaN(m.yAxis) | IsAnyNaN(m.zAxis));
}







template<class T> void SelfAdd(Matrix33Template<T> &a, const Matrix33Template<T> &b)
{
    a = Add(a,b);
}








template<class T> void SelfSubtract(Matrix33Template<T> &a, const Matrix33Template<T> &b)
{
    a = Subtract(a,b);
}








template<class T> void SelfMult(Matrix33Template<T> &m, T a)
{
    m = Mult(m, a);
}








template<class T> void SelfDivide(Matrix33Template<T> &m, T a)
{
    m = Divide(m, a);
}








template<class T> T Determinant(const Matrix33Template<T> &m)
{
    return m.xAxis.x*m.yAxis.y*m.zAxis.z + m.xAxis.y*m.yAxis.z*m.zAxis.x + m.xAxis.z*m.yAxis.x*m.zAxis.y
        - m.xAxis.x*m.yAxis.z*m.zAxis.y - m.xAxis.y*m.yAxis.x*m.zAxis.z - m.xAxis.z*m.yAxis.y*m.zAxis.x ;
}








template<class T> Matrix33Template<T> Transpose(const Matrix33Template<T> &m)
{
    Matrix33Template<T> result;
    for(int row=0; row<3; ++row)
    {
        for(int column=0; column<3; ++column)
        {
            result.SetElem(row, column, m.GetRow(column).GetComponent( row) );
        }
    }
    return result;
}








template<class T> Matrix33Template<T> Inverse(const Matrix33Template<T> &m)
{
    T determinant;
    return Inverse( m, determinant );
}









template<class T> Matrix33Template<T> Inverse(const Matrix33Template<T> &m, T& determinant)
{
    determinant = Determinant(m);
    ;
    if(determinant==0.0f)
    {
        return Matrix33Template<T>();
    }
    else
    {
        Matrix33Template<T> result;
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
        }
        return result;
    }
}








template<class T> Matrix33Template<T> Matrix33FromQuaternion(const QuaternionTemplate<T> &q)
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
    return Matrix33Template<T> (
        one-two*(yy+zz), two*(xy+wz), two*(xz-wy),
        two*(xy-wz), one-two*(xx+zz), two*(yz+wx),
        two*(xz+wy), two*(yz-wx), one-two*(xx+yy)
        );
}









template<class T> Matrix33Template<T> Matrix33FromAxisRotationAngle(const Vector3Template<T> &axis, T angle)
{
    T s, c;

    SinCos(angle, s, c);
    T t = 1.0f - c;
    T tx = t * axis.x;
    T ty = t * axis.y;
    T tz = t * axis.z;
    T sx = s * axis.x;
    T sy = s * axis.y;
    T sz = s * axis.z;

    return Matrix33Template<T>(
        tx * axis.x + c ,
        tx * axis.y + sz,
        tx * axis.z - sy,

        ty * axis.x - sz,
        ty * axis.y + c ,
        ty * axis.z + sx,

        tz * axis.x + sy,
        tz * axis.y - sx,
        tz * axis.z + c
        );
}












template<class T> Matrix33Template<T> Matrix33FromEulerXYZ(const Vector3Template<T> &euler)
{
    T ci, cj, ch, si, sj, sh;

    SinCos(euler.x, si, ci);
    SinCos(euler.y, sj, cj);
    SinCos(euler.z, sh, ch);

    T cc = ci * ch;
    T cs = ci * sh;
    T sc = si * ch;
    T ss = si * sh;

    return Matrix33Template<T>(
        cj * ch , cj * sh , -sj ,
        sj * sc - cs, sj * ss + cc, cj * si ,
        sj * cc + ss, sj * cs - sc, cj * ci
        );
}












template<class T> Vector3Template<T> EulerXYZFromMatrix33(const Matrix33Template<T>& m)
{
    T cy = Sqrt(m.xAxis.x * m.xAxis.x + m.xAxis.y * m.xAxis.y);

    if (cy > 0.001f)
    {
        return Vector3Template<T>(
            ATan2( m.yAxis.z, m.zAxis.z),
            ATan2(-m.xAxis.z, cy),
            ATan2( m.xAxis.y, m.xAxis.x)
            );
    }
    else
    {
        return Vector3Template<T>(
            ATan2(-m.zAxis.y, m.yAxis.y),
            ATan2(-m.xAxis.z, cy),
            0.0f
            );
    }
}








template<class T> T GetNormalError(const Matrix33Template<T>& matrix)
{
    Vector3Template<T> errorVec( MagnitudeSquared( matrix.XAxis() ) - static_cast<T>(1.0f),
        MagnitudeSquared( matrix.YAxis() ) - static_cast<T>(1.0f),
        MagnitudeSquared( matrix.ZAxis() ) - static_cast<T>(1.0f) );
    T error = MagnitudeSquared(errorVec);
    return error;
}








template<class T> T GetOrthogonalError(const Matrix33Template<T>& matrix)
{
    Matrix33Template<T> identity;
    identity.SetIdentity();

    Matrix33Template<T> result = Mult(matrix, Transpose(matrix));
    SelfSubtract(result, identity);

    Vector3Template<T> errorVec( MagnitudeSquared( result.XAxis() ),
                                 MagnitudeSquared( result.YAxis() ),
                                 MagnitudeSquared( result.ZAxis() ) );

    T error = MagnitudeSquared(errorVec);
    return error;
}








template<class T> T GetOrthogonalRowSetError(const Matrix33Template<T>& matrix)
{
    Vector3Template<T> errorVec( Dot( matrix.XAxis(), matrix.YAxis() ),
                                 Dot( matrix.YAxis(), matrix.ZAxis() ),
                                 Dot( matrix.ZAxis(), matrix.XAxis() ) );
    T error = MagnitudeSquared(errorVec);
    return error;
}

template<class T> Matrix33Template<T> SLerp(const Matrix33Template<T>& lFrom, const Matrix33Template<T>& lTo, T lrParam, T& lprAngle)
{
    Matrix33Template<T> lReturnmatrix;
    Matrix33Template<T> lScratch;
    Vector3Template<T> axis;
    T lrAngle;


    if(lrParam <= 0.0f)
    {
        lprAngle = AngleBetweenVectors( lFrom.ZAxis(), lTo.ZAxis() );
        return lFrom;
    }
    else if(lrParam >= 1.0f)
    {
        lprAngle = 0.0f;
        return lTo;
    }


    lScratch = Mult( InverseOrthonormal(lFrom), lTo );

    QueryRotate(lScratch, axis, lrAngle );


    if( lrAngle < MATRIX_MIN_SLERP_ANGLE )
    {

        Matrix33Template<T> lLerpmat;

        lLerpmat.XAxis() = lTo.XAxis() - lFrom.XAxis();
        lLerpmat.YAxis() = lTo.YAxis() - lFrom.YAxis();
        lLerpmat.ZAxis() = lTo.ZAxis() - lFrom.ZAxis();


        lLerpmat *= lrParam;

        lReturnmatrix.XAxis() = Normalize(lFrom.XAxis() + lLerpmat.XAxis());
        lReturnmatrix.YAxis() = Normalize(lFrom.YAxis() + lLerpmat.YAxis());
        lReturnmatrix.ZAxis() = Normalize(lFrom.ZAxis() + lLerpmat.ZAxis());
    }
    else

    {
        Matrix33Template<T> lRotatematrix;


        lReturnmatrix = lFrom;


        lRotatematrix = Matrix33FromAxisRotationAngle( axis, ( lrAngle * lrParam ) );
        lReturnmatrix = Mult( lReturnmatrix, lRotatematrix );
    }

    lprAngle = lrAngle - (lrAngle * lrParam);
    return lReturnmatrix;

}

template<class T> Matrix33Template<T> SLerpByAngle(const Matrix33Template<T>& lFrom, const Matrix33Template<T>& lTo, T lrMaxAngle, T lprAngle)
{
    Matrix33Template<T> lReturnmatrix;
    Matrix33Template<T> lRotatematrix;
    Vector3Template<T> axis;
    T lrAngle;
    T lrDeltaAngle;


    Matrix33Template<T> lScratch = InverseOrthonormal(lFrom);
    lScratch = Mult( lScratch, lTo );

    QueryRotate(lScratch, axis, lrAngle );
    if( IsZero(axis) )
    {
        lprAngle = 0.0f;
        return lTo;
    }


    lReturnmatrix = lFrom;


    lrDeltaAngle = Min(lrAngle, lrMaxAngle);

    lRotatematrix = Matrix33FromAxisRotationAngle( axis, lrDeltaAngle );
    lReturnmatrix = Mult( lReturnmatrix, lRotatematrix );

    lprAngle = lrAngle - lrDeltaAngle;

    return lReturnmatrix;
}




















template<class T> Matrix33Template<T> OrthoNormalize(const Matrix33Template<T>& matrix)
{
    Vector3Template<T> *vpU, *vpV, *vpW;

    Vector3Template<T> right = Normalize(matrix.XAxis());
    Vector3Template<T> up = Normalize(matrix.YAxis());
    Vector3Template<T> at = Normalize(matrix.ZAxis());

    Vector3Template<T> vInner( Magnitude(matrix.XAxis()),
        Magnitude(matrix.YAxis()),
        Magnitude(matrix.ZAxis()) );

    if (vInner.x > 0.0f)
    {
        if (vInner.y > 0.0f)
        {
            if (vInner.z > 0.0f)
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
    return Matrix33Template<T>(
        right,
        up,
        at
        );
}









template<class T> Vector3Template<T> Transform(const Vector3Template<T>& vec, const Matrix33Template<T>& matrix)
{
    return Mult(vec, matrix);
}

template<class T> bool IsValid(const Matrix33Template<T>& a)
{
    return IsValid(a.XAxis()) &&
        IsValid(a.YAxis()) &&
        IsValid(a.ZAxis());
}









template<class T> bool IsNormal(const Matrix33Template<T>& matrix, T tolerance = EPSILON)
{
    return IsZero( GetNormalError(matrix), tolerance );
}









template<class T> bool IsOrthogonalRowSet(const Matrix33Template<T>& a, T tolerance = EPSILON)
{
    return IsZero( GetOrthogonalRowSetError(a), tolerance );
}









template<class T> bool IsOrthogonal(const Matrix33Template<T>& a, T tolerance = EPSILON)
{
    return IsZero( GetOrthogonalError(a), tolerance );
}










template<class T> Matrix33Template<T> InverseOrthonormal(const Matrix33Template<T>& in)
{
    ;
    return Transpose(in);
}








template<class T> Matrix33Template<T> Matrix33FromXRotationAngle(T angle)
{
    T s,c;
    SinCos(angle,s,c);
    const T zero(0.0f);
    const T one(1.0f);
    return Matrix33Template<T>(
        one, zero, zero,
        zero, c, s,
        zero, -s, c
        );
}








template<class T> Matrix33Template<T> Matrix33FromYRotationAngle(T angle)
{
    T s,c;
    SinCos(angle,s,c);
    const T zero(0.0f);
    const T one(1.0f);
    return Matrix33Template<T>(
        c, zero, -s,
        zero, one, zero,
        s, zero, c );
}








template<class T> Matrix33Template<T> Matrix33FromZRotationAngle(T angle)
{
    T s,c;
    SinCos(angle,s,c);
    const T zero(0.0f);
    const T one(1.0f);
    return Matrix33Template<T>(
        c, s, zero,
        -s, c, zero,
        zero, zero, one );
}








template<class T> Matrix33Template<T> RotateAroundXAxis(const Matrix33Template<T>& m, T angle)
{







    T s,c;
    SinCos(angle, s, c);


    return Matrix33Template<T>(
        m.XAxis(),
        m.ZAxis() * s + m.YAxis() * c,
        m.ZAxis() * c - m.YAxis() * s
    );
}








template<class T> Matrix33Template<T> RotateAroundYAxis(const Matrix33Template<T>&m, T angle)
{







    T s,c;

    SinCos(angle, s, c);


    return Matrix33Template<T>(
        m.XAxis() * c - m.ZAxis() * s,
        m.YAxis(),
        m.XAxis() * s + m.ZAxis() * c
    );
}








template<class T> Matrix33Template<T> RotateAroundZAxis(const Matrix33Template<T>& m, T angle)
{







    T s,c;

    SinCos(angle, s, c);


    return Matrix33Template<T>(
        m.YAxis() * s + m.XAxis() * c,
        m.YAxis() * c - m.XAxis() * s,
        m.ZAxis()
    );
}














template<class T> Matrix33Template<T> ScaleRow(const Matrix33Template<T>& m, T r0, T r1, T r2)
{
    return Matrix33Template<T>(
        Mult( m.xAxis, r0 ),
        Mult( m.yAxis, r1 ),
        Mult( m.zAxis, r2 )
        );
}













template<class T> Matrix33Template<T> ScaleColumn(const Matrix33Template<T>& m, T c0, T c1, T c2 )
{
    Vector3Template<T> rowMultiplier(c0, c1, c2);
    return Matrix33Template<T>(
        Mult( m.xAxis, rowMultiplier ),
        Mult( m.yAxis, rowMultiplier ),
        Mult( m.zAxis, rowMultiplier )
        );
}















template<class T> Matrix33Template<T> Matrix33FromDiagonal(T a)
{
    return Matrix33Template<T>(
        a,0,0,
        0,a,0,
        0,0,a
        );
}


template<class T> Vector3Template<T> QueryRotateDegenerateUnitAxis(const Matrix33Template<T>& matrix)
{
    if(matrix.XAxis().x > matrix.YAxis().y)
    {
        if(matrix.XAxis().x > matrix.ZAxis().z)
        {
            T xVal = 1.0f + matrix.XAxis().x;
            return Normalize(Vector3Template<T>(
                xVal*xVal,
                matrix.XAxis().y + matrix.YAxis().x,
                matrix.XAxis().z + matrix.ZAxis().x
                ));
        }
        else
        {
            T zVal = 1.0f + matrix.ZAxis().z;
            return Normalize(Vector3Template<T>(
                matrix.ZAxis().x + matrix.XAxis().z,
                matrix.ZAxis().y + matrix.YAxis().z,
                zVal*zVal
                ));
        }
    }
    else
    {
        if(matrix.YAxis().y > matrix.ZAxis().z)
        {
            T yVal = 1.0f + matrix.YAxis().y;
            return Normalize(Vector3Template<T>(
                matrix.YAxis().x + matrix.XAxis().y,
                yVal*yVal,
                matrix.YAxis().z + matrix.ZAxis().y
                ));
        }
        else
        {
            T zVal = 1.0f + matrix.ZAxis().z;
            return Normalize(Vector3Template<T>(
                matrix.ZAxis().x + matrix.XAxis().z,
                matrix.ZAxis().y + matrix.YAxis().z,
                zVal*zVal
                ));
        }
    }
}


template<class T> void QueryRotate(const Matrix33Template<T>& matrix, Vector3Template<T>& unitAxis, T& angle)
{
    Vector3Template<T> twoSinThetaAxis;
    T twoCosTheta = matrix.XAxis().x + matrix.YAxis().y + matrix.ZAxis().z - 1.0f;
    twoSinThetaAxis.x =matrix.YAxis().z - matrix.ZAxis().y;
    twoSinThetaAxis.y =matrix.ZAxis().x - matrix.XAxis().z;
    twoSinThetaAxis.z =matrix.XAxis().y - matrix.YAxis().x;
    T twoSinTheta = Magnitude(twoSinThetaAxis);
    if(twoSinTheta > T(0.0f))
    {
        const T lrRecipLength = 1.0f / twoSinTheta;
        unitAxis = twoSinThetaAxis * lrRecipLength;
    }
    else
    {
        unitAxis = Vector3Template<T>(0.0f, 0.0f, 0.0f);
    }
    angle = ATan2(twoSinTheta, twoCosTheta);
    if((twoSinTheta <= MINIMUM_RECIPROCAL) && (twoCosTheta <= 0.0f))
    {
        unitAxis = QueryRotateDegenerateUnitAxis(matrix);
    }
}










template<class T> void Transform(const Vector3Template<T>* const vecs, int numVectors, const Matrix33Template<T>& matrix, Vector3Template<T>* transformedVecs)
{
    for( int vecIndex = 0; vecIndex < numVectors; ++vecIndex )
    {
        transformedVecs[vecIndex] = Transform(vecs[vecIndex], matrix);
    }
}









template<class T> Matrix33Template<T>& operator *=(Matrix33Template<T> &m, const T& a)
{
    m = Mult(m, a);
    return m;
}









template<class T> Matrix33Template<T>& operator /=(Matrix33Template<T> &m, const T& a)
{
    m = Divide(m, a);
    return m;
}









template<class T> Matrix33Template<T>& operator *=(Matrix33Template<T> &m, const Matrix33Template<T> &b)
{
    m = Mult(m, b);
    return m;
}









template<class T> Matrix33Template<T>& operator +=(Matrix33Template<T> &m, const Matrix33Template<T> &b)
{
    m = Add(m, b);
    return m;
}









template<class T> Matrix33Template<T>& operator -=(Matrix33Template<T> &m, const Matrix33Template<T> &b)
{
    m = Subtract(m, b);
    return m;
}








template<class T> Matrix33Template<T> operator - (const Matrix33Template<T> &m)
{
    return Negate(m);
}









template<class T> Matrix33Template<T> operator * (const Matrix33Template<T> &m, const T& a)
{
    return Mult(m, a);
}









template<class T> Matrix33Template<T> operator * (const T& a, const Matrix33Template<T> &b)
{
    return Mult(b, a);
}









template<class T> Matrix33Template<T> operator / (const Matrix33Template<T> &m, T a)
{
    return Divide(m, a);
}









template<class T> Matrix33Template<T> operator + (const Matrix33Template<T> &a, const Matrix33Template<T> &b)
{
    return Add(a, b);
}









template<class T> Matrix33Template<T> operator - (const Matrix33Template<T> &a, const Matrix33Template<T> &b)
{
    return Subtract(a, b);
}









template<class T> Matrix33Template<T> operator * (const Matrix33Template<T> &a, const Matrix33Template<T> &b)
{
    return Mult(a, b);
}









template<class T> Vector3Template<T> operator * (const Vector3Template<T> &v, const Matrix33Template<T> &m)
{
    return Mult(v, m);
}

template <class T>
inline Matrix33Template<T> Select(const MaskScalarTemplate<T> &mask, const Matrix33Template<T> &trueValue, const Matrix33Template<T> &falseValue )
{
    return Matrix33Template<T>(
            Select( mask, trueValue.xAxis, falseValue.xAxis ),
            Select( mask, trueValue.yAxis, falseValue.yAxis ),
            Select( mask, trueValue.zAxis, falseValue.zAxis )
        );
}




 template<class T> void Negate(const Matrix33Template<T> &m, Matrix33Template<T> &result)
{
    result = Negate(m);
}
 template<class T> void Mult(const Matrix33Template<T> &m, T a, Matrix33Template<T> &result)
{
    result = Mult(m, a);
}
 template<class T> void Mult(const Vector3Template<T> &v, const Matrix33Template<T> &m, Vector3Template<T> &result)
{
    result = Mult(v, m);
}
 template<class T> void Mult(const Matrix33Template<T> &m, const Matrix33Template<T> &b, Matrix33Template<T> &result)
{
    result = Mult(m,b);
}
 template<class T> void Divide(const Matrix33Template<T> &m, T a, Matrix33Template<T> &result)
{
    result = Divide(m, a);
}
 template<class T> void Add(const Matrix33Template<T> &a, const Matrix33Template<T> &b, Matrix33Template<T> &result)
{
    result = Add(a,b);
}
 template<class T> void Subtract(const Matrix33Template<T> &a, const Matrix33Template<T> &b, Matrix33Template<T> &result)
{
    result = Subtract(a,b);
}

 template<class T> void Transpose(const Matrix33Template<T> &m, Matrix33Template<T> &result)
{
    result = Transpose(m);
}
 template<class T> T Inverse(const Matrix33Template<T> &m, Matrix33Template<T> &result)
{
    T determinant;
    result = Inverse(m, determinant);
    return determinant;
}

 template<class T> void Matrix33FromQuaternion(const QuaternionTemplate<T> &q, Matrix33Template<T> &result)
{
    result = Matrix33FromQuaternion(q);
}
 template<class T> void Matrix33FromAxisAngle(const Vector3Template<T> &axis, T angle, Matrix33Template<T> &result)
{
    result = Matrix33FromAxisRotationAngle(axis, angle);
}
 template<class T> void Matrix33FromEulerXYZ(const Vector3Template<T> &euler, Matrix33Template<T> &result)
{
    result = Matrix33FromEulerXYZ(euler);
}
 template<class T> void EulerXYZFromMatrix33(const Matrix33Template<T>& m, Vector3Template<T> &result)
{
    result = EulerXYZFromMatrix33(m);
}



}

}

}
