struct _GUID {
    unsigned long Data1;
    unsigned long Data2;
    unsigned long Data3;
    unsigned long Data4;
};

class TCommunications_Handler {
public:
    char gap_00[0x12EC];
    _GUID ApplicationGUID;

    void SetApplicationGUID(_GUID guid);
};

void TCommunications_Handler::SetApplicationGUID(_GUID guid) {
    this->ApplicationGUID = guid;
}
