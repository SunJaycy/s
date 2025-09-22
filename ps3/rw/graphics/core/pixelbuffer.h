












namespace rw
{
namespace graphics
{
namespace core
{

































class PixelBuffer
{
public:

    static const uint32_t FLAG_DONTALLOCATE = 0x0001;
    static const uint32_t FLAG_SCAN_OUT = 0x0002;
    static const uint32_t FLAG_SYSTEM = 0x0004;

    enum Type
    {
        TYPE_NA = -1,

        TYPE_RENDERTARGET,
        TYPE_DEPTHSTENCIL,

        TYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };


    struct Parameters
    {
        Parameters() :
            type(TYPE_NA),
            flags(0),
            width(0),
            height(0),
            pitch(0),
            format(PIXELFORMAT_NA),
            multiSampleType(MULTISAMPLETYPE_NONE),
            tileIndex(-1),
            displayID(-1),
            zCullIndex(-1),
            zCullAddress(-1),
            zCullDirection(ZCULLDIR_LESS),
            zCullFormat(ZCULLFORMAT_LONES),
            compressionEnable(false),
            compressionBase(0),
            compressionBank(0)
        { }

        void SetType(Type t);
        void SetFlags(uint32_t f);
        void SetWidth(uint32_t w);
        void SetHeight(uint32_t h);
        void SetPitch(uint32_t p);
        void SetFormat(PixelFormat fmt);
        void SetMultiSampleType(uint32_t mst);
        void PS3SetTileIndex(uint8_t t);
        void PS3SetDisplayID(uint8_t d);
        void PS3SetZCullIndex(uint8_t i);
        void PS3SetZCullAddress(uint32_t addr);
        void PS3SetZCullDirection(uint32_t zdir);
        void PS3SetZCullFormat(uint32_t zFormat);
        void PS3SetCompressionEnable(bool enable);
        void PS3SetCompressionBase(uint16_t base);
        void PS3SetCompressionBank(uint8_t bank);

        Type GetType() const;
        uint32_t GetFlags() const;
        uint32_t GetWidth() const;
        uint32_t GetHeight() const;
        uint32_t GetPitch() const;
        PixelFormat GetFormat() const;
        uint32_t GetMultiSampleType() const;
        uint8_t PS3GetTileIndex() const;
        uint8_t PS3GetDisplayID() const;
        uint8_t PS3GetZCullIndex() const;
        uint32_t PS3GetZCullAddress() const;
        uint32_t PS3GetZCullDirection() const;
        uint32_t PS3GetZCullFormat() const;
        bool PS3GetCompressionEnable() const;



        uint8_t PS3GetCompressionMode() const;



        Type type;
        uint32_t flags;

        uint32_t width;
        uint32_t height;
        uint32_t pitch;

        PixelFormat format;
        uint8_t multiSampleType;

        int8_t tileIndex;
        int8_t displayID;
        int8_t zCullIndex;
        int32_t zCullAddress;
        uint32_t zCullDirection;
        uint32_t zCullFormat;
        bool compressionEnable;
        uint16_t compressionBase;
        uint8_t compressionBank;

        friend class PixelBuffer;
    };

    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static PixelBuffer *Initialize(const rw::Resource &resource, const Parameters &params);
    static void Destruct(PixelBuffer *pixelBuffer);
    void Release();
    void GetParameters(Parameters &parameters) const;

    Type GetType() const;
    uint32_t GetWidth() const;
    uint32_t GetHeight() const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();






    struct PS3TextureToSurfaceFormat
    {
        uint32_t textureBaseFormat;
        uint32_t surfaceFormat;
    };
    static const PS3TextureToSurfaceFormat m_pixelFormatToColorSurfaceFormatTable[];
    static const PS3TextureToSurfaceFormat m_pixelFormatToDepthSurfaceFormatTable[];

    static uint32_t PS3PixelFormatToSurfaceFormat(PixelFormat textureFormat);
    static uint32_t PS3GetAAPitchFactor(uint32_t multiSampleType);
    static uint32_t PS3GetAAHeightFactor(uint32_t multiSampleType);

