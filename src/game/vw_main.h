#pragma once
#include "common.h"

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

    virtual void draw();                                    // vt0[12]+0x30=0x53F6F0
    virtual long handle_idle();                             // vt0[19]+0x4C=0x53DB40
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[30]+0x78=0x53E280
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[32]+0x80=0x53E2F0
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[33]+0x84=0x53E340
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[35]+0x8C=0x53E7F0
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[36]+0x90=0x53E910
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[38]+0x98=0x53F220
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[40]+0xA0=0x53F2F0
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[41]+0xA4=0x53F3D0
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4); // vt0[51]+0xCC=0x5405E0
    virtual int start_scroll_view(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[58]+0xE8=0x53F660
    virtual int handle_scroll_view(long param_1, long param_2); // vt0[59]+0xEC=0x53F6B0
    virtual void draw_multi_object_outline();               // vt0[62]+0xF8=0x53F800
    virtual int command_place_object(long param_1, long param_2, int param_3); // vt0[63]+0xFC=0x53F810
    virtual int command_make_do(long param_1, long param_2, int param_3, short param_4); // vt0[64]+0x100=0x53FA10
    virtual int command_make_move(long param_1, long param_2); // vt0[65]+0x104=0x540350
    virtual int command_make_work(long param_1, long param_2); // vt0[66]+0x108=0x540420
    virtual int command_place_multi_object(long param_1, long param_2, long param_3, long param_4, int param_5); // vt0[67]+0x10C=0x5405C0
    RGE_Main_View();
    ~RGE_Main_View();
    int do_auto_scroll();
    int handle_keys();
    uchar pick1(uchar param_1, uchar param_2, long param_3, long param_4, RGE_Pick_Info* param_5, RGE_Static_Object* param_6, int param_7);
    int pick_objects1(long param_1, long param_2, RGE_Static_Object** param_3, int param_4);
    RGE_Static_Object* pick_best_target(long param_1, long param_2, int* param_3, short param_4);
    void fixup_pick_info(RGE_Pick_Info* param_1);
    void reset_display_object_selection(int param_1);
};

static_assert(sizeof(RGE_Main_View) == 0x380, "RGE_Main_View Size Mismatch");

