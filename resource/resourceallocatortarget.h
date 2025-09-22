













#include <stdio.h>






namespace rw
{






























class SystemAllocatorGeneric : public IResourceAllocator
{
public:



    SystemAllocatorGeneric();




    ~SystemAllocatorGeneric();




    static ResourceDescriptor GetResourceDescriptor();




    static SystemAllocatorGeneric* Initialize(const Resource& resource);





    void PS3GraphicsSystemMemoryInitialize(void *, uint32_t size);




    void PS3GraphicsLocalMemoryInitialize(void *, uint32_t size);


protected:


    Resource
    DoAllocate(const ResourceDescriptor &resourceDescriptor, const char8_t *name);

    void
    DoFree(const Resource &resource);


    static void *m_graphicsSystemStart;
    static uint32_t m_graphicsSystemSize;

    static void *m_graphicsLocalStart;
    static uint32_t m_graphicsLocalSize;


private:

    SystemAllocatorGeneric(const SystemAllocatorGeneric& other);
    SystemAllocatorGeneric operator=(const SystemAllocatorGeneric& other);
};

typedef SystemAllocatorGeneric SystemAllocator;



inline void
SystemAllocatorGeneric::PS3GraphicsSystemMemoryInitialize(void *start, uint32_t size)
{
    ;
    ;
    printf(" Initializing GraphicsSystem memory.  0x%x bytes at %p\n", size, start);
    m_graphicsSystemStart = start;
    m_graphicsSystemSize = size;
    return;
}



inline void
SystemAllocatorGeneric::PS3GraphicsLocalMemoryInitialize(void *start, uint32_t size)
{
    ;
    ;
    printf(" Initializing RSXLocal memory.  0x%x bytes at %p\n", size, start);
    m_graphicsLocalStart = start;
    m_graphicsLocalSize = size;
    return;
}


}
