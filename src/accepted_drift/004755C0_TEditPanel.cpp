// VA: 004755C0 TEditPanel ctor (170B)
// pnl_edit.cpp lines 50-75
// The unlisted members remain in their base-allocated state.
// Exact-finish: the full pnl_edit context supplies the proven base and member
// layout.  The final turn_ime_on write is required for the shipped VC5 order.
// Removing it changes the body to 164 bytes.  A raw vptr store is not needed.

#include "../../include/pnl_edit_context.h"

TEditPanel::TEditPanel() : TPanel()
{
    edit_wnd = 0;
    text = 0;
    fixed_len = 0;
    brush = 0;
    old_sub_wnd_proc = 0;
    text_color1 = 0;
    text_color2 = 0;
    highlight_text_color1 = 0;
    highlight_text_color2 = 0;
    back_color = 0;
    sel_len = 0;
    bevel_color1 = 0;
    bevel_color2 = 0;
    bevel_color3 = 0;
    bevel_color4 = 0;
    bevel_color5 = 0;
    bevel_color6 = 0;
    bevel_size = 0;
    imc = 0;
    enable_ime = 0;
    handle_mouse_input = 1;
    hidden = 1;
    bevel_type = 1;
    // BINARY NOTE: Keep this explicit final zero write.  VC5 places it before
    // the derived vptr store and preserves the three one-valued tail stores.
    turn_ime_on = 0;
}
