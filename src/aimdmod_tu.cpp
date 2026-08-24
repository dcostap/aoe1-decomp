// Authentic PDB-ordered owner wrapper for aimdmod.cpp.
//
// Source module: C:\\msdev\\work\\age1_x1\\aimdmod.cpp
// PDB order follows the source line bands: 0040CDF0, 0040CE90, 0040D020,
// 0040D090, 0040D0A0, 0040D180, 0040D250, 0040D2C0, 0040D2D0, 0040D3B0,
// 0040D480, 0040D580, 0040D660, 0040D760, 0040D780, 0040D9D0, 0040DB20,
// 0040DB40, 0040DB50, and 0040DC30.
//
// The nearby 0040CE70 vector-deleting destructor is compiler-generated.
// The shared context uses the reviewed AIModule, MainDecisionAIModule, and
// RGE_Static_Object member and virtual surfaces. It does not hand-write a
// vtable or use placeholder virtual slots.
//
// Candidate compile record (validate_candidate_tu.py):
//   exact MATCH: 0040D090, 0040D0A0, 0040D180, 0040D250, 0040D2C0,
//     0040D2D0, 0040D3B0, 0040D480, 0040D580, 0040D660, 0040D760,
//     0040D9D0, 0040DB20, 0040DB40, 0040DB50, and 0040DC30.
//   exact observed mismatches: 0040CE90, 0040D020, and 0040D780.
//   observed mismatch: 0040CDF0 (verified_logic source owner).
//   generated MATCH: 0040CE70 `vector_deleting_destructor',
//     ??_GMainDecisionAIModule@@UAEPAXI@Z.
//   blocked comparisons: none. All 21 listed entries compiled and compared.
// The three exact mismatches are retained as observed codegen evidence only;
// no exact tuning follows the authentic-wrapper compile gate.
#include "aimdmod_context.h"

#include "verified_logic/0040CDF0_MainDecisionAIModule.cpp"
#include "matching/0040CE90_MainDecisionAIModule.cpp"
#include "matching/0040D020_MainDecisionAIModule.cpp"
#include "matching/0040D090_setLogHistory.cpp"
#include "matching/0040D0A0_save.cpp"
#include "matching/0040D180_addObject.cpp"
#include "matching/0040D250_removeObject.cpp"
#include "matching/0040D2C0_numberObjects.cpp"
#include "matching/0040D2D0_numberObjectsWithAction.cpp"
#include "matching/0040D3B0_numberObjectsWithGroup.cpp"
#include "matching/0040D480_numberObjectsWithActionAndTarget.cpp"
#include "matching/0040D580_numberObjectsWithTargetType.cpp"
#include "matching/0040D660_numberObjectsWithActionAndTargetType.cpp"
#include "matching/0040D760_object.cpp"
#include "matching/0040D780_object.cpp"
#include "matching/0040D9D0_object.cpp"
#include "matching/0040DB20_objectGroupThatCanPerformAction.cpp"
#include "matching/0040DB40_canPerformAction.cpp"
#include "matching/0040DB50_numberBusyObjects.cpp"
#include "matching/0040DC30_mostDamaged.cpp"
