// 00428DA0 TCommunications_Handler::EvaluateSystemMessage (Com_hand.cpp:2411-2771)
// __thiscall (unsigned long p1, char* p2, unsigned long p3, unsigned long p4) -> void, ret 10h
// DPLAY system-message dispatcher: switch on *(unsigned long*)p2 with low-value sub-chain
// (3/5/7) + byte-table jump dispatch for 0x31..0x109; default logs "COMM:Unknown".
//
// Attempt log:
// - Baseline: natural switch reconstruction; local class stub modeled on exact donors
//   00428B10 (DropDeadPlayer), 0042D2D0 (InitPlayerInformation), 0042EA10 (Kick),
//   00429A90 (SendIResignMsg). Size/frame/call-count matched from the start (2235/0xC/75).
// - case5 scan: single-variable `unsigned short i` loop produced 16-bit compares +
//   and-masking; original is 32-bit signed jg/jle with a cold `mov esi,eax; jmp` found
//   block. Fixed with the UpdatePlayerInformation (0042D120) idiom: separate `int p`/
//   `int high` induction locals + `unsigned int i` result, `i = p; goto found2`, and
//   `i = 0` at the join -> exact cold found-block topology. Result check is `i <= 0`
//   (unsigned jbe) per original bytes.
// - Switch expression: using a `msg` local kept the value in callee-saved edi; the
//   original reloads [ebx] after the Log call and keeps it in volatile ecx. Dropped
//   the local: Log arg + switch expr + default all use *(unsigned long*)p2 directly.
// - case3: goto-found empty-slot scan (Humanity[i]==0) matches the 32-bit guard/bottom;
//   InitPlayerInformation and GIP/GIP2 args re-read *(unsigned long*)(p2+8) per original.
//   `p3 = newid` models the observed param-slot reuse (original spills newid to the
//   param_3 slot; rebuilt picks the dead param_2 slot -> 4-byte displacement diff).
// - case0x102 serial loops: pointer-based (`unsigned int* p = &PlayerHighSerialNumber[1]`,
//   dcoID via *(p+15)) with `unsigned int i` + ser/p declared inside the guard; matches
//   the original 16-bit guard + 32-bit bottom compare + [edi+3Ch] access exactly.
// - Case order: physical handler order follows source order for the table cases
//   (0x109 early, 0x101/0x31 swapped, 0x107 before 0x104) - reordering to the original's
//   physical order improved edit diff 855->593 and block coverage to ~79%.
// - REMAINING GAP: VC5 places the default handler inline right after the sub-chain
//   (rebuilt `sub eax,2; je case7` + inline default) instead of at the function end
//   (original `jne near default; jmp case7`). Tried default-case, post-switch
//   fall-through, and case reordering - all emit the inline default (stable basin).
//   Several Log sites differ by 1 byte from `mov eax,[L]` (A1) vs `mov ecx,[L]` (8B 0D)
//   register choice. Best: 1969 pos diff (88.1%), edit 593 (13.3%), shape 95.3%,
//   exact-block 78.6%, calls 75/75.
// - Left in scratch: unresolved but structurally strong; next lead is steering the
//   default block to the end (block-layout probe) and matching the L-load register.
// - ABI probe: the original 00436610 target is the static class member
//   TDebuggingLog::Log(TDebuggingLog*, const char*, ...), not a free helper
//   or non-static member. The class tag produces the original PAV1 binding.
//   The corrected relocation is exact, but whole-function bytes are unchanged.

#include <stdio.h>
#include <string.h>

class TDebuggingLog {
public:
    static void __cdecl Log(TDebuggingLog* log, const char* fmt, ...);
    void FlushLog();
};
extern TDebuggingLog* L;                          // 62C4FCh
extern "C" int g_DirectPlayConversation;          // 62C5ECh

struct MSGFORMAT_KILL_PLAYER {
    int dcoID;
    int CurrentTurn;
    int current_turn;
};

struct COMMPLAYEROPTIONS {
    unsigned char NeedsToBeSent;       // +0x00 (0x1550)
    unsigned char _pad0[3];
    unsigned long LastSentTime;        // +0x04
    int ProgramState;                  // +0x08
    unsigned long CurrentTurn;         // +0x0C
    unsigned char TurnSpeedMsec;       // +0x10
    unsigned char _pad1[3];
    unsigned long dcoID[10];           // +0x14 (0x1564)
    unsigned long AcknowledgeAfterMsec; // +0x3C (0x158C)
    unsigned char CommandTurnIncrement; // +0x40
    unsigned char _pad2[3];
    int PlayerReady[10];               // +0x44
    unsigned long User1[10];           // +0x6C
    unsigned long User2[10];           // +0x94
    unsigned long User3[10];           // +0xBC
    unsigned long User4[10];           // +0xE4
    unsigned long User5[10];           // +0x10C
    unsigned long User6[10];           // +0x134
    unsigned long User7[10];           // +0x15C
    int Humanity[10];                  // +0x184 (0x16D4)
    unsigned char InvalidPlayer[10];   // +0x1AC (0x16FC)
    unsigned char _pad3[2];
    unsigned long Initialized;         // +0x1B8
    unsigned long RandomSeed;          // +0x1BC
    unsigned short HighPlayerNumber;   // +0x1C0 (0x1710)
    unsigned short LowPlayerNumber;    // +0x1C2 (0x1712)
    unsigned int HostPlayerNumber;     // +0x1C4 (0x1714)
    int GameHasStarted;                // +0x1C8 (0x1718)
    unsigned long DataSizeToFollow;    // +0x1CC (0x171C)
};

