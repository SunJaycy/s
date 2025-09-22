
















namespace rw
{
namespace graphics
{
namespace core
{
























class StateBuffer;





struct DrawParameters
{


    void SetStartVertex(uint32_t start);
    void SetVertexCount(uint32_t count);

    uint32_t GetStartVertex() const;
    uint32_t GetVertexCount() const;

    void SetPrimitiveType(PrimitiveType primType);
    PrimitiveType GetPrimitiveType() const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;




    uint32_t m_startVertex;
    uint32_t m_vertexCount;
    uint8_t m_primitiveType;

};



inline void
DrawParameters::SetStartVertex(uint32_t start)
{
    ;
    m_startVertex = start;
    return;
}

inline void
DrawParameters::SetVertexCount(uint32_t count)
{
    ;
    m_vertexCount = count;
    return;
}

inline void
DrawParameters::SetPrimitiveType(PrimitiveType primType)
{
    ;
    m_primitiveType = (uint8_t )primType;
    return;
}

inline uint32_t
DrawParameters::GetStartVertex() const
{
    ;
    return m_startVertex;
}

inline uint32_t
DrawParameters::GetVertexCount() const
{
    ;
    return m_vertexCount;
}

inline PrimitiveType
DrawParameters::GetPrimitiveType() const
{
    ;
    return (PrimitiveType )m_primitiveType;
}






namespace CgsResource
{
    class RwDrawIndParamResourceType;
}

struct DrawIndexedParameters
{

friend class CgsResource::RwDrawIndParamResourceType;


    void SetBaseVertexIndex(uint32_t base);
    void SetMinVertexIndex(uint32_t minv);
    void SetMaxVertexIndex(uint32_t maxv);

    void SetStartIndex(uint32_t start);
    void SetIndexCount(uint32_t count);
    void SetPrimitiveType(PrimitiveType primType);
    void SetPrimitiveCount(uint32_t count);

    uint32_t GetBaseVertexIndex() const;
    uint32_t GetMinVertexIndex() const;
    uint32_t GetMaxVertexIndex() const;

    uint32_t GetStartIndex() const;
    uint32_t GetIndexCount() const;
    PrimitiveType GetPrimitiveType() const;
    uint32_t GetPrimitiveCount() const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;


    uint32_t m_startIndex;
    uint32_t m_indexCount;

    uint8_t m_primitiveType;

};



inline void
DrawIndexedParameters::SetBaseVertexIndex(uint32_t )
{
    ;
    return;
}

inline void
DrawIndexedParameters::SetMinVertexIndex(uint32_t )
{
    ;
    return;
}

inline void
DrawIndexedParameters::SetMaxVertexIndex(uint32_t )
{
    ;
    return;
}


inline void
DrawIndexedParameters::SetStartIndex(uint32_t start)
{
    ;
    m_startIndex = start;
    return;
}

inline void
DrawIndexedParameters::SetIndexCount(uint32_t count)
{
    ;
    m_indexCount = count;
    return;
}

inline void
DrawIndexedParameters::SetPrimitiveType(PrimitiveType primType)
{
    ;
    m_primitiveType = (uint8_t )primType;
    return;
}

inline uint32_t
DrawIndexedParameters::GetBaseVertexIndex() const
{
    ;
    return 0;
}

inline uint32_t
DrawIndexedParameters::GetMinVertexIndex() const
{
    ;
    return 0;
}

inline uint32_t
DrawIndexedParameters::GetMaxVertexIndex() const
{
    ;
    return 0;
}


inline uint32_t
DrawIndexedParameters::GetStartIndex() const
{
    ;
    return m_startIndex;
}

inline uint32_t
DrawIndexedParameters::GetIndexCount() const
{
    ;
    return m_indexCount;
}

inline PrimitiveType
DrawIndexedParameters::GetPrimitiveType() const
{
    ;
    return (PrimitiveType )m_primitiveType;
}





struct ClearColorParameters
{
    ClearColorParameters() :
        m_color(0xff000000)
    { }


    void SetColor(const RGBA32 &rgba);
    RGBA32 GetColor() const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;






    uint32_t m_color;
};

inline void
ClearColorParameters::SetColor(const RGBA32 &rgba)
{
    ;
    m_color =
        ((uint32_t )(rgba.Red() * 255.0f) << 16) |
        ((uint32_t )(rgba.Green() * 255.0f) << 8) |
        ((uint32_t )(rgba.Blue() * 255.0f) ) |
        ((uint32_t )(rgba.Alpha() * 255.0f) << 24);
    return;
}

inline RGBA32
ClearColorParameters::GetColor() const
{
    ;
    return RGBA32((float32_t )((m_color >> 16) ) / 255.0f, (float32_t )((m_color >> 8) & 0xff) / 255.0f, (float32_t )((m_color ) & 0xff) / 255.0f, (float32_t )((m_color >> 24) & 0xff) / 255.0f);



}
















struct ViewportParameters
{

    ViewportParameters() :
        m_x(0),
        m_y(0),
        m_w(0),
        m_h(0),
        m_minDepth(0.0f),
        m_maxDepth(1.0f)
    { }

