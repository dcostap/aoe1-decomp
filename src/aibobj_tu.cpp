// Authentic PDB-order owner wrapper for C:\\msdev\\work\\age1_x1\\aibobj.cpp.
//
// The source-line order below is the order reported by the PDB packet. The
// context class has the proven virtual destructor, field aliases, and 0xA0
// object size. The module spans PDB lines 43-544 and uses
// config/flags/default.rsp (/nologo /c /O2 /Oy). The 46 exact anchors and the
// compiler-generated vector deleting destructor match. The four constructors
// and four comparison operators remain observed nonexact owners. No generated
// entry is blocked. No synthetic function or manual vtable write is used here.

#define AIBOBJ_CONTEXT_READY 1
#include "aibobj_context.h"

#include "matching/00409FA0_BaseObject.cpp"
#include "matching/0040A060_BaseObject.cpp"
#include "matching/0040A130_BaseObject.cpp"
#include "matching/0040A240_BaseObject.cpp"
#include "matching/0040A350_BaseObject.cpp"
#include "scratch/0040A370_operator.cpp"
#include "scratch/0040A390_operator.cpp"
#include "scratch/0040A3B0_operator.cpp"
#include "scratch/0040A3D0_operator.cpp"
#include "matching/0040A3F0_numberGroups.cpp"
#include "matching/0040A400_groupID.cpp"
#include "matching/0040A420_inGroup.cpp"
#include "matching/0040A460_addGroup.cpp"
#include "matching/0040A4E0_removeGroup.cpp"
#include "matching/0040A560_categoryID.cpp"
#include "matching/0040A570_typeID.cpp"
#include "matching/0040A580_gameID.cpp"
#include "matching/0040A590_name.cpp"
#include "matching/0040A5A0_xPosition.cpp"
#include "matching/0040A5B0_yPosition.cpp"
#include "matching/0040A5C0_zPosition.cpp"
#include "matching/0040A5D0_xSize.cpp"
#include "matching/0040A5E0_ySize.cpp"
#include "matching/0040A5F0_zSize.cpp"
#include "matching/0040A600_hitPoints.cpp"
#include "matching/0040A610_minHitPoints.cpp"
#include "matching/0040A620_maxHitPoints.cpp"
#include "matching/0040A630_busy.cpp"
#include "matching/0040A640_currentTask.cpp"
#include "matching/0040A650_currentTarget.cpp"
#include "matching/0040A660_currentTargetType.cpp"
#include "matching/0040A670_currentTargetXPosition.cpp"
#include "matching/0040A680_currentTargetYPosition.cpp"
#include "matching/0040A690_currentTargetZPosition.cpp"
#include "matching/0040A6A0_setXPosition.cpp"
#include "matching/0040A6B0_setYPosition.cpp"
#include "matching/0040A6C0_setZPosition.cpp"
#include "matching/0040A6D0_setXSize.cpp"
#include "matching/0040A6E0_setYSize.cpp"
#include "matching/0040A6F0_setZSize.cpp"
#include "matching/0040A700_setHitPoints.cpp"
#include "matching/0040A710_incrementHitPoints.cpp"
#include "matching/0040A720_decrementHitPoints.cpp"
#include "matching/0040A730_setMinHitPoints.cpp"
#include "matching/0040A740_incrementMinHitPoints.cpp"
#include "matching/0040A750_decrementMinHitPoints.cpp"
#include "matching/0040A760_setMaxHitPoints.cpp"
#include "matching/0040A770_incrementMaxHitPoints.cpp"
#include "matching/0040A790_decrementMaxHitPoints.cpp"
#include "matching/0040A7B0_setBusy.cpp"
#include "matching/0040A7C0_setCurrentTask.cpp"
#include "matching/0040A7D0_setCurrentTarget.cpp"
#include "matching/0040A7E0_setCurrentTargetType.cpp"
#include "matching/0040A7F0_setCurrentTargetPosition.cpp"

#undef AIBOBJ_CONTEXT_READY
