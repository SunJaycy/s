
















namespace rw
{
   namespace core
   {
      extern GeneralAllocator* gpEAGeneralAllocator;





























      template <class T>
      class GeneralAllocatorSTL
      {
      public:
         typedef size_t size_type;
         typedef ptrdiff_t difference_type;
         typedef T* pointer;
         typedef const T* const_pointer;
         typedef T& reference;
         typedef const T& const_reference;
         typedef T value_type;

         GeneralAllocatorSTL(){}
         GeneralAllocatorSTL(const GeneralAllocatorSTL<T>&) {}
        ~GeneralAllocatorSTL() {}
         template <class T1> GeneralAllocatorSTL(const GeneralAllocatorSTL<T1>&){}
         template <class T1> struct rebind { typedef GeneralAllocatorSTL<T1> other; };

         T* address(T& t) const { return &t; }
         const T* address(const T& t) const { return &t; }

         T* allocate(size_type n, const void* = 0)
         {
             ;

             return (T*)gpEAGeneralAllocator->Malloc(n * sizeof(T));
         }

         void deallocate(T* p, size_type)
         {
             ;
             gpEAGeneralAllocator->Free(p);
         }

         void construct(T* p, const T& value) { new(p) T(value); }
         void destroy(T* p) { p->~T(); }
         size_type max_size() const { return size_type(-1) / sizeof(T); }
      };



      template<class T>
      inline bool operator==(const GeneralAllocatorSTL<T>&, const GeneralAllocatorSTL<T>&) { return true; }



      template<class T>
      inline bool operator!=(const GeneralAllocatorSTL<T>&, const GeneralAllocatorSTL<T>&) { return false; }

      template<> class GeneralAllocatorSTL<void>
      {
      public:
         typedef size_t size_type;
         typedef ptrdiff_t difference_type;
         typedef void* pointer;
         typedef const void* const_pointer;
         typedef void value_type;

         template<class T1> struct rebind { typedef GeneralAllocatorSTL<T1> other; };
      };


















   }

}
