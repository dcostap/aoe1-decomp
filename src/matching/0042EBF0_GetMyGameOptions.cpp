class TCommunications_Handler {
public:
    char gap_00[0x04];
    void* OptionsData;
    char gap_08[0x1714];
    unsigned long DataSizeToFollow;

    void* GetMyGameOptions(unsigned long* param);
};

void* TCommunications_Handler::GetMyGameOptions(unsigned long* param) {
    *param = DataSizeToFollow;
    return OptionsData;
}
