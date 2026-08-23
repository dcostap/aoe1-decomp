// VA: 004A00B0 TribeMPSetupScreen::TribeMPSetupScreen
// PDB donor: scr_mps.cpp:203-437
// Baseline reconstruction: period-plausible screen construction with the
// proven TScreenPanel/TEasy_Panel hierarchy, named panel arrays, and natural
// creation/setup call order.  The response file supplies /GX for the original
// constructor EH frame.
//
// Attempt log:
// - baseline: canonical panel ownership from the destructor and generated class
//   layout; direct TEasy_Panel helper calls, TPanel/TTextPanel virtual surfaces,
//   and natural single/multiplayer setup branches.
// - context: hoisted the proven draw_area member before nested setup-id
//   evaluation; VC5 then reproduced the original setup argument push order.
// - liveness: removing the synthetic row-index and scenario-pointer homes did
//   not change code until the row was expressed as a contiguous cursor.
// - layout: the named row arrays proved contiguous around playerCivDrop; using
//   those neighboring row offsets restored the 0x10C frame and removed 120
//   emitted bytes while substantially improving block coverage.
// - control-flow: a guarded for loop for the eight player rows removed VC5's
//   peeled duplicate dropdown site and aligned the static row call topology.
// - behavior: spelling the title resource as a conditional -1/0 offset matched
//   the original neg/sbb/add lowering and moved the first useful frontier deeper.
// - final control-flow (prior session): the settings rows use one guarded loop
//   site; the old remaining drift was a missing create_button site and late
//   branch gaps.
// - control-flow: reversed the host/nonhost dispatch arms.  The host arm now
//   follows IsHost in source order, with the nonhost arm as the fallback.  This
//   restored all 127 ordered calls, exact function size, and the original host
//   and nonhost block placement; the row setup still differs locally.
// - unresolved pass: twenty source hypotheses were compiled and checked.  The
//   clean baseline remains 3240 bytes, 0x10C frame, and 127 ordered calls.
// - BINARY NOTE: the shipped row setup stores y at entry-relative [esp+10],
//   then loads playerCivDrop and carries the row cursor through the calls.
//   The clean source still emits a three-instruction local-order drift there.
// - BINARY NOTE: the final row virtual call dereferences the player-CD output
//   slot before calling vslot +0x14.  Direct typed and base-pointer forms add
//   nine bytes, so the clean baseline remains pinned until a better source
//   model explains that register reuse.
// - LIKELY INTENT: the row cursor is one contiguous panel family centered on
//   playerCivDrop.  This explains the proven negative pointer offsets, but it
//   does not prove the original local declarations.
// - indexed-row recovery: direct indexed member arrays with one for-loop body,
//   a separate next_button_id, and the stack buffer base reduced the checked
//   difference from 2452 to 1478 bytes.  The frame, size, and 127 ordered calls
//   remain exact in this source model.
// - BINARY NOTE: the indexed source now reproduces the row setup through the
//   team-text block at +0x5A4, and reproduces the final CD-text virtual block.
//   The first remaining row mismatch is the y+2 register/arithmetic lowering.
// - BINARY NOTE: the shipped coordinates are y, y+2, and y+3.  The current
//   source uses text_y = y + 2 and text_y + 1 for the last two panels.
// - unresolved pass: direct indexed arrays are a strong shape lead, but the
//   remaining add ebx,2 versus lea ebx,[ebp+2] basin is not exact.
// - Authentic scr_mps.cpp context used the canonical screen layout and /GX.
//   PDB-ordered compilation kept 3240 bytes, 127 calls, and the 1478-byte diff.

#ifndef SCR_MPS_TU_CONTEXT

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

struct tagRECT;
class TDrawArea;
class TTextPanel;
class TButtonPanel;
class TDropDownPanel;
class TEditPanel;
class TScrollBarPanel;

enum FormatType {
    FORMAT_TYPE_DEFAULT = 0
};

class TPanel {
public:
    enum PositionMode {
        POSITION_MODE_DEFAULT = 0
    };
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
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

    char gap_04[0xD8 - 0x04];
    int field_D8;
    char gap_DC[0xF4 - 0xDC];

    void set_help_info(long help_id, long page_id);
    void set_curr_child(TPanel* child);
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x94];

    virtual void set_text(char**, short);
    virtual void set_text(long);
    virtual void set_text(char*);
    virtual void set_bevel_info(int, int, int, int, int, int, int);

    void set_alignment(int vertical, int horizontal);
    void empty_list();
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;

    void set_text(short state, char* text);
    void set_text(short state, long string_id);
    void set_id(short state, long id, long id2);
    void set_state_info(short state_count);
    void set_disabled(int disabled);
};

