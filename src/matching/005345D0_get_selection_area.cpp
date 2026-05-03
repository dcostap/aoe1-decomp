// 005345D0 get_selection_area (277 bytes)
// PDB: view.cpp (RGE_View::get_selection_area)
// Attempt log:
//   attempt 1: naive natural source with min/max normalize

#include "../../include/game_globals.h"

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[0x4];
    int map_width;           // +0x08
    int map_height;          // +0x0C
};

class RGE_View {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void redraw(int mode);

    char gap_04[0x100];
    RGE_Map* map;            // +0x104
    char gap_108[0x3C];
    int sel_col1;            // +0x144
    int sel_row1;            // +0x148
    int sel_col2;            // +0x14C
    int sel_row2;            // +0x150

    int get_selection_area(long* col1, long* row1, long* col2, long* row2, int normalize);
};

int RGE_View::get_selection_area(long* col1, long* row1, long* col2, long* row2, int normalize)
{
    *col1 = this->sel_col1;
    *row1 = this->sel_row1;
    *col2 = this->sel_col2;
    *row2 = this->sel_row2;

    if (*col1 == -1 && *row1 == -1 && *col2 == -1 && *row2 == -1) {
        return 0;
    }

    if (*col1 < 0) {
        *col1 = 0;
    } else if (*col1 >= this->map->map_width) {
        *col1 = this->map->map_width - 1;
    }

    if (*row1 < 0) {
        *row1 = 0;
    } else if (*row1 >= this->map->map_height) {
        *row1 = this->map->map_height - 1;
    }

    if (*col2 < 0) {
        *col2 = 0;
    } else if (*col2 >= this->map->map_width) {
        *col2 = this->map->map_width - 1;
    }

    if (*row2 < 0) {
        *row2 = 0;
    } else if (*row2 >= this->map->map_height) {
        *row2 = this->map->map_height - 1;
    }

    if (normalize) {
        long c1 = *col1;
        long c2 = *col2;
        long r1 = *row1;
        long r2 = *row2;

        *col1 = (c1 < c2) ? c1 : c2;
        *row1 = (r1 < r2) ? r1 : r2;
        *col2 = (c1 > c2) ? c1 : c2;
        *row2 = (r1 > r2) ? r1 : r2;
    }

    return 1;
}
