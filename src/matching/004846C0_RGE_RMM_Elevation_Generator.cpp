// first pass: delegate to the random-map module ctor, then copy the 0x3e0-byte elevation block and set the scalar field
// if this misses, the remaining mismatch is likely only the bulk-copy shape versus the original rep movsd basin

#include <string.h>

class RGE_Map;
class RGE_Random_Map_Module {
public:
    RGE_Random_Map_Module(RGE_Map* map, RGE_Random_Map_Module* module, int enable);
};

struct RGE_Elevation_Info {
    long data[0x3E0];
};

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    void* vftable;
    char gap_04[0x18];
    unsigned long field_1C;
    char gap_20[0x10];
    RGE_Elevation_Info info;

    RGE_RMM_Elevation_Generator(RGE_Map* map, RGE_Random_Map_Module* module, RGE_Elevation_Info* info);
};

RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator(RGE_Map* map, RGE_Random_Map_Module* module, RGE_Elevation_Info* info)
    : RGE_Random_Map_Module(map, module, 1) {
    this->vftable = (void*)0x00571EC4;
    memcpy(&this->info, info, 0x3E0 * sizeof(long));
    this->field_1C = 0x3FC00000;
}
