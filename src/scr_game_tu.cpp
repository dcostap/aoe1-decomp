// Canonical scr_game.cpp context slice for the active recovery owners.
//
// PDB source-line order is retained.  The four reviewed padding-only symbols
// in this address band are not owners and are not included.
//
// The 00493D60 constructor remains a standalone owner. Its local ABI surface
// conflicts with the shared scr_game_context used by this grouped prefix.
// Safe grouped owner proposal for this recovery set:
//   004954A0 [878-1151]     ??1TRIBE_Screen_Game@@UAE@XZ
//   00496800 [1589-1996]    ?handle_game_update@TRIBE_Screen_Game@@QAEXXZ
//   00497440 [2163-2820]    ?key_down_action@TRIBE_Screen_Game@@UAEJJFHHH@Z
//   004982E0 [2847-2962]    ?action@TRIBE_Screen_Game@@UAEJPAVTPanel@@JKK@Z
//   004996C0 [3395-4017]    ?setup_buttons@TRIBE_Screen_Game@@QAEXXZ
//   0049B000 [4282-4307]    ?scr_game_score_compare@@YAHPBX0@Z
//   0049B080 [4310-4486]    ?reset_score_display@TRIBE_Screen_Game@@QAEXXZ
//   0049B560 [4492-4575]    ?draw@TRIBE_Screen_Game@@UAEXXZ
//   0049B830 [4581-4615]    ?handle_anim_pal@TRIBE_Screen_Game@@QAEXXZ
// Use config/flags/004982E0_action.rsp for this set.  It is the one /GX set.
// Stop before 0049B910. Its accepted-drift owner differs by seven bytes.
// Do not add later owners until the 0049B910 boundary is resolved.
#include "matching/004954A0_TRIBE_Screen_Game.cpp"
#include "scratch/00496800_handle_game_update.cpp"
// 00497440 is exact in isolation. Its local class surface conflicts with the
// current sparse shared context, so it remains outside this wrapper.
#include "scratch/004982E0_action.cpp"
#include "scratch/004996C0_setup_buttons.cpp"
#include "matching/0049B000_scr_game_score_compare.cpp"
#include "scratch/0049B080_reset_score_display.cpp"
#include "matching/0049B560_draw.cpp"
#include "matching/0049B830_handle_anim_pal.cpp"
