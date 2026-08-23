// Authentic taitacmd.cpp context in PDB source-line and address order.
// Each include remains the sole source owner of its VA.
#define TAITACMD_SHARED_CONTEXT 1
#include "../include/taitacmd_context.h"

#include "matching/004ED1C0_TribeTacticalAIModule.cpp"
#include "scratch/004ED4F0_TribeTacticalAIModule.cpp"
#include "matching/004EEB40_TribeTacticalAIModule.cpp"
#include "matching/004EEE40_updateAreaName.cpp"
#include "matching/004EEF40_update.cpp"
#include "matching/004EF4D0_setMainDecisionAI.cpp"
#include "matching/004EF4E0_save.cpp"
#include "matching/004F0180_logGroupDebug.cpp"
#include "scratch/004F0190_doSomething.cpp"
#include "matching/004F0BC0_clearArea.cpp"
#include "matching/004F0D70_addObject.cpp"
#include "matching/004F1090_removeObject.cpp"
// 004F1390 is the utmarray.h template owner, not a taitacmd.cpp owner.
#include "matching/004F13F0_evaluateCivilianDistribution.cpp"
#include "scratch/004F1600_taskCivilians.cpp"
#include "matching/004F1E10_taskIdleSoldiers.cpp"
// 004F21F0 stays separate. This shared surface changes its reviewed output.
#include "matching/004F4760_playTaskSoldiers.cpp"
// 004F4AA0 stays separate. Its canonical resize-call surface regresses the
// earlier shared ManagedArray anchors.

#undef TAITACMD_SHARED_CONTEXT
