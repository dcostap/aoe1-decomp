// VA: 00475CC0, TEditPanel::set_rect, 267 bytes
// Source: pnl_edit.cpp lines 401-421
// FLAGS: default
//
// Attempt log:
// - v1-3: basic class declaration with TPanel base, tagRECT member. Redraw computation
//   used nested if-else which VC5 converts to setne (boolean pattern). 272 bytes.
// - v4: goto-based redraw pattern. VC5 inverts last condition's je to jne.
// - v5: if (cond && cond && cond) redraw=1; else redraw=0. Generates exact same jne/je/je
//   pattern as original for the redraw section. ✓
// - v6-8: various bevel load placements. VC5 always CSE-hoists bevel load before format check.
//   Inline this->bevel_size in each branch still gets hoisted.
//
// What works:
// - Prologue (+0 to +40): matches byte-exact. TPanel::set_rect call, register saves.
// - Redraw (+40 to +112): matches. jne for hidden, je for visible, je for active,
//   mov edx,1 / jmp / xor edx,edx pattern.
// - MoveWindow call sequence matches push order.
//
// Remaining blockers:
// 1. bevel_size load (mov edi,[esi+15Ch]) is hoisted before `cmp eax,7` / `jne` in
//    the format section. Original loads it after the cmp, inside the format check flow.
//    No source-level trick found to prevent this CSE hoisting.
// 2. Instruction scheduling in MultiLine branch: GetSystemMetrics called before render_left
//    load (original calls it after draw_left/draw_top computation). draw_top stored after
//    draw_right calculation (original stores it before).
// 3. Else branch: uses edi for bevel throughout, original uses eax then different regs.
// 4. Function is 272 bytes vs 267 (5 over) due to scheduling differences.
// 5. MoveWindow and GetSystemMetrics calls use reloc-based direct calls (e8 xx xx xx xx)
//    vs original's IAT indirect calls (ff 15 xx xx xx xx). The 1-byte difference per indirect
//    call is masked by relocation system.

#include <stddef.h>

extern "C" void __stdcall MoveWindow(void* hWnd, int X, int Y, int nWidth, int nHeight, int bRepaint);
extern "C" int __stdcall GetSystemMetrics(int nIndex);

class TPanel {
public:
    char gap_00[0x0C];
    int pnl_x;                     // +0x0C
    int pnl_y;                     // +0x10
    int pnl_wid;                   // +0x14
    int pnl_hgt;                   // +0x18
    char gap_1C[0x6C - 0x1C];
    int active;                    // +0x6C
    int visible;                   // +0x70
    char gap_74[0x8C - 0x74];
    int render_left;               // +0x8C
    int render_top;                // +0x90
    int render_right;              // +0x94
    int render_bottom;             // +0x98
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
    int draw_left;                 // +0x134
    int draw_top;                  // +0x138
    int draw_right;                // +0x13C
    int draw_bottom;               // +0x140
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

    if (this->format == 7) {
        int bevel = this->bevel_size;
        this->draw_left = this->render_left + bevel + 1;
        this->draw_top = this->render_top + bevel;
        int scrollbarW = GetSystemMetrics(0x15); // SM_CXVSCROLL
        this->draw_right = this->render_right - bevel - scrollbarW - 1;
        this->draw_bottom = this->render_bottom - bevel;
    } else {
        int bevel = this->bevel_size;
        this->draw_left = this->render_left + bevel + 8;
        this->draw_top = this->render_top + bevel;
        this->draw_right = this->render_right - bevel;
        this->draw_bottom = this->render_bottom - bevel;
    }
}
