// VA: 0044F3C0 RGE_Master_Action_Object::setup
// PDB source: m_ac_obj.cpp, lines 119-164
// Attempt log:
// baseline: canonical action-object fields, typed fscanf outputs, task-list
//            creation/load, and the default-task scan; 268-byte build, 36
//            positional diff, with all four calls and the full prefix aligned.
// control-flow probes: do/while, infinite-loop, positive-continue, found-arm,
// and goto spellings did not improve the natural loop basin (best transient
// was 269 bytes / 32 diff, but added a duplicated loop body). A bounded
// while had only 5 edit-diff bytes but added a redundant initial count test
// and four bytes past the original boundary. The exact source shape is a
// natural do/while whose nondefault arm increments the index/cursor and whose
// found arm assigns default_task and breaks; this preserves the late found
// store and the separate exhausted return while emitting the original CFG.

#include <stdio.h>

#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
class RGE_Sprite;
class RGE_Sound;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Player;
class RGE_Game_World;
class TDrawArea;
class RGE_Color_Table;

class RGE_Task {
public:
    char gap_00[4];
    unsigned char is_default;
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short task_type, int index);
    RGE_Task** list;
    short list_num;

    void load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
                                             float x, float y, float z);
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
                      long clip_x, long clip_y, int value, unsigned char flags);

    unsigned char master_type;
    char gap_005[0xB3];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;

    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count);
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x1C];

    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count);
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

    virtual RGE_Task_List* create_task_list();
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count);
};
#endif

int RGE_Master_Action_Object::setup(FILE* file, RGE_Sprite** sprites,
                                    RGE_Sound** sounds, short count)
{
    short task_by_group_out;
    short command_sound_id;
    short move_sound_id;
    short run_pattern_out;
    RGE_Sound* selected_command_sound;
    RGE_Sound* selected_move_sound;
    int index;
    int list_num;
    RGE_Task** task;

    RGE_Master_Moving_Object::setup(file, sprites, sounds, count);
    master_type = 0x28;

    fscanf(file, "%f %f %hd %hd %hd %hd %hd %hd",
           &search_radius, &work_rate, &drop_site, &backup_drop_site,
           &task_by_group_out, &command_sound_id, &move_sound_id,
           &run_pattern_out);

    task_by_group = (unsigned char)task_by_group_out;
    run_pattern = (unsigned char)run_pattern_out;

    if (command_sound_id >= 0)
        selected_command_sound = sounds[command_sound_id];
    else
        selected_command_sound = (RGE_Sound*)0;
    command_sound = selected_command_sound;

    if (move_sound_id >= 0)
        selected_move_sound = sounds[move_sound_id];
    else
        selected_move_sound = (RGE_Sound*)0;
    move_sound = selected_move_sound;

    tasks = create_task_list();
    tasks->load(file, sprites, sounds);
    default_task = -1;
    index = 0;
    list_num = (int)tasks->list_num;
    if (list_num > 0) {
        task = tasks->list;
        do {
            if ((*task)->is_default == 0) {
                index++;
                task++;
            } else {
                default_task = (short)index;
                break;
            }
        } while (index < list_num);
    }
    return 1;
}
