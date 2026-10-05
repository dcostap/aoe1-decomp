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
    RGE_Lobby(void* Host);
    ~RGE_Lobby();
    void ClearLobbyInfo(void);
    int IsLobbyLaunched(void);
    unsigned char CheckForLobbyLaunch(IDirectPlay3*& direct_play);
    unsigned char IsThisHost(void);
    unsigned char GetPlayerInfo(char** player_name);
    unsigned char GetSessionInfo(DPSESSIONDESC2& info);
    long SendZoneHandshakeResponse(void);
    int GameIsOver(void);
    long ReceiveZoneMessages(void);
    long SendZoneMessage(char* Data, unsigned long dwSize, _GUID guid);
};

#endif
