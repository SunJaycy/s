






















namespace rw
{






















enum {BASERESOURCE_MAINMEMORY = 0,
      BASERESOURCE_DISPOSABLE,
      BASERESOURCE_UNINITIALIZED,
      BASERESOURCE_DISPOSABLE_UNINITIALIZED,
      BASERESOURCE_GRAPHICS_SYSTEM,
      BASERESOURCE_GRAPHICS_LOCAL,
      BASERESOURCE_NUMBEROFBASERESOURCETYPES};
const RwChar* const BASERESOURCE_BASERESOURCETYPENAMES[] = {"main memory",
                                                            "disposable",
                                                            "uninitialized",
                                                            "disposable uninitialized",
                                                            "graphics system",
                                                            "graphics local"};

typedef BaseResourceDescriptorType<BASERESOURCE_MAINMEMORY> MemoryResourceDescriptor;
typedef BaseResourceDescriptorType<BASERESOURCE_DISPOSABLE> DisposableResourceDescriptor;
typedef BaseResourceDescriptorType<BASERESOURCE_UNINITIALIZED> UninitializedResourceDescriptor;
typedef BaseResourceDescriptorType<BASERESOURCE_DISPOSABLE_UNINITIALIZED>
                                                             DisposableUninitializedResourceDescriptor;
typedef BaseResourceDescriptorType<BASERESOURCE_GRAPHICS_SYSTEM> GraphicsSystemResourceDescriptor;
typedef BaseResourceDescriptorType<BASERESOURCE_GRAPHICS_LOCAL> GraphicsLocalResourceDescriptor;

typedef BaseResource MemoryResource;
typedef BaseResource DisposableResource;
typedef BaseResource UninitializedResource;
typedef BaseResource DisposableUninitializedResource;
typedef BaseResource GraphicsSystemResource;
typedef BaseResource GraphicsLocalResource;













class ResourceDescriptor : public BaseResourceDescriptors<BASERESOURCE_NUMBEROFBASERESOURCETYPES>
{
public:



    ResourceDescriptor(const MemoryResourceDescriptor& mainMemory = MemoryResourceDescriptor())
    {
        ;
        GetBaseResourceDescriptor(BASERESOURCE_MAINMEMORY) = mainMemory;
        return;
    }




    ResourceDescriptor(uint32_t size, uint32_t alignment)
    {
        ;
        GetBaseResourceDescriptor(BASERESOURCE_MAINMEMORY) = MemoryResourceDescriptor(size, alignment);
        return;
    }










    const MemoryResourceDescriptor& GetMemoryResourceDescriptor() const
    {
        ;
        return static_cast<const MemoryResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_MAINMEMORY));

    }




    MemoryResourceDescriptor& GetMemoryResourceDescriptor()
    {
        ;
        return static_cast<MemoryResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_MAINMEMORY));

    }





    const UninitializedResourceDescriptor& GetUninitializedResourceDescriptor() const
    {
        ;
        return static_cast<const UninitializedResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_UNINITIALIZED));

    }




    UninitializedResourceDescriptor& GetUninitializedResourceDescriptor()
    {
        ;
        return static_cast<UninitializedResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_UNINITIALIZED));

    }





    const DisposableResourceDescriptor& GetDisposableResourceDescriptor() const
    {
        ;
        return static_cast<const DisposableResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_DISPOSABLE));

    }




    DisposableResourceDescriptor& GetDisposableResourceDescriptor()
    {
        ;
        return static_cast<DisposableResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_DISPOSABLE));

    }





    const DisposableUninitializedResourceDescriptor& GetDisposableUninitializedResourceDescriptor() const
    {
        ;
        return static_cast<const DisposableUninitializedResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_DISPOSABLE_UNINITIALIZED));

    }




    DisposableUninitializedResourceDescriptor& GetDisposableUninitializedResourceDescriptor()
    {
        ;
        return static_cast<DisposableUninitializedResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_DISPOSABLE_UNINITIALIZED));

    }





    const GraphicsSystemResourceDescriptor& GetGraphicsSystemResourceDescriptor() const
    {
        ;
        return static_cast<const GraphicsSystemResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_GRAPHICS_SYSTEM));

    }




    GraphicsSystemResourceDescriptor& GetGraphicsSystemResourceDescriptor()
    {
        ;
        return static_cast<GraphicsSystemResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_GRAPHICS_SYSTEM));

    }





    const GraphicsLocalResourceDescriptor& GetGraphicsLocalResourceDescriptor() const
    {
        ;
        return static_cast<const GraphicsLocalResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_GRAPHICS_LOCAL));

    }




    GraphicsLocalResourceDescriptor& GetGraphicsLocalResourceDescriptor()
    {
        ;
        return static_cast<GraphicsLocalResourceDescriptor&> (GetBaseResourceDescriptor(BASERESOURCE_GRAPHICS_LOCAL));

    }






    uint32_t GetSize() const
    {
        ;
        return GetMemoryResourceDescriptor().GetSize();
    }





    uint32_t GetAlignment() const
    {
        ;
        return GetMemoryResourceDescriptor().GetAlignment();
    }
};