    static uint32_t PS3GetColorDepth(uint32_t format);
    static uint32_t PS3GetDepthStencilDepth(uint32_t format);

    PixelFormat PS3GetFormat() const;
    uint8_t PS3GetSurfaceFormat() const;
    uint32_t PS3GetFlags() const;
    uint16_t PS3GetWidth() const;
    uint16_t PS3GetHeight() const;
    uint32_t PS3GetPitch() const;
    uint8_t PS3GetLocation() const;
    uint32_t PS3GetOffset() const;
    uint8_t PS3GetAntiAliasType() const;
    uint8_t PS3GetDisplayBufferID() const;
    uint32_t PS3IsSwizzled() const;
    void *PS3GetBuffer() const;

    static void PS3CalculateBufferProperties(const Parameters &parameters,
                                             uint32_t &outSize,
                                             uint32_t &outAlignment,
                                             uint32_t &outPitch);


    static rw::ResourceDescriptor PS3GetProxyResourceDescriptor();
    static PixelBuffer *PS3InitializeProxy(rw::Resource const &resource, PixelBuffer const *source);
    void PS3UpdateProxy(PixelBuffer const *source);

protected:







    uint32_t m_offset;
    uint32_t m_size;
    uint16_t m_width;
    uint16_t m_height;


    uint8_t m_displayBufferID;


    uint8_t m_zCullIndex;
    uint32_t m_zCullAddress;
    uint32_t m_zCullDirection;
    uint32_t m_zCullFormat;

    uint32_t m_sFunc;
    uint32_t m_sRef;
    uint32_t m_sMask;


    uint32_t m_tileIndex;
    uint32_t m_pitch;

    uint8_t m_compressionMode;

    uint8_t m_format;
    uint8_t m_location;

    uint8_t m_antiAlias;



    PixelFormat m_pixelFormat;
    Type m_type;
    uint32_t m_flags;

    void* m_buffer;
    uint16_t m_compressionBase;
    uint8_t m_compressionBank;

protected:


    PixelBuffer();
    PixelBuffer(const PixelBuffer &pixelBuffer);
    ~PixelBuffer();

