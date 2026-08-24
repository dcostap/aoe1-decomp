// 0042F430 CheckForLobbyLaunch
// Natural typed DirectPlay lobby reconstruction.
// Attempt log:
// - Baseline used named RGE_Lobby fields, DPLCONNECTION ownership, and typed
//   DirectPlay lobby methods. It had the correct call set but missed the
//   reserved local stack home and was 8 bytes short.
// - ABI probe corrected IDirectPlayLobby inheritance. This aligned all 21
//   calls and the GetConnectionSettings, SetConnectionSettings, and Connect
//   vtable slots.
// - Liveness probe declared dwSize before parameter setup. VC5 then reused
//   the reserved local home and produced the original 514-byte body.
// - Final ABI audit used IDirectPlay3*& and the SDK DPNAME union surface.
//   The natural source matched all bytes with default flags.

#ifndef COM_LOBY_CONTEXT
struct GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

class TDebuggingLog {
public:
    void Log(char* format, ...);
};

extern TDebuggingLog* L;
extern "C" const GUID IID_IDirectPlayLobby2A;
extern "C" const GUID IID_IDirectPlay3A;

class RGE_Comm_Error {
public:
    void ShowReturn(long result, char* message);
};

struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    union {
        unsigned short* lpszShortName;
        char* lpszShortNameA;
    };
    union {
        unsigned short* lpszLongName;
        char* lpszLongNameA;
    };
};

struct DPSESSIONDESC2 {
    unsigned long dwSize;
    unsigned long dwFlags;
    GUID guidInstance;
    GUID guidApplication;
    unsigned long dwMaxPlayers;
    unsigned long dwCurrentPlayers;
    unsigned short* lpszSessionName;
    unsigned short* lpszPassword;
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
    virtual long __stdcall RunApplication(unsigned long flags, unsigned long* application,
                                          DPLCONNECTION* connection, void* event) = 0;
    virtual long __stdcall SendLobbyMessage(unsigned long flags, unsigned long application,
                                            void* message, unsigned long messageSize) = 0;
    virtual long __stdcall SetConnectionSettings(unsigned long application,
                                                 unsigned long flags,
                                                 DPLCONNECTION* connection) = 0;
    virtual long __stdcall SetLobbyMessageEvent(unsigned long application,
                                                unsigned long event) = 0;
};

class IDirectPlayLobby2 : public IDirectPlayLobby {
};

class IDirectPlay3 : public IDirectPlay2 {
};

long __stdcall DirectPlayLobbyCreateA(void* guid, IDirectPlayLobby** lobby,
                                      void* unknown, void* reserved,
                                      unsigned long flags);
void* __cdecl operator_new(unsigned int size);

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
    unsigned char gap_15[3];
    RGE_Comm_Error* Err;

    void ClearLobbyInfo(void);
    unsigned char CheckForLobbyLaunch(IDirectPlay3*& param_1);
};
#endif

unsigned char RGE_Lobby::CheckForLobbyLaunch(IDirectPlay3*& param_1) {
    unsigned long dwSize = 0x29;
    param_1 = 0;
    ClearLobbyInfo();

    long result = DirectPlayLobbyCreateA(0, &this->glpDPL, 0, 0, 0);
    this->Err->ShowReturn(result, "Lobby Create");
    if (result < 0) {
        return 0;
    }

    this->glpDPL->QueryInterface(&IID_IDirectPlayLobby2A,
                                 (void**)&this->glpDPL2);
    if (this->glpDPL2 == 0) {
        return 0;
    }

    this->glpDPL2->GetConnectionSettings(0, 0, &dwSize);
    this->glpdplConnection = (DPLCONNECTION*)operator_new(dwSize + 1);
    result = this->glpDPL2->GetConnectionSettings(0, this->glpdplConnection,
                                                  &dwSize);
    if (result < 0) {
        this->lobby_game = 0;
        return 0;
    }

    L->Log("LOBBY LAUNCHED GAME.");

    this->glpdplConnection->lpSessionDesc->dwFlags = 0x44;
    this->glpdplConnection->lpSessionDesc->dwMaxPlayers = 9;

    this->glpDPL2->SetConnectionSettings(0, 0, this->glpdplConnection);
    L->Log("Pre-connect");

    result = this->glpDPL2->Connect(0, &this->glpDP, 0);
    L->Log("Post Connect");
    if (result < 0) {
        if (result == 0x887700F0) {
            return 0xFF;
        }
        L->Log("Failed to connect!");
        this->Err->ShowReturn(result, "Connect");
        return 0xFF;
    }

    L->Log("Pre QI");
    result = this->glpDP->QueryInterface(&IID_IDirectPlay3A,
                                         (void**)&param_1);
    this->Err->ShowReturn(result, "Lobby QI");
    if (result < 0) {
        L->Log("Queryinterface failed.");
        return 0xFF;
    }

    L->Log("Calling enumeration of players.");
    param_1->EnumPlayers(0, EnumPlayersCallbackLobby, this, 0);
    L->Log("Post ENUMP");
    this->lobby_game = 1;
    return 1;
}
