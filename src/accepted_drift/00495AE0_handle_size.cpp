// VA: 00495AE0 TRIBE_Screen_Game::handle_size
// PDB donor: scr_game.cpp:1215-1431
//
// Baseline reconstruction: the method lays out the three game-screen size
// families, preserves each panel's real TPanel positioning surface, saves the
// score-panel active states, and restores them after the layout pass.  The
// repeated offsets below are the screen's named panel members, not a raw
// decompiler cursor view.
// Attempt log:
// - baseline: canonical TRIBE_Screen_Game/TPanel layout and typed
//   set_positioning/set_fixed_position virtual calls; frame 0x24, 2 missing
//   small-screen fixed-position calls, 1986 strict differing bytes.
// - behavior: restored the small-screen button-panel[5] and [11] positioning
//   and draw-type updates proven by the 00495FA1-004961B8 branch; call count
//   became 82/82 and size moved to +30 bytes.
// - control-flow: changed each repeated 2x6 button layout to a pointer-cursor
//   do/while form with the observed 0x36 column and 0x3A row strides; frame
//   became the original 0x20 and strict diff improved to 1945 bytes.
// - liveness/context: shared the panel cursor/coordinate/counter locals across
//   the three size families, reordered their setup, tested declaration order,
//   register qualification, long coordinate types, and nested size guards;
//   these variants either emitted identical code or only changed scheduling.
// - control-flow: tested a natural small-first threshold dispatch with a named
//   button-16 tail for the medium/large arms; call sites became 82/82 aligned,
//   but the first threshold moved to the wrong compare order and diff grew to
//   2237 bytes, so this source was restored.
// - control-flow: a preliminary tail form kept the first call prefix longer,
//   but added 70 bytes and worsened structural coverage; it was also restored.
// - paused: current source is the best natural reconstruction.  Remaining
//   structural lead is the first button-loop setup at 00495B75: original keeps
//   row y at [esp+38] and the six-column counter in EBX, while VC5 keeps the
//   y seed in EBX and homes the column count.  One branch-local call tail is
//   also physically shared differently (original 00495F73 versus rebuilt).
//
// Fresh bounded pass (sa-946ebf0a):
// - H1-H6 tested declaration order, loop form, local scope, register hints,
//   and int/long widths.  They were duplicate or worse codegen.
// - H7-H10 tested score-panel pointer cursors.  Two cursors added a 0x24 frame
//   and 2113 differing bytes.  The counted-for form kept that basin.
// - H11 used one panel cursor and worsened the result to 1952 bytes.
// - H12 kept direct score-panel indexing and added only a saved-state cursor.
//   This restored the original first save-loop register order and reduced the
//   strict difference to 1941 bytes.  This is the retained clean source.
// - H13-H17 tested an array-backed y local, branch-local cursors, declaration
//   order, and counter width.  They were duplicate codegen.
// - H18-H20 tested update order and final-frame declaration order.  They were
//   duplicate or worse codegen.  H21 added the full adjacent TPanel surface;
//   it was duplicate.  H22 replaced tagRECT with the period windows.h type;
//   it was neutral.
// - H23 moved button-panel[16] setup after all three size arms.  It removed
//   one call and worsened the size and CFG, so it was restored.
// - H24 shared button-panel[16] setup only between the large and medium arms.
//   It aligned all 82 call sites, but worsened size and structural coverage.
// - H25 named each grid button and stored draw_type after cursor updates.  It
//   added a 0x24 frame and worsened the result, so it was restored.
//
// BINARY NOTE: the first save loop uses EDI for save_score_active and EBX for
// score_panel.  The retained pointer shape reproduces this register order.
// BINARY NOTE: each button grid uses a stack y home and an EBX column count in
// the executable.  The clean source still emits the reverse assignment.
// LIKELY INTENT: the large-arm button-16 call shares the medium-arm call tail.
// The current natural nested arms do not reproduce that tail merge.
// Accepted-drift review: the apparent call-map gap is one relocated shared
// button-panel[16] tail, not an added or omitted runtime call. All 82 calls,
// arguments, three size thresholds, draw-type stores, frame stores, active
// save/restore effects, and player_changed arguments match. Remaining drift is
// private row/counter homes and the equivalent button-tail placement.

