









































namespace rw
{









template<typename T>
struct MemoryDumpTraits
{
    static ResourceDescriptor GetResourceDescriptor(void)
    {
        ;
        return T::GetResourceDescriptor();
    }

    static ResourceDescriptor GetResourceDescriptor(const T& obj)
    {
        ;
        return T::GetResourceDescriptor(obj);
    }

    static void Release(T& obj)
    {
        ;
        obj.Release();
        return;
    }

    static core::arena::SizeAndAlignment *Unfix(void *obj, core::arena::SizeAndAlignment *offset)
    {
        ;
        return T::Unfix(obj, offset);
    }

    static void Refix(void *obj, void *offset, core::arena::ArenaIterator *iteratorPtr)
    {
        ;
        T::Refix(obj, offset, iteratorPtr);
        return;
    }

    static RwBool Fixup(void *obj, core::arena::ArenaIterator *iteratorPtr)
    {
        ;
        return T::Fixup(obj, iteratorPtr);
    }

    static void Destruct(void *obj)
    {
        ;
        T::Destruct(obj);
        return;
    }
};








template<>
struct MemoryDumpTraits<uint32_t>
{
public:

    static ResourceDescriptor
    GetResourceDescriptor(void)
    {
        ;
        return ResourceDescriptor(sizeof(uint32_t), sizeof(uint32_t));
    }

    static ResourceDescriptor
    GetResourceDescriptor(uint32_t& )
    {
        ;
        return GetResourceDescriptor();
    }

    static void
    Release(uint32_t& )
    {
        ;
        return;
    }

    static core::arena::SizeAndAlignment *
    Unfix(void *obj, core::arena::SizeAndAlignment *offset)
    {
        ;
        EndianSwap(*reinterpret_cast<uint32_t *>(obj));
        return offset;
    }

    static void
    Refix(void *obj, void *, core::arena::ArenaIterator *)
    {
        ;
        EndianSwap(*reinterpret_cast<uint32_t *>(obj));
        return;
    }

    static RwBool
    Fixup(void *obj, core::arena::ArenaIterator *)
    {
        ;
        EndianSwap(*reinterpret_cast<uint32_t *>(obj));
        return (!0);
    }

    static void
    Destruct(void *)
    {
        ;
        return;
    }
};








template<>
struct MemoryDumpTraits<RwChar>
{
public:

    static ResourceDescriptor
    GetResourceDescriptor(void)
    {
        ;
        return ResourceDescriptor(sizeof(RwChar), sizeof(RwChar));
    }

    static ResourceDescriptor
    GetResourceDescriptor(const RwChar& )
    {
        ;
        return ResourceDescriptor(sizeof(RwChar), sizeof(RwChar));
    }

    static void
    Release(RwChar& )
    {
        ;
        return;
    }

    static core::arena::SizeAndAlignment *
    Unfix(void *, core::arena::SizeAndAlignment *offset)
    {
        ;
        return offset;
    }

    static void
    Refix(void *, void *, core::arena::ArenaIterator *)
    {
        ;
        return;
    }

    static RwBool
    Fixup(void *, core::arena::ArenaIterator *)
    {
        ;
        return (!0);
    }

    static void
    Destruct(void *)
    {
        ;
        return;
    }
};


















template<typename First, typename Second, typename FirstMemoryDumpTraits = MemoryDumpTraits<First>,
                                          typename SecondMemoryDumpTraits = MemoryDumpTraits<Second> >
struct StaticPair
{
public:



    StaticPair(void)
    {
        ;
        return;
    }








    StaticPair(const First &first, const Second &second)
      : m_first(first),
        m_second(second)
    {
        ;
        return;
    }







    StaticPair(const StaticPair &rhs)
      : m_first(rhs.m_first),
        m_second(rhs.m_second)
    {
        ;
        return;
    }





    ~StaticPair()
    {
        ;
        Release();
        return;
    }








    StaticPair &
    operator=(const StaticPair &rhs)
    {
        ;
        m_first = rhs.m_first;
        m_second = rhs.m_second;
        return *this;
    }




