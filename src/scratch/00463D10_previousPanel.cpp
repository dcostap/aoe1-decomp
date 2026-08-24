// previousPanel (00463D10, 15 bytes, Panel.cpp)
// if (currentPanel) return TPanel::previousPanel(currentPanel); return 0;
#include "../../include/game_globals.h"
#include "../../include/game_types.h"
#ifndef AOE1_PANEL_CONTEXT_H

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    void* vtable;
    TPanel* previous_panel;
    TPanel* previousPanel();
};
#endif

#ifndef AOE1_PANEL_CONTEXT_H
class TPanelSystem {
public:
    unsigned char _pad[0xC];
    TPanel* currentPanelValue;  // +0xC
};
#endif

#endif
TPanel* TPanelSystem::previousPanel() {
    if (currentPanelValue)
        return currentPanelValue->previousPanel();
    return 0;
}
