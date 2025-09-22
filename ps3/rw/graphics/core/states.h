












namespace rw
{
namespace graphics
{
namespace core
{





























class MeshState
{
public:


    static const uint32_t MaxNumVertexBuffers = 16;
    static const uint32_t MaxNumIndexBuffers = 1;

    struct Parameters;

    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static MeshState *Initialize(const rw::Resource &resource, const Parameters &params);
    static void Destruct(MeshState *meshState);
    void Release();
    void GetParameters(Parameters &parameters) const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();

protected:


    MeshState();
    MeshState(const MeshState &meshState);
    ~MeshState();

    friend class rw::graphics::core::Device;
};






class TextureState
{
public:

    enum AddressingMode
    {
        ADDRESSINGMODE_NA = 0,

        ADDRESSINGMODE_WRAP = (1),
        ADDRESSINGMODE_MIRROR = (2),
        ADDRESSINGMODE_CLAMP = (3),
        ADDRESSINGMODE_CLAMP_TO_EDGE = (3),
        ADDRESSINGMODE_BORDER = (4),
        ADDRESSINGMODE_PS3CLAMP = (5),
        ADDRESSINGMODE_MIRROR_ONCE_CLAMP_TO_EDGE = (6),
        ADDRESSINGMODE_MIRROR_ONCE_BORDER = (7),
        ADDRESSINGMODE_MIRROR_ONCE_CLAMP = (8),

        ADDRESSINGMODE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    enum FilterMode
    {
        FILTERMODE_NA = 0,

        FILTERMODE_NONE = 0x10,
        FILTERMODE_NEAREST = 0x20,
        FILTERMODE_LINEAR = 0x40,
        FILTERMODE_CONVOLUTION = 0x80,


        PS3FILTERMODE_NEAREST = (1),
        PS3FILTERMODE_LINEAR = (2),
        PS3FILTERMODE_NEAREST_NEAREST = (3),
        PS3FILTERMODE_LINEAR_NEAREST = (4),
        PS3FILTERMODE_NEAREST_LINEAR = (5),
        PS3FILTERMODE_LINEAR_LINEAR = (6),
        PS3FILTERMODE_CONVOLUTION_MIN = (7),
        PS3FILTERMODE_CONVOLUTION_MAG = (4),

        FILTERMODE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };


    enum PS3Convolution
    {
        PS3CONVOLUTION_QUINCUNX = (1),
        PS3CONVOLUTION_GAUSSIAN = (2),
        PS3CONVOLUTION_QUINCUNX_ALT = (3),
    };






    enum PS3UnsignedRemap
    {
        PS3UNSIGNEDREMAP_NORMAL = (0),
        PS3UNSIGNEDREMAP_BIASED = (1),

        PS3UNSIGNEDREMAP_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };




    enum PS3DepthTextureFunction
    {
        PS3DEPTHTEXTUREFUNCTION_ZFUNC_NEVER = (0),
        PS3DEPTHTEXTUREFUNCTION_ZFUNC_LESS = (1),
        PS3DEPTHTEXTUREFUNCTION_ZFUNC_EQUAL = (2),
        PS3DEPTHTEXTUREFUNCTION_ZFUNC_LEQUAL = (3),
        PS3DEPTHTEXTUREFUNCTION_ZFUNC_GREATER = (4),
        PS3DEPTHTEXTUREFUNCTION_ZFUNC_NOTEQUAL = (5),
        PS3DEPTHTEXTUREFUNCTION_ZFUNC_GEQUAL = (6),
        PS3DEPTHTEXTUREFUNCTION_ZFUNC_ALWAYS = (7),

        PS3DEPTHTEXTUREFUNCTION_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };




    enum PS3TextureGamma
    {
        PS3TEXTURE_GAMMA_NONE = 0,
        PS3TEXTURE_GAMMA_R = (1<<0),
        PS3TEXTURE_GAMMA_G = (1<<1),
        PS3TEXTURE_GAMMA_B = (1<<2),
        PS3TEXTURE_GAMMA_A = (1<<3),

        PS3TEXTUREGAMMA_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    struct Parameters;

    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static TextureState *Initialize(const rw::Resource &resource, const Parameters &params);
    static void Destruct(TextureState *textureState);
    void Release();
    void GetParameters(Parameters &parameters) const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();

protected:






    TextureState();
    TextureState(const TextureState &textureState);
    ~TextureState();

    friend class rw::graphics::core::Device;
};






class RenderTargetState
{
public:


    static const uint32_t MaxNumColorTargets = 4;

