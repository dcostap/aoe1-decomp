// 004C8740 TRIBE_Building_Object::set_object_state
// Source: t_b_obj.cpp lines 289-391
// Attempt log:
// - Replaced the former partial/manual-vtable scaffold with a complete typed
//   state-2 build path, state-3 doppleganger cleanup, terrain updates, tech
//   bookkeeping, and qualified base state call.
// - Baseline is intentionally period-plausible and uses real virtual/member
//   surfaces for the observed slots; no explicit vptr or raw vtable calls.
// - Corrected the inherited Static->Moving->Action->Combat->TRIBE_Combat
//   boundary and the +1C8 production-queue block before building fields.
// - Inverted the play-animation arm, used direct typed map calls, and bound
//   only positive terrain extents to DAT_005749E8; this recovered exact size,
//   ordered calls, CFG, and nearly all bytes.
// - The final two-byte drift was the terrain-object create argument order;
//   the binary pushes world_z, world_y, world_x, so the natural call is
//   create(owner, world_x, world_y, world_z). Exact after validation.

#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::set_object_state(uchar state)
{
    uchar dopple_removed;

    uchar state_copy;
    state_copy = state;

    if (state_copy == 2) {
        this->build_pts = (float)(int)this->master_obj->build_time;

        int random_value = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\t_b_obj.cpp", 0x12B);
        int old_random = debug_random_on;
        debug_random_on = 0;

        RGE_Sound* sound = this->master_obj->completion_sound;
        if (sound != 0 && this->owner->id == this->owner->world->sound_player_id) {
            sound->play(1);
        }

        debug_random_on = old_random;
        debug_srand((char*)"C:\\msdev\\work\\age1_x1\\t_b_obj.cpp", 0x135,
                    random_value);

        this->built = 1;
        this->give_building_attribute_to_owner();

        if (this->master_obj->play_animation_flag != 0) {
            this->die_die_die();
        } else {
            this->unexplore_terrain(this->owner, 1, -1);
            this->explore_terrain(this->owner, 0, -1);
            this->new_sprite((RGE_Sprite*)this->master_obj->action_value);
            this->terrain_restriction = this->master_obj->gather_flag_copy;
            if (this->master_obj->connect_flag != 0) {
                this->connect();
            }
        }

        if (this->master_obj->terrain_1 > -1) {
            this->owner->object_infos[this->master_obj->terrain_1]->make_new_obj(
                this->owner, this->world_x, this->world_y, this->world_z);
        }

        if (this->master_obj->terrain_2 > -1) {
            RGE_Game_World* world = this->owner->world;
            world->map->set_terrain(
                world->players[0], world,
                (long)(this->world_x - this->master_obj->radius_x),
                (long)(this->world_y - this->master_obj->radius_y),
                (long)(this->world_x + this->master_obj->radius_x - DAT_005749E8),
                (long)(this->world_y + this->master_obj->radius_y - DAT_005749E8),
                (uchar)this->master_obj->terrain_2, 1, 0);

            this->owner->world->map->request_redraw(
                (short)(this->world_x - this->master_obj->radius_x) - 1,
                (short)(this->world_y - this->master_obj->radius_y) - 1,
                (short)(this->world_x + this->master_obj->radius_x - DAT_005749E8) + 1,
                (short)(this->world_y + this->master_obj->radius_y - DAT_005749E8) + 1,
                0);
        }

        if (this->master_obj->tech_id > -1) {
            this->owner->tech->do_tech(this->master_obj->tech_id);
        }

        rge_base_game->send(0x69, (int)this->owner->id,
                            (int)this->master_obj->id,
                            (int)(this->world_x), (int)(this->world_y));
        this->owner->notify_building(this, this->unique_build_id);
    }

    if (state_copy == 3 && this->object_state == 2) {
        this->take_building_attribute_from_owner();
        this->owner->doppleganger_creator->remove_doppleganger_check(this);
        this->dopple_installed = 0;
        dopple_removed = 1;
    } else {
        dopple_removed = 0;
    }

    RGE_Static_Object::set_object_state(state);

    if (dopple_removed != 0) {
        RGE_Static_Object* object = this->owner->objects->find_by_master_id(
            (long)this->master_obj->id, -1.0f, -1.0f, 1, 2, 0);
        if (object == 0) {
            if (this->master_obj->tech_id > -1) {
                this->owner->tech->undo_tech(this->master_obj->tech_id);
            }
            this->owner->tech->undo_tech(0x4A);
            this->owner->tech->undo_tech(0x4B);
            this->owner->tech->undo_tech(0x4C);
        }
    }
}
