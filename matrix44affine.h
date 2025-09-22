












#include <rw/math/fpu/quatpos.h>


namespace rw
{
namespace math
{
namespace fpu
{

template <class T>
class Matrix44AffineTemplate
{
public:

    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfRows = 4 };
    enum { NumberOfCols = 3 };
    enum { NumberOfElement = 12 };

    typedef const Matrix44AffineTemplate& InParam;


        typedef Matrix44AffineTemplate& OutParam;
        typedef Matrix44AffineTemplate& InOutParam;


    void Set(T m0, T m1, T m2, T m3, T m4, T m5,
             T m6, T m7, T m8, T m9, T m10, T m11)
    {
        xAxis.Set( m0, m1, m2);
        yAxis.Set( m3, m4, m5);
        zAxis.Set( m6, m7, m8);
        wAxis.Set( m9, m10, m11);
    }


    void Set(const Vector3Template<T>& row0, const Vector3Template<T>& row1, const Vector3Template<T>& row2, const Vector3Template<T>& row3)
    {
        xAxis = row0;
        yAxis = row1;
        zAxis = row2;
        wAxis = row3;
    }

    template <class INPUT_T>
    explicit Matrix44AffineTemplate(const Matrix44Template<INPUT_T> &m);

    Matrix44AffineTemplate(const Matrix44AffineTemplate<float> &m)
    {
        xAxis = Vector3Template<T>(m.XAxis());
        yAxis = Vector3Template<T>(m.YAxis());
        zAxis = Vector3Template<T>(m.ZAxis());
        wAxis = Vector3Template<T>(m.WAxis());
    }


    Matrix44AffineTemplate(const Matrix44AffineTemplate<double> &m)
    {
        xAxis = Vector3Template<T>(m.XAxis());
        yAxis = Vector3Template<T>(m.YAxis());
        zAxis = Vector3Template<T>(m.ZAxis());
        wAxis = Vector3Template<T>(m.WAxis());
    }

    template <class INPUT_T>
    Matrix44AffineTemplate(const Matrix44AffinePackedTemplate<INPUT_T> &m);

    explicit Matrix44AffineTemplate( const rw::math::vpu::Matrix44Affine& m);

    Matrix44AffineTemplate() {}


    Matrix44AffineTemplate(const Vector3Template<T>& row0, const Vector3Template<T>& row1, const Vector3Template<T>& row2, const Vector3Template<T>& row3)
    {
        xAxis = row0;
        yAxis = row1;
        zAxis = row2;
        wAxis = row3;
    }


    Matrix44AffineTemplate(T m0, T m1, T m2, T m3, T m4, T m5,
                           T m6, T m7, T m8, T m9, T m10, T m11)
    {
        Set(m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11);
    }


    explicit Matrix44AffineTemplate(const T m[12])
    {
        Set(m[0], m[1], m[2], m[3],
            m[4], m[5], m[6], m[7],
            m[8], m[9], m[10], m[11]);
    }


    Matrix44AffineTemplate(const QuaternionTemplate<T>& q, const Vector3Template<T>& pos)
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
        Set(
            one-two*(yy+zz), two*(xy+wz), two*(xz-wy),
            two*(xy-wz), one-two*(xx+zz), two*(yz+wx),
            two*(xz+wy), two*(yz-wx), one-two*(xx+yy),
            pos.x, pos.y, pos.z
            );
    }


    void SetZero()
    {
        Set(0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f);
    }


    void SetIdentity()
    {
        Set(1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 0.0f);
    }


    T& GetElem(int i)
    {
        const int row = i / 3;
        const int column = i % 3;
        return GetRow( row).GetComponent(column);
    }


    const T& GetElem(int i) const
    {
        return const_cast<Matrix44AffineTemplate<T>*>(this)->GetElem(i);
    }


    T& GetElem(int row, int column)
    {
        ;
        Vector3Template<T> &vector = (&xAxis)[row];
        return (&vector.x)[column];
    }


    const T& GetElem(int row, int column) const
    {
        return const_cast<Matrix44AffineTemplate<T>*>(this)->GetRow(row).GetComponent( column);
    }


    T& operator () (int row, int column)
    {
        return GetRow(row).GetComponent( column);
    }


    const T& operator () (int row, int column) const
    {
        return GetRow(row).GetComponent( column);
    }


    Vector3Template<T>& GetRow(int i)
    {
        return (&xAxis)[i];
    }


