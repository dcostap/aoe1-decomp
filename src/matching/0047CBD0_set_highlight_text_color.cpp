#ifndef PNL_TXT_TU_CONTEXT
struct tagRECT;
class TPanel;
class TTextPanel {
public:
    virtual ~TTextPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                  long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int param);
    char gap_4[0x122];
    int field_128;
    int field_12C;

    void set_highlight_text_color(unsigned long a, unsigned long b);
};
#endif

void TTextPanel::set_highlight_text_color(unsigned long a, unsigned long b) {
    this->field_128 = a;
    this->field_12C = b;
    this->set_redraw(1);
}
