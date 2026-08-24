// Authentic PDB-ordered owner wrapper for aipbook.cpp.
//
// PDB source: C:\\msdev\\work\\age1_x1\\aipbook.cpp
// This wrapper includes all 68 normal owners in PDB source-line order.
// Matching owners are exact candidates unless grouped codegen keeps one
// observed. Scratch and accepted-drift owners stay observed. The nearby
// compiler-generated scalar deleting destructor at
// 004101D0 has no source include and is listed in the proposal manifest.
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
// Translation-unit context evidence:
//   PDB module: C:\\msdev\\work\\age1_x1\\aipbook.cpp
//   Source order: packet owner lines 26 through 1365, with the compiler-
//                 generated destructor between lines 942 and 947.
//   Owning classes: AIPlayPhaseCommand, AIPlayPhaseTrigger, AIPlayPhase,
//                   AIPlayGroup, AIPlay, AIPlayStatus, and AIPlayBook.
//   Exact anchors: 0040E930, 0040F230, 0040F2E0, 0040FC30, 0040FE90,
//                  004101B0, and 00411340.
//
// Persistence anchors are 0040FC30, 0040FE90, 0040FF70, 00410100, and
// 00410150. Playbook anchors are 00411340, 00411370, 00411400, 00411480,
// 004114E0, and 00411650. The original loadPlays EH frame requires /GX.
// This file is an owner wrapper, not a config registration.

#define AIPBOOK_CANONICAL_TU 1
#include "../include/aipbook_context.h"

#include "matching/0040E930_AIPlayPhaseCommand.cpp"
#include "scratch/0040E950_AIPlayPhaseCommand.cpp"
#include "matching/0040E980_AIPlayPhaseCommand.cpp"
#include "matching/0040E9C0_nameType.cpp"
#include "matching/0040E9D0_convertToIntType.cpp"
#include "matching/0040EBF0_convertToNameType.cpp"
#include "matching/0040EC70_AIPlayPhaseTrigger.cpp"
#include "scratch/0040EC90_AIPlayPhaseTrigger.cpp"
#include "matching/0040ECC0_AIPlayPhaseTrigger.cpp"
#include "matching/0040ED00_nameType.cpp"
#include "matching/0040ED10_convertToIntType.cpp"
#include "matching/0040EFF0_convertToNameType.cpp"
#include "matching/0040F0A0_AIPlayPhase.cpp"
#include "matching/0040F110_command.cpp"
#include "matching/0040F130_trigger.cpp"
#include "matching/0040F150_addCommand.cpp"
#include "matching/0040F1A0_addTrigger.cpp"
#include "scratch/0040F200_initialize.cpp"
#include "matching/0040F230_AIPlayGroup.cpp"
#include "matching/0040F240_minimum.cpp"
#include "matching/0040F260_setMinimum.cpp"
#include "matching/0040F280_maximum.cpp"
#include "matching/0040F2A0_setMaximum.cpp"
#include "matching/0040F2C0_initialize.cpp"
#include "matching/0040F2E0_AIPlay.cpp"
#include "scratch/0040F360_setName.cpp"
#include "matching/0040F380_humanPlay.cpp"
#include "matching/0040F3A0_typeName.cpp"
#include "matching/0040F3B0_targetType.cpp"
#include "scratch/0040F3D0_isTargetType.cpp"
#include "scratch/0040F3F0_addTargetType.cpp"
#include "matching/0040F420_targetCharacteristic.cpp"
#include "scratch/0040F440_isTargetCharacteristic.cpp"
#include "scratch/0040F460_addTargetCharacteristic.cpp"
#include "matching/0040F490_gatherTolerance.cpp"
#include "matching/0040F4E0_group.cpp"
#include "matching/0040F500_phase.cpp"
#include "scratch/0040F530_fillGroups.cpp"
#include "accepted_drift/0040F9B0_groupGivenCommandOnPhase.cpp"
#include "matching/0040FA40_convertToIntType.cpp"
#include "matching/0040FB60_convertToNameType.cpp"
#include "matching/0040FBB0_locationsOnMap.cpp"
#include "matching/0040FC30_AIPlayStatus.cpp"
#include "matching/0040FCB0_originalHitPoints.cpp"
#include "matching/0040FCD0_setOriginalHitPoints.cpp"
#include "matching/0040FCF0_numberInPlay.cpp"
#include "scratch/0040FD10_numberInGroup.cpp"
#include "matching/0040FD40_numberOfTypeInGroup.cpp"
#include "scratch/0040FD80_group.cpp"
#include "matching/0040FDB0_addGrouping.cpp"
#include "scratch/0040FDF0_removeGrouping.cpp"
#include "matching/0040FE30_zeroAllGroupings.cpp"
#include "matching/0040FE50_copyUnits.cpp"
#include "matching/0040FE90_load.cpp"
#include "matching/0040FF70_save.cpp"
#include "accepted_drift/00410050_copy.cpp"
#include "matching/00410100_removeDeadUnits.cpp"
#include "matching/00410150_resetHitPoints.cpp"
#include "matching/004101B0_AIPlayBook.cpp"
#include "scratch/004101F0_AIPlayBook.cpp"
#include "scratch/00410220_loadPlays.cpp"
#include "matching/00411340_play.cpp"
#include "matching/00411370_play.cpp"
#include "matching/00411400_playNumber.cpp"
#include "matching/00411480_convertTargetNameToIntType.cpp"
#include "matching/004114E0_convertTargetCharacteristicNameToIntType.cpp"
#include "matching/00411650_convertUnitNameToIntType.cpp"
#include "matching/00411660_convertUnitToIntType.cpp"

#undef AIPBOOK_CANONICAL_TU
