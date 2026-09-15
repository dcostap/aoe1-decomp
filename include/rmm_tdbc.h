#ifndef AOE1_RMM_TDBC_H
#define AOE1_RMM_TDBC_H

#include "rmm_dbct.h"

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    TRIBE_RMM_Database_Controller(char* land_file, char* terrain_file, char* object_file, char* map_file);
    TRIBE_RMM_Database_Controller(int infile);

    virtual uchar init(RGE_Map* in_map, RGE_Game_World* in_world, uchar type, long player_num, uchar fixed_position);
    virtual uchar de_init();

protected:
    virtual void add_land_module(uchar fixed_positions);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
    void add_shallows_module();

public:
    virtual uchar generate();
};

#endif
