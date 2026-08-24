#ifndef COM_SERV_TU_CONTEXT
struct ServiceInfo {
    char Name[0x60];
};

class TCommunications_Services {
public:
    ServiceInfo Service[0x64];
    int ServiceCount;

    char* GetServiceName(int index);
};
#endif

char* TCommunications_Services::GetServiceName(int index) {
    if ((index >= 0) && (index <= this->ServiceCount)) {
        return this->Service[index].Name;
    }
    return 0;
}
