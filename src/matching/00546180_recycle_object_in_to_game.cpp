// VA: 00546180 RGE_Game_World::recycle_object_in_to_game (250 bytes)
// PDB: World.cpp lines 3841-3898
//
// Status: active matching reconstruction
#include "../world_phase2_context.h"
//
// Attempt log:
// Prior parked attempts used a common break/result shape and produced a
// shared handler basin (224 bytes).  The binary's first six cases return from
// their own bodies; only the final case falls through to the common return.

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