    ViewportParameters(const PixelBuffer& pixelBuffer, float32_t minDepth = 0.0f, float32_t maxDepth = 1.0f) :
        m_x(0),
        m_y(0),
        m_w(pixelBuffer.GetWidth()),
        m_h(pixelBuffer.GetHeight()),
        m_minDepth(minDepth),
        m_maxDepth(maxDepth)
    { }

    void SetRectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h);
    void SetZRange(float32_t minDepth, float32_t maxDepth);

    void GetRectangle(uint32_t &x, uint32_t &y, uint32_t &w, uint32_t &h) const;
    void GetZRange(float32_t &minDepth, float32_t &maxDepth) const;

    void EndianSwap();


    uint32_t m_x;
    uint32_t m_y;
    uint32_t m_w;
    uint32_t m_h;
    float32_t m_minDepth;
    float32_t m_maxDepth;
};

inline void
ViewportParameters::SetRectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
}

inline void
ViewportParameters::SetZRange(float32_t minDepth, float32_t maxDepth)
{
    m_minDepth = minDepth;
    m_maxDepth = maxDepth;
}

inline void
ViewportParameters::GetRectangle(uint32_t &x, uint32_t &y, uint32_t &w, uint32_t &h) const
{
    x = m_x;
    y = m_y;
    w = m_w;
    h = m_h;
}

inline void
ViewportParameters::GetZRange(float32_t &minDepth, float32_t &maxDepth) const
{
    minDepth = m_minDepth;
    maxDepth = m_maxDepth;
}

inline void
ViewportParameters::EndianSwap()
{
    rw::EndianSwap(m_x);
    rw::EndianSwap(m_y);
    rw::EndianSwap(m_w);
    rw::EndianSwap(m_h);
    rw::EndianSwap(m_minDepth);
    rw::EndianSwap(m_maxDepth);
}






struct ScissorRectParameters
{

    ScissorRectParameters() :
        m_x(0),
        m_y(0),
        m_w(0),
        m_h(0)
    { }

    ScissorRectParameters(const PixelBuffer& pixelBuffer) :
        m_x(0),
        m_y(0),
        m_w(pixelBuffer.GetWidth()),
        m_h(pixelBuffer.GetHeight())
    { }

    void SetRectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h);
    void GetRectangle(uint32_t &x, uint32_t &y, uint32_t &w, uint32_t &h) const;
    void EndianSwap();


    uint32_t m_x;
    uint32_t m_y;
    uint32_t m_w;
    uint32_t m_h;
};

inline void
ScissorRectParameters::SetRectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
}

inline void
ScissorRectParameters::GetRectangle(uint32_t &x, uint32_t &y, uint32_t &w, uint32_t &h) const
{
    x = m_x;
    y = m_y;
    w = m_w;
    h = m_h;
}

inline void
ScissorRectParameters::EndianSwap()
{
    rw::EndianSwap(m_x);
    rw::EndianSwap(m_y);
    rw::EndianSwap(m_w);
    rw::EndianSwap(m_h);
}






struct ClearDepthStencilParameters
{
    ClearDepthStencilParameters() :
        m_clearFlags(CLEARFLAGS_Z | CLEARFLAGS_S),
        m_value(0xffffff00)
    { }


    void SetEnableClearDepth(bool enable);
    void SetEnableClearStencil(bool enable);

    void SetDepth(float32_t depth);
    void SetStencil(uint32_t stencil);

    bool GetEnableClearDepth() const;
    bool GetEnableClearStencil() const;

    float32_t GetDepth() const;
    uint32_t GetStencil() const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;






    uint32_t m_clearFlags;
    uint32_t m_value;
};

inline void
ClearDepthStencilParameters::SetEnableClearDepth(bool enable)
{
    ;
    if (enable)
    {
        m_clearFlags |= CLEARFLAGS_Z;
    }
    else
    {
        m_clearFlags &= ~CLEARFLAGS_Z;
    }
    return;
}

inline void
ClearDepthStencilParameters::SetEnableClearStencil(bool enable)
{
    ;
    if (enable)
    {
        m_clearFlags |= CLEARFLAGS_S;
    }
    else
    {
        m_clearFlags &= ~CLEARFLAGS_S;
    }
    return;
}

inline void
ClearDepthStencilParameters::SetDepth(float32_t depth)
{
    ;

    m_value = (m_value & 0xff) | ((uint32_t )(depth * (float32_t )0xffffff) << 8);
    return;
}

inline void
ClearDepthStencilParameters::SetStencil(uint32_t stencil)
{
    ;
    m_value = (m_value & 0xffffff00) | (uint8_t )stencil;
    return;
}

















class FloatShaderStateIterator
{
public:

    static const ProgramVariableHandle::DataType m_dataType = ProgramVariableHandle::DATATYPE_FLOAT;


    inline void
    Write(const rw::math::Vector4 &value)
    {
        ;
        ;
        *m_dest = value;
        ++m_dest;
        ;
        return;
    }

    inline void
    Write(const rw::math::Matrix44 &value)
    {
        ;
        ;
        *reinterpret_cast<rw::math::Matrix44 *>(m_dest) = value;
        m_dest += 4;




        return;
    }

