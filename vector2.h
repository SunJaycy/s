






#include <rw/math/types_fwd.h>

namespace rw {
namespace math {
namespace fpu {

template <class T>
class Vector2Template
{
public:

    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfElement = 2 };
    typedef const Vector2Template& InParam;
    typedef T FloatType;
    typedef T FastFloatType;


        typedef Vector2Template& OutParam;
        typedef Vector2Template& InOutParam;


    Vector2Template(const Vector2Template<float> &v)
    {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
    }

    Vector2Template(const Vector2Template<double> &v)
    {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
    }

    explicit Vector2Template(const rw::math::vpu::Vector2 &v);

    Vector2Template(T _x, T _y)
    {
        this->x = _x;
        this->y = _y;
    }

    explicit Vector2Template(const T xy[2])
    {
        this->x = xy[0];
        this->y = xy[1];
    }

    Vector2Template()
    {
    }

    void Set(T _x, T _y)
    {
        this->x = _x;
        this->y = _y;
    }

    void SetComponent(int i, T value) { (&this->x)[i] = value; }

    void SetX(T _x)
    {
        this->x = _x;
    }
    void SetY(T _y)
    {
        this->y = _y;
    }

    void SetZero() { Set(static_cast<T>(0.0f), static_cast<T>(0.0f));}

    const T& GetX() const { return this->x; }
    const T& GetY() const { return this->y; }
    T& GetX() { return this->x; }
    T& GetY() { return this->y; }

    const T& X() const { return this->x; }
    const T& Y() const { return this->y; }
    T& X() { return this->x; }
    T& Y() { return this->y; }

    T& GetComponent(int i) { return (&this->x)[i]; }
    const T& GetComponent(int i) const { return (&this->x)[i]; }

    T& operator [] (int i) { return (&this->x)[i]; }
    const T& operator [] (int i) const { return (&this->x)[i]; }

public:

    T x;
    T y;
};

typedef Vector2Template<float> Vector2;
typedef Vector2Template<float> Vector2_32;
typedef Vector2Template<double> Vector2_64;



    typedef Vector2Template<float> Vector2U_32;

    typedef Vector2Template<double> Vector2U_64;


}}







template <class T>
inline void EndianSwap(rw::math::fpu::Vector2Template<T>& t)
{
    math::detail::EndianSwapArray(reinterpret_cast<T *>(&t), sizeof(rw::math::fpu::Vector2Template<T>) / sizeof(T));
}

}
