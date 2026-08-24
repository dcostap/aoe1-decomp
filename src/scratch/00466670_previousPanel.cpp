// previousPanel (00466670, 4 bytes, Panel.cpp)
// returns this->previous_panel
#include "../../include/game_globals.h"
#include "../../include/game_types.h"

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    void* vtable;
    TPanel* previous_panel;
};

#endif
TPanel* TPanel::previousPanel() {
    return previous_panel;
}
