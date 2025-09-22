








namespace rw {
namespace math {
namespace fpu {

template <class T>
class Matrix33Template
{
public:

    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfRows = 3 };
    enum { NumberOfCols = 3 };
    enum { NumberOfElement = 9 };

    typedef const Matrix33Template& InParam;


        typedef Matrix33Template& OutParam;
        typedef Matrix33Template& InOutParam;


    void Set(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8)
    {
        xAxis.Set( m0, m1, m2);
        yAxis.Set( m3, m4, m5);
        zAxis.Set( m6, m7, m8);
    }


    void Set(const Vector3Template<T>& row0, const Vector3Template<T>& row1, const Vector3Template<T>& row2)
    {
        xAxis = row0;
        yAxis = row1;
        zAxis = row2;
    }


    Matrix33Template(const Matrix33Template<float> &v)
    {
        xAxis = Vector3Template<T>(v.XAxis());
        yAxis = Vector3Template<T>(v.YAxis());
        zAxis = Vector3Template<T>(v.ZAxis());
    }


    Matrix33Template(const Matrix33Template<double> &v)
    {
        xAxis = Vector3Template<T>(v.XAxis());
        yAxis = Vector3Template<T>(v.YAxis());
        zAxis = Vector3Template<T>(v.ZAxis());
    }


    explicit Matrix33Template( const rw::math::vpu::Matrix33& m);


    Matrix33Template()
    {
    }


    Matrix33Template(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8)
    {
        Set(m0, m1, m2, m3, m4, m5, m6, m7, m8);
    }


    explicit Matrix33Template(const T m[9])
    {
        Set(
            m[0], m[1], m[2],
            m[3], m[4], m[5],
            m[6], m[7], m[8]
            );
    }


    Matrix33Template(const Vector3Template<T>& row0, const Vector3Template<T>& row1, const Vector3Template<T>& row2)
    {
        xAxis = row0;
        yAxis = row1;
        zAxis = row2;
    }


    void SetZero()
    {
        Set(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
            static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
            static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
    }


    void SetIdentity()
    {
        Set(static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
            static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f),
            static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f));
    }


    T& GetElem(int i)
    {
        Vector3Template<T> &vector = (&xAxis)[i/3];
        return (&vector.x)[i%3];
    }


    const T& GetElem(int i) const
    {
        return const_cast<Matrix33Template<T>*>(this)->GetElem(i);
    }


    T& GetElem(int row, int column)
    {
        Vector3Template<T> &vector = (&xAxis)[row];
        return (&vector.x)[column];
    }


    const T& GetElem(int row, int column) const
    {
        return const_cast<Matrix33Template<T>*>(this)->GetRow(row).GetComponent( column);
    }


    T& operator () (int row, int column)
    {
        Vector3Template<T> &vector = (&xAxis)[row];
        return (&vector.x)[column];
    }


    const T& operator () (int row, int column) const
    {
        const Vector3Template<T> &vector = (&xAxis)[row];
        return (&vector.x)[column];
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

    const Vector3Template<T>& GetX() const { return xAxis; }
    const Vector3Template<T>& GetY() const { return yAxis; }
    const Vector3Template<T>& GetZ() const { return zAxis; }

    Vector3Template<T>& XAxis() { return xAxis; }
    Vector3Template<T>& YAxis() { return yAxis; }
    Vector3Template<T>& ZAxis() { return zAxis; }

    const Vector3Template<T>& XAxis() const { return xAxis; }
    const Vector3Template<T>& YAxis() const { return yAxis; }
    const Vector3Template<T>& ZAxis() const { return zAxis; }

    Vector3Template<T>& Right() { return xAxis; }
    Vector3Template<T>& Up() { return yAxis; }
    Vector3Template<T>& At() { return zAxis; }

    const Vector3Template<T>& Right() const { return xAxis; }
    const Vector3Template<T>& Up() const { return yAxis; }
    const Vector3Template<T>& At() const { return zAxis; }

    Vector3Template<T> GetXColumn() const
    {
        return Vector3Template<T>( xAxis.x, yAxis.x, zAxis.x );
    }

    Vector3Template<T> GetYColumn() const
    {
        return Vector3Template<T>( xAxis.y, yAxis.y, zAxis.y );
    }

    Vector3Template<T> GetZColumn() const
    {
        return Vector3Template<T>( xAxis.z, yAxis.z, zAxis.z );
    }

    void SetXColumn(const Vector3Template<T> &col)
    {
        xAxis.x = col.x;
        yAxis.x = col.y;
        zAxis.x = col.z;
    }

    void SetYColumn(const Vector3Template<T> &col)
    {
        xAxis.y = col.x;
        yAxis.y = col.y;
        zAxis.y = col.z;
    }

    void SetZColumn(const Vector3Template<T> &col)
    {
        xAxis.z = col.x;
        yAxis.z = col.y;
        zAxis.z = col.z;
    }

    void SetElem(int i, T f)
    {
        Vector3Template<T> &vector = (&xAxis)[i/3];
        (&vector.x)[i%3] = f;
    }


    void SetElem(int row, int column, T f)
    {
        Vector3Template<T> &vector = (&xAxis)[row];
        (&vector.x)[column] = f;
    }


    void SetRow(int i, const Vector3Template<T>& v)
    {
        (&xAxis)[i] = v;
    }


    void SetX(const Vector3Template<T>& v) { xAxis = v; }
    void SetY(const Vector3Template<T>& v) { yAxis = v; }
    void SetZ(const Vector3Template<T>& v) { zAxis = v; }


public:

    Vector3Template<T> xAxis;
    Vector3Template<T> yAxis;
    Vector3Template<T> zAxis;
};

typedef Matrix33Template<float> Matrix33;
typedef Matrix33Template<float> Matrix33_32;
typedef Matrix33Template<double> Matrix33_64;



    typedef Matrix33Template<float> Matrix33U_32;

    typedef Matrix33Template<double> Matrix33U_64;


}}







template <class T>
inline void EndianSwap(rw::math::fpu::Matrix33Template<T>& t)
{
    EndianSwap(t.xAxis);
    EndianSwap(t.yAxis);
    EndianSwap(t.zAxis);
}

}
