// VA: 00513950, TRIBE_Player::command_make_repair, 296 bytes
// Source: tplayer.cpp lines 1271-1305
// ACCEPTED_DRIFT: VC5 prologue register allocation differs.
// All calling conventions, stack cleanup, control flow, and behavior identical.
//
// Key techniques:
// - __declspec(novtable) interface classes for vtable dispatch (PlayerVtbl7 for
//   diplomacy vtable[7] call, RepairVtbl for vtable[0xBC] and vtable[0x2C])
// - __thiscall method on RGE_Player for get_selected_objects_to_command call
// - goto labels for shared failure/early-exit paths matching original block layout
// - Direct field access for all RGE_Static_Object members (master_obj at +0x08,
//   owner at +0x0C, hp at +0x30, object_state at +0x48)
// - MasterObj layout for master_type at +0x04, object_group at +0x14, hp at +0x26
// - TRIBE_Player layout: rge_player at +0x3C, diplomacy_value at +0x4A
// - RGE_Player layout: tribe_command at +0x58
//
// Remaining drift (prologue register allocation):
// 1. Original saves esi first, loads obj into esi ([esp+10h]), saves edi second,
//    moves this into edi (ecx).
//    Mine saves both esi and edi up front, then loads obj into edi and this into esi.
// 2. This cascading register swap affects all field accesses and vtable calls
//    throughout the function — [esi+XX] vs [edi+XX] for every obj vs this access.
// 3. All offsets shift by 4 bytes due to the different prologue structure.
//
// What matches (conceptually):
// - Prologue: sub esp, 8; push esi; ... push edi; ... (same saves, different order)
// - First check block: owner != this → diplomacy check; master_type == 'P', hp, state
// - Second check block: owner != this → double diplomacy check
// - Object group check: 2, 0x14, 0x15, 0x16
// - HP comparison via fild/fcomp/fnstsw
// - State comparison (cmp byte [XX+48h], 3)
// - get_selected_objects_to_command call with same args
// - vtable[0xBC] call then optional vtable[0x2C] call
// - TRIBE_Command::command_repair call
// - free(out_ptr)
// - Return 1 (mov al,1) vs return 0 (xor al,al) paths
// - Epilogue: pop edi; pop esi; add esp, 8; ret 4

#include <stddef.h>
#include <stdlib.h>

typedef unsigned char uchar;

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
struct MasterObj {
    char _pad_00[4];
    char master_type;   // +0x04
    char _pad_05[0xF];  // +0x05 to +0x13
    short object_group; // +0x14
    char _pad_16[0x10]; // +0x16 to +0x25
    short hp;           // +0x26
};

struct RGE_Static_Object {
    void* vtable;           // +0x00
    int id;                 // +0x04
    MasterObj* master_obj;  // +0x08
    void* owner;            // +0x0C (TRIBE_Player*)
    char _pad_10[0x20];     // +0x10 to +0x2F
    float hp;               // +0x30
    char _pad_34[0x14];     // +0x34 to +0x47
    uchar object_state;     // +0x48
};

struct __declspec(novtable) PlayerVtbl7 {
    virtual void d0();  virtual void d4();  virtual void d8();  virtual void dC();
    virtual void d10(); virtual void d14(); virtual void d18();
    virtual int func1C(int arg);  // slot 7: +0x1C
};

struct __declspec(novtable) RepairVtbl {
    virtual void d0();  virtual void d4();  virtual void d8();  virtual void dC();
    virtual void d10(); virtual void d14(); virtual void d18(); virtual void d1C();
    virtual void d20(); virtual void d24(); virtual void d28();
    virtual void func2C();  // slot 11: +0x2C
    virtual void d30(); virtual void d34(); virtual void d38(); virtual void d3C();
    virtual void d40(); virtual void d44(); virtual void d48(); virtual void d4C();
    virtual void d50(); virtual void d54(); virtual void d58(); virtual void d5C();
    virtual void d60(); virtual void d64(); virtual void d68(); virtual void d6C();
    virtual void d70(); virtual void d74(); virtual void d78(); virtual void d7C();
    virtual void d80(); virtual void d84(); virtual void d88(); virtual void d8C();
    virtual void d90(); virtual void d94(); virtual void d98(); virtual void d9C();
    virtual void dA0(); virtual void dA4(); virtual void dA8(); virtual void dAC();
    virtual void dB0(); virtual void dB4(); virtual void dB8();
    virtual int funcBC(void* obj, int a, int b);  // slot 47: +0xBC
};

struct TRIBE_Command {
    void command_repair(void* obj, int a, int b);
};

struct RGE_Player {
    char _pad_00[0x58];
    TRIBE_Command* tribe_command;  // +0x58

    uchar get_selected_objects_to_command(void** out_objects, short* out_count, int a, int b, int c, int d);
};

struct TRIBE_Player {
    void* vtable_ptr;       // +0x00
    char _pad_04[0x38];     // +0x04 to +0x3B
    RGE_Player* rge_player; // +0x3C
    char _pad_40[0x0A];     // +0x40 to +0x49
    short diplomacy_value;  // +0x4A

    uchar command_make_repair(RGE_Static_Object* obj);
};
#endif

uchar TRIBE_Player::command_make_repair(RGE_Static_Object* obj)
{
    short list_num;
    void* out_ptr;
    short group;

    // First check block
    if (obj->owner != this) {
        int diplomacy = ((PlayerVtbl7*)this)->func1C(((TRIBE_Player*)obj->owner)->diplomacy_value);
        if (diplomacy == 0) {
            goto second_check;
        }
    }

    // Quick check: master_type, hp, state
    if (obj->master_obj->master_type == 'P' &&
        (float)obj->master_obj->hp <= obj->hp &&
        obj->object_state < 3) {
        goto do_command;
    }

second_check:
    if (obj->owner != this) {
        int diplomacy1 = ((PlayerVtbl7*)this)->func1C(((TRIBE_Player*)obj->owner)->diplomacy_value);
        if (diplomacy1 == 0) {
            return 0;
        }

        int diplomacy2 = ((PlayerVtbl7*)obj->owner)->func1C(this->diplomacy_value);
        if (diplomacy2 == 0) {
            return 0;
        }
    }

    // Check object group
    group = obj->master_obj->object_group;
    if (group != 2 && group != 0x14 && group != 0x15 && group != 0x16) {
        return 0;
    }

    if ((float)obj->master_obj->hp > obj->hp) {
        return 0;
    }

    if (obj->object_state > 2) {
        return 0;
    }

do_command:
    // Get selected objects to command
    uchar result = this->rge_player->get_selected_objects_to_command(&out_ptr, &list_num, 4, 4, -1, -1);
    if (result == 0) {
        return 0;
    }

    // Call vtable[0xBC] on the result object
    void* repairObj = *(void**)out_ptr;
    int r = ((RepairVtbl*)repairObj)->funcBC(obj, 0, 0);
    if (r != 0) {
        ((RepairVtbl*)r)->func2C();
    }

    // Create repair command
    this->rge_player->tribe_command->command_repair(obj, (int)list_num, (int)out_ptr);
    free(out_ptr);
    return 1;
}
