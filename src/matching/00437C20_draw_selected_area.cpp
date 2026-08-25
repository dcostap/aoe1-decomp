// RGE_Diamond_Map::draw_selected_area
// VA: 00437C20
// diam_map.cpp:897-917
// 147 bytes, protected virtual, vt[56] (0xE0)
//
// Fields: +0x20 render_area (TDrawArea*), +0x150 main_view (RGE_View*)

#ifndef DIAM_MAP_CONTEXT_H
#include "../../include/game_globals.h"
#endif

#ifndef DIAM_MAP_CONTEXT_H
class TDrawArea;
#endif
class RGE_View;

// TDrawArea methods (__thiscall)
struct FakeTDrawArea {
    void* Lock(char* name, int flag);
    void  Unlock(char* name);
};

// RGE_View::get_selection_area (__thiscall)
struct FakeRGEView {
    int get_selection_area(long* p1, long* p2, long* p3, long* p4, int flag);
};

#ifndef DIAM_MAP_CONTEXT_H
class RGE_Diamond_Map {
public:
    char gap_00[0x20];
    TDrawArea* render_area;    // +0x20
    char gap_24[0x150 - 0x24];
    RGE_View* main_view;       // +0x150

    void draw_selected_area(void);
    void draw_tile(short x, short y, int param_3, unsigned char param_4);
};
#endif

void RGE_Diamond_Map::draw_selected_area(void) {
    if (this->main_view == 0)
        return;

    long x1, y1, x2, y2;
    if (!((FakeRGEView*)this->main_view)->get_selection_area(&x1, &y1, &x2, &y2, 1))
        return;

    if (!((FakeTDrawArea*)this->render_area)->Lock("diam_map::draw_selected_area", 1))
        return;

    int y;
    for (y = y1; y <= y2; y++) {
        int x;
        for (x = x1; x <= x2; x++) {
            draw_tile((short)x, (short)y, 1, 0);
        }
    }

    ((FakeTDrawArea*)this->render_area)->Unlock("diam_map::draw_selected_area");
}
