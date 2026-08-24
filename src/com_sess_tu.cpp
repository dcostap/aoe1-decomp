// Authentic owner wrapper for C:\\msdev\\work\\age1_x1\\com_sess.cpp.
//
// Translation-unit context gate evidence:
//   PDB module: com_sess.cpp, source path C:\\msdev\\work\\age1_x1\\com_sess.cpp.
//   PDB owner order and source bands:
//     00432200 TCommunications_Sessions::TCommunications_Sessions 19-35
//     00432290 TCommunications_Sessions::~TCommunications_Sessions 38
//     004322A0 TCommunications_Sessions::EraseInformation 45-51
//     004322C0 TCommunications_Sessions::GetSessionCount 54-60
//     004322D0 TCommunications_Sessions::GetSessionName 63-73
//     004322F0 TCommunications_Sessions::GetSessionMaxPlayers 76-81
//     00432320 TCommunications_Sessions::GetSessionCurrentPlayers 84-89
//     00432350 TCommunications_Sessions::GetSessionGUID 92-101
//     00432380 TCommunications_Sessions::IncSessionCount 105-111
//     00432390 TCommunications_Sessions::AddSession 126-157
//     004324F0 TCommunications_Sessions::Refresh 161-186
//     00432560 EnumSessionCallback 199-224
//     004325E0 TCommunications_Sessions::IsEqualGuid 233-239
//
// The owner sequence follows both PDB source-line order and linked address
// order. The constructor, method symbols, body boundaries, and callback call
// site are exact anchors. The grouped context models the proven 0x238-byte
// session record, 501-entry session array, handler GUID fields, and callback
// descriptor surface. The proposal uses config/flags/default.rsp, the pinned
// normal VC5 flags.
//
// This wrapper is for authentic TU compilation and proposal validation only.
// Exact tuning stops after the first grouped compile.

#define COM_SESS_TU_CONTEXT 1
#include "../include/com_sess_context.h"

#include "matching/00432200_TCommunications_Sessions.cpp"
#include "matching/00432290_TCommunications_Sessions.cpp"
#include "scratch/004322A0_EraseInformation.cpp"
#include "matching/004322C0_GetSessionCount.cpp"
#include "matching/004322D0_GetSessionName.cpp"
#include "matching/004322F0_GetSessionMaxPlayers.cpp"
#include "matching/00432320_GetSessionCurrentPlayers.cpp"
#include "matching/00432350_GetSessionGUID.cpp"
#include "scratch/00432380_IncSessionCount.cpp"
#include "matching/00432390_AddSession.cpp"
#include "matching/004324F0_Refresh.cpp"
#include "matching/00432560_EnumSessionCallback.cpp"
#include "matching/004325E0_IsEqualGuid.cpp"

#undef COM_SESS_TU_CONTEXT