    static ResourceDescriptor
    GetResourceDescriptor(void)
    {
        ;
        ResourceDescriptor firstResDesc = FirstMemoryDumpTraits::GetResourceDescriptor();
        ResourceDescriptor secondResDesc = SecondMemoryDumpTraits::GetResourceDescriptor();
        return GetResourceDescriptor(firstResDesc, secondResDesc);
    }




    static ResourceDescriptor
    GetResourceDescriptor(const First& first, const Second& second)
    {
        ;
        ResourceDescriptor firstResDesc = FirstMemoryDumpTraits::GetResourceDescriptor(first);
        ResourceDescriptor secondResDesc = SecondMemoryDumpTraits::GetResourceDescriptor(second);
        return GetResourceDescriptor(firstResDesc, secondResDesc);
    }




    static ResourceDescriptor
    GetResourceDescriptor(const StaticPair& obj)
    {
        ;
        ResourceDescriptor firstResDesc = FirstMemoryDumpTraits::GetResourceDescriptor(obj.m_first);
        ResourceDescriptor secondResDesc = SecondMemoryDumpTraits::GetResourceDescriptor(obj.m_second);
        return GetResourceDescriptor(firstResDesc, secondResDesc);
    }







    static StaticPair *
    Initialize(const Resource& resource)
    {
        ;
        return new (resource.GetMemoryResource()) StaticPair();
    }









    static StaticPair *
    Initialize(const Resource& resource, const First& first, const Second& second)
    {
        ;
        return new (resource.GetMemoryResource()) StaticPair(first, second);
    }








    static StaticPair *
    Initialize(const Resource& resource, const StaticPair& other)
    {
        ;
        return new (resource.GetMemoryResource()) StaticPair(other);
    }





    void
    Release()
    {
        ;
        FirstMemoryDumpTraits::Release(m_first);
        SecondMemoryDumpTraits::Release(m_second);
        return;
    }




    static core::arena::SizeAndAlignment *
    Unfix(void *obj, core::arena::SizeAndAlignment *offset)
    {
        ;
        StaticPair *ptr = reinterpret_cast<StaticPair *>(obj);
        if (!FirstMemoryDumpTraits::Unfix(&ptr->m_first, offset) ||
            !SecondMemoryDumpTraits::Unfix(&ptr->m_second, offset))
        {
            return 0;
        }
        return offset;
    }




    static void
    Refix(void *obj, void *offset, core::arena::ArenaIterator *iteratorPtr)
    {
        ;
        StaticPair *ptr = reinterpret_cast<StaticPair *>(obj);
        FirstMemoryDumpTraits::Refix(&ptr->m_first, offset, iteratorPtr);
        SecondMemoryDumpTraits::Refix(&ptr->m_second, offset, iteratorPtr);
        return;
    }




    static RwBool
    Fixup(void *obj, core::arena::ArenaIterator *iteratorPtr)
    {
        ;
        StaticPair *ptr = reinterpret_cast<StaticPair *>(obj);
        return static_cast<RwBool>( FirstMemoryDumpTraits::Fixup(&ptr->m_first, iteratorPtr) && SecondMemoryDumpTraits::Fixup(&ptr->m_second, iteratorPtr));


    }




    static void
    Destruct(void *obj)
    {
        ;
        StaticPair *ptr = reinterpret_cast<StaticPair *>(obj);
        FirstMemoryDumpTraits::Destruct(&ptr->m_first);
        SecondMemoryDumpTraits::Destruct(&ptr->m_second);
        return;
    }

    First m_first;
    Second m_second;

private:



    static ResourceDescriptor
    GetResourceDescriptor(const ResourceDescriptor& firstResDesc, const ResourceDescriptor& secondResDesc)
    {
        uint32_t alignFirst = firstResDesc.GetAlignment();
        uint32_t alignSecond = secondResDesc.GetAlignment();
        uint32_t alignment = ((alignFirst >= alignSecond) ? alignFirst : alignSecond);

        ;




        uint32_t size = sizeof(First) + secondResDesc.GetSize();

        return ResourceDescriptor(size, alignment);
    }

};



























template<typename Type, typename TypeMemoryDumpTraits = MemoryDumpTraits<Type> >
class FixedVector
{
public:








