

















#include <rw/core/resource/resourcetarget.h>






namespace rw
{




























typedef void* TargetBaseResource;






class TargetResource
{
public:




    TargetResource()
    {
        ;
        for (uint32_t i = 0; i < ResourceDescriptor::GetNumberOfBaseResourceTypes(); ++i)
        {
            m_baseResources[i] = TargetBaseResource((void*)0);
        }
        return;
    }





    TargetResource(const Resource& resource)
    {
        ;
        for (uint32_t i = 0; i < ResourceDescriptor::GetNumberOfBaseResourceTypes(); ++i)
        {
            m_baseResources[i] = resource.GetBaseResource(i);
        }
        return;
    }





    ~TargetResource()
    {
        ;
        return;
    }








    TargetBaseResource &
    GetTargetBaseResource(uint32_t i)
    {
        ;
        return m_baseResources[i];
    }




    Resource
    ToResource() const
    {
        ;
        Resource resource;
        for (uint32_t i = 0; i < ResourceDescriptor::GetNumberOfBaseResourceTypes(); ++i)
        {
            resource.GetBaseResource(i) = RwPtrToHostPtr(m_baseResources[i]);
        }
        return resource;
    }




    void
    FromResource(const Resource& resource)
    {
        ;
        for (uint32_t i = 0; i < ResourceDescriptor::GetNumberOfBaseResourceTypes(); ++i)
        {
            m_baseResources[i] = resource.GetBaseResource(i);
        }
        return;
    }




    void
    EndianSwap()
    {
        ;
        for (uint32_t i = 0; i < ResourceDescriptor::GetNumberOfBaseResourceTypes(); ++i)
        {
            rw::EndianSwap(m_baseResources[i]);
        }
        return;
    }


private:
    TargetBaseResource m_baseResources[BASERESOURCE_NUMBEROFBASERESOURCETYPES];
};

}