#if !defined(SCR_GAME_TU_CONTEXT)
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class TShape;
class PanelNode;
class TPanel;
class TTextPanel;
class TMessagePanel;
class TScrollBarPanel;
class RGE_Panel_Tool_Box;
class TRIBE_Panel_Time;
class TRIBE_Panel_Pop;
class TRIBE_Main_View;
class TRIBE_Diamond_Map_View;
class RGE_Player;
class RGE_Game_World;
class RGE_Base_Game;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea* area, TPanel* parent, long x,
                       long y, long wid, long hgt, unsigned char mode);
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long x, long y, long wid, long hgt);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(int mode, long p2, long p3, long p4,
                                 long p5, long p6, long p7, long p8,
                                 long p9, TPanel* p10, TPanel* p11,
                                 TPanel* p12, TPanel* p13);
    virtual void set_fixed_position(long x, long y, long wid, long hgt);
    virtual void set_redraw(int mode);
    virtual long handle_size(long width, long height);

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    tagRECT clip_rect;
    long position_mode;
    long need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    void* clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;

    long width();
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
};

class TScreenPanel : public TEasy_Panel {
};

class TMessagePanel : public TPanel {
};

class TTextPanel : public TPanel {
};

class TScrollBarPanel : public TPanel {
};

class TRIBE_Panel_Time : public TPanel {
};

class TRIBE_Panel_Pop : public TPanel {
};

class RGE_Panel_Tool_Box : public TPanel {
};

class TRIBE_Main_View : public TPanel {
};

class TRIBE_Diamond_Map_View : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1C4];
    unsigned char gap_2B8[8];
    unsigned char draw_type;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x46];
    short id;
};

class RGE_Base_Game {
public:
    RGE_Player* get_player();
};

