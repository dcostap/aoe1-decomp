#include "../include/TCommunications_Sessions.h"
#include "../include/TCommunications_Handler.h"

#include <dplay.h>

#include <stddef.h>
#include <string.h>

namespace {
static TCommunications_Handler* s_sessions_comm = nullptr;
static IDirectPlay3A* s_glpSERV = nullptr;
static GUID s_ServGUID{};
static GUID s_ApplicationGUID{};
}

static BOOL FAR PASCAL EnumSessionCallback(LPCDPSESSIONDESC2 desc, LPDWORD /*timeout*/, DWORD flags, LPVOID context) {
    // Source of truth: com_sess.cpp.decomp @ 0x00432560
    if ((flags & DPESC_TIMEDOUT) != 0) {
        return FALSE;
    }

    if (context == nullptr || desc == nullptr) {
        return TRUE;
    }

    TCommunications_Sessions* sessions = (TCommunications_Sessions*)context;
    (void)sessions->AddSession(desc->guidInstance, desc->guidApplication, desc->dwMaxPlayers, desc->dwCurrentPlayers,
                               desc->lpszSessionNameA, desc->lpszPasswordA, (ulong)desc->dwUser1, (ulong)desc->dwUser2,
                               (ulong)desc->dwUser3, (ulong)desc->dwUser4);
    return TRUE;
}

TCommunications_Sessions::TCommunications_Sessions(TCommunications_Handler* comm) {
    // Source of truth: com_sess.cpp.decomp @ 0x00432200
    s_sessions_comm = comm;
    s_glpSERV = comm ? (IDirectPlay3A*)comm->GetDPInterface() : nullptr;

    if (comm != nullptr) {
        s_ServGUID = comm->ServiceGUID;
        s_ApplicationGUID = comm->ApplicationGUID;
    } else {
        memset(&s_ServGUID, 0, sizeof(s_ServGUID));
        memset(&s_ApplicationGUID, 0, sizeof(s_ApplicationGUID));
    }

    this->SessionCount = 0;
    this->EraseInformation();
    (void)this->Refresh();
}

TCommunications_Sessions::~TCommunications_Sessions() {
    // Fully verified. Source of truth: com_sess.cpp.decomp @ 0x00432290
}

void TCommunications_Sessions::EraseInformation() {
    // Source of truth: com_sess.cpp.asm @ 0x004322A0
    this->SessionCount = 0;
    memset(&this->Session[0], 0, sizeof(TCommunications_Sessions) - offsetof(TCommunications_Sessions, Session));
}

int TCommunications_Sessions::GetSessionCount() {
    // Fully verified. Source of truth: com_sess.cpp.decomp @ 0x004322C0
    return this->SessionCount;
}

char* TCommunications_Sessions::GetSessionName(int index) {
    // Fully verified. Source of truth: com_sess.cpp.decomp @ 0x004322D0
    if ((index > -1) && (index <= this->SessionCount)) {
        return this->Session[index].Name;
    }
    return nullptr;
}

ulong TCommunications_Sessions::GetSessionMaxPlayers(int index) {
    // Fully verified. Source of truth: com_sess.cpp.decomp @ 0x004322F0
    if ((index > -1) && (index <= this->SessionCount)) {
        return this->Session[index].MaxPlayers;
    }
    return 0;
}

ulong TCommunications_Sessions::GetSessionCurrentPlayers(int index) {
    // Fully verified. Source of truth: com_sess.cpp.decomp @ 0x00432320
    if ((index > -1) && (index <= this->SessionCount)) {
        return this->Session[index].CurrentPlayers;
    }
    return 0;
}

_GUID* TCommunications_Sessions::GetSessionGUID(int index) {
    // Fully verified. Source of truth: com_sess.cpp.decomp @ 0x00432350
    if ((index > -1) && (index <= this->SessionCount)) {
        return &this->Session[index].SessGUID;
    }
    return nullptr;
}

int TCommunications_Sessions::IncSessionCount() {
    // Fully verified. Source of truth: com_sess.cpp.decomp @ 0x00432380
    const int next = this->SessionCount + 1;
    this->SessionCount = next;
    return next;
}

int TCommunications_Sessions::AddSession(_GUID session_guid, _GUID app_guid, ulong max_players, ulong current_players, char* name,
                                        char* password, ulong user1, ulong user2, ulong user3, ulong user4) {
    // Source of truth: com_sess.cpp.decomp @ 0x00432390
    if (this->SessionCount < 0 || this->SessionCount >= 501) {
        return 0;
    }

    SEs& s = this->Session[this->SessionCount];
    s.AppGUID = app_guid;
    s.SessGUID = session_guid;
    s.MaxPlayers = max_players;
    s.CurrentPlayers = current_players;
    s.User1 = user1;
    s.User2 = user2;
    s.User3 = user3;
    s.User4 = user4;

    if (name != nullptr) {
        strncpy(s.Name, name, sizeof(s.Name) - 1);
        s.Name[sizeof(s.Name) - 1] = '\0';
    }
    if (password != nullptr) {
        strncpy(s.Password, password, sizeof(s.Password) - 1);
        s.Password[sizeof(s.Password) - 1] = '\0';
    }

    (void)this->IncSessionCount();
    return 1;
}

int TCommunications_Sessions::Refresh() {
    // Source of truth: com_sess.cpp.decomp @ 0x004324F0
    this->EraseInformation();

    if (s_glpSERV == nullptr) {
        return 0;
    }

    DPSESSIONDESC2 dpDesc;
    memset(&dpDesc, 0, sizeof(dpDesc));
    dpDesc.dwSize = sizeof(dpDesc);
    dpDesc.guidApplication = s_ApplicationGUID;
    dpDesc.dwFlags = 0x50;

    const HRESULT hr = s_glpSERV->EnumSessions(&dpDesc, 0, EnumSessionCallback, this, DPENUMSESSIONS_AVAILABLE);
    return (int)hr;
}

int TCommunications_Sessions::IsEqualGuid(_GUID* a, _GUID* b) {
    // Fully verified. Source of truth: com_sess.cpp.decomp @ 0x004325E0
    if (a == nullptr || b == nullptr) {
        return 0;
    }

    if (a->Data1 != b->Data1) return 0;
    if (a->Data2 != b->Data2) return 0;
    if (a->Data3 != b->Data3) return 0;
    if (memcmp(a->Data4, b->Data4, 8) != 0) return 0;
    return 1;
}