    static ResourceDescriptor
    GetResourceDescriptor(const FixedVector& obj)
    {
        ;
        return GetResourceDescriptor(obj.GetNumEntries());
    }












    static ResourceDescriptor
    GetResourceDescriptor(const Type *sourceBegin, const Type *sourceEnd)
    {
        ;
        return GetResourceDescriptor(static_cast<uint32_t>(sourceEnd - sourceBegin));
    }








    static ResourceDescriptor
    GetResourceDescriptor(uint32_t numElementsReqd)
    {
        ;
        uint32_t objectAlignment = TypeMemoryDumpTraits::GetResourceDescriptor().GetAlignment();

        uint32_t vectorAlignment = (objectAlignment > 4 ? objectAlignment : 4);
        uint32_t objectSize = TypeMemoryDumpTraits::GetResourceDescriptor().GetSize();


        uint32_t size = SizeAlign(sizeof(FixedVector), vectorAlignment) +
                        numElementsReqd * SizeAlign(objectSize, objectAlignment);
        return ResourceDescriptor(size, vectorAlignment);
    }












    static FixedVector *
    Initialize(const Resource& resource, const Type *sourceBegin, const Type *sourceEnd)
    {
        ;
        return new (resource.GetMemoryResource()) FixedVector(sourceBegin, sourceEnd);
    }














    static FixedVector *
    Initialize(const Resource& resource, uint32_t numElementsReqd)
    {
        ;
        return new (resource.GetMemoryResource()) FixedVector(numElementsReqd);
    }





    void
    Release()
    {
        ;


        uint32_t objectAlignment = TypeMemoryDumpTraits::GetResourceDescriptor().GetAlignment();
        Type *array = reinterpret_cast<Type*>(MemAlign(this + 1, objectAlignment));
        for (uint32_t i = 0; i < m_size; i++)
        {
            TypeMemoryDumpTraits::Release(array[i]);
        }
        return;
    }







    uint32_t
    GetNumEntries(void) const
    {
        ;
        return m_size;
    }









    Type &
    operator[](uint32_t i)
    {
        ;



        uint32_t alignment = GetResourceDescriptor(*this).GetAlignment();
        Type* data = reinterpret_cast<Type *>(MemAlign(this + 1, alignment));
        uint32_t objectSize = SizeAlign(TypeMemoryDumpTraits::GetResourceDescriptor().GetSize(),
                                        TypeMemoryDumpTraits::GetResourceDescriptor().GetAlignment());
        return *(MemAddOffset(data, i * objectSize));
    }









    const Type &
    operator[](uint32_t i) const
    {
        ;



        uint32_t alignment = GetResourceDescriptor(GetNumEntries()).GetAlignment();
        const Type* data = reinterpret_cast<const Type *>(MemAlign(this + 1, alignment));
        uint32_t objectSize = SizeAlign(TypeMemoryDumpTraits::GetResourceDescriptor().GetSize(),
                                        TypeMemoryDumpTraits::GetResourceDescriptor().GetAlignment());
        return *(MemAddOffset(data, i * objectSize));
    }









    Type &
    At(uint32_t i)
    {
        ;
        ;
        return (*this)[i];
    }









    const Type &
    At(uint32_t i) const
    {
        ;
        ;
        return (*this)[i];
    }

    typedef Type* Iterator;
    typedef const Type* ConstIterator;







    Iterator
    Begin(void)
    {
        ;
        return &(*this)[0];
    }







    Iterator
    End(void)
    {
        ;
        return &(*this)[GetNumEntries()];
    }







    ConstIterator
    Begin(void) const
    {
        ;
        return &operator[](0);
    }







    ConstIterator
    End(void) const
    {
        ;
        return &operator[](GetNumEntries());
    }





