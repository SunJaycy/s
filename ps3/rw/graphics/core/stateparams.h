












namespace rw
{
namespace graphics
{
namespace core
{





























struct MeshState::Parameters
{
public:
    Parameters() : indexBuffer(0)
    {
        for (uint32_t vbIdx = 0 ; vbIdx < MaxNumVertexBuffers ; ++vbIdx)
        {
            vertexBuffer[vbIdx] = 0;
        }
    }


    void SetVertexBuffer(uint32_t id, VertexBuffer *vertexBuffer);
    void SetIndexBuffer(uint32_t id, IndexBuffer *indexBuffer);

    VertexBuffer *GetVertexBuffer(uint32_t id) const;
    IndexBuffer *GetIndexBuffer(uint32_t id) const;

protected:

    uint32_t PS3CountVertexBuffers() const;

    IndexBuffer *indexBuffer;
    VertexBuffer *vertexBuffer[MaxNumVertexBuffers];

    friend class MeshState;
};



inline uint32_t
MeshState::Parameters::PS3CountVertexBuffers() const
{
    ;

    uint32_t numVBs = 0;
    while(vertexBuffer[numVBs] != 0)
    {
        ++numVBs;
    }

    ;
    return numVBs;
}

inline void
MeshState::Parameters::SetVertexBuffer(uint32_t id, VertexBuffer *vb)
{
    ;
    vertexBuffer[id] = vb;
    return;
}

inline void
MeshState::Parameters::SetIndexBuffer(uint32_t , IndexBuffer *ib)
{
    ;
    ;
    indexBuffer = ib;
    return;
}

inline VertexBuffer *
MeshState::Parameters::GetVertexBuffer(uint32_t id) const
{
    ;
    return vertexBuffer[id];
}

inline IndexBuffer *
MeshState::Parameters::GetIndexBuffer(uint32_t ) const
{
    ;
    ;
    return indexBuffer;
}





struct TextureState::Parameters
{






    Parameters() :
        texture(0),
        addressU(ADDRESSINGMODE_WRAP),
        addressV(ADDRESSINGMODE_WRAP),
        addressW(ADDRESSINGMODE_WRAP),
        bias(0),
        maxLevel(0),
        minLevel(15),
        maxAnisotropy(1),
        magFilter(FILTERMODE_NEAREST),
        minFilter(FILTERMODE_NEAREST),
        mipFilter(FILTERMODE_NONE),
        convolution(PS3CONVOLUTION_QUINCUNX),
        color(RGBA(0xff, 0xff, 0xff, 0xff)),
        remap(PS3UNSIGNEDREMAP_NORMAL),
        depthTextureFunction(PS3DEPTHTEXTUREFUNCTION_ZFUNC_ALWAYS),
        gamma(PS3TEXTURE_GAMMA_NONE)
    { }






    void SetTexture(Texture *tex);
    void SetAddressU(AddressingMode addressMode);
    void SetAddressV(AddressingMode addressMode);
    void SetAddressW(AddressingMode addressMode);
    void SetMipMapLODBias(float32_t b);
    void SetMaxMipLevel(uint32_t level);
    void SetMinMipLevel(uint32_t level);
    void SetMaxAnisotropy(uint32_t maxAniso);
    void SetMagFilter(FilterMode filter);
    void SetMinFilter(FilterMode filter);
    void SetMipFilter(FilterMode filter);
    void SetBorderColor(RGBA color);

    void PS3SetURemap(PS3UnsignedRemap r);
    void PS3SetDepthTextureFunction(PS3DepthTextureFunction dtf);
    void PS3SetGamma(PS3TextureGamma gamma);
    void PS3SetConvolution(PS3Convolution convolution);

    Texture *GetTexture() const;
    AddressingMode GetAddressU() const;
    AddressingMode GetAddressV() const;
    AddressingMode GetAddressW() const;
    float32_t GetMipMapLODBias() const;
    uint32_t GetMaxMipLevel() const;
    uint32_t GetMinMipLevel() const;
    uint32_t GetMaxAnisotropy() const;
    FilterMode GetMagFilter() const;
    FilterMode GetMinFilter() const;
    FilterMode GetMipFilter() const;
    RGBA GetBorderColor() const;

    PS3UnsignedRemap PS3GetURemap() const;
    PS3DepthTextureFunction PS3GetDepthTextureFunction() const;
    PS3TextureGamma PS3GetGamma() const;
    PS3Convolution PS3GetConvolution() const;

protected:

