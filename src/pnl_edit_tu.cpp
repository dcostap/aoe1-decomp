// Authentic pnl_edit.cpp owner wrapper in PDB source order.
//
// The source module begins with pnl_sub_wnd_proc at lines 37-43, then the
// TEditPanel constructor and the remaining owners.  The nearby vector deleting
// destructor is compiler-generated and is checked separately.
//
// This proposal uses the reviewed pnl_edit class and DrawArea surfaces, plus a
// local ABI context for owners that still carry standalone declarations.  It
// does not change the registered pnl_edit_prefix wrapper or global config.
// Flags: /nologo /c /O2 /Oy /GX.

#define PNL_EDIT_TU_CONTEXT 1
#define PNL_EDIT_CONTEXT_H 1
#include "pnl_edit_tu_context.h"

#include "matching/00475930_pnl_sub_wnd_proc.cpp"
#include "matching/004755C0_TEditPanel.cpp"
#include "matching/00475690_TEditPanel.cpp"
#include "scratch/00475770_setup.cpp"
#include "matching/00475970_set_text.cpp"
#include "matching/00475A30_update_text.cpp"
#include "matching/00475AF0_get_text.cpp"
#include "matching/00475B00_get_input_buffer.cpp"
#include "matching/00475B10_currentLine.cpp"
#include "matching/00475B20_set_active.cpp"
#include "matching/00475B60_set_focus.cpp"
#include "matching/00475CC0_set_rect.cpp"
#include "matching/00475DD0_set_redraw.cpp"
#include "matching/00475E10_set_text_color.cpp"
#include "matching/00475E30_set_highlight_text_color.cpp"
#include "matching/00475E40_set_back_color.cpp"
#include "accepted_drift/00475E50_set_bevel_info.cpp"
#include "matching/00475F20_set_ime_info.cpp"
#include "matching/00475F40_wnd_proc.cpp"
#include "scratch/00476040_sub_wnd_proc.cpp"
#include "matching/00476440_verify_char.cpp"
#include "accepted_drift/00476680_draw.cpp"
#include "matching/00476A50_paint.cpp"
#include "matching/00476A60_is_blank.cpp"
#include "matching/00476AB0_get_trimmed_str.cpp"
#include "matching/00476BB0_handle_reactivate.cpp"
#include "matching/00476BE0_handle_mouse_down.cpp"

#undef PNL_EDIT_CONTEXT_H
#undef PNL_EDIT_TU_CONTEXT
