// VA: 0047AFD0 TScrollBarPanel::mouse_left_move_action(long, long, int, int)
// PDB source: Pnl_scbr.cpp lines 400-547 (991 bytes, 286 asm lines)
// Default flags.
//
// Attempt log:
// Baseline prior worker: decompiler-shaped field aliases and wrong helper/virtual surfaces; exact size was not
// meaningful because calls/offset ownership were broad. Reconstructed here with the proven TPanel base/vtable,
// canonical scrollbar fields, switch-on-item_down topology, and natural arrow/thumb drag control flow.
// Probe 1: baseline had exact size/prologue but five extra direct scroll sites because the small arrow cases did
// not tail-merge; first structural gap was the switch table/case layout.
// Probe 2: ordered cases 1,2,4,5,3 to follow PDB line order; calls became 19/19 and shape rose to 87.84%, with
// the remaining drift localized to the two thumb-drag arms.
// Probe 3: put delta positivity before the first edge-field loads; 453-byte drift and a smaller body.
// Probe 4: split both edge guards into delta-first nested checks and use x/y >= edge spelling; restored exact size,
// 19 calls, and the best 428-byte mismatch / 86.33% shape.
// Probe 5: reversed the first edge equality operands; only a two-byte neutral change.
// Probes 6-8: current/min locals and a scoped min load moved or left code unchanged; restored probe-4 source.
// Probe 9: separate new_pos locals were compiler-equivalent and left the 428-byte best unchanged.
// Paused: canonical ownership, ABI, switch case order, call set, and behavior are established. Remaining drift is
// localized to VC5 register/field-reload topology in the horizontal/vertical clamp guards and switch-table base;
// further blind variants are not justified without a new donor/source-order lead.
// New worker: natural member compound updates (`tab_x += delta`, `tab_y += delta`) improved the exact-size basin from
// 428 to 320 bytes with 92.39% shape and 81.47% exact-block coverage. Current-position and operand-order variants
// were worse or duplicate; retain the compound-update source as the best plausible candidate. Remaining drift is
// localized to edge/clamp reload/register topology and the extracted switch-table relocation.
// Probe 25: reversed both upper clamp operands to max < updated tab; diff worsened 320 to 321 with lower shape,
// so restored the clean compound-update source.
// Probe 27: reversed both lower clamp operands to min > updated tab; positional diff stayed 320 but shape fell,
// so restored the clean compound-update source. No bound-update spelling improved the first paired hunk.
// Probe 30: used the typed scrollbar edge-event short-circuit form from the original paired blocks; horizontal
// lower-or-upper and vertical lower-else-upper guards improved shape to 93.81% but worsened positional diff to 443.
// Probe 32: isolated the vertical lower-else-upper guard with the clean horizontal guard; diff worsened to 327 and
// shape fell to 91.38%, so restored the clean compound-update source. This branch-layout lead did not beat clean.
// Probe 35: scoped lower-edge min locals in both orientations were compiler-equivalent; the switch-table relocation
// and 320-byte clean result did not move.
// Probe 36: paired scoped min/current locals were also compiler-equivalent; the relocation stayed unchanged.
// Probe 37: added the explicit binary-supported switch default arm; VC5 emitted identical code and relocation.
// Probe 38: carried current/min locals through each orientation while keeping compound updates; this added a stack
// home and worsened the mismatch to 894 bytes, so restored the clean source.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void redraw(int flag); // vtable slot 8 (+20h)

    int is_inside_rect(long x, long y, tagRECT* rect);

    char gap_04[0xF0]; // TPanel ends at +0xF4
};

class TScrollBarPanel : public TPanel {
public:
    char gap_F4[4];
    long list_len;              // +0xF8
    char gap_FC[0x124 - 0xFC];
    long tab_y;                 // +0x124
    long tab_min_y;             // +0x128
    long tab_max_y;             // +0x12C
    long tab_mouse_y;           // +0x130
    long tab_x;                 // +0x134
    long tab_min_x;             // +0x138
    long tab_max_x;             // +0x13C
    long tab_mouse_x;           // +0x140
    unsigned char item_down;    // +0x144
    char gap_145[3];
    int item_is_down;           // +0x148
    long item_x;                // +0x14C
    long item_y;                // +0x150
    unsigned char item_mode;    // +0x154
    char gap_155[3];
    unsigned long item_last_time; // +0x158
    char gap_15C[8];
    tagRECT up_rect;            // +0x164
    tagRECT down_rect;          // +0x174
    tagRECT tab_rect;           // +0x184
    tagRECT top_rect;           // +0x194
    tagRECT bottom_rect;        // +0x1A4
    long orientationValue;      // +0x1B4 (1 = horizontal)

