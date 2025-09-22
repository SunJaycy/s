



























namespace rw
{














































struct FreeList;









typedef void (*FreeListCallBack)(void *entry, void *pData);
























struct FreeList
{
    LLLink link;






    int32_t entrySize;
    int32_t entriesPerBlock;
    uint32_t maxBlocks;
    int32_t alignment;
    uint32_t hint;
    uint32_t heapSize;
    LinkList blockList;

    uint32_t flags;
};




extern RwBool rw_IsFreeListModuleOpened;





extern RwBool
FreeListModuleOpen(void);

extern void
FreeListModuleClose(void);





extern uint32_t
FreeListGetSize(uint32_t entrySize,
                uint32_t entriesPerBlock,
                uint32_t alignment,
                uint32_t blocks,
                uint32_t maxBlocks);

extern uint32_t
FreeListGetAlignment(uint32_t entrySize,
                     uint32_t entriesPerBlock,
                     uint32_t alignment,
                     uint32_t blocks,
                     uint32_t maxBlocks);

extern FreeList *
FreeListInitialize(void * ptr,
                   uint32_t entrySize,
                   uint32_t entriesPerBlock,
                   uint32_t alignment,
                   uint32_t blocks,
                   uint32_t maxBlocks,
                   uint32_t hint);

extern RwBool
FreeListRelease(FreeList *freeList);

extern void *
FreeListAlloc(FreeList *freeList, uint32_t hint);

extern FreeList *
FreeListFree(FreeList *freeList, void *entry);

extern int32_t
FreeListPurge(FreeList *freeList);

extern FreeList *
FreeListForAllUsed(FreeList *freeList,
                   FreeListCallBack fpCallBack,
                   void *pData);

extern int32_t
FreeListPurgeAllFreeLists(void);












inline void
FreeListSetDebugName(FreeList *, const RwChar *)
{
    ;

    ;
    ;




    return;
}














inline const RwChar *
FreeListGetDebugName(const FreeList *)
{
    ;

    ;




    return (const RwChar *)"N/A ";

}

















inline void
FreeListSetFlags(FreeList *freeList, uint32_t flags)
{
    ;
    ;
    ;


    freeList->flags = (flags & ~2) |
                      (freeList->flags & 2);

    return;
}













inline uint32_t
FreeListGetFlags(FreeList *freeList)
{
    ;
    ;
    ;

    return freeList->flags;
}

}
