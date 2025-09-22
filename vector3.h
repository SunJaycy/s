








namespace rw {
namespace math {
namespace fpu {

template <class T>
class Vector3Template
{
public:

    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfElement = 3 };
    typedef const Vector3Template& InParam;
    typedef T FloatType;
    typedef T FastFloatType;


        typedef Vector3Template& OutParam;
        typedef Vector3Template& InOutParam;


    Vector3Template(const Vector3Template<float> &v)
    {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
        this->z = static_cast<T>(v.z);
    }

    Vector3Template(const Vector3Template<double> &v)
    {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
        this->z = static_cast<T>(v.z);
    }

    explicit Vector3Template(const rw::math::vpu::Vector3 &v);

    Vector3Template(T _x, T _y, T _z)
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }

    explicit Vector3Template(const T xyz[3])
    {
        this->x = xyz[0];
        this->y = xyz[1];
        this->z = xyz[2];
    }

    Vector3Template()
    {
    }

    void Set(T _x, T _y, T _z) { this->x = _x; this->y = _y; this->z = _z; }

    void SetComponent(int i, T value) { (&this->x)[i] = value; }

    void SetX(T _x) { this->x = _x; }
    void SetY(T _y) { this->y = _y; }
    void SetZ(T _z) { this->z = _z; }

    void SetZero() { Set(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));}

    const T& GetX() const { return this->x; }
    const T& GetY() const { return this->y; }
    const T& GetZ() const { return this->z; }
    T& GetX() { return this->x; }
    T& GetY() { return this->y; }
    T& GetZ() { return this->z; }

    const T& X() const { return this->x; }
    const T& Y() const { return this->y; }
    const T& Z() const { return this->z; }
    T& X() { return this->x; }
    T& Y() { return this->y; }
    T& Z() { return this->z; }

    T& GetComponent(int i) { return (&this->x)[i]; }
    const T& GetComponent(int i) const { return (&this->x)[i]; }

    T& operator [] (int i) { return (&this->x)[i]; }
    const T& operator [] (int i) const { return (&this->x)[i]; }

public:

    T x;
    T y;
    T z;
};

typedef Vector3Template<float> Vector3;
typedef Vector3Template<float> Vector3_32;
typedef Vector3Template<double> Vector3_64;



    typedef Vector3Template<float> Vector3U_32;

    typedef Vector3Template<double> Vector3U_64;


}}







template <class T>
inline void EndianSwap(rw::math::fpu::Vector3Template<T>& t)
{
    math::detail::EndianSwapArray(reinterpret_cast<T *>(&t), sizeof(rw::math::fpu::Vector3Template<T>) / sizeof(T));
}

}
