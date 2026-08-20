// 004282C0 TCommunications_Handler::EvaluatePlayerMessage
// Com_hand.cpp
// Attempt log:
// behavior-first reset: restored the sparse wire opcodes and named handler calls from the packet.
// typed the player-options ownership: dcoID, command-turn increment, and low/high player bounds.
// try 1: broad switch reconstruction from packet: message opcode dispatch to lobby/session/chat/control handlers.
// try 2: modeled early multiplayer guard at +0x10E4 returning 0, preserving original prologue register set (EBX/ESI/EDI) in broad form.
// try 3: modeled parameter surface as nine stack args, with opcode in arg4 and data pointer in arg6, matching packet stack references.
// try 4: implemented turn-speed message path: SetPlayerTurnSpeed from data[8]/data[9], regression warning when message turn < current_turn, lastTurn[player] update with latencyBase subtraction.
// try 5: implemented simple receive helper path at 004286F0, stats 9-argument path at lobby/stats +0x14D8, and generic six-arg receive path at 00426470.
// try 6: implemented speed update with two shorts and p5, and chat text path with logging, local-player/mode check, and chat sink display using player-name 0x80 stride.
// try 7: implemented pause/resume/control paths calling 0042C860/0042C840/0042C880-style helpers and zeroed stats reset call.
// try 8: implemented player-id lookup path: log incoming id, scan dpid range minPlayer..maxPlayer at +0x1564, add missing player flag, update local/remote UI.
// try 9: implemented default unknown opcode log with opcode twice, matching observed varargs shape.
// try 10: current source compiles to exact 972B, but broad mismatch remains: first 34 bytes match, then switch range differs because natural case labels are compact 0x44..0x4F while original normalizes opcode-0x2B and uses a sparse 0x2C range jump table.
// try 11: reviewed diff: major remaining drift is opcode mapping/jump table plus many handler argument/order details; behavior is only approximate in some helper surfaces.
// left in scratch: size-matched broad reconstruction, but exact sparse switch mapping and handler call surfaces are unresolved. No accepted_drift: broad switch/control-flow/call-surface drift.
// behavior-first baseline: the current source supersedes the compact-label attempt with the exact sparse opcode set and named calls.
// call-map baseline: all 24 original direct calls align by target and order; remaining drift is codegen structure, not a missing handler.
// left in scratch: clean behavior reconstruction is complete; exact codegen was not tuned in this tranche.
// try 13: model the kill-message lookup as one bounded natural index, resetting it only after an unsuccessful scan.
// try 14: keep the kill identifier declaration after the diagnostic call, matching the original handler's evaluation order.
// try 15: let the scan index carry the found player number, avoiding a second result local.
// try 16: rolled back a named advancing pointer; it added 105 bytes and reduced shape similarity.
// try 17: rolled back a shared success goto; it added 101 bytes and reduced shape similarity.
// try 18: dispatch on the wire opcode relative to the first protocol message; no emitted change, so retain the clean sparse switch.
// try 19: named COMMPLAYEROPTIONS ownership; codegen unchanged and retained as canonical layout.
// try 20: split turn subtraction; codegen unchanged.
// try 21: volatile packet-turn load forced the original arithmetic registers and reduced the diagnostic diff to 44 bytes; not retained as source without behavioral evidence.
// try 22: signed scan index/high bound improved the diagnostic diff to 42 bytes.
// try 23: delayed scan-index zero arm improved the diagnostic diff to 31 bytes; the remaining gap is DCO register coloring and switch-table relocation.
// Continuation pass (sa-163f5bba-r1, 2026-08-17):
// - Baseline pinned at 972 bytes, 24 ordered calls, 747 strict diff bytes, and 97.05% shape similarity.
// - Tested kill-scan goto forms, two-local candidate/result forms, declaration order, and failure-only labels.
//   The two-local form improved resynchronization but added a branch and 8 diff bytes; all were rolled back.
// - Tested received-turn temporaries, compound assignment, increment aliases, signed result width, and volatile load.
//   The ordinary forms were duplicate codegen; volatile added 101 bytes and was rejected as unsupported steering.
// - Tested opcode local materialization, direct kill-packet loads, signed stop-turn fields, register data pointer,
//   Windows/string/stdlib headers, and a VC5 risky flag sweep. They were neutral or worse. The flag sweep found
//   no invariant-eligible exact variant; default flags remained the only 972-byte basin.
// - Final clean validation: calls 24/24 aligned, no frame, saved EBX/ESI/EDI, 972/972 bytes, 747 strict diff.
// Next evidence: recover original Com_hand.cpp declaration/TU context or the natural kill-scan source layout.
// Review blocker: the original 0x44 arm reads data+4 before it reads
// PlayerOptions.CommandTurnIncrement. The rebuild reads the member first.
// This changes the first failing read for an invalid packet or invalid object.
// The later kill-scan register choice and duplicate bound test are mechanical,
// but they do not remove this pointer-read-order blocker.

