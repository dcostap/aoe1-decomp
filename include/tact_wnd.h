#ifndef AOE1_TACT_WND_H
#define AOE1_TACT_WND_H

#include "action.h"

class RGE_Action_Object;

class TRIBE_Action_Wonder : public RGE_Action {
public:
    TRIBE_Action_Wonder(int, RGE_Action_Object*);
    TRIBE_Action_Wonder(RGE_Action_Object*);

    virtual ~TRIBE_Action_Wonder();
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();

protected:
    virtual void set_state(unsigned char);
};

typedef char tact_wnd_action_wonder_size[
    (sizeof(TRIBE_Action_Wonder) == 0x40) ? 1 : -1];

#endif  // AOE1_TACT_WND_H
