// attempt 1: 127/127 but 93.7% diff - VC5 stack frame + rep movsd for GUID copy
// attempt 2: 80/127 - pass GUID pointers directly, no copy
// attempt 3: same 93.7% - reversed GUID copy order
// attempt 4: 127/127 but 95.3% - 16-byte GUID shrinks frame to 0x20
// attempt 5: 127/127 but 92.1% - if (!(param_3 & 1)) inverted test
// attempt 6: same 92.1% - return 1 inside if-block
// attempt 7: 127/127 but 93.7% - (unsigned char) cast for byte test
// BLOCKER: original has NO stack frame (test byte [esp+0Ch],1 direct), VC5 always
//   generates 'mov al,[esp+0Ch]; sub esp,28h; test al,1' for functions with locals.
//   Original uses push esi + push 8 dwords + sub esp,10h twice (manual stack mgmt).
//   VC5 uses sub esp,28h + push edi/esi + push 8 dwords + rep movsd for GUID copy.
//   Core logic correct: early return 0 if (param_3&1), copies GUIDs, calls AddSession,
//   returns 1. Left in scratch per 10-probe rule.

struct GUID {
    unsigned int Data1;
    unsigned int Data2;
    unsigned int Data3;
    unsigned int Data4_0, Data4_1;
};

struct DPSESSIONDESC2 {
    unsigned long dwSize;
    unsigned long dwFlags;
    GUID guidSession;
    GUID guidApplication;
    unsigned long dwMaxPlayers;
    unsigned long dwCurrentPlayers;
    char* lpszSessionNameA;
    char* lpszPasswordA;
    unsigned long dwUser1;
    unsigned long dwUser2;
    unsigned long dwUser3;
    unsigned long dwUser4;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
};

class TCommunications_Sessions {
public:
    int SessionCount;
    char gap_04[0x257C];

public:
    int AddSession(GUID* sessGUID, GUID* appGUID,
                   unsigned long maxPlayers, unsigned long currentPlayers,
                   char* name, char* password,
                   unsigned long user1, unsigned long user2,
                   unsigned long user3, unsigned long user4);
};

int __stdcall EnumSessionCallback(DPSESSIONDESC2* param_1, unsigned long* param_2,
                                   unsigned long param_3, void* param_4) {
    if ((unsigned char)param_3 & 1) {
        return 0;
    }

    GUID sg = param_1->guidSession;
    GUID ag = param_1->guidApplication;

    ((TCommunications_Sessions*)param_4)->AddSession(&sg, &ag,
        param_1->dwMaxPlayers, param_1->dwCurrentPlayers,
        param_1->lpszSessionNameA, param_1->lpszPasswordA,
        param_1->dwUser3, param_1->dwUser4,
        param_1->dwReserved1, param_1->dwReserved2);

    return 1;
}
