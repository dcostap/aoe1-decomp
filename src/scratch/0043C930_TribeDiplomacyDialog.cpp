// VA: 0043C930 TribeDiplomacyDialog::TribeDiplomacyDialog
// PDB: dlg_dip.cpp:77-369
//
// Baseline reconstruction: the dialog uses the real TPanel -> TEasy_Panel ->
// TDialogPanel hierarchy, named owned panel arrays, direct constructor/setup
// calls, and the observed /GX lifetime around the two TShape allocations.
// The original executable remains the behavior and exact-byte oracle.
//
// Attempt log:
// - baseline pending: canonical dlg_dip hierarchy and named panel ownership;
//   period-plausible setup order reconstructed from the packet and same-TU
//   exact donors. /GX is selected because the constructor has the VC5 EH frame.
// - added the observed civilization language lookup, title font lookup, and
//   early tab-order counter initialization; the frame then matched 0x124.
// - the player-row packet uses named wood/ally cursors.  The +/-8 and +16
//   resource views are the proven contiguous gold/wood/food/stone arrays, not
//   an invented object layout.  The row's humanity gate is kept separate from
//   the per-row disable-font flag and the radio-group cursor.
// - final bounded pass: the nested current-player guard did not change codegen.
//   Combining the current-player and relation-zero cases restored all three
//   distinct set_radio_button call sites.  The source remains a natural guard
//   followed by the relation-one and fallback arms; validation is 3425 rebuilt
//   bytes versus 3457 original, 0x12C versus 0x124 frame, and 112/112 calls.
// - direct world->players[player_id] reloads (instead of a loop-local player)
//   moved the structural diff from 3062 to 2959 and the frame from 0x12C to
//   0x128, but allowed VC5 to tail-merge two set_radio_button sites.  Keeping
//   radio selection on the named group cursor restored the 0x124 frame but
//   remained 110/112 calls and 2979 bytes.  Restored the validated clean form.
// - structural lead: use the named per-row ally cursor as the radio group and
//   reuse the existing loop index.  This follows the original tabCount cursor,
//   which advances by 0xc, and removes the separate group-offset home.  The
//   rebuilt frame moved to 0x128 and the positional diff improved to 2997;
//   keep this natural cursor topology as the best current reconstruction.
// - current bounded pass: restored the four total-field zero stores, used
//   assignment-in-the-null-guard for both TShape allocations, and selected
//   radio buttons through a row-local ally offset.  The last clean check is
//   3474 rebuilt bytes, 0x128 frame, 112/112 calls, and 2753 positional bytes.
//   This is still nonexact.  The H21 row local improves the ordered body
//   without changing the call set.  The direct player alias and raw cursor
//   spelling compiled to the same code and were not retained.
// - durable next lead: recover the original 0x124 frame and the 0x55D047 EH
//   handler value.  The body now has exact islands, but the constructor still
//   enters a different compiler frame basin.
// - claim sa-d1e42032: removing the row-player alias recovered the 0x124 frame
//   and improved the diff to 2711 bytes, but merged two radio call sites. The
//   alias is required for the current 112-call source shape.
// - claim sa-d1e42032: separate humanity storage, radio-row aliases, predicate
//   splits, register hints, and loop-index scopes did not improve the clean
//   source. A delayed player alias kept the frame but changed direct targets.
//   All such variants were restored to the pinned H21 source.
// - claim sa-a5acd99e-r1: restored the source literals and the separate
//   multiplayer humanity result.  The best reduced source keeps 112/112 calls,
//   a 0x128 frame, and 2723 differing bytes.  The original keeps a 0x124 frame.
//   Direct player aliases, byte cursors, cursor scopes, and register spelling
//   did not recover the original setup or frame.  The current source is the
//   best behavior-preserving checkpoint from this claim and remains nonexact.

#include <stdio.h>

#ifndef DLG_DIP_SHARED_CONTEXT
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

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long,
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

    char gap_04[0x1C];
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

    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long, long,
                              long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long, long,
                              long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long, long,
                            int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long, long, long,
                            long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long, long,
                            int, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, FormatType, long, long,
                             long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, FormatType, long, long,
                            long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long, long, long,
                                 long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long, long, long,
                                 long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long, long, long,
                                  long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long, long, long, long,
                                  long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);

    long get_popup_info_id();
    char* get_popup_info_file();
};

class TDialogPanel : public TEasy_Panel {
public:
    void* dlg_wnd;
    TPanel* save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;

    TDialogPanel(char*);
    virtual int setup(TDrawArea*, TPanel*, long, long, char*, long, int);
};

class TScreenPanel : public TEasy_Panel {
};

class TTextPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;
    int hotkey_shift;

    void set_picture(short, TShape*, short);
    void setDrawType(int);
    void set_radio_info(TButtonPanel**, short);
    void set_disabled(int);
    void set_radio_button();
};

class TShape {
public:
    char data[0x20];
    TShape(char*, int);
};

class RGE_Color_Table {
public:
    char gap_00[0x25];
    unsigned char color_index;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects;
    char gap_2C[0x18];
    char* name;
    char gap_48[8];
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

class TRIBE_Player : public RGE_Player {
public:
    TRIBE_Player_Tech* tech_tree;
};

class TRIBE_Player_Tech {
public:
    char gap_00[0x10];
    short get_tech_state(short);
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char pad_3E[2];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
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

    RGE_Font* get_font(int);
    RGE_Player* get_player();
    int multiplayerGame();
    int numberPlayers();
    int playerID(int);
};

class RGE_Object_List {
public:
    char gap_00[4];
    void* list;

    RGE_Static_Object* find_by_master_id(long, float, float, unsigned char, unsigned char,
                                         RGE_Static_Object*);
};

class RGE_Static_Object {
};

class TCommunications_Handler {
public:
    int GetPlayerHumanity(unsigned int);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern float DAT_0056f880;
extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(
    void*, unsigned int, unsigned int, void*);

void* __cdecl operator new(unsigned int);

class TribeDiplomacyDialog : public TDialogPanel {
public:
    virtual ~TribeDiplomacyDialog();
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

    int check_gold();
    int check_wood();
    int check_food();
    int check_stone();

