// Authentic aitacmod.cpp recovery wrapper.
//
// PDB source module: C:\\msdev\\work\\age1_x1\\aitacmod.cpp
// PDB source order:
//   00412B50 TacticalAIModule::TacticalAIModule (24-26)
//   00412BA0 TacticalAIModule::~TacticalAIModule (31)
//
// The scalar deleting destructor at 00412B80 is compiler-generated from the
// virtual TacticalAIModule destructor.  The wrapper has no synthetic body.
//
// Forbidden patterns rejected:
// - no inline assembly, naked functions, or manual vtable writes;
// - no synthetic dummy function or wrapper used to create a match;
// - no fake volatility, register steering, or replacement ABI declarations;
// - no padding-only source owner for a behavioral function.

#include "../include/aitacmod_context.h"

#include "matching/00412B50_TacticalAIModule.cpp"
#include "scratch/00412BA0_TacticalAIModule.cpp"
