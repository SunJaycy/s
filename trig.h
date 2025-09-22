












namespace rw {
namespace math {
namespace fpu {

template <class T> inline T DegToRad(T angle_degrees)
{
    return angle_degrees * DEGREES_TO_RADIANS;
}

template <class T> inline T RadToDeg(T angle_radians)
{
    return angle_radians * RADIANS_TO_DEGREES;
}

template <class T> inline T Sin(T a)
{
    return Sin(a);
}
template <> inline float Sin<float>(float a) { return sinf(a); }
template <> inline double Sin<double>(double a) { return sin(a); }

template <class T> inline T Cos(T a)
{
    return Cos(a);
}
template <> inline float Cos<float>(float a) { return cosf(a); }
template <> inline double Cos<double>(double a) { return cos(a); }

template <class T> inline T Tan(T a)
{
    return Tan(a);
}
template <> inline float Tan<float>(float a) { return tanf(a); }
template <> inline double Tan<double>(double a) { return tan(a); }

template <class T> inline T ASin(T a)
{
    return ASin(a);
}
template <> inline float ASin<float>(float a) { return asinf(a); }
template <> inline double ASin<double>(double a) { return asin(a); }

template <class T> inline T ACos(T a)
{
    return ACos(a);
}
template <> inline float ACos<float>(float a) { return acosf(a); }
template <> inline double ACos<double>(double a) { return acos(a); }

template <class T> inline T ATan(T a)
{
    return ATan(a);
}
template <> inline float ATan<float>(float a) { return atanf(a); }
template <> inline double ATan<double>(double a) { return atan(a); }

template <class T> inline T ATan2(T a, T b)
{
    return ATan2(a);
}
template <> inline float ATan2<float>(float a, float b)
{









    return atan2f(a, b);
}

template <> inline double ATan2<double>(double a, double b)
{









    return atan2(a, b);
}


template <class T>
inline T NormalizeAngle(T a)
{
    return (T)NormalizeAngle((double)a);
}

template <>
inline double NormalizeAngle(double a)
{
    using namespace detail;
    double scaledAngle = a * (1.0f/TWO_PI);
    double scaledAnglePlusHalf = scaledAngle + 0.5f;
    double scaledAngleMinusHalf = scaledAngle - 0.5f;
    double scaledAngleMinusOne = scaledAngle - 1.0f;
    double truncatedAngle = fcfid(fctiwz(scaledAngle));
    double fractionalAngle = scaledAngle - truncatedAngle;
    double wrapGreater = __fsel( scaledAngleMinusHalf - truncatedAngle, scaledAngleMinusOne - truncatedAngle, fractionalAngle );
    double addLess = __fsel( truncatedAngle-scaledAnglePlusHalf, TWO_PI, 0.0f );
    return __fmadd( wrapGreater, TWO_PI, addLess );
}

































template <class T> inline void SinCos(T a, T& sin_out, T& cos_out)
{
    sin_out = Sin(a);
    cos_out = Cos(a);
}
template <class T> inline Vector4Template<T> SinCos(T a)
{
    return Vector4Template<T>( Sin(a), Cos(a), 0.0f, 0.0f );
}
template <class T> inline Vector4Template<T> SinCosFast(T a)
{
    return SinCos<T>(a);
}
template <class T> inline Vector4Template<T> SinCosFast2(T a, T b)
{
    return Vector4Template<T>( Sin(a), Cos(a), Sin(b), Cos(b) );
}

}

}

}
