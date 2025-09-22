






















































































































































































































































































namespace rw
{
   namespace core
   {









      class GeneralAllocator
      {
      public:















         enum AllocationFlags
         {
            kAllocationFlagNone = 0x00000000,
            kAllocationFlagLow = 0x00000000,
            kAllocationFlagHigh = 0x00000001,
            kAllocationFlagEndFit = 0x00000002,
            kAllocationFlagBestFit = 0x00000004,
            kAllocationFlagMMap = 0x00000008,
            kAllocationFlagReserved = 0xff000000,
            kAllocationFlagRetry = 0x40000000,
            kAllocationFlagInternal = 0x80000000
         };











         enum Alignment
         {
            kAlignmentMin = 8,
            kAlignmentMax = 65536,
            kAlignmentOffsetMin = 8,
            kAlignmentOffsetMax = 65536
         };








         typedef size_t (*CoreFreeFunction)(GeneralAllocator* pGeneralAllocator, void* pCore, size_t nSize, void* pContext);















         GeneralAllocator(void* pInitialCore = 0, size_t nInitialCoreSize = 0,
                          bool bShouldFreeInitialCore = true, bool bShouldTrimInitialCore = false,
                          CoreFreeFunction pInitialCoreFreeFunction = 0, void* pInitialCoreFreeFunctionContext = 0);





         virtual ~GeneralAllocator();









         virtual bool Init(void* pInitialCore = 0, size_t nInitialCoreSize = 0,
                               bool bShouldFreeInitialCore = true, bool bShouldTrimInitialCore = false,
                               CoreFreeFunction pInitialCoreFreeFunction = 0, void* pInitialCoreFreeFunctionContext = 0);





         virtual bool Shutdown();




















         virtual void* Malloc(size_t nSize, int nAllocationFlags = 0);







         virtual void* Calloc(size_t nElementCount, size_t nElementSize, int nAllocationFlags = 0);


























         virtual void* Realloc(void* p, size_t nNewSize, int nAllocationFlags = 0);








         virtual void Free(void* p);















         virtual void* MallocAligned(size_t nSize, size_t nAlignment, size_t nAlignmentOffset = 0, int nAllocationFlags = 0);












         virtual void** MallocMultiple(size_t nElementCount, size_t nElementSize, void* pResultArray[], int nAllocationFlags = 0);






         virtual void** MallocMultiple(size_t nElementCount, const size_t nElementSizes[], void* pResultArray[], int nAllocationFlags = 0);




















         virtual bool AddCore(void* pCore, size_t nSize, bool bShouldFreeCore = false, bool bShouldTrimCore = false,
                                 CoreFreeFunction pCoreFreeFunction = 0, void* pCoreFreeFunctionContext = 0);








         virtual size_t TrimCore(size_t nPadding);













         virtual void ClearCache();















         typedef bool (*MallocFailureFunction)(GeneralAllocator* pGeneralAllocator, size_t nMallocRequestedSize, size_t nAllocatorRequestedSize, void* pContext);
         virtual void SetMallocFailureFunction(MallocFailureFunction pMallocFailureFunction, void* pContext);





         typedef void (*AssertionFailureFunction)(const char* pExpression, void* pContext);
         void SetAssertionFailureFunction(AssertionFailureFunction pAssertionFailureFunction, void* pContext);







         void AssertionFailure(const char* pExpression) const;













         enum HookType{
            kHookTypeMalloc,
            kHookTypeFree,
            kHookTypeCoreAlloc,
            kHookTypeCoreFree
         };













         enum HookSubType{
            kHookSubTypeNone,
            kHookSubTypeMalloc,
            kHookSubTypeCalloc,
            kHookSubTypeRealloc,
            kHookSubTypeMallocAligned,
            kHookSubTypeMallocMultiple1,
            kHookSubTypeMallocMultiple2
         };



















         struct HookInfo{
            bool mbEntry;
            HookType mHookType;
            HookSubType mHookSubType;
            size_t mnSizeInputTotal;
            const void* mpDataInput;
            size_t mnCountInput;
            size_t mnSizeInput;
            const size_t* mpSizeInputArray;
            size_t mnAlignmentInput;
            int mnAllocationFlags;
            void* mpDataOutput;
            void** mpArrayOutput;
            size_t mnSizeOutput;
         };












         typedef void (*HookFunction)(const HookInfo* pHookInfo, void* pContext);
         virtual void SetHookFuncton(HookFunction pHookFunction, void* pContext);









         void Lock(bool bEnable);


















