#ifndef AOE1_COM_LOBY_CONTEXT_H
#define AOE1_COM_LOBY_CONTEXT_H

// Authentic shared declarations for C:\\msdev\\work\\age1_x1\\com_loby.cpp.
// The module uses one RGE_Lobby object at 0x1c bytes.  The DirectPlay
// interfaces below keep the observed virtual slots and calling conventions.

struct _GUID {
    unsigned long Data1;
    unsigned long Data2;
    unsigned long Data3;
    unsigned long Data4;
};
typedef _GUID GUID;

extern const GUID GUID_NULL;
extern const GUID IID_IDirectPlayLobby2A;
extern const GUID IID_IDirectPlay3A;

struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    char* lpszShortName;
    char* lpszLongName;
};

struct DPSESSIONDESC2 {
    unsigned long dwSize;
    unsigned long dwFlags;
    GUID guidInstance;
    GUID guidApplication;
    unsigned long dwMaxPlayers;
    unsigned long dwCurrentPlayers;
    char* lpszSessionName;
    char* lpszPassword;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
    unsigned long dwUser1;
    unsigned long dwUser2;
    unsigned long dwUser3;
    unsigned long dwUser4;
};

struct DPLCONNECTION {
    unsigned long dwSize;
    unsigned long dwFlags;
    DPSESSIONDESC2* lpSessionDesc;
    DPNAME* lpPlayerName;
    GUID guidSP;
    void* lpAddress;
    unsigned long dwAddressSize;
};

typedef int (__stdcall *DPENUMPLAYERSCALLBACK)(unsigned long, unsigned long,
                                                DPNAME*, unsigned long, void*);

class TDebuggingLog {
public:
    void Log(char* format, ...);
};
extern TDebuggingLog* L;
extern char _s_Release[];

class RGE_Comm_Error {
public:
    void* HostHWND;
    long LastReportedError;

    RGE_Comm_Error(void* hwnd);
    ~RGE_Comm_Error();
    void ShowReturn(long result, char* message);
};

class IUnknown {
public:
    virtual long __stdcall QueryInterface(const GUID* iid, void** object) = 0;
    virtual unsigned long __stdcall AddRef(void) = 0;
    virtual unsigned long __stdcall Release(void) = 0;
};

class IDirectPlay2 : public IUnknown {
public:
    virtual long __stdcall AddPlayerToGroup(unsigned long group, unsigned long player) = 0;
    virtual long __stdcall Close(void) = 0;
    virtual long __stdcall CreateGroup(void* id, DPNAME* name, void* data,
                                       unsigned long size, unsigned long flags) = 0;
    virtual long __stdcall CreatePlayer(void* id, DPNAME* name, void* event,
                                        void* data, unsigned long size,
                                        unsigned long flags) = 0;
    virtual long __stdcall DeletePlayerFromGroup(unsigned long group,
                                                 unsigned long player) = 0;
    virtual long __stdcall DestroyGroup(unsigned long group) = 0;
    virtual long __stdcall DestroyPlayer(unsigned long player) = 0;
    virtual long __stdcall EnumGroupPlayers(unsigned long group, void* guid,
                                             DPENUMPLAYERSCALLBACK callback,
                                             void* context, unsigned long flags) = 0;
    virtual long __stdcall EnumGroups(void* guid, void* callback, void* context,
                                      unsigned long flags) = 0;
    virtual long __stdcall EnumPlayers(void* guid, DPENUMPLAYERSCALLBACK callback,
                                       void* context, unsigned long flags) = 0;
};

class IDirectPlay3 : public IDirectPlay2 {
};

class IDirectPlayLobby : public IUnknown {
public:
    virtual long __stdcall Connect(unsigned long flags, IDirectPlay2** dplay,
                                   void* unknown) = 0;
    virtual long __stdcall CreateAddress(const GUID* serviceProvider,
                                         const GUID* dataType, const void* data,
                                         unsigned long dataSize, void* address,
                                         unsigned long* addressSize) = 0;
    virtual long __stdcall EnumAddress(void* callback, const void* address,
                                       unsigned long addressSize, void* context) = 0;
    virtual long __stdcall EnumAddressTypes(void* callback, const GUID* application,
                                            void* context, unsigned long flags) = 0;
    virtual long __stdcall EnumLocalApplications(void* callback, void* context,
                                                 unsigned long flags) = 0;
    virtual long __stdcall GetConnectionSettings(unsigned long application,
                                                  void* data,
                                                  unsigned long* dataSize) = 0;
    virtual long __stdcall ReceiveLobbyMessage(unsigned long flags,
                                               unsigned long application,
                                               unsigned long* messageFlags,
                                               void* message,
                                               unsigned long* messageSize) = 0;
    virtual long __stdcall GetLobbyMessage(unsigned long flags, void* message,
                                           unsigned long* messageSize) = 0;
    virtual long __stdcall SendLobbyMessage(unsigned long flags,
                                            unsigned long application,
                                            void* message,
                                            unsigned long messageSize) = 0;
    virtual long __stdcall SetConnectionSettings(unsigned long application,
                                                 unsigned long flags,
                                                 DPLCONNECTION* connection) = 0;
    virtual long __stdcall SetLobbyMessageEvent(unsigned long application,
                                                unsigned long event) = 0;
    virtual long __stdcall RunApplication(unsigned long flags,
                                          unsigned long* application,
                                          DPLCONNECTION* connection,
                                          void* event) = 0;
};

class IDirectPlayLobby2 : public IDirectPlayLobby {
};

long __stdcall DirectPlayLobbyCreateA(void* guid, IDirectPlayLobby** lobby,
                                      void* unknown, void* reserved,
                                      unsigned long flags);
void* __cdecl operator new(unsigned int size);
void* __cdecl operator_new(unsigned int size);
void __cdecl operator delete(void* ptr);
extern "C" void __cdecl operator_delete(void* ptr);

int __stdcall EnumPlayersCallbackLobby(unsigned long, unsigned long, DPNAME*,
                                       unsigned long, void*);

class RGE_Lobby {
public:
    void* HostHWND;
    IDirectPlayLobby* glpDPL;
    IDirectPlayLobby2* glpDPL2;
    IDirectPlay2* glpDP;
    DPLCONNECTION* glpdplConnection;
    unsigned char lobby_game;
    unsigned char _pad_15[3];
    RGE_Comm_Error* Err;

    RGE_Lobby(void* hwnd);
    ~RGE_Lobby();
    void ClearLobbyInfo(void);
    int IsLobbyLaunched(void);
    unsigned char CheckForLobbyLaunch(IDirectPlay3*& dplay);
    unsigned char IsThisHost(void);
    unsigned char GetPlayerInfo(char** out);
    unsigned char GetSessionInfo(DPSESSIONDESC2* out);
    long SendZoneHandshakeResponse(void);
    int GameIsOver(void);
    long ReceiveZoneMessages(void);
    long SendZoneMessage(char* data, unsigned long dataSize, _GUID guid);
};

#endif
