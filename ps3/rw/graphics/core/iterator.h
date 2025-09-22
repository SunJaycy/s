










namespace rw
{
namespace graphics
{






    template<class TYPE>
    inline void rwgConvert(TYPE &destination, const TYPE &source)
    {
        destination = source;
    }






    template<class DESTINATION, class SOURCE>
    inline void rwgConvertWrite(void *&ptr, const SOURCE &source)
    {
        rwgConvert(*reinterpret_cast<DESTINATION *>(ptr), source);
        ptr = MemAddOffset(ptr, sizeof(DESTINATION));
    }






    template<class SOURCE, class DESTINATION>
    inline void rwgConvertRead(const void *&ptr, DESTINATION &destination)
    {
        rwgConvert(destination, *reinterpret_cast<const SOURCE *>(ptr));
        ptr = MemAddOffset(ptr, sizeof(SOURCE));
    }












class IteratorWrite
{
public:

    void GetReadAddresses(const void *&low, const void *&high) const;
    void GetWriteAddresses(void *&low, void *&high) const;
    bool IsFull() const;
    void SetReadAddresses(const void *low, const void *high);
    void SetWriteAddresses(void *low, void *high);
    template<class INTERFACE> void Write(const INTERFACE &value);
    void Write( const void* buffer, uint32_t size );

    void AddOffset( int32_t size );

private:
    void *mCurrent;
    void *mHigh;
    void *mLow;
};







inline
void IteratorWrite::GetReadAddresses(const void *&, const void *&) const
{
}







inline
void IteratorWrite::GetWriteAddresses(void *&low, void *&high) const
{
    low = mLow;
    high = mCurrent;
}






inline bool IteratorWrite::IsFull() const
{
    return mHigh < mCurrent;
}




inline void IteratorWrite::SetReadAddresses(const void *, const void *)
{
}




inline void IteratorWrite::SetWriteAddresses(void *low, void *high)
{
    mCurrent = low;
    mHigh = MemSubtractOffset(high, 4);
    mLow = low;
}






template<class INTERFACE>
inline void IteratorWrite::Write(const INTERFACE &value)
{
    void *current = mCurrent;
    rwgConvertWrite<INTERFACE>(current, value);
    {
        mCurrent = current;
    }
}

inline void
IteratorWrite::Write( const void* source, uint32_t size )
{
    memcpy(mCurrent, source, size);
    mCurrent = MemAddOffset(mCurrent, size);
}

inline void
IteratorWrite::AddOffset( int32_t size )
{
    mCurrent = MemAddOffset(mCurrent, size);
}









class IteratorRead
{
public:
    void GetReadAddresses(const void *&low, const void *&high) const;
    void GetWriteAddresses(void *&low, void *&high) const;
    bool IsEmpty() const;
    void SetReadAddresses(const void *low, const void *high);
    void SetWriteAddresses(void *low, void *high);
    template<class INTERFACE> void Read(INTERFACE &value);

    void AddOffset( int32_t size );
private:
    const void *mCurrent;
    const void *mHigh;
    const void *mLow;
};






inline void
IteratorRead::GetReadAddresses(const void *&low, const void *&high) const
{
    low = mLow;
    high = mCurrent;
}






inline void
IteratorRead::GetWriteAddresses(void *&, void *&) const
{
}







inline bool
IteratorRead::IsEmpty() const
{
    return mCurrent >= mHigh;
}






inline void
IteratorRead::SetReadAddresses(const void *low, const void *high)
{
    mCurrent = low;
    mHigh = MemSubtractOffset(high, sizeof(4));
    mLow = low;
}





inline void
IteratorRead::SetWriteAddresses(void *, void *)
{
}






template<class INTERFACE>
inline void IteratorRead::Read(INTERFACE &value)
{
    ;
    rwgConvertRead<INTERFACE>(mCurrent, value);
}

inline void
IteratorRead::AddOffset( int32_t size )
{
    mCurrent = MemAddOffset(mCurrent, size);
}
}
}
