



























namespace CgsResource
{
    class RwShaderProgramStateResourceType;
}

namespace rw
{
namespace graphics
{
namespace core
{




class ProgramVariableHandle;







































class ProgramBuffer
{
public:
    friend class CgsResource::RwShaderProgramStateResourceType;


    enum Type
    {
        TYPE_NA = 0,

        TYPE_VERTEX,
        TYPE_PIXEL,

        TYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };

    class Parameters
    {
    public:
        Parameters() :
            cgProgramBuffer(0),
            cgProgramSize(0),
            programType(TYPE_NA)
        { }

        void SetType(Type programType);
        void SetBuffer(void *buffer);
        void SetSize(uint32_t size);

        Type GetType() const;
        const void *GetBuffer() const;
        uint32_t GetSize() const;

    public:

        void *cgProgramBuffer;
        uint32_t cgProgramSize;
        Type programType;

        friend class ProgramBuffer;
    };

    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &params);
    static ProgramBuffer *Initialize(const rw::Resource &resource, const Parameters &params);
    static void Destruct(ProgramBuffer *meshState);
    void Release();
    void GetParameters(Parameters &parameters) const;
    Type GetType() const;


    uint32_t GetNumStates() const;
    void GetVariableHandleByRegister( uint32_t dataType, uint32_t registerIdx,
                                    uint32_t registerCount, ProgramVariableHandle &stateHandle) const;
    bool GetVariableHandleByName(const char8_t *name, ProgramVariableHandle &stateHandle) const;
    const char8_t *GetStateNameByIndex(uint32_t index) const;

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();



    const void *PS3GetCgProgramBuffer() const;
    void *PS3GetCgProgramBuffer();
    uint32_t PS3GetPixelProgramOffset() const;
    void PS3CreateProgram();
    void PS3CreateVariableHandleFromCGparam(cg::CGparameter param, ProgramVariableHandle &stateHandle) const;

public:





    struct ProgramVariableDescriptor
    {
        uint16_t m_index;
        uint16_t m_numConstants;
        uint16_t m_dataType;
        uint16_t m_cgParamIndex;
    };

    const ProgramVariableDescriptor *PS3GetVariableDescriptorTable() const;
    ProgramVariableDescriptor *PS3GetVariableDescriptorTable();

    static uint32_t PS3FillParamTable(ProgramVariableDescriptor *table, const cg::rw_CGprogram prog, ProgramBuffer::Type type);
    static uint32_t PS3CountParams(const cg::rw_CGprogram prog, ProgramBuffer::Type type);





    void* m_programBuffer;
    uint32_t m_programSize;
    uint32_t m_programOffset;
    Type m_programType;

    cg::CGprogram m_cgProgramBuffer;
    uint32_t m_cgProgramSize;
    uint32_t m_numParameters;



    ProgramBuffer();
    ProgramBuffer(const ProgramBuffer &programBuffer);
    ~ProgramBuffer();

    friend class rw::graphics::core::Device;
};



inline void
ProgramBuffer::Parameters::SetType(Type type)
{
    ;
    programType = type;
    return;
}

inline void
ProgramBuffer::Parameters::SetBuffer(void *buffer)
{
    ;
    cgProgramBuffer = buffer;
    return;
}

inline void
ProgramBuffer::Parameters::SetSize(uint32_t size)
{
    ;
    cgProgramSize = size;
    return;
}

inline ProgramBuffer::Type
ProgramBuffer::Parameters::GetType() const
{
    ;
    return programType;
}

inline const void *
ProgramBuffer::Parameters::GetBuffer() const
{
    ;
    return cgProgramBuffer;
}

inline uint32_t
ProgramBuffer::Parameters::GetSize() const
{
    ;
    return cgProgramSize;
}



inline ProgramBuffer::Type
ProgramBuffer::GetType() const
{
    ;
    return m_programType;
}

inline uint32_t
ProgramBuffer::GetNumStates() const
{
    ;
    return m_numParameters;
}

inline ProgramBuffer::ProgramVariableDescriptor *
ProgramBuffer::PS3GetVariableDescriptorTable()
{
    ;
    return (ProgramVariableDescriptor *)(this + 1);
}

inline const ProgramBuffer::ProgramVariableDescriptor *
ProgramBuffer::PS3GetVariableDescriptorTable() const
{
    ;
    return const_cast<ProgramBuffer *>(this)->PS3GetVariableDescriptorTable();
}

inline void *
ProgramBuffer::PS3GetCgProgramBuffer()
{
    ;
    return (void *)RwPtrToHostPtr(m_cgProgramBuffer);
}

inline const void *
ProgramBuffer::PS3GetCgProgramBuffer() const
{
    ;
    return const_cast<ProgramBuffer *>(this)->PS3GetCgProgramBuffer();
}

inline uint32_t
ProgramBuffer::PS3GetPixelProgramOffset() const
{
    ;
    ;

    return m_programOffset;
}



inline void
EndianSwap(rw::graphics::core::ProgramBuffer::Type& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::ProgramBuffer::Type) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_programbuffer_type_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_programbuffer_type_is_not_sizeof_uint32_t) break;

