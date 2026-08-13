// 004B3C90 TribeSelectScenarioScreen::TribeSelectScenarioScreen
// Attempt log:
// try 1-11: prior scaffold used the wrong setup overload and panel factory
// surface. It modeled list/input/picture helpers instead of the constructor's
// list, scrollbar, text, and button sequence.
// probe 1: restored the Scr_sels.cpp call surface and nested success topology;
// all 33 calls then aligned, but size was 15 bytes short.
// probe 2: corrected TEasy_Panel size to 0x478; exact block coverage rose to
// 69.94%, with the full-size code still differing in register/liveness shape.
// probe 3: cached draw_area and reversed the second-column expression; diff
// fell to 715 bytes, but the early setup argument schedule moved farther.
// probe 4: cached the game object; diff fell to 622 bytes, but the early
// setup schedule and later field scheduling moved. Restored this basin.
// probe 5: explicit second-column temporary did not improve codegen; restored.
// blockers: original setup hoists draw-area into EDI and calls multiplayerGame
// after pushing setup args; current typed source preserves calls and behavior
// but does not reproduce that early register schedule. Field writes around
// scenarioList and missionText also differ in harmless VC5 liveness order.
// No inline asm or shared-surface changes.
// FLAGS: config/flags/004B3C90_TribeSelectScenarioScreen.rsp (/GX)

struct tagRECT;
class TDrawArea;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
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

    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void set_string_id(long id);     // vslot +0xE4

    void set_help_info(long help_id, long page_id);
    void set_curr_child(TPanel* child);
};

class TTextPanel : public TPanel {
public:
    virtual void set_text(char* text);       // vslot +0xE8
    virtual void set_bevel_info(int mode, unsigned char c1, unsigned char c2,
                                unsigned char c3, unsigned char c4,
                                unsigned char c5, unsigned char c6); // +0xEC
    void set_second_column_pos(int position);
    void set_alignment(int horizontal, int vertical);
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

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)

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
    : TScreenPanel((char*)0x005868B0)
{
    char* setup_file;
    RGE_Base_Game* game;
    int multiplayer;

    this->init_vars();

    multiplayer = rge_base_game->multiplayerGame();
    setup_file = (char*)0x00586174;
    if (multiplayer == 0)
        setup_file = (char*)0x00586138;

    game = rge_base_game;

    if (!this->TEasy_Panel::setup(game->draw_area, 0, setup_file,
                                  (game->multiplayerGame() != 0) +
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
            this->scenarioList->set_string_id(0x25FD);

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

                        this->missionTextY = this->scenarioListHeight +
                                             this->scenarioListY + 0x19;
                        this->missionTextX = this->scenarioListX;
                        this->missionTextWidth = this->scenarioListWidth;
                        this->missionTextHeight = 0x3C;

                        if (this->create_text(this, &this->missionTitle,
                                              0x2600, this->missionTextX,
                                              this->missionTextY - 0x14,
                                              0x190, 0x14, 4, 0, 0, 0)) {
                            if (this->create_text(
                                    this, &this->missionText,
                                    (char*)0x00592A40, this->missionTextX,
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
