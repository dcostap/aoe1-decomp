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
    char gap_00[0x12EC];
    _GUID ApplicationGUID;

    void SetApplicationGUID(_GUID guid);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::SetApplicationGUID(_GUID guid) {
    this->ApplicationGUID = guid;
}