    Texture *texture;
    AddressingMode addressU;
    AddressingMode addressV;
    AddressingMode addressW;
    float32_t bias;
    uint32_t maxLevel;
    uint32_t minLevel;
    uint32_t maxAnisotropy;
    FilterMode magFilter;
    FilterMode minFilter;
    FilterMode mipFilter;
    PS3Convolution convolution;
    RGBA color;
    PS3UnsignedRemap remap;
    PS3DepthTextureFunction depthTextureFunction;
    PS3TextureGamma gamma;

    friend class TextureState;
    friend uint32_t RwHash32StateParams( const TextureState::Parameters& stateParams );
};




inline void
TextureState::Parameters::SetTexture(Texture *tex)
{
    ;
    texture = tex;
    return;
}

inline void
TextureState::Parameters::SetAddressU(AddressingMode addressMode)
{
    ;
    addressU = addressMode;
    return;
}

inline void
TextureState::Parameters::SetAddressV(AddressingMode addressMode)
{
    ;
    addressV = addressMode;
    return;
}

inline void
TextureState::Parameters::SetAddressW(AddressingMode addressMode)
{
    ;
    addressW = addressMode;
    return;
}

inline void
TextureState::Parameters::SetMipMapLODBias(float32_t b)
{
    ;
    bias = b;
    return;
}

inline void
TextureState::Parameters::SetMaxMipLevel(uint32_t level)
{
    ;
    maxLevel = level;
    return;
}

inline void
TextureState::Parameters::SetMinMipLevel(uint32_t level)
{
    ;
    minLevel = level;
    return;
}

inline void
TextureState::Parameters::SetMaxAnisotropy(uint32_t maxAniso)
{
    ;
    maxAnisotropy = maxAniso;
    return;
}

inline void
TextureState::Parameters::SetMagFilter(FilterMode filter)
{
    ;
    magFilter = filter;
    return;
}

inline void
TextureState::Parameters::SetMinFilter(FilterMode filter)
{
    ;
    minFilter = filter;
    return;
}

inline void
TextureState::Parameters::SetMipFilter(FilterMode filter)
{
    ;
    mipFilter = filter;
    return;
}

inline void
TextureState::Parameters::SetBorderColor(RGBA c)
{
    ;
    color = c;
    return;
}

inline void
TextureState::Parameters::PS3SetURemap(PS3UnsignedRemap r)
{
    ;
    remap = r;
    return;
}

inline void
TextureState::Parameters::PS3SetDepthTextureFunction(PS3DepthTextureFunction dtf)
{
    ;
    depthTextureFunction = dtf;
    return;
}

inline void
TextureState::Parameters::PS3SetGamma(PS3TextureGamma _gamma)
{
    ;
    gamma = _gamma;
    return;
}

inline void
TextureState::Parameters::PS3SetConvolution(PS3Convolution conv)
{
    ;
    convolution = conv;
    return;
}

inline Texture *
TextureState::Parameters::GetTexture() const
{
    ;
    return texture;
}

inline TextureState::AddressingMode
TextureState::Parameters::GetAddressU() const
{
    ;
    return addressU;
}

inline TextureState::AddressingMode
TextureState::Parameters::GetAddressV() const
{
    ;
    return addressV;
}

inline TextureState::AddressingMode
TextureState::Parameters::GetAddressW() const
{
    ;
    return addressV;
}

inline float32_t
TextureState::Parameters::GetMipMapLODBias() const
{
    ;
    return bias;
}

inline uint32_t
TextureState::Parameters::GetMaxMipLevel() const
{
    ;
    return maxLevel;
}

inline uint32_t
TextureState::Parameters::GetMinMipLevel() const
{
    ;
    return minLevel;
}

inline uint32_t
TextureState::Parameters::GetMaxAnisotropy() const
{
    ;
    return maxAnisotropy;
}

inline TextureState::FilterMode
TextureState::Parameters::GetMagFilter() const
{
    ;
    return magFilter;
}

inline TextureState::FilterMode
TextureState::Parameters::GetMinFilter() const
{
    ;
    return minFilter;
}

inline TextureState::FilterMode
TextureState::Parameters::GetMipFilter() const
{
    ;
    return mipFilter;
}

inline rw::RGBA
TextureState::Parameters::GetBorderColor() const
{
    ;
    return color;
}

inline TextureState::PS3UnsignedRemap
TextureState::Parameters::PS3GetURemap() const
{
    ;
    return remap;
}

inline TextureState::PS3DepthTextureFunction
TextureState::Parameters::PS3GetDepthTextureFunction() const
{
    ;
    return depthTextureFunction;
}

inline TextureState::PS3TextureGamma
TextureState::Parameters::PS3GetGamma() const
{
    ;
    return gamma;
}


inline TextureState::PS3Convolution
TextureState::Parameters::PS3GetConvolution() const
{
    ;
    return convolution;
}





struct RenderTargetState::Parameters
{
    Parameters()
    {
        ;
        for (uint32_t target = 0 ; target < TARGETID_NUMTARGETS ; ++target)
        {
            targets[target] = 0;
        }
        return;
    }