class TDropDownPanel : public TPanel {
public:
    char gap_F4[0x10];
    int mode;

    void set_draw_style(int style);
    void set_draw_val_rect(int enabled);
    void empty_list();
    int append_line(long string_id, long value);
};

class TEditPanel : public TTextPanel {
};

class TScrollBarPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x228];
    int use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_326[0x152];

    long setup(TDrawArea* draw_area, TPanel* parent, char* text, long id,
               int visible, long a, long b, long c, long d, int e);
    void setup_shadow_area(int force_rebuild);
    void set_ideal_size(long width, long height);

    int create_text(TPanel* parent, TTextPanel** out, long string_id,
                    long p4, long p5, long p6, long p7, long p8,
                    long p9, long p10, long p11);
    int create_text(TPanel* parent, TTextPanel** out, char* text,
                    long p4, long p5, long p6, long p7, long p8,
                    long p9, long p10, long p11);
    int create_button(TPanel* parent, TButtonPanel** out, long string_id,
                      long p4, long p5, long p6, long p7, long p8,
                      long p9, long p10, long p11);
    int create_button(TPanel* parent, TButtonPanel** out, char* text1,
                      char* text2, long p5, long p6, long p7, long p8,
                      long p9, long p10, long p11);
    int create_check_box(TPanel* parent, TButtonPanel** out,
                         long p3, long p4, long p5, long p6, long p7, long p8);
    int create_edit(TPanel* parent, TEditPanel** out, char* text,
                    short width, FormatType format, long x, long y, long w,
                    long h, long font, int p11, int p12);
    int create_drop_down(TPanel* parent, TDropDownPanel** out,
                         long p3, long p4, long p5, long p6, long p7,
                         long p8, long p9);
    int create_auto_scrollbar(TScrollBarPanel** out, TTextPanel* text,
                              long spacing);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
};

class TChat {
public:
    void ClearChat();
    void setInChatGroup(int group, int enabled);
};

class TDebuggingLog {
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;

    int multiplayerGame();
    int singlePlayerGame();
};

class TCommunications_Handler {
public:
    int IsHost();
    void SetMyReadiness(int, int, int, int, int, int, int, int);
};

extern TChat* chat;
extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern TDebuggingLog* L;
extern void Log(TDebuggingLog*, const char*, ...);

class TribeMPSetupScreen : public TScreenPanel {
public:
    TTextPanel* title;                 // +478
    TTextPanel* playerTitle;           // +47C
    TTextPanel* civTitle;              // +480
    TTextPanel* settingsTitle;         // +484
    TTextPanel* colorTitle;            // +488
    TTextPanel* teamTitle;             // +48C
    TTextPanel* playerNameText[8];     // +490
    TTextPanel* playerCivText[8];      // +4B0
    TTextPanel* scenarioPlayerText[8];// +4D0
    TTextPanel* playerCDText[8];       // +4F0
    TTextPanel* playerVersionText[8];  // +510
    TTextPanel* playerColorText[8];    // +530
    TTextPanel* playerTeamText[8];     // +550
    TButtonPanel* playerColor[8];      // +570
    TButtonPanel* playerTeam[8];       // +590
    TDropDownPanel* playerNameDrop[8];// +5B0
    TDropDownPanel* playerCivDrop[8]; // +5D0
    TDropDownPanel* scenarioPlayerDrop[8]; // +5F0
    TEditPanel* chatInput;             // +610
    TTextPanel* chatTitle;             // +614
    TTextPanel* chatBox;               // +618
    TScrollBarPanel* chatScrollbar;    // +61C
    TButtonPanel* gameSettingsButton;  // +620
    TTextPanel* scenarioName;          // +624
    TTextPanel* victoryFixedText;      // +628
    TTextPanel* settingText[20];       // +62C
    TTextPanel* settingValue[20];      // +67C
    TTextPanel* mapSizeLabel;          // +6CC
    TDropDownPanel* mapSizeDrop;       // +6D0
    TTextPanel* mapTypeLabel;          // +6D4
    TDropDownPanel* mapTypeDrop;       // +6D8
    TTextPanel* numberPlayersTitle;    // +6DC
    TDropDownPanel* numberPlayersDrop; // +6E0
    TTextPanel* numberPlayersText;     // +6E4
    TButtonPanel* hiddenMapButton;     // +6E8
    TTextPanel* hiddenMapText;         // +6EC
    TTextPanel* victoryTypeLabel;      // +6F0
    TDropDownPanel* victoryTypeDrop;   // +6F4
    TTextPanel* victoryAmountLabel;    // +6F8
    TEditPanel* victoryAmountInput;    // +6FC
    TButtonPanel* startButton;         // +700
    TButtonPanel* readyButtons[2];     // +704
    TButtonPanel* cancelButton;        // +70C
    TButtonPanel* help_button;         // +710
    TButtonPanel* ready_button;        // +714
    TButtonPanel* close_button;        // +718
    TTextPanel* ready_button_label;    // +71C
    int cancelMode;                    // +720
    int playerToKick;                  // +724
    int scenarioPlayerCount;           // +728
    int myCivilization;                // +72C
    int myScenarioPlayer;              // +730
    int myPlayerColor;                 // +734
    int myPlayerTeam;                  // +738
    long myScenarioChecksum;           // +73C
    char saveScenarioName[0x100];      // +740
    int saveRandomGame;                // +840
    long saveScenarioChecksum;         // +844
    void* scenarioInfo;                // +848
    int settingsFixed;                 // +84C
    int numberAnyPlayers;              // +850
    int sent_cd_status;                // +854
    TButtonPanel* netInfoButton;       // +858
    int i_am_ready;                    // +85C
    char gap_860[0x30];

