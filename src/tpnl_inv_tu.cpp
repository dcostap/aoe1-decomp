// Authentic PDB module: C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp.
// Owners follow source-line order, not numeric VA order.  Generated scalar
// deleting destructors and padding are not source owners.
//
// Context evidence:
// - TRIBE_Panel_Inven owns 0051A5C0, 0051A6D0, 0051A770, 0051AAD0,
//   0051ABF0, 0051AC10, and 0051ACA0 in this module.
// - 0051ACA0 is tpnl_inv.cpp:236-265 with qualified symbol
//   ?get_help_info@TRIBE_Panel_Inven@@UAEEAAPADAAJJJ@Z.
// - Its exact anchors are 0051ACA0, 0051ACC0 virtual slot +0xBC,
//   0054B700 __ftol, 00466870 TPanel::get_string, and 0054BBC0 sprintf.
// - The four resource arms are source lines 245, 250, 255, and 260.
//
// The canonical inventory panel/game declarations are in
// tpnl_inv_context.h.  One module flag set is required for this grouped
// context: /nologo /c /O2 /Oy /GX.  The /GX evidence is the exact destructor
// owner at 0051A6D0.  The existing tpnl_inv_prefix registration is preserved;
// this assignment does not modify config/translation_units.json.
//
// Safe exact manifest under that one flag set.  Each symbol was selected from
// the wrapper COFF object and its body was compared with the original range.
// Relocation fields are masked only for the byte comparison.
//
//   VA       owner symbol
//   0051A5C0 ??0TRIBE_Panel_Inven@@QAE@PAVTDrawArea@@PAVTPanel@@PAXPAVTRIBE_Player@@@Z
//   0051A6B0 ?set_text_color@TRIBE_Panel_Inven@@QAEXKK@Z
//   0051A6D0 ??1TRIBE_Panel_Inven@@UAE@XZ
//   0051A770 ?draw@TRIBE_Panel_Inven@@UAEXXZ
//   0051AAD0 ?handle_idle@TRIBE_Panel_Inven@@UAEJXZ
//   0051ABF0 ?set_player@TRIBE_Panel_Inven@@QAEXPAVTRIBE_Player@@@Z
//   0051AC10 PDB owner ?save_info@TRIBE_Panel_Inven@@IAEXXZ
//   0051ACA0 ?get_help_info@TRIBE_Panel_Inven@@UAEEAAPADAAJJJ@Z
//
// The grouped check produced 201, 30, 148, 859, 277, 31, 143, and 326 bytes
// respectively.  0051ACA0 has the original 13-call sequence.  Generated
// scalar/vector deleting destructors and padding remain excluded.
//
// BINARY NOTE: The PDB owner is protected
// (?save_info@TRIBE_Panel_Inven@@IAEXXZ).  The reviewed shared context
// preserves that access.  No alias or assembly workaround is used.

#include <windows.h>
#include "../include/tpnl_inv_context.h"

#define TPNL_INV_SHARED_CONTEXT 1

// tpnl_inv.cpp:33-61
#include "matching/0051A5C0_TRIBE_Panel_Inven.cpp"

// tpnl_inv.cpp:67-71
#include "matching/0051A6B0_set_text_color.cpp"

// tpnl_inv.cpp:77-91
#include "matching/0051A6D0_TRIBE_Panel_Inven.cpp"

// tpnl_inv.cpp:97-158
#include "matching/0051A770_draw.cpp"

// tpnl_inv.cpp:164-198
#include "matching/0051AAD0_handle_idle.cpp"

// tpnl_inv.cpp:204-208
#include "matching/0051ABF0_set_player.cpp"

// tpnl_inv.cpp:214-230
#include "matching/0051AC10_save_info.cpp"

// tpnl_inv.cpp:236-265
#include "matching/0051ACA0_get_help_info.cpp"

#undef TPNL_INV_SHARED_CONTEXT
