#pragma once

#include "game_globals.h"
#include "action.h"
#include "act_list.h"
#include "m_s_obj.h"
#include "m_ac_obj.h"
#include "stat_obj.h"
#include "move_obj.h"
#include "act_obj.h"
#include "player.h"
#include "sprite.h"
#include "task.h"
#include "world.h"

// map.h includes the legacy obj_list surface, so this module uses the
// canonical object-list method surface without importing that fallback.
class RGE_Object_List {
public:
    RGE_Static_Object* find_by_master_ids(long, long, float, float,
                                          unsigned char, unsigned char,
                                          RGE_Static_Object*);
};

// No canonical owner header exists for RGE_Action_Move_To yet.  This local
// declaration contains only the constructors and field used by tact_trd.
class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float,
                       RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float,
                       RGE_Sprite*);

    float range;
};

class TRIBE_Action_Trade : public RGE_Action {
public:
    virtual ~TRIBE_Action_Trade();
    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);

    TRIBE_Action_Trade(int, RGE_Action_Object*);
    TRIBE_Action_Trade(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Trade(RGE_Action_Object*, RGE_Task*, float, float, float);

protected:
    virtual void set_state(unsigned char);
    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();

public:
    float pick_up_x;
    float pick_up_y;
};

typedef char tact_trd_action_trade_size_check[
    (sizeof(TRIBE_Action_Trade) == 0x48) ? 1 : -1];
