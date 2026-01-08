#pragma once
#include "../common.h"

class RGE_Task_List       {
public:
    RGE_Task** list;                         // 0x4
    short list_num;                          // 0x8

    RGE_Task_List();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual RGE_Task* create_task(short param_1, short param_2); // Ghidra: create_task

    // [Slot 01] Offset 0x04 (Override)
    virtual RGE_Task* get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5); // Ghidra: get_target_task

    // [Slot 02] Offset 0x08 (Override)
    virtual int is_attack_task(RGE_Task* param_1); // Ghidra: is_attack_task

    // [Slot 03] Offset 0x0C (Override)
    virtual int check_task(RGE_Task* param_1, RGE_Action_Object* param_2, RGE_Static_Object* param_3); // Ghidra: check_task

    // --- Non-Virtual Destructor ---
    ~RGE_Task_List() noexcept(false);
    // --- Non-Virtual Members ---
    void copy(RGE_Task_List* param_1);
    void load(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    void load(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    void save(int param_1);
    void delete_list();
};

static_assert(sizeof(RGE_Task_List) == 0xC, "RGE_Task_List Size Mismatch");
static_assert(offsetof(RGE_Task_List, list_num) == 0x8, "RGE_Task_List Offset Mismatch");

