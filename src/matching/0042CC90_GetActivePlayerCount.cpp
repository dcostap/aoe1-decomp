// VA: 0042CC90 TCommunications_Handler::GetActivePlayerCount (63 B)
// PDB source: Com_hand.cpp lines 5052-5062
//
// Attempt log:
// 1-5: Various do-while and for-loop forms. Missing guard, prologue order wrong.
// 6. do-while with (int) casts: 79% diff, jle fixed at bottom, body/epilogue perfect.
//    Remaining: prologue order (xor esi before mov edi,ecx) + missing initial guard.
// 7. for-loop with int player: testing if signed comparison preserves the guard.

class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;

    int IsPlayerHuman(unsigned int player);
    int IsPlayerComputer(unsigned int player);
    int GetActivePlayerCount();
};

int TCommunications_Handler::GetActivePlayerCount() {
    int count = 0;

    for (int player = 0; player <= MaxGamePlayers; player++) {
        if (IsPlayerHuman(player)) {
            ++count;
        } else if (IsPlayerComputer(player)) {
            ++count;
        }
    }

    return count;
}
