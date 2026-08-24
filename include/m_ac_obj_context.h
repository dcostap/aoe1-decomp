#ifndef AOE1_M_AC_OBJ_CONTEXT_H
#define AOE1_M_AC_OBJ_CONTEXT_H

// Module-local declaration surface for m_ac_obj.cpp.
// Owner files keep their isolated declarations when this macro is not set.
#ifdef RGE_MAC_OBJ_SHARED_CONTEXT

#include <stdio.h>

extern void __cdecl operator_delete(void* object);

class RGE_Sprite;
class RGE_Static_Object;
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
    virtual unsigned char check_placement(RGE_Player* player, float x, float y,
                                          int* value, unsigned char a,
                                          unsigned char b, unsigned char c,
                                          unsigned char d, unsigned char e,
                                          unsigned char f);
    virtual unsigned char alignment(float* x, float* y, RGE_Game_World* world,
                                    unsigned char value);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y, RGE_Color_Table* colors,
                      long clip_x, long clip_y, int value,
                      unsigned char flags);

    unsigned char master_type;
    char gap_005[0x9F];
    unsigned char recyclable;
    char gap_0A5[0x13];
};

typedef char m_ac_obj_master_size[
    (sizeof(RGE_Master_Static_Object) == 0xB8) ? 1 : -1];

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Animated_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                             float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();

    RGE_Master_Animated_Object(RGE_Master_Animated_Object* source,
                               int do_setup);
    RGE_Master_Animated_Object(int id, RGE_Sprite** sprites,
                               RGE_Sound** sounds, int do_setup);
    RGE_Master_Animated_Object(FILE* file, RGE_Sprite** sprites,
                               RGE_Sound** sounds, short id, int do_setup);

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
    virtual ~RGE_Master_Moving_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                             float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();

    RGE_Master_Moving_Object(RGE_Master_Moving_Object* source, int do_setup);
    RGE_Master_Moving_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int do_setup);
    RGE_Master_Moving_Object(FILE* file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short id, int do_setup);

protected:
    int setup(RGE_Master_Moving_Object* source);
    int setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id);

    char gap_BC[0x1C];
};

typedef char m_ac_obj_moving_size[
    (sizeof(RGE_Master_Moving_Object) == 0xD8) ? 1 : -1];

class RGE_Task;

class RGE_Task_List {
public:
    RGE_Task** list;
    short list_num;

    RGE_Task_List();
    virtual ~RGE_Task_List();
    virtual RGE_Task* create_task(short task_type, int index);
    void copy(RGE_Task_List* source);
    void load(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    void load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Task {
public:
    char gap_00[4];
    unsigned char is_default;
    char pad_05;
    short action_type;
};

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

    RGE_Master_Action_Object(RGE_Master_Action_Object* source, int do_setup);
    RGE_Master_Action_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int do_setup);
    RGE_Master_Action_Object(FILE* file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short id, int do_setup);

protected:
    int setup(RGE_Master_Action_Object* source);
    int setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id);

public:
    RGE_Task* get_task(short task_id);
    RGE_Task* getTaskByTaskID(int task_id) const;
};

typedef char m_ac_obj_action_size[
    (sizeof(RGE_Master_Action_Object) == 0xFC) ? 1 : -1];

// These small views belong to unresolved owner bodies. They keep the module
// compiling without making their guessed layout part of the shared ABI.
struct RGE_Master_Moving_Object_copy_setup {
    char base[0xD8];
    void copy_setup(void* source);
};

struct RGE_Master_Moving_Object_copy {
    char base[0xD8];
    void copy_obj(void* source);
};

struct CopyRefHelper {
    char base[4];
    void copy_obj(void* source);
};

class VTable38Helper {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void* make_task_list();
};

#endif  // RGE_MAC_OBJ_SHARED_CONTEXT
#endif  // AOE1_M_AC_OBJ_CONTEXT_H
