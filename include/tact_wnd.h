#ifndef AOE1_TACT_WND_H
#define AOE1_TACT_WND_H

#include <stdio.h>
#include "action.h"
#include "act_list.h"
#include "act_obj.h"
#include "stat_obj.h"
#include "m_s_obj.h"
#include "m_ac_obj.h"
#include "move_obj.h"
#include "world.h"
#include "obj_list.h"
#include "player.h"
#include "basegame.h"
#include "rge_base_game_global.h"

// tact_wnd.cpp uses RGE_Scenario only through the canonical Base Game
// signatures. basegame.h supplies those forwards without a second Base Game
// declaration from scenario.h.
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
