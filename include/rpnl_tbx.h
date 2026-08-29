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

    RGE_Panel_Tool_Box(TDrawArea*, TPanel*, long, long, long, long, void*,
                       long, long, TDigital*, TScreenPanel*, RGE_View*,
                       RGE_Diamond_Map*);
    virtual ~RGE_Panel_Tool_Box();
    void game_mode_changed(int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long key_down_action(long, short, int, int, int);
    virtual void draw();
};

typedef char rpnl_tbx_size_check[
    (sizeof(RGE_Panel_Tool_Box) == 0x120) ? 1 : -1];

#endif
