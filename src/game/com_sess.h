#pragma once
#include "../common.h"
#include "Com_hand.h"

class TCommunications_Sessions       {
public:
    int SessionCount;                        // 0x0
    SEs Session[501];                        // 0x4
    _GUID glpGuid;                           // 0x4579C
    IDirectPlay2* glpIDC;                    // 0x457AC

    TCommunications_Sessions(TCommunications_Handler* param_1);

    // --- Non-Virtual Destructor ---
    ~TCommunications_Sessions() noexcept(false);
    // --- Non-Virtual Members ---
    void EraseInformation();
    int GetSessionCount();
    char* GetSessionName(int param_1);
    ulong GetSessionMaxPlayers(int param_1);
    ulong GetSessionCurrentPlayers(int param_1);
    _GUID* GetSessionGUID(int param_1);
    int IncSessionCount();
    int AddSession(_GUID param_1, _GUID param_2, ulong param_3, ulong param_4, char* param_5, char* param_6, ulong param_7, ulong param_8, ulong param_9, ulong param_10);
    int Refresh();
    int IsEqualGuid(_GUID* param_1, _GUID* param_2);
};

static_assert(sizeof(TCommunications_Sessions) == 0x457B0, "TCommunications_Sessions Size Mismatch");
static_assert(offsetof(TCommunications_Sessions, glpIDC) == 0x457AC, "TCommunications_Sessions Offset Mismatch");

