#pragma once

#include "common.h"
#include "TPanel.h"

class TButtonPanel;
class TScreenPanel;
class RGE_View;
class RGE_Diamond_Map;
struct TDigital;

class RGE_Panel_Tool_Box : public TPanel {
public:
    RGE_Panel_Tool_Box(
        TDrawArea* param_1,
        TPanel* param_2,
        long param_3,
        long param_4,
        long param_5,
        long param_6,
        void* param_7,
        long param_8,
        long param_9,
        TDigital* param_10,
        TScreenPanel* param_11,
        RGE_View* param_12,
        RGE_Diamond_Map* param_13);
    virtual ~RGE_Panel_Tool_Box();

    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) override;
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) override;
    virtual void draw() override;

    void game_mode_changed(int param_1, int param_2);

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
};

static_assert(sizeof(RGE_Panel_Tool_Box) == 0x120, "Size mismatch");
