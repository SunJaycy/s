







#include <PSGL/psgl.h>
#include <PSGL/psglu.h>



#include <rw/core/corelite.h>
















































namespace rw
{
namespace graphics
{
enum PSGLCoreState
{
    PSGLCORESTATE_NA = 0,
    PSGLCORESTATE_TRANSFORM = (1 << 0),
    PSGLCORESTATE_TRANSFORMREF = (1 << 1),
    PSGLCORESTATE_SHADER = (1 << 2),
    PSGLCORESTATE_SHADERDATA = (1 << 3),
    PSGLCORESTATE_MATERIALCOLOR = (1 << 4),
    PSGLCORESTATE_MATERIALCOLORREF = (1 << 5),
    PSGLCORESTATE_VERTEXDESCRIPTOR = (1 << 6),
    PSGLCORESTATE_AMBIENT = (1 << 7),
    PSGLCORESTATE_LIGHTSHIFT = (8),
    PSGLCORESTATE_LIGHTMASK = (((1 << (8))-1) << PSGLCORESTATE_LIGHTSHIFT),
    PSGLCORESTATE_MASK = ((1 << (PSGLCORESTATE_LIGHTSHIFT + (8))) - 1),
    PSGLCORESTATE_MASKNOREF = (PSGLCORESTATE_MASK & ~(PSGLCORESTATE_TRANSFORMREF & PSGLCORESTATE_MATERIALCOLORREF)),
    PSGLCORESTATE_GLOBALSTATE_MASK = PSGLCORESTATE_MASKNOREF &
                                   ~(PSGLCORESTATE_SHADER | PSGLCORESTATE_SHADERDATA | PSGLCORESTATE_VERTEXDESCRIPTOR),
    PSGLCORESTATE_ALWAYSUPLOAD = (1 << 26),
    PSGLCORESTATE_CAMERACHANGED = (1 << 27),
    PSGLCORESTATE_MESHCHANGED = (1 << 28),
    PSGLCORESTATE_TRANSFORMTYPE_SHIFT = 29,
    PSGLCORESTATE_TRANSFORMTYPEMASK = (7 << PSGLCORESTATE_TRANSFORMTYPE_SHIFT),
    PSGLCORESTATE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum PSGLDeviceState
{
    PSGL_NA = -1,
    PSGL_BLEND = 0,
    PSGL_ZTEST = 1, PSGL_DEPTHTEST = PSGL_ZTEST,
    PSGL_ALPHATEST = 2,
    PSGL_CULLING = 3,
    PSGL_STENCILTEST = 5,
    PSGL_COLOR_LOGIC_OP = 6,
    PSGL_POINTSMOOTH = 7,
    PSGL_LINESMOOTH = 8,
    PSGL_DITHER = 9,
    PSGL_SCISSORTEST = 10,
    PSGL_SAMPLE_ALPHA_TO_MASK = 11,
    PSGL_SAMPLE_ALPHA_TO_ONE = 12,
    PSGL_SAMPLE_MASK = 13,
    PSGL_VSYNC = 15,
    PSGL_NUMBOOLEANSTATES = 16,
    PSGL_BOOLEANMASK = 0x0000ffff,
    PSGL_ALPHAFUNCTION = 16,
    PSGL_ALPHAREFERENCE = 17,
    PSGL_SFACTOR = 18,
    PSGL_DFACTOR = 19,
    PSGL_CULLFACE = 20,
    PSGL_DEPTHMASK = 21,
    PSGL_COLORMASK = 22,
    PSGL_DEPTHFUNCTION = 23,
    PSGL_STENCILFUNCTION = 24,
    PSGL_STENCILMASK = 25,
    PSGL_STENCILOP = 26,
    PSGL_LINEWIDTH = 27,
    PSGL_POINTSIZE = 28,
    PSGL_LOGICOP = 29,
    PSGL_POLYGONMODE = 30,
    PSGL_SAMPLECOVERAGE = 31,
    PSGL_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum PrimitiveType
{
    PRIMITIVETYPE_NA = -1,
    PRIMITIVETYPE_POINTS = 0x0000,
    PRIMITIVETYPE_LINES = 0x0001,
    PRIMITIVETYPE_LINESTRIP = 0x0003,
    PRIMITIVETYPE_TRIANGLES = 0x0004,
    PRIMITIVETYPE_TRIANGLESTRIPS = 0x0005,
    PRIMITIVETYPE_TRIANGLEFAN = 0x0006,
    PRIMITIVETYPE_QUADS = 0x0007,
    PRIMITIVETYPE_QUADSTRIPS = 0x0008,
    PRIMITIVETYPE_MAX = 9,
    PRIMITIVETYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum AlphaTestFunction
{
    ALPHATESTFUNCTION_NA = 0,
    ALPHATESTFUNCTION_NEVER = 0x0200,
    ALPHATESTFUNCTION_LESS = 0x0201,
    ALPHATESTFUNCTION_EQUAL = 0x0202,
    ALPHATESTFUNCTION_LESSEQUAL = 0x0203,
    ALPHATESTFUNCTION_GREATER = 0x0204,
    ALPHATESTFUNCTION_NOTEQUAL = 0x0205,
    ALPHATESTFUNCTION_GREATEREQUAL = 0x0206,
    ALPHATESTFUNCTION_ALWAYS = 0x0207,
    ALPHATESTFUNCTION_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum AlphaTestReference
{
    ALPHATESTREFERENCE_NA = 0xffffff00,
    ALPHATESTREFERENCE_ZERO = 0,
    ALPHATESTREFERENCE_HALF = 127,
    ALPHATESTREFERENCE_ONE = 255,
    ALPHATESTREFERENCE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum BlendMode
{
    BLENDMODE_NA = -1,
    BLENDMODE_OPAQUE = 1,
    BLENDMODE_ADD = 2,
    BLENDMODE_DECAL = 3,
    BLENDMODE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum TextureData
{
    TEXTUREDATA_NA = 0x00,
    TEXTUREDATA_NUMBITS = 5,
    TEXTUREDATA_BITMASK =(1<<TEXTUREDATA_NUMBITS)-1,
    TEXTUREDATA_RASTER = 0x01,
    TEXTUREDATA_FILTERMIN = 0x02,
    TEXTUREDATA_FILTERMAG = 0x04,
    TEXTUREDATA_ADDRESSU = 0x08,
    TEXTUREDATA_ADDRESSV = 0x10,
    TEXTUREDATA_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum PSGLBlendFactor
{
    PSGLBLENDFACTOR_NA = -1,
    PSGLBLENDFACTOR_ZERO = 0x0000,
    PSGLBLENDFACTOR_ONE = 0x0001,
    PSGLBLENDFACTOR_SRCCOLOR = 0x0300,
    PSGLBLENDFACTOR_ONEMINUSSRCCOLOR = 0x0301,
    PSGLBLENDFACTOR_SRCALPHA = 0x0302,
    PSGLBLENDFACTOR_ONEMINUSSRCALPHA = 0x0303,
    PSGLBLENDFACTOR_DSTALPHA = 0x0304,
    PSGLBLENDFACTOR_ONEMINUSDSTALPHA = 0x0305,
    PSGLBLENDFACTOR_DSTCOLOR = 0x0306,
    PSGLBLENDFACTOR_ONEMINUSDSTCOLOR = 0x0307,
    PSGLBLENDFACTOR_SRCALPHASATURATE = 0x0308,
    PSGLBLENDFACTOR_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum PSGLColorLogicOp
{
    PSGLCOLOROP_NA = -1,
    PSGLCOLOROP_CLEAR = 0x1500,
    PSGLCOLOROP_SET = 0x150F,
    PSGLCOLOROP_COPY = 0x1503,
    PSGLCOLOROP_COPY_INVERTED = 0x150C,
    PSGLCOLOROP_NOOP = 0x1505,
    PSGLCOLOROP_INVERT = 0x150A,
    PSGLCOLOROP_AND = 0x1501,
    PSGLCOLOROP_NAND = 0x150E,
    PSGLCOLOROP_OR = 0x1507,
    PSGLCOLOROP_NOR = 0x1508,
    PSGLCOLOROP_XOR = 0x1506,
    PSGLCOLOROP_EQUIV = 0x1509,
    PSGLCOLOROP_AND_REVERSE = 0x1502,
    PSGLCOLOROP_AND_INVERTED = 0x1504,
    PSGLCOLOROP_OR_REVERSE = 0x150B,
    PSGLCOLOROP_OR_INVERTED = 0x150D,
    PSGLCOLOROP_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum CullMode
{
    CULLMODE_NA = -1,
    CULLMODE_NONE = 0,
    CULLMODE_BACK = 0x0405,
    CULLMODE_FRONT = 0x0404,
    CULLMODE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum PSGLDepthTestFunction
{
    PSGLDEPTHTEST_NA = -1,
    PSGLDEPTHTEST_NEVER = 0x0200,
    PSGLDEPTHTEST_LESS = 0x0201,
    PSGLDEPTHTEST_EQUAL = 0x0202,
    PSGLDEPTHTEST_LEQUAL = 0x0203,
    PSGLDEPTHTEST_GREATER = 0x0204,
    PSGLDEPTHTEST_NOTEQUAL = 0x0205,
    PSGLDEPTHTEST_GEQUAL = 0x0206,
    PSGLDEPTHTEST_ALWAYS = 0x0207,
    PSGLDEPTHTEST_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum PSGLPolygonMode
{
    PSGLPOLYMODE_NA = -1,
    PSGLPOLYMODE_POINT = 0x1B00,
    PSGLPOLYMODE_LINE = 0x1B01,
    PSGLPOLYMODE_FILL = 0x1B02,
    PSGLPOLYMODE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum PSGLStencilFunc
{
    PSGLSTENCILFUNC_NA = -1,
    PSGLSTENCILFUNC_NEVER = 0x0200,
    PSGLSTENCILFUNC_LESS = 0x0201,
    PSGLSTENCILFUNC_EQUAL = 0x0202,
    PSGLSTENCILFUNC_LEQUAL = 0x0203,
    PSGLSTENCILFUNC_GREATER = 0x0204,
    PSGLSTENCILFUNC_NOTEQUAL = 0x0205,
    PSGLSTENCILFUNC_GEQUAL = 0x0206,
    PSGLSTENCILFUNC_ALWAYS = 0x0207,
    PSGLSTENCILFUNC_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum PSGLStencilOp
{
    PSGLSTENCILOP_NA = -1,
    PSGLSTENCILOP_ZERO = 0,
    PSGLSTENCILOP_KEEP = 0x1E00,
    PSGLSTENCILOP_REPLACE = 0x1E01,
    PSGLSTENCILOP_INCREMENT = 0x1E02,
    PSGLSTENCILOP_DECREMENT = 0x1E03,
    PSGLSTENCILOP_INVERT = 0x150A,
    PSGLSTENCILOP_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum FogType
{
    FOGTYPE_NA = -1,
    FOGTYPE_NONE = 0,
    FOGTYPE_LINEAR = 0x2601,
    FOGTYPE_EXPONENTIAL = 0x0800,
    FOGTYPE_EXPONENTIAL2 = 0x0801,
    FOGTYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum Behaviour
{
    BEHAVIOUR_NA = -1,
    BEHAVIOUR_STATIC = 0,
    BEHAVIOUR_DYNAMIC,
    BEHAVIOUR_DYNAMIC_SHARED,
    BEHAVIOUR_EXTERNAL,
    BEHAVIOUR_REFERENCE,
    BEHAVIOUR_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};

































}
}
namespace rw
{
    inline void
    EndianSwap(rw::graphics::PSGLDeviceState& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::PSGLDeviceState) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_PSGLDeviceState_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_PSGLDeviceState_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::PrimitiveType& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::PrimitiveType) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_PrimitiveType_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_PrimitiveType_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::AlphaTestFunction& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::AlphaTestFunction) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_AlphaTestFunction_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_AlphaTestFunction_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::AlphaTestReference& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::AlphaTestReference) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_AlphaTestReference_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_AlphaTestReference_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::BlendMode& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::BlendMode) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_BlendMode_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_BlendMode_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::PSGLBlendFactor& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::PSGLBlendFactor) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_PSGLBlendFactor_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_PSGLBlendFactor_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::PSGLColorLogicOp& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::PSGLColorLogicOp) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_PSGLColorLogicOp_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_PSGLColorLogicOp_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::CullMode& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::CullMode) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_CullMode_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_CullMode_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::PSGLDepthTestFunction& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::PSGLDepthTestFunction) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_PSGLDepthTestFunction_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_PSGLDepthTestFunction_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::FogType& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::FogType) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_FogType_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_FogType_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::PSGLPolygonMode& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::PSGLPolygonMode) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_PSGLPolygonMode_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_PSGLPolygonMode_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::PSGLStencilFunc& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::PSGLStencilFunc) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_PSGLStencilFunc_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_PSGLStencilFunc_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::PSGLStencilOp& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::PSGLStencilOp) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_PSGLStencilOp_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_PSGLStencilOp_is_not_sizeof_uint32_t) break;

        ;
    }
    inline void
    EndianSwap(rw::graphics::Behaviour& )
    {
        for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::Behaviour) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_Behaviour_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_Behaviour_is_not_sizeof_uint32_t) break;

        ;
    }
}









namespace rw
{
namespace graphics
{
enum RwgObjectType
{
    RWGOBJECTTYPE_NA = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x00) & 0xff)),
    RWGOBJECTTYPE_CAMERA = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x01) & 0xff)),
    RWGOBJECTTYPE_PALETTE = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x02) & 0xff)),
    RWGOBJECTTYPE_RASTER = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x03) & 0xff)),
    RWGOBJECTTYPE_VDES = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x04) & 0xff)),
    RWGOBJECTTYPE_VBUF = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x05) & 0xff)),
    RWGOBJECTTYPE_IDES = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x06) & 0xff)),
    RWGOBJECTTYPE_IBUF = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x07) & 0xff)),
    RWGOBJECTTYPE_LIGHT = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x08) & 0xff)),
    RWGOBJECTTYPE_MESH = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x09) & 0xff)),
    RWGOBJECTTYPE_SHADER = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x0A) & 0xff)),
    RWGOBJECTTYPE_COMPILEDSTATE = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x0B) & 0xff)),
    RWGOBJECTTYPE_RENDEROBJECT = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x0C) & 0xff)),
    RWGOBJECTTYPE_GSDATA = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x0D) & 0xff)),
    RWGOBJECTTYPE_UPDATELOCATOR = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x7f) & 0xff)),
    RWGOBJECTTYPE_VERTEXSHADER = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x0E) & 0xff)),
    RWGOBJECTTYPE_VERTEXDATA = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x0F) & 0xff)),
    RWGOBJECTTYPE_INDEXDATA = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x10) & 0xff)),
    RWGOBJECTTYPE_RASTERDATA = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x11) & 0xff)),
    RWGOBJECTTYPE_BUILDSTATE = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x12) & 0xff)),
    RWGOBJECTTYPE_PIXELSHADER = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x13) & 0xff)),
    RWGOBJECTTYPE_PROFILEMESH = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x15) & 0xff)),
    RWGOBJECTTYPE_DESIGNVIEWOBJECT = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x16) & 0xff)),
    RWGOBJECTTYPE_PROFILERENDEROBJECT = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x17) & 0xff)),
    RWGOBJECTTYPE_IMAGE = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x18) & 0xff)),
    RWGOBJECTTYPE_RENDEROBJECTCONTAINER = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x19) & 0xff)),
    RWGOBJECTTYPE_MESHCOMPILEDSTATELINK = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x1A) & 0xff)),
    RWGOBJECTTYPE_SHADERCODE = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x1B) & 0xff)),
 RWGOBJECTTYPE_FONT = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x20) & 0xff)),
 RWGOBJECTTYPE_GLYPHTABLE = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x21) & 0xff)),
 RWGOBJECTTYPE_KERNTABLE = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x22) & 0xff)),
 RWGOBJECTTYPE_PAGETABLE = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x23) & 0xff)),
 RWGOBJECTTYPE_RASTERTEXTURE = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x24) & 0xff)),
 RWGOBJECTTYPE_FACENAME = ((((rwCOMPONENTID_GRAPHICS) & 0xff) << 16) | ((0x25) & 0xff)),
    RWGOBJECTTYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
typedef enum RwgObjectType RwgObjectType;
}
}















namespace rw
{
namespace graphics
{




































































































































































































}
}









namespace rw
{
namespace graphics
{














































































































}
}








