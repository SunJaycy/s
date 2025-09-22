





















namespace rw
{
namespace graphics
{
namespace core
{

































class VertexIteratorBaseClass
{
public:
    inline void SetBuffer(void * const m_buf)
    {
        ;
        m_dest = m_buf;
        return;
    }

protected:
    void *m_dest;
};





template<class DT>
class VertexIterator : public VertexIteratorBaseClass
{
public:
    template<typename ST>
    inline void
    Write(const ST &val)
    {
        ;

        *reinterpret_cast<DT *>(m_dest) = val;
        m_dest = reinterpret_cast<void *>(reinterpret_cast<DT *>(m_dest) + 1);

        return;
    };

    template<typename ST>
    inline void
    Read(ST &val)
    {
        ;

        val = *reinterpret_cast<DT *>(m_dest);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<DT *>(m_dest) + 1);

        return;
    };

    static inline uint32_t
    GetStride()
    {
        ;
        return sizeof(DT);
    };
};

































class VertexTypeFloat1
{
    uint8_t pad[4];
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeFloat1>::Write(const ST &val)
{
    ;

    reinterpret_cast<rw::math::fpu::Vector2U_32 *>(m_dest)->X() =static_cast<float32_t>(val.X());
    m_dest = reinterpret_cast<void *>( reinterpret_cast<float32_t *>(m_dest) + 1 );

    return;
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeFloat1>::Read(ST &val)
{
    ;

    val.X() =reinterpret_cast<rw::math::fpu::Vector2U_32 *>(m_dest)->X();
    m_dest = reinterpret_cast<void *>( reinterpret_cast<float32_t *>(m_dest) + 1 );

    return;
};

template<> template<>
inline void
VertexIterator<VertexTypeFloat1>::Write<float32_t>(const float32_t &val)
{
    ;

    *reinterpret_cast<float32_t *>(m_dest) = val;
    m_dest = reinterpret_cast<void *>( reinterpret_cast<float32_t *>(m_dest) + 1 );

    return;
};

template<> template<>
inline void
VertexIterator<VertexTypeFloat1>::Read<float32_t>(float32_t &val)
{
    ;

    val = *reinterpret_cast<float32_t *>(m_dest);
    m_dest = reinterpret_cast<void *>( reinterpret_cast<float32_t *>(m_dest) + 1 );

    return;
};



class VertexTypeFloat2
{
    uint8_t pad[8];
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeFloat2>::Write(const ST &val)
{
    ;

    reinterpret_cast<rw::math::fpu::Vector2U_32 *>(m_dest)->X() =static_cast<float32_t>(val.X());
    reinterpret_cast<rw::math::fpu::Vector2U_32 *>(m_dest)->Y() =static_cast<float32_t>(val.Y());
    m_dest = reinterpret_cast<void *>( reinterpret_cast<rw::math::fpu::Vector2U_32 *>(m_dest) + 1 );

    return;
};


template<> template<>
inline void
VertexIterator<VertexTypeFloat2>::Write<rw::math::Vector2>(const rw::math::Vector2 &val)
{
    ;

    register __attribute__((altivec(vector__))) float v = val;
    register __attribute__((altivec(vector__))) unsigned char permFlags = vec_lvsr(0, reinterpret_cast<uint8_t*>(m_dest));
    v = vec_perm(v, v, permFlags);

    float32_t *vbData = reinterpret_cast<float32_t *>(m_dest);
    vec_stvewx(v, 0, vbData);
    vec_stvewx(v, 0, vbData + 1);
    m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t*>(m_dest) + 8);

    return;
};


template<> template<class ST>
inline void
VertexIterator<VertexTypeFloat2>::Read(ST &val)
{
    ;

    val.X() =reinterpret_cast<rw::math::fpu::Vector2U_32 *>(m_dest)->X();
    val.Y() =reinterpret_cast<rw::math::fpu::Vector2U_32 *>(m_dest)->Y();
    m_dest = reinterpret_cast<void *>( reinterpret_cast<rw::math::fpu::Vector2U_32 *>(m_dest) + 1 );

    return;
};



class VertexTypeFloat3
{
    uint8_t pad[12];
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeFloat3>::Write(const ST &val)
{
    ;

    reinterpret_cast<rw::math::fpu::Vector3U_32 *>(m_dest)->X() =static_cast<float32_t>(val.X());
    reinterpret_cast<rw::math::fpu::Vector3U_32 *>(m_dest)->Y() =static_cast<float32_t>(val.Y());
    reinterpret_cast<rw::math::fpu::Vector3U_32 *>(m_dest)->Z() =static_cast<float32_t>(val.Z());
    m_dest = reinterpret_cast<void *>( reinterpret_cast<rw::math::fpu::Vector3U_32 *>(m_dest) + 1 );

    return;
};


template<> template<>
inline void
VertexIterator<VertexTypeFloat3>::Write<rw::math::Vector3>(const rw::math::Vector3 &val)
{
    ;

    register __attribute__((altivec(vector__))) float v = val;
    register __attribute__((altivec(vector__))) unsigned char permFlags = vec_lvsr(0, reinterpret_cast<uint8_t*>(m_dest));
    v = vec_perm(v, v, permFlags);

    float32_t *vbData = reinterpret_cast<float32_t *>(m_dest);
    vec_stvewx(v, 0, vbData);
    vec_stvewx(v, 0, vbData + 1);
    vec_stvewx(v, 0, vbData + 2);
    m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t*>(m_dest) + 12);

    return;
};


template<> template<class ST>
inline void
VertexIterator<VertexTypeFloat3>::Read(ST &val)
{
    ;

    val.X() =reinterpret_cast<rw::math::fpu::Vector3U_32 *>(m_dest)->X();
    val.Y() =reinterpret_cast<rw::math::fpu::Vector3U_32 *>(m_dest)->Y();
    val.Z() =reinterpret_cast<rw::math::fpu::Vector3U_32 *>(m_dest)->Z();
    m_dest = reinterpret_cast<void *>( reinterpret_cast<rw::math::fpu::Vector3U_32 *>(m_dest) + 1 );

    return;
};



class VertexTypeFloat4
{
    uint8_t pad[16];
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeFloat4>::Write(const ST &val)
{
    ;

    reinterpret_cast<rw::math::fpu::Vector4U_32 *>(m_dest)->X() =static_cast<float32_t>(val.X());
    reinterpret_cast<rw::math::fpu::Vector4U_32 *>(m_dest)->Y() =static_cast<float32_t>(val.Y());
    reinterpret_cast<rw::math::fpu::Vector4U_32 *>(m_dest)->Z() =static_cast<float32_t>(val.Z());
    reinterpret_cast<rw::math::fpu::Vector4U_32 *>(m_dest)->W() =static_cast<float32_t>(val.W());
    m_dest = reinterpret_cast<void *>( reinterpret_cast<rw::math::fpu::Vector4U_32 *>(m_dest) + 1 );

    return;
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeFloat4>::Read(ST &val)
{
    ;

    val.X() =reinterpret_cast<rw::math::fpu::Vector4U_32 *>(m_dest)->X();
    val.Y() =reinterpret_cast<rw::math::fpu::Vector4U_32 *>(m_dest)->Y();
    val.Z() =reinterpret_cast<rw::math::fpu::Vector4U_32 *>(m_dest)->Z();
    val.W() =reinterpret_cast<rw::math::fpu::Vector4U_32 *>(m_dest)->W();
    m_dest = reinterpret_cast<void *>( reinterpret_cast<rw::math::fpu::Vector4U_32 *>(m_dest) + 1 );

    return;
};



class VertexTypeUByte1
{
    uint8_t pad;
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeUByte1>::Write(const ST &val)
{
    ;

    *(uint8_t *)m_dest = (uint8_t)val.X();

    m_dest = reinterpret_cast<void *>( reinterpret_cast<uint8_t *>(m_dest) + 1 );

    return;
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeUByte1>::Read(ST &val)
{
    ;

    val.X() =reinterpret_cast<uint8_t *>(m_dest)[0];

    m_dest = reinterpret_cast<void *>( reinterpret_cast<uint8_t *>(m_dest) + 1 );

    return;
};



class VertexTypeUByte2
{
    uint8_t pad[2];
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeUByte2>::Write(const ST &val)
{
    ;

    *((uint16_t *)m_dest) = ((uint16_t)val.X() & 0xFF) |
                            (((uint16_t)val.Y() & 0xFF) << 8);

    m_dest = reinterpret_cast<void *>( reinterpret_cast<uint16_t *>(m_dest) + 1 );

    return;
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeUByte2>::Read(ST &val)
{
    ;

    val.X() = reinterpret_cast<uint16_t *>(m_dest)[0] & 0xFF ;
    val.Y() = (reinterpret_cast<uint16_t *>(m_dest)[0] >> 8L) & 0xFF ;

    m_dest = reinterpret_cast<void *>( reinterpret_cast<uint16_t *>(m_dest) + 1 );

    return;
};



class VertexTypeUByte3
{
    uint8_t pad[3];
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeUByte3>::Write(const ST &val)
{
    ;

    ((uint8_t *)m_dest)[0] = (uint8_t)val.X();
    ((uint8_t *)m_dest)[1] = (uint8_t)val.Y();
    ((uint8_t *)m_dest)[2] = (uint8_t)val.Z();

    m_dest = reinterpret_cast<void *>( reinterpret_cast<uint8_t *>(m_dest) + 3 );

    return;
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeUByte3>::Read(ST &val)
{
    ;

    val.X() =reinterpret_cast<uint8_t *>(m_dest)[0];
    val.Y() =reinterpret_cast<uint8_t *>(m_dest)[1];
    val.Z() =reinterpret_cast<uint8_t *>(m_dest)[2];

    m_dest = reinterpret_cast<void *>( reinterpret_cast<uint8_t *>(m_dest) + 3 );

    return;
};



class VertexTypeUByte4
{
    uint8_t pad[4];
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeUByte4>::Write(const ST &val)
{
    ;

    *((uint32_t *)m_dest) = ((((uint32_t)val.W()) & 0xFF) << 24L) |
                             (((uint32_t)val.X()) & 0xFF) |
                            ((((uint32_t)val.Y()) & 0xFF) << 8L) |
                            ((((uint32_t)val.Z()) & 0xFF) << 16L);

    m_dest = reinterpret_cast<void *>( reinterpret_cast<uint32_t *>(m_dest) + 1 );

    return;
};

template<> template<class ST>
inline void
VertexIterator<VertexTypeUByte4>::Read(ST &val)
{
    ;

    val.X() = reinterpret_cast<uint32_t *>(m_dest)[0] & 0xFF ;
    val.Y() = (reinterpret_cast<uint32_t *>(m_dest)[0] >> 8L) & 0xFF ;
    val.Z() = (reinterpret_cast<uint32_t *>(m_dest)[0] >> 16L) & 0xFF ;
    val.W() = (reinterpret_cast<uint32_t *>(m_dest)[0] >> 24L) & 0xFF ;
    m_dest = reinterpret_cast<void *>( reinterpret_cast<uint32_t *>(m_dest) + 1 );

    return;
};



class VertexTypePS3Color
{
public:
    VertexTypePS3Color(uint32_t _color) { *(uint32_t *)(void *)pad = _color; }
    VertexTypePS3Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    { pad[0] = red, pad[1] = green, pad[2] = blue, pad[3] = alpha; }
protected:
    uint8_t pad[4];
};

template<> template<> inline void VertexIterator<VertexTypePS3Color>::Write<rw::RGBA>(const rw::RGBA &rgba)
{
    ;


    asm("stw %0,0(%1)" : : "r" (rgba), "b" (m_dest));




    m_dest = reinterpret_cast<void *>( reinterpret_cast<uint8_t *>(m_dest) + 4 );
    return;
};

template<> template<> inline void VertexIterator<VertexTypePS3Color>::Read<rw::RGBA>(rw::RGBA &rgba)
{
    ;
    rgba.SetRed (reinterpret_cast<uint8_t *>(m_dest)[0]);
    rgba.SetGreen(reinterpret_cast<uint8_t *>(m_dest)[1]);
    rgba.SetBlue (reinterpret_cast<uint8_t *>(m_dest)[2]);
    rgba.SetAlpha(reinterpret_cast<uint8_t *>(m_dest)[3]);
    m_dest = reinterpret_cast<void *>( reinterpret_cast<uint8_t *>(m_dest) + 4 );
    return;
};

}
}
}
