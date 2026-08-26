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
    char gap_4[0x116];
    int field_11C;

    enum Style {
        NormalStyle = 0,
        BeveledStyle = 1,
        ChiseledStyle = 2
    };
    void set_style(Style value);
};
#endif

void TTextPanel::set_style(TTextPanel::Style value) {
    this->field_11C = value;
    this->set_redraw(1);
}
