#pragma once
#include "common.h"

class TRIBE_Screen_Campaign_Selection : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    long campaignListX;                      // 0x47C
    long campaignListY;                      // 0x480
    long campaignListWidth;                  // 0x484
    long campaignListHeight;                 // 0x488
    TTextPanel* campaignTitle;               // 0x48C
    TListPanel* campaignList;                // 0x490
    TScrollBarPanel* campaignScrollbar;      // 0x494
    long scenarioListX;                      // 0x498
    long scenarioListY;                      // 0x49C
    long scenarioListWidth;                  // 0x4A0
    long scenarioListHeight;                 // 0x4A4
    TTextPanel* scenarioTitle;               // 0x4A8
    TListPanel* scenarioList;                // 0x4AC
    TScrollBarPanel* scenarioScrollbar;      // 0x4B0
    TTextPanel* difficultyTitle;             // 0x4B4
    TDropDownPanel* difficultyDrop;          // 0x4B8
    TButtonPanel* okButton;                  // 0x4BC
    TButtonPanel* cancelButton;              // 0x4C0
    TButtonPanel* close_button;              // 0x4C4
    int campaignsLoaded;                     // 0x4C8

    virtual long handle_idle();                             // vt0[19]+0x4C=0x490F90
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x490FF0
    TRIBE_Screen_Campaign_Selection();
    void init_vars();
    ~TRIBE_Screen_Campaign_Selection();
    void fillCampaigns();
    void fillScenarios();
    void startGame();
};

static_assert(sizeof(TRIBE_Screen_Campaign_Selection) == 0x4CC, "TRIBE_Screen_Campaign_Selection Size Mismatch");

