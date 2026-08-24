// VA: 0042E610 AllPlayersReady
// for(; cond; ready++) with player++ in body forces exact instruction ordering at loop bottom
#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler { public:
    char gap_0[0x1594]; int PlayerReady[95]; unsigned short HighPlayerNumber; unsigned short LowPlayerNumber;
    int IsPlayerHuman(unsigned int player); int AllPlayersReady();
};
#endif // COM_HAND_TU_CONTEXT

int TCommunications_Handler::AllPlayersReady() {
    int player = this->PlayerOptions.LowPlayerNumber;
    if (player > this->PlayerOptions.HighPlayerNumber) return 1;
    int* ready = &this->PlayerOptions.PlayerReady[player];
    for (; player <= this->PlayerOptions.HighPlayerNumber; ready++) {
        if (this->IsPlayerHuman(player)) {
            if (*ready == 0) return 0;
        }
        player++;
    }
    return 1;
}
