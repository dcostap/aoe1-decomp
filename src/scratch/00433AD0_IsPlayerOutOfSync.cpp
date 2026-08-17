// VA: 00433AD0 IsPlayerOutOfSync (610B)
// com_sync.cpp lines 345-435
//
// Attempt log:
// - Replaced the placeholder with the checksum-record search, comparison,
//   human-player count, and original diagnostic logging flow.
// - Mirrored the binary-supported local order and preserved both the base
//   WTurn cursor and a moving lookup cursor; this restores the 0x28 frame and
//   the two-scan ownership, but VC5 still colors the opening registers and a
//   few late tails differently (580B emitted versus 610B original).
// - Ten hypotheses exhausted. Register-forcing aliases, extra duplicate
//   checksum homes, and explicit loop-polarity scaffolding were not retained.
// - Fresh bounded pass: changed the first checksum search to a natural bounded
//   for loop with header increment. This restores the oracle's two-jump CFG
//   shape and improves positional diff 557 -> 544 bytes and shape 69.12% ->
//   70.18%; the prologue and later typed-record layout still differ.
// - Replaced the local record reference with direct typed Check[firstIndex]
//   field accesses. The packet-backed +0x30 record base and 0x24 stride now
//   reproduce the saved-this prologue and original indexed load topology;
//   diff improves 544 -> 523 bytes and shape 70.18% -> 73.83%. Keep this
//   natural typed form; remaining drift is local-home initialization order.
// - Replaced the first raw PlayerNo/WTurn predicate with named Check[index]
//   fields. This is closer to the period-typed ownership and improves the
//   current diff 523 -> 517 bytes and shape 73.83% -> 74.30%.
// - Split local declarations from their ordered zero assignments, corrected
//   checksum field widths, and changed declaration order. VC5 emitted the
//   same code; retain the simpler declaration order and typed record widths.
// - Tried the final-gate operand rewrite and an early-return layout. The
//   operand rewrite was neutral. The early-return form dropped one Log call
//   and widened structural drift, so it was rolled back.
// - Tried a typed checksum-record cursor for the first search. It changed the
//   prologue, dropped one Log call, and widened drift; the WTurn cursor stays.
// - Revisited the typed source with the existing checksum-record ownership.
//   Moving the found flag assignment after the selected-record loads produced
//   a closer natural basin: 483 differing bytes versus the 517-byte baseline.
// - Kept the parameter-left player comparison in the second checksum scan and
//   made the humanity scan use a separate signed index; this recovers the
//   original signed JLE without changing the unsigned checksum-loop bound.
// - Recovered the late layout with an early negative count guard and a
//   positive player-count arm. This preserves the original diagnostic call
//   order and reaches 44.86% exact-block coverage, but is not an exact match.
// - A block-local typed record pointer, a bool found flag, and removal of the
//   pre-search WTime zero were worse. They were removed or restored.

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

extern TDebuggingLog* L;

class TCommunications_Handler {
public:
    int GetPlayerHumanity(unsigned int player);
};

struct RGE_Communications_Check {
    unsigned int PlayerNo;
    unsigned long WTime;
    unsigned long WTurn;
    long cs1;
    long cs2;
    long cs3;
    long cs4;
    long cs5;
    unsigned int Random;
};

class RGE_Communications_Synchronize {
public:
    TCommunications_Handler* Comm;
    int CheckTime;
    int CheckTurn;
    int StopOnSyncFail;
    int DialogOnSyncFail;
    int SendChatMsgs;
    int NewData;
    int LastResult;
    int Offset;
    int DoChecksums;
    int LastWorldRandom;
    int GameWorldChecksum;
    RGE_Communications_Check Check[0x37];

    int IsPlayerOutOfSync(unsigned int playerNo, unsigned long commTurn);
};

int RGE_Communications_Synchronize::IsPlayerOutOfSync(
    unsigned int playerNo, unsigned long commTurn) {
    unsigned long uVar5;
    unsigned long* puVar8 = &this->Check[1].WTurn;
    int NumPlayers;
    int NumDiff;
    int bVar1;
    long lVar6;
    long mycs5;
    long mycs2;
    long mycs3;
    int NumSame;
    unsigned int local_8;
    int foundMine;

    uVar5 = 0;
    NumPlayers = 0;
    NumDiff = 0;
    bVar1 = 0;
    lVar6 = 0;
    mycs5 = 0;
    mycs2 = 0;
    mycs3 = 0;
    NumSame = 0;
    local_8 = 0;
    foundMine = 0;

    unsigned long* puVar2 = puVar8;
    unsigned int firstIndex = 1;
    for (; firstIndex <= 0x36; ++firstIndex, puVar2 += 9) {
        if (this->Check[firstIndex].PlayerNo == playerNo &&
            this->Check[firstIndex].WTurn == commTurn) {
            mycs5 = this->Check[firstIndex].cs2;
            mycs2 = this->Check[firstIndex].cs3;
            uVar5 = this->Check[firstIndex].WTime;
            mycs3 = this->Check[firstIndex].cs4;
            NumSame = this->Check[firstIndex].cs5;
            lVar6 = this->Check[firstIndex].cs1;
            local_8 = this->Check[firstIndex].Random;
            bVar1 = 1;
            break;
        }
    }

    if (!bVar1) {
        L->Log("OUTOFSYNC: DIDN'T FIND MY VALUES");
        return 0;
    }

    L->Log("OUTOFSYNC: my values: %d %d %d %d %d %d",
           uVar5, lVar6, mycs5, mycs2, mycs3, NumSame);

    unsigned int i = 1;
    do {
        if (playerNo != puVar8[-2] && puVar8[0] == commTurn) {
            if (uVar5 == puVar8[-1] &&
                lVar6 == puVar8[1] &&
                mycs5 == puVar8[2] &&
                mycs2 == puVar8[3] &&
                mycs3 == puVar8[4] &&
                NumSame == puVar8[5] &&
                local_8 == puVar8[6]) {
                ++NumDiff;
                L->Log("OUTOFSYNC: %d same: %d %d %d %d %d %d",
                       i, uVar5, lVar6, puVar8[0],
                       mycs2, mycs3, NumSame);
            } else {
                ++NumPlayers;
                L->Log("OUTOFSYNC: %d diff: %d %d %d %d %d %d",
                       i, uVar5, lVar6, puVar8[0],
                       mycs2, mycs3, NumSame);
            }
        }
        ++i;
        puVar8 += 9;
    } while (i <= 0x36);

    int player = 1;
    do {
        if (this->Comm->GetPlayerHumanity(player) == 2) {
            ++foundMine;
        }
        ++player;
    } while (player <= 9);

    L->Log("OUTOFSYNC: numplayers=%d, diff=%d, same=%d",
           foundMine, NumPlayers, NumDiff);

    if (NumDiff + NumPlayers < foundMine - 1) {
        L->Log("OUTOFSYNC: return not out");
        return 0;
    }

    if (NumPlayers > NumDiff) {
        L->Log("OUTOFSYNC: return out");
        return 1;
    }

    L->Log("OUTOFSYNC: return not out 2");
    return 0;
}
