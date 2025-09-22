












namespace rw
{
namespace graphics
{
namespace core
{

































class StateBuffer : public rw::datacontainer::Buffer
{
public:



    uint32_t GetBufferSize() const;




    void Release();
    static void Destruct(StateBuffer *StateBuffer);

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();

    enum CommandToken
    {
        COMMANDTOKEN_DONE = 0x00,

        COMMANDTOKEN_MESHSTATE = 0x01,
        COMMANDTOKEN_VERTEXDESCRIPTOR = 0x02,
        COMMANDTOKEN_RENDERTARGETSTATE = 0x03,
        COMMANDTOKEN_BLENDSTATE = 0x04,
        COMMANDTOKEN_DEPTHSTENCILSTATE = 0x05,
        COMMANDTOKEN_RASTERIZERSTATE = 0x06,
        COMMANDTOKEN_VERTEXPROGRAM = 0x07,
        COMMANDTOKEN_PIXELPROGRAM = 0x08,

        COMMANDTOKEN_VIEWPORTPARAMETERS = 0x09,
        COMMANDTOKEN_SCISSORRECTPARAMETERS = 0x0a,
        COMMANDTOKEN_DRAWPARAMETERS = 0x0b,
        COMMANDTOKEN_DRAWINDEXEDPARAMETERS = 0x0c,
        COMMANDTOKEN_CLEARCOLORPARAMETERS = 0x0d,
        COMMANDTOKEN_CLEARDEPTHSTENCILPARAMETERS = 0x0e,

        COMMANDTOKEN_PROGRAMVARIABLEHANDLE = 0x0f,
        COMMANDTOKEN_PROGRAMSTATES = 0x10,

        COMMANDTOKEN_TEXTURESTATE = 0x11,


        COMMANDTOKEN_MAX,

        COMMANDTOKEN_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    struct ViewportParameters
    {
        rw::graphics::core::ViewportParameters viewport;
        RenderTargetState::TargetID id;
    };

    struct ScissorRectParameters
    {
        rw::graphics::core::ScissorRectParameters scissor;
        RenderTargetState::TargetID id;
    };

    struct ClearColorParameters
    {
        rw::graphics::core::ClearColorParameters clear;
        RenderTargetState::TargetID id;
    };

    struct TextureStateParameters
    {
        TextureState* state;
        float32_t mipBias;
        uint32_t id;
    };



    template<class ACCESSOR> bool Lock(ACCESSOR &accessor, const LockParameters &lockParameters);
    template<class ACCESSOR> void Unlock(const ACCESSOR &accessor);

    void* GetLowAddress() const;
    void* GetHighAddress() const;


    template <class _T> static CommandToken GetToken();

protected:
    struct ObjectDescriptor
    {public:
        CommandToken commandToken;
        uint32_t size;

        void EndianSwap();

    };

    const BaseResource StateBuffer::GetStreamBegin() const;
    BaseResource StateBuffer::GetStreamBegin();
    static ObjectDescriptor *GetNextObjectDescriptor(BaseResource &currentPosition);
    static void *GetNextObject(BaseResource &currentPosition, const uint32_t size, const uint32_t alignment = 4 );



    template <class _T> static uint32_t GetAlignment();

    void Unfix(rw::core::arena::SizeAndAlignment *offset);
    void Refix(rw::core::arena::ArenaIterator *iterator);
    void Fixup(rw::core::arena::ArenaIterator *iterator);



protected:
    void* m_buffer;
    uint32_t m_bufferSize;
    int32_t m_refCount;


    StateBuffer();
    StateBuffer(const StateBuffer &stateBuffer);
    ~StateBuffer();

    friend class StateCompilerDevice;
    friend class Device;
};





template<class ACCESSOR>
bool StateBuffer::Lock(ACCESSOR &accessor, const LockParameters &lockParameters)
{
    (void)lockParameters;
    accessor.Initialize(this, lockParameters.GetJobId());
    return true;
}




template<class ACCESSOR>
void StateBuffer::Unlock(const ACCESSOR &accessor)
{
    (void)accessor;
}

inline void*
StateBuffer::GetLowAddress() const
{
    return m_buffer;
}

inline void*
StateBuffer::GetHighAddress() const
{
    return MemAddOffset(m_buffer,m_bufferSize);
}

template <typename _T> uint32_t
StateBuffer::GetAlignment()
{
    ;
    return 4;
}


inline void
EndianSwap(rw::graphics::core::StateBuffer::CommandToken& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::StateBuffer::CommandToken) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_statebuffer_token_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_statebuffer_token_is_not_sizeof_uint32_t) break;

    ;
}
inline void
StateBuffer::ObjectDescriptor::EndianSwap()
{
    core::EndianSwap( commandToken );
    rw::EndianSwap( size );
}
}
}
}
