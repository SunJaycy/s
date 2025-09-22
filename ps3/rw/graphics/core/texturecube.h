













namespace rw
{
namespace graphics
{
namespace core
{




























class TextureCube : public Texture
{
public:

    struct Parameters
    {
        Parameters() : flags(0), edgeLength(0), mipLevels(0),
                        format(static_cast<PixelFormat>(0))
        { }

        void SetFlags(uint32_t f);
        void SetEdgeLength(uint32_t el);
        void SetMipLevels(uint32_t ml);
        void SetFormat(PixelFormat fmt);

        uint32_t GetFlags() const;
        uint32_t GetEdgeLength() const;
        uint32_t GetMipLevels() const;
        PixelFormat GetFormat() const;




        uint32_t flags;
        uint32_t edgeLength;
        uint32_t mipLevels;
        PixelFormat format;
    };

    static rw::ResourceDescriptor GetResourceDescriptor(const TextureCube::Parameters &params);
    static TextureCube *Initialize(const rw::Resource &resource, const TextureCube::Parameters &params);
    static void Destruct(TextureCube *texture);
    void GetParameters(TextureCube::Parameters &parameters) const;

    bool Lock(uint32_t lockFlags, uint32_t mipLevel, uint32_t face, Locked &locked);

protected:


    TextureCube();
    TextureCube(const TextureCube &texture);
    ~TextureCube();
};




inline void
TextureCube::Parameters::SetFlags(uint32_t f)
{
    ;
    flags = f;
    return;
}

inline void
TextureCube::Parameters::SetEdgeLength(uint32_t el)
{
    ;
    edgeLength = el;
    return;
}

inline void
TextureCube::Parameters::SetMipLevels(uint32_t ml)
{
    ;
    mipLevels = ml;
    return;
}

inline void
TextureCube::Parameters::SetFormat(PixelFormat fmt)
{
    ;
    format = fmt;
    return;
}

inline uint32_t
TextureCube::Parameters::GetFlags() const
{
    ;
    return flags;
}

inline uint32_t
TextureCube::Parameters::GetEdgeLength() const
{
    ;
    return edgeLength;
}

inline uint32_t
TextureCube::Parameters::GetMipLevels() const
{
    ;
    return mipLevels;
}

inline PixelFormat
TextureCube::Parameters::GetFormat() const
{
    ;
    return format;
}

inline void
TextureCube::Destruct(TextureCube *texture)
{
    ;
    Texture::Destruct(texture);
    return;
}

inline bool
TextureCube::Lock(uint32_t lockFlags,
                  uint32_t mipLevel,
                  uint32_t face,
                  Locked &locked)
{
    ;
    return Texture::Lock(lockFlags, mipLevel, face, locked);
}

}
}
}
