#pragma once
#include "common.h"
#include "TButtonPanel.h"

class TDropDownPanel;

// TDropDownButtonPanel inherits TButtonPanel and only overrides handle_mouse_move
// to forward mouse events to the dropdown's list/scrollbar when open.
// All other virtuals are inherited from TButtonPanel unchanged.
class TDropDownButtonPanel : public TButtonPanel {
public:
    TDropDownButtonPanel(TDropDownPanel* drop_down);
    virtual ~TDropDownButtonPanel();

    // Only override: forwards mouse to list/scbar when dropdown is open
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4) override;

    TDropDownPanel* drop_down_panel;
};
static_assert(sizeof(TDropDownButtonPanel) == 0x2BC, "Size mismatch");
