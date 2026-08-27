#ifndef AOE1_TACT_CNV_H
#define AOE1_TACT_CNV_H

// Declaration surface owned by tact_cnv.cpp.

#include "action.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;

class TRIBE_Action_Convert : public RGE_Action {
public:
    TRIBE_Action_Convert(int, RGE_Action_Object*);
    TRIBE_Action_Convert(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Convert(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    virtual void set_state(unsigned char);

public:
    unsigned char was_same_owner;
    char gap_41[3];
    float requiredRange;

    void martyrdom();
};

typedef char tact_cnv_size_check[
    (sizeof(TRIBE_Action_Convert) == 0x48) ? 1 : -1];

#endif  // AOE1_TACT_CNV_H
