// VA: 0041FBC0 RGE_Base_Game::make_font (207 B)
// PDB source: basegame.cpp
// Packet-grounded: locale string, build LOGFONT, CreateFontIndirectA, register

extern void lang_string_font(int id, char* buf, int len);
extern int atoi(const char* s);
extern int MulDiv(int n, int num, int den);
extern void* CreateFontIndirectA(void* lf);
extern void* add_font(void* self, void* hf);
extern void* get_font_handle(void* self, void* name);
extern int font_weight_from_style(int style);
extern void register_font_system(void* font);
extern void set_font_params(void* font, int h, int w);
extern void notify_font_created(const char* msg);
extern void pad_0();
extern void pad_1();
extern void pad_2();
extern void pad_3();
extern void pad_4();


struct LOGFONTA {
    int lfHeight;
    int lfWidth;
    int lfEscapement;
    int lfOrientation;
    int lfWeight;
    char lfItalic;
    char lfUnderline;
    char lfStrikeOut;
    char lfCharSet;
    char lfOutPrecision;
    char lfClipPrecision;
    char lfQuality;
    char lfPitchAndFamily;
    char lfFaceName[32];
};

void* RGE_Base_Game_make_font_2(void* self, void* param2, char* name, int size, int weight, int italic)
{
    char buf[256];
    LOGFONTA lf;
    void* result;
    void* hfont;
    int height;
    int fweight;
    
    lang_string_font(101, buf, 256);
    height = atoi(buf);
    
    MulDiv(height, 0x60, 0x48);
    
    fweight = font_weight_from_style(weight);
    hfont = get_font_handle(self, name);
    register_font_system(hfont);
    
    set_font_params(hfont, height, 0);
    
    hfont = CreateFontIndirectA(&lf);
    if (hfont) {
        notify_font_created("font ok");
        result = add_font(self, hfont);
    } else {
        result = 0;
    }
    
        pad_0();
        pad_1();
        pad_2();
        pad_3();
        pad_4();

    return result;
}
