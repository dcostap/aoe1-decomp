// VA: 004A16E0 TribeMPSetupScreen::action
// scr_mps.cpp lines 812-1134
//
// Attempt log:
// - Recovered the typed panel arrays, helper ABIs, 0x220 EH frame, and 105 direct calls.
// - BINARY NOTE: The fallback is shared by null input, nonzero param_2, and exhausted loops.
//   Keep the TEasy_Panel call as one emitted tail. The source keeps a natural base-action
//   return in the non-null arm and a second null-path return; VC5 merges the call itself.
// - BINARY NOTE: All four scenario filename LEAs are four bytes before file_name+4.
//   Direct file_name access restores the three scenario blocks without changing calls.
// - BINARY NOTE: The final player loop has one initial numberPlayers call and one bottom call.
//   A do-while loop recovers the signed bottom-test shape better than an explicit break.
// - Tested 15 additional hypotheses across fallback structure, loop form, cursor ownership,
//   local order, filename base, CD evaluation, and liveness. The natural fallback form reduced
//   the strict diff from 2159 to 1641 bytes and raised exact-block coverage to 91.60%.
//   A cursor variant reached 1607 bytes but lost exact blocks and produced call-target drift;
//   it was discarded. The current source keeps the behavior-correct do-while and direct base.
//
// Current unresolved result: 1641 strict differing bytes, 96.93% shape similarity,
// 91.60% exact-block coverage, and 105/105 ordered calls. The main gaps are the shared
// fallback tail size, the file_info stack home, and final-loop register coloring.

#include <string.h>
#include <io.h>

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

class TDebuggingLog {
public:
    static void __cdecl Log(TDebuggingLog* log, const char* format, ...);
};

extern TDebuggingLog* L;                 // 62C4FC

class TPanel;
class TButtonPanel;
class TEditPanel;
class TDropDownPanel;

class TPanel {
public:
    virtual ~TPanel();                       // slot 0
    // TPanel has 56 virtuals total (slots 0..55); TButtonPanel::set_state lands at slot 56 (0xE0).
    virtual void vpad01(); virtual void vpad02(); virtual void vpad03(); virtual void vpad04();
    virtual void vpad05(); virtual void vpad06(); virtual void vpad07(); virtual void vpad08();
    virtual void vpad09(); virtual void vpad10(); virtual void vpad11(); virtual void vpad12();
    virtual void vpad13(); virtual void vpad14(); virtual void vpad15(); virtual void vpad16();
    virtual void vpad17(); virtual void vpad18(); virtual void vpad19(); virtual void vpad20();
    virtual void vpad21(); virtual void vpad22(); virtual void vpad23(); virtual void vpad24();
    virtual void vpad25(); virtual void vpad26(); virtual void vpad27(); virtual void vpad28();
    virtual void vpad29(); virtual void vpad30(); virtual void vpad31(); virtual void vpad32();
    virtual void vpad33(); virtual void vpad34(); virtual void vpad35(); virtual void vpad36();
    virtual void vpad37(); virtual void vpad38(); virtual void vpad39(); virtual void vpad40();
    virtual void vpad41(); virtual void vpad42(); virtual void vpad43(); virtual void vpad44();
    virtual void vpad45(); virtual void vpad46(); virtual void vpad47(); virtual void vpad48();
    virtual void vpad49(); virtual void vpad50(); virtual void vpad51(); virtual void vpad52();
    virtual void vpad53(); virtual void vpad54(); virtual void vpad55();

    char gap_04[0x68];
    int active;                              // +0x6C
    char gap_70[0x84];                       // +0x70..+0xF4 (TPanel size 0xF4)

    void set_curr_child(TPanel* child);      // 004663A0
    char* panelName();                       // 004666B0
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];                      // TEasy_Panel size 0x478

    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    void popupOKDialog(long msg_id, char* title, int line, int height);   // 00469EE0
    void setup_popup_help();                                               // 0046A360
};

class TScreenPanel : public TEasy_Panel {
};

class TButtonPanel : public TPanel {
public:
    virtual void set_state(int state);       // slot 56 (vtable offset 0xE0)
    int get_state();                         // 00472810
    long get_id();                           // 00472820
    void set_disabled(int disabled);         // 004727B0
};

class TEditPanel : public TPanel {
public:
    char* currentLine();                     // 00475B10
    void set_text(char* text);               // 00475970
};

class TDropDownPanel : public TPanel {
public:
    long get_id();                           // 00475420
    long get_line();                         // 00475380
    long get_line(long id);                  // 004753A0
    void set_line(long line);                // 00475250
};

class T_Scenario {
public:
    int Get_player_Active(int index);        // 0048C3B0
};

