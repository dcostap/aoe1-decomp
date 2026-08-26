#ifndef AOE1_DLG_DIP_CONTEXT_H
#define AOE1_DLG_DIP_CONTEXT_H

// Canonical declarations for the original C:\\msdev\\work\\age1_x1\\dlg_dip.cpp
// module.  The wrapper defines DLG_DIP_SHARED_CONTEXT before including this
// header and then includes owners in their PDB source-line order.

#include <stdio.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

typedef int PositionMode;
typedef int RedrawMode;
typedef int FormatType;

class TDrawArea;
class TDrawSystem;
class TShape;
class TTextPanel;
class TButtonPanel;
class TInputPanel;
class TEditPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class RGE_Color_Table;
class RGE_Game_World;
class RGE_Player;
class TRIBE_Player;
class TRIBE_Player_Tech;
class RGE_Object_List;
class RGE_Static_Object;
class RGE_Font;
class TCommunications_Handler;
class TRIBE_Command;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long,
                                  long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    virtual void draw_background(int);

    char gap_04[8];
    long pnl_x;
    long pnl_y;
    char gap_14[12];
    TDrawArea* render_area;
    char gap_24[0xD0];

    TDrawArea* renderArea();
    void set_help_info(long, long);
    void set_curr_child(TPanel*);
    char* get_string(int);
};

class TEasy_Panel : public TPanel {
public:
    long ideal_width;
    long ideal_height;
    char info_file_name[260];
    long info_id;
    TShape* background_pic;
    TShape* background_pic2;
    void* palette;
    char cursor_file[260];
    long cursor_id;
    int background_pos;
    int use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char pad_326[2];
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    unsigned long state_color1;
    unsigned long state_color2;
    char popup_info_file_name[260];
    long popup_info_id;
    TShape* button_pics;
    RGE_Color_Table* shadow_color_table;
    long shadow_amount;
    unsigned char background_color1;
    unsigned char background_color2;
    unsigned char pad_456[2];
    int enable_ime;
    unsigned char help_mode;
    unsigned char pad_45D[3];
    int stock_brush;
    void* brush;
    unsigned long brush_color;
    TDrawArea* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;

    virtual void draw();
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long,
                              long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long,
                              long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long,
                                 long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long,
                                    long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long,
                            long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long, long,
                            long, long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long,
                            long, int, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, FormatType,
                             long, long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, FormatType,
                            long, long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long,
                                 long, long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel*, TTextPanel*, long,
                                 long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);

    long get_popup_info_id();
    char* get_popup_info_file();
    void setup_popup_help();
};

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char*);
    virtual ~TDialogPanel();
    virtual int setup(TDrawArea*, TPanel*, long, long, char*, long, int);

    void* dlg_wnd;
    TPanel* save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;
};

class TScreenPanel : public TEasy_Panel {
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;
    int hotkey_shift;

    virtual ~TButtonPanel();
    int get_state();
    void set_text(short, char*);
    void set_picture(short, TShape*, short);
    void setDrawType(int);
    void set_radio_info(TButtonPanel**, short);
    void set_disabled(int);
    void set_radio_button();
    void set_fn(int);
    void show(int);
    void slot5(int);
};

class TShape {
public:
    char data[0x20];
    TShape(char*, int);
    ~TShape();
    unsigned char shape_draw(TDrawArea*, long, long, int, unsigned char,
                             unsigned char*);
};

class RGE_Color_Table {
public:
    char gap_00[0x25];
    unsigned char color_index;
    unsigned char pad_26;
    unsigned char table[0x100];
};

class RGE_Object_List {
public:
    char gap_00[4];
    void* list;
    RGE_Static_Object* find_by_master_id(long, float, float, unsigned char,
                                         unsigned char, RGE_Static_Object*);
};

class RGE_Static_Object {
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects;
    char gap_2C[0x18];
    char* name;
    char gap_48[2];
    short id;
    char gap_4C[4];
    float* attributes;
    char gap_54[0x2C];
    unsigned char game_status;
    unsigned char resigned;
    unsigned char pad_82[2];
    unsigned char* relations;
    char gap_88[0x7C];
    unsigned char allied_victory;
    unsigned char master_player_id;
    unsigned char pad_106[2];
    RGE_Color_Table* color_table;
    char gap_10C[0x114];

    unsigned char get_allied_victory();
    unsigned char relation(long);
};

class TRIBE_Player_Tech {
public:
    char gap_00[0x10];
    short get_tech_state(short);
};

class TRIBE_Player : public RGE_Player {
public:
    TRIBE_Player_Tech* tech_tree;
    void command_give_attribute(int, int, float, float);
};

class TRIBE_Command {
public:
    void command_allied_victory(short, unsigned char);
    void command_relation(short, short, short);
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char pad_3E[2];
    RGE_Player** players;
    char gap_44[0x18];
    TRIBE_Command* commands;
    char gap_60[0x1C];
    short curr_player;
};

class RGE_Font {
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void language(int, int, int, char*, int);

    char gap_04[0x1AC];
    int prog_mode;
    char gap_1B4[0x240];
    RGE_Game_World* world;
    char gap_3F8[0x604];
    int save_paused;

    RGE_Font* get_font(int);
    RGE_Player* get_player();
    int multiplayerGame();
    int numberPlayers();
    int playerID(int);
    int singlePlayerGame();
    void set_paused(int, int);
};

class TCommunications_Handler {
public:
    int GetPlayerHumanity(unsigned int);
};

class TPanelSystem {
public:
    int setCurrentPanel(char*, int);
    int destroyPanel(char*);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern TPanelSystem panel_system;
extern int allow_user_commands;
extern float DAT_0056f880;
extern float DAT_0056f884;
extern double DAT_0056f888;
extern float DAT_0056f890;
extern float DAT_0056f894;

extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(
    void*, unsigned int, unsigned int, void*);
extern "C" int __cdecl _ASMSet_Color_Xform(int);

void* __cdecl operator new(unsigned int);
void __cdecl operator_delete(void*);

class TribeDiplomacyDialog : public TDialogPanel {
public:
    virtual ~TribeDiplomacyDialog();

protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);

public:
    TTextPanel* title[8];
    TTextPanel* playerName[8];
    TTextPanel* playerVictoryScores[8];
    TTextPanel* playerCivilization[8];
    TTextPanel* needMarket;
    TButtonPanel* goldTributeButton[8];
    TButtonPanel* woodTributeButton[8];
    TButtonPanel* foodTributeButton[8];
    TButtonPanel* stoneTributeButton[8];
    TButtonPanel* allyButton[24];
    TButtonPanel* allianceButton;
    TButtonPanel* okButton;
    TButtonPanel* clearButton;
    TButtonPanel* cancelButton;
    TButtonPanel* help_button;
    TShape* buttonPics;
    TShape* backgroundPics;
    float foodTotal;
    float woodTotal;
    float goldTotal;
    float stoneTotal;
    TTextPanel* playerFood;
    TTextPanel* playerGold;
    TTextPanel* playerWood;
    TTextPanel* playerStone;
    float goldTributeAmount[8];
    float foodTributeAmount[8];
    float stoneTributeAmount[8];
    float woodTributeAmount[8];
    int cur_player_row;
    int tribute_flag;

    TribeDiplomacyDialog(TScreenPanel*);

protected:
    int check_gold();
    int check_wood();
    int check_food();
    int check_stone();
    virtual void draw();
};

#endif
