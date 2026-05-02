// VA: 00546180 RGE_Game_World::recycle_object_in_to_game (250 bytes)
// PDB: World.cpp lines 3841-3898
// __thiscall, returns RGE_Static_Object*, takes unsigned char param

struct RGE_Static_Object;

struct RGE_Object_Node {
    RGE_Static_Object* node;   // +0x00
    RGE_Object_Node* next;      // +0x04
    RGE_Object_Node* prev;      // +0x08
};

struct RGE_Object_List {
    void* vtable_ptr;            // +0x00
    RGE_Object_Node* list;       // +0x04
    short number_of_objects;     // +0x08

    void remove_node(RGE_Static_Object* object, RGE_Object_Node* node);
};

class RGE_Game_World {
public:
    void* vtable_ptr;                                // +0x00
    char gap_04[0xD4];                               // +0x04 to +0xD7
    RGE_Object_List* reusable_static_objects;         // +0xD8
    RGE_Object_List* reusable_animated_objects;        // +0xDC
    RGE_Object_List* reusable_moving_objects;          // +0xE0
    RGE_Object_List* reusable_action_objects;          // +0xE4
    RGE_Object_List* reusable_combat_objects;          // +0xE8
    RGE_Object_List* reusable_missile_objects;         // +0xEC
    RGE_Object_List* reusable_doppleganger_objects;    // +0xF0

    RGE_Static_Object* recycle_object_in_to_game(unsigned char param_1);
};

RGE_Static_Object* RGE_Game_World::recycle_object_in_to_game(unsigned char param_1) {
    RGE_Object_List* list;
    RGE_Object_Node* node;

    switch (param_1) {
    case 0x0A:
        list = this->reusable_static_objects;
        node = list->list;
        if (node) {
            list->remove_node(node->node, 0);
            return node->node;
        }
        break;

    case 0x14:
        list = this->reusable_animated_objects;
        node = list->list;
        if (node) {
            list->remove_node(node->node, 0);
            return node->node;
        }
        break;

    case 0x1E:
        list = this->reusable_moving_objects;
        node = list->list;
        if (node) {
            list->remove_node(node->node, 0);
            return node->node;
        }
        break;

    case 0x28:
        list = this->reusable_action_objects;
        node = list->list;
        if (node) {
            list->remove_node(node->node, 0);
            return node->node;
        }
        break;

    case 0x32:
        list = this->reusable_combat_objects;
        node = list->list;
        if (node) {
            list->remove_node(node->node, 0);
            return node->node;
        }
        break;

    case 0x3C:
        list = this->reusable_missile_objects;
        node = list->list;
        if (node) {
            list->remove_node(node->node, 0);
            return node->node;
        }
        break;

    case 0x19:
        list = this->reusable_doppleganger_objects;
        node = list->list;
        if (node) {
            list->remove_node(node->node, 0);
            return node->node;
        }
        break;
    }

    return 0;
}
