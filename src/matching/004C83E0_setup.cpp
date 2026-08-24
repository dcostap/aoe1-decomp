// VA: 004C83E0 TRIBE_Building_Object::setup
// t_b_obj.cpp:176-199
// Retry 2026-05-24: replaced stale stub with packet-derived building setup body.

#include "../../include/t_b_obj_context.h"

int TRIBE_Building_Object::setup(TRIBE_Master_Building_Object* master, RGE_Player* player, float x, float y, float z)
{
    built = 0;
    TRIBE_Combat_Object::setup(master, player, x, y, z);
    object_type = 0x50;
    this->set_object_state(0);
    TRIBE_Master_Building_Object* master2 = master_obj;
    if (master2->word_15A > 0) {
        this->new_sprite((RGE_Sprite*)master2->field_168);
    }
    master2 = master_obj;
    build_pts = 0;
    field_30 = 1.0f;
    terrain_restriction = master2->terrain_restriction;
    culture = player->culture;
    world->destructables->check_destructables(world->map_id, master2->id, tile_y, tile_x, 0);
    production_queue_actions = this->create_action_list();
    return 1;
}