namespace rw
{
namespace graphics
{
class VertexDescriptor
{
public:
    enum ElementType
    {
        ELEMENTTYPE_NA = -1,
        ELEMENTTYPE_PSGLATTRIBUTE0 = 0,
        ELEMENTTYPE_PSGLATTRIBUTE1 = 1,
        ELEMENTTYPE_PSGLATTRIBUTE2 = 2,
        ELEMENTTYPE_PSGLATTRIBUTE3 = 3,
        ELEMENTTYPE_PSGLATTRIBUTE4 = 4,
        ELEMENTTYPE_PSGLATTRIBUTE5 = 5,
        ELEMENTTYPE_PSGLATTRIBUTE6 = 6,
        ELEMENTTYPE_PSGLATTRIBUTE7 = 7,
        ELEMENTTYPE_PSGLATTRIBUTE8 = 8,
        ELEMENTTYPE_PSGLATTRIBUTE9 = 9,
        ELEMENTTYPE_PSGLATTRIBUTE10 = 10,
        ELEMENTTYPE_PSGLATTRIBUTE11 = 11,
        ELEMENTTYPE_PSGLATTRIBUTE12 = 12,
        ELEMENTTYPE_PSGLATTRIBUTE13 = 13,
        ELEMENTTYPE_PSGLATTRIBUTE14 = 14,
        ELEMENTTYPE_PSGLATTRIBUTE15 = 15,
        ELEMENTTYPE_PSGL_NUM = 16,
        ELEMENTTYPE_PSGL_XYZ = ELEMENTTYPE_PSGLATTRIBUTE0,
        ELEMENTTYPE_PSGL_VERTEXCOLOR = ELEMENTTYPE_PSGLATTRIBUTE3,
        ELEMENTTYPE_PSGL_SPECULAR = ELEMENTTYPE_PSGLATTRIBUTE4,
        ELEMENTTYPE_PSGL_NORMAL = ELEMENTTYPE_PSGLATTRIBUTE2,
        ELEMENTTYPE_PSGL_TEXCOORD0 = ELEMENTTYPE_PSGLATTRIBUTE8,
        ELEMENTTYPE_PSGL_TEXCOORD1 = ELEMENTTYPE_PSGLATTRIBUTE9,
        ELEMENTTYPE_PSGL_TEXCOORD2 = ELEMENTTYPE_PSGLATTRIBUTE10,
        ELEMENTTYPE_PSGL_TEXCOORD3 = ELEMENTTYPE_PSGLATTRIBUTE11,
        ELEMENTTYPE_PSGL_TEXCOORD4 = ELEMENTTYPE_PSGLATTRIBUTE12,
        ELEMENTTYPE_PSGL_TEXCOORD5 = ELEMENTTYPE_PSGLATTRIBUTE13,
        ELEMENTTYPE_PSGL_TEXCOORD6 = ELEMENTTYPE_PSGLATTRIBUTE14,
        ELEMENTTYPE_PSGL_TEXCOORD7 = ELEMENTTYPE_PSGLATTRIBUTE15,
        ELEMENTTYPE_PSGL_WEIGHTS = ELEMENTTYPE_PSGLATTRIBUTE1,
        ELEMENTTYPE_PSGL_INDICES = ELEMENTTYPE_PSGLATTRIBUTE7,
        ELEMENTTYPE_PSGL_TANGENT = ELEMENTTYPE_PSGL_TEXCOORD6,
        ELEMENTTYPE_PSGL_BINORMAL = ELEMENTTYPE_PSGL_TEXCOORD7,
        ELEMENTTYPE_XYZ = ELEMENTTYPE_PSGL_XYZ,
        ELEMENTTYPE_UV = ELEMENTTYPE_PSGL_TEXCOORD0,
        ELEMENTTYPE_RGB = ELEMENTTYPE_NA,
        ELEMENTTYPE_RGBA = ELEMENTTYPE_PSGL_VERTEXCOLOR,
        ELEMENTTYPE_NORMAL = ELEMENTTYPE_PSGL_NORMAL,
        ELEMENTTYPE_TANGENT = ELEMENTTYPE_PSGL_TANGENT,
        ELEMENTTYPE_BINORMAL = ELEMENTTYPE_PSGL_BINORMAL,
        ELEMENTTYPE_IND8 = ELEMENTTYPE_NA,
        ELEMENTTYPE_IND16 = ELEMENTTYPE_NA,
        ELEMENTTYPE_IND32 = ELEMENTTYPE_NA,
        ELEMENTTYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    enum ElementData
    {
        ELEMENTDATA_NA,
        ELEMENTDATA_FLOAT = 0x1406,
        ELEMENTDATA_HALFFLOAT = 0x140B,
        ELEMENTDATA_USHORT = 0x1403,
        ELEMENTDATA_SHORT = 0x1402,
        ELEMENTDATA_UBYTE = 0x1401,
        ELEMENTDATA_BYTE = 0x1400,
        ELEMENTDATA_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    struct Element
    {
        ElementType type;
        ElementData dataType;
        uint32_t offset;
        uint8_t stream;
        uint8_t numComponents;
        uint8_t stride;
        uint8_t pad;
    };
    enum VertexElementUsage { ELEMENTUSAGE_POSITION, ELEMENTUSAGE_UV, ELEMENTUSAGE_COLOR, ELEMENTUSAGE_NORMAL, ELEMENTUSAGE_TANGENT, ELEMENTUSAGE_BINORMAL, ELEMENTUSAGE_INDICES, ELEMENTUSAGE_WEIGHTS, ELEMENTUSAGE_ATTR, ELEMENTUSAGE_NA }; enum VertexElementFormat { ELEMENTFORMAT_FLOAT1, ELEMENTFORMAT_FLOAT2, ELEMENTFORMAT_FLOAT3, ELEMENTFORMAT_FLOAT4, ELEMENTFORMAT_SHORT1, ELEMENTFORMAT_SHORT2, ELEMENTFORMAT_SHORT3, ELEMENTFORMAT_SHORT4, ELEMENTFORMAT_SHORT1N, ELEMENTFORMAT_SHORT2N, ELEMENTFORMAT_SHORT3N, ELEMENTFORMAT_SHORT4N, ELEMENTFORMAT_USHORT1, ELEMENTFORMAT_USHORT2, ELEMENTFORMAT_USHORT3, ELEMENTFORMAT_USHORT4, ELEMENTFORMAT_USHORT1N, ELEMENTFORMAT_USHORT2N, ELEMENTFORMAT_USHORT3N, ELEMENTFORMAT_USHORT4N, ELEMENTFORMAT_UBYTE1, ELEMENTFORMAT_UBYTE2, ELEMENTFORMAT_UBYTE3, ELEMENTFORMAT_UBYTE4, ELEMENTFORMAT_BYTE1N, ELEMENTFORMAT_BYTE2N, ELEMENTFORMAT_BYTE3N, ELEMENTFORMAT_BYTE4N, ELEMENTFORMAT_UBYTE1N, ELEMENTFORMAT_UBYTE2N, ELEMENTFORMAT_UBYTE3N, ELEMENTFORMAT_UBYTE4N, ELEMENTFORMAT_BYTE4, ELEMENTFORMAT_UDEC3N, ELEMENTFORMAT_UDEC3, ELEMENTFORMAT_DEC3N, ELEMENTFORMAT_DEC3, ELEMENTFORMAT_HALF1, ELEMENTFORMAT_HALF2, ELEMENTFORMAT_HALF3, ELEMENTFORMAT_HALF4, ELEMENTFORMAT_COLOR, ELEMENTFORMAT_COLOR_RGB, ELEMENTFORMAT_PACKED3N, ELEMENTFORMAT_FLOATXYWN, ELEMENTFORMAT_NA }; struct BuildElement { BuildElement() : usage(ELEMENTUSAGE_NA), format(ELEMENTFORMAT_NA), stream(0), usageIndex(0) { } void SetUsage(VertexElementUsage _usage) { usage = _usage; } void SetFormat(VertexElementFormat _format) { format = _format; } void SetStream(uint16_t _stream) { stream = _stream; } void SetUsageIndex(uint16_t _usageIndex) { usageIndex = _usageIndex; } VertexElementUsage GetUsage() { return usage; } VertexElementFormat GetFormat() { return format; } uint16_t GetStream() { return stream; } uint16_t GetUsageIndex() { return usageIndex; } VertexElementUsage usage; VertexElementFormat format; uint16_t stream; uint16_t usageIndex; }; static rw::ResourceDescriptor GetResourceDescriptor(const uint32_t numElements); static uint32_t GetAlignment(const uint32_t numElements); static uint32_t GetSize(const uint32_t numElements); static VertexDescriptor *Initialize(void *ptr, const uint32_t size, uint32_t numElements); static VertexDescriptor *Initialize(const rw::Resource &resource, uint32_t numElements, const BuildElement *buildElements = 0); void Release(); VertexDescriptor *Copy(VertexDescriptor *dst) const; VertexDescriptor *Lock(const uint32_t flags); VertexDescriptor *Unlock(); const uint32_t GetNumElements() const; Element *GetElement(uint32_t indx = 0); const Element *GetElement(uint32_t indx = 0) const; static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void Destruct(void *ptr); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); static RwBool AreEqual(const VertexDescriptor *vdesc0, const VertexDescriptor *vdesc1); void SetElement(const uint32_t index, const BuildElement *buildElement); void GetBuildElement(const uint32_t index, BuildElement *buildElement) const; static RwBool IsBuildElementValid(const BuildElement *buildElement);;
    uint32_t PSGLGetStride() const;
    void PSGLSetInterleavedData(RwBool interleaved);
    RwBool PSGLIsInterleavedData() const;
    void PSGLSetVertexData(uint32_t stream, uint32_t &curEl, uint8_t *base, uint32_t stride, const uint32_t numVertices) const;
    uint32_t PSGLGetInstanceSize() const;
    uint32_t PSGLGetElementFlags() const;
    uint32_t PSGLGetLinearVertexDataSize(uint32_t numVertices) const;
protected:
private:
    struct VertexUsagePIDetails
    {
        VertexElementUsage usage;
        uint16_t usageIndex;
    };
    struct ElementTypeConversionEntry
    {
        VertexDescriptor::VertexUsagePIDetails platformIndependentUsage;
        VertexDescriptor::ElementType platformSpecificType;
    };
    struct VertexFormatPSDetails
    {
        ElementData dataType;
        uint8_t numComponents;
    };
    struct ElementFormatConversionEntry
    {
        VertexDescriptor::VertexElementFormat platformIndependentFormat;
        VertexDescriptor::VertexFormatPSDetails platformSpecificFormat;
    };
    static VertexDescriptor::ElementTypeConversionEntry elementTypeConversionTable[];
    static VertexDescriptor::ElementFormatConversionEntry elementFormatConversionTable[];
    static ElementType LookUpPSElementType(VertexElementUsage usage, uint16_t usageIndex);
    static VertexUsagePIDetails LookUpPIElementUsage(ElementType type);
    static VertexFormatPSDetails LookUpPSElementFormat(VertexElementFormat format);
    static VertexElementFormat LookUpPIElementFormat(VertexFormatPSDetails format);
    uint8_t m_numElements;
    uint8_t m_stride;
    uint8_t m_lockFlags;
    uint8_t m_interleavedData;
    uint32_t m_instanceSize;
    uint32_t m_elementFlags;
    Element m_element[1];
    VertexDescriptor();
    VertexDescriptor(const VertexDescriptor &vertexDescriptor);
    ~VertexDescriptor();
};
inline uint32_t
VertexDescriptor::PSGLGetStride() const
{
    ;
    return m_stride;
}
inline void
VertexDescriptor::PSGLSetInterleavedData(RwBool interleaved)
{
    ;
    ;

    if ((0) == interleaved)
    {
        m_interleavedData = 0;
    }
    else
    {
        m_interleavedData = 0xFF;
    }
    return;
}
inline RwBool
VertexDescriptor::PSGLIsInterleavedData() const
{
    ;
    return (0 == m_interleavedData) ? (0) : (1);
}
inline uint32_t
VertexDescriptor::PSGLGetInstanceSize() const
{
    ;
    return m_instanceSize;
}
inline uint32_t
VertexDescriptor::PSGLGetElementFlags() const
{
    ;
    return m_elementFlags;
}
inline uint32_t
VertexDescriptor::PSGLGetLinearVertexDataSize(uint32_t numVertices) const
{
    ;
    ;
    uint32_t size;
    if (0xFF == m_interleavedData)
    {
        size = numVertices * m_stride;
    }
    else
    {
        const VertexDescriptor::Element *lastElement = m_element + m_numElements - 1;
        size = lastElement->offset + lastElement->stride * numVertices;
    }
    return size;
}
}
}













namespace rw
{
namespace graphics
{















}
}





namespace rw
{
namespace graphics
{
class ShaderDataWriter;
typedef void (*ShaderDataUnfixCallback)(void *shaderData, rw::core::arena::SizeAndAlignment *offset);
typedef void (*ShaderDataRefixCallback)(void *shaderData, rw::core::arena::ArenaIterator *iterator);
typedef void (*ShaderDataFixUpCallback)(void *shaderData, rw::core::arena::ArenaIterator *iterator);
typedef void (*ShaderDataUploadCallback)(void *cgParam, const void *data, uint32_t size);
typedef uint16_t (*ShaderStateRemapIDCallback)(uint16_t dataID);
typedef void (*ShaderConstantUploadCallback)(const ShaderDataWriter &output);
const uint32_t RWGSHADERMANAGERDATATYPE_MAX = 2048;
class Shader
{
public:
    typedef uint16_t StateID;
    enum DataType
    {
        DATATYPE_NA = 0,
        DATATYPE_BOOL = DATATYPE_NA,
        DATATYPE_FLOAT = 1,
        DATATYPE_FLOATARRAY,
        DATATYPE_FLOATMATRIX,
        DATATYPE_FLOATMATRIXARRAY,
        DATATYPE_INT,
        DATATYPE_INTARRAY,
        DATATYPE_INTMATRIX,
        DATATYPE_INTMATRIXARRAY,
        DATATYPE_CUSTOM,
        DATATYPE_MAX,
        DATATYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    enum ID
    {
        ID_NA = 0,
        ID_DEFAULT_MIN = 0x80000000u,
        ID_DIRECT = ID_DEFAULT_MIN,
        ID_DEFAULT_MAX,
        ID_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    enum PSGLDataID
    {
        PSGLDATAID_NA = 0,
        PSGLDATAID_VERTEXPROGRAM,
        PSGLDATAID_FRAGMENTPROGRAM,
        PSGLDATAID_SKIN_WEIGHTS,
        PSGLDATAID_SKIN_BONES,
        PSGLDATAID_MORPH_DELTA,
        PSGLDATAID_WORLD_VIEW_PROJ_TRANSPOSED_MATRIX,
        PSGLDATAID_WORLD_VIEW_TRANSPOSED_MATRIX,
        PSGLDATAID_WORLD_TRANSPOSED_MATRIX,
        PSGLDATAID_WORLD_VIEW_PROJ_MATRIX,
        PSGLDATAID_WORLD_VIEW_MATRIX,
        PSGLDATAID_WORLD_MATRIX,
        PSGLDATAID_VIEW_PROJ_TRANSPOSED_MATRIX,
        PSGLDATAID_VIEW_INVERSE_TRANSPOSED_MATRIX,
        PSGLDATAID_VIEW_TRANSPOSED_MATRIX,
        PSGLDATAID_VIEW_PROJ_MATRIX,
        PSGLDATAID_VIEW_INVERSE_MATRIX,
        PSGLDATAID_VIEW_MATRIX,
        PSGLDATAID_PROJ_TRANSPOSED_MATRIX,
        PSGLDATAID_PROJ_MATRIX,
        PSGLDATAID_LIGHT_POS_OBJECT_SPACE,
        PSGLDATAID_LIGHT_POS_WORLD_SPACE,
        PSGLDATAID_LIGHT_POS_VIEW_SPACE,
        PSGLDATAID_LIGHT_DIR_OBJECT_SPACE,
        PSGLDATAID_LIGHT_DIR_WORLD_SPACE,
        PSGLDATAID_LIGHT_DIR_VIEW_SPACE,
        PSGLDATAID_LIGHT_RANGE_OBJECT_SPACE,
        PSGLDATAID_LIGHT_RANGE_WORLD_SPACE,
        PSGLDATAID_LIGHT_RANGE_VIEW_SPACE,
        PSGLDATAID_LIGHT_COLOR,
        PSGLDATAID_EYE_POS_OBJECT_SPACE,
        PSGLDATAID_EYE_POS_WORLD_SPACE,
        PSGLDATAID_EYE_DIR_OBJECT_SPACE,
        PSGLDATAID_EYE_DIR_WORLD_SPACE,
        PSGLDATAID_MATERIAL_COLOR,
        PSGLDATAID_AMBIENT_COLOR,
        PSGLDATAID_FOG_COLOR,
        PSGLDATAID_FOG_COEFFICIENTS,
        PSGLDATAID_POINT_SIZE_COEFFICIENTS,
        PSGLDATAID_TIME,
        PSGLDATAID_PULSE,
        PSGLDATAID_WORLD_INVERSE_MATRIX,
        PSGLDATAID_WORLD_INVERSE_TRANSPOSED_MATRIX,
        PSGLDATAID_DEFAULT_MAX = 64,
        PSGLDATAID_ATOM_MIN = 1024,
        PSGLDATAID_ATOM_MAX = 2048,
        PSGLDATAID_MAX = RWGSHADERMANAGERDATATYPE_MAX,
        PSGLDATAID_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    typedef void (*PSGLDispatchCallback)();
    static void PSGLUploadMatrix(void *cgParam, const void *data, uint32_t columns, uint32_t rows);
    static void PSGLUploadMatrixArray(void *cgParam, const void *data, uint32_t size);
    static void PSGLUploadMatrixArrayR(void *cgParam, const void *data, uint32_t size);
    static void PSGLUploadStateMatrix(void *cgParam, const void *data, uint32_t size, uint32_t transform);
    static void PSGLUploadVector(void *cgParam, const void *data, uint32_t size);
    static void PSGLUploadVectorArray(void *cgParam, const void *data, uint32_t size, uint32_t arrayElements);
    static void PSGLModelViewProjMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLModelViewProjTransposeMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLModelViewMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLModelViewTransposeMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLModelMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLModelTransposeMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLModelInverseMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLModelInverseTransposeMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLViewMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLViewInverseMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLViewTransposeMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLViewInverseTransposeMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLViewProjectionMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLViewProjectionTransposeMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLProjectionMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLProjectionTransposeMatrixUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLEyePosObjectSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLEyePosWorldSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLEyeDirObjectSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLEyeDirWorldSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLLightPosObjectSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLLightDirObjectSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLLightColorUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLLightPosWorldSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLLightPosViewSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLLightDirWorldSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLLightDirViewSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLLightRangeObjectSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLLightRangeWorldSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLLightRangeViewSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLPulseUpload(void *cgParam, const void *data, uint32_t size);
    static void PSGLTimeUpload(void *cgParam, const void *data, uint32_t size);
    static void UploadMatrix(void *cgParam, const void *data, uint32_t columns, uint32_t rows);
    static void UploadMatrixArray(void *cgParam, const void *data, uint32_t size);
    static void UploadMatrixArrayR(void *cgParam, const void *data, uint32_t size);
    static void UploadStateMatrix(void *cgParam, const void *data, uint32_t size);
    static void UploadVector(void *cgParam, const void *data, uint32_t size);
    static void UploadVectorArray(void *cgParam, const void *data, uint32_t size, uint32_t arrayElements);
    static void ModelViewProjUpload(void *cgParam, const void *data, uint32_t size);
    static void ModelViewUpload(void *cgParam, const void *data, uint32_t size);
    static void ModelInverseTransposeUpload(void *cgParam, const void *data, uint32_t size);
    static void EyePosObjectSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void LightPosObjectSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void LightDirObjectSpaceUpload(void *cgParam, const void *data, uint32_t size);
    static void LightColorUpload(void *cgParam, const void *data, uint32_t size);
    static void PulseUpload(void *cgParam, const void *data, uint32_t size);
    struct PSGLSkinBoneData
    {
        struct Matrix
        {
            float32_t m_row0[4];
            float32_t m_row1[4];
            float32_t m_row2[4];
        };
        static void Register();
        static void Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
        static void Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
        static void Upload(void *cgParam, const void *ptr, uint32_t size);
        Matrix* m_skinBones;
        uint8_t* m_boneUploadTable;
        int32_t m_boneUploadTableLength;
        uint32_t m_numBonesUsed;
    };
    struct PSGLSkinNumWeights
    {
        static void Register();
        static void Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
        static void Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
        static void Upload(void *cgParam, const void *ptr, uint32_t size);
        float32_t m_numWeights;
    };
    struct ShaderDataInformation
    {
        StateID id;
        DataType type;
        uint8_t rows;
        uint8_t columns;
        const void *externalReference;
        ShaderDataUnfixCallback unfixCallback;
        ShaderDataRefixCallback refixCallback;
        ShaderDataFixUpCallback fixupCallback;
        ShaderDataUploadCallback uploadCallback;
    };
    static void Destruct(void *ptr); static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks();
    uint32_t GetID() const; void AddRef(); int32_t QueryRef() const; void Release();
    Shader *GetNext() const; void SetNext(Shader *shader);
    static Shader *PSGLInitialize(Shader *shader, uint32_t id, PSGLDispatchCallback dispatch);

    void PSGLSetDispatchCallback(PSGLDispatchCallback dispatchCB);
    const PSGLDispatchCallback PSGLGetDispatchCallback() const;

    static const PSGLDispatchCallback GetMinimalDispatchCallback();
    static const ShaderDataUnfixCallback GetDataUnfixCallback(StateID dataID);
    static const ShaderDataRefixCallback GetDataRefixCallback(StateID dataID);
    static const ShaderDataFixUpCallback GetDataFixUpCallback(StateID dataID);
    static const ShaderDataUploadCallback GetDataUploadCallback(StateID dataID);
    static const void * GetDataExternalReference(StateID dataID);
    static Shader::DataType GetDataType(StateID dataID);
    static uint32_t PSGLGetDataCoreState(StateID dataID);
    static uint32_t GetDataCoreState(StateID dataID);
    static void SetDataUnfixCallback(StateID dataID, ShaderDataUnfixCallback cb);
    static void SetDataRefixCallback(StateID dataID, ShaderDataRefixCallback cb);
    static void SetDataFixUpCallback(StateID dataID, ShaderDataFixUpCallback cb);
    static void SetDataUploadCallback(StateID dataID, ShaderDataUploadCallback cb, DataType type, uint8_t rows, uint8_t columns);
    static void SetDataExternalReference(StateID dataID, const void *address, DataType type, uint8_t rows, uint8_t columns);
    static void PSGLSetDataCoreState(StateID dataID, uint32_t coreState);
    static void SetDataCoreState(StateID dataID, uint32_t coreState);
    static void RegisterExternalReference(StateID id, const void *address, DataType type, uint8_t rows, uint8_t columns);
    static void RegisterExternalReference(const RwChar *referenceAnnotation, const void *address, DataType type, uint8_t rows, uint8_t columns);
    static void RegisterCustomUploadCallback(const RwChar *semanticString, ShaderConstantUploadCallback callback, DataType type, uint8_t rows, uint8_t columns);
    static rw::core::atom::AtomID GetAtomIDFromStateID(StateID id);
    static StateID GetStateIDFromAtomID(rw::core::atom::AtomID atomID);
    static StateID GetStateIDFromAtomTable(const RwChar *name);
    static StateID UnfixStateID(StateID id, rw::core::arena::SizeAndAlignment *offset);
    static StateID RefixStateID(StateID id, rw::core::arena::ArenaIterator *iterator);
    static StateID FixupStateID(StateID id, rw::core::arena::ArenaIterator *iterator);
    static bool StateIDIsAtomID(StateID id);
    static bool StateIDIsInternalType(StateID id);
    static void PSGLRegisterData(uint32_t shaderDataType,
                                 ShaderDataUnfixCallback unfixCallback,
                                 ShaderDataRefixCallback refixCallback,
                                 ShaderDataFixUpCallback fixupCallback,
                                 ShaderDataUploadCallback uploadCallback,
                                 uint32_t coreState = PSGLCORESTATE_ALWAYSUPLOAD);
    static RwBool PSGLStart();
    static void PSGLStop();
protected:
private:

    static ShaderDataInformation m_shaderDataInformationList[RWGSHADERMANAGERDATATYPE_MAX];

    static uint32_t m_dataCoreStateDependencies[RWGSHADERMANAGERDATATYPE_MAX];
    PSGLDispatchCallback m_dispatchCB;
    uint32_t m_id;
    uint32_t m_refCount;
    Shader *m_next;

    typedef void (*PSGLCGSetParamVector)(CGparameter, const float32_t *);
    typedef void (*PSGLCGSetParamVectorArray)(CGparameter, long, long, const float32_t *);
    static PSGLCGSetParamVector m_cgSetParamVector[4];
    static PSGLCGSetParamVectorArray m_cgSetParamVectorArray[4];

} __attribute__ ((__aligned__ (4)));

inline void
Shader::PSGLSetDispatchCallback(PSGLDispatchCallback dispatchCB)
{
    ;
    m_dispatchCB = dispatchCB;
    return;
}


inline const Shader::PSGLDispatchCallback
Shader::PSGLGetDispatchCallback() const
{
    ;
    return m_dispatchCB;
}

inline uint32_t
Shader::GetID() const
{
    ;
    return m_id;
}
inline void
Shader::AddRef()
{
    ;
    m_refCount += 1;
    return;
}
inline int32_t
Shader::QueryRef() const
{
    ;
    return m_refCount;
}
inline void
Shader::SetNext(Shader *shader)
{
    ;
    m_next = shader;
    return;
}
inline Shader *
Shader::GetNext() const
{
    ;
    return m_next;
}

inline const ShaderDataUnfixCallback
Shader::GetDataUnfixCallback(StateID dataID)
{
    ;
    return m_shaderDataInformationList[dataID].unfixCallback;
}


inline const ShaderDataRefixCallback
Shader::GetDataRefixCallback(StateID dataID)
{
    ;
    return m_shaderDataInformationList[dataID].refixCallback;
}


inline const ShaderDataFixUpCallback
Shader::GetDataFixUpCallback(StateID dataID)
{
    ;
    return m_shaderDataInformationList[dataID].fixupCallback;
}


inline const ShaderDataUploadCallback
Shader::GetDataUploadCallback(StateID dataID)
{
    ;
    return m_shaderDataInformationList[dataID].uploadCallback;
}


inline const void *
Shader::GetDataExternalReference(StateID dataID)
{
    ;
    return m_shaderDataInformationList[dataID].externalReference;
}


inline Shader::DataType
Shader::GetDataType(StateID dataID)
{
    ;
    return m_shaderDataInformationList[dataID].type;
}

inline uint32_t
Shader::PSGLGetDataCoreState(StateID dataID)
{
    ;
    return m_dataCoreStateDependencies[dataID];
}
inline void
Shader::PSGLSetDataCoreState(StateID dataID, uint32_t coreState)
{
    ;
    m_dataCoreStateDependencies[dataID] = coreState;
    return;
}
inline Shader::StateID
Shader::GetStateIDFromAtomID(rw::core::atom::AtomID atomID)
{
    ;
    StateID id = static_cast<StateID>(atomID + PSGLDATAID_ATOM_MIN);
    return id;
}
inline rw::core::atom::AtomID
Shader::GetAtomIDFromStateID(Shader::StateID id)
{
    ;
    rw::core::atom::AtomID atomID = static_cast<rw::core::atom::AtomID>(id - PSGLDATAID_ATOM_MIN);
    return atomID;
}
inline bool
Shader::StateIDIsAtomID(Shader::StateID id)
{
    ;
    return id >= PSGLDATAID_ATOM_MIN && id < PSGLDATAID_ATOM_MAX;
}
inline bool
Shader::StateIDIsInternalType(Shader::StateID id)
{
    ;
    return id <= PSGLDATAID_DEFAULT_MAX;
}
inline void
Shader::PSGLUploadMatrix(void *cgParam, const void *data,
                         uint32_t , uint32_t )
{
    ;

    cgGLSetMatrixParameterfr((CGparameter )cgParam, (const float32_t *)data);

    return;
}
inline void
Shader::PSGLUploadMatrixArray(void *cgParam, const void *data,
                              uint32_t size)
{
    ;

    cgGLSetMatrixParameterArrayfc((CGparameter )cgParam, 0, size, (const float32_t *)data);

    return;
}
inline void
Shader::PSGLUploadMatrixArrayR(void *cgParam, const void *data,
                               uint32_t size)
{
    ;

    cgGLSetMatrixParameterArrayfr((CGparameter )cgParam, 0, size, (const float32_t *)data);

    return;
}
inline void
Shader::PSGLUploadStateMatrix(void *cgParam, const void *,
                              uint32_t size, uint32_t transform)
{
    ;

    cgGLSetStateMatrixParameter((CGparameter)cgParam, static_cast<CGGLenum>(size),
                                static_cast<CGGLenum>(transform));

    return;
}
inline void
Shader::PSGLUploadVector(void *cgParam, const void *data,
                         uint32_t size)
{
    ;

    ;
    m_cgSetParamVector[size-1]((CGparameter )cgParam, (const float32_t *)data);

    return;
}
inline void
Shader::PSGLUploadVectorArray(void *cgParam, const void *data,
                              uint32_t size, uint32_t arrayElements)
{
    ;

    ;
    m_cgSetParamVectorArray[size-1]((CGparameter )cgParam, 0, arrayElements, (const float32_t *)data);

    return;
}
inline void
Shader::UploadMatrix(void *cgParam, const void *data, uint32_t columns, uint32_t rows)
{
    ;
    ;
    PSGLUploadMatrix(cgParam, data, columns, rows);
    return;
}
inline void
Shader::UploadMatrixArray(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLUploadMatrixArray(cgParam, data, size);
    return;
}
inline void
Shader::UploadMatrixArrayR(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLUploadMatrixArrayR(cgParam, data, size);
    return;
}
inline void
Shader::UploadStateMatrix(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLUploadStateMatrix(cgParam, data, size, 0 );
    return;
}
inline void
Shader::UploadVector(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLUploadVector(cgParam, data, size);
    return;
}
inline void
Shader::UploadVectorArray(void *cgParam, const void *data, uint32_t size, uint32_t arrayElements)
{
    ;
    ;
    PSGLUploadVectorArray(cgParam, data, size, arrayElements);
    return;
}
inline void
Shader::ModelViewProjUpload(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLModelViewProjMatrixUpload(cgParam, data, size);
    return;
}
inline void
Shader::ModelViewUpload(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLModelViewMatrixUpload(cgParam, data, size);
    return;
}
inline void
Shader::ModelInverseTransposeUpload(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLModelInverseTransposeMatrixUpload(cgParam, data, size);
    return;
}
inline void
Shader::EyePosObjectSpaceUpload(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLEyePosObjectSpaceUpload(cgParam, data, size);
    return;
}
inline void
Shader::LightPosObjectSpaceUpload(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLLightPosObjectSpaceUpload(cgParam, data, size);
    return;
}
inline void
Shader::LightDirObjectSpaceUpload(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLLightDirObjectSpaceUpload(cgParam, data, size);
    return;
}
inline void
Shader::LightColorUpload(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLLightColorUpload(cgParam, data, size);
    return;
}
inline void
Shader::PulseUpload(void *cgParam, const void *data, uint32_t size)
{
    ;
    ;
    PSGLPulseUpload(cgParam, data, size);
    return;
}
inline uint32_t
Shader::GetDataCoreState(StateID dataID)
{
    ;
    ;
    return PSGLGetDataCoreState(dataID);
}
inline void
Shader::SetDataCoreState(StateID dataID, uint32_t coreState)
{
    ;
    ;
    PSGLSetDataCoreState(dataID, coreState);
    return;
}
class ShaderDataWriter
{
    public:
        ShaderDataWriter(void *cgParam, uint8_t rows, uint8_t columns, Shader::DataType type)
        : m_cgParam(cgParam),
            m_rows(rows),
            m_columns(columns),
            m_type(type)
        {};
        void Write(const rw::math::VecFloat &data) const;
        void Write(const rw::math::Vector2 &data) const;
        void Write(const rw::math::Vector3 &data) const;
        void Write(const rw::math::Vector4 &data) const;
        void Write(const rw::math::Matrix44 &data) const;
        void Write(const rw::math::Matrix44Affine &data) const;
        void Write(const float32_t *data, int32_t numFloats) const;
        void Write(const RwRGBReal &color) const;
        void Write(const RwRGBAReal &color) const;
        void Write(int32_t data) const;
        void Write(const int32_t *data, int32_t numInts) const;
        void Write(RwBool data) const;
        void Write(const RwBool *data, int32_t numBools) const;
    private:
        void *m_cgParam;
        uint8_t m_rows;
        uint8_t m_columns;
        Shader::DataType m_type;
};
inline void
ShaderDataWriter::Write(const rw::math::VecFloat &data) const
{
    ;
    ;


    Shader::PSGLUploadVector(m_cgParam, (const float32_t *) &data, 1);
    return;
}
inline void
ShaderDataWriter::Write(const rw::math::Vector2 &data) const
{
    ;
    ;


    Shader::PSGLUploadVector(m_cgParam, (const float32_t *) &data, 2);
    return;
}
inline void
ShaderDataWriter::Write(const rw::math::Vector3 &data) const
{
    ;
    ;


    Shader::PSGLUploadVector(m_cgParam, (const float32_t *) &data, 3);
    return;
}
inline void
ShaderDataWriter::Write(const rw::math::Vector4 &data) const
{
    ;
    ;


    Shader::PSGLUploadVector(m_cgParam, (const float32_t *) &data, 4);
    return;
}
inline void
ShaderDataWriter::Write(const rw::math::Matrix44 &data) const
{
    ;
    ;


    Shader::PSGLUploadMatrix(m_cgParam, (const float32_t *) &data, 4, 4);
    return;
}
inline void
ShaderDataWriter::Write(const rw::math::Matrix44Affine &data) const
{
    ;
    ;


    Shader::PSGLUploadMatrix(m_cgParam, (const float32_t *) &data, 4, 4);
    return;
}
inline void
ShaderDataWriter::Write(const float32_t *data, int32_t numFloats) const
{
    ;
    ;


    Shader::PSGLUploadVector(m_cgParam, (const float32_t *) data, numFloats);
    return;
}
inline void
ShaderDataWriter::Write(const RwRGBReal &color) const
{
    ;
    ;


    Shader::PSGLUploadVector(m_cgParam, (const float32_t *) &color, 4);
    return;
}
inline void
ShaderDataWriter::Write(const RwRGBAReal &color) const
{
    ;
    ;


    Shader::PSGLUploadVector(m_cgParam, (const float32_t *) &color, 4);
    return;
}
inline void
ShaderDataWriter::Write(int32_t ) const
{
    ;
    ;


    return;
}
inline void
ShaderDataWriter::Write(const int32_t *, int32_t ) const
{
    ;
    ;


    return;
}
inline void
ShaderDataWriter::Write(RwBool ) const
{
    ;
    ;
    return;
}
inline void
ShaderDataWriter::Write(const RwBool *, int32_t ) const
{
    ;
    ;
    return;
}
}
}













namespace rw
{
namespace graphics
{







































































}
}












namespace rw
{
namespace graphics
{
class Raster
{
public:
    enum StateID
    {
        STATEID_NA = 0,
        STATEID_MIN_FILTER = 1,
        STATEID_MAG_FILTER = 2,
        STATEID_ADDRESSING_U = 3,
        STATEID_ADDRESSING_V = 4,
        STATEID_MAX = 5,
        STATEID_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    typedef uint32_t StateValue;
    static const uint32_t TYPE_CAMERA = (0x00000001u);
    static const uint32_t TYPE_ZBUFFER = (0x00000002u);
    static const uint32_t TYPE_NORMAL = (0x00000004u);
    static const uint32_t TYPE_TEXTURE = (0x00000008u);
    static const uint32_t TYPE_BASE_TYPE_MASK = (0x0000000Fu);
    static const uint32_t TYPE_CAMERATEXTURE = (TYPE_CAMERA | TYPE_TEXTURE);
    static const uint32_t TYPE_ZTEXTURE = (TYPE_ZBUFFER | TYPE_CAMERA | TYPE_TEXTURE);
    static const uint32_t TYPE_DYNAMIC = (0x00000010u);
    static const uint32_t TYPE_READ = (0x00000020u);
    static const uint32_t TYPE_DONTALLOCATE = (0x00000100u);
    static const uint32_t TYPE_PSGL_CUBE = (0x00001000u);
    static const uint32_t TYPE_KEEP_DATA = (0x00004000u);
    static const uint32_t TYPE_PSGL_VOLUME = (0x00008000u);
    static const uint32_t TYPE_CUBE = TYPE_PSGL_CUBE;
    static const uint32_t TYPE_VOLUME = TYPE_PSGL_VOLUME;
    static const uint32_t TYPE_VOLUME_OF_DEPTH(const uint32_t )
    {
        ;
        return TYPE_VOLUME;
    }
    static const uint32_t PS3SURFACE_X1R5G5B5_Z1R5G5B5 = (1);
    static const uint32_t PS3SURFACE_X1R5G5B5_O1R5G5B5 = (2);
    static const uint32_t PS3SURFACE_R5G6B5 = (3);
    static const uint32_t PS3SURFACE_X8R8G8B8_Z8R8G8B8 = (4);
    static const uint32_t PS3SURFACE_X8R8G8B8_O8R8G8B8 = (5);
    static const uint32_t PS3SURFACE_A8R8G8B8 = (8);
    static const uint32_t PS3SURFACE_B8 = (9);
    static const uint32_t PS3SURFACE_G8B8 = (10);
    static const uint32_t PS3SURFACE_F_W16Z16Y16X16 = (11);
    static const uint32_t PS3SURFACE_F_W32Z32Y32X32 = (12);
    static const uint32_t PS3SURFACE_F_X32 = (13);
    static const uint32_t PS3SURFACE_X8B8G8R8_Z8B8G8R8 = (14);
    static const uint32_t PS3SURFACE_X8B8G8R8_O8B8G8R8 = (15);
    static const uint32_t PS3SURFACE_A8B8G8R8 = (16);
    static const uint32_t PS3SURFACE_Z16 = (1);
    static const uint32_t PS3SURFACE_Z24S8 = (2);
    static const uint32_t PS3SURFACE_Z24 = (3);
    static const uint32_t PS3REMAP_ORDER_XYXY = (0);
    static const uint32_t PS3REMAP_ORDER_XXXY = (1);
    static const uint32_t PS3REMAP_FROM_A = (0);
    static const uint32_t PS3REMAP_FROM_R = (1);
    static const uint32_t PS3REMAP_FROM_G = (2);
    static const uint32_t PS3REMAP_FROM_B = (3);
    static const uint32_t PS3REMAP_OUTPUT_ZERO = (0);
    static const uint32_t PS3REMAP_OUTPUT_ONE = (1);
    static const uint32_t PS3REMAP_OUTPUT_REMAP = (2);
    enum Format
    {
        FORMAT_NA = -1,
        FORMAT_SURFACE_X1R5G5B5_Z1R5G5B5 = PS3SURFACE_X1R5G5B5_Z1R5G5B5,
        FORMAT_SURFACE_X1R5G5B5_O1R5G5B5 = PS3SURFACE_X1R5G5B5_O1R5G5B5,
        FORMAT_SURFACE_R5G6B5 = PS3SURFACE_R5G6B5,
        FORMAT_SURFACE_X8R8G8B8_Z8R8G8B8 = PS3SURFACE_X8R8G8B8_Z8R8G8B8,
        FORMAT_SURFACE_X8R8G8B8_O8R8G8B8 = PS3SURFACE_X8R8G8B8_O8R8G8B8,
        FORMAT_SURFACE_A8R8G8B8 = PS3SURFACE_A8R8G8B8,
        FORMAT_SURFACE_B8 = PS3SURFACE_B8,
        FORMAT_SURFACE_G8B8 = PS3SURFACE_G8B8,
        FORMAT_SURFACE_F_W16Z16Y16X16 = PS3SURFACE_F_W16Z16Y16X16,
        FORMAT_SURFACE_F_W32Z32Y32X32 = PS3SURFACE_F_W32Z32Y32X32,
        FORMAT_SURFACE_F_X32 = PS3SURFACE_F_X32,
        FORMAT_SURFACE_X8B8G8R8_Z8B8G8R8 = PS3SURFACE_X8B8G8R8_Z8B8G8R8,
        FORMAT_SURFACE_X8B8G8R8_O8B8G8R8 = PS3SURFACE_X8B8G8R8_O8B8G8R8,
        FORMAT_SURFACE_A8B8G8R8 = PS3SURFACE_A8B8G8R8,
        FORMAT_DEPTH_Z16 = PS3SURFACE_Z16,
        FORMAT_DEPTH_Z24S8 = PS3SURFACE_Z24S8,
        FORMAT_DEPTH_Z24 = PS3SURFACE_Z24,
        FORMAT_B8 = ( 0),
        FORMAT_A1R5G5B5 = ( 1),
        FORMAT_A4R4G4B4 = ( 2),
        FORMAT_R5G6B5 = ( 3),
        FORMAT_A8R8G8B8 = ( 4),
        FORMAT_COMPRESSED_DXT1 = ( 5),
        FORMAT_COMPRESSED_DXT23 = ( 6),
        FORMAT_COMPRESSED_DXT45 = ( 7),
        FORMAT_G8B8 = ( 8),
        FORMAT_R6G5B5 = ( 9),
        FORMAT_DEPTH24_STENCIL8 = (10),
        FORMAT_DEPTH24_STENCIL8F = (11),
        FORMAT_DEPTH16 = (12),
        FORMAT_FLOAT_DEPTH16 = (13),
        FORMAT_X16 = (14),
        FORMAT_Y16_X16 = (15),
        FORMAT_R5G5B5A1 = (16),
        FORMAT_COMPRESSED_HILO8 = (17),
        FORMAT_COMPRESSED_HILO_S8 = (18),
        FORMAT_W16_Z16_Y16_X16_FLOAT = (19),
        FORMAT_W32_Z32_Y32_X32_FLOAT = (20),
        FORMAT_X32_FLOAT = (21),
        FORMAT_D1R5G5B5 = (22),
        FORMAT_D8R8G8B8 = (23),
        FORMAT_Y16_X16_FLOAT = (24),
        FORMAT_R8G8B8A8 = (25),
        FORMAT_LIN_A8R8G8B8 = (26),
        FORMAT_8888 = FORMAT_A8R8G8B8,
        FORMAT_1555 = FORMAT_A1R5G5B5,
        FORMAT_565 = FORMAT_R5G6B5,
        FORMAT_4444 = FORMAT_A4R4G4B4,
        FORMAT_ALPHA = FORMAT_B8,
        FORMAT_RGBA = FORMAT_R8G8B8A8,
        FORMAT_DXT1 = FORMAT_COMPRESSED_DXT1,
        FORMAT_DXT2 = FORMAT_COMPRESSED_DXT23,
        FORMAT_DXT3 = FORMAT_COMPRESSED_DXT23,
        FORMAT_DXT4 = FORMAT_COMPRESSED_DXT45,
        FORMAT_DXT5 = FORMAT_COMPRESSED_DXT45,
        FORMAT_DXT1_RGB = FORMAT_COMPRESSED_DXT1,
        FORMAT_DXT1_RGBA = FORMAT_COMPRESSED_DXT1,
        FORMAT_DXT3_RGBA = FORMAT_COMPRESSED_DXT23,
        FORMAT_DXT5_RGBA = FORMAT_COMPRESSED_DXT45,
        FORMAT_888 = FORMAT_NA,
        FORMAT_RGBA8_CAMERA = FORMAT_NA,
        FORMAT_RGBA16_CAMERA = FORMAT_NA,
        FORMAT_FLOAT_RGBA16_CAMERA = FORMAT_NA,
        FORMAT_FLOAT_RGBA32_CAMERA = FORMAT_NA,
        FORMAT_FLOAT_RGBA32 = FORMAT_NA,
        FORMAT_FLOAT_DEPTH32 = FORMAT_NA,
        FORMAT_DEPTH32 = FORMAT_NA,
        FORMAT_STENCIL8 = FORMAT_NA,
        FORMAT_LUM16 = FORMAT_NA,
        FORMAT_16 = FORMAT_NA,
        FORMAT_24 = FORMAT_NA,
        FORMAT_32 = FORMAT_NA,
        FORMAT_PAL4 = FORMAT_NA,
        FORMAT_LUM4 = FORMAT_NA,
        FORMAT_PAL8 = FORMAT_NA,
        FORMAT_LUM8 = FORMAT_NA,
        FORMAT_555 = FORMAT_NA,
        FORMAT_A8B8G8R8 = FORMAT_NA,
        FORMAT_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    enum PSGLTarget
    {
        PSGLTARGET_NA = 0,
        PSGLTARGET_2D = 0x0DE1,
        PSGLTARGET_3D = 0x806F,
        PSGLTARGET_CUBEMAP = 0x8513,
        PSGLTARGET_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1)),
    };
    enum PSGLFormat
    {
        PSGLFORMAT_NA = 0,
        PSGLFORMAT_ALPHA = 0x1906,
        PSGLFORMAT_RGB = 0x1907,
        PSGLFORMAT_RGBA = 0x1908,
        PSGLFORMAT_LUMINANCE = 0x1909,
        PSGLFORMAT_LUMINANCE_ALPHA = 0x190A,
        PSGLFORMAT_RGB_DXT1 = 0x83F0,
        PSGLFORMAT_RGBA_DXT1 = 0x83F1,
        PSGLFORMAT_RGBA_DXT3 = 0x83F2,
        PSGLFORMAT_RGBA_DXT5 = 0x83F3,
        PSGLFORMAT_PAL4_RGB8 = 0x8B90,
        PSGLFORMAT_PAL4_RGBA8 = 0x8B91,
        PSGLFORMAT_PAL4_R5_G6_B5 = 0x8B92,
        PSGLFORMAT_PAL4_RGBA4 = 0x8B93,
        PSGLFORMAT_PAL4_RGB5_A1 = 0x8B94,
        PSGLFORMAT_PAL8_RGB8 = 0x8B95,
        PSGLFORMAT_PAL8_RGBA8 = 0x8B96,
        PSGLFORMAT_PAL8_R5_G6_B5 = 0x8B97,
        PSGLFORMAT_PAL8_RGBA4 = 0x8B98,
        PSGLFORMAT_PAL8_RGB5_A1 = 0x8B99,
        PSGLFORMAT_ARGB_SCE = 0x6007,
        PSGLFORMAT_ABGR = 0x8000,
        PSGLFORMAT_RGBA16F_ARB = 0x881A,
        PSGLFORMAT_RGBA32F_ARB = 0x8814,
        PSGLFORMAT_BGRA = 0x80E1,
        PSGLFORMAT_DEPTH = 0x1902,
        PSGLFORMAT_DEPTH16 = 0x81A5,
        PSGLFORMAT_DEPTH24 = 0x81A6,
        PSGLFORMAT_DEPTH32 = 0x81A7,
        PSGLFORMAT_DEPTH16_SCE = 0x6000,
        PSGLFORMAT_DEPTH32_SCE = 0x6001,
        PSGLFORMAT_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    enum PSGLDataType
    {
        PSGLDATATYPE_NA = 0,
        PSGLDATATYPE_UBYTE = 0x1401,
        PSGLDATATYPE_USHORT = 0x1403,
        PSGLDATATYPE_SHORT_4_4_4_4 = 0x8033,
        PSGLDATATYPE_SHORT_4_4_4_4_REV = 0x8365,
        PSGLDATATYPE_SHORT_5_5_5_1 = 0x8034,
        PSGLDATATYPE_SHORT_1_5_5_5_REV = 0x8366,
        PSGLDATATYPE_SHORT_5_6_5 = 0x8363,
        PSGLDATATYPE_SHORT_5_6_5_REV = 0x8364,
        PSGLDATATYPE_UBYTE_8_8_8_8 = 0x8035,
        PSGLDATATYPE_UBYTE_8_8_8_8_REV = 0x8367,
        PSGLDATATYPE_UBYTE_8888_REV = PSGLDATATYPE_UBYTE_8_8_8_8_REV,
        PSGLDATATYPE_INT_24_8 = 0x6008,
        PSGLDATATYPE_FLOAT = 0x1406,
        PSGLDATATYPE_FLOAT_16 = 0x140B,
        PSGLDATATYPE_COMPRESSED = 0xffff,
        PSGLDATATYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    enum Filter
    {
        FILTER_NA = 0,
        FILTER_NEAREST = 0x2600,
        FILTER_LINEAR = 0x2601,
        FILTER_MIPNEAREST = 0x2700,
        FILTER_MIPLINEAR = 0x2701,
        FILTER_LINEARMIPNEAREST = 0x2702,
        FILTER_LINEARMIPLINEAR = 0x2703,
        FILTER_ANISOTROPIC = FILTER_NA,
        FILTER_MIPANISOTROPIC = FILTER_NA,
        FILTER_LINEARMIPANISOTROPIC = FILTER_NA,
        FILTER_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    enum Addressing
    {
        ADDRESSING_NA = 0,
        ADDRESSING_WRAP = 0x2901,
        ADDRESSING_MIRROR = ADDRESSING_NA,
        ADDRESSING_CLAMP = 0x812F,
        ADDRESSING_BORDER = ADDRESSING_NA,
        ADDRESSING_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    struct ParameterStates
    {
        Filter m_minFilter;
        Filter m_magFilter;
        Addressing m_addressU;
        Addressing m_addressV;
    };
    struct Locked
    {
        Raster *lockedRaster;
        uint8_t *pixelData;
        uint32_t lockFlags;
        uint8_t lockedMipLevel;
        uint8_t pad0;
        uint16_t stride;
    };
    enum CubeMapFace
    {
        CUBEMAPFACE_NA = -1,
        CUBEMAPFACE_POSITIVE_X = 0,
        CUBEMAPFACE_NEGATIVE_X = 1,
        CUBEMAPFACE_POSITIVE_Y = 2,
        CUBEMAPFACE_NEGATIVE_Y = 3,
        CUBEMAPFACE_POSITIVE_Z = 4,
        CUBEMAPFACE_NEGATIVE_Z = 5,
        CUBEMAPFACE_MAX = 6,
        CUBEMAPFACE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1)),
    };
    static rw::ResourceDescriptor GetResourceDescriptor(uint16_t width, uint16_t height, uint8_t numMipLevels, uint32_t typeFlags, Format fmt); static uint32_t GetAlignment(uint16_t width, uint16_t height, uint8_t numMipLevels, uint32_t typeFlags, Format fmt); static uint32_t GetSize(uint16_t width, uint16_t height, uint8_t numMipLevels, uint32_t typeFlags, Format fmt); static Raster *Initialize(void *ptr, uint32_t size, uint16_t width, uint16_t height, uint8_t numMipLevels, uint32_t typeFlags, Format fmt); static Raster *Initialize(const rw::Resource &resource, uint16_t width, uint16_t height, uint8_t numMipLevels, uint32_t typeFlags, Format fmt); static void Destruct(Raster *raster); void Release(); uint16_t GetWidth() const; uint16_t GetHeight() const; uint8_t GetDepth() const; uint8_t GetNumMipLevels() const; int32_t GetType() const; Format GetFormat() const; uint32_t GetLinearBufferSize(uint8_t mipLevel) const; Raster *Lock(uint32_t lockFlags, uint8_t mipLevel, Locked &lockedRaster); Raster *Unlock(Locked &lockedRaster); RwBool Fill(const void *pixelData, uint8_t mipLevel); RwBool Extract(void *pixelData, uint32_t size, uint8_t mipLevel); static uint8_t FormatGetDepth(Format fmt); static RwBool FormatSupportsAlpha(Format fmt); static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks();
    void SetActiveFace(CubeMapFace face); CubeMapFace GetActiveFace() const;
    void PSGLSetActiveFace(CubeMapFace face);
    CubeMapFace PSGLGetActiveFace() const;
    PSGLTarget PSGLGetTarget() const;
    uint32_t PSGLGetName() const;
    uint32_t PSGLGetRenderBuffer() const;
    ParameterStates *PSGLParameterStates();
    const ParameterStates *PSGLParameterStates() const;
    uint32_t PSGLGetSurface() const;
    void PSGLSetSurface(uint32_t surface);
    void PSGLCameraTextureBeginUpdate();
    void PSGLCameraTextureEndUpdate();
    const void *PSGLGetPixelData() const;
    void *PSGLGetPixelData();
    void PSGLSetPixelData(void *data);
    uint32_t PSGLGetPixelDataSize() const;

    void *PSGLUpdateBegin(uint32_t flags);
    void PSGLUpdateEnd();

    bool PSGLZStencil() const;
protected:
private:

    void *PSGLRawLock(uint32_t flags);
    void PSGLRawUnlock();

    struct PSGLFormatDetails
    {
        PSGLFormat m_internalFormat;
        PSGLFormat m_dataFormat;
        PSGLDataType m_dataType;
    };
    static uint32_t PSGLBitsPerPixel(Format fmt);
    static uint32_t PSGLBitsPerPixel(PSGLFormat psglFormat, PSGLDataType psglDataType);
    static uint32_t PSGLMipLevelStride(PSGLFormat psglFormat, PSGLDataType psglDataType,
                                           uint16_t width, uint8_t mipLevel);
    static uint8_t PSGLMipLevels(uint16_t width, uint16_t height);
    static uint32_t PSGLMipLevelSize(PSGLFormat psglFormat, PSGLDataType psglDataType, uint16_t width,
                                         uint16_t height, uint8_t mipLevel);
    static uint32_t PSGLFaceSize(PSGLFormat psglFormat, PSGLDataType psglDataType, uint16_t width,
                                     uint16_t height, uint8_t mipLevels);
    uint32_t PSGLBitsPerPixel() const;
    uint32_t PSGLMipLevelStride(uint8_t mipLevel) const;
    uint32_t PSGLMipLevelSize(uint8_t mipLevel) const;
    uint32_t PSGLFaceSize() const;
    uint32_t PSGLDataOffset(uint8_t mipLevel) const;
    void SetDetailsFromFormat(Format fmt);
    void PSGLCreateGPUObjects();
    void PSGLSetPointer(uint32_t target, uint8_t mipLevel, uint16_t width, uint16_t height,
                                       uint32_t span, void *pixels);
    void PSGLFillPBO(uint8_t mipLevel);
    void PSGLUploadLevel(uint8_t mipLevel);
    void PSGLUploadData();
    static const uint32_t m_PSGLCubemapFaceTable[];
    static const PSGLFormatDetails m_formatDetails[];
    void* m_data;
    union
    {
        uint32_t m_name;
        uint32_t m_renderBuffer;
    };
    ParameterStates m_paramStates;
    uint32_t m_type;
    PSGLTarget m_target;
    PSGLFormat m_internalFormat;
    PSGLFormat m_dataFormat;
    PSGLDataType m_dataType;
    uint32_t m_bufferName;
    uint16_t m_width;
    uint16_t m_height;
    uint8_t m_numMipLevels;
    uint8_t m_face;
    Raster();
    Raster(const Raster &raster);
    ~Raster();
};
inline uint16_t
Raster::GetWidth() const
{
    ;
    return m_width;
}
inline uint16_t
Raster::GetHeight() const
{
    ;
    return m_height;
}
inline uint8_t
Raster::GetNumMipLevels() const
{
    ;
    return m_numMipLevels;
}
inline int32_t
Raster::GetType() const
{
    ;
    return m_type;
}
inline uint8_t
Raster::FormatGetDepth(Format fmt)
{
    ;
    return static_cast<uint8_t>(PSGLBitsPerPixel(fmt));
}
inline uint32_t
Raster::GetLinearBufferSize(uint8_t mipLevel) const
{
    ;

    ;

    ;


    return PSGLMipLevelSize(mipLevel);
}
inline bool
Raster::PSGLZStencil() const
{
    ;
    ;

    return m_dataType == m_formatDetails[FORMAT_DEPTH24_STENCIL8].m_dataType;



}
inline void
Raster::SetActiveFace(CubeMapFace face)
{
    ;
    ;
    ;
    m_face = static_cast<uint8_t>(face);
    return;
}
inline void
Raster::PSGLSetActiveFace(CubeMapFace face)
{
    ;
    ;
    SetActiveFace(face);
    return;
}
inline Raster::CubeMapFace
Raster::GetActiveFace() const
{
    ;
    ;
    return static_cast<CubeMapFace>(m_face);
}
inline Raster::CubeMapFace
Raster::PSGLGetActiveFace() const
{
    ;
    ;
    return GetActiveFace();
}
inline Raster::PSGLTarget
Raster::PSGLGetTarget() const
{
    ;
    ;
    return m_target;
}
inline uint32_t
Raster::PSGLGetName() const
{
    ;
    return m_name;
}
inline uint32_t
Raster::PSGLGetRenderBuffer() const
{
    ;
    ;
    return m_renderBuffer;
}
inline uint32_t
Raster::PSGLBitsPerPixel() const
{
    ;
    return PSGLBitsPerPixel(m_dataFormat, m_dataType);
}
inline const void *
Raster::PSGLGetPixelData() const
{
    ;
    return m_data;
}
inline void *
Raster::PSGLGetPixelData()
{
    ;
    return m_data;
}
inline void
Raster::PSGLSetPixelData(void *data)
{
    ;
    m_data = data;
    return;
}
inline Raster::ParameterStates *
Raster::PSGLParameterStates()
{
    ;
    return &m_paramStates;
}
inline const Raster::ParameterStates *
Raster::PSGLParameterStates() const
{
    ;
    return &m_paramStates;
}
}
}













namespace rw
{
namespace graphics
{
class DeviceInfoData;


























































}
}








namespace rw
{
namespace graphics
{






class Device
{
public:
    typedef PSGLDeviceState StateID;
    typedef uint32_t StateValue;
    enum State { STATE_NA = -1, STATE_COLD = 0, STATE_INITIALIZE = 1, STATE_START = 2, STATE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1)) }; class Parameters; typedef Parameters VideoMode; static RwBool Initialize(); static void Release(); static RwBool Start(); static void Stop(); static RwBool StartInternal(const Parameters &parameters); static RwBool Reset(const Parameters &parameters); static RwBool Start(const Parameters &parameters); static Raster *GetBackBuffer(); static Raster *GetZBuffer(); static Raster *GetCameraRaster(); static Raster *GetZBufferRaster(); static RwBool SceneBegin(); static void SceneEnd(); static void ShowRaster(Raster *raster); static RwBool ValidateVideoMode(const VideoMode &mode); static RwBool SetVideoMode(const VideoMode &mode); static const VideoMode GetVideoMode(); static void BlockUntilIdle(); static uint32_t GetCurrentFrameIndex(); static RwBool IsFrameFinished(uint32_t frameIndex); static uint32_t GetVersion(uint32_t userVersion); static uint32_t GetVersionFull(uint32_t userVersion, uint32_t headerVersion);
    class Parameters
    {
        friend class Device;
    public:
        enum DisplayType
        {
            DISPLAYTYPE_NA = 0,
            DISPLAYTYPE_VGA,
            DISPLAYTYPE_720P,
            DISPLAYTYPE_720P_AA,
            DISPLAYTYPE_1080I,
            DISPLAYTYPE_1080I_AA,
            DISPLAYTYPE_1080P,
            DISPLAYTYPE_1080P_AA,
            DISPLAYTYPE_VESA_1280x768,
            DISPLAYTYPE_VESA_1280x768_AA,
            DISPLAYTYPE_VESA_1280x1024,
            DISPLAYTYPE_VESA_1280x1024_AA,
            DISPLAYTYPE_VESA_1920x1200,
            DISPLAYTYPE_VESA_1920x1200_AA,
            DISPLAYTYPE_DEFAULT = DISPLAYTYPE_720P_AA
        };
        RwBool Validate(void) const;
        void SetBackBufferWidth(uint32_t width); uint32_t GetBackBufferWidth() const; void SetBackBufferHeight(uint32_t height); uint32_t GetBackBufferHeight() const; void SetBackBufferFormat(Raster::Format format); Raster::Format GetBackBufferFormat() const; void SetFrontBufferWidth(uint32_t width); uint32_t GetFrontBufferWidth() const; void SetFrontBufferHeight(uint32_t height); uint32_t GetFrontBufferHeight() const; void SetFrontBufferFormat(Raster::Format format); Raster::Format GetFrontBufferFormat() const; void SetZBufferFormat(Raster::Format format); Raster::Format GetZBufferFormat() const; void SetNumFramesToBuffer(uint32_t frames); uint32_t GetNumFramesToBuffer() const; void SetNumVSyncToWait(uint32_t vsyncs); uint32_t GetNumVSyncToWait() const;;
        void PSGLSetColorBits(int32_t numColorBits);
        int32_t PSGLGetColorBits() const;
        void PSGLSetAlphaBits(int32_t numAlphaBits);
        int32_t PSGLGetAlpaBits() const;
        void PSGLSetDepthBits(int32_t numDepthBits);
        int32_t PSGLGetDepthBits() const;
        void PSGLSetStencilBits(int32_t numStencilBits);
        int32_t PSGLGetStencilBits() const;
        void PSGLSetBufferingMode(PSGLbufferingMode bufferingMode);
        PSGLbufferingMode PSGLGetBufferingMode() const;
        void PSGLSetAntiAliasing(uint8_t antiAliasing);
        uint8_t PSGLGetAntiAliasing() const;
        void PSGLSetEnableInitOptions(uint32_t enableInitOptions);
        uint32_t PSGLGetEnableInitOptions() const;
        void PSGLSetMaxSPUs(uint32_t maxSPUs);
        uint32_t PSGLGetMaxSPUs() const;
        void PSGLSetInitializeSPUs(uint8_t initializeSPUs);
        uint8_t PSGLGetInitializeSPUs() const;
        void PSGLSetPersistentMemory(uint32_t persistentMemory);
        uint32_t PSGLGetPersistentMemory() const;
        void PSGLSetTransientMemory(uint32_t transientMemory);
        uint32_t PSGLGetTransientMemory() const;
        void PSGLSetErrorConsole(uint32_t errorConsole);
        uint32_t PSGLGetErrorConsole() const;
        void PSGLSetFIFOSize(uint32_t fifoSize);
        uint32_t PSGLGetFIFOSize() const;
        void PSGLSetHostMemorySize(uint32_t hostMemorySize);
        uint32_t PSGLGetHostMemorySize() const;
    private:
        Parameters()
        {
            ;
            return;
        }
        int32_t m_width;
        int32_t m_height;
        int32_t m_colorBits;
        int32_t m_alphaBits;
        int32_t m_depthBits;
        int32_t m_stencilBits;
        uint32_t m_deviceType;
        uint32_t m_tvStandard;
        uint32_t m_tvFormat;
        uint32_t m_bufferingMode;
        uint8_t m_antiAliasing;
        uint32_t m_enableInitOptions;
        uint32_t m_maxSPUs;
        uint8_t m_initializeSPUs;
        uint32_t m_persistentMemorySize;
        uint32_t m_transientMemorySize;
        uint32_t m_errorConsole;
        uint32_t m_fifoSize;
        uint32_t m_hostMemorySize;
        Raster::Format m_backBufferFormat;
        Raster::Format m_zBufferFormat;
        uint32_t m_numFramesToBuffer;
        uint32_t m_vSyncWait;
        void Initialize(DisplayType displayType);
    public:
        Parameters(DisplayType displayType)
        {
            ;
            Initialize(displayType);
            return;
        }
    };
    static Parameters GetParameters(void)
    {
        ;
        return m_parameters;
    };

