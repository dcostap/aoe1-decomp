// VA: 004CA8C0 TRIBE_Combat_Object::change_ownership
// PDB source: t_c_obj.cpp lines 368-424
// Canonical ownership is the shipped TRIBE_Combat_Object class.

#include "../../include/t_c_obj_context.h"

void TRIBE_Combat_Object::change_ownership(RGE_Player* player)
{
    if (this->id >= 0) {
        for (int i = 0; i < 9; ++i) {
            if (this->VUR_Ptrs[i] != 0) {
                this->VUR_Ptrs[i]->player = (unsigned char)player->id;
            }
        }
    }

    if (this->master_obj->object_group == 1) {
        ((RGE_Action_Object*)this)->change_ownership(player);
        return;
    }

    if (player->master_objects[this->master_obj->id] != 0) {
        if ((this->selected & 1) != 0) {
            this->owner->unselect_one_object((RGE_Static_Object*)this);
        }

        ((RGE_Static_Object*)this)->take_attribute_from_owner();

        this->owner->removeObject((RGE_Static_Object*)this,
                                  this->sleep_flag,
                                  this->dopple_flag,
                                  this->player_object_node);
        this->player_object_node = player->addObject((RGE_Static_Object*)this,
                                                       this->sleep_flag,
                                                       this->dopple_flag);

        if (this->object_state == 2) {
            this->unexplore_terrain(this->owner, 0, -1);
        }

        this->owner = player;

        if (this->own_master == 0) {
            this->master_obj = this->master_obj->make_new_master();
            this->own_master = 1;
        }

        if (this->object_state == 2) {
            this->explore_terrain(this->owner, 0, -1);
        }

        ((RGE_Static_Object*)this)->give_attribute_to_owner();

        if (this->unitAIValue != 0) {
            this->unitAIValue->purgeNotifyQueue(this->owner->world->world_time);
        }

        this->notify(this->id, this->id, 0x20B, player->id, 0, 0);
    }
}
