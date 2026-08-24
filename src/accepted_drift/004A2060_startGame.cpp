// VA: 004A2060 TribeMPSetupScreen::startGame
// PDB source: scr_mps.cpp lines 1140-1446
// __thiscall: this in ecx, no stack params. int return (1 = ok, 0 = error).
//
// Attempt log:
// 1 baseline: natural reconstruction of the full 83-call multiplayer start sequence
//   (host/ready checks, scenario checksum + player-version scans, scenario validation,
//   scenario-player dropdown fill, player count/color uniqueness, human+CD check,
//   randomize positions, single-player humanity fill, civ/team +0x32 reset, apply
//   colors/teams/civs, destroy status screen, launch multiplayer, start_game).
//   Frame exact (0x568). diff=1617 (87.5%), shape 84.83%, calls 76/83.
// 2 control-flow: forced the scenario-checksum error handler to a cold tail at the
//   very end via goto; VC5 re-emitted identical bytes (codegen duplicate), so the
//   error tail placement is not source-controllable through goto here.
// 7 source-shape audit: msg/msg_small BASE (not +4) for all four error handlers;
//   inline sprintf arguments (right-to-left cdecl pushes the GetPlayerName result
//   BEFORE the get_string call); single numberPlayers call in the single-player fill;
//   field_88C at +0x88C (4-byte gap at +0x888); temp_team[c-1] folds to
//   [esp+eax*4+14h]; block-5 dead `cmp eax,2` comes from if(hum==2||hum==4){ if
//   (hum==2){...}else{...} }. diff=1628 -> calls 79/83.
// 8 control-flow: CHECKSUM LOOP AS FOR-HEADER (init+increments in the for clause,
//   PDB line 1192 attribution) places the checksum-mismatch error as the COLD TAIL at
//   the end exactly like the original (the do-while form kept it inline). diff=530,
//   calls 83/83, EXACT CODEGEN stage reached.
// 9 liveness: checksum init order i3,u12,pl in source order. diff=523.
// 10-12 liveness/context: variable reuse and the full typed TribeMPSetupScreen class
//   surface (TPanel/TScreenPanel bases, 004A1300 donor layout) do not change the
//   register allocation (codegen duplicate / no effect).
// 14 control-flow: full for-header init clauses for the checksum loop; version loop as
//   `for (u12 = 0; u12 < 8; u12 = u4)` (matches PDB 1208 attribution). diff=520.
// 15-17 behavior: block-12 fill loop do-while val=idx+1/idx=val; then binary-proven
//   fills: temp_team/temp_civ filled with DWORD value 1 (mov eax,1; rep stosd - NOT
//   memset(...,1,...) which emits 0x01010101); civ/team check is >= 0x32 (cmp 32h)
//   not > 0x31; block-4 numberLines compare with i3 on the left (i3 >= lines);
//   0x25c3/0x25c5 compares with i5 on the left (i5 > count / i5 != count).
//   diff=67 (3.6%), shape 99.12%, exact-blocks 93.1%, calls 83/83, size/frame exact.
//
// Final state (10 meaningful probes this claim): diff=67 bytes (3.6275%), shape 99.12%,
// calls 83/83 aligned, exact-block coverage 93.12%, code_size/frame/saved-regs exact.
// Remaining drift is a whole-function register-allocation basin only:
// - original holds `this` in EBP (spilled to [esp+14h] when EBP becomes the block-12
//   cnt counter); rebuilt holds this in EBX. Every remaining byte diff is the ebp<->ebx
//   renaming plus the role-register swaps (version-loop u12b/u4 in esi/edi vs edi/esi,
//   block-4 i3/u4b in ebx/edi vs edi/ebp, block-5 i5 ebx vs ebp), the block-12 fill
//   loop `mov edx,eax; cmp edx,8` vs `cmp eax,8; mov edx,eax` scheduling, and
//   sub eax,32h vs add eax,0FFFFFFCEh in the civ/team reset.
// Resisted: variable reuse (probe-10/12), full typed class surface (probe-13), for/
// do-while loop forms, init clause orders, declaration scopes. This looks like a
// hard VC5 allocator basin; a future worker should try function-top declarations of
// the role variables in first-use order or a variant lab before accepting the drift.
//
// Follow-up sa44_startGame_followup:
// - confirmed the clean natural no-VPAD game/panel surface, exact frame/size, and 83/83
//   ordered calls; first checker hunk remains version-loop register roles at +0100.
// - swapped version roles, reused/top-declared loop scalars, changed the block-12
//   condition to the computed value, used compound civ/team decrements, moved
//   send_options, tested natural base/derived game ownership, and tried saved-this
//   aliases; all emitted the same 67-byte mismatch.
// - focused natural variant lab (send initialization x temp_team zero-fill, 4 variants)
//   preserved size/frame/call-set but collapsed to one codegen group, still diff=67.
// - restored the canonical no-VPAD source; remaining drift is the whole-function EBP/
//   EBX allocator basin plus documented role-register swaps, not a call/layout gap.
// - Fresh claim: same-TU prologue donor search confirms the remaining gap is
//   the allocator basin, not a missing call, layout, or declaration identity.
//
// Follow-up sa-f81e3ed5-r1 (21 meaningful probes, 2026-08-17):
// - bool send_options changed the frame shape and size. A split declaration did not.
// - A saved-this alias, top-scope role declarations, register hints, and scalar-first
//   declaration order kept the 67-byte result. The same held for TEasy inheritance.
// - Reviewed base/derived game ownership and extern global forms kept the same bytes.
//   They changed relocation counts only. Keep the current local macro for this target.
// - Explicit version and color loop forms moved control flow or grew the diff.
//   Compound civ/team decrements, zero-fill loops, and standard-header additions did not.
// - A 64-sample ambient declaration lab made one codegen group. A five-flag lab made
//   four default groups and one wrong-frame /O1-style group. No exact result appeared.
// - BINARY NOTE: the clean source remains 1847 bytes, frame 0x568, 83/83 ordered calls,
//   and 67 differing bytes. The first mismatch is the original EBP receiver versus
//   rebuilt EBX receiver at +0009. The remaining drift is register allocation only.
// ACCEPTED DRIFT: The residual exchanges the receiver, loop indexes, and counters
// between saved registers. One loop schedules a copy around its compare, and the
// civ/team reset uses `sub 0x32` versus `add -0x32`; its flags are dead. All 83
// calls, pushed values, branches, fills, memory effects, returns, and fault order
// match. The frame, saved registers, EH state, and function boundary also match.
// Authentic scr_mps.cpp context kept 1847 bytes, 83 calls, and the 67-byte diff.
// - DIA private symbols prove scoped msg[1024], playerColorUsed[8], msg[256],
//   temp_team[8], temp_color[8], and temp_civ[8]. The two int arrays share
//   the original EBP-1376 home because their lifetimes do not overlap.
// - Adding exact 004A0D80, 004A1300, and 004A1640 owners preserved this result.
//   The reviewed RGE_Base_Game* global type is required. TRIBE_Game* changed
//   the target to a 563-byte register-allocation basin.

