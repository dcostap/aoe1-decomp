// tried the direct compare/assignment shape first; VC5 still picked a wider register set than the packet
// tried a saved cursor-shape pointer plus a single local index; the body got close but the index still landed in eax instead of edx
// remaining mismatch is the top-of-function index-load / compare basin, not the field writes or arithmetic
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
    int cWidth;
    int cHeight;
    int gWidth;
    int gHeight;
    int mouse_x;
    int mouse_y;
    int save_x;
    int save_y;
    int facet;
    int game_facet;
    int next_facet;
    int last_facet;
    int d_top;
    int d_left;
    int d_bottom;
    int d_right;

    void set_facet(int facet);
};

void TMousePointer::set_facet(int facet) {
    int cursor = facet;
    TShape* shape;
    Shape_Info* info;

    if (cursor < 0 || cursor >= this->Num_Cursors) {
        return;
    }

    shape = this->Cursor_Shape;
    this->facet = cursor;
    info = shape->shape_info + cursor;
    this->cWidth = info->width;
    this->cHeight = info->height;
    this->d_top = info->hotspot_y;
    this->d_left = info->hotspot_x;
    this->d_right = this->cWidth - info->hotspot_x;
    this->d_bottom = this->cHeight - info->hotspot_y;
}
