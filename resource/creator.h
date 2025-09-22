
























namespace rw
{




































template <typename ValueType>
class AllocatedResource
{
public:



    AllocatedResource()
      : m_ptr(0),
        m_resource(),
        m_resourceDescriptor(),
        m_allocator(&GetDefaultAllocator())
    {
        ;
        return;
    }








    template <typename OtherValueType>
    AllocatedResource(OtherValueType* ptr, Resource& resource, const ResourceDescriptor& descriptor)
      : m_ptr(ptr),
        m_resource(resource),
        m_resourceDescriptor(descriptor),
        m_allocator(&GetDefaultAllocator())
    {
        ;
        return;
    }









    template <typename OtherValueType, typename AllocatorType>
    AllocatedResource(OtherValueType* ptr,
                      Resource& resource, const ResourceDescriptor& descriptor, AllocatorType& allocator)
      : m_ptr(ptr),
        m_resource(resource),
        m_resourceDescriptor(descriptor),
        m_allocator(&allocator)
    {
        ;
        return;
    }





    AllocatedResource(const AllocatedResource& other)
      : m_ptr(other.m_ptr),
        m_resource(other.m_resource),
        m_resourceDescriptor(other.m_resourceDescriptor),
        m_allocator(other.m_allocator)
    {
        ;
        return;
    }






    template <typename OtherValueType>
    AllocatedResource(const AllocatedResource<OtherValueType>& other)
      : m_ptr(other.m_ptr),
        m_resource(other.m_resource),
        m_resourceDescriptor(other.m_resourceDescriptor),
        m_allocator(other.m_allocator)
    {
        ;
        return;
    }




    ~AllocatedResource()
    {
        ;
        return;
    }






    AllocatedResource&
    operator=(const AllocatedResource& other)
    {
        ;
        m_ptr = other.m_ptr;
        m_resource = other.m_resource;
        m_resourceDescriptor = other.m_resourceDescriptor;
        m_allocator = other.m_allocator;
        return *this;
    }









    template <typename OtherValueType>
    AllocatedResource&
    operator=(const AllocatedResource<OtherValueType>& other)
    {
        ;
        m_ptr = other.m_ptr;
        m_resource = other.m_resource;
        m_resourceDescriptor = other.m_resourceDescriptor;
        m_allocator = other.m_allocator;
        return *this;
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




    ValueType* Get() const
    {
        ;
        return m_ptr;
    }




    operator ValueType*() const
    {
        ;
        return m_ptr;
    }




    operator ValueType*()
    {
        ;
        return m_ptr;
    }




    RwBool operator!() const
    {
        ;
        return static_cast<RwBool>(m_ptr == 0);
    }






    const Resource& GetResource() const
    {
        ;
        return m_resource;
    }







    const ResourceDescriptor& GetResourceDescriptor() const
    {
        ;
        return m_resourceDescriptor;
    }







    IResourceAllocator& GetAllocator() const
    {
        ;
        ;
        return *m_allocator;
    }


private:
    ValueType *m_ptr;
    Resource m_resource;
    ResourceDescriptor m_resourceDescriptor;
    IResourceAllocator *m_allocator;
};






template <typename ValueType>
struct TypeTraits
{
    static const char8_t * GetName()
    {
        ;
        return "Creator<UNKNOWN TYPE>::Allocate()";
    }
};


























template <typename ValueType>
class Creator
{
public:



    Creator(IResourceAllocator& allocator = GetDefaultAllocator())
      : m_allocator(allocator)
    {
        ;
        return;
    }




    ~Creator()
    {
        ;
        return;
    }





    AllocatedResource<ValueType> New()
    {
        ;
        ResourceDescriptor resourceDescriptor = ValueType::GetResourceDescriptor();
        Resource resource = m_allocator.Allocate(resourceDescriptor,
               0);
        AllocatedResource<ValueType> object(ValueType::Initialize(resource),
                                            resource, resourceDescriptor, m_allocator);
        if (!object)
        {
            m_allocator.Free(resource);
        }
        return object;
    }





    template <typename ARG1_TYPE>
    AllocatedResource<ValueType> New(const ARG1_TYPE& arg1)
    {
        ;
        ResourceDescriptor resourceDescriptor = ValueType::GetResourceDescriptor(arg1);
        Resource resource = m_allocator.Allocate(resourceDescriptor,
            0);
        AllocatedResource<ValueType> object(ValueType::Initialize(resource, arg1),
                                            resource, resourceDescriptor, m_allocator);
        if (!object)
        {
            m_allocator.Free(resource);
        }
        return object;
    }





    template <typename ARG1_TYPE, typename ARG2_TYPE>
    AllocatedResource<ValueType> New(const ARG1_TYPE& arg1,
                                     const ARG2_TYPE& arg2)
    {
        ;
        ResourceDescriptor resourceDescriptor = ValueType::GetResourceDescriptor(arg1, arg2);
        Resource resource = m_allocator.Allocate(resourceDescriptor,
            0);
        AllocatedResource<ValueType> object(ValueType::Initialize(resource, arg1, arg2),
                                            resource, resourceDescriptor, m_allocator);
        if (!object)
        {
            m_allocator.Free(resource);
        }
        return object;
    }





