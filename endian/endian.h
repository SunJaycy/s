






namespace rw
{
    namespace core {
        namespace endian {





            inline uint32_t ConvertLittle(const uint32_t x);





            inline uint16_t ConvertLittle(const uint16_t x);





            inline int32_t ConvertLittle(const int32_t x);





            inline int16_t ConvertLittle(const int16_t x);





            inline uint64_t ConvertLittle(const uint64_t x);





            inline int64_t ConvertLittle(const int64_t x);





            inline uint32_t ConvertBig(const uint32_t x);





            inline uint16_t ConvertBig(const uint16_t x);






            inline int32_t ConvertBig(const int32_t x);





            inline int16_t ConvertBig(const int16_t x);





            inline uint64_t ConvertBig(const uint64_t x);





            inline int64_t ConvertBig(const int64_t x);





            inline uint32_t make_id32(uint8_t a, uint8_t b, uint8_t c, uint8_t d);








            inline void PutBig(void* dst, uint32_t data, int32_t n);








            inline void PutLittle(void *dst, uint32_t data, int32_t n);








            inline uint32_t GetBig(const void* src, int32_t n);








            inline uint32_t GetLittle(const void* src, int32_t n);







            inline void PutBig64(void* dst, uint64_t data, int32_t n);







            inline void PutLittle64(void *dst, uint64_t data, int32_t n);







            inline uint64_t GetBig64(const void* src, int32_t n);







            inline uint64_t GetLittle64(const void* src, int32_t n);
        }
    }
}

#include <rw/core/endian/detail/endian_inlines.h>
