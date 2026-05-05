// 004324F0 TCommunications_Sessions::Refresh()
// Source: com_sess.cpp lines 161-186
// Size: 103 bytes, 32 asm lines

// 5 attempts. Best: 75.7% positional diff.
// Prologue, EraseInformation call, rep stosd (memset via for loop),
// GUID field loads from absolute addresses, and vcall structure all work.
// 
// Remaining diff: VC5 interleaves the first vcall arg push (`push 1`)
// inside the rep stosd setup sequence (between lea edi and rep stosd),
// while the original places it after all GUID loads. Also different
// scheduling of GUID stores relative to push arguments.
//
// This is a VC5 instruction scheduling basin — the push of a compile-time
// constant (1) can be freely moved into any dead slot.
// Left in scratch.

extern "C" void* __cdecl memset(void* dest, int val, unsigned int count);

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

int TCommunications_Sessions::Refresh() {
    DPSESSIONDESC2 desc;
    int i;

    this->EraseInformation();
    for (i = 0; i < 20; i++) {
        ((unsigned long*)&desc)[i] = 0;
    }

    desc.guidApplication[0] = *(unsigned long*)0x62CF48;
    desc.guidApplication[1] = *(unsigned long*)0x62CF4C;
    desc.guidApplication[2] = *(unsigned long*)0x62CF50;
    desc.guidApplication[3] = *(unsigned long*)0x62CF54;

    {
        void* serv = *(void**)0x62CF6C;
        desc.dwSize = 0x50;
        return ((int (__stdcall*)(void*, DPSESSIONDESC2*, unsigned long, void*, TCommunications_Sessions*, unsigned long))(*(void***)serv)[13])(serv, &desc, 0, (void*)0x432560, this, 1);
    }
}
