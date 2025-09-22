




























namespace rw
{





































template<typename KeyType, typename DatumType>
struct SeparateKeyAndDatumContained
{
public:



    SeparateKeyAndDatumContained()
        : key(), data()
    {
        ;
        return;
    }







    SeparateKeyAndDatumContained(const KeyType& key_, const DatumType& data_)
        : key(key_), data(data_)
    {
        ;
        return;
    }















    const KeyType& GetKey() const
    {
        ;
        return key;
    }






    KeyType& GetKey()
    {
        ;
        return key;
    }






    const DatumType& GetData() const
    {
        ;
        return data;
    }






    DatumType& GetData()
    {
        ;
        return data;
    }






    RwBool operator==(const SeparateKeyAndDatumContained& rhs) const
    {
        ;
        return (key == rhs.key) && (data == rhs.data);
    }






    RwBool operator!=(const SeparateKeyAndDatumContained& rhs) const
    {
        ;
        return !(*this == rhs);
    }






protected:



private:





    KeyType key;
    DatumType data;
};















template<size_t CAPACITY, typename HashTraitsT>
struct FixedSizeBufferPolicy
{




    struct BufferPolicyDetails
    {
    };







    FixedSizeBufferPolicy(BufferPolicyDetails &)
    {
        ;
        typename HashTraitsT::Contained defaultValue = HashTraitsT::DefaultContained();
        for (typename HashTraitsT::Contained *ptr = contents; ptr < contents + CAPACITY; ++ptr)
        {
            *ptr = defaultValue;
        }
        return;
    }





    size_t Capacity() const
    {
        ;
        return CAPACITY;
    }





    size_t GetInitialSize() const
    {
        ;
        return 0;
    }

    typename HashTraitsT::Contained contents[CAPACITY];
};














template<typename HashTraitsT>
struct PreallocatedBufferPolicy
{




    struct BufferPolicyDetails
    {



        BufferPolicyDetails()
            : contents(0), capacity(0)
        {
            ;
            return;
        }








        BufferPolicyDetails(typename HashTraitsT::Contained *contents_, size_t capacity_)
            : contents(contents_), capacity(capacity_)
        {
            ;
            typename HashTraitsT::Contained defaultValue = HashTraitsT::DefaultContained();
            for (typename HashTraitsT::Contained *ptr = contents; ptr < contents + capacity; ++ptr)
            {
                *ptr = defaultValue;
            }
            return;
        }

        typename HashTraitsT::Contained *contents;
        size_t capacity;
    };





    PreallocatedBufferPolicy(BufferPolicyDetails &details)
        : contents(details.contents),
          capacity(details.capacity)
    {
        ;
        return;
    }





    size_t Capacity() const
    {
        ;
        return capacity;
    }





    size_t GetInitialSize() const
    {
        ;
        return 0;
    }

    typename HashTraitsT::Contained *contents;
    size_t capacity;
};














template<typename HashTraitsT>
struct PreinitializedBufferPolicy
{



    struct BufferPolicyDetails
    {




        BufferPolicyDetails()
            : contents(0), capacity(0)
        {
            ;
            return;
        }







        BufferPolicyDetails(typename HashTraitsT::Contained *contents_, size_t capacity_)
            : contents(contents_), capacity(capacity_)
        {
            ;
            return;
        }

        typename HashTraitsT::Contained *contents;
        size_t capacity;
    };





    PreinitializedBufferPolicy(BufferPolicyDetails &details)
        : contents(details.contents),
          capacity(details.capacity)
    {
        ;
        return;
    }





    size_t Capacity() const
    {
        ;
        return capacity;
    }





    size_t GetInitialSize() const
    {
        ;

        size_t size = 0;
        for (typename HashTraitsT::Contained *ptr = contents; ptr < contents + capacity; ++ptr)
        {
            if (!HashTraitsT::EqualTo(HashTraitsT::BadKey(), HashTraitsT::GetKey(*ptr)))
            {
                ++size;
            }
        }
        return size;
    }

    typename HashTraitsT::Contained *contents;
    size_t capacity;
};








































template <typename BufferPolicy, typename HashTraitsT>
class HashContainer : private BufferPolicy
{
public:
    typedef HashTraitsT HashTraits;
    typedef typename HashTraitsT::KeyType KeyType;
    typedef typename HashTraitsT::DatumType DatumType;
    typedef typename HashTraitsT::Contained Contained;
    typedef typename BufferPolicy::BufferPolicyDetails SPDetails;










    template<class T>
    class IteratorT
    {
    public:
        friend class HashContainer<BufferPolicy, HashTraitsT>;




        IteratorT()
            : ptr(0), end(0)
        {
            ;
            return;
        }







        IteratorT(T *ptr_, T* end_)
            : ptr(ptr_), end(end_)
        {
            ;
            return;
        }






