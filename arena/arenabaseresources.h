





























namespace rw
{
namespace core
{
namespace arena
{






































extern void
rw_RegisterBaseResourceTypes();




inline RwBool
IsTypeIdOfMemoryResource(uint32_t typeId)
{
    ;
    return (RwBool)((typeId < RWOBJECTTYPE_BASERESOURCE_START) || (typeId > RWOBJECTTYPE_BASERESOURCE_RESERVEDTO));

}




inline RwBool
IsIndexOfMemoryResource(uint32_t objectIndex)
{
    ;
    return (RwBool)((objectIndex == 0) || (objectIndex >= Resource::GetNumberOfBaseResourceTypes()));
}




inline uint32_t
BaseResourceIndexToTypeId(uint32_t typeIndex)
{
    ;

    if (typeIndex == 0)
    {
        return RWOBJECTTYPE_NULL;
    }
    else
    {
        return RWOBJECTTYPE_BASERESOURCE_START + typeIndex - 1;
    }
}




inline uint32_t
TypeIdToBaseResourceIndex(uint32_t typeId)
{
    ;

    if (IsTypeIdOfMemoryResource(typeId))
    {
        return 0;
    }
    else
    {
        return typeId - RWOBJECTTYPE_BASERESOURCE_START + 1;
    }
}






template<class ArenaBaseResourceAdder>
void
AddResourceToArena(const Resource& resource, const ResourceDescriptor& descriptor,
                   uint32_t mainTypeId,
                   ArenaBaseResourceAdder& adder)
{
    ;


    for (uint32_t i = 1; i < ResourceDescriptor::GetNumberOfBaseResourceTypes(); ++i)
    {
        BaseResource baseResource = resource.GetBaseResource(i);
        if (baseResource)
        {
            BaseResourceDescriptor baseResourceDescriptor = descriptor.GetBaseResourceDescriptor(i);
            uint32_t baseResourceTypeId = BaseResourceIndexToTypeId(i);
            adder.Add(baseResource, baseResourceDescriptor, baseResourceTypeId);
        }
    }

    adder.Add(resource.GetMemoryResource(), descriptor.GetMemoryResourceDescriptor(), mainTypeId);

    return;
}









template <class Reader>
void
ArenaAllocatingRead(Reader& input,
                    Resource &resource,
                    ResourceDescriptor &descriptor,
                    IResourceAllocator &allocator=GetDefaultAllocator())
{
    ;

    SharedResource<Arena> retVal;

    Arena header;
    input.ReadHeader(header);

    descriptor = header.GetResourceDescriptor();

    descriptor.EndianSwap();

    resource = allocator.Allocate(descriptor);
    memcpy(resource.GetMemoryResource(), &header, sizeof(header));

    input.ReadRemainingMainMemory(MemAddOffset(resource.GetMemoryResource(), sizeof(header)),
                                  descriptor.GetMemoryResourceDescriptor().GetSize()-sizeof(header));


    for (uint32_t i = 1; i < Resource::GetNumberOfBaseResourceTypes(); ++i)
    {
        if (!Resource::IsBaseResourceTypeUninitialized(i))
        {
            input.ReadBaseResource(BaseResourceIndexToTypeId(i),
                                   resource,
                                   resource.GetBaseResource(i),
                                   descriptor.GetBaseResourceDescriptor(i).GetSize());
        }
    }

    return;
}




class ArenaReaderFromMemoryResource
{
public:



    ArenaReaderFromMemoryResource(const BaseResource &resource, const BaseResourceDescriptor &descriptor)
        : m_resource(resource), m_descriptor(descriptor), m_pos(0)
    {
        ;
        return;
    }




    void
    ReadHeader(Arena& header)
    {
        ;
        ;
        memcpy(&header, MemAddOffset(m_resource, m_pos), sizeof(header));
        m_pos += sizeof(header);
        return;
    }




    void
    ReadRemainingMainMemory(BaseResource dest, uint32_t remainingMainMemorySize)
    {
        ;
        ;
        memcpy(dest, MemAddOffset(m_resource, m_pos), remainingMainMemorySize);
        m_pos += remainingMainMemorySize;
        return;
    }




    void
    ReadBaseResource(uint32_t ,
                     Resource& ,
                     void *destAsPtr,
                     uint32_t size)
    {
        ;
        ;
        memcpy(destAsPtr, MemAddOffset(m_resource, m_pos), size);
        m_pos += size;
        return;
    }

private:
    BaseResource m_resource;
    BaseResourceDescriptor m_descriptor;
    uint32_t m_pos;
};

}
}
}



namespace rw
{
namespace core
{
namespace arena
{






extern RwBool
ArenaAccumulateNextResource(uint32_t currentIndex,
                            ArenaDictEntry *dictStart,
                            const ArenaDictEntry *end,
                            Resource& resource,
                            ArenaDictEntry *&currentRetval,
                            uint32_t &nextIndex);


extern ResourceDescriptor
ArenaAccumulateResourceDescriptorForExportedObject(ArenaDictEntry *current, ArenaDictEntry *dictionaryStart);

extern Resource
ArenaAccumulateResourceForExportedObject(ArenaDictEntry *current, ArenaDictEntry *dictionaryStart);


extern ResourceDescriptor
ArenaCalculateFinalResourceDescriptor(ArenaIterator *iterator);


extern void
ArenaWriteAdditionalBaseResources(Arena &arena, ArenaIterator *iterator);

}
}
}
