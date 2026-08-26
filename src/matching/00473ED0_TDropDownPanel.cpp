// VA: 00473ED0 TDropDownPanel::TDropDownPanel
// Pnl_drop.cpp lines 26-38.
// BINARY NOTE: The shipped constructor calls TPanel::TPanel before its own vptr store.
// Exact-finish audit: the reviewed shared context and TPanel constructor
// declaration are required for 86/86 bytes and one matching direct call.
// A local virtual-destructor experiment was rejected because it shifted the
// base and added three bytes. The TTextPanel overload order is incidental here
// but is required by the neighboring Pnl_drop owners.

#ifndef PNL_DROP_CONTEXT
#include "../../include/pnl_drop_context.h"
#endif

TDropDownPanel::TDropDownPanel() : TPanel() {
    // Zero out TDropDownPanel-specific fields
    this->val_panel = 0;
    this->btn_panel = 0;
    this->list_panel = 0;
    this->scbar_panel = 0;
    this->mode = 0;
    this->val_num = 0;
    this->list_is_above = 0;
    this->draw_style = 0;
    
    // TPanel field that gets set to 6
    this->panel_type = 6;
    
    this->draw_val_rect = 1;
}
