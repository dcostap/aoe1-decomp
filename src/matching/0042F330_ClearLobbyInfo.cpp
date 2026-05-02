// VA: 0042F330 RGE_Lobby::ClearLobbyInfo (64 B)
// PDB source: com_loby.cpp lines 53-77

extern "C" void __cdecl operator_delete(void*);

struct IDirectPlayLobby2Vtbl {
    void* QueryInterface;
    void* AddRef;
    long (__stdcall* Release)(void* self);
};

struct IDirectPlayLobby2 {
    IDirectPlayLobby2Vtbl* lpVtbl;
};

class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* msg);
};

extern char _s_Release[];

class RGE_Lobby {
public:
    void ClearLobbyInfo(void);
    char gap_00[0x08];
    IDirectPlayLobby2* glpDPL2;    // +0x08
    void* glpDP;                    // +0x0C
    void* glpdplConnection;         // +0x10
    unsigned char lobby_game;       // +0x14
    char gap_15[0x03];
    RGE_Comm_Error* Err;            // +0x18
};

void RGE_Lobby::ClearLobbyInfo(void) {
    if (this->glpdplConnection != 0) {
        operator_delete(this->glpdplConnection);
        this->glpdplConnection = 0;
    }
    if (this->glpDPL2 != 0) {
        IDirectPlayLobby2* pLobby = this->glpDPL2;
        long result = pLobby->lpVtbl->Release(pLobby);
        this->Err->ShowReturn(result, _s_Release);
        this->glpDPL2 = 0;
    }
    this->lobby_game = 0;
    this->glpDP = 0;
}
