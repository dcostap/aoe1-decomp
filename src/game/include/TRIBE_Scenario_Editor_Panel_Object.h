#pragma once
#include "common.h"
#include "TRIBE_Panel_Object.h"

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
public:
    TRIBE_Scenario_Editor_Panel_Object(TDrawArea* param_1, TPanel* param_2, void* param_3, long param_4, long param_5, TShape* param_6, TShape** param_7, TRIBE_Player* param_8);
    virtual ~TRIBE_Scenario_Editor_Panel_Object(); // vt[0] (0x0)
    virtual void draw() override; // vt[12] (0x30)
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) override; // vt[36] (0x90)
    virtual void draw_item(int param_1, int param_2, ValueType param_3, int param_4, int param_5) override; // vt[56] (0xE0)

    void set_master_info(RGE_Master_Static_Object* param_1, TRIBE_Player* param_2);
    long get_pierce_armor();

    RGE_Master_Static_Object* master_game_obj;
    int master_culture_id;
};
static_assert(sizeof(TRIBE_Scenario_Editor_Panel_Object) == 0x21C, "Size mismatch");
