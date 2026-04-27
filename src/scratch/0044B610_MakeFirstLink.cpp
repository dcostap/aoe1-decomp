// VA: 0044B610 MakeFirstLink (332B)
// fractal.cpp

#include <stdlib.h>

class RGE_Fractal {
public:
    char gap4[0x1008];
    int field_100C;
    char gap1010[0x34];
    int field_1044;
    
    void MakeFirstLink();
};

void RGE_Fractal::MakeFirstLink() {
    int randVal = field_100C;
    if (randVal > 0) {
        field_1044 = rand() % randVal;
    }
    randVal = field_100C;
    if (randVal > 0) {
        field_1044 = rand() % randVal;
    }
}
