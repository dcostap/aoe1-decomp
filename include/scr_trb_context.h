#ifndef SCR_TRB_CONTEXT_H
#define SCR_TRB_CONTEXT_H

class TDrawArea {
public:
    char gap_00[0x18];
    int width;
};

class TDigital;
class TTextPanel;
class TButtonPanel;
class TPicturePanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect();
    virtual void set_rect2();
    virtual void set_color();
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);

    char gap_04[0x8];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[4];
    TDrawArea* render_area;
    char gap_24[0xB4];
    int setup_error;
    char gap_DC[0x18];

    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, short count);
};

class TPicturePanel : public TPanel {
public:
    char gap_F4[0x28];
    TPicturePanel();
    long setup(TDrawArea* draw, TPanel* parent, long x, long y,
               long width, long height, char* picture, long resource,
               int size_from_picture, int keep_loaded);
};

class RGE_Font {
public:
    void* font;
    int font_wid;
    int font_hgt;
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x94];

    TTextPanel();
    long setup(TDrawArea* draw, TPanel* parent, long x, long y,
               long width, long height, void* font, long font_wid,
               long font_hgt, char* back_picture, int fill,
               unsigned char back_color, int outline,
               unsigned char outline_color, short fixed_len, char* text);
    void set_alignment(int vertical, int horizontal);
    // The canonical inherited virtual surface is unresolved in this pass.
    // Keep this observed owner on a direct declaration until that ABI is proved.
    void set_text(char* text);
    void scroll(int scroll_type, short amount, int param_3);
};

class TButtonPanel : public TPanel {
public:
    TButtonPanel();
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;
    char gap_2A0[0x18];

    long setup(TDrawArea* draw, TPanel* parent, long x, long y,
               long width, long height, long draw_type, TDigital* sound,
               long notify_type, long button_id);
    void set_text_info(char* text, void* font, long font_wid,
                       long font_hgt, long x, long y);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    long action(TPanel* sender, long actionType, unsigned param3,
                unsigned param4);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(TDrawArea* draw, char* text, long id, int value);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
    RGE_Font* get_font(int index);
    TDigital* get_sound(int index);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int a);
    int destroyPanel(char* name);
};

enum { NotifyAction = 1 };

class TribeSelectTribeScreen : public TScreenPanel {
public:
    TPicturePanel* background;
    TTextPanel* title;
    TTextPanel* tribeText;
    TButtonPanel* tribeButton[9];
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    char** screenText;
    int numLines;

    virtual ~TribeSelectTribeScreen();
    TribeSelectTribeScreen();
    long action(TPanel* sender, long actionType, unsigned param3,
                unsigned param4);
    void fillTribeText(int index);
    char* tribeName(int index);
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;

#endif
