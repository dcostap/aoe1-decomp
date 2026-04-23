// first pass: delegate to the random-map module ctor, then stamp the vtable/scale fields and copy the 0x50e-long land block
// if this misses, the remaining mismatch is likely only the bulk-copy shape versus the original rep movsd basin

#include <string.h>

class RGE_Map;
class RGE_Random_Map_Module {
public:
    RGE_Random_Map_Module(RGE_Map* map, RGE_Random_Map_Module* module, int enable);
};

struct RGE_Land_Info {
    long data[0x50E];
};

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
public:
    void* vftable;
    char gap_04[0x18];
    unsigned long field_1C;
    char gap_20[0x10];
    RGE_Land_Info info;

    RGE_RMM_Land_Generator(RGE_Map* map, RGE_Random_Map_Module* module, RGE_Land_Info* info);
};

RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(RGE_Map* map, RGE_Random_Map_Module* module, RGE_Land_Info* info)
    : RGE_Random_Map_Module(map, module, 1) {
    this->vftable = (void*)0x00571EC8;
    this->field_1C = 0x3F800000;
    memcpy(&this->info, info, 0x50E * sizeof(long));
}
