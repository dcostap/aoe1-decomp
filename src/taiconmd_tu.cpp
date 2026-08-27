// Authentic taiconmd.cpp owner wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\taiconmd.cpp
// PDB source order: lines 37, 45, 51, 57, 64, 111, 338, 363, and 385.
// The scalar deleting destructor at 004D5E90 is compiler-generated from the
// virtual TribeConstructionAIModule destructor and is not a source owner.
//
// The shared context keeps the proven ConstructionAIModule base, the
// ConstructionItem 0x80 layout, the construction-list offsets, the +0x314
// decision-AI pointer, and RGE_Static_Object's proven canPlace slot.

#define TAICONMD_SHARED_CONTEXT 1
#include "../include/taiconmd_context.h"

#include "matching/004D5E60_TribeConstructionAIModule.cpp"
#include "matching/004D5EB0_TribeConstructionAIModule.cpp"
#include "matching/004D5EE0_TribeConstructionAIModule.cpp"
#include "matching/004D5EF0_setMainDecisionAI.cpp"
#include "matching/004D5F00_canPlace.cpp"
#include "accepted_drift/004D60E0_placeStructure.cpp"
#include "matching/004D6780_placeDock.cpp"
#include "matching/004D6800_setBuilt.cpp"
#include "matching/004D68A0_compare.cpp"

#undef TAICONMD_SHARED_CONTEXT
