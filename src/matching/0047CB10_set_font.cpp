// VA: 0047CB10 TTextPanel::set_font (55B)
// PDB source: Pnl_txt.cpp lines 598-604

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
    virtual void set_redraw(int param_1);

    char gap_04[0x104 - 4];
    void* font;      // +0x104
    long font_wid;   // +0x108
    long font_hgt;   // +0x10C

    void calc_draw_info(int param_1);
    void set_font(void* param_1, long param_2, long param_3);
};
#endif

void TTextPanel::set_font(void* param_1, long param_2, long param_3) {
    this->font = param_1;
    this->font_wid = param_2;
    this->font_hgt = param_3;
    this->calc_draw_info(1);
    this->set_redraw(1);
}
