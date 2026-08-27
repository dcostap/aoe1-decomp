#ifndef AOE1_M_AC_OBJ_H
#define AOE1_M_AC_OBJ_H

#include "m_mo_obj.h"
#include <stdio.h>

class RGE_Sprite;
class RGE_Sound;
class RGE_Static_Object;
class RGE_Player;
class RGE_Task;
class RGE_Task_List;

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    using RGE_Master_Moving_Object::move_sprite;

    RGE_Task_List* tasks;
    short default_task;
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    unsigned char task_by_group;
    RGE_Sound* command_sound;
    RGE_Sound* move_sound;
    unsigned char run_pattern;

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

#endif  // AOE1_M_AC_OBJ_H
