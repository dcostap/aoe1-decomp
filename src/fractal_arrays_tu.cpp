// Authentic fractal.cpp PointMaker owner sequence.
//
// PDB module: C:\msdev\work\age1_x1\fractal.cpp. One default flag set.
// Owners follow the PDB source-line and address order from SetDefaultValues
// (line 29) through MapCleanUpEliminatingSinglesOnly (line 245).
//
// PDB-qualified owners, in source order:
// PointMaker::SetDefaultValues, PointMaker::PointMaker, PointMaker::~PointMaker,
// PointMaker::CreateMasks, PointMaker::DeleteMasks, PointMaker::DrawMask,
// PointMaker::ClearArrays, PointMaker::DeleteArrays, PointMaker::MakeArrays,
// PointMaker::CreateShape, PointMaker::CreateShape(int,int),
// PointMaker::Branch, PointMaker::MakeFirstLink, PointMaker::MakeNewLink,
// PointMaker::MakeSatelliteLink, PointMaker::DrawPrimaryIntoProbabilityArray,
// PointMaker::DrawCurrentBranchIntoProbArray,
// PointMaker::DrawCurrentSatelliteIntoProbArray, PointMaker::AddingRect,
// PointMaker::AddingCircle, PointMaker::CreateMapBasedOnProbabilityArray,
// PointMaker::SetPoint, PointMaker::SetMaxNumberOfBranches,
// PointMaker::SetChanceOfNextNode, PointMaker::SetNumberOfSatellites,
// PointMaker::SetSplitsPerBranch, PointMaker::SetWidthAndHeight,
// PointMaker::SetStartPositionRadius, PointMaker::SetBranchsRadius,
// PointMaker::SetSatelliteRadius, PointMaker::SetMaxNumberOfBranchLevels,
// PointMaker::SetSatelliteDistance, PointMaker::SetBranchDistance,
// PointMaker::SetMinimumNumberOfTiles, PointMaker::SetDrawToOneArray,
// PointMaker::SetBorderDepthPercentage, PointMaker::RetrieveMap,
// PointMaker::RetrieveProbMap, PointMaker::ErrorCheckingAndCorrection,
// PointMaker::PrepareLimits, PointMaker::MapCleanUpEliminatingSinglesOnly.
// Full-context reviewed drift: AB90, B2B0, B470, B760, BAA0, BB60, BCD0,
// BD80, BF90, C1B0, and C510. Unresolved scratch: AFE0 and B950.
// All remaining listed owners are exact under fresh grouped checks.
// The owner bodies below remain the sole compiler-facing VA owners.
//
// Each include is one canonical VA owner. Accepted-drift and scratch owners
// remain included as normal source owners so later codegen can use the real
// module context. Generated, padding, asm, and parent-owned fragments are not
// included.
#include "../include/fractal_arrays_context.h"

#include "accepted_drift/0044AB90_SetDefaultValues.cpp"
#include "matching/0044AC50_PointMaker.cpp"
#include "matching/0044AC80_PointMaker.cpp"
#include "matching/0044ACB0_CreateMasks.cpp"
#include "matching/0044AF90_DeleteMasks.cpp"
#include "scratch/0044AFE0_DrawMask.cpp"
#include "matching/0044B210_ClearArrays.cpp"
#include "matching/0044B270_DeleteArrays.cpp"
#include "accepted_drift/0044B2B0_MakeArrays.cpp"
#include "matching/0044B320_CreateShape.cpp"
#include "accepted_drift/0044B470_CreateShape.cpp"
#include "matching/0044B540_Branch.cpp"
#include "matching/0044B610_MakeFirstLink.cpp"
#include "accepted_drift/0044B760_MakeNewLink.cpp"
#include "scratch/0044B950_MakeSatelliteLink.cpp"
#include "accepted_drift/0044BAA0_DrawPrimaryIntoProbabilityArray.cpp"
#include "accepted_drift/0044BB60_DrawCurrentBranchIntoProbArray.cpp"
#include "accepted_drift/0044BCD0_DrawCurrentSatelliteIntoProbArray.cpp"
#include "accepted_drift/0044BD80_AddingRect.cpp"
#include "accepted_drift/0044BF90_AddingCircle.cpp"
#include "accepted_drift/0044C1B0_CreateMapBasedOnProbabilityArray.cpp"
#include "matching/0044C200_SetPoint.cpp"
#include "matching/0044C220_SetMaxNumberOfBranches.cpp"
#include "matching/0044C230_SetChanceOfNextNode.cpp"
#include "matching/0044C240_SetNumberOfSatellites.cpp"
#include "matching/0044C250_SetSplitsPerBranch.cpp"
#include "matching/0044C260_SetWidthAndHeight.cpp"
#include "matching/0044C280_SetStartPositionRadius.cpp"
#include "matching/0044C290_SetBranchsRadius.cpp"
#include "matching/0044C2A0_SetSatelliteRadius.cpp"
#include "matching/0044C2B0_SetMaxNumberOfBranchLevels.cpp"
#include "matching/0044C2D0_SetSatelliteDistance.cpp"
#include "matching/0044C2E0_SetBranchDistance.cpp"
#include "matching/0044C2F0_SetMinimumNumberOfTiles.cpp"
#include "matching/0044C300_SetDrawToOneArray.cpp"
#include "matching/0044C310_SetBorderDepthPercentage.cpp"
#include "matching/0044C350_RetrieveMap.cpp"
#include "matching/0044C360_RetrieveProbMap.cpp"
#include "matching/0044C370_ErrorCheckingAndCorrection.cpp"
#include "matching/0044C4B0_PrepareLimits.cpp"
#include "accepted_drift/0044C510_MapCleanUpEliminatingSinglesOnly.cpp"