    static void *PSGLCreateCgVertexProgramFromByteCode(const RwChar *byteCode, const RwChar *entry = 0);
    static void *PSGLCreateCgFragmentProgramFromByteCode(const RwChar *byteCode, const RwChar *entry = 0);
    static void PSGLDestroyCgProgram(void *program);
    static void *PSGLGetCGcontext();

private:

    static void PSGLSurfaceInitialize();
    static void PSGLSurfaceRelease();

protected:
private:
    static const uint32_t m_currentVersion; static State m_state; static Raster *m_defaultCameraRaster; static Raster *m_defaultZBufferRaster;
    static Parameters m_parameters;
    Device();
    Device(const Device &device);
    ~Device();
};
inline RwBool
Device::SceneBegin()
{
    ;
    ;
    return (1);
}
inline void
Device::SceneEnd()
{
    ;
    ;
    return;
}
inline RwBool
Device::Start()
{
    ;
    ;
    return StartInternal(Parameters::DISPLAYTYPE_DEFAULT);
}
inline RwBool
Device::Start(const Parameters &parameters)
{
    ;
    return StartInternal(parameters);
}
inline void
Device::Parameters::SetBackBufferWidth(uint32_t width)
{
    ;
    m_width = static_cast<int32_t>(width);
    return;
}
inline uint32_t
Device::Parameters::GetBackBufferWidth() const
{
    ;
    return m_width;
}
inline void
Device::Parameters::SetBackBufferHeight(uint32_t height)
{
    ;
    m_height = static_cast<int32_t>(height);
    return;
}
inline uint32_t
Device::Parameters::GetBackBufferHeight() const
{
    ;
    return m_height;
}
inline void
Device::Parameters::SetBackBufferFormat(Raster::Format format)
{
    ;
    ;




    m_backBufferFormat = format;
    if (Raster::FORMAT_RGBA8_CAMERA == format)
    {
        m_colorBits = 24;
        m_alphaBits = 8;
    }
    else if (Raster::FORMAT_RGBA16_CAMERA == format)
    {
        m_colorBits = 48;
        m_alphaBits = 16;
    }
    else if (Raster::FORMAT_FLOAT_RGBA16_CAMERA == format)
    {
        m_colorBits = 48;
        m_alphaBits = 16;
    }
    else if (Raster::FORMAT_FLOAT_RGBA32_CAMERA == format)
    {
        m_colorBits = 96;
        m_alphaBits = 32;
    }
    return;
}
inline Raster::Format
Device::Parameters::GetBackBufferFormat() const
{
    ;
    return m_backBufferFormat;
}
inline void
Device::Parameters::SetFrontBufferWidth(uint32_t )
{
    ;
    ;
    return;
}
inline uint32_t
Device::Parameters::GetFrontBufferWidth() const
{
    ;
    ;
    return 0;
}
inline void
Device::Parameters::SetFrontBufferHeight(uint32_t )
{
    ;
    ;
    return;
}
inline uint32_t
Device::Parameters::GetFrontBufferHeight() const
{
    ;
    ;
    return 0;
}
inline void
Device::Parameters::SetFrontBufferFormat(Raster::Format )
{
    ;
    ;
    return;
}
inline Raster::Format
Device::Parameters::GetFrontBufferFormat() const
{
    ;
    ;
    return Raster::FORMAT_NA;
}
inline void
Device::Parameters::SetZBufferFormat(Raster::Format format)
{
    ;
    ;






    m_zBufferFormat = format;
    if (Raster::FORMAT_FLOAT_DEPTH16 == format)
    {
        m_depthBits = 16;
        m_stencilBits = 0;
    }
    else if (Raster::FORMAT_FLOAT_DEPTH32 == format)
    {
        m_depthBits = 32;
        m_stencilBits = 0;
    }
    else if (Raster::FORMAT_DEPTH16 == format)
    {
        m_depthBits = 16;
        m_stencilBits = 0;
    }
    else if (Raster::FORMAT_DEPTH32 == format)
    {
        m_depthBits = 32;
        m_stencilBits = 0;
    }
    else if (Raster::FORMAT_DEPTH24_STENCIL8 == format)
    {
        m_depthBits = 24;
        m_stencilBits = 8;
    }
    else if (Raster::FORMAT_STENCIL8 == format)
    {
        m_depthBits = 0;
        m_stencilBits = 8;
    }
    return;
}
inline Raster::Format
Device::Parameters::GetZBufferFormat() const
{
    ;
    return m_zBufferFormat;
}
inline void
Device::Parameters::SetNumFramesToBuffer(uint32_t frames)
{
    ;
    ;
    m_numFramesToBuffer = frames;
    return;
}
inline uint32_t
Device::Parameters::GetNumFramesToBuffer() const
{
    ;
    return m_numFramesToBuffer;
}
inline void
Device::Parameters::SetNumVSyncToWait(uint32_t vsyncs)
{
    ;
    ;
    m_vSyncWait = vsyncs;
    return;
}
inline uint32_t
Device::Parameters::GetNumVSyncToWait() const
{
    ;
    return m_vSyncWait;
}
inline void
Device::Parameters::PSGLSetColorBits(int32_t numColorBits)
{
    ;
    m_colorBits = numColorBits;
    return;
}
inline int32_t
Device::Parameters::PSGLGetColorBits() const
{
    ;
    return m_colorBits;
}
inline void
Device::Parameters::PSGLSetAlphaBits(int32_t numAlphaBits)
{
    ;
    m_alphaBits = numAlphaBits;
    return;
}
inline int32_t
Device::Parameters::PSGLGetAlpaBits() const
{
    ;
    return m_alphaBits;
}
inline void
Device::Parameters::PSGLSetDepthBits(int32_t numDepthBits)
{
    ;
    m_depthBits = numDepthBits;
    return;
}
inline int32_t
Device::Parameters::PSGLGetDepthBits() const
{
    ;
    return m_depthBits;
}
inline void
Device::Parameters::PSGLSetStencilBits(int32_t numStencilBits)
{
    ;
    m_stencilBits = numStencilBits;
    return;
}
inline int32_t
Device::Parameters::PSGLGetStencilBits() const
{
    ;
    return m_stencilBits;
}
inline void
Device::Parameters::PSGLSetBufferingMode(PSGLbufferingMode bufferingMode)
{
    ;

    ;




    m_bufferingMode = static_cast<uint32_t>(bufferingMode);
    return;
}
inline PSGLbufferingMode
Device::Parameters::PSGLGetBufferingMode() const
{
    ;
    return static_cast<PSGLbufferingMode>(m_bufferingMode);
}
inline void
Device::Parameters::PSGLSetAntiAliasing(uint8_t antiAliasing)
{
    ;
    m_antiAliasing = ((0 == antiAliasing) ? 0 : 1);
    return;
}
inline uint8_t
Device::Parameters::PSGLGetAntiAliasing() const
{
    ;
    return m_antiAliasing;
}
inline void
Device::Parameters::PSGLSetEnableInitOptions(uint32_t enableInitOptions)
{
    ;

    ;








    m_enableInitOptions = enableInitOptions;
    return;
}
inline uint32_t
Device::Parameters::PSGLGetEnableInitOptions() const
{
    ;
    return m_enableInitOptions;
}
inline void
Device::Parameters::PSGLSetMaxSPUs(uint32_t maxSPUs)
{
    ;
    ;

    m_enableInitOptions |= 0x0001;

    m_maxSPUs = maxSPUs;
    return;
}
inline uint32_t
Device::Parameters::PSGLGetMaxSPUs() const
{
    ;
    return m_maxSPUs;
}
inline void
Device::Parameters::PSGLSetInitializeSPUs(uint8_t initializeSPUs)
{
    ;

    m_enableInitOptions |= 0x0002;

    m_initializeSPUs = ((0 == initializeSPUs) ? 0 : 1);
    return;
}
inline void
Device::Parameters::PSGLSetHostMemorySize(uint32_t hostMemorySize)
{
    ;

    m_enableInitOptions |= 0x0040;

    m_hostMemorySize = hostMemorySize;
    return;
}
inline uint32_t
Device::Parameters::PSGLGetHostMemorySize() const
{
    ;
    return m_hostMemorySize;
}
inline uint8_t
Device::Parameters::PSGLGetInitializeSPUs() const
{
    ;
    return m_initializeSPUs;
}
inline void
Device::Parameters::PSGLSetPersistentMemory(uint32_t persistentMemory)
{
    ;

    m_enableInitOptions |= 0x0004;

    m_persistentMemorySize = persistentMemory;
    return;
}
inline uint32_t
Device::Parameters::PSGLGetPersistentMemory() const
{
    ;
    return m_persistentMemorySize;
}
inline void
Device::Parameters::PSGLSetTransientMemory(uint32_t transientMemory)
{
    ;

    m_enableInitOptions |= 0x0008;

    m_transientMemorySize = transientMemory;
    return;
}
inline uint32_t
Device::Parameters::PSGLGetTransientMemory() const
{
    ;
    return m_transientMemorySize;
}
inline void
Device::Parameters::PSGLSetErrorConsole(uint32_t errorConsole)
{
    ;

    m_enableInitOptions |= 0x0010;

    m_errorConsole = errorConsole;
    return;
}
inline uint32_t
Device::Parameters::PSGLGetErrorConsole() const
{
    ;
    return m_errorConsole;
}
inline void
Device::Parameters::PSGLSetFIFOSize(uint32_t fifoSize)
{
    ;

    m_enableInitOptions |= 0x0020;

    m_fifoSize = fifoSize;
    return;
}
inline uint32_t
Device::Parameters::PSGLGetFIFOSize() const
{
    ;
    return m_fifoSize;
}
}
}




namespace rw
{
namespace graphics
{
inline Raster *
Device::GetBackBuffer()
{
    ;
    return m_defaultCameraRaster;
}
inline Raster *
Device::GetZBuffer()
{
    ;
    return m_defaultZBufferRaster;
}
inline Raster *
Device::GetCameraRaster()
{
    ;
    ;
    return GetBackBuffer();
}
inline Raster *
Device::GetZBufferRaster()
{
    ;
    ;
    return GetZBuffer();
}
inline uint32_t
Device::GetVersionFull(uint32_t userVersion, uint32_t )
{
    ;
    ;
    if (userVersion)
    {
        ;
    }
    return m_currentVersion;
}
inline uint32_t
Device::GetVersion(uint32_t userVersion)
{
    ;
    return GetVersionFull(userVersion, m_currentVersion);
}
}
}









namespace rw
{
namespace graphics
{


































}
}








namespace rw
{
namespace graphics
{
class Camera
{
public:
    enum Projection
    {
        PROJECTION_NA = 0,
        PROJECTION_PERSPECTIVE = 1,
        PROJECTION_PARALLEL = 2,
        PROJECTION_PERSPECTIVE_INFINITE = 3,
        PROJECTION_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    struct PSGLViewport
    {
        int32_t x;
        int32_t y;
        int32_t width;
        int32_t height;
    };
    static rw::ResourceDescriptor GetResourceDescriptor(); static uint32_t GetAlignment(); static uint32_t GetSize(); static Camera *Initialize(const rw::Resource &resource); static Camera *Initialize(void *ptr, uint32_t size); void Release(); void SetViewOffset(float32_t xOffset, float32_t yOffset); void SetViewWindow(float32_t x, float32_t y); void SetRaster(Raster *raster); void SetZRaster(Raster *zraster); void SetProjectionType(Projection p); void SetNearClip(float32_t nearPlane); void SetFarClip(float32_t farPlane); void SetTransform(const rw::math::Matrix44Affine &matrix); void GetViewOffset(float32_t &xOffset, float32_t &yOffset) const; void GetViewWindow(float32_t &x, float32_t &y) const; Raster *GetRaster() const; Raster *GetZRaster() const; Projection GetProjectionType() const; float32_t GetNearClip() const; float32_t GetFarClip() const; rw::math::Matrix44Affine GetTransform() const; void SetViewport(uint16_t xOrigin, uint16_t yOrigin, uint16_t width, uint16_t height); void GetViewport(uint16_t &xOrigin, uint16_t &yOrigin, uint16_t &width, uint16_t &height) const; RwBool Clear(const RwRGBAReal *rgba, uint32_t flags); RwBool BeginUpdate(); RwBool EndUpdate(); static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(void); static void RegisterArenaWriteCallbacks(void);
    const rw::math::Matrix44 &PSGLGetProjectionMatrix() const;
    void PSGLSetStencil(Raster *raster);
protected:
private:
    void PSGLCreateFrameBuffer();
    rw::math::Matrix44Affine m_transform;
    rw::math::Matrix44 m_projectionMatrix;
    Raster* m_raster;
    Raster* m_zBuffer;
    Raster* m_stencilBuffer;
    rw::math::fpu::Vector2U_32 m_viewOffset;
    rw::math::fpu::Vector2U_32 m_viewWindow;
    rw::math::fpu::Vector2U_32 m_recipViewWindow;
    uint32_t m_frameBufferObject;
    Projection m_projectionType;
    float32_t m_nearPlane;
    float32_t m_farPlane;
    PSGLViewport m_viewport;
    Camera();
    Camera(const Camera &camera);
    ~Camera();
};
inline void
Camera::SetNearClip(float32_t nearPlane)
{
    ;
    ;
    m_nearPlane = nearPlane;
    return;
}
inline void
Camera::SetFarClip(float32_t farPlane)
{
    ;
    ;
    m_farPlane = farPlane;
    return;
}
inline void
Camera::SetTransform(const rw::math::Matrix44Affine &matrix)
{
    ;
    m_transform = matrix;
    return;
}
inline void
Camera::GetViewOffset(float32_t &xOffset, float32_t &yOffset) const
{
    ;
    xOffset = m_viewOffset.X();
    yOffset = m_viewOffset.Y();
    return;
}
inline void
Camera::GetViewWindow(float32_t &x, float32_t &y) const
{
    ;
    x = m_viewWindow.X();
    y = m_viewWindow.Y();
    return;
}
inline Raster *
Camera::GetRaster() const
{
    ;
    return m_raster;
}
inline Raster *
Camera::GetZRaster() const
{
    ;
    return m_zBuffer;
}
inline Camera::Projection
Camera::GetProjectionType() const
{
    ;
    return m_projectionType;
}
inline float32_t
Camera::GetNearClip() const
{
    ;
    return m_nearPlane;
}
inline float32_t
Camera::GetFarClip() const
{
    ;
    return m_farPlane;
}
inline rw::math::Matrix44Affine
Camera::GetTransform() const
{
    ;
    return m_transform;
}
inline const rw::math::Matrix44 &
Camera::PSGLGetProjectionMatrix() const
{
    ;
    return m_projectionMatrix;
}
}
}













namespace rw
{
namespace graphics
{

























}
}






namespace rw
{
namespace graphics
{
class Light
{
public:
    enum Type
    {
        TYPE_NA = -1,
        TYPE_DIRECTIONAL = 0,
        TYPE_POINT,
        TYPE_SPOT,
        TYPE_AREA,
        TYPE_HEMISPHERICAL,
        TYPE_NUMTYPES,
        TYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    static rw::ResourceDescriptor GetResourceDescriptor(Type type); static uint32_t GetAlignment(Type type); static uint32_t GetSize(Type type); static Light *Initialize(void *ptr, uint32_t size, Type type); static Light *Initialize(const rw::Resource &resource, Type type); void Release(); void SetPosition(rw::math::Vector3::InParam pos); void SetDirection(rw::math::Vector3::InParam dir); void SetColor(const RwRGBReal &color); void SetRadius(float32_t radius); void SetInnerConeAngle(float32_t angle); void SetOuterConeAngle(float32_t angle); Type GetType() const; rw::math::Vector3 GetPosition() const; rw::math::Vector3 GetDirection() const; const RwRGBReal &GetColor() const; float32_t GetRadius() const; float32_t GetInnerConeAngle() const; float32_t GetOuterConeAngle() const; static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks();
protected:
private:
    Light();
    Light(const Light &light);
    ~Light();
    rw::math::Vector3 m_position;
    rw::math::Vector3 m_direction;
    RwRGBReal m_color;
    Type m_type;
    float32_t m_radius;
    float32_t m_innerAngle;
    float32_t m_outerAngle;
};
inline void
Light::SetPosition(rw::math::Vector3::InParam pos)
{
    ;
    m_position = pos;
    return;
}
inline void
Light::SetDirection(rw::math::Vector3::InParam dir)
{
    ;
    m_direction = dir;
    return;
}
inline void
Light::SetColor(const RwRGBReal &color)
{
    ;
    m_color = color;
    return;
}
inline void
Light::SetRadius(float32_t radius)
{
    ;
    m_radius = radius;
    return;
}
inline void
Light::SetInnerConeAngle(float32_t angle)
{
    ;
    m_innerAngle = angle;
    return;
}
inline void
Light::SetOuterConeAngle(float32_t angle)
{
    ;
    m_outerAngle = angle;
    return;
}
inline Light::Type
Light::GetType() const
{
    ;
    return m_type;
}
inline rw::math::Vector3
Light::GetPosition() const
{
    ;
    return m_position;
}
inline rw::math::Vector3
Light::GetDirection() const
{
    ;
    return m_direction;
}
inline const RwRGBReal &
Light::GetColor() const
{
    ;
    return m_color;
}
inline float32_t
Light::GetRadius() const
{
    ;
    return m_radius;
}
inline float32_t
Light::GetInnerConeAngle() const
{
    ;
    return m_innerAngle;
}
inline float32_t
Light::GetOuterConeAngle() const
{
    ;
    return m_outerAngle;
}
}
}













namespace rw
{
namespace graphics
{
typedef uint32_t VertexIteratorType;




























}
}










namespace rw
{
namespace graphics
{
class VertexBuffer
{
public:
    static const uint32_t TYPE_STATIC = 2;
    static const uint32_t TYPE_DYNAMIC = 3;
    static const uint32_t TYPE_STATIC_READ = 4;
    static const uint32_t TYPE_PSGL_STREAM = 5;
    static const uint32_t TYPE_MASK = 7;
    static const uint32_t TYPE_NOLOCALBUFFER = 8;
    static const uint32_t TYPE_MAX = 9;
    enum Life
    {
        LIFE_NA = -1,
        LIFE_STATIC = TYPE_STATIC,
        LIFE_DYNAMIC = TYPE_DYNAMIC,
        LIFE_STATIC_READ = TYPE_STATIC_READ,
        LIFE_MASK = TYPE_MASK,
        LIFE_NOLOCALBUFFER = TYPE_NOLOCALBUFFER,
        LIFE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    struct Iterator
    {
        uint8_t *buffer;
        uint32_t stride;
        void
        Increment()
        {
            ;
            buffer += stride;
            return;
        }
    };
    typedef Iterator PSGLIterator;
public:
    class BatchIterator
    {
    public:
        friend class VertexBuffer;
        BatchIterator()
        {



        }
        BatchIterator(const BatchIterator &iterator)
        {
            *this = iterator;
        }






