// Authentic Drawarea.cpp prefix through TDrawSystem::DeleteSurfaces.
// PDB source order: 316, 384, 444, 504, 580, 621-839, 845-921,
// 927-1031, and 1037-1056.
// The first custom per-function flag is 004430F0 (/GX), so this is the
// largest default-flag prefix that includes the first prioritized target.
//
// PDB-qualified owners:
//   TDrawSystem::TDrawSystem
//   TDrawSystem::~TDrawSystem
//   TDrawSystem::CheckAvailModes
//   TDrawSystem::CheckAvailModesCallback
//   TDrawSystem::IsModeAvail
//   TDrawSystem::Init
//   TDrawSystem::SetDisplaySize
//   TDrawSystem::ClearPrimarySurface
//   TDrawSystem::CheckSurfaces
//   TDrawSystem::ClearRestored
//   TDrawSystem::DeleteSurfaces
//
// 00442680 through 00443090 are exact anchors after owner repair.
// 00442A90 is the behavior-reviewed target and remains accepted drift.
#include "matching/00442680_TDrawSystem.cpp"
#include "matching/00442710_TDrawSystem.cpp"
#include "matching/004427A0_CheckAvailModes.cpp"
#include "matching/00442860_CheckAvailModesCallback.cpp"
#include "matching/004429C0_IsModeAvail.cpp"
#include "accepted_drift/00442A90_Init.cpp"
#include "matching/00442DC0_SetDisplaySize.cpp"
#include "matching/00442EF0_ClearPrimarySurface.cpp"
#include "matching/00442F30_CheckSurfaces.cpp"
#include "matching/00443070_ClearRestored.cpp"
#include "matching/00443090_DeleteSurfaces.cpp"
