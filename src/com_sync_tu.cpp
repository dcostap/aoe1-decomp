// Authentic com_sync.cpp owner sequence for the recovered synchronized-check
// segment.  This wrapper is intentionally unregistered.  It provides one
// compiler-facing context without creating a second VA owner.
//
// PDB source module: C:\\msdev\\work\\age1_x1\\com_sync.cpp
// Owner order and source lines:
//   00432FF0 RGE_Communications_Synchronize 23-27
//   00433070 ~RGE_Communications_Synchronize 30-32
//   004330A0 Add 44-62
//   00433180 ValidateChecksums 74-125
//   00433290 DoChecksum 129-195
//   00433450 SetLastWorldRandom 200-202
//   00433460 LogChecksums 207-322
//   00433A90 EnableSyncChecking 325-327
//   00433AA0 SetStopOnFail 330-332
//   00433AB0 SetDialogOnFail 335-337
//   00433AC0 SendChatMsgsAtChecksum 340-342
//   00433AD0 IsPlayerOutOfSync 345-435
//
// The first eleven owners are exact.  IsPlayerOutOfSync remains a scratch
// owner and is included to preserve the complete module source sequence.
//
// Exact anchors for the included owners are their original qualified symbols,
// body ranges, source bands, and positional checker matches.  The eleven exact
// owners use default /nologo /c /O2 /Oy flags.  No EH frame occurs in these
// ranges.

#define COM_SYNC_TU_CONTEXT 1
#include "../include/com_sync_context.h"

#include "matching/00432FF0_RGE_Communications_Synchronize.cpp"
#include "matching/00433070_RGE_Communications_Synchronize.cpp"
#include "matching/004330A0_Add.cpp"
#include "matching/00433180_ValidateChecksums.cpp"
#include "matching/00433290_DoChecksum.cpp"
#include "matching/00433450_SetLastWorldRandom.cpp"
#include "matching/00433460_LogChecksums.cpp"
#include "matching/00433A90_EnableSyncChecking.cpp"
#include "matching/00433AA0_SetStopOnFail.cpp"
#include "matching/00433AB0_SetDialogOnFail.cpp"
#include "matching/00433AC0_SendChatMsgsAtChecksum.cpp"
#include "scratch/00433AD0_IsPlayerOutOfSync.cpp"

#undef g_debuggingLog
#undef COM_SYNC_TU_CONTEXT
