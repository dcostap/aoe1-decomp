// TCommunications_Handler::CloseSession
// VA: 0042E920
// Com_hand.cpp:6467-6487
// 141 bytes

#include "../../include/game_globals.h"

extern void* L;
extern "C" void __cdecl Log(void* log, char* fmt, ...);

class RGE_Comm_Error {
public:
    void ShowReturn(long result, char* msg);
};

struct IDirectPlay3Vtbl {
    char gap_00[0x10];
    long (__stdcall* fn04)(void* thisptr);
};

struct IDirectPlay3 {
    IDirectPlay3Vtbl* vtbl;
};

class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;
    char gap_12DA[0x12FC - 0x12DA];
    _GUID SessionGUID;
    char gap_130C[0x1318 - 0x130C];
    _GUID NullGUID;
    char gap_1328[0x14E0 - 0x1328];
    RGE_Comm_Error* Err;
    char gap_14E4[0x1720 - 0x14E4];
    int LastTurnAck[1];

    long CloseSession(void);
};

long TCommunications_Handler::CloseSession(void) {
    long result = 0;

    Log(L, "Close Session Call");

    IDirectPlay3* dp = (IDirectPlay3*)(unsigned long)DAT_0062c5ec;
    if (dp != 0) {
        result = dp->vtbl->fn04(dp);
    }

    this->SessionGUID = this->NullGUID;

    this->Err->ShowReturn(result, "Close Session");

    for (int i = 1; i <= (int)this->MaxGamePlayers; i++) {
        this->LastTurnAck[i] = 0;
    }

    return result;
}
