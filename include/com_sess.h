#ifndef AOE1_COM_SESS_H
#define AOE1_COM_SESS_H

struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

typedef _GUID GUID;

struct DPSESSIONDESC2;
typedef int (__stdcall *DPENUMSESSIONSCALLBACK)(DPSESSIONDESC2*,
                                                  unsigned long*,
                                                  unsigned long,
                                                  void*);

class IUnknown {
public:
    virtual long __stdcall QueryInterface(const GUID* iid, void** object) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

class IDirectPlay2 : public IUnknown {
public:
    virtual long __stdcall AddPlayerToGroup(unsigned long group,
                                            unsigned long player) = 0;
    virtual long __stdcall Close() = 0;
    virtual long __stdcall CreateGroup() = 0;
    virtual long __stdcall CreatePlayer() = 0;
    virtual long __stdcall DeletePlayerFromGroup(unsigned long group,
                                                 unsigned long player) = 0;
    virtual long __stdcall DestroyGroup(unsigned long group) = 0;
    virtual long __stdcall DestroyPlayer(unsigned long player) = 0;
    virtual long __stdcall EnumGroupPlayers() = 0;
    virtual long __stdcall EnumGroups() = 0;
    virtual long __stdcall EnumPlayers() = 0;
    virtual long __stdcall EnumSessions(DPSESSIONDESC2* desc,
                                        unsigned long timeout,
                                        DPENUMSESSIONSCALLBACK callback,
                                        void* context,
                                        unsigned long flags) = 0;
};

class IDirectPlay3 : public IDirectPlay2 {
};

class TCommunications_Handler {
public:
    char data_0000[0x12DC];
    GUID ServiceGUID;
    GUID ApplicationGUID;

    IDirectPlay3* GetDPInterface();
};

struct SEs {
    char Name[255];
    char Password[255];
    unsigned char pad_01FE[2];
    GUID AppGUID;
    GUID SessGUID;
    unsigned long CurrentPlayers;
    unsigned long MaxPlayers;
    unsigned long User1;
    unsigned long User2;
    unsigned long User3;
    unsigned long User4;
};

struct DPSESSIONDESC2 {
    unsigned long dwSize;
    unsigned long dwFlags;
    GUID guidInstance;
    GUID guidApplication;
    unsigned long dwMaxPlayers;
    unsigned long dwCurrentPlayers;
    char* lpszSessionNameA;
    char* lpszPasswordA;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
    unsigned long dwUser1;
    unsigned long dwUser2;
    unsigned long dwUser3;
    unsigned long dwUser4;
};

class TCommunications_Sessions {
public:
    int SessionCount;
    SEs Session[501];
    GUID glpGuid;
    IDirectPlay2* glpIDC;

    TCommunications_Sessions(TCommunications_Handler* handler);
    ~TCommunications_Sessions();

private:
    void EraseInformation();

public:
    int GetSessionCount();
    char* GetSessionName(int index);
    unsigned long GetSessionMaxPlayers(int index);
    unsigned long GetSessionCurrentPlayers(int index);
    GUID* GetSessionGUID(int index);
    int IncSessionCount();
    int AddSession(GUID sessGUID, GUID appGUID,
                   unsigned long maxPlayers, unsigned long currentPlayers,
                   char* name, char* password,
                   unsigned long user1, unsigned long user2,
                   unsigned long user3, unsigned long user4);
    int Refresh();
    int IsEqualGuid(GUID* guid1, GUID* guid2);
};

extern IDirectPlay3* glpSERV;
extern GUID gServGUID;
extern GUID gAppGUID;
extern TCommunications_Handler* g_com_handler;

int __stdcall EnumSessionCallback(DPSESSIONDESC2* desc,
                                 unsigned long* timeout,
                                 unsigned long flags,
                                 void* context);

typedef char com_sess_guid_size_check[(sizeof(GUID) == 0x10) ? 1 : -1];
typedef char com_sess_entry_size_check[(sizeof(SEs) == 0x238) ? 1 : -1];
typedef char com_sess_desc_size_check[(sizeof(DPSESSIONDESC2) == 0x50) ? 1 : -1];
typedef char com_sess_size_check[(sizeof(TCommunications_Sessions) == 0x457B0) ? 1 : -1];

#endif
