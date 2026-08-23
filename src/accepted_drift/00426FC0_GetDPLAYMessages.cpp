// VA: 00426FC0 TCommunications_Handler::GetDPLAYMessages
// PDB source: Com_hand.cpp lines 965-1113
// attempt log:
// 1: natural reconstruction from packet/decompiler, COM v44/v64 as __stdcall virtuals; exact 819B but broad 79.61% positional / 94.14% edit mismatch, first diff frame 0x18 vs 0x14.
// 2: inlined duplicated player-index scans instead of helper; edit diff improved to 59.46%, positional still broad and frame 0x14.
// 3: added volatile local_4 stack pressure; no frame improvement and worsened diff to 81.20%/61.54%, rolled back.
// 4: flag probes: /O2 no-/Oy and /GX same mismatch; /O1 shrinks to 733B; /Od same size but broad mismatch from offset 0. Rolled back to default /O2 /Oy.
// 5: kept direct COM vtable calls and direct member calls for PreprocessMessages/EvaluateSystemMessage; call set/behavior plausible but prologue/local scheduling differs from original.
// session: terminal EvaluateSystemMessage return restored the oracle's 21-call/3-return
// CFG. Unsigned HighPlayerNumber(+1710)/LowPlayerNumber(+1712) bounds recover the
// zero-extend loop shape; explicit persistent COM caching and raw vtable surfaces
// were worse. Remaining drift is frame/local-home and COM argument scheduling.
// probe: use signed loop indices with unsigned-short bounds; original scan branches
// use signed JG after zero-extension, unlike the current unsigned JA branches.
// follow-up: removing the pre-guard dcoFromID zero-init shrank code by 4 bytes,
// but positional diff worsened from 792 to 807; rolled back to the clean source.
// FLAGS: config/flags/00426FC0_GetDPLAYMessages.rsp (/nologo /c /O2 /Oy)
// left in scratch: the remaining drift is the initial timer-call cleanup and
// the duplicated player-ID scan register shape; calls and frame are aligned.
// fresh pass: model the binary's separate peek-size and receive-size homes; the
// oracle copies the peek result into the receive size before the second call.
// probe: the peek count, not the receive size, drives the overflow check.
// probe: the peek Receive preserves the prologue-zeroed from-ID; it is not reset
// at the top of each loop.
// probe: loading a guard receiver before ID zeroing reproduces the exact prologue
// and keeps the repeated global DirectPlay loads in the call sites.
// subagent pass: typed external L/DAT globals removed raw global dereferences;
// this reduced the size gap from +37B to -10B and raised block coverage to 93.89%.
// subagent pass: a same-TU for scan with signed int bounds and direct dcoID
// ownership recovered both loop blocks exactly. Pointer and while variants did not.
// subagent pass: separate result locals, result initialization, guard inversion,
// hoisted scan locals, pointer-base caching, and explicit log labels did not fix
// the second found arm. The literal strings and const timer declaration were neutral.
// subagent pass: a late label after the receive loop was tested from the PDB late
// block, but VC5 folded it back into the hot path. The clean natural source remains
// 809B versus 819B, 21/21 ordered calls, 231 strict-diff bytes (28.2051%),
// and 93.89% block coverage.
// final unresolved pass: 20 meaningful hypotheses tested. The remaining mismatch
// is the second player scan's rare found arm: the oracle branches to +32EC, moves
// EBP, then jumps to the log block; natural VC5 source keeps that move inline.
// Accepted-drift review: the found arm and no-match arm produce the same player
// number before logging. All 21 DirectPlay, timer, log, error, preprocess, and
// system-message calls preserve arguments and order. Peek/receive sizes, IDs,
// overflow handling, counters, terminator store, loop state, and returns match.
// Residual drift is rare-arm placement and equivalent register scheduling.

#include "../../include/com_hand_context.h"

typedef unsigned long ulong;
#if 0
extern ulong __cdecl debug_timeGetTime(const char* file, int line);
class TDebuggingLog { public: void Log(char* fmt, ...); };
class RGE_Comm_Error { public: void ShowReturn(long result, char* msg); };
class IDirectPlay4A;
extern TDebuggingLog* L;
extern IDirectPlay4A* DAT_0062c5ec;
extern ulong DAT_0062cf04;

class IDirectPlay4A {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40();
    virtual long __stdcall GetMessageCount(ulong id, ulong* count);
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60();
    virtual long __stdcall Receive(ulong* from, ulong* to, unsigned long flags, void* data, ulong* size);
};

