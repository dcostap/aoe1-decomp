struct _GUID {
    unsigned long Data1;
    unsigned long Data2;
    unsigned long Data3;
    unsigned long Data4;
};

class TCommunications_Handler {
public:
    char gap_00[0x12FC];
    _GUID SessionGUID;

    void SetSessionGUID(_GUID guid);
};

void TCommunications_Handler::SetSessionGUID(_GUID guid) {
    this->SessionGUID = guid;
}
