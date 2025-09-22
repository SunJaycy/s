






















namespace rw
{
   namespace core
   {





      class HandleAllocator
      {
      public:

         typedef void* Handle;







         enum CompactionLevel
         {
            kCompactionLevelNone,
            kCompactionLevelMinor,
            kCompactionLevelMajor
         };








         enum CompactionStrategy
         {
            kCompactionStrategyNone,
            kCompactionStrategyLow,
            kCompactionStrategyHigh,
            kCompactionStrategyDefault
         };






         HandleAllocator(rw::core::GeneralAllocator* pGeneralAllocator = 0, size_t nInitialHandleCount = 256);





         virtual ~HandleAllocator();






         virtual bool Init(rw::core::GeneralAllocator* pGeneralAllocator, size_t nInitialHandleCount = 256);




         virtual bool Shutdown();





         virtual Handle Malloc(size_t nSize);





         virtual Handle MallocAligned(size_t nSize, size_t nAlignment, size_t nAlignmentOffset = 0);





         virtual Handle Calloc(size_t nElementCount, size_t nElementSize);







         virtual bool Realloc(Handle h, size_t nNewSize);






         virtual void Free(Handle h);









         virtual void* Lock(Handle h);





         virtual void Unlock(Handle h);







         virtual bool CompactHandle(Handle h, CompactionStrategy strategy = kCompactionStrategyDefault);




         virtual void Compact(CompactionLevel level = kCompactionLevelMajor, CompactionStrategy strategy = kCompactionStrategyDefault);




         virtual bool ValidateHandle(Handle h);






         virtual Handle GetHandleFromAddress(const void* pData);





         virtual unsigned GetLockCount(Handle h);






         enum Option{
            kOptionNone,
            kOptionEnableThreadSafety
         };




         virtual void SetOption(Option option, int nValue);


      protected:
         static void* CoreAllocationFunction(size_t nSize, void* pContext);
         static void CoreFreeFunction(void* pCore, void* pContext);

         enum { kMaxLockCount = ((1 << 15) - 1) };









         struct HandleInfo {
            void* mpData;







            struct {
               int mnLockCount : 15;
               int mnAlignment : 8;
               int mnAlignmentOffset : 8;
               int mbHigh : 1;
            } mBitfield;
         };





         class FixedAllocatorEx : public FixedAllocator<HandleInfo> {
         public:
            FixedAllocatorEx() : FixedAllocator<HandleInfo>(512){}

            HandleInfo* FindHandleInfo(const void* pData);
            bool ValidateAddress(const Handle h);

            void* BeginGetNext();
            HandleInfo* GetNext(void* pContext);
            void EndGetNext(void* pContext);

         protected:
            struct IterationContext{
               CoreBlock* mpCurrentCoreBlock;
               HandleInfo* mpCurrentHandleInfo;
            };
            IterationContext mIterationContext;
         };

         int mnHandleCount;
         FixedAllocatorEx mHandleInfoAllocator;
         GeneralAllocator* mpGeneralAllocator;

         rw::core::thread::Mutex mpMutex;



      private:
         HandleAllocator(const HandleAllocator&);
         HandleAllocator operator=(const HandleAllocator&);
      };

   }

}
