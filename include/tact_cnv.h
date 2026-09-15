#ifndef AOE1_TACT_CNV_H
#define AOE1_TACT_CNV_H

// Declaration surface owned by tact_cnv.cpp.

#include "action.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;

class TRIBE_Action_Convert : public RGE_Action {
public:
    TRIBE_Action_Convert(int infile, RGE_Action_Object* obj_in);
    TRIBE_Action_Convert(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in);
    TRIBE_Action_Convert(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);

    virtual void save(int outfile);
    virtual void first_in_stack(unsigned char first_time);
    virtual unsigned char update();
    virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);

protected:
    virtual void set_state(unsigned char new_state);

public:
    unsigned char was_same_owner;
    float requiredRange; // Natural alignment places this field at +0x44.

    void martyrdom();
};

typedef char tact_cnv_size_check[
    (sizeof(TRIBE_Action_Convert) == 0x48) ? 1 : -1];

#endif  // AOE1_TACT_CNV_H
