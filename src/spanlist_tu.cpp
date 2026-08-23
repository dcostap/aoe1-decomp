// Canonical spanlist.cpp translation-unit wrapper.
//
// The owner files below remain the sole source owner of each VA. They are
// included once, in PDB symbol order. The shared header supplies the reviewed
// PDB type surfaces and does not define a target function body.
#define SPANLIST_SHARED_CONTEXT 1
#include "../include/spanlist_context.h"

#include "matching/004BD5E0_TSpan_Node_List.cpp"
#include "matching/004BD640_TSpan_Node_List.cpp"
#include "matching/004BD690_SetNumZones.cpp"
#include "matching/004BD720_InitNewZone.cpp"
#include "matching/004BD790_GetNode.cpp"
#include "matching/004BD800_FreeNode.cpp"
#include "matching/004BD820_FreeThread.cpp"
#include "matching/004BD880_ReclaimAllNodes.cpp"
#include "matching/004BD8A0_ResetStats.cpp"
#include "matching/004BD8B0_TSpan_List_Manager.cpp"
#include "matching/004BD9A0_TSpan_List_Manager.cpp"
#include "matching/004BDA00_SetSpanRegions.cpp"
#include "matching/004BDA70_ResetAll.cpp"
#include "scratch/004BDB00_AddSpan.cpp"
#include "matching/004BDEA0_AddShape.cpp"
#include "matching/004BDFA0_AddShape_Align.cpp"
#include "accepted_drift/004BE090_AddLine_Align.cpp"
#include "matching/004BE1F0_AddMiniList.cpp"
#include "matching/004BE240_SubtractMiniList.cpp"
#include "scratch/004BE290_DeleteSpan.cpp"
#include "matching/004BE4B0_DeleteShape.cpp"
#include "matching/004BE5B0_PointVisible.cpp"
#include "matching/004BE5F0_Merge_n_Align.cpp"
#include "matching/004BE690_AlignamizeSpans.cpp"
#include "matching/004BE750_ScrollSpansHorizontally.cpp"
#include "verified_logic/004BE850_ScrollSpansVertically.cpp"
#include "matching/004BE9E0_ValidateSpan.cpp"
#include "accepted_drift/004BEAD0_DecodeLine.cpp"
#include "accepted_drift/004BEB10_take_snapshot.cpp"

#undef SPANLIST_SHARED_CONTEXT