class TPanelSystem {
public:
    TPanel* panel(char* name);               // 00463D50
    int setCurrentPanel(char* name, int param);  // 00463E60
};

extern TPanelSystem panel_system;            // 62E870 (object)

class TCommunications_Handler {
public:
    int IsHost();                            // 0042CB00
    int WhoAmI();                            // 0042CAF0
    int SetMyReadiness(int ready, unsigned long u1, unsigned long u2, unsigned long u3,
                       unsigned long u4, unsigned long u5, unsigned long u6, unsigned long u7);
    long SendSharedData(long a);             // 00428820
    void SendChatMsgAll(char* msg);          // 004297D0
    int Kick(unsigned int player);           // 0042EA10
    void SetPlayerHumanity(unsigned int player, int humanity);  // 0042CC30
    int IsPlayerHuman(unsigned int player);  // 0042CCD0
};

extern TCommunications_Handler* comm;        // 62C4C0

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class RGE_Prog_Info {
public:
    char gap_00[0xC17];
    char scenario_dir[1];
};

class TRIBE_Game {
public:
    VPAD16(0)
    VPAD2(16)
    virtual void beginStart();               // vtable slot 18 (offset 0x48)
    char gap_04[0x08];
    RGE_Prog_Info* prog_info;                // +0x0C

    unsigned char playerVersion(int);        // 004224C0
    int check_for_cd(int);                   // 0041FC90
    int scenarioGame();                      // 004223A0
    int multiplayerGame();                   // 00422400
    int singlePlayerGame();                  // 004223F0
    int numberPlayers();                     // 00422650
    char* scenarioName();                    // 004223E0
    long get_scenario_checksum(char* name);  // 00422D20
    void disable_input();                    // 00422A50
    void close();                            // 004200B0
    void setNumberPlayers(int n);            // 004227E0
    void setPlayerTeam(int i, unsigned char v);   // 00422880
    void setCivilization(int i, int v);      // 00529350
    void setScenarioPlayer(int i, int v);    // 00529380
    int scenarioPlayer(int i);               // 00529370
    void setPlayerColor(int i, unsigned char v); // 005293B0
};

extern TRIBE_Game* rge_base_game;            // 62C574

class TribeGameSettingsScreen : public TScreenPanel {
public:
    char gap_478[0xE8];                  // sizeof == 0x560
    TribeGameSettingsScreen();           // 004B4880
};

class TribeMPSetupScreen : public TScreenPanel {
public:
    TPanel* title;                 // +478
    TPanel* playerTitle;           // +47C
    TPanel* civTitle;              // +480
    TPanel* settingsTitle;         // +484
    TPanel* colorTitle;            // +488
    TPanel* teamTitle;             // +48C
    TPanel* playerNameText[8];     // +490
    TPanel* playerCivText[8];      // +4B0
    TPanel* scenarioPlayerText[8]; // +4D0
    TPanel* playerCDText[8];       // +4F0
    TPanel* playerVersionText[8];  // +510
    TPanel* playerColorText[8];    // +530
    TPanel* playerTeamText[8];     // +550
    TButtonPanel* playerColor[8];  // +570
    TButtonPanel* playerTeam[8];   // +590
    TDropDownPanel* playerNameDrop[8];      // +5B0
    TDropDownPanel* playerCivDrop[8];       // +5D0
    TDropDownPanel* scenarioPlayerDrop[8];  // +5F0
    TEditPanel* chatInput;         // +610
    TPanel* chatTitle;             // +614
    TPanel* chatBox;               // +618
    TPanel* chatScrollbar;         // +61C
    TButtonPanel* gameSettingsButton;  // +620
    TPanel* scenarioName;          // +624
    TPanel* victoryFixedText;      // +628
    TPanel* settingText[20];       // +62C
    TPanel* settingValue[20];      // +67C
    TPanel* mapSizeLabel;          // +6CC
    TDropDownPanel* mapSizeDrop;   // +6D0
    TPanel* mapTypeLabel;          // +6D4
    TDropDownPanel* mapTypeDrop;   // +6D8
    TPanel* numberPlayersTitle;    // +6DC
    TDropDownPanel* numberPlayersDrop;   // +6E0
    TPanel* numberPlayersText;     // +6E4
    TPanel* hiddenMapButton;       // +6E8
    TPanel* hiddenMapText;         // +6EC
    TPanel* victoryTypeLabel;      // +6F0
    TPanel* victoryTypeDrop;       // +6F4
    TPanel* victoryAmountLabel;    // +6F8
    TPanel* victoryAmountInput;    // +6FC
    TButtonPanel* startButton;     // +700
    TPanel* readyButtons[2];       // +704
    TButtonPanel* cancelButton;    // +70C
    TButtonPanel* help_button;     // +710
    TButtonPanel* ready_button;    // +714
    TButtonPanel* close_button;    // +718
    TPanel* ready_button_label;    // +71C
    int cancelMode;                // +720
    int playerToKick;              // +724
    int scenarioPlayerCount;       // +728
    int myCivilization;            // +72C
    int myScenarioPlayer;          // +730
    int myPlayerColor;             // +734
    int myPlayerTeam;              // +738
    long myScenarioChecksum;       // +73C
    char saveScenarioName[256];    // +740
    int saveRandomGame;            // +840
    long saveScenarioChecksum;     // +844
    T_Scenario* scenarioInfo;      // +848
    int settingsFixed;             // +84C
    int numberAnyPlayers;          // +850
    int sent_cd_status;            // +854
    TPanel* netInfoButton;         // +858
    int i_am_ready;                // +85C
    int rest_860[11];              // +860
    int resend_game_options;       // +88C

