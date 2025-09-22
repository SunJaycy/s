















































#include <rwmath.h>



#include <rw/datacontainer/accesstypes.h>
#include <rw/graphics/core/batchiteratorwrite.h>
#include <rw/graphics/core/iterator.h>
#include <rw/graphics/core/buffer.h>

#include <rw/graphics/core/objecttypes.h>

namespace rw
{
namespace graphics
{
namespace core
{











class RGBA32 : public rw::math::Vector4
{
    public:
        RGBA32(float32_t red, float32_t green, float32_t blue, float32_t alpha) :
          rw::math::Vector4(red, green, blue, alpha)
        {

        }

        rw::math::VecFloatRefX Red()
        {
           
            return rw::math::Vector4::X();
        };

        rw::math::VecFloatRefY Green()
        {
           
            return rw::math::Vector4::Y();
        };

        rw::math::VecFloatRefZ Blue()
        {
           
            return rw::math::Vector4::Z();
        };

        rw::math::VecFloatRefW Alpha()
        {
           
            return rw::math::Vector4::W();
        };

        const rw::math::VecFloatRefX Red() const
        {
           
            return rw::math::Vector4::X();
        };

        const rw::math::VecFloatRefY Green() const
        {
           
            return rw::math::Vector4::Y();
        };

        const rw::math::VecFloatRefZ Blue() const
        {
           
            return rw::math::Vector4::Z();
        };

        const rw::math::VecFloatRefW Alpha() const
        {
           
            return rw::math::Vector4::W();
        };
};


























extern uint32_t GetLibraryVersion();

extern void RegisterArenaReadCallbacks();
extern void RegisterArenaWriteCallbacks();










}
}
}




#include <rw/graphics/core/drvtypes.h>
