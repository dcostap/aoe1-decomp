#ifndef AOE1_DLG_DIP_H
#define AOE1_DLG_DIP_H

// PDB owner: dlg_dip.cpp.
// BLOCKER: dlg_dip.cpp needs canonical call and field normalization.

#include "pnl_dlg.h"
#include "pnl_btn.h"
#include "pnl_lst.h"
#include "Shape.h"
#include "basegame.h"
#include "player.h"
#include "tplayer.h"
#include "world.h"
#include "tworld.h"
#include "tcommand.h"
#include "com_hand.h"
#include "color.h"

class TScreenPanel;

class TribeDiplomacyDialog : public TDialogPanel {
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
    virtual ~TribeDiplomacyDialog();

protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    int check_gold();
    int check_wood();
    int check_food();
    int check_stone();
    virtual void draw();
};

typedef char dlg_dip_dialog_size_check[
    (sizeof(TribeDiplomacyDialog) == 0x6B8) ? 1 : -1];

#endif
