// 0047B8B0 TScrollBarPanel::draw_back_pic
// Source: Pnl_scbr.cpp lines 765-799, size 180 bytes
// Attempt log:
// first: 176 bytes (4 short). Non-virtual TShape methods, direct calls.
// second: precomputed temps didn't change register allocation.
// third: inline function args, back_frame local var — same result.
// fourth: mark base offset fields volatile to force call-argument evaluation order; worsened scheduling (180B but 15.6% diff), rolled back.
// fifth: field-first add expressions; no change from best 176B family.
// sixth: explicit x/y locals immediately before shape_draw; optimized away/no change.
// seventh: local shape pointer for draw call; no change.
// eighth-tenth: /Ob0, /O2-no-/Oy, /O1 flag probes; no improvement (/O1 153B), flags removed.
// eleventh: volatile cast on both coordinate member reads; worsened to 15.6%.
// twelfth: volatile cast only on x/base field_10; worsened early branch distances.
// thirteenth: volatile cast only on y/base field_0C; worsened early branch distances.
// GIVEUP: best source is 176B, 4 bytes shorter than original. Remaining issue is localized inner-loop register allocation/eval scheduling.
//   Original computes x as mov eax,[esi+10h]; mov ecx,ebx; add ecx,eax and y as mov ecx,[esi+0Ch]; mov edx,edi; add edx,ecx.
//   VC5 rebuild folds to mov ecx,[esi+10h]; add ecx,ebx and mov edx,[esi+0Ch]; add edx,edi.
//   Behavior is equivalent, but check_function cannot compare because the function is 4 bytes short; not proposing accepted_drift without a comparable 180B low-diff build.
// Retry 2026-05-26 Boss pass: 13 more probes. Revalidated best source: 176B too short.
// Tried reversed coordinate expression order, explicit x/y locals, staged xbase/ybase adds,
// volatile xbase and ybase, draw_area/frame locals, shape local, while loops, for loops,
// swapped semantic draw args, back_frame local, void/uchar TShape return declarations, and
// flags /Ob0 /Oa /Og. All exact-size variants were broad regressions (best volatile-xbase
// 62 positional / 37 edit, first mismatch +19); all close variants stayed 176B. Still no
// accepted_drift proposal: the behavior-equivalent diff is localized, but the best source is
// short/truncated and exact-size variants are not localized.
// Luna47B8B0 baseline: natural nested inclusive tiling source is 176B; all calls/fields/CFG align,
// but VC5 folds each base-plus-cursor add into a memory-destination form.
// ABI probes: corrected TShape return/reference/parameter types and TDrawArea*; relocation symbols now match,
// with no codegen movement. Offset-first terms, coordinate locals, and a canonical TPanel base were duplicates.
// Volatile coordinate rereads reached exact size and 28-byte positional drift, but changed scheduling broadly;
// rolled back as diagnostic-only. Raw probes of one-sided volatility, long cursors, comma sequencing, and swaps
// did not produce the original order. Keep the ordinary source reconstruction, not the compiler-steering variant.
// probe Luna-002: restored the same inherited virtual surface used by exact Pnl_scbr.cpp
// draw donors; it emitted the unchanged 176-byte basin.
// probe Luna-003: use the proven full 0x20-byte TShape data surface and pointer ABI for
// shape_minmax, testing canonical declaration/layout context at the call site.
// probe Luna-004: declaration-only defaults for shape_draw's two zero arguments are
// tested next; this is a period-plausible call-site spelling, not a fake helper.
// probe Luna-005: register-qualified coordinate temporaries emitted the unchanged
// 176-byte basin; restored the direct call for the next layout probe.
// probe Luna-006: model the proven full 0xF4-byte TPanel base and derived size while
// retaining named ownership for all fields touched by this function.

// probe Luna-001: materialized back_frame immediately before shape_draw; VC5 optimized
// the local away and emitted the unchanged 176-byte basin; restored the clean source.

// Luna-001 result: materialized back_frame was optimized away; unchanged 176-byte basin.
// Luna-002 result: restored inherited Pnl_scbr donor virtual surface; unchanged basin.
// Luna-003 result: full TShape layout and pointer shape_minmax ABI; unchanged code and
// corrected the direct-call symbol to the proven pointer signature.
// Luna-004 result: shape_draw default arguments for the two zero tail values; unchanged.
// Luna-005 result: register-qualified coordinate temporaries; unchanged.
// Luna-006 result: full proven TPanel/TScrollBarPanel layout; unchanged.
// Luna-007 result: natural call-form and coordinate-axis labs collapsed to the same
// 176-byte basin. Volatile-both reached 180 bytes/28 positional diff bytes but moved
// scheduling broadly; diagnostic-only. Current blocker is the original cursor-copy/add
// setup with delayed base loads across constant pushes; no plausible non-volatile axis remains.

