






namespace rw {
namespace math {
namespace fpu {

    typedef float VecFloat;
    typedef float& VecFloatRefX;
    typedef float& VecFloatRefY;
    typedef float& VecFloatRefZ;
    typedef float& VecFloatRefW;
    typedef float& VecFloatRefIndex;

    inline __attribute__ ((always_inline)) float GetFloat(float f);
    inline __attribute__ ((always_inline)) float GetFloat(float f) { return f; }

}}}
