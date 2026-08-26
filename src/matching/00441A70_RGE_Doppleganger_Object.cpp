// VA: 00441A70, RGE_Doppleganger_Object::RGE_Doppleganger_Object, 318 bytes
// Source: dpl_obj.cpp lines 121-162
// FLAGS: /GX (SEH frame for constructor)
//
// Constructor with SEH frame:
// - push -1 / push handler / push fs:0 / mov [fs:0],esp (SEH prologue)
// - call RGE_Animated_Object(this, param_1, world, 0)
// - Install the derived vtable through the natural polymorphic class surface
// - Initialize all fields to 0/null
// - Conditional setup(param_1, world) call
// - rge_read sequence for save file loading
// - Conditional CantSeeBits read based on save_game_version >= 7.06
//
// Fields (base class = RGE_Static_Object + RGE_Animated_Object = 0x8C bytes):
//   +0x00 derived vtable
//   +0x8C doppled_object
//   +0x90 draw_color
//   +0x94 doppled_master_obj
//   +0x98 doppled_player
//   +0x9C MapAddress
//   +0xA0 LastMapValue
//   +0xA4 CantSeeBits
//   +0xA8 map_draw_level
//   +0xA9 map_color
//   +0xAC doppledObjectID (-1)
//
// === Attempt log ===
// - Initial /GX reconstruction had the right calls and fields but reloaded the
//   file argument and missed the original output-home/register topology.
// - Naming the input `handle` and reusing one ordinary `value` local for the two
//   deserialized object IDs preserved the input in EDI and the parameter-home
//   reuse seen by VC5. The reset of doppledObjectID after the first read is part
//   of the original load behavior, not just initialization.
// - A natural polymorphic base/derived declaration emits the derived vtable;
//   no manual table store is retained. The /GX candidate matches all 318 bytes.

#ifndef DPL_OBJ_SHARED_CONTEXT
#include "../../include/dpl_obj_context.h"
#endif

RGE_Doppleganger_Object::RGE_Doppleganger_Object(int handle, RGE_Game_World* world, int param_3)
    : RGE_Animated_Object(handle, world, 0)
{
    int value;

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

    if (param_3 != 0) {
        this->setup(handle, world);
    }

    rge_read(handle, &value, 4);
    this->doppled_object = (RGE_Static_Object*)(size_t)value;
    this->doppledObjectID = -1;
    rge_read(handle, &this->map_draw_level, 1);
    rge_read(handle, &this->map_color, 4);
    rge_read(handle, &value, 4);
    this->doppled_master_obj = (RGE_Master_Static_Object*)(size_t)value;
    rge_read(handle, &this->doppled_player, 4);

    if (save_game_version >= 7.06f) {
        rge_read(handle, &this->CantSeeBits, 4);
    }
}
