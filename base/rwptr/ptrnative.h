










































namespace rw
{






















template <typename T>
inline rw::TargetPtr RwPtrToOffset(const T* ptr)
{
    ;
    return reinterpret_cast<rw::TargetPtr>(ptr);
}




template <typename T>
inline T* RwPtrFromOffset(rw::TargetPtr offset)
{
    ;
    return reinterpret_cast<T*>(offset);
}




template <typename T>
inline T* RwPtrAddOffset(T* ptr, rw::TargetPtr offset)
{
    ;
    return RwPtrFromOffset<T>(RwPtrToOffset(ptr) + offset);
}




template <typename T>
inline T* RwPtrSubtractOffset(T* ptr, rw::TargetPtr offset)
{
    ;
    return RwPtrFromOffset<T>(RwPtrToOffset(ptr) - offset);
}




template <typename ValueType>
ValueType* RwPtrAddBasePtr(ValueType* ptr, const void* base)
{
    ;
    return RwPtrAddOffset(ptr, RwPtrToOffset(base));
}




template <typename ValueType>
ValueType* RwPtrSubtractBasePtr(ValueType* ptr, const void* base)
{
    ;
    return RwPtrSubtractOffset(ptr, RwPtrToOffset(base));
}




template <typename T>
inline T* RwPtrToHostPtr(T* ptr)
{
    ;
    return ptr;
}




template <typename T>
class RwPtrReinterpretCast
{
public:
    template <typename U>
    RwPtrReinterpretCast(U* other)
      : m_ptr(reinterpret_cast<T*>(other))
    {
        ;
        return;
    }

    operator T*()const
    {
        ;
        return m_ptr;
    }

private:
    T* m_ptr;
};













}
