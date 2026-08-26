#include "../world_phase2_context.h"

unsigned char RGE_Game_World::recycle_object_out_of_game(unsigned char param_1, RGE_Static_Object* param_2) {
    switch (param_1) {
    case 0x0A:
        reusable_static_objects->add_node(param_2);
        return 1;
    case 0x14:
        reusable_animated_objects->add_node(param_2);
        return 1;
    case 0x1E:
        reusable_moving_objects->add_node(param_2);
        return 1;
    case 0x28:
        reusable_action_objects->add_node(param_2);
        return 1;
    case 0x32:
        reusable_combat_objects->add_node(param_2);
        return 1;
    case 0x3C:
        reusable_missile_objects->add_node(param_2);
        return 1;
    case 0x19:
        reusable_doppleganger_objects->add_node(param_2);
        return 1;
    default:
        return 0;
    }
}
