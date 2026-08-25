// 0047E110 TTextPanel::delete_line
// Baseline reconstruction: remove one linked-list text node, update the line
// counters, and refresh the panel. The list/node offsets are binary-proven.
// Attempt log:
// - Baseline natural bounded list removal: size/calls/frame matched, but VC5
//   loaded the parameter after saving this and strength-reduced the index loop.
// - Register-qualified parameter, split guards, function-scope locals, an
//   explicit index copy, and a shared fail label all emitted the same basin.
// - Natural-source variant lab (54 variants; size/frame/call-set gated) found
//   no exact group; full proven TPanel/TTextPanel layout also emitted the same
//   code. A while-loop and const-parameter loop probe were unchanged.
// - Explicit line decrement forms, long/function-scope loop locals, derived-
//   dtor/CRT-header context, and a four-variant limit-local lab stayed in the
//   same countdown basin. The flag lab found no usable flag lead.
// - Fresh bounded pass: short induction was the only prologue-closing lead,
//   but its required sign-extension added bytes; short+decrement was best at
//   139 bytes (205-byte target, rebuilt 208). Restored the natural int counter.
// - Fresh replacement pass: a guarded do-while reached 142 bytes with the
//   correct parameter-before-save prologue; a pretested do-while reached 134
//   bytes and reproduced the original count-up body, but VC5 emitted a zero
//   test at loop entry and an extra bottom compare. Reversed operands,
//   explicit condition labels, function-scope assignment, and a named bound
//   did not improve it. Restored the clean natural linked-list traversal.
// - Fresh count-up probes (less-than condition, explicit line decrement,
//   unsigned dword counter, and natural loop variants) either stayed in the
//   countdown basin or lost the exact prologue; the short-counter lead added
//   a required sign extension. A natural loop-shape lab confirmed no other
//   invariant-eligible form was exact.
// - Mirroring the same-TU get_line donor's while (true) / equality-break
//   traversal, with the binary-proven --line before it, reproduced the
//   original parameter load, count-up loop, and all 205 bytes exactly.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" void __cdecl free(void* block);

#ifndef PNL_TXT_TU_CONTEXT
struct PanelNode;
struct tagRECT;

class TDrawArea {
public:
    HDC GetDc(char* unused);
    void ReleaseDc(char* unused);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int clear);
    virtual void draw_finish();
    virtual void draw();

    TPanel* previous_panel;              // +0x04
    TPanel* previous_modal_panel;         // +0x08
    long pnl_x;                           // +0x0C
    long pnl_y;                           // +0x10
    long pnl_wid;                         // +0x14
    long pnl_hgt;                         // +0x18
    char* panel_name;                     // +0x1C
    TDrawArea* render_area;               // +0x20
    long clip_left;                       // +0x24
    long clip_top;                        // +0x28
    long clip_right;                      // +0x2C
    long clip_bottom;                     // +0x30
    int position_mode;                    // +0x34
    int need_redraw;                      // +0x38
    TPanel* curr_child;                   // +0x3C
    TPanel* parent_panel;                 // +0x40
    TPanel* left_panel;                   // +0x44
    TPanel* top_panel;                    // +0x48
    TPanel* right_panel;                  // +0x4C
    TPanel* bottom_panel;                 // +0x50
    PanelNode* node;                      // +0x54
    PanelNode* first_child_node;          // +0x58
    PanelNode* last_child_node;           // +0x5C
    TPanel* tab_prev_panel;               // +0x60
    TPanel* tab_next_panel;               // +0x64
    int mouse_captured;                   // +0x68
    int active;                           // +0x6C
    int visible;                          // +0x70
    int tab_stop;                         // +0x74
    int have_focus;                       // +0x78
    int overlapping_children;             // +0x7C
    int handle_mouse_input;               // +0x80
    int just_drawn;                       // +0x84
    void* clip_rgn;                       // +0x88
    char gap_8C[0x68];                    // +0x8C
};

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

struct TextNode {
    char* text;
    char* text2;
    long id;
    TextNode* next_node;
};

class TTextPanel : public TPanel {
public:
    virtual void draw();
    TextNode* list;                       // +0xF4
    short num_lines;                      // +0xF8
    short draw_lines;                     // +0xFA
    short top_line;                       // +0xFC
    short bot_line;                       // +0xFE
    short cur_line;                       // +0x100
    short cur_col;                        // +0x102
    void* font;                           // +0x104
    long font_wid;                        // +0x108
    long font_hgt;                        // +0x10C
    int vert_align;                       // +0x110
    int horz_align;                       // +0x114
    int word_wrap;                        // +0x118
    int text_style;                       // +0x11C
    unsigned long text_color1;            // +0x120
    unsigned long text_color2;            // +0x124
    unsigned long highlight_text_color1;  // +0x128
    unsigned long highlight_text_color2;  // +0x12C
    void* scbar_panel;                    // +0x130
    int auto_scbar;                       // +0x134
    short fixed_len;                      // +0x138
    short gap_13A;                        // +0x13A
    long text_wid;                        // +0x13C
    long text_hgt;                        // +0x140
    void* back_pic;                       // +0x144
    short back_pic_wid;                   // +0x148
    short back_pic_hgt;                   // +0x14A
    int fill_back;                        // +0x14C
    unsigned char back_color;             // +0x150
    char gap_151[0x03];                   // +0x151
    int outline;                          // +0x154
    unsigned char outline_color;          // +0x158
    char gap_159[0x03];                   // +0x159
    int sorted;                           // +0x15C
    long second_column_pos;               // +0x160
    long full_width;                      // +0x164
    long scbar_width;                     // +0x168
    int scbar_active;                     // +0x16C
    int bevel_type;                       // +0x170
    unsigned char bevel_color1;           // +0x174
    unsigned char bevel_color2;           // +0x175
    unsigned char bevel_color3;           // +0x176
    unsigned char bevel_color4;           // +0x177
    unsigned char bevel_color5;           // +0x178
    unsigned char bevel_color6;           // +0x179
    char gap_17A[0x02];                   // +0x17A
    void* clip_rgn2;                      // +0x17C
    int border_size;                      // +0x180
    int spacer_size;                      // +0x184

    void calc_draw_info(int);
    int delete_line(long line);
};
#endif

int TTextPanel::delete_line(long line)
{
    if (line >= 0 && line <= this->num_lines - 1) {
        TextNode* deleted;

        if (line == 0) {
            deleted = this->list;
            this->list = deleted->next_node;
        } else {
            TextNode* node = this->list;
            int i = 0;
            --line;
            while (true) {
                if (i == line) {
                    break;
                }
                node = node->next_node;
                ++i;
            }
            deleted = node->next_node;
            node->next_node = deleted->next_node;
        }

        if (deleted != 0) {
            if (deleted->text != 0) {
                free(deleted->text);
            }
            if (deleted->text2 != 0) {
                free(deleted->text2);
            }
            free(deleted);
            --this->num_lines;

            short count = this->num_lines;
            if (count == 0) {
                this->cur_line = 0;
            } else if (this->cur_line >= count) {
                this->cur_line = count - 1;
            }

            this->calc_draw_info(1);
            this->set_redraw(1);
            return 1;
        }
    }
    return 0;
}
