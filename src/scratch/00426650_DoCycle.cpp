// 00426650 TCommunications_Handler::DoCycle(unsigned long)  (Com_hand.cpp 502-785)
// Attempt log:
// - Initial natural reconstruction from packet + decompiler. Canonical ownership:
//   this->LastPlayerCommunication (base +0x1344), LastTurnAck (+0x1720),
//   WasKicked (+0x174C), Speed (+0x14D4), Sync (+0x14D8), ProgramState (+0x1558),
//   CommandTurnIncrement byte (+0x1590), current_turn (+0x10C8), Me (+0x10E0),
//   Multiplayer (+0x10E4), OutOfSyncFlag (+0x10E8)/dwStopTime (+0x10EC),
//   LastTimeoutMessageTime (+0x12D0), MaxGamePlayers word (+0x12D8),
//   Steps (+0x8), StepMode (+0x1288), MeHost (+0x1C), TBuff (+0xFC5),
//   NeedsToBeSent byte (+0x1550)/LastSentTime (+0x1554) [PlayerOptions cluster].
//   COMM states: PAUSE=4, JOINNOW=3, RUNNING=5.
// - SendAllDoneMsg static "LastSentTime" is a bare global at 0x8884D4.
//   Debug comm-dump rate gate global DAT_0062cf10.
// - [probe1 baseline] natural reconstruction, diff 1641 shape 76% frame 0x74.
// - [probe2 control-flow] moved the ack (ReloadBufferFrames/Starting-Turn-log) block to
//   AFTER the timeout/drop-self block (original jumps forward to ack path at +0x647).
//   Resolved 5 call-site gaps; diff 1639, shape 82.8%, calls aligned 52/55 (94.5%),
//   frame 0x7C vs 0x8C. BEST canonical form; keep.
// - [probe3 control-flow] rewrote timeout/dropSelf decision with inline-then-goto
//   polarity (dropSelf: label). Worse: calls 49/55, shape 75%. Reverted (probe4 restore).
// Remaining gaps (evidence-backed next leads):
//   (a) decision block at L698: original keeps TWO extra blocks B057/B058 -> the ==3 arm
//       emits `cmp ecx,2; jge DROPSELF; cmp eax,eax; jz CHECKTIMEOUT` (unconditional
//       cmp/jz) then else-arm `cdq;sub;sar;/2; jl CHECKTIMEOUT`. Need a source shape that
//       yields that 3-way block topology (sibling-if / explicit-else probing).
//   (b) checkTimeout block (CheckPingTime/debug_timeGetTime 0x2DF/Skip) must be placed
//       textually AFTER the drop-self UpdatePlayers() and BEFORE the ack path; the compiler
//       currently floats it elsewhere.
//   (c) frame 0x7C vs 0x8C (0x10 short). Main-agent audit established that the
//       local_70 store is not dead: it is byte +4 of the 12-byte DONE packet later
//       passed to CommOut. Model that packet explicitly; byte temps may explain
//       additional frame/liveness differences.
//   (d) middle timeout loop is a heavy /O2 scheduling basin (elapsed/Now/G liveness,
//       LastPlayerCommunication pointer ebx + player ebp); will need session-level liveness
//       work.
// - Main-agent semantic correction: modeled the 12-byte DONE packet and its +4
//   turn field (`CommandTurnIncrement + current_turn`). This removed an actual
//   missing memory effect, improved frame 0x7C->0x88 (target 0x8C), size -49->+15,
//   shape 82.83%->84.51%, and strict diff 1639->1622.

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned char uchar;

struct TDebuggingLog { void Log(char*, ...); };
extern "C" ulong debug_timeGetTime(char* file, int line);
extern "C" int sprintf(char* dest, const char* fmt, ...);

#define S(x) ((char*)(x))
#define L (*(TDebuggingLog**)0x0062C4FC)
#define LAST_COMM_DUMP (*(ulong*)0x0062CF10)
#define LAST_SENT_TIME (*(ulong*)0x008884D4)

#define COMM_STATE_PAUSE 4
#define COMM_STATE_JOINNOW 3
#define COMM_STATE_RUNNING 5
#define COMM_SYNC_ERROR 0x17B0
#define COMM_PLAYER_NOT_RESPONDING 0x17BD
#define COMM_PLAYER_DROPPED 0x17B2

struct TRIBE_World { void send_zone_score_info(); };

struct RGE_Base_Game {
    char gap[0x3F0]; TRIBE_World* world;
    virtual void vf0(); virtual void vf4(); virtual void vf8(); virtual void vfC();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void language(int, char*, int);
};
#define rge_base_game (*(RGE_Base_Game**)0x0062C574)

struct RGE_Communications_Speed {
    unsigned char GetHighLatencyCenti();
    uint GetAvgFrameRate();
    void SetPlayerTurnSpeed(int player, uint avgframe, uchar centi);
    uint BufferFramesRemaining();
    uint BufferTimeToUse(uint turn);
    uint WaitingOnAcknowledgement();
    void ReloadBufferFrames();
    int AnalyzeGameSpeed(uint* out_gran, uint* out_frames, int param3);
    uint GetBufferGranularityAdjusted();
    void Skip();
};