    inline void
    Write(const rw::math::Vector4 *values, uint32_t numValues)
    {
        ;
        ;
        ;
        do
        {
            *m_dest = *values;
            ++values;
            ++m_dest;
            ;
        } while(--numValues);
        return;
    }

    inline void
    Write(const rw::math::Matrix44AffinePacked &value)
    {
        ;
        ;
        ;
        Write(reinterpret_cast<const rw::math::Vector4 *>(&value), 3);
        return;
    }

    inline void
    Increment(uint32_t numConstants = 1)
    {
        ;
        m_dest += numConstants;




        return;
    }

    void Write(rw::math::fpu::Vector4::InParam value);
    void Write(rw::math::fpu::Matrix44::InParam value);
    void Write(const rw::math::fpu::Vector4 *values, uint32_t numValues);


    rw::math::Vector4 *m_dest;
    ProgramVariableHandle m_handle;




    friend class rw::graphics::core::Device;
    friend class rw::graphics::core::ProgramVariableBuffer;
};

inline void
FloatShaderStateIterator::Write(rw::math::fpu::Vector4::InParam value)
{
    ;
    ;




    *reinterpret_cast<rw::math::fpu::Vector4 *>(m_dest) = value;
    m_dest += 1;
    return;
}

inline void
FloatShaderStateIterator::Write(rw::math::fpu::Matrix44::InParam value)
{
    ;
    ;




    *reinterpret_cast<rw::math::fpu::Matrix44 *>(m_dest) = value;
    m_dest += 4;
    return;
}

inline void
FloatShaderStateIterator::Write(const rw::math::fpu::Vector4 *values, uint32_t numValues)
{
    ;
    ;
    ;




    do
    {
        *reinterpret_cast<rw::math::fpu::Vector4 *>(m_dest) = values[0];
        numValues -= 1;
        m_dest += 1;
        values += 1;
    }
    while (numValues);
    return;
}






























































































































































class Device
{
public:

    enum State
    {
        STATE_NA = -1,

        STATE_COLD = 0,
        STATE_INITIALIZE = 1,
        STATE_START = 2,

        STATE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };





    struct Parameters
    {
        enum DisplayType
        {
            DISPLAYTYPE_NTSC = 0,
            DISPLAYTYPE_PAL_50,
            DISPLAYTYPE_PAL_60,
            DISPLAYTYPE_HDTV_480I,
            DISPLAYTYPE_HDTV_480P,
            DISPLAYTYPE_HDTV_576I,
            DISPLAYTYPE_HDTV_576P,
            DISPLAYTYPE_HDTV_720P,
            DISPLAYTYPE_HDTV_1080I,
            DISPLAYTYPE_HDTV_1080P,

            DISPLAYTYPE_DEFAULT = DISPLAYTYPE_HDTV_720P
        };




        enum PS3ScanFormat
        {
            PS3SCANFORMAT_X8R8G8B8 = (1),
            PS3SCANFORMAT_X8B8G8R8 = (2),
            PS3SCANFORMAT_R16G16B16X16_FLOAT = (3),

            PS3SCANFORMAT_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
        };

        Parameters(DisplayType displayType = DISPLAYTYPE_DEFAULT) :
            cmdSize(512 << 10),
            ioSize(64 << 20),
            ioAddress(0),
            mode(static_cast<uint8_t>(displayType)),
            scanFormat(PS3SCANFORMAT_X8R8G8B8),
            colorFormat(PIXELFORMAT_LIN_A8R8G8B8),
            depthStencilFormat(PIXELFORMAT_LIN_D24S8),
            depthStencilAutoCreate(true),
            numFramesToBuffer(2),
            numVsyncs(1),
            immediateFlipEnable(false),
            directDrawBufferSize(512*1024),
            directDrawNumSubBuffers(4)
        {
            ;
            PS3SetDimensions();
            return;
        }

        bool Validate() const;

       void SetBackBufferWidth(uint32_t width);
     void SetBackBufferHeight(uint32_t height);
     void SetBackBufferFormat(PixelFormat format);

     void SetFrontBufferWidth(uint32_t width);
     void SetFrontBufferHeight(uint32_t height);
     void SetFrontBufferFormat(PixelFormat format);

     void SetDepthStencilBufferFormat(PixelFormat format);
     void SetAutoCreateDepthStencil(bool enable);

     void SetNumFramesToBuffer(uint32_t frames);
     void SetNumVSyncToWait(uint32_t vsyncs);

     uint32_t GetBackBufferWidth() const;
     uint32_t GetBackBufferHeight() const;
     PixelFormat GetBackBufferFormat() const;

        uint32_t GetFrontBufferWidth() const;
     uint32_t GetFrontBufferHeight() const;
     PixelFormat GetFrontBufferFormat() const;

        PixelFormat GetDepthStencilBufferFormat() const;
     bool GetAutoCreateDepthStencil() const;

        uint32_t GetNumFramesToBuffer() const;
     uint32_t GetNumVSyncToWait() const;


        void PS3SetCommandBufferSize(uint32_t size);
        void PS3SetGraphicsSystemMemoryBuffer(void *buffer);
        void PS3SetGraphicsSystemMemorySize(uint32_t size);
        void PS3SetDirectDrawBufferSize(uint32_t bufferSize);
        void PS3SetDirectDrawNumSubBuffers(uint32_t numSubBuffers);
        void PS3SetImmediateFlipEnable(bool enable);