    void scroll(int action, long param);
    void calc_item_rects();
    virtual long mouse_left_move_action(long x, long y, int key, int flags);
};

long TScrollBarPanel::mouse_left_move_action(long x, long y, int key, int flags)
{
    int delta;
    long value;

    switch (this->item_down) {
    case 1:
        if (this->is_inside_rect(x, y, &this->up_rect)) {
            if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("Pnl_scbr.cpp", 0x19A);
                this->scroll(0, 0);
                this->redraw(1);
            }
        } else if (this->item_is_down != 0) {
            this->item_is_down = 0;
            this->item_mode = 0;
            this->redraw(1);
        }
        break;

    case 2:
        if (this->is_inside_rect(x, y, &this->down_rect)) {
            if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("Pnl_scbr.cpp", 0x1AD);
                this->scroll(1, 0);
                this->redraw(1);
            }
        } else if (this->item_is_down != 0) {
            this->item_is_down = 0;
            this->item_mode = 0;
            this->redraw(1);
        }
        break;

    case 4:
        if (this->is_inside_rect(x, y, &this->top_rect)) {
            if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("Pnl_scbr.cpp", 0x1C0);
                this->scroll(2, 0);
                this->redraw(1);
            }
        } else if (this->item_is_down != 0) {
            this->item_is_down = 0;
            this->item_mode = 0;
            this->redraw(1);
        }
        break;

    case 5:
        if (this->is_inside_rect(x, y, &this->bottom_rect)) {
            if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("Pnl_scbr.cpp", 0x1D3);
                this->scroll(3, 0);
                this->redraw(1);
            }
        } else if (this->item_is_down != 0) {
            this->item_is_down = 0;
            this->item_mode = 0;
            this->redraw(1);
        }
        break;

    case 3:
        if (this->orientationValue == 1) {
            delta = x - this->item_x;
            if (delta > 0) {
                if ((this->tab_x == this->tab_min_x) &&
                    (x < this->tab_mouse_x + this->tab_x)) {
                    delta = 0;
                }
            }
            if (this->tab_x == this->tab_max_x) {
                if ((delta < 0) && (x >= this->tab_mouse_x + this->tab_x)) {
                    delta = 0;
                }
            }
            if (delta != 0) {
                this->tab_x += delta;
                if (this->tab_x < this->tab_min_x) {
                    this->tab_x = this->tab_min_x;
                } else if (this->tab_x > this->tab_max_x) {
                    this->tab_x = this->tab_max_x;
                }
                this->calc_item_rects();
                this->redraw(1);
                if (this->tab_min_x == this->tab_max_x) {
                    value = 0;
                } else {
                    value = ((this->tab_x - this->tab_min_x) * this->list_len) /
                            (this->tab_max_x - this->tab_min_x);
                    if (value < 0) {
                        value = 0;
                    } else {
                        long max_value = this->list_len - 1;
                        if (max_value < value) {
                            value = max_value;
                        }
                    }
                }
                this->scroll(4, value);
            }
        } else {
            delta = y;
            delta -= this->item_y;
            if (delta > 0) {
                if ((this->tab_y == this->tab_min_y) &&
                    (y < this->tab_mouse_y + this->tab_y)) {
                    delta = 0;
                }
            }
            if (this->tab_y == this->tab_max_y) {
                if ((delta < 0) && (y >= this->tab_mouse_y + this->tab_y)) {
                    delta = 0;
                }
            }
            if (delta != 0) {
                this->tab_y += delta;
                if (this->tab_y < this->tab_min_y) {
                    this->tab_y = this->tab_min_y;
                } else if (this->tab_y > this->tab_max_y) {
                    this->tab_y = this->tab_max_y;
                }
                this->calc_item_rects();
                this->redraw(1);
                if (this->tab_min_y == this->tab_max_y) {
                    value = 0;
                } else {
                    value = ((this->tab_y - this->tab_min_y) * this->list_len) /
                            (this->tab_max_y - this->tab_min_y);
                    if (value < 0) {
                        value = 0;
                    } else {
                        long max_value = this->list_len - 1;
                        if (max_value < value) {
                            value = max_value;
                        }
                    }
                }
                this->scroll(4, value);
            }
        }
        break;
    }

    if (this->item_down != 0) {
        this->item_x = x;
        this->item_y = y;
    }
    return 0;
}
