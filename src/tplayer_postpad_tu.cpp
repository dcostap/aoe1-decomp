// Canonical post-padding tplayer segment.
//
// 00519465 is a reviewed padding-only block and is intentionally excluded.
// The source order resumes at the next normal tplayer owners.
// Proposed flags: config/flags/00519490_load_victory.rsp.
// This wrapper is not registered in config/translation_units.json.
// 00519490 keeps reviewed 24-byte VC5 join-test drift. 00519500 is exact.
// 00519570 keeps reviewed x87 drift with its canonical virtual ABI.
// 005195D0 is exact. The next owner, 005196E0, remains scratch.
// It uses a +0x88 mouse-action view that conflicts with the canonical
// RGE_Player unitDiplomacy field and the proven +0x130 selection fields.

#include "../include/tplayer_context.h"

// tplayer.cpp:4859-4861
#include "accepted_drift/00519490_load_victory.cpp"

// tplayer.cpp:4865-4867
#include "matching/00519500_new_victory.cpp"

// tplayer.cpp:4873-4884
#include "accepted_drift/00519570_add_attribute_num.cpp"

// tplayer.cpp:4896-4950
#include "matching/005195D0_analyize_selected_objects.cpp"