        void PS3SetMultiSampleType(uint32_t multiSampleType);

        uint32_t PS3GetCommandBufferSize() const;
        uint32_t PS3GetMultiSampleType() const;

    protected:

        void PS3SetDimensions();


        struct PS3ModeInformation
        {
            uint32_t xResolution;
            uint32_t yResolution;
            uint32_t resolutionId;
        };

        static const PS3ModeInformation m_modeInformation[];


        uint32_t cmdSize;
        uint32_t ioSize;
        void *ioAddress;

        uint8_t mode;
        PS3ScanFormat scanFormat;

        PixelFormat colorFormat;
        PixelFormat depthStencilFormat;
        bool depthStencilAutoCreate;

        uint32_t width;
        uint32_t height;
        uint32_t resolutionId;

        uint32_t numFramesToBuffer;
        uint32_t numVsyncs;
        bool immediateFlipEnable;

        uint32_t directDrawBufferSize;
        uint32_t directDrawNumSubBuffers;

        friend class Device;
    };





    class DirectDraw
    {
    public:

        static const uint32_t VertexAlignment = 16;

        static uint32_t GetMinVerticesBatch(const VertexDescriptor *vd);
        static uint32_t GetMaxVerticesBatch(const VertexDescriptor *vd);

        class Parameters
        {
        public:
            Parameters() :
                m_vertexDescriptor(0),
                m_primitiveType(PRIMITIVETYPE_NA)
            { }

            void SetVertexDescriptor(const VertexDescriptor *vd);
            const VertexDescriptor *GetVertexDescriptor() const;

            void SetPrimitiveType(PrimitiveType primType);
            PrimitiveType GetPrimitiveType() const;

        protected:

            const VertexDescriptor *m_vertexDescriptor;
            PrimitiveType m_primitiveType;

            friend class rw::graphics::core::Device;
        };

        class BatchIterator
        {
        public:
            template <class VI> bool BeginBatch(uint32_t numVertices, VI & vertexIterator);
            template <class VI> void EndBatch(VI & );
        };

        static bool PS3Initialize(uint32_t bufferSize, uint32_t numSubBuffers);
        static void PS3Release();

    protected:


        static uint32_t m_bufferSize;
        static uint32_t m_maxBatchSize;
        static uint32_t m_currentBufferPut;

        static const uint8_t m_label;
        static uint32_t m_currentLabelIndex;

        static rw::Resource m_vbRes;
        static rw::Resource m_msRes;

        static VertexBuffer *m_vertexBuffer;
        static MeshState *m_meshState;

        static uint32_t m_numSegments;
        static uint32_t m_activeSegment;

        static VertexBuffer::Parameters m_vbParameters;
        static MeshState::Parameters m_msParameters;
        static DrawParameters m_drawParameters;

        friend class rw::graphics::core::Device;
    };




    static const uint32_t MaxTextureStates = 16;
    static const uint32_t NumTiledRegions = 8;
    static const uint32_t NumDisplayBuffers = 8;
    static const uint32_t NumShaderConstants = 468;
    static const uint32_t NumConditionalRenderIDs = 256;




    template <class BI> static bool BeginDirectDraw(const DirectDraw::Parameters &params, BI &batchIterator);
    template <class BI> static bool EndDirectDraw(BI &batchIterator);

    static State GetState();

    static bool Initialize();
    static void Release();

    static bool Start(const Parameters &parameters);
    static bool Reset(const Parameters &parameters);
    static void Stop();

    static void GetParameters(Parameters &parameters);
    static uint32_t GetNumAvailableSamplers();

    static PixelBuffer *GetBackBuffer();
    static PixelBuffer *GetDepthStencilBuffer();

    static bool FrameBegin();
    static void FrameEnd();

    static void ShowPixelBuffer(PixelBuffer *pixelBuffer);

    static void Flush();
    static void BlockUntilIdle();

    static uint32_t GetCurrentFrameIndex();
    static bool IsFrameFinished(uint32_t frameIndex);






    static void SetState(const MeshState *meshState);


    static void SetState(const TextureState *textureState, const ProgramVariableHandle &handle);
    static void SetState(const TextureState *textureState, uint32_t id);
    static void SetState(const TextureState *textureState, float32_t mipMapLoadBias, uint32_t id);


    static void SetState(const RenderTargetState *renderTargetState);


    static void SetState(const BlendState *blendState);


    static void SetState(const DepthStencilState *depthStencilState);
    static void SetState(const DepthStencilState *depthStencilState, uint32_t stencilRef );


    static void SetState(const RasterizerState *rasterizerState);


    static void SetVertexProgram(const ProgramBuffer *vertexProgram);


    static void SetPixelProgram(const ProgramBuffer *pixelProgram);


    static void SetState(const ProgramVariableState *programVariables);






    static void DisableMeshState();


    static void DisableTextureState( uint32_t samplerId );


    static void DisableRenderTargetState();


    static void DisableBlendState();


    static void DisableDepthStencilState();


    static void DisableRasterizerState();