    void SetTarget(TargetID id, PixelBuffer *pixelBuffer);
    PixelBuffer *GetTarget(TargetID id) const;


    PixelBuffer *targets[5];
};

inline void
RenderTargetState::Parameters::SetTarget(TargetID id, PixelBuffer *pixelBuffer)
{
    ;
    ;
    targets[id] = pixelBuffer;
    return;
}

inline PixelBuffer *
RenderTargetState::Parameters::GetTarget(TargetID id) const
{
    ;
    ;
    return targets[id];
}


inline void
RenderTargetState::PS3PrintCellGcmSurface(const CellGcmSurface *surface)
{
    ;

    ;
    ;
    ;
 ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;

    ;
    ;
    ;
    ;
    ;
    ;
    ;
    (void )surface;

    return;
}






struct BlendState::Parameters
{
    Parameters() :

        colorSource(INPUT_SRCALPHA),
        colorDestination(INPUT_INVSRCALPHA),
        colorOperation(OPERATION_ADD),
        factor(RGBA(255, 255, 255, 255)),
        alphaSource(INPUT_SRCALPHA),
        alphaDestination(INPUT_INVSRCALPHA),
        alphaOperation(OPERATION_ADD),




        alphaTestEnable(false),
        alphaTestFunction(FUNCTION_ALWAYS),
        alphaTestReference(0.0f),
        f16BlendColor(false)
    {
        blendEnable[0] = false;
        blendEnable[1] = false;
        blendEnable[2] = false;
        blendEnable[3] = false;

        colorRedMask[0] = true;
        colorRedMask[1] = true;
        colorRedMask[2] = true;
        colorRedMask[3] = true;

        colorGreenMask[0] = true;
        colorGreenMask[1] = true;
        colorGreenMask[2] = true;
        colorGreenMask[3] = true;

        colorBlueMask[0] = true;
        colorBlueMask[1] = true;
        colorBlueMask[2] = true;
        colorBlueMask[3] = true;

        colorAlphaMask[0] = true;
        colorAlphaMask[1] = true;
        colorAlphaMask[2] = true;
        colorAlphaMask[3] = true;
    }


    void SetBlendEnable(bool enable);
    void SetSource(RenderTargetState::TargetID id, Input src);
    void SetDestination(RenderTargetState::TargetID id, Input dest);
    void SetOperation(RenderTargetState::TargetID id, Operation op);
    void SetBlendFactor(RGBA color);
    void SetSourceAlpha(RenderTargetState::TargetID id, Input src);
    void SetDestinationAlpha(RenderTargetState::TargetID id, Input dest);
    void SetOperationAlpha(RenderTargetState::TargetID id, Operation op);
    void SetColorWriteEnable(RenderTargetState::TargetID id, bool red, bool green, bool blue, bool alpha);
    void SetAlphaTestEnable(bool enable);
    void SetAlphaTestFunction(Function func);
    void SetAlphaTestReference(uint32_t ref);

    bool GetBlendEnable() const;
    Input GetSource(RenderTargetState::TargetID id) const;
    Input GetDestination(RenderTargetState::TargetID id) const;
    Operation GetOperation(RenderTargetState::TargetID id) const;
    RGBA GetBlendFactor() const;
    Input GetSourceAlpha(RenderTargetState::TargetID id) const;
    Input GetDestinationAlpha(RenderTargetState::TargetID id) const;
    Operation GetOperationAlpha(RenderTargetState::TargetID id) const;
    void GetColorWriteEnable(RenderTargetState::TargetID id, bool &red, bool &green, bool &blue, bool &alpha);
    bool GetAlphaTestEnable() const;
    Function GetAlphaTestFunction() const;
    float32_t GetAlphaTestReference() const;




