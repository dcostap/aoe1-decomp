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

    void SetServiceActive(int index, int active);
};

void TCommunications_Services::SetServiceActive(int index, int active) {
    if ((index >= 0) && (index <= this->ServiceCount)) {
        this->Service[index].Active = active;
    }
}
