#ifndef AOE1_COM_SERV_H
#define AOE1_COM_SERV_H

#include "../third_party/directplay/include/dplay.h"

struct SPs {
    char Name[80];
    _GUID* GUID;
    unsigned long MajVersion;
    unsigned long MinVersion;
    int Active;
};

typedef char com_serv_sp_size_check[
    (sizeof(SPs) == 0x60) ? 1 : -1];

class TCommunications_Services {
protected:
    SPs Service[100];

private:
    int ServiceCount;

public:
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

typedef char com_serv_services_size_check[
    (sizeof(TCommunications_Services) == 0x2584) ? 1 : -1];

#endif