        void *
        GetLockedBuffer()
        {
            ;
            return reinterpret_cast<void *>(m_lockedBuffer);
        }
        void BeginBatch(uint32_t &numVertices, Iterator &vertexIterator);
        template <class VI> void BeginBatch(uint32_t &numVertices, VI &vertexIterator);
        RwBool
        EndBatch()
        {
            ;







            return (0);
        }
        void IteratorGoto(Iterator &iterator, uint32_t elementIndex);
        void PSGLIteratorGoto(Iterator &iterator, uint32_t elementIndex);
    private:
        void
        Initialize(void *lockedBuffer, VertexBuffer *vb)
        {
            ;
            m_lockedBuffer = static_cast<uint8_t *>(lockedBuffer);
            m_vb = vb;
            return;
        }
        uint8_t *m_lockedBuffer;
        VertexBuffer *m_vb;



    };
    static rw::ResourceDescriptor GetResourceDescriptor( const VertexDescriptor *desc, const uint32_t numVertices, const uint32_t type); static uint32_t GetAlignment(const VertexDescriptor *desc, const uint32_t numVertices, const uint32_t type); static uint32_t GetSize(const VertexDescriptor *desc, const uint32_t numVertices, const uint32_t type); static VertexBuffer *Initialize(void *ptr, const uint32_t size, const VertexDescriptor *desc, const uint32_t numVertices, const uint32_t type); static VertexBuffer *Initialize(const rw::Resource &resource, const VertexDescriptor *desc, const uint32_t numVertices, const uint32_t type); void Release(); VertexBuffer *Lock(const uint32_t flags, BatchIterator &batchIterator, VertexIteratorType &vertexType, uint32_t minVertex = 0, uint32_t numVertices = 0); VertexBuffer *Unlock(); const uint32_t GetNumVertices() const; inline const VertexDescriptor *GetVertexDescriptor() const; static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void Destruct(void *ptr); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); static const uint32_t GetMaxVertices();
    void PSGLSetDescriptor(const VertexDescriptor *desc);
    const VertexDescriptor *PSGLGetDescriptor() const
    {
        ;
        ;
        return m_desc;
    }
    uint32_t PSGLGetName() const;
    void PSGLDispatch(const uint32_t minVertex, const uint32_t numVertices) const;
    void PSGLUploadVertices(const void *data, uint32_t minVertex, uint32_t numVertices);

    uint8_t *PSGLGetDispatchBasePointer() const;


    VertexBuffer *PSGLVBOLock(uint32_t lockFlags, BatchIterator &batchIterator);
    void PSGLVBOUnlock();
    void *PSGLRawLock(uint32_t lockFlags);
    void PSGLRawUnlock();

protected:
private:
    const VertexDescriptor* m_desc;
    uint32_t m_numVertices;
    uint32_t m_type;
    uint32_t m_name;
    uint32_t m_lockFlags;
    uint32_t m_minLockedVertex;
    uint32_t m_numLockedVertices;
    void* m_mem;
    void* m_localBuffer;




    void PSGLGenerateName();
    void PSGLUploadData(const void *vertexData, uint32_t minVertex, uint32_t numVertices);

    void *PSGLGetVertexData() const;
    VertexBuffer();
    VertexBuffer(const VertexBuffer &vertexBuffer);
    ~VertexBuffer();
};
inline const VertexDescriptor *
VertexBuffer::GetVertexDescriptor() const
{
    ;
    return m_desc;
}
inline const uint32_t
VertexBuffer::GetNumVertices() const
{
    ;
    return m_numVertices;
}
inline void
VertexBuffer::PSGLSetDescriptor(const VertexDescriptor *desc)
{
    ;
    m_desc = desc;
    return;
}
inline uint32_t
VertexBuffer::PSGLGetName() const
{
    ;
    return m_name;
}
inline void
VertexBuffer::PSGLUploadVertices(const void *data, uint32_t minVertex,
                               uint32_t numVertices)
{
    ;
    m_numVertices = numVertices;

    PSGLUploadData(data, minVertex, numVertices);

    return;
}

inline uint8_t *
VertexBuffer::PSGLGetDispatchBasePointer() const
{
    ;
    return 0;
}

inline void *
VertexBuffer::PSGLGetVertexData() const
{
    ;
    if (m_type & TYPE_NOLOCALBUFFER)
    {
        return 0;
    }
    else
    {
        return m_localBuffer;
    }
}
inline void
VertexBuffer::BatchIterator::BeginBatch(uint32_t &numVertices, Iterator &vertexIterator)
{
    ;
    numVertices = m_vb->GetNumVertices();
    const VertexDescriptor *vbDesc = m_vb->GetVertexDescriptor();
    ;
    if ((0) == vbDesc->PSGLIsInterleavedData())
    {
        ;
        vertexIterator.stride = vbDesc->GetElement(0)->stride;
    }
    else
    {
        vertexIterator.stride = vbDesc->PSGLGetStride();
    }
    vertexIterator.buffer = m_lockedBuffer;



    return;
}
template <class VI>
inline void
VertexBuffer::BatchIterator::BeginBatch(uint32_t &numVertices, VI &vertexIterator)
{
    ;
    numVertices = m_vb->GetNumVertices();
    vertexIterator.SetBuffer(m_lockedBuffer);







    return;
}
inline void
VertexBuffer::BatchIterator::IteratorGoto(Iterator &iterator, uint32_t elementIndex)
{
    ;



    const VertexDescriptor *vbdesc = m_vb->GetVertexDescriptor();
    ;
    ;

    const VertexDescriptor::Element *element = vbdesc->GetElement(elementIndex);
    ;
    iterator.buffer = m_lockedBuffer;
    if ((0) == vbdesc->PSGLIsInterleavedData())
    {
        iterator.stride = element->stride;
    }
    else
    {
        iterator.stride = vbdesc->PSGLGetStride();
    }
    iterator.buffer += element->offset;
    return;
}
inline void
VertexBuffer::BatchIterator::PSGLIteratorGoto(Iterator &iterator, uint32_t elementIndex)
{
    ;
    IteratorGoto(iterator, elementIndex);
    return;
}
}
}













namespace rw
{
namespace graphics
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
    template<class ST>
    inline void
    Write(const ST &val)
    {
        ;
        *reinterpret_cast<DT *>(m_dest) = val;
        m_dest = reinterpret_cast<void *>(reinterpret_cast<DT *>(m_dest) + 1);
        return;
    };
    template<class ST>
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
typedef VertexTypeFloat1 PSGLVertexTypeFloat1;
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
class VertexTypeFloat2
{
    uint8_t pad[8];
};
typedef VertexTypeFloat2 PSGLVertexTypeFloat2;
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
    float32_t *dest = reinterpret_cast<float32_t *>(m_dest);
    vec_stvewx(v, 0, dest);
    vec_stvewx(v, 0, dest + 1);
    m_dest = reinterpret_cast<void *>(dest + 2);
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
typedef VertexTypeFloat3 PSGLVertexTypeFloat3;
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
    float32_t *dest = reinterpret_cast<float32_t *>(m_dest);
    vec_stvewx(v, 0, dest);
    vec_stvewx(v, 0, dest + 1);
    vec_stvewx(v, 0, dest + 2);
    m_dest = reinterpret_cast<void *>(dest + 3);
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
typedef VertexTypeFloat4 PSGLVertexTypeFloat4;
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
typedef VertexTypeUByte1 PSGLVertexTypeUByte1;
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
typedef VertexTypeUByte2 PSGLVertexTypeUByte2;
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
typedef VertexTypeUByte3 PSGLVertexTypeUByte3;
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
typedef VertexTypeUByte4 PSGLVertexTypeUByte4;
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
class VertexTypePSGLColor
{
    uint8_t pad[4];
};
typedef VertexTypePSGLColor PSGLVertexTypePSGLColor;
template<> template<> inline void VertexIterator<VertexTypePSGLColor>::Write<rw::RGBA>(const rw::RGBA &rgba)
{
    ;

    asm("stw %0,0(%1)" : : "r" (rgba), "b" (m_dest));






    m_dest = reinterpret_cast<void *>( reinterpret_cast<uint8_t *>(m_dest) + 4 );
    return;
};
template<> template<> inline void VertexIterator<VertexTypePSGLColor>::Read<rw::RGBA>(rw::RGBA &rgba)
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









namespace rw
{
namespace graphics
{
template<class DT1, class DT2>
class VertexIterator2 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2> inline void Write(const ST1 &val1, const ST2 &val2)
    {
        ;
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
        return;
    }
    template<class ST1, class ST2> inline void Read(ST1 &val1, ST2 &val2)
    {
        ;
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2);
    };
};
template<class DT1, class DT2, class DT3>
class VertexIterator3 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3)
    {
        ;
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
        return;
    }
    template<class ST1, class ST2, class ST3>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3)
    {
        ;
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3);
    };
};
template<class DT1, class DT2, class DT3, class DT4>
class VertexIterator4 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4)
    {
        ;
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4)
    {
        ;
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4);
    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5>
class VertexIterator5 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                          const ST5 &val5)
    {
        ;
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
        ((VertexIterator<DT5> *)this)->Write<ST5>(val5);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5)
    {
        ;
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
        ((VertexIterator<DT5> *)this)->Read<ST5>(val5);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5);
    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6>
class VertexIterator6 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                          const ST5 &val5, const ST6 &val6)
    {
        ;
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
        ((VertexIterator<DT5> *)this)->Write<ST5>(val5);
        ((VertexIterator<DT6> *)this)->Write<ST6>(val6);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6)
    {
        ;
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
        ((VertexIterator<DT5> *)this)->Read<ST5>(val5);
        ((VertexIterator<DT6> *)this)->Read<ST6>(val6);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6);
    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7>
class VertexIterator7 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                        const ST5 &val5, const ST6 &val6, const ST7 &val7)
    {
        ;
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
        ((VertexIterator<DT5> *)this)->Write<ST5>(val5);
        ((VertexIterator<DT6> *)this)->Write<ST6>(val6);
        ((VertexIterator<DT7> *)this)->Write<ST7>(val7);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7)
    {
        ;
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
        ((VertexIterator<DT5> *)this)->Read<ST5>(val5);
        ((VertexIterator<DT6> *)this)->Read<ST6>(val6);
        ((VertexIterator<DT7> *)this)->Read<ST7>(val7);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7);
    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8>
class VertexIterator8 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                        const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8)
    {
        ;
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
        ((VertexIterator<DT5> *)this)->Write<ST5>(val5);
        ((VertexIterator<DT6> *)this)->Write<ST6>(val6);
        ((VertexIterator<DT7> *)this)->Write<ST7>(val7);
        ((VertexIterator<DT8> *)this)->Write<ST8>(val8);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8)
    {
        ;
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
        ((VertexIterator<DT5> *)this)->Read<ST5>(val5);
        ((VertexIterator<DT6> *)this)->Read<ST6>(val6);
        ((VertexIterator<DT7> *)this)->Read<ST7>(val7);
        ((VertexIterator<DT8> *)this)->Read<ST8>(val8);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8);
    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9>
class VertexIterator9 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                        const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                        const ST9 &val9)
    {
        ;
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
        ((VertexIterator<DT5> *)this)->Write<ST5>(val5);
        ((VertexIterator<DT6> *)this)->Write<ST6>(val6);
        ((VertexIterator<DT7> *)this)->Write<ST7>(val7);
        ((VertexIterator<DT8> *)this)->Write<ST8>(val8);
        ((VertexIterator<DT9> *)this)->Write<ST9>(val9);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8, ST9 &val9)
    {
        ;
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
        ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
        ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
        ((VertexIterator<DT5> *)this)->Read<ST5>(val5);
        ((VertexIterator<DT6> *)this)->Read<ST6>(val6);
        ((VertexIterator<DT7> *)this)->Read<ST7>(val7);
        ((VertexIterator<DT8> *)this)->Read<ST8>(val8);
        ((VertexIterator<DT9> *)this)->Read<ST9>(val9);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8) + sizeof(DT9);

    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10>
class VertexIterator10 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                        const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                        const ST9 &val9, const ST10 &val10)
    {
        ;
        ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10)
    {
        ;
        ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8) + sizeof(DT9) + sizeof(DT10);

    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11>
class VertexIterator11 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                        const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                        const ST9 &val9, const ST10 &val10, const ST11 &val11)
    {
        ;
        ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11)
    {
        ;
        ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8) + sizeof(DT9) + sizeof(DT10) + sizeof(DT11);

    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11, class DT12>
class VertexIterator12 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                        const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                        const ST9 &val9, const ST10 &val10, const ST11 &val11, const ST12 &val12)
    {
        ;
        ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
        ((VertexIterator<DT12> *)this)->Write<ST12>(val12);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11, ST12 &val12)
    {
        ;
        ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
        ((VertexIterator<DT12> *)this)->Read<ST12>(val12);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8) + sizeof(DT9) + sizeof(DT10) + sizeof(DT11) + sizeof(DT12);

    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11, class DT12, class DT13>
class VertexIterator13 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                        const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                        const ST9 &val9, const ST10 &val10, const ST11 &val11, const ST12 &val12,
                        const ST13 &val13)
    {
        ;
        ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
        ((VertexIterator<DT12> *)this)->Write<ST12>(val12);
        ((VertexIterator<DT13> *)this)->Write<ST13>(val13);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11, ST12 &val12, ST13 &val13)
    {
        ;
        ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
        ((VertexIterator<DT12> *)this)->Read<ST12>(val12);
        ((VertexIterator<DT13> *)this)->Read<ST13>(val13);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8) + sizeof(DT9) + sizeof(DT10) + sizeof(DT11) + sizeof(DT12) + sizeof(DT13);

    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11, class DT12, class DT13, class DT14>
class VertexIterator14 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                        const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                        const ST9 &val9, const ST10 &val10, const ST11 &val11, const ST12 &val12,
                        const ST13 &val13, const ST14 &val14)
    {
        ;
        ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
        ((VertexIterator<DT12> *)this)->Write<ST12>(val12);
        ((VertexIterator<DT13> *)this)->Write<ST13>(val13);
        ((VertexIterator<DT14> *)this)->Write<ST14>(val14);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11, ST12 &val12, ST13 &val13, ST14 &val14)
    {
        ;
        ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
        ((VertexIterator<DT12> *)this)->Read<ST12>(val12);
        ((VertexIterator<DT13> *)this)->Read<ST13>(val13);
        ((VertexIterator<DT14> *)this)->Read<ST14>(val14);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8) + sizeof(DT9) + sizeof(DT10) + sizeof(DT11) + sizeof(DT12) + sizeof(DT13) + sizeof(DT14);

    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11, class DT12, class DT13, class DT14, class DT15>
class VertexIterator15 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14, class ST15>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                        const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                        const ST9 &val9, const ST10 &val10, const ST11 &val11, const ST12 &val12,
                        const ST13 &val13, const ST14 &val14, const ST15 &val15)
    {
        ;
        ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
        ((VertexIterator<DT12> *)this)->Write<ST12>(val12);
        ((VertexIterator<DT13> *)this)->Write<ST13>(val13);
        ((VertexIterator<DT14> *)this)->Write<ST14>(val14);
        ((VertexIterator<DT15> *)this)->Write<ST15>(val15);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14, class ST15>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11, ST12 &val12, ST13 &val13, ST14 &val14, ST15 &val15)
    {
        ;
        ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
        ((VertexIterator<DT12> *)this)->Read<ST12>(val12);
        ((VertexIterator<DT13> *)this)->Read<ST13>(val13);
        ((VertexIterator<DT14> *)this)->Read<ST14>(val14);
        ((VertexIterator<DT15> *)this)->Read<ST15>(val15);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8) + sizeof(DT9) + sizeof(DT10) + sizeof(DT11) + sizeof(DT12) + sizeof(DT13) + sizeof(DT14) + sizeof(DT15);

    };
};
template<class DT1, class DT2, class DT3, class DT4, class DT5, class DT6, class DT7, class DT8,
         class DT9, class DT10, class DT11, class DT12, class DT13, class DT14, class DT15, class DT16>
class VertexIterator16 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14, class ST15, class ST16>
        inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4,
                        const ST5 &val5, const ST6 &val6, const ST7 &val7, const ST8 &val8,
                        const ST9 &val9, const ST10 &val10, const ST11 &val11, const ST12 &val12,
                        const ST13 &val13, const ST14 &val14, const ST15 &val15, const ST16 &val16)
    {
        ;
        ((VertexIterator <DT1> *)this)->Write <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Write <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Write <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Write <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Write <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Write <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Write <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Write <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Write <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Write<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Write<ST11>(val11);
        ((VertexIterator<DT12> *)this)->Write<ST12>(val12);
        ((VertexIterator<DT13> *)this)->Write<ST13>(val13);
        ((VertexIterator<DT14> *)this)->Write<ST14>(val14);
        ((VertexIterator<DT15> *)this)->Write<ST15>(val15);
        ((VertexIterator<DT16> *)this)->Write<ST16>(val16);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4, class ST5, class ST6, class ST7, class ST8,
            class ST9, class ST10, class ST11, class ST12, class ST13, class ST14, class ST15, class ST16>
        inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4, ST5 &val5, ST6 &val6, ST7 &val7, ST8 &val8,
                        ST9 &val9, ST10 &val10, ST11 &val11, ST12 &val12, ST13 &val13, ST14 &val14, ST15 &val15, ST16 &val16)
    {
        ;
        ((VertexIterator <DT1> *)this)->Read <ST1>( val1);
        ((VertexIterator <DT2> *)this)->Read <ST2>( val2);
        ((VertexIterator <DT3> *)this)->Read <ST3>( val3);
        ((VertexIterator <DT4> *)this)->Read <ST4>( val4);
        ((VertexIterator <DT5> *)this)->Read <ST5>( val5);
        ((VertexIterator <DT6> *)this)->Read <ST6>( val6);
        ((VertexIterator <DT7> *)this)->Read <ST7>( val7);
        ((VertexIterator <DT8> *)this)->Read <ST8>( val8);
        ((VertexIterator <DT9> *)this)->Read <ST9>( val9);
        ((VertexIterator<DT10> *)this)->Read<ST10>(val10);
        ((VertexIterator<DT11> *)this)->Read<ST11>(val11);
        ((VertexIterator<DT12> *)this)->Read<ST12>(val12);
        ((VertexIterator<DT13> *)this)->Read<ST13>(val13);
        ((VertexIterator<DT14> *)this)->Read<ST14>(val14);
        ((VertexIterator<DT15> *)this)->Read<ST15>(val15);
        ((VertexIterator<DT16> *)this)->Read<ST16>(val16);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return sizeof(DT1) + sizeof(DT2) + sizeof(DT3) + sizeof(DT4) + sizeof(DT5) + sizeof(DT6) + sizeof(DT7) + sizeof(DT8) + sizeof(DT9) + sizeof(DT10) + sizeof(DT11) + sizeof(DT12) + sizeof(DT13) + sizeof(DT14) + sizeof(DT15) + sizeof(DT16);

    };
};
template<uint32_t N0, class DT1, uint32_t N1>
class PartialVertexIterator1 : public VertexIteratorBaseClass
{
public:
    template<class ST1> inline void Write(const ST1 &val1)
    {
        ;
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N0);
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N1);
        return;
    }
    template<class ST1> inline void Read(ST1 &val1)
    {
        ;
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N0);
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N1);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return N0 + sizeof(DT1) + N1;
    };
};
template<uint32_t N0, class DT1, uint32_t N1, class DT2, uint32_t N2>
class PartialVertexIterator2 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2> inline void Write(const ST1 &val1, const ST2 &val2)
    {
        ;
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N0);
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N1);
        ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N2);
        return;
    }
    template<class ST1, class ST2> inline void Read(ST1 &val1, ST2 &val2)
    {
        ;
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N0);
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N1);
        ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N2);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return N0 + sizeof(DT1) + N1 + sizeof(DT2) + N2;
    };
};
template<uint32_t N0, class DT1, uint32_t N1, class DT2, uint32_t N2, class DT3, uint32_t N3>
class PartialVertexIterator3 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3>
    inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3)
    {
        ;
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N0);
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N1);
        ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N2);
        ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N3);
        return;
    }
    template<class ST1, class ST2, class ST3>
    inline void Read(ST1 &val1, ST2 &val2, ST3 &val3)
    {
        ;
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N0);
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N1);
        ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N2);
        ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N3);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return N0 + sizeof(DT1) + N1 + sizeof(DT2) + N2 + sizeof(DT3) + N3;
    };
};
template<uint32_t N0, class DT1, uint32_t N1, class DT2, uint32_t N2,
                      class DT3, uint32_t N3, class DT4, uint32_t N4>
class PartialVertexIterator4 : public VertexIteratorBaseClass
{
public:
    template<class ST1, class ST2, class ST3, class ST4>
    inline void Write(const ST1 &val1, const ST2 &val2, const ST3 &val3, const ST4 &val4)
    {
        ;
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N0);
        ((VertexIterator<DT1> *)this)->Write<ST1>(val1);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N1);
        ((VertexIterator<DT2> *)this)->Write<ST2>(val2);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N2);
        ((VertexIterator<DT3> *)this)->Write<ST3>(val3);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N3);
        ((VertexIterator<DT4> *)this)->Write<ST4>(val4);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N4);
        return;
    }
    template<class ST1, class ST2, class ST3, class ST4>
    inline void Read(ST1 &val1, ST2 &val2, ST3 &val3, ST4 &val4)
    {
        ;
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N0);
        ((VertexIterator<DT1> *)this)->Read<ST1>(val1);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N1);
        ((VertexIterator<DT2> *)this)->Read<ST2>(val2);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N2);
        ((VertexIterator<DT3> *)this)->Read<ST3>(val3);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N3);
        ((VertexIterator<DT4> *)this)->Read<ST4>(val4);
        m_dest = reinterpret_cast<void *>(reinterpret_cast<uint8_t *>(m_dest) + N4);
        return;
    }
    static inline uint32_t GetStride()
    {
        ;
        return N0 + sizeof(DT1) + N1 + sizeof(DT2) + N2 + sizeof(DT3) + N3 + sizeof(DT4) + N4;

    };
};
}
}









namespace rw
{
namespace graphics
{
typedef VertexIterator<PSGLVertexTypeFloat2> IM2DVertexIterator;
typedef VertexIterator2<PSGLVertexTypeFloat2,
                        PSGLVertexTypeUByte4> IM2DColorVertexIterator;
typedef VertexIterator2<PSGLVertexTypeFloat2,
                        PSGLVertexTypeFloat2> IM2DTextureVertexIterator;
typedef VertexIterator3<PSGLVertexTypeFloat2,
                        PSGLVertexTypeUByte4,
                        PSGLVertexTypeFloat2> IM2DColorTextureVertexIterator;
typedef VertexIterator<PSGLVertexTypeFloat3> IM3DVertexIterator;
typedef VertexIterator2<PSGLVertexTypeFloat3,
                        PSGLVertexTypeUByte4> IM3DColorVertexIterator;
typedef VertexIterator2<PSGLVertexTypeFloat3,
                        PSGLVertexTypeFloat2> IM3DTextureVertexIterator;
typedef VertexIterator3<PSGLVertexTypeFloat3,
                        PSGLVertexTypeUByte4,
                        PSGLVertexTypeFloat2> IM3DColorTextureVertexIterator;
}
}









namespace rw
{
namespace graphics
{
class Shader;
class ShaderManager
{
    public:
        static void Initialize();
        static void AddShader(uint32_t id, Shader *shader);
        static Shader *GetShader(uint32_t id);
        static void RemoveShader(uint32_t id);
        static uint32_t GetNumShaders();
        static void Release();
    private:
        static uint32_t m_numShaders;
        static Shader *m_lastRequestedShader;
        static Shader *m_shaders[];
};
inline uint32_t
ShaderManager::GetNumShaders()
{
    ;
    return m_numShaders;
}
}
}









namespace rw
{
namespace graphics
{












}
}








namespace rw
{
namespace graphics
{
class IndexDescriptor
{
public:
    static rw::ResourceDescriptor GetResourceDescriptor(); static uint32_t GetAlignment(); static uint32_t GetSize(); static IndexDescriptor *Initialize(const rw::Resource &resource); static IndexDescriptor *Initialize(void *ptr, uint32_t size); void Release(); IndexDescriptor *Lock(const uint32_t flags); IndexDescriptor *Unlock(); static const IndexDescriptor *GetDefault(const uint32_t depth); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks();
    static const IndexDescriptor *PSGLGetDefault(uint32_t indexSize);
    uint32_t PSGLGetIndexSize() const;
protected:
private:
    static const IndexDescriptor m_PSGLDefault[2];
    uint32_t m_indexSize;
    IndexDescriptor(uint32_t indexSize)
        : m_indexSize(indexSize)
    {
        ;
    }
    IndexDescriptor(const IndexDescriptor &indexDescriptor)
        : m_indexSize(indexDescriptor.m_indexSize)
    {
        ;
    }
    ~IndexDescriptor()
    {
        ;
    }
};
inline const IndexDescriptor *
IndexDescriptor::GetDefault(const uint32_t indexSize)
{
    ;
    ;
    if (16 == indexSize)
    {
        return &(m_PSGLDefault[0]);
    }
    else
    {
        return &(m_PSGLDefault[1]);
    }
}
inline const IndexDescriptor *
IndexDescriptor::PSGLGetDefault(uint32_t indexSize)
{
    ;
    ;
    return GetDefault(indexSize);
}
inline uint32_t
IndexDescriptor::PSGLGetIndexSize() const
{
    ;
    return m_indexSize;
}
}
}













namespace rw
{
namespace graphics
{







































}
}










