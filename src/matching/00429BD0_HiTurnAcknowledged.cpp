// attempt 1: zero the global max, scan players in the inclusive low/high range, and keep the largest ack among human players
// exact match landed with the inclusive player loop, helper gate, and max compare against the global 0x62C5E8

extern unsigned long DAT_0062C5E8;

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    unsigned char gap_00[0x1710];
    unsigned short high_player;
    unsigned short low_player;
    unsigned char gap_1714[0xC];
    unsigned long last_turn_ack[64];

    int IsPlayerHuman(int player_id);
    unsigned long HiTurnAcknowledged();
};
#endif // COM_HAND_TU_CONTEXT


unsigned long TCommunications_Handler::HiTurnAcknowledged() {
    unsigned long* ack;
    int player;

    DAT_0062C5E8 = 0;
    player = this->low_player;
    if (player <= this->high_player) {
        ack = this->last_turn_ack + player;
        do {
            if (this->IsPlayerHuman(player) != 0 && *ack > DAT_0062C5E8) {
                DAT_0062C5E8 = *ack;
            }
            player++;
            ack++;
        } while (player <= this->high_player);
    }
    return DAT_0062C5E8;
}
