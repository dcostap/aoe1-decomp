// Authentic aiemomod.cpp owner wrapper in PDB source order.
//
// Source module: C:\\msdev\\work\\age1_x1\\aiemomod.cpp
// PDB owner line bands:
//   0040C7C0  EmotionalAIModule(void*, int)       23-33
//   0040C920  EmotionalAIModule(int, int)          40-50
//   0040CA90  ~EmotionalAIModule                 55
//   0040CAA0  setMainDecisionAI                    61-63
//   0040CAB0  save                                68-72
//   0040CAE0  stateName                           77-81
//   0040CB10  state                               86-90
//   0040CB30  setState                             95-98
//   0040CB50  incrementState                     103-106
//   0040CB80  decrementState                     111-114
//   0040CBB0  overallState                        119-129
//   0040CBE0  setOverallState                     134-187
//   0040CD80  defaultState                        192-194
//
// The class context carries the reviewed AIModule hierarchy and EmotionalAIModule
// field ownership.  The nearby scalar deleting destructor at 0040C900 is emitted
// by VC5 from the real virtual destructor surface.
#define AOE1_AIEMOMOD_TU_CONTEXT 1
#include "../include/aiemomod_context.h"

#include "matching/0040C7C0_EmotionalAIModule.cpp"
#include "matching/0040C920_EmotionalAIModule.cpp"
#include "scratch/0040CA90_EmotionalAIModule.cpp"
#include "matching/0040CAA0_setMainDecisionAI.cpp"
#include "matching/0040CAB0_save.cpp"
#include "matching/0040CAE0_stateName.cpp"
#include "matching/0040CB10_state.cpp"
#include "matching/0040CB30_setState.cpp"
#include "matching/0040CB50_incrementState.cpp"
#include "matching/0040CB80_decrementState.cpp"
#include "matching/0040CBB0_overallState.cpp"
#include "matching/0040CBE0_setOverallState.cpp"
#include "matching/0040CD80_defaultState.cpp"

#undef AOE1_AIEMOMOD_TU_CONTEXT
