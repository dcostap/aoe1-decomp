// 00426D50 TCommunications_Handler::SendPlayerName (Com_hand.cpp:808-826, 105B)
//
// Status: STUCK — VC5 dead-store elimination + store scheduling mismatch.
//
// Blocker: VC5's optimizer makes different decisions than the 1998 build for:
// 1. Dead-store elimination: eliminates 2+ of 4 zero-initializer stores
//    (fields set to 0 then immediately overwritten).
// 2. Store scheduling: original interleaves struct field assignments with
//    argument pushes (stack offsets shift dynamically). Rebuilt schedules
//    all field stores before pushes.
// 3. Prologue register save order (esi/edi/xor order differs).
// Best result: 60.00% positional / 53.33% edit (memset variant).
// Far too broad for accepted_drift.
//
// Attempt log:
// - Pre-existing passes: 15+ variants per pass (Store scheduling, volatile,
//   array/dword forms, brace-init, explicit zeros). Best: 86.67% (baseline).
// - 2026-05-12 (this pass):
//   V1: memset + individual field stores (60.00%)
//   V2: Explicit individual zero assignments (96 bytes, too short)
//   V3: Restored baseline brace-init (86.67%)
// No accepted_drift: 60%+ positional diff is structural.

#include <string.h>

class RGE_Comm_Error;

struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned short* lpszShortName;
    unsigned short* lpszLongName;
};

class TCommunications_Handler {
public:
    char pad_000[0x10F8];
    char MyFriendlyName[129];
    char MyFormalName[129];
    char pad_11FA[0x2E6];
    RGE_Comm_Error* Err;

    long SendPlayerName();
};

class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* msg);
};

long TCommunications_Handler::SendPlayerName()
{
    DPNAME dpnSetName = {0};
    dpnSetName.lpszLongName = (unsigned short*)(void*)this->MyFormalName;
    dpnSetName.lpszShortName = (unsigned short*)(void*)this->MyFriendlyName;
    dpnSetName.dwSize = 16;
    long result = ((long (__stdcall *)(void*, void*, void*, int))(*(void***)*(void**)0x62C5EC)[0x78 / 4])(*(void**)0x62C5EC, *(void**)0x62CF04, &dpnSetName, 2);
    this->Err->ShowReturn(result, "Send Player Name");
    return result;
}