    enum TargetID
    {
        TARGETID_COLOR0 = 0,
        TARGETID_COLOR1 = 1,
        TARGETID_COLOR2 = 2,
        TARGETID_COLOR3 = 3,

        TARGETID_DEPTHSTENCIL = 4,

        TARGETID_COLOR_ALL = 5,
        TARGETID_NUMTARGETS = 5,

        TARGETID_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    enum PS3SurfaceType
    {
        SURFACETYPE_PITCH = 1,
        SURFACETYPE_SWIZZLE = 2,
    };

    struct Parameters;

    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static RenderTargetState *Initialize(const rw::Resource &resource, const Parameters &params);
    static void Destruct(RenderTargetState *renderTargetState);
    void Release();
    void GetParameters(Parameters &parameters) const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();

protected:

    RenderTargetState();
    RenderTargetState(const RenderTargetState &renderTargetState);
    ~RenderTargetState();


    static void PS3PrintCellGcmSurface(const CellGcmSurface *surface);


    friend class Device;
};






class BlendState
{
public:

    enum Input
    {
        INPUT_ZERO = (0),
        INPUT_ONE = (1),
        INPUT_SRCCOLOR = (0x0300),
        INPUT_INVSRCCOLOR = (0x0301),
        INPUT_SRCALPHA = (0x0302),
        INPUT_INVSRCALPHA = (0x0303),
        INPUT_DESTCOLOR = (0x0306),
        INPUT_INVDESTCOLOR = (0x0307),
        INPUT_DESTALPHA = (0x0304),
        INPUT_INVDESTALPHA = (0x0305),

        INPUT_SRCALPHASATURATE = (0x0308),
        INPUT_CONSTANTCOLOR = (0x8001),
        INPUT_INVCONSTANTCOLOR = (0x8002),
        INPUT_CONSTANTALPHA = (0x8003),
        INPUT_INVCONSTANTALPHA = (0x8004),
    };

    enum Operation
    {
        OPERATION_ADD = (0x8006),
        OPERATION_SUBTRACT = (0x800A),
        OPERATION_REVSUBTRACT = (0x800B),
        OPERATION_MIN = (0x8007),
        OPERATION_MAX = (0x8008),
    };

    enum Function
    {
        FUNCTION_NEVER = (0x0200),
        FUNCTION_LESS = (0x0201),
        FUNCTION_EQUAL = (0x0202),
        FUNCTION_LESSEQUAL = (0x0203),
        FUNCTION_GREATER = (0x0204),
        FUNCTION_NOTEQUAL = (0x0205),
        FUNCTION_GREATEREQUAL = (0x0206),
        FUNCTION_ALWAYS = (0x0207),

        FUNCTION_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    struct Parameters;

    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static BlendState *Initialize(const rw::Resource &resource, const Parameters &params);
    static void Destruct(BlendState *blendState);
    void Release();
    void GetParameters(Parameters &parameters) const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();



    BlendState();
    BlendState(const BlendState &blendState);
    ~BlendState();

protected:

    static const uint32_t COLOR_MASK_B = (1<<0);
    static const uint32_t COLOR_MASK_G = (1<<8);
    static const uint32_t COLOR_MASK_R = (1<<16);
    static const uint32_t COLOR_MASK_A = (1<<24);

    static const uint32_t COLOR_MASK_MRT1_A = (1<<4);
    static const uint32_t COLOR_MASK_MRT1_R = (1<<5);
    static const uint32_t COLOR_MASK_MRT1_G = (1<<6);
    static const uint32_t COLOR_MASK_MRT1_B = (1<<7);

    static const uint32_t COLOR_MASK_MRT2_A = (1<<8);
    static const uint32_t COLOR_MASK_MRT2_R = (1<<9);
    static const uint32_t COLOR_MASK_MRT2_G = (1<<10);
    static const uint32_t COLOR_MASK_MRT2_B = (1<<11);

    static const uint32_t COLOR_MASK_MRT3_A = (1<<12);
    static const uint32_t COLOR_MASK_MRT3_R = (1<<13);
    static const uint32_t COLOR_MASK_MRT3_G = (1<<14);
    static const uint32_t COLOR_MASK_MRT3_B = (1<<15);


    friend class rw::graphics::core::Device;
    friend uint32_t RwHash32StateParams( const BlendState::Parameters& stateParams );
};






class DepthStencilState
{
public:

    enum Function
    {
        FUNCTION_NEVER = (0x0200),
        FUNCTION_LESS = (0x0201),
        FUNCTION_EQUAL = (0x0202),
        FUNCTION_LESSEQUAL = (0x0203),
        FUNCTION_GREATER = (0x0204),
        FUNCTION_NOTEQUAL = (0x0205),
        FUNCTION_GREATEREQUAL = (0x0206),
        FUNCTION_ALWAYS = (0x0207),