namespace rw
{
namespace graphics
{
class IndexBuffer
{
public:
    static const uint32_t TYPE_STATIC = 1;
    static const uint32_t TYPE_DYNAMIC = 2;
    static const uint32_t TYPE_READ = 4;
    static const uint32_t TYPE_PSGL_STREAM = 5;
    static const uint32_t TYPE_MASK = 7;
    enum Flags
    {
        FLAGS_NA = 0,
        FLAGS_STATIC = 1,
        FLAGS_DYNAMIC = 2,
        FLAGS_STATIC_READ = 4,
        FLAGS_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    struct Locked
    {
        IndexBuffer *lockedIndexBuffer;
        void *indices;
        uint32_t lockFlags;
    };
    static rw::ResourceDescriptor GetResourceDescriptor( const IndexDescriptor *iDes, uint32_t numPrims, uint32_t numIndices, uint32_t flags, PrimitiveType primType); static uint32_t GetAlignment( const IndexDescriptor *iDes, uint32_t numPrims, uint32_t numIndices, uint32_t flags); static uint32_t GetSize( const IndexDescriptor *iDes, uint32_t numPrims, uint32_t numIndices, uint32_t flags); static IndexBuffer *Initialize( void *ptr, uint32_t size, const IndexDescriptor *iDes, uint32_t numPrims, uint32_t numIndices, uint32_t flags, PrimitiveType primType); static IndexBuffer *Initialize( const rw::Resource &resource, const IndexDescriptor *iDes, uint32_t numPrims, uint32_t numIndices, uint32_t flags, PrimitiveType primType); void Release(); IndexBuffer *Lock(const uint32_t flags, Locked &lockedIndexBuffer); IndexBuffer *Unlock(Locked &lockedIndexBuffer); uint32_t GetNumIndices() const; uint32_t GetDepth() const; static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void Destruct(void *ptr); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks();;
    void ComputeMinAndMaxVertex(const uint32_t start, const uint32_t numIndices, uint32_t &minVertex, uint32_t &maxVertex);;
    uint32_t PSGLGetName() const;
    PrimitiveType PSGLGetPrimitiveType() const;
    uint32_t PSGLGetNumIndices() const;
    uint32_t PSGLGetMinVertexIndex() const;
    uint32_t PSGLGetMaxVertexIndex() const;
    uint16_t PSGLGetIndexStride() const;
    uint16_t PSGLGetIndexType() const;
    void *PSGLGetIndexData() const;
    void PSGLComputeMinAndMaxVertex(const uint32_t start,
                                     const uint32_t numIndices,
                                     uint32_t &minVertex,
                                     uint32_t &maxVertex);
protected:
private:
    uint32_t m_name;
    uint32_t m_numIndices;
    PrimitiveType m_primType;
    uint32_t m_type;
    void* m_localBuffer;
    uint32_t m_minVertexIndex;
    uint32_t m_maxVertexIndex;
    uint16_t m_indexStride;
    uint16_t m_indexType;

    void PSGLGenerateName();
    void PSGLUploadData(const void *indexData);

    IndexBuffer();
    IndexBuffer(const IndexBuffer &indexBuffer);
    ~IndexBuffer();
};
inline uint32_t
IndexBuffer::PSGLGetName() const
{
    ;
    return m_name;
}
inline PrimitiveType
IndexBuffer::PSGLGetPrimitiveType() const
{
    ;
    return m_primType;
}
inline uint32_t
IndexBuffer::GetNumIndices() const
{
    ;
    return m_numIndices;
}
inline uint32_t
IndexBuffer::PSGLGetNumIndices() const
{
    ;
 ;
    return GetNumIndices();
}
inline uint32_t
IndexBuffer::GetDepth() const
{
    ;
    return m_indexStride * 8;
}
inline uint32_t
IndexBuffer::PSGLGetMinVertexIndex() const
{
    ;
    return m_minVertexIndex;
}
inline uint32_t
IndexBuffer::PSGLGetMaxVertexIndex() const
{
    ;
    return m_maxVertexIndex;
}
inline uint16_t
IndexBuffer::PSGLGetIndexStride() const
{
    ;
 ;
    return m_indexStride;
}
inline uint16_t
IndexBuffer::PSGLGetIndexType() const
{
    ;
    return m_indexType;
}
inline void *
IndexBuffer::PSGLGetIndexData() const
{
    ;
    return m_localBuffer;
}
}
}













namespace rw
{
namespace graphics
{








































}
}





namespace rw
{
namespace graphics
{
class EmbeddedMesh
{
public:
    RwBool SetVertexBuffer(const uint32_t vertexBufferIndex, VertexBuffer *vertexBuffer); RwBool SetVertexBuffer(VertexBuffer *vertexBuffer, const uint32_t vertexBufferIndex); VertexBuffer *GetVertexBuffer(const uint32_t vertexBufferIndex) const; const uint32_t GetNumVertexBuffers() const;;
    void SetIndexBuffer(IndexBuffer *indexBuffer); IndexBuffer *GetIndexBuffer() const;;
    uint32_t GetNumVertexElements() const; const uint32_t GetInstanceSize() const; static RwBool AreEqual(const EmbeddedMesh *mesh0, const EmbeddedMesh *mesh1);;
    void SetMinAndMaxVertexIndex(const uint32_t minVertexIndex, const uint32_t maxVertexIndex); uint32_t GetMinVertexIndex() const; uint32_t GetMaxVertexIndex() const;;
    uint32_t PSGLGetInstanceSize() const;
    static RwBool PSGLAreEqual(const EmbeddedMesh *mesh0,
                             const EmbeddedMesh *mesh1);
    void SetStart(const uint32_t start);
    uint32_t GetStart() const;
    void SetNumIndices(const uint32_t numIndices);
    uint32_t GetNumIndices() const;
    void PSGLSetMinVertexIndex(const uint32_t minVertex);
    uint32_t PSGLGetMinVertexIndex() const;
    void PSGLSetMaxVertexIndex(const uint32_t maxVertex);
    uint32_t PSGLGetMaxVertexIndex() const;
    void SetMinVertexIndex(const uint32_t minVertex);
    void SetMaxVertexIndex(const uint32_t maxVertex);
protected:
    typedef VertexBuffer* VertexBufferPtr; typedef const VertexBuffer* VertexBufferConstPtr;
    typedef IndexBuffer* IndexBufferPtr; typedef const IndexBuffer* IndexBufferConstPtr;
    uint32_t m_numVertexBuffers;
    uint32_t m_instanceSize;
    uint32_t m_start;
    uint32_t m_numIndices;
    uint32_t m_minVertexIndex;
    uint32_t m_maxVertexIndex;
    IndexBufferPtr m_indexBuffer;
    VertexBufferPtr m_vertexBuffer[1];
    EmbeddedMesh();
    EmbeddedMesh(const EmbeddedMesh &embeddedMesh);
    ~EmbeddedMesh();
private:
};
class Mesh : public EmbeddedMesh
{
public:
    static rw::ResourceDescriptor GetResourceDescriptor(const uint32_t numVertexBuffers); static uint32_t GetAlignment(const uint32_t numVertexBuffers); static uint32_t GetSize(const uint32_t numVertexBuffers); static Mesh *Initialize(void *ptr, const uint32_t size, const uint32_t numVertexBuffers); static Mesh *Initialize(const rw::Resource &resource, const uint32_t numVertexBuffers);
    void Release(); rw::ResourceDescriptor GetInstanceResourceDescriptor() const; const uint32_t GetInstanceAlignment() const; Mesh *Clone(void *ptr) const; Mesh *Clone(const rw::Resource &resource) const; void Dispatch() const; static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void Destruct(void *ptr); static void RegisterArenaReadCallbacks(void); static void RegisterArenaWriteCallbacks(void);
    void DispatchNoSync() const; void DispatchAgainNoSync() const;;
    void DispatchAgain() const;;
    void PSGLDispatch(RwBool syncToGlobal) const;
    void PSGLDispatchAgain(RwBool syncToGlobal) const;
    uint32_t PSGLGetNumTotalVertexElements() const;
protected:
private:
    Mesh();
    Mesh(const Mesh &mesh);
    ~Mesh();
};
inline const uint32_t
EmbeddedMesh::GetInstanceSize() const
{
    ;
    return m_instanceSize;
}
inline uint32_t
EmbeddedMesh::PSGLGetInstanceSize() const
{
    ;
    return m_instanceSize;
}
inline void
EmbeddedMesh::SetStart(const uint32_t start)
{
    ;
    m_start = start;
    return;
}
inline uint32_t
EmbeddedMesh::GetStart() const
{
    ;
    return m_start;
}
inline void
EmbeddedMesh::SetNumIndices(const uint32_t numIndices)
{
    ;
    m_numIndices = numIndices;
    return;
}
inline uint32_t
EmbeddedMesh::GetNumIndices() const
{
    ;
    return m_numIndices;
}
inline void
EmbeddedMesh::SetMinAndMaxVertexIndex(const uint32_t minVertex, const uint32_t maxVertex)
{
    ;
    m_minVertexIndex = minVertex;
    m_maxVertexIndex = maxVertex;
    return;
}
inline void
EmbeddedMesh::PSGLSetMinVertexIndex(const uint32_t minVertex)
{
    ;
    ;
    m_minVertexIndex = minVertex;
    return;
}
inline uint32_t
EmbeddedMesh::GetMinVertexIndex() const
{
    ;
    return m_minVertexIndex;
}
inline uint32_t
EmbeddedMesh::PSGLGetMinVertexIndex() const
{
    ;
    ;
    return m_minVertexIndex;
}
inline void
EmbeddedMesh::PSGLSetMaxVertexIndex(const uint32_t maxVertex)
{
    ;
    ;
    m_maxVertexIndex = maxVertex;
    return;
}
inline uint32_t
EmbeddedMesh::GetMaxVertexIndex() const
{
    ;
    return m_maxVertexIndex;
}
inline uint32_t
EmbeddedMesh::PSGLGetMaxVertexIndex() const
{
    ;
    ;
    return m_maxVertexIndex;
}
inline void
Mesh::Dispatch() const
{
    ;
    PSGLDispatch((1));
    return;
}
inline void
Mesh::DispatchNoSync() const
{
    ;
    PSGLDispatch((0));
    return;
}
inline void
Mesh::DispatchAgain() const
{
    ;
    PSGLDispatchAgain((1));
    return;
}
inline void
Mesh::DispatchAgainNoSync() const
{
    ;
    PSGLDispatchAgain((0));
    return;
}
inline void
EmbeddedMesh::SetMinVertexIndex(const uint32_t minVertex)
{
    ;
    ;
    PSGLSetMinVertexIndex(minVertex);
    return;
}
inline void
EmbeddedMesh::SetMaxVertexIndex(const uint32_t maxVertex)
{
    ;
    ;
    PSGLSetMaxVertexIndex(maxVertex);
    return;
}
}
}













namespace rw
{
namespace graphics
{











































}
}





namespace rw
{
namespace graphics
{
class SamplerStateBitField
{
public:
    typedef uint64_t WordType;
    SamplerStateBitField();
    ~SamplerStateBitField();
    SamplerStateBitField(const SamplerStateBitField &source);
    SamplerStateBitField(const uint64_t &source);
    static void EndianSwap(SamplerStateBitField &bitField);
    uint32_t GetSize() const;
    RwBool operator[](uint32_t i) const;
    void operator&=(const SamplerStateBitField &operand);
    uint32_t operator&(const uint32_t &operand) const;
    void operator|=(const SamplerStateBitField &operand);
    void operator|=(const uint32_t &operand);
    void operator>>=(uint32_t shift);
    void operator<<=(uint32_t shift);
    SamplerStateBitField operator>>(uint32_t shift) const;
    SamplerStateBitField operator<<(uint32_t shift) const;
    RwBool operator!=(const SamplerStateBitField &operand) const;
    SamplerStateBitField operator~() const;
    void Set(uint32_t i);
    void Unset(uint32_t i);
    void SetAll();
    void UnsetAll();
    RwBool AnySet() const;
protected:
    enum Constants
    {
        SIZE_IN_BITS = (TEXTUREDATA_NUMBITS * (16)),
        BITS_PER_WORD = 8 * sizeof(WordType),
        WORD_SHIFT = 6,
        SIZE_IN_WORDS = ((SIZE_IN_BITS + (BITS_PER_WORD - 1)) >> WORD_SHIFT)
    };
private:
    WordType m_data[SIZE_IN_WORDS];
};
inline void
SamplerStateBitField::UnsetAll()
{
    ;
    WordType *pos = m_data, *last = m_data + SIZE_IN_WORDS;
    while (pos != last)
    {
        *pos++ = SamplerStateBitField::WordType(0);
    }
    return;
}
inline
SamplerStateBitField::SamplerStateBitField()
{
    ;
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(SamplerStateBitField::WordType) <= 8) != 0) > ERROR_SamplerStateBitField_assumes_at_most_64_bits_per_WordType; ; (void)ERROR_SamplerStateBitField_assumes_at_most_64_bits_per_WordType) break;

