
























namespace rw
{
namespace graphics
{
namespace core
{



class Device;



























class ProgramVariableBuffer
{
public:

    static const uint32_t LOCK_READ = 0x0001;
    static const uint32_t LOCK_WRITE = 0x0002;




    class Parameters
    {
    public:

        Parameters() :
            programType(ProgramBuffer::TYPE_NA),
            dataType(ProgramVariableHandle::DATATYPE_FLOAT),
            numConstants(0)
        { }




        void SetProgramType(ProgramBuffer::Type type);




        ProgramBuffer::Type GetProgramType() const;




        void SetDataType(ProgramVariableHandle::DataType type);




        ProgramVariableHandle::DataType GetDataType() const;




        void SetNumConstants(uint32_t numStates);




        uint32_t GetNumConstants() const;

        ProgramBuffer::Type programType;
        ProgramVariableHandle::DataType dataType;
        uint32_t numConstants;

        friend class ProgramVariableBuffer;
    };

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();
    void EndianSwapData();

    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &param);
    static ProgramVariableBuffer *Initialize(rw::Resource &resource, const Parameters &param);

    void Release();
    static void Destruct(ProgramVariableBuffer *ProgramVariableState);






    template <class SSI> bool Lock(uint32_t flags, SSI &shaderStateIterator);





    template <class SSI> void Unlock(const SSI &shaderStateIterator);

    ProgramVariableHandle::DataType GetDataType() const;
    ProgramBuffer::Type GetProgramType() const;
    uint32_t GetNumConstants() const;

protected:


    ProgramVariableHandle::DataType m_dataType;
    uint32_t m_numConstants;
    ProgramBuffer::Type m_programType;
    uint32_t m_bufferOffset;
    void* m_buffer;

protected:


    ProgramVariableBuffer();
    ProgramVariableBuffer(const ProgramVariableBuffer &programVariableBuffer);
    ~ProgramVariableBuffer();

    friend class rw::graphics::core::Device;
};















class ProgramVariableState
{
public:




    class Parameters
    {
    public:
        static const uint32_t MaxVariableHandles = 256;

        Parameters() :
            programVariableBuffer(0),
            registerRangeStart(0),
            registerRangeNumRegisters(0),
            programBuffer(0),
            numUsedHandles(0)
        { }




        void SetProgramVariableBuffer(const ProgramVariableBuffer *stateBuffer);




        void AddProgramVariableHandle(const ProgramVariableHandle &stateHandle);








        void SetRegisterRange(const ProgramBuffer *programBuffer, uint32_t startRegister, uint32_t numRegisters);

    protected:


        const ProgramVariableBuffer *programVariableBuffer;


        uint32_t registerRangeStart;
        uint32_t registerRangeNumRegisters;
        const ProgramBuffer *programBuffer;


        uint32_t numUsedHandles;
        ProgramVariableHandle handles[MaxVariableHandles];

        friend class rw::graphics::core::ProgramVariableState;

    };

    static rw::core::arena::SizeAndAlignment *Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset); static void Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator); static RwBool Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator); static void RegisterArenaReadCallbacks(); static void RegisterArenaWriteCallbacks(); void EndianSwapUnfix(); void EndianSwapFixup();;
    int32_t AddRef(); int32_t RemoveRef();

    static rw::ResourceDescriptor GetResourceDescriptor(const Parameters &param);
    static ProgramVariableState *Initialize(rw::Resource &resource, const Parameters &param);

    void Release();
    static void Destruct(ProgramVariableState *ProgramVariableState);

    void GetParameters(Parameters &params) const;

protected:
    static void CheckHandles(const ProgramVariableState::Parameters &params);


    const ProgramBuffer* m_programBuffer;
    const ProgramVariableBuffer* m_programVariableBuffer;
    ProgramBuffer::Type m_programType;
    uint16_t m_index;
    uint16_t m_numConstants;


    ProgramVariableState();
    ProgramVariableState(const ProgramVariableState &ProgramVariableState);
    ~ProgramVariableState();

    friend class rw::graphics::core::Device;
};

}
}
}

#include <rw/graphics/core/programstates_imp.h>
