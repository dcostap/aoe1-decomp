#ifndef AOE1_VW_DIMAP_H
#define AOE1_VW_DIMAP_H

#include "diam_map.h"

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    virtual ~RGE_Diamond_Map_View();
    RGE_Diamond_Map_View();

    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual void draw();

    virtual int command_make_do(long, long);
    virtual int command_make_move(long, long);
    virtual int command_make_work(long, long);

    int capture_mouse();
    int right_click2(long, long);
};

typedef char vw_dimap_view_size_check[
    (sizeof(RGE_Diamond_Map_View) == 0x16C) ? 1 : -1];

extern int allow_user_commands;
extern float FLOAT_005777e8;

#endif
