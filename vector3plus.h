





#include <rw/math/fpu/vector3.h>



namespace rw {
namespace math {
namespace fpu {

template <class T>
class Vector3PlusTemplate
{
public:

    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfElement = 4 };
    typedef const Vector3PlusTemplate& InParam;
    typedef T FloatType;
    typedef T FastFloatType;


        typedef Vector3PlusTemplate& OutParam;
        typedef Vector3PlusTemplate& InOutParam;


    Vector3PlusTemplate(const Vector3PlusTemplate<float> &v)
    {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
        this->z = static_cast<T>(v.z);
        this->userData = static_cast<T>(v.UserData());
    }

    Vector3PlusTemplate(const Vector3PlusTemplate<double> &v)
    {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
        this->z = static_cast<T>(v.z);
        this->userData = static_cast<T>(v.UserData());
    }

    explicit Vector3PlusTemplate(const rw::math::vpu::Vector3Plus &v);

    Vector3PlusTemplate()
    {
    }

    Vector3PlusTemplate( T _x, T _y, T _z, T plus )
    {
        Set(_x, _y, _z, plus);
    }

    explicit Vector3PlusTemplate( T xyzplus[4] )
    {
        Set(xyzplus[0],xyzplus[1],xyzplus[2],xyzplus[3]);
    }

    void Set(T _x, T _y, T _z, T plus)
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
        this->userData = plus;
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

    void SetZ(T _z)
    {
        this->z = _z;
    }

    void SetPlus(T plus)
    {
        this->userData = plus;
    }

    void SetZero() { Set(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));}

    const T& GetX() const { return this->x; }
    T& GetX() { return this->x; }

    const T& GetY() const { return this->y; }
    T& GetY() { return this->y; }

    const T& GetZ() const { return this->z; }
    T& GetZ() { return this->z; }

    const T& GetPlus() const { return this->userData; }
    T& GetPlus() { return this->userData; }

    const T& X() const { return this->x; }
    T& X() { return this->x; }

    const T& Y() const { return this->y; }
    T& Y() { return this->y; }

    const T& Z() const { return this->z; }
    T& Z() { return this->z; }

    const T& UserData() const { return this->userData; }
    T& UserData() { return this->userData; }

    T& GetComponent(int i) { return (&this->x)[i]; }
    const T& GetComponent(int i) const { return (&this->x)[i]; }

    T& operator [] (int i) { return GetComponent(i); }
    const T& operator [] (int i) const { return GetComponent(i); }


    void SetVector3(const Vector3Template<T>& v3)
    {
        Set(v3.x, v3.y, v3.z, UserData());
    }
    const Vector3Template<T>& GetVector3() const { return *reinterpret_cast<const Vector3Template<T>*>(this); }

public:

    T x;
    T y;
    T z;
    T userData;

};

typedef Vector3PlusTemplate<float> Vector3Plus;

typedef Vector3PlusTemplate<float> Vector3Plus_32;
typedef Vector3PlusTemplate<double> Vector3Plus_64;



    typedef Vector3PlusTemplate<float> Vector3PlusU_32;

    typedef Vector3PlusTemplate<double> Vector3PlusU_64;


}}







template <class T>
inline void EndianSwap(rw::math::fpu::Vector3PlusTemplate<T>& t)
{
    math::detail::EndianSwapArray(reinterpret_cast<T *>(&t), sizeof(rw::math::fpu::Vector3PlusTemplate<T>) / sizeof(T));
}

}
