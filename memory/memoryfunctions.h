



































































































typedef struct RwMemoryFunctions RwMemoryFunctions;











typedef void *(*RwMallocFunc)(size_t size);
typedef void *(*RwReallocFunc)(void *mem, size_t newSize);

typedef void (*RwFreeFunc)(void *mem);







struct RwMemoryFunctions
{
    RwMallocFunc rwmalloc;
    RwReallocFunc rwrealloc;
    RwFreeFunc rwfree;
};







extern RwMemoryFunctions rwMemoryFunctions;








extern void RwMemSetMalloc(RwMallocFunc mallocFunc);
extern void RwMemSetRealloc(RwReallocFunc reallocFunc);
extern void RwMemSetFree(RwFreeFunc freeFunc);

extern RwMallocFunc RwMemGetMalloc(void);
extern RwReallocFunc RwMemGetRealloc(void);
extern RwFreeFunc RwMemGetFree(void);







class RwMemoryFunctionsAutoInitializer
{
    static volatile int32_t initcount;

public:

    RwMemoryFunctionsAutoInitializer();
    ~RwMemoryFunctionsAutoInitializer();
};







namespace
{
    static RwMemoryFunctionsAutoInitializer gRwMemoryFunctionsAutoInitializerInstance;
}
