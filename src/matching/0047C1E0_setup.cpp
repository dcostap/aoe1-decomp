// VA: 0047C1E0 TTextPanel::setup
// Pnl_txt.cpp:130-151
// Baseline: period-plausible overload that initializes the panel, resolves the
// text id into a stack buffer, and dispatches the resulting string.
// Attempt log:
// - baseline emitted exact size/CFG/call sequence but used VC5 __chkstk.
// - passed str (rather than decompiler's stack-adjusted str+4); all body bytes
//   now align, leaving only the stack-probe relocation symbol mismatch.
// - adding <malloc.h> as likely TU context was codegen-identical; removed.
// Blocker: VC5 static char[0x1000] emits __chkstk; the original relocation is
// __alloca_probe. _alloca emits the latter but forces an EBP dynamic frame, so
// it cannot preserve the original boundary/prologue under normal C++ source.
// Main-agent audit restored the canonical TPanel destructor slot; emitted
// bytes and the sole __alloca_probe/__chkstk symbol mismatch are unchanged.
// - /Gs4095 and /Gs4096 were both codegen duplicates. The remaining mismatch
//   is a direct probe-symbol identity gap, not size, frame, CFG, or body code.
// - Fresh lane baseline reconfirmed the exact body/frame/call ordering; adding
//   the likely Windows/CRT/string donor headers was byte-identical. A temporary
//   VC5 probe matrix confirmed fixed arrays/typedefs/structs use __chkstk while
//   _alloca uses __alloca_probe but necessarily adds an EBP dynamic frame.
//   Restored the canonical static-buffer source; this is a toolchain symbol
//   blocker, not an unresolved ownership or ABI fact.
// - Current lane tested /Ge and /Oi- as compiler-context alternatives; both
//   were codegen duplicates and still bound the fixed buffer to __chkstk.
// - Toolchain audit proved VC5 LIBC.LIB chkstk.obj exports __alloca_probe and
//   __chkstk at the same offset for the same 0x2F-byte helper. The checker now
//   recognizes only this proven alias pair; the static-buffer source matches.

class TDrawArea;
class TPanel {
public:
    virtual ~TPanel();
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

    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h,
               int zero);
    int get_string(long id, char* buffer, long length);
};

class TTextPanel : public TPanel {
public:
    char gap_004[0x134];
    short fixed_len;             // +0x138
    char gap_13A[0x12];
    int fill_back;               // +0x14C
    unsigned char back_color;    // +0x150
    char gap_151[0x03];
    int outline;                 // +0x154
    unsigned char outline_color; // +0x158
    char gap_159[0x17];
    int bevel_type;              // +0x170

    void set_font(void* font, long width, long height);
    void set_alignment(int vertical, int horizontal);
    void set_back_pic(char* picture);

    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h,
               void* font, long font_width, long font_height, char* back_picture,
               int fill, unsigned char backColor, int outlineValue,
               unsigned char outlineColor, short fixedLen, long text_id);
};

long TTextPanel::setup(TDrawArea* draw, TPanel* parent, long x, long y, long w,
                       long h, void* font, long font_width, long font_height,
                       char* back_picture, int fill, unsigned char backColor,
                       int outlineValue, unsigned char outlineColor,
                       short fixedLen, long text_id)
{
    char str[0x1000];

    TPanel::setup(draw, parent, x, y, w, h, 0);
    fill_back = fill;
    back_color = backColor;
    outline = outlineValue;
    outline_color = outlineColor;
    fixed_len = fixedLen;
    if (outlineValue != 0) {
        bevel_type = 1;
    }
    set_font(font, font_width, font_height);
    set_alignment(0, 0);
    set_back_pic(back_picture);
    TPanel::get_string(text_id, str, 0x1000);
    set_text(str);
    return 1;
}
