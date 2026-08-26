// VA: 00498A50 player_changed (scr_game.cpp)
// Initial reconstruction: use the recovered TRIBE_Screen_Game ownership and
// the natural panel/shape calls rather than the decompiler's byte-offset view.
// Attempt log:
// - baseline: canonical TScreenPanel/TRIBE_Screen_Game fields, typed player and
//   panel calls, natural new/delete TShape ownership; default flags omitted the
//   original EH frame and produced a 205-byte-short build.
// - flags: /GX restored the 0x204 frame, four callee-saves, all 73 calls, and
//   exact size; this is the binary-supported donor context (scr_game.cpp EH).
// - control-flow/liveness: direct player->culture guard with the field on the
//   left recovered the original ECX save-culture/EAX culture load and compare;
//   saved-culture locals and direct assignment variants were unchanged or worse.
// - behavior: using str rather than decompiler str+4 was required by transient
//   push accounting; it raised exact-block coverage to 91% and shape similarity
//   to 98.08%.
// - MATCH breakthrough (3 changes, each verified independently):
//   (1) branch-duplicated set_info_file/set_popup_info_file and set_button_pics
//       calls (culture == 4 literal pushed twice, else branch CSEs culture+id
//       into edi) recovered the original branch-local argument pushes;
//   (2) the 17-item border publication loop keeps the button load at the store
//       site instead of hoisting it before the i<12 guard;
//   (3) `save_culture = player->culture;` (CSE with the guard load) selects the
//       original EAX store instead of the EBX clamp copy.
//   These reduced the diff from 1790 bytes to 0.
// - surface: replaced unnamed slot scaffolding with the canonical
//   TPanel/TButtonPanel surfaces (TPanel vt[0..8] = dtor/setup/set_rect/...
//   /set_redraw per donor-slot evidence; TButtonPanel : TPanel with virtual
//   ~TButtonPanel; RGE_Base_Game/RGE_Player virtual dtors; real TPanel fields
//   previousPanelValue..panelNameValue). Codegen unchanged (still exact).
// - owner/boundary: PDB names TRIBE_Screen_Game::player_changed in scr_game.cpp
//   lines 3048-3255, body 00498A50-004992C8. 00498950 is jump-table data in
//   do_button_action, not a function.
// - exact-finish audit: the common-call walkback removed one set_info_file call
//   and missed by 1784 bytes. The save-culture walkback changed one byte. The
//   direct conditional border assignment stayed exact and is the smaller form.
//   Final validation preserves the 0x204 EH frame, ebx/ebp/esi/edi saves, all 73
//   ordered calls, stack homes, shape publication, delete/new fault order, and
//   ret 8 cleanup. No synthetic owner, assembly, volatility, or config change.

#include <stdio.h>

#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Player;
class TShape;
class TButtonPanel;
class TRIBE_Panel_Button;
class TRIBE_Main_View;
class TRIBE_Diamond_Map_View;
class TRIBE_Panel_Inven;
class TRIBE_Panel_Object;
class TTextPanel;

class TDrawArea;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();                                        // vt[0]
    virtual long setup(TDrawArea* area, TPanel* parent, long x,
                       long y, long wid, long hgt, unsigned char mode);  // vt[1]
    virtual void set_rect(tagRECT rect);                      // vt[2]
    virtual void set_rect(long x, long y, long wid, long hgt); // vt[3]
    virtual void set_color(unsigned char color);              // vt[4]
    virtual void set_active(int active);                      // vt[5]
    virtual void set_positioning(int mode, long x, long y, long wid,
                                 long hgt, long x2, long y2, TPanel* p1,
                                 TPanel* p2, TPanel* p3, TPanel* p4); // vt[6]
    virtual void set_fixed_position(long x, long y, long wid, long hgt); // vt[7]
    virtual void set_redraw(int mode);                        // vt[8]

    TPanel* previousPanelValue;   // +0x04
    TPanel* previousModalPanelValue; // +0x08
    long pnl_x;                   // +0x0C
    long pnl_y;                   // +0x10
    long pnl_wid;                 // +0x14
    long pnl_hgt;                 // +0x18
    char* panelNameValue;         // +0x1C
    char gap_20[0xD4];            // 0x20..0xF3
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
    unsigned char gap_326[2];
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    unsigned long state_color1;
    unsigned long state_color2;
    char popup_info_file_name[260];
    long popup_info_id;
    TShape* button_pics;
    void* shadow_color_table;
    long shadow_amount;
    unsigned char background_color1;
    unsigned char background_color2;
    unsigned char gap_456[2];
    int enable_ime;
    unsigned char help_mode;
    unsigned char gap_45D[3];
    int stock_brush;
    void* brush;
    unsigned long brush_color;
    void* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;

    void set_info_file(char* filename, long id);
    void set_popup_info_file(char* filename, long id);
    void set_button_pics(char* filename, long id);
    void set_bevel_colors(unsigned char a, unsigned char b, unsigned char c,
                          unsigned char d, unsigned char e, unsigned char f);
};

class TScreenPanel : public TEasy_Panel {
};

