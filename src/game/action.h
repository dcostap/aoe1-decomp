#pragma once
#include "../common.h"
#include "act_obj.h"
#include "task.h"
#include "stat_obj.h"
#include "act_list.h"

// =========================================================
// FORWARD DECLARATIONS
// Required to break circular include dependencies.
// =========================================================
class RGE_Action;
class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;
class RGE_Action_List;
class RGE_Sprite;
class RGE_Master_Action_Object;

// ----------------------------------------------------------------
// RGE_Action_Node
// Size: 0x8
struct RGE_Action_Node {
    RGE_Action * action; // 0x0
    RGE_Action_Node * next; // 0x4
};

class RGE_Action       {
public:
    short action_type;                       // 0x4
    RGE_Action_Object* obj;                  // 0x8
    uchar state;                             // 0xC
    RGE_Static_Object* target_obj;           // 0x10
    RGE_Static_Object* target_obj2;          // 0x14
    int targetID;                            // 0x18
    int target2ID;                           // 0x1C
    float target_x;                          // 0x20
    float target_y;                          // 0x24
    float target_z;                          // 0x28
    float timer;                             // 0x2C
    RGE_Task* task;                          // 0x30
    RGE_Action_List* sub_actions;            // 0x34
    RGE_Sprite* sprite;                      // 0x38
    uchar subActionValue;                    // 0x3C

    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
    RGE_Action(RGE_Action_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Action() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual int setup(RGE_Action_Object* param_1); // Ghidra: setup

    // [Slot 02] Offset 0x08 (Override)
    virtual int setup(int param_1, RGE_Action_Object* param_2); // Ghidra: setup

    // [Slot 03] Offset 0x0C (Override)
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1); // Ghidra: create_action_list

    // [Slot 04] Offset 0x10 (Override)
    virtual void rehook(); // Ghidra: rehook

    // [Slot 05] Offset 0x14 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 06] Offset 0x18 (Override)
    virtual short type(); // Ghidra: type

    // [Slot 07] Offset 0x1C (Override)
    virtual void first_in_stack(uchar param_1); // Ghidra: first_in_stack

    // [Slot 08] Offset 0x20 (Override)
    virtual uchar inside_obj_update(); // Ghidra: inside_obj_update

    // [Slot 09] Offset 0x24 (Override)
    virtual uchar idle_update(); // Ghidra: idle_update

    // [Slot 10] Offset 0x28 (Override)
    virtual uchar update(); // Ghidra: update

    // [Slot 11] Offset 0x2C (Override)
    virtual int stop(); // Ghidra: stop

    // [Slot 12] Offset 0x30 (Override)
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // Ghidra: move_to

    // [Slot 13] Offset 0x34 (Override)
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // Ghidra: work

    // [Slot 14] Offset 0x38 (Override)
    virtual uchar attack_response(RGE_Static_Object* param_1); // Ghidra: attack_response

    // [Slot 15] Offset 0x3C (Override)
    virtual uchar relation_response(long param_1, uchar param_2); // Ghidra: relation_response

    // [Slot 16] Offset 0x40 (Override)
    virtual void copy_obj(RGE_Master_Action_Object* param_1); // Ghidra: copy_obj

    // [Slot 17] Offset 0x44 (Override)
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3); // Ghidra: copy_obj_sprites

    // [Slot 18] Offset 0x48 (Override)
    virtual void get_state_name(char* param_1); // Ghidra: get_state_name

    // [Slot 19] Offset 0x4C (Override)
    virtual RGE_Static_Object* get_target_obj(); // Ghidra: get_target_obj

    // [Slot 20] Offset 0x50 (Override)
    virtual RGE_Static_Object* get_target_obj2(); // Ghidra: get_target_obj2

    // [Slot 21] Offset 0x54 (Override)
    virtual void set_target_obj(RGE_Static_Object* param_1); // Ghidra: set_target_obj

    // [Slot 22] Offset 0x58 (Override)
    virtual void set_target_obj2(RGE_Static_Object* param_1); // Ghidra: set_target_obj2

    // [Slot 23] Offset 0x5C (Override)
    virtual void set_state(uchar param_1); // Ghidra: set_state

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void displayBuildList();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void loadBuildList();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void numberBuiltOrInProgressItemsOfType();

    // --- Non-Virtual Members ---
    float targetX();
    float targetY();
    float targetZ();
    uchar subAction();
    void setSubAction(uchar param_1);
};

static_assert(sizeof(RGE_Action) == 0x40, "RGE_Action Size Mismatch");
static_assert(offsetof(RGE_Action, subActionValue) == 0x3C, "RGE_Action Offset Mismatch");

RGE_Static_Object* RGE_Action::get_target_obj() {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall get_target_obj(RGE_Action * this)
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?get_target_obj@RGE_Action@@UAEPAVRGE_Static_Object@@XZ      XREF[22]:    0056e0a4(*), 0056e124(*),
//                               RGE_Action::get_target_obj                                                0056e18c(*), 0056e1fc(*),
//                                                                                                         0056e264(*), 0056e304(*),
//                                                                                                         0056e36c(*), 0056e3ec(*),
//                                                                                                         0056e69c(*), 0056e71c(*),
//                                                                                                         00574ef4(*), 00574f64(*),
//                                                                                                         00574fdc(*), 0057505c(*),
//                                                                                                         005750cc(*), 0057513c(*),
//                                                                                                         005751f4(*), 00575254(*),
//                                                                                                         005752cc(*), 00575334(*), [more]
//                              action.h:85 (4)
//         00401130     MOV        EAX,dword ptr [ECX + this->target_obj]
//         00401133     RET
//         00401134     ??         90h
//         00401135     NOP
//         00401136     NOP
//         00401137     NOP
//         00401138     NOP
//         00401139     NOP
//         0040113a     NOP
//         0040113b     NOP
//         0040113c     NOP
//         0040113d     NOP
//         0040113e     NOP
//         0040113f     NOP
    return 0;
}

RGE_Static_Object* RGE_Action::get_target_obj2() {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall get_target_obj2(RGE_Action * this)
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?get_target_obj2@RGE_Action@@UAEPAVRGE_Static_Object@@XZ     XREF[22]:    0056e0a8(*), 0056e128(*),
//                               RGE_Action::get_target_obj2                                               0056e190(*), 0056e200(*),
//                                                                                                         0056e268(*), 0056e308(*),
//                                                                                                         0056e370(*), 0056e3f0(*),
//                                                                                                         0056e6a0(*), 0056e720(*),
//                                                                                                         00574ef8(*), 00574f68(*),
//                                                                                                         00574fe0(*), 00575060(*),
//                                                                                                         005750d0(*), 00575140(*),
//                                                                                                         005751f8(*), 00575258(*),
//                                                                                                         005752d0(*), 00575338(*), [more]
//                              action.h:86 (4)
//         00401140     MOV        EAX,dword ptr [ECX + this->target_obj2]
//         00401143     RET
//         00401144     ??         90h
//         00401145     NOP
//         00401146     NOP
//         00401147     NOP
//         00401148     NOP
//         00401149     NOP
//         0040114a     NOP
//         0040114b     NOP
//         0040114c     NOP
//         0040114d     NOP
//         0040114e     NOP
//         0040114f     NOP
    return 0;
}

