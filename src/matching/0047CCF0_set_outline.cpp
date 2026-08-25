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
    virtual void set_redraw(int value);

    char gap_04[0x150];
    int outline;
    unsigned char outline_color;
    char gap_159[0x17];
    int bevel_type;

    void set_outline(int outline, unsigned char color);
};
#endif

void TTextPanel::set_outline(int outline, unsigned char color) {
    this->outline = outline;
    if (outline != 0) {
        this->bevel_type = 1;
    } else {
        this->bevel_type = 0;
    }
    this->outline_color = color;
    this->set_redraw(1);
}
