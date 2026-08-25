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
    char gap_4[0x10A];
    int field_110;
    int field_114;

    void set_alignment(int a, int b);
};
#endif

void TTextPanel::set_alignment(int a, int b) {
    this->field_110 = a;
    this->field_114 = b;
    this->set_redraw(1);
}
