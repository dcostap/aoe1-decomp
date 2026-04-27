// attempt 1: direct inclusive loop over low/high player words with ready flag check
// result: compiled, but VC5 picked bx-based compares instead of the original esi/eax short-register basin
// attempt 2: switch to the decompiler-style ready-pointer walk so the loop shape and register reuse have a better chance
// attempt 3: reverse the bound compare so VC5 has a better shot at the original cmp esi,eax / jg basin
// attempt 4: drop the extra high temp and go back to the pointer walk if the compare basin still fights it
// attempt 5: try the direct `LowPlayerNumber > HighPlayerNumber` guard so VC5 can pick the original cmp/jg pair

class TCommunications_Handler {
public:
    char gap_0[0x1594];
    int PlayerReady[95]; // +0x1594
    unsigned short HighPlayerNumber; // +0x1710
    unsigned short LowPlayerNumber;  // +0x1712

    int IsPlayerHuman(unsigned int player);
    int AllPlayersReady();
};

int TCommunications_Handler::AllPlayersReady() {
    unsigned int player;
    int* ready;

    if (this->LowPlayerNumber > this->HighPlayerNumber) {
        return 1;
    }

    player = this->LowPlayerNumber;
    ready = &this->PlayerReady[player];
    while (1) {
        if (IsPlayerHuman(player) != 0) {
            if (*ready == 0) {
                return 0;
            }
        }

        player = player + 1;
        ready = ready + 1;
        if (player > this->HighPlayerNumber) {
            return 1;
        }
    }
}