         enum Option{
            kOptionEnableThreadSafety,
            kOptionEnableHighAllocation,
            kOptionEnableSystemAlloc,
            kOptionNewCoreSize,
            kOptionCoreIncrementSize,
            kOptionMaxFastBinRequestSize,
            kOptionTrimThreshold,
            kOptionTopPad,
            kOptionMMapThreshold,
            kOptionMMapMaxAllowed,
            kOptionMMapTopDown,
            kOptionTraceInternalMemory,
            kOptionMaxMallocFailureCount
         };








         virtual void SetOption(int option, int nValue);









         virtual size_t GetUsableSize(const void* pData) const;










         virtual size_t GetBlockSize(const void* pData) const;








         virtual size_t GetLargestFreeBlock(bool bClearCache = false);







         typedef void (*TraceFunction)(const char* pTraceText, void* pContext);
         virtual void SetTraceFunction(TraceFunction pTraceFunction, void* pContext);












         virtual void SetTraceFieldDelimiters(unsigned char fieldDelimiter, unsigned char recordDelimiter);












         enum HeapValidationLevel{
            kHeapValidationLevelNone,
            kHeapValidationLevelBasic,
            kHeapValidationLevelDetail,
            kHeapValidationLevelFull
         };
         virtual bool ValidateHeap(HeapValidationLevel heapValidationLevel = kHeapValidationLevelBasic);











         virtual void SetAutoHeapValidation(HeapValidationLevel heapValidationLevel, size_t nFrequency);


















         virtual void TraceAllocatedMemory(TraceFunction pTraceFunction = 0, void* pTraceFunctionContext = 0, void* pStorage = 0, size_t nStorageSize = 0);






         virtual size_t DescribeData(const void* pData, char* pBuffer, size_t nBufferLength);









         virtual bool ValidateAddress(const void* pAddress, bool bPointerIsAllocation);









         virtual bool IsAddressHigh(const void* pAddress);













         enum BlockType{
            kBlockTypeNone = 0,
            kBlockTypeInvalid = 1,
            kBlockTypeAllocated = 2,
            kBlockTypeFree = 4,
            kBlockTypeCore = 8,
            kBlockTypeInternal = 16,
            kBlockTypeAll = 31
         };












         struct BlockInfo{
            const void* mpBlock;
            size_t mnBlockSize;
            void* mpData;
            size_t mnDataSize;
            char mBlockType;
            bool mbMemoryMapped;
         };



















         virtual void* TakeSnapshot(int nBlockTypeFlags = kBlockTypeAll, bool bMakeCopy = false, void* pStorage = 0, size_t nStorageSize = 0);
         virtual void FreeSnapshot(void* pSnapshot);



















         typedef bool (*HeapReportFunction)(const BlockInfo* pBlockInfo, void* pContext);
         virtual bool ReportHeap(HeapReportFunction, void* pContext, int nBlockTypeFlags, bool bMakeCopy = false, void* pStorage = 0, size_t nStorageSize = 0);
















         virtual const void* ReportBegin(void* pSnapshot = 0, int nBlockTypeFlags = kBlockTypeAll, bool bMakeCopy = false, void* pStorage = 0, size_t nStorageSize = 0);
         virtual const BlockInfo* ReportNext(const void* pContext, int nBlockTypeFlags = kBlockTypeAll);
         virtual void ReportEnd(const void* pContext);


      protected:
         friend class HandleAllocator;

         typedef uint32_t size_type;











         struct Chunk{
            size_type mnPriorSize;
            size_type mnSize;
            Chunk* mpPrevChunk;
            Chunk* mpNextChunk;
         };



















         struct CoreBlock{
            char* mpCore;
            size_t mnSize;
            size_t mnReservedSize;
            bool mbMMappedMemory;
            bool mbShouldFree;
            bool mbShouldFreeOnShutdown;
            bool mbShouldTrim;
            CoreFreeFunction mpCoreFreeFunction;
            void* mpCoreFreeFunctionContext;
            CoreBlock* mpPrevCoreBlock;
            CoreBlock* mpNextCoreBlock;
         };
         friend struct CoreBlockEx;



















         struct Snapshot{
            enum{ kSnapshotMagicNumber = 0x534e4150 };

            int mnMagicNumber;
            size_t mnSizeOfThis;
            int mnBlockTypeFlags;
            bool mbUserAllocated;
            bool mbReport;
            bool mbDynamic;
            CoreBlock* mpCurrentCoreBlock;
            Chunk* mpCurrentChunk;
            Chunk* mpCurrentMChunk;
            size_t mnBlockInfoCount;
            size_t mnBlockInfoIndex;
            BlockInfo mBlockInfo[1];