        IteratorT operator++()
        {
            ;

            ;


            if (ptr == end)
            {
                return *this;
            }

            do
            {
              ++ptr;
            }
            while ((ptr < end) && HashTraitsT::EqualTo(HashTraitsT::BadKey(), HashTraitsT::GetKey(*ptr)));

            return *this;
        }






        const T& operator*() const
        {
            ;
            ;
            return *ptr;
        }






        const T* operator->() const
        {
            ;
            ;
            return ptr;
        }






        bool operator==(const IteratorT& rhs) const
        {
            ;
            ;
            return (ptr == rhs.ptr);
        }






        bool operator!=(const IteratorT& rhs) const
        {
            ;
            return !(ptr == rhs.ptr);
        }

    private:
        T *ptr;
        T *end;
    };

    typedef IteratorT<Contained> iterator;
    typedef IteratorT<const Contained> const_iterator;







    HashContainer(SPDetails details = SPDetails())
        : BufferPolicy(details), size(BufferPolicy::GetInitialSize())
    {
        ;
        return;
    }











    static ResourceDescriptor
    GetResourceDescriptor()
    {
        ;
        return ResourceDescriptor(sizeof(HashContainer), HashTraitsT::GetAlign());
    }






    static size_t
    GetSize()
    {
        ;
        ;
        return GetResourceDescriptor().GetSize();
    }






    static size_t
    GetAlign()
    {
        ;
        ;
        return GetResourceDescriptor().GetAlignment();
    }






    static HashContainer *
    Initialize(const Resource& resource, SPDetails details = SPDetails())
    {
        ;
        return new (resource.GetMemoryResource()) HashContainer(details);
    }







    static HashContainer *
    Initialize(void *ptr, SPDetails details = SPDetails())
    {
        ;
        ;
        return Initialize(Resource(ptr), details);
    }





    bool Empty() const
    {
        ;
        return 0 == size;
    }





    size_t Size() const
    {
        ;
        return size;
    }





    size_t Capacity() const
    {
        ;
        return BufferPolicy::Capacity();
    }






    iterator Begin();




    const_iterator Begin() const;




    iterator End();




    const_iterator End() const;







    iterator
    Find(const KeyType& key);





    const_iterator
    Find(const KeyType& key) const;








    void
    Insert(const Contained& obj);










    DatumType&
    operator[](const KeyType &key);






    void
    Erase(const KeyType& key);






    void
    Erase(const iterator& position);






    void Clear();





    void
    Swap(HashContainer &rhs);



private:
    class Index
    {
    public:
        Index(size_t pos_, size_t size_)
            : pos(pos_), size(size_)
        {
            ;
            ;
            return;
        }

        operator size_t() const
        {
            ;
            return pos;
        }

        Index operator++()
        {
            ;
            ++pos;
            if (pos == size)
            {
                pos = 0;
            }
            return *this;
        }

        Index operator--()
        {
            ;
            if (pos == 0)
            {
                pos = size;
            }
            --pos;
            return *this;
        }


        RwBool IsInRange(Index lower, Index upper)
        {
            ;
            if (upper >= lower)
            {
                return (RwBool)((pos >= lower) && (pos <= upper));
            }
            else
            {
                return (RwBool)((pos >= lower) || (pos <= upper));
            }
        }


    private:
        size_t pos;
        size_t size;
    };







    Index
    FindIndexForKey(const KeyType &key) const;






    void
    Remove(Index i);


