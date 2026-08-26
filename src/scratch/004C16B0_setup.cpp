// VA: 004C16B0 RGE_Static_Object::setup
// Source: stat_obj.cpp lines 484-567
// Attempt log:
// 1: initial implementation from packet, shaped to original store/call order; wrong first param load/store and create-list vtable offset.
// 2: correct vtable padding to put create_object_list/create_sprite_list at +1E0/+1E4 and store owner before master.
// 3: source order master/type/owner made first param load wrong again; explicit p/m temps no change.
// 4: dead first owner assignment probe no change.
// 5: return to owner/type/master best early load family.
// 6: owner/master/type order probe no codegen change.
// 7: reorder world_y/world_z stores worsened set_position block.
// 8: restore z-before-y best shape.
// 9: local z temp before world/position call; no codegen change.
// 10: /Ot flag probe no change; removed flag.
// Follow-up: the +0x34 virtual is the proven float-returning teleport ABI; an
// ignored result supplies the original fstp st0.  Keeping the position stores
// in source order x/y/z restores VC5's original register schedule.
// Follow-up: source initialization order type/owner/master restores the
// original type-before-owner store while retaining the expected parameter
// preload.  Exact 398-byte match; typed period-plausible source, no asm/hack.
// BINARY NOTE: setup is a protected virtual member in the shipped symbol.
// BINARY NOTE: setup is a protected virtual member in the shipped symbol.

#include "../../include/stat_obj_context.h"

extern int __cdecl debug_rand(char* file, int line);
extern void __cdecl debug_srand(char* file, int line, int seed);
extern int debug_random_on;

int RGE_Static_Object::setup(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z)
{
    int old_debug;
    int seed;
    this->type = 10;
    this->owner = player;
    this->master_obj = master;
    this->tile = 0;
    this->inside_obj = 0;
    this->objects = this->create_object_list();

    this->hp = (float)(int)this->master_obj->hp;
    this->sleep_flag = (this->hp > 0.0f);
    this->dopple_flag = (this->master_obj->master_type == 0x19);

    this->facet = 0;
    this->world_x = -999.0f;
    this->world_y = -999.0f;
    this->world_z = 0.0f;
    this->screen_x_offset = 0;
    this->screen_y_offset = 0;
    this->shadow_x_offset = 0;
    this->shadow_y_offset = 0;
    this->selected = 0;
    this->selected_group = 0;
    this->worker_num = 0;
    this->object_state = 2;
    this->curr_damage_percent = 0;
    this->goto_sleep_flag = 0;
    this->get_starting_attribute();
    this->give_attribute_to_owner();

    if (this->master_obj->recyclable != 0) {
        this->id = this->owner->world->get_next_reusable_object_id();
    } else {
        this->id = this->owner->world->get_next_object_id();
    }
    this->sprite_list = this->create_sprite_list();
    this->new_sprite(this->master_obj->sprite);

    this->world_x = x;
    this->world_y = y;
    this->world_z = z;
    this->old_sprite = 0;
    this->teleport(x, y, z);

    this->player_object_node = this->owner->addObject(this, this->sleep_flag, this->dopple_flag);

    seed = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x22A);
    old_debug = debug_random_on;
    debug_random_on = 0;
    if (this->master_obj->created_sound != 0 && this->owner->id == this->owner->world->curr_player) {
        this->master_obj->created_sound->play(1);
    }
    debug_random_on = old_debug;
    debug_srand((char*)"C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x235, seed);
    return 1;
}
