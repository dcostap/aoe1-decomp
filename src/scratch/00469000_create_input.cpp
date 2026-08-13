// 00469000 TEasy_Panel::create_input
// Source: Panel_ez.cpp lines 1345-1380
// attempt 1: natural source from packet/decompiler; first 156 bytes exact but VC5 put success epilogue before failure block (failure target outside original body), edit diff 55B.
// attempt 2: added volatile result local and common return; first 156 bytes still exact, failure block moved before common epilogue, best edit diff 52B. Kept for accepted_drift review.
// attempt 3: nonvolatile result local with goto common return; VC5 optimized back to early success return, no improvement.
// attempt 4: result initialized to 0 plus final if(result==0) failure write; worsened register allocation from offset 78.
// attempt 5: used dead parameter as return result; caused broad register allocation drift like attempt 4.
// attempt 6: explicit ok/fail labels without volatile; no improvement over natural early-return tail split.
// attempt 7: register out pointer local; no codegen change in natural body.
// attempt 8: removed /GX diagnostically; object lost EH frame and .text was too small (400B), reverted.
// attempt 9: /GX /Ob0; no codegen change, reverted.
// attempt 10: reviewed setup arg surface/order and vtable slot declarations; current call order/body matches original through setup/bevel/color calls; remaining drift is tail/return lowering.
// attempt 11: typed the PDB/SDK FormatType enum through create_input and setup; emitted code is unchanged, confirming the remaining first hunk is tail CFG placement.
// shardE probe: a switch around setup produced a 38-byte diagnostic basin, but only by falling into the failure return; restoring success return restored the natural 180-byte basin.
// ACCEPTED_DRIFT suggestion: with volatile result, all functional calls/memory effects match; extra writes are only to this function's stack result slot before common epilogue, and branch distances/tail layout differ. Needs review; not promoted.
// session 2026-08-11: baseline rebuilt the volatile common-return candidate at 451 bytes; natural direct returns and nonvolatile result/goto joins both rebuilt at 457 bytes with the same 156-byte prefix and the success epilogue before failure.
// session probes: a register result, a destructor declaration, and the packet-indicated virtual create_input ABI (with the proven gap adjustment) did not change that tail family; /O1 introduced an extra EH helper and broad structural drift.
// final session source restores the natural typed factory form; remaining blocker is the VC5 /GX shared EH failure-tail placement (oracle success jump over failure block to one epilogue).

class TPanel {};
class TDrawArea {};
class TDigital {};
enum FormatType { FormatSingleLine = 0, FormatMultiLine = 7 };
class RGE_Font { public: void* font; long font_wid; long font_hgt; };
class RGE_Base_Game { public: RGE_Font* get_font(int id); };
extern RGE_Base_Game* rge_base_game;

class TInputPanel {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
    virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
    virtual void vfC0(); virtual void vfC4(); virtual void vfC8(); virtual void vfCC();
    virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
    virtual void vfE0(); virtual void vfE4(); virtual void vfE8();
    virtual void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6); // +EC
    char gap_004[0xD4];
    long field_D8;
    char gap_0DC[0xDC];
    TInputPanel();
    ~TInputPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, long, char, char, int, int, short, TDigital*, char*, FormatType);
    void set_text_color(unsigned long c1, unsigned long c2);
    void set_highlight_text_color(unsigned long c1, unsigned long c2);
};

class TEasy_Panel {
public:
    char gap_000[0x10];
    long base_width;
    long base_height;
    char gap_01C[4];
    TDrawArea* draw_area;
    char gap_024[0xB4];
    long error_flag;       // +D8
    char gap_0DC[0x18];
    long ideal_width;      // +F4
    long ideal_height;     // +F8
    char gap_0FC[0x220];
    int use_bevels;        // +31C
    unsigned char bevel_color1; // +320
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_326[2];
    unsigned long text_color1;  // +328
    unsigned long text_color2;  // +32C
    unsigned long focus_color1; // +330
    unsigned long focus_color2; // +334

    virtual int create_input(TPanel* parent, TInputPanel** out, char* text, short max_len, FormatType format,
                             long x, long y, long w, long h, long font_id);
};

int TEasy_Panel::create_input(TPanel* parent, TInputPanel** out, char* text, short max_len, FormatType format,
                              long x, long y, long w, long h, long font_id)
{
    long ideal_x = (x * this->base_width) / this->ideal_width;
    long ideal_y = (y * this->base_height) / this->ideal_height;
    long ideal_w = (w * this->base_width) / this->ideal_width;
    long ideal_h = (h * this->base_height) / this->ideal_height;

    *out = new TInputPanel;
    if (*out != 0 && (*out)->field_D8 == 0) {
        RGE_Font* font;
        if (font_id >= 0) {
            font = rge_base_game->get_font(font_id);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*out)->setup(this->draw_area, parent, ideal_x, ideal_y, ideal_w, ideal_h,
                          font->font, font->font_wid, font->font_hgt,
                          0, 0, 0, 1, 0xff, 0xff, max_len, 0, text, format) != 0) {
            if (this->use_bevels != 0) {
                (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2,
                                       this->bevel_color3, this->bevel_color4,
                                       this->bevel_color5, this->bevel_color6);
            }
            (*out)->set_text_color(this->text_color1, this->text_color2);
            (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }

    this->error_flag = 1;
    return 0;
}
