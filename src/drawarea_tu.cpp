// Authentic Drawarea.cpp owner wrapper.
//
// The include order follows the PDB source-line order.  Matching owners are
// exact owners.  Accepted-drift and scratch owners stay observed; this
// wrapper does not promote them.  The module response file is the reviewed
// /GX context used by the existing Drawarea prefix.
//
// This complete wrapper is a context-validation proposal.  Several older
// owner files still carry standalone class declarations.  The first compile
// result records whether those declarations can share one authentic TU.

#define DRAWAREA_CANONICAL_TU 1

// The module-local context preserves the period GDI import declaration.
#include "drawarea_phase2_context.h"

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
#include "scratch/00443520_Paint.cpp"
#include "matching/00443680_GetIsLostErrorNum.cpp"
#include "matching/004436D0_GetRestoreErrorNum.cpp"
#include "matching/00443780_GetSetDispModeErrorNum.cpp"
#include "matching/00443840_GetLockErrorNum.cpp"
#include "matching/00443990_GetBlitErrorNum.cpp"
#include "matching/00443AD0_GetCreateErrorNum.cpp"
#include "matching/00443C00_GetColorKeyErrorNum.cpp"
#include "accepted_drift/00443CB0_SetPalette.cpp"
#include "matching/00443D40_ModifyPalette.cpp"
#include "matching/00443DE0_TDrawArea.cpp"
#include "matching/00443F10_TDrawArea.cpp"
#include "accepted_drift/00444040_Init.cpp"
#include "matching/00444110_CheckSurface.cpp"
#include "matching/00444270_Lock.cpp"
#include "matching/00444300_Unlock.cpp"
#include "matching/00444340_GetDc.cpp"
#include "matching/00444390_ReleaseDc.cpp"
#include "matching/004443D0_SetSize.cpp"
#include "accepted_drift/00444680_Clear.cpp"
#include "matching/00444990_SetAccessOffsets.cpp"
#include "matching/00444A60_SetFloatOffsets.cpp"
#include "matching/00444B10_SetInfo.cpp"
#include "matching/00444B40_AlignedWidth.cpp"
#include "matching/00444B50_SetClipRect.cpp"
#include "accepted_drift/00444C30_SetClipRect.cpp"
#include "accepted_drift/00444D50_Copy.cpp"
#include "matching/00445710_SetTrans.cpp"
#include "matching/00445780_SetOverlayTrans.cpp"
#include "matching/004457E0_SetPixel.cpp"
#include "scratch/00445840_DrawLine.cpp"
#include "accepted_drift/004459A0_DrawRect.cpp"
#include "matching/00445A40_DrawRect.cpp"
#include "accepted_drift/00445A60_DrawHorzLine.cpp"
#include "accepted_drift/00445AF0_DrawVertLine.cpp"
#include "matching/00445B80_FillRect.cpp"
#include "matching/00445C70_DrawBevel.cpp"
#include "matching/00445D20_DrawBevel2.cpp"
#include "matching/00445E40_DrawBevel3.cpp"
#include "matching/00445FE0_DrawBevel21.cpp"
#include "matching/004460C0_DrawBevel32.cpp"
#include "matching/00446220_SetShadowTable.cpp"
#include "matching/00446230_DrawShadowBox.cpp"
#include "matching/00446340_GetPalette.cpp"
#include "matching/00446370_SetPalette.cpp"
#include "accepted_drift/004463B0_take_snapshot.cpp"

#undef DRAWAREA_CANONICAL_TU