    static core::arena::SizeAndAlignment *
    Unfix(void *obj, core::arena::SizeAndAlignment *offset)
    {
        ;

        FixedVector *vectPtr = reinterpret_cast<FixedVector *>(obj);

        for (uint32_t i = 0; i < vectPtr->m_size; i++)
        {
            TypeMemoryDumpTraits::Unfix(const_cast<Type *>(&(*vectPtr)[i]), offset);
        }
        EndianSwap(vectPtr->m_size);
        return offset;
    }




    static void
    Refix(void *obj, void *offset, core::arena::ArenaIterator *iteratorPtr)
    {
        ;

        FixedVector *vectPtr = reinterpret_cast<FixedVector *>(obj);
        EndianSwap(vectPtr->m_size);
        for (uint32_t i = 0; i < vectPtr->m_size; i++)
        {
            TypeMemoryDumpTraits::Refix(const_cast<Type *>(&(*vectPtr)[i]), offset, iteratorPtr);
        }
        return;
    }




    static RwBool
    Fixup(void *obj, core::arena::ArenaIterator *iteratorPtr)
    {
        ;

        FixedVector *vectPtr = reinterpret_cast<FixedVector *>(obj);

        EndianSwap(vectPtr->m_size);
        for (uint32_t i = 0; i < vectPtr->m_size; i++)
        {
            TypeMemoryDumpTraits::Fixup(const_cast<Type *>(&(*vectPtr)[i]), iteratorPtr);
        }
        return (!0);
    }




    static void
    Destruct(void *)
    {
        ;
        return;
    }


private:




    FixedVector(const FixedVector &rhs);



    FixedVector &operator=(const FixedVector &rhs);










    FixedVector(const Type *sourceBegin, const Type *sourceEnd)
    {
        ;
        uint32_t objectAlignment = TypeMemoryDumpTraits::GetResourceDescriptor().GetAlignment();
        Type *array = reinterpret_cast<Type*>(MemAlign(this + 1, objectAlignment));
        m_size = static_cast<uint32_t>(sourceEnd - sourceBegin);
        for (const Type* cur = sourceBegin; cur != sourceEnd; cur++, array++)
        {
            new (array) Type(*cur);
        }
        return;
    }










    FixedVector(uint32_t numElementsReqd)
      : m_size(numElementsReqd)
    {
        ;


        return;
    }






    ~FixedVector()
    {
        ;
        Release();
        return;
    }

    uint32_t m_size;
};























template<typename Key, typename Record,
         typename KeyMDTraits = MemoryDumpTraits<Key>,
         typename RecordMDTraits = MemoryDumpTraits<Record> >
class FixedMap
{
public:
    typedef StaticPair<Key, Record, KeyMDTraits, RecordMDTraits> ValueType;
    typedef FixedVector<ValueType> StorageType;





    typedef ValueType* Iterator;





    typedef const ValueType* ConstIterator;










    Record &
    operator[](const Key &key) const
    {
        ;
        const StorageType& vector = *reinterpret_cast<const StorageType*>(this);
        ValueType *endPtr = &vector[vector.GetNumEntries()];

        for (ValueType *cur = &vector[0]; cur != endPtr; cur++)
        {
            if (cur->m_first == key)
            {
                return cur->m_second;
            }
        }
        return 0;
    }








    ConstIterator
    Find(const Key &key) const
    {
        ;
        ConstIterator endPtr = End();
        ConstIterator i = Begin();

        while ((i != endPtr) && !(i->m_first == key))
        {
            ++i;
        }
        return i;
    }








    Iterator
    Find(const Key &key)
    {
        ;
        ConstIterator endPtr = End();
        Iterator i = Begin();

        while ((i != endPtr) && !(i->m_first == key))
        {
            ++i;
        }
        return i;
    }







    uint32_t
    GetNumEntries(void) const
    {
        ;
        const StorageType& vector = *reinterpret_cast<const StorageType*>(this);
        return vector.GetNumEntries();
    }









