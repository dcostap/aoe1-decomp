#ifndef AOE1_M_AC_OBJ_H
#define AOE1_M_AC_OBJ_H

#include <stdio.h>

extern void __cdecl operator_delete(void* object);
extern "C" void rge_read(int file, void* buffer, int size);
extern "C" void rge_write(int file, void* buffer, int size);

extern float save_game_version;
extern float DAT_00570484;

class RGE_Sprite;
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Combat_Object;
class TDrawArea;
class RGE_Color_Table;

class RGE_Sound {
public:
    char gap_00[0x0C];
    short id;
    char gap_0E[2];

    void play(int mode);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                             float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player* player, float x,
                                          float y, int* value,
                                          unsigned char a, unsigned char b,
                                          unsigned char c, unsigned char d,
                                          unsigned char e, unsigned char f);
    virtual unsigned char alignment(float* x, float* y, RGE_Game_World* world,
                                    unsigned char value);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* colors, long clip_x, long clip_y,
                      int value, unsigned char flags);

    unsigned char master_type;
    char gap_005[0x9F];
    unsigned char recyclable;
    char gap_0A5[0x13];
};

typedef char m_ac_obj_master_size[
    (sizeof(RGE_Master_Static_Object) == 0xB8) ? 1 : -1];

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Animated_Object(RGE_Master_Animated_Object* source,
                               int do_setup);
    RGE_Master_Animated_Object(int id, RGE_Sprite** sprites,
                               RGE_Sound** sounds, int do_setup);
    RGE_Master_Animated_Object(FILE* file, RGE_Sprite** sprites,
                               RGE_Sound** sounds, short id, int do_setup);

    virtual ~RGE_Master_Animated_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                             float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();

protected:
    int setup(RGE_Master_Animated_Object* source);
    int setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id);

    float speed;
};

typedef char m_ac_obj_animated_size[
    (sizeof(RGE_Master_Animated_Object) == 0xBC) ? 1 : -1];

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Master_Moving_Object(RGE_Master_Moving_Object* source, int do_setup);
    RGE_Master_Moving_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int do_setup);
    RGE_Master_Moving_Object(FILE* file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short id, int do_setup);

    virtual ~RGE_Master_Moving_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                             float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();

protected:
    int setup(RGE_Master_Moving_Object* source);
    int setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id);

    char gap_BC[0x1C];
};

typedef char m_ac_obj_moving_size[
    (sizeof(RGE_Master_Moving_Object) == 0xD8) ? 1 : -1];

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

    RGE_Task(short object_id);
    ~RGE_Task();
    void copy(RGE_Task* source);
    void load(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    void load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds);
    void save(int file);
};

typedef char m_ac_obj_task_size[
    (sizeof(RGE_Task) == 0x4C) ? 1 : -1];

class RGE_Task_List {
public:
    RGE_Task_List();
    // BINARY NOTE: exact owner 00508E20 and include/task_lst.h prove a
    // nonvirtual destructor. Virtual dispatch changes 0044F4D0's target and
    // escapes its original boundary.
    ~RGE_Task_List();
    void copy(RGE_Task_List* source);
    void load(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    void load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds);
    void save(int file);
    void delete_list();

    virtual RGE_Task* create_task(short task_type, short index);
    virtual RGE_Task* get_target_task(RGE_Action_Object* action_object,
                                      RGE_Static_Object* static_object,
                                      float x, float y, float z);
    virtual int is_attack_task(RGE_Task* task);

protected:
    virtual int check_task(RGE_Task* task, RGE_Action_Object* action_object,
                           RGE_Static_Object* static_object);

public:
    RGE_Task** list;
    short list_num;
};

typedef char m_ac_obj_task_list_size[
    (sizeof(RGE_Task_List) == 0x0C) ? 1 : -1];

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Task_List* tasks;
    short default_task;
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    unsigned char task_by_group;
    char gap_ED[3];
    RGE_Sound* command_sound;
    RGE_Sound* move_sound;
    unsigned char run_pattern;
    char gap_F9[3];

    RGE_Master_Action_Object(RGE_Master_Action_Object* source, int do_setup);
    RGE_Master_Action_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int do_setup);
    RGE_Master_Action_Object(FILE* file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short id, int do_setup);

    virtual ~RGE_Master_Action_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                             float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual RGE_Task_List* create_task_list();
    virtual void play_command_sound();
    virtual void play_move_sound();

    RGE_Task* get_task(short task_id);
    RGE_Task* getTaskByTaskID(int task_id) const;

protected:
    int setup(RGE_Master_Action_Object* source);
    int setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id);
};

typedef char m_ac_obj_action_size[
    (sizeof(RGE_Master_Action_Object) == 0xFC) ? 1 : -1];

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z);
    char gap_04[0x84];
};

class RGE_Game_World {
public:
    RGE_Static_Object* recycle_object_in_to_game(unsigned char master_type);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Moving_Object : public RGE_Static_Object {
public:
    char gap_88[0xF8];

    RGE_Moving_Object(RGE_Master_Static_Object* master, RGE_Player* player,
                      float x, float y, float z, int do_setup);
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    char gap_180[0x14];

    RGE_Action_Object(RGE_Master_Action_Object* master, RGE_Player* player,
                      float x, float y, float z, int do_setup);
};

#endif  // AOE1_M_AC_OBJ_H
