// first pass: store outline, then set bevel type/color and invoke the redraw callback when outline is nonzero
// if this misses, the remaining mismatch is likely only the vtable-slot call basin or the exact TTextPanel field offsets

typedef void (*TextPanelRedrawFn)(TTextPanel*, int);

class TTextPanel {
public:
    void** vftable;
    char gap_04[0x14C];
    int outline;
    char gap_154[0x3];
    unsigned char outline_color;
    char gap_158[0x17];
    int bevel_type;

    void set_outline(int outline, unsigned char color);
};

void TTextPanel::set_outline(int outline, unsigned char color) {
    this->outline = outline;
    if (outline != 0) {
        this->bevel_type = 1;
        this->outline_color = color;
    } else {
        this->bevel_type = 0;
        this->outline_color = color;
    }
    ((TextPanelRedrawFn)this->vftable[8])(this, 1);
}
