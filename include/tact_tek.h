#ifndef AOE1_TACT_TEK_H
#define AOE1_TACT_TEK_H

// Declarations owned by the tact_tek.cpp source module.
#include "action.h"

class RGE_Action_Object;

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    virtual ~TRIBE_Action_Make_Tech();
    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int stop();

    short tech_id;
    int unique_id;

    TRIBE_Action_Make_Tech(int, RGE_Action_Object*);
    TRIBE_Action_Make_Tech(RGE_Action_Object*, short, int);
    void get_info(short&, short&, char*, short);

protected:
    virtual void set_state(unsigned char);
};

typedef char tribe_action_make_tech_size_check[
    (sizeof(TRIBE_Action_Make_Tech) == 0x48) ? 1 : -1];

#endif  // AOE1_TACT_TEK_H
