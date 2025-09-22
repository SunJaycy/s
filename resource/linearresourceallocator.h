
























namespace rw
{
































class LinearResourceAllocator : public IResourceAllocator
{
public:
    struct RestorePoint
    {
        ResourceDescriptor currentUsage;
        ResourceDescriptor paddingUsed;
        uint32_t numAllocations;
    };




    static rw::ResourceDescriptor GetResourceDescriptor(const ResourceDescriptor& heapCapacityRequired);
    static LinearResourceAllocator* Initialize(const rw::Resource& resource,
                                                   const ResourceDescriptor& heapCapacityRequired);




    static rw::ResourceDescriptor GetResourceDescriptor(const Resource &heapResource,
                                                        const ResourceDescriptor& heapResourceDescriptor);
    static LinearResourceAllocator* Initialize(const rw::Resource& resource,
                                               const Resource& heapResource,
                                               const ResourceDescriptor& heapResourceDescriptor);

    static rw::ResourceDescriptor GetResourceDescriptor(uint32_t heapSize, uint32_t heapAlignment);
    static LinearResourceAllocator* Initialize(const rw::Resource& resource,
                                                   uint32_t heapSize, uint32_t heapAlignment);
    void Release();

    ResourceDescriptor
    GetCapacity() const;

    ResourceDescriptor
    GetCurrentUsage() const;

    ResourceDescriptor
    GetAvailable() const;

    uint32_t
    GetNumAllocations() const;

    ResourceDescriptor
    GetPaddingUsed() const;

    void
    GetRestorePoint(RestorePoint& restorePoint) const;

    void
    Clear(const RestorePoint& restorePoint);

    void
    Clear();

    const Resource&
    GetLinearHeapBase(void) const;


protected:

    Resource DoAllocate(const ResourceDescriptor &resourceDescriptor, const char8_t *name);
    void DoFree(const Resource &resource);


private:
    LinearResourceAllocator(const Resource& heapResource, const ResourceDescriptor& heapCapacity);
    virtual ~LinearResourceAllocator();


    LinearResourceAllocator(const LinearResourceAllocator& other);
    LinearResourceAllocator operator=(const LinearResourceAllocator& other);

    Resource m_heapResource;
    ResourceDescriptor m_heapCapacity;
    ResourceDescriptor m_currentUsage;
    ResourceDescriptor m_paddingUsed;
    uint32_t m_numAllocations;
};



}
