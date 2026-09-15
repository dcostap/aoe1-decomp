#ifndef AOE1_VW_MAIN_H
#define AOE1_VW_MAIN_H

#include "view.h"

class TRIBE_Player;
class TRIBE_Master_Building_Object;

struct DisplaySelectedObjRec {
    int active;
    int id;
    unsigned long start_time;
    unsigned long duration;
    int select_type;
};

class RGE_Main_View : public RGE_View {
public:
    RGE_Main_View();
    virtual void draw();
    virtual long handle_idle();
    virtual long handle_mouse_up(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_move_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_left_down_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_left_move_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_left_up_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_right_down_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_right_move_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_right_up_action(long x, long y, int ctrl_key, int shift_key);
    virtual int command_place_object(long x, long y, int reset_mode);
    virtual int command_make_do(long x, long y, int work_on_tile, short action_type);
    virtual int command_make_move(long x, long y);
    virtual int command_make_work(long x, long y);
    virtual int command_place_multi_object(long x1, long y1, long x2, long y2, int reset_mode);
    virtual int start_scroll_view(unsigned char scroll_action_in, long x, long y, int ctrl_key, int shift_key);
    virtual int handle_scroll_view(long x, long y);
    virtual void draw_multi_object_outline();
    int do_auto_scroll();
    int handle_keys();
    unsigned char pick1(unsigned char pick_mode_in, unsigned char select_level, long x, long y,
                        RGE_Pick_Info* pick_info, RGE_Static_Object* last_picked_object, int pick_dopples);
    int pick_objects1(long x, long y, RGE_Static_Object** object_list, int max_objects);
    RGE_Static_Object* pick_best_target(long x, long y, int* attacking_in, short action_type);

protected:
    virtual unsigned char get_help_info(char*& string, long& page, long x, long y);
    void fixup_pick_info(RGE_Pick_Info* pick_info);

public:
    void reset_display_object_selection(int reset_type);

    TPanel* map_view;
    unsigned long last_mouse_scroll_time;
    int mouse_scrolling;
    long mouse_last_x;
    long mouse_last_y;
    unsigned long last_key_scroll_time;
    int key_scrolling;
    RGE_Player* save_player;
};

typedef char vw_main_main_view_size_check[
    (sizeof(RGE_Main_View) == 0x380) ? 1 : -1];

// tvw_main.cpp owns the derived game-view input and wall-placement methods.
// The base layout and virtual surface remain owned by vw_main.cpp/view.cpp.
class TRIBE_Main_View : public RGE_Main_View {
public:
    virtual long mouse_left_up_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_left_dbl_click_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_right_up_action(long x, long y, int ctrl_key, int shift_key);
    virtual int pick_through_fog(RGE_Static_Object* obj);
    virtual int pick_weight(RGE_Static_Object* obj, int confidence);
    virtual void draw_multi_object_outline();
    virtual int command_place_object(long x, long y, int reset_mode);
    virtual int command_make_do(long x, long y, int work_on_tile, short action_type);
    virtual int command_place_multi_object(long x1, long y1, long x2, long y2, int reset_mode);

protected:
    int draw_wall_outline(long col, long row, TRIBE_Master_Building_Object* master_bldg, long facet);
    void place_line_of_walls(TRIBE_Player* player, TRIBE_Master_Building_Object* master_obj, int x1, int y1, int x2, int y2);
};

typedef char vw_main_tribe_main_view_size_check[
    (sizeof(TRIBE_Main_View) == 0x380) ? 1 : -1];

#endif