    const Vector3Template<T>& GetRow(int i) const
    {
        return (&xAxis)[i];
    }

    Vector3Template<T>& GetX() { return xAxis; }
    Vector3Template<T>& GetY() { return yAxis; }
    Vector3Template<T>& GetZ() { return zAxis; }
    Vector3Template<T>& GetW() { return wAxis; }

    const Vector3Template<T>& GetX() const { return xAxis; }
    const Vector3Template<T>& GetY() const { return yAxis; }
    const Vector3Template<T>& GetZ() const { return zAxis; }
    const Vector3Template<T>& GetW() const { return wAxis; }

    Vector3Template<T>& XAxis() { return xAxis; }
    Vector3Template<T>& YAxis() { return yAxis; }
    Vector3Template<T>& ZAxis() { return zAxis; }
    Vector3Template<T>& WAxis() { return wAxis; }

    const Vector3Template<T>& XAxis() const { return xAxis; }
    const Vector3Template<T>& YAxis() const { return yAxis; }
    const Vector3Template<T>& ZAxis() const { return zAxis; }
    const Vector3Template<T>& WAxis() const { return wAxis; }

    Vector3Template<T>& Right() { return xAxis; }
    Vector3Template<T>& Up() { return yAxis; }
    Vector3Template<T>& At() { return zAxis; }
    Vector3Template<T>& Pos() { return wAxis; }

    const Vector3Template<T>& Right() const { return xAxis; }
    const Vector3Template<T>& Up() const { return yAxis; }
    const Vector3Template<T>& At() const { return zAxis; }
    const Vector3Template<T>& Pos() const { return wAxis; }

    Vector4Template<T> GetXColumn() const
    {
        return Vector4Template<T>( xAxis.x, yAxis.x, zAxis.x, wAxis.x );
    }

    Vector4Template<T> GetYColumn() const
    {
        return Vector4Template<T>( xAxis.y, yAxis.y, zAxis.y, wAxis.y );
    }

    Vector4Template<T> GetZColumn() const
    {
        return Vector4Template<T>( xAxis.z, yAxis.z, zAxis.z, wAxis.z );
    }

    void SetXColumn(const Vector4Template<T> &col)
    {
        xAxis.x = col.x;
        yAxis.x = col.y;
        zAxis.x = col.z;
        wAxis.x = col.w;
    }

    void SetYColumn(const Vector4Template<T> &col)
    {
        xAxis.y = col.x;
        yAxis.y = col.y;
        zAxis.y = col.z;
        wAxis.y = col.w;
    }

    void SetZColumn(const Vector4Template<T> &col)
    {
        xAxis.z = col.x;
        yAxis.z = col.y;
        zAxis.z = col.z;
        wAxis.z = col.w;
    }

    void SetElem(int i, T f)
    {
        const int row = i / 3;
        const int column = i % 3;
        SetElem( row, column, f );
    }

    void SetElem(int row, int col, T f)
    {
        Vector3Template<T> &vector = (&xAxis)[row];
        (&vector.x)[col] = f;
    }

    void SetRow(int i, const Vector3Template<T>& v)
    {
        (&xAxis)[i] = v;
    }


    void SetX(const Vector3Template<T>& v)
    {
        SetRow(0, v);
    }


    void SetY(const Vector3Template<T>& v)
    {
        SetRow(1, v);
    }


    void SetZ(const Vector3Template<T>& v)
    {
        SetRow(2, v);
    }


    void SetW(const Vector3Template<T>& v)
    {
        SetRow(3, v);
    }

public:

    Vector3Template<T> xAxis;
    Vector3Template<T> yAxis;
    Vector3Template<T> zAxis;
    Vector3Template<T> wAxis;
};

typedef Matrix44AffineTemplate<float> Matrix44Affine;
typedef Matrix44AffineTemplate<float> Matrix44Affine_32;
typedef Matrix44AffineTemplate<double> Matrix44Affine_64;



    typedef Matrix44AffineTemplate<float> Matrix44AffineU_32;

    typedef Matrix44AffineTemplate<double> Matrix44AffineU_64;


}
}







    template <class T>
    inline void EndianSwap(rw::math::fpu::Matrix44AffineTemplate<T>& t)
    {
        EndianSwap(t.xAxis);
        EndianSwap(t.yAxis);
        EndianSwap(t.zAxis);
        EndianSwap(t.wAxis);
    }

}

#include <rw/math/fpu/detail/matrix44affine_type_inline.h>
