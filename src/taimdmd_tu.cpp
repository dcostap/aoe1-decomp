// Authentic PDB-ordered owner wrapper for taimdmd.cpp.
//
// Module: C:\\msdev\\work\\age1_x1\\taimdmd.cpp
// PDB order is 004E4800, 004E4B80, 004E4EC0, 004E4FA0, 004E5050,
// 004E5DB0, 004E5F30, 004E5FA0, 004E5FE0, 004E6020, 004E6090,
// 004E60D0, 004E60F0, 004E6160, 004E6250, 004E6490, 004E6580,
// 004E6600, and 004E6870.  The scalar deleting destructor at 004E4B60
// is compiler-generated beside the constructor pair and has no source owner.
//
// The context header records the proven embedded module offsets and the
// 0x125C8 TribeMainDecisionAIModule layout.  Build with the module's EH-aware
// flags: /nologo /c /O2 /Oy /GX.
//
// Candidate compile record (validate_candidate_tu.py):
//   exact MATCH: 004E4EC0, 004E5FA0, 004E5FE0, 004E6020, 004E60F0, 004E6870.
//   exact observed mismatches: 004E4FA0, 004E5DB0, 004E5F30, 004E6160,
//     004E6250, 004E6490, 004E6580, and 004E6600.
//   observed scratch: 004E60D0 compiled with a 2-byte relocation mismatch;
//     004E4800, 004E4B80, and 004E5050 compiled but comparison was blocked by
//     duplicate constructor/update display names in the grouped object.
//   generated MATCH: 004E4B60 scalar deleting destructor.
//   comparison blocked: 004E6090 has two qualifying MainDecision symbols;
//     the three duplicate-name scratch rows have the same symbol-resolution
//     issue.  The wrapper itself compiles.  No exact tuning follows this gate.

#include "../include/taimdmd_context.h"

#include "scratch/004E4800_TribeMainDecisionAIModule.cpp"
#include "scratch/004E4B80_TribeMainDecisionAIModule.cpp"
#include "matching/004E4EC0_TribeMainDecisionAIModule.cpp"
#include "matching/004E4FA0_setLogHistory.cpp"
#include "scratch/004E5050_update.cpp"
#include "matching/004E5DB0_save.cpp"
#include "matching/004E5F30_kick.cpp"
#include "matching/004E5FA0_addObject.cpp"
#include "matching/004E5FE0_removeObject.cpp"
#include "matching/004E6020_objectGroupThatCanPerformAction.cpp"
#include "matching/004E6090_canPerformAction.cpp"
#include "scratch/004E60D0_detask.cpp"
#include "matching/004E60F0_isMoveable.cpp"
#include "matching/004E6160_updateBuildAIWithObjects.cpp"
#include "matching/004E6250_tributeNotify.cpp"
#include "matching/004E6490_revokeTributeAlliance.cpp"
#include "matching/004E6580_setTributeChat.cpp"
#include "matching/004E6600_processAICommand.cpp"
#include "matching/004E6870_currentScore.cpp"
