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

typedef char com_serv_sp_size_check[(sizeof(SPs) == 0x60) ? 1 : -1];

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
    char* GetServiceName(int id);
    int SetServiceName(int id, char* Text);
    _GUID GetServiceGUID(int id);
    void EnumServiceGUID(int id, _GUID* gid);
    int GetServiceActive(int id);
    void SetServiceActive(int id, int state);
};

BOOL __stdcall DPEnumCallback(LPGUID pid, LPSTR szName, DWORD major_ver, DWORD minor_ver, LPVOID lpx);

typedef char com_serv_services_size_check[(sizeof(TCommunications_Services) == 0x2584) ? 1 : -1];

#endif
