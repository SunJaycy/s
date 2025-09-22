



















namespace rw
{






































class BitArray
{
private:

    class IteratorBase;

public:

    typedef uint32_t WordType;

    class ConstIterator;
    class Iterator;

    typedef const WordType* ConstWordIterator;
    typedef WordType* WordIterator;


    BitArray();
    ~BitArray();


    void Initialize(WordType *mem, uint32_t sizeInBits);


    uint32_t GetSize() const;


    RwBool operator[](uint32_t i) const;

    RwBool at(uint32_t i) const;


    void Set(uint32_t i);

    void Unset(uint32_t i);


    void SetAll();

    void UnsetAll();


    ConstIterator Begin() const;
    Iterator Begin();
    ConstIterator End() const;
    Iterator End();


    ConstIterator GetIterator(uint32_t index) const;
    Iterator GetIterator(uint32_t index);


    uint32_t GetIndex(const IteratorBase &iter) const;


    ConstWordIterator WordBegin() const;
    WordIterator WordBegin();
    ConstWordIterator WordEnd() const;
    WordIterator WordEnd();

private:
    WordType *m_data;
    uint32_t m_sizeInBits;
    uint32_t m_sizeInWords;

protected:
    enum MiscConstants
    {





        BITS_PER_WORD = 32,





        WORD_SHIFT = 5
    };

};









class BitArray::IteratorBase
{
public:
    IteratorBase();
    IteratorBase(WordType *word, uint32_t bitIndex);
    IteratorBase(const IteratorBase &other);
    const IteratorBase& operator=(const IteratorBase &other);


    RwBool operator==(const IteratorBase &other) const;

    RwBool operator!=(const IteratorBase &other) const;

    RwBool operator<(const IteratorBase &other) const;

    RwBool operator>(const IteratorBase &other) const;
    RwBool operator>=(const IteratorBase &other) const;
    RwBool operator<=(const IteratorBase &other) const;

    RwBool operator*() const;

    RwBool FindOne(const IteratorBase &end);

    RwBool FindZero(const IteratorBase &end);

protected:

    ~IteratorBase();


    void MoveToNextBit();
    void MoveForward(uint32_t distance);
    void MoveBackward(uint32_t distance);

    WordType *m_word;
    uint32_t m_bitIndex;

private:
    friend class BitArray;
};









class BitArray::Iterator : public BitArray::IteratorBase
{
public:
    Iterator();
    Iterator(uint32_t *word, uint32_t bitIndex);
    Iterator(const Iterator &other);
    ~Iterator();

    const Iterator& operator=(const Iterator &other);

    Iterator& operator++();
    Iterator operator+(uint32_t distance) const;
    Iterator operator-(uint32_t distance) const;

    void Set() const;
    void Unset() const;
};









class BitArray::ConstIterator : public BitArray::IteratorBase
{
public:
    ConstIterator();
    ConstIterator(WordType *word, uint32_t bitIndex);
    ConstIterator(const IteratorBase &other);
    ~ConstIterator();

    const ConstIterator& operator=(const ConstIterator &other);