#ifndef SCR_MPS_TU_CONTEXT

#include <string.h>
#include <windows.h>

extern "C" int __cdecl sprintf(char*, const char*, ...);

#define rge_base_game (*(TRIBE_Game**)0x0062C574)
#define comm (*(TCommunications_Handler**)0x0062C4C0)
#define L (*(TDebuggingLog**)0x0062C4FC)
#define chat (*(TChat**)0x0062C4B8)
#define AppWnd (*(void**)0x005B236C)
#define panel_system (*(TPanelSystem*)0x0062E870)

class TDebuggingLog {};
extern "C" void __cdecl Log(TDebuggingLog* self, char* msg);

class TTextPanel {
public:
    int numberLines();
};

class TDropDownPanel {
public:
    char pad_00[0xFC];
    TTextPanel* list_panel;      // +0xFC
    long get_id(int);
};

class TCommunications_Handler {
public:
    int IsHost();
    int AllPlayersReady();
    int WhoAmI();
    int GetPlayerHumanity(int);
    char* GetPlayerName(int);
    void SetPlayerHumanity(int, int);
    void LaunchMultiplayerGame();
    void* SetWindowHandle(void*);
};

class TChat {
public:
    void setWindowHandle(void*);
};

class TPanelSystem {
public:
    int destroyPanel(char* name);
};

