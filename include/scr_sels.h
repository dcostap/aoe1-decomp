#ifndef AOE1_SCR_SELS_H
#define AOE1_SCR_SELS_H

// PDB source module: C:\\msdev\\work\\age1_x1\\Scr_sels.cpp.
// TribeSelectScenarioScreen is the only class owned by this header. Its
// complete screen base comes from the canonical screen owner.
#include "Pnl_scr.h"

class TPanel;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;

class TribeSelectScenarioScreen : public TScreenPanel {
public:
    TTextPanel* title;
    TTextPanel* scenarioTitle;
    TTextPanel* scenarioPlayersTitle;
    long scenarioListX;
    long scenarioListY;
    long scenarioListWidth;
    long scenarioListHeight;
    TListPanel* scenarioList;
    TScrollBarPanel* scenarioScrollbar;
    int scenarioCount;
    char** scenarioMission;
    int* scenarioFixed;
    int scenariosLoaded;
    TTextPanel* missionTitle;
    long missionTextX;
    long missionTextY;
    long missionTextWidth;
    long missionTextHeight;
    TTextPanel* missionText;
    TScrollBarPanel* missionScrollbar;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* close_button;
    int last_scenario_line;

    TribeSelectScenarioScreen();
    virtual ~TribeSelectScenarioScreen();
    virtual long handle_idle();

protected:
    virtual long action(TPanel* panel, long event, unsigned long p3,
                        unsigned long p4);
    void init_vars();
    void fillScenarios();
    void getSettings();
    void fillMissionText();
    void sendSettings();
    void activatePanels();
};

typedef char scr_sels_screen_size_check[
    (sizeof(TribeSelectScenarioScreen) == 0x4D8) ? 1 : -1];

#endif
