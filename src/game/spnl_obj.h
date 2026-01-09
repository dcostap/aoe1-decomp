#pragma once
#include "common.h"

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
public:
    RGE_Master_Static_Object* master_game_obj; // 0x214
    int master_culture_id;                   // 0x218

    virtual void draw();                                    // vt0[12]+0x30=0x4BEE70
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[36]+0x90=0x4BF6C0
    virtual void draw_item(int param_1, int param_2, ValueType param_3, int param_4, int param_5); // vt0[56]+0xE0=0x4BF4D0
    TRIBE_Scenario_Editor_Panel_Object(TDrawArea* param_1, TPanel* param_2, void* param_3, long param_4, long param_5, TShape* param_6, TShape** param_7, TRIBE_Player* param_8);
    ~TRIBE_Scenario_Editor_Panel_Object();
    void set_master_info(RGE_Master_Static_Object* param_1, TRIBE_Player* param_2);
    long get_pierce_armor();
};

static_assert(sizeof(TRIBE_Scenario_Editor_Panel_Object) == 0x21C, "TRIBE_Scenario_Editor_Panel_Object Size Mismatch");

