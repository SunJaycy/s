













namespace rw
{
    namespace core
    {
        namespace thread
        {

            template <class T>
            class AtomicInt
            {
            public:
                typedef T ValueType;




                AtomicInt()
                {
                    ;
                    return;
                }

                AtomicInt(ValueType n)
                {
                    ;
                    SetValue(n);
                    return;
                }

                ValueType GetValueRaw() const
                {
                    ;
                    return mValue;
                }

                ValueType GetValue() const;
                ValueType SetValue(ValueType n);
                bool SetValueConditional(ValueType n, ValueType condition);
                ValueType Increment();
                ValueType Decrement();
                ValueType Add(ValueType n);


                inline operator const ValueType() const
                {
                    ;
                    return GetValue();
                }

                inline ValueType operator =(ValueType n)
                {
                    ;
                    return SetValue(n);
                }

                inline ValueType operator+=(ValueType n)
                {
                    ;
                    return Add(n);
                }

                inline ValueType operator-=(ValueType n)
                {
                    ;
                    return Add(-n);
                }

                inline ValueType operator++()
                {
                    ;
                    return Increment();
                }

                inline ValueType operator++(int)
                {
                    ;
                    return Increment() - 1;
                }

                inline ValueType operator--()
                {
                    ;
                    return Decrement();
                }

                inline ValueType operator--(int)
                {
                    ;
                    return Decrement() + 1;
                }

            protected:
                volatile ValueType mValue;
            };








            template <> inline
                AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::GetValue() const
            {






                ;
                ValueType nValue;




                __asm__ __volatile__("1: lwarx  %0,0,%1\n                                     stwcx. %0,0,%1\n                                     bne 1b"


                                     : "=&b" (nValue) : "b" (&mValue) : "cc", "memory");

                return nValue;
            }

            template <> inline
                AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::GetValue() const
            {
                ;
                ValueType nValue;




                __asm__ __volatile__("1: lwarx  %0,0,%1\n                                     stwcx. %0,0,%1\n                                     bne 1b"


                                     : "=&b" (nValue) : "b" (&mValue) : "cc", "memory");

                return nValue;
            }

            template <> inline
                AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::SetValue(ValueType n)
            {
                ;
                ValueType nOriginalValue;
                __asm__ __volatile__("1: lwarx  %0,0,%2\n                                     stwcx. %1,0,%2\n                                     bne-   1b"



                                     "\n\tisync"

                                     : "=&b" (nOriginalValue) : "r" (n), "b" (&mValue) : "cc", "memory");
                return nOriginalValue;
            }

            template <> inline
                AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::SetValue(ValueType n)
            {
                ;
                ValueType nOriginalValue;
                __asm__ __volatile__("1: lwarx  %0,0,%2\n                                     stwcx. %1,0,%2\n                                     bne-   1b"



                                     "\n\tisync"

                                     : "=&b" (nOriginalValue) : "r" (n), "b" (&mValue) : "cc", "memory");
                return nOriginalValue;
            }

            template <> inline
                bool AtomicInt<int32_t>::SetValueConditional(ValueType n, ValueType condition)
            {
                ;
                ValueType nOriginalValue;
                __asm__ __volatile__("\n                                     1: lwarx  %0,0,%1 \n                                     cmpw    0,%0,%2 \n                                     bne     2f \n                                     stwcx. %3,0,%1 \n                                     bne-    1b\n"






                                     "sync\n"

                                     "2:"
                                     : "=&b" (nOriginalValue)
                                     : "b" (&mValue), "r" (condition), "r" (n)
                                     : "cc", "memory");
                return condition == nOriginalValue;
            }

            template <> inline
                bool AtomicInt<uint32_t>::SetValueConditional(ValueType n, ValueType condition)
            {
                ;
                ValueType nOriginalValue;
                __asm__ __volatile__("\n                                     1: lwarx  %0,0,%1 \n                                     cmpw    0,%0,%2 \n                                     bne     2f \n                                     stwcx. %3,0,%1 \n                                     bne-    1b\n"






                                     "sync\n"

                                     "2:"
                                     : "=&b" (nOriginalValue)
                                     : "b" (&mValue), "r" (condition), "r" (n)
                                     : "cc", "memory");
                return condition == nOriginalValue;
            }

            template <> inline
                AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Increment()
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: lwarx  %0,0,%1\n                                     addi   %0,%0,1\n                                     stwcx. %0,0,%1\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }

            template <> inline
                AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Increment()
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: lwarx  %0,0,%1\n                                     addi   %0,%0,1\n                                     stwcx. %0,0,%1\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }

