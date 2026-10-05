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

    RGE_Master_Action_Object(RGE_Master_Action_Object* other_object, int do_setup);
    RGE_Master_Action_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
    RGE_Master_Action_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup);

    virtual ~RGE_Master_Action_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, unsigned char flag);
    virtual void modify_delta(float amount, unsigned char flag);
    virtual void modify_percent(float amount, unsigned char flag);
    virtual void save(int outfile);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual RGE_Task_List* create_task_list();
    virtual void play_command_sound();
    virtual void play_move_sound();

    RGE_Task* get_task(short task_id);
    RGE_Task* getTaskByTaskID(int t) const;

  protected:
    int setup(RGE_Master_Action_Object* other_object);
    int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);
};

typedef char m_ac_obj_action_size[(sizeof(RGE_Master_Action_Object) == 0xFC) ? 1 : -1];

#endif // AOE1_M_AC_OBJ_H
