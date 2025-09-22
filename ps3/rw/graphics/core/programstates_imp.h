
























namespace rw
{
namespace graphics
{
namespace core
{







inline void
ProgramVariableBuffer::Parameters::SetProgramType(ProgramBuffer::Type type)
{
    ;
    programType = type;
    return;
}

inline void
ProgramVariableBuffer::Parameters::SetDataType(ProgramVariableHandle::DataType type)
{
    ;
    dataType = type;
    return;
}

inline void
ProgramVariableBuffer::Parameters::SetNumConstants(uint32_t numStates)
{
    ;
    numConstants = numStates;
    return;
}

inline ProgramBuffer::Type
ProgramVariableBuffer::Parameters::GetProgramType() const
{
    ;
    return programType;
}

inline ProgramVariableHandle::DataType
ProgramVariableBuffer::Parameters::GetDataType() const
{
    ;
    return dataType;
}

inline uint32_t
ProgramVariableBuffer::Parameters::GetNumConstants() const
{
    ;
    return numConstants;
}



template <class SSI> inline bool
ProgramVariableBuffer::Lock(uint32_t , SSI &shaderStateIterator)
{
    ;
    ;


    shaderStateIterator.m_dest = (rw::math::Vector4 *)m_buffer;





    return true;
}

template <class SSI> inline void
ProgramVariableBuffer::Unlock(const SSI &shaderStateIterator)
{
    ;
    ;

    return;
}

inline ProgramVariableHandle::DataType
ProgramVariableBuffer::GetDataType() const
{
    ;
    return m_dataType;
}

inline ProgramBuffer::Type
ProgramVariableBuffer::GetProgramType() const
{
    ;
    return m_programType;
}

inline uint32_t
ProgramVariableBuffer::GetNumConstants() const
{
    ;
    return m_numConstants;
}







inline void
ProgramVariableState::Parameters::SetProgramVariableBuffer(const ProgramVariableBuffer *stateBuffer)
{
    ;
    programVariableBuffer = stateBuffer;
    return;
}

inline void
ProgramVariableState::Parameters::AddProgramVariableHandle(const ProgramVariableHandle &stateHandle)
{
    ;
    ;
    handles[numUsedHandles++] = stateHandle;
    return;
}

inline void
ProgramVariableState::Parameters::SetRegisterRange(const ProgramBuffer *prog, uint32_t startRegister, uint32_t numRegisters)
{
    ;
    ;
    programBuffer = prog;
    registerRangeStart = startRegister;
    registerRangeNumRegisters = numRegisters;
    return;
}

}
}
}