class TCommunications_Handler {
public:
    char gap_00[0x1C];
    int MeHost;                             // +0x1C
    char gap_20[0xFC5 - 0x20];
    char TBuff[1];                          // +0xFC5
    char gap_FC6[0x10C8 - 0xFC6];
    unsigned int current_turn;              // +0x10C8
    char gap_10CC[0x10DC - 0x10CC];
    unsigned int AcknowledgeAfterMsec;      // +0x10DC
    unsigned int Me;                        // +0x10E0
    unsigned int Multiplayer;               // +0x10E4
    char gap_10E8[0x12D8 - 0x10E8];
    unsigned short MaxGamePlayers;          // +0x12D8
    char gap_12DA[0x13BC - 0x12DA];
    int PlayerStopTurn[16];                 // +0x13BC
    char gap_13FC[0x14E4 - 0x13FC];
    unsigned int GTDSerialNo;               // +0x14E4
    char gap_14E8[0x1528 - 0x14E8];
    unsigned int PlayerHighSerialNumber[10]; // +0x1528
    COMMPLAYEROPTIONS PlayerOptions;        // +0x1550

    void NotifyWindow(int msg);
    void NotifyWindowParam(int msg, int player);
    int IsPlayerHuman(unsigned int player);
    void InitPlayerInformation(unsigned int player, int human, char* status, char* info);
    void UpdatePlayers();
    int CalculatePlayerRange();
    void DropDeadPlayer(unsigned int player, unsigned long dpid);
    void UpdatePlayer(unsigned int player, int param);
    void ClearRXTXForPlayer(unsigned int player);
    long SendSharedData(int force);
    long FastSend(unsigned long to, void* data, unsigned long size, int param_4, int param_5);
    void CheckPingTime(int param_1);
    long EnableNewPlayers(int direct_play, int enable_links);
    void KillAnyMissingPlayers();
    int SetMyGameOptions(char* param_1, unsigned long param_2);
    void SetSelfPlayer();
    void ResetLastCommunicationTimes();
    void ClearRXandTX();
    long CommOut(int type, int msg_type, void* data, long size, int flags);
    void EvaluateSystemMessage(unsigned long p1, char* p2, unsigned long p3, unsigned long p4);
};

#define S(x) ((char*)(x))