            Snapshot(size_t nSizeOfThis, int nBlockTypeFlags);
         };














































         enum Constants{
            kSizeTypeSize = sizeof(size_type),
            kChunkInternalHeaderSize = 2 * kSizeTypeSize,
            kFenceChunkSize = kChunkInternalHeaderSize,
            kDoubleFenceChunkSize = 2 * kFenceChunkSize,
            kMinAlignment = 2 * kSizeTypeSize,
            kMinAlignmentMask = kMinAlignment - 1,
            kMinChunkSize = sizeof(Chunk),
            kMinAllocSize = ((kMinChunkSize + kMinAlignmentMask) & ~kMinAlignmentMask),
            kMaxAllocSize = (((unsigned)-1) - kMinAllocSize),
            kChunkListPointersSize = 2 * sizeof(Chunk*),
            kFastBinConsolidationThreshold = 65536,
            kFastBinDefaultMaxDataSize = 64,
            kFastBinMaxDataSize = 80,
            kFastBinChunkSizeMax = (2 * kSizeTypeSize) + 80,
            kFastBinChunkSizeMin = kMinChunkSize,
            kFastBinChunkSizeIncrement = 8,
            kFastBinChunkSizeShift = 3,
            kFastBinIndexMin = 2,
            kFastBinCount = (kFastBinChunkSizeMax / kFastBinChunkSizeIncrement) - kFastBinIndexMin + 1,
            kFlagFastBinChunksExist = 1,
            kBinCount = 128,
            kSmallBinCount = 64,
            kSmallBinSizeIncrement = 8,
            kLargeBinMinChunkSize = 512,
            kMinSortedBinChunkSize = 512,
            kBinBitmapShift = 5,
            kBitsPerBinBitmapWord = 1 << kBinBitmapShift,
            kBinBitmapWordCount = kBinCount / kBitsPerBinBitmapWord,
            kDefaultTrimThreshold = 128 * 1024,
            kDefaultTopPad = 64 * 1024,
            kDefaultMMapThreshold = 128 * 1024,
            kDefaultMMapMaxCount = 65536,
            kDefaultMMapAsCoreSize = 1024 * 1024,
            kChunkFlagPrevInUse = 1,
            kChunkFlagMMapped = 2,
            kChunkFlagInternal = 4,
            kChunkFlagFastBin = (int)(1 << ((sizeof(size_type) * 8) - 1)),
            kChunkFlagAll = (kChunkFlagPrevInUse | kChunkFlagMMapped | kChunkFlagInternal | kChunkFlagFastBin),
            kChunkSizeMask = ~kChunkFlagAll
         };








         enum DataType{
            kDataTypeBinary,
            kDataTypeChar,
            kDataTypeWChar
         };









         enum BinType{
            kBinTypeNone,
            kBinTypeFast,
            kBinTypeNormal,
            kBinTypeTop
         };




            virtual void* MallocInternal(size_t nSize, int nAllocationFlags = 0);
            virtual void* CallocInternal(size_t nElementCount, size_t nElementSize, int nAllocationFlags = 0);
            virtual void* ReallocInternal(void* p, size_t nNewSize, int nAllocationFlags = 0);
            virtual void FreeInternal(void* p);
            virtual void* MallocAlignedInternal(size_t nAlignment, size_t nSize, size_t nAlignmentOffset, int nAllocationFlags = 0);

         virtual void** MallocMultipleInternal(size_t nElementCount, size_t nSizeCount, const size_t nElementSizes[], void* pResultArray[], int nAllocationFlags = 0);

         virtual Chunk* ExtendCoreInternal(size_t nMinSize);
         virtual Chunk* AddCoreInternal(size_t nMinSize);
         virtual bool FreeCore(CoreBlock* pCoreBlock, bool bInShutdown);






         virtual void ClearFastBins();


         static bool GetIsPowerOf2(size_t nValue);
         static bool GetIsMinAligned(void* pAddress);
         static bool GetIsAligned(void* pAddress, size_t nAlignment);
         static size_t AlignUp(size_t nValue, size_t nAlignment);
         static char* AlignUp(void* pValue, size_t nAlignment);
         static unsigned GetPageSize();
         static bool RequestIsWithinRange(size_t nBytes);
         bool GetCoreIsContiguous() const;
         void AdjustHighFence();
         void SetNewTopChunk(Chunk* pChunk, bool bFreePreviousTopChunk);
         void AdjustTopChunk(Chunk* pChunk, size_type nChunkSize);
         bool ChunkMatchesLowHigh(int bHigh, const Chunk* pChunk, const size_type nChunkSize) const;
         static int ChunkMatchesBlockType(const Chunk* pChunk, int nBlockTypeFlags);
         static void SetFencepostAfterChunk(const Chunk* pChunk, size_type nChunkSize);

