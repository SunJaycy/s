





















namespace rw
{






 namespace core
 {
























class GeneralResourceAllocator : public rw::IResourceAllocator
{
public:

    void Release();
    static rw::ResourceDescriptor GeneralResourceAllocator::GetResourceDescriptor(const rw::ResourceDescriptor& heapCapacityRequired);
    static GeneralResourceAllocator* GeneralResourceAllocator::Initialize(const rw::Resource& resource, const rw::ResourceDescriptor& heapCapacityRequired);
    static rw::ResourceDescriptor GeneralResourceAllocator::GetResourceDescriptor(uint32_t heapSize, uint32_t heapAlignment);
    static GeneralResourceAllocator* GeneralResourceAllocator::Initialize(const rw::Resource& resource, uint32_t heapSize, uint32_t heapAlignment);








    rw::core::GeneralAllocator* GetGeneralAllocator();





protected:

    Resource DoAllocate(const ResourceDescriptor &resourceDescriptor, const char8_t *name);
    void DoFree(const Resource &resource);

    virtual ~GeneralResourceAllocator();


    GeneralResourceAllocator(const GeneralResourceAllocator &);
    GeneralResourceAllocator & operator=(const GeneralResourceAllocator &);

private:
    GeneralResourceAllocator(const rw::Resource& heapResource, const rw::ResourceDescriptor& heapCapacity);







    rw::core::GeneralAllocator pAllocator;





};



 }

}
