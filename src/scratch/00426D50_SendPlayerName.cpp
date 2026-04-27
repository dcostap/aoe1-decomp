// first pass: stack-temp DPNAME plus logging of the returned HRESULT/result
// probe 1: direct member offsets were structurally right but still optimized into the smaller basin
// probe 2: keeping local_4 before the DPNAME did not change the 96-byte basin; the remaining mismatch is the stack temp/call-shape basin around the DPNAME setup and DirectPlay vtable call
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
    char pad_127A[0x26E];
    RGE_Comm_Error* Err;

    long SendPlayerName();
};

class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* msg);
};

extern const char s_Send_Player_Name[];

long TCommunications_Handler::SendPlayerName() {
    long local_4;
    DPNAME dpnSetName;
    long result;

    local_4 = 0;
    dpnSetName.dwSize = 0;
    dpnSetName.dwFlags = 0;
    dpnSetName.lpszShortName = 0;
    dpnSetName.lpszLongName = 0;
    dpnSetName.lpszShortName = (unsigned short*)(this->MyFormalName);
    dpnSetName.lpszLongName = (unsigned short*)(this->MyFriendlyName);
    dpnSetName.dwSize = 0x10;

    result = (long)((int (__stdcall *)(void*, void*, DPNAME*, int))(*(void***)*(void**)0x62C5EC)[0x78 / 4])(*(void**)0x62C5EC, *(void**)0x62CF04, &dpnSetName, 2);
    this->Err->ShowReturn(result, s_Send_Player_Name);
    return result;
}
