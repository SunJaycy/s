



























































namespace rw
{




   namespace core
   {
























      class StackAllocator
      {
      public:
         typedef void* (*CoreAllocationFunction)(size_t nSize, size_t* pSizeResult, void* pContext);
         typedef void (*CoreFreeFunction)(void* pBlock, void* pContext);








         StackAllocator(void* pData = 0, size_t nInitialSize = (size_t)(~0),
                        CoreAllocationFunction pCoreAllocationFunction = 0,
                        CoreFreeFunction pCoreFreeFunction = 0, void* pCoreFunctionContext = 0);







         StackAllocator(const StackAllocator& stackAllocator);





         ~StackAllocator();






         StackAllocator& operator=(const StackAllocator& stackAllocator);














         void Init(void* pData = 0, size_t nInitialSize = 0,
                   CoreAllocationFunction pCoreAllocationFunction = 0,
                   CoreFreeFunction pCoreFreeFunction = 0, void* pCoreFunctionContext = 0);





         void Shutdown();





         void* Malloc(size_t nSize, bool bBoundsCheck = true);





         void* Calloc(size_t nElementCount, size_t nElementSize, bool bBoundsCheck = true);









         void* Realloc(void* pData, size_t nNewSize, bool bBoundsCheck = true);












         void* MallocAligned(size_t nSize, size_t nAlignment, size_t nAlignmentOffset = 0, bool bBoundsCheck = true);








         void Free(void* pData);











         void FreeObjects(const void* pAddress);







         void Reset();





         size_t GetDefaultBlockSize();





         void SetDefaultBlockSize(size_t nDefaultBlockSize);







         void PushBookmark(const void* pAddress = 0);





         void PopBookmark();





         size_t GetMemoryUsage();
















            void* GetCurrentObjectBegin();









            void* GetCurrentObjectEnd();






            size_t GetCurrentObjectSize();






            size_t GetCurrentFreeSpace();













            void ExtendCurrentObject(size_t nSize, bool bBoundsCheck = true);








            void AppendToCurrentObject(const void* pData, size_t nSize, bool bBoundsCheck = true);













            template<class T>
            void AppendToCurrentObject(const T& t, bool bBoundsCheck = true);







            template<class T>
            void AppendToCurrentObjectMemcpy(const T& t, bool bBoundsCheck = true);





            void* FinishCurrentObject();



      protected:




         enum Constants{
            kMinAlignment = 8,
            kMinAlignmentMask = kMinAlignment - 1,
            kMinAlignmentMaskInverse = ~kMinAlignmentMask,
            kDefaultBlockSize = 8192,
            kBookmarkStackSize = 128
         };








         struct Block{
            Block* mpPrevBlock;
            char* mpEnd;
            char mData[4];
         };


         Block* GetBlockForAddress(const void* pAddress);



         void AllocateNewBlock(size_t nExtraSize);
         void FreeObjectsEx(const void* pAddress);



         size_t mnDefaultBlockSize;

         Block* mpCurrentBlock;

         char* mpCurrentBlockEnd;

         char* mpCurrentObjectBegin;


         char* mpCurrentObjectEnd;


         CoreAllocationFunction mpCoreAllocationFunction;

         CoreFreeFunction mpCoreFreeFunction;

         void* mpCoreFunctionContext;

         const void* mBookmarkStack[kBookmarkStackSize];

         size_t mnBookmarkStackIndex;
      };

   }

}






namespace rw
{
   namespace core
   {




      inline StackAllocator& StackAllocator::operator=(const StackAllocator& stackAllocator)
      {
         if(this != &stackAllocator)
            memcpy(this, &stackAllocator, sizeof(stackAllocator));
         return *this;
      }



      inline StackAllocator::StackAllocator(const StackAllocator& stackAllocator)
      {
         operator=(stackAllocator);
      }



      inline void* StackAllocator::Malloc(size_t nSize, bool bBoundsCheck)
      {

            ;


         nSize = (nSize + kMinAlignmentMask) & kMinAlignmentMaskInverse;





         if(bBoundsCheck && (((intptr_t)mpCurrentBlockEnd - ((intptr_t)mpCurrentObjectBegin + (intptr_t)nSize)) < 0))
            AllocateNewBlock(nSize);

         void* const pReturnValue = mpCurrentObjectBegin;
         mpCurrentObjectBegin += nSize;

             mpCurrentObjectEnd = mpCurrentObjectBegin;

         ;
         return pReturnValue;
      }