    const ValueType &
    GetPairAtIndex(uint32_t i) const
    {
        ;
        const StorageType& vector = *reinterpret_cast<const StorageType*>(this);
        return vector[i];
    }







    Iterator
    Begin(void)
    {
        ;
        StorageType& vector = *reinterpret_cast<StorageType*>(this);
        return vector.Begin();
    }







    Iterator
    End(void)
    {
        ;
        StorageType& vector = *reinterpret_cast<StorageType*>(this);
        return vector.End();
    }







    ConstIterator
    Begin(void) const
    {
        ;
        const StorageType& vector = *reinterpret_cast<const StorageType*>(this);
        return vector.Begin();
    }







    ConstIterator
    End(void) const
    {
        ;
        const StorageType& vector = *reinterpret_cast<const StorageType*>(this);
        return vector.End();
    }





    static ResourceDescriptor
    GetResourceDescriptor(const FixedMap& obj)
    {
        ;
        return StorageType::GetResourceDescriptor(obj);
    }












    static ResourceDescriptor
    GetResourceDescriptor(const ValueType *sourceBegin, const ValueType *sourceEnd)
    {
        ;
        return StorageType::GetResourceDescriptor(sourceBegin, sourceEnd);
    }








    static ResourceDescriptor
    GetResourceDescriptor(uint32_t numElementsReqd)
    {
        ;
        return StorageType::GetResourceDescriptor(numElementsReqd);
    }












    static FixedMap *
    Initialize(const Resource& resource, const ValueType *sourceBegin, const ValueType *sourceEnd)
    {
        ;
        StorageType* vector = StorageType::Initialize(resource, sourceBegin, sourceEnd);
        return reinterpret_cast<FixedMap*>(vector);
    }














    static FixedMap *
    Initialize(const Resource& resource, uint32_t numElementsReqd)
    {
        ;
        return new (resource.GetMemoryResource()) FixedMap(numElementsReqd);
    }





    void
    Release()
    {
        ;
        StorageType& vector = *reinterpret_cast<StorageType*>(this);
        vector.Release();
        return;
    }




    static core::arena::SizeAndAlignment *
    Unfix(void *obj, core::arena::SizeAndAlignment *offset)
    {
        ;
        StorageType* vector = reinterpret_cast<StorageType*>(obj);
        StorageType::Unfix(vector, offset);
        return offset;
    }




    static void
    Refix(void *obj, void *offset, core::arena::ArenaIterator *iteratorPtr)
    {
        ;
        StorageType* vector = reinterpret_cast<StorageType*>(obj);
        StorageType::Refix(vector, offset, iteratorPtr);
        return;
    }




    static RwBool
    Fixup(void *obj, core::arena::ArenaIterator *iteratorPtr)
    {
        ;
        StorageType* vector = reinterpret_cast<StorageType*>(obj);
        StorageType::Fixup(vector, iteratorPtr);
        return (!0);
    }




    static void
    Destruct(void *)
    {
        ;
        return;
    }





    FixedMap()
    {
        ;
        ;
        return;
    }

private:



    FixedMap(uint32_t numElementsReqd)
    {
        ;
        StorageType::Initialize(this, numElementsReqd);
        return;
    }


    FixedMap(const FixedMap &rhs);
    FixedMap &operator=(const FixedMap &rhs);



};






















template <typename Type, typename TypeMemoryDumpTraits = MemoryDumpTraits<Type> >
class StaticPtr
{
public:



    StaticPtr(void)
        : m_data(),
          m_copy()
    {
        ;
        return;
    }







    explicit StaticPtr(Type *source)
    {
        ;
        m_data = source;
        m_copy = source;
        return;
    }








    Type &
    operator*()
    {
        ;


        return *m_copy;
    }








    const Type &
    operator*() const
    {
        ;


        return *m_copy;
    }








    Type*
    operator->()
    {
        ;


        return m_copy;
    }








    const Type*
    operator->() const
    {
        ;


        return m_copy;
    }








    const Type*
    Get() const
    {
        ;
        return m_copy;
    }








