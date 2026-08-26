// 00441BB0 RGE_Doppleganger_Object::recycle_in_to_game
// PDB: dpl_obj.cpp:166-235, 384 bytes
// __thiscall, void, ret 0x18
// FLAGS: default
//
// Attempt log:
// v0: initial — wrong register allocation (no ebp, edi used for param_6, 58.8% diff)
// v1: fixed prologue — avoid keeping param_6 in callee-saved reg; prologue matches (7.3% diff)
// v2: using void* mapAddr intermediate to force stores after ftol; 0.5% diff (2 bytes)
// v3-v9: various register/scheduling tweaks — stable 2-byte diff is register choice
//
// ACCEPTED_DRIFT: remaining 2 bytes = lea edx vs lea eax for MapAddress computation.
// Original: lea edx,[ecx+eax*4] / mov [esi+9Ch],edx
// Rebuilt:  lea eax,[ecx+eax*4] / mov [esi+9Ch],eax
// Benign register allocation difference — eax immediately overwritten by mov al,[edi+48h]
// in both versions. Rest of function (86 trailing bytes) is byte-identical,
// including all branch targets, epilogues, register saves/restores, and virtual calls.
// 382/384 bytes match (99.48%), no behavioral difference.

#ifndef DPL_OBJ_SHARED_CONTEXT
#include "../../include/dpl_obj_context.h"
#endif

void RGE_Doppleganger_Object::recycle_in_to_game(
    RGE_Master_Static_Object* param_1,
    RGE_Player* param_2,
    float param_3,
    float param_4,
    float param_5,
    RGE_Static_Object* param_6)
{
    // Zero all doppleganger-specific fields
    *(int*)((char*)this + 0x8C) = 0;  // doppled_object
    *(int*)((char*)this + 0x90) = 0;  // draw_color
    *(int*)((char*)this + 0x94) = 0;  // doppled_master_obj
    *(int*)((char*)this + 0x98) = 0;  // doppled_player
    *(int*)((char*)this + 0x9C) = 0;  // MapAddress
    *(int*)((char*)this + 0xA0) = 0;  // LastMapValue
    *(int*)((char*)this + 0xA4) = 0;  // CantSeeBits
    *(unsigned char*)((char*)this + 0xA8) = 0;  // map_draw_level
    *(unsigned char*)((char*)this + 0xA9) = 0;  // map_color
    *(int*)((char*)this + 0xAC) = -1;  // doppledObjectID

    // Call base class version (passes first 5 params)
    RGE_Animated_Object::recycle_in_to_game(param_1, param_2, param_3, param_4, param_5);

    // Set type to doppleganger (0x19 = 25)
    *(unsigned char*)((char*)this + 0x4E) = 0x19;

    // Store doppled_object
    *(int*)((char*)this + 0x8C) = (int)param_6;

    if (param_6 != 0) {
        // Copy fields from source object directly
        *(int*)((char*)this + 0x94) = *(int*)((char*)param_6 + 0x08);  // doppled_master_obj = param_6->master_obj
        *(int*)((char*)this + 0x98) = (signed short)*(short*)((char*)*(int*)((char*)param_6 + 0x0C) + 0x4A);  // doppled_player = owner->id
        *(int*)((char*)this + 0xAC) = *(int*)((char*)param_6 + 0x04);  // doppledObjectID = param_6->id

        // Copy sprite
        *(int*)((char*)this + 0x10) = *(int*)((char*)param_6 + 0x10);  // this->sprite = param_6->sprite

        // Copy sprite list
        RGE_Active_Sprite_Node* newNode = ((RGE_Active_Sprite_List*)*(int*)((char*)param_6 + 0x18))->copy_sprite_list();
        ((RGE_Active_Sprite_List*)*(int*)((char*)this + 0x18))->use_sprite_list(newNode);

        // Reload doppled_object pointer (now stored in field)
        void* obj = *(void**)((char*)this + 0x8C);

        // Copy facet
        *(unsigned char*)((char*)this + 0x35) = *(unsigned char*)((char*)obj + 0x35);

        // draw_color = owner->color_table
        *(int*)((char*)this + 0x90) = *(int*)((char*)*(int*)((char*)obj + 0x0C) + 0x108);

        // map_draw_level and map_color
        unsigned char ml = *(unsigned char*)((char*)*(int*)((char*)obj + 0x08) + 0x8E);
        *(unsigned char*)((char*)this + 0xA8) = ml;

        if (ml == 3) {
            *(unsigned char*)((char*)this + 0xA9) = *(unsigned char*)((char*)*(int*)((char*)obj + 0x08) + 0x90);
        } else {
            *(unsigned char*)((char*)this + 0xA9) = *(unsigned char*)((char*)*(int*)((char*)*(int*)((char*)obj + 0x0C) + 0x108) + 0x25);
        }

        // Map address calculation (ftol order: y first, then x)
        int row = (int)(long)param_4;  // ftol(y) -> ebp
        int col = (int)(long)param_3;  // ftol(x) -> eax
        void* mapAddr = (void*)((unsigned long*)unified_map_offsets[row] + col);

        *(int*)((char*)this + 0xA0) = 0;  // LastMapValue = 0
        *(int*)((char*)this + 0xA4) = 0;  // CantSeeBits = 0
        *(int*)((char*)this + 0x9C) = (int)mapAddr;  // MapAddress

        // Check object_state
        if (*(unsigned char*)((char*)obj + 0x48) >= 7) {
            *(int*)((char*)this + 0x8C) = 0;  // doppled_object = NULL
            *(int*)((char*)this + 0xAC) = -1;  // doppledObjectID = -1
            this->validate();
            return;
        }
    } else {
        // param_6 == NULL path
        *(int*)((char*)this + 0xAC) = -1;  // doppledObjectID = -1
        *(int*)((char*)this + 0x94) = 0;   // doppled_master_obj = NULL
        *(int*)((char*)this + 0x98) = 0;   // doppled_player = 0
        this->destroy_obj();
    }

    // Shared tail: call validate
    this->validate();
}
