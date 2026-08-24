#ifndef PNL_EDIT_TU_CONTEXT
class TPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void notify(int param);
    char gap_4[0x10E];
    int field_114;
    int field_118;

    void set_text_color(int a, int b);
};
#endif

#ifndef PNL_EDIT_TU_CONTEXT
void TPanel::set_text_color(int a, int b) {
    this->field_114 = a;
    this->field_118 = b;
    this->notify(1);
}
#else
void TEditPanel::set_text_color(unsigned long a, unsigned long b) {
    this->text_color1 = a;
    this->text_color2 = b;
    this->set_redraw(1);
}
#endif
