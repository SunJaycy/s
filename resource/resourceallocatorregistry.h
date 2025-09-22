

























namespace rw
{




























class ResourceAllocatorRegistry
{
public:
    static IResourceAllocator& GetDefaultAllocator();
    static void SetDefaultAllocator(IResourceAllocator *allocator);









private:
    ResourceAllocatorRegistry();

    static SystemAllocator DefaultSystemAllocator;
    static IResourceAllocator *s_defaultAllocator;




    friend struct DefaultSystemAllocatorInitializer;

};





inline IResourceAllocator&
GetDefaultAllocator()
{
    ;
    return ResourceAllocatorRegistry::GetDefaultAllocator();
}














}
