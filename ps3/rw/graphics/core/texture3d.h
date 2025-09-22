













namespace rw
{
namespace graphics
{
namespace core
{




























class Texture3D : public Texture
{
public:
    static rw::ResourceDescriptor GetResourceDescriptor(const Texture3D::Parameters &params);
    static Texture3D *Initialize(const rw::Resource &resource, const Texture3D::Parameters &params);
    static void Destruct(Texture3D *texture);
    void GetParameters(Texture3D::Parameters &parameters) const;

    bool Lock(uint32_t lockFlags,
              uint32_t mipLevel,
              Locked &locked);

protected:

    Texture3D();
    Texture3D(const Texture3D &texture);
    ~Texture3D();
};




inline void
Texture3D::Destruct(Texture3D *texture)
{
    ;
    Texture::Destruct(texture);
    return;
}

inline bool
Texture3D::Lock(uint32_t lockFlags,
                uint32_t mipLevel,
                Locked &locked)
{
    ;
    return Texture::Lock(lockFlags, mipLevel, 0, locked);
}

}
}
}
