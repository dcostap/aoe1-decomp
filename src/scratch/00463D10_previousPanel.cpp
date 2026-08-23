// previousPanel (00463D10, 15 bytes, Panel.cpp)
// if (currentPanel) return TPanel::previousPanel(currentPanel); return 0;
#include "game_globals.h"
#include "game_types.h"

class TPanel {
public:
    void* vtable;
    TPanel* previous_panel;
    TPanel* previousPanel();
};

class TPanelSystem {
public:
    unsigned char _pad[0xC];
    TPanel* currentPanelValue;  // +0xC
};

TPanel* TPanelSystem::previousPanel() {
    if (currentPanelValue)
        return TPanel::previousPanel(currentPanelValue);
    return 0;
}
