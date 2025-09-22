






















namespace rw
{
   namespace core
   {

      void SystemAllocInit();
      void SystemAllocShutdown();

      void* SystemAlloc(size_t n);
      void SystemFree(void* p);
      void* SystemRealloc(void* p, size_t n);
































      template <class T>
      class SystemSTLAllocator
      {
      public:
         typedef size_t size_type;
         typedef ptrdiff_t difference_type;
         typedef T* pointer;
         typedef const T* const_pointer;
         typedef T& reference;
         typedef const T& const_reference;
         typedef T value_type;

         SystemSTLAllocator(){}
         SystemSTLAllocator(const SystemSTLAllocator<T>&) {}
        ~SystemSTLAllocator() {}
         template <class T1> SystemSTLAllocator(const SystemSTLAllocator<T1>&){}
         template <class T1> struct rebind { typedef SystemSTLAllocator<T1> other; };

         T* address(T& t) const { return &t; }
         const T* address(const T& t) const { return &t; }
         T* allocate(size_type n, const void* = 0) { return (T*)SystemAlloc(n * sizeof(T)); }
         void deallocate(T* p, size_type) { SystemFree(p); }
         void construct(T* p, const T& value) { new(p) T(value); }
         void destroy(T* p) { p->~T(); }
         size_type max_size() const { return size_type(-1) / sizeof(T); }
      };



      template<class T>
      inline bool operator==(const SystemSTLAllocator<T>&, const SystemSTLAllocator<T>&) { return true; }



      template<class T>
      inline bool operator!=(const SystemSTLAllocator<T>&, const SystemSTLAllocator<T>&) { return false; }

      template<> class SystemSTLAllocator<void>
      {
      public:
         typedef size_t size_type;
         typedef ptrdiff_t difference_type;
         typedef void* pointer;
         typedef const void* const_pointer;
         typedef void value_type;

         template<class T1> struct rebind { typedef SystemSTLAllocator<T1> other; };
      };


















   }

}















#include <stdlib.h>


namespace rw
{
   namespace core
   {
































































         inline void SystemAllocInit()
         {

         }



         inline void SystemAllocShutdown()
         {

         }



         inline void* SystemAlloc(size_t n)
         {
            return malloc(n);
         }



         inline void SystemFree(void* p)
         {
            return free(p);
         }



         inline void* SystemRealloc(void* p, size_t nNewBytes)
         {
            return realloc(p, nNewBytes);
         }



   }

}