    virtual ~TribeMPSetupScreen();

    void init_vars();
    void setupTabOrder();
    void updateSummary();
    void setupSinglePlayerPlayers();
    void fillPlayers();

    TribeMPSetupScreen();
};

#endif

TribeMPSetupScreen::TribeMPSetupScreen()
    : TScreenPanel("MP Setup Screen")
{
    int row;
    char str[256];
    int y;
    int button_id;
    int multiplayer;

    Log(L, "$$$ CHAT SCREEN: CONSTRUCTOR BEGIN");
    init_vars();
    chat->ClearChat();
    for (int i = 1; i < 9; i++) {
        chat->setInChatGroup(i, 1);
    }

    char* setup_file;
    if (rge_base_game->multiplayerGame()) {
        setup_file = (char*)"scr3";
    } else {
        setup_file = (char*)"scr2";
    }

    TDrawArea* draw_area = rge_base_game->draw_area;
    if (this->TEasy_Panel::setup(
            draw_area, 0, setup_file,
            (rge_base_game->multiplayerGame() != 0) + 0xC384,
            1, 0, 0, 0, 0, 1) == 0) {
        this->field_D8 = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->title,
                          0x25CF + (rge_base_game->multiplayerGame() ? -1 : 0),
                          0x14, 6, 600, 0x1E, 1, 1, 0, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->playerTitle, 0x25D0,
                          0x1A, 0x32, 0xA0, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->civTitle, 0x25D1,
                          0xBD, 0x32, 0xA0, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }

    if (!rge_base_game->singlePlayerGame() && !comm->IsHost()) {
        if (this->create_text(this, &this->settingsTitle, 0x25D2,
                              0x1A4, 0x32, 0xD2, 0x1E, 0, 0, 1, 0) == 0) {
            return;
        }
    }

    if (this->create_text(this, &this->colorTitle, 0x25AE,
                          0xF0, 0x32, 100, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }
    this->colorTitle->set_alignment(0, 2);
    if (this->create_text(this, &this->teamTitle, 0x25AF,
                          0x136, 0x32, 100, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }
    this->teamTitle->set_alignment(0, 2);

    y = 0x55;
    row = 0;
    for (; y < 0x115; ++row, y += 0x18) {
        if (this->create_drop_down(this, &this->playerNameDrop[row],
                                   0x9E, 100, 7, y - 1,
                                   0x9E, 0x18, 0x0B) == 0) {
            return;
        }
        this->playerNameDrop[row]->set_draw_style(1);
        this->playerNameDrop[row]->set_draw_val_rect(0);
        this->playerNameDrop[row]->set_help_info(0x75F9, -1);
        this->playerNameDrop[row]->empty_list();
        if (rge_base_game->multiplayerGame()) {
            this->playerNameDrop[row]->append_line(0x25D3, 4);
            this->playerNameDrop[row]->append_line(0x25D4, 1);
            this->playerNameDrop[row]->append_line(0x25D5, 0);
        } else {
            this->playerNameDrop[row]->append_line(0x25D3, 4);
            this->playerNameDrop[row]->append_line(0x25D6, 0);
        }

        if (this->create_drop_down(this, &this->playerCivDrop[row],
                                   0x80, 100, 0xAA, y - 1,
                                   0x80, 0x18, 0x0B) == 0) {
            return;
        }
        this->playerCivDrop[row]->set_draw_style(1);
        this->playerCivDrop[row]->set_draw_val_rect(0);
        this->playerCivDrop[row]->set_help_info(0x75FA, 0x25F09);
        this->playerCivDrop[row]->empty_list();
        this->playerCivDrop[row]->append_line(0x27F7, 1);
        this->playerCivDrop[row]->append_line(0x27F8, 2);
        this->playerCivDrop[row]->append_line(0x27F9, 3);
        this->playerCivDrop[row]->append_line(0x27FA, 4);
        this->playerCivDrop[row]->append_line(0x27FB, 5);
        this->playerCivDrop[row]->append_line(0x27FC, 6);
        this->playerCivDrop[row]->append_line(0x27FD, 7);
        this->playerCivDrop[row]->append_line(0x27FE, 8);
        this->playerCivDrop[row]->append_line(0x27FF, 9);
        this->playerCivDrop[row]->append_line(0x2800, 10);
        this->playerCivDrop[row]->append_line(0x2801, 0x0B);
        this->playerCivDrop[row]->append_line(0x2802, 0x0C);
        this->playerCivDrop[row]->append_line(0x2806, 0x0D);
        this->playerCivDrop[row]->append_line(0x2807, 0x0E);
        this->playerCivDrop[row]->append_line(0x2809, 0x0F);
        this->playerCivDrop[row]->append_line(0x2808, 0x10);
        this->playerCivDrop[row]->append_line(0x280A, 0x11);

        if (this->create_drop_down(this, &this->scenarioPlayerDrop[row],
                                   0x28, 100, 0x144, y - 1,
                                   0x28, 0x18, 0x0B) == 0) {
            return;
        }
        this->scenarioPlayerDrop[row]->set_draw_style(1);
        this->scenarioPlayerDrop[row]->set_draw_val_rect(0);
        this->scenarioPlayerDrop[row]->set_help_info(0x75FB, -1);

        if (this->create_button(this, &this->playerColor[row], "", 0,
                                0x136, y, 0x1E, 0x14, 0x0B, 0, 1) == 0) {
            return;
        }
        this->playerColor[row]->set_help_info(0x7604, -1);

        if (this->create_text(this, &this->playerColorText[row], "",
                              0x131, y, 0x28, 0x16, 0x0B, 1, 1, 0) == 0) {
            return;
        }

        TButtonPanel** team = &this->playerTeam[row];
        if (this->create_button(this, team, 0x25B0,
                                0, 0x17C, y, 0x1E, 0x14, 0x0B, 0, 1) == 0) {
            return;
        }
        (*team)->set_help_info(0x7603, -1);
        (*team)->set_state_info(5);

        button_id = 1;
        do {
            sprintf(str, "%d", button_id);
            (*team)->set_text((short)button_id, str);
            int next_button_id = button_id + 1;
            (*team)->set_id((short)button_id, next_button_id, 0);
            button_id = next_button_id;
        } while (button_id < 5);

        int text_y = y + 2;
        if (this->create_text(this, &this->playerTeamText[row], "",
                              0x177, y, 0x28, 0x16, 0x0B, 1, 1, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->playerNameText[row], "",
                              0x1C, text_y, 0x8B, 0x16, 0x0B, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->playerCivText[row], "",
                              0xBF, text_y, 0x6D, 0x16, 0x0B, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->scenarioPlayerText[row], "",
                              0x159, text_y, 0x28, 0x16, 0x0B, 0, 0, 0) == 0) {
            return;
        }
        TTextPanel** player_cd = &this->playerCDText[row];
        if (this->create_text(this, player_cd, 0x25DF,
                              0x151, text_y + 1, 0x14, 0x16, 6, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->playerVersionText[row], "",
                              0x161, text_y + 1, 0x1D, 0x16, 6, 0, 0, 0) == 0) {
            return;
        }

        (*player_cd)->set_active(0);
    }

    if (rge_base_game->singlePlayerGame() || comm->IsHost()) {
        if (this->create_button(this, &this->gameSettingsButton, 0x25D2,
                                0, 0x1A4, 0x32, 0xD2, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->gameSettingsButton->set_help_info(0x75FC, -1);
    }

    if (this->create_text(this, &this->scenarioName, "",
                          0x1A4, 0x54, 0xDC, 0x44, 0x0B, 0, 0, 1) == 0) {
        return;
    }

    y = 0x53;
    TTextPanel** setting = this->settingText;
    for (; y < 0x233; ++setting, y += 0x18) {
        if (this->create_text(this, setting, "",
                              0x1A4, y, 0xDC, 0x14, 0x0B, 0, 0, 0) == 0) {
            return;
        }
    }

    if (rge_base_game->multiplayerGame()) {
        if (this->create_text(this, &this->chatTitle, 0x25D7,
                              10, 0x118, 100, 0x14, 4, 0, 1, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->chatBox, "",
                              10, 300, 400, 0x60, 10, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_auto_scrollbar(&this->chatScrollbar,
                                        this->chatBox, 0x14) == 0) {
            return;
        }
        if (this->create_edit(this, &this->chatInput, "", 0xF7, (FormatType)0,
                              10, 0x192, 400, 0x17, 10, 1, 0) == 0) {
            return;
        }
        this->chatInput->set_help_info(0x75FE, -1);
        this->chatBox->set_bevel_info(3,
                                      this->bevel_color1,
                                      this->bevel_color2,
                                      this->bevel_color3,
                                      this->bevel_color4,
                                      this->bevel_color5,
                                      this->bevel_color6);
        this->chatBox->set_help_info(0x75FD, -1);
        this->chatBox->empty_list();
    }

    if (rge_base_game->singlePlayerGame()) {
        if (this->create_text(this, &this->numberPlayersTitle, 0x25D8,
                              0x1A, 0x127, 0x14F, 0x14, 0, 0, 1, 0) == 0) {
            return;
        }
        if (this->create_drop_down(this, &this->numberPlayersDrop,
                                   0x46, 100, 0x1F, 0x142,
                                   0x46, 0x18, 0x0B) == 0) {
            return;
        }
        this->numberPlayersDrop->set_help_info(0x7600, -1);
    }

    this->i_am_ready = 0;

    if (rge_base_game->singlePlayerGame()) {
        if (this->create_button(this, &this->startButton, "", 0,
                                0x46, 0x1B8, 0xF0, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->startButton->set_text(0, 0x25EE);
        this->startButton->set_help_info(0x75FF, -1);
        this->set_curr_child(this->startButton);
        if (this->create_button(this, &this->cancelButton, 0xFA2,
                                0, 0x14A, 0x1B8, 0xF0, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->cancelButton->set_help_info(0x7532, -1);
    } else if (comm->IsHost()) {
        if (this->create_check_box(this, &this->ready_button,
                                   10, 0x1B8, 0x1E, 0x1E, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->ready_button_label, 0x25BF,
                              0x2D, 0x1B8, 0x96, 0x1E, 0, 0, 1, 0) == 0) {
            return;
        }
        this->ready_button->set_help_info(0x7602, -1);
        if (this->create_button(this, &this->startButton, "", 0,
                                0xC3, 0x1B8, 200, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->startButton->set_text(0, 0x25EE);
        this->startButton->set_help_info(0x75FF, -1);
        this->startButton->set_disabled(1);
        if (this->create_button(this, &this->cancelButton, 0xFA2,
                                0, 0x195, 0x1B8, 0xB4, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->cancelButton->set_help_info(0x7532, -1);
        if (this->create_button(this, &this->netInfoButton, 0x25EF,
                                0, 600, 400, 0x1E, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->netInfoButton->set_help_info(0x7601, -1);
        comm->SetMyReadiness(0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        if (this->create_check_box(this, &this->ready_button,
                                   100, 0x1B8, 0x1E, 0x1E, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->ready_button_label, 0x25BF,
                              0x87, 0x1B8, 0x96, 0x1E, 0, 0, 1, 0) == 0) {
            return;
        }
        this->ready_button->set_help_info(0x7602, -1);
        if (this->create_button(this, &this->cancelButton, 0xFA2,
                                0, 0x14A, 0x1B8, 0xF0, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->cancelButton->set_help_info(0x7532, -1);
    }

    if (this->create_button(this, &this->help_button, 0xFA9,
                            0, 600, 0x1B8, 0x1E, 0x1E, 0, 0, 0) == 0) {
        return;
    }
    if (this->create_button(this, &this->close_button, 0x3EA,
                            0, 0, 0, 0, 0, -1, -1, 0) == 0) {
        return;
    }
    this->close_button->set_active(1);
    this->close_button->set_positioning((TPanel::PositionMode)9, 4, 4, 4, 4,
                                        0x11, 0x11, 0x11, 0x11,
                                        0, 0, 0, 0);
    this->cancelButton->hotkey = 0x1B;
    this->cancelButton->hotkey_shift = 0;
    this->setupTabOrder();
    Log(L, "$$$ CHAT SCREEN: UPDATE SUMMARY");
    this->updateSummary();
    if (rge_base_game->singlePlayerGame()) {
        this->setupSinglePlayerPlayers();
        this->fillPlayers();
    }
    Log(L, "$$$ CHAT SCREEN: CONSTRUCTOR DONE");
}
