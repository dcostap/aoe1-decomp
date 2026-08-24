// tried the obvious member-call form; compiler still wants a different prolog / call basin
// the remaining gap is early register allocation around the Kick loop, not the loop logic itself
#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x1C];
    int MeHost;
    char gap_20[0x10A8];
    unsigned long current_turn;
    char gap_10CC[0x20C];
    unsigned short MaxGamePlayers;

    int Kick(unsigned int player_number);
    void DropAllHostedPlayers(void);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::DropAllHostedPlayers(void) {
    if (MeHost != 0 && current_turn <= 6) {
        unsigned int player = 1;
        if (player <= MaxGamePlayers) {
            do {
                Kick(player);
                player = player + 1;
            } while ((int)player <= (int)MaxGamePlayers);
        }
    }
}
