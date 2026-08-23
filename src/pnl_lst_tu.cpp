// Authentic Pnl_lst.cpp owner wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp
// PDB owner order is source-line order. The owner sequence below follows
// inventory/pdb/function_source_map.csv and the original address range.
//
// The canonical list-panel surface is in include/pnl_lst_context.h. It keeps
// TTextPanel::list and the short selection fields aliased to their proven
// inherited storage. It also keeps the TListPanel state at +0x188..+0x19C.
// This is important for item_at, character selection, focus callbacks, and
// draw highlighting. Do not replace these fields with a second selection list.
//
// PDB-qualified source owners, in order:
//   ??0TListPanel@@QAE@XZ             004782A0  Pnl_lst.cpp:26-41
//   ??1TListPanel@@UAE@XZ             00478330  Pnl_lst.cpp:47
//   ?set_auto_track@TListPanel@@QAEXH@Z
//                                      00478340  Pnl_lst.cpp:55-57
//   ?set_bevel_info@TListPanel@@UAEXHHHHHHH@Z
//                                      00478350  Pnl_lst.cpp:63-94
//   ?handle_idle@TListPanel@@UAEJXZ   004783F0  Pnl_lst.cpp:100-128
//   ?mouse_move_action@TListPanel@@UAEJJJHH@Z
//                                      004784A0  Pnl_lst.cpp:134-148
//   ?mouse_left_down_action@TListPanel@@UAEJJJHH@Z
//                                      00478510  Pnl_lst.cpp:154-158
//   ?mouse_left_move_action@TListPanel@@UAEJJJHH@Z
//                                      00478540  Pnl_lst.cpp:164-196
//   ?mouse_left_up_action@TListPanel@@UAEJJJHH@Z
//                                      00478610  Pnl_lst.cpp:202-210
//   ?mouse_left_dbl_click_action@TListPanel@@UAEJJJHH@Z
//                                      00478660  Pnl_lst.cpp:216-221
//   ?item_at@TListPanel@@QAEFJJ@Z      004786B0  Pnl_lst.cpp:227-237
//   ?goto_item@TListPanel@@QAEXJJ@Z    00478700  Pnl_lst.cpp:243-245
//   ?key_down_action@TListPanel@@UAEJJFHHH@Z
//                                      00478730  Pnl_lst.cpp:251-285
//   ?char_action@TListPanel@@UAEJJF@Z  00478850  Pnl_lst.cpp:291-332
//   ?action@TListPanel@@UAEJPAVTPanel@@JKK@Z
//                                      00478900  Pnl_lst.cpp:338-367
//   ?scroll_cur_line@TListPanel@@QAEXEFH@Z
//                                      00478920  Pnl_lst.cpp:373-463
//   ?draw@TListPanel@@UAEXXZ           00478BA0  Pnl_lst.cpp:468-509
//   ?draw_highlight_bar@TListPanel@@QAEXXZ
//                                      00478CD0  Pnl_lst.cpp:515-572
//   ?setDrawHighlightBar@TListPanel@@QAEXH@Z
//                                      00478EE0  Pnl_lst.cpp:577-579
//   ?set_focus@TListPanel@@UAEXH@Z     00478EF0  Pnl_lst.cpp:585-593
//
// The scalar deleting destructor at 00478310 is generated code, not a source
// owner. No padding, assembly, or parent-owned fragment is included. This
// wrapper is context scaffolding only and is intentionally not registered in
// config/translation_units.json.
// All 20 normal PDB owners above have fresh per-owner MATCH results. The
// generated scalar destructor remains excluded from this source-owner map.
// The reviewed module flag set is config/flags/default.rsp:
// /nologo /c /O2 /Oy.

#include "../include/pnl_lst_context.h"

#include "matching/004782A0_TListPanel.cpp"
#include "matching/00478330_TListPanel.cpp"
#include "matching/00478340_set_auto_track.cpp"
#include "matching/00478350_set_bevel_info.cpp"
#include "matching/004783F0_handle_idle.cpp"
#include "matching/004784A0_mouse_move_action.cpp"
#include "matching/00478510_mouse_left_down_action.cpp"
#include "matching/00478540_mouse_left_move_action.cpp"
#include "matching/00478610_mouse_left_up_action.cpp"
#include "matching/00478660_mouse_left_dbl_click_action.cpp"
#include "matching/004786B0_item_at.cpp"
#include "matching/00478700_goto_item.cpp"
#include "matching/00478730_key_down_action.cpp"
#include "matching/00478850_char_action.cpp"
#include "matching/00478900_action.cpp"
#include "matching/00478920_scroll_cur_line.cpp"
#include "matching/00478BA0_draw.cpp"
#include "matching/00478CD0_draw_highlight_bar.cpp"
#include "matching/00478EE0_setDrawHighlightBar.cpp"
#include "matching/00478EF0_set_focus.cpp"
