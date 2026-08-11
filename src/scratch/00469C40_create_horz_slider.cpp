// attempt 1: natural horizontal slider factory with proportional coordinates, optional button art and bevels
// size matches; early-return version keeps math/setup block exact, remaining drift is epilogue layout plus bevel color zero-extension/order
// tried result-local single-exit form and int color formal parameters; result local regressed early register allocation, so keep cleaner early-return basin
// worker 2026-08-10: one explicit done label with an initialized result local moved the first mismatch
// into allocation math and was restored. Final holdout is the original shared EH cleanup tail; the
// natural source matches all five calls and the complete factory body before that tail.
// probe 2026-08-11: corrected the two helper declarations to the period ABI proven by their exact
// same-TU definitions (all set_buttons/set_bevel_info value parameters are int, not long).
// probe 2026-08-11: corrected setup's third post-pointer parameter to long, matching the exact
// THorizontalSliderPanel::setup donor and its decorated ABI.
// probe 2026-08-11: restored the proven polymorphic slider base surface and vptr while preserving
// field_D8 at 0xD8 and the complete 0x1CC derived allocation size.
// probe 2026-08-11: restored TEasy_Panel's virtual method surface with the exact donor-style
// 0x10 post-vptr gap so all observed panel fields retain their proven offsets.
// probe 2026-08-11: the labeled success-to-done form was codegen-identical to the clean basin.
// Delayed result initialization reached exact size but displaced the out-pointer/register topology
// (215-byte diff); explicit failure gotos and ordinary early returns likewise worsened the body
// (210-byte and 251-byte diffs). All were rolled back. The remaining 46-byte drift is only the
// /GX cleanup-tail shape: the oracle joins three failure edges at one xor/common epilogue, while
// VC5 clones the failure cleanup after the success epilogue in this natural source basin.

class TPanel {};
class TShape {};

class TScrollBarPanel {
public:
    virtual ~TScrollBarPanel();
    char gap_004[0xD8 - 0x4];
    int field_D8;
    void set_buttons(TShape* pics, int a, int b, int c, int d);
    void set_bevel_info(int count, int c1, int c2, int c3, int c4, int c5, int c6);
};

class THorizontalSliderPanel : public TScrollBarPanel {
public:
    virtual ~THorizontalSliderPanel();
    char data[0x1CC - 0xDC];
    THorizontalSliderPanel();
    long setup(void* draw_area, TPanel* parent, long x, long y, long w, long h,
               char* a, char* b, long c, long p3, long p4, long p5, int one, int zero);
};

class TEasy_Panel {
public:
    char gap_000[0x10];
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

    virtual int create_horz_slider(TPanel* parent, THorizontalSliderPanel** out, long p3, long p4, long p5, long p6, long p7, long p8, long p9);
};

int TEasy_Panel::create_horz_slider(TPanel* parent, THorizontalSliderPanel** out, long p3, long p4, long p5, long p6, long p7, long p8, long p9) {
    long ideal_x = (p6 * this->base_width) / this->ideal_width;
    long ideal_y = (p7 * this->base_height) / this->ideal_height;
    long ideal_w = (p8 * this->base_width) / this->ideal_width;
    long ideal_h = (p9 * this->base_height) / this->ideal_height;

    int result;
    *out = new THorizontalSliderPanel;
    if (*out != 0 && (*out)->field_D8 == 0 &&
        (*out)->setup(this->draw_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, 0, 0, 0, p3, p4, p5, 1, 0) != 0) {
        if (this->button_pics != 0) {
            (*out)->set_buttons(this->button_pics, -1, 8, 10, 12);
        }

        if (this->use_bevels != 0) {
            (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
        }
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
