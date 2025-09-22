












namespace rw
{
namespace graphics
{
namespace core
{






static const uint32_t PS3TEXTUREFORMAT_B8 = (0x81);
static const uint32_t PS3TEXTUREFORMAT_A1R5G5B5 = (0x82);
static const uint32_t PS3TEXTUREFORMAT_A4R4G4B4 = (0x83);
static const uint32_t PS3TEXTUREFORMAT_R5G6B5 = (0x84);
static const uint32_t PS3TEXTUREFORMAT_A8R8G8B8 = (0x85);
static const uint32_t PS3TEXTUREFORMAT_COMPRESSED_DXT1 = (0x86);
static const uint32_t PS3TEXTUREFORMAT_COMPRESSED_DXT23 = (0x87);
static const uint32_t PS3TEXTUREFORMAT_COMPRESSED_DXT45 = (0x88);
static const uint32_t PS3TEXTUREFORMAT_G8B8 = (0x8B);
static const uint32_t PS3TEXTUREFORMAT_R6G5B5 = (0x8F);
static const uint32_t PS3TEXTUREFORMAT_DEPTH24_D8 = (0x90);
static const uint32_t PS3TEXTUREFORMAT_DEPTH24_D8_FLOAT = (0x91);
static const uint32_t PS3TEXTUREFORMAT_DEPTH16 = (0x92);
static const uint32_t PS3TEXTUREFORMAT_DEPTH16_FLOAT = (0x93);
static const uint32_t PS3TEXTUREFORMAT_X16 = (0x94);
static const uint32_t PS3TEXTUREFORMAT_Y16_X16 = (0x95);
static const uint32_t PS3TEXTUREFORMAT_R5G5B5A1 = (0x97);
static const uint32_t PS3TEXTUREFORMAT_COMPRESSED_HILO8 = (0x98);
static const uint32_t PS3TEXTUREFORMAT_COMPRESSED_HILO_S8 = (0x99);
static const uint32_t PS3TEXTUREFORMAT_W16_Z16_Y16_X16_FLOAT = (0x9A);
static const uint32_t PS3TEXTUREFORMAT_W32_Z32_Y32_X32_FLOAT = (0x9B);
static const uint32_t PS3TEXTUREFORMAT_X32_FLOAT = (0x9C);
static const uint32_t PS3TEXTUREFORMAT_D1R5G5B5 = (0x9D);
static const uint32_t PS3TEXTUREFORMAT_D8R8G8B8 = (0x9E);
static const uint32_t PS3TEXTUREFORMAT_Y16_X16_FLOAT = (0x9F);


static const uint32_t PS3TEXTUREFORMAT_LN = (0x20);

static const uint32_t PS3TEXTUREFORMAT_UN = (0x40);






inline uint32_t
PS3TextureFormatIsSwizzled(uint32_t textureFormat)
{
    ;
    return (textureFormat & PS3TEXTUREFORMAT_LN) == 0;
}




inline uint32_t
PS3TextureBaseFormat(uint32_t textureFormat)
{
    ;
    return textureFormat & ~(PS3TEXTUREFORMAT_LN | PS3TEXTUREFORMAT_UN);
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




static const uint32_t PS3REMAP_ORDER_XYXY = (0);
static const uint32_t PS3REMAP_ORDER_XXXY = (1);
static const uint32_t PS3REMAP_FROM_A = (0);
static const uint32_t PS3REMAP_FROM_R = (1);
static const uint32_t PS3REMAP_FROM_G = (2);
static const uint32_t PS3REMAP_FROM_B = (3);
static const uint32_t PS3REMAP_OUTPUT_ZERO = (0);
static const uint32_t PS3REMAP_OUTPUT_ONE = (1);
static const uint32_t PS3REMAP_OUTPUT_REMAP = (2);









struct PS3PixelFormatDescriptor
{
    uint32_t gcmFormat;
    uint32_t gcmRemap;
};

extern const PS3PixelFormatDescriptor ps3_pixelFormatDescriptorTable[];





enum PixelFormat
{
    PIXELFORMAT_NA = -1,


























    PIXELFORMAT_B8 = ( 0),
    PIXELFORMAT_A1R5G5B5 = ( 1),
    PIXELFORMAT_A4R4G4B4 = ( 2),
    PIXELFORMAT_R5G6B5 = ( 3),
    PIXELFORMAT_A8R8G8B8 = ( 4),
    PIXELFORMAT_COMPRESSED_DXT1 = ( 5),
    PIXELFORMAT_COMPRESSED_DXT23 = ( 6),
    PIXELFORMAT_COMPRESSED_DXT45 = ( 7),
    PIXELFORMAT_G8B8 = ( 8),
    PIXELFORMAT_R6G5B5 = ( 9),
    PIXELFORMAT_D24S8 = (10),
    PIXELFORMAT_D24S8F = (11),
    PIXELFORMAT_D16 = (12),
    PIXELFORMAT_D16F = (13),
    PIXELFORMAT_X16 = (14),
    PIXELFORMAT_Y16_X16 = (15),
    PIXELFORMAT_R5G5B5A1 = (16),
    PIXELFORMAT_COMPRESSED_HILO8 = (17),
    PIXELFORMAT_COMPRESSED_HILO_S8 = (18),
    PIXELFORMAT_W16_Z16_Y16_X16_FLOAT = (19),
    PIXELFORMAT_W32_Z32_Y32_X32_FLOAT = (20),
    PIXELFORMAT_X32_FLOAT = (21),
    PIXELFORMAT_D1R5G5B5 = (22),
    PIXELFORMAT_D8R8G8B8 = (23),
    PIXELFORMAT_Y16_X16_FLOAT = (24),
    PIXELFORMAT_R8G8B8A8 = (25),
    PIXELFORMAT_LIN_A8R8G8B8 = (26),
    PIXELFORMAT_LIN_A1R5G5B5 = (27),
    PIXELFORMAT_LIN_R5G6B5 = (28),
    PIXELFORMAT_LIN_D8R8G8B8 = (29),
    PIXELFORMAT_LIN_B8 = (30),
    PIXELFORMAT_LIN_G8B8 = (31),
    PIXELFORMAT_LIN_W16_Z16_Y16_X16_FLOAT = (32),
    PIXELFORMAT_LIN_W32_Z32_Y32_X32_FLOAT = (33),
    PIXELFORMAT_LIN_X32_FLOAT = (34),
    PIXELFORMAT_LIN_D16 = (35),
    PIXELFORMAT_LIN_D24S8 = (36),
    PIXELFORMAT_LIN_X16 = (37),
    PIXELFORMAT_LIN_COMPRESSED_DXT1 = (38),
    PIXELFORMAT_LIN_COMPRESSED_DXT23 = (39),
    PIXELFORMAT_LIN_COMPRESSED_DXT45 = (40),


    PIXELFORMAT_DXT1 = PIXELFORMAT_COMPRESSED_DXT1,
    PIXELFORMAT_DXT3 = PIXELFORMAT_COMPRESSED_DXT23,
    PIXELFORMAT_DXT5 = PIXELFORMAT_COMPRESSED_DXT45,
    PIXELFORMAT_LIN_DXT1 = PIXELFORMAT_LIN_COMPRESSED_DXT1,
    PIXELFORMAT_LIN_DXT3 = PIXELFORMAT_LIN_COMPRESSED_DXT23,
    PIXELFORMAT_LIN_DXT5 = PIXELFORMAT_LIN_COMPRESSED_DXT45,





























    PIXELFORMAT_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};

PixelFormat
PS3PixelFormatFromGCMFormat(uint32_t format, uint32_t remap );

inline uint32_t
PS3PixelFormatToGCMFormat(PixelFormat format)
{
    ;
    return ps3_pixelFormatDescriptorTable[(uint32_t )format].gcmFormat;
}

inline uint32_t
PS3PixelFormatToGCMRemap(PixelFormat format)
{
    ;
    return ps3_pixelFormatDescriptorTable[(uint32_t )format].gcmRemap;
}




inline uint32_t
PS3PixelFormatIsSwizzled(PixelFormat format)
{
    ;
    return PS3TextureFormatIsSwizzled(PS3PixelFormatToGCMFormat(format));
}

uint8_t PS3PixelFormatGetDepthFromGCMFormat(uint32_t gcmFormat);




bool PixelFormatIsCompressed(PixelFormat format);
uint8_t PixelFormatGetDepth(PixelFormat format);











}
}
}
