#pragma once
#include "common.h"

class RGE_Panel_Tool_Box : public TPanel {
public:
    TScreenPanel* screen_panel;              // 0xF4
    RGE_View* view;                          // 0xF8
    RGE_Diamond_Map* map;                    // 0xFC
    TButtonPanel* game_mode_button;          // 0x100
    TButtonPanel* object_mode_button;        // 0x104
    TButtonPanel* delete_mode_button;        // 0x108
    TButtonPanel* move_mode_button;          // 0x10C
    TButtonPanel* terrain_mode_button;       // 0x110
    TButtonPanel* elevation_mode_button;     // 0x114
    TButtonPanel* command_button;            // 0x118
    TPanel* dialog;                          // 0x11C

    virtual void draw();                                    // vt0[12]+0x30=0x48A640
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[43]+0xAC=0x48A320
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x489F50
    RGE_Panel_Tool_Box(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, long param_8, long param_9, TDigital* param_10, TScreenPanel* param_11, RGE_View* param_12, RGE_Diamond_Map* param_13);
    ~RGE_Panel_Tool_Box();
    void game_mode_changed(int param_1, int param_2);
};

static_assert(sizeof(RGE_Panel_Tool_Box) == 0x120, "RGE_Panel_Tool_Box Size Mismatch");

