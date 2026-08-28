#ifndef AOE1_COM_LOBY_H
#define AOE1_COM_LOBY_H

#include <windows.h>
#include "com_err.h"
#include "../third_party/directplay/include/dplay.h"
#include "../third_party/directplay/include/dplobby.h"

class RGE_Lobby {
protected:
    void* HostHWND;
    IDirectPlayLobby* glpDPL;
    IDirectPlayLobby2* glpDPL2;
    IDirectPlay2* glpDP;
    DPLCONNECTION* glpdplConnection;
    unsigned char lobby_game;
    RGE_Comm_Error* Err;

public:
    RGE_Lobby(void* hwnd);
    ~RGE_Lobby();
    void ClearLobbyInfo(void);
    int IsLobbyLaunched(void);
    unsigned char CheckForLobbyLaunch(IDirectPlay3*& dplay);
    unsigned char IsThisHost(void);
    unsigned char GetPlayerInfo(char** out);
    unsigned char GetSessionInfo(DPSESSIONDESC2& out);
    long SendZoneHandshakeResponse(void);
    int GameIsOver(void);
    long ReceiveZoneMessages(void);
    long SendZoneMessage(char* data, unsigned long dataSize, _GUID guid);
};

#endif
