#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS_gph {
    char gap_00[0x184];
    int Humanity[10];
};
class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;
    char gap_12DA[0x276];
    COMMPLAYEROPTIONS_gph PlayerOptions;
    int GetPlayerHumanity(unsigned int player);
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::GetPlayerHumanity(unsigned int player) {
    if (player >= 1u && player <= this->MaxGamePlayers)
        return this->PlayerOptions.Humanity[player];
    return 0;
}
