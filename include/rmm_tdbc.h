#ifndef AOE1_RMM_TDBC_H
#define AOE1_RMM_TDBC_H

#include "rmm_dbct.h"

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    TRIBE_RMM_Database_Controller(char*, char*, char*, char*);
    TRIBE_RMM_Database_Controller(int);

    virtual uchar init(RGE_Map*, RGE_Game_World*, uchar, long, uchar);
    virtual uchar de_init();

protected:
    virtual void add_land_module(uchar);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
    void add_shallows_module();

public:
    virtual uchar generate();
};

#endif