         static void AddDoubleFencepost(Chunk* pChunk, int nPrevChunkFlags);
         static Chunk* MakeChunkFromCore(void* pCore, size_t nCoreSize, int nFlags);
         void GetBlockInfoForCoreBlock(const CoreBlock* pCoreBlock, BlockInfo* pBlockInfo) const;
         void GetBlockInfoForChunk(const Chunk* pChunk, BlockInfo* pBlockInfo) const;


         static void* GetPostHeaderPtrFromChunkPtr(const Chunk* pChunk);
         static void* GetDataPtrFromChunkPtr(const Chunk* pChunk);
         static Chunk* GetChunkPtrFromDataPtr(const void* pData);
         static size_type GetChunkSizeFromDataSize(size_type nDataSize);
         static size_type GetChunkSizeFromDataSizeChecked(size_type nDataSize);
         static size_type GetMMapChunkSizeFromDataSize(size_type nDataSize);
         static Chunk* GetMMapChunkFromMMapListChunk(const Chunk* pChunk);
         static int GetChunkIsInternal(const Chunk* pChunk);
         static void SetChunkIsInternal(Chunk* pChunk);
         static void ClearChunkIsInternal(Chunk* pChunk);
         static int GetChunkIsFastBin(const Chunk* pChunk);
         static void SetChunkIsFastBin(Chunk* pChunk);
         static void ClearChunkIsFastBin(Chunk* pChunk);
         static int GetChunkIsMMapped(const Chunk* pChunk);
         static int GetPrevChunkIsInUse(const Chunk* pChunk);
         static size_type GetChunkSize(const Chunk* pChunk);
         static size_type GetUsableChunkSize(const Chunk* pChunk);
         static Chunk* GetNextChunk(const Chunk* pChunk);
         static Chunk* GetPrevChunk(const Chunk* pChunk);
         static Chunk* GetChunkAtOffset(const Chunk* pChunk, int nOffset);
         static int GetChunkIsInUse(const Chunk* pChunk);
         static void SetChunkIsInUse(Chunk* pChunk);
         static void ClearChunkInUse(Chunk* pChunk);
         static int GetChunkInUseOffset(const Chunk* pChunk, int nOffset);
         static void SetChunkInUseOffset(Chunk* pChunk, int nOffset);
         static void ClearChunkInUseOffset(Chunk* pChunk, int nOffset);
         static void SetChunkSize(Chunk* pChunk, size_type nSize);
         static void SetChunkSizePreserveFlags(Chunk* pChunk, size_type nSize);
         static size_type GetNextChunkPrevSize(const Chunk* pChunk, size_type nSize);
         static void SetNextChunkPrevSize(Chunk* pChunk, size_type nSize);
         static void LinkChunk(Chunk* pChunk, Chunk* pPrev, Chunk* pNext);
         static void UnlinkChunk(const Chunk* pChunk);
         Chunk* FindPriorChunk(const Chunk* pChunk) const;
         Chunk* GetInitialTopChunk() const;
         Chunk* FindAndSetNewTopChunk();
         bool GetChunkIsListHead(const Chunk* pChunk) const;
         bool GetChunkIsFenceChunk(const Chunk* pChunk) const;
         static Chunk* GetFenceChunk(const CoreBlock* pCoreBlock);
         BinType FindChunkBin(const Chunk* pChunk) const;


         Chunk* GetBin(int nIndex) const;
         Chunk* GetUnsortedBin() const;
         static Chunk* GetFirstChunkInBin(const Chunk* pBin);
         static Chunk* GetLastChunkInBin(const Chunk* pBin);
         static Chunk* GetNextBin(Chunk* pBin);
         static bool SizeIsWithinSmallBinRange(size_type nSize);
         static int GetSmallBinIndexFromChunkSize(size_type nSize);
         static int GetLargeBinIndexFromChunkSize(size_type nSize);
         static int GetBinIndexFromChunkSize(size_type nSize);
         static int GetBinBitmapWordFromBinIndex(int nBinIndex);
         static int GetBinBitmapBitFromBinIndex(int nBinIndex);
         void MarkBinBitmapBit(int nBinIndex);
         void UnmarkBinBitmapBit(int nBinIndex);
         int GetBinBitmapBit(int nBinIndex) const;