    Type*
    Get()
    {
        ;


        return m_copy;
    }




    static ResourceDescriptor
    GetResourceDescriptor()
    {
        ;
        return ResourceDescriptor(sizeof(StaticPtr), 4);
    }




    static ResourceDescriptor
    GetResourceDescriptor(Type* )
    {
        ;
        return GetResourceDescriptor();
    }




    static ResourceDescriptor
    GetResourceDescriptor(const StaticPtr& )
    {
        ;
        return GetResourceDescriptor();
    }











    static StaticPtr *
    Initialize(const Resource& resource, Type *source = 0)
    {
        ;
        return new (resource.GetMemoryResource()) StaticPtr(source);
    }








    static StaticPtr *
    Initialize(const Resource& resource, const StaticPtr& other)
    {
        ;
        return new (resource.GetMemoryResource()) StaticPtr(other);
    }








    void
    Release()
    {
        ;
        TypeMemoryDumpTraits::Release(*m_copy);
        return;
    }




    static core::arena::SizeAndAlignment *
    Unfix(void *obj, core::arena::SizeAndAlignment *offset)
    {
        ;

        StaticPtr *ptr = reinterpret_cast<StaticPtr *>(obj);

        ResourceDescriptor typeResDesc = TypeMemoryDumpTraits::GetResourceDescriptor(*ptr->m_copy);
        ;




        void* preAlign = MemAddOffset(offset->iterator->offset, offset->extraSize);
        ptr->m_data = reinterpret_cast<Type*>(MemAlign(preAlign, typeResDesc.GetAlignment()));
        uint32_t padding =
            static_cast<uint32_t>(RwPtrToOffset(ptr->m_data) - reinterpret_cast<rw::HostPtr>(preAlign));


        ptr->m_size = typeResDesc.GetSize();
        offset->extraSize += padding + ptr->m_size;

        EndianSwap(ptr->m_data);
        TypeMemoryDumpTraits::Unfix(ptr->m_copy, offset);
        return offset;
    }




    static void
    Refix(void *obj, void *offset, core::arena::ArenaIterator *iteratorPtr)
    {
        ;
        StaticPtr *ptr = reinterpret_cast<StaticPtr *>(obj);


        uint32_t alignment = TypeMemoryDumpTraits::GetResourceDescriptor(*ptr->m_copy).GetAlignment();
        void* alignedOffset = MemAlign(iteratorPtr->offset, alignment);
        uint32_t alignmentPadding = reinterpret_cast<rw::HostPtr>(alignedOffset) -
                                    reinterpret_cast<rw::HostPtr>(iteratorPtr->offset);


        ptr->m_data = ptr->m_copy;


        iteratorPtr->WriteCallback(ptr->m_copy, ptr->m_size, alignmentPadding);


        iteratorPtr->Align(alignment);
        iteratorPtr->AddOffset(ptr->m_size);


        TypeMemoryDumpTraits::Refix(ptr->m_copy, offset, iteratorPtr);
        return;
    }




    static RwBool
    Fixup(void *obj, core::arena::ArenaIterator *iteratorPtr)
    {
        ;
        StaticPtr *ptr=reinterpret_cast<StaticPtr *>(obj);


        EndianSwap(ptr->m_data);
        ptr->m_data = RwPtrAddOffset(ptr->m_data, RwPtrToOffset(iteratorPtr->m_arena->base));
        ptr->m_copy = ptr->m_data;

        ;




        TypeMemoryDumpTraits::Fixup(ptr->m_copy, iteratorPtr);
        return (!0);
    }




    static void
    Destruct(void *)
    {
        ;
        return;
    }

private:
    Type* m_data;


    Type* m_copy;
    uint32_t m_size;
};















template<typename CharT>
class BasicFixedString
{
public:
    typedef FixedVector<CharT> StorageType;
    typedef StaticPtr<StorageType> PtrType;







    BasicFixedString(const BasicFixedString &rhs)
        : m_stringPtr(CopyData(rhs.c_str()))
    {
        ;
        return;
    }







