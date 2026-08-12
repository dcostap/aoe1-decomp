// attempt 1: natural TEasy_Panel text factory from Ghidra/PDB line shape
// Attempt log:
// - Baseline matches the natural typed factory through the first 156 bytes,
//   all 9 ordered calls, saved registers, and 17 exact blocks; rebuilt is 436
//   bytes versus 413.  The remaining structural gap is the success return
//   epilogue: the oracle jumps over a cold failure tail at +0x17C, while VC5
//   emits a success epilogue before that tail.
// - An initialized result local added an 8-byte frame and broad drift; rolled
//   back.  Goto/result-join, explicit result assignments, and negative early
//   failure guards all emitted the same 436-byte basin as the baseline.
// - Adding a virtual TTextPanel destructor as an extra slot moved the set_text
//   call to +0xEC; replacing slot zero preserved +0xE8 but did not move the
//   return tail.  stdio/string header context was also an emitted duplicate.
// - Making create_text virtual worsened early member offsets/register coloring;
//   rolled back.  Best source is restored; remaining lead is the original
//   source's cold failure/common-epilogue topology, not call or layout parity.
// - A register result with a common source return was a codegen duplicate; no
//   stack home or CFG change appeared.  Restored the natural typed factory.

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
    virtual void vf56(); virtual void vf57(); virtual void set_text(char* text);
    char gap_004[0xD4];
    long field_D8;
    char gap_0DC[0xAC];
    TTextPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long, char*, long, char, long, char, long, char*);
    void set_alignment(int v, int h);
    void set_word_wrap(int wrap);
    void set_text_color(unsigned long c1, unsigned long c2);
    void set_highlight_text_color(unsigned long c1, unsigned long c2);
};

class TEasy_Panel {
public:
    char gap_000[0x14];
    long base_width;
    long base_height;
    char gap_01C[4];
    TDrawArea* draw_area;
    char gap_024[0xD0];
    long ideal_width;
    long ideal_height;
    char gap_0FC[0x22C];
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    char gap_338[0x10];
    void* button_pics;
    int create_text(TPanel* parent, TTextPanel** out, char* text, long p4, long p5, long p6, long p7, long font_id, int center_h, int center_v, int word_wrap);
};

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** out, char* text, long p4, long p5, long p6, long p7, long font_id, int center_h, int center_v, int word_wrap) {
    long ideal_x = (p4 * this->base_width) / this->ideal_width;
    long ideal_y = (p5 * this->base_height) / this->ideal_height;
    long ideal_w = (p6 * this->base_width) / this->ideal_width;
    long ideal_h = (p7 * this->base_height) / this->ideal_height;

    *out = new TTextPanel;
    if (*out != 0 && (*out)->field_D8 == 0) {
        RGE_Font* font;
        if (font_id >= 0) {
            font = rge_base_game->get_font(font_id);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*out)->setup(this->draw_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, font->font, font->font_wid, font->font_hgt, 0, 0, 0, 0, 0, 0, 0) != 0) {
            if (center_h != 0 && center_v != 0) {
                (*out)->set_alignment(0, 0);
            } else if (center_h != 0) {
                (*out)->set_alignment(3, 0);
            } else if (center_v != 0) {
                (*out)->set_alignment(0, 1);
            } else {
                (*out)->set_alignment(3, 1);
            }
            (*out)->set_word_wrap(word_wrap);
            (*out)->set_text(text);
            (*out)->set_text_color(this->text_color1, this->text_color2);
            (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    *(long*)(this->gap_000 + 0xD8) = 1;
    return 0;
}
