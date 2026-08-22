#ifndef PANEL_BUTTON_TEXT_CONTEXT_H
#define PANEL_BUTTON_TEXT_CONTEXT_H

typedef unsigned char uchar;

class TDrawArea;
class TDigital;
class TShape;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;

enum FormatType {
    FormatSingleLine = 0,
    FormatMultiLine = 7
};

struct RGE_Font {
    void* font;
    long font_wid;
    long font_hgt;
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x14 - 0x04];
    union { long width; long base_width; long field_14; long pnl_wid; };
    union { long height; long base_height; long field_18; long pnl_hgt; };
    char gap_1C[4];
    union { TDrawArea* draw_area; TDrawArea* render_area; };
    char gap_24[0xD8 - 0x24];
    union { long failed; long error_code; long error_flag; long error; long field_D8; };
    char gap_DC[0xF4 - 0xDC];
};

class RGE_Base_Game {
public:
    TDigital* get_sound(int id);
    RGE_Font* get_font(int id);
};

extern RGE_Base_Game* rge_base_game;

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x2B8 - 0xF4];
    TButtonPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, int, TDigital*, int, long);
    void set_sound_number(long sound_id);
    void set_text_info(char*, void*, int, int, int, int);
    void set_text(short mode, char* text);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_text_color(int, int, int);
    void set_highlight_text_color(int, int, int);
};

class TTextPanelBase {
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
    // The executable puts the char** overload at +0xE0 and char* at +0xE8.
    // A distinct recovery name prevents VC5 from regrouping both overloads.
    virtual void set_text_list(char** text, short id);
};

class TTextPanel : public TTextPanelBase {
public:
    virtual void vf57();
    virtual void set_text(char* text);
    char gap_004[0xD4];
    union { long field_D8; long error_code; };
    char gap_0DC[0xAC];
    TTextPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, long, char, long, char, long, char*);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, unsigned char, int, unsigned char, short, long);
    void scroll(int, int, int);
    void set_alignment(int, int);
    void set_word_wrap(int);
    void set_text_color(unsigned long, unsigned long);
    void set_highlight_text_color(unsigned long, unsigned long);
    void set_scrollbar(TScrollBarPanel*, int);
};

class TShape {};

class TScrollBarPanel : public TPanel {
public:
    char data_F4[0x108 - 0xF4];
    TShape* button_pics;
    int back_frame;
    int up_frame;
    int down_frame;
    int tab_frame;
    char data_11C[0x1B8 - 0x11C];
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char data_1C2[0x1C4 - 0x1C2];
    virtual ~TScrollBarPanel();
    TScrollBarPanel();
    long setup(void*, TPanel*, long, long, long, long, char*, char*, char*, char*,
               long, long, TPanel*, long, int);
    void set_buttons(TShape*, int, int, int, int);
    void set_bevel_info(int, int, int, int, int, int, int);
};

class TVerticalSliderPanel : public TScrollBarPanel {
public:
    char data[0x1CC - 0x1C4];
    virtual ~TVerticalSliderPanel();
    TVerticalSliderPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, char*, char*, long,
               long, long, long, int, int);
};

class THorizontalSliderPanel : public TScrollBarPanel {
public:
    char data[0x1CC - 0x1C4];
    virtual ~THorizontalSliderPanel();
    THorizontalSliderPanel();
    long setup(void*, TPanel*, long, long, long, long, char*, char*, long,
               long, long, long, int, int);
};

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
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    char gap_004[0xD4];
    long field_D8;
    char gap_0DC[0xDC];
    TInputPanel();
    ~TInputPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, long, char, char, int, int, short, TDigital*, char*, FormatType);
    void set_text_color(unsigned long, unsigned long);
    void set_highlight_text_color(unsigned long, unsigned long);
};

class TEditPanel : public TPanel {
public:
    char whole[0x16C - 0xF4];
    TEditPanel();
    virtual ~TEditPanel();
    int setup(TDrawArea*, TPanel*, int, int, int, int, void*, short, char*, int, int);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_text_color(int, int);
    void set_highlight_text_color(int, int);
    void set_back_color(void*, int, unsigned char);
    void set_ime_info(int, int);
};

class TEasy_Panel : public TPanel {
public:
    long ideal_width;
    long ideal_height;
    char gap_FC[0x31C - 0xFC];
    long use_bevels;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    char gap_326[2];
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    unsigned long state_color1;
    unsigned long state_color2;
    char gap_340[0x448 - 0x340];
    TShape* button_pics;
    char gap_44C[0x454 - 0x44C];
    unsigned char background_color1;
    char gap_455[0x464 - 0x455];
    void* brush;
    int brush_color;

    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long,
                              long, long, long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long,
                            long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long, long,
                            long, long, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, FormatType,
                             long, long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, int, long, long,
                            long, long, long, int, int);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long,
                                 long, long, long, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long, long,
                                   long, long, long, long, long);
};

#endif
