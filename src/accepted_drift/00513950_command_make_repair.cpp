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
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual void make_new_obj(void*, float, float, float);
    virtual void make_new_master();
    virtual void check_placement();
    virtual void alignment();
    virtual long calc_base_damage_ability(void*);
    virtual void play_command_sound();
    char master_type;
    char _pad_05[0xF];
    short object_group;
    char _pad_16[0x10];
    short hp;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(); virtual void recycle_out_of_game();
    virtual void draw(); virtual void shadow_draw(); virtual void normal_draw();
    virtual void draw_front_frame(); virtual void draw_back_frame(); virtual void draw_frame();
    virtual void update(); virtual void check_damage_sprites(); virtual void rehook();
    virtual void save(int); virtual void teleport(); virtual void new_sprite();
    virtual void add_overlay_sprite(); virtual void remove_overlay_sprite();
    virtual void change_ownership(); virtual void modify(); virtual void modify_delta();
    virtual void modify_percent(); virtual void transform(); virtual void copy_obj();
    virtual void set_object_state(); virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying(); virtual void destroy_obj();
    virtual void die_die_die(); virtual void damage(); virtual void calculateDamage();
    virtual void rotate(); virtual void can_attack(); virtual void set_attribute();
    virtual void set_attribute_amount();
    virtual void heal(); virtual void heal(float);
    virtual void canRepair();
    virtual void notify_of_relation(); virtual void do_command(); virtual void move_to();
    virtual void work(); virtual void stop(); virtual void set_attack();
    virtual void play_command_sound(); virtual void play_move_sound(); virtual void new_angle();
    virtual void spawn_death_obj(); virtual RGE_Master_Static_Object* get_command_master(void*, float, float, float);
    virtual void set_being_worked_on(); virtual void release_being_worked_on(); virtual void is_moving();
    virtual void get_target_obj(); virtual void enter_obj(); virtual void exit_obj();
    virtual void explore_terrain(); virtual void unexplore_terrain();
    int id;                 // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    void* owner;            // +0x0C (TRIBE_Player*)
    char _pad_10[0x20];     // +0x10 to +0x2F
    float hp;               // +0x30
    char _pad_34[0x14];     // +0x34 to +0x47
    uchar object_state;     // +0x48
};

struct TRIBE_Command {
    void command_repair(void* obj, int a, int b);
};

struct RGE_Player {
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    char _pad_00[0x58];
    TRIBE_Command* tribe_command;  // +0x58

    uchar get_selected_objects_to_command(void** out_objects, short* out_count, int a, int b, int c, int d);
};

struct TRIBE_Player {
    virtual ~TRIBE_Player();
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
        int diplomacy = ((RGE_Player*)this)->isAlly(((TRIBE_Player*)obj->owner)->diplomacy_value);
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
        int diplomacy1 = ((RGE_Player*)this)->isAlly(((TRIBE_Player*)obj->owner)->diplomacy_value);
        if (diplomacy1 == 0) {
            return 0;
        }

        int diplomacy2 = ((RGE_Player*)obj->owner)->isAlly(this->diplomacy_value);
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
    RGE_Static_Object* repairObj = *(RGE_Static_Object**)out_ptr;
    RGE_Master_Static_Object* r = repairObj->get_command_master(obj, 0.0f, 0.0f, 0.0f);
    if (r != 0) {
        r->play_command_sound();
    }

    // Create repair command
    this->rge_player->tribe_command->command_repair(obj, (int)list_num, (int)out_ptr);
    free(out_ptr);
    return 1;
}
