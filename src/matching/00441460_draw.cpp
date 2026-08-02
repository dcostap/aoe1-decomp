// TribeSendMessageDialog::draw (00441460)
// Attempt log:
// - baseline: typed TPanel/TDialogPanel layout, world/player/color-table ownership;
//   180 bytes versus 203, with the loop locals in the wrong register basin.
// - direct repeated player color-table accesses plus an explicit do/while: exact
//   size and 50 differing bytes; this preserved the binary's reloads and loop CFG.
// - moved the y-offset increment outside the color-table guard: 31 differing bytes.
// - modeled RGE_Color_Table::table as the proven inline byte array at +0x28 rather
//   than a pointer; exact 203-byte match.

typedef unsigned char uchar;
typedef unsigned long ulong;

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
class TEditPanel;
class TShape;
class RGE_Color_Table;
class RGE_Player;
class RGE_Game_World;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    int position_mode;
    int need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    void* node;
    void* first_child_node;
    void* last_child_node;
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
    uchar mouse_action;
    uchar mouse_down_button;
    uchar panel_type;
    uchar color;
    uchar fill_in_background;
    uchar clip_to_parent;
    uchar draw_rect2_flag;
    uchar need_restore;
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual void draw();
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
};

class TShape {
public:
    uchar shape_draw(TDrawArea*, long, long, long, uchar, uchar*);
};

class RGE_Color_Table {
public:
    char gap_00[0x26];
    short id;
    uchar table[0x100];
};

class RGE_Player {
public:
    char gap_00[0x108];
    RGE_Color_Table* color_table;
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x3F0];
    RGE_Game_World* world;
    int playerID(int);
};

extern RGE_Base_Game* rge_base_game;
extern "C" void __cdecl _ASMSet_Color_Xform(int);

class TribeSendMessageDialog : public TDialogPanel {
public:
    TTextPanel* title;
    TTextPanel* playerName[8];
    TTextPanel* playerCivilization[8];
    TButtonPanel* checkButton[8];
    TTextPanel* radioTitle[4];
    TButtonPanel* radioButton[4];
    TShape* radioButtonShapes;
    TEditPanel* chatInput;
    TTextPanel* chatTitle;
    TButtonPanel* okButton;
    TButtonPanel* help_button;
    TShape* backgroundPics;
    int commPlayers[8];

    virtual void draw();
};

void TribeSendMessageDialog::draw()
{
    TEasy_Panel::draw();

    if (this->backgroundPics != 0) {
        RGE_Game_World* world = rge_base_game->world;
        this->draw_setup(0);

        int y = 0;
        int i = 1;
        do {
            int id = rge_base_game->playerID(i);
            if (id != 0) {
                if (world->players[id]->color_table != 0) {
                    _ASMSet_Color_Xform(
                        (world->players[id]->color_table->id + 1) * 0x10);
                    this->backgroundPics->shape_draw(
                        this->render_area,
                        this->pnl_x + 0x32,
                        this->pnl_y + y + 0x28,
                        0, 1, world->players[id]->color_table->table);
                }
                y += 0x1E;
            }
            ++i;
        } while (i < 9);

        this->draw_finish();
    }
}
