#ifndef AOE1_SCR_CAMS_H
#define AOE1_SCR_CAMS_H

// This header owns only the campaign-selection screen. Shared panel and
// screen types come from their canonical owners.
#include "Pnl_scr.h"

class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TDropDownPanel;
class TButtonPanel;

class TRIBE_Screen_Campaign_Selection : public TScreenPanel {
public:
    TTextPanel* title;
    int campaignListX;
    int campaignListY;
    int campaignListWidth;
    int campaignListHeight;
    TTextPanel* campaignTitle;
    TListPanel* campaignList;
    TScrollBarPanel* campaignScrollbar;
    int scenarioListX;
    int scenarioListY;
    int scenarioListWidth;
    int scenarioListHeight;
    TTextPanel* scenarioTitle;
    TListPanel* scenarioList;
    TScrollBarPanel* scenarioScrollbar;
    TTextPanel* difficultyTitle;
    TDropDownPanel* difficultyDrop;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* close_button;
    int campaignsLoaded;

    TRIBE_Screen_Campaign_Selection();
    virtual ~TRIBE_Screen_Campaign_Selection();
    virtual long handle_idle();

protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void init_vars();
    void fillCampaigns();
    void fillScenarios();
    void startGame();
};

typedef char scr_cams_screen_size_check[
    (sizeof(TRIBE_Screen_Campaign_Selection) == 0x4CC) ? 1 : -1];

#endif
