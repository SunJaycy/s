






















namespace rw
{































template <typename ElementType>
class SimpleVector
{
public:

    SimpleVector(IResourceAllocator& allocator, uint32_t size = 0);
    SimpleVector(uint32_t size = 0);
    ~SimpleVector();






    bool empty() const;
    uint32_t size() const;
    uint32_t capacity() const;

    void clear();
    void resize(uint32_t size);
    void reserve(uint32_t capacity);

    const ElementType& operator[](uint32_t i) const;
    ElementType& operator[](uint32_t i);

    const ElementType* data() const;
    ElementType* data();

    void push_back(const ElementType& value);

protected:


private:

    SimpleVector(const SimpleVector& other);
    SimpleVector& operator=(const SimpleVector& other);




    IResourceAllocator& m_allocator;
    Resource m_storage;
    ElementType* m_elements;
    uint32_t m_capacity;
    uint32_t m_size;

    static const uint32_t INITIAL_CAPACITY;
    static const float32_t GROWTH_FACTOR;
};

template <typename ElementType>
const uint32_t SimpleVector<ElementType>::INITIAL_CAPACITY = 16;
template <typename ElementType>
const float32_t SimpleVector<ElementType>::GROWTH_FACTOR = 2.0f;







template <typename ElementType>
SimpleVector<ElementType>::SimpleVector(IResourceAllocator& allocator, uint32_t size_)
  : m_allocator(allocator),
    m_storage(),
    m_elements(0),
    m_capacity(0),
    m_size(0)
{
    ;
    reserve(INITIAL_CAPACITY);
    resize(size_);
    return;
}






template <typename ElementType>
SimpleVector<ElementType>::SimpleVector(uint32_t size_)
  : m_allocator(rw::GetDefaultAllocator()),
    m_storage(),
    m_elements(0),
    m_capacity(0),
    m_size(0)
{
    ;
    reserve(INITIAL_CAPACITY);
    resize(size_);
    return;
}




template <typename ElementType>
SimpleVector<ElementType>::~SimpleVector()
{
    ;
    if (m_storage)
    {
        m_allocator.Free(m_storage);
    }
    return;
}





template <typename ElementType>
bool
SimpleVector<ElementType>::empty() const
{
    ;
    return m_size == 0;
}




template <typename ElementType>
uint32_t
SimpleVector<ElementType>::size() const
{
    ;
    return m_size;
}





template <typename ElementType>
uint32_t
SimpleVector<ElementType>::capacity() const
{
    ;
    return m_capacity;
}




template <typename ElementType>
void
SimpleVector<ElementType>::clear()
{
    ;
    resize(0);
    return;
}





template <typename ElementType>
void
SimpleVector<ElementType>::resize(uint32_t size_)
{
    ;
    reserve(size_);
    m_size = size_;
    return;
}






template <typename ElementType>
void
SimpleVector<ElementType>::reserve(uint32_t capacity_)
{
    ;
    if (capacity_ < m_capacity)
    {
        return;
    }

    if (capacity_ > GROWTH_FACTOR * m_capacity)
    {
        m_capacity = capacity_;
    }
    else
    {
        m_capacity = static_cast<uint32_t>(GROWTH_FACTOR * m_capacity);
    }

    Resource oldStorage = m_storage;
    ElementType* oldElements = m_elements;


    ResourceDescriptor storageReq(m_capacity * sizeof(ElementType), 4);
    m_storage = m_allocator.Allocate(storageReq);
    m_elements = reinterpret_cast<ElementType*>(m_storage.GetMemoryResource());


    if (oldElements)
    {
        memcpy(m_elements, oldElements, m_size * sizeof(ElementType));
        ;
        m_allocator.Free(oldStorage);
    }

    return;
}





template <typename ElementType>
const ElementType&
SimpleVector<ElementType>::operator[](uint32_t i) const
{
    ;
    ;
    return m_elements[i];
}





template <typename ElementType>
ElementType&
SimpleVector<ElementType>::operator[](uint32_t i)
{
    ;
    ;
    return m_elements[i];
}





template <typename ElementType>
const ElementType*
SimpleVector<ElementType>::data() const
{
    ;
    return m_elements;
}





template <typename ElementType>
ElementType*
SimpleVector<ElementType>::data()
{
    ;
    return m_elements;
}





template <typename ElementType>
void
SimpleVector<ElementType>::push_back(const ElementType& value)
{
    ;
    uint32_t nextElement = m_size;
    resize(m_size + 1);
    m_elements[nextElement] = value;
    return;
}


}