inline ResourceDescriptor operator+(const ResourceDescriptor& lhs, const ResourceDescriptor& rhs)
{
    ;
    ResourceDescriptor sum = lhs;
    sum += rhs;
    return sum;
}




inline ResourceDescriptor operator-(const ResourceDescriptor& lhs, const ResourceDescriptor& rhs)
{
    ;
    ResourceDescriptor diff = lhs;
    diff -= rhs;
    return diff;
}






class Resource : public BaseResources<BASERESOURCE_NUMBEROFBASERESOURCETYPES>
{
public:



    Resource(const MemoryResource& mainMemory = MemoryResource())
    {
        ;
        GetBaseResource(BASERESOURCE_MAINMEMORY) = mainMemory;
        return;
    }









    MemoryResource GetMemoryResource() const
    {
        ;
        return GetBaseResource(BASERESOURCE_MAINMEMORY);
    }




    MemoryResource& GetMemoryResource()
    {
        ;
        return GetBaseResource(BASERESOURCE_MAINMEMORY);
    }





    UninitializedResource GetUninitializedResource() const
    {
        ;
        return GetBaseResource(BASERESOURCE_UNINITIALIZED);
    }




    UninitializedResource& GetUninitializedResource()
    {
        ;
        return GetBaseResource(BASERESOURCE_UNINITIALIZED);
    }





    DisposableResource GetDisposableResource() const
    {
        ;
        return GetBaseResource(BASERESOURCE_DISPOSABLE);
    }




    DisposableResource& GetDisposableResource()
    {
        ;
        return GetBaseResource(BASERESOURCE_DISPOSABLE);
    }





    DisposableUninitializedResource GetDisposableUninitializedResource() const
    {
        ;
        return GetBaseResource(BASERESOURCE_DISPOSABLE_UNINITIALIZED);
    }




    DisposableUninitializedResource& GetDisposableUninitializedResource()
    {
        ;
        return GetBaseResource(BASERESOURCE_DISPOSABLE_UNINITIALIZED);
    }





    GraphicsSystemResource GetGraphicsSystemResource() const
    {
        ;
        return GetBaseResource(BASERESOURCE_GRAPHICS_SYSTEM);
    }





    GraphicsSystemResource& GetGraphicsSystemResource()
    {
        ;
        return GetBaseResource(BASERESOURCE_GRAPHICS_SYSTEM);
    }





    GraphicsLocalResource GetGraphicsLocalResource() const
    {
        ;
        return GetBaseResource(BASERESOURCE_GRAPHICS_LOCAL);
    }





    GraphicsLocalResource& GetGraphicsLocalResource()
    {
        ;
        return GetBaseResource(BASERESOURCE_GRAPHICS_LOCAL);
    }





    static const RwChar* GetBaseResourceTypeName(uint32_t index)
    {
        ;
        ;
        return BASERESOURCE_BASERESOURCETYPENAMES[index];
    }





    static bool IsBaseResourceTypeUninitialized(uint32_t index)
    {
        ;
        return (index == BASERESOURCE_UNINITIALIZED) || (index == BASERESOURCE_DISPOSABLE_UNINITIALIZED);
    }





    static bool IsBaseResourceTypeDisposable(uint32_t index)
    {
        ;
        return (index == BASERESOURCE_DISPOSABLE) || (index == BASERESOURCE_DISPOSABLE_UNINITIALIZED);
    }
};




inline Resource operator+(const Resource& resource, const ResourceDescriptor& descriptor)
{
    ;
    Resource sum = resource;
    sum += descriptor;
    return sum;
}







inline ResourceDescriptor operator-(const Resource& lhs, const Resource& rhs)
{
    ;
    ResourceDescriptor diff;
    for (uint32_t i = 0; i < BASERESOURCE_NUMBEROFBASERESOURCETYPES; ++i)
    {
        uint32_t sizeDiff = MemCalculateOffset(lhs.GetBaseResource(i), rhs.GetBaseResource(i));
        diff.GetBaseResourceDescriptor(i) = BaseResourceDescriptor(sizeDiff, 1);
    }
    return diff;
}




}
