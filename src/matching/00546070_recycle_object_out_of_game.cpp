#ifndef WORLD_TU
class RGE_Object_List {
public:
    void add_node(void* obj);
};

class RGE_Game_World {
public:
    void* vtable_ptr;                              // +0x00
    char gap_04[0xD4];                             // +0x04 to +0xD7
    RGE_Object_List* reusable_static_objects;       // +0xD8
    RGE_Object_List* reusable_animated_objects;      // +0xDC
    RGE_Object_List* reusable_moving_objects;        // +0xE0
    RGE_Object_List* reusable_action_objects;        // +0xE4
    RGE_Object_List* reusable_combat_objects;        // +0xE8
    RGE_Object_List* reusable_missile_objects;       // +0xEC
    RGE_Object_List* reusable_doppleganger_objects;  // +0xF0

    unsigned char recycle_object_out_of_game(unsigned char param_1, void* param_2);
};
#endif

unsigned char RGE_Game_World::recycle_object_out_of_game(unsigned char param_1, void* param_2) {
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

void RGE_Object_List::add_node(void* obj) { }
