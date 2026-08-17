// VA: 004982E0 TRIBE_Screen_Game::action
// PDB source: scr_game.cpp
// Attempt log:
// - baseline was a close behavior skeleton but used the wrong base-panel
//   action slot, recursed through action for button dispatch, and called
//   screen helpers where the original calls TRIBE_Game helpers.
// - reconstructed the period panel hierarchy and the shared dialog branches;
//   the original EH registration/new path is retained through the target flag
//   context below.
// - /GX plus the real TEasy_Panel vslot+B4, base-game dialog calls, null-name
//   guard, and explicit null-panel base return aligned all 33 calls and exact
//   size; best strict diff is 523 bytes (99.22% shape, 93.98% exact blocks).
// - indexed/aliased action and close-pause receiver variants were diagnostic;
//   the current direct parameter and natural branch-local restart receiver are
//   retained.  Remaining drift is EH-handler identity and a localized
//   confirmed-close/global-load schedule; left in scratch for later work.
// - a typed close-pause receiver moved the global load before confirmed_close,
//   but worsened the diff from 523 to 533 bytes; rolled back.
// - limiting that receiver to singlePlayerGame collapsed the tail and lost two
//   calls (diff 623); rolled back.  The direct global form remains best.
// - a named TRIBE_Game global plus a direct restart receiver reduced the
//   diagnostic diff to 12 bytes; the close global still used the wrong load
//   schedule, so this mixed surface was rolled back.
// - a close-only TRIBE_Game receiver on that named global produced exact
//   instruction shape and a 1-byte branch-target drift; the dual global
//   surface is diagnostic, not retained source.
// - original rdata proves CloseProgramDialog and QuitAndLoadDialog, not the
//   earlier Save Game Dialog spelling.  Two split fallback labels reproduce
//   the original shared action call and reduce the strict diff to 523 bytes.
// - restoring natural string literals in that split source reduces the strict
//   diff to 517 bytes with a 2-byte size excess.  Receiver-local cleanup
//   variants measured 532 and 533 bytes; the remaining gap is cleanup order.
// FLAGS: config/flags/004982E0_action.rsp (/GX required by original EH setup)

#include <new.h>
#include <string.h>

class TPanel {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void set_active(int active);
    virtual void v18();
    virtual void v1C();
    virtual void v20();

    char gap_04[0x68];
    int active;
    char gap_70[0x84];

    char* panelName();
};

class TEasy_Panel : public TPanel {
public:
    virtual void ev24(); virtual void ev28(); virtual void ev2C();
    virtual void ev30(); virtual void ev34(); virtual void ev38();
    virtual void ev3C(); virtual void ev40(); virtual void ev44();
    virtual void ev48(); virtual void ev4C(); virtual void ev50();
    virtual void ev54(); virtual void ev58(); virtual void ev5C();
    virtual void ev60(); virtual void ev64(); virtual void ev68();
    virtual void ev6C(); virtual void ev70(); virtual void ev74();
    virtual void ev78(); virtual void ev7C(); virtual void ev80();
    virtual void ev84(); virtual void ev88(); virtual void ev8C();
    virtual void ev90(); virtual void ev94(); virtual void ev98();
    virtual void ev9C(); virtual void evA0(); virtual void evA4();
    virtual void evA8(); virtual void evAC(); virtual void evB0();
    virtual long action(TPanel*, long, unsigned long, unsigned long);

    char gap_F4[0x384];
};

class TScreenPanel : public TEasy_Panel {
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

class RGE_Player {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26();
    virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52();
    virtual void resign(int who, long id);
};

class RGE_Base_Game {
public:
    char gap_00[0xA00];
    int save_paused;

    void close();
    void set_paused(int paused, int mode);
    int singlePlayerGame();
    RGE_Player* get_player();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void restart_game();
    void do_game_over();
};

class TCommunications_Handler {
public:
    int WhoAmI();
};

class TribeLoadSavedGameScreen {
public:
    char gap_00[0x494];
    TribeLoadSavedGameScreen();
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x4C4 - 0x478];
    TPanel* object_panel;
    TPanel* button_panel[17];
    char gap_50C[0x70];
    TEasy_Panel* tool_box;
    char gap_580[0x1B0];
    int resign_flag;

    void object_changed();
    void do_button_action(int value, unsigned long flags, int mode);
    long action(TPanel*, long, unsigned long, unsigned long);
};

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)
#define panel_system (*(TPanelSystem*)0x0062E870)
#define confirmed_close (*(int*)0x0086BACC)
#define comm (*(TCommunications_Handler**)0x0062C4C0)

long TRIBE_Screen_Game::action(TPanel* panel, long id,
                               unsigned long p3, unsigned long p4)
{
    TEasy_Panel* tool_box;

    if (panel == 0) {
        goto null_base_action;
    }

    tool_box = this->tool_box;
    if (panel != tool_box && tool_box->active != 0 &&
        tool_box->action(panel, id, p3, p4) != 0) {
        return 1;
    }

        if (id == 1 || id == 4) {
            for (int i = 0; i < 17; ++i) {
                if (panel == this->button_panel[i]) {
                    this->do_button_action(p3, p4, id == 4);
                    return 1;
                }
            }
        }

        if (panel == this->object_panel && id == 1) {
            this->object_changed();
            return 1;
        }

    if (panel->panelName() == 0) {
        goto named_base_action;
    }

    if (strcmp(panel->panelName(), "RestartDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("RestartDialog");
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
        if (id == 0) {
            game->restart_game();
            return 1;
        }
        goto pause_cleanup;
    } else if (strcmp(panel->panelName(), "QuitGameDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("QuitGameDialog");
        if (id == 0) {
            ((TRIBE_Game*)rge_base_game)->do_game_over();
            return 1;
        }
        goto clear_cleanup;
    } else if (strcmp(panel->panelName(), "CloseProgramDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("CloseProgramDialog");
        if (id == 0) {
            rge_base_game->close();
            return 1;
        }
        goto clear_cleanup;
    } else if (strcmp(panel->panelName(), "ResignDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("ResignDialog");
        if (id == 0) {
            this->resign_flag = 1;
            RGE_Player* player = rge_base_game->get_player();
            player->resign(comm->WhoAmI(), id);
            return 1;
        }
        goto pause_cleanup;
    } else if (strcmp(panel->panelName(), "QuitAndLoadDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("QuitAndLoadDialog");
        if (id == 0) {
            new TribeLoadSavedGameScreen();
            panel_system.setCurrentPanel("Load Saved Game Screen", 0);
            return 1;
        }
        goto pause_cleanup;
    } else {
        goto named_base_action;
    }

clear_cleanup:
    confirmed_close = 0;
    if (rge_base_game->singlePlayerGame() == 1 &&
        rge_base_game->save_paused == 0) {
        rge_base_game->set_paused(0, 0);
        return 1;
    }
    goto finish;

pause_cleanup:
    if (rge_base_game->singlePlayerGame() == 1 &&
        rge_base_game->save_paused == 0) {
        rge_base_game->set_paused(0, 0);
    }

finish:

    return 1;

null_base_action:
    return TEasy_Panel::action(panel, id, p3, p4);

named_base_action:
    return TEasy_Panel::action(panel, id, p3, p4);
}
