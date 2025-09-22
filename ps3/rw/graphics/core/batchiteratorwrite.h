






namespace rw
{
namespace datacontainer
{


static const size_t DEFAULTBATCHSIZE = 0x80000000;




static const size_t CONTAINERALIGNMENT = 1;




static const size_t LINESIZE = 1;












template<class CONTAINER, uint32_t BATCHSIZE = DEFAULTBATCHSIZE>
class BatchIteratorWrite
{
public:
    struct Limits
    {
        uint32_t minElements;
        uint32_t maxElements;
    };
    typedef CONTAINER Container;
    typedef CONTAINER *ContainerParam;
    typedef const CONTAINER *ConstContainerParam;

    template<class ITERATOR> void BeginBatch(ITERATOR &iterator);
    template<class ITERATOR> void EndBatch(ITERATOR &iterator);
    template<class ITERATOR> Limits GetLimits(const ITERATOR &iterator);
                             void Initialize(CONTAINER *container, TaskId jobId, void *localAddress = 0);
    template<class ITERATOR> void NextBatch(ITERATOR &iterator);
                             void Release();
private:
    CONTAINER* mContainer;
    void *mWrite;



};






template<class CONTAINER, uint32_t BATCHSIZE>
template<class ITERATOR>
inline void BatchIteratorWrite<CONTAINER, BATCHSIZE>::BeginBatch(ITERATOR &iterator)
{
    void *batchLow = MemAlign(mWrite, LINESIZE);
    void *batchHigh = rw::math::Min(MemAddOffset(batchLow, BATCHSIZE), mContainer->GetHighAddress());

    iterator.SetWriteAddresses(mWrite, batchHigh);

}






template<class CONTAINER, uint32_t BATCHSIZE>
template<class ITERATOR>
inline void BatchIteratorWrite<CONTAINER, BATCHSIZE>::EndBatch(ITERATOR &iterator)
{

    void *writeLow;
    iterator.GetWriteAddresses(writeLow, mWrite);
}






template<class CONTAINER, uint32_t BATCHSIZE>
template<class ITERATOR>
inline typename BatchIteratorWrite<CONTAINER, BATCHSIZE>::Limits
BatchIteratorWrite<CONTAINER, BATCHSIZE>::GetLimits(const ITERATOR &iterator)
{
    Limits limits;
    limits.minElements = 1;
    limits.maxElements = BATCHSIZE / iterator.GetStride();
    return limits;
}







template<class CONTAINER, uint32_t BATCHSIZE>
inline void BatchIteratorWrite<CONTAINER, BATCHSIZE>::Initialize(CONTAINER *container,
                                                                 TaskId ,
                                                                 void *)
{
    mContainer = container;
    mWrite = mContainer->GetLowAddress();







}







template<class CONTAINER, uint32_t BATCHSIZE>
template<class ITERATOR>
inline void BatchIteratorWrite<CONTAINER, BATCHSIZE>::NextBatch(ITERATOR &iterator)
{
    EndBatch(iterator);
    BeginBatch(iterator);
}





template<class CONTAINER, uint32_t BATCHSIZE>
inline void BatchIteratorWrite<CONTAINER, BATCHSIZE>::Release()
{




}


}
}