    void PS3SetBlendEnable(RenderTargetState::TargetID id, bool enable);
    bool PS3GetBlendEnable(RenderTargetState::TargetID id) const;


    void PS3SetEnableBlendFactorF16(bool enable);
    bool PS3GetEnableBlendFactorF16() const;

protected:


    bool blendEnable[4];

    Input colorSource;
    Input colorDestination;
    Operation colorOperation;

    RGBA factor;

    Input alphaSource;
    Input alphaDestination;
    Operation alphaOperation;

    bool colorRedMask[4];
    bool colorGreenMask[4];
    bool colorBlueMask[4];
    bool colorAlphaMask[4];

    bool alphaTestEnable;
    Function alphaTestFunction;
    float32_t alphaTestReference;

    bool f16BlendColor;

    friend class BlendState;
    friend uint32_t RwHash32StateParams( const BlendState::Parameters& stateParams );
};



inline void
BlendState::Parameters::SetBlendEnable(bool enable)
{
    ;
    blendEnable[0] = enable;
    return;
}

inline void
BlendState::Parameters::SetSource(RenderTargetState::TargetID , Input src)
{
    ;
    ;

    colorSource = src;
    return;
}

inline void
BlendState::Parameters::SetDestination(RenderTargetState::TargetID , Input dest)
{
    ;
    ;

    colorDestination = dest;
    return;
}

inline void
BlendState::Parameters::SetOperation(RenderTargetState::TargetID , Operation op)
{
    ;
    ;

    colorOperation = op;
    return;
}

inline void
BlendState::Parameters::SetBlendFactor(RGBA color)
{
    ;
    factor = color;
    return;
}

inline void
BlendState::Parameters::SetSourceAlpha(RenderTargetState::TargetID , Input src)
{
    ;
    ;

    alphaSource = src;
    return;
}

inline void
BlendState::Parameters::SetDestinationAlpha(RenderTargetState::TargetID , Input dest)
{
    ;
    ;

    alphaDestination = dest;
    return;
}

inline void
BlendState::Parameters::SetOperationAlpha(RenderTargetState::TargetID , Operation op)
{
    ;
    ;

    alphaOperation = op;
    return;
}

inline void
BlendState::Parameters::SetColorWriteEnable(RenderTargetState::TargetID id, bool red, bool green, bool blue, bool alpha)
{
    ;
    colorRedMask[id] = red;
    colorGreenMask[id] = green;
    colorBlueMask[id] = blue;
    colorAlphaMask[id] = alpha;
    return;
}

inline void
BlendState::Parameters::SetAlphaTestEnable(bool enable)
{
    ;
    alphaTestEnable = enable;
    return;
}

inline void
BlendState::Parameters::SetAlphaTestFunction(Function func)
{
    ;
    alphaTestFunction = func;
    return;
}

inline void
BlendState::Parameters::SetAlphaTestReference(uint32_t ref)
{
    ;
    alphaTestReference = (float32_t)(ref)/255.0f;
    return;
}

inline void
BlendState::Parameters::PS3SetBlendEnable(RenderTargetState::TargetID id, bool enable)
{
    ;
    blendEnable[id] = enable;
    return;
}

inline void
BlendState::Parameters::PS3SetEnableBlendFactorF16(bool enable)
{
    ;
    f16BlendColor = enable;
    return;
}

inline bool
BlendState::Parameters::GetBlendEnable() const
{
    ;
    return blendEnable[0];
}

inline BlendState::Input
BlendState::Parameters::GetSource(RenderTargetState::TargetID ) const
{
    ;
    return colorSource;
}

inline BlendState::Input
BlendState::Parameters::GetDestination(RenderTargetState::TargetID ) const
{
    ;
    return colorDestination;
}

inline BlendState::Operation
BlendState::Parameters::GetOperation(RenderTargetState::TargetID ) const
{
    ;
    return colorOperation;
}

inline rw::RGBA
BlendState::Parameters::GetBlendFactor() const
{
    ;
    return factor;
}

inline BlendState::Input
BlendState::Parameters::GetSourceAlpha(RenderTargetState::TargetID ) const
{
    ;
    return alphaSource;
}

inline BlendState::Input
BlendState::Parameters::GetDestinationAlpha(RenderTargetState::TargetID ) const
{
    ;
    return alphaDestination;
}

inline BlendState::Operation
BlendState::Parameters::GetOperationAlpha(RenderTargetState::TargetID ) const
{
    ;
    return alphaOperation;
}

inline void
BlendState::Parameters::GetColorWriteEnable(RenderTargetState::TargetID id, bool &red, bool &green, bool &blue, bool &alpha)
{
    ;
    red = colorRedMask[id];
    green = colorGreenMask[id];
    blue = colorBlueMask[id];
    alpha = colorAlphaMask[id];
    return;
}

inline bool
BlendState::Parameters::GetAlphaTestEnable() const
{
    ;
    return alphaTestEnable;
}

inline BlendState::Function
BlendState::Parameters::GetAlphaTestFunction() const
{
    ;
    return alphaTestFunction;
}

inline float32_t
BlendState::Parameters::GetAlphaTestReference() const
{
    ;
    return alphaTestReference;
}

inline bool
BlendState::Parameters::PS3GetBlendEnable(RenderTargetState::TargetID id) const
{
    ;
    return blendEnable[id];
}

inline bool
BlendState::Parameters::PS3GetEnableBlendFactorF16() const
{
    ;
    return f16BlendColor;
}





struct DepthStencilState::Parameters
{
    Parameters() :
        depthEnable(true),
        depthFunction(FUNCTION_LESSEQUAL),
        depthWriteEnable(true),
        stencilEnable(false),
        stencilFunction(FUNCTION_ALWAYS),
        stencilReference(0x0),
        stencilMask(0x0),
        stencilWriteMask(0x0),
        stencilFailOperation(STENCILOPERATION_KEEP),
        stencilZFailOperation(STENCILOPERATION_KEEP),
        stencilPassOperation(STENCILOPERATION_KEEP),
        backStencilFunction(FUNCTION_ALWAYS),
        backStencilReference(0x0),
        backStencilMask(0x0),
        backStencilWriteMask(0x0),
        backStencilFailOperation(STENCILOPERATION_KEEP),
        backStencilZFailOperation(STENCILOPERATION_KEEP),
        backStencilPassOperation(STENCILOPERATION_KEEP),
        twoSideStencilEnable(false)
    { }


