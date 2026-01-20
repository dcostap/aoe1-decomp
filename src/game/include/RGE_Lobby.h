#pragma once
#include "common.h"

struct RGE_Lobby {
    void* HostHWND;
    IDirectPlayLobby* glpDPL;
    IDirectPlayLobby2* glpDPL2;
    IDirectPlay2* glpDP;
    DPLCONNECTION* glpdplConnection;
    uchar lobby_game;
    RGE_Comm_Error* Err;
};
static_assert(sizeof(RGE_Lobby) == 0x1C, "Size mismatch");
