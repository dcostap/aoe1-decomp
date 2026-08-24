#ifndef AOE1_TASK_LST_CONTEXT_H
#define AOE1_TASK_LST_CONTEXT_H

// Authentic source-module context for C:\\msdev\\work\\age1_x1\\task_lst.cpp.
//
// The member order below follows the PDB source order and the observed object
// offsets.  It is the one compiler-facing owner for this module.

#include <stdio.h>
#include "game_globals.h"

class RGE_Sprite;
class RGE_Sound;
class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Game_World;
class RGE_Map;
class RGE_Player;
class RGE_Task_List;

extern "C" int __cdecl rge_read(int fd, void* buffer, int size);
extern "C" void __cdecl rge_write(int fd, void* buffer, int size);
extern void* __cdecl calloc(int count, int size);
extern void __cdecl free(void* block);
extern int __cdecl fscanf(FILE* file, const char* format, ...);

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
    unsigned char search_flag;           // +0x28
    unsigned char pad_29[3];            // +0x29..+0x2B
    float search_wait_time;             // +0x2C
    short work_flag;                    // +0x30
    short work_flag2;                   // +0x32
    RGE_Sprite* move_sprite;            // +0x34
    RGE_Sprite* work_sprite;            // +0x38
    RGE_Sprite* work_sprite2;           // +0x3C
    RGE_Sprite* carry_sprite;           // +0x40
    RGE_Sound* work_sound;              // +0x44
    RGE_Sound* work_sound2;             // +0x48

    RGE_Task(short);
    ~RGE_Task();
    void copy(RGE_Task*);
    void load(int, RGE_Sprite**, RGE_Sound**);
    void load(FILE*, RGE_Sprite**, RGE_Sound**);
    void save(int);
};

typedef char task_lst_task_size_check[(sizeof(RGE_Task) == 0x4C) ? 1 : -1];

class RGE_Task_List {
public:
    RGE_Task_List();
    // BINARY NOTE: the vtable starts with create_task at slot zero.  The
    // destructor is nonvirtual even though the class has virtual task methods.
    ~RGE_Task_List();

    void copy(RGE_Task_List*);
    void load(int, RGE_Sprite**, RGE_Sound**);
    void load(FILE*, RGE_Sprite**, RGE_Sound**);
    void save(int);
    void delete_list();

    virtual RGE_Task* create_task(short, short);                                  // vt[0]
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float, float, float); // vt[1]
    virtual int is_attack_task(RGE_Task*);                                         // vt[2]
    virtual int check_task(RGE_Task*, RGE_Action_Object*, RGE_Static_Object*);      // vt[3]

    RGE_Task** list;                    // +0x04
    short list_num;                     // +0x08
};

typedef char task_lst_task_list_size_check[(sizeof(RGE_Task_List) == 0x0C) ? 1 : -1];

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    unsigned char master_type;           // +0x04
    char pad_05[0x0B];                   // +0x05..+0x0F
    short id;                            // +0x10
    short copy_id;                       // +0x12
    short object_group;                  // +0x14
    char pad_16[0x76];                   // +0x16..+0x8B
    unsigned char combat_level;          // +0x8C
};

typedef char task_lst_master_prefix_check[(sizeof(RGE_Master_Static_Object) == 0x90) ? 1 : -1];

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void*);
    char pad_04[0x24];                   // +0x04..+0x27
    RGE_Map* map;                        // +0x28
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char pad_04[4];                      // +0x04..+0x07
    int map_width;                        // +0x08
    int map_height;                       // +0x0C
    unsigned char get_terrain(short, short);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vpad04();
    virtual void vpad08();
    virtual void vpad0C();
    virtual void vpad10();
    virtual void vpad14();
    virtual void vpad18();
    virtual int isAlly(long);             // vt[7], +0x1C

    char pad_04[0x34];                    // +0x04..+0x37
    char pad_38[4];                       // +0x38..+0x3B
    RGE_Game_World* world;                // +0x3C
    char pad_40[0x0A];                    // +0x40..+0x49
    short id;                             // +0x4A
    unsigned char relation(long);
};

typedef char task_lst_player_prefix_check[(sizeof(RGE_Player) == 0x4C) ? 1 : -1];

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;                              // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                    // +0x0C
    char pad_10[0x34];                    // +0x10..+0x43
    float attribute_amount_held;          // +0x44
    unsigned char object_state;           // +0x48
    unsigned char pad_49[3];              // +0x49..+0x4B
    short attribute_type_held;            // +0x4C
};

typedef char task_lst_static_prefix_check[(sizeof(RGE_Static_Object) == 0x50) ? 1 : -1];

class RGE_Action_Object : public RGE_Static_Object {
};

#endif