class TDrawArea;

struct TShape {
    unsigned char* shape_data;
    int load_type;
    int load_size;
    void* shape_header;
    void* head;
    void* offsets;
    void* fshape;
    void* shape_info;

    unsigned char shape_minmax(long* y_max, long* pic_hgt, long* x_min, long* y_min, long frame);
    unsigned char shape_draw(TDrawArea* draw_area, long x, long y, long frame,
                             unsigned char color_flag, unsigned char* color_table);
};

class TPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void enterCS(int unk);
    virtual void leaveCS();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void draw_rect(void* rect);
    void* previousPanelValue;       // +0x04
    void* previousModalPanelValue;  // +0x08
    long field_0C;                  // +0x0C (base x offset)
    long field_10;                  // +0x10 (base y offset)
    long field_14;                  // +0x14 (inner loop bound)
    long field_18;                  // +0x18 (outer loop bound)
    char* panelNameValue;           // +0x1C
    TDrawArea* field_20;            // +0x20 (draw area pointer)
    char clip_rect[0x10];           // +0x24
    long position_mode;             // +0x34
    long need_redraw;               // +0x38
    void* curr_child;               // +0x3C
    void* parent_panel;             // +0x40
    void* left_panel;               // +0x44
    void* top_panel;                // +0x48
    void* right_panel;              // +0x4C
    void* bottom_panel;             // +0x50
    void* node;                      // +0x54
    void* first_child_node;          // +0x58
    void* last_child_node;           // +0x5C
    void* tab_prev_panel;            // +0x60
    void* tab_next_panel;            // +0x64
    long mouse_captured;             // +0x68
    long active;                     // +0x6C
    long visible;                    // +0x70
    long tab_stop;                   // +0x74
    long have_focus;                 // +0x78
    long overlapping_children;       // +0x7C
    long handle_mouse_input;         // +0x80
    long just_drawn;                 // +0x84
    void* clip_rgn;                  // +0x88
    char render_rect[0x10];           // +0x8C
    long left_border;                // +0x9C
    long top_border;                 // +0xA0
    long right_border;               // +0xA4
    long bottom_border;              // +0xA8
    long min_wid;                    // +0xAC
    long max_wid;                    // +0xB0
    long min_hgt;                    // +0xB4
    long max_hgt;                    // +0xB8
    long mouse_hold_interval;        // +0xBC
    long mouse_move_tolerance;       // +0xC0
    long mouse_down_x;               // +0xC4
    long mouse_down_y;               // +0xC8
    long mouse_down_ctrl;            // +0xCC
    long mouse_down_shift;           // +0xD0
    unsigned long mouse_down_time;   // +0xD4
    long error_code;                 // +0xD8
    long z_order;                    // +0xDC
    long display_changed_count;      // +0xE0
    long help_string_id;             // +0xE4
    long help_page_id;               // +0xE8
    unsigned char mouse_action;      // +0xEC
    unsigned char mouse_down_button; // +0xED
    unsigned char panel_type;        // +0xEE
    unsigned char color;             // +0xEF
    unsigned char fill_in_background;// +0xF0
    unsigned char clip_to_parent;    // +0xF1
    unsigned char draw_rect2_flag;   // +0xF2
    unsigned char need_restore;      // +0xF3
};

class TScrollBarPanel : public TPanel {
    char gap_F4[0x14];       // +0xF4 to +0x107
    TShape* button_pics;     // +0x108
    int back_frame;          // +0x10C
    char gap_110[0xB4];       // +0x110 to +0x1C3

protected:
    virtual void draw();
    void draw_back_pic();
};

void TScrollBarPanel::draw_back_pic() {
    if (this->button_pics != 0 && this->back_frame != -1) {
        long x_min, y_max, pic_hgt, y_min;
        this->button_pics->shape_minmax(&y_max, &pic_hgt, &x_min, &y_min, this->back_frame);

        int row_step = (x_min - y_max) + 1;
        int col_step = (y_min - pic_hgt) + 1;
        int outer = 0;

        if (this->field_18 >= 0) {
            do {
                int inner = 0;
                if (this->field_14 >= 0) {
                    do {
                        this->button_pics->shape_draw(
                            this->field_20,
                            this->field_0C + inner,
                            this->field_10 + outer,
                            this->back_frame, 0, 0);
                        inner += row_step;
                    } while (inner <= this->field_14);
                }
                outer += col_step;
            } while (outer <= this->field_18);
        }
    }
}
