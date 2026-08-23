// 00483540 init
// Tried the obvious derived-only surface first. Because the base lacked a
// vptr, VC5 treated the random-map-module subobject as starting at +4 and
// emitted `lea edi,[esi+4]` before helper calls. Use the real polymorphic base
// so helper calls stay on ecx = esi, and keep the full virtual slot order so
// the four module calls land at vt[1..4] rather than vt[0..3].
// Context audit: this owner uses the canonical rmm_dbct random-map surface.

#include "..\..\include\rmm_dbct_context.h"

uchar RGE_RMM_Database_Controller::init(RGE_Map* param_1,
                                        RGE_Game_World* param_2,
                                        uchar param_3, long param_4,
                                        uchar param_5) {
    this->world = param_2;
    this->map_type = param_3;
    this->number_of_players = param_4;
    this->update_map_info(param_1);
    this->create_shared_resources();
    this->add_land_module(param_5);
    this->add_terrain_module();
    this->add_object_module();
    this->add_elevation_module();
    return 1;
}
