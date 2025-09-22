


























namespace rw
{



























template <typename ValueType>
class SharedResourceRefCountImpl
{
public:







    SharedResourceRefCountImpl()
      : m_count(0),
        m_objectPtr(0),
        m_objectResource(),
        m_objectResourceDescriptor(),
        m_allocator(0)
    {
        ;
        return;
    }




    ~SharedResourceRefCountImpl()
    {
        ;
        return;
    }




    const Resource& GetObjectResource() const
    {
        ;
        return m_objectResource;
    }




    Resource& GetObjectResource()
    {
        ;
        return m_objectResource;
    }




    const ResourceDescriptor& GetObjectResourceDescriptor() const
    {
        ;
        return m_objectResourceDescriptor;
    }




    ResourceDescriptor& GetObjectResourceDescriptor()
    {
        ;
        return m_objectResourceDescriptor;
    }




    size_t Count() const
    {
        ;
        return m_count;
    }




    RwBool Unique() const
    {
        ;
        return m_count == 1;
    }




    void
    Incr()
    {
        ;
        ++m_count;
        return;
    }





    void
    Decr()
    {
        ;
        --m_count;
        if (m_count == 0)
        {
            Dispose();
            Destruct();
        }
        return;
    }






    static ResourceDescriptor GetResourceDescriptor()
    {
        ;
        return ResourceDescriptor(sizeof(SharedResourceRefCountImpl<ValueType>), 1);
    }




    static SharedResourceRefCountImpl* Initialize(const Resource& resource,
                                                  ValueType* ptr,
                                                  const Resource& objectResource,
                                                  const ResourceDescriptor& objectResourceDescriptor,
                                                  IResourceAllocator& allocator)
    {
        ;
        SharedResourceRefCountImpl* refCountImpl =
            static_cast<SharedResourceRefCountImpl*>(resource.GetMemoryResource());
        refCountImpl->m_count = 1;
        refCountImpl->m_objectPtr = ptr;
        refCountImpl->m_objectResource = objectResource;
        refCountImpl->m_objectResourceDescriptor = objectResourceDescriptor;
        refCountImpl->m_allocator = &allocator;
        return refCountImpl;
    }




    void Release()
    {
        ;
        return;
    }

private:




    SharedResourceRefCountImpl(const SharedResourceRefCountImpl& other);



    SharedResourceRefCountImpl& operator=(const SharedResourceRefCountImpl& other);




    void Dispose()
    {
        ;
        ;
        m_objectPtr->Release();
        m_allocator->Free(m_objectResource);
        return;
    }




    void Destruct()
    {
        ;
        Release();
        m_allocator->Free(Resource(this));
        return;
    }

    size_t m_count;
    ValueType* m_objectPtr;
    Resource m_objectResource;
    ResourceDescriptor m_objectResourceDescriptor;
    IResourceAllocator* m_allocator;
};






template <typename ValueType>
class SharedResourceRefCount
{
private:
    typedef SharedResourceRefCountImpl<ValueType> Impl;

public:






    SharedResourceRefCount()
      : m_impl(0)
    {
        ;
        return;
    }




    SharedResourceRefCount(ValueType* ptr,
                           const Resource& resource,
                           const ResourceDescriptor& descriptor,
                           IResourceAllocator& allocator)
      : m_impl(0)
    {
        ;
        ;
        Resource implResource = allocator.Allocate(Impl::GetResourceDescriptor());
        m_impl = Impl::Initialize(implResource, ptr, resource, descriptor, allocator);
        return;
    }




    SharedResourceRefCount(const SharedResourceRefCount& other)
      : m_impl(other.m_impl)
    {
        ;
        if (m_impl)
        {
            m_impl->Incr();
        }
        return;
    }





    ~SharedResourceRefCount()
    {
        ;
        if (m_impl)
        {
            m_impl->Decr();
        }
        return;
    }





    SharedResourceRefCount& operator=(const SharedResourceRefCount& other)
    {
        ;
        if (this != &other)
        {
            Impl *temp = other.m_impl;
            if (temp)
            {
                temp->Incr();
            }
            if (m_impl)
            {
                m_impl->Decr();
            }
            m_impl = temp;
        }
        return *this;
    }




    size_t Count() const
    {
        ;
        if (m_impl)
        {
            return m_impl->Count();
        }
        else
        {
            return 0;
        }
    }





    RwBool Unique() const
    {
        ;
        if (m_impl)
        {
            return m_impl->Unique();
        }
        else
        {
            return 0;
        }
    }




    const ResourceDescriptor& GetResourceDescriptor() const
    {
        ;
        ;
        return m_impl->GetObjectResourceDescriptor();
    }




    ResourceDescriptor& GetResourceDescriptor()
    {
        ;
        ;
        return m_impl->GetObjectResourceDescriptor();
    }




    const Resource& GetResource() const
    {
        ;
        ;
        return m_impl->GetObjectResource();
    }




    Resource& GetResource()
    {
        ;
        ;
        return m_impl->GetObjectResource();
    }





    void Swap(SharedResourceRefCount& other)
    {
        ;
        Impl* temp(m_impl);
        m_impl = other.m_impl;
        other.m_impl = temp;
        return;
    }

private:
    Impl *m_impl;
};










template <typename ValueType>
class SharedResource
{
public:



