#pragma once
#include "../common.h"
#include "action.h"
#include "act_obj.h"
#include "task.h"
#include "stat_obj.h"

class RGE_Action_Attack : public RGE_Action       {
public:
    char _pad_0x4[0x3C];
    RGE_Sprite* move_sprite;                 // 0x40
    RGE_Sprite* fight_sprite;                // 0x44
    RGE_Sprite* wait_sprite;                 // 0x48
    float range;                             // 0x4C
    float min_range;                         // 0x50
    short missile_id;                        // 0x54
    short fire_missile_at_frame;             // 0x56
    uchar need_to_attack;                    // 0x58
    uchar was_same_owner;                    // 0x59
    uchar indirect_fire_flag;                // 0x5A

    RGE_Action_Attack(int param_1, RGE_Action_Object* param_2);
    RGE_Action_Attack(RGE_Action_Object* param_1, RGE_Static_Object* param_2, RGE_Sprite* param_3, RGE_Sprite* param_4, RGE_Sprite* param_5, float param_6, float param_7, short param_8, short param_9);
    RGE_Action_Attack(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, RGE_Sprite* param_5, RGE_Sprite* param_6, RGE_Sprite* param_7, float param_8, float param_9, short param_10, short param_11);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Action_Attack() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void create_action_list();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void rehook();

    // [Slot 05] Offset 0x14 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void type();

    // [Slot 07] Offset 0x1C (Override)
    virtual void first_in_stack(uchar param_1); // Ghidra: first_in_stack

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void inside_obj_update();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void idle_update();

    // [Slot 10] Offset 0x28 (Override)
    virtual uchar update(); // Ghidra: update

    // [Slot 11] Offset 0x2C (Override)
    virtual int stop(); // Ghidra: stop

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void move_to();

    // [Slot 13] Offset 0x34 (Override)
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // Ghidra: work

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void attack_response();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void relation_response();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void copy_obj();

    // [Slot 17] Offset 0x44 (Override)
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3); // Ghidra: copy_obj_sprites

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

    // [Slot 23] Offset 0x5C (Override)
    virtual void set_state(uchar param_1); // Ghidra: set_state

    // --- Non-Virtual Members ---
    int ready_to_attack(int* param_1);
    void do_attack();
};

static_assert(sizeof(RGE_Action_Attack) == 0x5C, "RGE_Action_Attack Size Mismatch");
static_assert(offsetof(RGE_Action_Attack, indirect_fire_flag) == 0x5A, "RGE_Action_Attack Offset Mismatch");