    friend class rw::graphics::core::Device;
    friend class rw::graphics::core::Texture;

};



inline void
PixelBuffer::Parameters::SetType(Type t)
{
    ;
    type = t;
    return;
}

inline void
PixelBuffer::Parameters::SetFlags(uint32_t f)
{
    ;
    flags = f;
    return;
}

inline void
PixelBuffer::Parameters::SetWidth(uint32_t w)
{
    ;
    width = w;
    return;
}

inline void
PixelBuffer::Parameters::SetHeight(uint32_t h)
{
    ;
    height = h;
    return;
}

inline void
PixelBuffer::Parameters::SetPitch(uint32_t p)
{
    ;
    pitch = p;
    return;
}

inline void
PixelBuffer::Parameters::SetFormat(PixelFormat fmt)
{
    ;
    format = fmt;
    return;
}

inline void
PixelBuffer::Parameters::SetMultiSampleType(uint32_t mst)
{
    ;
    multiSampleType = static_cast<uint8_t>(mst);
    return;
}

inline void
PixelBuffer::Parameters::PS3SetTileIndex(uint8_t t)
{
    ;
    tileIndex = (int8_t )t;
    return;
}

inline void
PixelBuffer::Parameters::PS3SetDisplayID(uint8_t d)
{
    ;
    displayID = (int8_t )d;
    return;
}

inline void
PixelBuffer::Parameters::PS3SetZCullIndex(uint8_t i)
{
    ;
    zCullIndex = (int8_t )i;
    return;
}

inline void
PixelBuffer::Parameters::PS3SetZCullAddress(uint32_t addr)
{
    ;
    zCullAddress = (int32_t )addr;
    return;
}

inline void
PixelBuffer::Parameters::PS3SetZCullDirection(uint32_t zdir)
{
    ;
    ;

    zCullDirection = zdir;
    return;
}

inline void
PixelBuffer::Parameters::PS3SetZCullFormat(uint32_t zFormat)
{
    ;
    ;

    zCullFormat = zFormat;
    return;
}

inline void
PixelBuffer::Parameters::PS3SetCompressionEnable(bool compEnable)
{
    ;
    compressionEnable = compEnable;
    return;
}

inline void
PixelBuffer::Parameters::PS3SetCompressionBase(uint16_t base)
{
    ;
    compressionBase = base;
    return;
}

inline void
PixelBuffer::Parameters::PS3SetCompressionBank(uint8_t bank)
{
    ;
    compressionBank = bank;
    return;
}


inline PixelBuffer::Type
PixelBuffer::Parameters::GetType() const
{
    ;
    return type;
}

inline uint32_t
PixelBuffer::Parameters::GetFlags() const
{
    ;
    return flags;
}

inline uint32_t
PixelBuffer::Parameters::GetWidth() const
{
    ;
    return width;
}

inline uint32_t
PixelBuffer::Parameters::GetHeight() const
{
    ;
    return height;
}

inline uint32_t
PixelBuffer::Parameters::GetPitch() const
{
    ;
    return pitch;
}

inline PixelFormat
PixelBuffer::Parameters::GetFormat() const
{
    ;
    return format;
}

inline uint32_t
PixelBuffer::Parameters::GetMultiSampleType() const
{
    ;
    return multiSampleType;
}

inline uint8_t
PixelBuffer::Parameters::PS3GetTileIndex() const
{
    ;
    return (uint8_t )tileIndex;
}

inline uint8_t
PixelBuffer::Parameters::PS3GetDisplayID() const
{
    ;
    return (uint8_t )displayID;
}

inline uint8_t
PixelBuffer::Parameters::PS3GetZCullIndex() const
{
    ;
    return (uint8_t )zCullIndex;
}

inline uint32_t
PixelBuffer::Parameters::PS3GetZCullAddress() const
{
    ;
    return (uint32_t )zCullAddress;
}

inline uint32_t
PixelBuffer::Parameters::PS3GetZCullDirection() const
{
    ;
    return zCullDirection;
}

inline uint32_t
PixelBuffer::Parameters::PS3GetZCullFormat() const
{
    ;
    return zCullFormat;
}

inline bool
PixelBuffer::Parameters::PS3GetCompressionEnable() const
{
    ;
    return compressionEnable;
}



inline PixelBuffer::Type
PixelBuffer::GetType() const
{
    ;
    return m_type;
}

inline uint32_t
PixelBuffer::GetWidth() const
{
    ;
    return m_width;
}

inline uint32_t
PixelBuffer::GetHeight() const
{
    ;
    return m_height;
}

inline PixelFormat
PixelBuffer::PS3GetFormat() const
{
    ;
    return m_pixelFormat;
}

inline uint8_t
PixelBuffer::PS3GetSurfaceFormat() const
{
    ;
    return m_format;
}

inline uint32_t
PixelBuffer::PS3GetFlags() const
{
    ;
    return m_flags;
}

inline uint16_t
PixelBuffer::PS3GetWidth() const
{
    ;
    return m_width;
}

inline uint16_t
PixelBuffer::PS3GetHeight() const
{
    ;
    return m_height;
}

inline uint32_t
PixelBuffer::PS3GetPitch() const
{
    ;
    return (uint32_t )m_pitch;
}

inline uint8_t
PixelBuffer::PS3GetLocation() const
{
    ;
    return m_location;
}

inline uint32_t
PixelBuffer::PS3GetOffset() const
{
    ;
    return m_offset;
}

inline uint8_t
PixelBuffer::PS3GetAntiAliasType() const
{
    ;
    return m_antiAlias;
}

inline uint8_t
PixelBuffer::PS3GetDisplayBufferID() const
{
    ;
    ;

    return m_displayBufferID;
}

inline uint32_t
PixelBuffer::PS3IsSwizzled() const
{
    ;
    return PS3PixelFormatIsSwizzled(m_pixelFormat);
}

inline void *
PixelBuffer::PS3GetBuffer() const
{
    ;
    return m_buffer;
}

}
}
}