class TPanel {
public:
    char _gap_04[0x1C];
    void* render_area;
    char _gap_24[0x1C];
    void* parent_panel;
    char _gap_44[0x28];
    int active;
    int visible;
    char _gap_74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char _gap_9C[0x44];
    int display_changed_count;
    char _gap_E4[0x10];

    virtual ~TPanel();
};

class TScreenPanel : public TPanel {
public:
    char _gap_F4[0x384];
    virtual ~TScreenPanel();
};

class T_Scenario {
public:
    virtual void unknown();
    virtual ~T_Scenario();
};

class RGE_Scenario;
class RGE_Scenario_Header;

// RGE_Base_Game / TRIBE_Game played through the rge_base_game global.
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario*);
    virtual RGE_Scenario_Header* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void beginStart();   // vtable slot 18 (offset 0x48)
    int multiplayerGame();
    int scenarioGame();
    int singlePlayerGame();
    int numberPlayers();
    unsigned char playerVersion(int);
    int check_for_cd(int);
    void setPlayerHasCD(int, int);
    int playerTeam(int);
    void setPlayerTeam(int, int);
    void setScenarioPlayer(int, int);
    int playerColor(int);
    void setPlayerColor(int, int);
    int civilization(int);
    void setCivilization(int, int);
    int randomizePositions();
    int start_game(int);
};

class TribeMPSetupScreen : public TScreenPanel {
public:
    TPanel* title;                  // +478
    TPanel* playerTitle;            // +47C
    TPanel* civTitle;               // +480
    TPanel* settingsTitle;          // +484
    TPanel* colorTitle;             // +488
    TPanel* teamTitle;              // +48C
    TPanel* playerNameText[8];      // +490
    TPanel* playerCivText[8];       // +4B0
    TPanel* scenarioPlayerText[8];  // +4D0
    TPanel* playerCDText[8];        // +4F0
    TPanel* playerVersionText[8];   // +510
    TPanel* playerColorText[8];     // +530
    TPanel* playerTeamText[8];      // +550
    TPanel* playerColor[8];         // +570
    TPanel* playerTeam[8];          // +590
    TPanel* playerNameDrop[8];      // +5B0
    TPanel* playerCivDrop[8];       // +5D0
    TDropDownPanel* scenarioPlayerDrop[8]; // +5F0
    TPanel* chatInput;              // +610
    TPanel* chatTitle;              // +614
    TPanel* chatBox;                // +618
    TPanel* chatScrollbar;          // +61C
    TPanel* gameSettingsButton;     // +620
    TPanel* scenarioName;           // +624
    TPanel* victoryFixedText;       // +628
    TPanel* settingText[20];        // +62C
    TPanel* settingValue[20];       // +67C
    TPanel* mapSizeLabel;           // +6CC
    TPanel* mapSizeDrop;            // +6D0
    TPanel* mapTypeLabel;           // +6D4
    TPanel* mapTypeDrop;            // +6D8
    TPanel* numberPlayersTitle;     // +6DC
    TPanel* numberPlayersDrop;      // +6E0
    TPanel* numberPlayersText;      // +6E4
    TPanel* hiddenMapButton;        // +6E8
    TPanel* hiddenMapText;          // +6EC
    TPanel* victoryTypeLabel;       // +6F0
    TPanel* victoryTypeDrop;        // +6F4
    TPanel* victoryAmountLabel;     // +6F8
    TPanel* victoryAmountInput;     // +6FC
    TPanel* startButton;            // +700
    TPanel* readyButtons[2];        // +704
    TPanel* cancelButton;           // +70C
    TPanel* help_button;            // +710
    TPanel* ready_button;           // +714
    TPanel* close_button;           // +718
    TPanel* ready_button_label;     // +71C
    int cancelMode;                 // +720
    int playerToKick;               // +724
    int scenarioPlayerCount;        // +728
    int myCivilization;             // +72C
    int myScenarioPlayer;           // +730
    int myPlayerColor;              // +734
    int myPlayerTeam;               // +738
    long myScenarioChecksum;        // +73C
    char saveScenarioName[256];     // +740
    int saveRandomGame;             // +840
    long saveScenarioChecksum;      // +844
    T_Scenario* scenarioInfo;       // +848
    int settingsFixed;              // +84C
    int numberAnyPlayers;           // +850
    int sent_cd_status;             // +854
    TPanel* netInfoButton;          // +858
    int pad_85C[3];                 // +85C
    long scenarioCheckSum[8];       // +868 .. +884
    int pad_888;                    // +888
    int resend_game_options;        // +88C

