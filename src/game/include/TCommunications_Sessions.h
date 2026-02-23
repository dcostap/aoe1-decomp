#pragma once
#include "common.h"
#include "SEs.h"

struct IDirectPlay2;

struct TCommunications_Sessions {
    TCommunications_Sessions(TCommunications_Handler* comm);
    ~TCommunications_Sessions();

    int GetSessionCount();
    char* GetSessionName(int index);
    ulong GetSessionMaxPlayers(int index);
    ulong GetSessionCurrentPlayers(int index);
    _GUID* GetSessionGUID(int index);
    int IncSessionCount();
    int AddSession(_GUID session_guid, _GUID app_guid, ulong max_players, ulong current_players, char* name,
                   char* password, ulong user1, ulong user2, ulong user3, ulong user4);
    int Refresh();
    int IsEqualGuid(_GUID* a, _GUID* b);

    void EraseInformation();

    int SessionCount;
    SEs Session[501];
    _GUID glpGuid;
    IDirectPlay2* glpIDC;
};
static_assert(sizeof(TCommunications_Sessions) == 0x457B0, "Size mismatch");
