#ifndef AOE1_COM_SESS_CONTEXT_H
#define AOE1_COM_SESS_CONTEXT_H

// Authentic grouped context for C:\\msdev\\work\\age1_x1\\com_sess.cpp.
// The owner files are included by src/com_sess_tu.cpp in PDB source order.

struct _GUID {
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char c[8];
};

typedef _GUID GUID;

class IDirectPlay3 {};

extern IDirectPlay3* glpSERV;
extern GUID gServGUID;
extern GUID gAppGUID;
extern "C" void* __cdecl memset(void* dest, int val, unsigned int count);

class TCommunications_Handler {
public:
    char gap_00[0x12DC];
    GUID ServiceGUID;
    GUID ApplicationGUID;

    IDirectPlay3* GetDPInterface();
};

TCommunications_Handler* g_com_handler;

struct SEs {
    char Name[255];
    char Password[255];
    unsigned char gap_1FE[2];
    _GUID AppGUID;
    _GUID SessGUID;
    unsigned long CurrentPlayers;
    unsigned long MaxPlayers;
    unsigned long User1;
    unsigned long User2;
    unsigned long User3;
    unsigned long User4;
};

class TCommunications_Sessions {
public:
    union {
        int SessionCount;
        int field_0;
    };
    SEs Session[501];

    TCommunications_Sessions(TCommunications_Handler* handler);
    ~TCommunications_Sessions();
    void EraseInformation();
    int GetSessionCount();
    char* GetSessionName(int index);
    unsigned long GetSessionMaxPlayers(int index);
    unsigned long GetSessionCurrentPlayers(int index);
    _GUID* GetSessionGUID(int index);
    int IncSessionCount();
    int AddSession(GUID sessGUID, GUID appGUID,
                   unsigned long maxPlayers, unsigned long currentPlayers,
                   char* name, char* password,
                   unsigned long user1, unsigned long user2,
                   unsigned long user3, unsigned long user4);
    int Refresh();
    int IsEqualGuid(_GUID* guid1, _GUID* guid2);
};

struct DPSESSIONDESC2 {
    struct Fields {
        unsigned long dwSize;
        unsigned long dwFlags;
        GUID guidInstance;
        GUID guidApplication;
        unsigned long dwMaxPlayers;
        unsigned long dwCurrentPlayers;
        char* lpszSessionNameA;
        char* lpszPasswordA;
        char gap_38[8];
        unsigned long dwUser1;
        unsigned long dwUser2;
        unsigned long dwUser3;
        unsigned long dwUser4;
    };
    union {
        Fields fields;
        unsigned long a[20];
    };
};

#endif