    BasicFixedString(const CharT *source)
        : m_stringPtr(CopyData(source))
    {
        ;
        return;
    }






    BasicFixedString(void)
        : m_stringPtr()
    {
        ;
        return;
    }





    ~BasicFixedString()
    {
        ;
        Release();
        return;
    }








    BasicFixedString &
    operator=(const BasicFixedString &rhs)
    {
        ;
        BasicFixedString temp(rhs);
        Swap(temp, *this);
        return *this;
    }








    const CharT *
    c_str(void) const
    {
        ;
        return &(*m_stringPtr)[0];
    }








    bool
    operator==(const BasicFixedString& rhs)
    {
        ;


        if (m_stringPtr->GetNumEntries()!=rhs.m_stringPtr->GetNumEntries())
        {
            return false;
        }

        CharT *left = &(*m_stringPtr)[0];
        const CharT *right = &(*rhs.m_stringPtr)[0];

        for(size_t i=0; i<m_stringPtr->GetNumEntries() ; ++i, ++left, ++right)
        {
            if (*left != *right)
            {
                return false;
            }
        }
        return true;
    }




    static ResourceDescriptor
    GetResourceDescriptor(void)
    {
        ;
        return PtrType::GetResourceDescriptor();
    }




    static ResourceDescriptor
    GetResourceDescriptor(const BasicFixedString& obj)
    {
        ;
        return PtrType::GetResourceDescriptor(obj);
    }




    static ResourceDescriptor
    GetResourceDescriptor(const CharT *)
    {
        ;
        return PtrType::GetResourceDescriptor();
    }










    static BasicFixedString *
    Initialize(const Resource& resource, const CharT *source)
    {
        ;
        return new (resource.GetMemoryResource()) BasicFixedString(source);
    }





    void
    Release()
    {
        ;
        if (m_stringPtr.Get())
        {
            m_stringPtr.Get()->StorageType::Release();
            GetDefaultAllocator().Free(Resource(m_stringPtr.Get()));
            m_stringPtr = PtrType();
        }
        return;
    }




    static core::arena::SizeAndAlignment *
    Unfix(void *obj, core::arena::SizeAndAlignment *offset)
    {
        ;
        BasicFixedString *strPtr = reinterpret_cast<BasicFixedString *>(obj);
        PtrType::Unfix(&strPtr->m_stringPtr, offset);
        return offset;
    }




    static void
    Refix(void *obj, void *offset, core::arena::ArenaIterator *iteratorPtr)
    {
        ;
        BasicFixedString *strPtr = reinterpret_cast<BasicFixedString *>(obj);
        PtrType::Refix(&strPtr->m_stringPtr, offset, iteratorPtr);
        return;
    }




    static RwBool
    Fixup(void *obj, core::arena::ArenaIterator *iteratorPtr)
    {
        ;
        BasicFixedString *strPtr = reinterpret_cast<BasicFixedString *>(obj);
        PtrType::Fixup(&strPtr->m_stringPtr, iteratorPtr);
        return (!0);
    }




    static void
    Destruct(void *)
    {
        ;
        return;
    }

private:








    static void
    Swap(BasicFixedString &s1, BasicFixedString &s2)
    {
        ;
        PtrType temp(s1.m_stringPtr);
        s1.m_stringPtr = s2.m_stringPtr;
        s2.m_stringPtr = temp;
        return;
    }











    static StorageType *
    CopyData(const CharT *source)
    {
        ;
        StorageType *retVal;
        if (source)
        {
            const CharT *sourceEnd = source + strlen(source) + 1;


            ResourceDescriptor resDesc = StorageType::GetResourceDescriptor(source, sourceEnd);
            Resource resource = GetDefaultAllocator().Allocate(resDesc,
                0);


            retVal = StorageType::Initialize(resource, source, sourceEnd);
        }
        else
        {
            retVal = 0;
        }
        return retVal;
    }


    PtrType m_stringPtr;
};




typedef BasicFixedString<RwChar> FixedString;












typedef FixedString StaticString;

}
