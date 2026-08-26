#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
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
        set_redraw(TPanel::RedrawImmediate);
    }
}
