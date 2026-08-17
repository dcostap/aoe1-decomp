// 004B3C90 TribeSelectScenarioScreen::TribeSelectScenarioScreen
// Exact finish:
// BINARY NOTE: TPanel slots through +0xDC and TTextPanel slots +0xE0..+0xEC
// are required for the list's virtual text calls and exact register coloring.
// BINARY NOTE: The +0xE4 call is TTextPanel::set_text(long), not a TPanel stub.
// BINARY NOTE: The extern game pointer stays exact and avoids a raw address
// macro. The repository reviews this global surface.
// BINARY NOTE: The named string externs follow the PDB and inventory symbols.
// Decisive changes: period virtual surfaces, set_text(long), extern global,
// and missionTextX before missionTextY.
// Required group: the TTextPanel virtual overloads and the set_text call.
// Incidental cleanup: ABI names and types for unused virtual slots do not alter
// output. Walkbacks proved that the mission assignment order is required.
// LIKELY INTENT: The source order preserves the original VC5 register colors.
// Exact: 1134 bytes, MATCH, 0.0000%. No inline asm or shared changes.
// FLAGS: config/flags/004B3C90_TribeSelectScenarioScreen.rsp (/GX)

struct tagRECT;
class TDrawArea;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;

extern char s_Select_Scenario_Screen[];
extern char s_scr2[];
extern char s_scr3[];
extern char s_592A40[];

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea* draw_area, TPanel* parent, long p3,
                       long p4, long p5, long p6, unsigned char p7);
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);

    char gap_04[8];
    long pnl_x;                              // +0x0C
    long pnl_y;                              // +0x10
    long pnl_wid;                            // +0x14
    long pnl_hgt;                            // +0x18
    char gap_1C[0xBC];
    int setup_error;                         // +0xD8
    char gap_DC[0x18];                       // +0xF4

    // BINARY NOTE: These named slots preserve the period TPanel ABI.
    virtual void set_fixed_position(long x, long y, long width, long height);
    virtual void set_redraw(int mode);
    virtual void set_overlapped_redraw(TPanel* panel1, TPanel* panel2,
                                       int mode);
    virtual void draw_setup(int mode);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT* rect);
    virtual void draw_offset(long x, long y, tagRECT* rect);
    virtual void draw_rect2(tagRECT* rect);
    virtual void draw_offset2(long x, long y, tagRECT* rect);
    virtual void paint();
    virtual long wnd_proc(void* hwnd, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual long handle_idle();
    virtual long handle_size(long width, long height);
    virtual long handle_paint();
    virtual long handle_key_down(long key, short repeat, int ctrl,
                                 int shift, int alt);
    virtual long handle_char(long key, short repeat);
    virtual long handle_command(unsigned int command, long param);
    virtual long handle_user_command(unsigned int command, long param);
    virtual long handle_timer_command(unsigned int command, long param);
    virtual long handle_scroll(long scroll, long param);
    virtual long handle_mouse_down(unsigned char button, long x, long y,
                                   int ctrl, int shift);
    virtual long handle_mouse_move(long x, long y, int ctrl, int shift);
    virtual long handle_mouse_up(unsigned char button, long x, long y,
                                 int ctrl, int shift);
    virtual long handle_mouse_dbl_click(unsigned char button, long x, long y,
                                        int ctrl, int shift);
    virtual long mouse_move_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_down_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_hold_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_move_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_up_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_dbl_click_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_down_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_hold_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_move_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_up_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_dbl_click_action(long x, long y, int ctrl,
                                              int shift);
    virtual long key_down_action(long key, short repeat, int ctrl,
                                 int shift, int alt);
    virtual long char_action(long key, short repeat);
    virtual long action(TPanel* panel, long code, unsigned long p3,
                        unsigned long p4);
    virtual void get_true_render_rect(tagRECT* rect);
    virtual int is_inside(long x, long y);
    virtual void set_focus(int focus);
    virtual void set_tab_order(TPanel* first, TPanel* second);
    virtual void set_tab_order(TPanel** panels, short count);
    virtual unsigned char get_help_info(char** text, long* page, long p3,
                                        long p4);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    void set_help_info(long help_id, long page_id);
    void set_curr_child(TPanel* child);
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text(char** texts, short count);
    virtual void set_text(long string_id);
    virtual void set_text(char* text);       // vslot +0xE8
    virtual void set_bevel_info(int mode, int c1, int c2, int c3, int c4,
                                int c5, int c6); // +0xEC
    void set_second_column_pos(long position);
    void set_alignment(int vertical, int horizontal);
};

