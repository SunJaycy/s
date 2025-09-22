












namespace rw
{
namespace graphics
{
namespace core
{

class Texture2D;
class Texture3D;
class TextureCube;





class Texture
{
public:

    static const uint32_t MaxSize = 4096u;
    static const uint32_t PS3MaxNumMipLevels = 13u;

    static const uint32_t FLAG_DONTALLOCATE = 0x0001;
    static const uint32_t FLAG_RENDERABLE = 0x0002;
    static const uint32_t FLAG_PS3RENDERABLEDEPTH = 0x0004;
    static const uint32_t FLAG_SYSTEM = 0x0008;
    static const uint32_t FLAG_DYNAMIC = FLAG_SYSTEM;

    static const uint32_t ALL_MIP_LEVELS = 0;

    static const uint32_t LOCK_READ = (0x00000001u);
    static const uint32_t LOCK_WRITE = (0x00000002u);
    static const uint32_t LOCK_READWRITE = (LOCK_READ | LOCK_WRITE);




    enum Type
    {
        TYPE_NA = -1,

        TYPE_1D = 0x00001,
        TYPE_2D = 0x00002,
        TYPE_CUBE = 0x10002,
        TYPE_3D = 0x00003,

        TYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    enum PS3Dimension
    {
        PS3DIMENSION_TEXTURE_DIMENSION_1 = (1),
        PS3DIMENSION_TEXTURE_DIMENSION_2 = (2),
        PS3DIMENSION_TEXTURE_DIMENSION_3 = (3),
    };

    struct Parameters
    {
        Parameters() : type(TYPE_NA),
                       flags(0),
                       width(0),
                       height(0),
                       depth(1),
                       pitch(0),
                       mipLevels(0),
                       format(static_cast<PixelFormat>(0)),
                       multiSampleType(MULTISAMPLETYPE_NONE),
                       tileIndex(-1)
        { }

        void SetType(Type t);
        void SetFlags(uint32_t f);
        void SetWidth(uint32_t w);
        void SetHeight(uint32_t h);
        void SetDepth(uint32_t d);
        void SetPitch(uint32_t pitch);
        void SetMipLevels(uint32_t ml);
        void SetFormat(PixelFormat fmt);
        void PS3SetMultiSampleType(uint32_t mst);
        void PS3SetTileIndex(int8_t t);

        Type GetType() const;
        uint32_t GetFlags() const;
        uint32_t GetWidth() const;
        uint32_t GetHeight() const;
        uint32_t GetDepth() const;
        uint32_t GetPitch() const;
        uint32_t GetMipLevels() const;
        PixelFormat GetFormat() const;

        uint32_t PS3GetMultiSampleType() const;
        uint8_t PS3GetTileIndex() const;

    protected:

        void PS3ConvertToPixelBufferParams(PixelBuffer::Parameters &pbParams) const;





        Type type;
        uint32_t flags;
        uint32_t width;
        uint32_t height;
        uint32_t depth;
        uint32_t pitch;
        uint32_t mipLevels;
        PixelFormat format;


        uint8_t multiSampleType;
        int8_t tileIndex;

        friend class rw::graphics::core::Texture;
        friend class rw::graphics::core::Texture2D;
        friend class rw::graphics::core::Texture3D;
        friend class rw::graphics::core::TextureCube;
    };

    struct Locked
    {
        Texture *texture;
        void *pixelData;
        uint32_t stride;
        uint16_t width;
        uint16_t height;
        uint16_t volumeDepth;
        uint8_t mipLevel;
        uint8_t index;
        uint32_t sliceStride;
        uint32_t lockFlags;
    };




    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static Texture *Initialize(const rw::Resource &resource, const Parameters &params);
    static void Destruct(Texture *texture);
    void Release();

    void GetParameters(Parameters &parameters) const;
    Type GetType() const;

    uint32_t GetWidth() const;
    uint32_t GetHeight() const;
    uint32_t GetDepth() const;
    uint32_t GetNumMipLevels() const;
    uint32_t GetArraySize() const;

    bool Lock(uint32_t lockFlags,
              uint32_t mipLevel,
              uint32_t index,
              Locked &locked);
    void Unlock(const Locked &locked);

    rw::ResourceDescriptor GetPixelBufferResourceDescriptor(uint32_t mipLevel, uint32_t index) const;
    PixelBuffer *InitializePixelBuffer(const rw::Resource &resource, uint32_t mipLevel, uint32_t index) const;

    rw::ResourceDescriptor GetPixelBufferResourceDescriptor(uint32_t mipLevel, uint32_t index, PixelBuffer::Parameters &parameters) const;
    PixelBuffer *InitializePixelBuffer(const rw::Resource &resource, uint32_t mipLevel, uint32_t index, PixelBuffer::Parameters &parameters) const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();






    static uint32_t GetDefaultNumMipLevels(uint32_t width, uint32_t height);


    static uint8_t PS3DimensionFromType(Texture::Type type);
    static uint8_t PS3CubeMapFromType(Texture::Type type);

    static uint16_t PS3CalculateMipLinearDimension(uint16_t dimension, uint8_t mipIndex);
    static uint16_t PS3CalculateMipSwizzledDimension(uint16_t dimension, uint8_t mipIndex);
    static uint16_t PS3CalculateMipCompressedDimension(uint16_t dimension, uint8_t mipIndex);

    static uint32_t PS3CalculateMipLinearBufferSize
        (uint16_t width, uint16_t height, uint16_t depth, uint32_t pitch, uint8_t mipIndex);
    static uint32_t PS3CalculateMipSwizzledBufferSize
        (uint16_t width, uint16_t height, uint16_t depth, uint32_t pitch, uint8_t mipIndex);
    static uint32_t PS3CalculateMipCompressedBufferSize
        (uint16_t width, uint16_t height, uint16_t depth, uint32_t bitsPerPixel, uint8_t mipIndex);