    ConstIterator& operator++();
    ConstIterator operator+(uint32_t distance) const;
    ConstIterator operator-(uint32_t distance) const;
};











inline
BitArray::IteratorBase::IteratorBase()
{
    ;
    return;
}





inline
BitArray::IteratorBase::IteratorBase(BitArray::WordType *word, uint32_t bitIndex)
  : m_word(word),
    m_bitIndex(bitIndex)
{
    ;
    return;
}





inline
BitArray::IteratorBase::IteratorBase(const BitArray::IteratorBase &other)
  : m_word(other.m_word),
    m_bitIndex(other.m_bitIndex)
{
    ;
    return;
}





inline
BitArray::IteratorBase::~IteratorBase()
{
    ;
    return;
}





inline const BitArray::IteratorBase&
BitArray::IteratorBase::operator=(const BitArray::IteratorBase &other)
{
    ;
    m_word = other.m_word;
    m_bitIndex = other.m_bitIndex;
    return *this;
}





inline RwBool
BitArray::IteratorBase::operator==(const BitArray::IteratorBase &other) const
{
    ;
    return (RwBool)((m_word == other.m_word) && (m_bitIndex == other.m_bitIndex));
}





inline RwBool
BitArray::IteratorBase::operator!=(const BitArray::IteratorBase &other) const
{
    ;
    return (RwBool)(!operator==(other));
}





inline void
BitArray::IteratorBase::MoveToNextBit()
{
    ;
    ;
    if (++m_bitIndex == BITS_PER_WORD)
    {
        m_bitIndex = 0;
        ++m_word;
    }
    return;
}






inline void
BitArray::IteratorBase::MoveForward(uint32_t distance)
{
    ;
    ;
    ;
    m_word += distance >> WORD_SHIFT;
    m_bitIndex += distance & (BITS_PER_WORD - 1);
    if (m_bitIndex >= BITS_PER_WORD)
    {
        m_bitIndex -= BITS_PER_WORD;
        ++m_word;
    }
    return;
}






inline void
BitArray::IteratorBase::MoveBackward(uint32_t distance)
{
    ;
    ;
    ;
    uint32_t i = distance & (BITS_PER_WORD - 1);
    m_word -= distance >> WORD_SHIFT;
    if (i > m_bitIndex)
    {
        m_bitIndex += BITS_PER_WORD - i;
        --m_word;
    }
    else
    {
        m_bitIndex -= i;
    }
    return;
}








inline RwBool
BitArray::IteratorBase::operator<(const IteratorBase &other) const
{
    ;
    return (RwBool)(m_word < other.m_word || (m_word == other.m_word && m_bitIndex < other.m_bitIndex) );
}






inline RwBool
BitArray::IteratorBase::operator>(const IteratorBase &other) const
{
    ;
    return other < *this;
}






inline RwBool
BitArray::IteratorBase::operator>=(const IteratorBase &other) const
{
    ;
    return (RwBool)(!(*this < other));
}






inline RwBool
BitArray::IteratorBase::operator<=(const IteratorBase &other) const
{
    ;
    return (RwBool)(!(other < *this));
}







inline RwBool
BitArray::IteratorBase::operator*() const
{
    ;
    ;
    return (*m_word >> m_bitIndex) & 1;
}








inline RwBool
BitArray::IteratorBase::FindOne(const IteratorBase &end)
{
    ;
    ;
    ;
    uint32_t bit = (uint32_t)(1 << m_bitIndex);

    while (!(*m_word & bit))
    {
        bit *= 2;
        if (++m_bitIndex == BITS_PER_WORD)
        {
            m_bitIndex = 0;
            bit = 1;
            do
            {
                if (++m_word > end.m_word)
                {
                    operator=(end);
                    return 0;
                }
            }
            while (*m_word == 0);
        }
    }
    return operator<(end);
}








inline RwBool
BitArray::IteratorBase::FindZero(const IteratorBase &end)
{
    ;
    ;
    ;
    uint32_t bit = (uint32_t)(1 << m_bitIndex);

    while (*m_word & bit)
    {
        bit *= 2;
        if (++m_bitIndex == BITS_PER_WORD)
        {
            m_bitIndex = 0;
            bit = 1;
            do
            {
                if (++m_word > end.m_word)
                {
                    operator=(end);
                    return 0;
                }
            }
            while (*m_word == ~WordType(0));
        }
    }
    return operator<(end);
}






inline
BitArray::Iterator::Iterator()
  : BitArray::IteratorBase()
{
    ;
    return;
}







inline
BitArray::Iterator::Iterator(BitArray::WordType *word, uint32_t bitIndex)
  : BitArray::IteratorBase(word, bitIndex)
{
    ;
    return;
}






inline
BitArray::Iterator::Iterator(const BitArray::Iterator &other)
  : BitArray::IteratorBase(other)
{
    ;
    return;
}






inline
BitArray::Iterator::~Iterator()
{
    ;
    return;
}





inline const BitArray::Iterator&
BitArray::Iterator::operator=(const BitArray::Iterator &other)
{
    ;
    BitArray::IteratorBase::operator=(other);
    return *this;
}





inline BitArray::Iterator&
BitArray::Iterator::operator++()
{
    ;
    MoveToNextBit();
    return *this;
}







inline BitArray::Iterator
BitArray::Iterator::operator+(uint32_t distance) const
{
    ;
    Iterator copy(*this);
    copy.MoveForward(distance);
    return copy;
}







inline BitArray::Iterator
BitArray::Iterator::operator-(uint32_t distance) const
{
    ;
    Iterator copy(*this);
    copy.MoveBackward(distance);
    return copy;
}






inline void
BitArray::Iterator::Set() const
{
    ;
    ;
    *m_word |= (1 << m_bitIndex);
    return;
}





inline void
BitArray::Iterator::Unset() const
{
    ;
    ;
    *m_word &= ~(1 << m_bitIndex);
    return;
}







inline
BitArray::ConstIterator::ConstIterator()
  : BitArray::IteratorBase()
{
    ;
    return;
}







inline
BitArray::ConstIterator::ConstIterator(BitArray::WordType *word, uint32_t bitIndex)
  : BitArray::IteratorBase(word, bitIndex)
{
    ;
    return;
}






inline
BitArray::ConstIterator::ConstIterator(const BitArray::IteratorBase &other)
  : BitArray::IteratorBase(other)
{
    ;
    return;
}






inline
BitArray::ConstIterator::~ConstIterator()
{
    ;
    return;
}





inline const BitArray::ConstIterator&
BitArray::ConstIterator::operator=(const BitArray::ConstIterator &other)
{
    ;
    BitArray::IteratorBase::operator=(other);
    return *this;
}





inline BitArray::ConstIterator&
BitArray::ConstIterator::operator++()
{
    ;
    MoveToNextBit();
    return *this;
}







inline BitArray::ConstIterator
BitArray::ConstIterator::operator+(uint32_t distance) const
{
    ;
    ConstIterator copy(*this);
    copy.MoveForward(distance);
    return copy;
}







inline BitArray::ConstIterator
BitArray::ConstIterator::operator-(uint32_t distance) const
{
    ;
    ConstIterator copy(*this);
    copy.MoveBackward(distance);
    return copy;
}






inline
BitArray::BitArray()
  : m_data(0),
    m_sizeInBits(0),
    m_sizeInWords(0)
{
    ;
    return;
}






inline
BitArray::~BitArray()
{
    ;
    return;
}









inline void
BitArray::Initialize(BitArray::WordType *mem, uint32_t sizeInBits)
{
    ;
    m_data = mem;
    m_sizeInBits = sizeInBits;
    m_sizeInWords = ((m_sizeInBits + (BITS_PER_WORD - 1)) >> WORD_SHIFT);
    return;
}







inline uint32_t
BitArray::GetSize() const
{
    ;
    return m_sizeInBits;
}








inline RwBool
BitArray::operator[](uint32_t index) const
{
    ;
    ;
    return (m_data[index >> WORD_SHIFT] >> (index & (BITS_PER_WORD - 1))) & 1;
}







inline RwBool
BitArray::at(uint32_t index) const
{
    ;
    ;
    return (*this)[index];
}








inline void
BitArray::Set(uint32_t index)
{
    ;
    ;
    m_data[index >> WORD_SHIFT] |= (1 << (index & (BITS_PER_WORD - 1)));
    return;
}






inline void
BitArray::Unset(uint32_t index)
{
    ;
    ;
    m_data[index >> WORD_SHIFT] &= ~(1 << (index & (BITS_PER_WORD - 1)));
    return;
}





inline void
BitArray::SetAll()
{
    ;

    WordType *pos = m_data, *last = m_data + m_sizeInWords;
    while (pos != last)
    {
        *pos++ = ~BitArray::WordType(0);
    }

    return;
}





inline void
BitArray::UnsetAll()
{
    ;

    WordType *pos = m_data, *last = m_data + m_sizeInWords;
    while (pos != last)
    {
        *pos++ = BitArray::WordType(0);
    }

    return;
}





inline BitArray::ConstIterator
BitArray::Begin() const
{
    ;
    return ConstIterator(m_data, 0);
}





inline BitArray::Iterator
BitArray::Begin()
{
    ;
    return Iterator(m_data, 0);
}





inline BitArray::ConstIterator
BitArray::End() const
{
    ;
    return ConstIterator(m_data + (m_sizeInBits >> WORD_SHIFT), m_sizeInBits & (BITS_PER_WORD - 1));
}





inline BitArray::Iterator
BitArray::End()
{
    ;
    return Iterator(m_data + (m_sizeInBits >> WORD_SHIFT), m_sizeInBits & (BITS_PER_WORD - 1));
}







inline BitArray::ConstIterator
BitArray::GetIterator(uint32_t index) const
{
    ;
    ;
    return ConstIterator(m_data + (index >> WORD_SHIFT), index & (BITS_PER_WORD - 1));
}







inline BitArray::Iterator
BitArray::GetIterator(uint32_t index)
{
    ;
    ;
    return Iterator(m_data + (index >> WORD_SHIFT), index & (BITS_PER_WORD - 1));
}





inline uint32_t
BitArray::GetIndex(const IteratorBase &iter) const
{
    ;
    return static_cast<uint32_t>((iter.m_word - m_data) * BITS_PER_WORD + iter.m_bitIndex);
}






inline BitArray::ConstWordIterator
BitArray::WordBegin() const
{
    ;
    return m_data;
}





inline BitArray::WordIterator
BitArray::WordBegin()
{
    ;
    return m_data;
}





inline BitArray::ConstWordIterator
BitArray::WordEnd() const
{
    ;
    return m_data + m_sizeInWords;
}





inline BitArray::WordIterator
BitArray::WordEnd()
{
    ;
    return m_data + m_sizeInWords;
}

}
