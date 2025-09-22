



















#include <rwcore.h>
#include <stddef.h>

























#include <rw/core/generalallocator/generalallocator.h>
#include <rw/core/generalallocator/generalallocatordebug.h>





namespace rw
{
   namespace core
   {







































      class AllocationRecorder
      {
      public:






         enum Mode
         {
            kModeNone,
            kModeRecord,
            kModePlayback
         };









         enum PlaybackAllocatorType
         {
            kPlaybackAllocatorTypeNULL,
            kPlaybackAllocatorTypeMalloc,
            kPlaybackAllocatorTypeNew,
            kPlaybackAllocatorTypeGeneral,
            kPlaybackAllocatorTypeGeneralDebug,
            kPlaybackAllocatorTypeCustom
         };









         enum HookType
         {
            kHookTypeMalloc,
            kHookTypeMallocAligned,
            kHookTypeCalloc,
            kHookTypeRealloc,
            kHookTypeFree
         };













         struct HookInfo
         {
            HookType mHookType;
            size_t mnSizeInputTotal;
            const void* mpDataInput;
            size_t mnCountInput;
            size_t mnSizeInput;
            size_t mnAlignmentInput;
            size_t mnAlignmentOffsetInput;
            int mnAllocationFlags;
            void* mpDataOutput;
         };



         AllocationRecorder(Mode mode = kModeNone, const char* pStreamName = 0, PlaybackAllocatorType playbackAllocatorType = kPlaybackAllocatorTypeGeneralDebug);



        ~AllocationRecorder();













         bool Init(Mode mode, const char* pStreamName = 0, PlaybackAllocatorType playbackAllocatorType = kPlaybackAllocatorTypeGeneralDebug);







         bool Shutdown();


















         void RecordMalloc(const void* pResult, size_t nSize, size_t nAlignment = 0, size_t nAlignmentOffset = 0, int nAllocationFlags = 0, char* pBuffer = 0);










         void RecordRealloc(const void* pResult, const void* pData, size_t nSize, int nAllocationFlags = 0, char* pBuffer = 0);










         void RecordCalloc(const void* pResult, size_t nElementCount, size_t nElementSize, int nAllocationFlags = 0, char* pBuffer = 0);







         void RecordFree(const void* pData, char* pBuffer = 0);











            void RecordAllocator(GeneralAllocator* pAllocator, bool bEnable);








            GeneralAllocator* GetPlaybackAllocator();



         typedef void (*HookFunctionType)(HookInfo* pHookInfo, void* pContext);









         void SetPlaybackHook(HookFunctionType pHookFunction, void* pContext);








         void Playback(size_t nStepCount = (size_t)(~0));






         bool PlaybackStep();







         size_t GetCurrentEventCount() const;









         size_t GetTotalEventCount() const;

      protected:

            static void HookFunction(const GeneralAllocator::HookInfo* pHookInfo, void* pContext);


















         Mode mMode;
         PlaybackAllocatorType mPlaybackAllocatorType;
         char* mpStreamName;
         void* mpStreamHandle;
         char* mpStreamData;
         size_t mnStreamDataSize;
         char* mpStreamPosition;
         char* mpStreamEnd;
         size_t mnCurrentEventCount;
         size_t mnTotalEventCount;
         uint64_t mnEventTime;
         HookFunctionType mpHookFunction;
         void* mpHookFunctionContext;











            GeneralAllocator* mpRecordedAllocator;
            GeneralAllocator* mpPlaybackAllocator;
            rw::core::thread::Mutex mpMutex;
            char mpMutexData[32];


         class HashTable
         {
         public:
            HashTable() : mppTable(0), mbReHashing(false), mnTableSize(0), mnTableSizeMin(4096), mnElementCount(0) { }
           ~HashTable() { Clear(true); }

            void Insert(const void* pKey, const void* pValue);
            bool Find(const void* pKey, void** ppValue) const;
            bool Remove(const void* pKey);
            void Clear(bool bDestroyTable);
            void Nuke();
            int Size() const { return mnElementCount; }

         protected:
            friend class AllocationRecorder;

            void ReHash(int nNewTableSize);
            int Hash(const void* pKey) const { return (int)(((intptr_t)pKey / 8) % mnTableSize); }

            struct HashPair{
               HashPair(const void* pKey = 0, const void* pValue = 0, HashPair* pNext = 0) : mpKey(pKey), mpValue(pValue), mpNext(pNext) {}

               const void* mpKey;
               const void* mpValue;
               HashPair* mpNext;
            };

            HashPair** mppTable;
            bool mbReHashing;
            int mnTableSize;
            int mnTableSizeMin;
            int mnElementCount;
            void* mpFunctionContext;
         };

         HashTable mHashTable;

         private:
            AllocationRecorder(const AllocationRecorder& );
            AllocationRecorder& operator=(const AllocationRecorder& );
      };

   }

}
