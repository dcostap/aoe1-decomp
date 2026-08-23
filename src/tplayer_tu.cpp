// Canonical tplayer.cpp owner prefix from the original PDB module.
//
// The order follows the PDB source lines and virtual addresses.  Each included
// file owns one VA.  The source files are normal or reviewed accepted-drift
// owners only; generated, padding, assembly, and parent fragments stay out.
//
// Proposed module flags: config/flags/default.rsp.  This wrapper is not yet
// registered in config/translation_units.json.
//
// Evidence anchors retained in the owners:
// - 00513000 keeps the tech count, table ownership, and original pointer-fault
//   order as a reviewed blocker.
// - 005153D0 keeps the save-random order, enemy-before-ally checks, two
//   diplomacy loops, and the 42-call AI load sequence.
// - 00515E00 keeps the literal rule IDs, selected counters, seven reduction
//   passes, and the cold final rule branch.
// - 005182E0 keeps the civilization table slots and accepted drift note.
//
// The civilization setup run below is one PDB-ordered block.  It starts at
// 00517B90 and ends at 00518DD0.  The next tplayer owner, 00518F00, is also
// included after the source gap.  Accepted drift owners retain their review
// notes.  00517B90, 00517E10, 005181C0, 005188F0, 00518B50, 00518DD0,
// 00518F00, 005192F0, and 00519320 remain exact in isolated checks.
// 005188F0 now uses the real TRIBE_Player owner instead of a synthetic
// TRIBE_Player3 owner.
// Reviewed accepted-drift owners in this run are 00517CD0, 00518090,
// 005182E0, 00518400, 00518540, 00518670, 005187A0, 00518A20, and 00518C90.
// 00517F30 remains scratch because its store order changes partial output and
// fault order.  Safe exact owners continue through 00519320.  The wrapper
// stops before the reviewed padding-only block at 00519465.

#include "../include/tplayer_context.h"

// tplayer.cpp:930-975
#include "scratch/00513000_interface_tech_avail.cpp"

// tplayer.cpp:2145-2302
#include "accepted_drift/005153D0_loadAIInformation.cpp"

// tplayer.cpp:2550-3937
#include "scratch/00515E00_intelligentBuildListAndRulesSelection.cpp"

// tplayer.cpp:3943-3987
#include "matching/00517B90_setupEgyptian.cpp"

// tplayer.cpp:3992-4041
#include "accepted_drift/00517CD0_setupGreek.cpp"

// tplayer.cpp:4046-4084
#include "matching/00517E10_setupBabylonian.cpp"

// tplayer.cpp:4089-4142
#include "scratch/00517F30_setupAssyrian.cpp"

// tplayer.cpp:4147-4195
#include "accepted_drift/00518090_setupMinoan.cpp"

// tplayer.cpp:4200-4243
#include "matching/005181C0_setupHittite.cpp"

// tplayer.cpp:4248-4287
#include "accepted_drift/005182E0_setupPhoenician.cpp"

// tplayer.cpp:4292-4340
#include "accepted_drift/00518400_setupSumerian.cpp"

// tplayer.cpp:4345-4390
#include "accepted_drift/00518540_setupPersian.cpp"

// tplayer.cpp:4395-4435
#include "accepted_drift/00518670_setupShang.cpp"

// tplayer.cpp:4440-4490
#include "accepted_drift/005187A0_setupYamato.cpp"

// tplayer.cpp:4495-4540
#include "matching/005188F0_setupChoson.cpp"

// tplayer.cpp:4545-4589
#include "accepted_drift/00518A20_setupRoman.cpp"

// tplayer.cpp:4594-4640
#include "matching/00518B50_setupCarthaginian.cpp"

// tplayer.cpp:4645-4691
#include "accepted_drift/00518C90_setupPalmyran.cpp"

// tplayer.cpp:4696-4739
#include "matching/00518DD0_setupMacedonian.cpp"

// tplayer.cpp:4744-4805
#include "matching/00518F00_logStatus.cpp"

// tplayer.cpp:4810-4815
#include "matching/005192F0_trackUnitGather.cpp"

// tplayer.cpp:4819-4855
#include "matching/00519320_get_achievement.cpp"

// The post-padding owners use their own /GX segment in
// src/tplayer_postpad_tu.cpp.  This keeps the default prefix flag set stable.