    static void SetVertexDescriptor(const VertexDescriptor *vdesc);


    static void SetViewport(const ViewportParameters &viewportParameters,
                            RenderTargetState::TargetID id = RenderTargetState::TARGETID_COLOR_ALL);


    static void SetScissorRect(const ScissorRectParameters &scissorRectParameters,
                               RenderTargetState::TargetID id = RenderTargetState::TARGETID_COLOR_ALL);






    static bool BeginConditionalRenderQuery(uint32_t conditionalRenderQueryID);


    static void EndConditionalRenderQuery();






    static void Draw(const DrawParameters &drawParameters);


    static void Draw(const DrawIndexedParameters &drawIndexedParameters);


    static void BeginConditionalRendering(uint32_t conditionalRenderQueryID);


    static void EndConditionalRendering();






    static void Clear(const ClearColorParameters &clearParameters,
                      RenderTargetState::TargetID id = RenderTargetState::TARGETID_COLOR_ALL);


    static void Clear(const ClearDepthStencilParameters &clearParameters);


    static void Clear(const ClearColorParameters &clearColorParameters,
                      const ClearDepthStencilParameters &clearDepthStencilParameters,
                      RenderTargetState::TargetID id = RenderTargetState::TARGETID_COLOR_ALL );





    static void Dispatch(const StateBuffer *stateBuffer);





    template <class SSI> static inline void BeginShaderStates(const ProgramVariableHandle &varHandle,
                                                              SSI &shaderStateIterator);
    template <class SSI> static inline void EndShaderStates(SSI &shaderStateIterator);




    static const RenderTargetState *PS3GetDefaultRenderTargetState();


    static uint32_t PS3AddressToOffset(void *address);


    static void PS3CPUSetLabelValue(uint8_t label, uint32_t value);
    static uint32_t PS3CPUGetLabelValue(uint8_t label);
    static void PS3CPUWaitLabelSpin(uint8_t label, uint32_t value);
    static void PS3CPUWaitLabelSleep(uint8_t label, uint32_t value);


    static void PS3GPUSetWaitLabel(uint8_t label, uint32_t value);
    static void PS3GPUSetLabelBackEnd(uint8_t label, uint32_t value);
    static void PS3GPUSetLabelCommand(uint8_t label, uint32_t value);
    static void PS3GPUSetLabelTexture(uint8_t label, uint32_t value);


    static PixelBuffer *PS3GetFrontBuffer();


    static uint32_t *PS3CommandBufferOverflowCallback(uint32_t space);
    static void PS3BeginUserCommandBuffer(uint32_t *destination, uint32_t size);
    static uint32_t PS3EndUserCommandBuffer();
    static void PS3DispatchUserCommandBuffer(uint32_t *buffer);
    static void PS3DispatchUserCommandBuffer(uint32_t offset);


    static void PS3DumpGPUStatus();





    static const uint32_t MAX_FRAMES_TO_BUFFER = 4;

protected:

    static void PS3SetVertexPointers();
    static void VFreqHandler(const uint32_t head);


    static const uint8_t m_deviceSyncLabel = 253;
    static const uint8_t m_directDrawLabel = 254;


    static State m_currentState;
    static Parameters m_parameterCopy;

    static uint32_t m_cmdSize;




    static void *m_gcmLocalAddress;
    static void *m_gcmIOAddress;
    static uint64_t m_gcmLocalSize;
    static uint64_t m_gcmIOSize;
    static uint32_t m_gcmMemoryFrequency;
    static uint32_t m_gcmCoreFrequency;




    static uint8_t m_mode;
    static uint8_t m_scanFormat;
    static uint8_t m_sync;
    static uint32_t m_colorFormat;
    static uint32_t m_framePitch;
    static uint32_t m_depthStencilFormat;
    static bool m_depthStencilAutoCreate;




    static PixelBuffer *m_backBuffers[MAX_FRAMES_TO_BUFFER];
    static PixelBuffer *m_depthStencilBuffer;
    static PixelBuffer *m_proxyBackBuffer;

    static RenderTargetState *m_renderTargetState;




    static uint32_t m_currentBackBufferIndex;
    static uint32_t m_nextBackBufferIndex[MAX_FRAMES_TO_BUFFER];
    static uint32_t m_numFramesRendered;
    static uint32_t m_numFramesToBuffer;

    static uint32_t m_numVSyncsToWait;
    static volatile uint32_t m_numVSyncs;
    static uint32_t m_lastNumVSyncs;
    static uint32_t m_immediateFlipEnable;

    static rw::math::Vector4 m_temporaryConstantTable[];

    static uint32_t m_needToResetVertexPointers;
    static uint32_t m_currentVertexAttributeMask;
    static ScissorRectParameters m_currentscissorRect;
    static const MeshState *m_currentMeshState;
    static const VertexDescriptor *m_currentVertexDescriptor;





    static uint32_t *m_userCommandBuffer;
    static uint32_t *m_defaultCommandBuffer;


public:
    static uint32_t m_reference;
protected:


    static bool m_conditionalReportEnabled;
    static uint32_t m_currentConditionalReportIndex;




















protected:


    Device();
    Device(const Device &device);
    ~Device();

};





