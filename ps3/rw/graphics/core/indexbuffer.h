

















namespace CgsResource
{
    class RwIndexBufferResourceType;
    class RwRenderableResourceType;
}

namespace rw
{
namespace graphics
{
namespace core
{










































class IndexBuffer
{

friend class CgsResource::RwIndexBufferResourceType;
friend class CgsResource::RwRenderableResourceType;

public:
    static const uint32_t TYPE_STATIC = (0x00000000u);
    static const uint32_t TYPE_DYNAMIC = (0x00000001u);
    static const uint32_t TYPE_MASK = (TYPE_DYNAMIC);

    static const uint32_t LOCK_READ = (0x00000001u);
    static const uint32_t LOCK_WRITE = (0x00000002u);
    static const uint32_t LOCK_READWRITE = (LOCK_READ | LOCK_WRITE);
    static const uint32_t LOCK_NOOVERWRITE = (0x00000008u);

    struct Parameters
    {
        Parameters() : type(TYPE_STATIC), depth(0), numIndices(0)
        { }

        void SetType(uint32_t t);
        void SetDepth(uint32_t de);
        void SetNumIndices(uint32_t num);

        uint32_t GetType() const;
        uint32_t GetDepth() const;
        uint32_t GetNumIndices() const;




        uint32_t type;
        uint32_t depth;
        uint32_t numIndices;
    };




    struct Locked
    {
        void *indices;
        uint32_t indexStride;
    };


    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static IndexBuffer *Initialize(const rw::Resource &resource, const Parameters &params);
    static void Destruct(IndexBuffer *indexBuffer);
    void Release();

    bool Lock(uint32_t flags, Locked &lockedIndexBuffer);
    void Unlock(const Locked &lockedIndexBuffer);
    void GetParameters(Parameters &params) const;
    uint32_t GetNumIndices() const;
    uint32_t GetDepth() const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();



protected:


    IndexBuffer();
    IndexBuffer(const IndexBuffer &indexBuffer);
    ~IndexBuffer();

protected:

    static uint32_t PS3GetIndexStride(uint8_t indexType);
    void PS3EndianSwapBuffer();

    void* m_buffer;

    uint32_t m_offset;
    uint32_t m_numIndices;
    uint32_t m_stride;

    uint8_t m_indexType;
    uint8_t m_location;

    uint8_t m_type;
    uint8_t m_lockFlags;

    friend class rw::graphics::core::Device;
};



inline void
IndexBuffer::Parameters::SetType(uint32_t t)
{
    ;
    type = t;
    return;
}

inline void
IndexBuffer::Parameters::SetDepth(uint32_t de)
{
    ;
    ;
    depth = de;
    return;
}

inline void
IndexBuffer::Parameters::SetNumIndices(uint32_t num)
{
    ;
    numIndices = num;
    return;
}

inline uint32_t
IndexBuffer::Parameters::GetType() const
{
    ;
    return type;
}

inline uint32_t
IndexBuffer::Parameters::GetDepth() const
{
    ;
    return depth;
}

inline uint32_t
IndexBuffer::Parameters::GetNumIndices() const
{
    ;
    return numIndices;
}



inline uint32_t
IndexBuffer::GetNumIndices() const
{
    ;
    return m_numIndices;
}

inline uint32_t
IndexBuffer::GetDepth() const
{
    ;
    return (m_indexType == PS3INDEXTYPE_16)?(16):(32);
}

}
}
}
