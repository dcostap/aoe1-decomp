// PDB source-line order for the recovered pnl_edit.cpp context.
//
// 00475930 has source lines 37-43 but a VA after the line-50 constructor.
// Keep this order. The current constructor and setup owners stay outside this
// safe prefix until their natural shared-surface sources are exact.
//
// After the nine exact prefix owners, verify_char is the tenth exact anchor.
// The later draw and window owners use the same canonical panel header.
// Audit result: the expanded /O2 /Oy /GX wrapper preserves all nine prefix
// MATCH results and later paint, is_blank, get_trimmed_str,
// handle_reactivate, and handle_mouse_down MATCH results. draw remains
// accepted drift with its proven 30-byte VC5 save-schedule difference.
#include "matching/00475930_pnl_sub_wnd_proc.cpp"
#include "matching/00475690_TEditPanel.cpp"
#include "matching/00475970_set_text.cpp"
#include "matching/00475A30_update_text.cpp"
#include "matching/00475AF0_get_text.cpp"
#include "matching/00475B00_get_input_buffer.cpp"
#include "matching/00475B10_currentLine.cpp"
#include "matching/00475B20_set_active.cpp"
#include "matching/00475B60_set_focus.cpp"
#include "matching/00475F40_wnd_proc.cpp"
#include "matching/00476440_verify_char.cpp"
#include "accepted_drift/00476680_draw.cpp"
#include "matching/00476A50_paint.cpp"
#include "matching/00476A60_is_blank.cpp"
#include "matching/00476AB0_get_trimmed_str.cpp"
#include "matching/00476BB0_handle_reactivate.cpp"
#include "matching/00476BE0_handle_mouse_down.cpp"
