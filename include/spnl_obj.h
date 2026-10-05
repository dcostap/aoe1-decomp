#ifndef AOE1_SPNL_OBJ_H
#define AOE1_SPNL_OBJ_H

// This header owns only the scenario-editor panel extension.
#include "tpnl_obj.h"

class RGE_Master_Static_Object;

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
  public:
    virtual ~TRIBE_Scenario_Editor_Panel_Object();
    TRIBE_Scenario_Editor_Panel_Object(
        TDrawArea* render_area_in, TPanel* parent_panel_in, void* font_in, long font_wid_in, long font_hgt_in,
        TShape* unit_pics_in, TShape** bldg_pics_in, TRIBE_Player* player_in
    );

    virtual void draw();
    virtual void draw_item(int row, int pic_index, ValueType val_type, int val1, int val2);
    virtual long mouse_left_up_action(long x, long y, int ctrl_key, int shift_key);

    void set_master_info(RGE_Master_Static_Object* master_game_object_in, TRIBE_Player* master_player_in);
    long get_pierce_armor();

    RGE_Master_Static_Object* master_game_obj;
    int master_culture_id;
};

typedef char spnl_obj_panel_size_check[(sizeof(TRIBE_Scenario_Editor_Panel_Object) == 0x21C) ? 1 : -1];

#endif // AOE1_SPNL_OBJ_H
