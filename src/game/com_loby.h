#pragma once
#include "common.h"

class RGE_Lobby {
public:
    void* HostHWND;                          // 0x0
    IDirectPlayLobby* glpDPL;                // 0x4
    IDirectPlayLobby2* glpDPL2;              // 0x8
    IDirectPlay2* glpDP;                     // 0xC
    DPLCONNECTION* glpdplConnection;         // 0x10
    uchar lobby_game;                        // 0x14
    RGE_Comm_Error* Err;                     // 0x18

    RGE_Lobby(void* param_1);
    ~RGE_Lobby();
    void ClearLobbyInfo();
    int IsLobbyLaunched();
    uchar CheckForLobbyLaunch(IDirectPlay3** param_1);
    uchar IsThisHost();
    uchar GetPlayerInfo(char** param_1);
    uchar GetSessionInfo(DPSESSIONDESC2* param_1);
    long SendZoneHandshakeResponse();
    int GameIsOver();
    long ReceiveZoneMessages();
    long SendZoneMessage(char* param_1, ulong param_2, _GUID param_3);
};

static_assert(sizeof(RGE_Lobby) == 0x1C, "RGE_Lobby Size Mismatch");