    UnsetAll();
    return;
}
inline
SamplerStateBitField::~SamplerStateBitField()
{
    ;
    return;
}
inline
SamplerStateBitField::SamplerStateBitField(const SamplerStateBitField &source)
{
    ;
    for (uint32_t i = 0; i < SIZE_IN_WORDS; i++)
    {
        m_data[i] = source.m_data[i];
    }
    return;
}
inline
SamplerStateBitField::SamplerStateBitField(const uint64_t &source)
{
    ;
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(SamplerStateBitField::WordType) <= 8) != 0) > ERROR_SamplerStateBitField_assumes_at_most_64_bits_per_WordType; ; (void)ERROR_SamplerStateBitField_assumes_at_most_64_bits_per_WordType) break;

    UnsetAll();
    m_data[0] = source;
    return;
}
inline void
SamplerStateBitField::EndianSwap(SamplerStateBitField &bitField)
{
    ;
    for (uint32_t i = 0; i < SIZE_IN_WORDS; i++)
    {
        rw::EndianSwap(bitField.m_data[i]);
    }
    return;
}
inline uint32_t
SamplerStateBitField::GetSize() const
{
    ;
    return SIZE_IN_BITS;
}
inline RwBool
SamplerStateBitField::operator[](uint32_t index) const
{
    ;
    ;
    return ((m_data[index >> WORD_SHIFT] >> (index & (BITS_PER_WORD - 1))) & 1) != (WordType)0;
}
inline SamplerStateBitField
SamplerStateBitField::operator~() const
{
    ;
    SamplerStateBitField temp(*this);
    for (uint32_t i = 0; i < SIZE_IN_WORDS; i++)
    {
        temp.m_data[i] = ~(temp.m_data[i]);
    }
    return temp;
}
inline void
SamplerStateBitField::operator&=(const SamplerStateBitField &operand)
{
    ;
    for (uint32_t i = 0; i < SIZE_IN_WORDS; i++)
    {
        m_data[i] &= operand.m_data[i];
    }
    return;
}
inline uint32_t
SamplerStateBitField::operator&(const uint32_t &operand) const
{
    ;
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(SamplerStateBitField::WordType) >= 4) != 0) > ERROR_SamplerStateBitField_assumes_at_least_32_bits_per_WordType; ; (void)ERROR_SamplerStateBitField_assumes_at_least_32_bits_per_WordType) break;

    return (uint32_t)m_data[0] & operand;
}
inline void
SamplerStateBitField::operator|=(const SamplerStateBitField &operand)
{
    ;
    for (uint32_t i = 0; i < SIZE_IN_WORDS; i++)
    {
        m_data[i] |= operand.m_data[i];
    }
    return;
}
inline void
SamplerStateBitField::operator|=(const uint32_t &operand)
{
    ;
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(SamplerStateBitField::WordType) >= 4) != 0) > ERROR_SamplerStateBitField_assumes_at_least_32_bits_per_WordType; ; (void)ERROR_SamplerStateBitField_assumes_at_least_32_bits_per_WordType) break;

    m_data[0] |= operand;
    return;
}
inline void
SamplerStateBitField::operator>>=(uint32_t shift)
{
    ;
    uint32_t i;
    if (shift==0)
    {
        return;
    }
    if (shift < BITS_PER_WORD)
    {
        for(i = 0; i < SIZE_IN_WORDS - 1; i++)
        {
            m_data[i] >>= shift;
            m_data[i] |= (m_data[i+1] << (BITS_PER_WORD - shift));
        }
        m_data[i] >>= shift;
    }
    else
    {
        for (i = 0; i < (SIZE_IN_BITS - shift); i++)
        {
            if( m_data[(i + shift) >> WORD_SHIFT] & (1 << ((i + shift) & (BITS_PER_WORD - 1))) )
            {
                m_data[i >> WORD_SHIFT] |= ((WordType)1 << (i & (BITS_PER_WORD - 1)));
            }
            else
            {
                m_data[i >> WORD_SHIFT] &= ~((WordType)1 << (i & (BITS_PER_WORD - 1)));
            }
        }
        for (i = (SIZE_IN_BITS - shift); i < SIZE_IN_BITS; i++)
        {
            m_data[i >> WORD_SHIFT] &= ~((WordType)1 << (i & (BITS_PER_WORD - 1)));
        }
    }
    return;
}
inline void
SamplerStateBitField::operator<<=(uint32_t shift)
{
    ;
    int32_t i;
    if (shift == 0)
    {
        return;
    }
    if (shift < BITS_PER_WORD)
    {
        for(i = SIZE_IN_WORDS - 1; i > 0; i--)
        {
            m_data[i] <<= shift;
            m_data[i] |= (m_data[i-1] >> (BITS_PER_WORD - shift));
        }
        m_data[0] <<= shift;
    }
    else
    {
        for (i = (SIZE_IN_BITS - 1); i >= (int32_t)shift; i--)
        {
            if( m_data[(i - shift) >> WORD_SHIFT] & (1 << ((i - shift) & (BITS_PER_WORD - 1))) )
            {
                m_data[i >> WORD_SHIFT] |= ((WordType)1 << (i & (BITS_PER_WORD - 1)));
            }
            else
            {
                m_data[i >> WORD_SHIFT] &= ~((WordType)1 << (i & (BITS_PER_WORD - 1)));
            }
        }
        for (i = shift - 1; i >= 0; i--)
        {
            m_data[i >> WORD_SHIFT] &= ~((WordType)1 << (i & (BITS_PER_WORD - 1)));
        }
    }
    return;
}
inline SamplerStateBitField
SamplerStateBitField::operator>>(uint32_t shift) const
{
    ;
    SamplerStateBitField temp(*this);
    temp >>= shift;
    return temp;
}
inline SamplerStateBitField
SamplerStateBitField::operator<<(uint32_t shift) const
{
    ;
    SamplerStateBitField temp(*this);
    temp <<= shift;
    return temp;
}
inline RwBool
SamplerStateBitField::operator!=(const SamplerStateBitField &operand) const
{
    ;
    RwBool result = (0);
    for (uint32_t i = 0; i < SIZE_IN_WORDS; i++)
    {
        if (m_data[i] != operand.m_data[i])
        {
            result = (1);
            break;
        }
    }
    return result;
}
inline void
SamplerStateBitField::Set(uint32_t index)
{
    ;
    ;
    m_data[index >> WORD_SHIFT] |= (1 << (index & (BITS_PER_WORD - 1)));
    return;
}
inline void
SamplerStateBitField::Unset(uint32_t index)
{
    ;
    ;
    m_data[index >> WORD_SHIFT] &= ~(1 << (index & (BITS_PER_WORD - 1)));
    return;
}
inline void
SamplerStateBitField::SetAll()
{
    ;
    WordType *pos = m_data, *last = m_data + SIZE_IN_WORDS;
    while (pos != last)
    {
        *pos++ = ~SamplerStateBitField::WordType(0);
    }
    return;
}
inline RwBool
SamplerStateBitField::AnySet() const
{
    ;
    RwBool result = (0);
    for (uint32_t i = 0; i < SIZE_IN_WORDS; i++)
    {
        if (m_data[i] != (WordType)0)
        {
            result = (1);
            break;
        }
    }
    return result;
}
class BuildState
{
public:
    struct TextureData
    {
        Raster *m_raster;
        Raster::Filter m_minFilter;
        Raster::Filter m_magFilter;
        Raster::Addressing m_addressU;
        Raster::Addressing m_addressV;
    };
    struct PSGLShaderDataInfo
    {
        uint32_t id;
        const void *buffer;
        Behaviour behaviour;
        Shader::DataType type;
        uint16_t size;
        uint16_t alignment;
    };
    static rw::ResourceDescriptor GetResourceDescriptor(uint32_t shaderID, uint32_t numShaderData = 0); static BuildState *Initialize(const rw::Resource &resource, uint32_t shaderID, uint32_t numShaderData = 0, IResourceAllocator& allocator = GetDefaultAllocator()); void Release(); void SetMaterialColor(const RwRGBAReal &color, Behaviour behaviour = BEHAVIOUR_STATIC); const RwRGBAReal GetMaterialColor() const; RwBool HasMaterialColor() const; void SetTransform(const rw::math::Matrix44Affine &matrix, const rw::math::MatrixType matrixType, Behaviour behaviour = BEHAVIOUR_STATIC); rw::math::Matrix44Affine GetTransform() const; RwBool HasTransform() const; void SetPrimitiveType(PrimitiveType primType, Behaviour behaviour = BEHAVIOUR_STATIC); PrimitiveType GetPrimitiveType() const; RwBool HasPrimitiveType() const; void SetVertexDescriptor(const VertexDescriptor *vdesc, Behaviour behaviour = BEHAVIOUR_STATIC); const VertexDescriptor *GetVertexDescriptor() const; RwBool HasVertexDescriptor() const; void SetDeviceState(Device::StateID state, Device::StateValue value, Behaviour behaviour = BEHAVIOUR_STATIC); Device::StateValue GetDeviceState(Device::StateID state) const; RwBool HasDeviceState(Device::StateID state) const; void SetShaderState(Shader::StateID state, const void *value, uint32_t size, uint32_t alignment, Shader::DataType dataType, Behaviour behaviour = BEHAVIOUR_STATIC); void GetShaderState(Shader::StateID state, void *value, uint32_t size) const; RwBool HasShaderState(Shader::StateID state) const; void SetRaster(uint32_t rasterIndex, const Raster *raster, Behaviour behaviour = BEHAVIOUR_STATIC); const Raster *GetRaster(uint32_t rasterIndex) const; RwBool HasRaster(uint32_t rasterIndex) const; void SetRasterState(uint32_t rasterIndex, Raster::StateID state, Raster::StateValue value, Behaviour behaviour = BEHAVIOUR_STATIC); Raster::StateValue GetRasterState(uint32_t rasterIndex, Raster::StateID state) const; RwBool HasRasterState(uint32_t rasterIndex, Raster::StateID state) const;
    void PSGLCopy(const BuildState *sourceBS);
    void PSGLAdd(const BuildState *sourceBS);
    void PSGLSubtract(const BuildState *sourceBS);
    void PSGLSetTransform(const rw::math::Matrix44Affine *matrix,
                          rw::math::MatrixType matrixType,
                          Behaviour behaviour = BEHAVIOUR_STATIC);
    const rw::math::Matrix44Affine *PSGLGetTransform() const;
    rw::math::MatrixType PSGLGetTransformType() const;
    void PSGLClearTransform();
    uint32_t PSGLGetShaderID() const;
    uint32_t PSGLGetCoreState() const;
    Behaviour PSGLGetCoreStateBehaviour(PSGLCoreState coreState) const;
    uint32_t PSGLGetStaticCoreState() const;
    void PSGLSetMaterialColor(const RwRGBAReal *color, Behaviour behaviour = BEHAVIOUR_STATIC);
    const RwRGBAReal *PSGLGetMaterialColor() const;
    void PSGLClearMaterialColor();
    void PSGLSetRaster(uint32_t unit, Raster *raster, Behaviour behaviour = BEHAVIOUR_STATIC);
    const Raster *PSGLGetRaster(uint32_t stage) const;
    void PSGLClearRaster(uint32_t unit);
    RwBool PSGLHasRaster(uint32_t stage) const;
    void PSGLSetRasterMinFilter(uint32_t unit, Raster::Filter filter, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLClearRasterMinFilter(uint32_t unit);
    void PSGLSetRasterMagFilter(uint32_t unit, Raster::Filter filter, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLClearRasterMagFilter(uint32_t unit);
    void PSGLSetRasterFilter(uint32_t unit, Raster::Filter filter, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLClearRasterFilter(uint32_t unit);
    void PSGLSetRasterAddressingU(uint32_t unit, Raster::Addressing addressing,
                                Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLClearRasterAddressingU(uint32_t unit);
    void PSGLSetRasterAddressingV(uint32_t unit, Raster::Addressing addressing,
                                Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLClearRasterAddressingV(uint32_t unit);
    const SamplerStateBitField &PSGLGetTextureStates() const;
    uint32_t PSGLGetTextureUnits() const;
    const TextureData *PSGLGetTextureData() const;
    SamplerStateBitField &PSGLGetStaticTextureStates(SamplerStateBitField &staticStates) const;
    void PSGLSetShaderData(uint32_t dataID, const void *shaderData, uint32_t size, uint32_t alignment,
                         Shader::DataType dataType, Behaviour behaviour = BEHAVIOUR_STATIC);
    const void *PSGLGetShaderData(uint32_t dataID) const;
    const PSGLShaderDataInfo *PSGLGetShaderDataInfo(uint32_t shaderDataType) const;
    void RemapShaderDataIDs(ShaderStateRemapIDCallback remapCallback);
    void PSGLSetBooleanStates(uint32_t states, uint32_t values);
    void PSGLEnableState(Device::StateID stateId, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLDisableState(Device::StateID stateId, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetAlphaFunction(AlphaTestFunction alphaFunc, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetAlphaReference(float32_t alphaReference, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetSourceBlendFactor(PSGLBlendFactor sFactor, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetDestinationBlendFactor(PSGLBlendFactor dFactor, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetCullFace(CullMode cullFace, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetDepthMask(RwBool depthMask, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetColorMask(RwBool colorMask, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetDepthTestFunction(PSGLDepthTestFunction depthFunc, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetStencilFunction(PSGLStencilFunc func, int32_t ref, uint32_t mask,
        Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetStencilWriteMask(uint32_t writeMask, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetStencilOps(PSGLStencilOp fail, PSGLStencilOp zFail, PSGLStencilOp zPass,
        Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetLineWidth(float32_t lineWidth, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetPointSize(float32_t pointSize, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetColorLogicOp(PSGLColorLogicOp logicOp, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetPolygonMode(PSGLPolygonMode polyMode, Behaviour behaviour = BEHAVIOUR_STATIC);
    void PSGLSetSampleCoverage(float32_t coverage, RwBool inverted,
        Behaviour behaviour = BEHAVIOUR_STATIC);
    AlphaTestFunction PSGLGetAlphaFunction() const;
    float32_t PSGLGetAlphaReference() const;
    PSGLBlendFactor PSGLGetSourceBlendFactor() const;
    PSGLBlendFactor PSGLGetDestinationBlendFactor() const;
    CullMode PSGLGetCullFace() const;
    RwBool PSGLGetDepthMask() const;
    RwBool PSGLGetColorMask() const;
    PSGLDepthTestFunction PSGLGetDepthTestFunction() const;
    void PSGLGetStencilFunction(PSGLStencilFunc &func, int32_t &ref, uint32_t &mask) const;
    uint32_t PSGLGetStencilWriteMask() const;
    void PSGLGetStencilOps(PSGLStencilOp &fail, PSGLStencilOp &zFail, PSGLStencilOp &zPass) const;
    float32_t PSGLGetLineWidth() const;
    float32_t PSGLGetPointSize() const;
    PSGLColorLogicOp PSGLGetColorLogicOp() const;
    PSGLPolygonMode PSGLGetPolygonMode() const;
    void PSGLGetSampleCoverage(float32_t &coverage, RwBool &inverted) const;
    void SetBlendMode(BlendMode blend);
    void SetCullMode(CullMode cullMode);
    void SetAlphaTestFunction(AlphaTestFunction alphaTestFunction);
    void SetAlphaTestReference(AlphaTestReference alphaTestReference);
    uint32_t PSGLGetDeviceStates() const;
    uint32_t PSGLGetBooleanValues() const;
    void PSGLSetPrimitiveType(PrimitiveType primType,
                            Behaviour behaviour = BEHAVIOUR_STATIC);
    PrimitiveType PSGLGetPrimitiveType() const;
    void PSGLSetVertexDescriptor(const VertexDescriptor *vdesc,
                               Behaviour behaviour = BEHAVIOUR_STATIC);
    const VertexDescriptor *PSGLGetVertexDescriptor() const;
    void PSGLClearVertexDescriptor();
    static VertexDescriptor *PSGLCreateVertexDescriptorFromMesh(const Mesh *mesh);
    void PSGLSetAmbient(const RwRGBReal &ambient, Behaviour behaviour = BEHAVIOUR_STATIC);
    const RwRGBReal &PSGLGetAmbient() const;
    void PSGLClearAmbient();
private:
    void PSGLUpdateCoreStateBehaviour(PSGLCoreState state, Behaviour behaviour);
    void PSGLClearCoreState(PSGLCoreState state);
    void PSGLUpdateDeviceStateBehaviour(PSGLDeviceState state, Behaviour behaviour);
    uint32_t PSGLGetStaticDeviceState() const;
    void PSGLUpdateTextureStateBehaviour(uint32_t unit, uint64_t state, Behaviour behaviour);
    void PSGLClearTextureState(uint32_t unit, uint64_t state);
protected:
private:
    uint32_t m_shaderID;
    rw::math::MatrixType m_transformType;
    rw::math::Matrix44Affine *m_transform;
    rw::math::Matrix44Affine m_localTransform;
    uint32_t m_coreState;
    uint32_t m_dynamicCoreState;
    uint32_t m_dynamicSharedCoreState;
    uint32_t m_externalCoreState;
    RwRGBAReal *m_materialColor;
    RwRGBAReal m_localMaterialColor;
    SamplerStateBitField m_textureStates;
    SamplerStateBitField m_dynamicTextureStates;
    TextureData m_textureData[(16)];
    uint32_t m_textureUnits;
    PSGLShaderDataInfo *m_shaderData;
    uint32_t m_deviceStates;
    uint32_t m_dynamicDeviceStates;
    uint32_t m_dynamicSharedDeviceStates;
    uint32_t m_deviceBooleanValues;
    AlphaTestFunction m_alphaFunction;
    float32_t m_alphaReference;
    PSGLBlendFactor m_sFactor;
    PSGLBlendFactor m_dFactor;
    CullMode m_cullFace;
    uint32_t m_depthMask;
    uint32_t m_colorMask;
    PSGLDepthTestFunction m_depthFunction;
    PSGLStencilFunc m_stencilFunc;
    int32_t m_stencilRef;
    uint32_t m_stencilFuncMask;
    uint32_t m_stencilWriteMask;
    PSGLStencilOp m_stencilOpFail;
    PSGLStencilOp m_stencilOpZFail;
    PSGLStencilOp m_stencilOpZPass;
    float32_t m_lineWidth;
    float32_t m_pointSize;
    PSGLColorLogicOp m_colorLogicOp;
    PSGLPolygonMode m_polyMode;
    float32_t m_sampleCoverage;
    uint32_t m_sampleCoverageInverted;
    PrimitiveType m_primitiveType;
    const VertexDescriptor *m_vertexDescriptor;
    RwRGBReal m_ambient;
private:
    BuildState();
    BuildState(const BuildState &buildState);
    ~BuildState();
};
inline uint32_t
BuildState::PSGLGetShaderID() const
{
    ;
    return m_shaderID;
}
inline uint32_t
BuildState::PSGLGetCoreState() const
{
    ;
    return m_coreState;
}
inline uint32_t
BuildState::PSGLGetStaticCoreState() const
{
    ;
    return m_coreState & ~m_dynamicCoreState;
}
inline uint32_t
BuildState::PSGLGetStaticDeviceState() const
{
    ;
    return m_deviceStates & ~(m_dynamicDeviceStates | m_dynamicSharedDeviceStates);
}
inline void
BuildState::PSGLUpdateCoreStateBehaviour(PSGLCoreState state, Behaviour behaviour)
{
    ;
    m_dynamicCoreState &= ~state;
    m_dynamicSharedCoreState &= ~state;
    m_externalCoreState &= ~state;
    if (BEHAVIOUR_DYNAMIC == behaviour)
    {
        m_dynamicCoreState |= state;
    }
    else if (BEHAVIOUR_DYNAMIC_SHARED == behaviour)
    {
        m_dynamicSharedCoreState |= state;
    }
    else if (BEHAVIOUR_EXTERNAL == behaviour)
    {
        m_externalCoreState |= state;
    }
    return;
}
inline void
BuildState::PSGLUpdateDeviceStateBehaviour(PSGLDeviceState state, Behaviour behaviour)
{
    ;
    m_dynamicDeviceStates &= ~state;
    m_dynamicSharedDeviceStates &= ~state;
    if (BEHAVIOUR_DYNAMIC == behaviour)
    {
        m_dynamicDeviceStates |= state;
    }
    else if (BEHAVIOUR_DYNAMIC_SHARED == behaviour)
    {
        m_dynamicSharedDeviceStates |= state;
    }
    return;
}
inline void
BuildState::PSGLClearCoreState(PSGLCoreState state)
{
    ;
    m_coreState &= ~state;
    m_dynamicCoreState &= ~state;
    m_dynamicSharedCoreState &= ~state;
    m_externalCoreState &= ~state;
    return;
}
inline const SamplerStateBitField&
BuildState::PSGLGetTextureStates() const
{
    ;
    return m_textureStates;
}
inline uint32_t
BuildState::PSGLGetTextureUnits() const
{
    ;
    return m_textureUnits;
}
inline const BuildState::TextureData *
BuildState::PSGLGetTextureData() const
{
    ;
    return m_textureData;
}
inline SamplerStateBitField&
BuildState::PSGLGetStaticTextureStates(SamplerStateBitField &staticStates) const
{
    ;
    staticStates = ~m_dynamicTextureStates;
    staticStates &= m_textureStates;
    return staticStates;
}
inline void
BuildState::PSGLSetBooleanStates(uint32_t stateFlags, uint32_t valueFlags)
{
    ;
    ;

    m_deviceStates |= stateFlags;
    m_deviceBooleanValues = (m_deviceBooleanValues & ~stateFlags) | valueFlags;
    ;

    return;
}
inline void
BuildState::PSGLEnableState(Device::StateID stateId, Behaviour behaviour)
{
    ;
    uint32_t flag = (1 << stateId);
    ;

    m_deviceStates |= flag;
    m_deviceBooleanValues |= flag;
    PSGLUpdateDeviceStateBehaviour(stateId, behaviour);
    ;

    return;
}
inline void
BuildState::PSGLDisableState(Device::StateID stateId, Behaviour behaviour)
{
    ;
    uint32_t flag = (1 << stateId);
    ;

    m_deviceStates |= flag;
    m_deviceBooleanValues &= ~flag;
    PSGLUpdateDeviceStateBehaviour(stateId, behaviour);
    ;

    return;
}
inline uint32_t
BuildState::PSGLGetDeviceStates() const
{
    ;
    return m_deviceStates;
}
inline uint32_t
BuildState::PSGLGetBooleanValues() const
{
    ;
    return m_deviceBooleanValues;
}
inline AlphaTestFunction
BuildState::PSGLGetAlphaFunction() const
{
    ;
    return m_alphaFunction;
}
inline float32_t
BuildState::PSGLGetAlphaReference() const
{
    ;
    return m_alphaReference;
}
inline PSGLBlendFactor
BuildState::PSGLGetSourceBlendFactor() const
{
    ;
    return m_sFactor;
}
inline PSGLBlendFactor
BuildState::PSGLGetDestinationBlendFactor() const
{
    ;
    return m_dFactor;
}
inline CullMode
BuildState::PSGLGetCullFace() const
{
    ;
    return m_cullFace;
}
inline RwBool
BuildState::PSGLGetDepthMask() const
{
    ;
    return m_depthMask;
}
inline RwBool
BuildState::PSGLGetColorMask() const
{
    ;
    return m_colorMask;
}
inline void
BuildState::SetMaterialColor(const RwRGBAReal &color,
                             Behaviour behaviour)
{
    ;
    PSGLSetMaterialColor(&color, behaviour);
    return;
}
inline const RwRGBAReal
BuildState::GetMaterialColor() const
{
    ;
    return *PSGLGetMaterialColor();
}
inline RwBool
BuildState::HasMaterialColor() const
{
    ;
    return 0 != (m_coreState & PSGLCORESTATE_MATERIALCOLOR);
}
inline void
BuildState::SetTransform(const rw::math::Matrix44Affine &matrix,
                         const rw::math::MatrixType matrixType,
                         Behaviour behaviour)
{
    ;
    PSGLSetTransform(&matrix, matrixType, behaviour);
    return;
}
inline rw::math::Matrix44Affine
BuildState::GetTransform() const
{
    ;
    return *PSGLGetTransform();
}
inline RwBool
BuildState::HasTransform() const
{
    ;
    return 0 != (m_coreState & PSGLCORESTATE_TRANSFORM);
}
inline void
BuildState::SetPrimitiveType(PrimitiveType primType,
                             Behaviour behaviour)
{
    ;
    PSGLSetPrimitiveType(primType, behaviour);
    return;
}
inline PrimitiveType
BuildState::GetPrimitiveType() const
{
    ;
    return PSGLGetPrimitiveType();
}
inline RwBool
BuildState::HasPrimitiveType() const
{
    ;
    return m_primitiveType > PRIMITIVETYPE_NA && m_primitiveType < PRIMITIVETYPE_MAX;
}
inline void
BuildState::SetVertexDescriptor(const VertexDescriptor *vdesc,
                                Behaviour behaviour)
{
    ;
    PSGLSetVertexDescriptor(vdesc, behaviour);
    return;
}
inline const VertexDescriptor *
BuildState::GetVertexDescriptor() const
{
    ;
    return PSGLGetVertexDescriptor();
}
inline RwBool
BuildState::HasVertexDescriptor() const
{
    ;
    return 0 != (m_coreState & PSGLCORESTATE_VERTEXDESCRIPTOR);
}
inline void
BuildState::SetShaderState(Shader::StateID state,
                           const void *value,
                           uint32_t size,
                           uint32_t alignment,
                           Shader::DataType dataType,
                           Behaviour behaviour)
{
    ;
    PSGLSetShaderData(state, value, size, alignment, dataType, behaviour);
    return;
}
inline void
BuildState::GetShaderState(Shader::StateID state, void *value, uint32_t size) const
{
    ;
    memcpy(value, PSGLGetShaderData(state), size);
    return;
}
inline RwBool
BuildState::HasShaderState(Shader::StateID state) const
{
    ;
    return 0 != PSGLGetShaderDataInfo(state);
}
inline void
BuildState::SetRaster(uint32_t rasterIndex,
                      const Raster *raster,
                      Behaviour behaviour)
{
    ;
    PSGLSetRaster(rasterIndex, const_cast<Raster*>(raster), behaviour);
    return;
}
inline const Raster *
BuildState::GetRaster(uint32_t rasterIndex) const
{
    ;
    return PSGLGetRaster(rasterIndex);
}
inline RwBool
BuildState::HasRaster(uint32_t rasterIndex) const
{
    ;
    return PSGLHasRaster(rasterIndex);
}
}
}













namespace rw
{
namespace graphics
{












































































































}
}





namespace rw
{
namespace graphics
{
class EmbeddedState
{
public:
    void SetShader(const Shader *shader); void SetAlphaTestFunction(const AlphaTestFunction alphaTestFunction); void SetAlphaTestReference(const AlphaTestReference alphaTestReference); void SetAmbient(const RwRGBReal &ambient); void SetBlendMode(const BlendMode blend); void SetMaterialColor(const RwRGBAReal &color); void SetColorWriteEnable(const RwBool colorWriteEnable); void SetCullMode(const CullMode cullMode); void SetFogColor(const RwRGBReal &color); void SetFogDensity(const float32_t density); void SetFogType(const FogType type); void SetFogFarDistance(const float32_t distance); void SetFogNearDistance(const float32_t distance); void SetLight(const uint32_t lightIndex, const Light *light); void SetRaster(const Raster *raster); void SetRasterAddressU(const Raster::Addressing addressMode); void SetRasterAddressV(const Raster::Addressing addressMode); void SetRasterFilter(const Raster::Filter filter); void SetTransform(const rw::math::Matrix44Affine &matrix, const rw::math::MatrixType matrixType); void SetZTestEnable(const RwBool enable); void SetZWriteEnable(const RwBool enable); const Shader *GetShader() const; AlphaTestFunction GetAlphaTestFunction() const; AlphaTestReference GetAlphaTestReference() const; const RwRGBReal GetAmbient() const; BlendMode GetBlendMode() const; const RwRGBAReal GetMaterialColor() const; RwBool GetColorWriteEnable() const; CullMode GetCullMode() const; const RwRGBReal GetFogColor() const; float32_t GetFogDensity() const; FogType GetFogType() const; float32_t GetFogFarDistance() const; float32_t GetFogNearDistance() const; const Light *GetLight(const uint32_t lightIndex) const; Raster *GetRaster() const; Raster::Addressing GetRasterAddressU() const; Raster::Addressing GetRasterAddressV() const; Raster::Filter GetRasterFilter() const; rw::math::Matrix44Affine GetTransform() const; RwBool GetZTestEnable() const; RwBool GetZWriteEnable() const; RwBool HasShader() const; RwBool HasAlphaTestFunction() const; RwBool HasAlphaTestReference() const; RwBool HasAmbient() const; RwBool HasBlendMode() const; RwBool HasMaterialColor() const; RwBool HasColorWriteEnable() const; RwBool HasCullMode() const; RwBool HasFogColor() const; RwBool HasFogDensity() const; RwBool HasFogType() const; RwBool HasFogFarDistance() const; RwBool HasFogNearDistance() const; RwBool HasLight(const uint32_t lightIndex) const; RwBool HasRaster() const; RwBool HasRasterAddressU() const; RwBool HasRasterAddressV() const; RwBool HasRasterFilter() const; RwBool HasTransform() const; RwBool HasZTestEnable() const; RwBool HasZWriteEnable() const; void SetPrimitiveType(PrimitiveType primType); PrimitiveType GetPrimitiveType() const; RwBool HasPrimitiveType() const; void SetVertexDescriptor(const VertexDescriptor *vdesc); const VertexDescriptor *GetVertexDescriptor() const; RwBool HasVertexDescriptor() const; void SetDeviceState(Device::StateID state, Device::StateValue value); Device::StateValue GetDeviceState(Device::StateID state) const; RwBool HasDeviceState(Device::StateID state) const; void SetShaderState(Shader::StateID state, const void *value, uint32_t size); void GetShaderState(Shader::StateID state, void *value, uint32_t size) const; RwBool HasShaderState(Shader::StateID state) const; void SetRaster(uint32_t rasterIndex, const Raster *raster); Raster *GetRaster(uint32_t rasterIndex) const; RwBool HasRaster(uint32_t rasterIndex) const; void SetRasterState(uint32_t rasterIndex, Raster::StateID state, Raster::StateValue value); Raster::StateValue GetRasterState(uint32_t rasterIndex, Raster::StateID state) const; RwBool HasRasterState(uint32_t rasterIndex, Raster::StateID state) const;
    uint32_t PSGLGetInstanceSize() const;
    void PSGLSetRaster(uint32_t unit, const Raster *raster);
    Raster *PSGLGetRaster(uint32_t unit) const;
    RwBool PSGLHasRaster(uint32_t unit) const;
    void PSGLSetRasterMinFilter(uint32_t unit, Raster::Filter minFilter);
    Raster::Filter PSGLGetRasterMinFilter(uint32_t unit) const;
    RwBool PSGLHasRasterMinFilter(uint32_t unit) const;
    void PSGLSetRasterMagFilter(uint32_t unit, Raster::Filter magFilter);
    Raster::Filter PSGLGetRasterMagFilter(uint32_t unit) const;
    RwBool PSGLHasRasterMagFilter(uint32_t unit) const;
    void PSGLSetRasterFilter(uint32_t unit, Raster::Filter filter);
    Raster::Filter PSGLGetRasterFilter(uint32_t unit) const;
    RwBool PSGLHasRasterFilter(uint32_t unit) const;
    void PSGLSetRasterAddressU(uint32_t unit, Raster::Addressing addressU);
    Raster::Addressing PSGLGetRasterAddressU(uint32_t unit) const;
    RwBool PSGLHasRasterAddressU(uint32_t unit) const;
    void PSGLSetRasterAddressV(uint32_t unit, Raster::Addressing addressV);
    Raster::Addressing PSGLGetRasterAddressV(uint32_t unit) const;
    RwBool PSGLHasRasterAddressV(uint32_t unit) const;
    void PSGLSetShaderData(Shader::StateID shaderDataType, void *shaderData,
                         uint32_t size, RwBool copyData);
    const void *PSGLGetShaderData(Shader::StateID shaderDataType) const;
    RwBool PSGLHasShaderData(Shader::StateID shaderDataType) const;
    void PSGLAddCoreState(PSGLCoreState coreState);
    PSGLCoreState PSGLGetCoreState() const;
    void PSGLEnableState(Device::StateID state);
    void PSGLDisableState(Device::StateID state);
    RwBool PSGLBooleanState(Device::StateID state) const;
    void PSGLSetAlphaFunction(AlphaTestFunction alphaFunc);
    void PSGLSetAlphaReference(float32_t alphaReference);
    void PSGLSetSourceBlendFactor(PSGLBlendFactor sFactor);
    void PSGLSetDestinationBlendFactor(PSGLBlendFactor dFactor);
    void PSGLSetCullFace(CullMode cullFace);
    void PSGLSetDepthMask(RwBool depthMask);
    void PSGLSetColorMask(RwBool colorMask);
    void PSGLSetDepthTestFunction(PSGLDepthTestFunction depthFunc);
    void PSGLSetStencilFunction(PSGLStencilFunc func, int32_t ref, uint32_t mask);
    void PSGLSetStencilWriteMask(uint32_t writeMask);
    void PSGLSetStencilOps(PSGLStencilOp fail, PSGLStencilOp zFail, PSGLStencilOp zPass);
    void PSGLSetLineWidth(float32_t lineWidth);
    void PSGLSetPointSize(float32_t pointSize);
    void PSGLSetColorLogicOp(PSGLColorLogicOp logicOp);
    void PSGLSetPolygonMode(PSGLPolygonMode polyMode);
    void PSGLSetSampleCoverage(float32_t coverage, RwBool inverted);
    AlphaTestFunction PSGLGetAlphaFunction() const;
    float32_t PSGLGetAlphaReference() const;
    PSGLBlendFactor PSGLGetSourceBlendFactor() const;
    PSGLBlendFactor PSGLGetDestinationBlendFactor() const;
    CullMode PSGLGetCullFace() const;
    RwBool PSGLGetDepthMask() const;
    RwBool PSGLGetColorMask() const;
    PSGLDepthTestFunction PSGLGetDepthTestFunction();
    void PSGLGetStencilFunction(PSGLStencilFunc &func, int32_t &ref, uint32_t &mask);
    uint32_t PSGLGetStencilWriteMask();
    void PSGLGetStencilOps(PSGLStencilOp &fail, PSGLStencilOp &zFail, PSGLStencilOp &zPass);
    float32_t PSGLGetLineWidth();
    float32_t PSGLGetPointSize();
    PSGLColorLogicOp PSGLGetColorLogicOp();
    PSGLPolygonMode PSGLGetPolygonMode();
    void PSGLGetSampleCoverage(float32_t &coverage, RwBool &inverted);
    RwBool PSGLHasDepthTestFunction();
    RwBool PSGLHasStencilFunction();
    RwBool PSGLHasStencilWriteMask();
    RwBool PSGLHasStencilOps();
    RwBool PSGLHasLineWidth();
    RwBool PSGLHasPointSize();
    RwBool PSGLHasColorLogicOp();
    RwBool PSGLHasPolygonMode();
    RwBool PSGLHasSampleCoverage();
protected:
    uint8_t *PSGLDeviceData();
    const uint8_t *PSGLDeviceData() const;
    const Shader* m_shader;
    uint32_t m_coreState;
    uint32_t m_coreStateNoSync;
    SamplerStateBitField m_textureStates;
    SamplerStateBitField m_textureStatesNoSync;
    uint32_t m_textureUnits;
    uint32_t m_textureUnitsNoSync;
    uint32_t m_deviceStateNoSync;
    uint32_t m_deviceStates;
    uint32_t m_deviceBooleanValues;
    uint32_t m_instanceSize;
    PrimitiveType m_primitiveType;
    EmbeddedState();
    EmbeddedState(const EmbeddedState &embeddedState);
    ~EmbeddedState();
private:
};
class CompiledState : public EmbeddedState
{
public:
    static rw::ResourceDescriptor GetResourceDescriptor(const BuildState *buildState); static uint32_t GetAlignment(const BuildState *buildState); static uint32_t GetSize(const BuildState *buildState); static CompiledState *Initialize(const rw::Resource &resource, const BuildState *buildState); static CompiledState *Initialize(void *ptr, uint32_t size, const BuildState *buildState);
    void Release(); void Dispatch(); rw::ResourceDescriptor GetInstanceResourceDescriptor() const; uint32_t GetInstanceSize() const; uint32_t GetInstanceAlignment() const; CompiledState *Clone(void *ptr) const; CompiledState *Clone(const rw::Resource& resource) const; static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void Destruct(void *ptr); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks();
    static rw::ResourceDescriptor PSGLGetResourceDescriptor(const BuildState *deltaBS, const BuildState *sourceBS);
    static CompiledState *PSGLInitialize(const rw::Resource &resource,
                                       const BuildState *deltaBS, const BuildState *sourceBS);
    void PSGLDispatchNoSync();
protected:
private:

    uint8_t *PSGLDispatchCoreState(uint8_t *csData);
    uint8_t *PSGLDispatchTextureState(uint8_t *csData);
    uint8_t *PSGLDispatchDeviceState(uint8_t *csData);

    CompiledState();
    CompiledState(const CompiledState &compiledState);
    ~CompiledState();
};
inline uint32_t
EmbeddedState::PSGLGetInstanceSize() const
{
    ;
    return m_instanceSize;
}
inline void
EmbeddedState::PSGLAddCoreState(PSGLCoreState coreState)
{
    ;
    m_coreState |= coreState;
    return;
}
inline PSGLCoreState
EmbeddedState::PSGLGetCoreState() const
{
    ;
    return static_cast<PSGLCoreState>(m_coreState);
}
inline void
EmbeddedState::SetShaderState(Shader::StateID state, const void *value, uint32_t size)
{
    ;
    PSGLSetShaderData(state, const_cast<void *>(value), size, (1));
    return;
}
inline RwBool
EmbeddedState::HasShaderState(Shader::StateID state) const
{
    ;
    return PSGLHasShaderData(state);
}
inline void
EmbeddedState::SetPrimitiveType(PrimitiveType primType)
{
    ;
    ;
    ;
    m_primitiveType = primType;
    return;
}
inline PrimitiveType
EmbeddedState::GetPrimitiveType() const
{
    ;
    return m_primitiveType;
}
inline RwBool
EmbeddedState::HasPrimitiveType() const
{
    ;
    return (1);
}
inline rw::ResourceDescriptor
CompiledState::GetResourceDescriptor(const BuildState *buildState)
{
    ;
    return PSGLGetResourceDescriptor(buildState, buildState);
}
inline CompiledState *
CompiledState::Initialize(const rw::Resource &resource, const BuildState *buildState)
{
    ;
    return PSGLInitialize(resource, buildState, buildState);
}
inline Raster *
EmbeddedState::GetRaster() const
{
    ;
    return GetRaster(0);
}
inline void
EmbeddedState::SetRaster(const Raster *raster)
{
    ;
    SetRaster(0, raster);
    return;
}
inline RwBool
EmbeddedState::HasRaster(uint32_t sampler) const
{
    ;
    return (m_textureStates >> (sampler * TEXTUREDATA_NUMBITS)) & TEXTUREDATA_RASTER;
}
inline RwBool
EmbeddedState::HasRaster() const
{
    ;
    return HasRaster(0);
}
inline void
EmbeddedState::PSGLEnableState(Device::StateID state)
{
    ;
    uint32_t flag = 1 << state;
    ;
    m_deviceStateNoSync |= flag;
    m_deviceStates |= flag;
    m_deviceBooleanValues |= flag;
    return;
}
inline void
EmbeddedState::PSGLDisableState(Device::StateID state)
{
    ;
    uint32_t flag = 1 << state;
    ;
    m_deviceStateNoSync |= flag;
    m_deviceStates |= flag;
    m_deviceBooleanValues &= ~flag;
    return;
}
inline RwBool
EmbeddedState::PSGLBooleanState(Device::StateID state) const
{
    ;
    uint32_t flag = 1 << state;
    ;
    ;
    return (m_deviceBooleanValues & flag) != 0;
}
inline void
EmbeddedState::SetRasterState(uint32_t rasterIndex, Raster::StateID state, Raster::StateValue value)
{
 ;
    ;
 ;
 if(state == Raster::STATEID_MIN_FILTER)
 {
  PSGLSetRasterMinFilter(rasterIndex, (Raster::Filter)value);
 }
 else if (state == Raster::STATEID_MAG_FILTER)
 {
  PSGLSetRasterMagFilter(rasterIndex, (Raster::Filter)value);
 }
 else if (state == Raster::STATEID_ADDRESSING_U)
 {
  PSGLSetRasterAddressU(rasterIndex, (Raster::Addressing)value);
 }
 else if (state == Raster::STATEID_ADDRESSING_V)
 {
  PSGLSetRasterAddressV(rasterIndex, (Raster::Addressing)value);
 }
 else
 {
  ;
 }
 return;
}
inline Raster::StateValue
EmbeddedState::GetRasterState(uint32_t rasterIndex, Raster::StateID state) const
{
 ;
    ;
 ;
 Raster::StateValue stateVal = 0;
 if(state == Raster::STATEID_MIN_FILTER)
 {
  stateVal = (Raster::StateValue)PSGLGetRasterMinFilter(rasterIndex);
 }
 else if (state == Raster::STATEID_MAG_FILTER)
 {
  stateVal = (Raster::StateValue)PSGLGetRasterMagFilter(rasterIndex);
 }
 else if (state == Raster::STATEID_ADDRESSING_U)
 {
  stateVal = (Raster::StateValue)PSGLGetRasterAddressU(rasterIndex);
 }
 else if (state == Raster::STATEID_ADDRESSING_V)
 {
  stateVal = (Raster::StateValue)PSGLGetRasterAddressV(rasterIndex);
 }
 else
 {
  ;
 }
 return stateVal;
}
inline RwBool
EmbeddedState::HasRasterState(uint32_t rasterIndex, Raster::StateID state) const
{
 ;
    ;
 ;
 RwBool result = (0);
 if(state == Raster::STATEID_MIN_FILTER)
 {
  result = (Raster::StateValue)PSGLHasRasterMinFilter(rasterIndex);
 }
 else if (state == Raster::STATEID_MAG_FILTER)
 {
  result = (Raster::StateValue)PSGLHasRasterMagFilter(rasterIndex);
 }
 else if (state == Raster::STATEID_ADDRESSING_U)
 {
  result = (Raster::StateValue)PSGLHasRasterAddressU(rasterIndex);
 }
 else if (state == Raster::STATEID_ADDRESSING_V)
 {
  result = (Raster::StateValue)PSGLHasRasterAddressV(rasterIndex);
 }
 else
 {
  ;
 }
 return result;
}
}
}













namespace rw
{
namespace graphics
{





























}
}





namespace rw
{
namespace graphics
{
class RenderObject
{
public:
    class EmbeddedObjectIterator
    {
    public:
        EmbeddedState *GetEmbeddedState() const; EmbeddedMesh *GetEmbeddedMesh() const; RwBool Next();
        EmbeddedObjectIterator()
        {




        }
        EmbeddedObjectIterator(const EmbeddedObjectIterator &iterator)
        {
            m_data = iterator.m_data;
            m_dataEnd = iterator.m_dataEnd;
        }
        friend class RenderObject;
    protected:
    private:
        uint8_t *m_data;
        const uint8_t *m_dataEnd;
        EmbeddedObjectIterator(const uint8_t *data, const uint8_t *dataEnd)
            : m_data(const_cast<uint8_t *>(data)), m_dataEnd(dataEnd)
        {
            ;
        }
    };
    static rw::ResourceDescriptor GetResourceDescriptor(uint32_t numMeshes, const Mesh * const * meshes, const BuildState * const * buildStates, uint32_t flags); static uint32_t GetAlignment(uint32_t numMeshes, const Mesh * const * meshes, const BuildState * const * buildStates, uint32_t flags); static uint32_t GetSize(uint32_t numMeshes, const Mesh * const * meshes, const BuildState * const * buildStates, uint32_t flags); static RenderObject *Initialize(void *ptr, uint32_t size, uint32_t numMeshes, const Mesh * const * meshes, const BuildState * const * buildStates, uint32_t flags); static RenderObject *Initialize(const rw::Resource &resource, uint32_t numMeshes, const Mesh * const * meshes, const BuildState * const * buildStates, uint32_t flags);
    void Release(); void Dispatch(); uint32_t GetNumEmbeddedObjects() const; EmbeddedObjectIterator GetIterator() const; static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks();
    static void Destruct(void *ptr);
protected:
private:
    uint32_t m_numMeshes;
    uint32_t m_flags;
    uint32_t m_deltaCoreState;
    uint32_t m_deltaDeviceState;
    SamplerStateBitField m_deltaTextureState;
    const uint8_t* m_end;
    const EmbeddedState *PSGLGetFirstEmbeddedState() const;
    RenderObject();
    RenderObject(const RenderObject &renderObject);
    ~RenderObject();
};
inline const EmbeddedState *
RenderObject::PSGLGetFirstEmbeddedState() const
{
    ;
    const uint8_t *roData = reinterpret_cast<const uint8_t *>(this + 1);
    return static_cast<const EmbeddedState *>(((void *)(((rw::HostPtr)(roData) + ((rw::HostPtr)(16) - 1)) & ~((rw::HostPtr)(16) - 1))));
}
}
}













namespace rw
{
namespace graphics
{




















































}
}





namespace rw
{
namespace graphics
{
class GlobalState
{
public:
    static void SetAmbient(const RwRGBReal &ambient); static void SetBlendMode(BlendMode blend); static void SetMaterialColor(const RwRGBAReal &color); static void SetCullMode(CullMode cullMode); static void SetFogColor(const RwRGBReal &color); static void SetFogDensity(float32_t density); static void SetFogType(FogType t); static void SetFogFarDistance(float32_t distance); static void SetFogNearDistance(float32_t distance); static void SetLight(uint32_t indx, const Light *light); static void SetTransform(const rw::math::Matrix44Affine &matrix, rw::math::MatrixType matrixType); static void SetZTestEnable(RwBool enable); static void SetZWriteEnable(RwBool enable); static void SetRaster(const Raster *raster); static void SetRasterAddressU(Raster::Addressing addressMode); static void SetRasterAddressV(Raster::Addressing addressMode); static void SetRasterFilter(Raster::Filter filter); static void SetAlphaTestFunction(AlphaTestFunction alphaTestFunction); static void SetAlphaTestReference(AlphaTestReference alphaTestReference); static void SetColorWriteEnable(RwBool colorWriteEnable); static RwRGBReal GetAmbient(); static BlendMode GetBlendMode(); static RwRGBAReal GetMaterialColor(); static CullMode GetCullMode(); static RwRGBReal GetFogColor(); static float32_t GetFogDensity(); static FogType GetFogType(); static float32_t GetFogFarDistance(); static float32_t GetFogNearDistance(); static const Light *GetLight(uint32_t indx); static rw::math::Matrix44Affine GetTransform(); static RwBool GetZTestEnable(); static RwBool GetZWriteEnable(); static const Raster *GetRaster(); static Raster::Addressing GetRasterAddressU(); static Raster::Addressing GetRasterAddressV(); static Raster::Filter GetRasterFilter(); static AlphaTestFunction GetAlphaTestFunction(); static AlphaTestReference GetAlphaTestReference(); static RwBool GetColorWriteEnable(); static void SetDeviceState(Device::StateID state, Device::StateValue value); static Device::StateValue GetDeviceState(Device::StateID state); static void SetRaster(uint32_t rasterIndex, const Raster *raster); static const Raster *GetRaster(uint32_t rasterIndex); static void SetRasterState(uint32_t rasterIndex, Raster::StateID state, Raster::StateValue value); static Raster::StateValue GetRasterState(uint32_t rasterIndex, Raster::StateID state); static void DirtyAll(); static void Dispatch();
    static RwBool PSGLInitialize();
    static void PSGLRelease();
    static void PSGLSync();
    static void PSGLAddCoreState(uint32_t coreState);
    static void PSGLDirtyDeviceState(uint32_t deviceStates);
    static void PSGLAddTextureStates(SamplerStateBitField textureStates);
    static void PSGLSetRaster(uint32_t texUnit, const Raster *raster);
    static void PSGLSetRasterFilter(uint32_t texUnit, Raster::Filter filter);
    static void PSGLSetRasterMinFilter(uint32_t texUnit, Raster::Filter minFilter);
    static void PSGLSetRasterMagFilter(uint32_t texUnit, Raster::Filter minFilter);
    static void PSGLSetRasterAddressU(uint32_t texUnit, Raster::Addressing addressingU);
    static void PSGLSetRasterAddressV(uint32_t texUnit, Raster::Addressing addressingV);
    static Raster *PSGLGetRaster(uint32_t texUnit);
    static Raster::Filter PSGLGetRasterFilter(uint32_t texUnit);
    static Raster::Filter PSGLGetRasterMinFilter(uint32_t texUnit);
    static Raster::Filter PSGLGetRasterMagFilter(uint32_t texUnit);
    static Raster::Addressing PSGLGetRasterAddressU(uint32_t texUnit);
    static Raster::Addressing PSGLGetRasterAddressV(uint32_t texUnit);

    static void PSGLDispatchCoreState(uint32_t coreState);
    static void PSGLDispatchTextureStates(SamplerStateBitField textureStates, uint32_t textureUnits);
    static void PSGLDispatchDeviceStates(uint32_t deviceStates);

    static void PSGLEnableState(Device::StateID state);
    static void PSGLDisableState(Device::StateID state);
    static void PSGLSetAlphaFunction(AlphaTestFunction alphaFunc);
    static void PSGLSetAlphaReference(float32_t alphaReference);
    static void PSGLSetSourceBlendFactor(PSGLBlendFactor sFactor);
    static void PSGLSetDestinationBlendFactor(PSGLBlendFactor dFactor);
    static void PSGLSetCullFace(CullMode cullFace);
    static void PSGLSetDepthMask(RwBool depthMask);
    static void PSGLSetColorMask(RwBool colorMask);
    static void PSGLSetDepthTestFunction(PSGLDepthTestFunction depthFunc);
    static void PSGLSetStencilFunction(PSGLStencilFunc func, int32_t ref, uint32_t mask);
    static void PSGLSetStencilWriteMask(uint32_t writeMask);
    static void PSGLSetStencilOps(PSGLStencilOp fail, PSGLStencilOp zFail, PSGLStencilOp zPass);
    static void PSGLSetLineWidth(float32_t lineWidth);
    static void PSGLSetPointSize(float32_t pointSize);
    static void PSGLSetColorLogicOp(PSGLColorLogicOp logicOp);
    static void PSGLSetPolygonMode(PSGLPolygonMode polyMode);
    static void PSGLSetSampleCoverage(float32_t coverage, RwBool inverted);
    static PSGLDepthTestFunction PSGLGetDepthTestFunction();
    static void PSGLGetStencilFunction(PSGLStencilFunc &func, int32_t &ref, uint32_t &mask);
    static uint32_t PSGLGetStencilWriteMask();
    static void PSGLGetStencilOps(PSGLStencilOp &fail, PSGLStencilOp &zFail, PSGLStencilOp &zPass);
    static float32_t PSGLGetLineWidth();
    static float32_t PSGLGetPointSize();
    static PSGLColorLogicOp PSGLGetColorLogicOp();
    static PSGLPolygonMode PSGLGetPolygonMode();
    static void PSGLGetSampleCoverage(float32_t &coverage, RwBool &inverted);
    static RwBool PSGLGetBooleanState(Device::StateID state);
protected:
private:
    struct TextureData
    {
        Raster *m_raster;
        Raster::Filter m_minFilter;
        Raster::Filter m_magFilter;
        Raster::Addressing m_addressU;
        Raster::Addressing m_addressV;
    };
    static rw::math::MatrixType m_transformType;
    static rw::math::Matrix44 m_transform;
    static uint32_t m_coreState;
    static RwRGBAReal m_materialColor;
    static uint32_t m_deviceDirtyStates;
    static uint32_t m_deviceBooleanValues;
    static AlphaTestFunction m_alphaFunction;
    static float32_t m_alphaReference;
    static PSGLBlendFactor m_sFactor;
    static PSGLBlendFactor m_dFactor;
    static CullMode m_cullFace;
    static uint32_t m_depthMask;
    static uint32_t m_colorMask;
    static PSGLDepthTestFunction m_depthFunction;
    static PSGLStencilFunc m_stencilFunc;
    static int32_t m_stencilRef;
    static uint32_t m_stencilFuncMask;
    static uint32_t m_stencilWriteMask;
    static PSGLStencilOp m_stencilOpFail;
    static PSGLStencilOp m_stencilOpZFail;
    static PSGLStencilOp m_stencilOpZPass;
    static float32_t m_lineWidth;
    static float32_t m_pointSize;
    static PSGLColorLogicOp m_colorLogicOp;
    static PSGLPolygonMode m_polyMode;
    static float32_t m_sampleCoverage;
    static uint32_t m_sampleCoverageInverted;
    static TextureData m_textureData[(16)];
    static uint32_t m_textureUnits;
    static SamplerStateBitField m_textureDataChanged;
    static uint32_t m_textureUnitsChanged;
    static RwRGBReal m_ambient;
    static const Light *m_lights[(8)];
    GlobalState();
    GlobalState(const GlobalState &globalState);
    ~GlobalState();
};
inline void
GlobalState::PSGLAddCoreState(uint32_t coreState)
{
    ;
    ;
    ;
    m_coreState |= coreState;
    return;
}
inline void
GlobalState::PSGLDirtyDeviceState(uint32_t deviceStates)
{
    ;
    m_deviceDirtyStates |= deviceStates;
    return;
}
inline void
GlobalState::PSGLAddTextureStates(SamplerStateBitField textureStates)
{
    ;
    m_textureDataChanged |= textureStates;
    return;
}
inline void
GlobalState::PSGLEnableState(Device::StateID state)
{
    ;
    uint32_t flag = 1 << state;
    ;
    if ((m_deviceBooleanValues & flag) == 0)
    {
        m_deviceDirtyStates |= flag;
        m_deviceBooleanValues |= flag;
    }
    return;
}
inline void
GlobalState::PSGLDisableState(Device::StateID state)
{
    ;
    uint32_t flag = 1 << state;
    ;
    if (m_deviceBooleanValues & flag)
    {
        m_deviceDirtyStates |= flag;
        m_deviceBooleanValues &= ~flag;
    }
    return;
}
inline RwBool
GlobalState::PSGLGetBooleanState(Device::StateID state)
{
    ;
    return (m_deviceBooleanValues & (1 << state))?((1)):((0));
}
inline void
GlobalState::PSGLSetAlphaFunction(AlphaTestFunction alphaFunc)
{
    ;
    ;
    m_deviceDirtyStates |= (1 << PSGL_ALPHAFUNCTION);
    m_alphaFunction = alphaFunc;
    return;
}
inline void
GlobalState::PSGLSetAlphaReference(float32_t alphaReference)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_ALPHAREFERENCE);
    m_alphaReference = alphaReference;
    return;
}
inline void
GlobalState::PSGLSetSourceBlendFactor(PSGLBlendFactor sFactor)
{
    ;
    ;









    m_deviceDirtyStates |= (1 << PSGL_SFACTOR);
    m_sFactor = sFactor;
    return;
}
inline void
GlobalState::PSGLSetDestinationBlendFactor(PSGLBlendFactor dFactor)
{
    ;
    ;








    m_deviceDirtyStates |= (1 << PSGL_DFACTOR);
    m_dFactor = dFactor;
    return;
}
inline void
GlobalState::PSGLSetRasterMinFilter(uint32_t texUnit, Raster::Filter minFilter)
{
    ;
    ;
    ;
    SamplerStateBitField rasterBit(TEXTUREDATA_FILTERMIN);
    rasterBit <<= (texUnit * TEXTUREDATA_NUMBITS);
    m_textureDataChanged |= rasterBit;
    m_textureData[texUnit].m_minFilter = minFilter;
    return;
}
inline void
GlobalState::PSGLSetRasterMagFilter(uint32_t texUnit, Raster::Filter magFilter)
{
    ;
    ;
    ;
    SamplerStateBitField rasterBit(TEXTUREDATA_FILTERMAG);
    rasterBit <<= (texUnit * TEXTUREDATA_NUMBITS);
    m_textureDataChanged |= rasterBit;
    m_textureData[texUnit].m_magFilter = magFilter;
    return;
}
inline void
GlobalState::PSGLSetRasterAddressU(uint32_t texUnit, Raster::Addressing addressingU)
{
    ;
    ;
    ;
    SamplerStateBitField rasterBit(TEXTUREDATA_ADDRESSU);
    rasterBit <<= (texUnit * TEXTUREDATA_NUMBITS);
    m_textureDataChanged |= rasterBit;
    m_textureData[texUnit].m_addressU = addressingU;
    return;
}
inline void
GlobalState::PSGLSetRasterAddressV(uint32_t texUnit, Raster::Addressing addressingV)
{
    ;
    ;
    ;
    SamplerStateBitField rasterBit(TEXTUREDATA_ADDRESSV);
    rasterBit <<= (texUnit * TEXTUREDATA_NUMBITS);
    m_textureDataChanged |= rasterBit;
    m_textureData[texUnit].m_addressV = addressingV;
    return;
}
inline void
GlobalState::PSGLSetCullFace(CullMode cullFace)
{
    ;
    ;
    m_deviceDirtyStates |= (1 << PSGL_CULLFACE);
    m_cullFace = cullFace;
    return;
}
inline void
GlobalState::PSGLSetDepthMask(RwBool depthMask)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_DEPTHMASK);
    m_depthMask = depthMask;
    return;
}
inline void
GlobalState::PSGLSetColorMask(RwBool colorMask)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_COLORMASK);
    m_colorMask = colorMask;
    return;
}
inline void
GlobalState::PSGLSetDepthTestFunction(PSGLDepthTestFunction depthFunc)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_DEPTHFUNCTION);
    m_depthFunction = depthFunc;
    return;
}
inline void
GlobalState::PSGLSetStencilFunction(PSGLStencilFunc func, int32_t ref, uint32_t mask)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_STENCILFUNCTION);
    m_stencilFunc = func;
    m_stencilRef = ref;
    m_stencilFuncMask = mask;
    return;
}
inline void
GlobalState::PSGLSetStencilWriteMask(uint32_t writeMask)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_STENCILMASK);
    m_stencilWriteMask = writeMask;
    return;
}
inline void
GlobalState::PSGLSetStencilOps(PSGLStencilOp fail, PSGLStencilOp zFail, PSGLStencilOp zPass)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_STENCILOP);
    m_stencilOpFail = fail;
    m_stencilOpZFail = zFail;
    m_stencilOpZPass = zPass;
    return;
}
inline void
GlobalState::PSGLSetLineWidth(float32_t lineWidth)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_LINEWIDTH);
    m_lineWidth = lineWidth;
    return;
}
inline void
GlobalState::PSGLSetPointSize(float32_t pointSize)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_POINTSIZE);
    m_pointSize = pointSize;
    return;
}
inline void
GlobalState::PSGLSetColorLogicOp(PSGLColorLogicOp logicOp)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_LOGICOP);
    m_colorLogicOp = logicOp;
    return;
}
inline void
GlobalState::PSGLSetPolygonMode(PSGLPolygonMode polyMode)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_POLYGONMODE);
    m_polyMode = polyMode;
    return;
}
inline void
GlobalState::PSGLSetSampleCoverage(float32_t coverage, RwBool inverted)
{
    ;
    m_deviceDirtyStates |= (1 << PSGL_SAMPLECOVERAGE);
    m_sampleCoverage = coverage;
    m_sampleCoverageInverted = (uint32_t)inverted;
    return;
}
inline PSGLDepthTestFunction
GlobalState::PSGLGetDepthTestFunction()
{
    ;
    return m_depthFunction;
}
inline void
GlobalState::PSGLGetStencilFunction(PSGLStencilFunc &func, int32_t &ref, uint32_t &mask)
{
    ;
    func = m_stencilFunc;
    ref = m_stencilRef;
    mask = m_stencilFuncMask;
    return;
}
inline uint32_t
GlobalState::PSGLGetStencilWriteMask()
{
    ;
    return m_stencilWriteMask;
}
inline void
GlobalState::PSGLGetStencilOps(PSGLStencilOp &fail, PSGLStencilOp &zFail, PSGLStencilOp &zPass)
{
    ;
    fail = m_stencilOpFail;
    zFail = m_stencilOpZFail;
    zPass = m_stencilOpZPass;
    return;
}
inline float32_t
GlobalState::PSGLGetLineWidth()
{
    ;
    return m_lineWidth;
}
inline float32_t
GlobalState::PSGLGetPointSize()
{
    ;
    return m_pointSize;
}
inline PSGLColorLogicOp
GlobalState::PSGLGetColorLogicOp()
{
    ;
    return m_colorLogicOp;
}
inline PSGLPolygonMode
GlobalState::PSGLGetPolygonMode()
{
    ;
    return m_polyMode;
}
inline void
GlobalState::PSGLGetSampleCoverage(float32_t &coverage, RwBool &inverted)
{
    ;
    coverage = m_sampleCoverage;
    inverted = (RwBool)m_sampleCoverageInverted;
    return;
}
inline void
GlobalState::SetAmbient(const RwRGBReal &ambient)
{
    ;
    m_ambient = ambient;
    m_coreState |= PSGLCORESTATE_AMBIENT;
    return;
}
inline void
GlobalState::SetBlendMode(BlendMode blend)
{
    ;
    ;
    switch(blend)
    {
    case BLENDMODE_OPAQUE:
        PSGLDisableState(PSGL_BLEND);
        return;
        break;
    case BLENDMODE_ADD:
        PSGLSetSourceBlendFactor(PSGLBLENDFACTOR_ONE);
        PSGLSetDestinationBlendFactor(PSGLBLENDFACTOR_ONE);
        break;
    case BLENDMODE_DECAL:
        PSGLSetSourceBlendFactor(PSGLBLENDFACTOR_SRCALPHA);
        PSGLSetDestinationBlendFactor(PSGLBLENDFACTOR_ONEMINUSSRCALPHA);
        break;
    default:
        ;
    }
    PSGLEnableState(PSGL_BLEND);
    return;
}
inline void
GlobalState::SetMaterialColor(const RwRGBAReal &color)
{
    ;
    m_coreState |= PSGLCORESTATE_MATERIALCOLOR;
    m_materialColor = color;
    return;
}
inline void
GlobalState::SetCullMode(CullMode cullMode)
{
    ;
    ;
    switch (cullMode)
    {
    case CULLMODE_NONE:
        PSGLDisableState(PSGL_CULLING);
        return;
    default:
        PSGLSetCullFace(cullMode);
        break;
    }
    PSGLEnableState(PSGL_CULLING);
    return;
}
inline void
GlobalState::SetLight(uint32_t indx, const Light *light)
{
    ;
    ;
    m_lights[indx] = light;
    m_coreState |= 1 << (indx + PSGLCORESTATE_LIGHTSHIFT);
    return;
}
inline void
GlobalState::SetTransform(const rw::math::Matrix44Affine &matrix, rw::math::MatrixType matrixType)
{
    ;
    m_coreState |= PSGLCORESTATE_TRANSFORM;
    m_transformType = matrixType;
    m_transform = *reinterpret_cast<const rw::math::Matrix44 *>(&matrix);
    m_transform.XAxis().W() =0.0f;
    m_transform.YAxis().W() =0.0f;
    m_transform.ZAxis().W() =0.0f;
    m_transform.WAxis().W() =1.0f;
    return;
}
inline void
GlobalState::SetZTestEnable(RwBool enable)
{
    ;
    if (enable)
    {
        PSGLSetDepthTestFunction(PSGLDEPTHTEST_LEQUAL);
    }
    else
    {
        PSGLSetDepthTestFunction(PSGLDEPTHTEST_ALWAYS);
    }
    return;
}
inline void
GlobalState::SetZWriteEnable(RwBool enable)
{
    ;
    PSGLSetDepthMask(enable);
    return;
}
inline void
GlobalState::SetRaster(const Raster *raster)
{
    ;
    SetRaster(0, raster);
    return;
}
inline void
GlobalState::SetRasterAddressU(Raster::Addressing addressMode)
{
    ;
    PSGLSetRasterAddressU(0, addressMode);
    return;
}
inline void
GlobalState::SetRasterAddressV(Raster::Addressing addressMode)
{
    ;
    PSGLSetRasterAddressV(0, addressMode);
    return;
}
inline void
GlobalState::SetRasterFilter(Raster::Filter filter)
{
    ;
    PSGLSetRasterFilter(0, filter);
    return;
}
inline void
GlobalState::SetAlphaTestFunction(AlphaTestFunction alphaTestFunction)
{
    ;
    ;
    if (ALPHATESTFUNCTION_ALWAYS == alphaTestFunction)
    {
        PSGLDisableState(PSGL_ALPHATEST);
        return;
    }
    PSGLSetAlphaFunction(alphaTestFunction);
    PSGLEnableState(PSGL_ALPHATEST);
    return;
}
inline void
GlobalState::SetAlphaTestReference(AlphaTestReference alphaTestReference)
{
    ;
    float32_t ref = alphaTestReference / 255.0f;
    PSGLSetAlphaReference(ref);
    return;
}
inline void
GlobalState::SetColorWriteEnable(RwBool colorWriteEnable)
{
    ;
    PSGLSetColorMask(colorWriteEnable);
    return;
}
inline RwRGBAReal
GlobalState::GetMaterialColor()
{
    ;
    return m_materialColor;
}
inline CullMode
GlobalState::GetCullMode()
{
    ;
    if (!PSGLGetBooleanState(PSGL_CULLFACE))
    {
        return CULLMODE_NONE;
    }
    return m_cullFace;
}
inline rw::math::Matrix44Affine
GlobalState::GetTransform()
{
    ;
    return *reinterpret_cast<const rw::math::Matrix44Affine *>(&m_transform);
}
inline RwBool
GlobalState::GetZTestEnable()
{
    ;
    return PSGLGetBooleanState(PSGL_DEPTHTEST);
}
inline RwBool
GlobalState::GetZWriteEnable()
{
    ;
    return m_depthMask;
}
inline const Raster *
GlobalState::GetRaster()
{
    ;
    return GetRaster(0);
}
inline Raster::Addressing
GlobalState::GetRasterAddressU()
{
    ;
    return PSGLGetRasterAddressU(0);
}
inline Raster::Addressing
GlobalState::GetRasterAddressV()
{
    ;
    return PSGLGetRasterAddressV(0);
}
inline Raster::Filter
GlobalState::GetRasterFilter()
{
    ;
    return PSGLGetRasterFilter(0);
}
inline AlphaTestFunction
GlobalState::GetAlphaTestFunction()
{
    ;
    if (!PSGLGetBooleanState(PSGL_ALPHATEST))
    {
        return ALPHATESTFUNCTION_ALWAYS;
    }
    return m_alphaFunction;
}
inline AlphaTestReference
GlobalState::GetAlphaTestReference()
{
    ;
    AlphaTestReference ref = static_cast<AlphaTestReference>
        (static_cast<uint32_t>(m_alphaReference * 255.0f));
    return ref;
}
inline RwBool
GlobalState::GetColorWriteEnable()
{
    ;
    return m_colorMask;
}
inline void
GlobalState::SetRasterState(uint32_t rasterIndex, Raster::StateID state, Raster::StateValue value)
{
 ;
    ;
 ;
 if(state == Raster::STATEID_MIN_FILTER)
 {
  PSGLSetRasterMinFilter(rasterIndex, (Raster::Filter)value);
 }
 else if (state == Raster::STATEID_MAG_FILTER)
 {
  PSGLSetRasterMagFilter(rasterIndex, (Raster::Filter)value);
 }
 else if (state == Raster::STATEID_ADDRESSING_U)
 {
  PSGLSetRasterAddressU(rasterIndex, (Raster::Addressing)value);
 }
 else if (state == Raster::STATEID_ADDRESSING_V)
 {
  PSGLSetRasterAddressV(rasterIndex, (Raster::Addressing)value);
 }
 else
 {
  ;
 }
 return;
}
inline Raster::StateValue
GlobalState::GetRasterState(uint32_t rasterIndex, Raster::StateID state)
{
 ;
    ;
 ;
 Raster::StateValue stateVal = 0;
 if(state == Raster::STATEID_MIN_FILTER)
 {
  stateVal = (Raster::StateValue)PSGLGetRasterMinFilter(rasterIndex);
 }
 else if (state == Raster::STATEID_MAG_FILTER)
 {
  stateVal = (Raster::StateValue)PSGLGetRasterMagFilter(rasterIndex);
 }
 else if (state == Raster::STATEID_ADDRESSING_U)
 {
  stateVal = (Raster::StateValue)PSGLGetRasterAddressU(rasterIndex);
 }
 else if (state == Raster::STATEID_ADDRESSING_V)
 {
  stateVal = (Raster::StateValue)PSGLGetRasterAddressV(rasterIndex);
 }
 else
 {
  ;
 }
 return stateVal;
}
}
}













