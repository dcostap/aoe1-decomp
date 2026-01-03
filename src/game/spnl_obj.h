#pragma once
#include "../common.h"
#include "m_s_obj.h"
#include "tpnl_obj.h"
#include "Panel.h"
#include "tplayer.h"

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
public:
    RGE_Master_Static_Object* master_game_obj; // 0x214
    int master_culture_id;                   // 0x218

    TRIBE_Scenario_Editor_Panel_Object(TDrawArea* param_1, TPanel* param_2, void* param_3, long param_4, long param_5, TShape* param_6, TShape** param_7, TRIBE_Player* param_8);
    virtual ~TRIBE_Scenario_Editor_Panel_Object();
    virtual void set_master_info(RGE_Master_Static_Object* param_1, TRIBE_Player* param_2);
    virtual void draw();
    virtual void draw_item(int param_1, int param_2, ValueType param_3, int param_4, int param_5);
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long get_pierce_armor();
};

static_assert(sizeof(TRIBE_Scenario_Editor_Panel_Object) == 0x21C, "TRIBE_Scenario_Editor_Panel_Object Size Mismatch");
static_assert(offsetof(TRIBE_Scenario_Editor_Panel_Object, master_culture_id) == 0x218, "TRIBE_Scenario_Editor_Panel_Object Offset Mismatch");

