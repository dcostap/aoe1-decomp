// 00426350 TCommunications_Handler::KillAnyMissingPlayers()
// Source: Com_hand.cpp lines 383-431
//
// Natural reconstruction from the Com_hand.cpp donor surface.  The first
// dword of MSGFORMAT_KILL_PLAYER is the result of GetPlayerName and is not
// part of the packet sent by CommOut; the packet starts at dcoID.
// Attempt log:
// - Baseline decompiler-shaped declarations: wrong frame and broad call setup drift.
// - Named PlayerStopTurn cursor: removed; the proven dcoID-relative field access
//   restored the original frame, running cursor, and exact loop tail.
// - Caching the typed DirectPlay pointer per call restored both COM call sites.
// - Exact breakthrough: declare the first-call vtable local before zeroing its
//   size variable.  VC5 then emits the original vtable load, argument pushes,
//   and delayed zero store.  The source remains a plausible COM call surface.

#include "../../include/com_hand_context.h"

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

#if 0
class TDebuggingLog {
public:
    static void __cdecl Log(TDebuggingLog* log, const char* format, ...);
};

extern TDebuggingLog* L;
#endif

struct MSGFORMAT_KILL_PLAYER {
    int PlayerNo;
    unsigned long dcoID;
    unsigned long CurrentTurn;
    unsigned long current_turn;
};

struct IDirectPlay;

struct IDirectPlayVtbl {
    char gap_00[0x54];
    long (__stdcall* GetPlayerName)(IDirectPlay* self,
                                    unsigned long player,
                                    void* data,
                                    unsigned long* size);
};

struct IDirectPlay {
    IDirectPlayVtbl* vtbl;
};

#define g_pDirectPlay (*(IDirectPlay**)0x0062C5EC)

#if 0
struct COMMPLAYEROPTIONS {
    char gap_00[0x14];
    unsigned long dcoID[10];
};

class TCommunications_Handler {
public:
    char gap_0000[0x10C8];
    unsigned long current_turn;              // +0x10C8
    char gap_10CC[0x20C];
    unsigned short MaxGamePlayers;           // +0x12D8
    char gap_12DA[0xE2];
    unsigned long PlayerStopTurn[10];        // +0x13BC
    char gap_13E4[0x16C];
    COMMPLAYEROPTIONS PlayerOptions;         // +0x1550

    int IsPlayerHuman(unsigned int player);
    long CommOut(long a, long b, void* data, long size, long flags);
    void DropDeadPlayer(unsigned int player, unsigned long dcoID);

    void KillAnyMissingPlayers();
};
#endif

void TCommunications_Handler::KillAnyMissingPlayers()
{
    MSGFORMAT_KILL_PLAYER kp;
    void* buf;
    IDirectPlay* dp;
    unsigned int i = 1;

    if (i <= this->MaxGamePlayers) {
        unsigned long* dcoID = this->PlayerOptions.dcoID + 1;
        do {
            if (this->IsPlayerHuman(i)) {
                dp = g_pDirectPlay;
                long hr;
                IDirectPlayVtbl* dp_vtbl = dp->vtbl;
                hr = 0;
                dp_vtbl->GetPlayerName(
                    dp, *dcoID, 0, (unsigned long*)&hr);

                buf = operator_new(hr);
                dp = g_pDirectPlay;
                kp.PlayerNo = dp->vtbl->GetPlayerName(
                    dp, *dcoID, buf, (unsigned long*)&hr);
                operator_delete(buf);

                if (kp.PlayerNo != 0) {
                    kp.dcoID = i;
                    kp.CurrentTurn = *dcoID;
                    kp.current_turn = this->current_turn;
                    TDebuggingLog::Log(L, (const char*)0x580D40, i, 0x0C);
                    this->CommOut(0, 0x4B, &kp.dcoID, 0x0C, 0);

                    // PlayerStopTurn[i] is the proven field at dcoID[i]-0x1A8;
                    // the running dcoID cursor keeps the original packed-array
                    // ownership and addressing shape.
                    if (dcoID[-0x6A] == 0) {
                        this->DropDeadPlayer(i, *dcoID);
                    }
                }
            }

            ++i;
            ++dcoID;
        } while (i <= this->MaxGamePlayers);
    }
}
