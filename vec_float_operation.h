







namespace rw {
namespace math {
namespace vpu {


template<VectorAxis INDEX> inline __attribute__ ((always_inline)) VecFloat Negate(VecFloatRef<INDEX> a);
                           inline __attribute__ ((always_inline)) VecFloat Negate(VecFloat::InParam a);
                           inline __attribute__ ((always_inline)) VecFloat Negate(VecFloatRefIndex::InParam a);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfAdd(VecFloatRef<INDEX1> &a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfAdd(VecFloatRef<INDEX1> &a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfAdd(VecFloatRef<INDEX1> &a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfAdd(VecFloatRef<INDEX1> &a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat& SelfAdd(VecFloat& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfAdd(VecFloat& a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfAdd(VecFloat& a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfAdd(VecFloat& a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfAdd(VecFloatRefIndex& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfAdd(VecFloatRefIndex& a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfAdd(VecFloatRefIndex& a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfAdd(VecFloatRefIndex& a, const float& b);
                                               inline __attribute__ ((always_inline)) float& SelfAdd(float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) float& SelfAdd(float& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) float& SelfAdd(float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfSubtract(VecFloatRef<INDEX1> &a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfSubtract(VecFloatRef<INDEX1> &a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfSubtract(VecFloatRef<INDEX1> &a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfSubtract(VecFloatRef<INDEX1> &a, const float& b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfSubtract(VecFloat& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat& SelfSubtract(VecFloat& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfSubtract(VecFloat& a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfSubtract(VecFloat& a, const float& b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfSubtract(VecFloatRefIndex& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfSubtract(VecFloatRefIndex& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfSubtract(VecFloatRefIndex& a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfSubtract(VecFloatRefIndex& a, const float& b);
                                               inline __attribute__ ((always_inline)) float& SelfSubtract(float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) float& SelfSubtract(float& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) float& SelfSubtract(float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfMult(VecFloatRef<INDEX1> &a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfMult(VecFloatRef<INDEX1> &a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfMult(VecFloatRef<INDEX1> &a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfMult(VecFloatRef<INDEX1> &a, const float& b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfMult(VecFloat& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat& SelfMult(VecFloat& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfMult(VecFloat& a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfMult(VecFloat& a, const float& b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfMult(VecFloatRefIndex& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfMult(VecFloatRefIndex& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfMult(VecFloatRefIndex& a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfMult(VecFloatRefIndex& a, const float& b);
                                               inline __attribute__ ((always_inline)) float& SelfMult(float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) float& SelfMult(float& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) float& SelfMult(float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfDivide(VecFloatRef<INDEX1> &a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfDivide(VecFloatRef<INDEX1> &a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfDivide(VecFloatRef<INDEX1> &a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRef<INDEX1>& SelfDivide(VecFloatRef<INDEX1> &a, const float& b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfDivide(VecFloat& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat& SelfDivide(VecFloat& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfDivide(VecFloat& a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat& SelfDivide(VecFloat& a, const float& b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfDivide(VecFloatRefIndex& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfDivide(VecFloatRefIndex& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfDivide(VecFloatRefIndex& a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloatRefIndex& SelfDivide(VecFloatRefIndex& a, const float& b);
                                               inline __attribute__ ((always_inline)) float& SelfDivide(float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) float& SelfDivide(float& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) float& SelfDivide(float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloat Add(VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Add(VecFloatRef<INDEX1> a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Add(VecFloatRef<INDEX1> a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Add(VecFloatRef<INDEX1> a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Add(VecFloat::InParam a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Add(VecFloat::InParam a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Add(VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Add(VecFloat::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Add(VecFloatRefIndex::InParam a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Add(VecFloatRefIndex::InParam a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Add(VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Add(VecFloatRefIndex::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Add(const float& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Add(const float& a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Add(const float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloatRef<INDEX1> a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloatRef<INDEX1> a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloatRef<INDEX1> a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloat::InParam a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloat::InParam a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloat::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloatRefIndex::InParam a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloatRefIndex::InParam a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Subtract(VecFloatRefIndex::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Subtract(const float& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Subtract(const float& a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Subtract(const float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloat Mult(VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Mult(VecFloatRef<INDEX1> a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Mult(VecFloatRef<INDEX1> a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Mult(VecFloatRef<INDEX1> a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Mult(VecFloat::InParam a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Mult(VecFloat::InParam a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Mult(VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Mult(VecFloat::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Mult(VecFloatRefIndex::InParam a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Mult(VecFloatRefIndex::InParam a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Mult(VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Mult(VecFloatRefIndex::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Mult(const float& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Mult(const float& a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Mult(const float& a, VecFloatRefIndex::InParam b);



template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloat Divide(VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Divide(VecFloatRef<INDEX1> a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Divide(VecFloatRef<INDEX1> a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Divide(VecFloatRef<INDEX1> a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Divide(VecFloat::InParam a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Divide(VecFloat::InParam a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Divide(VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Divide(VecFloat::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Divide(VecFloatRefIndex::InParam a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Divide(VecFloatRefIndex::InParam a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Divide(VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Divide(VecFloatRefIndex::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat Divide(const float& a, VecFloatRef<INDEX1> b);
                                               inline __attribute__ ((always_inline)) VecFloat Divide(const float& a, VecFloat::InParam b);
                                               inline __attribute__ ((always_inline)) VecFloat Divide(const float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) bool operator ==(VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
                                                inline __attribute__ ((always_inline)) bool operator ==(VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator ==(VecFloat::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator ==(VecFloat::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator ==(VecFloatRef<INDEX> a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator ==(VecFloatRefIndex::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator ==(VecFloatRef<INDEX> a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator ==(VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator ==(VecFloatRefIndex::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator ==(const float& a, VecFloatRef<INDEX> b);
                                                inline __attribute__ ((always_inline)) bool operator ==(const float& a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator ==(const float& a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator ==(VecFloatRef<INDEX> a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator ==(VecFloatRefIndex::InParam a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator ==(VecFloat::InParam a, const float& b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) bool operator !=(VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
                                                inline __attribute__ ((always_inline)) bool operator !=(VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator !=(VecFloat::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator !=(VecFloat::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator !=(VecFloatRef<INDEX> a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator !=(VecFloatRefIndex::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator !=(VecFloatRef<INDEX> a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator !=(VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator !=(VecFloatRefIndex::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator !=(const float& a, VecFloatRef<INDEX> b);
                                                inline __attribute__ ((always_inline)) bool operator !=(const float& a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator !=(const float& a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator !=(VecFloatRef<INDEX> a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator !=(VecFloatRefIndex::InParam a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator !=(VecFloat::InParam a, const float& b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) bool operator >(VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
                                                inline __attribute__ ((always_inline)) bool operator >(VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator >(VecFloat::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >(VecFloat::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >(VecFloatRef<INDEX> a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >(VecFloatRefIndex::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >(VecFloatRef<INDEX> a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator >(VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator >(VecFloatRefIndex::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >(const float& a, VecFloatRef<INDEX> b);
                                                inline __attribute__ ((always_inline)) bool operator >(const float& a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator >(const float& a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >(VecFloatRef<INDEX> a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator >(VecFloatRefIndex::InParam a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator >(VecFloat::InParam a, const float& b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) bool operator <(VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
                                                inline __attribute__ ((always_inline)) bool operator <(VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator <(VecFloat::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <(VecFloat::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <(VecFloatRef<INDEX> a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <(VecFloatRefIndex::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <(VecFloatRef<INDEX> a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator <(VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator <(VecFloatRefIndex::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <(const float& a, VecFloatRef<INDEX> b);
                                                inline __attribute__ ((always_inline)) bool operator <(const float& a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator <(const float& a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <(VecFloatRef<INDEX> a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator <(VecFloatRefIndex::InParam a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator <(VecFloat::InParam a, const float& b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) bool operator >=(VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
                                                inline __attribute__ ((always_inline)) bool operator >=(VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator >=(VecFloat::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >=(VecFloat::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >=(VecFloatRef<INDEX> a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >=(VecFloatRefIndex::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >=(VecFloatRef<INDEX> a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator >=(VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator >=(VecFloatRefIndex::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >=(const float& a, VecFloatRef<INDEX> b);
                                                inline __attribute__ ((always_inline)) bool operator >=(const float& a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator >=(const float& a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator >=(VecFloatRef<INDEX> a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator >=(VecFloatRefIndex::InParam a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator >=(VecFloat::InParam a, const float& b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) bool operator <=(VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
                                                inline __attribute__ ((always_inline)) bool operator <=(VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator <=(VecFloat::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <=(VecFloat::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <=(VecFloatRef<INDEX> a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <=(VecFloatRefIndex::InParam a, VecFloatRef<INDEX> b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <=(VecFloatRef<INDEX> a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator <=(VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator <=(VecFloatRefIndex::InParam a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <=(const float& a, VecFloatRef<INDEX> b);
                                                inline __attribute__ ((always_inline)) bool operator <=(const float& a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) bool operator <=(const float& a, VecFloat::InParam b);
template<VectorAxis INDEX> inline __attribute__ ((always_inline)) bool operator <=(VecFloatRef<INDEX> a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator <=(VecFloatRefIndex::InParam a, const float& b);
                                                inline __attribute__ ((always_inline)) bool operator <=(VecFloat::InParam a, const float& b);


template<VectorAxis INDEX>
inline __attribute__ ((always_inline)) VecFloat operator - (VecFloatRef<INDEX> a);
inline __attribute__ ((always_inline)) VecFloat operator - (VecFloat::InParam a);
inline __attribute__ ((always_inline)) VecFloat operator - (VecFloatRefIndex::InParam a);



template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat& operator += (VecFloat& a, VecFloatRef<INDEX1> b);
                            inline __attribute__ ((always_inline)) VecFloat& operator += (VecFloat& a, VecFloat::InParam b);
                            inline __attribute__ ((always_inline)) VecFloat& operator += (VecFloat& a, VecFloatRefIndex::InParam b);
                            inline __attribute__ ((always_inline)) VecFloat& operator += (VecFloat& a, const float& b);
                            inline __attribute__ ((always_inline)) float& operator += (float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) float& operator += (float& a, VecFloatRef<INDEX1> b);
                            inline __attribute__ ((always_inline)) float& operator += (float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat& operator -= (VecFloat& a, VecFloatRef<INDEX1> b);
                            inline __attribute__ ((always_inline)) VecFloat& operator -= (VecFloat& a, VecFloat::InParam b);
                            inline __attribute__ ((always_inline)) VecFloat& operator -= (VecFloat& a, VecFloatRefIndex::InParam b);
                            inline __attribute__ ((always_inline)) VecFloat& operator -= (VecFloat& a, const float& b);
                            inline __attribute__ ((always_inline)) float& operator -= (float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) float& operator -= (float& a, VecFloatRef<INDEX1> b);
                            inline __attribute__ ((always_inline)) float& operator -= (float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat& operator *= (VecFloat& a, VecFloatRef<INDEX1> b);
                            inline __attribute__ ((always_inline)) VecFloat& operator *= (VecFloat& a, VecFloat::InParam b);
                            inline __attribute__ ((always_inline)) VecFloat& operator *= (VecFloat& a, VecFloatRefIndex::InParam b);
                            inline __attribute__ ((always_inline)) VecFloat& operator *= (VecFloat& a, const float& b);
                            inline __attribute__ ((always_inline)) float& operator *= (float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) float& operator *= (float& a, VecFloatRef<INDEX1> b);
                            inline __attribute__ ((always_inline)) float& operator *= (float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat& operator /= (VecFloat& a, VecFloatRef<INDEX1> b);
                            inline __attribute__ ((always_inline)) VecFloat& operator /= (VecFloat& a, VecFloat::InParam b);
                            inline __attribute__ ((always_inline)) VecFloat& operator /= (VecFloat& a, VecFloatRefIndex::InParam b);
                            inline __attribute__ ((always_inline)) VecFloat& operator /= (VecFloat& a, const float& b);
                            inline __attribute__ ((always_inline)) float& operator /= (float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) float& operator /= (float& a, VecFloatRef<INDEX1> b);
                            inline __attribute__ ((always_inline)) float& operator /= (float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloat operator + (VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator + (VecFloatRef<INDEX1> a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator + (VecFloatRef<INDEX1> a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator + (VecFloatRef<INDEX1> a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator + (VecFloat::InParam a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator + (VecFloat::InParam a, VecFloat::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator + (VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator + (VecFloat::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator + (VecFloatRefIndex::InParam a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator + (VecFloatRefIndex::InParam a, VecFloat::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator + (VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator + (VecFloatRefIndex::InParam a, const float& b);
                                                inline __attribute__ ((always_inline)) VecFloat operator + (const float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator + (const float& a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator + (const float& a, VecFloatRefIndex::InParam b);


template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloat operator - (VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator - (VecFloatRef<INDEX1> a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator - (VecFloatRef<INDEX1> a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator - (VecFloatRef<INDEX1> a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator - (VecFloat::InParam a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator - (VecFloat::InParam a, VecFloat::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator - (VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator - (VecFloat::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator - (VecFloatRefIndex::InParam a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator - (VecFloatRefIndex::InParam a, VecFloat::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator - (VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator - (VecFloatRefIndex::InParam a, const float& b);
                                                inline __attribute__ ((always_inline)) VecFloat operator - (const float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator - (const float& a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator - (const float& a, VecFloatRefIndex::InParam b);



template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloat operator * (VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator * (VecFloatRef<INDEX1> a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator * (VecFloatRef<INDEX1> a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator * (VecFloatRef<INDEX1> a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator * (VecFloat::InParam a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator * (VecFloat::InParam a, VecFloat::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator * (VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator * (VecFloat::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator * (VecFloatRefIndex::InParam a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator * (VecFloatRefIndex::InParam a, VecFloat::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator * (VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator * (VecFloatRefIndex::InParam a, const float& b);
                                                inline __attribute__ ((always_inline)) VecFloat operator * (const float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator * (const float& a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator * (const float& a, VecFloatRefIndex::InParam b);



template<VectorAxis INDEX1, VectorAxis INDEX2> inline __attribute__ ((always_inline)) VecFloat operator / (VecFloatRef<INDEX1> a, VecFloatRef<INDEX2> b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator / (VecFloatRef<INDEX1> a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator / (VecFloatRef<INDEX1> a, VecFloatRefIndex::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator / (VecFloatRef<INDEX1> a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator / (VecFloat::InParam a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator / (VecFloat::InParam a, VecFloat::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator / (VecFloat::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator / (VecFloat::InParam a, const float& b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator / (VecFloatRefIndex::InParam a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator / (VecFloatRefIndex::InParam a, VecFloat::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator / (VecFloatRefIndex::InParam a, VecFloatRefIndex::InParam b);
                                                inline __attribute__ ((always_inline)) VecFloat operator / (VecFloatRefIndex::InParam a, const float& b);
                                                inline __attribute__ ((always_inline)) VecFloat operator / (const float& a, VecFloat::InParam b);
template<VectorAxis INDEX1> inline __attribute__ ((always_inline)) VecFloat operator / (const float& a, VecFloatRef<INDEX1> b);
                                                inline __attribute__ ((always_inline)) VecFloat operator / (const float& a, VecFloatRefIndex::InParam b);


}}}


#include <rw/math/vpu/detail/vec_float_operation_inline.h>
