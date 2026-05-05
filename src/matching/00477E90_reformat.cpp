// VA: 00477E90 TInputPanel::reformat (91 B)
// PDB source: Pnl_inp.cpp lines 874-892

class TTTextPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int);
    char gap_04[0xF8-4];
    short num_lines;      // +0xF8
    short draw_lines;     // +0xFA
    short top_line;       // +0xFC
    short bot_line;       // +0xFE
    short cur_line;       // +0x100
    short cur_col;        // +0x102
    char gap_104[0x1A0-0x104];
    void set_text(char*);
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
    this->set_text(*(char**)((char*)this + 0x1A0));
    short n = this->num_lines;
    if (cur >= n) cur = n - 1;
    this->cur_line = cur;
    if (top >= n) this->top_line = n - 1;
    this->scroll(1, top, 1);
    this->vf20(1);
}
