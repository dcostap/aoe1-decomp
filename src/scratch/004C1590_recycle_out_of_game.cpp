// VA: 004C1590 | RGE_Static_Object::recycle_out_of_game | stat_obj.cpp:406-477
//
// Attempt log:
// baseline: natural typed cleanup reconstructed from the original call order,
// exact stat_obj.cpp layouts, and the executable's virtual slots.
// main-agent audit restored canonical object-list/master/player/world virtual
// ownership; emitted code remains exact.

#include "../../include/stat_obj_context.h"

void RGE_Static_Object::recycle_out_of_game() {
    if (this->master_obj->recyclable != 0 &&
        this->owner->world->recycle_object_out_of_game(
            this->master_obj->master_type, this) != 0) {
        if (this->object_state < 3) {
            this->take_attribute_from_owner();
        }
        if (this->object_state < 7) {
            this->owner->victory_conditions->update_for_object(this);
        }
        if (this->sprite_list != 0) {
            this->sprite_list->delete_list();
        }
        if (this->owner != 0) {
            if ((this->selected & 1) != 0) {
                this->owner->unselect_one_object(this);
            }
            this->owner->removeObject(this, this->sleep_flag,
                                      this->dopple_flag,
                                      this->player_object_node);
            this->owner = 0;
        }
        if (this->tile != 0) {
            this->tile->objects.remove_node(this, 0);
            this->tile = 0;
        }
        if (this->inside_obj != 0) {
            this->inside_obj->objects->remove_node(this, 0);
            this->inside_obj = 0;
        }
        if (this->objects != 0) {
            RGE_Object_Node* node = this->objects->list;
            while (node != 0) {
                RGE_Object_Node* next = node->next;
                node->node->exit_obj();
                node = next;
            }
        }
        if (this->unitAIValue != 0) {
            delete this->unitAIValue;
            this->unitAIValue = 0;
        }
        if (this->master_obj != 0 && 0.0 < this->master_obj->radius_z) {
            this->removeFromObstructionMap(2);
        }
        this->master_obj = 0;
    } else {
        delete this;
    }
}
