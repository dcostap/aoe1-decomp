// VA: 00546180 RGE_Game_World::recycle_object_in_to_game (250 bytes)
// PDB: World.cpp lines 3841-3898
//
// Status: active matching reconstruction
//
// Attempt log:
// Prior parked attempts used a common break/result shape and produced a
// shared handler basin (224 bytes).  The binary's first six cases return from
// their own bodies; only the final case falls through to the common return.

#ifndef WORLD_TU
struct RGE_Static_Object;

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
};

struct RGE_Object_List {
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;

    void remove_node(RGE_Static_Object* object, RGE_Object_Node* node);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0xD4];
    RGE_Object_List* reusable_static_objects;
    RGE_Object_List* reusable_animated_objects;
    RGE_Object_List* reusable_moving_objects;
    RGE_Object_List* reusable_action_objects;
    RGE_Object_List* reusable_combat_objects;
    RGE_Object_List* reusable_missile_objects;
    RGE_Object_List* reusable_doppleganger_objects;

    RGE_Static_Object* recycle_object_in_to_game(unsigned char param_1);
};
#endif

RGE_Static_Object* RGE_Game_World::recycle_object_in_to_game(unsigned char param_1) {
    RGE_Static_Object* result = 0;
    RGE_Object_List* lst;
    RGE_Object_Node* nod;

    switch (param_1) {
    case 0x0A:
        lst = this->reusable_static_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x14:
        lst = this->reusable_animated_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x1E:
        lst = this->reusable_moving_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x28:
        lst = this->reusable_action_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x32:
        lst = this->reusable_combat_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x3C:
        lst = this->reusable_missile_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x19:
        lst = this->reusable_doppleganger_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
        }
        break;
    }

    return result;
}
