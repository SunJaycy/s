

















namespace CgsResource
{
    class RwVertexDescResourceType;
}





namespace rw
{
namespace graphics
{
namespace core
{























class VertexDescriptor
{

friend class CgsResource::RwVertexDescResourceType;

public:

    static const uint32_t MaxNumElements = 16;




    enum ElementType
    {
        ELEMENTTYPE_NA = 0xff,

        ELEMENTTYPE_PS3ATTRIBUTE0 = 0,
        ELEMENTTYPE_PS3ATTRIBUTE1 = 1,
        ELEMENTTYPE_PS3ATTRIBUTE2 = 2,
        ELEMENTTYPE_PS3ATTRIBUTE3 = 3,
        ELEMENTTYPE_PS3ATTRIBUTE4 = 4,
        ELEMENTTYPE_PS3ATTRIBUTE5 = 5,
        ELEMENTTYPE_PS3ATTRIBUTE6 = 6,
        ELEMENTTYPE_PS3ATTRIBUTE7 = 7,
        ELEMENTTYPE_PS3ATTRIBUTE8 = 8,
        ELEMENTTYPE_PS3ATTRIBUTE9 = 9,
        ELEMENTTYPE_PS3ATTRIBUTE10 = 10,
        ELEMENTTYPE_PS3ATTRIBUTE11 = 11,
        ELEMENTTYPE_PS3ATTRIBUTE12 = 12,
        ELEMENTTYPE_PS3ATTRIBUTE13 = 13,
        ELEMENTTYPE_PS3ATTRIBUTE14 = 14,
        ELEMENTTYPE_PS3ATTRIBUTE15 = 15,
        ELEMENTTYPE_MAX = 15,
        ELEMENTTYPE_NUM = MaxNumElements,


        ELEMENTTYPE_XYZ = ELEMENTTYPE_PS3ATTRIBUTE0,
        ELEMENTTYPE_NORMAL = ELEMENTTYPE_PS3ATTRIBUTE2,
        ELEMENTTYPE_VERTEXCOLOR = ELEMENTTYPE_PS3ATTRIBUTE3,
        ELEMENTTYPE_TEX0 = ELEMENTTYPE_PS3ATTRIBUTE8,
        ELEMENTTYPE_TEX1 = ELEMENTTYPE_PS3ATTRIBUTE9,
        ELEMENTTYPE_TEX2 = ELEMENTTYPE_PS3ATTRIBUTE10,
        ELEMENTTYPE_TEX3 = ELEMENTTYPE_PS3ATTRIBUTE11,
        ELEMENTTYPE_TEX4 = ELEMENTTYPE_PS3ATTRIBUTE12,
        ELEMENTTYPE_TEX5 = ELEMENTTYPE_PS3ATTRIBUTE13,
        ELEMENTTYPE_TEX6 = ELEMENTTYPE_PS3ATTRIBUTE14,
        ELEMENTTYPE_TEX7 = ELEMENTTYPE_PS3ATTRIBUTE15,


        ELEMENTTYPE_INDICES = ELEMENTTYPE_PS3ATTRIBUTE7,
        ELEMENTTYPE_WEIGHTS = ELEMENTTYPE_PS3ATTRIBUTE1,


        ELEMENTTYPE_TANGENT = ELEMENTTYPE_TEX6,
        ELEMENTTYPE_BINORMAL = ELEMENTTYPE_TEX7,


        ELEMENTTYPE_SPECULAR = ELEMENTTYPE_PS3ATTRIBUTE4,

        ELEMENTTYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    static const uint32_t ELEMENTTYPEFLAG_XYZ = (1 << ELEMENTTYPE_XYZ);
    static const uint32_t ELEMENTTYPEFLAG_NORMAL = (1 << ELEMENTTYPE_NORMAL);
    static const uint32_t ELEMENTTYPEFLAG_VERTEXCOLOR = (1 << ELEMENTTYPE_VERTEXCOLOR);

    static const uint32_t ELEMENTTYPEFLAG_TEX0 = (1 << ELEMENTTYPE_TEX0);
    static const uint32_t ELEMENTTYPEFLAG_TEX1 = (1 << ELEMENTTYPE_TEX1);
    static const uint32_t ELEMENTTYPEFLAG_TEX2 = (1 << ELEMENTTYPE_TEX2);
    static const uint32_t ELEMENTTYPEFLAG_TEX3 = (1 << ELEMENTTYPE_TEX3);
    static const uint32_t ELEMENTTYPEFLAG_TEX4 = (1 << ELEMENTTYPE_TEX4);
    static const uint32_t ELEMENTTYPEFLAG_TEX5 = (1 << ELEMENTTYPE_TEX5);
    static const uint32_t ELEMENTTYPEFLAG_TEX6 = (1 << ELEMENTTYPE_TEX6);
    static const uint32_t ELEMENTTYPEFLAG_TEX7 = (1 << ELEMENTTYPE_TEX7);

    static const uint32_t ELEMENTTYPEFLAG_INDICES = (1 << ELEMENTTYPE_INDICES);
    static const uint32_t ELEMENTTYPEFLAG_WEIGHTS = (1 << ELEMENTTYPE_WEIGHTS);

    static const uint32_t ELEMENTTYPEFLAG_TANGENT = (1 << ELEMENTTYPE_TANGENT);
    static const uint32_t ELEMENTTYPEFLAG_BINORMAL = (1 << ELEMENTTYPE_BINORMAL);
    static const uint32_t ELEMENTTYPEFLAG_SPECULAR = (1 << ELEMENTTYPE_SPECULAR);

