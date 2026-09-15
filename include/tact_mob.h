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
    TRIBE_Action_Make_Obj(int infile, RGE_Action_Object* obj_in);
    TRIBE_Action_Make_Obj(RGE_Action_Object* obj_in, short id, int uniqueID, uchar paid);

    virtual ~TRIBE_Action_Make_Obj();
    virtual void save(int outfile);
    virtual void first_in_stack(uchar first_time);
    virtual uchar update();
    virtual int stop();

protected:
    virtual void set_state(uchar new_state);
    uchar place_obj(RGE_Static_Object** rObj);

public:
    short obj_id;
    float work_done;
    int unique_id;
    uchar pre_paid;

    void get_info(short& id, short& progress, char* name, short name_size);
};

typedef char tact_mob_action_size[(sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_mob_make_obj_size[
    (sizeof(TRIBE_Action_Make_Obj) == 0x50) ? 1 : -1];

#endif