    ;
}












class ProgramVariableHandle
{
public:


    static const uint8_t FLAGS_FLOAT = 0x01;
    static const uint8_t FLAGS_SAMPLER = 0x02;
    static const uint8_t FLAGS_BOOL = 0x04;
    static const uint8_t FLAGS_DATATYPEMASK = 0x07;
    static const uint8_t FLAGS_VERTEXPROGRAM = 0x80;


    typedef uint32_t DataType;
    static const uint32_t DATATYPE_NA = 0;
    static const uint32_t DATATYPE_FLOAT = (uint32_t )FLAGS_FLOAT;
    static const uint32_t DATATYPE_SAMPLER = (uint32_t )FLAGS_SAMPLER;
    static const uint32_t DATATYPE_BOOL = (uint32_t )FLAGS_BOOL;

    ProgramVariableHandle() :
        m_programBuffer(0),
        m_index(0),
        m_numConstants(0),
        m_dataFlags(0)
    { }

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;

    void SetProgramType(ProgramBuffer::Type programType);
    void SetDataType(DataType dataType);
    void SetNumConstants(uint32_t numConstants);
    void SetConstantIndex(uint32_t constantIndex);
    void PS3SetProgramBuffer(const ProgramBuffer *programBuffer);

    ProgramBuffer::Type GetProgramType() const;
    DataType GetDataType() const;
    uint32_t GetNumConstants() const;
    uint32_t GetConstantIndex() const;
    const ProgramBuffer *PS3GetProgramBuffer() const;

protected:



    const ProgramBuffer* m_programBuffer;
    uint16_t m_index;
    uint8_t m_numConstants;
    uint8_t m_dataFlags;
};




inline void
ProgramVariableHandle::SetProgramType(ProgramBuffer::Type programType)
{
    ;
    if (programType == ProgramBuffer::TYPE_VERTEX)
    {
        m_dataFlags |= FLAGS_VERTEXPROGRAM;
    }
    else
    {
        m_dataFlags &= ~FLAGS_VERTEXPROGRAM;
    }
    return;
}

inline void
ProgramVariableHandle::SetDataType(DataType dataType)
{
    ;
    m_dataFlags = (m_dataFlags & ~FLAGS_DATATYPEMASK) | (uint8_t )dataType;
    return;
}

inline void
ProgramVariableHandle::SetNumConstants(uint32_t numConstants)
{
    ;
    m_numConstants = (uint8_t )numConstants;
    return;
}

inline void
ProgramVariableHandle::SetConstantIndex(uint32_t constantIndex)
{
    ;
    m_index = (uint16_t )constantIndex;
    return;
}

inline void
ProgramVariableHandle::PS3SetProgramBuffer(const ProgramBuffer *programBuffer)
{
    ;
    m_programBuffer = programBuffer;
    return;
}

inline ProgramBuffer::Type
ProgramVariableHandle::GetProgramType() const
{
    ;
    return (m_dataFlags & FLAGS_VERTEXPROGRAM)?(ProgramBuffer::TYPE_VERTEX):(ProgramBuffer::TYPE_PIXEL);
}

inline ProgramVariableHandle::DataType
ProgramVariableHandle::GetDataType(void) const
{
    ;
    return (DataType )(m_dataFlags & FLAGS_DATATYPEMASK);
}

inline uint32_t
ProgramVariableHandle::GetNumConstants(void) const
{
    ;
    return (uint32_t )m_numConstants;
}

inline uint32_t
ProgramVariableHandle::GetConstantIndex(void) const
{
    ;
    return (uint32_t )m_index;
}

inline const ProgramBuffer *
ProgramVariableHandle::PS3GetProgramBuffer() const
{
    ;
    return m_programBuffer;
}



inline void
EndianSwap(rw::graphics::core::ProgramVariableHandle::DataType& )
{
    for (rwASSERTATCOMPILETIME_FAILURE< ((sizeof(rw::graphics::core::ProgramVariableHandle::DataType) == sizeof(uint32_t)) != 0) > ERROR_sizeof_rw_graphics_core_programstatehandle_datatype_is_not_sizeof_uint32_t; ; (void)ERROR_sizeof_rw_graphics_core_programstatehandle_datatype_is_not_sizeof_uint32_t) break;

    ;
}

}
}
}
