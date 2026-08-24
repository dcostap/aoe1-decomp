#ifndef AOE1_COM_SERV_CONTEXT_H
#define AOE1_COM_SERV_CONTEXT_H

// Canonical grouped context for C:\\msdev\\work\\age1_x1\\com_serv.cpp.
// The owner files retain narrow standalone declarations for focused checks.
// This surface supplies one complete class and ABI for the PDB-ordered TU.

struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

typedef _GUID GUID;

struct Service_Entry {
    char Name[80];
    union {
        _GUID* GUID;
        int field_50;
    };
    int field_54;
    int field_58;
    int Active;
};

class TCommunications_Services {
public:
    Service_Entry Service[100];
    union {
        int ServiceCount;
        int field_2580;
    };

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

extern "C" void __stdcall DirectPlayEnumerateA(void* callback, void* lpContext);
extern "C" int __stdcall DirectPlayCreate(const GUID* dpid, void** ppDirectPlay, unsigned long param);

int __stdcall DPEnumCallback(_GUID* param_1, char* param_2,
                             unsigned long param_3, unsigned long param_4,
                             void* param_5);

class IDirectPlay {
public:
    virtual int __stdcall QueryInterface(const GUID* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

#endif
