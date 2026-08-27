#ifndef AOE1_TACT_DAR_H
#define AOE1_TACT_DAR_H

// Declarations owned by the tact_dar.cpp source module.
#include "action.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    unsigned char* flags;

    TRIBE_Action_Discovery_Artifact(int, RGE_Action_Object*);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*,
                                    RGE_Static_Object*);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*,
                                    float, float, float);

    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();

protected:
    virtual void set_state(unsigned char);
    void check_objects();
};

typedef char tact_dar_action_size_check[
    (sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_dar_discovery_size_check[
    (sizeof(TRIBE_Action_Discovery_Artifact) == 0x44) ? 1 : -1];

#endif  // AOE1_TACT_DAR_H
