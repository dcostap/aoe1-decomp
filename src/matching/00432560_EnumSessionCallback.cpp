// 00432560 EnumSessionCallback
// pass DPSESSIONDESC2 GUIDs by value to AddSession; original builds argument copies directly on stack.

#ifndef COM_SESS_TU_CONTEXT
struct GUID {
    unsigned int d[4];
};

struct DPSESSIONDESC2 {
    unsigned long dwSize;                 // +00
    unsigned long dwFlags;                // +04
    GUID guidInstance;                    // +08
    GUID guidApplication;                 // +18
    unsigned long dwMaxPlayers;           // +28
    unsigned long dwCurrentPlayers;       // +2C
    char* lpszSessionNameA;               // +30
    char* lpszPasswordA;                  // +34
    char gap_38[8];
    unsigned long dwUser1;                // +40
    unsigned long dwUser2;                // +44
    unsigned long dwUser3;                // +48
    unsigned long dwUser4;                // +4C
};

class TCommunications_Sessions {
public:
    int AddSession(GUID sessGUID, GUID appGUID,
                   unsigned long maxPlayers, unsigned long currentPlayers,
                   char* name, char* password,
                   unsigned long user1, unsigned long user2,
                   unsigned long user3, unsigned long user4);
};
#endif

int __stdcall EnumSessionCallback(DPSESSIONDESC2* desc, unsigned long* timeout,
                                  unsigned long flags, void* context) {
    if (flags & 1) {
        return 0;
    }

#ifdef COM_SESS_TU_CONTEXT
    ((TCommunications_Sessions*)context)->AddSession(
        desc->fields.guidInstance,
        desc->fields.guidApplication,
        desc->fields.dwMaxPlayers,
        desc->fields.dwCurrentPlayers,
        desc->fields.lpszSessionNameA,
        desc->fields.lpszPasswordA,
        desc->fields.dwUser1,
        desc->fields.dwUser2,
        desc->fields.dwUser3,
        desc->fields.dwUser4);
#else
    ((TCommunications_Sessions*)context)->AddSession(
        desc->guidInstance,
        desc->guidApplication,
        desc->dwMaxPlayers,
        desc->dwCurrentPlayers,
        desc->lpszSessionNameA,
        desc->lpszPasswordA,
        desc->dwUser1,
        desc->dwUser2,
        desc->dwUser3,
        desc->dwUser4);
#endif
    return 1;
}
