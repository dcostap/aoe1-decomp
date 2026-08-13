// 00468E50 TEasy_Panel::create_text
// Source: Panel_ez.cpp lines 1281-1328
// attempt 1: natural source based on nearby 00468CB0 overload and packet; main body extremely close, but VC5 emits success early-return epilog and places failure block after configured end.
// attempt 2: added explicit result local with goto common return; worsened register allocation from first coordinate math (first mismatch 78).
// attempt 3: same common return using dead parameter center_h as result; same broad register-allocation regression.
// attempt 4: same common return using dead text_id/font_id as result; same broad regression.
// attempt 5: reordered source with ok/fail labels and no result local; no improvement over natural tail split.
// attempt 6: added register outp local to encourage EBX out pointer; no codegen change in best natural form.
// attempt 7: tried setting error_flag=0 on success to force common block; worsened broad diff.
// attempt 8: removed /GX; object lost required EH frame and was too small, reverted.
// attempt 9: tried /Ob0 with /GX; no codegen change.
// attempt 10: tried /Gy with /GX; no codegen change, reverted.
// attempt 11: late uninitialized int result with a common return widened the frame slot; 313 bytes, first mismatch 78, rolled back.
// attempt 12: reused ideal_y as the result; duplicate 313-byte codegen, rolled back.
// attempt 13: moved the result declaration before coordinate locals; duplicate 313-byte codegen, rolled back.
// attempt 14: success-only goto done with literal failure return; duplicate natural 53-byte codegen, rolled back.
// attempt 15: byte result formed one common epilogue but changed EBX/EBP coloring; 262 bytes, first mismatch 102, rolled back.
// attempt 16: output-pointer alias with byte result; duplicate attempt 15, rolled back.
// attempt 17: natural early failure guards produced duplicate 442-byte codegen; restored nested source because tail topology did not move.
// attempt 18: modeled the ABI-supported virtual TEasy_Panel surface with a vptr-preserving leading gap; emitted code was unchanged, rolled back.
// continuation probe: nested allocation/error guards were a codegen duplicate.
// continuation probe: reusing center_v for the common return widened early liveness to 448 bytes / 313 diff, rolled back.
// continuation probe: naming setup's return before its guard was a codegen duplicate.
// continuation probe: making create_text virtual shifted proven field accesses and worsened to 62 diff, rolled back.
// continuation probe: hoisting font selection before the allocation/error guard widened drift to 143 diff, rolled back.
// continuation probe: exact sibling nested factory guard shape was a codegen duplicate.
// Remaining evidence: 9 ordered calls, first 156 bytes, and all body blocks stay exact; only /GX success/failure cleanup-tail placement differs. Same-TU create_input, create_edit, create_scrollbar, and slider factories show the same duplicated-tail basin after typed control-flow/result probes.
// Left in scratch: best source has all functional code and first 156 bytes exact, but tail/failed-path placement is not exact; not accepted_drift because rebuilt failure target lies outside original configured function body.

class TPanel {};
class TDrawArea {};
class RGE_Font { public: void* font; long font_wid; long font_hgt; };
class RGE_Base_Game { public: RGE_Font* get_font(int id); };
extern RGE_Base_Game* rge_base_game;

class TTextPanel {
public:
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void vf08(); virtual void vf09(); virtual void vf10(); virtual void vf11();
    virtual void vf12(); virtual void vf13(); virtual void vf14(); virtual void vf15();
    virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
    virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23();
    virtual void vf24(); virtual void vf25(); virtual void vf26(); virtual void vf27();
    virtual void vf28(); virtual void vf29(); virtual void vf30(); virtual void vf31();
    virtual void vf32(); virtual void vf33(); virtual void vf34(); virtual void vf35();
    virtual void vf36(); virtual void vf37(); virtual void vf38(); virtual void vf39();
    virtual void vf40(); virtual void vf41(); virtual void vf42(); virtual void vf43();
    virtual void vf44(); virtual void vf45(); virtual void vf46(); virtual void vf47();
    virtual void vf48(); virtual void vf49(); virtual void vf50(); virtual void vf51();
    virtual void vf52(); virtual void vf53(); virtual void vf54(); virtual void vf55();
    virtual void set_text(char** text, long id); // vt +0xE0
    char gap_004[0xD4];
    long field_D8;
    char gap_0DC[0xAC];
    TTextPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long, char*, long, char, long, char, long, char*);
    void scroll(int a, int b, int c);
    void set_alignment(int v, int h);
    void set_text_color(unsigned long c1, unsigned long c2);
    void set_highlight_text_color(unsigned long c1, unsigned long c2);
};

class TEasy_Panel {
public:
    char gap_000[0x14];
    long base_width;       // +14
    long base_height;      // +18
    char gap_01C[4];
    TDrawArea* draw_area;  // +20
    char gap_024[0xB4];
    long error_flag;       // +D8
    char gap_0DC[0x18];
    long ideal_width;      // +F4
    long ideal_height;     // +F8
    char gap_0FC[0x22C];
    unsigned long text_color1;  // +328
    unsigned long text_color2;  // +32C
    unsigned long focus_color1; // +330
    unsigned long focus_color2; // +334

    int create_text(TPanel* parent, TTextPanel** out, char** text, long text_id,
                    long x, long y, long w, long h, long font_id,
                    int center_h, int center_v);
};

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** out, char** text, long text_id,
                             long x, long y, long w, long h, long font_id,
                             int center_h, int center_v)
{
    long ideal_x = (x * this->base_width) / this->ideal_width;
    long ideal_y = (y * this->base_height) / this->ideal_height;
    long ideal_w = (w * this->base_width) / this->ideal_width;
    long ideal_h = (h * this->base_height) / this->ideal_height;

    *out = new TTextPanel;
    if (*out != 0 && (*out)->field_D8 == 0) {
        RGE_Font* font;
        if (font_id >= 0) {
            font = rge_base_game->get_font(font_id);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*out)->setup(this->draw_area, parent, ideal_x, ideal_y, ideal_w, ideal_h,
                          font->font, font->font_wid, font->font_hgt,
                          0, 0, 0, 0, 0, 0, 0) != 0) {
            (*out)->set_text(text, text_id);
            (*out)->scroll(6, 0, 1);
            if (center_h != 0 && center_v != 0) {
                (*out)->set_alignment(0, 0);
            } else if (center_h != 0) {
                (*out)->set_alignment(3, 0);
            } else if (center_v != 0) {
                (*out)->set_alignment(0, 1);
            } else {
                (*out)->set_alignment(3, 1);
            }
            (*out)->set_text_color(this->text_color1, this->text_color2);
            (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    this->error_flag = 1;
    return 0;
}