inline void
Device::Parameters::SetBackBufferWidth(uint32_t w)
{
    ;
    width = w;
    return;
}

inline void
Device::Parameters::SetBackBufferHeight(uint32_t h)
{
    ;
    height = h;
    return;
}

inline void
Device::Parameters::SetBackBufferFormat(PixelFormat f)
{
    ;
    colorFormat = f;
    return;
}

inline void
Device::Parameters::SetFrontBufferWidth(uint32_t w)
{
    ;
    width = w;
    return;
}

inline void
Device::Parameters::SetFrontBufferHeight(uint32_t h)
{
    ;
    height = h;
    return;
}

inline void
Device::Parameters::SetFrontBufferFormat(PixelFormat f)
{
    ;
    colorFormat = f;
    return;
}

inline void
Device::Parameters::SetDepthStencilBufferFormat(PixelFormat f)
{
    ;
    depthStencilFormat = f;
    return;
}

inline void
Device::Parameters::SetAutoCreateDepthStencil(bool enable)
{
    ;
    depthStencilAutoCreate = enable;
    return;
}

inline void
Device::Parameters::SetNumFramesToBuffer(uint32_t f)
{
    ;
    numFramesToBuffer = f;
    return;
}

inline void
Device::Parameters::SetNumVSyncToWait(uint32_t vsyncs)
{
    ;
    numVsyncs = vsyncs;
    return;
}

inline void
Device::Parameters::PS3SetCommandBufferSize(uint32_t size)
{
    ;
    cmdSize = size;
    return;
}

inline void
Device::Parameters::PS3SetGraphicsSystemMemoryBuffer(void *buffer)
{
    ;
    ioAddress = buffer;
    return;
}

inline void
Device::Parameters::PS3SetGraphicsSystemMemorySize(uint32_t size)
{
    ;
    ioSize = size;
    return;
}

inline void
Device::Parameters::PS3SetDirectDrawBufferSize(uint32_t bufferSize)
{
    ;
    directDrawBufferSize = bufferSize;
    return;
}

inline void
Device::Parameters::PS3SetDirectDrawNumSubBuffers(uint32_t numSubBuffers)
{
    ;
    directDrawNumSubBuffers = numSubBuffers;
    return;
}

inline void
Device::Parameters::PS3SetImmediateFlipEnable(bool enable)
{
    ;
    immediateFlipEnable = enable;
    return;
}





inline void
Device::DirectDraw::Parameters::SetVertexDescriptor(const VertexDescriptor *vd)
{
    ;
    m_vertexDescriptor = vd;
    return;
}

inline void
Device::DirectDraw::Parameters::SetPrimitiveType(PrimitiveType primType)
{
    ;
    m_primitiveType = primType;
    return;
}

inline const VertexDescriptor *
Device::DirectDraw::Parameters::GetVertexDescriptor() const
{
    ;
    return m_vertexDescriptor;
}

inline PrimitiveType
Device::DirectDraw::Parameters::GetPrimitiveType() const
{
    ;
    return m_primitiveType;
}





inline uint32_t
Device::DirectDraw::GetMinVerticesBatch(const VertexDescriptor * )
{
    ;
    return 1;
}

inline uint32_t
Device::DirectDraw::GetMaxVerticesBatch(const VertexDescriptor *vd)
{
    ;
    uint32_t stride = vd->GetStride();
    return m_maxBatchSize / stride;
}

template <class VI> inline bool
Device::DirectDraw::BatchIterator::BeginBatch(uint32_t numVertices, VI & vertexIterator)
{
    ;




    ;





    uint32_t requiredSize;
    requiredSize = numVertices * Device::m_currentVertexDescriptor->GetStride();
    requiredSize = (((requiredSize) + ((Device::DirectDraw::VertexAlignment) - 1)) & ~((Device::DirectDraw::VertexAlignment) - 1));




    m_currentBufferPut = (((m_currentBufferPut) + ((Device::DirectDraw::VertexAlignment) - 1)) & ~((Device::DirectDraw::VertexAlignment) - 1));




    uint32_t nextBufferPos;
    uint32_t segmentBoundry = m_maxBatchSize * ( m_activeSegment + 1 );
    if ( m_currentBufferPut + requiredSize > segmentBoundry )
    {



        Device::PS3GPUSetLabelBackEnd( m_label, m_currentLabelIndex );
        Device::Flush();




        uint32_t nextSegment = ( m_activeSegment + 1 ) % m_numSegments;
        m_activeSegment = nextSegment;




        nextBufferPos = (((( m_maxBatchSize * nextSegment )) + ((Device::DirectDraw::VertexAlignment) - 1)) & ~((Device::DirectDraw::VertexAlignment) - 1));




        for (;;)
        {
            uint32_t lastLabelCrossed = PS3CPUGetLabelValue( m_label );

            if ( lastLabelCrossed + m_numSegments > m_currentLabelIndex )
            {
                break;
            }



            sys_timer_usleep( 30 );
        }

        m_currentLabelIndex++;
    }
    else
    {
        nextBufferPos = m_currentBufferPut;
    }


    Resource vbRes;
    vbRes.GetMemoryResource() = m_vbRes.GetMemoryResource();
    vbRes.GetGraphicsSystemResource()= (uint8_t *)m_vbRes.GetGraphicsSystemResource() + nextBufferPos;
    m_vertexBuffer = VertexBuffer::Initialize(vbRes, m_vbParameters);





    m_drawParameters.SetVertexCount(numVertices);
    vertexIterator.SetBuffer(m_vertexBuffer->PS3GetBuffer());


    m_meshState = MeshState::Initialize(m_msRes, m_msParameters);


    m_currentBufferPut = nextBufferPos + requiredSize;

    return true;
}

