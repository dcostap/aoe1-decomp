// attempt 1: natural vertical slider factory with proportional coordinates, optional button art and bevels
// size matches; early-return version keeps math/setup block exact, remaining drift is epilogue layout plus bevel color zero-extension/order
// tried result-local single-exit form and int color formal parameters; result local regressed early register allocation, so keep cleaner early-return basin
// worker 2026-08-10: a failure-label rewrite was codegen-identical; a result local moved the first
// mismatch into the allocation math and was restored. Final holdout is the original shared EH cleanup
// tail (oracle branches to one failure epilogue; this natural source emits separate cleanup tails).
// worker 2026-08-11 (sa02c04fb1_00469AD0): uninitialized result plus an explicit done label was
// codegen-identical. Positive and negative compound success/failure guards were also identical;
// all three probes preserved the exact 0x0000-0x014D prefix, five ordered calls, and 46-byte diff.
// Dossier confirms the only structural gap is the /GX return tail: the oracle joins three failure
// edges at 00469C24 (xor eax,eax) before one common cleanup, while VC5 clones a failure cleanup
// after the success epilogue. The paired create_scrollbar target documents the same persistent
// EH-tail behavior even after result/goto/vptr probes. Keep this natural typed source in
// scratch; remaining lead is a compiler/EH-tail blocker, not an unresolved call or field layout.
// worker 2026-08-12 (normal-469AD0-r1): exact Panel_ez/pnl_sld donors confirm the int helper
// values and long setup parameter; changing declarations did not change emitted code.
// Compiler-owned vptr surfaces with proven offsets were also a duplicate and were not retained.
// A natural combined success guard with one trailing failure return remained the same 46-byte
// mismatch. The common /GX cleanup tail remains the only structural gap.

class TPanel {};
class TShape {};

class TScrollBarPanel {
public:
    char gap_000[0xD8];
    int field_D8;
    void set_buttons(TShape* pics, int a, int b, int c, int d);
    void set_bevel_info(int count, int c1, int c2, int c3, int c4, int c5, int c6);
};

class TVerticalSliderPanel : public TScrollBarPanel {
public:
    char data[0x1CC - 0xDC];
    TVerticalSliderPanel();
    long setup(void* draw_area, TPanel* parent, long x, long y, long w, long h,
               char* a, char* b, long c, long p3, long p4, long p5, int one, int zero);
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
    if (*out != 0 && (*out)->field_D8 == 0 &&
        (*out)->setup(this->draw_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, 0, 0, 0, p3, p4, p5, 1, 0) != 0) {
        if (this->button_pics != 0) {
            (*out)->set_buttons(this->button_pics, -1, 8, 10, 12);
        }

        if (this->use_bevels != 0) {
            (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
        }

        return 1;
    }

    return 0;
}
