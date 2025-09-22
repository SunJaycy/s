









namespace rw {
namespace math {
namespace fpu {

template <class T>
class Vector4Template
{
public:

    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfElement = 4 };
    typedef const Vector4Template& InParam;
    typedef T FloatType;
    typedef T FastFloatType;


        typedef Vector4Template& OutParam;
        typedef Vector4Template& InOutParam;


    Vector4Template(const Vector4Template<float> &v)
    {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
        this->z = static_cast<T>(v.z);
        this->w = static_cast<T>(v.w);
    }

    Vector4Template(const Vector4Template<double> &v)
    {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
        this->z = static_cast<T>(v.z);
        this->w = static_cast<T>(v.w);
    }

    explicit Vector4Template(const rw::math::vpu::Vector4 &v);

    Vector4Template( const Vector3Template<T>& v3, const T _w )
    {
        this->x = v3.x;
        this->y = v3.y;
        this->z = v3.z;
        this->w = _w;
    }

    Vector4Template(T _x, T _y, T _z, T _w)
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
        this->w = _w;
    }

    explicit Vector4Template(const T xyzw[4])
    {
        this->x = xyzw[0];
        this->y = xyzw[1];
        this->z = xyzw[2];
        this->w = xyzw[3];
    }

    Vector4Template()
    {
    }

    inline __attribute__ ((always_inline)) Vector4Template operator = (const Vector4Template<T> &v)
    {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        this->w = v.w;
        return *this;
    }

    void Set(T _x, T _y, T _z, T _w)
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
        this->w = _w;
    }

    void SetComponent(int i, T value) { (&this->x)[i] = value; }

    void SetX(T _x) { this->x = _x; }
    void SetY(T _y) { this->y = _y; }
    void SetZ(T _z) { this->z = _z; }
    void SetW(T _w) { this->w = _w; }

    void SetZero() { Set(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));}

    const T& GetX() const { return this->x; }
    const T& GetY() const { return this->y; }
    const T& GetZ() const { return this->z; }
    const T& GetW() const { return this->w; }
    T& GetX() { return this->x; }
    T& GetY() { return this->y; }
    T& GetZ() { return this->z; }
    T& GetW() { return this->w; }

    const T& X() const { return this->x; }
    const T& Y() const { return this->y; }
    const T& Z() const { return this->z; }
    const T& W() const { return this->w; }
    T& X() { return this->x; }
    T& Y() { return this->y; }
    T& Z() { return this->z; }
    T& W() { return this->w; }

    T& GetComponent(int i) { return (&this->x)[i]; }
    const T& GetComponent(int i) const { return (&this->x)[i]; }

    T& operator [] (int i) { return (&this->x)[i]; }
    const T& operator [] (int i) const { return (&this->x)[i]; }

public:

    T x;
    T y;
    T z;
    T w;
};

typedef Vector4Template<float> Vector4;
typedef Vector4Template<float> Vector4_32;
typedef Vector4Template<double> Vector4_64;



    typedef Vector4Template<float> Vector4U_32;

    typedef Vector4Template<double> Vector4U_64;


}}







template <class T>
inline void EndianSwap(rw::math::fpu::Vector4Template<T>& t)
{
    math::detail::EndianSwapArray(reinterpret_cast<T *>(&t), sizeof(rw::math::fpu::Vector4Template<T>) / sizeof(T));
}

}
