// VA: 00477220 TInputPanel::key_down_action
// PDB source: Pnl_inp.cpp lines 274-471
// Attempt log:
// - baseline switch omitted control keys and used helper/raw vtable plumbing; 22/36 calls matched.
// - reconstructed the period-plausible TInputPanel/TTextPanel case order from PDB bands and the executable switch table.
// - corrected TPanel/TTextPanel layout: parent_panel +0x40, num_lines +0xF8, cursor fields +0x100/+0x102, and format fields +0x19C onward.
// - kept a short cursor local across get_text/mbslen to reproduce the target's saved EDI and 1289-byte boundary; best check is 1067 positional diff, 85.34% shape, and 30/36 ordered calls.
// - tested shared-label and page-clamp variants; the compiler kept the same nonexact 3/5 calc_input_pos and vslot call sites.
// - separated the right-move success arm and upward-move body; this adds one calc_input_pos/redraw pair and improves the call map to 32/36.
// - the original page tail conditionally clamps cur_col after get_text/mbslen; duplicating that condition in both page cases expands the function by 178 bytes, so that behavior/layout lead remains open.
// - tested binary-shaped shared labels for left/down/page cursor tails; VC5 merged the calc/redraw blocks, lost call sites, or grew 150 bytes, so rolled back.
// - tested the prior early-guard/local-column variant; it reaches 1067 positional bytes but changes a direct-call target and loses structural call alignment, so rolled back.
// - restored the single paste call by routing case 0x2D through the case 0x56 paste tail; this removes one call and reaches the exact 1289-byte size.
// - restored the explicit default-zero/common return-one switch tail from the original CFG; this improves shape and preserves break-path behavior.
// - restored the shared page clamp and carried the selected page line in a short local; this returns the exact size and restores both page get_text/mbslen pairs.
// - a direct down-arrow tail produces the full call count but grows 154 bytes and splits the home/end tail; the shared page tail is the best clean basin.
// - twenty meaningful probes completed. Best clean result is 1082 positional bytes, 84.91% shape, exact size, 32/36 ordered calls.
// - unresolved compiler basin: VC5 tail-merges the up calc/redraw pair into a later tail and omits the down-specific get_text/mbslen pair; direct-tail variants restore calls but lose size and shape.
// - takeover probes: an up local argument did not restore a call site; direct down tails restored 36 calls but added 154-158 bytes. Shared clamp labels did not reduce that basin.
// - takeover probes: direct-member, explicit-short-cast, and base-pointer receiver forms stayed in the 32-call basin. Block-local and function-wide line forms stayed in the oversized 36-call basin.
// - takeover probes: a separate left-arrow positive-column block is the best
//   natural basin at 1076 positional bytes, 85.13% shape, and the exact 1289-
//   byte size. It preserves the oracle's distinct left calc/redraw block.
// - takeover probes: restoring the down-arrow get_text/mbslen pair reaches the
//   full 36-call surface but grows 154-158 bytes and loses the target layout.
// - left in scratch: remaining drift is switch-table relocation masking, one calc_input_pos/redraw tail pair, and the shared page clamp.
// - current claim probes: a shared left assignment changed the 32-call basin to 34 calls and worsened the diff.
// - current claim probes: explicit up/right labels removed calls and worsened the shape, so the pinned clean source remains.

#include <stddef.h>

typedef unsigned char uchar;
typedef unsigned long ulong;
typedef int PositionMode;
typedef int RedrawMode;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;

extern "C" short __cdecl __mbslen(const char* str);

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long,
                                  long, long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, ulong, ulong);

    char gap_04[0x40 - 0x04];
    TPanel* parent_panel; // +0x40
    char gap_44[0xF4 - 0x44];
};

class TTextPanel : public TPanel {
public:
    void* list; // +0xF4
    short num_lines; // +0xF8
    short draw_lines; // +0xFA
    short top_line; // +0xFC
    short bot_line; // +0xFE
    short cur_line; // +0x100
    short cur_col; // +0x102
    char gap_104[0x188 - 0x104];

    char* get_text(int);
    void scroll(uchar, uchar, int);
};

class TInputPanel : public TTextPanel {
public:
    char gap_188[0x19C - 0x188];
    int format_type; // +0x19C
    char* input_buffer; // +0x1A0
    char* input_buffer1; // +0x1A4
    char* input_buffer2; // +0x1A8
    short input_len; // +0x1AC
    short max_len; // +0x1AE
    int insert_mode; // +0x1B0

    virtual long key_down_action(long, short, int, int, int);
    void calc_input_pos();
    int delete_character();
    int backspace_character();
    int insert_character(long);
    int paste();
};

