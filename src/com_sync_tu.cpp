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
//   00433460 LogChecksums 207-322
//
// The omitted line 200 SetLastWorldRandom owner is already an independent
// exact owner.  The next owner, 00433AD0 IsPlayerOutOfSync, is included for
// authentic context validation but remains a scratch owner.
//
// Exact anchors for the included owners are their original qualified symbols,
// body ranges, source bands, and positional checker matches.  All six use the
// default /nologo /c /O2 /Oy flags.  No EH frame occurs in these ranges.

#define COM_SYNC_TU_CONTEXT 1
#include "../include/com_sync_context.h"

#include "matching/00432FF0_RGE_Communications_Synchronize.cpp"
#include "matching/00433070_RGE_Communications_Synchronize.cpp"
#include "matching/004330A0_Add.cpp"
#include "matching/00433180_ValidateChecksums.cpp"
#include "matching/00433290_DoChecksum.cpp"
#include "matching/00433460_LogChecksums.cpp"
#include "scratch/00433AD0_IsPlayerOutOfSync.cpp"

#undef g_debuggingLog
#undef COM_SYNC_TU_CONTEXT
