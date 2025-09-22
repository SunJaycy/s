






#include <rw/math/fpu/vector4.h>



namespace rw {
namespace math {
namespace fpu {

enum PlaneIntersection
{
    PI_ZERO,
    PI_ONE,
    PI_INFINITY
};

template <class T>
class PlaneTemplate
{
public:

    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfElement = 4 };
    typedef const PlaneTemplate& InParam;


        typedef PlaneTemplate& OutParam;
        typedef PlaneTemplate& InOutParam;


    PlaneTemplate(const PlaneTemplate<float> &v)
    {
        this->a = static_cast<T>(v.a);
        this->b = static_cast<T>(v.b);
        this->c = static_cast<T>(v.c);
        this->d = static_cast<T>(v.d);
    }

    PlaneTemplate(const PlaneTemplate<double> &v)
    {
        this->a = static_cast<T>(v.a);
        this->b = static_cast<T>(v.b);
        this->c = static_cast<T>(v.c);
        this->d = static_cast<T>(v.d);
    }

    explicit PlaneTemplate(const rw::math::vpu::Plane &v);

    PlaneTemplate()
    {
    }

    PlaneTemplate(const Vector3Template<T> &normal, T _d)
    {
        Set(normal, _d);
    }

    explicit PlaneTemplate(const T abcd[4])
    {
        Set(abcd[0], abcd[1], abcd[2], abcd[3]);
    }

    PlaneTemplate(T _a, T _b, T _c, T _d)
    {
        Set(_a, _b, _c, _d);
    }

    void Set(const Vector3Template<T> &normal, T _d)
    {
        Set(normal.x, normal.y, normal.z, _d);
    }

    void Set(T _a, T _b, T _c, T _d)
    {
        this->a = _a;
        this->b = _b;
        this->c = _c;
        this->d = _d;
    }

    void SetComponent(int i, T value) { (&this->a)[i] = value; }

    void SetA(T _a) { this->a = _a; }
    void SetB(T _b) { this->b = _b; }
    void SetC(T _c) { this->c = _c; }
    void SetD(T _d) { this->d = _d; }

    void A(T _a) { this->a = _a; }
    void B(T _b) { this->b = _b; }
    void C(T _c) { this->c = _c; }
    void D(T _d) { this->d = _d; }

    void SetZero() { Set(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f)); }

    const T& GetA() const { return this->a; }
    const T& GetB() const { return this->b; }
    const T& GetC() const { return this->c; }
    const T& GetD() const { return this->d; }
    T& GetA() { return this->a; }
    T& GetB() { return this->b; }
    T& GetC() { return this->c; }
    T& GetD() { return this->d; }

    const T& A() const { return this->a; }
    const T& B() const { return this->b; }
    const T& C() const { return this->c; }
    const T& D() const { return this->d; }
    T& A() { return this->a; }
    T& B() { return this->b; }
    T& C() { return this->c; }
    T& D() { return this->d; }

    T& GetComponent(int i) { return (&this->a)[i]; }
    const T& GetComponent(int i) const { return (&this->a)[i]; }

    T& operator [] (int i) { return (&this->a)[i]; }
    const T& operator [] (int i) const { return (&this->a)[i]; }

    void SetNormal(const Vector3Template<T>& v)
    {
        Set(v, this->d);
    }

    const Vector3Template<T>& GetNormal() const { return *reinterpret_cast<const Vector3Template<T>*>(&this->a);}
          Vector3Template<T>& GetNormal() { return *reinterpret_cast< Vector3Template<T>*>(&this->a);}

          T& SignedDistance() { return D(); }
    const T& SignedDistance() const { return D(); }

    T Distance() const { return Abs(D()); }

          Vector4Template<T>& GetVector() { return *reinterpret_cast< Vector4Template<T>*>(&this->a); }
    const Vector4Template<T>& GetVector() const { return *reinterpret_cast<const Vector4Template<T>*>(&this->a); }

public:

    T a;
    T b;
    T c;
    T d;
};


typedef PlaneTemplate<float> Plane;
typedef PlaneTemplate<float> Plane_32;
typedef PlaneTemplate<double> Plane_64;



    typedef PlaneTemplate<float> PlaneU_32;

    typedef PlaneTemplate<double> PlaneU_64;


}

}







template <class T>
inline void EndianSwap(rw::math::fpu::PlaneTemplate<T>& t)
{
    math::detail::EndianSwapArray(reinterpret_cast<T *>(&t), sizeof(rw::math::fpu::PlaneTemplate<T>) / sizeof(T));
}

}
