








namespace rw {
namespace math {
namespace fpu {


template <class T>
class Matrix44Template
{
public:

    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfRows = 4 };
    enum { NumberOfCols = 4 };
    enum { NumberOfElement = 16 };

    typedef const Matrix44Template& InParam;


        typedef Matrix44Template& OutParam;
        typedef Matrix44Template& InOutParam;


    void Set(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7,
             T m8, T m9, T m10, T m11, T m12, T m13, T m14, T m15)
    {
        xAxis.Set( m0, m1, m2, m3);
        yAxis.Set( m4, m5, m6, m7);
        zAxis.Set( m8, m9, m10, m11);
        wAxis.Set(m12, m13, m14, m15);
    }


    void Set(const Vector4Template<T>& row0,
             const Vector4Template<T>& row1,
             const Vector4Template<T>& row2,
             const Vector4Template<T>& row3)
    {
        xAxis = row0;
        yAxis = row1;
        zAxis = row2;
        wAxis = row3;
    }


    inline __attribute__ ((always_inline)) Matrix44Template(const Matrix44Template<float> &_v)
    {
        xAxis = Vector4Template<T>(_v.XAxis());
        yAxis = Vector4Template<T>(_v.YAxis());
        zAxis = Vector4Template<T>(_v.ZAxis());
        wAxis = Vector4Template<T>(_v.WAxis());
    }


    Matrix44Template(const Matrix44Template<double> &_v)
    {
        xAxis = Vector4Template<T>(_v.XAxis());
        yAxis = Vector4Template<T>(_v.YAxis());
        zAxis = Vector4Template<T>(_v.ZAxis());
        wAxis = Vector4Template<T>(_v.WAxis());
    }

    template <class INPUT_T>
    explicit Matrix44Template(const Matrix44AffineTemplate<INPUT_T> &_v);

    template <class INPUT_T>
    explicit Matrix44Template(const Matrix44AffinePackedTemplate<INPUT_T> &m);

    explicit Matrix44Template( const rw::math::vpu::Matrix44& m);

    Matrix44Template() {}


    Matrix44Template(const Vector4Template<T>& row0,
                     const Vector4Template<T>& row1,
                     const Vector4Template<T>& row2,
                     const Vector4Template<T>& row3)

    {
        Set(row0, row1, row2, row3);
    }


    Matrix44Template(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7,
                     T m8, T m9, T m10, T m11, T m12, T m13, T m14, T m15)
    {
        Set(m0, m1, m2, m3, m4, m5, m6, m7,
            m8, m9, m10, m11, m12, m13, m14, m15);
    }


    explicit Matrix44Template(const T m[16])
    {
        Set(m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7],
            m[8], m[9], m[10], m[11], m[12], m[13], m[14], m[15]);
    }

    inline __attribute__ ((always_inline)) Matrix44Template operator = (const Matrix44Template<T> &m)
    {
        this->xAxis = m.xAxis;
        this->yAxis = m.yAxis;
        this->zAxis = m.zAxis;
        this->wAxis = m.wAxis;
        return *this;
    }

    void SetZero()
    {
        Set(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
            static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
            static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
            static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
    }


    void SetIdentity()
    {
        Set(static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
            static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
            static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f),
            static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f));
    }


    T& GetElem(int i)
    {
        Vector4Template<T> &vector = (&xAxis)[i/4];
        return (&vector.x)[i%4];
    }


    const T& GetElem(int i) const
    {
        return const_cast<Matrix44Template<T>*>(this)->GetElem(i);
    }


    T& GetElem(int row, int column)
    {
        Vector4Template<T> &vector = (&xAxis)[row];
        return (&vector.x)[column];
    }


    const T& GetElem(int row, int column) const
    {
        return const_cast<Matrix44Template<T>*>(this)->GetRow(row).GetComponent( column);
    }


