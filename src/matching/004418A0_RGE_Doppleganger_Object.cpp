// VA: 004418A0 RGE_Doppleganger_Object::RGE_Doppleganger_Object
// Source: dpl_obj.cpp lines 52-115
// Attempt log:
// - The initial reconstruction had the right constructor/branch topology but
//   used an untyped child sprite pointer and an incorrect extra copy-list call.
// - Restoring the period typed ownership (`id`, `sprite`, and `sprite_list`) and
//   the base `destroy_obj` call fixed the direct-call surface. Spelling the guard
//   and subsequent child accesses through `this->doppled_object` preserves the
//   member reload after the sprite-list calls and matches all 410 bytes.
// - The derived vtable is emitted by the natural polymorphic declaration; no
//   manual table store is retained.
// FLAGS: config/flags/004418A0_RGE_Doppleganger_Object.rsp

#ifndef DPL_OBJ_SHARED_CONTEXT
#include "../../include/dpl_obj_context.h"
#endif

RGE_Doppleganger_Object::RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object* master, RGE_Player* player, float x, float y, float z, int doSetup, RGE_Static_Object* doppled)
    : RGE_Animated_Object(master, player, x, y, z, 0)
{
    this->doppled_object = 0;
    this->draw_color = 0;
    this->doppled_master_obj = 0;
    this->doppled_player = 0;
    this->MapAddress = 0;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    this->map_draw_level = 0;
    this->map_color = 0;
    this->doppledObjectID = -1;

    if (doSetup != 0) {
        this->setup(master, player, x, y, z);
    }

    this->doppled_object = doppled;
    if (this->doppled_object != 0) {
        this->doppled_master_obj = this->doppled_object->master_obj;
        this->doppled_player = this->doppled_object->owner->id;
        this->doppledObjectID = this->doppled_object->id;
        this->sprite = this->doppled_object->sprite;
        this->sprite_list->use_sprite_list(this->doppled_object->sprite_list->copy_sprite_list());
        this->facet = this->doppled_object->facet;
        this->draw_color = this->doppled_object->owner->color_table;
        this->map_draw_level = this->doppled_object->master_obj->map_draw_level;
        if (this->map_draw_level == 3) {
            this->map_color = this->doppled_object->master_obj->map_color;
        } else {
            this->map_color = this->doppled_object->owner->color_table->map_color;
        }
        if (this->doppled_object->object_state >= 7) {
            this->doppled_object = 0;
            this->doppledObjectID = -1;
        }
    } else {
        this->doppledObjectID = -1;
        this->doppled_master_obj = 0;
        this->doppled_player = 0;
        this->destroy_obj();
    }
    this->validate();
}
