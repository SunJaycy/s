




















namespace rw
{
    namespace core
    {
        namespace stdc
        {









            enum UtilValues
            {
                DEFAULT_CRC16_SEED = 0xfbea
            };








            inline void *AlignAddrUp(
                void *p,
                unsigned int a
                )
            {

                ;
                return reinterpret_cast<void *>((reinterpret_cast<uintptr_t>(p)+(a-1))&~(a-1));
            }





            inline void *AlignAddrDown(
                void *p,
                unsigned int a
                )
            {

                ;
                return reinterpret_cast<void *>((reinterpret_cast<uintptr_t>(p))&~(a-1));
            }






            inline unsigned int GetUnalignedUnsignedInt(const void *ptr)
            {
                ;
                return *reinterpret_cast<const unsigned int *>(ptr);
            }


            inline int16_t Min(int16_t numA,int16_t numB)
            {
                ;
                return (((numA)<(numB))?(numA):(numB));
            }
            inline int16_t Max(int16_t numA,int16_t numB)
            {
                ;
                return (((numA)>(numB))?(numA):(numB));
            }
            inline uint16_t Min(uint16_t numA,uint16_t numB)
            {
                ;
                return (((numA)<(numB))?(numA):(numB));
            }
            inline uint16_t Max(uint16_t numA,uint16_t numB)
            {
                ;
                return (((numA)>(numB))?(numA):(numB));
            }
            inline int Min(int numA,int numB)
            {
                ;
                return (((numA)<(numB))?(numA):(numB));
            }
            inline int Max(int numA,int numB)
            {
                ;
                return (((numA)>(numB))?(numA):(numB));
            }
            inline unsigned int Min(unsigned int numA,unsigned int numB)
            {
                ;
                return static_cast<unsigned int>(((numA)<(numB))?(numA):(numB));
            }
            inline unsigned int Max(unsigned int numA,unsigned int numB)
            {
                ;
                return static_cast<unsigned int>(((numA)>(numB))?(numA):(numB));
            }
            inline int64_t Min(int64_t numA,int64_t numB)
            {
                ;
                return (((numA)<(numB))?(numA):(numB));
            }
            inline int64_t Max(int64_t numA,int64_t numB)
            {
                ;
                return (((numA)>(numB))?(numA):(numB));
            }
            inline uint64_t Min(uint64_t numA,uint64_t numB)
            {
                ;
                return (((numA)<(numB))?(numA):(numB));
            }
            inline uint64_t Max(uint64_t numA,uint64_t numB)
            {
                ;
                return (((numA)>(numB))?(numA):(numB));
            }


            uint16_t CalculateCrc16(const void *buf, unsigned int bufsize, uint16_t seed=DEFAULT_CRC16_SEED);
            unsigned int CalculateCrc32(const void *buf, unsigned int bufsize);
        }
    }
}
