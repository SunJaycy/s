











namespace rw
{
    namespace core
    {
        namespace thread
        {




            typedef AtomicInt32 AtomicIntPtr;






















            class AtomicPointer : public AtomicIntPtr
            {
            public:



                typedef void* PointerValueType;






                AtomicPointer(void* p = 0)
                    : AtomicIntPtr(static_cast<ValueType>(reinterpret_cast<uintptr_t>(p)))
                {
                    ;
                    return;
                }

                AtomicPointer& operator=(void* p)
                {
                    ;
                    AtomicIntPtr::operator=(static_cast<ValueType>(reinterpret_cast<uintptr_t>(p)));
                    return *this;
                }

                operator const void*() const
                {
                    ;
                    return (void*)AtomicIntPtr::GetValue();
                }









                void* GetValue() const
                {
                    ;
                    return (void*)AtomicIntPtr::GetValue();
                }












                void* GetValueRaw() const
                {
                    ;
                    return (void*)AtomicIntPtr::GetValueRaw();
                }











                void* SetValue(void* p)
                {
                    ;
                    return (void*)AtomicIntPtr::SetValue(static_cast<ValueType>(reinterpret_cast<uintptr_t>(p)));
                }
















                bool SetValueConditional(void* p, void* pCondition)
                {
                    ;
                    return AtomicIntPtr::SetValueConditional(static_cast<ValueType>(reinterpret_cast<uintptr_t>(p)), static_cast<ValueType>(reinterpret_cast<uintptr_t>(pCondition)));
                }
            };





        }
    }
}
