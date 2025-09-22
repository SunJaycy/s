




















namespace rw
{
    namespace core
    {
        namespace stdc
        {





















            void MemCopy(void* destPtr,const void* sourcePtr,unsigned int byteCount);
            void MemMove(void* destPtr,const void* sourcePtr,unsigned int byteCount);
            void MemFill8(void* destPtr,unsigned char value,unsigned int byteCount);
            void MemFill16(void* destPtr,uint16_t value,unsigned int byteCount);










            void MemFill32(void* destPtr,unsigned int value,unsigned int byteCount);
            void MemFillSpecific(void* destPtr,const void* sourcePtr,unsigned int destByteCount,unsigned int sourceByteCount);
            void MemClear(void* destPtr,unsigned int byteCount);
            int MemCompare(const void* source1,const void* source2,unsigned int byteCount);
        }
    }
}