class TListPanel : public TTextPanel {
};

class TScrollBarPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;                              // +0x298
    long hotkey_shift;                        // +0x29C
};

class TEasy_Panel : public TPanel {
public:
    int ideal_width;                          // +0xF4
    char gap_F8[0x224];
    int field_31C;
    unsigned char desc[6];                    // +0x320
    char gap_326[0x152];

    long setup(TDrawArea* draw_area, TPanel* parent, char* info_file,
               long info_id, int visible, long a, long b, long c,
               long d, int e);
    void setup_shadow_area(int force_rebuild);
    void set_ideal_size(long width, long height);
    int create_text(TPanel* parent, TTextPanel** output, long string_id,
                    long x, long y, long width, long height,
                    long font, long align, long center, long wrap);
    int create_text(TPanel* parent, TTextPanel** output, char* text,
                    long x, long y, long width, long height,
                    long font, long align, long center, long wrap);
    int create_list(TPanel* parent, TListPanel** output,
                    long x, long y, long width, long height, long lines);
    int create_auto_scrollbar(TScrollBarPanel** output,
                              TTextPanel* text, long width);
    int create_button(TPanel* parent, TButtonPanel** output, long string_id,
                      long text2, long x, long y, long width, long height,
                      long p9, long p10, long p11);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;                    // +0x4C
    int multiplayerGame();
};

extern RGE_Base_Game* rge_base_game;

class TribeSelectScenarioScreen : public TScreenPanel {
public:
    TTextPanel* title;                        // +0x478
    TTextPanel* scenarioTitle;                // +0x47C
    TTextPanel* scenarioPlayersTitle;         // +0x480
    long scenarioListX;                       // +0x484
    long scenarioListY;                       // +0x488
    long scenarioListWidth;                   // +0x48C
    long scenarioListHeight;                  // +0x490
    TListPanel* scenarioList;                 // +0x494
    TScrollBarPanel* scenarioScrollbar;       // +0x498
    int scenarioCount;                        // +0x49C
    char** scenarioMission;                   // +0x4A0
    int* scenarioFixed;                       // +0x4A4
    int scenariosLoaded;                      // +0x4A8
    TTextPanel* missionTitle;                 // +0x4AC
    long missionTextX;                        // +0x4B0
    long missionTextY;                        // +0x4B4
    long missionTextWidth;                    // +0x4B8
    long missionTextHeight;                   // +0x4BC
    TTextPanel* missionText;                  // +0x4C0
    TScrollBarPanel* missionScrollbar;        // +0x4C4
    TButtonPanel* okButton;                   // +0x4C8
    TButtonPanel* cancelButton;               // +0x4CC
    TButtonPanel* close_button;               // +0x4D0
    int last_scenario_line;                   // +0x4D4

    TribeSelectScenarioScreen();
    virtual ~TribeSelectScenarioScreen();
    void init_vars();
    void fillScenarios();
    void getSettings();
    void fillMissionText();
    void activatePanels();
};

