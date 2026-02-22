#pragma once
#include "common.h"

struct IDirectPlayLobby;
struct IDirectPlayLobby2;
struct IDirectPlay2;
struct _DPLCONNECTION;

struct RGE_Lobby {
    void* HostHWND;
    IDirectPlayLobby* glpDPL;
    IDirectPlayLobby2* glpDPL2;
    IDirectPlay2* glpDP;
    _DPLCONNECTION* glpdplConnection;
    uchar lobby_game;
    RGE_Comm_Error* Err;
};
static_assert(sizeof(RGE_Lobby) == 0x1C, "Size mismatch");
