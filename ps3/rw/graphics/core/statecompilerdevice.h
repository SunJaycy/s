













namespace rw
{
namespace graphics
{
namespace core
{



class StateBuffer;




























class StateCompilerDevice
{
public:

    StateCompilerDevice()
    { }

    ~StateCompilerDevice()
    { }




    static rw::ResourceDescriptor GetMinimumRequirements();






    bool BeginStateBuffer(rw::Resource &resource, const rw::ResourceDescriptor &usableResourceSpace);






    StateBuffer *EndStateBuffer(rw::ResourceDescriptor &usedResourceSpace);





    void SetState(const MeshState *meshState);
    void SetState(const TextureState *textureState, uint32_t id);
    void SetState(const TextureState *textureState, float32_t mipBias, uint32_t id);
    void SetState(const RenderTargetState *renderTargetState);
    void SetState(const BlendState *blendState);
    void SetState(const DepthStencilState *depthStencilState);
    void SetState(const RasterizerState *rasterizerState);
    void SetState(const ProgramVariableState *progamStates);
    void SetVertexDescriptor(const VertexDescriptor *vdesc);
    void SetVertexProgram(const ProgramBuffer *vertexProgram);
    void SetPixelProgram(const ProgramBuffer *vertexProgram);






    void SetViewport(const ViewportParameters &viewportParameters,
                     RenderTargetState::TargetID id = RenderTargetState::TARGETID_COLOR_ALL);

    void SetScissorRect(const ScissorRectParameters &scissorRectParameters,
                        RenderTargetState::TargetID id = RenderTargetState::TARGETID_COLOR_ALL);






    void Draw(const DrawParameters &drawParameters);


    void Draw(const DrawIndexedParameters &drawIndexedParameters);






    void Clear(const ClearColorParameters &clearParameters, RenderTargetState::TargetID id = RenderTargetState::TARGETID_COLOR_ALL);


    void Clear(const ClearDepthStencilParameters &clearParameters);


    void Clear(const ClearColorParameters &clearColorParameters,
               const ClearDepthStencilParameters &clearDepthStencilParameters,
               RenderTargetState::TargetID id = RenderTargetState::TARGETID_COLOR_ALL)
    {
        ;

        Clear(clearColorParameters, id);
        Clear(clearDepthStencilParameters);
        return;
    }





    template <class SSI> inline void BeginShaderStates(const ProgramVariableHandle &variableHandle,
                                                       SSI &shaderStateIterator)
    {
        ;

        ;

        BeginCommand( StateBuffer::COMMANDTOKEN_PROGRAMVARIABLEHANDLE, m_dataWriter );

        void *low, *current;
        m_dataWriter.GetWriteAddresses(low, current);
        low = current;

        ProgramVariableHandle &dstVariableHandle = *reinterpret_cast<ProgramVariableHandle *>(current);
        dstVariableHandle = variableHandle;

        current = MemAddOffset( current, sizeof(ProgramVariableHandle) );
        current = MemAlign( current, 16 );
        shaderStateIterator.m_dest = reinterpret_cast<rw::math::Vector4 *>(current);


        current = MemAddOffset( current, variableHandle.GetNumConstants()*sizeof(float)*4 );

        m_dataWriter.AddOffset( MemCalculateOffset( current, low ));








        return;
    }

    template <class SSI> void EndShaderStates(SSI &)
    {
        ;
        EndCommand( m_dataWriter );


        return;
    }

protected:

    template<class ITERATOR> void BeginCommand( StateBuffer::CommandToken cmdId, ITERATOR& it )
    {
        it.Write( cmdId );

        void *low;
        it.GetWriteAddresses( low, m_pSize);
        it.Write( (uint32_t)0 );


        if( it.IsFull() )
        {
            m_batchWriter.NextBatch(it);
        }
    }

    template<class ITERATOR> void EndCommand( ITERATOR& it )
    {
        void *low, *current;
        it.GetWriteAddresses( low, current );

        uint32_t size = MemCalculateOffset( current, m_pSize ) - sizeof(uint32_t);
        rwgConvert(*reinterpret_cast<uint32_t *>(m_pSize), size);
    }










    template <class _T> void CopyParameterBlockIntoBuffer(const _T *paramBlock);
    void CopyParameterBlockIntoBuffer(const ClearColorParameters *paramBlock, RenderTargetState::TargetID id);

    template <class _T> void CopyStateBlockIntoBuffer(const _T *stateBlock);
    void CopyStateBlockIntoBuffer(const TextureState *textureState, uint32_t id);

protected:



    rw::datacontainer::BatchIteratorWrite<StateBuffer> m_batchWriter;
    rw::graphics::IteratorWrite m_dataWriter;

    rw::Resource m_initialResource;
    rw::ResourceDescriptor m_initialResourceDescriptor;

    void* m_pSize;

};


}
}
}