namespace rw
{
namespace graphics
{

















































}
}







namespace rw
{
namespace graphics
{
class Camera;
typedef int32_t LightsArrayType;
typedef LightsArrayType PSGLLightsArrayType;
class ActiveState
{
public:
    static RwBool Initialize (); static void Release (); static void Reset (); static const uint32_t GetRenderFrame (); static void SetTransform (const rw::math::Matrix44Affine *matrix, const rw::math::MatrixType matrixType); static const rw::math::Matrix44Affine * GetTransform (); static const rw::math::MatrixType GetTransformType (); static void SetTransposeTransform (const rw::math::Matrix44Affine *matrix); static const rw::math::Matrix44Affine * GetTransposeTransform (); static void SetInverseTransform (const rw::math::Matrix44Affine *matrix); static const rw::math::Matrix44Affine * GetInverseTransform (); static void SetInverseNormalizedTransform (const rw::math::Matrix44Affine *matrix); static const rw::math::Matrix44Affine * GetInverseNormalizedTransform (); static void SetViewMatrix (const rw::math::Matrix44Affine *matrix); static const rw::math::Matrix44Affine * GetViewMatrix (); static void SetProjectionMatrix (const rw::math::Matrix44Affine *matrix); static const rw::math::Matrix44Affine * GetProjectionMatrix (); static void SetViewProjectionMatrix (const rw::math::Matrix44Affine *matrix); static const rw::math::Matrix44Affine * GetViewProjectionMatrix (); static void SetViewProjectionTransposeMatrix(const rw::math::Matrix44Affine *matrix); static const rw::math::Matrix44Affine * GetViewProjectionTransposeMatrix(); static void SetCamera (const rw::graphics::Camera *camera); static const rw::graphics::Camera * GetCamera (); static void SetVertexDescriptor (const VertexDescriptor *vdesc); static const VertexDescriptor * GetVertexDescriptor (); static void SetLight (const Light *light, const uint32_t index); static const Light * GetLight (const uint32_t index); static const uint32_t GetNumLights (); static const Light * GetFirstLight (); static const LightsArrayType & GetSortedLightArray (); static void SetMaterialColor (const RwRGBAReal &color); static const RwRGBAReal & GetMaterialColor (); static RwBool IsMaterialWhite (); static void SetAmbientColor (const RwRGBReal &color); static const RwRGBReal & GetAmbientColor (); static RwBool IsAmbientBlack (); static void SetShader (const Shader *shader); static const Shader * GetShader (); static void SetVertexShader (const void *vertexShader); static const void * GetVertexShader (); static void SetPixelShader (const void *pixelShader); static const void * GetPixelShader (); static void SetShaderState (Shader::StateID shaderID, const void *shaderState); static const void * GetShaderState (Shader::StateID shaderID); static RwBool HasShaderStateChanged (Shader::StateID type); static void SetShaderStateChanged (Shader::StateID type); static void SetAllShaderStatesChanged (); static void DispatchShader ();
public:
    struct TextureUnitData
    {
        Raster *m_currentRaster;
        Raster::Filter m_minFilter;
        Raster::Filter m_magFilter;
        Raster::Addressing m_addressU;
        Raster::Addressing m_addressV;
    };
    enum Attachment
    {
        ATTACHMENT_NA = 0,
        ATTACHMENT_COLOR0 = 0x8CE0,
        ATTACHMENT_COLOR1 = 0x8CE1,
        ATTACHMENT_COLOR2 = 0x8CE2,
        ATTACHMENT_COLOR3 = 0x8CE3,
        ATTACHMENT_DEPTH = 0x8D00,
        ATTACHMENT_STENCIL = 0x8D20,
        ATTACHMENT_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    static void SetBooleanStates(uint32_t states, uint32_t values);
    static void EnableState(Device::StateID stateId);
    static void DisableState(Device::StateID stateId);
    static void SetAlphaFunction(AlphaTestFunction alphaFunc);
    static void SetAlphaReference(float32_t alphaReference);
    static void SetSourceBlendFactor(PSGLBlendFactor sFactor);
    static void SetDestinationBlendFactor(PSGLBlendFactor dFactor);
    static void SetCullFace(CullMode cullFace);
    static void SetDepthMask(RwBool depthMask);
    static void SetColorMask(RwBool colorMask);
    static void PSGLSetDepthTestFunction(PSGLDepthTestFunction depthFunc);
    static void PSGLSetStencilFunction(PSGLStencilFunc func, int32_t ref, uint32_t mask);
    static void PSGLSetStencilWriteMask(uint32_t writeMask);
    static void PSGLSetStencilOps(PSGLStencilOp fail, PSGLStencilOp zFail, PSGLStencilOp zPass);
    static void PSGLSetLineWidth(float32_t lineWidth);
    static void PSGLSetPointSize(float32_t pointSize);
    static void PSGLSetColorLogicOp(PSGLColorLogicOp logicOp);
    static void PSGLSetPolygonMode(PSGLPolygonMode polyMode);
    static void PSGLSetSampleCoverage(float32_t coverage, RwBool inverted);
    static void SetVertexBufferObject(uint32_t name);
    static void SetIndexBufferObject(uint32_t name);
    static void SetPixelBufferObject(uint32_t name);
    static void DrawArrays(uint32_t firstVertex, uint32_t numVertices);
    static void DrawElements(uint32_t numIndices, uint32_t indexDataType, const void *indexData);
    static void DrawRangeElements(uint32_t minVertexIndex, uint32_t maxVertexIndex, uint32_t numIndices,
                                  uint32_t indexDataType, const void *indexData);
    static void SetCgVertexProgram(const void *vertexProgram);
    static void SetCgFragmentProgram(const void *fragmentProgram);
    static void SetTextureUnitStatus(uint32_t units, uint32_t values);
    static void EnableTextureUnit(uint32_t unit);
    static void DisableTextureUnit(uint32_t unit);
    static TextureUnitData &GetTextureUnitData(uint32_t unit);
    static uint32_t GetTextureUnitStatus();
    static void SetRaster(TextureUnitData &tUnit, uint32_t unit, Raster *raster);
    static void SetRasterMagFilter(TextureUnitData &tUnit, Raster::Filter filter);
    static void SetRasterMinFilter(TextureUnitData &tUnit, Raster::Filter filter);
    static void SetRasterAddressingU(TextureUnitData &tUnit, Raster::Addressing address);
    static void SetRasterAddressingV(TextureUnitData &tUnit, Raster::Addressing address);
    static void SyncTextureStates();
    static void BindTexture(Raster *raster);
    static void UnbindTexture(uint32_t unit, Raster *raster);
    static void SetClientActiveTextureUnit(uint32_t unit);
    static void BindRenderBuffer(uint32_t name);
    static void BindFrameBufferObject(uint32_t name);
    static void FrameBufferSetTarget(Attachment target, const Raster *raster);
    static void FrameBufferSetRaster(uint32_t bufferIdx, const Raster *raster);
    static void FrameBufferSetZBuffer(const Raster *zraster);
    static void FrameBufferSetStencilBuffer(const Raster *stencil);
    static void SetReadAttachment(Attachment attachment);
    static void ClearChangedFlags();
    static void DirtyShaderDataFlags();
    static void SetShaderData(Shader::StateID shaderDataType, const void *shaderData);
    static RwBool HasShaderDataChanged(Shader::StateID shaderDataType);
    static void ShaderDispatch();
    static void SetMatrixBuffer(rw::math::Matrix44 *buffer, uint32_t numMatrices);
    static void SetNumWeights(uint32_t numWeights);
public:
    static uint32_t m_deviceStateChanged;
    static uint32_t m_deviceStateDispatched;
    static uint32_t m_deviceBooleanValues;
    static AlphaTestFunction m_alphaFunction;
    static float32_t m_alphaReference;
    static PSGLBlendFactor m_sFactor;
    static PSGLBlendFactor m_dFactor;
    static CullMode m_cullFace;
    static uint32_t m_depthMask;
    static uint32_t m_colorMask;
    static PSGLDepthTestFunction m_depthFunction;
    static PSGLStencilFunc m_stencilFunc;
    static int32_t m_stencilRef;
    static uint32_t m_stencilFuncMask;
    static uint32_t m_stencilWriteMask;
    static PSGLStencilOp m_stencilOpFail;
    static PSGLStencilOp m_stencilOpZFail;
    static PSGLStencilOp m_stencilOpZPass;
    static float32_t m_lineWidth;
    static float32_t m_pointSize;
    static PSGLColorLogicOp m_colorLogicOp;
    static PSGLPolygonMode m_polyMode;
    static float32_t m_sampleCoverage;
    static uint32_t m_sampleCoverageInverted;
    static uint32_t m_clientStateFlags;
    static uint32_t m_previousClientStateFlags;
    static uint32_t m_vertexBufferObject;
    static uint32_t m_indexBufferObject;
    static uint32_t m_pixelBufferObject;
    static uint32_t m_frameBufferObject;
    static uint32_t m_coreStateChanged;
    static uint32_t m_coreStateDispatched;
    static const Shader *m_shader;
    static Shader::PSGLDispatchCallback m_shaderDispatchCB;
    static const void *m_cgVertexProgram;
    static const void *m_cgFragmentProgram;
    static const void *m_vertexVaryingParam;
    static const void *m_previousVertexVaryingParam;
    static void *m_camera;
    static Camera::PSGLViewport m_viewport;
    static rw::math::Vector4 m_2DScreenSpaceToClipSpace;
    static const rw::math::Matrix44 *m_transform;
    static rw::math::MatrixType m_transformType;
    static const rw::math::Matrix44Affine *m_inverseTransform;
    static const void *m_shaderData[Shader::PSGLDATAID_MAX];
    static uint64_t m_shaderDataChanged[((Shader::PSGLDATAID_MAX + 63) >> 6)];
    static uint32_t m_textureUnitDataChanged;
    static uint32_t m_textureUnitRasterChanged;
    static uint32_t m_textureUnitStatusChanged;
    static uint32_t m_textureUnitStatusDispatched;
    static SamplerStateBitField m_textureUnitDataDispatched;
    static uint32_t m_currentActiveTextureUnit;
    static uint32_t m_currentClientActiveTextureUnit;
    static const Light *m_lights[(8)];
    static RwRGBReal m_ambient;
    static RwRGBAReal m_materialColor;
    static PrimitiveType m_primitiveType;
    static const VertexDescriptor *m_vertexDescriptor;
    static uint32_t m_framesRendered;
    static rw::math::Matrix44 *m_currentViewMatrix;
    static rw::math::Matrix44 *m_currentProjectionMatrix;
    static uint64_t m_timeAtAppStart;
protected:
private:
    static void DoSetActiveTextureUnit(uint32_t unit);
    static void DoSetRaster(Raster *raster);
    static uint32_t m_textureUnitStatus;
    static TextureUnitData m_textureUnitData[(16)];
    static void SyncDeviceStates();
    ActiveState();
    ActiveState(const ActiveState &activeState);
    ~ActiveState();
};
typedef ActiveState PSGLActiveState;
inline void
rwg_PSGLSyncVertexClientState(uint32_t clientStates)
{
    ;
    ;
    uint32_t vertexAttr = 0;
    uint32_t clientStateFlags = ActiveState::m_clientStateFlags;
    uint32_t previousClientStateFlags = ActiveState::m_previousClientStateFlags;
    while (clientStates)
    {
        uint32_t state = (clientStates & 0x1);
        if (state & clientStateFlags)
        {
            const CGparameter varyingParam =
                reinterpret_cast<const CGparameter *>(ActiveState::m_vertexVaryingParam)[vertexAttr];
            if (varyingParam)
            {
                cgGLEnableClientState(varyingParam);
            }
            else
            {
                ActiveState::m_clientStateFlags &= ~(1 << vertexAttr);
            }
        }
        else if (state & previousClientStateFlags)
        {
            const CGparameter varyingParam =
                reinterpret_cast<const CGparameter *>(ActiveState::m_previousVertexVaryingParam)[vertexAttr];
            if (varyingParam)
            {
                cgGLDisableClientState(varyingParam);
            }
        }
        clientStates >>= 1;
        clientStateFlags >>= 1;
        previousClientStateFlags >>= 1;
        vertexAttr += 1;
    };
    return;
}
inline const uint32_t
ActiveState::GetRenderFrame()
{
    ;
    return static_cast<const uint32_t>(ActiveState::m_framesRendered);
}
inline void
ActiveState::SetTransform(const rw::math::Matrix44Affine *matrix, const rw::math::MatrixType matrixType)
{
    ;
    ActiveState::m_transformType = matrixType;
    ActiveState::m_transform = reinterpret_cast<const rw::math::Matrix44 *>(matrix);
    return;
}
inline const rw::math::Matrix44Affine *
ActiveState::GetTransform()
{
    ;
    return reinterpret_cast<const rw::math::Matrix44Affine *>(ActiveState::m_transform);
}
inline const rw::math::MatrixType
ActiveState::GetTransformType()
{
    ;
    return ActiveState::m_transformType;
}
inline void
ActiveState::SetInverseTransform(const rw::math::Matrix44Affine *matrix)
{
    ;
    ActiveState::m_inverseTransform = matrix;
    return;
}
inline const rw::math::Matrix44Affine *
ActiveState::GetInverseTransform()
{
    ;
    return ActiveState::m_inverseTransform;
}
inline void
ActiveState::SetViewMatrix(const rw::math::Matrix44Affine *matrix)
{
    ;
    ActiveState::m_currentViewMatrix = const_cast<rw::math::Matrix44 *>(
                                       reinterpret_cast<const rw::math::Matrix44 *>(matrix));
    return;
}
inline const rw::math::Matrix44Affine *
ActiveState::GetViewMatrix()
{
    ;
    return (const rw::math::Matrix44Affine *)ActiveState::m_currentViewMatrix;
}
inline void
ActiveState::SetProjectionMatrix(const rw::math::Matrix44Affine *matrix)
{
    ;
    ActiveState::m_currentProjectionMatrix = const_cast<rw::math::Matrix44 *>(
                                             reinterpret_cast<const rw::math::Matrix44 *>(matrix));
    return;
}
inline const rw::math::Matrix44Affine *
ActiveState::GetProjectionMatrix()
{
    ;
    return reinterpret_cast<const rw::math::Matrix44Affine *>(ActiveState::m_currentProjectionMatrix);
}
inline const VertexDescriptor *
ActiveState::GetVertexDescriptor()
{
    ;
    return ActiveState::m_vertexDescriptor;
}
inline void
ActiveState::SetLight(const Light *light, const uint32_t index)
{
    ;
    ;
    ActiveState::m_lights[index] = light;
    return;
}
inline const Light *
ActiveState::GetLight(const uint32_t index)
{
    ;
    ;
    return ActiveState::m_lights[index];
}
inline const Light *
ActiveState::GetFirstLight()
{
    ;
    uint32_t n = 0;
    while (ActiveState::m_lights[n] == 0)
    {
        n++;
    }
    if (n >= (8))
    {
        return 0;
    }
    return ActiveState::m_lights[n];
}
inline void
ActiveState::SetMaterialColor(const RwRGBAReal &color)
{
    ;
    ActiveState::m_materialColor = color;
    return;
}
inline const RwRGBAReal &
ActiveState::GetMaterialColor()
{
    ;
    return reinterpret_cast<RwRGBAReal &>(ActiveState::m_materialColor);
}
inline void
ActiveState::SetAmbientColor(const RwRGBReal &color)
{
    ;
    ActiveState::m_ambient.red = color.red;
    ActiveState::m_ambient.green = color.green;
    ActiveState::m_ambient.blue = color.blue;
    return;
}
inline const RwRGBReal &
ActiveState::GetAmbientColor()
{
    ;
    return ActiveState::m_ambient;
}
inline void
ActiveState::SetShader(const Shader *shader)
{
    ;
    ;
    ActiveState::m_shader = shader;
    ActiveState::m_shaderDispatchCB = shader->PSGLGetDispatchCallback();
    ActiveState::m_coreStateChanged |= PSGLCORESTATE_SHADER;
    return;
}
inline const Shader *
ActiveState::GetShader()
{
    ;
    return ActiveState::m_shader;
}
inline void
ActiveState::SetVertexShader(const void *vertexShader)
{
    ;
    if (ActiveState::m_cgVertexProgram != vertexShader)
    {
        cgGLBindProgram(static_cast<CGprogram>(const_cast<void *>(vertexShader)));
        ActiveState::m_cgVertexProgram = vertexShader;
    }
    return;
}
inline const void *
ActiveState::GetVertexShader()
{
    ;
    return const_cast<void *>(ActiveState::m_cgVertexProgram);
}
inline void
ActiveState::SetPixelShader(const void *pixelShader)
{
    ;
    if (ActiveState::m_cgFragmentProgram != pixelShader)
    {
        cgGLBindProgram(static_cast<CGprogram>(const_cast<void *>(pixelShader)));
        ActiveState::m_cgFragmentProgram = pixelShader;
    }
    return;
}
inline const void *
ActiveState::GetPixelShader()
{
    ;
    return const_cast<void *>(ActiveState::m_cgFragmentProgram);
}
inline void
ActiveState::SetShaderState(Shader::StateID shaderID, const void *shaderState)
{
    ;
    ActiveState::m_shaderData[shaderID] = shaderState;
    ActiveState::m_shaderDataChanged[shaderID >> 6] |= ((1ull) << (shaderID & 63));
    return;
}
inline const void *
ActiveState::GetShaderState(Shader::StateID shaderID)
{
    ;
    return ActiveState::m_shaderData[shaderID];
}
inline RwBool
ActiveState::HasShaderStateChanged(Shader::StateID type)
{
    ;
    uint64_t mask = ((1ull) << (type & 63));
    return mask == (ActiveState::m_shaderDataChanged[type >> 6] & mask);
}
inline void
ActiveState::SetShaderStateChanged(Shader::StateID type)
{
    ;
    ActiveState::m_shaderDataChanged[type >> 6] |= ((1ull) << (type & 63));
    return;
}
inline void
ActiveState::SetAllShaderStatesChanged()
{
    ;
    for (uint32_t i = 0; i < ((Shader::PSGLDATAID_MAX + 63) >> 6); i += 1)
    {
        m_shaderDataChanged[i] = (0xffffffffffffffffull);
    }
    return;
}
inline void
ActiveState::DispatchShader()
{
    ;
    Shader::GetDataUploadCallback(Shader::PSGLDATAID_VERTEXPROGRAM)(0, m_shaderData[Shader::PSGLDATAID_VERTEXPROGRAM], 0);
    Shader::GetDataUploadCallback(Shader::PSGLDATAID_FRAGMENTPROGRAM)(0, m_shaderData[Shader::PSGLDATAID_FRAGMENTPROGRAM], 0);
    if ((m_shader != 0) && (m_shader->PSGLGetDispatchCallback() != 0))
    {
        m_shader->PSGLGetDispatchCallback()();
    }
    return;
}
inline void
ActiveState::SetCgVertexProgram(const void *vertexProgram)
{
    ;
    SetVertexShader(vertexProgram);
    return;
}
inline void
ActiveState::SetCgFragmentProgram(const void *fragmentProgram)
{
    ;
    ActiveState::SetPixelShader(fragmentProgram);
    return;
}
inline void
ActiveState::SetClientActiveTextureUnit(uint32_t texture)
{
    ;
    if ( texture != m_currentClientActiveTextureUnit )
    {
        glClientActiveTexture(0x84C0
                              + texture );
        ;
        m_currentClientActiveTextureUnit = texture;
    }
    return;
}
inline void
ActiveState::SetVertexBufferObject(uint32_t name)
{
    ;
    if (m_vertexBufferObject != name)
    {
        glBindBuffer(0x8892, name);
        ;
        m_vertexBufferObject = name;
    }
    return;
}
inline void
ActiveState::SetIndexBufferObject(uint32_t name)
{
    ;
    if (m_indexBufferObject != name)
    {
        glBindBuffer(0x8893, name);
        ;
        m_indexBufferObject = name;
    }
    return;
}
inline void
ActiveState::SetPixelBufferObject(uint32_t name)
{
    ;
    if (m_pixelBufferObject != name)
    {
        glBindBuffer(0x88EC, name);
        ;
        m_pixelBufferObject = name;
    }
    return;
}
inline void
ActiveState::BindRenderBuffer(uint32_t name)
{
    ;
    ;
    glBindRenderbufferOES(0x8D41, name);
    ;
    return;
}
inline void
ActiveState::BindFrameBufferObject(uint32_t name)
{
    ;
    if (m_frameBufferObject != name)
    {
        ;
        glBindFramebufferOES(0x8D40, name);
        ;
        m_frameBufferObject = name;
    }
    return;
}
inline void
ActiveState::FrameBufferSetTarget(Attachment target, const Raster *raster)
{
    ;
    if (raster->GetType() & (Raster::TYPE_TEXTURE))
    {
        ;

        ;

        glFramebufferTexture2DOES(0x8D40, target, raster->PSGLGetTarget(), raster->PSGLGetName(),
                                  0);
        ;
    }
    else
    {
        ;



        ;

        glFramebufferRenderbufferOES(0x8D40, target, 0x8D41,
                                     raster->PSGLGetRenderBuffer());
        ;
    }
    return;
}
inline void
ActiveState::FrameBufferSetRaster(uint32_t bufferIndex, const Raster *raster)
{
    ;
    ;
    ;
    ;

    Attachment attachment = (Attachment )(ATTACHMENT_COLOR0 + bufferIndex);
    FrameBufferSetTarget(attachment, raster);
    return;
}
inline void
ActiveState::FrameBufferSetZBuffer(const Raster *zraster)
{
    ;
    ;
    ;

    FrameBufferSetTarget(ATTACHMENT_DEPTH, zraster);
    ;
    return;
}
inline void
ActiveState::FrameBufferSetStencilBuffer(const Raster *stencil)
{
    ;
    ;

    FrameBufferSetTarget(ATTACHMENT_STENCIL, stencil);
    return;
}
inline void
ActiveState::DrawArrays(uint32_t firstVertex, uint32_t numVertices)
{
    ;
    ;
    ;
    if (m_deviceStateChanged)
    {
        SyncDeviceStates();
    }
    glDrawArrays(m_primitiveType, firstVertex, numVertices);
    ;
    return;
}
inline void
ActiveState::DrawElements(uint32_t numIndices, uint32_t indexDataType, const void *indexData)
{
    ;
    ;
    ;
    if (m_deviceStateChanged)
    {
        SyncDeviceStates();
    }
    glDrawElements(m_primitiveType, numIndices, indexDataType, indexData);
    ;
    return;
}
inline void
ActiveState::DrawRangeElements(uint32_t minVertexIndex, uint32_t maxVertexIndex, uint32_t numIndices,
                                   uint32_t indexDataType, const void *indexData)
{
    ;
    ;
    ;
    if (m_deviceStateChanged)
    {
        SyncDeviceStates();
    }
    glDrawRangeElements(m_primitiveType, minVertexIndex, maxVertexIndex, numIndices, indexDataType, indexData);
    ;
    return;
}
inline void
ActiveState::DoSetActiveTextureUnit(uint32_t unit)
{
    ;
    ;
    if ( m_currentActiveTextureUnit != unit )
    {
        glActiveTexture((0x84C0) + unit);
        ;
        m_currentActiveTextureUnit = unit;
    }
    return;
}
inline void
ActiveState::DoSetRaster(Raster *raster)
{
    ;
    ;

    glBindTexture(raster->PSGLGetTarget(), raster->PSGLGetName());
    ;
    return;
}
inline void
ActiveState::SetTextureUnitStatus(uint32_t units, uint32_t values)
{
    ;
    ;
    ;

    uint32_t unitsToChange = units & (values ^ m_textureUnitStatus);
    m_textureUnitStatus = (m_textureUnitStatus & ~unitsToChange) | (unitsToChange & values);
    m_textureUnitStatusChanged |= unitsToChange;
    return;
}
inline void
ActiveState::EnableTextureUnit(uint32_t unit)
{
    ;
    ;
    uint32_t flag = 1 << unit;
    if ((m_textureUnitStatus & flag) == 0)
    {
        m_textureUnitStatus |= flag;
        m_textureUnitStatusChanged |= flag;
    }
    return;
}
inline void
ActiveState::DisableTextureUnit(uint32_t unit)
{
    ;
    ;
    uint32_t flag = 1 << unit;
    if ((m_textureUnitStatus & flag) != 0)
    {
        m_textureUnitStatus &= ~flag;
        m_textureUnitStatusChanged |= flag;
    }
    return;
}
inline ActiveState::TextureUnitData &
ActiveState::GetTextureUnitData(uint32_t unit)
{
    ;
    ;
    m_textureUnitDataChanged |= 1 << unit;
    return m_textureUnitData[unit];
}
inline uint32_t
ActiveState::GetTextureUnitStatus()
{
    ;
    return m_textureUnitStatus;
}
inline void
ActiveState::SetRaster(TextureUnitData &tUnit, uint32_t unit, Raster *raster)
{
    ;
    ;
    if (tUnit.m_currentRaster != raster)
    {
        tUnit.m_currentRaster = raster;
        m_textureUnitRasterChanged |= 1 << unit;
    }
    return;
}
inline void
ActiveState::SetRasterMagFilter(TextureUnitData &tUnit, Raster::Filter filter)
{
    ;
    ;

    tUnit.m_magFilter = filter;
    return;
}
inline void
ActiveState::SetRasterMinFilter(TextureUnitData &tUnit, Raster::Filter filter)
{
    ;
    ;
    tUnit.m_minFilter = filter;
    return;
}
inline void
ActiveState::SetRasterAddressingU(TextureUnitData &tUnit, Raster::Addressing address)
{
    ;
    ;
    tUnit.m_addressU = address;
    return;
}
inline void
ActiveState::SetRasterAddressingV(TextureUnitData &tUnit, Raster::Addressing address)
{
    ;
    ;
    tUnit.m_addressV = address;
    return;
}
inline void
ActiveState::BindTexture(Raster *raster)
{
    ;
    ;
    DoSetRaster(raster);
    m_textureUnitData[m_currentActiveTextureUnit].m_currentRaster = raster;
    return;
}
inline void
ActiveState::SetBooleanStates(uint32_t stateFlags, uint32_t valueFlags)
{
    ;
    ;

    uint32_t statesThatDiffer = (stateFlags & m_deviceBooleanValues) ^ valueFlags;
    m_deviceStateChanged |= statesThatDiffer;
    m_deviceBooleanValues = (m_deviceBooleanValues & ~statesThatDiffer) | valueFlags;
    return;
}
inline void
ActiveState::EnableState(Device::StateID stateId)
{
    ;
    uint32_t flag = (1 << stateId);
    if ((m_deviceBooleanValues & flag) == 0)
    {
        m_deviceStateChanged |= flag;
        m_deviceBooleanValues |= flag;
    }
    return;
}
inline void
ActiveState::DisableState(Device::StateID stateId)
{
    ;
    uint32_t flag = (1 << stateId);
    if (m_deviceBooleanValues & flag)
    {
        m_deviceStateChanged |= flag;
        m_deviceBooleanValues &= ~flag;
    }
    return;
}
inline void
ActiveState::SetAlphaFunction(AlphaTestFunction alphaFunc)
{
    ;
    ;
    if (alphaFunc != m_alphaFunction)
    {
        m_deviceStateChanged |= (1 << PSGL_ALPHAFUNCTION);
        m_alphaFunction = alphaFunc;
    }
    return;
}
inline void
ActiveState::SetAlphaReference(float32_t alphaReference)
{
    ;
    if (alphaReference != m_alphaReference)
    {
        m_deviceStateChanged |= (1 << PSGL_ALPHAREFERENCE);
        m_alphaReference = alphaReference;
    }
    return;
}
inline void
ActiveState::SetSourceBlendFactor(PSGLBlendFactor sFactor)
{
    ;
    ;









    if (sFactor != m_sFactor)
    {
        m_deviceStateChanged |= (1 << PSGL_SFACTOR);
        m_sFactor = sFactor;
    }
    return;
}
inline void
ActiveState::SetDestinationBlendFactor(PSGLBlendFactor dFactor)
{
    ;
    ;








    if (dFactor != m_dFactor)
    {
        m_deviceStateChanged |= (1 << PSGL_DFACTOR);
        m_dFactor = dFactor;
    }
    return;
}
inline void
ActiveState::SetCullFace(CullMode cullFace)
{
    ;
    ;
    ;
    ;

    if (cullFace != m_cullFace)
    {
        m_deviceStateChanged |= (1 << PSGL_CULLFACE);
        m_cullFace = cullFace;
    }
    return;
}
inline void
ActiveState::SetDepthMask(RwBool depthMask)
{
    ;
    if (depthMask != m_depthMask)
    {
        m_deviceStateChanged |= (1 << PSGL_DEPTHMASK);
        m_depthMask = depthMask;
    }
    return;
}
inline void
ActiveState::SetColorMask(RwBool colorMask)
{
    ;
    if (colorMask != m_colorMask)
    {
        m_deviceStateChanged |= (1 << PSGL_COLORMASK);
        m_colorMask = colorMask;
    }
    return;
}
inline void
ActiveState::PSGLSetDepthTestFunction(PSGLDepthTestFunction depthFunc)
{
    ;
    if (depthFunc != m_depthFunction)
    {
        m_deviceStateChanged |= (1 << PSGL_DEPTHFUNCTION);
        m_depthFunction = depthFunc;
    }
    return;
}
inline void
ActiveState::PSGLSetStencilFunction(PSGLStencilFunc func, int32_t ref, uint32_t mask)
{
    ;
    if ((func != m_stencilFunc) || (ref != m_stencilRef) || (mask != m_stencilFuncMask))
    {
        m_deviceStateChanged |= (1 << PSGL_STENCILFUNCTION);
        m_stencilFunc = func;
        m_stencilRef = ref;
        m_stencilFuncMask = mask;
    }
    return;
}
inline void
ActiveState::PSGLSetStencilWriteMask(uint32_t writeMask)
{
    ;
    if (writeMask != m_stencilWriteMask)
    {
        m_deviceStateChanged |= (1 << PSGL_STENCILMASK);
        m_stencilWriteMask = writeMask;
    }
    return;
}
inline void
ActiveState::PSGLSetStencilOps(PSGLStencilOp fail, PSGLStencilOp zFail, PSGLStencilOp zPass)
{
    ;
    if ((fail != m_stencilOpFail) || (zFail != m_stencilOpZFail) || (zPass != m_stencilOpZPass))
    {
        m_deviceStateChanged |= (1 << PSGL_STENCILOP);
        m_stencilOpFail = fail;
        m_stencilOpZFail = zFail;
        m_stencilOpZPass = zPass;
    }
    return;
}
inline void
ActiveState::PSGLSetLineWidth(float32_t lineWidth)
{
    ;
    if (lineWidth != m_lineWidth)
    {
        m_deviceStateChanged |= (1 << PSGL_LINEWIDTH);
        m_lineWidth = lineWidth;
    }
    return;
}
inline void
ActiveState::PSGLSetPointSize(float32_t pointSize)
{
    ;
    if (pointSize != m_pointSize)
    {
        m_deviceStateChanged |= (1 << PSGL_POINTSIZE);
        m_pointSize = pointSize;
    }
    return;
}
inline void
ActiveState::PSGLSetColorLogicOp(PSGLColorLogicOp logicOp)
{
    ;
    if (logicOp != m_colorLogicOp)
    {
        m_deviceStateChanged |= (1 << PSGL_LOGICOP);
        m_colorLogicOp = logicOp;
    }
    return;
}
inline void
ActiveState::PSGLSetPolygonMode(PSGLPolygonMode polyMode)
{
    ;
    if (polyMode != m_polyMode)
    {
        m_deviceStateChanged |= (1 << PSGL_POLYGONMODE);
        m_polyMode = polyMode;
    }
    return;
}
inline void
ActiveState::PSGLSetSampleCoverage(float32_t coverage, RwBool inverted)
{
    ;
    if ((coverage != m_sampleCoverage) || ((uint32_t)inverted != m_sampleCoverageInverted))
    {
        m_deviceStateChanged |= (1 << PSGL_SAMPLECOVERAGE);
        m_sampleCoverage = coverage;
        m_sampleCoverageInverted = (uint32_t)inverted;
    }
    return;
}
inline void
ActiveState::SetReadAttachment(Attachment attachment)
{
    ;
    ;


    if (m_frameBufferObject != 0)
    {
        glReadBuffer(attachment);
        ;
    }
    return;
}
inline void
ActiveState::ClearChangedFlags()
{
    ;
    m_coreStateChanged = 0;
    for (uint32_t i = 0; i < ((Shader::PSGLDATAID_MAX + 63) >> 6); i += 1)
    {
        m_shaderDataChanged[i] = 0;
    }
    m_textureUnitDataChanged = m_textureUnitRasterChanged = m_textureUnitStatusChanged = 0;
    return;
}
inline void
ActiveState::DirtyShaderDataFlags()
{
    ;
    ActiveState::SetAllShaderStatesChanged();
    return;
}
inline void
ActiveState::SetShaderData(Shader::StateID shaderDataType, const void *shaderData)
{
    ;
    ActiveState::SetShaderState(shaderDataType, shaderData);
    return;
}
inline RwBool
ActiveState::HasShaderDataChanged(Shader::StateID shaderDataType)
{
    ;
    return ActiveState::HasShaderStateChanged(shaderDataType);
}
}
}













namespace rw
{
namespace graphics
{
































}
}





namespace rw
{
namespace graphics
{
class ShaderCode
{
    public: enum Type { VERTEX_SHADER = 0, PIXEL_SHADER = 1, DATATYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1)) }; static rw::ResourceDescriptor GetResourceDescriptor(const uint32_t *bytecode, const Type type, uint32_t bytecodeSize = 0); static ShaderCode *Initialize(const rw::Resource &resource, const uint32_t *bytecode, const Type type, uint32_t bytecodeSize = 0); static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void Destruct(void *ptr); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); const Type GetType() const; void Dispatch(); void DispatchVertexShader(); void DispatchPixelShader(); void Release();private: void ConstructDriverObject(); void DestructDriverObject(); void ConstructPixelShader(); void ConstructVertexShader(); void DestructPixelShader(); void DestructVertexShader();
public:
    const void *GetCgProgram() const;
private:
    void* m_cgProgram;
    Type m_type;
    uint32_t m_bytecode[1];
};
inline const void *
ShaderCode::GetCgProgram() const
{
    ;
    return m_cgProgram;
}
inline const ShaderCode::Type
ShaderCode::GetType() const
{
    ;
    return m_type;
}
inline void
ShaderCode::DestructVertexShader()
{
    ;
    DestructDriverObject();
    return;
}
inline void
ShaderCode::DestructPixelShader()
{
    ;
    DestructDriverObject();
    return;
}
inline void
ShaderCode::Release()
{
    ;
    DestructDriverObject();
    return;
}
inline void
ShaderCode::DispatchVertexShader()
{
    ;

    PSGLActiveState::SetCgVertexProgram(m_cgProgram);

    return;
}
inline void
ShaderCode::DispatchPixelShader()
{
    ;

    PSGLActiveState::SetCgFragmentProgram(m_cgProgram);

    return;
}
}
}