struct TDebuggingLog { void Log(char*, ...); };
extern TDebuggingLog* L;

#define S(address) ((char*)(address))

class RGE_Communications_Speed {
public:
    void SetPlayerTurnSpeed(unsigned int, unsigned char, unsigned char);
    void SetFutureSpeedChange(unsigned int, unsigned int, unsigned long);
};

class RGE_Communications_Synchronize {
public:
    int Add(unsigned int, unsigned long, unsigned long, unsigned long,
            long, long, long, long, long);
    void LogChecksums(unsigned int, unsigned long, unsigned long,
                      long, long, long, long, long, unsigned long);
};

class TChat { public: int AddChatMsg(char*, char*, int); };

struct MSGFORMAT_KILL_PLAYER {
    unsigned long player;
    unsigned long dco_id;
};

struct COMMPLAYEROPTIONS {
    char gap_00[8];
    int ProgramState;
    char gap_0C[0x14 - 0x0C];
    unsigned long dcoID[10];
    char gap_3C[0x40 - 0x3C];
    unsigned char CommandTurnIncrement;
    char gap_41[0x1C0 - 0x41];
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
};

class TCommunications_Handler {
public:
    char gap_0000[0x18];
    TChat* Chat;
    int MeHost;
    char gap_0020[0x10C8 - 0x20];
    unsigned int current_turn;
    char gap_10CC[0x10E0 - 0x10CC];
    unsigned int Me;
    int Multiplayer;
    char gap_10E8[0x12C8 - 0x10E8];
    char (*FriendlyName)[128];
    char gap_12CC[0x13BC - 0x12CC];
    unsigned long PlayerStopTurn[16];
    char gap_13FC[0x14D4 - 0x13FC];
    RGE_Communications_Speed* Speed;
    RGE_Communications_Synchronize* Sync;
    char gap_14DC[0x1550 - 0x14DC];
    COMMPLAYEROPTIONS PlayerOptions;
    char gap_1714[0x1720 - 0x1714];
    unsigned long LastTurnAck[16];

    int EvaluatePlayerMessage(unsigned long a1, unsigned int player,
                              unsigned long a3, unsigned char opcode,
                              unsigned char p5, char* data, unsigned int p7,
                              unsigned long p8, unsigned long p9);
    void SetPlayerStopTurn(unsigned int player, unsigned long turn);
    int AddCommand(unsigned long, void*, unsigned long, int, unsigned char, int);
    void LocalPauseGame(unsigned int player);
    void LocalResumeGame(unsigned int player);
    void SendPauseGame(int pause);
    void DropDeadPlayer(unsigned int player, unsigned long dco_id);
    void NotifyWindow(int message);
    void NotifyWindowParam(int message, int player);
};

