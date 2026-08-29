#ifndef AOE1_SCR_SAVE_H
#define AOE1_SCR_SAVE_H

// TribeSaveGameScreen is the only class owned by this header. It owns all five
// control, drawing, shape, picture, and game-owner surfaces come from their
// canonical owners.
#include "pnl_dlg.h"
#include "panel_ez.h"
#include "Pnl_scr.h"
#include "panel.h"
#include "basegame.h"
#include "drawarea.h"
#include "Shape.h"
#include "Picture.h"
#include "pnl_btn.h"
#include "Pnl_txt.h"
#include "pnl_lst.h"
#include "Pnl_inp.h"
#include "pnl_edit.h"
#include "Pnl_scbr.h"
#include "pnl_drop.h"
#include "pnl_sld.h"
#include "main.h"
#include "world.h"
#include "scenario.h"
#include "tribegam.h"
#include "rge_base_game_global.h"

class TRIBE_Screen_Sed_Open;

class TribeSaveGameScreen : public TScreenPanel {
public:
    enum Mode {
        SaveGame = 0,
        SaveScenario = 1,
        SaveScenarioEdit = 2
    };

    TribeSaveGameScreen(Mode mode, char* name, int quit_after_save);
    virtual ~TribeSaveGameScreen();

protected:
    TTextPanel* title;
    TEditPanel* input;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* deleteButton;
    char fileName[260];
    char fileNameNoExt[260];
    Mode modeValue;
    int quit_after_save;

    void fillList();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void save_for_scenario_editor();
};

typedef char scr_save_screen_size_check[
    (sizeof(TribeSaveGameScreen) == 0x6A4) ? 1 : -1];

#endif
