#ifndef PANEL_BUTTON_TEXT_CONTEXT_H
#define PANEL_BUTTON_TEXT_CONTEXT_H

typedef unsigned char uchar;

class TDrawSystem;
class TDrawArea;
class RGE_Color_Table;
struct tagRECT;
class TDigital;
class TShape;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class TListPanel;
class TDropDownPanel;

class TDrawSystem {
public:
    char gap_00[0x28];
    unsigned long Flags;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x14];
    long width;
    long height;
    TDrawArea(char*, int);
    int Init(TDrawSystem*, long, long, int, int);
    void Clear(tagRECT*, int);
    unsigned char* Lock(char*, int);
    void SetShadowTable(class RGE_Color_Table*);
    void DrawShadowBox(long, long, long, long);
    void Unlock(char*);
};

struct RGE_Font {
    void* font;
    long font_wid;
    long font_hgt;
};
typedef RGE_Font FontInfo;

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x14 - 0x04];
    union { long width; long base_width; long screen_width; long field_14; long pnl_wid; };
    union { long height; long base_height; long screen_height; long field_18; long pnl_hgt; };
    char* panelNameValue;
    union { TDrawArea* draw_area; TDrawArea* render_area; };
    char gap_24[0xD8 - 0x24];
    union { long failed; long error_code; long error_flag; long error; long field_D8; };
    char gap_DC[0xF4 - 0xDC];
    long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    void set_positioning(int, long, long, long, long, long, long, long, long,
                         TPanel*, TPanel*, TPanel*, TPanel*);
    void draw_rect2(unsigned char);
    void draw_setup(int);
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
    void set_state_info(short state);
    void setDrawType(int type);
    void set_picture(short state, TShape*, short frame);
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
    virtual void set_bevel_info(int, int, int, int, int, int, int); // +0xEC
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

class TShape {
public:
    char data[0x20];
    TShape(char* filename, long id);
    ~TShape();
    int is_loaded();
    unsigned char shape_minmax(long&, long&, long&, long&, long);
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char, unsigned char*);
};

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
    enum FormatType {
        FormatSingleLine = 0,
        FormatMultiLine = 7
    };
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
    enum FormatType {
        FormatSingleLine = 0,
        FormatMultiLine = 7
    };
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

class TListPanel {
public:
    char gap_00[0xD8];
    long error;
    TListPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, unsigned char, int, unsigned char, short, char**, int);
    void scroll_cur_line(unsigned char, int, unsigned char);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_text_color(unsigned long, unsigned long);
    void set_highlight_text_color(unsigned long, unsigned long);
};

class TDropDownPanel : public TPanel {
public:
    TTextPanel* val_panel;
    TButtonPanel* btn_panel;
    TListPanel* list_panel;
    char gap_100[0x144 - 0x100];
    TDropDownPanel();
    long setup(TDrawArea*, TPanel*, void*, int, int, int, char, int, int, int, int,
               int, int, int, int, int, int, char*, int, int, char**, int, int,
               char*, char*, char*, char*, int, int);
    void set_buttons(TShape*, int, int, int, int, int);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_val_text_color(unsigned long, unsigned long);
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
    RGE_Color_Table* shadow_color_table;
    char gap_450[4];
    unsigned char background_color1;
    char gap_455[0x0F];
    void* brush;
    int brush_color;
    long allow_shadow_area;

    long setup(TDrawArea*, TPanel*, char*, long, int, long, long, long, long, int);
    void setup_shadow_area(int);
    void draw_setup(int);
    void draw();
    void set_info_file(char*, long);
    void set_use_bevels(int);
    int set_background(char*, long);
    int set_background2(char*, long);
    void set_shadow_amount(long);
    int set_palette(char*, long);
    int set_cursor(char*, long);
    void set_background_pos(int);
    void set_background_colors(unsigned char, unsigned char);
    void set_bevel_colors(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
    void set_text_colors(unsigned long, unsigned long);
    void set_focus_colors(unsigned long, unsigned long);
    void set_state_colors(unsigned long, unsigned long);
    void set_button_pics(char*, long);
    void set_popup_info_file(char*, long);
    virtual void draw_background(int);

protected:
    virtual void set_ideal_size(long width, long height);

    // Panel_ez.cpp records these factory owners as protected virtual methods.
    // Keep MAE decoration and the PDB virtual-slot order in the shared TU.
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long,
                              long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long,
                              long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long,
                            long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long,
                            long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long, long,
                            long, long, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, TInputPanel::FormatType,
                             long, long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, TEditPanel::FormatType, long, long,
                            long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long, long,
                                 long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long,
                                 long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);
};

#endif
