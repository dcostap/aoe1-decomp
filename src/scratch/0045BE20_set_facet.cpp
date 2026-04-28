// VA: 0045BE20 TMousePointer::set_facet(int)
// Source: Mouseptr.cpp lines 918-939
// Size: 91 bytes, __thiscall
//
// Attempt log (7 probes):
// Probe 1-3: Struct-based approach, facet in eax instead of edx → 16 diff bytes
// Probe 4: Raw pointer arithmetic — same 16 bytes
// Probe 5: Local idx temp — same 16 bytes
// Probe 6: Proper struct inheritance — same 16 bytes
// Probe 7: Pre-load Cursor_Shape before bounds check — much worse (74 bytes)
//
// Remaining 16 bytes: register allocation — param_1 loaded into eax instead of edx.
// This propagates: eax=idx throughout, edx=Cursor_Shape, esi=shape_info (pushed early)
// vs original: edx=idx, eax=Cursor_Shape→shape_info (reused), esi=pushed late
// All field offsets, loop structure, and control flow are identical.
// Parked in scratch per Boss direction.

struct ShapeInfo {
    int _pad[4];
    int width;       // +0x10
    int height;      // +0x14
    int hotspot_x;   // +0x18
    int hotspot_y;   // +0x1C
};

struct CursorShape {
    char _pad[0x1C];
    ShapeInfo* shape_infos;  // +0x1C
};

class TMousePointer {
public:
    int custom_draw;         // +0x00
    void* render_area;       // +0x04
    void* save_area;         // +0x08
    void* primary_area;      // +0x0C
    int Num_Cursors;         // +0x10
    int Max_Cursors;         // +0x14
    void* cursors[16];       // +0x18
    CursorShape* Cursor_Shape; // +0x58
    int Mouse_Mode;          // +0x5C
    int Max_CX;              // +0x60
    int Max_CY;              // +0x64
    int cWidth;              // +0x68
    int cHeight;             // +0x6C
    int gWidth;              // +0x70
    int gHeight;             // +0x74
    int mouse_x;             // +0x78
    int mouse_y;             // +0x7C
    int save_x;              // +0x80
    int save_y;              // +0x84
    int facet;               // +0x88
    int game_facet;          // +0x8C
    int next_facet;          // +0x90
    int last_facet;          // +0x94
    int d_top;               // +0x98
    int d_left;              // +0x9C
    int d_bottom;            // +0xA0
    int d_right;             // +0xA4

    void set_facet(int f);
};

void TMousePointer::set_facet(int f) {
    if (f < 0 || f >= this->Num_Cursors)
        return;

    this->facet = f;
    ShapeInfo* info = this->Cursor_Shape->shape_infos + f;
    this->cWidth = info->width;
    this->cHeight = info->height;
    this->d_top = info->hotspot_y;
    this->d_left = info->hotspot_x;
    this->d_right = this->cWidth - info->hotspot_x;
    this->d_bottom = this->cHeight - info->hotspot_y;
}
