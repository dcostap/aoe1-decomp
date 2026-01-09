#pragma once
#include "common.h"

class TribeDiplomacyDialog : public TDialogPanel {
public:
    TTextPanel* title[8];                    // 0x490
    TTextPanel* playerName[8];               // 0x4B0
    TTextPanel* playerVictoryScores[8];      // 0x4D0
    TTextPanel* playerCivilization[8];       // 0x4F0
    TTextPanel* needMarket;                  // 0x510
    TButtonPanel* goldTributeButton[8];      // 0x514
    TButtonPanel* woodTributeButton[8];      // 0x534
    TButtonPanel* foodTributeButton[8];      // 0x554
    TButtonPanel* stoneTributeButton[8];     // 0x574
    TButtonPanel* allyButton[24];            // 0x594
    TButtonPanel* allianceButton;            // 0x5F4
    TButtonPanel* okButton;                  // 0x5F8
    TButtonPanel* clearButton;               // 0x5FC
    TButtonPanel* cancelButton;              // 0x600
    TButtonPanel* help_button;               // 0x604
    TShape* buttonPics;                      // 0x608
    TShape* backgroundPics;                  // 0x60C
    float foodTotal;                         // 0x610
    float woodTotal;                         // 0x614
    float goldTotal;                         // 0x618
    float stoneTotal;                        // 0x61C
    TTextPanel* playerFood;                  // 0x620
    TTextPanel* playerGold;                  // 0x624
    TTextPanel* playerWood;                  // 0x628
    TTextPanel* playerStone;                 // 0x62C
    float goldTributeAmount[8];              // 0x630
    float foodTributeAmount[8];              // 0x650
    float stoneTributeAmount[8];             // 0x670
    float woodTributeAmount[8];              // 0x690
    int cur_player_row;                      // 0x6B0
    int tribute_flag;                        // 0x6B4

    virtual void draw();                                    // vt0[12]+0x30=0x43E770
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x43D8A0
    TribeDiplomacyDialog(TScreenPanel* param_1);
    ~TribeDiplomacyDialog();
    int check_gold();
    int check_wood();
    int check_food();
    int check_stone();
};

static_assert(sizeof(TribeDiplomacyDialog) == 0x6B8, "TribeDiplomacyDialog Size Mismatch");

