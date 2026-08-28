// Authentic infmap.cpp owner wrapper.
//
// PDB module: C:\\msdev\\work\\age1_x1\\infmap.cpp
// PDB order: 26-36, 45-47, 52-57, 62-66, 71-81, 86-100, 105-173,
// 178-181, 186-188, 203-213, 219-235, 240-257, 263-299, 304-321,
// 327-363, 369-387, 394-458, 464-488, 495-585, 590-594, and 599-607.
//
// Owner categories: matching 12, accepted_drift 3, scratch 5, and
// verified_logic 1. The 21 normal owners below are the only source owners.
// 0044E030 is the compiler-generated scalar deleting destructor. 0044EBD2
// and 0044EFE9 are reviewed padding-only entries. None is included here.
//
// Forbidden patterns rejected for this grouped source:
// - no inline assembly, naked functions, or handwritten wrappers;
// - no synthetic dummy function or padding-only behavioral owner;
// - no manual vtable write, fake volatility, register steering, or raw cursor
//   replacement for the canonical InfluenceMap and XYPoint surfaces;
// - no duplicate compiler-facing owner or source outside this PDB module.
//
// All owners use config/flags/default.rsp. No owner has a reviewed custom flag.

#define INFMAP_SHARED_CONTEXT 1
#include "../include/infmap.h"

#include "matching/0044DF80_InfluenceMap.cpp"
#include "matching/0044E050_InfluenceMap.cpp"
#include "matching/0044E080_InfluenceMap.cpp"
#include "matching/0044E0B0_initialize.cpp"
#include "matching/0044E0F0_save.cpp"
#include "matching/0044E1A0_load.cpp"
#include "accepted_drift/0044E250_printToFile.cpp"
#include "matching/0044E4C0_setReferencePoint.cpp"
#include "matching/0044E4E0_lookupValue.cpp"
#include "matching/0044E510_setValue.cpp"
#include "matching/0044E560_setValue.cpp"
#include "accepted_drift/0044E600_incrementValue.cpp"
#include "matching/0044E680_incrementValue.cpp"
#include "matching/0044E790_decrementValue.cpp"
#include "matching/0044E800_decrementValue.cpp"
#include "matching/0044E900_setCoverageCount.cpp"
#include "scratch/0044E9E0_setConnectionCount.cpp"
#include "verified_logic/0044EC00_coverageIncluding.cpp"
#include "accepted_drift/0044ED20_connectionsIncluding.cpp"
#include "matching/0044F030_setUnchangeableLimit.cpp"
#include "matching/0044F040_maxValue.cpp"

#undef INFMAP_SHARED_CONTEXT
