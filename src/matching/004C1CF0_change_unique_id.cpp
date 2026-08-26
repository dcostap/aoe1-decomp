// attempt 1: direct owner/world update with the virtual owner callback and the recyclable-object-id branch
// exact match landed once the first callback used player_object_node at +0x50 and the second callback stored the new node back there
#include "..\..\include\game_types.h"

void RGE_Static_Object::change_unique_id() {
    this->owner->removeObject(this, this->sleep_flag, this->dopple_flag, this->player_object_node);

    if (this->master_obj->recyclable != 0) {
        this->id = this->owner->world->get_next_reusable_object_id();
    } else {
        this->id = this->owner->world->get_next_object_id();
    }
    this->player_object_node = this->owner->addObject(this, this->sleep_flag, this->dopple_flag);
}