struct RGE_Communications_Synchronize { ulong DoChecksum(uint turn); };

class TCommunications_Handler {
public:
    char gap1[0x8];
    int Steps;                                    // +0x8
    char gap2[0x1C - 0xC];
    int MeHost;                                   // +0x1C
    char gap3[0xFC5 - 0x20];
    char TBuff[1];                                // +0xFC5
    char gap3b[0x10C8 - 0xFC6];
    uint current_turn;                            // +0x10C8
    char gap4[0x10E0 - 0x10CC];
    uint Me;                                      // +0x10E0
    int Multiplayer;                              // +0x10E4
    int OutOfSyncFlag;                            // +0x10E8
    ulong dwStopTime;                             // +0x10EC
    char gap5[0x1288 - 0x10F0];
    int StepMode;                                 // +0x1288
    char gap5b[0x12D0 - 0x128C];
    ulong LastTimeoutMessageTime;                 // +0x12D0
    char gap6[0x12D8 - 0x12D4];
    unsigned short MaxGamePlayers;                // +0x12D8
    char gap7[0x1344 - 0x12DA];
    ulong LastPlayerCommunication[16];            // +0x1344
    char gap8[0x14D4 - 0x1384];
    RGE_Communications_Speed* Speed;              // +0x14D4
    RGE_Communications_Synchronize* Sync;         // +0x14D8
    char gap9[0x1550 - 0x14DC];
    unsigned char NeedsToBeSent;                  // +0x1550
    char gap10[0x1554 - 0x1551];
    ulong LastSentTime;                           // +0x1554
    int ProgramState;                             // +0x1558
    char gap11[0x1590 - 0x155C];
    unsigned char CommandTurnIncrement;           // +0x1590
    char gap12[0x1720 - 0x1591];
    ulong LastTurnAck[11];                        // +0x1720
    int WasKicked[16];                            // +0x174C

    char* GetCommInfo(unsigned char index);
    void ReceiveGameMessages();
    long CommOut(long a, char b, char* buf, long size, long c);
    char* GetPlayerName(uint player);
    int IsPlayerHuman(uint player);
    int AllPlayersAcknowledged();
    void NotifyWindowParam(int msg, long param);
    void CheckPingTime(int param);
    void SendChatMsgAll(char* msg);
    int Kick(uint player);
    void InitPlayerInformation(uint player, int human, char* status, char* info);
    void UpdatePlayers();
    void CheckPlayerStopTurn(uint turn);

    int DoCycle(ulong param_1);
};

