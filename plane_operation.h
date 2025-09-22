




#include <rw/math/fpu/plane.h>






namespace rw {
namespace math {
namespace fpu {

template <class T> bool operator ==(const PlaneTemplate<T>& a, const PlaneTemplate<T>& b)
{
    return (a.a==b.a && a.b==b.b && a.c==b.c && a.d==b.d);
}

template <class T> bool operator !=(const PlaneTemplate<T>& a, const PlaneTemplate<T>& b)
{
    return !(a==b);
}

template <class T> bool IsSimilar(const PlaneTemplate<T>& a, const PlaneTemplate<T>& b, T epsilon = SMALL_FLOAT)
{
    return (Abs(a.a-b.a) <= epsilon &&
            Abs(a.b-b.b) <= epsilon &&
            Abs(a.c-b.c) <= epsilon &&
            Abs(a.d-b.d) <= epsilon);
}


template <class T> void SetZero(PlaneTemplate<T>& v)
{
    v.Set(0.0f, 0.0f, 0.0f, 0.0f);
}

template<class T>
bool IsAnyNaN(const PlaneTemplate<T>& p)
{
    return (bool)(IsNaN(p.a) | IsNaN(p.b) | IsNaN(p.c) | IsNaN(p.d));
}

template <class T> PlaneTemplate<T> PlaneFromPosNormal(const Vector3Template<T>& pos, const Vector3Template<T>& normal)
{
    return PlaneTemplate<T>( normal, -Dot(normal, pos) );
}
template <class T> PlaneTemplate<T> PlaneFromPosNormal(const Vector4Template<T>& pos, const Vector4Template<T>& normal)
{
    return PlaneFromPosNormal(Vector3Template<T>(pos.x, pos.y, pos.z), Vector3Template<T>(normal.x, normal.y, normal.z));
}
template <class T> PlaneTemplate<T> PlaneFromVertices(const Vector3Template<T>& origin, const Vector3Template<T>& vert1, const Vector3Template<T>& vert2)
{
    Vector3Template<T> normal = Normalize( Cross(vert1-origin, vert2-origin) );
    return PlaneTemplate<T>( normal, -Dot(normal, origin) );
}
template <class T> PlaneTemplate<T> PlaneFromVertices(const Vector4Template<T>& origin, const Vector4Template<T>& vert1, const Vector4Template<T>& vert2)
{
    return PlaneFromVertices(Vector3Template<T>(origin.x, origin.y, origin.z), Vector3Template<T>(vert1.x, vert1.y, vert1.z), Vector3Template<T>(vert2.x, vert2.y, vert2.z));
}
template <class T> PlaneTemplate<T> PlaneFromVectors(const Vector3Template<T>& origin, const Vector3Template<T>& vec1, const Vector3Template<T>& vec2)
{
    Vector3Template<T> normal = Normalize( Cross(vec1, vec2) );
    return PlaneTemplate<T>( normal, -Dot(normal, origin) );
}
template <class T> PlaneTemplate<T> PlaneFromVectors(const Vector4Template<T>& origin, const Vector4Template<T>& vec1, const Vector4Template<T>& vec2)
{
    return PlaneFromVectors(Vector3Template<T>(origin.x, origin.y, origin.z), Vector3Template<T>(vec1.x, vec1.y, vec1.z), Vector3Template<T>(vec2.x, vec2.y, vec2.z));
}

template <class T> PlaneIntersection IntersectPlaneLine(const PlaneTemplate<T> &plane, const Vector3Template<T> &p0, const Vector3Template<T> &p1, Vector3Template<T> &impact_out, T epsilon = 0.0f )
{
    Vector3Template<T> dif = p1-p0;
    T dn = Dot(plane.GetNormal(),dif);
    if (Abs(dn) <= epsilon)
    {


        T testValue = plane.a * p0.x + plane.b * p0.y + plane.c * p0.z + plane.d;
        if( Abs(testValue) <= epsilon )
        {
            return PI_INFINITY;
        }
        else
        {

            return PI_ZERO;
        }
    }
    T t = -(plane.SignedDistance()+Dot(plane.GetNormal(),p0) )/dn;
    impact_out = p0 + (dif*t);

    return PI_ONE;
}
template <class T> PlaneIntersection IntersectPlaneDirectedSegment(const PlaneTemplate<T> &plane, const Vector3Template<T> &p0, const Vector3Template<T> &p1, Vector3Template<T> &impact_out, T epsilon = 0.0f )
{
    Vector3Template<T> dif = p1-p0;
    T dn = Dot(plane.GetNormal(),dif);
    if (Abs(dn) <= epsilon)
    {


        T testValue = plane.a * p0.x + plane.b * p0.y + plane.c * p0.z + plane.d;
        if( Abs(testValue) <= epsilon )
        {
            return PI_INFINITY;
        }
        else
        {

            return PI_ZERO;
        }
    }
    T t = -(plane.SignedDistance()+Dot(plane.GetNormal(),p0) )/dn;
    if (t < 0.0f || t > 1.0f)
    {

        return PI_ZERO;
    }
    impact_out = p0 + (dif*t);

    return PI_ONE;
}
template <class T> PlaneTemplate<T> TransformPlane(const Matrix44Template<T> &m, const PlaneTemplate<T> p)
{
    ;

    Vector3Template<T> normal = Mult3x3(p.GetNormal(),m);
    T d = p.SignedDistance() - Dot(GetXYZ(m.wAxis),normal);

    return PlaneTemplate<T>(normal, d);
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompLessEqual(const PlaneTemplate<T> &a, const PlaneTemplate<T> &b)
{
    return Mask4Template<T>(
            b.a-a.a,
            b.b-a.b,
            b.c-a.c,
            b.d-a.d
            );
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompGreaterEqual(const PlaneTemplate<T> &a, const PlaneTemplate<T> &b)
{
    return Mask4Template<T>(
            a.a-b.a,
            a.b-b.b,
            a.c-b.c,
            a.d-b.d
            );
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompLessThan(const PlaneTemplate<T> &a, const PlaneTemplate<T> &b)
{
    return Not(CompGreaterEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompGreaterThan(const PlaneTemplate<T> &a, const PlaneTemplate<T> &b)
{
    return Not(CompLessEqual(a, b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompEqual(const PlaneTemplate<T> &a, const PlaneTemplate<T> &b)
{
    return And(CompLessEqual(a, b), CompGreaterEqual(a,b));
}

template <class T>
inline __attribute__ ((always_inline)) Mask4Template<T> CompNotEqual(const PlaneTemplate<T> &a, const PlaneTemplate<T> &b)
{
    return Not(And(CompLessEqual(a, b), CompGreaterEqual(a,b)));
}

template <class T>
inline __attribute__ ((always_inline)) PlaneTemplate<T> Select(const MaskScalarTemplate<T> &mask, const PlaneTemplate<T> &trueValue, const PlaneTemplate<T> &falseValue )
{
    return PlaneTemplate<T>(
            (T)__fsel((mask.mS), (trueValue.a), (falseValue.a)),
            (T)__fsel((mask.mS), (trueValue.b), (falseValue.b)),
            (T)__fsel((mask.mS), (trueValue.c), (falseValue.c)),
            (T)__fsel((mask.mS), (trueValue.d), (falseValue.d))
        );
}

template <class T>
inline __attribute__ ((always_inline)) PlaneTemplate<T> Select(const Mask4Template<T> &mask, const PlaneTemplate<T> &trueValue, const PlaneTemplate<T> &falseValue )
{
    return PlaneTemplate<T>(
            (T)__fsel((mask.mX), (trueValue.a), (falseValue.a)),
            (T)__fsel((mask.mY), (trueValue.b), (falseValue.b)),
            (T)__fsel((mask.mZ), (trueValue.c), (falseValue.c)),
            (T)__fsel((mask.mW), (trueValue.d), (falseValue.d))
        );
}





template <class T> void TransformPlane(const Matrix44Template<T> &m, const PlaneTemplate<T> &p, PlaneTemplate<T> &result)
{
    result = TransformPlane(m, p);
}



template<class T> inline T Distance(const PlaneTemplate<T>& p, const Vector3Template<T>& v) { return p.a * v.x + p.b * v.y + p.c * v.z + p.d; }
template<class T> inline T Distance(const PlaneTemplate<T>& p, const Vector4Template<T>& v) { return p.a * v.x + p.b * v.y + p.c * v.z + p.d; }
template<class T> inline T Distance(const Vector3Template<T>& v, const PlaneTemplate<T>& p) { return p.a * v.x + p.b * v.y + p.c * v.z + p.d; }
template<class T> inline T Distance(const Vector4Template<T>& v, const PlaneTemplate<T>& p) { return p.a * v.x + p.b * v.y + p.c * v.z + p.d; }

}

}

}
