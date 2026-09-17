#include "../include/com_sess.h"
#include <string.h>

TCommunications_Handler* g_com_handler;

TCommunications_Sessions::TCommunications_Sessions(
    TCommunications_Handler* Comm) {
    g_com_handler = Comm;
    glpSERV = Comm->GetDPInterface();
    gServGUID = g_com_handler->ServiceGUID;
    gAppGUID = g_com_handler->ApplicationGUID;
    this->SessionCount = 0;
    EraseInformation();
    Refresh();
}

TCommunications_Sessions::~TCommunications_Sessions() {
}

void TCommunications_Sessions::EraseInformation() {
    SessionCount = 0;
    memset(Session, 0, sizeof(Session));
}

int TCommunications_Sessions::GetSessionCount() {
    return this->SessionCount;
}

char* TCommunications_Sessions::GetSessionName(int id) {
    if ((id >= 0) && (id <= this->SessionCount)) {
        return this->Session[id].Name;
    }
    return 0;
}

unsigned long TCommunications_Sessions::GetSessionMaxPlayers(int id) {
    if ((id >= 0) && (id <= this->SessionCount)) {
        return this->Session[id].MaxPlayers;
    }
    return 0;
}

unsigned long TCommunications_Sessions::GetSessionCurrentPlayers(int id) {
    if ((id >= 0) && (id <= this->SessionCount)) {
        return this->Session[id].CurrentPlayers;
    }
    return 0;
}

GUID* TCommunications_Sessions::GetSessionGUID(int id) {
    if ((id >= 0) && (id <= this->SessionCount)) {
        return &this->Session[id].SessGUID;
    }
    return 0;
}

int TCommunications_Sessions::IncSessionCount() {
    return ++this->SessionCount;
}

int TCommunications_Sessions::AddSession(
    GUID Instance, GUID Application,
    unsigned long MaxPlayers, unsigned long CurrentPlayers,
    char* Name, char* Password,
    unsigned long User1, unsigned long User2,
    unsigned long User3, unsigned long User4) {
    this->Session[SessionCount].AppGUID = Application;
    this->Session[SessionCount].SessGUID = Instance;
    this->Session[SessionCount].MaxPlayers = MaxPlayers;
    this->Session[SessionCount].CurrentPlayers = CurrentPlayers;
    // The binary writes all four user values to User1.
    // Preserve this defect to match the shipped executable; do not correct User2-User4.
    this->Session[SessionCount].User1 = User1;
    this->Session[SessionCount].User1 = User2;
    this->Session[SessionCount].User1 = User3;
    this->Session[SessionCount].User1 = User4;

    if (Name) {
        strcpy(this->Session[SessionCount].Name, Name);
    }
    if (Password) {
        strcpy(this->Session[SessionCount].Password, Password);
    }

    IncSessionCount();
    return 1;
}

int TCommunications_Sessions::Refresh() {
    DPSESSIONDESC2 dpDesc;

    EraseInformation();
    memset(&dpDesc, 0, sizeof(dpDesc));
    dpDesc.guidApplication = gAppGUID;
    dpDesc.dwSize = sizeof(dpDesc);

    return glpSERV->EnumSessions(&dpDesc, 0, reinterpret_cast<LPDPENUMSESSIONSCALLBACK2>(EnumSessionCallback), this, 1);
}

int __stdcall EnumSessionCallback(DPSESSIONDESC2* lpDPSessionDesc,
                                  unsigned long* lpdwTimeOut,
                                  unsigned long dwFlags,
                                  void* lpContext) {
    if (dwFlags & 1) {
        return 0;
    }

    static_cast<TCommunications_Sessions*>(lpContext)->AddSession(lpDPSessionDesc->guidInstance,
                                                                  lpDPSessionDesc->guidApplication, lpDPSessionDesc->dwMaxPlayers, lpDPSessionDesc->dwCurrentPlayers,
                                                                  lpDPSessionDesc->lpszSessionNameA, lpDPSessionDesc->lpszPasswordA, lpDPSessionDesc->dwUser1,
                                                                  lpDPSessionDesc->dwUser2, lpDPSessionDesc->dwUser3, lpDPSessionDesc->dwUser4);
    return 1;
}

int TCommunications_Sessions::IsEqualGuid(GUID* lpguid1, GUID* lpguid2) {
    return IsEqualGUID(*lpguid1, *lpguid2);
}
