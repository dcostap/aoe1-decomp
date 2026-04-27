// VA: 0044B760 MakeNewLink (496B)
// fractal.cpp

#include <stdlib.h>

class RGE_Fractal {
public:
    char gap4[0x1008];
    int field_100C;
    char gap1010[0x34];
    int field_1044;
    
    void MakeNewLink();
};

void RGE_Fractal::MakeNewLink() {
    int randVal = field_100C;
    if (randVal > 0) {
        field_1044 = rand() % randVal;
    }
}
