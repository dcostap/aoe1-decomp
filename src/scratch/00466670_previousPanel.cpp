// previousPanel (00466670, 4 bytes, Panel.cpp)
// returns this->previous_panel
#include "../../include/game_globals.h"
#include "../../include/game_types.h"

// Context gate: Panel.cpp lines 2363-2365, TPanel owner. The exact anchor is
// one load from this +0x04 followed by return.
// The const owner matches ?previousPanel@TPanel@@QBEPAV1@XZ.

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    void* vtable;
    TPanel* previous_panel;
    TPanel* previousPanel() const;
};

#endif
TPanel* TPanel::previousPanel() const {
    return previous_panel;
}
