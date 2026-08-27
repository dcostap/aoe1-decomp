#ifndef AOE1_COM_SERV_H
#define AOE1_COM_SERV_H

struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

typedef _GUID GUID;

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

extern "C" void __stdcall DirectPlayEnumerateA(void* callback, void* context);
extern "C" int __stdcall DirectPlayCreate(const GUID* guid, void** directPlay,
                                            unsigned long parameter);

int __stdcall DPEnumCallback(_GUID* guid, char* name, unsigned long flags,
                             unsigned long reserved, void* context);

class IDirectPlay {
public:
    virtual int __stdcall QueryInterface(const GUID* riid, void** object) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

typedef char com_serv_service_entry_size_check[
    (sizeof(Service_Entry) == 0x60) ? 1 : -1];
typedef char com_serv_services_size_check[
    (sizeof(TCommunications_Services) == 0x2584) ? 1 : -1];

#endif
