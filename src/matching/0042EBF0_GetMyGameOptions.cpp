#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x04];
    void* OptionsData;
    char gap_08[0x1714];
    unsigned long DataSizeToFollow;

    void* GetMyGameOptions(unsigned long* param);
};
#endif // COM_HAND_TU_CONTEXT


void* TCommunications_Handler::GetMyGameOptions(unsigned long* param) {
    *param = this->PlayerOptions.DataSizeToFollow;
    return this->OptionsData;
}
