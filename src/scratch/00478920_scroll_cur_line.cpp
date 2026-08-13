// TListPanel::scroll_cur_line - switch over action (1-7) with clamping and scroll/redraw/callback
//
// Attempt log:
// - restored the typed same-TU scroll ABI (int, short, int), the +0x20 redraw
//   virtual, and the +0xB4 parent callback with the oracle's action value 1.
// - corrected the strict max clamp, page endpoint ownership (case 4 -> bot,
//   case 5 -> top), and case-3 range/decrement behavior from the executable.
// - a positive current<bot case-2 arm and split case-3 decrement/scroll arms
//   recover the oracle's switch block topology; this reaches exact size/frame,
//   9 ordered calls, and 10/10 CFG signals with 267 positional bytes differing.
// - shared endpoint locals and explicit common-tail goto probes were broader
//   regressions or emitted duplicates; restored the natural scoped-source best.
// - removed redundant case-4/case-5 endpoint assignments from the range arms;
//   VC5 emitted the existing code unchanged, so the natural source is retained.
//   Left in scratch: localized case-5/6 tail/block layout and branch-span drift.

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
    virtual void set_redraw(int clear);
    virtual void vf24();
    virtual void vf28();
    virtual long vf2C(long param_1);
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40(void*, int, int, int);
    virtual void vf44();
    virtual void vf48(void*, int, int, int);
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58(void*, int, int, int);
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
    virtual long action(TPanel* caller, long action, unsigned long index,
                        unsigned long zero);

    char pad_00[0x3C];
    TPanel* parent_panel;
};

class TTextPanel : public TPanel {
public:
    void scroll(int action, short delta, int param_3);
};

class TListPanel : public TTextPanel {
public:
    char gap_44[0xB4];
    short num_lines;                  // 0xF8
    short draw_lines;                 // 0xFA
    short top_line;                   // 0xFC
    short bot_line;                   // 0xFE
    short cur_line;                   // 0x100
    char pad_102[0xBE];

    void scroll_cur_line(unsigned char action, short line, int flag);
};

void TListPanel::scroll_cur_line(unsigned char action, short line, int flag) {
    short old_cur = this->cur_line;

    switch (action) {
    case 1: {
        short new_cur = line;
        this->cur_line = new_cur;
        if (new_cur < 0) {
            this->cur_line = 0;
        } else if (new_cur > this->num_lines - 1) {
            this->cur_line = this->num_lines - 1;
        }
        if (this->cur_line < this->top_line) {
            this->scroll(1, this->cur_line, flag);
        } else if (this->cur_line > this->bot_line) {
            this->scroll(0, this->cur_line - this->bot_line, flag);
        }
        break;
    }
    case 2: {
        short cur = this->cur_line;
        if (cur < this->top_line || cur > this->bot_line) {
            this->cur_line = this->bot_line;
        }
        cur = this->cur_line;
        if (cur < this->bot_line) {
            cur++;
            this->cur_line = cur;
        } else if (cur < this->num_lines - 1) {
            cur++;
            this->cur_line = cur;
            this->scroll(2, 0, flag);
        }
        break;
    }
    case 3: {
        short cur = this->cur_line;
        if (cur < this->top_line || cur > this->bot_line) {
            this->cur_line = this->top_line;
        }
        cur = this->cur_line;
        if (cur > this->top_line) {
            cur--;
            this->cur_line = cur;
        } else if (cur > 0) {
            this->cur_line = cur;
            this->scroll(3, 0, flag);
        }
        break;
    }
    case 4: {
        short cur = this->cur_line;
        if (cur < this->top_line || cur > this->bot_line) {
            this->cur_line = this->bot_line;
        }
        if (this->cur_line == this->bot_line) {
            this->scroll(4, 0, flag);
        }
        this->cur_line = this->bot_line;
        break;
    }
    case 5: {
        short cur = this->cur_line;
        if (cur < this->top_line || cur > this->bot_line) {
            this->cur_line = this->top_line;
        }
        if (this->cur_line == this->top_line) {
            this->scroll(5, 0, flag);
        }
        this->cur_line = this->top_line;
        break;
    }
    case 6:
        this->scroll(6, 0, flag);
        this->cur_line = this->top_line;
        break;
    case 7:
        this->scroll(7, 0, flag);
        this->cur_line = this->bot_line;
        break;
    }

    this->set_redraw(1);

    if (this->cur_line != old_cur) {
        if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
            this->parent_panel->action(this, 1, this->cur_line, 0);
        }
    }
}
