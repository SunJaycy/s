






























namespace rw
{
   namespace core
   {























      class GeneralAllocatorDebug : public GeneralAllocator
      {
      public:
         GeneralAllocatorDebug(void* pInitialCore = 0, size_t nInitialCoreSize = 0,
                               bool bShouldFreeInitialCore = true, bool bShouldTrimInitialCore = false,
                               CoreFreeFunction pInitialCoreFreeFunction = 0, void* pInitialCoreFreeFunctionContext = 0);
        ~GeneralAllocatorDebug();

         bool Init(void* pInitialCore = 0, size_t nInitialCoreSize = 0,
                              bool bShouldFreeInitialCore = true, bool bShouldTrimInitialCore = false,
                              CoreFreeFunction pInitialCoreFreeFunction = 0, void* pInitialCoreFreeFunctionContext = 0);
         bool Shutdown();





         virtual void* Malloc(size_t nSize, int nAllocationFlags = 0);
         virtual void* MallocAligned(size_t nSize, size_t nAlignment, size_t nAlignmentOffset = 0, int nAllocationFlags = 0);
         virtual void* Calloc(size_t nElementCount, size_t nElementSize, int nAllocationFlags = 0);
         virtual void* Realloc(void* p, size_t nNewSize, int nAllocationFlags = 0);
         virtual void Free(void* p);

         virtual size_t GetUsableSize(const void* pData) const;
         virtual bool ValidateHeap(HeapValidationLevel heapValidationLevel = kHeapValidationLevelBasic);
         virtual void TraceAllocatedMemory(TraceFunction pTraceFunction = 0, void* pTraceFunctionContext = 0, void* pStorage = 0, size_t nStorageSize = 0);
         virtual void* TakeSnapshot(int nBlockTypeFlags = kBlockTypeAll, bool bMakeCopy = false, void* pStorage = 0, size_t nStorageSize = 0);
         virtual void FreeSnapshot(void* pSnapshot);












         void SetAllocator(GeneralAllocator* pAllocator);







         unsigned GetDefaultDebugDataFlags() const;







         bool GetDefaultDebugDataFlag(unsigned debugDataFlag) const;







         void SetDefaultDebugDataFlags(unsigned flags);








         void SetDefaultDebugDataFlag(unsigned debugDataFlag);
















         virtual void* MallocDebug(size_t nSize, int nAllocationFlags = 0,
                                        unsigned nDebugDataFlags = 0, const char* pName = 0, const char* pFile = 0, int nLine = 0);
         virtual void* MallocAlignedDebug(size_t nSize, size_t nAlignment, size_t nAlignmentOffset, int nAllocationFlags = 0,
                                               unsigned nDebugDataFlags = 0, const char* pName = 0, const char* pFile = 0, int nLine = 0);
         virtual void* CallocDebug(size_t nElementCount, size_t nElementSize, int nAllocationFlags = 0,
                                        unsigned nDebugDataFlags = 0, const char* pName = 0, const char* pFile = 0, int nLine = 0);









         enum DelayedFreePolicy
         {
            kDelayedFreePolicyNone,
            kDelayedFreePolicyCount,
            kDelayedFreePolicyVolume,
            kDelayedFreePolicyTime
         };











         virtual void SetDelayedFreePolicy(DelayedFreePolicy policy, int value);





         virtual void ClearDelayedFreeList();













         virtual bool ValidateAddress(const void* pData, bool bPointerIsAllocation = true);















         enum DefaultFillValue
         {
            kDefaultFillValueDisabled = 0x01,
            kDefaultFillValueFree = 0xdd,
            kDefaultFillValueDelayedFree = 0xde,
            kDefaultFillValueNew = 0xcd,
            kDefaultFillValueGuard = 0xab,
            kDefaultFillValueUnusedCore = 0xfe
         };













