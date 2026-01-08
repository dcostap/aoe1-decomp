#pragma once
#include "../common.h"
#include "action.h"
#include "act_obj.h"
#include "task.h"
#include "stat_obj.h"

class RGE_Action_List       {
public:
    RGE_Action_Object* obj;                  // 0x4
    RGE_Action_Node* list;                   // 0x8

    RGE_Action_List(RGE_Action_Object* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual RGE_Action* create_action(int param_1, short param_2); // Ghidra: create_action

    // [Slot 01] Offset 0x04 (Override)
    virtual RGE_Action* create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5); // Ghidra: create_task_action

    // [Slot 02] Offset 0x08 (Override)
    virtual uchar inside_obj_update(); // Ghidra: inside_obj_update

    // [Slot 03] Offset 0x0C (Override)
    virtual uchar update(); // Ghidra: update

    // [Slot 04] Offset 0x10 (Override)
    virtual void get_action_name(char* param_1); // Ghidra: get_action_name

    // [Slot 05] Offset 0x14 (Override)
    virtual void copy_obj(RGE_Master_Action_Object* param_1); // Ghidra: copy_obj

    // [Slot 06] Offset 0x18 (Override)
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3); // Ghidra: copy_obj_sprites

    // --- Non-Virtual Destructor ---
    ~RGE_Action_List() noexcept(false);
    // --- Non-Virtual Members ---
    void load(int param_1);
    void rehook();
    void save(int param_1);
    void delete_list();
    void add_action(RGE_Action* param_1);
    void add_action_at_end(RGE_Action* param_1);
    void add_action_at_end_of_action_queue(RGE_Action* param_1);
    void remove_action();
    uchar have_action();
    int action_stop();
    int action_move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    int action_work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    int attack_response(RGE_Static_Object* param_1);
    int relation_response(long param_1, uchar param_2);
    RGE_Action* get_action();
    RGE_Task* get_task();
};

static_assert(sizeof(RGE_Action_List) == 0xC, "RGE_Action_List Size Mismatch");
static_assert(offsetof(RGE_Action_List, list) == 0x8, "RGE_Action_List Offset Mismatch");

