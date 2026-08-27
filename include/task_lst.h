#ifndef AOE1_TASK_LST_H
#define AOE1_TASK_LST_H

#include <stdio.h>

class RGE_Sprite;
class RGE_Sound;
class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Map;
class RGE_Task_List;

extern "C" int __cdecl rge_read(int fd, void* buffer, int size);
extern "C" void __cdecl rge_write(int fd, void* buffer, int size);
extern void* __cdecl calloc(int count, int size);
extern void __cdecl free(void* block);
extern int __cdecl fscanf(FILE* file, const char* format, ...);

class RGE_Task {
public:
    short task_type;
    short id;
    unsigned char is_default;
    unsigned char pad_05;
    short action_type;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char owner_type;
    unsigned char holding_attr;
    unsigned char state_building;
    unsigned char pad_13;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    unsigned char search_flag;
    unsigned char pad_29[3];
    float search_wait_time;
    short work_flag;
    short work_flag2;
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
    RGE_Sound* work_sound;
    RGE_Sound* work_sound2;

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
    // The destructor is nonvirtual in the original ABI.
    ~RGE_Task_List();

    void copy(RGE_Task_List*);
    void load(int, RGE_Sprite**, RGE_Sound**);
    void load(FILE*, RGE_Sprite**, RGE_Sound**);
    void save(int);
    void delete_list();

    virtual RGE_Task* create_task(short, short);
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float, float, float);
    virtual int is_attack_task(RGE_Task*);

protected:
    virtual int check_task(RGE_Task*, RGE_Action_Object*, RGE_Static_Object*);

    RGE_Task** list;
    short list_num;
};

typedef char task_lst_task_list_size_check[(sizeof(RGE_Task_List) == 0x0C) ? 1 : -1];

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    unsigned char master_type;
    char pad_05[0x0B];
    short id;
    short copy_id;
    short object_group;
    char pad_16[0x76];
    unsigned char combat_level;
};

typedef char task_lst_master_prefix_check[(sizeof(RGE_Master_Static_Object) == 0x90) ? 1 : -1];

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void*);
    char pad_04[0x24];
    RGE_Map* map;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char pad_04[4];
    int map_width;
    int map_height;
    unsigned char get_terrain(short, short);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(long);
    virtual int isAlly(long);

    char pad_04[0x34];
    char pad_38[4];
    RGE_Game_World* world;
    char pad_40[0x0A];
    short id;
    unsigned char relation(long);
};

typedef char task_lst_player_prefix_check[(sizeof(RGE_Player) == 0x4C) ? 1 : -1];

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char pad_10[0x34];
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char pad_49[3];
    short attribute_type_held;
};

typedef char task_lst_static_prefix_check[(sizeof(RGE_Static_Object) == 0x50) ? 1 : -1];

class RGE_Action_Object : public RGE_Static_Object {
};

#endif