class RGE_Game_World {
public:
    char gap_00[0x11C];
    unsigned char countdown_victory;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game : public TScreenPanel {
public:
    TShape* game_screen_pic;             // +0x478
    TShape* button_border1_pic;          // +0x47C
    TShape* button_other_pic;            // +0x480
    TShape* button_border2_pic;          // +0x484
    TShape* button_border3_pic;          // +0x488
    TShape* button_cmd_pic;              // +0x48C
    TShape* button_tech_pic;             // +0x490
    TShape* button_unit_pic;             // +0x494
    TShape* button_bldg_pics[5];         // +0x498
    TShape* more_cancel_pic;             // +0x4AC
    short more_frame;                    // +0x4B0
    short cancel_frame;                  // +0x4B2
    short unselect_frame;                // +0x4B4
    unsigned char gap_4B6[2];

    TRIBE_Main_View* main_view;          // +0x4B8
    TRIBE_Diamond_Map_View* map_view;    // +0x4BC
    TPanel* inven_panel;                 // +0x4C0
    TPanel* object_panel;                // +0x4C4
    TButtonPanel* button_panel[17];      // +0x4C8
    TPanel* text_line_panel;             // +0x50C
    TPanel* quit_message_panel;          // +0x510
    TRIBE_Panel_Time* time_panel;        // +0x514
    TRIBE_Panel_Time* countdown_clock[10]; // +0x518
    TRIBE_Panel_Pop* pop_panel;          // +0x540
    TPanel* message_panel[6];            // +0x544
    TPanel* chat_panel[8];               // +0x55C
    RGE_Panel_Tool_Box* tool_box;        // +0x57C
    TPanel* age_panel;                   // +0x580
    TPanel* pause_text;                  // +0x584
    TPanel* fps_panel;                   // +0x588
    TPanel* score_panel[8];              // +0x58C
    TPanel* log_text;                    // +0x5AC
    TScrollBarPanel* log_scrollbar;      // +0x5B0
    RGE_Game_World* world;               // +0x5B4
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

    virtual long handle_size(long width, long height);
    void player_changed(int old_player, int new_player);
};
#endif

#if defined(SCR_GAME_TU_CONTEXT)
#define message_panel message_panels_at_544
#endif

long TRIBE_Screen_Game::handle_size(long width, long height) {
    TPanel::handle_size(width, height);

    if (this->main_view == 0) {
        return 0;
    }

    int save_score_active[8];
    TRIBE_Panel_Button** buttons;
    int panel_cols;
    long panel_y;
    int panel_rows;
    long panel_x;

    this->log_text->set_active(0);
    this->text_line_panel->set_active(1);
    this->message_panel[0]->set_active(1);
    this->message_panel[1]->set_active(1);
    this->message_panel[2]->set_active(1);
    this->message_panel[3]->set_active(1);
    this->message_panel[4]->set_active(1);
    this->message_panel[5]->set_active(1);

    int* saved_score = save_score_active;
    for (int score_active_index = 0; score_active_index < 8; ++score_active_index) {
        TPanel* panel = this->score_panel[score_active_index];
        if (panel != 0) {
            *saved_score = panel->active;
            panel->set_active(1);
        }
        ++saved_score;
    }

    short final_frame;

    if (this->pnl_wid >= 0x400 && this->pnl_hgt >= 0x300) {
        this->pop_panel->set_positioning(7, 0x1B0, 4, 4, 4,
                                         0xA0, 0xA0, 0x14, 0x14,
                                         0, 0, 0, 0);

        if (this->tool_box->active != 0) {
            this->tool_box->set_fixed_position(0, 0x14, 0x400, 0x1E);
            this->main_view->set_fixed_position(0, 0x32, 0x400, 0x250);
        } else {
            this->main_view->set_fixed_position(0, 0x14, 0x400, 0x26E);
        }

        this->map_view->set_fixed_position(0x31B, 0x288, 0xDC, 0x72);
        this->age_panel->set_fixed_position(0x10E, 2, 0x1EC, 0x10);
        this->fps_panel->set_fixed_position(2, 2, 0x118, 0x10);
        this->inven_panel->set_fixed_position(0, 0, 0x10E, 0x14);
        this->object_panel->set_fixed_position(5, 0x289, 0x7F, 0x72);

        panel_y = 0x28A;
        buttons = this->button_panel;
        panel_rows = 2;
        do {
            panel_x = 0x88;
            panel_cols = 6;
            do {
                (*buttons)->set_fixed_position(panel_x, panel_y, 0x36, 0x36);
                (*buttons)->draw_type = 0;
                ++buttons;
                panel_x += 0x36;
                --panel_cols;
            } while (panel_cols != 0);
            panel_y += 0x3A;
            --panel_rows;
        } while (panel_rows != 0);

        this->button_panel[12]->set_fixed_position(0x304, 0, 0x48, 0x13);
        this->button_panel[13]->set_fixed_position(0x34C, 0, 0x6C, 0x13);
        this->button_panel[14]->set_fixed_position(0x3B8, 0, 0x48, 0x13);
        this->button_panel[15]->set_fixed_position(0x3DD, 0x2DC, 0x1E, 0x1E);
        this->button_panel[15]->draw_type = 3;
        this->button_panel[16]->set_fixed_position(0x3DD, 0x28A, 0x1E, 0x1E);
        this->button_panel[16]->draw_type = 3;

        this->more_cancel_pic = this->button_cmd_pic;
        this->more_frame = 0xB;
        final_frame = 0xA;
    } else {
        if (this->pnl_wid >= 0x320 && this->pnl_hgt >= 0x258) {
        this->pop_panel->set_positioning(7, 0x140, 4, 4, 4,
                                         0xA0, 0xA0, 0x14, 0x14,
                                         0, 0, 0, 0);

        if (this->tool_box->active != 0) {
            this->tool_box->set_fixed_position(0, 0x14, 0x320, 0x1E);
            this->main_view->set_fixed_position(0, 0x32, 0x320, 0x1A8);
        } else {
            this->main_view->set_fixed_position(0, 0x14, 0x320, 0x1C6);
        }

        this->map_view->set_fixed_position(0x23B, 0x1E0, 0xDC, 0x72);
        this->age_panel->set_fixed_position(0x10E, 2, 0x10C, 0x10);
        this->fps_panel->set_fixed_position(2, 2, 0x118, 0x10);
        this->inven_panel->set_fixed_position(0, 0, 0x10E, 0x14);
        this->object_panel->set_fixed_position(5, 0x1E1, 0x7F, 0x72);

        panel_y = 0x1E2;
        buttons = this->button_panel;
        panel_rows = 2;
        do {
            panel_x = 0x88;
            panel_cols = 6;
            do {
                (*buttons)->set_fixed_position(panel_x, panel_y, 0x36, 0x36);
                (*buttons)->draw_type = 0;
                ++buttons;
                panel_x += 0x36;
                --panel_cols;
            } while (panel_cols != 0);
            panel_y += 0x3A;
            --panel_rows;
        } while (panel_rows != 0);

        this->button_panel[12]->set_fixed_position(0x224, 0, 0x48, 0x13);
        this->button_panel[13]->set_fixed_position(0x26C, 0, 0x6C, 0x13);
        this->button_panel[14]->set_fixed_position(0x2D8, 0, 0x48, 0x13);
        this->button_panel[15]->set_fixed_position(0x2FD, 0x234, 0x1E, 0x1E);
        this->button_panel[15]->draw_type = 3;
        this->button_panel[16]->set_fixed_position(0x2FD, 0x1E2, 0x1E, 0x1E);
        this->button_panel[16]->draw_type = 3;

        this->more_cancel_pic = this->button_cmd_pic;
        this->more_frame = 0;
        final_frame = 2;
        } else {
        this->pop_panel->set_positioning(7, 0xF0, 4, 4, 4,
                                         0xA0, 0xA0, 0x14, 0x14,
                                         0, 0, 0, 0);

        if (this->tool_box->active != 0) {
            this->tool_box->set_fixed_position(0, 0x14, 0x280, 0x1E);
            this->main_view->set_fixed_position(0, 0x32, 0x280, 0x130);
        } else {
            this->main_view->set_fixed_position(0, 0x14, 0x280, 0x14E);
        }

        this->map_view->set_fixed_position(0x19B, 0x16A, 0xDC, 0x72);
        this->age_panel->set_fixed_position(0x10E, 2, 0x6A, 0x10);
        this->fps_panel->set_fixed_position(2, 2, 0x118, 0x10);
        this->inven_panel->set_fixed_position(0, 0, 0x10E, 0x14);
        this->object_panel->set_fixed_position(5, 0x169, 0x7F, 0x72);

        panel_y = 0x16A;
        buttons = this->button_panel;
        panel_rows = 2;
        do {
            panel_x = 0x88;
            panel_cols = 6;
            do {
                (*buttons)->set_fixed_position(panel_x, panel_y, 0x36, 0x36);
                (*buttons)->draw_type = 0;
                ++buttons;
                panel_x += 0x36;
                --panel_cols;
            } while (panel_cols != 0);
            panel_y += 0x3A;
            --panel_rows;
        } while (panel_rows != 0);

        this->button_panel[5]->set_fixed_position(0x196, 0x16A, 0x66, 0x35);
        this->button_panel[5]->draw_type = 2;
        this->button_panel[11]->set_fixed_position(0x196, 0x1BB, 0x66, 0x35);
        this->button_panel[11]->draw_type = 2;
        this->button_panel[12]->set_fixed_position(0x184, 0, 0x48, 0x13);
        this->button_panel[13]->set_fixed_position(0x1CC, 0, 0x6C, 0x13);
        this->button_panel[14]->set_fixed_position(0x238, 0, 0x48, 0x13);
        this->button_panel[15]->set_fixed_position(0x25D, 0x1BC, 0x1E, 0x1E);
        this->button_panel[15]->draw_type = 3;
        this->button_panel[16]->set_fixed_position(0x25D, 0x16A, 0x1E, 0x1E);
        this->button_panel[16]->draw_type = 3;

        this->more_cancel_pic = this->button_cmd_pic;
        this->more_frame = 0;
            final_frame = 2;
        }
    }

    this->cancel_frame = final_frame;
    this->unselect_frame = final_frame;

    this->pause_text->set_positioning(2, 4, 4, 4, 4,
                                      0x258, 0x258, 0x3C, 0x3C,
                                      0, 0, 0, 0);
    this->time_panel->set_positioning(7, 4, 4, 4, 4,
                                      0x78, 0x78, 0x14, 0x14,
                                      0, 0, 0, 0);

    TRIBE_Panel_Time** clocks = this->countdown_clock;
    int clock_y = 4;
    for (int clock_index = 0; clock_index < 10; ++clock_index) {
        (*clocks)->set_positioning(9, 4, clock_y, 4, 4,
                                   0xAA, 0xAA, 0x14, 0x14,
                                   0, 0, 0, 0);
        ++clocks;
        clock_y += 0x14;
    }

    if (this->world->countdown_victory != 0) {
        this->text_line_panel->set_positioning(8, 4, 0, 0xB8, 4,
                                               0, 0, 0x22, 0x22,
                                               0, 0, 0, 0);
    } else {
        this->text_line_panel->set_positioning(8, 4, 0, 4, 4,
                                               0, 0, 0x22, 0x22,
                                               0, 0, 0, 0);
    }

    int half_width = (this->main_view->width() - 500) / 2;
    this->quit_message_panel->set_positioning(7, half_width, 8,
                                              half_width, 8,
                                              0, 0, 0x14, 0x14,
                                              0, 0, 0, 0);

    this->message_panel[0]->set_positioning(8, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->text_line_panel);
    this->message_panel[1]->set_positioning(8, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->message_panel[0]);
    this->message_panel[2]->set_positioning(8, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->message_panel[1]);
    this->message_panel[3]->set_positioning(8, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->message_panel[2]);
    this->message_panel[4]->set_positioning(8, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->message_panel[3]);
    this->message_panel[5]->set_positioning(8, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->message_panel[4]);

    TPanel** chats = this->chat_panel;
    int chat_y = 0x22;
    for (int chat_index = 0; chat_index < 8; ++chat_index) {
        (*chats)->set_fixed_position(4, chat_y, 0x26C, 0x14);
        ++chats;
        chat_y += 0x14;
    }

    short score_index = 7;
    do {
        TPanel* score = this->score_panel[(int)score_index];
        if (score != 0) {
            TPanel* next_score = 0;
            if (score_index != 7) {
                next_score = this->score_panel[(int)score_index + 1];
            }
            score->set_positioning(10, 4, 0, 4,
                                   score_index != 7 ? 4 : 0,
                                   200, 200, 0x14, 0x14,
                                   0, 0, 0, next_score);
        }
        --score_index;
    } while (score_index >= 0);

    this->text_line_panel->set_active(0);
    this->message_panel[0]->set_active(0);
    this->message_panel[1]->set_active(0);
    this->message_panel[2]->set_active(0);
    this->message_panel[3]->set_active(0);
    this->message_panel[4]->set_active(0);
    this->message_panel[5]->set_active(0);

    TPanel** panels = (TPanel**)this->score_panel;
    int* saved = save_score_active;
    for (int score_restore_index = 0; score_restore_index < 8; ++score_restore_index) {
        if (*panels != 0) {
            (*panels)->set_active(*saved);
        }
        ++panels;
        ++saved;
    }

    this->player_changed((short)rge_base_game->get_player()->id,
                         (short)rge_base_game->get_player()->id);
    return 0;
}

#if defined(SCR_GAME_TU_CONTEXT)
#undef message_panel
#endif
