








#include <rw/math/fpu/vector2.h>




#include <rw/math/fpu/matrix33.h>
#include <rw/math/fpu/matrix44.h>
#include <rw/math/fpu/matrix44affine.h>

namespace rw
{
namespace math
{
namespace fpu
{

template<class T>
T GetVecFloat_NegativeTwoTemplate()
{
    return static_cast<T>(-2.0f);
}

template<class T>
T GetVecFloat_NegativeOneTemplate()
{
    return static_cast<T>(-1.0f);
}

template<class T>
T GetVecFloat_NegativeHalfTemplate()
{
    return static_cast<T>(-0.5f);
}

template<class T>
T GetVecFloat_NegativeZeroTemplate()
{
    return static_cast<T>(-0.0f);
}

template<class T>
T GetVecFloat_ZeroTemplate()
{
    return static_cast<T>(0.0f);
}

template<class T>
T GetVecFloat_HalfTemplate()
{
    return static_cast<T>(0.5f);
}

template<class T>
T GetVecFloat_OneTemplate()
{
    return static_cast<T>(1.0f);
}

template<class T>
T GetVecFloat_TwoTemplate()
{
    return static_cast<T>(2.0f);
}






template<class T>
Vector2Template<T> GetVector2_ZeroTemplate()
{
    return Vector2Template<T>(static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
Vector2Template<T> GetVector2_OneTemplate()
{
    return Vector2Template<T>(static_cast<T>(1.0f), static_cast<T>(1.0f));
}






template<class T>
Vector2Template<T> GetVector2_XAxisTemplate()
{
    return Vector2Template<T>(static_cast<T>(1.0f), static_cast<T>(0.0f));
}






template<class T>
Vector2Template<T> GetVector2_YAxisTemplate()
{
    return Vector2Template<T>(static_cast<T>(0.0f), static_cast<T>(1.0f));
}






template<class T>
Vector3Template<T> GetVector3_ZeroTemplate()
{
    return Vector3Template<T>(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
Vector3Template<T> GetVector3_OneTemplate()
{
    return Vector3Template<T>(static_cast<T>(1.0f), static_cast<T>(1.0f), static_cast<T>(1.0f));
}






template<class T>
Vector3Template<T> GetVector3_XAxisTemplate()
{
    return Vector3Template<T>(static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
Vector3Template<T> GetVector3_YAxisTemplate()
{
    return Vector3Template<T>(static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f));
}






template<class T>
Vector3Template<T> GetVector3_ZAxisTemplate()
{
    return Vector3Template<T>(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f));
}






template<class T>
Vector4Template<T> GetVector4_ZeroTemplate()
{
    return Vector4Template<T>(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
Vector4Template<T> GetVector4_OneTemplate()
{
    return Vector4Template<T>(static_cast<T>(1.0f), static_cast<T>(1.0f), static_cast<T>(1.0f), static_cast<T>(1.0f));
}






template<class T>
Vector4Template<T> GetVector4_OriginTemplate()
{
    return Vector4Template<T>(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f));
}






template<class T>
Vector4Template<T> GetVector4_XAxisTemplate()
{
    return Vector4Template<T>(static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
Vector4Template<T> GetVector4_YAxisTemplate()
{
    return Vector4Template<T>(static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
Vector4Template<T> GetVector4_ZAxisTemplate()
{
    return Vector4Template<T>(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f));
}






template<class T>
Vector4Template<T> GetVector4_WAxisTemplate()
{
    return Vector4Template<T>(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f));
}






template<class T>
Matrix33Template<T> GetMatrix33_IdentityTemplate()
{
    return Matrix33Template<T>(
        static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f));
}






template<class T>
Matrix33Template<T> GetMatrix33_ZeroTemplate()
{
    return Matrix33Template<T>(
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
Matrix44Template<T> GetMatrix44_IdentityTemplate()
{
    return Matrix44Template<T>(
        static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f));
}






template<class T>
Matrix44Template<T> GetMatrix44_ZeroTemplate()
{
    return Matrix44Template<T>(
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
Matrix44AffineTemplate<T> GetMatrix44Affine_IdentityTemplate()
{
    return Matrix44AffineTemplate<T>(
        static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
Matrix44AffineTemplate<T> GetMatrix44Affine_ZeroTemplate()
{
    return Matrix44AffineTemplate<T>(
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}

template<class T>
Matrix44AffinePackedTemplate<T> GetMatrix44AffinePacked_IdentityTemplate()
{
    return Matrix44AffinePackedTemplate<T>(
        static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}

template<class T>
Matrix44AffinePackedTemplate<T> GetMatrix44AffinePacked_ZeroTemplate()
{
    return Matrix44AffinePackedTemplate<T>(
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
        static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
QuaternionTemplate<T> GetQuaternion_IdentityTemplate()
{
    return QuaternionTemplate<T>(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f));
}






template<class T>
QuaternionTemplate<T> GetQuaternion_ZeroTemplate()
{
    return QuaternionTemplate<T>(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
QuaternionTemplate<T> GetQuaternion_OneTemplate()
{
    return QuaternionTemplate<T>(static_cast<T>(1.0f), static_cast<T>(1.0f), static_cast<T>(1.0f), static_cast<T>(1.0f));
}






template<class T>
QuatPosTemplate<T> GetQuatPos_IdentityTemplate()
{
    return QuatPosTemplate<T>(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}






template<class T>
QuatPosTemplate<T> GetQuatPos_ZeroTemplate()
{
    return QuatPosTemplate<T>(static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(0.0f));
}




inline float GetVecFloat_NegativeTwo()
{
    return -2.0f;
}

inline float GetVecFloat_NegativeOne()
{
    return -1.0f;
}

inline float GetVecFloat_NegativeHalf()
{
    return -0.5f;
}

inline float GetVecFloat_NegativeZero()
{
    return -0.0f;
}

inline float GetVecFloat_Zero()
{
    return 0.0f;
}

inline float GetVecFloat_Half()
{
    return 0.5f;
}

inline float GetVecFloat_One()
{
    return 1.0f;
}

inline float GetVecFloat_Two()
{
    return 2.0f;
}

inline Vector2Template<float> GetVector2_Zero()
{
    return GetVector2_ZeroTemplate<float>();
}

inline Vector2Template<float> GetVector2_One()
{
    return GetVector2_OneTemplate<float>();
}

inline Vector2Template<float> GetVector2_XAxis()
{
    return GetVector2_XAxisTemplate<float>();
}

inline Vector2Template<float> GetVector2_YAxis()
{
    return GetVector2_YAxisTemplate<float>();
}


inline Vector3Template<float> GetVector3_Zero()
{
    return GetVector3_ZeroTemplate<float>();
}

inline Vector3Template<float> GetVector3_One()
{
    return GetVector3_OneTemplate<float>();
}

inline Vector3Template<float> GetVector3_XAxis()
{
    return GetVector3_XAxisTemplate<float>();
}

inline Vector3Template<float> GetVector3_YAxis()
{
    return GetVector3_YAxisTemplate<float>();
}

inline Vector3Template<float> GetVector3_ZAxis()
{
    return GetVector3_ZAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4_Zero()
{
    return GetVector4_ZeroTemplate<float>();
}

inline Vector4Template<float> GetVector4_One()
{
    return GetVector4_OneTemplate<float>();
}

inline Vector4Template<float> GetVector4_Origin()
{
    return GetVector4_OriginTemplate<float>();
}

inline Vector4Template<float> GetVector4_XAxis()
{
    return GetVector4_XAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4_YAxis()
{
    return GetVector4_YAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4_ZAxis()
{
    return GetVector4_ZAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4_WAxis()
{
    return GetVector4_WAxisTemplate<float>();
}

inline Matrix33Template<float> GetMatrix33_Identity()
{
    return GetMatrix33_IdentityTemplate<float>();
}

inline Matrix33Template<float> GetMatrix33_Zero()
{
    return GetMatrix33_ZeroTemplate<float>();
}

inline Matrix44Template<float> GetMatrix44_Identity()
{
    return GetMatrix44_IdentityTemplate<float>();
}

inline Matrix44AffineTemplate<float> GetMatrix44Affine_Identity()
{
    return GetMatrix44Affine_IdentityTemplate<float>();
}

inline Matrix44AffinePackedTemplate<float> GetMatrix44AffinePacked_Identity()
{
    return GetMatrix44AffinePacked_IdentityTemplate<float>();
}

inline Matrix44Template<float> GetMatrix44_Zero()
{
    return GetMatrix44_ZeroTemplate<float>();
}

inline Matrix44AffineTemplate<float> GetMatrix44Affine_Zero()
{
    return GetMatrix44Affine_ZeroTemplate<float>();
}


inline Matrix44AffinePackedTemplate<float> GetMatrix44AffinePacked_Zero()
{
    return GetMatrix44AffinePacked_ZeroTemplate<float>();
}


inline QuaternionTemplate<float> GetQuaternion_Identity()
{
    return GetQuaternion_IdentityTemplate<float>();
}

inline QuaternionTemplate<float> GetQuaternion_Zero()
{
    return GetQuaternion_ZeroTemplate<float>();
}

inline QuaternionTemplate<float> GetQuaternion_One()
{
    return GetQuaternion_OneTemplate<float>();
}

inline QuatPosTemplate<float> GetQuatPos_Identity()
{
    return GetQuatPos_IdentityTemplate<float>();
}

inline QuatPosTemplate<float> GetQuatPos_Zero()
{
    return GetQuatPos_ZeroTemplate<float>();
}



inline float GetVecFloat_32_NegativeTwo()
{
    return -2.0f;
}

inline float GetVecFloat_32_NegativeOne()
{
    return -1.0f;
}

inline float GetVecFloat_32_NegativeHalf()
{
    return -0.5f;
}

inline float GetVecFloat_32_NegativeZero()
{
    return -0.0f;
}

inline float GetVecFloat_32_Zero()
{
    return 0.0f;
}

inline float GetVecFloat_32_Half()
{
    return 0.5f;
}

inline float GetVecFloat_32_One()
{
    return 1.0f;
}

inline float GetVecFloat_32_Two()
{
    return 2.0f;
}

inline Vector2Template<float> GetVector2_32_Zero()
{
    return GetVector2_ZeroTemplate<float>();
}

inline Vector2Template<float> GetVector2_32_One()
{
    return GetVector2_OneTemplate<float>();
}

inline Vector2Template<float> GetVector2_32_XAxis()
{
    return GetVector2_XAxisTemplate<float>();
}

inline Vector2Template<float> GetVector2_32_YAxis()
{
    return GetVector2_YAxisTemplate<float>();
}


inline Vector3Template<float> GetVector3_32_Zero()
{
    return GetVector3_ZeroTemplate<float>();
}

inline Vector3Template<float> GetVector3_32_One()
{
    return GetVector3_OneTemplate<float>();
}

inline Vector3Template<float> GetVector3_32_XAxis()
{
    return GetVector3_XAxisTemplate<float>();
}

inline Vector3Template<float> GetVector3_32_YAxis()
{
    return GetVector3_YAxisTemplate<float>();
}

inline Vector3Template<float> GetVector3_32_ZAxis()
{
    return GetVector3_ZAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4_32_Zero()
{
    return GetVector4_ZeroTemplate<float>();
}

inline Vector4Template<float> GetVector4_32_One()
{
    return GetVector4_OneTemplate<float>();
}

inline Vector4Template<float> GetVector4_32_Origin()
{
    return GetVector4_OriginTemplate<float>();
}

inline Vector4Template<float> GetVector4_32_XAxis()
{
    return GetVector4_XAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4_32_YAxis()
{
    return GetVector4_YAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4_32_ZAxis()
{
    return GetVector4_ZAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4_32_WAxis()
{
    return GetVector4_WAxisTemplate<float>();
}

inline Matrix33Template<float> GetMatrix33_32_Identity()
{
    return GetMatrix33_IdentityTemplate<float>();
}

inline Matrix33Template<float> GetMatrix33_32_Zero()
{
    return GetMatrix33_ZeroTemplate<float>();
}

inline Matrix44Template<float> GetMatrix44_32_Identity()
{
    return GetMatrix44_IdentityTemplate<float>();
}

inline Matrix44AffineTemplate<float> GetMatrix44Affine_32_Identity()
{
    return GetMatrix44Affine_IdentityTemplate<float>();
}

inline Matrix44Template<float> GetMatrix44_32_Zero()
{
    return GetMatrix44_ZeroTemplate<float>();
}

inline Matrix44AffineTemplate<float> GetMatrix44Affine_32_Zero()
{
    return GetMatrix44Affine_ZeroTemplate<float>();
}

inline QuaternionTemplate<float> GetQuaternion_32_Identity()
{
    return GetQuaternion_IdentityTemplate<float>();
}

inline QuaternionTemplate<float> GetQuaternion_32_Zero()
{
    return GetQuaternion_ZeroTemplate<float>();
}

inline QuaternionTemplate<float> GetQuaternion_32_One()
{
    return GetQuaternion_OneTemplate<float>();
}

inline QuatPosTemplate<float> GetQuatPos_32_Identity()
{
    return GetQuatPos_IdentityTemplate<float>();
}

inline QuatPosTemplate<float> GetQuatPos_32_Zero()
{
    return GetQuatPos_ZeroTemplate<float>();
}


inline float GetVecFloat_64_NegativeTwo()
{
    return -2.0;
}

inline float GetVecFloat_64_NegativeOne()
{
    return -1.0;
}

inline float GetVecFloat_64_NegativeHalf()
{
    return -0.5;
}

inline float GetVecFloat_64_NegativeZero()
{
    return -0.0;
}

inline float GetVecFloat_64_Zero()
{
    return 0.0;
}

inline float GetVecFloat_64_Half()
{
    return 0.5;
}

inline float GetVecFloat_64_One()
{
    return 1.0;
}

inline float GetVecFloat_64_Two()
{
    return 2.0f;
}

inline Vector2Template<double> GetVector2_64_Zero()
{
    return GetVector2_ZeroTemplate<double>();
}

inline Vector2Template<double> GetVector2_64_One()
{
    return GetVector2_OneTemplate<double>();
}

inline Vector2Template<double> GetVector2_64_XAxis()
{
    return GetVector2_XAxisTemplate<double>();
}

inline Vector2Template<double> GetVector2_64_YAxis()
{
    return GetVector2_YAxisTemplate<double>();
}


inline Vector3Template<double> GetVector3_64_Zero()
{
    return GetVector3_ZeroTemplate<double>();
}

inline Vector3Template<double> GetVector3_64_One()
{
    return GetVector3_OneTemplate<double>();
}

inline Vector3Template<double> GetVector3_64_XAxis()
{
    return GetVector3_XAxisTemplate<double>();
}

inline Vector3Template<double> GetVector3_64_YAxis()
{
    return GetVector3_YAxisTemplate<double>();
}

inline Vector3Template<double> GetVector3_64_ZAxis()
{
    return GetVector3_ZAxisTemplate<double>();
}

inline Vector4Template<double> GetVector4_64_Zero()
{
    return GetVector4_ZeroTemplate<double>();
}

inline Vector4Template<double> GetVector4_64_One()
{
    return GetVector4_OneTemplate<double>();
}

inline Vector4Template<double> GetVector4_64_Origin()
{
    return GetVector4_OriginTemplate<double>();
}

inline Vector4Template<double> GetVector4_64_XAxis()
{
    return GetVector4_XAxisTemplate<double>();
}

inline Vector4Template<double> GetVector4_64_YAxis()
{
    return GetVector4_YAxisTemplate<double>();
}

inline Vector4Template<double> GetVector4_64_ZAxis()
{
    return GetVector4_ZAxisTemplate<double>();
}

inline Vector4Template<double> GetVector4_64_WAxis()
{
    return GetVector4_WAxisTemplate<double>();
}

inline Matrix33Template<double> GetMatrix33_64_Identity()
{
    return GetMatrix33_IdentityTemplate<double>();
}

inline Matrix33Template<double> GetMatrix33_64_Zero()
{
    return GetMatrix33_ZeroTemplate<double>();
}

inline Matrix44Template<double> GetMatrix44_64_Identity()
{
    return GetMatrix44_IdentityTemplate<double>();
}

inline Matrix44AffineTemplate<double> GetMatrix44Affine_64_Identity()
{
    return GetMatrix44Affine_IdentityTemplate<double>();
}

inline Matrix44Template<double> GetMatrix44_64_Zero()
{
    return GetMatrix44_ZeroTemplate<double>();
}

inline Matrix44AffineTemplate<double> GetMatrix44Affine_64_Zero()
{
    return GetMatrix44Affine_ZeroTemplate<double>();
}

inline QuaternionTemplate<double> GetQuaternion_64_Identity()
{
    return GetQuaternion_IdentityTemplate<double>();
}


inline QuaternionTemplate<double> GetQuaternion_64_Zero()
{
    return GetQuaternion_ZeroTemplate<double>();
}

inline QuaternionTemplate<double> GetQuaternion_64_One()
{
    return GetQuaternion_OneTemplate<double>();
}

inline QuatPosTemplate<double> GetQuatPos_64_Identity()
{
    return GetQuatPos_IdentityTemplate<double>();
}

inline QuatPosTemplate<double> GetQuatPos_64_Zero()
{
    return GetQuatPos_ZeroTemplate<double>();
}


inline Vector2Template<float> GetVector2U_32_Zero()
{
    return GetVector2_ZeroTemplate<float>();
}

inline Vector2Template<float> GetVector2U_32_One()
{
    return GetVector2_OneTemplate<float>();
}

inline Vector2Template<float> GetVector2U_32_XAxis()
{
    return GetVector2_XAxisTemplate<float>();
}

inline Vector2Template<float> GetVector2U_32_YAxis()
{
    return GetVector2_YAxisTemplate<float>();
}


inline Vector3Template<float> GetVector3U_32_Zero()
{
    return GetVector3_ZeroTemplate<float>();
}

inline Vector3Template<float> GetVector3U_32_One()
{
    return GetVector3_OneTemplate<float>();
}

inline Vector3Template<float> GetVector3U_32_XAxis()
{
    return GetVector3_XAxisTemplate<float>();
}

inline Vector3Template<float> GetVector3U_32_YAxis()
{
    return GetVector3_YAxisTemplate<float>();
}

inline Vector3Template<float> GetVector3U_32_ZAxis()
{
    return GetVector3_ZAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4U_32_Zero()
{
    return GetVector4_ZeroTemplate<float>();
}

inline Vector4Template<float> GetVector4U_32_One()
{
    return GetVector4_OneTemplate<float>();
}

inline Vector4Template<float> GetVector4U_32_Origin()
{
    return GetVector4_OriginTemplate<float>();
}

inline Vector4Template<float> GetVector4U_32_XAxis()
{
    return GetVector4_XAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4U_32_YAxis()
{
    return GetVector4_YAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4U_32_ZAxis()
{
    return GetVector4_ZAxisTemplate<float>();
}

inline Vector4Template<float> GetVector4U_32_WAxis()
{
    return GetVector4_WAxisTemplate<float>();
}

inline Matrix33Template<float> GetMatrix33U_32_Identity()
{
    return GetMatrix33_IdentityTemplate<float>();
}

inline Matrix33Template<float> GetMatrix33U_32_Zero()
{
    return GetMatrix33_ZeroTemplate<float>();
}

inline Matrix44Template<float> GetMatrix44U_32_Identity()
{
    return GetMatrix44_IdentityTemplate<float>();
}

inline Matrix44AffineTemplate<float> GetMatrix44AffineU_32_Identity()
{
    return GetMatrix44Affine_IdentityTemplate<float>();
}

inline Matrix44Template<float> GetMatrix44U_32_Zero()
{
    return GetMatrix44_ZeroTemplate<float>();
}

inline Matrix44AffineTemplate<float> GetMatrix44AffineU_32_Zero()
{
    return GetMatrix44Affine_ZeroTemplate<float>();
}

inline QuaternionTemplate<float> GetQuaternionU_32_Identity()
{
    return GetQuaternion_IdentityTemplate<float>();
}

inline QuaternionTemplate<float> GetQuaternionU_32_Zero()
{
    return GetQuaternion_ZeroTemplate<float>();
}

inline QuaternionTemplate<float> GetQuaternionU_32_One()
{
    return GetQuaternion_OneTemplate<float>();
}

inline QuatPosTemplate<float> GetQuatPosU_32_Identity()
{
    return GetQuatPos_IdentityTemplate<float>();
}

inline QuatPosTemplate<float> GetQuatPosU_32_Zero()
{
    return GetQuatPos_ZeroTemplate<float>();
}


inline Vector2Template<double> GetVector2U_64_Zero()
{
    return GetVector2_ZeroTemplate<double>();
}

inline Vector2Template<double> GetVector2U_64_One()
{
    return GetVector2_OneTemplate<double>();
}

inline Vector2Template<double> GetVector2U_64_XAxis()
{
    return GetVector2_XAxisTemplate<double>();
}

inline Vector2Template<double> GetVector2U_64_YAxis()
{
    return GetVector2_YAxisTemplate<double>();
}


inline Vector3Template<double> GetVector3U_64_Zero()
{
    return GetVector3_ZeroTemplate<double>();
}

inline Vector3Template<double> GetVector3U_64_One()
{
    return GetVector3_OneTemplate<double>();
}

inline Vector3Template<double> GetVector3U_64_XAxis()
{
    return GetVector3_XAxisTemplate<double>();
}

inline Vector3Template<double> GetVector3U_64_YAxis()
{
    return GetVector3_YAxisTemplate<double>();
}

inline Vector3Template<double> GetVector3U_64_ZAxis()
{
    return GetVector3_ZAxisTemplate<double>();
}

inline Vector4Template<double> GetVector4U_64_Zero()
{
    return GetVector4_ZeroTemplate<double>();
}

inline Vector4Template<double> GetVector4U_64_One()
{
    return GetVector4_OneTemplate<double>();
}

inline Vector4Template<double> GetVector4U_64_Origin()
{
    return GetVector4_OriginTemplate<double>();
}

inline Vector4Template<double> GetVector4U_64_XAxis()
{
    return GetVector4_XAxisTemplate<double>();
}

inline Vector4Template<double> GetVector4U_64_YAxis()
{
    return GetVector4_YAxisTemplate<double>();
}

inline Vector4Template<double> GetVector4U_64_ZAxis()
{
    return GetVector4_ZAxisTemplate<double>();
}

inline Vector4Template<double> GetVector4U_64_WAxis()
{
    return GetVector4_WAxisTemplate<double>();
}

inline Matrix33Template<double> GetMatrix33U_64_Identity()
{
    return GetMatrix33_IdentityTemplate<double>();
}

inline Matrix33Template<double> GetMatrix33U_64_Zero()
{
    return GetMatrix33_ZeroTemplate<double>();
}

inline Matrix44Template<double> GetMatrix44U_64_Identity()
{
    return GetMatrix44_IdentityTemplate<double>();
}

inline Matrix44AffineTemplate<double> GetMatrix44AffineU_64_Identity()
{
    return GetMatrix44Affine_IdentityTemplate<double>();
}

inline Matrix44Template<double> GetMatrix44U_64_Zero()
{
    return GetMatrix44_ZeroTemplate<double>();
}

inline Matrix44AffineTemplate<double> GetMatrix44AffineU_64_Zero()
{
    return GetMatrix44Affine_ZeroTemplate<double>();
}


inline QuaternionTemplate<double> GetQuaternionU_64_Identity()
{
    return GetQuaternion_IdentityTemplate<double>();
}

inline QuaternionTemplate<double> GetQuaternionU_64_Zero()
{
    return GetQuaternion_ZeroTemplate<double>();
}

inline QuaternionTemplate<double> GetQuaternionU_64_One()
{
    return GetQuaternion_OneTemplate<double>();
}

inline QuatPosTemplate<double> GetQuatPosU_64_Identity()
{
    return GetQuatPos_IdentityTemplate<double>();
}

inline QuatPosTemplate<double> GetQuatPosU_64_Zero()
{
    return GetQuatPos_ZeroTemplate<double>();
}

}
}
}
