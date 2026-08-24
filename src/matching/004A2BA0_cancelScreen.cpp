// VA: 004A2BA0 TribeMPSetupScreen::cancelScreen(int)
// PDB donor: scr_mps.cpp:1576-1622
//
// The argument is the lobby timeout flag.  The routine selects the next
// screen for single-player, lobby, and ordinary multiplayer cancellation;
// the constructor sizes and the setup-state field below are binary-proven.
//
// Attempt log (sa64f8-cancel):
// - Natural typed new/constructor branches recovered all 18 direct calls and
//   the correct allocation sizes, but default flags omitted the original EH
//   registration and produced a 312-byte body.
// - /GX is required, matching the exact same-TU constructor donors.  A common
//   panel-name local preserved call count but changed EH-state/string-argument
//   scheduling.  Keeping the ordinary setCurrentPanel call in each successful
//   source branch lets VC5 cross-jump the common call/destroy tail and emits
//   the original single call site with each branch's literal push.
// - MATCH: 429/429 bytes, 18/18 calls, 100% shape and relocation identity.
// FLAGS: config/flags/004A2BA0_cancelScreen.rsp (/GX)

#ifndef SCR_MPS_TU_CONTEXT

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    int singlePlayerGame();
    void disable_input();
    int scenarioGame();
    void close();
};

class TCommunications_Handler {
public:
    int IsLobbyLaunched();
    void UnlinkToLevel(int service);
};

class TPanelSystem {
public:
    void setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xD4];
    int setup_failed; // +0xD8
};

class TScreenPanel : public TPanel {
public:
    char gap_DC[0x39C];
};

class TribeSelectScenarioScreen {
public:
    char gap[0x4D8];
    TribeSelectScenarioScreen();
};

class TribeSPMenuScreen {
public:
    char gap[0x49C];
    TribeSPMenuScreen();
};

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    char gap_478[0xC];
    TRIBE_Screen_Main_Error();
    void set_text(int string_id);
};

class TribeJoinScreen {
public:
    char gap[0x4B0];
    TribeJoinScreen();
};

class TribeMPSetupScreen {
public:
    void cancelScreen(int timed_out);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern TPanelSystem panel_system;

#endif

void TribeMPSetupScreen::cancelScreen(int timed_out) {
    if (rge_base_game->singlePlayerGame() != 0) {
        rge_base_game->disable_input();
        if (rge_base_game->scenarioGame() != 0) {
            new TribeSelectScenarioScreen;
            panel_system.setCurrentPanel("Select Scenario Screen", 0);
        } else {
            new TribeSPMenuScreen;
            panel_system.setCurrentPanel("Single Player Menu", 0);
        }
    } else if (comm->IsLobbyLaunched() != 0) {
        if (timed_out != 0) {
            TRIBE_Screen_Main_Error* error = new TRIBE_Screen_Main_Error;
            if (error != 0 && error->setup_failed == 0) {
                error->set_text(0x96A);
                panel_system.setCurrentPanel("Main Error Screen", 0);
            } else {
                rge_base_game->close();
                return;
            }
        } else {
            rge_base_game->close();
            return;
        }
    } else {
        rge_base_game->disable_input();
        comm->UnlinkToLevel(5);
        new TribeJoinScreen;
        panel_system.setCurrentPanel("Join Screen", 0);
    }

    panel_system.destroyPanel("MP Setup Screen");
}
