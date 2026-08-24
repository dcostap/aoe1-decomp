// target: VA 0042E500 TCommunications_Handler::GetClientReadiness(uint,int*,ulong*,ulong*,ulong*,ulong*,ulong*,ulong*,ulong*)
// first pass: direct indexed copies from the eight readiness arrays and return 1

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x1594];
    unsigned long PlayerReady[10]; // +0x1594
    unsigned long User1[10]; // +0x15BC
    unsigned long User2[10]; // +0x15E4
    unsigned long User3[10]; // +0x160C
    unsigned long User4[10]; // +0x1634
    unsigned long User5[10]; // +0x165C
    unsigned long User6[10]; // +0x1684
    unsigned long User7[10]; // +0x16AC

    int GetClientReadiness(unsigned int index, int* out0, unsigned long* out1, unsigned long* out2, unsigned long* out3, unsigned long* out4, unsigned long* out5, unsigned long* out6, unsigned long* out7);
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::GetClientReadiness(unsigned int index, int* out0, unsigned long* out1, unsigned long* out2, unsigned long* out3, unsigned long* out4, unsigned long* out5, unsigned long* out6, unsigned long* out7) {
    *out0 = this->PlayerOptions.PlayerReady[index];
    *out1 = this->PlayerOptions.User1[index];
    *out2 = this->PlayerOptions.User2[index];
    *out3 = this->PlayerOptions.User3[index];
    *out4 = this->PlayerOptions.User4[index];
    *out5 = this->PlayerOptions.User5[index];
    *out6 = this->PlayerOptions.User6[index];
    *out7 = this->PlayerOptions.User7[index];
    return 1;
}
