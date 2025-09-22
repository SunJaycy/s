




































































typedef struct RwMemoryAlignedFunctions RwMemoryAlignedFunctions;











typedef void *(*RwMallocAlignedFunc)(size_t size, size_t alignment);
typedef void *(*RwReallocAlignedFunc)(void *mem, size_t newSize, size_t alignment);

typedef void (*RwFreeAlignedFunc)(void *mem);







struct RwMemoryAlignedFunctions
{
    RwMallocAlignedFunc rwMallocAligned;
    RwReallocAlignedFunc rwReallocAligned;
    RwFreeAlignedFunc rwFreeAligned;
};






extern RwMemoryAlignedFunctions rwMemoryAlignedFunctions;








extern void RwMemSetMallocAligned(RwMallocAlignedFunc mallocAlignedFunc);
extern void RwMemSetReallocAligned(RwReallocAlignedFunc reallocAlignedFunc);
extern void RwMemSetFreeAligned(RwFreeAlignedFunc freeAlignedFunc);

extern RwMallocAlignedFunc RwMemGetMallocAligned(void);
extern RwReallocAlignedFunc RwMemGetReallocAligned(void);
extern RwFreeAlignedFunc RwMemGetFreeAligned(void);







class RwMemoryAlignedFunctionsAutoInitializer
{
    static volatile int32_t initcount;

public:

    RwMemoryAlignedFunctionsAutoInitializer();
    ~RwMemoryAlignedFunctionsAutoInitializer();
};







namespace
{
    static RwMemoryAlignedFunctionsAutoInitializer gRwMemoryAlignedFunctionsAutoInitializerInstance;
}
