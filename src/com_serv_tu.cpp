// Authentic owner wrapper for C:\\msdev\\work\\age1_x1\\com_serv.cpp.
//
// Translation-unit context gate evidence:
//   PDB module: com_serv.cpp, source path C:\\msdev\\work\\age1_x1\\com_serv.cpp.
//   PDB owner order and source bands:
//     00431FB0 TCommunications_Services::TCommunications_Services 20-37
//     00432030 TCommunications_Services::~TCommunications_Services 42
//     00432040 TCommunications_Services::GetServiceCount 49-51
//     00432050 TCommunications_Services::IncServiceCount 54-57
//     00432060 TCommunications_Services::GetServiceName 61-66
//     00432080 TCommunications_Services::SetServiceName 69-75
//     004320C0 TCommunications_Services::GetServiceGUID 80-82
//     004320F0 TCommunications_Services::EnumServiceGUID 86-91
//     00432120 TCommunications_Services::GetServiceActive 97-105
//     00432150 TCommunications_Services::SetServiceActive 108-118
//     00432180 DPEnumCallback 123-162
//
// The owner sequence follows both PDB line order and linked address order.
// The constructor, method symbols, body boundaries, and callback call sites are
// exact anchors. The complete class surface models Service[100] at +0x00 and
// ServiceCount at +0x2580. The proposal uses config/flags/default.rsp
// (/nologo /c /O2 /Oy), the pinned normal VC5 flags.
//
// This wrapper is for authentic TU compilation and proposal validation only.
// Exact tuning stops after the first grouped compile.

#define COM_SERV_TU_CONTEXT 1
#include "../include/com_serv_context.h"

#include "matching/00431FB0_TCommunications_Services.cpp"
#include "matching/00432030_TCommunications_Services.cpp"
#include "matching/00432040_GetServiceCount.cpp"
#include "matching/00432050_IncServiceCount.cpp"
#include "matching/00432060_GetServiceName.cpp"
#include "matching/00432080_SetServiceName.cpp"
#include "matching/004320C0_GetServiceGUID.cpp"
#include "matching/004320F0_EnumServiceGUID.cpp"
#include "matching/00432120_GetServiceActive.cpp"
#include "matching/00432150_SetServiceActive.cpp"
#include "matching/00432180_DPEnumCallback.cpp"

#undef COM_SERV_TU_CONTEXT
