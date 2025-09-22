





















#include <rw/graphics/core/drvvertexiterator.h>

namespace rw
{
namespace graphics
{
namespace core
{































template<class DT1, class DT2>
class VertexIterator2 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2> inline void Write(const ST1 &val1, const ST2 &val2)
   {
       ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
   }
   template<class ST1, class ST2> inline void Read(ST1 &val1, ST2 &val2)
   {
       ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2);
   };
};


template<class DT1, class DT2, class DT3>
class VertexIterator3 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3)
   {
       ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
   }
   template<class ST1, class ST2, class ST3>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3)
   {
       ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3);
   };
};


template<class DT1, class DT2, class DT3, class DT4>
class VertexIterator4 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4)
   {
       ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
   }
   template<class ST1, class ST2, class ST3, class ST4>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4)
   {
       ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4);
   };
};


template<class DT1, class DT2, class DT3, class DT4, class DT5>
class VertexIterator5 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5)
   {
       ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
       ((VertexIterator<DT5> *)this)->Write<ST5>(val5);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5)
   {
       ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
       ((VertexIterator<DT5> *)this)->Read<ST5>(val5);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5);
   };
};


template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6>
class VertexIterator6 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5, const ST6 &val6)
   {
       ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
       ((VertexIterator<DT5> *)this)->Write<ST5>(val5);
       ((VertexIterator<DT6> *)this)->Write<ST6>(val6);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6)
   {
       ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
       ((VertexIterator<DT5> *)this)->Read<ST5>(val5);
       ((VertexIterator<DT6> *)this)->Read<ST6>(val6);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6);
   };
};


template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7>
class VertexIterator7 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5, const ST6 &val6, const ST7 &val7)
   {
       ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
       ((VertexIterator<DT5> *)this)->Write<ST5>(val5);
       ((VertexIterator<DT6> *)this)->Write<ST6>(val6);
       ((VertexIterator<DT7> *)this)->Write<ST7>(val7);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7)
   {
       ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
       ((VertexIterator<DT5> *)this)->Read<ST5>(val5);
       ((VertexIterator<DT6> *)this)->Read<ST6>(val6);
       ((VertexIterator<DT7> *)this)->Read<ST7>(val7);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7);
   };
};

template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8>
class VertexIterator8 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8)
   {
       ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
       ((VertexIterator<DT5> *)this)->Write<ST5>(val5);
       ((VertexIterator<DT6> *)this)->Write<ST6>(val6);
       ((VertexIterator<DT7> *)this)->Write<ST7>(val7);
       ((VertexIterator<DT8> *)this)->Write<ST8>(val8);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8)
   {
       ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
       ((VertexIterator<DT5> *)this)->Read<ST5>(val5);
       ((VertexIterator<DT6> *)this)->Read<ST6>(val6);
       ((VertexIterator<DT7> *)this)->Read<ST7>(val7);
       ((VertexIterator<DT8> *)this)->Read<ST8>(val8);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8);
   };
};


template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9>
class VertexIterator9 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                         const ST9 &val9)
   {
       ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
       ((VertexIterator<DT5> *)this)->Write<ST5>(val5);
       ((VertexIterator<DT6> *)this)->Write<ST6>(val6);
       ((VertexIterator<DT7> *)this)->Write<ST7>(val7);
       ((VertexIterator<DT8> *)this)->Write<ST8>(val8);
       ((VertexIterator<DT9> *)this)->Write<ST9>(val9);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8, ST9 &val9)
   {
       ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
       ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
       ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
       ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
       ((VertexIterator<DT5> *)this)->Read<ST5>(val5);
       ((VertexIterator<DT6> *)this)->Read<ST6>(val6);
       ((VertexIterator<DT7> *)this)->Read<ST7>(val7);
       ((VertexIterator<DT8> *)this)->Read<ST8>(val8);
       ((VertexIterator<DT9> *)this)->Read<ST9>(val9);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8)
                + sizeof(DT9);
   };
};


template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10>
class VertexIterator10 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                         const ST9 &val9, const ST10 &val10)
   {
       ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10)
   {
       ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8)
                + sizeof(DT9) + sizeof(DT10);
   };
};


template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11>
class VertexIterator11 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                         const ST9 &val9, const ST10 &val10, const ST11 &val11)
   {
       ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11)
   {
       ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8)
                + sizeof(DT9) + sizeof(DT10) + sizeof(DT11);
   };
};


template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11, class DT12>
class VertexIterator12 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                         const ST9 &val9, const ST10 &val10, const ST11 &val11, const ST12 &val12)
   {
       ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
       ((VertexIterator<DT12> *)this)->Write<ST12>(val12);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11, ST12 &val12)
   {
       ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
       ((VertexIterator<DT12> *)this)->Read<ST12>(val12);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8)
                + sizeof(DT9) + sizeof(DT10) + sizeof(DT11) + sizeof(DT12);
   };
};

template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11, class DT12, class DT13>
class VertexIterator13 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                         const ST9 &val9, const ST10 &val10, const ST11 &val11, const ST12 &val12,
                         const ST13 &val13)
   {
       ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
       ((VertexIterator<DT12> *)this)->Write<ST12>(val12);
       ((VertexIterator<DT13> *)this)->Write<ST13>(val13);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11, ST12 &val12, ST13 &val13)
   {
       ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
       ((VertexIterator<DT12> *)this)->Read<ST12>(val12);
       ((VertexIterator<DT13> *)this)->Read<ST13>(val13);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8)
                + sizeof(DT9) + sizeof(DT10) + sizeof(DT11) + sizeof(DT12) + sizeof(DT13);
   };
};