        FUNCTION_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    enum StencilOperation
    {
        STENCILOPERATION_NA = 0,

        STENCILOPERATION_KEEP = (0x1E00),
        STENCILOPERATION_ZERO = (0),
        STENCILOPERATION_INVERT = (0x150A),
        STENCILOPERATION_REPLACE = (0x1E01),
        STENCILOPERATION_INCR = (0x1E02),
        STENCILOPERATION_INCRWRAP = (0x8507),
        STENCILOPERATION_DECR = (0x1E03),
        STENCILOPERATION_DECRWRAP = (0x8508),

        STENCILOPERATION_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    struct Parameters;

    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static DepthStencilState *Initialize(const rw::Resource &resource, const Parameters &params);
    static void Destruct(DepthStencilState *blendState);
    void Release();
    void GetParameters(Parameters &parameters) const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();



protected:

    DepthStencilState();
    DepthStencilState(const DepthStencilState &depthStencilState);
    ~DepthStencilState();

    friend class rw::graphics::core::Device;
};






class RasterizerState
{
public:


    enum FillMode
    {
        FILLMODE_POINT = 0x00001B00,
        FILLMODE_WIREFRAME = 0x00001B01,
        FILLMODE_SOLID = 0x00001B02,

        FILLMODE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    enum CullMode
    {
        CULLMODE_NONE = 0,
        CULLMODE_FRONT = (0x0404),
        CULLMODE_BACK = (0x0405),
        CULLMODE_FRONT_AND_BACK = (0x0408),

        CULLMODE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    enum PS3FrontFace
    {
        PS3FRONTFACE_CW = (0x0900),
        PS3FRONTFACE_CCW = (0x0901),

        PS3FRONTFACE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    enum PS3ShadeMode
    {
        PS3SHADEMODE_FLAT = (0x1D00),
        PS3SHADEMODE_SMOOTH = (0x1D01),

        PS3SHADEMODE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    struct Parameters;

    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static RasterizerState *Initialize(const rw::Resource &resource, const Parameters &params);
    static void Destruct(RasterizerState *blendState);
    void Release();
    void GetParameters(Parameters &parameters) const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();

protected:


    RasterizerState();
    RasterizerState(const RasterizerState &rasterizerState);
    ~RasterizerState();

    friend class rw::graphics::core::Device;
};




inline void
EndianSwap(rw::graphics::core::BlendState::Input& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::BlendState::Input) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_blendstate_input_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_blendstate_input_is_not_sizeof_uint32_t) break;

    ;
}

inline void
EndianSwap(rw::graphics::core::BlendState::Operation& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::BlendState::Operation) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_blendstate_operation_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_blendstate_operation_is_not_sizeof_uint32_t) break;

    ;
}

inline void
EndianSwap(rw::graphics::core::BlendState::Function& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::BlendState::Function) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_blendstate_function_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_blendstate_function_is_not_sizeof_uint32_t) break;

    ;
}

inline void
EndianSwap(rw::graphics::core::DepthStencilState::Function& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::DepthStencilState::Function) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_depthstencilstate_function_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_depthstencilstate_function_is_not_sizeof_uint32_t) break;

    ;
}

inline void
EndianSwap(rw::graphics::core::DepthStencilState::StencilOperation& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::DepthStencilState::StencilOperation) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_depthstencilstate_stenciloperation_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_depthstencilstate_stenciloperation_is_not_sizeof_uint32_t) break;

    ;
}

inline void
EndianSwap(rw::graphics::core::RasterizerState::PS3FrontFace& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::RasterizerState::PS3FrontFace) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_rasterizerstate_ps3frontface_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_rasterizerstate_ps3frontface_is_not_sizeof_uint32_t) break;

    ;
}

inline void
EndianSwap(rw::graphics::core::RasterizerState::FillMode& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::RasterizerState::FillMode) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_raterizer_fillmode_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_raterizer_fillmode_is_not_sizeof_uint32_t) break;

    ;
}

inline void
EndianSwap(rw::graphics::core::RasterizerState::CullMode& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::RasterizerState::CullMode) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_rasterizerstate_CullMode_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_rasterizerstate_CullMode_is_not_sizeof_uint32_t) break;

    ;
}

inline void
EndianSwap(rw::graphics::core::RenderTargetState::TargetID& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::RenderTargetState::TargetID) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_rendertargetstate_TargetID_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_rendertargetstate_TargetID_is_not_sizeof_uint32_t) break;

    ;
}


}
}
}