    T& operator () (int row, int column)
    {
        Vector4Template<T> &vector = (&xAxis)[row];
        return (&vector.x)[column];
    }


    const T& operator () (int row, int column) const
    {
        const Vector4Template<T> &vector = (&xAxis)[row];
        return (&vector.x)[column];
    }


    Vector4Template<T>& GetRow(int i)
    {
        return (&xAxis)[i];
    }


    const Vector4Template<T>& GetRow(int i) const
    {
        return (&xAxis)[i];
    }


    Vector4Template<T>& GetX() { return xAxis; }
    Vector4Template<T>& GetY() { return yAxis; }
    Vector4Template<T>& GetZ() { return zAxis; }
    Vector4Template<T>& GetW() { return wAxis; }

    const Vector4Template<T>& GetX() const { return xAxis; }
    const Vector4Template<T>& GetY() const { return yAxis; }
    const Vector4Template<T>& GetZ() const { return zAxis; }
    const Vector4Template<T>& GetW() const { return wAxis; }

    Vector4Template<T>& XAxis() { return xAxis; }
    Vector4Template<T>& YAxis() { return yAxis; }
    Vector4Template<T>& ZAxis() { return zAxis; }
    Vector4Template<T>& WAxis() { return wAxis; }

    const Vector4Template<T>& XAxis() const { return xAxis; }
    const Vector4Template<T>& YAxis() const { return yAxis; }
    const Vector4Template<T>& ZAxis() const { return zAxis; }
    const Vector4Template<T>& WAxis() const { return wAxis; }

    Vector4Template<T>& Right() { return xAxis; }
    Vector4Template<T>& Up() { return yAxis; }
    Vector4Template<T>& At() { return zAxis; }
    Vector4Template<T>& Pos() { return wAxis; }

    const Vector4Template<T>& Right() const { return xAxis; }
    const Vector4Template<T>& Up() const { return yAxis; }
    const Vector4Template<T>& At() const { return zAxis; }
    const Vector4Template<T>& Pos() const { return wAxis; }

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

    Vector4Template<T> GetWColumn() const
    {
        return Vector4Template<T>( xAxis.w, yAxis.w, zAxis.w, wAxis.w );
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

    void SetWColumn(const Vector4Template<T> &col)
    {
        xAxis.w = col.x;
        yAxis.w = col.y;
        zAxis.w = col.z;
        wAxis.w = col.w;
    }

    void SetElem(int i, T f)
    {
        Vector4Template<T> &vector = (&xAxis)[i/4];
        (&vector.x)[i%4] = f;
    }


    void SetElem(int row, int column, T f)
    {
        Vector4Template<T> &vector = (&xAxis)[row];
        (&vector.x)[column] = f;
    }


    void SetRow(int i, const Vector4Template<T>& v)
    {
        (&xAxis)[i] = v;
    }


    void SetX(const Vector4Template<T>& v) { xAxis = v; }
    void SetY(const Vector4Template<T>& v) { yAxis = v; }
    void SetZ(const Vector4Template<T>& v) { zAxis = v; }
    void SetW(const Vector4Template<T>& v) { wAxis = v; }

public:

    Vector4Template<T> xAxis;
    Vector4Template<T> yAxis;
    Vector4Template<T> zAxis;
    Vector4Template<T> wAxis;
};

typedef Matrix44Template<float> Matrix44;
typedef Matrix44Template<float> Matrix44_32;
typedef Matrix44Template<double> Matrix44_64;



    typedef Matrix44Template<float> Matrix44U_32;

    typedef Matrix44Template<double> Matrix44U_64;


}}







template <class T>
inline void EndianSwap(rw::math::fpu::Matrix44Template<T>& t)
{
    EndianSwap(t.xAxis);
    EndianSwap(t.yAxis);
    EndianSwap(t.zAxis);
    EndianSwap(t.wAxis);
}

}

#include <rw/math/fpu/detail/matrix44_type_inline.h>
