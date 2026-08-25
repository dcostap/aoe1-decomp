// Authentic Drawarea.cpp prefix through TDrawSystem::CreateSurfaces.
//
// PDB source order is Drawarea.cpp lines 316-1056, then 1062-1149 and
// 1155-1218.  Stop before 00443520 Paint at lines 1224-1328; it remains
// scratch and is the first unresolved intervening owner.
// The wrapper keeps one canonical owner include per VA.  The /GX response
// file is module-wide for this probe.  Original EH evidence occurs at
// 004430F0, 004443D0, and 00444C30.  Non-EH owners are flag-insensitive in
// controlled VC5 probes, so a binary-only code-band claim is not possible.
#define DRAWAREA_CANONICAL_TU
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
#include "matching/004430F0_CreateSurfaces.cpp"
#include "matching/004433F0_HandleSize.cpp"
#include "matching/00443460_HandlePaletteChanged.cpp"
#include "matching/00443490_HandleQueryNewPalette.cpp"
