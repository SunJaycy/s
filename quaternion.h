








namespace rw {
namespace math {
namespace fpu {

template <class T>
class QuaternionTemplate
{
public:

    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfElement = 4 };
    typedef const QuaternionTemplate& InParam;


        typedef QuaternionTemplate& OutParam;
        typedef QuaternionTemplate& InOutParam;


    QuaternionTemplate(const QuaternionTemplate<float> &v)
    {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
        this->z = static_cast<T>(v.z);
        this->w = static_cast<T>(v.w);
    }

    QuaternionTemplate(const QuaternionTemplate<double> &v)
    {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
        this->z = static_cast<T>(v.z);
        this->w = static_cast<T>(v.w);
    }

    explicit QuaternionTemplate(const rw::math::vpu::Quaternion &v);

    QuaternionTemplate(T _x, T _y, T _z, T _w)
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
        this->w = _w;
    }

    explicit QuaternionTemplate(const T xyzw[4])
    {
        this->x = xyzw[0];
        this->y = xyzw[1];
        this->z = xyzw[2];
        this->w = xyzw[3];
    }

    QuaternionTemplate()
    {
    }

    void Set(T _x, T _y, T _z, T _w)
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
        this->w = _w;
    }

    void SetComponent(int i, const T& value) { (&this->x)[i] = value; }

    void SetX(T _x) { this->x = _x; }
    void SetY(T _y) { this->y = _y; }
    void SetZ(T _z) { this->z = _z; }
    void SetW(T _w) { this->w = _w; }

    void SetZero() { Set(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));}

    void SetIdentity() { Set(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f));}

    T GetX() const { return this->x; }
    T GetY() const { return this->y; }
    T GetZ() const { return this->z; }
    T GetW() const { return this->w; }
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

typedef QuaternionTemplate<float> Quaternion;

typedef QuaternionTemplate<float> Quaternion_32;
typedef QuaternionTemplate<double> Quaternion_64;



    typedef QuaternionTemplate<float> QuaternionU_32;

    typedef QuaternionTemplate<double> QuaternionU_64;


}}







template <class T>
inline void EndianSwap(rw::math::fpu::QuaternionTemplate<T>& t)
{
    math::detail::EndianSwapArray(reinterpret_cast<T *>(&t), sizeof(rw::math::fpu::QuaternionTemplate<T>) / sizeof(T));
}

}
