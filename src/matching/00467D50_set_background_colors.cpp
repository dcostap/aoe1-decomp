// first pass: notify the panel via the vtable slot, then store the two background bytes and stock brush state
// if this misses, the remaining mismatch is likely only the vcall shape or one of the tail field offsets

extern "C" __declspec(dllimport) void* __stdcall GetStockObject(int index);

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void notify_background_color(unsigned char color);

    char gap_04[0x450];
    unsigned char background_color1;
    unsigned char background_color2;
    char gap_456[0xA];
    int fill_in_background;
    void* background_brush;
    int brush_color;

    void set_background_colors(unsigned char color1, unsigned char color2);
};
#endif

void TEasy_Panel::set_background_colors(unsigned char color1, unsigned char color2) {
    this->notify_background_color(color1);
    background_color1 = color1;
    background_color2 = color2;
    background_brush = GetStockObject(4);
    fill_in_background = 1;
    brush_color = 0;
}
