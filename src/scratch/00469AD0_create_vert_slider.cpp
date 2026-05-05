// attempt 1: natural vertical slider factory with proportional coordinates, optional button art and bevels
// size matches; early-return version keeps math/setup block exact, remaining drift is epilogue layout plus bevel color zero-extension/order
// tried result-local single-exit form and int color formal parameters; result local regressed early register allocation, so keep cleaner early-return basin

class TPanel {};
class TShape {};

class TScrollBarPanel {
public:
    char gap_000[0xD8];
    int field_D8;
    void set_buttons(TShape* pics, long a, long b, long c, long d);
    void set_bevel_info(long count, int c1, int c2, int c3, int c4, int c5, int c6);
};

class TVerticalSliderPanel : public TScrollBarPanel {
public:
    char data[0x1CC - 0xDC];
    TVerticalSliderPanel();
    long setup(void* draw_area, TPanel* parent, long x, long y, long w, long h,
               char* a, char* b, int c, long p3, long p4, long p5, int one, int zero);
};

class TEasy_Panel {
public:
    char gap_000[0x14];
    long base_width;
    long base_height;
    char gap_01C[0x20 - 0x1C];
    void* draw_area;
    char gap_024[0xF4 - 0x24];
    long ideal_width;
    long ideal_height;
    char gap_0FC[0x31C - 0xFC];
    long use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_326[0x448 - 0x326];
    TShape* button_pics;

    int create_vert_slider(TPanel* parent, TVerticalSliderPanel** out, long p3, long p4, long p5, long p6, long p7, long p8, long p9);
};

int TEasy_Panel::create_vert_slider(TPanel* parent, TVerticalSliderPanel** out, long p3, long p4, long p5, long p6, long p7, long p8, long p9) {
    long ideal_x = (p6 * this->base_width) / this->ideal_width;
    long ideal_y = (p7 * this->base_height) / this->ideal_height;
    long ideal_w = (p8 * this->base_width) / this->ideal_width;
    long ideal_h = (p9 * this->base_height) / this->ideal_height;

    *out = new TVerticalSliderPanel;
    if (*out == 0 || (*out)->field_D8 != 0) {
        return 0;
    }

    if ((*out)->setup(this->draw_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, 0, 0, 0, p3, p4, p5, 1, 0) == 0) {
        return 0;
    }

    if (this->button_pics != 0) {
        (*out)->set_buttons(this->button_pics, -1, 8, 10, 12);
    }

    if (this->use_bevels != 0) {
        (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
    }

    return 1;
}
