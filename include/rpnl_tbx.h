#ifndef AOE1_RPNL_TBX_H
#define AOE1_RPNL_TBX_H

// This header owns RGE_Panel_Tool_Box. Panel controls stay with their owners.
#include "Pnl_scr.h"
#include "pnl_btn.h"
#include "rdlg_lst.h"

class TDigital;
class RGE_View;
class RGE_Diamond_Map;

class RGE_Panel_Tool_Box : public TPanel {
public:
    TScreenPanel* screen_panel;
    RGE_View* view;
    RGE_Diamond_Map* map;
    TButtonPanel* game_mode_button;
    TButtonPanel* object_mode_button;
    TButtonPanel* delete_mode_button;
    TButtonPanel* move_mode_button;
    TButtonPanel* terrain_mode_button;
    TButtonPanel* elevation_mode_button;
    TButtonPanel* command_button;
    TPanel* dialog;

    RGE_Panel_Tool_Box(TDrawArea* draw_area_in, TPanel* parent_in, long x, long y,
                       long wid, long hgt, void* font, long font_wid, long font_hgt,
                       TDigital* sound, TScreenPanel* screen_panel_in, RGE_View* view_in,
                       RGE_Diamond_Map* map_in);
    virtual ~RGE_Panel_Tool_Box();
    void game_mode_changed(int old_mode, int new_mode);
    virtual long action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2);
    virtual long key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key);
    virtual void draw();
};

typedef char rpnl_tbx_size_check[
    (sizeof(RGE_Panel_Tool_Box) == 0x120) ? 1 : -1];

#endif
