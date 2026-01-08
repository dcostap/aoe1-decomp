#pragma once
#include "../common.h"

class TRIBE_Action_List : public RGE_Action_List       {
public:
    char _pad_0x4[0x8];

    TRIBE_Action_List(RGE_Action_Object* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual RGE_Action* create_action(int param_1, short param_2); // Ghidra: create_action

    // [Slot 01] Offset 0x04 (Override)
    virtual RGE_Action* create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5); // Ghidra: create_task_action

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void inside_obj_update();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 04] Offset 0x10 (Override)
    virtual void get_action_name(char* param_1); // Ghidra: get_action_name

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void copy_obj();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void copy_obj_sprites();

};

static_assert(sizeof(TRIBE_Action_List) == 0xC, "TRIBE_Action_List Size Mismatch");

