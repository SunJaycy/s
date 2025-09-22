





















namespace rw
{


























template <uint32_t NumberOfBaseResourceTypes>
class BaseResourceDescriptors
{
public:
    typedef BaseResourceDescriptor* const_iterator;
    typedef BaseResourceDescriptor* iterator;




    BaseResourceDescriptors()
    {
        ;
        return;
    }











    const BaseResourceDescriptor& GetBaseResourceDescriptor(uint32_t i) const
    {
        ;
        return m_baseResourceDescriptors[i];
    }




    BaseResourceDescriptor& GetBaseResourceDescriptor(uint32_t i)
    {
        ;
        return m_baseResourceDescriptors[i];
    }





    static uint32_t GetNumberOfBaseResourceTypes()
    {
        ;
        return NumberOfBaseResourceTypes;
    }





    const_iterator begin() const
    {
        ;
        return m_baseResourceDescriptors;
    }




    iterator begin()
    {
        ;
        return m_baseResourceDescriptors;
    }





    const_iterator end() const
    {
        ;
        return m_baseResourceDescriptors + NumberOfBaseResourceTypes;
    }




    iterator end()
    {
        ;
        return m_baseResourceDescriptors + NumberOfBaseResourceTypes;
    }





    void
    EndianSwap()
    {
        ;
        for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
        {
            m_baseResourceDescriptors[i].EndianSwap();
        }
        return;
    }






    void Align(const BaseResourceDescriptors& alignmentDescriptor)
    {
        ;
        for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
        {
            m_baseResourceDescriptors[i].Align(alignmentDescriptor);
        }
        return;
    }







    void Flatten()
    {
        ;
        BaseResourceDescriptor totalMemoryResDesc;
        for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
        {
            totalMemoryResDesc += GetBaseResourceDescriptor(i);
            GetBaseResourceDescriptor(i) = BaseResourceDescriptor();
        }
        GetBaseResourceDescriptor(0) = totalMemoryResDesc;
        return;
    }






    void operator+=(const BaseResourceDescriptors& rhs)
    {
        ;
        for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
        {
            m_baseResourceDescriptors[i] += rhs.m_baseResourceDescriptors[i];
        }
        return;
    }





    void operator-=(const BaseResourceDescriptors& rhs)
    {
        ;
        for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
        {
            m_baseResourceDescriptors[i] -= rhs.m_baseResourceDescriptors[i];
        }
        return;
    }

private:
    BaseResourceDescriptor m_baseResourceDescriptors[NumberOfBaseResourceTypes];
};








template <uint32_t NumberOfBaseResourceTypes>
RwBool
operator==(const BaseResourceDescriptors<NumberOfBaseResourceTypes>& lhs,
           const BaseResourceDescriptors<NumberOfBaseResourceTypes>& rhs)
{
    ;
    for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
    {
        if (lhs.GetBaseResourceDescriptor(i) != rhs.GetBaseResourceDescriptor(i))
        {
            return 0;
        }
    }
    return (!0);
}







template <uint32_t NumberOfBaseResourceTypes>
RwBool
operator<(const BaseResourceDescriptors<NumberOfBaseResourceTypes>& lhs,
          const BaseResourceDescriptors<NumberOfBaseResourceTypes>& rhs)
{
    ;
    for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
    {
        if (rhs.GetBaseResourceDescriptor(i) <= lhs.GetBaseResourceDescriptor(i))
        {
            return 0;
        }
    }
    return (!0);
}







template <uint32_t NumberOfBaseResourceTypes>
RwBool
operator<=(const BaseResourceDescriptors<NumberOfBaseResourceTypes>& lhs,
           const BaseResourceDescriptors<NumberOfBaseResourceTypes>& rhs)
{
    ;
    for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
    {
        if (rhs.GetBaseResourceDescriptor(i) < lhs.GetBaseResourceDescriptor(i))
        {
            return 0;
        }
    }
    return (!0);
}






template <uint32_t NumberOfBaseResourceTypes>
class BaseResources
{
public:
    typedef BaseResource* const_iterator;
    typedef BaseResource* iterator;




    BaseResources()
    {
        ;
        for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
        {
            m_baseResources[i] = BaseResource((void*)0);
        }
        return;
    }










    operator bool() const
    {
        ;
        for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
        {
            if (m_baseResources[i])
            {
                return (!0);
            }
        }
        return 0;
    }





    const BaseResource& GetBaseResource(uint32_t i) const
    {
        ;
        return m_baseResources[i];
    }




    BaseResource& GetBaseResource(uint32_t i)
    {
        ;
        return m_baseResources[i];
    }





    static uint32_t GetNumberOfBaseResourceTypes()
    {
        ;
        return NumberOfBaseResourceTypes;
    }





    const_iterator begin() const
    {
        ;
        return m_baseResources;
    }




    iterator begin()
    {
        ;
        return m_baseResources;
    }





    const_iterator end() const
    {
        ;
        return m_baseResources + NumberOfBaseResourceTypes;
    }




    iterator end()
    {
        ;
        return m_baseResources + NumberOfBaseResourceTypes;
    }







    RwBool IsAligned(const BaseResourceDescriptors<NumberOfBaseResourceTypes>& alignmentDescriptor)
    {
        ;
        for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
        {
            if (!IsMemAligned(m_baseResources[i],
                              alignmentDescriptor.GetBaseResourceDescriptor(i).GetAlignment()))
            {
                return 0;
            }
        }
        return (!0);
    }







    void Align(const BaseResourceDescriptors<NumberOfBaseResourceTypes>& alignmentDescriptor)
    {
        ;
        for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
        {
            m_baseResources[i] = MemAlign(m_baseResources[i],
                                          alignmentDescriptor.GetBaseResourceDescriptor(i).GetAlignment());
        }
        return;
    }







    void operator+=(const BaseResourceDescriptors<NumberOfBaseResourceTypes>& descriptor)
    {
        ;
        for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
        {
            ;

            m_baseResources[i] = MemAddOffset(m_baseResources[i],
                                              descriptor.GetBaseResourceDescriptor(i).GetSize());
        }
        return;
    }








    void FromMemoryBlock(void* ptr, const BaseResourceDescriptors<NumberOfBaseResourceTypes>& descriptor)
    {
        ;
        for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
        {
            if (descriptor.GetBaseResourceDescriptor(i).GetSize() > 0)
            {
                ;
                m_baseResources[i] = ptr;
                ptr = MemAddOffset(ptr, descriptor.GetBaseResourceDescriptor(i).GetSize());
            }
            else
            {
                m_baseResources[i] = (void*)0;
            }
        }
        return;
    }

private:
    BaseResource m_baseResources[NumberOfBaseResourceTypes];
};









template <uint32_t NumberOfBaseResourceTypes>
RwBool
operator==(const BaseResources<NumberOfBaseResourceTypes>& lhs,
           const BaseResources<NumberOfBaseResourceTypes>& rhs)
{
    ;
    for (uint32_t i = 0; i < NumberOfBaseResourceTypes; ++i)
    {
        if (lhs.GetBaseResource(i) != rhs.GetBaseResource(i))
        {
            return 0;
        }
    }
    return (!0);
}




}
