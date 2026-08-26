// VA: 0042EF80 TCommunications_Handler::SendZoneMessage
// Com_hand.cpp:6766-6790

#include <string.h>

struct ZoneGuid {
    unsigned long data1;
    unsigned long data2;
    unsigned long data3;
    unsigned long data4;
};

#if !defined(COM_HAND_TU_CONTEXT)
void Log(void* log, const char* format, ...);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* message);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Lobby {
public:
    long SendZoneMessage(const char* msg, unsigned long param_2, void* zone_guid);
};
#endif // COM_HAND_TU_CONTEXT


class RGE_Prog_Info {
public:
    char gap_00[0x8F8];
    ZoneGuid zone_guid; // +0x8F8
};

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info; // +0x0C
};
#endif // COM_HAND_TU_CONTEXT


extern RGE_Base_Game* rge_base_game;

#if !defined(COM_HAND_TU_CONTEXT)
extern void* L;
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x1310];
    int LobbyLaunched;
    char gap_1314[0x14CC - 0x1314];
    RGE_Lobby* Lobby;          // +0x14CC
    char gap_14D0[0x10];
    RGE_Comm_Error* Err;       // +0x14E0

    int IsLobbyLaunched();
    int SendZoneMessage(char* msg, unsigned long param_2);
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::SendZoneMessage(char* msg, unsigned long param_2) {
    if (!this->LobbyLaunched) {
        Log(L, "NOT LOBBY LAUNCHED.  EXITING");
        return 0;
    }

    Log(L, "Sending zone message.");
    Log(L, "  >TX ZONE MSG (%u)", param_2);

    ZoneGuid zone_guid = rge_base_game->prog_info->zone_guid;

    long result = this->Lobby->SendZoneMessage(msg, param_2, (void*)&zone_guid);

    if (result == 0) {
        return 1;
    }

    this->Err->ShowReturn(result, "SendGameOptions");
    return 0;
}
