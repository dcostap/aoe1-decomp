// 00426D50 TCommunications_Handler::SendPlayerName (Com_hand.cpp:808-826, 105B)
// 96/105 bytes. VC5 dead-store-elimination / scheduling differences.
//
// Our VC5 optimizes away 3 of 4 zero stores (keeps only dwFlags=0 as the
// sole survivor) and schedules all field stores before call pushes. The
// 1998 build keeps all 4 zero stores and interleaves field stores with
// pushes, using [esp+N] to access different DPNAME fields as pushes shift
// the stack. Cannot replicate from C source.
//
// Correct struct layout:
//   DPNAME at [esp+0..+0Ch] before pushes.
//   lpszLongName = this->MyFormalName (+0x1179)
//   lpszShortName = this->MyFriendlyName (+0x10F8)
//   dwSize = 0x10

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
    dpnSetName.dwSize = 0x10;
    long result = ((long (__stdcall *)(void*, void*, void*, int))(*(void***)*(void**)0x62C5EC)[0x78 / 4])(*(void**)0x62C5EC, *(void**)0x62CF04, &dpnSetName, 2);
    this->Err->ShowReturn(result, "Send Player Name");
    return result;
}
