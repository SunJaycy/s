





















namespace rw
{
namespace core
{
namespace filesys
{








class Stream
{
public:






    enum {
        BUFFERALIGN = 16
    };







    enum State
    {
        STATE_IDLE=0,
        STATE_RUNNING,
        STATE_STOPPED
    };









    enum RequestState
    {
        REQUESTSTATE_FREE=0,
        REQUESTSTATE_PENDING,
        REQUESTSTATE_EXECUTING,
        REQUESTSTATE_COMPLETED,
        REQUESTSTATE_CANCELLED
    };






    enum PriorityLevel
    {
        STREAM_PRIORITYLOW = -1000,
        STREAM_PRIORITYHIGH = 1000
    };




    typedef int RequestId;








    struct ChunkInfo
    {
        RequestId reqId;
        unsigned int size;
        void *pData;
    };











    enum ParseReturnValue
    {
        PARSE_RETURN_MORE_DATA_NEEDED,
        PARSE_RETURN_CHUNK,
        PARSE_RETURN_CHUNK_END_REQ
    };















    typedef bool (FILTERFUNC)(void *pData, void *filtercontext);





















    typedef ParseReturnValue (PARSEFUNC)( void *pData,
        unsigned int datasize, RequestId reqid, void *context,
        FILTERFUNC *filterfunc, void *filtercontext,
        unsigned int *blocksize);


    static Stream * Create(int requests, void *buffer, int bufsize, int readblocksize=0, PARSEFUNC *default_parse_func=0, void *context=0);
    void SetFilter(int tapnum, FILTERFUNC *filterfunc, void *context) const;
    void Destroy() const;


    void SetPriority(int prioritylow, int priorityhigh) const;
    void SetGreedyLevel(int greedylevel) const;
    void SetGreedyState() const;
    void SetNonGreedyState() const;


    Stream * CreateTap() const;
    int TapNum() const;


    RequestId QueueFile(const char *fname, int64_t offset=0, PARSEFUNC *parse_func=0, void *parsecontext=0) const;
    RequestId QueueMem(void *address, unsigned int length, PARSEFUNC *parse_func=0, void *parsecontext=0) const;
    void CancelRequest(RequestId requestid) const;
    void Kill() const;


    ChunkInfo * GetChunk() const;
    void ReleaseChunk(ChunkInfo *chunk) const;


    int Gettable() const;
    int Gettable(RequestId requestid) const;
    State GetState() const;
    bool IsEndOfStream() const;
    int BufferSize() const;
    int BufferUsage() const;
    RequestId TapRequestId() const;
    RequestState GetRequestState(RequestId requestid) const;
    uint64_t GetFileSize() const;
};
}
}
}
