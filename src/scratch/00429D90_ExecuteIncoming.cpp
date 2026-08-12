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
// BLOCKER: behavior and the eight-call set are reconstructed, and the rebuilt
//   frame is 0xC, but the original is 485 bytes with saved EBX/ESI while VC5
//   keeps this in EDI and spills the byte offset/local pair.  The remaining
//   structural gap is the prologue/register and stack-home topology plus the
//   resulting clear-entry/loop-update spans; no productive source hypothesis
//   remained within this bounded pass.  Current source is the clean typed
//   reconstruction, not the shorter positive-gate diagnostic.
// Follow-up pass: same-TU zero-local and pno-scope probes were codegen duplicates or
// worse. A positive guard improved the metric to 398 bytes but lost the separate early
// return topology. Restored the negative guard. Exact KillAnyMissingPlayers ownership
// also confirms COMMPLAYEROPTIONS::dcoID; the nested type is retained although bytes stay
// unchanged. A fully indexed HOLDER scan widened the frame and was rolled back.

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
    uint offset = 0;

    if (this->Multiplayer == 0) {
        return 0;
    } else {
        uint pno = 0;
        do {
            if (*(uint*)((char*)&this->OnHold->Length + offset) != 0) {
                uint* dco;
                uint player = 1;
                if (this->MaxGamePlayers >= 1) {
                    dco = this->PlayerOptions.dcoID + 1;
                    do {
                        if (this->IsPlayerHuman(player) && player != this->Me) {
                        uint humanSerial = *(dco - 15) + 1;
                        HOLDER* entry = (HOLDER*)((char*)this->OnHold + offset);
                        uint serial = *(uint*)((char*)&this->OnHold->Serial + offset);
                        if (serial < humanSerial && *(uint*)((char*)&this->OnHold->dcoFromID + offset) == *dco) {
                            L->Log(s_clear_past, pno, serial, *(uint*)((char*)&this->OnHold->Length + offset), *(uint*)((char*)&this->OnHold->dcoFromID + offset), *(uint*)((char*)&this->OnHold->dcoReceiveID + offset), humanSerial);
                            if (entry->HoldMsg != 0) operator delete(entry->HoldMsg);
                            entry->HoldMsg = 0; entry->Serial = 0; entry->Length = 0; entry->dcoFromID = 0; entry->dcoReceiveID = 0;
                        }
                        if (*(uint*)((char*)&this->OnHold->Serial + offset) == humanSerial && *(uint*)((char*)&this->OnHold->dcoFromID + offset) == *dco) {
                            sprintf(this->TBuff, s_cached, humanSerial, pno);
                            L->Log(this->TBuff);
                            entry = (HOLDER*)((char*)this->OnHold + offset);
                            this->PreprocessMessages(entry->Length, entry->HoldMsg, entry->dcoFromID, entry->dcoReceiveID, 1);
                            L->Log(s_clearing, pno, entry->Length, entry->dcoFromID, entry->dcoReceiveID);
                            if (entry->HoldMsg != 0) operator delete(entry->HoldMsg);
                            entry->HoldMsg = 0; entry->Serial = 0; entry->Length = 0; entry->dcoFromID = 0; entry->dcoReceiveID = 0;
                        }
                        }
                    player++;
                    dco++;
                    } while (player <= this->MaxGamePlayers);
                }
            }
            offset += 0x18;
            pno++;
        } while (offset <= 0x2ef8);
    }
    return 0;
}
