// 00534530 set_selection_area (157 bytes) — MATCHED
// PDB: view.cpp (RGE_View::set_selection_area)

#include "../../include/game_globals.h"

// RGE_Base_Game stub with only game_mode field
// rge_base_game->game_mode is at +0x1B4
class RGE_Base_Game_Stub {
public:
    char gap_00[0x1B4];
    int game_mode;
};

#ifndef RGE_VIEW_SHARED_CONTEXT
class RGE_Map {
public:
    void request_redraw(int col1, int row1, int col2, int row2, unsigned char flags);
};

class RGE_View {
public:
    virtual ~RGE_View();
    virtual void set_rect(long, long, long, long);
    virtual void set_redraw(int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void release_mouse();
    virtual void set_focus(int);
    virtual void redraw(int mode);

    char gap_04[0x100];
    RGE_Map* map;            // +0x104
    char gap_108[0x3C];
    int sel_col1;            // +0x144
    int sel_row1;            // +0x148
    int sel_col2;            // +0x14C
    int sel_row2;            // +0x150

    void set_selection_area(long col1, long row1, long col2, long row2);
};
#endif

void RGE_View::set_selection_area(long col1, long row1, long col2, long row2)
{
    if (this->map && ((RGE_Base_Game_Stub*)rge_base_game)->game_mode != 0x15) {
        this->map->request_redraw(this->sel_col1, this->sel_row1, this->sel_col2, this->sel_row2, 0);
    }
    this->sel_col1 = col1;
    this->sel_row1 = row1;
    this->sel_col2 = col2;
    this->sel_row2 = row2;
    if (this->map && ((RGE_Base_Game_Stub*)rge_base_game)->game_mode != 0x15) {
        this->map->request_redraw(col1, row1, col2, row2, 0x10);
    }
    this->redraw(1);
}
