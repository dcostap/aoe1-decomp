#pragma once
#include "../common.h"

class TRIBE_Action : public RGE_Action       {
public:
    char _pad_0x4[0x3C];

    TRIBE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
    TRIBE_Action(RGE_Action_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Action() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual int setup(RGE_Action_Object* param_1); // Ghidra: setup

    // [Slot 02] Offset 0x08 (Override)
    virtual int setup(int param_1, RGE_Action_Object* param_2); // Ghidra: setup

    // [Slot 03] Offset 0x0C (Override)
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1); // Ghidra: create_action_list

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void rehook();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void type();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void first_in_stack();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void inside_obj_update();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void idle_update();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void stop();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void move_to();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void work();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void attack_response();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void relation_response();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void copy_obj();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void copy_obj_sprites();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void get_state_name();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void get_target_obj();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void get_target_obj2();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void set_target_obj();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void set_target_obj2();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void set_state();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void displayBuildList();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void loadBuildList();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void numberBuiltOrInProgressItemsOfType();

};

static_assert(sizeof(TRIBE_Action) == 0x40, "TRIBE_Action Size Mismatch");

