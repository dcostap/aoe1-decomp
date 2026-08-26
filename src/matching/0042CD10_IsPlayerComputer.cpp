#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS_ipc {
    char gap_00[0x184];
    int Humanity[10];
};
class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;
    char gap_12DA[0x276];
    COMMPLAYEROPTIONS_ipc PlayerOptions;
    int IsPlayerComputer(unsigned int player);
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::IsPlayerComputer(unsigned int player) {
    int humanity;

    if (player >= 1u && player <= this->MaxGamePlayers) {
        humanity = this->PlayerOptions.Humanity[player];
        return humanity == 4;
    }
    return 0;
}
