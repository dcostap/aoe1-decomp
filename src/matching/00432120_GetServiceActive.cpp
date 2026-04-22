struct ServiceInfo {
    char Name[0x50];
    void* GUID;
    char gap_54[0x08];
    int Active;
};

class TCommunications_Services {
public:
    ServiceInfo Service[0x64];
    int ServiceCount;

    int GetServiceActive(int index);
};

int TCommunications_Services::GetServiceActive(int index) {
    if ((index >= 0) && (index <= this->ServiceCount)) {
        return this->Service[index].Active;
    }
    return 0;
}
