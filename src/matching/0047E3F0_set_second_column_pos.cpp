#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    virtual ~TTextPanel();
    virtual long setup(void*, TTextPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                  long, long, TTextPanel*, TTextPanel*,
                                  TTextPanel*, TTextPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int param);
    char gap_4[0x15A];
    long second_column_pos;

    void set_second_column_pos(long value);
};
#endif

void TTextPanel::set_second_column_pos(long value) {
    this->second_column_pos = value;
    this->set_redraw(1);
}
