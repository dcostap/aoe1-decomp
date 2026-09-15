#ifndef AOE1_TACT_DAR_H
#define AOE1_TACT_DAR_H

#include "action.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    unsigned char* flags;

    TRIBE_Action_Discovery_Artifact(int infile, RGE_Action_Object* obj_in);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj_in, RGE_Task* task_in,
                                    RGE_Static_Object* target_obj_in);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj_in, RGE_Task* task_in,
                                    float x, float y, float z);

    virtual void save(int outfile);
    virtual void first_in_stack(unsigned char first_time);
    virtual unsigned char update();

protected:
    virtual void set_state(unsigned char new_state);
    void check_objects();
};

typedef char tact_dar_action_size_check[
    (sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_dar_discovery_size_check[
    (sizeof(TRIBE_Action_Discovery_Artifact) == 0x44) ? 1 : -1];

#endif  // AOE1_TACT_DAR_H
