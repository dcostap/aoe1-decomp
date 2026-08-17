// 004754C0 TDropDownButtonPanel::handle_mouse_move
// Attempt log:
// - baseline: the previous file was only an empty Stub_004754C0 definition.
// - reconstructed the period dropdown-button forwarding path from the original
//   virtual slots and the TPanel/TButtonPanel field ownership evidence.
// - second list-panel forwarding is also a mouse-down dispatch; separate
//   width/xPosition temporaries reproduce the original call order and frame.
// - probes of direct versus local child pointers, arithmetic spellings,
//   named argument copies, and named child types were codegen duplicates.
// - inline width/xPosition, receiver-local, arithmetic-parenthesization, and
//   inherited TPanel-base-call probes were also duplicates or structurally worse.
// - canonical TListPanel->TTextPanel ownership and the int/long width ABI
//   variants do not affect the remaining final-call scheduling hunk.
// - focused final-dispatch variant lab (direct/base cast/named x/split x/local
//   receiver) collapsed to one 253-byte group; no variant changed the hunk.
// - fresh TU lane confirmed the period TPanel/TTextPanel/TListPanel ownership
//   and virtual mouse ABI from the class/type dumps and Pnl_drop donors.
// - width - 1 + x, x + width - 1, top-level locals, complete TListPanel size,
//   TPanel receiver casts, Windows header context, register locals, and a
//   scoped result local all emitted the same bytes as the clean candidate.
// - direct xPosition()+width() evaluation was structurally worse (263 bytes);
//   reversing the width/x local declaration order selected the original LEA SIB
//   encoding but left the same 15-byte shifted push/LEA schedule, so it was
//   restored. Named coordinate/receiver/param3 forms were duplicates.
// - focused 16-variant declaration/expression lab and 10-variant param3-cast
//   lab preserved size/frame/call-set but collapsed to two nonexact 253-byte
//   groups; neither delayed the final param3 push. Clean source remains best.
// - reverse local-order plus receiver/parameter lifetime labs isolated a
//   diagnostic lead: reverse declarations select the oracle LEA SIB bytes,
//   but VC5 still pushes param3 before the receiver load/arithmetic; receiver
//   aliases instead color the drop pointer into ESI and worsen the prefix.
// - TTextPanel/TListPanel field surfaces, alternate final expressions,
//   parameter ABI widths, and narrow volatile/address aliases all collapsed
//   back to the same 253-byte group; no source-plausible form delayed that
//   push. Restore the natural typed candidate after each lab.
// - best natural reconstruction: 253 bytes, all 9 calls/CFG/frame aligned;
//   remaining 15 bytes are only final-call scheduling/SIB operand order.
// - fresh pass: exact Pnl_drop and panel ABI donors confirm the same typed
//   TPanel/TListPanel ownership and vslot calls; the first mismatch stays at
//   +00C8 (LEA versus the rebuilt param3 push). No new source-plausible lead
//   remains without repeating prior receiver, local-order, or ABI probes.
// - reassessed exact Panel.cpp width/xPosition donors: int/non-const method
//   declarations and int result locals were codegen duplicates; restored the
//   period PDB long/const ABI.
// - restored the six PDB-proven TListPanel data fields after TTextPanel; this
//   layout correction is codegen-neutral and keeps the local model canonical.
// - fresh worker probes of a post-arithmetic list-panel receiver local, a named
//   right-edge temporary, and an inline arithmetic helper were codegen
//   duplicates; restored the pinned natural source after each test.
// - fresh worker lab tested 12 natural edge-expression spellings across 64
//   neutral file-scope declaration contexts (768 variants); every variant
//   stayed in the same 253-byte group with the +00C8 scheduling mismatch.
// - fresh worker probes of top-level parameter const qualifiers, inherited
//   TListPanel mouse virtuals, a post-arithmetic reference receiver, and
//   original-style one-line call formatting were all codegen duplicates.
// - reverse width/x local declarations select the oracle LEA SIB but retain
//   the same 15-byte shifted param3 push; combining that form with a named
//   right-edge temporary is also a duplicate. Restored the simpler pinned
//   natural source.

class TPanel {
public:
    virtual ~TPanel();
    virtual void setup();
    virtual void set_rect_a();
    virtual void set_rect_b();
    virtual void set_color();
    virtual void set_active();
    virtual void set_positioning();
    virtual void set_fixed_position();
    virtual void set_redraw();
    virtual void set_overlapped_redraw();
    virtual void draw_setup();
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect();
    virtual void draw_offset();
    virtual void draw_rect2();
    virtual void draw_offset2();
    virtual void paint();
    virtual void wnd_proc();
    virtual void handle_idle();
    virtual void handle_size();
    virtual void handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual void handle_char();
    virtual void handle_command();
    virtual void handle_user_command();
    virtual void handle_timer_command();
    virtual void handle_scroll();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual void handle_mouse_dbl_click();
    virtual void mouse_move_action();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual void mouse_left_hold_action();
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual void mouse_right_hold_action();
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect();
    virtual int is_inside(long, long);
    virtual void set_focus();
    virtual void set_tab_order();
    virtual void set_tab_order_alt();
    virtual void get_help_info();
    virtual void stop_sound_system();
    virtual void restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[0x64];
    int mouse_captured; // TPanel +0x68
    char gap_6C[0x88];

    long width() const;
    long xPosition() const;
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1C4];
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x8C];
    int border_size;
    int spacer_size;
};

class TListPanel : public TTextPanel {
public:
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual int is_inside(long, long);

    int auto_track;
    unsigned long mouse_scroll_last_time;
    unsigned long mouse_scroll_interval;
    int mouse_scroll_up;
    int mouse_scroll_down;
    int drawHighlightBar;
};

class TScrollBarPanel : public TPanel {
public:
    virtual int is_inside(long, long);
};

class TDropDownPanel : public TPanel {
public:
    char gap_F4[8];
    TListPanel* list_panel;       // TDropDownPanel +0xFC
    TScrollBarPanel* scbar_panel; // TDropDownPanel +0x100
};

class TDropDownButtonPanel : public TButtonPanel {
public:
    TDropDownPanel* drop_down_panel; // TDropDownButtonPanel +0x2B8

    virtual long handle_mouse_move(long, long, int, int);
};

long TDropDownButtonPanel::handle_mouse_move(long x, long y, int param3, int param4)
{
    if (this->mouse_captured != 0) {
        if (this->drop_down_panel->list_panel->is_inside(x, y) != 0) {
            this->handle_mouse_up(1, x, y, param3, param4);
            return this->drop_down_panel->list_panel->handle_mouse_down(1, x, y, param3, param4);
        }

        if (this->drop_down_panel->scbar_panel->is_inside(x, y) != 0) {
            this->handle_mouse_up(1, x, y, param3, param4);
            long list_width = this->drop_down_panel->list_panel->width();
            long list_x = this->drop_down_panel->list_panel->xPosition();
            return this->drop_down_panel->list_panel->handle_mouse_down(
                1, list_width + list_x - 1, y, param3, param4);
        }
    }

    return TPanel::handle_mouse_move(x, y, param3, param4);
}
