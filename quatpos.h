





#include <rw/math/fpu/quaternion.h>




namespace rw {
namespace math {
namespace fpu {

template <class T>
class QuatPosTemplate
{
public:

    enum { IsAligned = 0 };
    enum { Alignment = 1 };
    enum { NumberOfElement = 7 };
    typedef const QuatPosTemplate& InParam;


        typedef QuatPosTemplate& OutParam;
        typedef QuatPosTemplate& InOutParam;


    QuatPosTemplate(const QuatPosTemplate<float> &v)
    {
        this->quat = QuaternionTemplate<T>(v.quat);
        this->pos = Vector3Template<T>(v.pos);
    }

    QuatPosTemplate(const QuatPosTemplate<double> &v)
    {
        this->quat = QuaternionTemplate<T>(v.quat);
        this->pos = Vector3Template<T>(v.pos);
    }

    explicit QuatPosTemplate(const rw::math::vpu::QuatPos &v);

    QuatPosTemplate()
    {
    }

    QuatPosTemplate(const QuaternionTemplate<T>& q, const Vector3Template<T>& p)
        :quat(q)
        ,pos(p)
    {
    }

    QuatPosTemplate(T quatX, T quatY, T quatZ, T quatW, T posX, T posY, T posZ)
        :quat( quatX, quatY, quatZ, quatW )
        ,pos(posX, posY, posZ)
    {
    }

    explicit QuatPosTemplate(T* xyzw )
        :quat(xyzw)
        ,pos(&xyzw[4])
    {
    }

    void Set(T quatX, T quatY, T quatZ, T quatW, T posX, T posY, T posZ)
    {
        quat.Set( quatX, quatY, quatZ, quatW );
        pos.Set( posX, posY, posZ );
    }

    void SetQuaternion(const QuaternionTemplate<T>& q)
    {
        quat = q;
    }

    void SetPos(const Vector3Template<T>& v)
    {
        pos = v;
    }

    void SetZero() { Set(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));}

    void SetIdentity() { Set(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));}

    QuaternionTemplate<T>& GetQuaternion()
    {
        return quat;
    }

    const QuaternionTemplate<T>& GetQuaternion() const
    {
        return quat;
    }

    Vector3Template<T> GetPos()
    {
        return pos;
    }

    const Vector3Template<T> GetPos() const
    {
        return pos;
    }

public:

    QuaternionTemplate<T> quat;
    Vector3Template<T> pos;
};


typedef QuatPosTemplate<float> QuatPos;

typedef QuatPosTemplate<float> QuatPos_32;
typedef QuatPosTemplate<double> QuatPos_64;



    typedef QuatPosTemplate<float> QuatPosU_32;

    typedef QuatPosTemplate<double> QuatPosU_64;


}
}







template <class T>
inline void EndianSwap(rw::math::fpu::QuatPosTemplate<T>& t)
{
    EndianSwap(t.quat);
    EndianSwap(t.pos);
}

}
