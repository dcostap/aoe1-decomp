// VA: 00477220 TInputPanel::key_down_action
// PDB source: Pnl_inp.cpp lines 274-471
// Attempt log:
// - baseline switch omitted control keys and used helper/raw vtable plumbing; 22/36 calls matched.
// - reconstructed the period-plausible TInputPanel/TTextPanel case order from PDB bands and the executable switch table.
// - corrected TPanel/TTextPanel layout: parent_panel +0x40, num_lines +0xF8, cursor fields +0x100/+0x102, and format fields +0x19C onward.
// - kept a short cursor local across get_text/mbslen to reproduce the target's saved EDI and 1289-byte boundary; best check is 1067 positional diff, 85.34% shape, and 30/36 ordered calls.
// - tested shared-label and page-clamp variants; the compiler kept the same nonexact 3/5 calc_input_pos and vslot call sites.
// - left in scratch: remaining drift is switch-table relocation masking plus two VC5 tail-sharing decisions; next lead is a focused source-order or local-lifetime donor comparison.

#include <stddef.h>

typedef unsigned char uchar;
typedef unsigned long ulong;

extern "C" short __cdecl __mbslen(const char* str);

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void set_redraw(int);
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
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

    switch (key) {
    case 0x25:
        if (this->num_lines < 1)
            return 1;
        col = this->cur_col;
        if (col > 0) {
            col--;
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
            return 1;
        }
        if (this->cur_line >= this->num_lines - 1)
            return 1;
        this->cur_line++;
        this->cur_col = 0;
        this->calc_input_pos();
        this->set_redraw(1);
        return 1;

    case 0x26:
        if (this->num_lines < 1)
            return 1;
        if (this->cur_line <= 0)
            return 1;
        this->cur_line--;
        if (this->cur_col > __mbslen(this->get_text(this->cur_line)))
            this->cur_col = __mbslen(this->get_text(this->cur_line));
        this->calc_input_pos();
        this->set_redraw(1);
        return 1;

    case 0x28:
        if (this->num_lines < 1)
            return 1;
        if (this->cur_line >= this->num_lines - 1)
            return 1;
        this->cur_line++;
        if (this->cur_col > __mbslen(this->get_text(this->cur_line)))
            this->cur_col = __mbslen(this->get_text(this->cur_line));
        this->calc_input_pos();
        this->set_redraw(1);
        return 1;

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
        if (this->cur_line < this->top_line || this->cur_line > this->bot_line)
            this->cur_line = this->top_line;
        if (this->cur_line == this->top_line) {
            this->scroll(5, 0, 1);
            this->cur_line = this->top_line;
        }
        this->cur_col = __mbslen(this->get_text(this->cur_line));
        this->calc_input_pos();
        this->set_redraw(1);
        return 1;

    case 0x22:
        if (this->num_lines < 1)
            return 1;
        if (this->cur_line >= this->num_lines - 1)
            return 1;
        if (this->cur_line < this->top_line || this->cur_line > this->bot_line)
            this->cur_line = this->bot_line;
        if (this->cur_line == this->bot_line) {
            this->scroll(4, 0, 1);
            this->cur_line = this->bot_line;
        }
        this->cur_col = __mbslen(this->get_text(this->cur_line));
        this->calc_input_pos();
        this->set_redraw(1);
        return 1;

    case 0x2E:
        this->delete_character();
        return 1;

    case 0x2D:
        if (param5 != 0)
            goto paste;
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
    paste:
        this->paste();
        return 1;
    }
    return 0;
}