         virtual void SetFillValues(unsigned char cFree = kDefaultFillValueFree,
                                        unsigned char cDelayedFree = kDefaultFillValueDelayedFree,
                                        unsigned char cNew = kDefaultFillValueNew,
                                        unsigned char cGuard = kDefaultFillValueGuard,
                                        unsigned char cUnusedCore = kDefaultFillValueUnusedCore);









         virtual void SetGuardSize(float fGuardSizeRatio, size_t nMinGuardSize, size_t nMaxGuardSize);







         int GetCurrentGroupId() const;






         int SetCurrentGroupId(int nGroupId);









         enum DebugDataLocation
         {
            kDebugDataLocationBlock,
            kDebugDataLocationSeparate,
            kDebugDataLocationDefault
         };





         virtual void SetDefaultDebugDataLocation(DebugDataLocation debugDataLocation);


























         enum DebugDataId
         {
            kDebugDataIdNone = 0,
            kDebugDataIdAllocator = 1,
            kDebugDataIdSize = 2,
            kDebugDataIdFlags = 3,
            kDebugDataIdAlignment = 4,
            kDebugDataIdName = 5,
            kDebugDataIdPlace = 6,
            kDebugDataIdCallStack = 7,
            kDebugDataIdChecksum = 8,
            kDebugDataIdAllocationCount = 9,
            kDebugDataIdAllocationTime = 10,
            kDebugDataIdGuard = 11,
            kDebugDataIdOverhead = 12,
            kDebugDataIdGroup = 13,
            kDebugDataIdInternalCount = 14,
            kDebugDataIdUser = 1000
         };

         struct FileLineInfo{
            const char* mpFile;
            int mnLine;
         };

         struct AlignmentInfo{
            size_t mnAlignment;
            size_t mnAlignmentOffset;
         };

         typedef uint16_t DebugDataIdType;
         typedef uint16_t DebugDataLengthType;





         enum DebugRecordConstants
         {
            kDebugBlockSizeSize = sizeof(DebugDataLengthType),
            kDebugRecordSizeSize = sizeof(DebugDataLengthType),
            kDebugRecordIdSize = sizeof(DebugDataIdType),
            kDebugRecordOverheadSize = kDebugRecordSizeSize + kDebugRecordIdSize,
         };








         virtual size_t GetDebugDataLength(const void* pData, DebugDataLocation debugDataLocation = kDebugDataLocationDefault, void** ppDebugData = 0);






         size_t GetDebugDataRecordLength(size_t nDebugDataLength) const;








         virtual void* GetDebugData(const void* pData, DebugDataIdType id,
                                       void* pDebugData, size_t nDataLength, size_t* pActualDataLength = 0,
                                       DebugDataLocation debugDataLocation = kDebugDataLocationDefault);








         virtual void* SetDebugData(void* pData, DebugDataIdType id,
                                       const void* pDebugData, size_t nDataLength,
                                       DebugDataLocation debugDataLocation = kDebugDataLocationDefault);









         struct Metrics
         {
            uint64_t mnAllocationCount;
            uint64_t mnAllocationCountHistorical;
            uint64_t mnAllocationVolume;
            uint64_t mnAllocationVolumeHistorical;
            uint64_t mnFreeCountHistorical;

            uint64_t mnFreeVolumeHistorical;
         };









         enum MetricType
         {
            kMetricTypeAll,
            kMetricTypeSystem,
            kMetricTypeDebug,
            kMetricTypeUser,
            kMetricTypeCount
         };




         virtual const Metrics& GetMetrics(MetricType metricsType);










         virtual uint64_t GetAllocationCount() const;







         enum OptionDebug
         {
            kOptionEnableMetrics = 1000,
            kOptionEnablePtrValidation,
         };







         virtual void SetOption(int option, int nValue);

      protected:
         struct DebugDataInfoShared{
            size_t mnRecordSize;
            size_t mnRecordDataSize;
            DebugDataLocation mDebugDataLocation;
         };

         struct DebugDataInfo{
            size_t mnDebugDataSize;
            DebugDataInfoShared mShared[kDebugDataIdInternalCount];
            size_t mnBlockUsage;
            size_t mnSeparateUsage;