void TCommunications_Handler::EvaluateSystemMessage(unsigned long p1, char* p2, unsigned long p3, unsigned long p4)
{
    if (this->Multiplayer == 0) {
        TDebuggingLog::Log(L, S(0x581CD8));          // "!MP in DPANALYSIS"
        return;
    }

    TDebuggingLog::Log(L, S(0x581CC8), *(unsigned long*)p2);         // "DP Sys Msg %d"

    switch (*(unsigned long*)p2) {
    case 5: {                         // DPSYS_DESTROYPLAYERORGROUP
        unsigned long victim = *(unsigned long*)(p2 + 8);
        unsigned int i;
        if (victim != 0) {
            int p = this->PlayerOptions.LowPlayerNumber;
            int high = this->PlayerOptions.HighPlayerNumber;
            if (p <= high) {
                for (; p <= high; p++) {
                    if (this->PlayerOptions.dcoID[p] == victim) {
                        i = p;
                        goto found2;
                    }
                }
            }
        }
        i = 0;
found2:
        TDebuggingLog::Log(L, S(0x581C90));          // "DPMSG_DESTRPYPLAYERORGROUP  (to debug drop player)"
        TDebuggingLog::Log(L, S(0x581C78), *(unsigned long*)(p2 + 8));  // "FROM Player ID =..."
        TDebuggingLog::Log(L, S(0x581C5C), i);       // "Equates to our player # %d "
        TDebuggingLog::Log(L, S(0x581C40), this->PlayerOptions.ProgramState);  // "Program state is..."
        L->FlushLog();
        if (this->IsPlayerHuman(i) != 0 && this->PlayerStopTurn[i] == 0) {
            if (i == this->Me)
                this->NotifyWindow(0x17B2);
            else
                this->NotifyWindowParam(0x17B3, i);
        }
        if (this->MeHost == 0)
            return;
        MSGFORMAT_KILL_PLAYER kp;
        kp.dcoID = i;
        kp.CurrentTurn = *(unsigned long*)(p2 + 8);
        kp.current_turn = this->current_turn;
        TDebuggingLog::Log(L, S(0x581C14), i, kp.CurrentTurn);  // "HOST Send to all - drop player %d ID=%d "
        TDebuggingLog::Log(L, S(0x581C00), i, 0xC);             // "  >TX KP2 #%d (%d)"
        this->CommOut(0, 'K', &kp, 0xC, 0);
        if (i <= 0)
            return;
        if (this->PlayerStopTurn[kp.dcoID] != 0)
            return;
        this->DropDeadPlayer(i, victim);
        return;
    }

    case 3: {                         // DPSYS_CREATEPLAYERORGROUP
        unsigned long newid;
        unsigned int i;
        newid = *(unsigned long*)(p2 + 8);
        p3 = newid;
        TDebuggingLog::Log(L, S(0x581BEC), newid);   // "RX NEW PLR ID=%d"
        TDebuggingLog::Log(L, S(0x581BCC));          // "COMM: Create Player Request."
        sprintf(this->TBuff, S(0x581B8C), this->MeHost, this->PlayerOptions.ProgramState, newid);
        TDebuggingLog::Log(L, this->TBuff);
        if (this->PlayerOptions.ProgramState == 5 || this->current_turn > 6) {
            *this->TBuff = 'I';
            TDebuggingLog::Log(L, S(0x581B64), *(unsigned long*)(p2 + 8));   // "  >TX GIP %u (1)"
            this->FastSend(*(unsigned long*)(p2 + 8), this->TBuff, 1, 0, 0);
            return;
        }
        if (this->MeHost == 0)
            return;
        i = 1;
        for (; i <= this->MaxGamePlayers; i++) {
            if (this->PlayerOptions.Humanity[i] == 0)
                goto found;
        }
        i = 0;
found:
        if (i != 0 && this->PlayerOptions.ProgramState == 3) {
            this->InitPlayerInformation(i, (int)*(unsigned long*)(p2 + 8), *(char**)(p2 + 0x20), *(char**)(p2 + 0x24));
            this->PlayerOptions.dcoID[i] = p3;
            this->PlayerOptions.Humanity[i] = 2;
            this->PlayerOptions.NeedsToBeSent = 1;
            this->PlayerOptions.InvalidPlayer[i] = 0;
            this->CalculatePlayerRange();
            this->UpdatePlayer(i, 1);
            this->PlayerOptions.NeedsToBeSent = 1;
            this->PlayerHighSerialNumber[i] = i * 2000;
            this->ClearRXTXForPlayer(i);
            this->SendSharedData(0);
            return;
        }
        *this->TBuff = 'I';
        TDebuggingLog::Log(L, S(0x581B78), *(unsigned long*)(p2 + 8));   // "  >TX GIP2 %u (1)"
        this->FastSend(*(unsigned long*)(p2 + 8), this->TBuff, 1, 0, 0);
        this->UpdatePlayers();
        return;
    }

    case 7:
    case 0x105:
        TDebuggingLog::Log(L, S(0x581B30));          // "Add/delete player of group."
        return;

    case 0x109:
        TDebuggingLog::Log(L, S(0x581B24));          // "DP Chat Msg"
        return;

    case 0x21:
        TDebuggingLog::Log(L, S(0x581B4C));          // "delete player of group."
        return;

    case 0x101:
        if (this->PlayerOptions.ProgramState != 3 && this->current_turn >= 6) {
            TDebuggingLog::Log(L, S(0x581B14));      // "Assumed host"
            this->MeHost = 1;
            this->PlayerOptions.HostPlayerNumber = this->Me;
            this->CheckPingTime(1);
            this->UpdatePlayers();
            this->EnableNewPlayers(g_DirectPlayConversation, 0);
            this->CalculatePlayerRange();
            this->NotifyWindowParam(0x17B1, this->Me);
            this->KillAnyMissingPlayers();
            return;
        }
        TDebuggingLog::Log(L, S(0x581AF0));          // "Host (other) Exit before game start"
        this->NotifyWindow(0x17A9);
        this->EnableNewPlayers(g_DirectPlayConversation, 1);
        return;

    case 0x31:
        TDebuggingLog::Log(L, S(0x581AD8));          // "COMM:Host session lost."
        this->PlayerOptions.NeedsToBeSent = 1;
        this->UpdatePlayers();
        this->NotifyWindow(0x17A9);
        return;

    case 0x102: {
        sprintf(this->TBuff, S(0x581A98),
                this->PlayerOptions.dcoID[1], this->PlayerOptions.dcoID[2],
                this->PlayerOptions.dcoID[3], this->PlayerOptions.dcoID[4],
                this->PlayerOptions.dcoID[5], this->PlayerOptions.dcoID[6],
                this->PlayerOptions.dcoID[7], this->PlayerOptions.dcoID[8]);
        TDebuggingLog::Log(L, this->TBuff);
        unsigned int i = 1;
        if (this->MaxGamePlayers >= i) {
            unsigned int ser = 2000;
            unsigned int* p = &this->PlayerHighSerialNumber[1];
            do {
                if (*p == 0 && *(p + 15) != 0) {
                    this->ClearRXTXForPlayer(i);
                    *p = ser;
                    TDebuggingLog::Log(L, S(0x581A70), i, ser + 1);
                }
                i++;
                p++;
                ser += 2000;
            } while (i <= this->MaxGamePlayers);
        }
        if (this->MeHost != 0) {
            TDebuggingLog::Log(L, S(0x581A5C));      // "Host - no rcv opts."
            return;
        }
        TDebuggingLog::Log(L, S(0x581A30));          // "Checking state for options rcvd from host."
        if (this->PlayerOptions.ProgramState != 3)
            return;
        TDebuggingLog::Log(L, S(0x581A10));          // "Group options rcvd from host."
        if (*(unsigned long*)(p2 + 0x10) >= 0x1D0) {
            memcpy(&this->PlayerOptions, *(void**)(p2 + 0xC), 0x1D0);
            if (*(unsigned long*)(p2 + 0x10) >= this->PlayerOptions.DataSizeToFollow + 0x1D0) {
                this->SetMyGameOptions((char*)(*(char**)(p2 + 0xC) + 0x1D0), this->PlayerOptions.DataSizeToFollow);
            }
            this->NotifyWindow(0x17A6);
        }
        this->AcknowledgeAfterMsec = this->PlayerOptions.AcknowledgeAfterMsec;
        this->current_turn = this->PlayerOptions.CurrentTurn;
        this->SetSelfPlayer();
        if (this->PlayerOptions.GameHasStarted != 0) {
            TDebuggingLog::Log(L, S(0x5819FC));      // "Host Launched game"
            this->CalculatePlayerRange();
            TDebuggingLog::Log(L, S(0x5819D8), this->PlayerOptions.ProgramState);  // "OPTIONS SET - program state = %d"
            this->PlayerOptions.ProgramState = 5;
            this->ResetLastCommunicationTimes();
            this->ClearRXandTX();
            for (int j = 1; j <= 9; j++)
                this->PlayerStopTurn[j] = 0;
            {
                unsigned int k = 1;
                if (this->MaxGamePlayers >= k) {
                    unsigned int ser2 = 2000;
                    unsigned int* p2 = &this->PlayerHighSerialNumber[1];
                    do {
                        if (*(p2 + 15) != 0) {
                            *p2 = ser2;
                            TDebuggingLog::Log(L, S(0x581A70), k, ser2 + 1);
                        }
                        k++;
                        p2++;
                        ser2 += 2000;
                    } while (k <= this->MaxGamePlayers);
                }
            }
            this->GTDSerialNo = this->Me * 2000 + 1;
            TDebuggingLog::Log(L, S(0x5819BC), this->GTDSerialNo);  // "Set my serial number to %d"
            this->NotifyWindow(0x17A6);
            this->NotifyWindow(0x17A7);
        } else {
            TDebuggingLog::Log(L, S(0x5819A4));      // "Game not yet started."
        }
        if (this->PlayerOptions.GameHasStarted == 0 && this->GTDSerialNo == 0 && this->Me != 0) {
            this->GTDSerialNo = this->Me * 2000 + 1;
            TDebuggingLog::Log(L, S(0x581974), this->GTDSerialNo);  // "Serial # was 0, setting my serial number to %d"
        }
        this->UpdatePlayers();
        this->NotifyWindow(0x17A6);
        return;
    }

    case 0x103:
        this->UpdatePlayers();
        TDebuggingLog::Log(L, S(0x581958));          // "Set player or group name"
        this->NotifyWindow(0x17A6);
        return;

    case 0x107:
        TDebuggingLog::Log(L, S(0x581944));          // "Secure message dp"
        return;

    case 0x104:
        TDebuggingLog::Log(L, S(0x58192C));          // "Set Sessino Description"
        return;

    case 0x108:
        TDebuggingLog::Log(L, S(0x58190C));          // "START SESSION MESSAGE RCVD. "
        TDebuggingLog::Log(L, S(0x5818FC));          // " *** NOTICE ***"
        return;
    }
    TDebuggingLog::Log(L, S(0x5818DC), *(unsigned long*)p2);     // "COMM:Unknown system message. %d"
}
