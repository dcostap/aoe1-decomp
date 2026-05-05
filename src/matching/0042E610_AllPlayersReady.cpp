// VA: 0042E610 AllPlayersReady
// for(; cond; ready++) with player++ in body forces exact instruction ordering at loop bottom
class TCommunications_Handler { public:
    char gap_0[0x1594]; int PlayerReady[95]; unsigned short HighPlayerNumber; unsigned short LowPlayerNumber;
    int IsPlayerHuman(unsigned int player); int AllPlayersReady();
};
int TCommunications_Handler::AllPlayersReady() {
    int player = this->LowPlayerNumber;
    if (player > this->HighPlayerNumber) return 1;
    int* ready = &this->PlayerReady[player];
    for (; player <= this->HighPlayerNumber; ready++) {
        if (this->IsPlayerHuman(player)) {
            if (*ready == 0) return 0;
        }
        player++;
    }
    return 1;
}