    TribeDiplomacyDialog(TScreenPanel*);
};
#endif

TribeDiplomacyDialog::TribeDiplomacyDialog(TScreenPanel* parent)
    : TDialogPanel("Diplomacy Dialog")
{
    TButtonPanel** button;
    int y;
    RGE_Game_World* world;
    int humanity;
    int player_id;
    int i;
    TButtonPanel** tab_buttons;
    int tab_count = 0;
    int disable_buttons;
    tagPALETTEENTRY palette_color;
    char temp_str[100];
    TPanel* tab_list[35];

    for (i = 0; i < 8; ++i) {
        this->title[i] = 0;
        this->playerName[i] = 0;
        this->playerVictoryScores[i] = 0;
        this->playerCivilization[i] = 0;
        this->goldTributeButton[i] = 0;
        this->woodTributeButton[i] = 0;
        this->foodTributeButton[i] = 0;
        this->stoneTributeButton[i] = 0;
        this->goldTributeAmount[i] = 0.0f;
        this->foodTributeAmount[i] = 0.0f;
        this->stoneTributeAmount[i] = 0.0f;
        this->woodTributeAmount[i] = 0.0f;
    }

    for (i = 0; i < 24; ++i) {
        this->allyButton[i] = 0;
    }

    this->allianceButton = 0;
    this->okButton = 0;
    this->cancelButton = 0;
    this->clearButton = 0;
    this->help_button = 0;
    this->needMarket = 0;
    this->buttonPics = 0;
    this->backgroundPics = 0;
    this->playerWood = 0;
    this->playerStone = 0;
    this->playerGold = 0;
    this->playerFood = 0;
    this->woodTotal = 0.0f;
    this->stoneTotal = 0.0f;
    this->foodTotal = 0.0f;
    this->goldTotal = 0.0f;
    this->tribute_flag = 0;

    if (this->setup(parent->renderArea(), parent, 0x271, 0x195,
                    parent->get_popup_info_file(), parent->get_popup_info_id(), 1) == 0) {
        return;
    }

    // BINARY NOTE: VC5 keeps the allocation result through this null join.
    if ((this->buttonPics = new TShape("tradicon.shp", 0xC62C)) == 0) {
        return;
    }

    if ((this->backgroundPics = new TShape("dlg_plbn.shp", 0xC63A)) == 0) {
        return;
    }

    if (this->create_text(this, &this->title[0], 0x267B,
                          0x48, 5, 0x1F4, 0x1E,
                          (long)rge_base_game->get_font(1), 1, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->needMarket, 0x2687,
                          0x1B8, 0x6E, 0xAF, 0x3C, 0x0B, 1, 1, 1) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[1], 0x2686,
                          5, 0x32, 0x82, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[2], 0x267C,
                          0x89, 0x32, 0x50, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[3], 0x267D,
                          0xEB, 0x32, 0x46, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[4], 0x267E,
                          0x122, 0x32, 0x46, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[5], 0x267F,
                          0x168, 0x32, 0x46, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }

    sprintf(temp_str + 4, this->get_string(0x2680),
            (long)(rge_base_game->get_player()->attributes[46] * DAT_0056f880));
    if (this->create_text(this, &this->title[6], temp_str + 4,
                          0x1B8, 0x32, 0xB4, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[7], 0x2681,
                          0x13E, 0x14A, 300, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }

    this->cur_player_row = -1;
    world = rge_base_game->world;
    if (world->player_num - 1 > 0) {
        player_id = 1;
        y = 0x50;
        disable_buttons = 0;
        button = this->woodTributeButton;
        tab_buttons = this->allyButton;
        do {
            RGE_Player* player = *(RGE_Player**)((char*)world->players +
                                                  ((char*)button - (char*)this - 0x530));

            GetPaletteEntries(this->palette, player->color_table->color_index,
                              1, &palette_color);
            disable_buttons = 0;

            if (rge_base_game->prog_mode == 5 || player_id == world->curr_player ||
                player->game_status != 0) {
                humanity = 1;
            } else {
                humanity = 0;
            }

            if (player_id == world->curr_player) {
                this->cur_player_row = player_id - 1;
            }

            if (player->game_status == 2) {
                disable_buttons = 1;
            } else {
                if (rge_base_game->multiplayerGame()) {
                    int humanity_result = 0;
                    int j = 1;
                    int humanity_count = rge_base_game->numberPlayers();
                    if (j <= humanity_count) {
                        do {
                        if (rge_base_game->playerID(j) == player_id) {
                            int h = comm->GetPlayerHumanity(j);
                            if (h == 2 || h == 4) {
                                humanity_result = h;
                            }
                        }
                            ++j;
                            humanity_count = rge_base_game->numberPlayers();
                        } while (j <= humanity_count);
                    }
                    if (humanity_result != 2 && humanity_result != 4) {
                        disable_buttons = 1;
                    }
                }
            }

            if (this->create_text(this, &this->playerName[player_id - 1], player->name,
                                  5, y, 0x82, 0x1E,
                                  disable_buttons ? 7 : 0x0B, 0, 1, 0) == 0) {
                return;
            }
            rge_base_game->language(0x69, player->master_player_id, 0,
                                    temp_str, 100);
            if (this->create_text(this, &this->playerCivilization[player_id - 1], temp_str,
                                  0x89, y, 0x64, 0x1E, 0x0B, 0, 1, 0) == 0) {
                return;
            }

            if (player_id != world->curr_player) {
                if (this->create_radio_button(this,
                                              &tab_buttons[0],
                                              0xF0, y, 0x1E, 0x1E, 0, 0) == 0) {
                    return;
                }
                tab_buttons[0]->set_help_info(0x7684, -1);
                if (this->create_radio_button(this,
                                              &tab_buttons[1],
                                              0x136, y, 0x1E, 0x1E, 0, 0) == 0) {
                    return;
                }
                tab_buttons[1]->set_help_info(0x7685, -1);
                if (this->create_radio_button(this,
                                              &tab_buttons[2],
                                              0x17C, y, 0x1E, 0x1E, 0, 0) == 0) {
                    return;
                }
                tab_buttons[2]->set_help_info(0x7686, -1);

                TButtonPanel** group = tab_buttons;
                for (i = 0; i < 3; ++i) {
                    group[i]->set_radio_info(group, 3);
                    if (rge_base_game->prog_mode == 5) {
                        group[i]->set_disabled(1);
                    }
                }

                // BINARY NOTE: creation uses tab_buttons, but selection uses
                // the owning ally row.  The executable has three call sites.
                unsigned char relation = rge_base_game->get_player()->relation(player_id);
                int row = (player_id - 1) * 3;
                if (player_id == world->curr_player || relation == 0) {
                    this->allyButton[row]->set_radio_button();
                } else {
                    if (relation == 1) {
                        this->allyButton[row + 1]->set_radio_button();
                    } else {
                        this->allyButton[row + 2]->set_radio_button();
                    }
                }
            }

            if (humanity == 0) {
                if (this->create_button(this, button,
                                        -1, 0, 0x1B8, y, 0x28, 0x1E, 0x0B, 0, 0) == 0) {
                    return;
                }
                if (this->create_button(this, button + 8,
                                        -1, 0, 0x1E0, y, 0x28, 0x1E, 0x0B, 0, 0) == 0) {
                    return;
                }
                if (this->create_button(this, button - 8,
                                        -1, 0, 0x208, y, 0x28, 0x1E, 0x0B, 0, 0) == 0) {
                    return;
                }
                if (this->create_button(this, button + 16,
                                        -1, 0, 0x230, y, 0x28, 0x1E, 0x0B, 0, 0) == 0) {
                    return;
                }

                button[0]->set_picture(0, this->buttonPics, 0);
                button[8]->set_picture(0, this->buttonPics, 2);
                button[-8]->set_picture(0, this->buttonPics, 3);
                button[16]->set_picture(0, this->buttonPics, 1);
                button[0]->setDrawType(4);
                button[8]->setDrawType(4);
                button[-8]->setDrawType(4);
                button[16]->setDrawType(4);
                button[0]->set_help_info(0x7687, -1);
                button[8]->set_help_info(0x7688, -1);
                button[-8]->set_help_info(0x7689, -1);
                button[16]->set_help_info(0x768A, -1);
            }

            y += 0x1E;
            ++button;
            tab_buttons += 3;
            ++player_id;
        } while (player_id < world->player_num);
    }

    if (this->create_check_box(this, &this->allianceButton,
                               0x11A, 0x147, 0x1E, 0x1E, 0, 0) == 0) {
        return;
    }
    this->allianceButton->draw_background(rge_base_game->get_player()->get_allied_victory());
    this->allianceButton->set_help_info(0x768C, -1);
    if (rge_base_game->prog_mode == 5) {
        this->allianceButton->set_disabled(1);
    }

    if (rge_base_game->prog_mode != 5) {
        if (this->create_button(this, &this->okButton,
                                0xFA1, 0, 0x0A, 0x16F, 0xBE, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->okButton->set_help_info(0x7531, -1);
        if (this->create_button(this, &this->clearButton,
                                0x2683, 0, 0xD7, 0x16F, 0xBE, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->clearButton->set_help_info(0x768B, -1);
    }

    if (this->create_button(this, &this->cancelButton,
                            0xFA2, 0, 0x1A4, 0x16F, 0xBE, 0x1E, 0, 0, 0) == 0) {
        return;
    }
    this->cancelButton->set_help_info(0x7532, -1);
    this->cancelButton->hotkey = 0x1B;
    this->cancelButton->hotkey_shift = 0;

    if (this->create_button(this, &this->help_button,
                            0xFA9, 0, 0x1F4, 0x147, 0x1E, 0x1E, 0, 0, 0) == 0) {
        return;
    }

    sprintf(temp_str + 4, "%ld",
            (long)(rge_base_game->get_player()->attributes[1] - this->woodTotal));
    if (this->create_text(this, &this->playerWood, temp_str + 4,
                          0x1B8, this->cur_player_row * 0x1E + 0x50,
                          0x28, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    sprintf(temp_str + 4, "%ld",
            (long)(rge_base_game->get_player()->attributes[0] - this->foodTotal));
    if (this->create_text(this, &this->playerFood, temp_str + 4,
                          0x1E0, this->cur_player_row * 0x1E + 0x50,
                          0x28, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    sprintf(temp_str + 4, "%ld",
            (long)(rge_base_game->get_player()->attributes[3] - this->goldTotal));
    if (this->create_text(this, &this->playerGold, temp_str + 4,
                          0x208, this->cur_player_row * 0x1E + 0x50,
                          0x28, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    sprintf(temp_str + 4, "%ld",
            (long)(rge_base_game->get_player()->attributes[2] - this->stoneTotal));
    if (this->create_text(this, &this->playerStone, temp_str + 4,
                          0x230, this->cur_player_row * 0x1E + 0x50,
                          0x28, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }

    RGE_Static_Object* market =
        rge_base_game->get_player()->objects->find_by_master_id(
            0x54, -1.0f, -1.0f, 1, 2, 0);
    if (market == 0) {
        this->tribute_flag = 0;
        this->needMarket->set_active(1);
        this->title[6]->set_active(0);
        this->playerWood->set_active(0);
        this->playerFood->set_active(0);
        this->playerGold->set_active(0);
        this->playerStone->set_active(0);
    } else {
        this->tribute_flag = 1;
        this->needMarket->set_active(0);
        this->title[6]->set_active(1);
        this->playerWood->set_active(1);
        this->playerFood->set_active(1);
        this->playerGold->set_active(1);
        this->playerStone->set_active(1);
    }

    if (((TRIBE_Player*)rge_base_game->get_player())->tech_tree->get_tech_state(0x1E) == 3) {
        this->title[6]->set_active(0);
    }

    this->check_gold();
    this->check_wood();
    this->check_food();
    this->check_stone();
    this->set_curr_child(this->okButton);

    if (this->okButton != 0) {
        tab_list[tab_count++] = this->okButton;
    }
    if (this->clearButton != 0) {
        tab_list[tab_count++] = this->clearButton;
    }
    if (this->cancelButton != 0) {
        tab_list[tab_count++] = this->cancelButton;
    }
    this->set_tab_order(tab_list, (short)tab_count);
}
