#include "../include/TDropDownButtonPanel.h"
#include "../include/TDropDownPanel.h"
#include "../include/TListPanel.h"
#include "../include/TScrollBarPanel.h"

// Constructor - from decomp at 0x00475470
TDropDownButtonPanel::TDropDownButtonPanel(TDropDownPanel* drop_down) : TButtonPanel() {
    this->drop_down_panel = drop_down;
}

// Destructor
TDropDownButtonPanel::~TDropDownButtonPanel() {
}

// handle_mouse_move - from decomp at 0x004754C0
// Forwards mouse capture from the button to list/scbar while dropdown is open.
// Source of truth: src/game/src/Pnl_drop.cpp.decomp/.asm (immutable references).
long TDropDownButtonPanel::handle_mouse_move(long x, long y, int wparam, int param_4) {
    // ASM checks button mouse-capture state first (offset 0x68 in TPanel).
    // This prevents forwarding unless the dropdown button currently owns the drag.
    if (this->mouse_captured != 0 && this->drop_down_panel) {
        TListPanel* list = this->drop_down_panel->list_panel;
        TScrollBarPanel* scbar = this->drop_down_panel->scbar_panel;

        if (list && list->is_inside(x, y)) {
            // Release button press and transfer interaction to the list.
            // Source-of-truth (Pnl_drop.cpp.asm @ 0x004754F3):
            // synthetic mouse-up forwards original trailing mouse args (param_3/param_4).
            this->handle_mouse_up(1, x, y, wparam, param_4);
            return list->handle_mouse_down(1, x, y, wparam, param_4);
        }

        if (list && scbar && scbar->is_inside(x, y)) {
            // Same handoff for scrollbar hit: synthetic down at list's right edge.
            this->handle_mouse_up(1, x, y, wparam, param_4);
            const long list_right_x = list->xPosition() + list->width() - 1;
            return list->handle_mouse_down(1, list_right_x, y, wparam, param_4);
        }
    }

    return TButtonPanel::handle_mouse_move(x, y, wparam, param_4);
}
