class DPLCONNECTION;

class IDirectPlayLobby2 {
public:
    virtual long QueryInterface(void*, void**) = 0;
    virtual unsigned long AddRef() = 0;
    virtual unsigned long Release() = 0;
};

class IDirectPlay2;

class RGE_Comm_Error {
public:
    void ShowReturn(long param_1, char* param_2);
};

class RGE_Lobby {
public:
    void* HostHWND;
    void* glpDPL;
    IDirectPlayLobby2* glpDPL2;
    IDirectPlay2* glpDP;
    DPLCONNECTION* glpdplConnection;
    unsigned char lobby_game;
    unsigned char _pad_0[0x3];
    RGE_Comm_Error* Err;

    void ClearLobbyInfo(void);
};

// tried direct ifs, a local pointer temp, and an assignment-in-condition form; mismatch stayed at
// the glpDPL2 null-check codegen (eax vs ecx) on the second branch

void RGE_Lobby::ClearLobbyInfo(void) {
    if (this->glpdplConnection != 0) {
        operator delete(this->glpdplConnection);
        this->glpdplConnection = 0;
    }

    IDirectPlayLobby2* pIVar1;
    long lVar2;

    if ((pIVar1 = this->glpDPL2) != 0) {
        lVar2 = pIVar1->Release();
        this->Err->ShowReturn(lVar2, (char*)"Release");
        this->glpDPL2 = 0;
    }

    this->lobby_game = 0;
    this->glpDP = 0;
}