         static unsigned GetFastBinIndexFromChunkSize(size_type nSize);
         int GetFastBinChunksExist() const;
         void SetFastBinChunksExist(bool bExist);
         unsigned GetMaxFastBinChunkSize() const;
         void SetMaxFastBinDataSize(size_type nSize);


         virtual void LinkCoreBlock(CoreBlock* pCoreBlock, CoreBlock* pNext);
         virtual void UnlinkCoreBlock(CoreBlock* pCoreBlock);
         virtual CoreBlock* FindCoreBlockForAddress(const void* pAddress) const;


         virtual int CheckChunk(const Chunk* pChunk);
         virtual int CheckFreeChunk(const Chunk* pChunk);
         virtual int CheckUsedChunk(const Chunk* pChunk);
         virtual int CheckRemallocedChunk(const Chunk* pChunk, size_type nRequestedChunkSize);
         virtual int CheckMallocedChunk(const Chunk* pChunk, size_type nRequestedChunkSize, bool bNewlyMalloced, bool bAllowPrevNotInUse);
         virtual int CheckMMappedChunk(const Chunk* pChunk);
         virtual int CheckState(HeapValidationLevel heapValidationLevel);
         virtual size_t DescribeChunk(const Chunk* pChunk, char* pBuffer, size_t nBufferLength);
         virtual DataType GetDataPreview(const void* pData, size_t nDataSize, char* pBuffer, wchar_t* pBufferW, size_t nBufferLength) const;
         static void TraceFunctionDefault(const char* pTraceText, void* pContext);
         static void AssertionFailureFunctionDefault(const char* pExpression, void* pContext);

      protected:


         bool mbInitialized;

         size_type mnMaxFastBinChunkSize;

         Chunk* mpFastBinArray[kFastBinCount];

         Chunk* mpBinArray[kBinCount * 2];

         unsigned mBinBitmap[kBinBitmapWordCount];

         Chunk* mpTopChunk;

         Chunk* mpLastRemainderChunk;

         CoreBlock mHeadCoreBlock;

         void* mpHighFence;

         bool mbHighFenceInternallyDisabled;

         bool mbSystemAllocEnabled;
         int mnCheckChunkReentrancyCount;

         unsigned char mcTraceFieldDelimiter;

         unsigned char mcTraceRecordDelimiter;



         HeapValidationLevel mAutoHeapValidationLevel;

         size_t mnAutoHeapValidationFrequency;

         size_t mnAutoHeapValidationEventCount;

         bool mbHeapValidationActive;


         int mnMMapCount;
         size_t mnMMapMallocTotal;
         int mnMMapMaxAllowed;

         size_type mnMMapThreshold;

         bool mbMMapTopDown;

         Chunk mHeadMMapChunk;







         MallocFailureFunction mpMallocFailureFunction;
         void* mpMallocFailureFunctionContext;

         unsigned mnMaxMallocFailureCount;

         AssertionFailureFunction mpAssertionFailureFunction;
         void* mpAssertionFailureFunctionContext;

         TraceFunction mpTraceFunction;
         void* mpTraceFunctionContext;


         unsigned mnTrimThreshold;
         size_type mnTopPad;
         char* mpInitialTopChunk;

         size_t mnPageSize;

         size_t mnNewCoreSize;

         size_t mnCoreIncrementSize;

         bool mbTraceInternalMemory;



         rw::core::thread::Mutex mpMutex;








         unsigned char mnFillFree;
         unsigned char mnFillDelayedFree;
         unsigned char mnFillNew;
         unsigned char mnFillGuard;
         unsigned char mnFillUnusedCore;

     private:
         GeneralAllocator(const GeneralAllocator& );
         GeneralAllocator& operator=(const GeneralAllocator& );
      };

   }

}













namespace rw
{
   namespace core
   {






         inline
         void GeneralAllocator::Lock(bool bEnable)
         {
               if(bEnable)
                  mpMutex.Lock(rw::core::thread::kTimeoutNone);
               else
                  mpMutex.Unlock();
         }














      inline
      bool GeneralAllocator::GetIsPowerOf2(size_t nValue)
      {
         return (nValue > 0) && ((nValue & (nValue - 1)) == 0);
      }




      inline
      bool GeneralAllocator::GetIsMinAligned(void* pAddress)
      {
         return (((uintptr_t)pAddress & kMinAlignmentMask) == 0);
      }




      inline
      bool GeneralAllocator::GetIsAligned(void* pAddress, size_t nAlignment)
      {
         ;
         return (((uintptr_t)pAddress & (nAlignment - 1)) == 0);
      }




