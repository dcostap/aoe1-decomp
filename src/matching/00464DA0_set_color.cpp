#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void redraw(int mode);

    char gap_04[0x68];
    int active;
    char gap_70[0x7F];
    unsigned char color;

    virtual void set_color(unsigned char color);
};

#endif
void TPanel::set_color(unsigned char color) {
    this->color = color;
    if (active != 0) {
        set_redraw(2);
    }
}
