





namespace rw
{
namespace datacontainer
{



static const size_t BUFFERALIGNMENT = 1;
static const size_t BUFFERPADDING = 0;
static const size_t TRANSFERSIZE = 1;
















struct Extents
{
    void* minimum;
    void* maximumAllocated;
    void* maximumUsed;
    uint32_t dimension0;
    uint32_t dimension1;
};








class BufferParameters
{
public:

    BufferParameters();
    BufferParameters(uint32_t id, uint32_t size, uint32_t memoryType = rw::BASERESOURCE_MAINMEMORY);
    BufferParameters(uint32_t id, uint32_t size, uint32_t width, uint32_t memoryType = rw::BASERESOURCE_MAINMEMORY);
    BufferParameters(uint32_t id, uint32_t size, uint32_t width, uint32_t height, uint32_t memoryType = rw::BASERESOURCE_MAINMEMORY);


    uint32_t GetId() const;
    uint32_t GetSize() const;
    uint32_t GetMemoryType() const;
    uint32_t GetDimension0() const;
    uint32_t GetDimension1() const;


    void EndianSwap();
    template<class POINTERRESOLVER> void Unfix(POINTERRESOLVER &resolver);
    template<class POINTERRESOLVER> void Fixup(POINTERRESOLVER &resolver);

private:
    uint32_t mId;
    uint32_t mSize;
    uint32_t mMemoryType;
    uint32_t mDimension0;
    uint32_t mDimension1;
};




inline BufferParameters::BufferParameters()
{
}




inline BufferParameters::BufferParameters(uint32_t id, uint32_t size, uint32_t memoryType)
: mId(id), mSize(size), mMemoryType(memoryType), mDimension0(1), mDimension1(1)
{
}




inline BufferParameters::BufferParameters(uint32_t id, uint32_t size, uint32_t width, uint32_t memoryType)
: mId(id), mSize(size), mMemoryType(memoryType), mDimension0(1), mDimension1(width)
{
}




inline BufferParameters::BufferParameters(uint32_t id, uint32_t size, uint32_t width, uint32_t height, uint32_t memoryType)
: mId(id), mSize(size), mMemoryType(memoryType), mDimension0(width), mDimension1(height)
{
}




inline uint32_t BufferParameters::GetId() const
{
    return mId;
}




inline uint32_t BufferParameters::GetSize() const
{
    return mSize;
}




inline uint32_t BufferParameters::GetMemoryType() const
{
    return mMemoryType;
}




inline uint32_t BufferParameters::GetDimension0() const
{
    return mDimension0;
}




inline uint32_t BufferParameters::GetDimension1() const
{
    return mDimension1;
}




inline void BufferParameters::EndianSwap()
{
    ;
    ;
    ;
    ;
    ;
}




template<class POINTERRESOLVER>
inline void BufferParameters::Unfix(POINTERRESOLVER &)
{
}




template<class POINTERRESOLVER>
inline void BufferParameters::Fixup(POINTERRESOLVER &)
{
}









class BufferLockParameters
{
public:
    explicit BufferLockParameters(uint32_t jobId);
    uint32_t GetJobId() const;
private:
    uint32_t mJobId;
};




inline BufferLockParameters::BufferLockParameters(uint32_t jobId) : mJobId(jobId)
{
}




inline uint32_t BufferLockParameters::GetJobId() const
{
    return mJobId;
}









class Buffer
{
public:

    typedef BufferParameters Parameters;
    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &parameters);
    static Buffer *Initialize(rw::Resource &resource, const Parameters &parameters);
    void Release();


    void GetParameters(Parameters &parameters) const;


    typedef BufferLockParameters LockParameters;
    template<class ACCESSOR> bool Lock(ACCESSOR &accessor, const LockParameters &lockParameters);
    template<class ACCESSOR> void Unlock(const ACCESSOR &accessor);


    void EndianSwap();
    template<class POINTERRESOLVER> void Unfix(POINTERRESOLVER &resolver);
    template<class POINTERRESOLVER> void Fixup(POINTERRESOLVER &resolver);

private:
    void* mMinimum;
    void* mMaximumAllocated;
    void* mMaximumUsed;
    Parameters mParameters;
};




inline rw::ResourceDescriptor Buffer::GetResourceDescriptor(const Parameters &parameters)
{
    return rw::ResourceDescriptor(sizeof(Buffer), __alignof(Buffer))
        + rw::ResourceDescriptor(rw::SizeAlign(parameters.GetSize(), TRANSFERSIZE) + BUFFERPADDING, BUFFERALIGNMENT);
}




inline Buffer *Buffer::Initialize(rw::Resource &resource, const Parameters &parameters)
{
    rw::Resource dataResource = resource
        + rw::ResourceDescriptor(sizeof(Buffer), __alignof(Buffer)) + rw::ResourceDescriptor(0, BUFFERALIGNMENT);
    Buffer *buffer = reinterpret_cast<Buffer *>(resource.GetMemoryResource());
    buffer->mMinimum = dataResource.GetMemoryResource();
    buffer->mMaximumAllocated = rw::MemAddOffset(dataResource.GetMemoryResource(), parameters.GetSize());
    buffer->mMaximumUsed = dataResource.GetMemoryResource();
    buffer->mParameters = parameters;
    return buffer;
}




inline void Buffer::Release()
{
}




inline void Buffer::GetParameters(Parameters &parameters) const
{
    parameters = mParameters;
}




template<class ACCESSOR>
inline bool Buffer::Lock(ACCESSOR &accessor, const LockParameters &lockParameters)
{
    (void)lockParameters;
    accessor.Initialize(this, lockParameters.GetJobId());








    return true;
}




template<class ACCESSOR>
inline void Buffer::Unlock(const ACCESSOR &accessor)
{
    (void)accessor;











}




inline void Buffer::EndianSwap()
{
    ;
    ;
    ;
    mParameters.EndianSwap();
}




template<class POINTERRESOLVER>
inline void Buffer::Unfix(POINTERRESOLVER &resolver)
{
    mMinimum = resolver.PointerToOffset(mMinimum, mParameters.GetMemoryType());
    mMaximumAllocated = resolver.PointerToOffset(mMaximumAllocated, mParameters.GetMemoryType());
    mMaximumUsed = resolver.PointerToOffset(mMaximumUsed, mParameters.GetMemoryType());
    mParameters.Unfix(resolver);
}




template<class POINTERRESOLVER>
inline void Buffer::Fixup(POINTERRESOLVER &resolver)
{
    mParameters.Fixup(resolver);
    mMinimum = resolver.OffsetToPointer(mMinimum, mParameters.GetMemoryType());
    mMaximumAllocated = resolver.OffsetToPointer(mMaximumAllocated, mParameters.GetMemoryType());
    mMaximumUsed = resolver.OffsetToPointer(mMaximumUsed, mParameters.GetMemoryType());
}


}
}
