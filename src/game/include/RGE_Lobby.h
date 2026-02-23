#pragma once
#include "common.h"
#include <dplay.h>

struct IDirectPlayLobby;
struct IDirectPlayLobby2;
struct RGE_Comm_Error;

struct RGE_Lobby {
    RGE_Lobby(void* host_hwnd);
    ~RGE_Lobby();

    void ClearLobbyInfo();
    int IsLobbyLaunched();
    uchar CheckForLobbyLaunch(IDirectPlay3** out_dp3);
    uchar IsThisHost();
    uchar GetPlayerInfo(char** out_name);
    uchar GetSessionInfo(DPSESSIONDESC2* out_desc);
    long SendZoneHandshakeResponse();
    int GameIsOver();
    long ReceiveZoneMessages();
    long SendZoneMessage(char* data, ulong data_size, _GUID to_player);

    void* HostHWND;
    IDirectPlayLobby* glpDPL;
    IDirectPlayLobby2* glpDPL2;
    IDirectPlay2* glpDP;
    DPLCONNECTION* glpdplConnection;
    uchar lobby_game;
    RGE_Comm_Error* Err;
};
static_assert(sizeof(RGE_Lobby) == 0x1C, "Size mismatch");