long TInputPanel::key_down_action(long key, short, int, int param4, int param5)
{
    short len;
    short col;
    short line;

    switch (key) {
    case 0x25:
        if (this->num_lines < 1)
            return 1;
        col = this->cur_col;
        if (col > 0) {
            col--;
            this->cur_col = col;
            this->calc_input_pos();
            this->set_redraw(1);
            return 1;
        } else {
            col = this->cur_line;
            if (col <= 0)
                return 1;
            col--;
            this->cur_line = col;
            col = __mbslen(this->get_text(this->cur_line));
        }
        this->cur_col = col;
        this->calc_input_pos();
        this->set_redraw(1);
        return 1;

    case 0x27:
        if (this->num_lines < 1)
            return 1;
        col = this->cur_col;
        len = __mbslen(this->get_text(this->cur_line));
        if (col < len) {
            this->cur_col = col + 1;
            this->calc_input_pos();
            this->set_redraw(1);
        } else {
            if (this->cur_line >= this->num_lines - 1)
                return 1;
            this->cur_line++;
            this->cur_col = 0;
            this->calc_input_pos();
            this->set_redraw(1);
        }
        return 1;

    case 0x26:
        if (this->num_lines < 1)
            return 1;
        if (this->cur_line > 0) {
            this->cur_line--;
            if (this->cur_col > __mbslen(this->get_text(this->cur_line)))
                this->cur_col = __mbslen(this->get_text(this->cur_line));
            this->calc_input_pos();
            this->set_redraw(1);
            return 1;
        }
        break;

    case 0x28:
        if (this->num_lines < 1)
            return 1;
        if (this->cur_line >= this->num_lines - 1)
            return 1;
        this->cur_line++;
        line = this->cur_line;
        goto page_update;

    case 0x24:
        if (this->num_lines < 1)
            return 1;
        if (param4 != 0) {
            if (this->cur_col == 0 && this->cur_line == 0)
                break;
            this->cur_col = 0;
            this->cur_line = 0;
            this->calc_input_pos();
            this->set_redraw(1);
            return 1;
        }
        if (this->cur_col == 0)
            break;
        this->cur_col = 0;
        this->set_redraw(1);
        this->calc_input_pos();
        return 1;

    case 0x23:
        if (this->num_lines < 1)
            return 1;
        if (param4 != 0) {
            if (this->cur_line == this->num_lines - 1) {
                len = __mbslen(this->get_text(this->cur_line));
                if (this->cur_col == len)
                    break;
            }
            this->cur_line = this->num_lines - 1;
            this->cur_col = __mbslen(this->get_text(this->cur_line));
        } else {
            len = __mbslen(this->get_text(this->cur_line));
            if (this->cur_col == len)
                break;
            this->cur_col = __mbslen(this->get_text(this->cur_line));
        }
        this->set_redraw(1);
        this->calc_input_pos();
        return 1;

    case 0x21:
        if (this->num_lines < 1)
            return 1;
        if (this->cur_line <= 0)
            return 1;
        line = this->cur_line;
        if (line < this->top_line || line > this->bot_line)
            line = this->top_line;
        if (line == this->top_line) {
            this->scroll(5, 0, 1);
            line = this->top_line;
        }
        goto page_update;

    case 0x22:
        if (this->num_lines < 1)
            return 1;
        if (this->cur_line >= this->num_lines - 1)
            return 1;
        line = this->cur_line;
        if (line < this->top_line || line > this->bot_line)
            line = this->bot_line;
        if (line == this->bot_line) {
            this->scroll(4, 0, 1);
            line = this->bot_line;
        }
page_update:
        this->cur_line = line;
        len = __mbslen(this->get_text(this->cur_line));
        if (this->cur_col > len)
            this->cur_col = __mbslen(this->get_text(this->cur_line));
        this->calc_input_pos();
        this->set_redraw(1);
        return 1;

    case 0x2E:
        this->delete_character();
        return 1;

    case 0x2D:
        if (param5 != 0) {
            goto paste_action;
        }
        if (param4 != 0)
            return 1;
        this->insert_mode = (this->insert_mode == 0);
        return 1;

    case 8:
        this->backspace_character();
        return 1;

    case 0x0D:
        if (this->format_type == 7) {
            this->insert_character(10);
            return 1;
        }
        if (this->parent_panel != 0)
            this->parent_panel->action(this, 0, 0, 0);
        return 1;

    case 0x1B:
        if (this->parent_panel != 0)
            this->parent_panel->action(this, 1, 0, 0);
        return 1;

    case 0x56:
        if (param4 == 0)
            return 0;
paste_action:
        this->paste();
        return 1;

    default:
        return 0;
    }
    return 1;
}