template <class VI> inline void
Device::DirectDraw::BatchIterator::EndBatch(VI & )
{
    ;

    m_vertexBuffer->SetDefaultStride(m_currentVertexDescriptor->GetStride());

    Device::SetState(m_meshState);

    Device::Draw(m_drawParameters);

    return;
}





template <class BI> inline bool
Device::BeginDirectDraw(const DirectDraw::Parameters &params, BI &)
{
    ;
    ;
    ;
    ;

    DirectDraw::m_drawParameters.SetStartVertex(0);
    DirectDraw::m_drawParameters.SetPrimitiveType(params.m_primitiveType);

    Device::SetVertexDescriptor(params.m_vertexDescriptor);

    return true;
}

template <class BI> inline bool
Device::EndDirectDraw(BI &)
{
    ;
    return true;
}

template <class SSI> inline void
Device::BeginShaderStates(const ProgramVariableHandle &varHandle,
                          SSI &shaderStateIterator)
{
    ;

    ;

    ;




    ;

    *reinterpret_cast<rw::math::Vector4**>(&shaderStateIterator.m_dest) = m_temporaryConstantTable;
    shaderStateIterator.m_handle = varHandle;



    return;
}

template <class SSI> void
Device::EndShaderStates(SSI &shaderStateIterator)
{
    ;

    ;


    if (shaderStateIterator.m_handle.GetProgramType() == ProgramBuffer::TYPE_VERTEX)
    {
        cellGcmSetVertexProgramParameterBlockInline(gCellGcmCurrentContext, shaderStateIterator.m_handle.GetConstantIndex(), shaderStateIterator.m_handle.GetNumConstants(), (float *)&m_temporaryConstantTable[0]);



    }
    else if (shaderStateIterator.m_handle.GetProgramType() == ProgramBuffer::TYPE_PIXEL)
    {
        ;

        CGprogram program = (CGprogram )const_cast<void *>
            (shaderStateIterator.m_handle.PS3GetProgramBuffer()->PS3GetCgProgramBuffer());
        CGparameter param = cellGcmCgGetIndexParameter(program, shaderStateIterator.m_handle.GetConstantIndex());
        uint32_t uCode = shaderStateIterator.m_handle.PS3GetProgramBuffer()->PS3GetPixelProgramOffset();
        rw::math::Vector4 *source = &m_temporaryConstantTable[0];

        cellGcmSetFragmentProgramParameter(gCellGcmCurrentContext, program, param, (float *)source, uCode);



        cellGcmSetUpdateFragmentProgramParameterInline(gCellGcmCurrentContext, uCode);
    }
    else
    {
        ;
    }

    ;
    ;




    return;
}

inline uint32_t
Device::GetNumAvailableSamplers()
{
    ;
    return MaxTextureStates;
}

inline PixelBuffer *
Device::GetBackBuffer()
{
    ;
    return m_proxyBackBuffer;
}

inline PixelBuffer *
Device::GetDepthStencilBuffer()
{
    ;
    return m_depthStencilBuffer;
}

inline const RenderTargetState *
Device::PS3GetDefaultRenderTargetState()
{
    ;
    return m_renderTargetState;
}

inline void
Device::SetState(const MeshState *meshState)
{
    ;

    ;








    m_currentMeshState = meshState;
    m_needToResetVertexPointers = PS3_GCM_TRUE;

    ;

    return;
}

inline void
Device::SetVertexDescriptor(const VertexDescriptor *vdesc)
{
    ;

    ;








    m_currentVertexDescriptor = vdesc;
    m_needToResetVertexPointers = PS3_GCM_TRUE;

    ;

    ;
}

inline void
Device::SetVertexProgram(const ProgramBuffer *vertexProgram)
{
    ;
    ;










    cellGcmSetVertexProgram(gCellGcmCurrentContext, vertexProgram->m_cgProgramBuffer, vertexProgram->m_programBuffer);




    return;
}

inline void
Device::SetPixelProgram(const ProgramBuffer *pixelProgram)
{
    ;
    ;










    cellGcmSetFragmentProgram(gCellGcmCurrentContext, pixelProgram->m_cgProgramBuffer, pixelProgram->m_programOffset);




    return;
}

inline void
Device::GetParameters(Parameters &parameters)
{
    ;
    parameters = m_parameterCopy;
    return;
}


inline uint32_t
Device::PS3AddressToOffset(void *address)
{
    ;
    uint32_t offset = 0;

    int32_t result;
    result = cellGcmAddressToOffset(address, &offset);
    ;

    return offset;
}

