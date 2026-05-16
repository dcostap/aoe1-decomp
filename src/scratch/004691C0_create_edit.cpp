// VA: 004691C0 TEasy_Panel::create_edit (442 B)
// PDB source: Panel_ez.cpp lines 1399-1439
// Attempt log: see bottom

// Forward declarations
struct TPanel;
struct TEditPanel;
struct TDrawArea;
struct RGE_Font;
struct RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;

struct TEasy_Panel {
    void* vtable;
    int field_04;
    int field_08;
    int field_0C;
    int gap_10[2];
    int field_14;       // +0x14 = ideal_width?
    int field_18;       // +0x18 = ideal_height?
    int field_1C;
    int field_20;       // +0x20 = TDrawArea*
    char gap_24[0xD8 - 0x24];
    int field_D8;       // +0xD8 = some flag
    char gap_DC[0xF4 - 0xDC];
    int field_F4;       // +0xF4 = divisor for width?
    int field_F8;       // +0xF8 = divisor for height?
    char gap_FC[0x320 - 0xFC];
    unsigned char bevel_color1;  // +0x320
    unsigned char bevel_color2;  // +0x321
    unsigned char bevel_color3;  // +0x322
    unsigned char bevel_color4;  // +0x323
    unsigned char bevel_color5;  // +0x324
    unsigned char bevel_color6;  // +0x325
    char gap_326[0x328 - 0x326];
    int text_color1;    // +0x328
    int text_color2;    // +0x32C
    int focus_color1;   // +0x330
    int focus_color2;   // +0x334
    char gap_338[0x454 - 0x338];
    unsigned char background_color1; // +0x454
    char gap_455[0x464 - 0x455];
    void* brush;        // +0x464
    int brush_color;    // +0x468
    int use_bevels;     // +0x31C
    char gap_31D_320[3]; // padding

    int create_edit(TPanel* p1, TEditPanel** p2, char* p3, short p4, int p5,
                    long p6, long p7, long p8, long p9, long p10,
                    int p11, int p12);
};

struct TEditPanel {
    void* vtable;
    int field_04;
    // ... up to 0x16C
    char whole[0x16C];
    
    TEditPanel();
    int setup(TDrawArea* parent, int x, int y, int w, int h, long p7,
              void* font, short p9, char* p10, int p11, int multiline);
    void set_bevel_info(int type, unsigned char c1, unsigned char c2,
                        unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6);
    void set_text_color(int c1, int c2);
    void set_highlight_text_color(int c1, int c2);
    void set_back_color(unsigned char bg, void* brush, int brush_color);
    void set_ime_info(int p1, int p2);
};

struct TPanel {
    void* vtable;
};

struct TDrawArea {
    void* vtable;
};

struct RGE_Font {
    void* vtable;
    int font;
};

struct RGE_Base_Game {
    void* vtable;
    RGE_Font* get_font(int font_id);
};

int TEasy_Panel::create_edit(TPanel* p1, TEditPanel** p2, char* p3, short p4, int p5,
                              long p6, long p7, long p8, long p9, long p10,
                              int p11, int p12)
{
    int w = this->field_14;
    int d1 = this->field_F4;
    int x = (p6 * w) / d1;
    
    int h = this->field_18;
    int d2 = this->field_F8;
    int y = (h * p7) / d2;
    
    int width = (p8 * w) / d1;
    
    TEditPanel* edit = new TEditPanel;
    if (edit) {
        edit = (TEditPanel*)edit;
    } else {
        edit = 0;
    }
    
    *p2 = edit;
    
    if (edit && edit->field_04 == 0) {
        if (p10 < 0)
            p10 = 10;
        
        RGE_Font* font = rge_base_game->get_font(p10);
        
        int multiline = (p5 != 7) ? 1 : 0;
        
        if (edit->setup((TDrawArea*)this->field_20, x, y, width, p9,
                        0, font->font, p4, p3, p5, multiline)) {
            ((void)0);
            
            if (this->use_bevels) {
                edit->set_bevel_info(3,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color3, this->bevel_color4,
                    this->bevel_color5, this->bevel_color6);
            }
            
            edit->set_text_color(this->text_color1, this->text_color2);
            edit->set_highlight_text_color(this->focus_color1, this->focus_color2);
            edit->set_back_color(this->background_color1, this->brush, this->brush_color);
            edit->set_ime_info(p11, p12);
            
            return 1;
        }
    }
    
    this->field_D8 = 1;
    return 0;
}
