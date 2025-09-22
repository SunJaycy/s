




#include <eabase/eabase.h>




#include <rw/math/vpu/detail/ps3/ppu/vector_intrinsic.h>












namespace rw {
namespace math {
namespace vpu {



        typedef VectorIntrinsic Vector4Intrinsic_32;


        typedef VectorIntrinsicInParam Vector4Intrinsic_32_InParam;



    namespace detail
    {

        union VectorIntrinsicUnion
        {
            uint32_t scalarUInt[4];
            float scalarFloat[4];
            VectorIntrinsic vector;
        };
    }
}}}