TribeSelectScenarioScreen::TribeSelectScenarioScreen()
    : TScreenPanel(s_Select_Scenario_Screen)
{
    char* setup_file;
    TDrawArea* draw_area;
    int multiplayer;

    this->init_vars();

    multiplayer = rge_base_game->multiplayerGame();
    setup_file = s_scr3;
    if (multiplayer == 0)
        setup_file = s_scr2;

    draw_area = rge_base_game->draw_area;

    if (!this->TEasy_Panel::setup(draw_area, 0, setup_file,
                                  (rge_base_game->multiplayerGame() != 0) +
                                      0xC384,
                                  1, 0, 0, 0, 0, 1)) {
        this->setup_error = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->title, 0x25FA,
                          0x14, 0x0A, 0x258, 0x1E, 1, 1, 0, 0)) {
        this->scenarioListX = 0x14;
        this->scenarioListY = 0x46;
        this->scenarioListWidth = 0x258;
        this->scenarioListHeight = 0x107;

        if (this->create_list(this, &this->scenarioList,
                              0x14, 0x46, 0x258, 0x107, 0x0B)) {
            this->scenarioList->set_second_column_pos(
                ((this->scenarioListWidth - 0x3C) * this->pnl_wid) /
                this->ideal_width);
            // BINARY NOTE: The list uses the TTextPanel +0xE4 text slot.
            this->scenarioList->set_text((long)0x25FD);

            if (this->create_auto_scrollbar(&this->scenarioScrollbar,
                                            this->scenarioList, 0x14)) {
                this->scenarioScrollbar->set_help_info(-1, -1);

                if (this->create_text(this, &this->scenarioTitle, 0x25FE,
                                      this->scenarioListX,
                                      this->scenarioListY - 0x14,
                                      0x12C, 0x14, 4, 0, 0, 0)) {
                    if (this->create_text(this, &this->scenarioPlayersTitle,
                                          0x25FF,
                                          this->scenarioListWidth - 0xDC +
                                              this->scenarioListX,
                                          this->scenarioListY - 0x14,
                                          0xC8, 0x14, 4, 0, 0, 0)) {
                        this->scenarioPlayersTitle->set_alignment(3, 2);

                        // BINARY NOTE: This assignment order selects the exact
                        // VC5 register colors for the mission setup block.
                        this->missionTextX = this->scenarioListX;
                        this->missionTextY = this->scenarioListHeight +
                                             this->scenarioListY + 0x19;
                        this->missionTextWidth = this->scenarioListWidth;
                        this->missionTextHeight = 0x3C;

                        if (this->create_text(this, &this->missionTitle,
                                              0x2600, this->missionTextX,
                                              this->missionTextY - 0x14,
                                              0x190, 0x14, 4, 0, 0, 0)) {
                            if (this->create_text(
                                    this, &this->missionText,
                                    s_592A40, this->missionTextX,
                                    this->missionTextY,
                                    this->missionTextWidth,
                                    this->missionTextHeight,
                                    0x0B, 0, 0, 1)) {
                                this->missionText->set_bevel_info(
                                    3, this->desc[0], this->desc[1],
                                    this->desc[2], this->desc[3],
                                    this->desc[4], this->desc[5]);

                                if (this->create_auto_scrollbar(
                                        &this->missionScrollbar,
                                        this->missionText, 0x14)) {
                                    this->missionScrollbar->set_help_info(
                                        0x7532, -1);

                                    if (this->create_button(
                                            this, &this->okButton, 0x0FA1,
                                            0, 0x46, 0x1B8, 0xF0, 0x1E,
                                            0, 0, 0)) {
                                        this->okButton->set_help_info(
                                            0x7531, -1);

                                        if (this->create_button(
                                                this, &this->cancelButton,
                                                0x0FA2, 0, 0x14A, 0x1B8,
                                                0xF0, 0x1E, 0, 0, 0)) {
                                            this->cancelButton->set_help_info(
                                                0x7532, -1);
                                            TButtonPanel* cancel =
                                                this->cancelButton;
                                            cancel->hotkey = 0x1B;
                                            cancel->hotkey_shift = 0;

                                            if (this->create_button(
                                                    this, &this->close_button,
                                                    0x03EA, 0, 0, 0, 0, 0,
                                                    -1, -1, 0)) {
                                                this->close_button->set_active(1);
                                                this->close_button->set_positioning(
                                                    9, 4, 4, 4, 4, 0x11,
                                                    0x11, 0x11, 0x11, 0, 0,
                                                    0, 0);
                                                this->fillScenarios();
                                                this->scenariosLoaded = 1;
                                                this->getSettings();
                                                this->fillMissionText();
                                                this->activatePanels();
                                                this->set_curr_child(
                                                this->scenarioList);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
