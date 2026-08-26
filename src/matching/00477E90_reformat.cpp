// VA: 00477E90 TInputPanel::reformat (91 B)
// PDB source: Pnl_inp.cpp lines 874-892

typedef unsigned char uchar;
typedef int PositionMode;
typedef int RedrawMode;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class TPanel;

class TTextPanel {
public:
    virtual ~TTextPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long,
                                  long, long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    char gap_04[0xF8-4];
    short num_lines;      // +0xF8
    short draw_lines;     // +0xFA
    short top_line;       // +0xFC
    short bot_line;       // +0xFE
    short cur_line;       // +0x100
    short cur_col;        // +0x102
    char gap_104[0x1A0-0x104];
    virtual void set_text(char*);
    void scroll(unsigned char, short, int);
};

class TInputPanel : public TTTextPanel {
public:
    char* input_buffer;   // +0x1A0
    void reformat();
};

void TInputPanel::reformat()
{
    short top = *(short*)((char*)this + 0xFC);
    short cur = *(short*)((char*)this + 0x100);
    TTextPanel::set_text(*(char**)((char*)this + 0x1A0));
    short n = this->num_lines;
    if (cur >= n) cur = n - 1;
    this->cur_line = cur;
    if (top >= n) this->top_line = n - 1;
    this->scroll(1, top, 1);
    this->set_redraw(1);
}
