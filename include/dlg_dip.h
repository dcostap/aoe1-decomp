#ifndef AOE1_DLG_DIP_H
#define AOE1_DLG_DIP_H

// PDB source module: C:\\msdev\\work\\age1_x1\\dlg_dip.cpp.
// TribeDiplomacyDialog is the only class owned by this header. Shared dialog,
// panel, screen, control, drawing, shape, base-game, player, and world types
// come from their canonical owners.
#include "pnl_dlg.h"
#include "Pnl_scr.h"
#include "Pnl_txt.h"
#include "pnl_btn.h"
#include "panel.h"
#include "drawarea.h"
#include "Shape.h"
#include "color.h"
#include "basegame.h"
#include "player.h"
#include "tplayer.h"
#include "tech.h"
#include "world.h"
#include "obj_list.h"
#include "rge_base_game_global.h"

class TribeDiplomacyDialog : public TDialogPanel {
public:
    virtual ~TribeDiplomacyDialog();

protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);

public:
    TTextPanel* title[8];
    TTextPanel* playerName[8];
    TTextPanel* playerVictoryScores[8];
    TTextPanel* playerCivilization[8];
    TTextPanel* needMarket;
    TButtonPanel* goldTributeButton[8];
    TButtonPanel* woodTributeButton[8];
    TButtonPanel* foodTributeButton[8];
    TButtonPanel* stoneTributeButton[8];
    TButtonPanel* allyButton[24];
    TButtonPanel* allianceButton;
    TButtonPanel* okButton;
    TButtonPanel* clearButton;
    TButtonPanel* cancelButton;
    TButtonPanel* help_button;
    TShape* buttonPics;
    TShape* backgroundPics;
    float foodTotal;
    float woodTotal;
    float goldTotal;
    float stoneTotal;
    TTextPanel* playerFood;
    TTextPanel* playerGold;
    TTextPanel* playerWood;
    TTextPanel* playerStone;
    float goldTributeAmount[8];
    float foodTributeAmount[8];
    float stoneTributeAmount[8];
    float woodTributeAmount[8];
    int cur_player_row;
    int tribute_flag;

    TribeDiplomacyDialog(TScreenPanel*);

protected:
    int check_gold();
    int check_wood();
    int check_food();
    int check_stone();
    virtual void draw();
};

typedef char dlg_dip_dialog_size_check[
    (sizeof(TribeDiplomacyDialog) == 0x6B8) ? 1 : -1];

#endif
