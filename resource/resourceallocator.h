























namespace rw
{












































class IResourceAllocator
{
public:



    virtual ~IResourceAllocator()
    {
        ;
        return;
    }








    Resource Allocate(const ResourceDescriptor &resourceDescriptor, const char8_t *name = 0)
    {
        ;

















        return DoAllocate(resourceDescriptor, name);

    }






    void Free(const Resource& resource)
    {
        ;
        DoFree(resource);
        return;
    }






    void Free(void *ptr)
    {
        ;
        DoFree(Resource(ptr));
        return;
    }









    void FreeDisposable(Resource& resource)
    {
        ;
        DoFreeDisposable(resource);
        return;
    }






    MemoryResource AllocateMemoryResource(uint32_t size, uint32_t alignment, const char8_t *name = 0)
    {
        ;
        return DoAllocate(ResourceDescriptor(size, alignment), name).GetMemoryResource();
    }





    void FreeMemoryResource(MemoryResource memoryResource)
    {
        ;
        Resource resource;
        resource.GetMemoryResource() = memoryResource;
        return DoFree(resource);
    }






    DisposableResource AllocateDisposable(uint32_t size, uint32_t alignment, const char8_t *name = 0)
    {
        ;
        ResourceDescriptor descriptor;
        descriptor.GetDisposableResourceDescriptor() = DisposableResourceDescriptor(size, alignment);
        return DoAllocate(descriptor, name).GetDisposableResource();
    }





    void FreeDisposableResource(DisposableResource disposableResource)
    {
        ;
        Resource resource;
        resource.GetDisposableResource() = disposableResource;
        return DoFree(resource);
    }

























































    virtual void PS3GraphicsSystemMemoryInitialize(void *, uint32_t) { };
    virtual void PS3GraphicsLocalMemoryInitialize(void *, uint32_t) { };



 protected:









    virtual Resource DoAllocate(const ResourceDescriptor &resourceDescriptor,
                                const char8_t *name = 0) = 0;







    virtual void DoFree(const Resource& resource) = 0;








    virtual void DoFreeDisposable(Resource& resource)
    {
        ;
        Resource newResource;
        for (uint32_t i = 0; i < ResourceDescriptor::GetNumberOfBaseResourceTypes(); ++i)
        {
            if (Resource::IsBaseResourceTypeDisposable(i))
            {
                newResource.GetBaseResource(i) = resource.GetBaseResource(i);
                resource.GetBaseResource(i) = (void*)0;
            }
        }
        DoFree(newResource);
        return;
    }

};




}
