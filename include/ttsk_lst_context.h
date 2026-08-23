#ifndef AOE1_TTSK_LST_CONTEXT_H
#define AOE1_TTSK_LST_CONTEXT_H

// Authentic source-module context for C:\\msdev\\work\\age1_x1\\ttsk_lst.cpp.
//
// The declarations below keep the canonical task-list and game-object owners
// used by the reviewed task-list bodies.  They are not replacement objects or
// helper wrappers.  In particular, RGE_Task_List::list is the one pointer at
// +0x04 and list_num is the one short at +0x08.

#include "game_globals.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Task_List;

class RGE_Task {
public:
    short task_type;                    // +0x00
    short id;                           // +0x02
    unsigned char is_default;           // +0x04
    unsigned char pad_05;               // +0x05
    short action_type;                  // +0x06
    short object_group;                 // +0x08
    short object_id;                    // +0x0A
    unsigned char combat_level;         // +0x0C
    unsigned char combat_level_flag;    // +0x0D
    short terrain_id;                   // +0x0E
    unsigned char owner_type;           // +0x10
    unsigned char holding_attr;         // +0x11
    unsigned char state_building;       // +0x12
    unsigned char pad_13;               // +0x13
    short attribute_type;               // +0x14
    short attribute_type2;              // +0x16
    short attribute_type3;              // +0x18
    short attribute_type4;              // +0x1A
    float work_val1;                    // +0x1C
    float work_val2;                    // +0x20
    float work_range;                   // +0x24
    unsigned char search_flag;          // +0x28
    unsigned char pad_29[3];            // +0x29
    float search_wait_time;             // +0x2C
    short work_flag;                    // +0x30
    short work_flag2;                   // +0x32
    RGE_Sprite* move_sprite;            // +0x34
    RGE_Sprite* work_sprite;            // +0x38
    RGE_Sprite* work_sprite2;           // +0x3C
    RGE_Sprite* carry_sprite;           // +0x40
    RGE_Sound* work_sound;              // +0x44
    RGE_Sound* work_sound2;             // +0x48
};

typedef char ttsk_lst_task_size_check[(sizeof(RGE_Task) == 0x4C) ? 1 : -1];

class RGE_Task_List {
public:
    RGE_Task_List();
    virtual ~RGE_Task_List();

    void copy(RGE_Task_List*);
    void load(int, RGE_Sprite**, RGE_Sound**);
    void load(FILE*, RGE_Sprite**, RGE_Sound**);
    void save(int);
    void delete_list();

    virtual RGE_Task* create_task(short, short);                       // vt[0]
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float, float, float); // vt[1]
    virtual int is_attack_task(RGE_Task*);                              // vt[2]
    virtual int check_task(RGE_Task*, RGE_Action_Object*, RGE_Static_Object*); // vt[3]

    RGE_Task** list;                    // +0x04; shared list alias
    short list_num;                     // +0x08
};

typedef char ttsk_lst_task_list_size_check[(sizeof(RGE_Task_List) == 0x0C) ? 1 : -1];

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;                            // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                   // +0x0C
    char pad_10[0x20];                   // +0x10..+0x2F
    float hp;                            // +0x30
    char pad_34[0x10];                   // +0x34..+0x43
    float attribute_amount_held;         // +0x44
    unsigned char object_state;          // +0x48
    unsigned char pad_49[3];             // +0x49..+0x4B
    short attribute_type_held;           // +0x4C
};

typedef char ttsk_lst_static_prefix_check[
    (sizeof(RGE_Static_Object) == 0x50) ? 1 : -1];

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    unsigned char master_type;           // +0x04
    char pad_05[3];                      // +0x05..+0x07
    char* name;                          // +0x08
    short string_id;                     // +0x0C
    short string_id2;                    // +0x0E
    short id;                            // +0x10
    short copy_id;                       // +0x12
    short object_group;                  // +0x14
    char pad_16[0x10];                   // +0x16..+0x25
    short hp;                            // +0x26
    char pad_28[0x67];                   // +0x28..+0x8E
    unsigned char unit_level;            // +0x8F
};

typedef char ttsk_lst_master_prefix_check[
    (sizeof(RGE_Master_Static_Object) == 0x90) ? 1 : -1];

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(long);
    virtual int isAlly(long);             // vt[7], +0x1C; call anchor surface

    char pad_04[0x46];                    // +0x04..+0x49
    short id;                             // +0x4A
};

typedef char ttsk_lst_player_prefix_check[
    (sizeof(RGE_Player) == 0x4C) ? 1 : -1];

class TRIBE_Task_List : public RGE_Task_List {
public:
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float, float, float);
    virtual int is_attack_task(RGE_Task*);
};

#endif
