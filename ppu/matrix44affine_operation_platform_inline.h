




namespace rw
{

namespace math
{

namespace vpu
{

    inline __attribute__ ((always_inline)) VecFloat Determinant(Matrix44Affine::InParam m)
    {
        return
            m.xAxis.X() * (
            m.yAxis.Y() * m.zAxis.Z() -
            m.yAxis.Z() * m.zAxis.Y()
            ) +
            m.xAxis.Y() * (
            m.yAxis.Z() * m.zAxis.X() -
            m.yAxis.X() * m.zAxis.Z()
            ) +
            m.xAxis.Z() * (
            m.yAxis.X() * m.zAxis.Y() -
            m.yAxis.Y() * m.zAxis.X()
            );
    }

    inline __attribute__ ((always_inline)) Vector3 TransformVector(Vector3::InParam vec, Matrix44Affine::InParam matrix)
    {
        VectorIntrinsic tmp = vec.mV;
        VectorIntrinsic xSplat, ySplat, zSplat, result;

        { xSplat = (::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(tmp), ((int)(0))); };
        { ySplat = (::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(tmp), ((int)(1))); };
        { zSplat = (::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(tmp), ((int)(2))); };

        result = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((matrix.xAxis.mV), (xSplat), ((::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(0))));;
        result = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((matrix.yAxis.mV), (ySplat), (result));;
        result = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((matrix.zAxis.mV), (zSplat), (result));;

        return Vector3(result);
    }

    inline __attribute__ ((always_inline)) Vector3 TransformPoint(Vector3::InParam pt, Matrix44Affine::InParam matrix)
    {
        VectorIntrinsic tmp = pt.mV;
        VectorIntrinsic xSplat, ySplat, zSplat, result;

        { xSplat = (::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(tmp), ((int)(0))); };
        { ySplat = (::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(tmp), ((int)(1))); };
        { zSplat = (::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(tmp), ((int)(2))); };

        result = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((matrix.xAxis.mV), (xSplat), (matrix.wAxis.mV));;
        result = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((matrix.yAxis.mV), (ySplat), (result));;
        result = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((matrix.zAxis.mV), (zSplat), (result));;

        return Vector3(result);
    }


