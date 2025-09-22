





































typedef struct RwLinearAllocHeap RwLinearAllocHeap;



typedef struct RwLinearAllocHeapRestorePoint RwLinearAllocHeapRestorePoint;













struct RwLinearAllocHeap
{
    void *memory;
    uint32_t numAllocations;
    size_t numAlignmentBytes;
    size_t currentUsage;
    size_t heapSize;
};




struct RwLinearAllocHeapRestorePoint
{
    uint32_t numAllocations;
    size_t numAlignmentBytes;
    size_t currentUsage;
};








extern RwLinearAllocHeap *
RwLinearAllocInitializeHeap(RwLinearAllocHeap *heap, void *mem, size_t size);

extern RwLinearAllocHeap *
RwLinearAllocSetCurrentHeap(RwLinearAllocHeap *heap);

extern RwLinearAllocHeap *
RwLinearAllocGetCurrentHeap(void);

extern void *
RwLinearAllocAlloc(size_t size, size_t alignment);

extern void
RwLinearAllocGetCurrentHeapRestorePoint(RwLinearAllocHeapRestorePoint *restorePoint);

extern void
RwLinearAllocSetCurrentHeapRestorePoint(const RwLinearAllocHeapRestorePoint *restorePoint);
