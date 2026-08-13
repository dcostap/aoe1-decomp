// VA: 004691C0 TEasy_Panel::create_edit (442 B)
// PDB source: Panel_ez.cpp lines 1399-1439
// Attempt log:
// - Baseline decompiler-shaped stubs had the wrong TEditPanel size, error
//   offset, TEasy_Panel styling offset, setup arity, and font field.
// - Restored the period typed layouts and /GX context: TPanel owns +14/+18,
//   +20, and +D8; TEasy_Panel owns +F4/+F8 and +31C onward; TEditPanel is
//   0x16C bytes.  This moved the check from a 415-byte mismatch to 267.
// - Restored the real setup(TDrawArea*, TPanel*, ...) ABI, direct out-slot
//   construction, positive font guard, promoted bevel colors, and
//   brush/brush-color/background argument order.  The body through all calls
//   is now byte-aligned; remaining drift is VC5 success/failure epilogue
//   placement (54 positional bytes, +19 emitted bytes).
// - Common result/goto, volatile-result, initialized-result, destructor, and
//   register-result probes did not change the best ordinary codegen basin.
// - Mirrored same-TU create_auto_scrollbar's direct success/failure returns;
//   VC5 emitted the same 461-byte basin, so no control-flow lead remains.
// - A natural local TEditPanel owner before publishing the out slot left the
//   emitted code unchanged; restored the direct out-slot construction.
// - Inverted the allocation/error guard with one result return; VC5 normalized
//   it to the same 461-byte basin and retained the duplicated return tail.
// - Used explicit fail and done labels after separate allocation and error
//   guards; VC5 again emitted the same 461-byte basin, so the tail remains a
//   compiler/codegen blocker rather than an unresolved call or layout issue.
// Left in scratch: typed source is behaviorally aligned with all 9 calls and
//   proven field accesses; only the compiler's duplicated return tail remains.

// Canonical layouts recovered from the Panel_ez/pnl_edit surfaces.  The base
// panel owns the width/height/draw-area/error fields; TEasy_Panel owns the
// ideal dimensions and edit styling fields.
class TPanel;
class TEditPanel;
class TDrawArea;
class RGE_Font;
class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x10];
    int width;                  // +0x14
    int height;                 // +0x18
    char gap_1C[4];
    TDrawArea* draw_area;       // +0x20
    char gap_24[0xB4];
    int error;                  // +0xD8
    char gap_DC[0x18];
};

class TEasy_Panel : public TPanel {
public:
    int ideal_width;            // +0xF4
    int ideal_height;           // +0xF8
    char gap_FC[0x31C - 0xFC];
    int use_bevels;             // +0x31C
    unsigned char bevel_color1; // +0x320
    unsigned char bevel_color2; // +0x321
    unsigned char bevel_color3; // +0x322
    unsigned char bevel_color4; // +0x323
    unsigned char bevel_color5; // +0x324
    unsigned char bevel_color6; // +0x325
    char gap_326[0x328 - 0x326];
    int text_color1;            // +0x328
    int text_color2;            // +0x32C
    int focus_color1;           // +0x330
    int focus_color2;           // +0x334
    char gap_338[0x454 - 0x338];
    unsigned char background_color1; // +0x454
    char gap_455[0x464 - 0x455];
    void* brush;                // +0x464
    int brush_color;            // +0x468

    virtual int create_edit(TPanel* p1, TEditPanel** p2, char* p3, short p4, int p5,
                            long p6, long p7, long p8, long p9, long p10,
                            int p11, int p12);
};

class TEditPanel : public TPanel {
public:
    char whole[0x16C - 0xF4];

    TEditPanel();
    virtual ~TEditPanel();
    int setup(TDrawArea* draw_area, TPanel* parent, int x, int y, int w, int h,
              void* font, short p9, char* p10, int p11, int multiline);
    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
    void set_text_color(int c1, int c2);
    void set_highlight_text_color(int c1, int c2);
    void set_back_color(void* brush, int brush_color, unsigned char bg);
    void set_ime_info(int p1, int p2);
};

class TDrawArea {
public:
    void* vtable;
};

class RGE_Font {
public:
    void* font;
};

struct RGE_Base_Game {
    void* vtable;
    RGE_Font* get_font(int font_id);
};

int TEasy_Panel::create_edit(TPanel* p1, TEditPanel** p2, char* p3, short p4, int p5,
                              long p6, long p7, long p8, long p9, long p10,
                              int p11, int p12)
{
    int x = (p6 * this->width) / this->ideal_width;
    int y = (this->height * p7) / this->ideal_height;
    int width = (p8 * this->width) / this->ideal_width;

    *p2 = new TEditPanel;
    if (*p2 != 0 && (*p2)->error == 0) {
        RGE_Font* font;
        if (p10 >= 0) {
            font = rge_base_game->get_font(p10);
        } else {
            font = rge_base_game->get_font(10);
        }
        
        int multiline = (p5 != 7) ? 1 : 0;
        
        if ((*p2)->setup(this->draw_area, p1, x, y, width, p9,
                         font->font, p4, p3, p5, multiline)) {
            
            if (this->use_bevels) {
                (*p2)->set_bevel_info(3,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color3, this->bevel_color4,
                    this->bevel_color5, this->bevel_color6);
            }
            
            (*p2)->set_text_color(this->text_color1, this->text_color2);
            (*p2)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            (*p2)->set_back_color(this->brush, this->brush_color, this->background_color1);
            (*p2)->set_ime_info(p11, p12);

            return 1;
        }
    }

    this->error = 1;
    return 0;
}
