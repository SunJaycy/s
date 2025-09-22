


















namespace rw {
namespace math {
namespace fpu {

template <class T>
class Matrix44AffinePackedTemplate
{
public:


    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfRows = 3 };
    enum { NumberOfCols = 4 };
    enum { NumberOfElement = 12 };

    inline __attribute__ ((always_inline)) Matrix44AffinePackedTemplate(){}
    inline __attribute__ ((always_inline)) explicit Matrix44AffinePackedTemplate( const rw::math::vpu::Matrix44AffinePacked& m);

    inline __attribute__ ((always_inline)) Matrix44AffinePackedTemplate(const Matrix44AffinePackedTemplate<float>& m)
    {
        this->xAxis = m.xAxis;
        this->yAxis = m.yAxis;
        this->zAxis = m.zAxis;
    }

    inline __attribute__ ((always_inline)) Matrix44AffinePackedTemplate(const Matrix44AffinePackedTemplate<double>& m)
    {
        this->xAxis = m.xAxis;
        this->yAxis = m.yAxis;
        this->zAxis = m.zAxis;
    }


    template <class INPUT_T>
    inline __attribute__ ((always_inline)) Matrix44AffinePackedTemplate(const Matrix44AffineTemplate<INPUT_T>& m)
        :xAxis(Vector4Template<T>(static_cast<T>(m.xAxis.x), static_cast<T>(m.yAxis.x), static_cast<T>(m.zAxis.x), static_cast<T>(m.wAxis.x)))
        ,yAxis(Vector4Template<T>(static_cast<T>(m.xAxis.y), static_cast<T>(m.yAxis.y), static_cast<T>(m.zAxis.y), static_cast<T>(m.wAxis.y)))
        ,zAxis(Vector4Template<T>(static_cast<T>(m.xAxis.z), static_cast<T>(m.yAxis.z), static_cast<T>(m.zAxis.z), static_cast<T>(m.wAxis.z)))
    {
    }


    template <class INPUT_T>
    explicit inline __attribute__ ((always_inline)) Matrix44AffinePackedTemplate(const Matrix44Template<INPUT_T>& m)
        :xAxis(Vector4Template<T>(static_cast<T>(m.xAxis.x), static_cast<T>(m.yAxis.x), static_cast<T>(m.zAxis.x), static_cast<T>(m.wAxis.x)))
        ,yAxis(Vector4Template<T>(static_cast<T>(m.xAxis.y), static_cast<T>(m.yAxis.y), static_cast<T>(m.zAxis.y), static_cast<T>(m.wAxis.y)))
        ,zAxis(Vector4Template<T>(static_cast<T>(m.xAxis.z), static_cast<T>(m.yAxis.z), static_cast<T>(m.zAxis.z), static_cast<T>(m.wAxis.z)))
    {
        ;





    }


    inline __attribute__ ((always_inline)) Matrix44AffinePackedTemplate(const Vector3Template<T>& row0, const Vector3Template<T>& row1, const Vector3Template<T>& row2, const Vector3Template<T>& row3)
    {
        this->xAxis.Set(row0.x, row1.x, row2.x, row3.x);
        this->yAxis.Set(row0.y, row1.y, row2.y, row3.y);
        this->zAxis.Set(row0.z, row1.z, row2.z, row3.z);
    }


    inline __attribute__ ((always_inline)) Matrix44AffinePackedTemplate(T m0, T m1, T m2, T m3, T m4, T m5,
                                                           T m6, T m7, T m8, T m9, T m10, T m11)
    {
        this->xAxis.Set(m0, m3, m6, m9);
        this->yAxis.Set(m1, m4, m7, m10);
        this->zAxis.Set(m2, m5, m8, m11);
    }


    inline __attribute__ ((always_inline)) Matrix44AffinePackedTemplate(const T m[12])
    {
        this->xAxis.Set(m[0], m[3], m[6], m[9]);
        this->yAxis.Set(m[1], m[4], m[7], m[10]);
        this->zAxis.Set(m[2], m[5], m[8], m[11]);
    }


    inline __attribute__ ((always_inline)) void SetZero()
    {
        this->xAxis.SetZero();
        this->yAxis.SetZero();
        this->zAxis.SetZero();
    }


    inline __attribute__ ((always_inline)) void Set(T m0, T m1, T m2, T m3, T m4, T m5,
                                       T m6, T m7, T m8, T m9, T m10, T m11)
    {
        this->xAxis.Set(m0, m3, m6, m9);
        this->yAxis.Set(m1, m4, m7, m10);
        this->zAxis.Set(m2, m5, m8, m11);
    }


    inline __attribute__ ((always_inline)) void Set(const Vector3Template<T>& row0, const Vector3Template<T>& row1, const Vector3Template<T>& row2, const Vector3Template<T>& row3)
    {
        this->xAxis.Set(static_cast<T>(row0.x), static_cast<T>(row1.x), static_cast<T>(row2.x), static_cast<T>(row3.x));
        this->yAxis.Set(static_cast<T>(row0.y), static_cast<T>(row1.y), static_cast<T>(row2.y), static_cast<T>(row3.y));
        this->zAxis.Set(static_cast<T>(row0.z), static_cast<T>(row1.z), static_cast<T>(row2.z), static_cast<T>(row3.z));
    }


    inline __attribute__ ((always_inline)) T& GetElem(int row, int column)
    {
        ;
        return reinterpret_cast< Vector4Template<T>* >(this)[column].GetComponent(row);
    }


    inline __attribute__ ((always_inline)) const T& GetElem(int row, int column) const
    {
        ;
        return reinterpret_cast< const Vector4Template<T>* >(this)[column].GetComponent(row);
    }


    inline __attribute__ ((always_inline)) T& GetElem(int i)
    {
        const int row = i / 3;
        const int column = i % 3;
        return GetElem( row, column );
    }

    inline __attribute__ ((always_inline)) const T& GetElem(int i) const
    {
        const int row = i / 3;
        const int column = i % 3;
        return GetElem( row, column );
    }


    inline __attribute__ ((always_inline)) T& operator () (int row, int column)
    {
        return GetElem( row, column );
    }


    inline __attribute__ ((always_inline)) const T& operator () (int row, int column) const
    {
        return GetElem( row, column );
    }


    inline __attribute__ ((always_inline)) void SetElem(int row, int col, const T& f)
    {
        reinterpret_cast< Vector4Template<T>* >(this)[col].SetComponent(row, f);
    }


    inline __attribute__ ((always_inline)) void SetElem(int i, const T& f)
    {
        const int row = i / 3;
        const int column = i % 3;
        SetElem( row, column, f );
    }

    Vector4Template<T> xAxis;
    Vector4Template<T> yAxis;
    Vector4Template<T> zAxis;
};

typedef Matrix44AffinePackedTemplate<float> Matrix44AffinePacked;
typedef Matrix44AffinePackedTemplate<float> Matrix44AffinePacked_32;
typedef Matrix44AffinePackedTemplate<double> Matrix44AffinePacked_64;



typedef Matrix44AffinePackedTemplate<float> Matrix44AffinePackedU_32;



typedef Matrix44AffinePackedTemplate<double> Matrix44AffinePackedU_64;

}}







    template <class T>
    inline void EndianSwap(rw::math::fpu::Matrix44AffinePackedTemplate<T>& t)
    {
        EndianSwap(t.xAxis);
        EndianSwap(t.yAxis);
        EndianSwap(t.zAxis);
    }

}