      inline
      size_t GeneralAllocator::AlignUp(size_t nValue, size_t nAlignment)
      {
         ;
         return (nValue + (nAlignment - 1)) & ~(nAlignment - 1);
      }




      inline
      char* GeneralAllocator::AlignUp(void* pValue, size_t nAlignment)
      {
         return (char*)(((uintptr_t)pValue + (nAlignment - 1)) & ~(nAlignment - 1));
      }




      inline
      bool GeneralAllocator::RequestIsWithinRange(size_t nSize)
      {



         return (nSize < (size_type)(-2 * kMinAllocSize));
      }




      inline
      void* GeneralAllocator::GetPostHeaderPtrFromChunkPtr(const Chunk* pChunk)
      {
         return const_cast<char*>((const char*)pChunk + sizeof(Chunk));
      }



      inline
      void* GeneralAllocator::GetDataPtrFromChunkPtr(const Chunk* pChunk)
      {
         return const_cast<char*>((const char*)pChunk + kChunkInternalHeaderSize);
      }




      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetChunkPtrFromDataPtr(const void* pData)
      {
         return reinterpret_cast<GeneralAllocator::Chunk*>
                (const_cast<char*>((const char*)pData - kChunkInternalHeaderSize));
      }




      inline
      GeneralAllocator::size_type GeneralAllocator::GetChunkSizeFromDataSize(size_type nDataSize)
      {











            const size_type sum = (size_type)(nDataSize + kSizeTypeSize + kMinAlignmentMask);


         if(sum > kMinChunkSize)
            return (sum & ~kMinAlignmentMask);
         return kMinChunkSize;
      }




      inline
      GeneralAllocator::size_type GeneralAllocator::GetMMapChunkSizeFromDataSize(size_type nDataSize)
      {

















         const unsigned kPageMask(4096 - 1);
         return (kChunkInternalHeaderSize + nDataSize + kMinChunkSize + kMinAlignmentMask + kPageMask) & ~kPageMask;
      }




      inline
      GeneralAllocator::size_type GeneralAllocator::GetChunkSizeFromDataSizeChecked(size_type nDataSize)
      {
         if(RequestIsWithinRange(nDataSize))
            return GetChunkSizeFromDataSize(nDataSize);
         return 0;
      }




      inline
      unsigned GeneralAllocator::GetFastBinIndexFromChunkSize(size_type nChunkSize)
      {
         return ((nChunkSize >> kFastBinChunkSizeShift) - kFastBinIndexMin);
      }




      inline
      int GeneralAllocator::GetPrevChunkIsInUse(const Chunk* pChunk)
      {
         return (int)(pChunk->mnSize & kChunkFlagPrevInUse);
      }




      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetMMapChunkFromMMapListChunk(const Chunk* pChunk)
      {



         return reinterpret_cast<Chunk*>(const_cast<char*>((const char*)pChunk - pChunk->mnPriorSize));
      }




      inline
      int GeneralAllocator::GetChunkIsMMapped(const Chunk* pChunk)
      {
         return (int)(pChunk->mnSize & kChunkFlagMMapped);
      }




      inline
      int GeneralAllocator::GetChunkIsInternal(const Chunk* pChunk)
      {
         return (int)(pChunk->mnSize & kChunkFlagInternal);
      }




      inline
      void GeneralAllocator::SetChunkIsInternal(Chunk* pChunk)
      {
         pChunk->mnSize |= kChunkFlagInternal;
      }




      inline
      void GeneralAllocator::ClearChunkIsInternal(Chunk* pChunk)
      {
         pChunk->mnSize &= ~(size_type)kChunkFlagInternal;
      }




      inline
      int GeneralAllocator::GetChunkIsFastBin(const Chunk* pChunk)
      {
         return (int)(pChunk->mnSize & kChunkFlagFastBin);
      }




      inline
      void GeneralAllocator::SetChunkIsFastBin(Chunk* pChunk)
      {
         pChunk->mnSize |= kChunkFlagFastBin;
      }




      inline
      void GeneralAllocator::ClearChunkIsFastBin(Chunk* pChunk)
      {
         pChunk->mnSize &= ~(size_type)kChunkFlagFastBin;
      }




      inline
      GeneralAllocator::size_type GeneralAllocator::GetChunkSize(const Chunk* pChunk)
      {
         return (pChunk->mnSize & kChunkSizeMask);
      }