      inline void* StackAllocator::Calloc(size_t nElementCount, size_t nElementSize, bool bBoundsCheck)
      {
         const size_t nSize = nElementCount * nElementSize;
         void* const pReturnValue = Malloc(nSize, bBoundsCheck);
         if(!bBoundsCheck || pReturnValue)
            memset(pReturnValue, 0, nSize);
         return pReturnValue;
      }




      inline void StackAllocator::Free(void* )
      {


      }




      inline void StackAllocator::FreeObjects(const void* pAddress)
      {
         ;
         if((pAddress > mpCurrentBlock) && (pAddress < (void*)mpCurrentBlockEnd))
         {
            mpCurrentObjectBegin = reinterpret_cast<char*>(const_cast<void*>(pAddress));

               mpCurrentObjectEnd = mpCurrentObjectBegin;

         }
         else
            FreeObjectsEx(pAddress);
      }



      inline void StackAllocator::Reset()
      {

         Shutdown();
      }



      inline size_t StackAllocator::GetDefaultBlockSize()
      {
         return mnDefaultBlockSize;
      }




      inline void StackAllocator::SetDefaultBlockSize(size_t nDefaultBlockSize)
      {
         mnDefaultBlockSize = nDefaultBlockSize;
      }




      inline void StackAllocator::PushBookmark(const void* pAddress)
      {
          ;
         if(!pAddress)
            pAddress = mpCurrentObjectBegin;
          mBookmarkStack[mnBookmarkStackIndex++] = pAddress;
      }




      inline void StackAllocator::PopBookmark()
      {
          ;
         FreeObjects(mBookmarkStack[--mnBookmarkStackIndex]);
      }







      inline void* StackAllocator::GetCurrentObjectBegin()
      {
         return mpCurrentObjectBegin;
      }




      inline void* StackAllocator::GetCurrentObjectEnd()
      {
         return mpCurrentObjectEnd;
      }




      inline size_t StackAllocator::GetCurrentObjectSize()
      {
         return (size_t)(mpCurrentObjectEnd - mpCurrentObjectBegin);
      }




      inline size_t StackAllocator::GetCurrentFreeSpace()
      {
         return (size_t)(mpCurrentBlockEnd - mpCurrentObjectEnd);
      }




      inline void StackAllocator::ExtendCurrentObject(size_t nSize, bool bBoundsCheck)
      {

         if(bBoundsCheck && ((mpCurrentObjectEnd + nSize) > mpCurrentBlockEnd))
            AllocateNewBlock(nSize);
         mpCurrentObjectEnd += nSize;
      }




      inline void StackAllocator::AppendToCurrentObject(const void* pData, size_t nSize, bool bBoundsCheck)
      {

         if(bBoundsCheck && ((mpCurrentObjectEnd + nSize) > mpCurrentBlockEnd))
            AllocateNewBlock(nSize);
         memcpy(mpCurrentObjectEnd, pData, nSize);
         mpCurrentObjectEnd += nSize;
      }




      template <class T>
      inline void StackAllocator::AppendToCurrentObjectMemcpy(const T& t, bool bBoundsCheck)
      {

         if(bBoundsCheck && ((mpCurrentObjectEnd + sizeof(T)) > mpCurrentBlockEnd))
            AllocateNewBlock(sizeof(T));
         memcpy(mpCurrentObjectEnd, &t, sizeof(T));
         mpCurrentObjectEnd += sizeof(T);
      }




      template <class T>
      inline void StackAllocator::AppendToCurrentObject(const T& t, bool bBoundsCheck)
      {

         if(bBoundsCheck && ((mpCurrentObjectEnd + sizeof(T)) > mpCurrentBlockEnd))
            AllocateNewBlock(sizeof(T));
         new(mpCurrentObjectEnd) T(t);
         mpCurrentObjectEnd += sizeof(T);
      }




      inline void* StackAllocator::FinishCurrentObject()
      {
         void* const pReturnValue = mpCurrentObjectBegin;

         mpCurrentObjectEnd = (char*)(((size_t)mpCurrentObjectEnd + kMinAlignmentMask) & kMinAlignmentMaskInverse);
         if(mpCurrentObjectEnd > (char*)mpCurrentBlock)
            mpCurrentObjectEnd = mpCurrentBlockEnd;
         mpCurrentObjectBegin = mpCurrentObjectEnd;
         return pReturnValue;
      }




   }

}
