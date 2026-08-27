#ifndef AOE1_TACT_MOB_H
#define AOE1_TACT_MOB_H

// Canonical owner declarations for C:\\msdev\\work\\age1_x1\\tact_mob.cpp.
// The source module supplies the full owner declarations.
#include "action.h"

typedef unsigned char uchar;

class RGE_Action_Object;
class RGE_Static_Object;

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    TRIBE_Action_Make_Obj(int, RGE_Action_Object*);
    TRIBE_Action_Make_Obj(RGE_Action_Object*, short, int, uchar);

    virtual ~TRIBE_Action_Make_Obj();
    virtual void save(int);
    virtual void first_in_stack(uchar);
    virtual uchar update();
    virtual int stop();

protected:
    virtual void set_state(uchar);
    uchar place_obj(RGE_Static_Object**);

public:
    short obj_id;
    float work_done;
    int unique_id;
    uchar pre_paid;

    void get_info(short&, short&, char*, short);
};

typedef char tact_mob_action_size[(sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_mob_make_obj_size[
    (sizeof(TRIBE_Action_Make_Obj) == 0x50) ? 1 : -1];

#endif
