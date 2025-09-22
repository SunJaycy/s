












namespace rw
{
namespace graphics
{
namespace core
{




static const uint8_t PS3VERTEXTYPE_SHORTN = (1);
static const uint8_t PS3VERTEXTYPE_FLOAT = (2);
static const uint8_t PS3VERTEXTYPE_FLOAT16 = (3);
static const uint8_t PS3VERTEXTYPE_UBYTEN = (4);
static const uint8_t PS3VERTEXTYPE_SHORT = (5);
static const uint8_t PS3VERTEXTYPE_CMP = (6);
static const uint8_t PS3VERTEXTYPE_UBYTE = (7);
static const uint8_t PS3VERTEXTYPE_NA = (255);








enum VertexFormat
{
    VERTEXFORMAT_NA = ((uint32_t )(((PS3VERTEXTYPE_NA) << 8) | (0))),
    VERTEXFORMAT_UNUSED = VERTEXFORMAT_NA,

    VERTEXFORMAT_SHORT1N = ((uint32_t )(((PS3VERTEXTYPE_SHORTN) << 8) | (1))),
    VERTEXFORMAT_SHORT2N = ((uint32_t )(((PS3VERTEXTYPE_SHORTN) << 8) | (2))),
    VERTEXFORMAT_SHORT3N = ((uint32_t )(((PS3VERTEXTYPE_SHORTN) << 8) | (3))),
    VERTEXFORMAT_SHORT4N = ((uint32_t )(((PS3VERTEXTYPE_SHORTN) << 8) | (4))),

    VERTEXFORMAT_FLOAT1 = ((uint32_t )(((PS3VERTEXTYPE_FLOAT) << 8) | (1))),
    VERTEXFORMAT_FLOAT2 = ((uint32_t )(((PS3VERTEXTYPE_FLOAT) << 8) | (2))),
    VERTEXFORMAT_FLOAT3 = ((uint32_t )(((PS3VERTEXTYPE_FLOAT) << 8) | (3))),
    VERTEXFORMAT_FLOAT4 = ((uint32_t )(((PS3VERTEXTYPE_FLOAT) << 8) | (4))),

    VERTEXFORMAT_FLOAT16_1 = ((uint32_t )(((PS3VERTEXTYPE_FLOAT16) << 8) | (1))),
    VERTEXFORMAT_FLOAT16_2 = ((uint32_t )(((PS3VERTEXTYPE_FLOAT16) << 8) | (2))),
    VERTEXFORMAT_FLOAT16_3 = ((uint32_t )(((PS3VERTEXTYPE_FLOAT16) << 8) | (3))),
    VERTEXFORMAT_FLOAT16_4 = ((uint32_t )(((PS3VERTEXTYPE_FLOAT16) << 8) | (4))),

    VERTEXFORMAT_UBYTE1N = ((uint32_t )(((PS3VERTEXTYPE_UBYTEN) << 8) | (1))),
    VERTEXFORMAT_UBYTE2N = ((uint32_t )(((PS3VERTEXTYPE_UBYTEN) << 8) | (2))),
    VERTEXFORMAT_UBYTE3N = ((uint32_t )(((PS3VERTEXTYPE_UBYTEN) << 8) | (3))),
    VERTEXFORMAT_UBYTE4N = ((uint32_t )(((PS3VERTEXTYPE_UBYTEN) << 8) | (4))),

    VERTEXFORMAT_SHORT1 = ((uint32_t )(((PS3VERTEXTYPE_SHORT) << 8) | (1))),
    VERTEXFORMAT_SHORT2 = ((uint32_t )(((PS3VERTEXTYPE_SHORT) << 8) | (2))),
    VERTEXFORMAT_SHORT3 = ((uint32_t )(((PS3VERTEXTYPE_SHORT) << 8) | (3))),
    VERTEXFORMAT_SHORT4 = ((uint32_t )(((PS3VERTEXTYPE_SHORT) << 8) | (4))),


    VERTEXFORMAT_CMP1 = ((uint32_t )(((PS3VERTEXTYPE_CMP) << 8) | (1))),

    VERTEXFORMAT_UBYTE1 = ((uint32_t )(((PS3VERTEXTYPE_UBYTE) << 8) | (1))),
    VERTEXFORMAT_UBYTE2 = ((uint32_t )(((PS3VERTEXTYPE_UBYTE) << 8) | (2))),
    VERTEXFORMAT_UBYTE3 = ((uint32_t )(((PS3VERTEXTYPE_UBYTE) << 8) | (3))),
    VERTEXFORMAT_UBYTE4 = ((uint32_t )(((PS3VERTEXTYPE_UBYTE) << 8) | (4))),

    VERTEXFORMAT_PS3COLOR = VERTEXFORMAT_UBYTE4,

    VERTEXFORMAT_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};








uint32_t PS3VertexTypeGetSize(uint8_t vertexType);





inline uint32_t
VertexFormatGetStride( VertexFormat vertexFormat )
{
    ;
    return PS3VertexTypeGetSize(((uint8_t )((uint32_t )(vertexFormat) >> 8))) * ((uint8_t )((uint32_t )(vertexFormat) & 0xff));

}




inline uint32_t
VertexFormatGetNumComponents( VertexFormat vertexFormat )
{
    ;
    return (uint32_t )((uint8_t )((uint32_t )(vertexFormat) & 0xff));
}




inline void
EndianSwap(rw::graphics::core::VertexFormat& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::VertexFormat) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_vertexformat_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_vertexformat_is_not_sizeof_uint32_t) break;

    ;
}


}
}
}
