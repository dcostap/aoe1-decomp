// TTextPanel::scroll
// VA: 0047D060
// Pnl_txt.cpp:839-878
// 153 bytes
//
// Attempt 1: Switch-based scroll function.

#ifndef PNL_TXT_TU_CONTEXT
struct tagRECT;
class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                  long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);  // vt[8] = +0x20
    char gap_04[0xF0];  // +0x04 to +0xF3
};

class TTextPanel : public TPanel {
public:
    char pad_F4[4];       // +0xF4 to +0xF7 (gap)
    short max_scroll;     // +0xF8
    short page_scroll;    // +0xFA
    short cur_scroll;     // +0xFC

    void calc_draw_info(int);  // @ 0047CE70, __thiscall
    void scroll(unsigned char scroll_type, short amount, int param_3);
};
#endif

void TTextPanel::scroll(unsigned char scroll_type, short amount, int param_3)
{
    switch (scroll_type) {
    case 0:
        this->cur_scroll += amount;
        break;
    case 1:
        this->cur_scroll = amount;
        break;
    case 2:
        this->cur_scroll++;
        break;
    case 3:
        this->cur_scroll--;
        break;
    case 4: {
        short dx = this->page_scroll;
        dx--;
        this->cur_scroll += dx;
        break;
    }
    case 5: {
        short ax = 1;
        ax -= this->page_scroll;
        this->cur_scroll += ax;
        break;
    }
    case 6:
        this->cur_scroll = 0;
        break;
    case 7: {
        short cx = this->max_scroll;
        cx--;
        this->cur_scroll = cx;
        break;
    }
    }

    this->calc_draw_info(param_3);
    this->set_redraw(1);
}
