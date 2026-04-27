// first pass: erase cached info, build the 0x50-byte DPSESSIONDESC2 on the stack, then enumerate sessions through glpSERV
// tried direct struct zeroing, memset, and raw absolute loads; the remaining mismatch is the stack-frame / push-order basin around the session enum call
// leaving this in scratch for now because the behavior is right and the remaining difference is localized codegen drift
struct DPSESSIONDESC2 {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long guidInstance[4];
    unsigned long guidApplication[4];
    unsigned long dwMaxPlayers;
    unsigned long dwCurrentPlayers;
    unsigned long lpszSessionName;
    unsigned long lpszPassword;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
    unsigned long dwUser1;
    unsigned long dwUser2;
    unsigned long dwUser3;
    unsigned long dwUser4;
};

class TCommunications_Sessions {
public:
    void EraseInformation();
    int Refresh();
};

extern "C" void* __cdecl memset(void* dest, int val, unsigned int count);

int TCommunications_Sessions::Refresh() {
    DPSESSIONDESC2 desc;
    void* serv;

    this->EraseInformation();
    memset(&desc, 0, 0x50);

    desc.dwSize = 0x50;
    desc.guidApplication[0] = *(unsigned long*)0x62CF48;
    desc.guidApplication[1] = *(unsigned long*)0x62CF4C;
    desc.guidApplication[2] = *(unsigned long*)0x62CF50;
    desc.guidApplication[3] = *(unsigned long*)0x62CF54;
    desc.dwMaxPlayers = *(unsigned long*)0x62CF6C;

    serv = *(void**)0x62CF6C;
    return ((int (__stdcall *)(void*, DPSESSIONDESC2*, unsigned long, void*, TCommunications_Sessions*, unsigned long))(*(void***)serv)[0x34 / 4])(serv, &desc, 0, (void*)0x432560, this, 1);
}
