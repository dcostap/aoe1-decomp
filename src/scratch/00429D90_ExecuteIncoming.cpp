// 00429D90 TCommunications_Handler::ExecuteIncoming
// PDB: Com_hand.cpp:3080-3142, 485 bytes
// Attempt log:
// - v1: reconstructed on-hold message scan from packet/decompiler with local structs and member calls.
// - v2: inlined clear-entry code and rewrote around byte offset to match original EBX offset topology.
// - v3: delayed offset initialization until after multiplayer check and marked offset register to probe EBX allocation; no size improvement.
// - v4: introduced self local and restored offset zero-before-check to probe original ESI-this/EBX-zero allocation.
// - v5: tried /GX as TU-context probe; no change to compiled main .text size, removed flag.
// - v6 (sa8b70374_r1): removed the self alias and used direct this accesses to
//   test whether the original ESI-this/EBX-offset basin comes from natural
//   member expressions rather than a long-lived receiver alias.
// - v7 (sa8b70374_r1): restored the proven HOLDER/PlayerHighSerialNumber and
//   PlayerOptions.dcoID ownership (dcoID starts at +1564, with the loop's
//   pre-increment selecting player 1) and scoped loop locals to their guards.
// - v8 (sa8b70374_r1): declared the byte offset before the packet counter and
//   scoped pno to the multiplayer arm, matching the original's early zeroed
//   offset and late address-taken counter home.
// - v9 (sa8b70374_r1): initialized the dco cursor at dcoID+1 and advanced it
//   once at the loop tail, the same typed player-1 ownership used by the exact
//   KillAnyMissingPlayers donor.
// - v10 (sa8b70374_r1): expressed the multiplayer gate as the original
//   positive guarded body with one fall-through return, rather than an early
//   negative return, to test VC5's block placement and local lifetime basin.
// - v11 (sa8b70374_r1): made the negative multiplayer return an explicit
//   if/else arm so the body remains a separate positive region while retaining
//   the oracle's two return sites.
// - v12 (sa8b70374_r1): mirrored the decompiler/PDB condition shape by
//   assigning player=1 inside the Length-and-MaxGamePlayers conjunction,
//   rather than spelling two nested guards.
// - v13 (sa8b70374_r1): corrected the direct-call ABI surface to the exact
//   Com_hand.cpp donor: variadic member Log and CRT C-linkage sprintf, while
//   restoring the cleaner nested guard after the conjunction probe.
// - v14 (sa8b70374_r1): declared the inner dco cursor before player and
//   assigned it only in the MaxGamePlayers arm, probing the original dco/player
//   stack-home ordering without changing the observed loop behavior; emitted
//   code was unchanged from v13.
// - bounded pass result: direct this access, canonical HOLDER/serial/dcoID
//   ownership, typed donor ABI, natural nested loops, and guard/local-order
//   probes all preserve the same 457-byte VC5 basin.  The positive-gate
//   diagnostic was 456 bytes but collapsed the oracle's separate early return;
//   it was not retained.
// Prior structural gap: behavior and the eight-call set were reconstructed, but
// the earlier source model used the wrong register basin.
// The resolved model keeps the original 0xC frame, saved EBX/ESI, eight calls,
// and byte-offset ownership.
// Follow-up pass: same-TU zero-local and pno-scope probes were codegen duplicates or
// worse. A positive guard improved the metric to 398 bytes but lost the separate early
// return topology. Restored the negative guard. Exact KillAnyMissingPlayers ownership
// also confirms COMMPLAYEROPTIONS::dcoID; the nested type is retained although bytes stay
// unchanged. A fully indexed HOLDER scan widened the frame and was rolled back.
// fresh shardC3 probe: the first checker hunk and PDB 3080/3142 bands led to a
// positive Multiplayer guard with one natural common return. It reached the prior
// 398-byte diagnostic basin but emitted one return instead of the oracle's two;
// restored the negative guard and kept the typed owner-lifetime reconstruction.
// shardC5 probe: a typed HOLDER cursor and PlayerHighSerialNumber cursor preserved
// the two clear/process branches and eight calls, but widened the frame to 0x10 and
// worsened the positional diff; restored the clean byte-offset reconstruction.
// Exact follow-up: a byte-offset HOLDER cursor recovered all 485 bytes, but
// main review rejected that source as compiler-steering plumbing. The retained
// source uses typed HOLDER indexing and named player arrays.

typedef unsigned int uint;

#include <stdio.h>

class TDebuggingLog {
public:
    void Log(char* fmt, ...);
};

void operator delete(void* p);
extern TDebuggingLog* L;

static char s_clear_past[] = "+++Clearing PAST OnHold Slot=%d  Serial#%d Len=%d  From=%d  To=%d  HumanSerial#%d";
static char s_cached[] = "Cached Execute #%d  Slot#%d ";
static char s_clearing[] = "Clearing OnHold Slot=%d  Len=%d  From=%d  To=%d";

struct HOLDER { char* HoldMsg; uint Serial; uint Length; uint dcoFromID; uint dcoReceiveID; uint fromPlayer; };
struct COMMPLAYEROPTIONS { char gap_00[0x14]; uint dcoID[10]; };

class TCommunications_Handler {
public:
    char gap_0000[0x0fc5]; char TBuff[0x101];
    char gap_10c6[0x10e0 - 0x10c6];
    uint Me; int Multiplayer;
    char gap_10e8[0x12d8 - 0x10e8]; unsigned short MaxGamePlayers;
    char gap_12da[0x1524 - 0x12da]; HOLDER* OnHold;
    uint PlayerHighSerialNumber[10];
    COMMPLAYEROPTIONS PlayerOptions;
    int IsPlayerHuman(uint player);
    int PreprocessMessages(uint len, void* msg, uint from, uint to, int cached);
    uint ExecuteIncoming();
};

uint TCommunications_Handler::ExecuteIncoming()
{
    if (this->Multiplayer == 0) {
        return 0;
    } else {
        for (uint pno = 0; pno < 502; ++pno) {
            HOLDER* entry = &this->OnHold[pno];
            if (entry->Length != 0) {
                for (uint player = 1; player <= this->MaxGamePlayers; ++player) {
                    if (this->IsPlayerHuman(player) && player != this->Me) {
                        uint humanSerial = this->PlayerHighSerialNumber[player] + 1;
                        uint dco = this->PlayerOptions.dcoID[player];
                        if (entry->Serial < humanSerial && entry->dcoFromID == dco) {
                            L->Log(s_clear_past, pno, entry->Serial, entry->Length,
                                   entry->dcoFromID, entry->dcoReceiveID, humanSerial);
                            if (entry->HoldMsg != 0) {
                                operator delete(entry->HoldMsg);
                            }
                            entry->HoldMsg = 0;
                            entry->Serial = 0;
                            entry->Length = 0;
                            entry->dcoFromID = 0;
                            entry->dcoReceiveID = 0;
                        }
                        if (entry->Serial == humanSerial && entry->dcoFromID == dco) {
                            sprintf(this->TBuff, s_cached, humanSerial, pno);
                            L->Log(this->TBuff);
                            this->PreprocessMessages(entry->Length, entry->HoldMsg,
                                                     entry->dcoFromID,
                                                     entry->dcoReceiveID, 1);
                            L->Log(s_clearing, pno, entry->Length,
                                   entry->dcoFromID, entry->dcoReceiveID);
                            if (entry->HoldMsg != 0) {
                                operator delete(entry->HoldMsg);
                            }
                            entry->HoldMsg = 0;
                            entry->Serial = 0;
                            entry->Length = 0;
                            entry->dcoFromID = 0;
                            entry->dcoReceiveID = 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
