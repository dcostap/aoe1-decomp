#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Speed {
public:
    void EnableSpeedControl(int param);
};
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x14D4];
    RGE_Communications_Speed *Speed;
    void SetSpeedControl(int param);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::SetSpeedControl(int param) {
    this->Speed->EnableSpeedControl(param);
}
