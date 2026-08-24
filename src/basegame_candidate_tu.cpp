// Candidate basegame.cpp wrapper.
//
// The owner list follows the PDB source-line order.  This first packet keeps
// only owners whose source has a complete, policy-safe local ABI.  Class
// owners remain omitted until the real RGE_Base_Game declaration is recovered.
// The 0041E7A0 owner is omitted because its implementation depends on a raw
// vtable call.  00423030 is omitted because its stdio declarations conflict
// with the standalone period declarations in the earlier logging owners.
//
// PDB module: C:\\msdev\\work\\age1_x1\\basegame.cpp
// Flags: /nologo /c /O2 /Oy /GX

#include <windows.h>
#include <io.h>
#include <new.h>
#include <string.h>

extern void* AppWnd;

#include "matching/00420580_enum_wnd_proc.cpp"
#include "matching/004205B0_enum_child_proc.cpp"
#include "matching/004205E0_enum_thread_proc.cpp"
#include "matching/00420610_close_thread_windows.cpp"

#include "matching/00423010_debug_random_reset.cpp"
#include "matching/004231E0_debug_timeGetTime.cpp"
