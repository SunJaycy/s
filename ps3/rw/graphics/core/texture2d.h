













namespace rw
{
namespace graphics
{
namespace core
{




























class Texture2D : public Texture
{
public:

    static rw::ResourceDescriptor GetResourceDescriptor(const Texture2D::Parameters &params);
    static Texture2D *Initialize(const rw::Resource &resource, const Texture2D::Parameters &params);
    static void Destruct(Texture2D *texture);
    void GetParameters(Texture2D::Parameters &parameters) const;

    bool Lock(uint32_t lockFlags,
              uint32_t mipLevel,
              Locked &locked);

protected:

    Texture2D();
    Texture2D(const Texture2D &texture);
    ~Texture2D();
};
















































































inline void
Texture2D::Destruct(Texture2D *texture)
{
    ;
    Texture::Destruct(texture);
    return;
}

inline bool
Texture2D::Lock(uint32_t lockFlags,
                uint32_t mipLevel,
                Locked &locked)
{
    ;
    return Texture::Lock(lockFlags, mipLevel, 0, locked);
}

}
}
}