class TCommunications_Handler {
public:
    char gap_0000[0x24];
    char InCommBuff[0x1000];
    char gap_1024[0x12B8-0x1024];
    ulong RXPacketLength;
    char gap_12BC[0x1334-0x12BC];
    ulong RXPackets;
    char gap_1338[0x14E0-0x1338];
    RGE_Comm_Error* Err;
    char gap_14E4[0x1564-0x14E4];
    ulong dcoID[64];
    char gap_1664[0x1710-0x1664];
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    void GetDPLAYMessages();
    void EvaluateSystemMessage(ulong size, char* msg, int a, ulong to);
    int PreprocessMessages(ulong size, char* msg, ulong from, ulong to, int cached);
};
#endif

void TCommunications_Handler::GetDPLAYMessages() {
    ulong dcoFromID;
    ulong dcoReceiveID;
    ulong dwCount;
    ulong dwPreSize;
    ulong dwSize;
    ulong local_4;
    long hr;
    IDirectPlay4A* guard_dplay = DAT_0062c5ec;
    dcoFromID = 0;
    dcoReceiveID = 0;
    if (guard_dplay == 0) return;
    dwCount = 4000;
    dwSize = 4000;
    char* buf = this->InCommBuff;
    local_4 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x3d4);
    dwPreSize = 0;
    hr = DAT_0062c5ec->GetMessageCount(DAT_0062cf04, &dwPreSize);
    if (hr == 0 && dwPreSize > 10) L->Log((char*)"!!! DPMsgCount = %u", dwPreSize);
    while (1) {
        ulong t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x3e1);
        hr = DAT_0062c5ec->Receive(&dcoFromID, &dcoReceiveID, 8, 0, &dwCount);
        ulong elapsed = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x3ec) - t;
        if (elapsed > 50) L->Log((char*)"!!! Receive Peek slow - %u msec", elapsed);
        if (hr == 0 && dwCount >= 4000) { L->Log((char*)"True overflow %d requested.  Max = %d", dwCount, 4000); return; }
        dwSize = dwCount;
        if (hr != 0) dwSize = 4000;
        t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x403);
        hr = DAT_0062c5ec->Receive(&dcoFromID, &dcoReceiveID, 1, buf, &dwSize);
        elapsed = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x40c) - t;
        if (elapsed > 50) L->Log((char*)"!!! Receive slow - %u msec", elapsed);
        elapsed = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x417) - local_4;
        if (elapsed > 500) {
            ulong now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x419);
            L->Log((char*)"!!! In Receive Loop for %u ms", now - local_4);
        }
        if (hr == (long)0x887700BE) return;
        if (dwSize == 0) return;
        if (hr != 0) { this->Err->ShowReturn(hr, (char*)"Rcv MSG"); return; }
        int pno;
        if (dcoFromID != 0) {
            int i = this->PlayerOptions.LowPlayerNumber;
            int hi = this->PlayerOptions.HighPlayerNumber;
            if (i <= hi) {
                ulong* p = this->PlayerOptions.dcoID + i;
                for (; i <= hi; i++, p++) {
                    if (*p == dcoFromID)
                        goto found_first_player;
                }
            }
            i = 0;
found_first_player:
            pno = i;
        } else pno = 0;
        L->Log((char*)"  >RX #%d %c-%d (%u)", pno, (int)*buf, (int)*buf, dwSize);
        if (dcoFromID != 0) {
            int i = this->PlayerOptions.LowPlayerNumber;
            int hi = this->PlayerOptions.HighPlayerNumber;
            if (i <= hi) {
                ulong* p = this->PlayerOptions.dcoID + i;
                for (; i <= hi; i++, p++) {
                    if (*p == dcoFromID)
                        goto found_second_player;
                }
            }
            i = 0;
found_second_player:
            pno = i;
        } else pno = 0;
        L->Log((char*)"COMM: RX P#%d ID(%ld) siz=%db   MSG=%d '%c'", pno, dcoFromID, dwSize, (int)*buf, (int)*buf, debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x435));
        this->RXPacketLength += dwSize;
        this->RXPackets++;
        buf[dwSize] = 0;
        if (dcoFromID != 0) this->PreprocessMessages(dwSize, buf, dcoFromID, dcoReceiveID, 0);
        else {
            this->EvaluateSystemMessage(dwSize, buf, 0, dcoReceiveID);
            return;
        }
    }
}
