#pragma once
#include "../common.h"
#include "task_lst.h"
#include "m_mo_obj.h"

class RGE_Master_Action_Object : public RGE_Master_Moving_Object       {
public:
    char _pad_0x4[0xD4];
    RGE_Task_List* tasks;                    // 0xD8
    short default_task;                      // 0xDC
    float search_radius;                     // 0xE0
    float work_rate;                         // 0xE4
    short drop_site;                         // 0xE8
    short backup_drop_site;                  // 0xEA
    uchar task_by_group;                     // 0xEC
    RGE_Sound* command_sound;                // 0xF0
    RGE_Sound* move_sound;                   // 0xF4
    uchar run_pattern;                       // 0xF8

    RGE_Master_Action_Object(RGE_Master_Action_Object* param_1, int param_2);
    RGE_Master_Action_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    RGE_Master_Action_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Master_Action_Object() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // Ghidra: copy_obj

    // [Slot 02] Offset 0x08 (Override)
    virtual void modify(float param_1, uchar param_2); // Ghidra: modify

    // [Slot 03] Offset 0x0C (Override)
    virtual void modify_delta(float param_1, uchar param_2); // Ghidra: modify_delta

    // [Slot 04] Offset 0x10 (Override)
    virtual void modify_percent(float param_1, uchar param_2); // Ghidra: modify_percent

    // [Slot 05] Offset 0x14 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 06] Offset 0x18 (Override)
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4); // Ghidra: make_new_obj

    // [Slot 07] Offset 0x1C (Override)
    virtual RGE_Master_Static_Object* make_new_master(); // Ghidra: make_new_master

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void check_placement();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void alignment();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void calc_base_damage_ability();

    // [Slot 11] Offset 0x2C (Override)
    virtual void play_command_sound(); // Ghidra: play_command_sound

    // [Slot 12] Offset 0x30 (Override)
    virtual void play_move_sound(); // Ghidra: play_move_sound

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 14] Offset 0x38 (Override)
    virtual RGE_Task_List* create_task_list(); // Ghidra: create_task_list

    // --- Non-Virtual Members ---
    int setup(RGE_Master_Action_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
    RGE_Task* get_task(short param_1);
    RGE_Task* getTaskByTaskID(int param_1);
};

static_assert(sizeof(RGE_Master_Action_Object) == 0xFC, "RGE_Master_Action_Object Size Mismatch");
static_assert(offsetof(RGE_Master_Action_Object, run_pattern) == 0xF8, "RGE_Master_Action_Object Offset Mismatch");

