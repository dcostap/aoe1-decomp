// VA: 004C1420 RGE_Static_Object::recycle_in_to_game
// Source: stat_obj.cpp lines 336-398
// Attempt log:
// Attempt log:
// - natural typed initialization matched the first 0xFD bytes and all eight
//   calls, leaving only the ignored float result of the +0x34 virtual call;
// - ABI query and the original FPU sequence identified +0x34 as the real
//   float-returning teleport method, so its ignored result naturally emits the
//   required fstp st0 before addObject;
// - replacing owner/world offset casts with the proven RGE_Player::id/world
//   and RGE_Game_World::curr_player fields preserved the exact output;
// - exact 361-byte match; source is typed, period-plausible, and has no asm or
//   compiler-only scaffolding.

#include "../../include/stat_obj_context.h"

extern int __cdecl debug_rand(char* file, int line);
extern void __cdecl debug_srand(char* file, int line, int seed);
extern int debug_random_on;

void RGE_Static_Object::recycle_in_to_game(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z)
{
    this->old_sprite = 0;
    this->unitAIValue = 0;
    this->underAttackValue = 0;
    this->sprite = 0;
    this->groupCommanderValue = -1;
    this->groupRangeValue = 5.0f;
    this->owner = player;
    this->master_obj = master;
    this->tile = 0;
    this->inside_obj = 0;

    this->hp = (float)(int)master->hp;
    this->sleep_flag = (this->hp > 0.0f);
    this->dopple_flag = (master->master_type == 0x19);

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
    this->player_object_node = 0;

    this->get_starting_attribute();
    this->give_attribute_to_owner();

    this->new_sprite(this->master_obj->sprite);
    this->world_x = x;
    this->world_y = y;
    this->world_z = z;
    this->old_sprite = 0;
    this->teleport(x, y, z);

    this->player_object_node = this->owner->addObject(this, this->sleep_flag, this->dopple_flag);

    int seed = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x183);
    int old_debug = debug_random_on;
    debug_random_on = 0;

    RGE_Sound* sound = this->master_obj->created_sound;
    if (sound != 0 && this->owner->id == this->owner->world->curr_player) {
        sound->play(1);
    }

    debug_random_on = old_debug;
    debug_srand((char*)"C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x18D, seed);
}
