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
// Earlier gap: the first natural forms were 384 bytes and read param_2 after
// the frame setup. The current best is full size with 46 strict diff bytes.

// Current normal-source pass:
// - one function-scope tagRECT recovered the 0x10 frame and stack homes;
//   strict diff improved from 368 to 299 bytes.
// - compound self-subtraction for the left and top fields reproduced the
//   original subtract-to-zero code and reached 387 bytes / 53 diff bytes.
// - direct p2 guards, declaration placement, and a nested local scope were
//   codegen duplicates. Reversed saved top/bottom assignment was restored.
// - reversing the source top/bottom update order matched the original register
//   pair and reduced the best result to 46 diff bytes.
// - paused: calls, frame, size, CFG, and most body blocks match. Remaining drift
//   is prologue scheduling, early area-register coloring, one delayed store,
//   and equivalent call-setup register coloring.

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
    if (p2 == 0)
        p2 = this->render_area;

    this->cur_render_area = p2;

    {
        tagRECT save_render_rect;
        if (p2 == this->save_area1) {
        save_render_rect.left = this->render_rect.left;
        save_render_rect.right = this->render_rect.right;
        save_render_rect.top = this->render_rect.top;
        save_render_rect.bottom = this->render_rect.bottom;

        this->render_rect.left -= save_render_rect.left;
        this->render_rect.right -= save_render_rect.left;
        this->start_scr_col -= (short)save_render_rect.left;
        this->start_scr_row -= (short)save_render_rect.top;
        this->render_rect.bottom -= save_render_rect.top;
        this->render_rect.top -= save_render_rect.top;
        this->map_scr_x_offset += save_render_rect.left;
        this->map_scr_y_offset += save_render_rect.top;
    }
    if (this->cur_render_area->Lock("view::draw_view", 1)) {
        if (p1 == 10) {
            tagRECT rect;
            rect.left = save_render_rect.left;
            rect.top = save_render_rect.top;
            rect.right = save_render_rect.right;
            rect.bottom = save_render_rect.bottom;
            this->view_function_terrain(10, rect);
        } else {
            this->view_function(p1, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        this->cur_render_area->Unlock("view::draw_view");
    }
    if (this->cur_render_area == this->save_area1) {
        this->start_scr_col += (short)save_render_rect.left;
        this->start_scr_row += (short)save_render_rect.top;
        this->render_rect.right += save_render_rect.left;
        this->render_rect.bottom += save_render_rect.top;
        this->render_rect.left += save_render_rect.left;
        this->render_rect.top += save_render_rect.top;
        this->map_scr_x_offset -= save_render_rect.left;
        this->map_scr_y_offset -= save_render_rect.top;
        }
    }
    this->cur_render_area = 0;
}