      inline
      GeneralAllocator::size_type GeneralAllocator::GetUsableChunkSize(const Chunk* pChunk)
      {






            if(!GetChunkIsMMapped(pChunk))
               return GetChunkSize(pChunk) + kSizeTypeSize;
            return GetChunkSize(pChunk);

      }




      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetNextChunk(const Chunk* pChunk)
      {
         return reinterpret_cast<Chunk*>
                (const_cast<char*>(((const char*)pChunk) + (pChunk->mnSize & kChunkSizeMask)));
      }




      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetPrevChunk(const Chunk* pChunk)
      {




            ;


         return reinterpret_cast<Chunk*>(const_cast<char*>((const char*)pChunk - pChunk->mnPriorSize));
      }




      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetChunkAtOffset(const Chunk* pChunk, int nOffset)
      {
         return reinterpret_cast<Chunk*>(const_cast<char*>((const char*)pChunk + nOffset));
      }




      inline
      int GeneralAllocator::GetChunkIsInUse(const Chunk* pChunk)
      {
         const Chunk* const pNextChunk = reinterpret_cast<const Chunk*>
                                         ((const char*)pChunk + (pChunk->mnSize & kChunkSizeMask));

         return (int)(pNextChunk->mnSize & kChunkFlagPrevInUse);
      }




      inline
      void GeneralAllocator::SetChunkIsInUse(Chunk* pChunk)
      {


         (reinterpret_cast<Chunk*>(((char*)pChunk) + (pChunk->mnSize & kChunkSizeMask)))->mnSize
             |= kChunkFlagPrevInUse;
      }




      inline void GeneralAllocator::ClearChunkInUse(Chunk* pChunk)
      {


         (reinterpret_cast<Chunk*>(((char*)pChunk) + (pChunk->mnSize & kChunkSizeMask)))->mnSize
             &= (size_t)~kChunkFlagPrevInUse;
      }




      inline
      int GeneralAllocator::GetChunkInUseOffset(const Chunk* pChunk, int nOffset)
      {
         return (int)
            ((reinterpret_cast<const Chunk*>(((const char*)pChunk) + nOffset))->mnSize & kChunkFlagPrevInUse);
      }




      inline
      void GeneralAllocator::SetChunkInUseOffset(Chunk* pChunk, int nOffset)
      {
         reinterpret_cast<Chunk*>(((char*)pChunk) + nOffset)->mnSize |= kChunkFlagPrevInUse;
      }




      inline
      void GeneralAllocator::ClearChunkInUseOffset(Chunk* pChunk, int nOffset)
      {
         reinterpret_cast<Chunk*>(((char*)pChunk) + nOffset)->mnSize &= (size_t)~kChunkFlagPrevInUse;
      }




      inline
      void GeneralAllocator::SetChunkSize(Chunk* pChunk, size_type nSize)
      {
         pChunk->mnSize = nSize;
      }




      inline
      void GeneralAllocator::SetChunkSizePreserveFlags(Chunk* pChunk, size_type nSize)
      {

         pChunk->mnSize = ((pChunk->mnSize & kChunkFlagAll) | nSize);
      }




      inline
      GeneralAllocator::size_type GeneralAllocator::GetNextChunkPrevSize(const Chunk* pChunk, size_type nSize)
      {
         return reinterpret_cast<const Chunk*>((const char*)pChunk + nSize)->mnPriorSize;
      }




      inline
      void GeneralAllocator::SetNextChunkPrevSize(Chunk* pChunk, size_type nSize)
      {
         reinterpret_cast<Chunk*>((char*)pChunk + nSize)->mnPriorSize = nSize;
      }




      inline
      void GeneralAllocator::LinkChunk(Chunk* pChunk, Chunk* pPrev, Chunk* pNext)
      {
         pChunk->mpPrevChunk = pPrev;
         pChunk->mpNextChunk = pNext;
         pPrev->mpNextChunk = pChunk;
         pNext->mpPrevChunk = pChunk;
      }




      inline
      void GeneralAllocator::UnlinkChunk(const Chunk* pChunk)
      {
         pChunk->mpPrevChunk->mpNextChunk = pChunk->mpNextChunk;
         pChunk->mpNextChunk->mpPrevChunk = pChunk->mpPrevChunk;





      }




      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetFirstChunkInBin(const Chunk* pBin)
      {
         return pBin->mpNextChunk;
      }




      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetLastChunkInBin(const Chunk* pBin)
      {
         return pBin->mpPrevChunk;
      }



      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetNextBin(Chunk* pBin)
      {

         return reinterpret_cast<Chunk*>((char*)pBin + (sizeof(Chunk*) * 2));
      }




      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetBin(int nIndex) const
      {




         return reinterpret_cast<Chunk*>
                (const_cast<char*>((const char*)(mpBinArray + (nIndex * 2)) - (kSizeTypeSize * 2)));
      }




