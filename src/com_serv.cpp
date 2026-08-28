#include "../include/com_serv.h"
#include <string.h>

TCommunications_Services::TCommunications_Services() {
    ServiceCount = 0;

    for (int i = 0; i < 100; i++) {
        strcpy(Service[i].Name, "");
        Service[i].GUID = 0;
        Service[i].Active = 0;
        Service[i].field_58 = 0;
        Service[i].field_54 = 0;
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

char* TCommunications_Services::GetServiceName(int index) {
    if ((index >= 0) && (index <= ServiceCount)) {
        return Service[index].Name;
    }
    return 0;
}

int TCommunications_Services::SetServiceName(int serviceIndex, char* name) {
    strcpy(Service[serviceIndex].Name, name);
    return 1;
}

_GUID TCommunications_Services::GetServiceGUID(int index) {
    return *Service[index].GUID;
}

void TCommunications_Services::EnumServiceGUID(int index, _GUID* guid) {
    if ((index >= 0) && (index <= ServiceCount)) {
        Service[index].GUID = guid;
    }
}

int TCommunications_Services::GetServiceActive(int index) {
    if ((index >= 0) && (index <= ServiceCount)) {
        return Service[index].Active;
    }
    return 0;
}

void TCommunications_Services::SetServiceActive(int index, int active) {
    if ((index >= 0) && (index <= ServiceCount)) {
        Service[index].Active = active;
    }
}

BOOL __stdcall DPEnumCallback(LPGUID guid, LPSTR name, DWORD flags,
                              DWORD reserved, LPVOID context) {
    TCommunications_Services* services =
        (TCommunications_Services*)context;
    int count = services->GetServiceCount();
    services->SetServiceName(count, name);
    services->EnumServiceGUID(count, guid);

    IDirectPlay* directPlay;
    int result = DirectPlayCreate(guid, (LPDIRECTPLAY*)&directPlay, 0);

    if (result == 0) {
        services->SetServiceActive(count, 1);
        directPlay->Release();
        services->IncServiceCount();
        return 1;
    }

    services->SetServiceActive(count, 0);
    services->IncServiceCount();
    return 1;
}