int TCommunications_Handler::EvaluatePlayerMessage(unsigned long a1, unsigned int player,
                                                   unsigned long a3, unsigned char opcode,
                                                   unsigned char p5, char* data, unsigned int p7,
                                                   unsigned long p8, unsigned long p9) {
    if (!this->Multiplayer) return 0;
    switch (opcode) {
    case 0x44: {
        this->Speed->SetPlayerTurnSpeed(player, (unsigned char)data[9],
                                        (unsigned char)data[8]);
        if ((this->PlayerOptions.ProgramState < 5 || this->current_turn < 6) &&
            *(unsigned int*)(data + 4) < this->current_turn) {
            L->Log(S(0x5816D0), this->current_turn, *(unsigned int*)(data + 4));
            return 0;
        }
        unsigned int v = *(unsigned int*)(data + 4) - this->PlayerOptions.CommandTurnIncrement;
        if (v <= this->LastTurnAck[player]) v = this->LastTurnAck[player];
        this->LastTurnAck[player] = v;
        return 1;
    }
    case 0x51:
        this->SetPlayerStopTurn(player, *(unsigned long*)data);
        return 1;
    case 0x4D:
        this->Sync->Add(player, *(unsigned long*)data,
                        *(unsigned long*)(data + 4),
                        *(unsigned long*)(data + 8),
                        *(long*)(data + 0x0C), *(long*)(data + 0x10),
                        *(long*)(data + 0x14), *(long*)(data + 0x18),
                        *(long*)(data + 0x1C));
        return 1;
    case 0x3E:
        this->AddCommand(a3, data, a1, (int)player, p5, 0);
        return 1;
    case 0x53:
        this->Speed->SetFutureSpeedChange((unsigned int)*(unsigned short*)data,
                                           (unsigned int)*(unsigned short*)(data + 2),
                                           a3);
        return 1;
    case 0x43: {
        char* text = data + 0x11;
        L->Log(S(0x58167C), player, p8, p9, text,
               *(int*)(data + 0x0C), p7, (unsigned char)data[0x10]);
        if (data[this->Me + 1] == 'Y' || this->PlayerOptions.ProgramState == 3)
            this->Chat->AddChatMsg(this->FriendlyName[(unsigned char)data[0]],
                                   text, 0);
        return 1;
    }
    case 0x50:
        L->Log(S(0x581664));
        this->LocalPauseGame(player);
        this->Sync->LogChecksums(0, 0, 0, 0, 0, 0, 0, 0, 0);
        return 1;
    case 0x55:
        L->Log(S(0x581654));
        this->LocalResumeGame(player);
        return 1;
    case 0x2B:
        if (this->MeHost) {
            this->SendPauseGame(0);
            L->Log(S(0x581638));
            this->LocalResumeGame(player);
            return 1;
        }
        break;
    case 0x57:
        if (this->MeHost) {
            this->SendPauseGame(1);
            this->LocalPauseGame(player);
            return 1;
        }
        break;
    case 0x4B: {
        MSGFORMAT_KILL_PLAYER* message = (MSGFORMAT_KILL_PLAYER*)data;
        L->Log(S(0x58160C), player, message->player);
        unsigned long dco_id = message->dco_id;
        int high;
        int i;
        if (dco_id != 0) {
            i = this->PlayerOptions.LowPlayerNumber;
            high = this->PlayerOptions.HighPlayerNumber;
            while (i <= high && this->PlayerOptions.dcoID[i] != dco_id)
                ++i;
            if (i > high)
                i = 0;
        } else {
            i = 0;
        }
        if (i != 0) {
            if (this->PlayerStopTurn[i] == 0)
                this->DropDeadPlayer(i, dco_id);
            if (i == this->Me) {
                this->NotifyWindow(0x17AA);
                return 1;
            }
            if (this->PlayerStopTurn[i] == 0) {
                this->NotifyWindowParam(0x17B3, i);
                return 1;
            }
        }
        break;
    }
    case 0x4E:
        if (!this->MeHost) {
            L->Log(S(0x5815D8));
            return 1;
        }
        break;
    default:
        L->Log(S(0x5815BC), (unsigned int)opcode, (unsigned int)opcode);
        break;
    }
    return 1;
}