      inline
      bool GeneralAllocator::SizeIsWithinSmallBinRange(size_type nSize)
      {
         return nSize < (size_type)kLargeBinMinChunkSize;
      }




      inline
      int GeneralAllocator::GetSmallBinIndexFromChunkSize(size_type nSize)
      {
         return (int)(nSize / kSmallBinSizeIncrement);
      }




      inline
      int GeneralAllocator::GetBinIndexFromChunkSize(size_type nSize)
      {
         if(SizeIsWithinSmallBinRange(nSize))
            return GetSmallBinIndexFromChunkSize(nSize);
         return GetLargeBinIndexFromChunkSize(nSize);
      }





      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetUnsortedBin() const
      {
         return GetBin(1);
      }




      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetInitialTopChunk() const
      {
         return GetUnsortedBin();
      }




      inline
      bool GeneralAllocator::GetChunkIsListHead(const Chunk* pChunk) const
      {
         return ((const char*)pChunk >= (const char*)mpBinArray) &&
                ((const char*)pChunk < ((const char*)mpBinArray + sizeof(mpBinArray)));
      }




      inline
      GeneralAllocator::Chunk* GeneralAllocator::GetFenceChunk(const CoreBlock* pCoreBlock)
      {
         return reinterpret_cast<Chunk*>
                (const_cast<char*>((const char*)pCoreBlock + pCoreBlock->mnSize - kDoubleFenceChunkSize));
      }




      inline
      int GeneralAllocator::GetBinBitmapWordFromBinIndex(int nBinIndex)
      {
         return (nBinIndex >> kBinBitmapShift);
      }



      inline
      int GeneralAllocator::GetBinBitmapBitFromBinIndex(int nBinIndex)
      {
         return (1 << (nBinIndex & ((1 << kBinBitmapShift) - 1)));
      }




      inline
      void GeneralAllocator::MarkBinBitmapBit(int nBinIndex)
      {
         const int nWord = GetBinBitmapWordFromBinIndex(nBinIndex);
         const int nBit = GetBinBitmapBitFromBinIndex(nBinIndex);
         mBinBitmap[nWord] |= (unsigned)nBit;
      }




      inline
      void GeneralAllocator::UnmarkBinBitmapBit(int nBinIndex)
      {
         const int nWord = GetBinBitmapWordFromBinIndex(nBinIndex);
         const int nBit = GetBinBitmapBitFromBinIndex(nBinIndex);
         mBinBitmap[nWord] &= (unsigned)~nBit;
      }




      inline
      int GeneralAllocator::GetBinBitmapBit(int nBinIndex) const
      {
         const int nWord = GetBinBitmapWordFromBinIndex(nBinIndex);
         const int nBit = GetBinBitmapBitFromBinIndex(nBinIndex);
         return (int)(mBinBitmap[nWord] & (unsigned)nBit);
      }




      inline
      int GeneralAllocator::GetFastBinChunksExist() const
      {
         return (int)(mnMaxFastBinChunkSize & kFlagFastBinChunksExist);
      }



      inline
      void GeneralAllocator::SetFastBinChunksExist(bool bExist)
      {
         if(bExist)
            mnMaxFastBinChunkSize |= (size_type) kFlagFastBinChunksExist;
         else
            mnMaxFastBinChunkSize &= (size_type)~kFlagFastBinChunksExist;
      }




      inline
      bool GeneralAllocator::GetCoreIsContiguous() const
      {

         return (mHeadCoreBlock.mpNextCoreBlock == mHeadCoreBlock.mpPrevCoreBlock);
      }




      inline
      unsigned GeneralAllocator::GetMaxFastBinChunkSize() const
      {
         return (mnMaxFastBinChunkSize & ~kFlagFastBinChunksExist);
      }




      inline
      void GeneralAllocator::SetMaxFastBinDataSize(size_type nSize)
      {
         const unsigned nExistingFlags = (mnMaxFastBinChunkSize & kFlagFastBinChunksExist);
         if(nSize)
         {
            if(nSize > kFastBinMaxDataSize)
               nSize = kFastBinMaxDataSize;
            mnMaxFastBinChunkSize = GetChunkSizeFromDataSize(nSize) | nExistingFlags;
         }
         else
            mnMaxFastBinChunkSize = nExistingFlags;
      }

   }

}