    inline __attribute__ ((always_inline)) Vector4 Mult(Vector4::InParam v, Matrix44Affine::InParam m)
    {
        VectorIntrinsic tmp = v.mV;
        VectorIntrinsic splatX = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(tmp), (0));
        VectorIntrinsic splatY = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(tmp), (1));
        VectorIntrinsic splatZ = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(tmp), (2));
        VectorIntrinsic splatW = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(tmp), (3));

        VectorIntrinsic result = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((m.xAxis.mV), (splatX), (((::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(0)))));
        result = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((m.yAxis.mV), (splatY), (result));
        result = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((m.zAxis.mV), (splatZ), (result));
        result = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((m.wAxis.mV), (splatW), (result));

        result = _asmSwizzleStore<VectorAxisW, VectorAxisW>(result,tmp);
        return Vector4(result);
    }

    inline __attribute__ ((always_inline)) Matrix44Affine Mult(Matrix44Affine::InParam m, Matrix44Affine::InParam b)
    {
        VectorIntrinsic sp0, sp1, sp2, sp3;
        VectorIntrinsic ma0, ma1, ma2, ma3;
        VectorIntrinsic bx = b.xAxis.mV;
        VectorIntrinsic by = b.yAxis.mV;
        VectorIntrinsic bz = b.zAxis.mV;

        VectorIntrinsic zero = ((::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(0)));

        sp0 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.xAxis.mV), (0));
        sp1 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.yAxis.mV), (0));
        sp2 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.zAxis.mV), (0));
        sp3 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.wAxis.mV), (0));

        ma0 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp0), (bx), (zero));;
        ma1 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp1), (bx), (zero));;
        ma2 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp2), (bx), (zero));;
        ma3 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp3), (bx), (b.wAxis.mV));;

        sp0 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.xAxis.mV), (1));
        sp1 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.yAxis.mV), (1));
        sp2 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.zAxis.mV), (1));
        sp3 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.wAxis.mV), (1));

        ma0 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp0), (by), (ma0));;
        ma1 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp1), (by), (ma1));;
        ma2 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp2), (by), (ma2));;
        ma3 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp3), (by), (ma3));;

        sp0 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.xAxis.mV), (2));
        sp1 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.yAxis.mV), (2));
        sp2 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.zAxis.mV), (2));
        sp3 = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(m.wAxis.mV), (2));

        sp0 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp0), (bz), (ma0));;
        sp1 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp1), (bz), (ma1));;
        sp2 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp2), (bz), (ma2));;
        sp3 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((sp3), (bz), (ma3));;

        return Matrix44Affine(
            Vector3(sp0),
            Vector3(sp1),
            Vector3(sp2),
            Vector3(sp3)
            );
    }


    inline __attribute__ ((always_inline)) Matrix44Affine Transpose(Matrix44Affine::InParam m)
    {
        VectorIntrinsic temp0 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrghw((__attribute__((altivec(vector__))) signed int)(m.xAxis.mV), (__attribute__((altivec(vector__))) signed int)(m.zAxis.mV));
        VectorIntrinsic temp1 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrghw((__attribute__((altivec(vector__))) signed int)(m.yAxis.mV), (__attribute__((altivec(vector__))) signed int)(m.wAxis.mV));
        VectorIntrinsic temp2 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrglw((__attribute__((altivec(vector__))) signed int)(m.xAxis.mV), (__attribute__((altivec(vector__))) signed int)(m.zAxis.mV));
        VectorIntrinsic temp3 = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrglw((__attribute__((altivec(vector__))) signed int)(m.yAxis.mV), (__attribute__((altivec(vector__))) signed int)(m.wAxis.mV));

        return Matrix44Affine(
                (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrghw((__attribute__((altivec(vector__))) signed int)(temp0), (__attribute__((altivec(vector__))) signed int)(temp1)),
                (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrglw((__attribute__((altivec(vector__))) signed int)(temp0), (__attribute__((altivec(vector__))) signed int)(temp1)),
                (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrghw((__attribute__((altivec(vector__))) signed int)(temp2), (__attribute__((altivec(vector__))) signed int)(temp3)),
                ((::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(0)))
                );
    }

    inline Matrix44Affine Inverse(Matrix44Affine::InParam m, VecFloat& determinant)
    {
        determinant = Determinant(m);
        ;
        if(determinant==GetVecFloat_Zero())
        {
            return Matrix44Affine();
        }
        else
        {
            VecFloat determinantRecip = Reciprocal( determinant );
            return Matrix44Affine(
                ((m.yAxis.Y()*(m.zAxis.Z())+m.yAxis.Z()*(-m.zAxis.Y()))*determinantRecip),
                ((m.zAxis.Y()*(m.xAxis.Z())+m.zAxis.Z()*(-m.xAxis.Y()))*determinantRecip),
                ((m.xAxis.Y()*m.yAxis.Z()-m.xAxis.Z()*m.yAxis.Y())*determinantRecip),

                ((m.yAxis.Z()*(m.zAxis.X())+m.yAxis.X()*(-m.zAxis.Z()))*determinantRecip),
                ((m.zAxis.Z()*(m.xAxis.X())+m.zAxis.X()*(-m.xAxis.Z()))*determinantRecip),
                ((m.yAxis.X()*m.xAxis.Z()-m.xAxis.X()*m.yAxis.Z())*determinantRecip),

                ((m.yAxis.X()*(m.zAxis.Y())+m.yAxis.Y()*(-m.zAxis.X()))*determinantRecip),
                ((m.zAxis.X()*(m.xAxis.Y())+m.zAxis.Y()*(-m.xAxis.X()))*determinantRecip),
                ((m.xAxis.X()*m.yAxis.Y()-m.yAxis.X()*m.xAxis.Y())*determinantRecip),

                ((m.yAxis.X()*(m.wAxis.Y()*m.zAxis.Z()-m.zAxis.Y()*m.wAxis.Z())+m.yAxis.Y()*(m.zAxis.X()*m.wAxis.Z()-m.wAxis.X()*m.zAxis.Z())+m.yAxis.Z()*(m.wAxis.X()*m.zAxis.Y()-m.zAxis.X()*m.wAxis.Y()))*determinantRecip),
                ((m.zAxis.X()*(m.xAxis.Z()*m.wAxis.Y()-m.xAxis.Y()*m.wAxis.Z())+m.zAxis.Y()*(m.xAxis.X()*m.wAxis.Z()-m.wAxis.X()*m.xAxis.Z())+m.zAxis.Z()*(m.wAxis.X()*m.xAxis.Y()-m.xAxis.X()*m.wAxis.Y()))*determinantRecip),
                ((m.wAxis.X()*(m.xAxis.Z()*m.yAxis.Y()-m.xAxis.Y()*m.yAxis.Z())+m.wAxis.Y()*(m.xAxis.X()*m.yAxis.Z()-m.yAxis.X()*m.xAxis.Z())+m.wAxis.Z()*(m.yAxis.X()*m.xAxis.Y()-m.xAxis.X()*m.yAxis.Y()))*determinantRecip)
                );
        }
    }

    inline __attribute__ ((always_inline)) Matrix44Affine Matrix44AffineFromAxisRotationAngle(Vector3::InParam axis, VecFloat::InParam angle)
    {
        VecFloat s, c;

        SinCos(angle, s, c);
        VecFloat t = GetVecFloat_One() - c;
        VecFloat tx = t * axis.X();
        VecFloat ty = t * axis.Y();
        VecFloat tz = t * axis.Z();
        VecFloat sx = s * axis.X();
        VecFloat sy = s * axis.Y();
        VecFloat sz = s * axis.Z();

        const VecFloat zero(0.0f);
        return Matrix44Affine(
            tx * axis.X() + c ,
            tx * axis.Y() + sz,
            tx * axis.Z() - sy,

            ty * axis.X() - sz,
            ty * axis.Y() + c ,
            ty * axis.Z() + sx,

            tz * axis.X() + sy,
            tz * axis.Y() - sx,
            tz * axis.Z() + c,

            zero,
            zero,
            zero
            );
    }



    inline Matrix44Affine Inverse3x3(Matrix44Affine::InParam m, VecFloat& determinant)
    {
        determinant = Determinant(m);
        ;
        if(determinant==GetVecFloat_Zero())
        {
            return Matrix44Affine();
        }
        else
        {
            Matrix44Affine result;
            for(int i=0; i<3; ++i)
            {
                for(int j=0; j<3; ++j)
                {
                    int32_t i1=(i+1)%3;
                    int32_t i2=(i+2)%3;
                    int32_t j1=(j+1)%3;
                    int32_t j2=(j+2)%3;
                    result.SetElem(j,i,
                        (m.GetElem(i1, j1)*m.GetElem(i2, j2)-m.GetElem(i2, j1)*m.GetElem(i1, j2)) / determinant
                        );
                }
                result.SetElem(3,i, GetVecFloat_Zero());
            }
            return result;
        }
    }

    inline __attribute__ ((always_inline)) Matrix44Affine InverseOfMatrixWithOrthonormal3x3(Matrix44Affine::InParam in)
    {
        ;

        VectorIntrinsic zero = ((::rw::math::vpu::VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltisw((char)(0)));

        VectorIntrinsic negatePos = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vsubfp( zero, in.wAxis.mV );

        VectorIntrinsic tempT[4];
        tempT[2] = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrghw((__attribute__((altivec(vector__))) signed int)(in.xAxis.mV), (__attribute__((altivec(vector__))) signed int)(in.zAxis.mV));
        tempT[3] = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrghw((__attribute__((altivec(vector__))) signed int)(in.yAxis.mV), (__attribute__((altivec(vector__))) signed int)(zero));
        tempT[0] = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrglw((__attribute__((altivec(vector__))) signed int)(in.xAxis.mV), (__attribute__((altivec(vector__))) signed int)(in.zAxis.mV));
        tempT[1] = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrglw((__attribute__((altivec(vector__))) signed int)(in.yAxis.mV), (__attribute__((altivec(vector__))) signed int)(zero));

        VectorIntrinsic transposedTransform[4];
        transposedTransform[0] = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrghw((__attribute__((altivec(vector__))) signed int)(tempT[2]), (__attribute__((altivec(vector__))) signed int)(tempT[3]));
        transposedTransform[1] = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrglw((__attribute__((altivec(vector__))) signed int)(tempT[2]), (__attribute__((altivec(vector__))) signed int)(tempT[3]));
        transposedTransform[2] = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmrghw((__attribute__((altivec(vector__))) signed int)(tempT[0]), (__attribute__((altivec(vector__))) signed int)(tempT[1]));

        VectorIntrinsic Z = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(negatePos), (2));
        VectorIntrinsic Y = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(negatePos), (1));
        VectorIntrinsic X = (VectorIntrinsic)(::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vspltw ((__attribute__((altivec(vector__))) signed int)(negatePos), (0));

        transposedTransform[3] = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((Z), (transposedTransform[2]), (zero));;
        transposedTransform[3] = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((Y), (transposedTransform[1]), (transposedTransform[3]));;
        transposedTransform[3] = (::rw::math::vpu::VectorIntrinsic)__builtin_altivec_vmaddfp((X), (transposedTransform[0]), (transposedTransform[3]));;
        return Matrix44Affine(transposedTransform[0], transposedTransform[1], transposedTransform[2], transposedTransform[3]);
    }

    inline __attribute__ ((always_inline)) Matrix44Affine Matrix44AffineFromXRotationAngle(VecFloat::InParam angle)
    {
        VecFloat s,c;
        SinCos(angle,s,c);
        const VecFloat zero(0.0f);
        const VecFloat one(1.0f);
        return Matrix44Affine(
            one, zero, zero,
            zero, c, s,
            zero, -s, c,
            zero, zero, zero
            );
    }

    inline __attribute__ ((always_inline)) Matrix44Affine Matrix44AffineFromYRotationAngle(VecFloat::InParam angle)
    {
        VecFloat s,c;
        SinCos(angle,s,c);
        const VecFloat zero(0.0f);
        const VecFloat one(1.0f);
        return Matrix44Affine(
            c, zero, -s,
            zero, one, zero,
            s, zero, c,
            zero, zero, zero );
    }

    inline __attribute__ ((always_inline)) Matrix44Affine Matrix44AffineFromZRotationAngle(VecFloat::InParam angle)
    {
        VecFloat s,c;
        SinCos(angle,s,c);
        const VecFloat zero(0.0f);
        const VecFloat one(1.0f);
        return Matrix44Affine(
            c, s, zero,
            -s, c, zero,
            zero, zero, one,
            zero, zero, zero);
    }

    inline void QueryRotate(Matrix44Affine::InParam matrix, Vector3& unitAxis, VecFloat& angle, Vector3& center)
    {
        Vector3 twoSinThetaAxis;
        VecFloat twoCosTheta = matrix.xAxis.X() + matrix.yAxis.Y() + matrix.zAxis.Z() - GetVecFloat_One();
        twoSinThetaAxis.X() =matrix.yAxis.Z() - matrix.zAxis.Y();
        twoSinThetaAxis.Y() =matrix.zAxis.X() - matrix.xAxis.Z();
        twoSinThetaAxis.Z() =matrix.xAxis.Y() - matrix.yAxis.X();
        VecFloat twoSinTheta = Magnitude(twoSinThetaAxis);
        if(twoSinTheta > GetVecFloat_Zero())
        {
            const VecFloat lrRecipLength = GetVecFloat_One() / twoSinTheta;
            unitAxis = twoSinThetaAxis * lrRecipLength;
        }
        else
        {
            unitAxis = Vector3(0.0f, 0.0f, 0.0f);
        }
        angle = ATan2(twoSinTheta, twoCosTheta);
        if((twoSinTheta <= VecFloat(MINIMUM_RECIPROCAL)) && (twoCosTheta <= GetVecFloat_Zero()))
        {
            unitAxis = QueryRotateDegenerateUnitAxis(matrix);
        }
        Vector3 axisXpos = Cross(unitAxis, matrix.wAxis);
        center = Cross(axisXpos, unitAxis) * VecFloat(0.5f);
        center += axisXpos * (VecFloat(0.5f) * twoSinTheta / (VecFloat(2.0f) - twoCosTheta));
    }

    inline Matrix44Affine SLerp(Matrix44Affine::InParam lFrom, Matrix44Affine::InParam lTo, VecFloat::InParam lrParam, VecFloat& lprAngle)
    {
        Matrix44Affine lReturnmatrix;
        Matrix44Affine lScratch;
        Vector3 axis;
        Vector3 lCentre;
        VecFloat lrAngle;


        if(lrParam <= GetVecFloat_Zero())
        {
            lprAngle = AngleBetweenVectors( lFrom.zAxis, lTo.zAxis );
            return lFrom;
        }
        else if(lrParam >= GetVecFloat_One())
        {
            lprAngle = GetVecFloat_Zero();
            return lTo;
        }


        lScratch = Mult( InverseOrthonormal(lFrom), lTo );

        QueryRotate(lScratch, axis, lrAngle, lCentre );


        if( lrAngle < VecFloat(MATRIX_MIN_SLERP_ANGLE) )
        {

            Matrix44Affine lLerpmat;

            lLerpmat.xAxis = lTo.xAxis - lFrom.xAxis;
            lLerpmat.yAxis = lTo.yAxis - lFrom.yAxis;
            lLerpmat.zAxis = lTo.zAxis - lFrom.zAxis;
            lLerpmat.wAxis = lTo.wAxis - lFrom.wAxis;


            lLerpmat = Mult( lLerpmat, lrParam);

            lReturnmatrix.xAxis = Normalize(lFrom.xAxis + lLerpmat.xAxis);
            lReturnmatrix.yAxis = Normalize(lFrom.yAxis + lLerpmat.yAxis);
            lReturnmatrix.zAxis = Normalize(lFrom.zAxis + lLerpmat.zAxis);
            lReturnmatrix.wAxis = lFrom.wAxis + lLerpmat.wAxis;
        }
        else

        {
            Matrix44Affine lRotatematrix;

            Vector3 lStartPos = lFrom.wAxis;
            Vector3 lEndPos = lTo.wAxis;


            lReturnmatrix = lFrom;
            lReturnmatrix.wAxis = GetVector3_Zero() ;


            lRotatematrix = Matrix44AffineFromAxisRotationAngle( axis, ( lrAngle * lrParam ) );
            lReturnmatrix = Mult( lReturnmatrix, lRotatematrix );


            lReturnmatrix.wAxis = (lEndPos - lStartPos) * lrParam + lStartPos;
        }

        lprAngle = lrAngle - (lrAngle * lrParam);
        return lReturnmatrix;

    }

    inline Matrix44Affine SLerpByAngle(Matrix44Affine::InParam lFrom, Matrix44Affine::InParam lTo, VecFloat::InParam lrMaxAngle, VecFloat& lprAngle)
    {
        Matrix44Affine lReturnmatrix;
        Matrix44Affine lRotatematrix;
        Vector3 axis;
        Vector3 lCentre;
        VecFloat lrAngle;
        VecFloat lrDeltaAngle;


        Matrix44Affine lScratch = InverseOrthonormal(lFrom);
        lScratch = Mult( lScratch, lTo );

        QueryRotate(lScratch, axis, lrAngle, lCentre );
        if( IsZero(axis) )
        {
            lprAngle = 0.0f;
            return lTo;
        }


        Vector3 lPosBackup = lFrom.wAxis;
        lReturnmatrix = lFrom;
        lReturnmatrix.wAxis = GetVector3_Zero() ;


        lrDeltaAngle = Min(lrAngle, lrMaxAngle);

        lRotatematrix = Matrix44AffineFromAxisRotationAngle( axis, lrDeltaAngle );
        lReturnmatrix = Mult( lReturnmatrix, lRotatematrix );


        lReturnmatrix.wAxis = lPosBackup ;

        lprAngle = lrAngle - lrDeltaAngle;

        return lReturnmatrix;
    }



    inline Matrix44Affine OrthoNormalize3x3(Matrix44Affine::InParam matrix)
    {
        Vector3 *vpU, *vpV, *vpW;

        Vector3 right = Normalize(matrix.xAxis);
        Vector3 up = Normalize(matrix.yAxis);
        Vector3 at = Normalize(matrix.zAxis);
        const Vector3 &pos = matrix.wAxis;

        Vector3 vInner( Magnitude(matrix.xAxis),
            Magnitude(matrix.yAxis),
            Magnitude(matrix.zAxis) );

        if (vInner.X() > GetVecFloat_Zero())
        {
            if (vInner.Y() > GetVecFloat_Zero())
            {
                if (vInner.Z() > GetVecFloat_Zero())
                {
                    Vector3 vOuter(Abs(Dot(up, at)), Abs(Dot(at,right)), Abs(Dot(right, up)));
                    if (vOuter.X() < vOuter.Y())
                    {
                        if (vOuter.X() < vOuter.Z())
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
                        if (vOuter.Y() < vOuter.Z())
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
        Matrix44Affine result(
            right.mV,
            up.mV,
            at.mV,
            pos.mV
            );
        return result;
    }

    inline Matrix44Affine InverseGeneric3x3(Matrix44Affine::InParam in)
    {




        Matrix44Affine out;
        out.xAxis.X() =( (in.yAxis.Y()) * (in.zAxis.Z()) - (in.yAxis.Z()) * (in.zAxis.Y()) );
        out.xAxis.Y() =-( (in.xAxis.Y()) * (in.zAxis.Z()) - (in.xAxis.Z()) * (in.zAxis.Y()) );
        out.xAxis.Z() =( (in.xAxis.Y()) * (in.yAxis.Z()) - (in.xAxis.Z()) * (in.yAxis.Y()) );
        VecFloat determinant = ((out.xAxis.X()) * (in.xAxis.X()) +
            (out.xAxis.Y()) * (in.yAxis.X()) +
            (out.xAxis.Z()) * (in.zAxis.X()) );
        VecFloat normalize;
        if (IsZero(determinant))
        {
            normalize = GetVecFloat_One();
        }
        else
        {
            normalize = GetVecFloat_One() / determinant;
        }

        out.xAxis *= normalize;
        out.yAxis.X() =-( (in.yAxis.X()) * (in.zAxis.Z()) - (in.yAxis.Z()) * (in.zAxis.X()) ) * normalize;
        out.yAxis.Y() = ( (in.xAxis.X()) * (in.zAxis.Z()) - (in.xAxis.Z()) * (in.zAxis.X()) ) * normalize;
        out.yAxis.Z() =-( (in.xAxis.X()) * (in.yAxis.Z()) - (in.xAxis.Z()) * (in.yAxis.X()) ) * normalize;
        out.zAxis.X() = ( (in.yAxis.X()) * (in.zAxis.Y()) - (in.yAxis.Y()) * (in.zAxis.X()) ) * normalize;
        out.zAxis.Y() =-( (in.xAxis.X()) * (in.zAxis.Y()) - (in.xAxis.Y()) * (in.zAxis.X()) ) * normalize;
        out.zAxis.Z() = ( (in.xAxis.X()) * (in.yAxis.Y()) - (in.xAxis.Y()) * (in.yAxis.X()) ) * normalize;
        out.wAxis.X() =-((in.wAxis.X() * out.xAxis.X()) +
            (in.wAxis.Y() * out.xAxis.Y()) +
            (in.wAxis.Z() * out.xAxis.Z()));
        out.wAxis.Y() =-((in.wAxis.X() * out.yAxis.X()) +
            (in.wAxis.Y() * out.yAxis.Y()) +
            (in.wAxis.Z() * out.yAxis.Z()));
        out.wAxis.Z() =-((in.wAxis.X() * out.zAxis.X()) +
            (in.wAxis.Y() * out.zAxis.Y()) +
            (in.wAxis.Z() * out.zAxis.Z()));
        return out;

    }


}

}

}
