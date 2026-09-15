#include "../include/com_serv.h"
#include <string.h>

TCommunications_Services::TCommunications_Services() {
    ServiceCount = 0;

    for (int i = 0; i < 100; i++) {
        strcpy(Service[i].Name, "");
        Service[i].GUID = 0;
        Service[i].Active = 0;
        Service[i].MinVersion = 0;
        Service[i].MajVersion = 0;
    }

    DirectPlayEnumerateA(DPEnumCallback, this);
}

TCommunications_Services::~TCommunications_Services() {
}

int TCommunications_Services::GetServiceCount() {
    return ServiceCount;
}

int TCommunications_Services::IncServiceCount() {
    ServiceCount = ServiceCount + 1;
    return ServiceCount;
}

char* TCommunications_Services::GetServiceName(int id) {
    if ((id >= 0) && (id <= ServiceCount)) {
        return Service[id].Name;
    }
    return 0;
}

int TCommunications_Services::SetServiceName(int id, char* Text) {
    strcpy(Service[id].Name, Text);
    return 1;
}

_GUID TCommunications_Services::GetServiceGUID(int id) {
    return *Service[id].GUID;
}

void TCommunications_Services::EnumServiceGUID(int id, _GUID* gid) {
    if ((id >= 0) && (id <= ServiceCount)) {
        Service[id].GUID = gid;
    }
}

int TCommunications_Services::GetServiceActive(int id) {
    if ((id >= 0) && (id <= ServiceCount)) {
        return Service[id].Active;
    }
    return 0;
}

void TCommunications_Services::SetServiceActive(int id, int state) {
    if ((id >= 0) && (id <= ServiceCount)) {
        Service[id].Active = state;
    }
}

BOOL __stdcall DPEnumCallback(LPGUID pid, LPSTR szName, DWORD major_ver,
                              DWORD minor_ver, LPVOID lpx) {
    TCommunications_Services* services =
        (TCommunications_Services*)lpx;
    int count = services->GetServiceCount();
    services->SetServiceName(count, szName);
    services->EnumServiceGUID(count, pid);

    IDirectPlay* lpIDC;
    int result = DirectPlayCreate(pid, (LPDIRECTPLAY*)&lpIDC, 0);

    if (result == 0) {
        services->SetServiceActive(count, 1);
        lpIDC->Release();
        services->IncServiceCount();
        return 1;
    }

    services->SetServiceActive(count, 0);
    services->IncServiceCount();
    return 1;
}