            size_t mnSize;
            int mnAllocationFlags;
            size_t mnAlignment;
            size_t mnAlignmentOffset;
            FileLineInfo mFileLineInfo;
            void* mpReturnAddressArray[24];
         };

         void* MallocInternal(size_t nSize, int nAllocationFlags = 0);
         DebugDataLocation GetDefaultDebugDataLocation(DebugDataIdType id) const;
         size_t GetDebugDataLengthInternal(const char* pDebugBlock, size_t nDebugBlockLength, void** ppDebugData) const;
         void* GetDebugDataInternal(const char* pDebugBlock, size_t nDebugBlockLength, DebugDataIdType id, void* pDebugData, size_t dataLength, size_t* pActualDataLength) const;
         void* SetDebugDataInternal(char* pDebugBlock, size_t nDebugBlockLength, DebugDataIdType id, const void* pDebugData, size_t dataLength) const;
         size_t FormatPlace(char* pBuffer, size_t nBufferLength, const char* pFile, int nLine, const char* pFunction) const;
         void GetDebugInfoForAllocation(DebugDataInfo& debugDataInfo, size_t nSize, int nAllocationFlags, size_t nAlignment = 0, size_t nAlignmentOffset = 0);
         bool SetDebugInfoForAllocation(DebugDataInfo& debugDataInfo, void* pData, bool bAttemptNewFill);
         void ClearDelayedFreeList(DelayedFreePolicy delayedFreePolicy, int nDelayedFreePolicyValue);
         size_t GetGuardSizeForBlock(size_t nBlockSize);
         bool VerifyGuardFill(const Chunk* pChunk, bool bChunkIsInAList, bool bForceVerify);
         bool VerifyDelayedFreeFill(const Chunk* pChunk);
         void FreeDelayedFreeChunk(const Chunk* pChunk);
         void DoFailureNotification(const Chunk* pChunk, const char* pMessage);
         int CheckDelayedFreeChunk(const Chunk* pChunk);
         size_t DescribeChunk(const Chunk* pChunk, char* pBuffer, size_t nBufferLength);
         void CollectStats(const Chunk* pChunk, bool bMalloc);
         bool AddToDebugDataMap(const void* pData, size_t nDebugDataLength, char* pDebugBlock, bool bAllowDuplicate);
         bool RemoveFromDebugDataMap(const void* pData, bool bFreeDebugData);
         bool VerifyFromDebugDataMap(const void* pData) const;
         static void* HashAllocationFunction(size_t n, void* pContext);
         static void HashFreeFunction(void* p, void* pContext);
         void* AllocatorMalloc(size_t n);
         void AllocatorFree(void* p);

      protected:

         bool mbInitializedDebug;



         unsigned mnDebugDataFlags;

         unsigned mnNextDebugDataFlags;

         const char* mpNextAllocationName;

         const char* mpNextAllocationFile;

         int mnNextAllocationLine;

         const char* mpNextAllocationFunc;

         int mnCurrentGroupId;

         int mnPtrValidationDisabled;



         float mfGuardSizeRatio;

         size_t mnMinGuardSize;

         size_t mnMaxGuardSize;


         DelayedFreePolicy mDelayedFreePolicy;
         int mDelayedFreePolicyValue;
         Chunk mDelayedFreeChunkListHead;
         size_t mDelayedFreeListSize;
         size_t mDelayedFreeVolume;



         bool mbMetricsEnabled;

         uint64_t mnAllocationCountHistorical;

         Metrics mAllocationMetrics[kMetricTypeCount];

         unsigned int mnLastAllocationTime;

         unsigned int mnLastFreeTime;


         GeneralAllocator* mpAllocator;
         DebugDataLocation mnDebugDataLocationDefault;



         class HashTable
         {
         public:
            typedef void* (*AllocationFunction)(size_t n, void* pContext);
            typedef void (*FreeFunction)(void* p, void* pContext);

