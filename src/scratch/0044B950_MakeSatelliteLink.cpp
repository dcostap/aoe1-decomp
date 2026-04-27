// VA: 0044B950 MakeSatelliteLink (336B)
// fractal.cpp

#include <stdlib.h>

class RGE_Fractal {
public:
    char gap4[0x1004];
    int field_1008;
    char gap100C[0x38];
    int field_1044;
    
    void MakeSatelliteLink();
};

void RGE_Fractal::MakeSatelliteLink() {
    int randVal = field_1008;
    if (randVal > 0) {
        field_1044 = rand() % randVal;
    }
}
