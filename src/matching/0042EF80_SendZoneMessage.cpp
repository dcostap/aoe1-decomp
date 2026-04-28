// VA: 0042EF80 TCommunications_Handler::SendZoneMessage
// Com_hand.cpp:6766-6790

#include <string.h>

struct ZoneGuid {
    unsigned long data1;
    unsigned long data2;
    unsigned long data3;
    unsigned long data4;
};

void Log(void* log, const char* format, ...);

class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* message);
};

class RGE_Lobby {
public:
    long SendZoneMessage(const char* msg, unsigned long param_2, ZoneGuid zone_guid);
};

class RGE_Prog_Info {
public:
    char gap_00[0x8F8];
    ZoneGuid zone_guid; // +0x8F8
};

class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info; // +0x0C
};

extern RGE_Base_Game* rge_base_game;

extern void* L;

class TCommunications_Handler {
public:
    char gap_00[0x14CC];
    RGE_Lobby* Lobby;          // +0x14CC
    char gap_14D0[0x10];
    RGE_Comm_Error* Err;       // +0x14E0

    int IsLobbyLaunched();
    int SendZoneMessage(const char* msg, unsigned long param_2);
};

int TCommunications_Handler::SendZoneMessage(const char* msg, unsigned long param_2) {
    if (!IsLobbyLaunched()) {
        Log(L, "NOT LOBBY LAUNCHED.  EXITING");
        return 0;
    }

    Log(L, "Sending zone message.");
    Log(L, "  >TX ZONE MSG (%u)", param_2);

    ZoneGuid zone_guid = rge_base_game->prog_info->zone_guid;

    long result = this->Lobby->SendZoneMessage(msg, param_2, zone_guid);

    if (result == 0) {
        return 1;
    }

    this->Err->ShowReturn(result, "SendGameOptions");
    return 0;
}
