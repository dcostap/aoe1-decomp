#ifndef AOE1_COM_SERV_H
#define AOE1_COM_SERV_H

#include "../third_party/directplay/include/dplay.h"

struct Service_Entry {
    char Name[80];
    _GUID* GUID;
    int field_54;
    int field_58;
    int Active;
};

class TCommunications_Services {
public:
    Service_Entry Service[100];
    int ServiceCount;

    TCommunications_Services();
    ~TCommunications_Services();
    int GetServiceCount();
    int IncServiceCount();
    char* GetServiceName(int index);
    int SetServiceName(int serviceIndex, char* name);
    _GUID GetServiceGUID(int index);
    void EnumServiceGUID(int index, _GUID* guid);
    int GetServiceActive(int index);
    void SetServiceActive(int index, int active);
};

BOOL __stdcall DPEnumCallback(LPGUID guid, LPSTR name, DWORD flags,
                               DWORD reserved, LPVOID context);

typedef char com_serv_service_entry_size_check[
    (sizeof(Service_Entry) == 0x60) ? 1 : -1];
typedef char com_serv_services_size_check[
    (sizeof(TCommunications_Services) == 0x2584) ? 1 : -1];

#endif
