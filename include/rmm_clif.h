#ifndef AOE1_RMM_CLIF_H
#define AOE1_RMM_CLIF_H


#include "rmm_base.h"

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

typedef char RMM_Clif_Info_Size_Check[
    (sizeof(RGE_Cliffs_Info) == 0x4C0) ? 1 : -1];

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    virtual uchar generate();

    RGE_Cliffs_Info info;
    Map_Stack valid_cliff_sites;

    RGE_RMM_Cliffs_Generator(RGE_Map* map,
        RGE_Random_Map_Module* module, RGE_Cliffs_Info cliffs_info);

protected:
    void setup_cliff_maps();
    void generate_cliff();
    uchar check_for_valid_cliff_site(long direction, long& y,
        long& valid_height, long index);
    void invalidate_cliff_area(long x, long y, long spacing);
};

typedef char RMM_Clif_Generator_Size_Check[
    (sizeof(RGE_RMM_Cliffs_Generator) == 0x508) ? 1 : -1];

#endif