    void SetDepthEnable(bool enable);
    void SetDepthFunction(Function function);
    void SetDepthWriteEnable(bool enable);

    void SetStencilEnable(bool enable);
    void SetStencilFunction(Function function);
    void SetStencilReference(uint32_t reference);
    void SetStencilMask(uint32_t mask);
    void SetStencilWriteMask(uint32_t mask);
    void SetStencilFailOperation(StencilOperation operation);
    void SetStencilZFailOperation(StencilOperation operation);
    void SetStencilPassOperation(StencilOperation operation);

    void SetBackStencilFunction(Function function);
    void SetBackStencilReference(uint32_t reference);
    void SetBackStencilMask(uint32_t mask);
    void SetBackStencilWriteMask(uint32_t mask);
    void SetBackStencilFailOperation(StencilOperation operation);
    void SetBackStencilZFailOperation(StencilOperation operation);
    void SetBackStencilPassOperation(StencilOperation operation);

    void SetTwoSidedStencilEnable(bool enable);

    bool GetDepthEnable() const;
    Function GetDepthFunction() const;
    bool GetDepthWriteEnable() const;

    bool GetStencilEnable() const;
    Function GetStencilFunction() const;
    uint32_t GetStencilReference() const;
    uint32_t GetStencilMask() const;
    uint32_t GetStencilWriteMask() const;
    StencilOperation GetStencilFailOperation() const;
    StencilOperation GetStencilZFailOperation() const;
    StencilOperation GetStencilPassOperation() const;
    Function GetBackStencilFunction() const;
    uint32_t GetBackStencilReference() const;
    uint32_t GetBackStencilMask() const;
    uint32_t GetBackStencilWriteMask() const;
    StencilOperation GetBackStencilFailOperation() const;
    StencilOperation GetBackStencilZFailOperation() const;
    StencilOperation GetBackStencilPassOperation() const;
    bool GetTwoSidedStencilEnable() const;



    bool depthEnable;
    Function depthFunction;
    bool depthWriteEnable;


    bool stencilEnable;
    Function stencilFunction;
    uint32_t stencilReference;
    uint32_t stencilMask;
    uint32_t stencilWriteMask;

    StencilOperation stencilFailOperation;
    StencilOperation stencilZFailOperation;
    StencilOperation stencilPassOperation;


    Function backStencilFunction;
    uint32_t backStencilReference;
    uint32_t backStencilMask;
    uint32_t backStencilWriteMask;

    StencilOperation backStencilFailOperation;
    StencilOperation backStencilZFailOperation;
    StencilOperation backStencilPassOperation;

