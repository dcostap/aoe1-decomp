// matched source hypothesis: proportional wrapper to child panel set_rect virtual slot

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TPanel {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void set_rect(long x, long y, long w, long h);
};
#endif

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    char gap_000[0x10];
    long base_width;
    long base_height;
    char gap_01C[0xD8];
    long ideal_width;
    long ideal_height;

    virtual void position_panel(TPanel* panel, long x, long y, long w, long h);
};
#endif

void TEasy_Panel::position_panel(TPanel* panel, long x, long y, long w, long h) {
    panel->set_rect(
        (x * this->base_width) / this->ideal_width,
        (y * this->base_height) / this->ideal_height,
        (w * this->base_width) / this->ideal_width,
        (h * this->base_height) / this->ideal_height);
}
