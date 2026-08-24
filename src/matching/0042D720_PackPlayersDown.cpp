// VA: 0042D720 TCommunications_Handler::PackPlayersDown
// Source: Com_hand.cpp lines 5669-5714
// Attempt log:
// 1: initial reconstruction from packet: scan player slots, move later occupied slot down, copy two name strings and player metadata columns.
// 2: changed early numPlayers guard to wrap loop and fall through to final SetSelfPlayer call like original.
// 3: rewrote inner search with goto move_found/next_player so found branch jumps directly to copy; duplicated first human check.
// 4: split inner human/computer tests into separate statements inside one do/while.
// 5: spelled outer tests with numPlayers on left; no improvement.
// 6: made inner source index volatile; much worse (first mismatch offset 2), rolled back.
// 7: tested direct array assignments as current best; remaining mismatch begins with initial branch distance due later block layout.
// 8: reordered locals (dst before offset); no codegen change.
// 9: restored local order; tried source-level helper GetPlayerName/log order is already matching call order.
// 10: left in scratch: behavior and main copy/log calls are understood, but block layout differs. Rebuilt keeps the no-player final call close, then inner search duplicates/peels the first IsPlayerHuman check and shifts the copy block by +0x0B; original has a compact do-loop with found branches directly to copy and no post-loop recheck. Not accepted_drift-safe due broad shifted mismatch.
// 11: replacing the inner do-loop with a top-tested while and naming the final
// SetSelfPlayer call removed the peeled call site and reached 563/563 bytes;
// the remaining drift is only the two commutative name-destination LEA
// encodings at +00A0/+00D4. Pointer, array-index, and reversed-add spellings
// did not change those bytes; named pointer temporaries worsened the frame.
// 12: reversed the destination pointer-add operands in both typed name copies;
// codegen was unchanged, so restored the natural pointer-plus-offset form.
// 13: modeled both name buffers as typed NAME arrays and used the natural first
// element member for the destination; codegen was unchanged, so restored the
// clean pointer-plus-offset source.
// 14: integer-cast destination addition was a codegen duplicate; rolled back.
// 15: typed the offset as the pointer operand; VC5 still canonicalized the LEA.
// 16: array-index destination spelling also emitted the same two-byte drift.
// 17: mutable strcpy source declaration did not change codegen.
// 18: restoring the period <string.h> declaration context flipped both SIB
// encodings and reached an exact match; kept the natural named-pointer source.

#include <string.h>

typedef unsigned short ushort;

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog { public: void Log(char* fmt, ...); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0000[0x12C8];
    char* names1;          // +12C8, 0x80 per player
    char* names2;          // +12CC, 0x80 per player
    char gap_12D0[8];
    ushort numPlayers;     // +12D8
    char gap_12DA[0x1344 - 0x12DA];
    int f1344[10];
    char gap_136C[0x1564 - 0x136C];
    int f1564[10];
    int f158C[2];
    int f1594[10];
    int f15BC[10];
    int f15E4[10];
    int f160C[10];
    int f1634[10];
    int f165C[10];
    int f1684[10];
    int f16AC[10];
    int f16D4[10];
    char gap_16FC[0x1720 - 0x16FC];
    int f1720[10];

    int IsPlayerHuman(int i);
    int IsPlayerComputer(int i);
    char* GetPlayerName(int i);
    void InitPlayerInformation(int i, int zero, char* s1, char* s2);
    void SetSelfPlayer();
    void PackPlayersDown();
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::PackPlayersDown()
{
    int offset;
    int pos;
    int* dst;
    int save;

    pos = 1;
    if (this->numPlayers >= 1) {
        offset = 0x80;
        dst = (int*)((char*)this + 0x1568);
        do {
        if (this->IsPlayerHuman(pos) || this->IsPlayerComputer(pos)) {
            L->Log((char*)"Position %d *LOCKED*.   Plr=%s", pos, this->GetPlayerName(pos));
        } else {
            int src = pos;
            while (src <= (int)this->numPlayers) {
                if (this->IsPlayerHuman(src)) {
                    goto move_found;
                }
                if (this->IsPlayerComputer(src)) {
                    goto move_found;
                }
                ++src;
            }
            goto next_player;

move_found:
            {
                strcpy((char*)this->FriendlyName + offset, (char*)this->FriendlyName + src * 0x80);
                strcpy((char*)this->FormalName + offset, (char*)this->FormalName + src * 0x80);

                dst[0x30 / 4] = this->f1594[src];
                dst[0] = this->f1564[src];
                dst[0x58 / 4] = this->f15BC[src];
                dst[0x80 / 4] = this->f15E4[src];
                dst[0xA8 / 4] = this->f160C[src];
                dst[0xD0 / 4] = this->f1634[src];
                dst[0xF8 / 4] = this->f165C[src];
                dst[0x120 / 4] = this->f1684[src];
                dst[0x148 / 4] = this->f16AC[src];
                dst[0x170 / 4] = this->f16D4[src];
                dst[0x1BC / 4] = this->f1720[src];
                dst[-0x220 / 4] = this->f1344[src];

                save = pos;
                L->Log((char*)"Moved %d->%d", src, save);
                L->Log((char*)"Position %d *LOCKED*.   Plr=%s", save, this->GetPlayerName(save));
                this->InitPlayerInformation(src, 0, (char*)"", (char*)"");
            }
        }
next_player:
            ++pos;
            ++dst;
            offset += 0x80;
        } while (pos <= (int)this->numPlayers);
    }

    this->SetSelfPlayer();
}