            HashTable() : mppHashTable(0), mbReHashing(false), mnHashTableSize(0), mnHashTableSizeMin(4096), mnHashElementCount(0),
                          mpAllocationFunction(0), mpFreeFunction(0), mpFunctionContext(0) { }
           ~HashTable() { Clear(true, false); }

            bool Insert(const void* pKey, char* pValue);
            bool Find(const void* pKey, char*** pppValue) const;
            bool Remove(const void* pKey, bool bFreeValue);
            void Clear(bool bDestroyTable, bool bFreeValues);
            void Nuke();
            size_t Size() const { return mnHashElementCount; }
            void SetAllocationFunction(AllocationFunction pAllocationFunction, FreeFunction pFreeFunction, void* pFunctionContext)
                      { mpAllocationFunction = pAllocationFunction; mpFreeFunction = pFreeFunction; mpFunctionContext = pFunctionContext; }

         protected:
            bool ReHash(size_t nNewTableSize);
            size_t Hash(const void* pKey) const { return (size_t)(((uintptr_t)pKey / 8) % mnHashTableSize); }

            struct HashPair{
               HashPair(const void* pKey = 0, char* pValue = 0, HashPair* pNext = 0) : mpKey(pKey), mpValue(pValue), mpNext(pNext) {}

               const void* mpKey;
               char* mpValue;
               HashPair* mpNext;
            };

            HashPair** mppHashTable;
            bool mbReHashing;
            size_t mnHashTableSize;
            size_t mnHashTableSizeMin;
            size_t mnHashElementCount;
            AllocationFunction mpAllocationFunction;
            FreeFunction mpFreeFunction;
            void* mpFunctionContext;
         };

         bool mbHashTableEnabled;
         HashTable mHashTable;
      private:

          GeneralAllocatorDebug(const GeneralAllocatorDebug & );
          GeneralAllocatorDebug & operator=(const GeneralAllocatorDebug &);

      };

   }

}















namespace rw
{
   namespace core
   {



      inline
      size_t GeneralAllocatorDebug::GetDebugDataRecordLength(size_t nDebugDataLength) const
      {
         return (nDebugDataLength > 0) ? (nDebugDataLength + kDebugRecordOverheadSize) : 0;
      }




      inline
      unsigned GeneralAllocatorDebug::GetDefaultDebugDataFlags() const
      {
         return mnDebugDataFlags;
      }




      inline
      bool GeneralAllocatorDebug::GetDefaultDebugDataFlag(unsigned debugDataFlag) const
      {
         return (mnDebugDataFlags & (1 << debugDataFlag)) != 0;
      }




      inline
      void GeneralAllocatorDebug::SetDefaultDebugDataFlags(unsigned flags)
      {
         mnDebugDataFlags = flags;
      }




      inline
      void GeneralAllocatorDebug::SetDefaultDebugDataFlag(unsigned debugDataFlag)
      {
         mnDebugDataFlags = mnDebugDataFlags | (1 << debugDataFlag);
      }




      inline
      int GeneralAllocatorDebug::GetCurrentGroupId() const
      {
         return mnCurrentGroupId;
      }




      inline
      int GeneralAllocatorDebug::SetCurrentGroupId(int nGroupId)
      {
         const int nPreviousGroupId = mnCurrentGroupId;
         mnCurrentGroupId = nGroupId;
         return nPreviousGroupId;
      }




      inline
      GeneralAllocatorDebug::DebugDataLocation GeneralAllocatorDebug::GetDefaultDebugDataLocation(DebugDataIdType id) const
      {
         if(id == kDebugDataIdGuard)
            return kDebugDataLocationBlock;
         return mnDebugDataLocationDefault;
      }




      inline
      void GeneralAllocatorDebug::SetDefaultDebugDataLocation(DebugDataLocation debugDataLocation)
      {
         if(debugDataLocation != kDebugDataLocationDefault)
         {
            mnDebugDataLocationDefault = debugDataLocation;
            if(debugDataLocation == kDebugDataLocationSeparate)
               SetOption(kOptionEnablePtrValidation, true);
         }
      }


   }

}
