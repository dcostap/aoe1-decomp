// 004C1290 RGE_Static_Object::~RGE_Static_Object
// PDB: stat_obj.cpp:192-327, 388 bytes
// __thiscall, void
// FLAGS: default + /GX (EH)
//
// Attempt log:
// - the initial flattened-array/root-dtor source matched the cleanup body but
//   lacked VC5's EH/member state and vtable context;
// - modeling the proven ManagedArray<int> members and using their natural
//   inline delete[] destructor restored the complete 388-byte EH-framed body;
// - correcting the owner addObject ABI to int sleep/dopple and the master
//   radius_z double comparison fixed the remaining call/FPU shape;
// - typed RGE_Player and inside-object ownership replaced raw offset casts
//   without changing bytes; exact 388-byte match, no asm or vptr store.

#include "../../include/stat_obj_context.h"

RGE_Static_Object::~RGE_Static_Object() {
    this->remove_visible_resource();

    if (this->owner != 0) {
        if (this->object_state < 3) {
            this->take_attribute_from_owner();
        }
        if (this->object_state < 7) {
            this->owner->victory_conditions->update_for_object(this);
        }
    }

    if (this->sprite_list != 0) {
        delete this->sprite_list;
        this->sprite_list = 0;
    }

    if (this->owner != 0) {
        if (this->selected & 1) {
            this->owner->unselect_one_object(this);
        }

        this->owner->removeObject(this, this->sleep_flag, this->dopple_flag,
                                  this->player_object_node);

        this->owner = 0;
    }

    if (this->tile != 0) {
        this->tile->objects.remove_node(this, 0);
        this->tile = 0;
    }

    if (this->master_obj != 0) {
        if (this->master_obj->radius_z > 0.0) {
            this->removeFromObstructionMap(2);
        }
    }

    if (this->inside_obj != 0) {
        this->inside_obj->objects->remove_node(this, 0);
        this->inside_obj = 0;
    }

    if (this->objects != 0) {
        RGE_Object_Node* node = this->objects->head;
        while (node != 0) {
            RGE_Object_Node* next = node->next;
            ((RGE_Static_Object*)node->object)->release_from_holder();
            node = next;
        }

        RGE_Object_List* list = this->objects;
        if (list != 0) {
            list->RGE_Object_List::~RGE_Object_List();
            operator_delete(list);
        }
    }

    if (this->unitAIValue != 0) {
        delete (UnitAIModule*)this->unitAIValue;
        this->unitAIValue = 0;
    }
}