inline void
Device::PS3CPUSetLabelValue(uint8_t label, uint32_t value)
{
    ;

    volatile uint32_t *labelAddress;
    labelAddress = cellGcmGetLabelAddress(label);
    *labelAddress = value;

    return;
}

inline uint32_t
Device::PS3CPUGetLabelValue(uint8_t label)
{
    ;
    uint32_t value;

    volatile uint32_t *labelAddress;
    labelAddress = cellGcmGetLabelAddress(label);
    value = *labelAddress;



    return value;
}

inline void
Device::PS3CPUWaitLabelSpin(uint8_t label, uint32_t value)
{
    ;

    uint32_t *labelAddress;
    labelAddress = cellGcmGetLabelAddress(label);
    while(*(volatile uint32_t *)labelAddress != value)
        ;

    return;
}

inline void
Device::PS3CPUWaitLabelSleep(uint8_t label, uint32_t value)
{
    ;

    uint32_t *labelAddress;
    labelAddress = cellGcmGetLabelAddress(label);
    while(*(volatile uint32_t *)labelAddress != value)
    {

        sys_timer_usleep(0);
    }

    return;
}

inline void
Device::PS3GPUSetWaitLabel(uint8_t label, uint32_t value)
{
    ;

    cellGcmSetWaitLabelInline(gCellGcmCurrentContext, label, value);

    return;
}

inline void
Device::PS3GPUSetLabelBackEnd(uint8_t label, uint32_t value)
{
    ;

    cellGcmSetWriteBackEndLabelInline(gCellGcmCurrentContext, label, value);

    return;
}

inline void
Device::PS3GPUSetLabelCommand(uint8_t label, uint32_t value)
{
    ;

    cellGcmSetWriteCommandLabelInline(gCellGcmCurrentContext, label, value);

    return;
}

inline void
Device::PS3GPUSetLabelTexture(uint8_t label, uint32_t value)
{
    ;

    cellGcmSetWriteTextureLabelInline(gCellGcmCurrentContext, label, value);

    return;
}

inline PixelBuffer *
Device::PS3GetFrontBuffer()
{
    ;
    uint32_t frontBufferIndex = (m_currentBackBufferIndex == 0)?(m_numFramesToBuffer-1):(m_currentBackBufferIndex-1);
    return m_backBuffers[frontBufferIndex];
}





inline void
Device::PS3BeginUserCommandBuffer(uint32_t *destination, uint32_t size)
{
    ;

    ;

    ;

    m_userCommandBuffer = destination;
    m_defaultCommandBuffer = cellGcmGetCurrentBuffer();
    cellGcmSetCurrentBuffer(m_userCommandBuffer, size);

    return;
}




inline uint32_t
Device::PS3EndUserCommandBuffer()
{
    ;

    uint32_t *bufferEnd;

    ;


    cellGcmSetReturnCommandInline(gCellGcmCurrentContext);
    bufferEnd = cellGcmGetCurrentBuffer();
    uint32_t size = (rw::HostPtr )bufferEnd - (rw::HostPtr )m_userCommandBuffer;
    cellGcmSetDefaultCommandBuffer();







    return size;
}




inline void
Device::PS3DispatchUserCommandBuffer(uint32_t *buffer)
{
    ;

    ;

    ;

    cellGcmSetCallCommandInline(gCellGcmCurrentContext, Device::PS3AddressToOffset(buffer));

    return;
}




inline void
Device::PS3DispatchUserCommandBuffer(uint32_t offset)
{
    ;

    ;

    cellGcmSetCallCommandInline(gCellGcmCurrentContext, offset);

    return;
}

inline bool
Device::BeginConditionalRenderQuery(uint32_t conditionalRenderQueryID)
{
    ;
    ;

    ;


    cellGcmSetClearReportInline(gCellGcmCurrentContext, CELL_GCM_ZPASS_PIXEL_CNT);
    cellGcmSetZpassPixelCountEnableInline(gCellGcmCurrentContext, CELL_GCM_TRUE);

    m_conditionalReportEnabled = true;
    m_currentConditionalReportIndex = conditionalRenderQueryID;
    return true;
}

inline void
Device::EndConditionalRenderQuery()
{
    ;

    cellGcmSetReportInline(gCellGcmCurrentContext, CELL_GCM_ZPASS_PIXEL_CNT, m_currentConditionalReportIndex);
    cellGcmSetZpassPixelCountEnableInline(gCellGcmCurrentContext, CELL_GCM_FALSE);

    m_conditionalReportEnabled = false;
    return;
}




inline void
Device::BeginConditionalRendering(uint32_t conditionalRenderQueryID)
{
    ;
    ;


    cellGcmSetRenderEnableInline(gCellGcmCurrentContext, CELL_GCM_CONDITIONAL, conditionalRenderQueryID);

    return;
}




inline void
Device::EndConditionalRendering()
{
    ;

    cellGcmSetRenderEnableInline(gCellGcmCurrentContext, CELL_GCM_TRUE, 0);

    return;
}

inline void
Device::PS3DumpGPUStatus()
{
    ;

    cellGcmSetJumpCommandInline(gCellGcmCurrentContext, 0xffffffff);
    cellGcmFinishInline(gCellGcmCurrentContext, m_reference++);

    return;
}

}
}
}
