#pragma once
#include "../common.h"
#include "com_err.h"

class RGE_Lobby : public RGE_Comm_Error {
public:
    IDirectPlayLobby2* glpDPL2;              // 0x8
    IDirectPlay2* glpDP;                     // 0xC
    DPLCONNECTION* glpdplConnection;         // 0x10
    uchar lobby_game;                        // 0x14
    RGE_Comm_Error* Err;                     // 0x18

    RGE_Lobby(void* param_1);
    virtual ~RGE_Lobby();
    virtual void ClearLobbyInfo();
    virtual int IsLobbyLaunched();
    virtual uchar CheckForLobbyLaunch(IDirectPlay3** param_1);
    virtual uchar IsThisHost();
    virtual uchar GetPlayerInfo(char** param_1);
    virtual uchar GetSessionInfo(DPSESSIONDESC2* param_1);
    virtual long SendZoneHandshakeResponse();
    virtual int GameIsOver();
    virtual long ReceiveZoneMessages();
    virtual long SendZoneMessage(char* param_1, ulong param_2, _GUID param_3);
};

static_assert(sizeof(RGE_Lobby) == 0x1C, "RGE_Lobby Size Mismatch");
static_assert(offsetof(RGE_Lobby, Err) == 0x18, "RGE_Lobby Offset Mismatch");