namespace rw
{
namespace graphics
{













































}
}





namespace rw
{
namespace graphics
{
typedef void (*ShaderDataUploadCallback)(void *cgParam, const void *data, uint32_t size);
struct ProgramData
{
    void* m_cgParam;
    uint16_t m_dataID;
    uint16_t m_dataType;
    union {
        struct {
            uint16_t m_arrayElements;
            uint8_t m_columns;
            uint8_t m_rows;
        } m_sizeInfo;
        uint32_t m_customDataArg;
    };

    inline CGparameter GetCgParam() const
    {
        ;
        return (CGparameter )m_cgParam;
    }

    inline RwChar *GetName()
    {
        ;
        return (RwChar *)rw::RwPtrToHostPtr(m_cgParam);
    }
    inline const RwChar *GetName() const
    {
        ;
        return (const RwChar *)rw::RwPtrToHostPtr(m_cgParam);
    }














    inline void SetCgParam(CGparameter cgParam)
    {
        ;
        m_cgParam = (void *)cgParam;
        return;
    }

};
typedef ProgramData ShaderStateUploadBuildItem;
class ShaderStateMapping
{
public:
    static uint32_t GetSizeOfUploadItemTable(const uint32_t numItems, const ShaderStateUploadBuildItem *items); static void InitializeUploadItemTable(void *uploadItems, const uint32_t numItems, const ShaderStateUploadBuildItem *buildItems); static void UnfixUploadItemTable(void *itemTable, const uint32_t numItems = 0, rw::core::arena::SizeAndAlignment *offset = 0); static void RefixUploadItemTable(void *itemTable, const uint32_t numItems = 0, rw::core::arena::ArenaIterator *iterator = 0); static void FixupUploadItemTable(void *itemTable, const uint32_t numItems = 0, rw::core::arena::ArenaIterator *iterator = 0); static void RemapStateIDs(void *itemTable, uint32_t numItems, ShaderStateRemapIDCallback remapCallback); void SetShaderCode(ShaderCode *shaderCode); void DispatchShaderCode(); void DispatchAsVertexShader(); void DispatchAsPixelShader(); void DispatchAsVertexShaderNoCheck(); void DispatchAsPixelShaderNoCheck(); void Dispatch(); void DispatchNoCheck();
public:
    void ResolveParameters();

    void *GetCgNamedParameter(const RwChar *name) const;

private:
    void DataUploadNoCheck(const ProgramData *programData) const;
    void DataUploadCheck(const ProgramData *programData) const;
protected:
    ShaderCode* m_shaderCode;
    uint32_t m_numShaderData;
    uint16_t m_instanceSize;
    uint16_t m_vertexElementHash;
};
class VertexShader : public ShaderStateMapping
{
public:
    static VertexShader *Initialize(const rw::Resource &resource, ShaderCode *shaderCode, const uint32_t stateFlags, const uint32_t numItems, const ShaderStateUploadBuildItem *items); static rw::ResourceDescriptor GetResourceDescriptor(ShaderCode *shaderCode, const uint32_t stateFlags, const uint32_t numItems, const ShaderStateUploadBuildItem *items); static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void Upload(); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void Release(); void RemapShaderStateMappingIDs(ShaderStateRemapIDCallback remapCallback);
public:
    static void DataUpload(void *param, const void *ptr, uint32_t size);

    void *GetCGVaryingParams();
    const void *GetCGVaryingParams() const;
    void ResolveVertexVaryingParams();

};
class PixelShader : public ShaderStateMapping
{
public:
    static PixelShader *Initialize(const rw::Resource &resource, ShaderCode *shaderCode, const uint32_t stateFlags, const uint32_t numItems, const ShaderStateUploadBuildItem *items); static rw::ResourceDescriptor GetResourceDescriptor(ShaderCode *shaderCode, const uint32_t stateFlags, const uint32_t numItems, const ShaderStateUploadBuildItem *items); static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void Upload(); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void Release(); void RemapShaderStateMappingIDs(ShaderStateRemapIDCallback remapCallback);
public:
    static void DataUpload(void *param, const void *ptr, uint32_t size);
};

inline void *
VertexShader::GetCGVaryingParams()
{
    ;
    return static_cast<void *>(((void *)(((rw::HostPtr)(reinterpret_cast<uint8_t *>(this) + m_instanceSize) + ((rw::HostPtr)(4) - 1)) & ~((rw::HostPtr)(4) - 1))));
}


inline const void *
VertexShader::GetCGVaryingParams() const
{
    ;
    return static_cast<const void *>(((void *)(((rw::HostPtr)(reinterpret_cast<const uint8_t *>(this) + m_instanceSize) + ((rw::HostPtr)(4) - 1)) & ~((rw::HostPtr)(4) - 1))));
}

}
}
















namespace rw
{
namespace graphics
{
class Mesh;
class CompiledState;
class MeshCompiledStateLink
{
public:
    static rw::ResourceDescriptor GetResourceDescriptor(uint32_t numCompiledStates);
    static MeshCompiledStateLink *Initialize(const rw::Resource &resource, uint32_t numCompiledStates);
    void Release();
    rw::ResourceDescriptor GetInstanceResourceDescriptor() const;
    MeshCompiledStateLink *Clone(const rw::Resource &resource) const;
    void SetMesh(Mesh *mesh);
    void SetCompiledState(uint32_t compiledStateIndex, CompiledState *compiledState);
    Mesh *GetMesh() const;
    uint32_t GetNumCompiledStates() const;
    CompiledState *GetCompiledState(uint32_t compiledStateIndex) const;
    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
    static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator);
    static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
    static void RegisterArenaReadCallbacks();
    static void RegisterArenaWriteCallbacks();
private:
    MeshCompiledStateLink();
    MeshCompiledStateLink(const MeshCompiledStateLink &meshcompiledstatelink);
    ~MeshCompiledStateLink();
private:
    typedef Mesh* MeshPtr; typedef const Mesh* MeshConstPtr;
    typedef CompiledState* CompiledStatePtr; typedef const CompiledState* CompiledStateConstPtr;
    MeshPtr m_mesh;
    uint32_t m_numCompiledStates;



    CompiledStatePtr m_compiledStates[1];
};
inline rw::ResourceDescriptor
MeshCompiledStateLink::GetResourceDescriptor(uint32_t numCompiledStates)
{
    ;
    ;
    return rw::ResourceDescriptor(sizeof(MeshCompiledStateLink) + (numCompiledStates - 1) * sizeof(CompiledStatePtr), 4);

}
inline rw::ResourceDescriptor
MeshCompiledStateLink::GetInstanceResourceDescriptor() const
{
    ;
    ;
    return rw::ResourceDescriptor(sizeof(MeshCompiledStateLink) + (m_numCompiledStates - 1) * sizeof(CompiledStatePtr), 4);

}
inline void
MeshCompiledStateLink::SetMesh(Mesh *mesh)
{
    ;
    ;
    m_mesh = mesh;
    return;
}
inline void
MeshCompiledStateLink::SetCompiledState(uint32_t compiledStateIndex, CompiledState *compiledState)
{
    ;
    ;

    m_compiledStates[compiledStateIndex] = compiledState;
    return;
}
inline Mesh *
MeshCompiledStateLink::GetMesh() const
{
    ;
    return m_mesh;
}
inline uint32_t
MeshCompiledStateLink::GetNumCompiledStates() const
{
    ;
    return m_numCompiledStates;
}
inline CompiledState *
MeshCompiledStateLink::GetCompiledState(uint32_t compiledStateIndex) const
{
    ;
    ;

    return m_compiledStates[compiledStateIndex];
}
}
}






namespace rw
{
namespace graphics
{
    bool InitializeArenaReadCallbacks();
    bool InitializeArenaWriteCallbacks();
}
}
