// VA: 00535480
// PDB: view.cpp lines 1993-2056
// RGE_View::draw_view(unsigned char param_1, TDrawArea* param_2)

// Attempt log:
// - version 1: tagRECT sr + int l4 locals, separate Lock call from cur_render_area 
//   -> 384 bytes vs 387, prologue reads param after sub esp (not before)
// - version 2: separate int locals (a,c,d,e) 
//   -> reg allocation changed, similar mismatch
// - version 3: 5th local tmpR to force spill of right value
//   -> no improvement, still 384 bytes
// - version 4: inline member function (inside class body)
//   -> no .text section emitted (inlined)
// - version 5: else-branch with uninitialized locals mirroring original pattern
//   -> compiler warns+zeroes uninitialized reads, breaking the pattern
// - version 6: Ghidra-decompiler-style mapping (sr.top=left, sr.bottom=right, sr.right=top)
//   -> variant lab G0000 (rect_sr+da_yes): 384 bytes, edit diff=159
// - version 7: variant lab with int locals + tmpR + da/no-da variants
//   -> all 384 bytes, closest is G0000 with sub esp,10h prologue but xor eax,eax vs test eax,eax
// - variant lab with --flag-preset vc5-debug-context
//   -> no change in any variant
// 
// Remaining gap:
// Original: 387 bytes. Rebuilt: 384 bytes (3 bytes short).
// Prologue: original reads param_2 from [esp+8] BEFORE sub esp,10h.
//           rebuilt allocates sub esp,10h first then reads param from adjusted stack.
// This appears to be a VC5 scheduling choice that our source cannot override
// without inline asm or a specific TU context from view.cpp.
// The 3-byte difference = the original's `mov eax,[esp+8]` (4 bytes) + 
// `test eax,eax` (2 bytes) = 6 bytes vs rebuilt's `sub esp,10h` (3 bytes) first,
// so the original interleaves the param read into the prologue before sub.
// All flag presets tested produce the same prologue scheduling.
// 
// Register allocation also differs: original uses ebx=left, edi=top, ebp=bottom,
// eax=right (spilled to [esp+0x18]). Rebuilt uses different regs.

#include <windows.h>

class TDrawArea {
public:
    char gap_00[0x3C];
    void* DrawSurface;
    unsigned char* Lock(char*, int);
    void Unlock(char*);
};

class RGE_View {
public:
    char gap_00[0x20];
    TDrawArea* render_area;
    char gap_24[0x68];
    tagRECT render_rect;
    char gap_9C[0x58];
    TDrawArea* cur_render_area;
    char gap_F8[0x2E];
    short start_scr_col;
    short start_scr_row;
    char gap_12A[0x6];
    int map_scr_x_offset;
    int map_scr_y_offset;
    char gap_138[0x324 - 0x138];
    TDrawArea* save_area1;

    void draw_view(unsigned char p1, TDrawArea* p2);
    long view_function_terrain(unsigned char, tagRECT);
    long view_function(unsigned char, unsigned char, void*, void*, void*, void*, void*, void*, void*);
};

void RGE_View::draw_view(unsigned char p1, TDrawArea* p2)
{
    int l4;
    int tp;
    int bt;
    int rt;
    int lf;

    if (p2 == 0)
        p2 = this->render_area;
    this->cur_render_area = p2;
    if (this->cur_render_area == this->save_area1) {
        tp = this->render_rect.left;
        bt = this->render_rect.right;
        rt = this->render_rect.top;
        l4 = this->render_rect.bottom;

        this->render_rect.left = 0;
        this->render_rect.right -= tp;
        this->start_scr_col -= (short)tp;
        this->start_scr_row -= (short)rt;
        this->render_rect.top = 0;
        this->render_rect.bottom -= rt;
        this->map_scr_x_offset += tp;
        this->map_scr_y_offset += rt;
    }
    if (this->cur_render_area->Lock("view::draw_view", 1)) {
        if (p1 == 10) {
            tagRECT rect;
            rect.left = tp;
            rect.top = rt;
            rect.right = bt;
            rect.bottom = l4;
            this->view_function_terrain(10, rect);
        } else {
            this->view_function(p1, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        this->cur_render_area->Unlock("view::draw_view");
    }
    if (this->cur_render_area == this->save_area1) {
        this->start_scr_col += (short)tp;
        this->start_scr_row += (short)rt;
        this->render_rect.right += tp;
        this->render_rect.bottom += rt;
        this->render_rect.left += tp;
        this->render_rect.top += rt;
        this->map_scr_x_offset -= tp;
        this->map_scr_y_offset -= rt;
    }
    this->cur_render_area = 0;
}
