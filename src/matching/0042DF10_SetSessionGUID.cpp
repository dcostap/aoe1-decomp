#if !defined(COM_HAND_TU_CONTEXT)
struct _GUID {
    unsigned long Data1;
    unsigned long Data2;
    unsigned long Data3;
    unsigned long Data4;
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x12FC];
    _GUID SessionGUID;

    void SetSessionGUID(_GUID guid);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::SetSessionGUID(_GUID guid) {
    this->SessionGUID = guid;
}