    bool twoSideStencilEnable;

    friend class DepthStencilState;
    friend uint32_t RwHash32StateParams( const DepthStencilState::Parameters& stateParams );
};



inline void
DepthStencilState::Parameters::SetDepthEnable(bool enable)
{
    ;
    depthEnable = enable;
    return;
}

inline void
DepthStencilState::Parameters::SetDepthFunction(Function function)
{
    ;
    depthFunction = function;
    return;
}

inline void
DepthStencilState::Parameters::SetDepthWriteEnable(bool enable)
{
    ;
    depthWriteEnable = enable;
    return;
}

inline void
DepthStencilState::Parameters::SetStencilEnable(bool enable)
{
    ;
    stencilEnable = enable;
    return;
}

inline void
DepthStencilState::Parameters::SetStencilFunction(Function function)
{
    ;
    stencilFunction = function;
    return;
}

inline void
DepthStencilState::Parameters::SetStencilReference(uint32_t reference)
{
    ;
    stencilReference = reference;
    return;
}

inline void
DepthStencilState::Parameters::SetStencilMask(uint32_t mask)
{
    ;
    stencilMask = mask;
    return;
}

inline void
DepthStencilState::Parameters::SetStencilWriteMask(uint32_t mask)
{
    ;
    stencilWriteMask = mask;
    return;
}

inline void
DepthStencilState::Parameters::SetStencilFailOperation(StencilOperation operation)
{
    ;
    stencilFailOperation = operation;
    return;
}

inline void
DepthStencilState::Parameters::SetStencilZFailOperation(StencilOperation operation)
{
    ;
    stencilZFailOperation = operation;
    return;
}

inline void
DepthStencilState::Parameters::SetStencilPassOperation(StencilOperation operation)
{
    ;
    stencilPassOperation = operation;
    return;
}



inline void
DepthStencilState::Parameters::SetBackStencilFunction(Function function)
{
    ;
    backStencilFunction = function;
    return;
}

inline void
DepthStencilState::Parameters::SetBackStencilReference(uint32_t reference)
{
    ;
    backStencilReference = reference;
    return;
}

inline void
DepthStencilState::Parameters::SetBackStencilMask(uint32_t mask)
{
    ;
    backStencilMask = mask;
    return;
}

inline void
DepthStencilState::Parameters::SetBackStencilWriteMask(uint32_t mask)
{
    ;
    backStencilWriteMask = mask;
    return;
}

inline void
DepthStencilState::Parameters::SetBackStencilFailOperation(StencilOperation operation)
{
    ;
    backStencilFailOperation = operation;
    return;
}

inline void
DepthStencilState::Parameters::SetBackStencilZFailOperation(StencilOperation operation)
{
    ;
    backStencilZFailOperation = operation;
    return;
}

inline void
DepthStencilState::Parameters::SetBackStencilPassOperation(StencilOperation operation)
{
    ;
    backStencilPassOperation = operation;
    return;
}

inline void
DepthStencilState::Parameters::SetTwoSidedStencilEnable(bool enable)
{
    ;
    twoSideStencilEnable = enable;
    return;
}

inline bool
DepthStencilState::Parameters::GetDepthEnable() const
{
    ;
    return depthEnable;
}

inline DepthStencilState::Function
DepthStencilState::Parameters::GetDepthFunction() const
{
    ;
    return depthFunction;
}

inline bool
DepthStencilState::Parameters::GetDepthWriteEnable() const
{
    ;
    return depthWriteEnable;
}

inline bool
DepthStencilState::Parameters::GetStencilEnable() const
{
    ;
    return stencilEnable;
}

inline DepthStencilState::Function
DepthStencilState::Parameters::GetStencilFunction() const
{
    ;
    return stencilFunction;
}

inline uint32_t
DepthStencilState::Parameters::GetStencilReference() const
{
    ;
    return stencilReference;
}

inline uint32_t
DepthStencilState::Parameters::GetStencilMask() const
{
    ;
    return stencilMask;
}

inline uint32_t
DepthStencilState::Parameters::GetStencilWriteMask() const
{
    ;
    return stencilWriteMask;
}

inline DepthStencilState::StencilOperation
DepthStencilState::Parameters::GetStencilFailOperation() const
{
    ;
    return stencilFailOperation;
}

inline DepthStencilState::StencilOperation
DepthStencilState::Parameters::GetStencilZFailOperation() const
{
    ;
    return stencilZFailOperation;
}

inline DepthStencilState::StencilOperation
DepthStencilState::Parameters::GetStencilPassOperation() const
{
    ;
    return stencilPassOperation;
}



inline DepthStencilState::Function
DepthStencilState::Parameters::GetBackStencilFunction() const
{
    ;
    return backStencilFunction;
}

inline uint32_t
DepthStencilState::Parameters::GetBackStencilReference() const
{
    ;
    return backStencilReference;
}

inline uint32_t
DepthStencilState::Parameters::GetBackStencilMask() const
{
    ;
    return backStencilMask;
}

inline uint32_t
DepthStencilState::Parameters::GetBackStencilWriteMask() const
{
    ;
    return backStencilWriteMask;
}

inline DepthStencilState::StencilOperation
DepthStencilState::Parameters::GetBackStencilFailOperation() const
{
    ;
    return backStencilFailOperation;
}

inline DepthStencilState::StencilOperation
DepthStencilState::Parameters::GetBackStencilZFailOperation() const
{
    ;
    return backStencilZFailOperation;
}

inline DepthStencilState::StencilOperation
DepthStencilState::Parameters::GetBackStencilPassOperation() const
{
    ;
    return backStencilPassOperation;
}

inline bool
DepthStencilState::Parameters::GetTwoSidedStencilEnable() const
{
    ;
    return twoSideStencilEnable;
}





struct RasterizerState::Parameters
{
    Parameters() :
        fillModeFront(FILLMODE_SOLID),
        fillModeBack(FILLMODE_SOLID),
        cullMode(CULLMODE_BACK),
        offsetFactor(0.0f),
        offsetUnits(0.0f),
        primitiveResetIndex(0xffff),
        frontFace(PS3FRONTFACE_CCW),
        shadeMode(PS3SHADEMODE_SMOOTH),
        scissorTestEnable(false),
        primitiveResetEnable(true)
    { }