    void startGame();              // 004A2060
    void fillPlayers();            // 004A37D0
    void updateSummary();          // 004A4190
    void cancelScreen(int mode);   // 004A2BA0
    void showNetInfo();            // 004A2910
    void kickPlayer(int player);   // 004A4FC0

    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

long TribeMPSetupScreen::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    char file_name[260];
    _finddata_t file_info;

    if (param_1 != 0) {
        if (param_1 == this->startButton && param_2 == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            this->startGame();
            return 1;
        }

        if (param_1 == this->ready_button && param_2 == 1) {
            if (this->ready_button->get_state() != 0) {
                TDebuggingLog::Log(L, "$$$ SELECTED I'M READY");
                if (comm->IsHost()) {
                    comm->SetMyReadiness(1, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    if (rge_base_game->playerVersion(0) != 1) {
                        this->ready_button->set_state(0);
                        this->popupOKDialog(0x25E3, 0, 0x1C2, 100);
                        return 1;
                    }
                    int me = comm->WhoAmI() - 1;
                    TDebuggingLog::Log(L, "$$$ SAVING MYCIV & MYTEAM");
                    this->myCivilization = this->playerCivDrop[me]->get_id();
                    this->myScenarioPlayer = this->scenarioPlayerDrop[me]->get_id();
                    this->myPlayerColor = this->playerColor[me]->get_id();
                    this->myPlayerTeam = this->playerTeam[me]->get_state() + 1;
                    if (rge_base_game->scenarioGame()) {
                        char* dir = rge_base_game->prog_info->scenario_dir;
                        sprintf(file_name, "%s%s.scn", dir,
                                rge_base_game->scenarioName());
                        if (_findfirst(file_name, (struct _finddata_t*)&file_info.time_create) == -1) {
                            sprintf(file_name, "%s.scx", rge_base_game->scenarioName());
                        } else {
                            sprintf(file_name, "%s.scn", rge_base_game->scenarioName());
                        }
                        this->myScenarioChecksum = rge_base_game->get_scenario_checksum(file_name);
                    } else {
                        this->myScenarioChecksum = 0;
                    }
                    comm->SetMyReadiness(1, this->myCivilization, this->myScenarioPlayer + 1,
                        rge_base_game->check_for_cd(0) + 1, this->myPlayerColor, this->myPlayerTeam,
                        this->myScenarioChecksum, 1);
                }
                if (this->chatInput != 0 && this->chatInput->active != 0) {
                    this->set_curr_child(this->chatInput);
                }
                this->i_am_ready = 1;
            } else {
                TDebuggingLog::Log(L, "$$$ SELECTED NOT READY");
                int cd = 0;
                if (!comm->IsHost()) {
                    cd = rge_base_game->check_for_cd(0) + 1;
                }
                comm->SetMyReadiness(0, 0, 0, cd, 0, 0, 0, 0);
                if (this->chatInput != 0 && this->chatInput->active != 0) {
                    this->set_curr_child(this->chatInput);
                }
                this->i_am_ready = 0;
            }
            this->fillPlayers();
            if (comm->IsHost()) {
                this->gameSettingsButton->set_disabled(this->i_am_ready);
                this->startButton->set_disabled(this->i_am_ready == 0);
                rge_base_game->beginStart();
                this->resend_game_options = 0;
                comm->SendSharedData(1);
                return 1;
            }
            goto L_1F6B;
        }

        if (param_1 == this->gameSettingsButton && param_2 == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            if (panel_system.panel("Game Settings Screen") == 0) {
                rge_base_game->disable_input();
                new TribeGameSettingsScreen();
            }
            panel_system.setCurrentPanel("Game Settings Screen", 0);
            return 1;
        }

        if (param_1 == this->help_button && param_2 == 1) {
            this->setup_popup_help();
            return 1;
        }

        if (param_1 == this->close_button && param_2 == 1) {
            rge_base_game->close();
            return 1;
        }

        if (param_1 == this->cancelButton && param_2 == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            this->cancelScreen(0);
            return 1;
        }

        if (param_1 == this->netInfoButton) {
            if (param_2 == 1) {
                this->showNetInfo();
                return 1;
            }
        } else if (param_2 == 1) {
            for (int i = 0; i < 8; i++) {
                if (param_1 == this->playerColor[i]) {
                    rge_base_game->setPlayerColor(i, this->playerColor[i]->get_id());
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myPlayerColor = this->playerColor[i]->get_id();
                        return 1;
                    }
                    goto L_1F6B;
                }
                if (param_1 == this->playerTeam[i]) {
                    rge_base_game->setPlayerTeam(i, this->playerTeam[i]->get_state() + 1);
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myPlayerTeam = this->playerTeam[i]->get_state() + 1;
                        return 1;
                    }
                    goto L_1F6B;
                }
            }
        }

