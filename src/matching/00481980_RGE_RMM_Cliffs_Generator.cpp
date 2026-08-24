#ifdef RMM_CLIF_SHARED_CONTEXT
#include "../../include/rmm_clif_context.h"
#else
#include "../../include/rmm_obj_base_context.h"

// BINARY NOTE: PDB passes RGE_Cliffs_Info by value. Its 0x4C0-byte layout
// accounts for the constructor's ret 0x4C8 cleanup and rep movsd copy.
struct RGE_Cliffs_Hot_Spots {
    long x;
    long y;
    long radius;
};

struct RGE_Cliffs_Info {
    long number_of_cliffs;
    long number_of_cliffs_variance;
    long average_cliff_size;
    long cliff_size_variance;
    long cliff_terrain_spacing;
    long cliff_to_cliff_spacing;
    RGE_Cliffs_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    RGE_Cliffs_Info info;

    RGE_RMM_Cliffs_Generator(RGE_Map* map, RGE_Random_Map_Module* module, RGE_Cliffs_Info cliffs_info);
};
#endif

RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Generator(RGE_Map* map, RGE_Random_Map_Module* module, RGE_Cliffs_Info cliffs_info)
    : RGE_Random_Map_Module(map, module, 1) {
    this->info = cliffs_info;
    this->schedule = 1.75f;
}
