


















namespace CgsResource
{
    class RwVertexBufferResourceType;
    class RwRenderableResourceType;
}

namespace rw
{
namespace graphics
{
namespace core
{































class VertexBuffer
{

    friend class CgsResource::RwVertexBufferResourceType;
    friend class CgsResource::RwRenderableResourceType;

public:

    static const uint32_t MAXNUMELEMENTS = 16;


    static const uint32_t FLAG_DONTALLOCATE = 0x0001;
    static const uint32_t FLAG_SYSTEM = 0x0002;



    static const uint32_t TYPE_STATIC = 1;
    static const uint32_t TYPE_DYNAMIC = 2;
    static const uint32_t TYPE_MASK = 3;
    static const uint32_t TYPE_MAX = 3;


    static const uint32_t LOCK_READ = (0x00000001u);
    static const uint32_t LOCK_WRITE = (0x00000002u);
    static const uint32_t LOCK_DISCARD = (0x00000004u);
    static const uint32_t LOCK_NOOVERWRITE = (0x00000008u);
    static const uint32_t LOCK_READWRITE = (LOCK_READ | LOCK_WRITE);




    class Parameters
    {
    public:


        Parameters();

        void SetType(uint32_t tp);
        void SetBufferSize(uint32_t bytes);

        uint32_t GetType() const;
        uint32_t GetBufferSize() const;

    public:

        void PS3SetFlags(uint32_t flags);
        uint32_t PS3GetFlags() const;
        uint32_t PS3GetFlagsFromType() const;

        uint32_t flags;
        uint32_t type;
        uint32_t bufferSize;

        friend class VertexBuffer;
    };




    class BatchIterator
    {
    public:

        VertexBuffer::BatchIterator::BatchIterator();
        VertexBuffer::BatchIterator::BatchIterator(const BatchIterator &iterator);




        template <class VI> bool BeginBatch(uint32_t &batchSize, VI &vertexIterator);
        template <class VI> void EndBatch(VI &);

        void *BatchIterator::GetLockedBuffer() const;
        uint32_t GetLockedBufferSize() const;
        uint32_t GetFlags() const;

    protected:

        void Initialize(void *lockedBuffer, uint32_t bufferSize, VertexBuffer *vb, uint32_t flags);

        uint32_t m_flags;
        uint32_t m_bufferSize;
        uint8_t *m_lockedBuffer;
        VertexBuffer *m_vb;





        friend class VertexBuffer;
    };


    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static VertexBuffer *Initialize(const rw::Resource &resource, const Parameters &params);
    static void Destruct(VertexBuffer *ptr);
    void Release();
    void GetParameters(Parameters &params) const;

    bool Lock(const uint32_t flags, BatchIterator &batchIterator, uint32_t regionOffset, uint32_t regionSize);
    void Unlock(const BatchIterator &batchIterator);
    uint32_t GetType() const;
    uint32_t GetBufferSize() const;

    void SetDefaultStride(uint32_t stride);
    uint32_t GetDefaultStride() const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();

    void *PS3GetBuffer();
    uint32_t PS3GetOffset();
    uint8_t PS3GetLocation() const;

public:

    VertexBuffer();
    VertexBuffer(const VertexBuffer &vertexBuffer);
    ~VertexBuffer();


    void* m_buffer;
    uint32_t m_offset;
    uint32_t m_bufferSize;

    uint16_t m_defaultStride;
    uint8_t m_location;
    uint8_t m_lockFlags;

    friend class rw::graphics::core::Device;
};





inline
VertexBuffer::Parameters::Parameters() :
    flags(0),
    type(TYPE_STATIC),
    bufferSize(0)
{ }

inline void
VertexBuffer::Parameters::SetType(uint32_t t)
{
    ;
    type = t;
    return;
}

inline void
VertexBuffer::Parameters::SetBufferSize(uint32_t bytes)
{
    ;
    bufferSize = bytes;
    return;
}

inline void
VertexBuffer::Parameters::PS3SetFlags(uint32_t f)
{
    ;
    flags = f;
    return;
}


inline uint32_t
VertexBuffer::Parameters::GetType() const
{
    ;
    return type;
}

inline uint32_t
VertexBuffer::Parameters::GetBufferSize() const
{
    ;
    return bufferSize;
}

inline uint32_t
VertexBuffer::Parameters::PS3GetFlags() const
{
    ;
    return flags;
}





inline
VertexBuffer::BatchIterator::BatchIterator()
{
    ;



    return;
}

inline
VertexBuffer::BatchIterator::BatchIterator(const BatchIterator &iterator)
{
    ;
    *this = iterator;
    return;
}











template <class VI> inline bool
VertexBuffer::BatchIterator::BeginBatch(uint32_t &batchSize, VI &vertexIterator)
{
    ;





    batchSize = m_bufferSize;
    vertexIterator.SetBuffer(m_lockedBuffer);
    return true;
}

template <class VI> inline void
VertexBuffer::BatchIterator::EndBatch(VI &)
{
    ;




    return;
}

inline void *
VertexBuffer::BatchIterator::GetLockedBuffer() const
{
    ;
    return reinterpret_cast<void *>(m_lockedBuffer);
}

inline uint32_t
VertexBuffer::BatchIterator::GetLockedBufferSize() const
{
    ;

    return m_bufferSize;
}

inline uint32_t
VertexBuffer::BatchIterator::GetFlags() const
{
    ;
    return m_flags;
}

inline void
VertexBuffer::BatchIterator::Initialize(void *lockedBuffer, uint32_t bufferSize, VertexBuffer *vb, uint32_t flags)
{
    ;
    m_lockedBuffer = reinterpret_cast<uint8_t *>(lockedBuffer);
    m_bufferSize = bufferSize;
    m_flags = flags;
    m_vb = vb;
    return;
};





inline void
VertexBuffer::SetDefaultStride(uint32_t stride)
{
    ;
    m_defaultStride = (uint8_t )stride;
    return;
}

inline uint32_t
VertexBuffer::GetBufferSize() const
{
    ;
    return m_bufferSize;
}

inline uint32_t
VertexBuffer::GetDefaultStride() const
{
    ;
    return m_defaultStride;
}

inline void *
VertexBuffer::PS3GetBuffer()
{
    ;
    return m_buffer;
}

inline uint32_t
VertexBuffer::PS3GetOffset()
{
    ;
    return m_offset;
}

inline uint8_t
VertexBuffer::PS3GetLocation() const
{
    ;
    return m_location;
}

}
}
}