        if (param_1 == this->chatInput && param_2 == 0 &&
            this->chatInput->currentLine() != 0 && this->chatInput->currentLine()[0] != 0) {
            comm->SendChatMsgAll(this->chatInput->currentLine());
            this->chatInput->set_text("");
            return 1;
        }

        if (param_1 == this->numberPlayersDrop && param_2 == 0) {
            rge_base_game->setNumberPlayers(this->numberPlayersDrop->get_id());
            this->updateSummary();
            return 1;
        }

        if (param_1->panelName() != 0 && strcmp(param_1->panelName(), "Game Settings Screen") == 0) {
            if (param_2 != 0) {
                this->updateSummary();
                if (!rge_base_game->singlePlayerGame()) {
                    rge_base_game->beginStart();
                    this->resend_game_options = 0;
                }
            }
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            return 1;
        }

        if (param_1->panelName() != 0 && strcmp(param_1->panelName(), "Kick Dialog") == 0) {
            if (param_2 == 0) {
                long id = this->playerNameDrop[this->playerToKick - 1]->get_id();
                comm->Kick(this->playerToKick);
                comm->SetPlayerHumanity(this->playerToKick, id);
                this->playerNameDrop[this->playerToKick - 1]->set_line(
                    this->playerNameDrop[this->playerToKick - 1]->get_line(id));
            } else {
                this->playerNameDrop[this->playerToKick - 1]->set_line(0);
            }
            delete param_1;
            return 1;
        }

        if (param_2 == 0 && rge_base_game->numberPlayers() > 0) {
            int i = 0;
            do {
                if (param_1 == this->playerNameDrop[i]) {
                    if (rge_base_game->multiplayerGame() &&
                        this->playerNameDrop[i]->get_line() > 0 &&
                        comm->IsPlayerHuman(i + 1)) {
                        this->kickPlayer(i + 1);
                        return 1;
                    }
                    comm->SetPlayerHumanity(i + 1, this->playerNameDrop[i]->get_id());
                    return 1;
                }
                if (param_1 == this->playerCivDrop[i]) {
                    rge_base_game->setCivilization(i, this->playerCivDrop[i]->get_id());
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myCivilization = this->playerCivDrop[i]->get_id();
                        return 1;
                    }
                    goto L_1F6B;
                }
                if (param_1 == this->scenarioPlayerDrop[i]) {
                    if (rge_base_game->multiplayerGame()) {
                        rge_base_game->setScenarioPlayer(i, this->scenarioPlayerDrop[i]->get_id());
                        if (!comm->IsHost()) {
                            this->myScenarioPlayer = this->scenarioPlayerDrop[i]->get_id();
                            return 1;
                        }
                        goto L_1F6B;
                    }
                    rge_base_game->setScenarioPlayer(0, this->scenarioPlayerDrop[0]->get_id());
                    int sp = 1;
                    int player = 0;
                    do {
                        if (player != rge_base_game->scenarioPlayer(0) &&
                            this->scenarioInfo->Get_player_Active(player) != 0) {
                            rge_base_game->setScenarioPlayer(sp, player);
                            sp++;
                            if (sp >= rge_base_game->numberPlayers()) break;
                        }
                        player++;
                    } while (player < 8);
                    this->fillPlayers();
                    goto L_1F6B;
                }
                i++;
            } while (i < rge_base_game->numberPlayers());
        }
        return this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
L_1F6B:
        return 1;
    }
L_1F72:
    return this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
