// previousPanel (00466670, 4 bytes, Panel.cpp)
// returns this->previous_panel
#include "game_globals.h"
#include "game_types.h"

class TPanel {
public:
    void* vtable;
    TPanel* previous_panel;
};

TPanel* TPanel::previousPanel() {
    return previous_panel;
}