    void SetFillMode(FillMode fillMode);
    void SetCullMode(CullMode cm);
    void SetDepthBias(float32_t b);
    void SetSlopeScaleDepthBias(float32_t s);
    void SetScissorTestEnable(bool enable);
    void SetPrimitiveResetEnable(bool enable);
    void SetPrimitiveResetIndex(uint32_t index);

    void PS3SetFillModeBack(FillMode fillmode);
    void PS3SetShadeMode(PS3ShadeMode sm);
    void PS3SetFrontFace(PS3FrontFace ff);

    FillMode GetFillMode() const;
    CullMode GetCullMode() const;
    float32_t GetDepthBias() const;
    float32_t GetSlopeScaleDepthBias() const;
    bool GetScissorTestEnable() const;
    bool GetPrimitiveResetEnable() const;
    uint32_t GetPrimitiveResetIndex() const;

    PS3FrontFace PS3GetFrontFace() const;
    PS3ShadeMode PS3GetShadeMode() const;

protected:

    friend class RasterizerState;
    friend uint32_t RwHash32StateParams( const RasterizerState::Parameters& stateParams );

    FillMode fillModeFront;
    FillMode fillModeBack;
    CullMode cullMode;
    float32_t offsetFactor;
    float32_t offsetUnits;
    uint32_t primitiveResetIndex;
    PS3FrontFace frontFace;
    PS3ShadeMode shadeMode;
    bool scissorTestEnable;
    bool primitiveResetEnable;
};

inline void
RasterizerState::Parameters::SetFillMode(FillMode fm)
{
    ;
    fillModeFront = fillModeBack = fm;
    return;
}

inline void
RasterizerState::Parameters::SetCullMode(CullMode cm)
{
    ;
    cullMode = cm;
    return;
}

inline void
RasterizerState::Parameters::SetDepthBias(float32_t b)
{
    ;
    offsetUnits = b;
    return;
}

inline void
RasterizerState::Parameters::SetSlopeScaleDepthBias(float32_t s)
{
    ;
    offsetFactor = s;
    return;
}

inline void
RasterizerState::Parameters::SetScissorTestEnable(bool enable)
{
    ;
    scissorTestEnable = enable;
    return;
}

inline void
RasterizerState::Parameters::SetPrimitiveResetEnable(bool enable)
{
    ;
    primitiveResetEnable = enable;
    return;
}

inline void
RasterizerState::Parameters::SetPrimitiveResetIndex(uint32_t index)
{
    ;
    primitiveResetIndex = index;
    return;
}

inline void
RasterizerState::Parameters::PS3SetFillModeBack(FillMode fm)
{
    ;
    fillModeBack = fm;
    return;
}

inline void
RasterizerState::Parameters::PS3SetShadeMode(PS3ShadeMode sm)
{
    ;
    shadeMode = sm;
    return;
}

inline void
RasterizerState::Parameters::PS3SetFrontFace(PS3FrontFace ff)
{
    ;
    frontFace = ff;
    return;
}

inline RasterizerState::CullMode
RasterizerState::Parameters::GetCullMode() const
{
    ;
    return cullMode;
}

inline float32_t
RasterizerState::Parameters::GetDepthBias() const
{
    ;
    return offsetUnits;
}

inline float32_t
RasterizerState::Parameters::GetSlopeScaleDepthBias() const
{
    ;
    return offsetFactor;
}

inline bool
RasterizerState::Parameters::GetScissorTestEnable() const
{
    ;
    return scissorTestEnable;
}

inline bool
RasterizerState::Parameters::GetPrimitiveResetEnable() const
{
    ;
    return primitiveResetEnable;
}

inline uint32_t
RasterizerState::Parameters::GetPrimitiveResetIndex() const
{
    ;
    return primitiveResetIndex;
}


inline RasterizerState::PS3FrontFace
RasterizerState::Parameters::PS3GetFrontFace() const
{
    ;
    return frontFace;
}

inline RasterizerState::PS3ShadeMode
RasterizerState::Parameters::PS3GetShadeMode() const
{
    ;
    return shadeMode;
}





template <typename T>
inline uint32_t
RwHash32StateParams( const T& stateParams )
{
    return RwHash32Buffer( reinterpret_cast<const uint8_t*>(&stateParams), sizeof(T), RWHASH32_INIT );
}

inline uint32_t
RwHash32StateParams( const TextureState::Parameters& stateParams )
{
    uint32_t hash = RWHASH32_INIT;

    hash = RwHash32UInt32( (rw::HostPtr )stateParams.texture, hash);

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.addressU), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.addressV), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.addressW), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.bias), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.maxLevel), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.minLevel), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.maxAnisotropy), hash);

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.magFilter), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.minFilter), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.mipFilter), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.convolution), hash);

    hash = RwHash32UInt32( *reinterpret_cast<const uint32_t*>(&stateParams.color), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.remap), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.depthTextureFunction), hash);

    return hash;
}