class TShape {
public:
    char data[0x20];
    TShape(char* filename, long resource_id);
    ~TShape();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x1B0];
    int game_mode;
    RGE_Player* get_player();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x46];
    short id;
    char gap_4C[8];
    unsigned char culture;
};

class RGE_View {
public:
    void set_player(RGE_Player* player);
};

class RGE_Diamond_Map {
public:
    void set_player(RGE_Player* player);
};

class TRIBE_Main_View : public RGE_View {
};

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map {
};

class TRIBE_Panel_Inven {
public:
    void set_player(RGE_Player* player);
    void set_text_color(unsigned long color1, unsigned long color2);
};

class TRIBE_Panel_Object {
public:
    void set_player(RGE_Player* player);
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();

    char gap_F4[0x1C4];

    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
    void set_picture(short state, TShape* picture, short frame);
    long get_id();
    void set_text_color(int state, unsigned long color1, unsigned long color2);
};

class TRIBE_Panel_Button : public TButtonPanel {
public:
    char gap_2B8[0x0C];
    TShape* border_pic;
};

class TTextPanel {
public:
    void set_text_color(unsigned long color1, unsigned long color2);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game : public TScreenPanel {
public:
    TShape* game_screen_pic;
    TShape* button_border1_pic;
    TShape* button_other_pic;
    TShape* button_border2_pic;
    TShape* button_border3_pic;
    TShape* button_cmd_pic;
    TShape* button_tech_pic;
    TShape* button_unit_pic;
    TShape* button_bldg_pics[5];
    TShape* more_cancel_pic;
    short more_frame;
    short cancel_frame;
    short unselect_frame;
    unsigned char gap_4B6[2];
    TRIBE_Main_View* main_view;
    TRIBE_Diamond_Map_View* map_view;
    TRIBE_Panel_Inven* inven_panel;
    TRIBE_Panel_Object* object_panel;
    TRIBE_Panel_Button* button_panel[17];
    void* text_line_panel;
    void* quit_message_panel;
    void* time_panel;
    void* countdown_clock[10];
    void* pop_panel;
    void* message_panel;
    void* message_panel2;
    void* message_panel3;
    void* message_panel4;
    void* message_panel5;
    void* message_panel6;
    void* chat_panel[8];
    void* tool_box;
    TTextPanel* age_panel;
    void* pause_text;
    void* fps_panel;
    void* score_panel[8];
    void* log_text;
    void* log_scrollbar;
    void* world;
    unsigned long update_interval;
    unsigned long last_update_time;
    unsigned long map_redraw_interval;
    unsigned long last_map_redraw_time;
    void* game_obj;
    short sel_count;
    unsigned char gap_5CE[2];
    char gap_5D0[0x144];
    int save_culture;
    long save_screen_width;

    void game_mode_changed(int new_mode, int old_mode);
    void object_changed();
    void age_changed();
    void setup_buttons();
    void player_changed(int old_player, int new_player);
};
#endif

void TRIBE_Screen_Game::player_changed(int old_player, int new_player) {
    char str[512];
    RGE_Player* player = rge_base_game->get_player();

    this->main_view->set_player(player);
    this->map_view->set_player(player);
    this->inven_panel->set_player(player);
    this->object_panel->set_player(player);

    this->game_mode_changed(rge_base_game->game_mode, rge_base_game->game_mode);
    this->object_changed();
    this->age_changed();

    if (player->id != 0) {
        if (player->culture != this->save_culture || this->pnl_wid != this->save_screen_width) {
            int culture = player->culture;
            this->save_culture = player->culture;
            this->save_screen_width = this->pnl_wid;

            if (culture >= 5) {
                culture = 0;
            }

            sprintf(str, (char*)0x5864E8, culture);

            if (culture == 4) {
                this->set_info_file(str, 0xCF08);
                this->set_popup_info_file(str, 0xCF08);
            } else {
                this->set_info_file(str, culture + 0xC356);
                this->set_popup_info_file(str, culture + 0xC356);
            }

            sprintf(str, (char*)0x5864E0, culture);

            if (culture == 4) {
                this->set_button_pics(str, 0xCF0C);
            } else {
                this->set_button_pics(str, culture + 0xC5AD);
            }

            switch (culture) {
            case 0:
                this->set_bevel_colors(0x7E, 0x6D, 0x6F, 0x6F, 0xEE, 0x38);
                break;
            case 1:
                this->set_bevel_colors(0x72, 0x73, 0x74, 0x74, 0xB7, 0xB8);
                break;
            case 2:
                this->set_bevel_colors(0xB9, 0x77, 0x78, 0x78, 0x78, 0x79);
                break;
            case 3:
                this->set_bevel_colors(0x8A, 0xED, 0xEE, 0xEE, 0x38, 0x95);
                break;
            case 4:
                this->set_bevel_colors(0x73, 0x74, 0x75, 0x75, 0x76, 0x77);
                break;
            }

            this->button_panel[12]->set_bevel_info(3, this->bevel_color1,
                this->bevel_color2, this->bevel_color3, this->bevel_color4,
                this->bevel_color5, this->bevel_color6);
            this->button_panel[13]->set_bevel_info(3, this->bevel_color1,
                this->bevel_color2, this->bevel_color3, this->bevel_color4,
                this->bevel_color5, this->bevel_color6);
            this->button_panel[14]->set_bevel_info(3, this->bevel_color1,
                this->bevel_color2, this->bevel_color3, this->bevel_color4,
                this->bevel_color5, this->bevel_color6);
            this->button_panel[15]->set_bevel_info(4, this->bevel_color1,
                this->bevel_color2, this->bevel_color3, this->bevel_color4,
                this->bevel_color5, this->bevel_color6);
            this->button_panel[16]->set_bevel_info(4, this->bevel_color1,
                this->bevel_color2, this->bevel_color3, this->bevel_color4,
                this->bevel_color5, this->bevel_color6);

            if (this->button_border1_pic != 0) {
                delete this->button_border1_pic;
            }
            sprintf(str, (char*)0x5864D0, culture);
            if (culture == 4) {
                this->button_border1_pic = new TShape(str, 0xCF0E);
            } else {
                this->button_border1_pic = new TShape(str, culture + 0xC619);
            }

            if (this->button_other_pic != 0) {
                delete this->button_other_pic;
            }
            sprintf(str, (char*)0x5864C0, culture);
            if (culture == 4) {
                this->button_other_pic = new TShape(str, 0xCF11);
            } else {
                this->button_other_pic = new TShape(str, culture + 0xC625);
            }

            if (this->button_border2_pic != 0) {
                delete this->button_border2_pic;
            }
            sprintf(str, (char*)0x5864B0, culture);
            if (culture == 4) {
                this->button_border2_pic = new TShape(str, 0xCF0F);
            } else {
                this->button_border2_pic = new TShape(str, culture + 0xC61D);
            }

            if (this->button_border3_pic != 0) {
                delete this->button_border3_pic;
            }
            sprintf(str, (char*)0x5864A0, culture);
            if (culture == 4) {
                this->button_border3_pic = new TShape(str, 0xCF10);
            } else {
                this->button_border3_pic = new TShape(str, culture + 0xC63B);
            }

            if (this->game_screen_pic != 0) {
                delete this->game_screen_pic;
            }

            int game_pic_id;
            if (this->pnl_wid >= 0x400 && this->pnl_hgt >= 0x300) {
                sprintf(str, (char*)0x586494, culture);
                if (culture == 4) {
                    game_pic_id = 0xCF14;
                } else {
                    game_pic_id = culture + 0xC635;
                }
            } else if (this->pnl_wid >= 0x320 && this->pnl_hgt >= 0x258) {
                sprintf(str, (char*)0x586488, culture);
                if (culture == 4) {
                    game_pic_id = 0xCF13;
                } else {
                    game_pic_id = culture + 0xC631;
                }
            } else {
                sprintf(str, (char*)0x58647C, culture);
                if (culture == 4) {
                    game_pic_id = 0xCF12;
                } else {
                    game_pic_id = culture + 0xC62D;
                }
            }
            this->game_screen_pic = new TShape(str, game_pic_id);

            for (int i = 0; i < 0x11; ++i) {
                this->button_panel[i]->border_pic =
                    (i < 0x0C) ? this->button_border1_pic : this->button_border2_pic;
            }

            if (this->pnl_wid >= 0x320 && this->pnl_hgt >= 0x258) {
                this->more_cancel_pic = this->button_cmd_pic;
            } else {
                this->more_cancel_pic = this->button_other_pic;
            }

            this->button_panel[5]->set_picture(0, this->more_cancel_pic,
                                                this->more_frame);
            if (this->button_panel[11]->get_id() == 6) {
                this->button_panel[11]->set_picture(0, this->more_cancel_pic,
                                                    this->unselect_frame);
            } else {
                this->button_panel[11]->set_picture(0, this->more_cancel_pic,
                                                    this->cancel_frame);
            }

            if (culture == 2 || culture == 3 || culture == 4) {
                this->inven_panel->set_text_color(0xFFFFFF, 0);
                this->age_panel->set_text_color(0xFFFFFF, 0);
                this->button_panel[12]->set_text_color(0, 0xFFFFFF, 0);
                this->button_panel[13]->set_text_color(0, 0xFFFFFF, 0);
                this->button_panel[14]->set_text_color(0, 0xFFFFFF, 0);
                this->button_panel[15]->set_text_color(0, 0xFFFFFF, 0);
                this->button_panel[16]->set_text_color(0, 0xFFFFFF, 0);
            } else {
                this->inven_panel->set_text_color(0, 0xFFFFFF);
                this->age_panel->set_text_color(0, 0xFFFFFF);
                this->button_panel[12]->set_text_color(0, 0, 0xFFFFFF);
                this->button_panel[13]->set_text_color(0, 0, 0xFFFFFF);
                this->button_panel[14]->set_text_color(0, 0, 0xFFFFFF);
                this->button_panel[15]->set_text_color(0, 0, 0xFFFFFF);
                this->button_panel[16]->set_text_color(0, 0, 0xFFFFFF);
            }
        }
    }

    this->setup_buttons();
    this->set_redraw((TPanel::RedrawMode)1);
}
