// first pass: delegate to the random-map module ctor, then copy the 0x130-byte cliff info block and set the scalar field
// if this misses, the remaining mismatch is likely only the bulk-copy shape versus the original rep movsd basin

class RGE_Map;
class RGE_Random_Map_Module {
public:
    RGE_Random_Map_Module(RGE_Map* map, RGE_Random_Map_Module* module, int enable);
};

struct RGE_Cliffs_Info {
    long data[0x130];
};

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    void* vftable;
    char gap_04[0x18];
    unsigned long field_1C;
    char gap_20[0x10];
    RGE_Cliffs_Info info;

    RGE_RMM_Cliffs_Generator(RGE_Map* map, RGE_Random_Map_Module* module, RGE_Cliffs_Info cliffs_info);
};

RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Generator(RGE_Map* map, RGE_Random_Map_Module* module, RGE_Cliffs_Info cliffs_info)
    : RGE_Random_Map_Module(map, module, 1) {
    this->vftable = (void*)0x00571E64;
    this->info = cliffs_info;
    this->field_1C = 0x3FE00000;
}