inline uint32_t
RwHash32StateParams( const DepthStencilState::Parameters& stateParams )
{
    uint32_t hash = RWHASH32_INIT;

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.depthEnable), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.depthFunction), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.depthWriteEnable), hash);

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.stencilEnable), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.stencilFunction), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.stencilReference), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.stencilMask), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.stencilWriteMask), hash);

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.stencilFailOperation), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.stencilZFailOperation), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.stencilPassOperation), hash);

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.twoSideStencilEnable), hash);

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.backStencilFunction), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.backStencilReference), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.backStencilMask), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.backStencilWriteMask), hash);

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.backStencilFailOperation), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.backStencilZFailOperation), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.backStencilPassOperation), hash);

    return hash;
}

inline uint32_t
RwHash32StateParams( const BlendState::Parameters& stateParams )
{
    uint32_t hash = RWHASH32_INIT;

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.blendEnable[0]), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.blendEnable[1]), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.blendEnable[2]), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.blendEnable[3]), hash);

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.colorSource), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.colorDestination), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.colorOperation), hash);
    hash = RwHash32UInt32( *reinterpret_cast<const uint32_t *>(&stateParams.factor), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.alphaSource), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.alphaDestination), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.alphaOperation), hash);

    for( uint32_t n = 0; n < 4; ++n )
    {
        hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.colorRedMask[n]), hash);
        hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.colorGreenMask[n]), hash);
        hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.colorBlueMask[n]), hash);
        hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.colorAlphaMask[n]), hash);
    }
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.alphaTestEnable), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.alphaTestFunction), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.alphaTestReference), hash);

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.f16BlendColor), hash);

    return hash;
}

inline uint32_t
RwHash32StateParams( const RasterizerState::Parameters& stateParams )
{
    uint32_t hash = RWHASH32_INIT;

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.cullMode), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.offsetUnits), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.offsetFactor), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.scissorTestEnable), hash);

    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.frontFace), hash);
    hash = RwHash32UInt32( static_cast<uint32_t>(stateParams.shadeMode), hash);
    return hash;
}



}
}
}
