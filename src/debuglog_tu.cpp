// Authentic complete owner wrapper for C:\\msdev\\work\\age1_x1\\Debuglog.cpp.
//
// PDB-qualified owner order and boundaries:
//   00436220 TDebuggingLog::TDebuggingLog  lines 45-62
//   004362A0 TDebuggingLog::~TDebuggingLog lines 66-66
//   004362B0 TDebuggingLog::LogFile       lines 71-79
//   004362F0 TDebuggingLog::LogOutput     lines 82-90
//   00436330 TDebuggingLog::LogTimestamp  lines 93-100
//   00436360 TDebuggingLog::LogDateTimestamp lines 103-110
//   004363A0 TDebuggingLog::Time           lines 114-129
//   00436430 TDebuggingLog::FlushToDisk    lines 132-139
//   00436470 TDebuggingLog::LogSequence    lines 142-152
//   004364B0 TDebuggingLog::OpenLog        lines 156-191
//   004365A0 TDebuggingLog::FlushLog       lines 194-198
//   004365C0 TDebuggingLog::CloseLog       lines 201-213
//   00436610 TDebuggingLog::Log            lines 216-296
//   00436810 TDebuggingLog::YesOrNo        lines 300-305
//
// Exact anchors are the constructor at 00436220, OpenLog at 004364B0,
// FlushLog at 004365A0, Log at 00436610, and YesOrNo at 00436810. The Log
// body owns [00436610,00436804), including its variadic stack receiver,
// vsprintf buffer, date and sequence prefixes, output call, file write, and
// flush cleanup. No generated or padding owner is present in this span.
//
// The canonical TDebuggingLog surface is include/debuglog_context.h. It is
// the PDB type surface: 13 fields and size 0x7B0. Every owner appears once.
// Log is the variadic public member and YesOrNo is the protected member. The
// owner sources use these qualified members, not free-function ABI shims.
// This file is the complete safe owner wrapper registered as the debuglog
// translation unit in config/translation_units.json.
//
// One module flag set: config/flags/default.rsp (/nologo /c /O2 /Oy).

#define DEBUGLOG_CANONICAL_TU 1
#include "../include/debuglog_context.h"

#include "matching/00436220_TDebuggingLog.cpp"
#include "matching/004362A0_TDebuggingLog.cpp"
#include "matching/004362B0_LogFile.cpp"
#include "matching/004362F0_LogOutput.cpp"
#include "matching/00436330_LogTimestamp.cpp"
#include "matching/00436360_LogDateTimestamp.cpp"
#include "matching/004363A0_Time.cpp"
#include "matching/00436430_FlushToDisk.cpp"
#include "matching/00436470_LogSequence.cpp"
#include "matching/004364B0_OpenLog.cpp"
#include "matching/004365A0_FlushLog.cpp"
#include "matching/004365C0_CloseLog.cpp"
#include "matching/00436610_Log.cpp"
#include "matching/00436810_YesOrNo.cpp"

#undef DEBUGLOG_CANONICAL_TU
