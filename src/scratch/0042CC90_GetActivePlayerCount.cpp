// first pass: direct do/while over player index and count active humans/computers
// tried unsigned short player; VC5 chose ebp/ebx and widened the loop compare
// tried a handler alias; the remaining mismatch stayed at the entry zeroing order
// tried swapping local init order; still off at the prolog zeroing/assignment sequence (first mismatch offset 3)

class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;
    char gap_12DA[0x3FA];

    int IsPlayerHuman(unsigned int player);
    int IsPlayerComputer(unsigned int player);
    int GetActivePlayerCount();
};

int TCommunications_Handler::GetActivePlayerCount() {
    unsigned int player = 0;
    int count = 0;

    do {
        if (this->IsPlayerHuman(player)) {
            ++count;
        } else if (this->IsPlayerComputer(player)) {
            ++count;
        }
        ++player;
    } while (player <= this->MaxGamePlayers);

    return count;
}