    size_t size;
};






template <typename BufferPolicy, typename HashTraitsT>
typename HashContainer<BufferPolicy, HashTraitsT>::iterator
HashContainer<BufferPolicy, HashTraitsT>::Begin()
{
    ;
    iterator iter(&this->contents[0], &this->contents[0] + Capacity());
    if (HashTraitsT::EqualTo(HashTraitsT::BadKey(), HashTraitsT::GetKey(this->contents[0])))
    {
        ++iter;
    }
    return iter;
}


template <typename BufferPolicy, typename HashTraitsT>
typename HashContainer<BufferPolicy, HashTraitsT>::const_iterator
HashContainer<BufferPolicy, HashTraitsT>::Begin() const
{
    ;
    const_iterator iter(&this->contents[0], &this->contents[0] + Capacity());
    if (HashTraitsT::EqualTo(HashTraitsT::BadKey(), HashTraitsT::GetKey(this->contents[0])))
    {
        ++iter;
    }
    return iter;
}


template <typename BufferPolicy, typename HashTraitsT>
typename HashContainer<BufferPolicy, HashTraitsT>::iterator
HashContainer<BufferPolicy, HashTraitsT>::End()
{
    ;
    return iterator(&this->contents[0] + Capacity(), &this->contents[0] + Capacity());
}


template <typename BufferPolicy, typename HashTraitsT>
typename HashContainer<BufferPolicy, HashTraitsT>::const_iterator
HashContainer<BufferPolicy, HashTraitsT>::End() const
{
    ;
    return const_iterator(&this->contents[0] + Capacity(), &this->contents[0] + Capacity());
}


template<typename BufferPolicy, typename HashTraitsT>
void
HashContainer<BufferPolicy, HashTraitsT>::Insert(const Contained& obj)
{
    ;
    Index i = FindIndexForKey(HashTraitsT::GetKey(obj));
    ;

    this->contents[i] = obj;
    ++size;









    return;
}


template<typename BufferPolicy, typename HashTraitsT>
typename HashContainer<BufferPolicy, HashTraitsT>::DatumType&
HashContainer<BufferPolicy, HashTraitsT>::operator[]
    (const typename HashContainer<BufferPolicy, HashTraitsT>::KeyType &key)
{
    ;
    Index i = FindIndexForKey(key);
    if (!HashTraitsT::EqualTo(key, HashTraitsT::GetKey(this->contents[i])))
    {

        HashTraitsT::GetKey(this->contents[i]) = key;
        ++size;









    }
    return HashTraitsT::GetData(this->contents[i]);
}


template <typename BufferPolicy, typename HashTraitsT>
void
HashContainer<BufferPolicy, HashTraitsT>::Erase(const KeyType& key)
{
    ;
    Index i = FindIndexForKey(key);
    Remove(i);
    return;
}


template <typename BufferPolicy, typename HashTraitsT>
void
HashContainer<BufferPolicy, HashTraitsT>::Erase(const iterator& position)
{
    ;
    Index i((size_t)(position.ptr - &this->contents[0]), Capacity());
    Remove(i);
    return;
}


template<typename BufferPolicy, typename HashTraitsT>
void
HashContainer<BufferPolicy, HashTraitsT>::Clear()
{
    ;
    Contained* start = &this->contents[0];
    Contained* finish = &this->contents[0] + Capacity();
    const typename HashTraitsT::Contained defaultValue = HashTraitsT::DefaultContained();
    for (Contained* ptr = start; ptr < finish; ++ptr)
    {
        *ptr = defaultValue;
    }

    size = 0;
    return;
}



template<typename BufferPolicy, typename HashTraitsT>
void
HashContainer<BufferPolicy, HashTraitsT>::Swap(HashContainer &rhs)
{
    ;
    HashContainer temp(rhs);
    rhs = *this;
    *this = temp;
    return;
}


template <typename BufferPolicy, typename HashTraitsT>
typename HashContainer<BufferPolicy, HashTraitsT>::iterator
HashContainer<BufferPolicy, HashTraitsT>::Find(const KeyType& key)
{
    ;
    Index i = FindIndexForKey(key);
    if (HashTraitsT::EqualTo(key, HashTraitsT::GetKey(this->contents[i])))
    {
        return iterator(&this->contents[i], &this->contents[0] + Capacity());
    }
    else
    {
        return End();
    }
}


template <typename BufferPolicy, typename HashTraitsT>
typename HashContainer<BufferPolicy, HashTraitsT>::const_iterator
HashContainer<BufferPolicy, HashTraitsT>::Find(const KeyType& key) const
{
    ;
    Index i = FindIndexForKey(key);
    if (HashTraitsT::EqualTo(key, HashTraitsT::GetKey(this->contents[i])))
    {
        return const_iterator(&this->contents[i], &this->contents[0] + Capacity());
    }
    else
    {
        return End();
    }
}



template<typename BufferPolicy, typename HashTraitsT>
typename HashContainer<BufferPolicy, HashTraitsT>::Index
HashContainer<BufferPolicy, HashTraitsT>::FindIndexForKey(const KeyType &key) const
{
    ;


    Index start(HashTraitsT::Hash(Capacity(), key), Capacity());
    Index i = start;


    while (!HashTraitsT::EqualTo(key, HashTraitsT::GetKey(this->contents[i])) &&
           !HashTraitsT::EqualTo(HashTraitsT::BadKey(), HashTraitsT::GetKey(this->contents[i])))
    {
        ++i;
        ;
    };

    return i;
}


template<typename BufferPolicy, typename HashTraitsT>
void
HashContainer<BufferPolicy, HashTraitsT>::Remove
    (typename HashContainer<BufferPolicy, HashTraitsT>::Index i)
{
    ;

    ;


    Index start = i;
    Index j = i;
    for(;;)
    {
        ++j;

        if (j == start)
        {

            break;
        }

        const KeyType& j_key = HashTraitsT::GetKey(this->contents[j]);

        if (HashTraitsT::EqualTo(HashTraitsT::BadKey(), j_key))
        {

            break;
        }

        Index j_hash(HashTraitsT::Hash(Capacity(), j_key), Capacity());
        if (!j_hash.IsInRange(++Index(i), j))
        {

            this->contents[i] = this->contents[j];
            i = j;
        }
    }


    this->contents[i] = HashTraitsT::DefaultContained();

    --size;

    return;
}

}