            template <> inline
                AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Decrement()
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: lwarx  %0,0,%1\n                                     addi   %0,%0,-1\n                                     stwcx. %0,0,%1\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }

            template <> inline
                AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Decrement()
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: lwarx  %0,0,%1\n                                     addi   %0,%0,-1\n                                     stwcx. %0,0,%1\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }

            template <> inline
                AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Add(ValueType n)
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: lwarx   %0,0,%2\n                                     add        %0,%1,%0\n                                     stwcx. %0,0,%2\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "r" (n), "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }

            template <> inline
                AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Add(ValueType n)
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: lwarx   %0,0,%2\n                                     add        %0,%1,%0\n                                     stwcx. %0,0,%2\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "r" (n), "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }

            template <> inline
                AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::GetValue() const
            {






                ;
                ValueType nValue;




                __asm__ __volatile__("1: ldarx  %0,0,%1\n                                     stdcx. %0,0,%1\n                                     bne 1b"


                                     : "=&b" (nValue) : "b" (&mValue) : "cc", "memory");

                return nValue;
            }

            template <> inline
                AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::GetValue() const
            {
                ;
                ValueType nValue;




                __asm__ __volatile__("1: ldarx  %0,0,%1\n                                     stdcx. %0,0,%1\n                                     bne 1b"


                                     : "=&b" (nValue) : "b" (&mValue) : "cc", "memory");

                return nValue;
            }

            template <> inline
                AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::SetValue(ValueType n)
            {
                ;
                ValueType nOriginalValue;
                __asm__ __volatile__("1: ldarx  %0,0,%2\n                                     stdcx. %1,0,%2\n                                     bne-   1b"



                                     "\n\tisync"

                                     : "=&b" (nOriginalValue) : "r" (n), "b" (&mValue) : "cc", "memory");
                return nOriginalValue;
            }

            template <> inline
                AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::SetValue(ValueType n)
            {
                ;
                ValueType nOriginalValue;
                __asm__ __volatile__("1: ldarx  %0,0,%2\n                                     stdcx. %1,0,%2\n                                     bne-   1b"



                                     "\n\tisync"

                                     : "=&b" (nOriginalValue) : "r" (n), "b" (&mValue) : "cc", "memory");
                return nOriginalValue;
            }

            template <> inline
                bool AtomicInt<int64_t>::SetValueConditional(ValueType n, ValueType condition)
            {
                ;
                ValueType nOriginalValue;
                __asm__ __volatile__("\n                                     1: ldarx  %0,0,%1 \n                                     cmpd    0,%0,%2 \n                                     bne     2f \n                                     stdcx. %3,0,%1 \n                                     bne-    1b\n"






                                     "sync\n"

                                     "2:"
                                     : "=&b" (nOriginalValue)
                                     : "b" (&mValue), "r" (condition), "r" (n)
                                     : "cc", "memory");
                return condition == nOriginalValue;
            }

            template <> inline
                bool AtomicInt<uint64_t>::SetValueConditional(ValueType n, ValueType condition)
            {
                ;
                ValueType nOriginalValue;
                __asm__ __volatile__("\n                                     1: ldarx  %0,0,%1 \n                                     cmpd    0,%0,%2 \n                                     bne     2f \n                                     stdcx. %3,0,%1 \n                                     bne-    1b\n"






                                     "sync\n"

                                     "2:"
                                     : "=&b" (nOriginalValue)
                                     : "b" (&mValue), "r" (condition), "r" (n)
                                     : "cc", "memory");
                return condition == nOriginalValue;
            }

            template <> inline
                AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Increment()
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: ldarx  %0,0,%1\n                                     addi   %0,%0,1\n                                     stdcx. %0,0,%1\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }

            template <> inline
                AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Increment()
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: ldarx  %0,0,%1\n                                     addi   %0,%0,1\n                                     stdcx. %0,0,%1\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }

            template <> inline
                AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Decrement()
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: ldarx  %0,0,%1\n                                     addi   %0,%0,-1\n                                     stdcx. %0,0,%1\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }

            template <> inline
                AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Decrement()
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: ldarx  %0,0,%1\n                                     addi   %0,%0,-1\n                                     stdcx. %0,0,%1\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }

            template <> inline
                AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Add(ValueType n)
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: ldarx   %0,0,%2\n                                     add        %0,%1,%0\n                                     stdcx. %0,0,%2\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "r" (n), "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }

            template <> inline
                AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Add(ValueType n)
            {
                ;
                ValueType nNewValue;
                __asm__ __volatile__("1: ldarx   %0,0,%2\n                                     add        %0,%1,%0\n                                     stdcx. %0,0,%2\n                                     bne-   1b"




                                     "\n\tisync"

                                     : "=&b" (nNewValue) : "r" (n), "b" (&mValue) : "cc", "memory");
                return nNewValue;
            }


            typedef AtomicInt<int32_t> AtomicInt32;
            typedef AtomicInt<uint32_t> AtomicUint32;
            typedef AtomicInt<int64_t> AtomicInt64;
            typedef AtomicInt<uint64_t> AtomicUint64;

        }
    }
}
