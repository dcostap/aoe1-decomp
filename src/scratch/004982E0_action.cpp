// 004982E0 TRIBE_Screen_Game::action
// Attempt log:
// initial natural reconstruction from asm: dialog-name chain, pause/resign/load actions, /GX EH; not yet exact.
// check: 1211 bytes, 78.03% positional diff, first mismatch at offset 38: early null-panel branch +2 bytes due tail/default handler layout; broad later drift.
// leave in scratch: behavior skeleton is useful, but exact needs real helper at 004987A0 and tighter inherited TPanel/TRIBE_Screen_Game vtable/layout source; current source is not accepted_drift quality.

#include <string.h>
#include <new.h>

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)
#define panel_system (*(TPanelSystem*)0x0062E870)
#define confirmed_close (*(int*)0x0086BACC)
#define comm (*(TCommunications_Handler**)0x0062C4C0)

class TPanel {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    char* panelName();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

class RGE_Player {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void resign(int who, long id);
};

class RGE_Base_Game {
public:
    char gap_00[0xA00];
    int save_paused;
    void close();
    void set_paused(int a, int b);
    int singlePlayerGame();
    RGE_Player* get_player(long id);
};

class TCommunications_Handler { public: int WhoAmI(); };
class TribeLoadSavedGameScreen { public: char pad[0x494]; TribeLoadSavedGameScreen(); };

class TRIBE_Screen_Game : public TPanel {
public:
    char gap_04[0x4C0];
    TPanel* button_cancel;        // +4C4
    TPanel* proper_buttons[17];   // +4C8
    char gap_50C[0x70];
    TPanel* current_panel;        // +57C
    char gap_580[0x1B0];
    int resign_flag;              // +730

    void object_changed();
    void restart_game();
    void do_game_over();
    long action(TPanel*, long, unsigned long, unsigned long);
};

long TRIBE_Screen_Game::action(TPanel* panel, long id, unsigned long p3, unsigned long p4)
{
    if (panel == 0) {
        return TPanel::action(panel, id, p3, p4);
    }

    if (panel != this->current_panel && *(int*)((char*)this->current_panel + 0x6c) != 0) {
        if (this->current_panel->action(panel, id, p3, p4)) {
            return 1;
        }
    }

    if (id == 1 || id == 4) {
        for (int i = 0; i < 17; ++i) {
            if (panel == this->proper_buttons[i]) {
                return this->action((TPanel*)0, p3, p4, id == 4 ? 1 : 0); // placeholder for helper at 004987A0 is next function
            }
        }
    }

    if (panel == this->button_cancel && id == 1) {
        this->object_changed();
        return id;
    }

    if (panel->panelName() == 0) {
        return TPanel::action(panel, id, p3, p4);
    }

    if (strcmp(panel->panelName(), (char*)0x584370) == 0) {
        panel_system.setCurrentPanel((char*)0x5842CC, 0);
        panel_system.destroyPanel((char*)0x584370);
        if (id == 0) this->restart_game();
        else if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) rge_base_game->set_paused(0, 0);
        return 1;
    }

    if (strcmp(panel->panelName(), (char*)0x584394) == 0) {
        panel_system.setCurrentPanel((char*)0x5842CC, 0);
        panel_system.destroyPanel((char*)0x584394);
        if (id == 0) rge_base_game->close();
        else {
            confirmed_close = 0;
            if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) rge_base_game->set_paused(0, 0);
        }
        return 1;
    }

    if (strcmp(panel->panelName(), (char*)0x5863B4) == 0) {
        panel_system.setCurrentPanel((char*)0x5842CC, 0);
        panel_system.destroyPanel((char*)0x5863B4);
        if (id == 0) rge_base_game->close();
        else {
            confirmed_close = 0;
            if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) rge_base_game->set_paused(0, 0);
        }
        return 1;
    }

    if (strcmp(panel->panelName(), (char*)0x584350) == 0) {
        panel_system.setCurrentPanel((char*)0x5842CC, 0);
        panel_system.destroyPanel((char*)0x584350);
        if (id == 0) {
            this->resign_flag = 1;
            RGE_Player* p = rge_base_game->get_player(id);
            p->resign(comm->WhoAmI(), id);
        } else if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) rge_base_game->set_paused(0, 0);
        return 1;
    }

    if (strcmp(panel->panelName(), (char*)0x5843A4) == 0) {
        panel_system.setCurrentPanel((char*)0x5842CC, 0);
        panel_system.destroyPanel((char*)0x5843A4);
        if (id == 0) {
            TribeLoadSavedGameScreen* s = new TribeLoadSavedGameScreen();
            panel_system.setCurrentPanel((char*)0x586464, 0);
        } else if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) rge_base_game->set_paused(0, 0);
        return 1;
    }

    return TPanel::action(panel, id, p3, p4);
}
