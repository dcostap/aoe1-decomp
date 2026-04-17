struct _GUID {
    unsigned long Data1;
    unsigned long Data2;
    unsigned long Data3;
    unsigned long Data4;
};

class TCommunications_Handler {
public:
    char gap_00[0x12DC];
    _GUID ServiceGUID;

    void SetServiceGUID(_GUID guid);
};

void TCommunications_Handler::SetServiceGUID(_GUID guid) {
    this->ServiceGUID = guid;
}
