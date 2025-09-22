































namespace rw
{
namespace graphics
{
namespace core
{



















class PixelBuffer;
class Texture;
class VertexBuffer;
class IndexBuffer;
class VertexDescriptor;
class RenderTargetState;
class DepthStencilState;
class BlendState;
class RasterizerState;
class MeshState;
class TextureState;
class ProgramBuffer;
class ShaderProgramVariable;
class Device;


enum PrimitiveType
{
    PRIMITIVETYPE_NA = 0,

    PRIMITIVETYPE_POINTS = 1,
    PRIMITIVETYPE_LINES = 2,
    PRIMITIVETYPE_LINELOOP = 3,
    PRIMITIVETYPE_LINESTRIP = 4,
    PRIMITIVETYPE_TRIANGLES = 5,
    PRIMITIVETYPE_TRIANGLESTRIPS = 6,
    PRIMITIVETYPE_TRIANGLEFAN = 7,
    PRIMITIVETYPE_QUADS = 8,
    PRIMITIVETYPE_QUADSTRIPS = 9,
    PRIMITIVETYPE_POLYGON = 10,

    PRIMITIVETYPE_MAX = 11,
    PRIMITIVETYPE_NUM = 11,

    PRIMITIVETYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};



static const uint32_t PS3_GCM_FALSE = 0;
static const uint32_t PS3_GCM_TRUE = 1;


static const uint8_t SYNC_HSYNC = 1;
static const uint8_t SYNC_VSYNC = 2;


static const uint8_t LOCATION_LOCAL = 0;
static const uint8_t LOCATION_SYSTEM = 1;



static const uint8_t COMPMODE_DISABLED = (0);
static const uint8_t COMPMODE_C32_2X1 = (7);
static const uint8_t COMPMODE_C32_2X2 = (8);
static const uint8_t COMPMODE_Z32_SEPSTENCIL = (9);
static const uint8_t COMPMODE_Z32_SEPSTENCIL_REGULAR = (10);
static const uint8_t COMPMODE_Z32_SEPSTENCIL_DIAGONAL = (11);
static const uint8_t COMPMODE_Z32_SEPSTENCIL_ROTATED = (12);



static const uint8_t MULTISAMPLETYPE_NONE = 0;
static const uint8_t MULTISAMPLETYPE_DIAGONAL_2 = 3;
static const uint8_t MULTISAMPLETYPE_SQUARE_4 = 4;
static const uint8_t MULTISAMPLETYPE_SQUARE_4_ROT = 5;



static const uint32_t ZCULLDIR_LESS = 0;
static const uint32_t ZCULLDIR_GREATER = 1;



static const uint32_t ZCULLFORMAT_MSB = 0;
static const uint32_t ZCULLFORMAT_LONES = 1;



static const uint32_t CLEARFLAGS_Z = (1<<0);
static const uint32_t CLEARFLAGS_S = (1<<1);
static const uint32_t CLEARFLAGS_R = (1<<4);
static const uint32_t CLEARFLAGS_G = (1<<5);
static const uint32_t CLEARFLAGS_B = (1<<6);
static const uint32_t CLEARFLAGS_A = (1<<7);



static const uint8_t PS3INDEXTYPE_32 = 0;
static const uint8_t PS3INDEXTYPE_16 = 1;

































































































inline uint16_t PS3FloatToLODBias(float32_t bias)
{
    ;
    return ((int16_t )(bias * 255.0f) & 0x1fff);
}

inline float32_t PS3LODBiasToFloat(const uint16_t bias)
{
    ;
    int16_t sBias = bias;
    if (sBias & 0x1000)
    {
        sBias |= 0xe000;
    }
    return ((float32_t )sBias) / 255.0f;
}

struct VectorI4
{
    int32_t elements[4];
} __attribute__ ((__aligned__ (16)));




inline uint32_t PS3IsPowerTwo(uint32_t value)
{
    ;
    return ((value - 1) & (value)) == 0;
}

}
}
}