template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11, class DT12, class DT13, class DT14>
class VertexIterator14 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                         const ST9 &val9, const ST10 &val10, const ST11 &val11, const ST12 &val12,
                         const ST13 &val13, const ST14 &val14)
   {
       ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
       ((VertexIterator<DT12> *)this)->Write<ST12>(val12);
       ((VertexIterator<DT13> *)this)->Write<ST13>(val13);
       ((VertexIterator<DT14> *)this)->Write<ST14>(val14);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11, ST12 &val12, ST13 &val13, ST14 &val14)
   {
       ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
       ((VertexIterator<DT12> *)this)->Read<ST12>(val12);
       ((VertexIterator<DT13> *)this)->Read<ST13>(val13);
       ((VertexIterator<DT14> *)this)->Read<ST14>(val14);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8)
                + sizeof(DT9) + sizeof(DT10) + sizeof(DT11) + sizeof(DT12) + sizeof(DT13) + sizeof(DT14);
   };
};


template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11, class DT12, class DT13, class DT14, class DT15>
class VertexIterator15 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14, class ST15>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                         const ST9 &val9, const ST10 &val10, const ST11 &val11, const ST12 &val12,
                         const ST13 &val13, const ST14 &val14, const ST15 &val15)
   {
       ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
       ((VertexIterator<DT12> *)this)->Write<ST12>(val12);
       ((VertexIterator<DT13> *)this)->Write<ST13>(val13);
       ((VertexIterator<DT14> *)this)->Write<ST14>(val14);
       ((VertexIterator<DT15> *)this)->Write<ST15>(val15);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14, class ST15>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11, ST12 &val12, ST13 &val13, ST14 &val14, ST15 &val15)
   {
       ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
       ((VertexIterator<DT12> *)this)->Read<ST12>(val12);
       ((VertexIterator<DT13> *)this)->Read<ST13>(val13);
       ((VertexIterator<DT14> *)this)->Read<ST14>(val14);
       ((VertexIterator<DT15> *)this)->Read<ST15>(val15);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8)
                + sizeof(DT9) + sizeof(DT10) + sizeof(DT11) + sizeof(DT12) + sizeof(DT13) + sizeof(DT14) + sizeof(DT15);
   };
};


template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11, class DT12, class DT13, class DT14, class DT15, class DT16>
class VertexIterator16 : public VertexIteratorBaseClass
{
public:
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14, class ST15, class ST16>
       inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                         const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                         const ST9 &val9, const ST10 &val10, const ST11 &val11, const ST12 &val12,
                         const ST13 &val13, const ST14 &val14, const ST15 &val15, const ST16 &val16)
   {
       ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
       ((VertexIterator<DT12> *)this)->Write<ST12>(val12);
       ((VertexIterator<DT13> *)this)->Write<ST13>(val13);
       ((VertexIterator<DT14> *)this)->Write<ST14>(val14);
       ((VertexIterator<DT15> *)this)->Write<ST15>(val15);
       ((VertexIterator<DT16> *)this)->Write<ST16>(val16);
   }
   template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14, class ST15, class ST16>
       inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11, ST12 &val12, ST13 &val13, ST14 &val14, ST15 &val15, ST16 &val16)
   {
       ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
       ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
       ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
       ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
       ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
       ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
       ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
       ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
       ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
       ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
       ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
       ((VertexIterator<DT12> *)this)->Read<ST12>(val12);
       ((VertexIterator<DT13> *)this)->Read<ST13>(val13);
       ((VertexIterator<DT14> *)this)->Read<ST14>(val14);
       ((VertexIterator<DT15> *)this)->Read<ST15>(val15);
       ((VertexIterator<DT16> *)this)->Read<ST16>(val16);
   }
   static inline uint32_t GetStride()
   {
       return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8)
                + sizeof(DT9) + sizeof(DT10) + sizeof(DT11) + sizeof(DT12) + sizeof(DT13) + sizeof(DT14) + sizeof(DT15) + sizeof(DT16);
   };
};



class UserVertexIterator : public VertexIteratorBaseClass
{
public:
    void *GetBuffer()
    {
        return m_dest;
    }

    void IncrementBuffer(size_t inc)
    {
        m_dest = reinterpret_cast<void*>(reinterpret_cast<uint8_t *>(m_dest) + inc);
    }
};


class StrideVertexIterator : public VertexIteratorBaseClass
{
public:
    StrideVertexIterator( VertexDescriptor& vbDesc )
    : m_vbDesc ( vbDesc )
    {
    }

    void *GetBuffer()
    {
        ;
        return m_dest;
    }

    uint32_t GetStride() const
    {
        ;
        return m_vbDesc.GetStride();
    }

    void RestartAtElementOffset( VertexBuffer::BatchIterator& batchIt, uint32_t elementIndex )
    {
        ;
        m_dest = reinterpret_cast<void*>(reinterpret_cast<uint8_t*>(batchIt.GetLockedBuffer()) + m_vbDesc.GetElements()[elementIndex].offset );
        return;
    }

    void Increment()
    {
        ;
        m_dest = reinterpret_cast<void*>(reinterpret_cast<uint8_t *>(m_dest) + m_vbDesc.GetStride() );
        return;
    }

protected:
    StrideVertexIterator& operator=(const StrideVertexIterator& p)
    {
        ;
        return *this = p;
    }

protected:
    VertexDescriptor& m_vbDesc;
};


}
}
}
