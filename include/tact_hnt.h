#ifndef AOE1_TACT_HNT_H
#define AOE1_TACT_HNT_H

#include "action.h"

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;

class TRIBE_Action_Hunt : public RGE_Action {
  public:
    TRIBE_Action_Hunt(int infile, RGE_Action_Object* obj_in);
    TRIBE_Action_Hunt(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in);
    TRIBE_Action_Hunt(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);
    virtual void save(int outfile);
    virtual void first_in_stack(unsigned char first_time);
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
    virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);

  protected:
    virtual void set_state(unsigned char new_state);
    int targetType;

    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();
};

typedef char tact_hnt_hunt_abi[(sizeof(TRIBE_Action_Hunt) == 0x44) ? 1 : -1];

#endif
