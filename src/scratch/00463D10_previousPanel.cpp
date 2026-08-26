// previousPanel (00463D10, 15 bytes, Panel.cpp)
// if (currentPanel) return TPanel::previousPanel(currentPanel); return 0;
#include "../../include/game_globals.h"
#include "../../include/game_types.h"
#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    void* vtable;
    TPanel* previous_panel;
    TPanel* previousPanel() const;
};
#endif

#ifndef AOE1_PANEL_CONTEXT_H
class TPanelSystem {
public:
    unsigned char _pad[0xC];
    TPanel* currentPanelValue;  // +0xC
    TPanel* previousPanel() const;
};
#endif

// Context gate: Panel.cpp lines 115-119, TPanelSystem owner. The source-line
// order is load currentPanel at +0x0C, test it, then tail-call TPanel::previousPanel.
// BINARY NOTE: the PDB owner record proves the const symbol
// ?previousPanel@TPanelSystem@@QBEPAVTPanel@@XZ.
TPanel* TPanelSystem::previousPanel() const {
    if (currentPanelValue)
        return currentPanelValue->previousPanel();
    return 0;
}
