// VA: 0047C120 TTextPanel::setup
// Pnl_txt.cpp:102-120
// Retry 2026-05-24: replace stale stub with packet-derived TTextPanel setup.

class TDrawArea;
class TPanel {
public:
    virtual void vf_000();
    virtual void vf_004();
    virtual void vf_008();
    virtual void vf_00C();
    virtual void vf_010();
    virtual void vf_014();
    virtual void vf_018();
    virtual void vf_01C();
    virtual void vf_020();
    virtual void vf_024();
    virtual void vf_028();
    virtual void vf_02C();
    virtual void vf_030();
    virtual void vf_034();
    virtual void vf_038();
    virtual void vf_03C();
    virtual void vf_040();
    virtual void vf_044();
    virtual void vf_048();
    virtual void vf_04C();
    virtual void vf_050();
    virtual void vf_054();
    virtual void vf_058();
    virtual void vf_05C();
    virtual void vf_060();
    virtual void vf_064();
    virtual void vf_068();
    virtual void vf_06C();
    virtual void vf_070();
    virtual void vf_074();
    virtual void vf_078();
    virtual void vf_07C();
    virtual void vf_080();
    virtual void vf_084();
    virtual void vf_088();
    virtual void vf_08C();
    virtual void vf_090();
    virtual void vf_094();
    virtual void vf_098();
    virtual void vf_09C();
    virtual void vf_0A0();
    virtual void vf_0A4();
    virtual void vf_0A8();
    virtual void vf_0AC();
    virtual void vf_0B0();
    virtual void vf_0B4();
    virtual void vf_0B8();
    virtual void vf_0BC();
    virtual void vf_0C0();
    virtual void vf_0C4();
    virtual void vf_0C8();
    virtual void vf_0CC();
    virtual void vf_0D0();
    virtual void vf_0D4();
    virtual void vf_0D8();
    virtual void vf_0DC();
    virtual void vf_0E0();
    virtual void vf_0E4();
    virtual void set_text(char* text); // +0xE8
    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h, int zero);
};

class TTextPanel : public TPanel {
public:
    char gap_004[0x134];
    short fixed_len;           // +0x138
    char gap_13A[0x12];
    char* fill_back;           // +0x14C
    unsigned char back_color;  // +0x150
    char gap_151[0x03];
    int outline;               // +0x154
    unsigned char outline_color; // +0x158
    char gap_159[0x17];
    int bevel_type;            // +0x170

    void set_font(void* font, long p2, long p3);
    void set_alignment(int h, int v);
    void set_back_pic(char* pic);

    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h,
               void* font, long font_arg2, long font_arg3, char* back_pic,
               char* fill, int backColor, int outline, unsigned char outlineColor,
               short fixedLen, char* text);
};

long TTextPanel::setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h,
                       void* font, long font_arg2, long font_arg3, char* back_pic,
                       char* fill, int backColor, int outlineValue, unsigned char outlineColor,
                       short fixedLenValue, char* text)
{
    TPanel::setup(draw, parent, x, y, w, h, 0);
    fill_back = fill;
    back_color = (unsigned char)backColor;
    outline = outlineValue;
    outline_color = outlineColor;
    fixed_len = fixedLenValue;
    if (outlineValue != 0) {
        bevel_type = 1;
    }
    set_text(text);
    set_font(font, font_arg2, font_arg3);
    set_alignment(0, 0);
    set_back_pic(back_pic);
    return 1;
}
