#pragma once
#include "../common.h"

class RGE_Main_View : public RGE_View {
public:
    TPanel* map_view;                        // 0x360
    ulong last_mouse_scroll_time;            // 0x364
    int mouse_scrolling;                     // 0x368
    long mouse_last_x;                       // 0x36C
    long mouse_last_y;                       // 0x370
    ulong last_key_scroll_time;              // 0x374
    int key_scrolling;                       // 0x378
    RGE_Player* save_player;                 // 0x37C

    RGE_Main_View();
    virtual ~RGE_Main_View();
    virtual long handle_idle();
    virtual int do_auto_scroll();
    virtual int handle_keys();
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual int start_scroll_view(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual int handle_scroll_view(long param_1, long param_2);
    virtual void draw();
    virtual void draw_multi_object_outline();
    virtual int command_place_object(long param_1, long param_2, int param_3);
    virtual int command_make_do(long param_1, long param_2, int param_3, short param_4);
    virtual uchar pick1(uchar param_1, uchar param_2, long param_3, long param_4, RGE_Pick_Info* param_5, RGE_Static_Object* param_6, int param_7);
    virtual int pick_objects1(long param_1, long param_2, RGE_Static_Object** param_3, int param_4);
    virtual RGE_Static_Object* pick_best_target(long param_1, long param_2, int* param_3, short param_4);
    virtual int command_make_move(long param_1, long param_2);
    virtual int command_make_work(long param_1, long param_2);
    virtual int command_place_multi_object(long param_1, long param_2, long param_3, long param_4, int param_5);
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4);
    virtual void fixup_pick_info(RGE_Pick_Info* param_1);
    virtual void reset_display_object_selection(int param_1);
};

static_assert(sizeof(RGE_Main_View) == 0x380, "RGE_Main_View Size Mismatch");
static_assert(offsetof(RGE_Main_View, save_player) == 0x37C, "RGE_Main_View Offset Mismatch");

