




#include <rw/math/detail/base.h>

namespace rw {
namespace math {






    unsigned int Random();






    void SeedRandom(unsigned int seed);








    class RandomNumberGenerator
    {
    public:





        RandomNumberGenerator();






        unsigned int Random();





        void Seed(unsigned int seed);

    private:
        unsigned int mSeedArray[6];
    };


}}
