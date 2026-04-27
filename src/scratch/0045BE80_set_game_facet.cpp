// tried the direct field-write shape first; it matches the instruction but VC5 keeps picking the wrong prolog/register basin
// tried direct repeated member access; that widened the prolog and moved the first mismatch earlier
// tried a donor-style sibling set_facet in the same TU; that poisoned extraction, so it was removed
// leaving this in scratch because the remaining gap is still prolog/register allocation drift, not a behavior question
#include "..\..\include\game_types.h"

class Shape_Info {
public:
    char pad_00[0x10];
    int width;
    int height;
    int hotspot_x;
    int hotspot_y;
};

class TShape {
public:
    char pad_00[0x1C];
    Shape_Info* shape_info;
};

class TMousePointer {
public:
    int custom_draw;
    void* render_area;
    void* save_area;
    void* primary_area;
    int Num_Cursors;
    int Max_Cursors;
    void* cursors[16];
    TShape* Cursor_Shape;
    int Mouse_Mode;
    int Max_CX;
    int Max_CY;
    int gWidth;
    int gHeight;
    long mouse_x;
    long mouse_y;
    long save_x;
    long save_y;
    int facet;
    int game_facet;
    int next_facet;
    int last_facet;
    int d_top;
    int d_left;
    int d_bottom;
    int d_right;
    int g_top;
    int g_left;
    int g_bottom;
    int g_right;

    void set_game_facet(int facet);
};

void TMousePointer::set_game_facet(int facet) {
    if (facet < 0 || facet >= this->Num_Cursors) {
        return;
    }

    Shape_Info* info;
    info = this->Cursor_Shape->shape_info;
    info += facet;

    this->game_facet = facet;
    this->gWidth = info->width;
    this->gHeight = info->height;
    this->g_top = info->hotspot_y;
    this->g_left = info->hotspot_x;
    this->g_right = this->gWidth - info->hotspot_x;
    this->g_bottom = this->gHeight - info->hotspot_y;
}
