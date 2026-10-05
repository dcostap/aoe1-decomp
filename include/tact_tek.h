#ifndef AOE1_TACT_TEK_H
#define AOE1_TACT_TEK_H

#include "action.h"

class RGE_Action_Object;

class TRIBE_Action_Make_Tech : public RGE_Action {
  public:
    virtual ~TRIBE_Action_Make_Tech();
    virtual void save(int outfile);
    virtual void first_in_stack(unsigned char first_time);
    virtual unsigned char update();
    virtual int stop();

    short tech_id;
    int unique_id;

    TRIBE_Action_Make_Tech(int infile, RGE_Action_Object* obj_in);
    TRIBE_Action_Make_Tech(RGE_Action_Object* obj_in, short id, int uID);
    void get_info(short& id, short& progress, char* name, short name_size);

  protected:
    virtual void set_state(unsigned char new_state);
};

typedef char tribe_action_make_tech_size_check[(sizeof(TRIBE_Action_Make_Tech) == 0x48) ? 1 : -1];

#endif // AOE1_TACT_TEK_H
