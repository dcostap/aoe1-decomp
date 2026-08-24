#ifndef COM_SERV_TU_CONTEXT
struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

struct ServiceInfo {
    char Name[0x50];
    _GUID* GUID;
    char gap_54[0x08];
    int Active;
};

class TCommunications_Services {
public:
    ServiceInfo Service[0x64];
    int ServiceCount;

    _GUID GetServiceGUID(int index);
};
#endif

_GUID TCommunications_Services::GetServiceGUID(int index) {
    return *this->Service[index].GUID;
}
