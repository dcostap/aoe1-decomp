// TCommunications_Handler::CalculatePlayerRange
// VA: 00425990
// Com_hand.cpp:236-257
// 130 bytes, ~2 byte positional diff (parked)
// VC5 quirk: original uses `xor eax; mov ax,[mem]; cmp eax,edi; jg/jl; mov eax,edi; mov [mem],ax`
// for the HighPlayerNumber/LowPlayerNumber update, but any source form with temps
// generates extra `and` instructions (load ax → copy to other reg → and 0FFFFh).
// Best compact form: 128 bytes (no extra and instructions, uses `mov [mem],di` directly
// instead of `mov eax,edi; mov [mem],ax` — 2 bytes short).
// 8+ attempts across all variants. 0 relocations.
// Same behavior, same field layout.

#include "../../include/game_globals.h"

class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;   // +0x12D8
    char gap_12DA[0x1710 - 0x12DA];
    unsigned short HighPlayerNumber; // +0x1710
    unsigned short LowPlayerNumber;  // +0x1712

    int IsPlayerHuman(int playerIndex);
    int IsPlayerComputer(int playerIndex);
    int CalculatePlayerRange(void);
};

int TCommunications_Handler::CalculatePlayerRange(void) {
    unsigned int i = 1;
    unsigned short maxPlayers = this->MaxGamePlayers;

    this->HighPlayerNumber = 0;
    this->LowPlayerNumber = maxPlayers + 1;

    if ((int)maxPlayers < 1)
        goto done;

    do {
        if (this->IsPlayerHuman(i)) {
            goto update;
        }
        if (!this->IsPlayerComputer(i)) {
            goto skip;
        }
update:
        {
            int high = (int)this->HighPlayerNumber;
            if (high <= (int)i)
                high = i;
            this->HighPlayerNumber = (unsigned short)high;

            int low = (int)this->LowPlayerNumber;
            if (low >= (int)i)
                low = i;
            this->LowPlayerNumber = (unsigned short)low;
        }
skip:
        i++;
    } while ((int)i <= (int)(unsigned short)this->MaxGamePlayers);

done:
    return 1;
}
