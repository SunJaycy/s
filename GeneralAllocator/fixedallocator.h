




























namespace rw
{
   namespace core
   {








      template <class T, int alignment = 0>
      class FixedAllocator
      {
      public:
         enum { kDefaultCountPerCoreBlock = 128 };



         typedef T value_type;

         typedef void* (*CoreAllocationFunction)(size_t nSize, void* pContext);
         typedef void (*CoreFreeFunction)(void* pCore, void* pContext);






         FixedAllocator(size_t nCountPerCoreBlock = kDefaultCountPerCoreBlock, void* pInitialCore = 0, size_t nInitialCoreSize = (size_t)(~0),
                        CoreAllocationFunction pCoreAllocationFunction = 0,
                        CoreFreeFunction pCoreFreeFunction = 0, void* pCoreFunctionContext = 0);




         ~FixedAllocator();























         bool Init(size_t nCountPerCoreBlock = kDefaultCountPerCoreBlock, void* pCore = 0, size_t nCoreSize = 0,
                   CoreAllocationFunction pCoreAllocationFunction = 0,
                   CoreFreeFunction pCoreFreeFunction = 0, void* pCoreFunctionContext = 0);






         bool Shutdown();

















         void* Malloc();
















         void Free(void* pData);













         bool AddCore(void* pCore = 0, size_t nCoreSize = 0);

      protected:









         struct Chunk{
            Chunk* mpNext;
         };









         struct CoreBlock{
            CoreBlock* mpNext;
            size_t mnSize;
            char mData[4];
         };











         size_t mnCountPerCoreBlock;
         CoreBlock* mpHeadCoreBlock;
         Chunk* mpHeadChunk;
         CoreAllocationFunction mpCoreAllocationFunction;
         CoreFreeFunction mpCoreFreeFunction;
         void* mpCoreFunctionContext;
      };

      void* DefaultFixedAllocationFunction(size_t nSize, void* pContext);
      void DefaultFixedFreeFunction(void* pBlock, void* pContext);



      void* NULLFixedAllocationFunction(size_t nSize, void* pContext);



      void NULLFixedFreeFunction(void *pData, void* pContext);

   }

}






namespace rw
{
   namespace core
   {



      template <class T, int alignment>
      inline FixedAllocator<T, alignment>::FixedAllocator(size_t nCountPerCoreBlock, void* pInitialCore, size_t nInitialCoreSize,
                                               CoreAllocationFunction pCoreAllocationFunction,
                                               CoreFreeFunction pCoreFreeFunction, void* pCoreFunctionContext)
         : mnCountPerCoreBlock(kDefaultCountPerCoreBlock),
            mpHeadCoreBlock(0),
            mpHeadChunk(0),
            mpCoreAllocationFunction(DefaultFixedAllocationFunction),
            mpCoreFreeFunction(DefaultFixedFreeFunction),
            mpCoreFunctionContext(0)
      {
         Init(nCountPerCoreBlock, pInitialCore, nInitialCoreSize, pCoreAllocationFunction, pCoreFreeFunction, pCoreFunctionContext);
      }




      template <class T, int alignment>
      inline FixedAllocator<T, alignment>::~FixedAllocator()
      {
         Shutdown();
      }




      template <class T, int alignment>
      inline bool FixedAllocator<T, alignment>::Init(size_t nCountPerCoreBlock, void* pCore, size_t nCoreSize,
                                             CoreAllocationFunction pCoreAllocationFunction,
                                             CoreFreeFunction pCoreFreeFunction, void* pCoreFunctionContext)
      {
         if(nCountPerCoreBlock)
            mnCountPerCoreBlock = nCountPerCoreBlock;
         if(pCoreAllocationFunction)
            mpCoreAllocationFunction = pCoreAllocationFunction;
         if(pCoreFreeFunction)
            mpCoreFreeFunction = pCoreFreeFunction;
         mpCoreFunctionContext = pCoreFunctionContext;

         if(!mpHeadCoreBlock)
            return AddCore(pCore, nCoreSize);
         return false;
      }




      template <class T, int alignment>
      bool FixedAllocator<T, alignment>::Shutdown()
      {
         while(mpHeadCoreBlock)
         {
            CoreBlock* const pChunkTemp = mpHeadCoreBlock;
            mpHeadCoreBlock = mpHeadCoreBlock->mpNext;
            mpCoreFreeFunction(pChunkTemp, mpCoreFunctionContext);
         }
         return true;
      }




      template <class T, int alignment>
      inline void* FixedAllocator<T, alignment>::Malloc()
      {
         Top:
         if(mpHeadChunk)
         {
            Chunk* const pChunk = mpHeadChunk;
            mpHeadChunk = pChunk->mpNext;
            return pChunk;
         }

         if(AddCore())
            goto Top;
         return 0;
      }




      template <class T, int alignment>
      inline void FixedAllocator<T, alignment>::Free(void* pData)
      {






         Chunk* const pChunk = static_cast<Chunk*>(pData);
         pChunk->mpNext = mpHeadChunk;
         mpHeadChunk = pChunk;
      }




      template <class T, int alignment>
      inline bool FixedAllocator<T, alignment>::AddCore(void* pCore, size_t nCoreSize)
      {
         const int aligmentUsed = ((alignment <= 0) ? 8 : alignment);
         size_t nSizeOfT = (sizeof(T) >= sizeof(Chunk) ? sizeof(T) : sizeof(Chunk));
         nSizeOfT = (((nSizeOfT + (aligmentUsed - 1))) & ~(aligmentUsed - 1));

         if(pCore)
         {

            CoreBlock* const pCoreBlock = (CoreBlock*)pCore;
            pCoreBlock->mpNext = mpHeadCoreBlock;
            pCoreBlock->mnSize = nCoreSize;
            mpHeadCoreBlock = pCoreBlock;

            Chunk* pStart = (Chunk*)(((intptr_t)(pCoreBlock->mData + (aligmentUsed - 1))) & ~(aligmentUsed - 1));
            Chunk* pEnd = reinterpret_cast<Chunk*>((char*)pCoreBlock + nCoreSize - (2 * nSizeOfT));

            mpHeadChunk = pStart;
            while(pStart <= pEnd)
            {
               Chunk* const pNext = reinterpret_cast<Chunk*>((char*)pStart + nSizeOfT);
               pStart->mpNext = pNext;
               pStart = pNext;
            }
            pStart->mpNext = 0;

            return true;
         }

         if(nCoreSize)
         {
            if(nCoreSize == (size_t)-1)
               return false;
            else
            {
               pCore = mpCoreAllocationFunction(nCoreSize, mpCoreFunctionContext);
               if(!pCore)
                  return false;
            }
         }
         else
            nCoreSize = sizeof(CoreBlock*) + (nSizeOfT * mnCountPerCoreBlock);

         return AddCore(pCore, nCoreSize);
      }

   }

}
