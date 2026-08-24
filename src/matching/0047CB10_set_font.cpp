// VA: 0047CB10 TTextPanel::set_font (55B)
// PDB source: Pnl_txt.cpp lines 598-604

#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int param_1);

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
    this->vf20(1);
}