    static const uint32_t ELEMENTTYPEFLAG_TEX_MASK = ( ELEMENTTYPEFLAG_TEX0 |
                                                            ELEMENTTYPEFLAG_TEX1 |
                                                            ELEMENTTYPEFLAG_TEX2 |
                                                            ELEMENTTYPEFLAG_TEX3 |
                                                            ELEMENTTYPEFLAG_TEX4 |
                                                            ELEMENTTYPEFLAG_TEX5 |
                                                            ELEMENTTYPEFLAG_TEX6 |
                                                            ELEMENTTYPEFLAG_TEX7 );

    static const uint32_t ELEMENTTYPEFLAG_MASK = ((1 << ELEMENTTYPE_NUM) - 1);










    struct Element
    {
        uint8_t vertexType;
        uint8_t numComponents;
        uint8_t stream;
        uint8_t offset;
        uint8_t type;
        uint8_t pad1;
        uint16_t pad0;
    };





    struct Parameters
    {
        Parameters()
        {
            for (uint32_t n = 0; n < ELEMENTTYPE_NUM; n++)
            {
                elements[n].vertexType = PS3VERTEXTYPE_NA;
                elements[n].numComponents = 0;
                elements[n].stream = 0;
                elements[n].offset = 0xff;
                elements[n].type = 0;
            }
        };

        void SetElementStream(uint32_t elementIndex, uint32_t stream);
        void SetElementOffset(uint32_t elementIndex, uint32_t offset);
        void SetElementFormat(uint32_t elementIndex, VertexFormat format);
        void SetElementType(uint32_t elementIndex, ElementType type);

        uint32_t GetElementStream(uint32_t elementIndex) const;
        uint32_t GetElementOffset(uint32_t elementIndex) const;
        VertexFormat GetElementFormat(uint32_t elementIndex) const;
        ElementType GetElementType(uint32_t elementIndex) const;

    protected:



        uint32_t PS3CountElements() const;
        bool PS3IsAnotherElementOnStream(uint32_t streamIndex, const Element *&element) const;

        Element elements[ELEMENTTYPE_NUM];

        friend class VertexDescriptor;
    };





    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static VertexDescriptor *Initialize(const rw::Resource &resource, const Parameters &params);
    void Release();
    static void Destruct(VertexDescriptor *ptr);

    void GetParameters(Parameters &params) const;


    uint32_t GetNumElements() const;
    const Element *GetElements() const;
    uint32_t GetStride() const;


    static RwBool AreEqual(const VertexDescriptor *vdesc0, const VertexDescriptor *vdesc1);

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();





    uint32_t PS3GetMaxStreamIndex() const;
    uint32_t PS3GetVertexTypesFlags() const;

protected:

    VertexDescriptor();
    VertexDescriptor(const VertexDescriptor &vertexDescriptor);
    ~VertexDescriptor();

protected:
    int32_t m_refCount;
    uint32_t m_typesFlags;
    uint16_t m_maxStreamIndex;
    uint8_t m_numElements;
    uint8_t m_singleVBStride;
    Element m_elements[1];

    friend class rw::graphics::core::Device;
};





inline void
VertexDescriptor::Parameters::SetElementStream(uint32_t elementIndex, uint32_t stream)
{
    ;
    ;
    elements[elementIndex].stream = static_cast<uint8_t>(stream);
    return;
}

inline void
VertexDescriptor::Parameters::SetElementOffset(uint32_t elementIndex, uint32_t offset)
{
    ;
    ;
    elements[elementIndex].offset = static_cast<uint8_t>(offset);
    return;
}

inline void
VertexDescriptor::Parameters::SetElementFormat(uint32_t elementIndex, VertexFormat format)
{
    ;
    ;
    elements[elementIndex].vertexType = ((uint8_t )((uint32_t )(format) >> 8));
    elements[elementIndex].numComponents = ((uint8_t )((uint32_t )(format) & 0xff));
    return;
}

inline void
VertexDescriptor::Parameters::SetElementType(uint32_t elementIndex, ElementType type)
{
    ;
    ;
    elements[elementIndex].type = static_cast<uint8_t>(type);
    return;
}

inline uint32_t
VertexDescriptor::Parameters::GetElementStream(uint32_t elementIndex) const
{
    ;
    ;
    return elements[elementIndex].stream;
}

inline uint32_t
VertexDescriptor::Parameters::GetElementOffset(uint32_t elementIndex) const
{
    ;
    ;
    return elements[elementIndex].offset;
}

inline VertexFormat
VertexDescriptor::Parameters::GetElementFormat(uint32_t elementIndex) const
{
    ;
    ;
    return (VertexFormat ) ((uint32_t )(((elements[elementIndex].vertexType) << 8) | (elements[elementIndex].numComponents)));

}

inline VertexDescriptor::ElementType
VertexDescriptor::Parameters::GetElementType(uint32_t elementIndex) const
{
    ;
    ;
    return static_cast<ElementType>(elements[elementIndex].type);
}





inline uint32_t
VertexDescriptor::PS3GetMaxStreamIndex() const
{
    ;
    return (uint32_t )m_maxStreamIndex;
}

inline uint32_t
VertexDescriptor::PS3GetVertexTypesFlags() const
{
    ;
    return m_typesFlags;
}

}
}
}
