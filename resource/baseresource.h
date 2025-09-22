



















namespace rw
{





























class BaseResourceDescriptor
{
public:



    BaseResourceDescriptor()
      : m_size(0),
        m_alignment(1)
    {
        ;
        ;
        return;
    }







    BaseResourceDescriptor(uint32_t size, uint32_t alignment)
      : m_size(size),
        m_alignment(alignment)
    {
        ;
        ;
        return;
    }




    ~BaseResourceDescriptor()
    {
        ;
        return;
    }








    void
    EndianSwap()
    {
        ;
        rw::EndianSwap(m_size);
        rw::EndianSwap(m_alignment);
        return;
    }





    uint32_t GetSize() const
    {
        ;
        return static_cast<uint32_t>(m_size);
    }





    void SetSize(uint32_t size)
    {
        ;
        m_size = size;
        return;
    }





    uint32_t GetAlignment() const
    {
        ;
        return m_alignment;
    }





    void SetAlignment(uint32_t alignment)
    {
        ;
        m_alignment = alignment;
        return;
    }







    void Align(const BaseResourceDescriptor& rhs)
    {
        ;
        m_size = SizeAlign(m_size, rhs.m_alignment);
        m_alignment = (m_alignment > rhs.m_alignment ? m_alignment : rhs.m_alignment);
        return;
    }










    void operator+=(const BaseResourceDescriptor& rhs)
    {
        ;
        Align(rhs);
        m_size += rhs.m_size;
        return;
    }










    BaseResourceDescriptor operator+(const BaseResourceDescriptor& rhs) const
    {
        ;
        BaseResourceDescriptor sum = *this;
        sum += rhs;
        return sum;
    }









    void operator-=(const BaseResourceDescriptor& rhs)
    {
        ;
        ;
        m_size -= rhs.m_size;
        return;
    }










    BaseResourceDescriptor operator-(const BaseResourceDescriptor& rhs) const
    {
        ;
        BaseResourceDescriptor diff = *this;
        diff -= rhs;
        return diff;
    }

private:

    uint32_t m_size;
    uint32_t m_alignment;
};








inline bool operator==(const BaseResourceDescriptor& lhs, const BaseResourceDescriptor& rhs)
{
    ;
    return (lhs.GetSize() == rhs.GetSize()) && (lhs.GetAlignment() == rhs.GetAlignment());
}





inline bool operator!=(const BaseResourceDescriptor& lhs, const BaseResourceDescriptor& rhs)
{
    ;
    return !(lhs == rhs);
}








inline bool operator<(const BaseResourceDescriptor& lhs, const BaseResourceDescriptor& rhs)
{
    ;
    return lhs.GetSize() < rhs.GetSize();
}








inline bool operator<=(const BaseResourceDescriptor& lhs, const BaseResourceDescriptor& rhs)
{
    ;
    return lhs.GetSize() <= rhs.GetSize();
}










template <uint32_t typeId>
class BaseResourceDescriptorType : public BaseResourceDescriptor
{
public:



    BaseResourceDescriptorType()
      : BaseResourceDescriptor()
    {
        ;
        return;
    }






    BaseResourceDescriptorType(uint32_t size, uint32_t alignment)
      : BaseResourceDescriptor(size, alignment)
    {
        ;
        return;
    }




    ~BaseResourceDescriptorType()
    {
        ;
        return;
    }




};




typedef void* BaseResource;






template <uint32_t typeId>
class BaseResourceType
{
public:




    BaseResourceType(void* resource = 0)
      : m_resource(resource)
    {
        ;
        return;
    }





    ~BaseResourceType()
    {
        ;
        return;
    }





    operator void*()
    {
        ;
        return m_resource;
    }

    operator const void*() const
    {
        ;
        return const_cast<const void*>(m_resource);
    }

private:
    void* m_resource;
};

}
