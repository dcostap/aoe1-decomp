#include "../include/com_sess.h"
#include <string.h>

TCommunications_Handler* g_com_handler;

TCommunications_Sessions::TCommunications_Sessions(
    TCommunications_Handler* handler) {
    g_com_handler = handler;
    glpSERV = handler->GetDPInterface();
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

char* TCommunications_Sessions::GetSessionName(int index) {
    if ((index >= 0) && (index <= this->SessionCount)) {
        return this->Session[index].Name;
    }
    return 0;
}

unsigned long TCommunications_Sessions::GetSessionMaxPlayers(int index) {
    if ((index >= 0) && (index <= this->SessionCount)) {
        return this->Session[index].MaxPlayers;
    }
    return 0;
}

unsigned long TCommunications_Sessions::GetSessionCurrentPlayers(int index) {
    if ((index >= 0) && (index <= this->SessionCount)) {
        return this->Session[index].CurrentPlayers;
    }
    return 0;
}

GUID* TCommunications_Sessions::GetSessionGUID(int index) {
    if ((index >= 0) && (index <= this->SessionCount)) {
        return &this->Session[index].SessGUID;
    }
    return 0;
}

int TCommunications_Sessions::IncSessionCount() {
    return ++this->SessionCount;
}

int TCommunications_Sessions::AddSession(
    GUID sessGUID, GUID appGUID,
    unsigned long maxPlayers, unsigned long currentPlayers,
    char* name, char* password,
    unsigned long user1, unsigned long user2,
    unsigned long user3, unsigned long user4) {
    this->Session[SessionCount].AppGUID = appGUID;
    this->Session[SessionCount].SessGUID = sessGUID;
    this->Session[SessionCount].MaxPlayers = maxPlayers;
    this->Session[SessionCount].CurrentPlayers = currentPlayers;
    // ORIGINAL BUG: The binary writes all four user values to User1.
    // Preserve this defect to match the shipped executable; do not correct User2-User4.
    this->Session[SessionCount].User1 = user1;
    this->Session[SessionCount].User1 = user2;
    this->Session[SessionCount].User1 = user3;
    this->Session[SessionCount].User1 = user4;

    if (name) {
        strcpy(this->Session[SessionCount].Name, name);
    }
    if (password) {
        strcpy(this->Session[SessionCount].Password, password);
    }

    IncSessionCount();
    return 1;
}

int TCommunications_Sessions::Refresh() {
    DPSESSIONDESC2 desc;

    EraseInformation();
    memset(&desc, 0, sizeof(desc));
    desc.guidApplication = gAppGUID;
    desc.dwSize = sizeof(desc);

    return glpSERV->EnumSessions(&desc, 0,
                                 (LPDPENUMSESSIONSCALLBACK2)EnumSessionCallback,
                                 this, 1);
}

int __stdcall EnumSessionCallback(DPSESSIONDESC2* desc,
                                  unsigned long* timeout,
                                  unsigned long flags,
                                  void* context) {
    if (flags & 1) {
        return 0;
    }

    ((TCommunications_Sessions*)context)->AddSession(
        desc->guidInstance,
        desc->guidApplication,
        desc->dwMaxPlayers,
        desc->dwCurrentPlayers,
        desc->lpszSessionNameA,
        desc->lpszPasswordA,
        desc->dwUser1,
        desc->dwUser2,
        desc->dwUser3,
        desc->dwUser4);
    return 1;
}

int TCommunications_Sessions::IsEqualGuid(GUID* guid1, GUID* guid2) {
    if (guid1->Data1 == guid2->Data1) {
        if (*(unsigned long*)&guid1->Data2 == *(unsigned long*)&guid2->Data2) {
            if (*(unsigned long*)&guid1->Data4[0] == *(unsigned long*)&guid2->Data4[0]) {
                if (*(unsigned long*)&guid1->Data4[4] == *(unsigned long*)&guid2->Data4[4]) {
                    return 1;
                }
            }
        }
    }

    return 0;
}
