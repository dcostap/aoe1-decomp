// TTextPanel::scroll
// VA: 0047D060
// Pnl_txt.cpp:839-878
// 153 bytes
//
// Attempt 1: Switch-based scroll function.

class TPanel {
public:
    virtual ~TPanel();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void redraw(int);  // vt[8] = +0x20
    char gap_04[0xF0];  // +0x04 to +0xF3
};

class TTextPanel : public TPanel {
public:
    char pad_F4[4];       // +0xF4 to +0xF7 (gap)
    short max_scroll;     // +0xF8
    short page_scroll;    // +0xFA
    short cur_scroll;     // +0xFC

    void scroll_set(int);  // @ 0047CE70, __thiscall
    void scroll(int scroll_type, short amount, int param_3);
};

void TTextPanel::scroll(int scroll_type, short amount, int param_3)
{
    unsigned char type = (unsigned char)scroll_type;

    switch (type) {
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

    this->scroll_set(param_3);
    this->redraw(1);
}
