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
    virtual ~RGE_Main_View();
    virtual void draw();
    virtual long handle_idle();
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual int command_place_object(long, long, int);
    virtual int command_make_do(long, long, int, short);
    virtual int command_make_move(long, long);
    virtual int command_make_work(long, long);
    virtual int command_place_multi_object(long, long, long, long, int);
    virtual int start_scroll_view(unsigned char, long, long, int, int);
    virtual int handle_scroll_view(long, long);
    virtual void draw_multi_object_outline();
    int do_auto_scroll();
    int handle_keys();
    unsigned char pick1(unsigned char, unsigned char, long, long,
                        RGE_Pick_Info*, RGE_Static_Object*, int);
    int pick_objects1(long, long, RGE_Static_Object**, int);
    RGE_Static_Object* pick_best_target(long, long, int*, short);
    virtual unsigned char get_help_info(char*&, long&, long, long);
    void fixup_pick_info(RGE_Pick_Info*);
    void reset_display_object_selection(int);

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
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual int pick_through_fog(RGE_Static_Object*);
    virtual int pick_weight(RGE_Static_Object*, int);
    virtual void draw_multi_object_outline();
    virtual int command_place_object(long, long, int);
    virtual int command_make_do(long, long, int, short);
    virtual int command_place_multi_object(long, long, long, long, int);

protected:
    int draw_wall_outline(long, long, TRIBE_Master_Building_Object*, long);
    void place_line_of_walls(TRIBE_Player*, TRIBE_Master_Building_Object*,
                             int, int, int, int);
};

typedef char vw_main_tribe_main_view_size_check[
    (sizeof(TRIBE_Main_View) == 0x380) ? 1 : -1];

#endif
