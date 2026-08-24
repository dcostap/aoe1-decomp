#ifndef SCR_VC_CONTEXT_H
#define SCR_VC_CONTEXT_H

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class TPanel;
class TTextPanel;
class TButtonPanel;
class TScrollBarPanel;
class TPicture;
class TPanelSystem;
class RGE_Scenario;
class RGE_World;
class RGE_Base_Game;

class TPanel {
public:
    virtual ~TPanel();
    virtual long handle_idle();
    virtual void set_active(int active);
    virtual void set_fixed_position(long x, long y, long width, long height);
    virtual void draw();
    virtual void draw_setup(int value);
    virtual void draw_finish();
    virtual void set_ideal_size(long width, long height);

    void set_curr_child(TPanel* child);
    char* get_string(int lang_id);

    TPanel* previous_panel;             // +0x04
    TPanel* previous_modal_panel;       // +0x08
    long pnl_x;                         // +0x0C
    long pnl_y;                         // +0x10
    long pnl_wid;                       // +0x14
    long pnl_hgt;                       // +0x18
    char* panel_name;                   // +0x1C
    TDrawArea* render_area;             // +0x20
    tagRECT clip_rect;                  // +0x24
    long position_mode;                 // +0x34
    int need_redraw;                    // +0x38
    char gap_3C[4];                     // +0x3C
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void setText(char* text);
    virtual void textExtra(int a, int b, int c, int d, int e, int f, int g);
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    void set_radio_info(TPanel* group, int param);
    void set_radio_button();
};

class TScrollBarPanel : public TPanel {
public:
    virtual ~TScrollBarPanel();
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual void set_ideal_size(long width, long height);
    virtual int create_button(TPanel* panel, TButtonPanel** out, int lang, int a4,
                              int x, int y, int w, int h, int a, int b, int c);
    virtual int create_button(TPanel* panel, TButtonPanel** out, char* lang, char* a4,
                              int x, int y, int w, int h, int a, int b, int c);
    virtual int create_text(TPanel* panel, TTextPanel** out, int lang,
                            int x, int y, int w, int h, int font, int center_h,
                            int center_v, int word_wrap);
    virtual int create_text(TPanel* panel, TTextPanel** out, char** lang,
                            int x, int y, int w, int h, int font, int center_h,
                            int center_v, int word_wrap);
    virtual int create_text(TPanel* panel, TTextPanel** out, char* text,
                            int x, int y, int w, int h, int font, int center_h,
                            int center_v, int word_wrap);
    virtual int create_auto_scrollbar(TScrollBarPanel** out, TTextPanel* text, int param);
    virtual void position_panel(TPanel* panel, int x, int y, int w, int h);
    long action(TPanel* sender, long actionType,
                unsigned long param3, unsigned long param4);
    void setup_shadow_area(int param);

    char gap_40[0x2DC];                // +0x40 .. +0x31B
    int field_31C;                     // +0x31C
    unsigned char desc[6];             // +0x320
    char gap_326[0x12E];               // +0x326 .. +0x453
    unsigned char background_color1;   // +0x454
    char gap_455[0x1F];                // +0x455 .. +0x473
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    virtual void draw();
    int setup(TDrawArea* draw_area, char* info_file, long info_id, int param);

    char gap_474[4];                   // +0x474 .. +0x477
};

class TPicture {
public:
    void Draw(TDrawArea* draw_area, long x, long y, int dst_x, int dst_y);
};

class TDrawArea {
public:
    void Clear(tagRECT* rect, int color);
    unsigned char* Lock(char* name, int wait);
    void Unlock(char* name);
};

class TPanelSystem {
public:
    TEasy_Panel* currentPanel();
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

class RGE_Scenario {
public:
    char* Get_scenario_name();
    char* Get_message(long id);
};

class RGE_World {
public:
    char gap_00[0x5C];
    RGE_Scenario* scenario;            // +0x5C
};

class RGE_Prog_Info {
public:
    char gap_00[0x8A8];
    int use_sound;                      // +0x8A8
};

class TSound_Driver {
public:
    int stop_stream();
    int stream_file(char* file_name, int param_2, long param_3);
};

class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info;           // +0x0C
    char gap_10[0x3C];
    TDrawArea* draw_area;               // +0x4C
    char gap_50[0x10];
    union {
        TSound_Driver* sound_system;    // +0x60
        TSound_Driver* sound_driver;    // +0x60
    };
    char gap_64[0x174];
    int input_enabled;                  // +0x1D8
    char gap_1DC[0x218];
    RGE_World* world;                   // +0x3F4
    char gap_3F8[0x608];
    int save_paused;                    // +0xA00

    int singlePlayerGame();
    void set_paused(int paused, int non_user_pause);
    int create_game_screen();
    void enable_input();
};

class TRIBE_Game : public RGE_Base_Game {
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;

class TRIBE_Mission_Screen : public TScreenPanel {
public:
    TTextPanel* title;                  // +0x478
    TTextPanel* list;                   // +0x47C
    TScrollBarPanel* scroll_bar;        // +0x480
    TButtonPanel* ok_button;            // +0x484
    TButtonPanel* text_buttons[3];      // +0x488
    unsigned char game_flag;            // +0x494
    char pad_495[3];
    TPicture* vc_back_bmp;              // +0x498

    TRIBE_Mission_Screen(char* info_file, unsigned char game_flag,
                         TPicture* vc_back_bmp);
    virtual ~TRIBE_Mission_Screen();
    virtual long handle_idle();
    virtual void draw();
    virtual long action(TPanel* sender, long actionType,
                        unsigned long param3, unsigned long param4);
    virtual long key_down_action(long param_1, short param_2, int param_3,
                                 int param_4, int param_5);
};

#endif
