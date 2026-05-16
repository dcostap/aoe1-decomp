// VA: 00426D50 TCommunications_Handler::SendPlayerName (Com_hand.cpp:808-826, 105B)

#include <string.h>

struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned short* lpszShortName;
    unsigned short* lpszLongName;
};

class RGE_Comm_Error;

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
    DPNAME dpnSetName;
    memset(&dpnSetName, 0, sizeof(dpnSetName));
    dpnSetName.lpszLongName = (unsigned short*)(void*)this->MyFormalName;
    dpnSetName.lpszShortName = (unsigned short*)(void*)this->MyFriendlyName;
    dpnSetName.dwSize = 16;
    long result = ((long (__stdcall *)(void*, void*, DPNAME*, int))(*(void***)*(void**)0x62C5EC)[0x78 / 4])(*(void**)0x62C5EC, *(void**)0x62CF04, &dpnSetName, 2);
    this->Err->ShowReturn(result, "Send Player Name");
    return result;
}