    virtual ~TribeMPSetupScreen();

    char* get_string(int);
    void popupOKDialog(int, int, int, int);              // 0x469EE0
    void popupOKDialog(char*, int, int, int);            // 0x469F30
    void calcRandomPositions();                          // 0x4A27A0
    int startGame();
};

#endif

int TribeMPSetupScreen::startGame()
{
    int send_options = 0;

    if (rge_base_game->multiplayerGame()) {
        char msg[1024];
        if (!comm->IsHost()) {
            return 0;
        }
        if (!comm->AllPlayersReady()) {
            this->popupOKDialog(0x25c1, 0, 0x1c2, 100);
            return 0;
        }
        int u12;
        if (rge_base_game->scenarioGame()) {
            int i3;
            int* pl;
            for (i3 = 0, u12 = 1, pl = this->scenarioCheckSum; u12 < 9; i3++, pl++, u12++) {
                if (u12 != comm->WhoAmI() &&
                    comm->GetPlayerHumanity(u12) == 2) {
                    if (*pl != this->myScenarioChecksum) {
                        sprintf(msg, this->get_string(0x25e1), comm->GetPlayerName(i3 + 1));
                        this->popupOKDialog(msg, 0, 0x1c2, 100);
                        return 0;
                    }
                }
            }
        }
        int u4;
        for (u12 = 0; u12 < 8; u12 = u4) {
            u4 = u12 + 1;
            if (u4 != comm->WhoAmI() &&
                comm->GetPlayerHumanity(u4) == 2) {
                if (rge_base_game->playerVersion(u12) != 1) {
                    sprintf(msg, this->get_string(0x25e2), comm->GetPlayerName(u12 + 1));
                    this->popupOKDialog(msg, 0, 0x1c2, 100);
                    return 0;
                }
            }
        }
    }

    if (rge_base_game->scenarioGame() && this->scenarioInfo == 0) {
        this->popupOKDialog(0x25c2, 0, 0x1c2, 100);
        return 0;
    }

    if (rge_base_game->multiplayerGame() && rge_base_game->scenarioGame()) {
        int i3 = 0;
        int u12 = 0;
        int u4b;
        do {
            u4b = u12 + 1;
            int hum = comm->GetPlayerHumanity(u4b);
            if (hum == 2 || hum == 4) {
                long id = this->scenarioPlayerDrop[0]->get_id(i3);
                ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(u12, id);
                i3++;
                if (i3 >= this->scenarioPlayerDrop[0]->list_panel->numberLines()) {
                    i3 = 0;
                }
            }
            u12 = u4b;
        } while (u4b < 8);
    }

    if (rge_base_game->multiplayerGame()) {
        int playerColorUsed[8];
        char msg[256];
        memset(playerColorUsed, 0, sizeof(playerColorUsed));
        int i5 = 0;
        int u12 = 0;
        int num = rge_base_game->numberPlayers();
        if (num > 0) {
            int u4c;
            do {
                u4c = u12 + 1;
                int hum = comm->GetPlayerHumanity(u4c);
                if (hum == 2 || hum == 4) {
                    if (hum == 2) {
                        int c = ((TRIBE_Game*)rge_base_game)->playerColor(u12);
                        if (playerColorUsed[c - 1] == 0) {
                            i5++;
                            c = ((TRIBE_Game*)rge_base_game)->playerColor(u12);
                            playerColorUsed[c - 1] = 1;
                        }
                    } else {
                        i5++;
                    }
                }
                u12 = u4c;
            } while (u4c < rge_base_game->numberPlayers());
        }
        if (i5 < 2) {
            this->popupOKDialog(0x25c6, 0, 0x1c2, 100);
            return 0;
        }
        if (rge_base_game->scenarioGame() && i5 > this->scenarioPlayerCount) {
            sprintf(msg, this->get_string(0x25c3), this->scenarioPlayerCount);
            this->popupOKDialog(msg, 0, 0x1c2, 100);
            return 0;
        }
        if (rge_base_game->scenarioGame() && this->settingsFixed != 0 &&
            i5 != this->scenarioPlayerCount) {
            sprintf(msg, this->get_string(0x25c5), this->scenarioPlayerCount);
            this->popupOKDialog(msg, 0, 0x1c2, 100);
            return 0;
        }

        int i5h = 0;
        int u12c = 0;
        int nump = rge_base_game->numberPlayers();
        if (nump > 0) {
            do {
                u12c++;
                if (comm->GetPlayerHumanity(u12c) == 2) {
                    i5h++;
                }
            } while (u12c < rge_base_game->numberPlayers());
        }
        int cd = rge_base_game->check_for_cd(0);
        rge_base_game->setPlayerHasCD(comm->WhoAmI() - 1, cd);
        int cd2 = rge_base_game->check_for_cd(i5h);
        if (cd2 == 0) {
            this->popupOKDialog(0x7d9, 0, 0x1c2, 100);
            return 0;
        }
    }

    if (rge_base_game->scenarioGame() && ((TRIBE_Game*)rge_base_game)->randomizePositions()) {
        this->calcRandomPositions();
        if (rge_base_game->multiplayerGame()) {
            send_options = 1;
        }
    }

    if (rge_base_game->singlePlayerGame()) {
        int num = rge_base_game->numberPlayers();
        if (num < 8) {
            int u12 = num + 1;
            do {
                comm->SetPlayerHumanity(u12, 0);
                u12++;
            } while (u12 < 9);
        }
    }

    if (rge_base_game->multiplayerGame()) {
        int i5 = 0;
        int num = rge_base_game->numberPlayers();
        if (num > 0) {
            do {
                int civ = ((TRIBE_Game*)rge_base_game)->civilization(i5);
                if (civ >= 0x32) {
                    Log(L, (char*)0x00586894);
                    civ = ((TRIBE_Game*)rge_base_game)->civilization(i5);
                    ((TRIBE_Game*)rge_base_game)->setCivilization(i5, civ - 0x32);
                    send_options = 1;
                }
                int team = rge_base_game->playerTeam(i5);
                if (team >= 0x32) {
                    Log(L, (char*)0x0058687C);
                    team = rge_base_game->playerTeam(i5);
                    rge_base_game->setPlayerTeam(i5, team - 0x32);
                    send_options = 1;
                }
                i5++;
            } while (i5 < rge_base_game->numberPlayers());
        }
    }

    if (rge_base_game->multiplayerGame()) {
        int temp_team[8];
        int temp_color[8];
        int temp_civ[8];
        int idx = 0;
        for (int i = 0; i < 8; i++) temp_team[i] = 1;
        for (int j = 0; j < 8; j++) temp_civ[j] = 1;
        do {
            int val = idx + 1;
            temp_color[idx] = val;
            idx = val;
        } while (idx < 8);
        int cnt = 0;
        for (int u12 = 1; u12 < 9; u12++) {
            int hum = comm->GetPlayerHumanity(u12);
            if (hum == 2 || hum == 4) {
                int p = u12 - 1;
                temp_color[cnt] = ((TRIBE_Game*)rge_base_game)->playerColor(p);
                temp_civ[cnt] = ((TRIBE_Game*)rge_base_game)->civilization(p);
                temp_team[cnt] = rge_base_game->playerTeam(p);
                cnt++;
            }
        }
        if (cnt > 0) {
            for (int i = 0; i < 8; i++) {
                ((TRIBE_Game*)rge_base_game)->setPlayerColor(i, temp_color[i]);
                ((TRIBE_Game*)rge_base_game)->setCivilization(i, temp_civ[i]);
                rge_base_game->setPlayerTeam(i, temp_team[i]);
            }
            send_options = 1;
        }
    }

    panel_system.destroyPanel((char*)0x00586218);

    if (rge_base_game->multiplayerGame()) {
        if (send_options || this->resend_game_options != 0) {
            rge_base_game->beginStart();
            this->resend_game_options = 0;
        }
        comm->LaunchMultiplayerGame();
        chat->setWindowHandle(AppWnd);
        comm->SetWindowHandle(AppWnd);
    }

    if (!((TRIBE_Game*)rge_base_game)->start_game(0)) {
        this->popupOKDialog(0x961, 0, 0x1c2, 100);
        return 0;
    }
    return 1;
}