    template <typename ARG1_TYPE, typename ARG2_TYPE, typename ARG3_TYPE>
    AllocatedResource<ValueType> New(const ARG1_TYPE& arg1,
                                     const ARG2_TYPE& arg2,
                                     const ARG3_TYPE& arg3)
    {
        ;
        ResourceDescriptor resourceDescriptor = ValueType::GetResourceDescriptor(arg1, arg2, arg3);
        Resource resource = m_allocator.Allocate(resourceDescriptor,
            0);
        AllocatedResource<ValueType> object(ValueType::Initialize(resource, arg1, arg2, arg3),
                                            resource, resourceDescriptor, m_allocator);
        if (!object)
        {
            m_allocator.Free(resource);
        }
        return object;
    }





    template <typename ARG1_TYPE,
              typename ARG2_TYPE,
              typename ARG3_TYPE,
              typename ARG4_TYPE>
    AllocatedResource<ValueType> New(const ARG1_TYPE& arg1,
                                     const ARG2_TYPE& arg2,
                                     const ARG3_TYPE& arg3,
                                     const ARG4_TYPE& arg4)
    {
        ;
        ResourceDescriptor resourceDescriptor =
            ValueType::GetResourceDescriptor(arg1, arg2, arg3, arg4);
        Resource resource = m_allocator.Allocate(resourceDescriptor,
            0);
        AllocatedResource<ValueType> object(ValueType::Initialize(resource, arg1, arg2, arg3, arg4),
                                            resource, resourceDescriptor, m_allocator);
        if (!object)
        {
            m_allocator.Free(resource);
        }
        return object;
    }





    template <typename ARG1_TYPE,
              typename ARG2_TYPE,
              typename ARG3_TYPE,
              typename ARG4_TYPE,
              typename ARG5_TYPE>
    AllocatedResource<ValueType> New(const ARG1_TYPE& arg1,
                                     const ARG2_TYPE& arg2,
                                     const ARG3_TYPE& arg3,
                                     const ARG4_TYPE& arg4,
                                     const ARG5_TYPE& arg5)
    {
        ;
        ResourceDescriptor resourceDescriptor =
            ValueType::GetResourceDescriptor(arg1, arg2, arg3, arg4, arg5);
        Resource resource = m_allocator.Allocate(resourceDescriptor,
            0);
        AllocatedResource<ValueType> object(ValueType::Initialize(resource, arg1, arg2, arg3, arg4, arg5),
                                            resource, resourceDescriptor, m_allocator);
        if (!object)
        {
            m_allocator.Free(resource);
        }
        return object;
    }





    template <typename ARG1_TYPE,
              typename ARG2_TYPE,
              typename ARG3_TYPE,
              typename ARG4_TYPE,
              typename ARG5_TYPE,
              typename ARG6_TYPE>
    AllocatedResource<ValueType> New(const ARG1_TYPE& arg1,
                                     const ARG2_TYPE& arg2,
                                     const ARG3_TYPE& arg3,
                                     const ARG4_TYPE& arg4,
                                     const ARG5_TYPE& arg5,
                                     const ARG6_TYPE& arg6)
    {
        ;
        ResourceDescriptor resourceDescriptor =
            ValueType::GetResourceDescriptor(arg1, arg2, arg3, arg4, arg5, arg6);
        Resource resource = m_allocator.Allocate(resourceDescriptor,
            0);
        AllocatedResource<ValueType> object(ValueType::Initialize(resource,
                                                                  arg1, arg2, arg3, arg4, arg5, arg6),
                                            resource, resourceDescriptor, m_allocator);
        if (!object)
        {
            m_allocator.Free(resource);
        }
        return object;
    }





    template <typename ARG1_TYPE,
              typename ARG2_TYPE,
              typename ARG3_TYPE,
              typename ARG4_TYPE,
              typename ARG5_TYPE,
              typename ARG6_TYPE,
              typename ARG7_TYPE>
    AllocatedResource<ValueType> New(const ARG1_TYPE& arg1,
                                     const ARG2_TYPE& arg2,
                                     const ARG3_TYPE& arg3,
                                     const ARG4_TYPE& arg4,
                                     const ARG5_TYPE& arg5,
                                     const ARG6_TYPE& arg6,
                                     const ARG7_TYPE& arg7)
    {
        ;
        ResourceDescriptor resourceDescriptor =
            ValueType::GetResourceDescriptor(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        Resource resource = m_allocator.Allocate(resourceDescriptor,
            0);
        AllocatedResource<ValueType> object(ValueType::Initialize(resource,
                                                                  arg1, arg2, arg3, arg4, arg5, arg6, arg7),
                                            resource, resourceDescriptor, m_allocator);
        if (!object)
        {
            m_allocator.Free(resource);
        }
        return object;
    }

private:
    IResourceAllocator& m_allocator;
};







}
