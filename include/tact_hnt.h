#ifndef AOE1_TACT_HNT_H
#define AOE1_TACT_HNT_H

#include <stdio.h>

// Declarations used only by the tact_hnt.cpp source module.
#include "m_co_obj.h"
#include "action.h"
#include "act_atak.h"
#include "act_move.h"
#include "act_list.h"
#include "act_obj.h"
#include "stat_obj.h"
#include "m_s_obj.h"
#include "m_ac_obj.h"
#include "move_obj.h"
#include "obj_list.h"
#include "world.h"
#include "player.h"
#include "task.h"
#include "sound.h"
#include "basegame.h"
#include "rge_base_game_global.h"

class TRIBE_Action_Hunt : public RGE_Action {
public:
    TRIBE_Action_Hunt(int, RGE_Action_Object*);
    TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, float, float, float);
    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    virtual void set_state(unsigned char);
    int targetType;

    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();
};

typedef char tact_hnt_hunt_abi[
    (sizeof(TRIBE_Action_Hunt) == 0x44) ? 1 : -1];

extern float DAT_00575150;
extern double DAT_00575168;

#endif