    static uint32_t PS3CalculateLinearBufferSize
        (uint16_t width, uint16_t height, uint16_t depth, uint32_t pitch, Type type, uint8_t numMipMaps);
    static uint32_t PS3CalculateSwizzledBufferSize
        (uint16_t width, uint16_t height, uint16_t depth, uint32_t pitch, Type type, uint8_t numMipMaps);
    static uint32_t PS3CalculateCompressedBufferSize
        (uint16_t width, uint16_t height, uint16_t depth, uint32_t bitsPerPixel, Type type, uint8_t numMipMaps);

    static uint32_t PS3CalculateLinearBufferOffset
        (uint16_t width, uint16_t height, uint16_t depth, uint32_t pitch, Type type, uint8_t numMipMaps,
         uint8_t mipIndex, uint32_t face);
    static uint32_t PS3CalculateSwizzledBufferOffset
        (uint16_t width, uint16_t height, uint16_t depth, uint32_t pitch, Type type, uint8_t numMipMaps,
         uint8_t mipIndex, uint32_t face);
    static uint32_t PS3CalculateCompressedBufferOffset
        (uint16_t width, uint16_t height, uint16_t depth, uint32_t bitsPerPixel, Type type, uint8_t numMipMaps,
         uint8_t mipIndex, uint32_t face);

    static uint32_t PS3CalculateBufferOffset(uint16_t width,
                                             uint16_t height,
                                             uint16_t depth,
                                             uint32_t pitch,
                                             uint32_t bitsPerPixel,
                                             Type type,
                                             uint8_t numMipMaps,
                                             uint8_t mipIndex,
                                             uint32_t index,
                                             PixelFormat format);

    void PS3CalculatePixelBufferParameters(PixelBuffer::Parameters &parameters, uint8_t mipLevel) const;








    uint8_t m_format;
    uint8_t m_mipmap;
    uint8_t m_dimension;
    uint8_t m_cubemap;

    uint32_t m_remap;

    uint16_t m_width;
    uint16_t m_height;
    uint16_t m_depth;
    uint8_t m_location;
    uint8_t m_padding;

    uint32_t m_pitch;
    uint32_t m_offset;



    void* m_buffer;

    Type m_storeType;
    uint32_t m_storeFlags;









protected:
    Texture();
    Texture(const Texture &texture);
    ~Texture();

    friend class rw::graphics::core::Device;
};




inline void
Texture::Parameters::SetType(Texture::Type t)
{
    ;
    type = t;
    return;
}

inline void
Texture::Parameters::SetFlags(uint32_t f)
{
    ;
    flags = f;
    return;
}

inline void
Texture::Parameters::SetWidth(uint32_t w)
{
    ;
    width = w;
    return;
}

inline void
Texture::Parameters::SetHeight(uint32_t h)
{
    ;
    height = h;
    return;
}

inline void
Texture::Parameters::SetDepth(uint32_t d)
{
    ;
    depth = d;
    return;
}

inline void
Texture::Parameters::SetPitch(uint32_t p)
{
    ;
    pitch = p;
    return;
}

inline void
Texture::Parameters::SetMipLevels(uint32_t ml)
{
    ;
    mipLevels = ml;
    return;
}

inline void
Texture::Parameters::SetFormat(PixelFormat fmt)
{
    ;
    format = fmt;
    return;
}

inline void
Texture::Parameters::PS3SetMultiSampleType(uint32_t mst)
{
    ;
    multiSampleType = (uint8_t )mst;
    return;
}

inline void
Texture::Parameters::PS3SetTileIndex(int8_t t)
{
    ;
    tileIndex = t;
    return;
}

inline Texture::Type
Texture::Parameters::GetType() const
{
    ;
    return type;
}

inline uint32_t
Texture::Parameters::GetFlags() const
{
    ;
    return flags;
}

inline uint32_t
Texture::Parameters::GetWidth() const
{
    ;
    return width;
}

inline uint32_t
Texture::Parameters::GetHeight() const
{
    ;
    return height;
}

inline uint32_t
Texture::Parameters::GetDepth() const
{
    ;
    return depth;
}

inline uint32_t
Texture::Parameters::GetPitch() const
{
    ;
    return pitch;
}

inline uint32_t
Texture::Parameters::GetMipLevels() const
{
    ;
    return mipLevels;
}

inline PixelFormat
Texture::Parameters::GetFormat() const
{
    ;
    return format;
}

inline uint32_t
Texture::Parameters::PS3GetMultiSampleType() const
{
    ;
    return multiSampleType;
}

inline uint8_t
Texture::Parameters::PS3GetTileIndex() const
{
    ;
    return (uint8_t )tileIndex;
}



inline Texture::Type
Texture::GetType() const
{
    ;
    return (Type )m_storeType;
}


inline uint32_t
Texture::GetWidth() const
{
    ;
    return (uint32_t )m_width;
}


inline uint32_t
Texture::GetHeight() const
{
    ;
    return (uint32_t )m_height;
}


inline uint32_t
Texture::GetDepth() const
{
    ;
    return (uint32_t )m_depth;
}


inline uint32_t
Texture::GetNumMipLevels() const
{
    ;
    return (uint32_t )m_mipmap;
}


}
}
}



#include <rw/graphics/core/texture2d.h>
#include <rw/graphics/core/texture3d.h>
#include <rw/graphics/core/texturecube.h>
