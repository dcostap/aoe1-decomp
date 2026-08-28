#ifndef AOE1_VW_MAIN_H
#define AOE1_VW_MAIN_H

#include "view.h"
#include "sprite.h"

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

struct DisplaySelectedObjRec {
    int active;
    int id;
    unsigned long start_time;
    unsigned long duration;
    int select_type;
};

struct RGE_Pick_Obj_Info {
    int object_id;
    short confidence;
    short draw_level;
    short sx;
    short sy;
};

typedef RGE_Pick_Obj_Info PickedInfo;

extern RGE_Pick_Obj_Info Picked_Objects[];
extern int allow_user_commands;
extern int do_draw_log;
extern const float DAT_00577900;
extern const float DAT_00577904;
extern const float DAT_00577908;

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

extern "C" void __cdecl color_log(unsigned char, unsigned char, int);
extern "C" unsigned long __cdecl debug_timeGetTime(char*, int);
extern void __cdecl write_draw_log2(char*);

#endif
