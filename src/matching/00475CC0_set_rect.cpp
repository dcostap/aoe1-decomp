// VA: 00475CC0, TEditPanel::set_rect, 267 bytes
// Source: pnl_edit.cpp lines 401-421
// FLAGS: default
//
// Attempt log:
// - Baseline natural named-field reconstruction: 273 bytes; prologue, base call,
//   redraw CFG, and arithmetic/call behavior were already aligned.
// - Imported stdcall declarations restored the two original IAT call identities.
// - Materializing format/render_left and using direct named bevel members produced
//   the original format pre-branch load order; modeling draw_rect as tagRECT was
//   layout-canonical but codegen-neutral.
// - Variant lab (8 source-shape combinations) selected direct draw_rect stores with
//   an inline GetSystemMetrics expression: exact size/call set, 47 strict diff bytes.
// - Replacing the preloaded render_left local with direct render_rect.left member
//   expressions restored the original register scheduling and produced an exact match.
//
// What works:
// - Prologue through MoveWindow (+0 to +75): byte-exact, including IAT calls.
// - Format dispatch prefix (+75 to +8C): byte-exact, including delayed bevel load.
// - Function size/frame/CFG/call set match the 267-byte original.
//
// Exactness: 267/267 bytes, 3/3 calls, and 100% positional equality.

#include <stddef.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" __declspec(dllimport) void __stdcall MoveWindow(void* hWnd, int X, int Y, int nWidth, int nHeight, int bRepaint);
extern "C" __declspec(dllimport) int __stdcall GetSystemMetrics(int nIndex);

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x08];
    int pnl_x;                     // +0x0C
    int pnl_y;                     // +0x10
    int pnl_wid;                   // +0x14
    int pnl_hgt;                   // +0x18
    char gap_1C[0x6C - 0x1C];
    int active;                    // +0x6C
    int visible;                   // +0x70
    char gap_74[0x8C - 0x74];
    tagRECT render_rect;            // +0x8C
    char gap_9C[0xF4 - 0x9C];

    void set_rect(int left, int top, int width, int height);
};

class TEditPanel : public TPanel {
public:
    void* edit_wnd;                // +0xF4
    char gap_F8[0x104 - 0xF8];
    int hidden;                    // +0x104
    char gap_108[0x128 - 0x108];
    int format;                    // +0x128
    char gap_12C[0x134 - 0x12C];
    tagRECT draw_rect;             // +0x134
    char gap_144[0x15C - 0x144];
    int bevel_size;                // +0x15C

    void set_rect(int param_1, int param_2, int param_3, int param_4);
};

void TEditPanel::set_rect(int param_1, int param_2, int param_3, int param_4)
{
    TPanel::set_rect(param_1, param_2, param_3, param_4);

    if (this->edit_wnd != 0) {
        int redraw;
        if (this->hidden == 0 && this->visible != 0 && this->active != 0) {
            redraw = 1;
        } else {
            redraw = 0;
        }

        int bevel = this->bevel_size;
        int left = this->pnl_x + bevel;
        int top = this->pnl_y + bevel;
        int width = this->pnl_wid - bevel * 2 - 1;
        int height = this->pnl_hgt - bevel * 2 - 1;
        MoveWindow(this->edit_wnd, left, top, width, height, redraw);
    }

    int format = this->format;
    if (format == 7) {
        this->draw_rect.left = this->render_rect.left + 1 + this->bevel_size;
        this->draw_rect.top = this->render_rect.top + this->bevel_size;
        this->draw_rect.right = this->render_rect.right - this->bevel_size - GetSystemMetrics(0x15) - 1;
        this->draw_rect.bottom = this->render_rect.bottom - this->bevel_size;
    } else {
        this->draw_rect.left = this->render_rect.left + this->bevel_size + 8;
        this->draw_rect.top = this->render_rect.top + this->bevel_size;
        this->draw_rect.right = this->render_rect.right - this->bevel_size;
        this->draw_rect.bottom = this->render_rect.bottom - this->bevel_size;
    }
}
