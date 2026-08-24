#ifndef COM_SERV_TU_CONTEXT
struct _GUID;

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

    void EnumServiceGUID(int index, _GUID* guid);
};
#endif

void TCommunications_Services::EnumServiceGUID(int index, _GUID* guid) {
    if ((index >= 0) && (index <= this->ServiceCount)) {
        this->Service[index].GUID = guid;
    }
}
