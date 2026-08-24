#ifndef ACT_EXPL_CONTEXT_H
#define ACT_EXPL_CONTEXT_H

// Use the reviewed action/object ABI from the existing action context.  This
// module adds only its derived owner and does not invent virtual-slot padding.
#include "act_atak_context.h"

class RGE_Action_Explore : public RGE_Action {
public:
    RGE_Action_Explore(int, RGE_Action_Object*);
    RGE_Action_Explore(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual void first_in_stack(uchar);
    virtual uchar update(void);
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    virtual void set_state(uchar);
};

#endif
