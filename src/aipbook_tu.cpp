// Authentic aipbook.cpp owner context for the unresolved and persistence path.
//
// PDB source: C:\\msdev\\work\\age1_x1\\aipbook.cpp
// Owner includes follow PDB source-line and linked-address order.
// The wrapper contains no synthetic function or unused compiler-state owner.
//
// Canonical aggregate evidence:
//   AIPlayPhaseCommand  0x10
//   AIPlayPhaseTrigger  0x14
//   AIPlayPhase         0x8C
//   AIPlayGroup         0x0C
//   AIPlay              0x608
//   AIPlayStatus        0x1C8
//   AIPlayBook          0x50
//
// Exact anchors include the natural phase, group, and play helpers below.
// Persistence-path anchors are:
//   0040FC30 AIPlayStatus::AIPlayStatus  lines 719-727
//   0040FE90 AIPlayStatus::load          lines 848-863
//   0040FF70 AIPlayStatus::save          lines 868-882
//   00410100 AIPlayStatus::removeDeadUnits lines 906-918
//   00410150 AIPlayStatus::resetHitPoints  lines 923-934
// The playbook anchors are:
//   00411340 AIPlayBook::play(int) lines 1295-1299
//   00411370 AIPlayBook::play(char*) lines 1304-1312
//   00411400 AIPlayBook::playNumber lines 1317-1325
//   00411480 AIPlayBook::convertTargetNameToIntType lines 1330-1334
//   004114E0 AIPlayBook::convertTargetCharacteristicNameToIntType lines 1339-1351
//   00411650 AIPlayBook::convertUnitNameToIntType lines 1356-1358
//
// 0040F530 and 00410220 remain scratch owners. 00410050 is the reviewed
// accepted-drift owner. The original loadPlays EH frame requires /GX for this
// translation unit. This file is an owner wrapper, not a config registration.

#define AIPBOOK_CANONICAL_TU 1
#include "../include/aipbook_context.h"

#include "matching/0040E930_AIPlayPhaseCommand.cpp"
#include "matching/0040E980_AIPlayPhaseCommand.cpp"
#include "matching/0040E9C0_nameType.cpp"
#include "matching/0040E9D0_convertToIntType.cpp"
#include "matching/0040EBF0_convertToNameType.cpp"
#include "matching/0040EC70_AIPlayPhaseTrigger.cpp"
#include "matching/0040ECC0_AIPlayPhaseTrigger.cpp"
#include "matching/0040ED00_nameType.cpp"
#include "matching/0040ED10_convertToIntType.cpp"
#include "matching/0040EFF0_convertToNameType.cpp"
#include "matching/0040F0A0_AIPlayPhase.cpp"
#include "matching/0040F130_trigger.cpp"
#include "matching/0040F150_addCommand.cpp"
#include "matching/0040F1A0_addTrigger.cpp"
#include "matching/0040F230_AIPlayGroup.cpp"
#include "matching/0040F240_minimum.cpp"
#include "matching/0040F260_setMinimum.cpp"
#include "matching/0040F280_maximum.cpp"
#include "matching/0040F2A0_setMaximum.cpp"
#include "matching/0040F2C0_initialize.cpp"
#include "matching/0040F380_humanPlay.cpp"
#include "matching/0040F3A0_typeName.cpp"
#include "matching/0040F3B0_targetType.cpp"
#include "matching/0040F420_targetCharacteristic.cpp"
#include "matching/0040F490_gatherTolerance.cpp"
#include "matching/0040F4E0_group.cpp"
#include "matching/0040F500_phase.cpp"
#include "scratch/0040F530_fillGroups.cpp"
#include "matching/0040FC30_AIPlayStatus.cpp"
#include "matching/0040FE90_load.cpp"
#include "matching/0040FF70_save.cpp"
#include "accepted_drift/00410050_copy.cpp"
#include "matching/00410100_removeDeadUnits.cpp"
#include "matching/00410150_resetHitPoints.cpp"
#include "scratch/00410220_loadPlays.cpp"
#include "matching/00411340_play.cpp"
#include "matching/00411370_play.cpp"
#include "matching/00411400_playNumber.cpp"
#include "matching/00411480_convertTargetNameToIntType.cpp"
#include "matching/004114E0_convertTargetCharacteristicNameToIntType.cpp"
#include "matching/00411650_convertUnitNameToIntType.cpp"

#undef AIPBOOK_CANONICAL_TU
