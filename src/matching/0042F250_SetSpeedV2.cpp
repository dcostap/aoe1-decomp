#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Speed {
public:
    void SetV2(unsigned long param);
};
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x14D4];
    RGE_Communications_Speed* Speed;
    void SetSpeedV2(unsigned long param);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::SetSpeedV2(unsigned long param) {
    this->Speed->SetV2(param);
}
