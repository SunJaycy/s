




#include <ppu_intrinsics.h>

namespace rw
{

namespace math
{

namespace fpu
{

namespace detail
{



inline float fcfid(float x) {
  float r;
  asm("fcfid %0,%1" : "=f"(r) : "f"(x));
  return r;
}

inline double fcfid(double x) {
  float r;
  asm("fcfid %0,%1" : "=f"(r) : "f"(x));
  return r;
}

inline float fctiwz(float x) {
  float r;
  asm("fctiwz %0,%1" : "=f"(r) : "f"(x));
  return r;
}

inline double fctiwz(double x) {
  double r;
  asm("fctiwz %0,%1" : "=f"(r) : "f"(x));
  return r;
}

}

}

}

}