int TCommunications_Handler::DoCycle(ulong param_1)
{
    if (this->Multiplayer == 0) {
        return -(int)(this->ProgramState != COMM_STATE_PAUSE);
    }
    if (this->Me > (uint)this->MaxGamePlayers) {
        return 0;
    }

    ulong now = debug_timeGetTime(S(0x580BF4), 0x20D);
    if (now - LAST_COMM_DUMP > 4999) {
        L->Log(GetCommInfo(6));
        L->Log(GetCommInfo(5));
        L->Log(GetCommInfo(4));
        L->Log(GetCommInfo(3));
        L->Log(GetCommInfo(2));
        L->Log(GetCommInfo(1));
        LAST_COMM_DUMP = now;
    }

    this->ReceiveGameMessages();
    this->LastPlayerCommunication[this->Me] = now;

    unsigned char inc = this->CommandTurnIncrement;
    uint turn = this->current_turn;
    if (this->Multiplayer != 0 && this->ProgramState != COMM_STATE_JOINNOW &&
        this->LastTurnAck[this->Me] != turn) {
        this->LastTurnAck[this->Me] = turn;
        if (turn > 6) {
            unsigned char centi = this->Speed->GetHighLatencyCenti();
            uchar frame = (uchar)this->Speed->GetAvgFrameRate();
            this->Speed->SetPlayerTurnSpeed(this->Me, frame, centi);
        }
        LAST_SENT_TIME = debug_timeGetTime(S(0x580BF4), 0xBF9);
        struct DoneMessage {
            char type;
            char gap_01[3];
            int turn;
            char gap_08[4];
        } doneMsg;
        doneMsg.type = 'D';
        doneMsg.turn = inc + turn;
        L->Log(S(0x580EA4), 0x0C);          // "  >TX DONE (%d)"
        this->CommOut(0, 'D', (char*)&doneMsg, 0x0C, 0);
    }

    if (this->StepMode != 0) {
        int steps = this->Steps;
        if (steps == 0) {
            return 0;
        }
        this->Steps = steps - 1;
    }

    this->Sync->DoChecksum(this->current_turn);

    if ((this->OutOfSyncFlag == 1) && (param_1 >= this->dwStopTime)) {
        this->NotifyWindowParam(COMM_SYNC_ERROR, this->dwStopTime);
        return 0;
    }

    uint framesLeft = this->Speed->BufferFramesRemaining();
    if (framesLeft != 0 && this->current_turn > 6) {
        return this->Speed->BufferTimeToUse(this->current_turn);
    }

    uint G = 0;
    int ack = this->AllPlayersAcknowledged();

    if (ack == 0) {
        if ((int)this->ProgramState < 5) {
            return 0;
        }

        this->Speed->WaitingOnAcknowledgement();
        now = debug_timeGetTime(S(0x580BF4), 0x259);

        char msg_str[100];
        uint i = 1;
        ulong lastAnyPlayerMessage = 0;
        int selfTimedOutCount = 0;
        if (this->MaxGamePlayers >= i) {
            ulong* lpc = this->LastPlayerCommunication + 1;
            do {
                if (this->IsPlayerHuman(i) && i != this->Me) {
                    selfTimedOutCount++;
                    if (G > *lpc) {
                        // keep G
                    } else {
                        G = *lpc;
                    }
                    ulong elapsed = now - *lpc;
                    if (elapsed > 60000) {
                        lastAnyPlayerMessage++;
                    }
                    if (elapsed > 25000 && now - lpc[10] > 25000) {
                        lpc[10] = now;
                        this->NotifyWindowParam(COMM_PLAYER_NOT_RESPONDING, i);
                    }
                    int timedOut = 0;
                    if (this->current_turn < 8 && elapsed > 98000) {
                        L->Log(S(0x580E74), this->current_turn, elapsed);
                        timedOut = 1;
                    }
                    if (this->current_turn > 7 && elapsed > 0x1DA9C && this->MeHost != 0) {
                        L->Log(S(0x580E48), this->current_turn, elapsed);
                        timedOut = 1;
                    }
                    if (this->current_turn > 7 && elapsed > 0x1D6B4) {
                        L->Log(S(0x580E1C), this->current_turn, elapsed);
                        timedOut = 1;
                    }
                    if (timedOut) {
                        L->Log(S(0x580DF4), elapsed);
                        L->Log(S(0x580DD8), i);
                        if (this->MeHost != 0) {
                            L->Log(S(0x580DB4), i, this->current_turn, elapsed);
                            rge_base_game->language(0x4BA, msg_str, 0x64);
                            sprintf(this->TBuff, msg_str, this->GetPlayerName(i), i);
                            if (this->current_turn > 6) {
                                this->SendChatMsgAll(this->TBuff);
                            }
                            L->Log(this->TBuff);
                            lpc[0x56] = 1;
                            this->Kick(i);
                        }
                        *lpc = now;
                        lpc[0x14] = now;
                    }
                }
                i++;
                lpc++;
            } while (i <= (uint)this->MaxGamePlayers);
        }

        if (selfTimedOutCount + 1 == 3) {
            if (lastAnyPlayerMessage < 2) {
                goto checkTimeout;
            }
        } else if (lastAnyPlayerMessage < (selfTimedOutCount + 1) / 2) {
            goto checkTimeout;
        }

        // dropped myself
        L->Log(S(0x580DA0));   // "I Dropped myself."
        this->NotifyWindowParam(COMM_PLAYER_DROPPED, this->Me);
        i = 1;
        if (this->MaxGamePlayers >= i) {
            int* wk = &this->WasKicked[1];
            do {
                *wk = 1;
                i++;
                wk++;
            } while (i <= (uint)this->MaxGamePlayers);
        }
        rge_base_game->world->send_zone_score_info();
        L->Log(S(0x580C4C));   // "Initialize Player List"
        i = 1;
        if (this->MaxGamePlayers >= i) {
            do {
                this->InitPlayerInformation(i, 0, S(0x580460), S(0x580460));
                i++;
            } while ((int)i <= (int)(uint)this->MaxGamePlayers);
        }
        this->NeedsToBeSent = 0;
        this->LastSentTime = 0;
        this->UpdatePlayers();
        return 0;

    checkTimeout:
        {
            ulong lastTimeout = this->LastTimeoutMessageTime;
            if (this->LastTimeoutMessageTime < G) {
                lastTimeout = G;
            }
            if (now - lastTimeout > 25000) {
                this->CheckPingTime(1);
                this->LastTimeoutMessageTime = debug_timeGetTime(S(0x580BF4), 0x2DF);
            }
            this->Speed->Skip();
            return 0;
        }
    }

    // ack != 0
    if (this->ProgramState != COMM_STATE_RUNNING) {
        return 0;
    }
    this->Speed->ReloadBufferFrames();
    uint WT = 0;
    uint Fr = 0;
    if (this->MeHost != 0) {
        this->Speed->AnalyzeGameSpeed(&WT, &Fr, 1);
    }
    uint newTurn = this->current_turn + 1;
    this->current_turn = newTurn;
    L->Log(S(0x580D74), newTurn, param_1, WT, Fr);   // "....Starting Turn#%d, WT=%d, Fr=%d, Gr=%d"
    this->CheckPlayerStopTurn(this->current_turn);
    return this->Speed->GetBufferGranularityAdjusted();
}