    SharedResource()
      : m_ptr(0),
        m_count()
    {
        ;
        return;
    }








    template <typename OtherValueType>
    SharedResource(OtherValueType* ptr, Resource& resource, const ResourceDescriptor& descriptor)
      : m_ptr(ptr),
        m_count()
    {
        ;
        if (m_ptr)
        {
            SharedResourceRefCount<ValueType> newCount(m_ptr, resource, descriptor,
                                                       GetDefaultAllocator());
            m_count.Swap(newCount);
        }
        return;
    }










    template <typename OtherValueType>
    SharedResource(OtherValueType* ptr,
                   Resource& resource, const ResourceDescriptor& descriptor, IResourceAllocator& allocator)
      : m_ptr(ptr),
        m_count(ptr, resource, descriptor, allocator)
    {
        ;
        return;
    }







    template <typename OtherValueType>
    SharedResource(const AllocatedResource<OtherValueType>& allocatedResource)
      : m_ptr(allocatedResource.Get()),
        m_count()
    {
        ;
        if (m_ptr)
        {
            SharedResourceRefCount<ValueType> newCount(m_ptr,
                                                       allocatedResource.GetResource(),
                                                       allocatedResource.GetResourceDescriptor(),
                                                       allocatedResource.GetAllocator());
            m_count.Swap(newCount);
        }
        return;
    }






    SharedResource(const SharedResource& other)
      : m_ptr(other.m_ptr),
        m_count(other.m_count)
    {
        ;
        return;
    }





    ~SharedResource()
    {
        ;
        return;
    }







    SharedResource&
    operator=(const SharedResource& other)
    {
        ;
        m_ptr = other.m_ptr;
        m_count = other.m_count;
        return *this;
    }






    void Reset()
    {
        ;
        SharedResource<ValueType>().Swap(*this);
        return;
    }









    template <typename OtherValueType>
    void Reset(OtherValueType* ptr, Resource& resource, const ResourceDescriptor& descriptor)
    {
        ;
        ;
        SharedResource<ValueType>(ptr, resource, descriptor, GetDefaultAllocator()).Swap(*this);
        return;
    }










    template <typename OtherValueType>
    void Reset(OtherValueType* ptr,
               Resource& resource, const ResourceDescriptor& descriptor, IResourceAllocator& allocator)
    {
        ;
        ;
        SharedResource<ValueType>(ptr, resource, descriptor, allocator).Swap(*this);
        return;
    }










    template <typename OtherValueType>
    void Reset(const AllocatedResource<OtherValueType>& allocatedResource)
    {
        ;
        ;
        SharedResource<ValueType>(allocatedResource).Swap(*this);
        return;
    }







    const ValueType& operator*() const
    {
        ;
        ;
        return *m_ptr;
    }







    ValueType& operator*()
    {
        ;
        ;
        return *m_ptr;
    }







    const ValueType* operator->() const
    {
        ;
        ;
        return m_ptr;
    }







    ValueType* operator->()
    {
        ;
        ;
        return m_ptr;
    }







    const ValueType* Get() const
    {
        ;
        return m_ptr;
    }







    ValueType* Get()
    {
        ;
        return m_ptr;
    }







    const ResourceDescriptor& GetResourceDescriptor() const
    {
        ;
        return m_count.GetResourceDescriptor();
    }







    ResourceDescriptor& GetResourceDescriptor()
    {
        ;
        return m_count.GetResourceDescriptor();
    }







    const Resource& GetResource() const
    {
        ;
        return m_count.GetResource();
    }






    Resource& GetResource()
    {
        ;
        return m_count.GetResource();
    }





    operator RwBool() const
    {
        ;
        return static_cast<RwBool>(m_ptr != 0);
    }





    RwBool operator!() const
    {
        ;
        return m_ptr == 0;
    }





    size_t Count() const
    {
        ;
        return m_count.Count();
    }





    RwBool Unique() const
    {
        ;
        return m_count.Unique();
    }





    void Swap(SharedResource<ValueType>& other)
    {
        ;
        ValueType* tempPtr = m_ptr;
        m_ptr = other.m_ptr;
        other.m_ptr = tempPtr;
        m_count.Swap(other.m_count);
        return;
    }


private:

    ValueType *m_ptr;
    SharedResourceRefCount<ValueType> m_count;
};







template <typename ValueType>
inline void RwSwap(SharedResource<ValueType>& lhs, SharedResource<ValueType>& rhs)
{
    ;
    lhs.Swap(rhs);
    return;
}





template <typename LhsValueType, typename RhsValueType>
inline RwBool operator==(const SharedResource<LhsValueType>&lhs, const SharedResource<RhsValueType>& rhs)
{
    ;
    return lhs.Get() == rhs.Get();
}




template <typename LhsValueType, typename RhsValueType>
inline RwBool operator!=(const SharedResource<LhsValueType>& lhs, const SharedResource<RhsValueType>& rhs)
{
    ;
    return lhs.Get() != rhs.Get();
}






template <typename LhsValueType, typename RhsValueType>
inline RwBool operator<(const SharedResource<LhsValueType>& lhs, const SharedResource<RhsValueType>& rhs)
{
    ;
    ;
    ;
    return lhs.Get() < rhs.Get();
}



}
