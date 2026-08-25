// VA: 00442680 TDrawSystem::TDrawSystem
// PDB source: Drawarea.cpp lines 316-378
// Attempt log:
// rewrite 2026-05-19: implemented full observed constructor field initialization and _ASMSet_Shadowing call.

extern "C" void __cdecl _ASMSet_Shadowing(int, int, int, int);
#define system_ignore_size_messages (*(int*)0x62E63C)
#include "../drawarea_phase2_context.h"

TDrawSystem::TDrawSystem()
{
    this->Inst = 0;
    this->Wnd = 0;
    this->Pal = 0;
    this->DrawArea = 0;
    this->PrimaryArea = 0;
    this->DirDraw = 0;
    this->PrimarySurface = 0;
    this->Clipper = 0;
    this->DirDrawPal = 0;
    this->ChangedMode = 0;
    this->DrawType = 0;
    this->ScreenMode = 0;
    this->ScreenWidth = 0;
    this->ScreenHeight = 0;
    this->ColorBits = 8;
    this->Flags = 0;
    this->IsBanked = 0;
    this->CanSrcBlt = 0;
    this->DrawAreaList = 0;
    this->Restored = 0;
    this->ModeAvail640 = 0;
    this->ModeAvail800 = 0;
    this->ModeAvail1024 = 0;
    this->ModeAvail1280 = 0;
    this->ModeAvail320_200 = 0;
    this->ModeAvail320_240 = 0;
    this->ModeAvail320_200_16 = 0;
    this->ModeAvail320_240_16 = 0;
    this->ModeAvail640_16 = 0;
    this->ModeAvail800_16 = 0;
    this->ModeAvail1024_16 = 0;
    this->ErrorCode = 0;
    system_ignore_size_messages = 0;
    _ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
}

#undef system_ignore_size_messages
