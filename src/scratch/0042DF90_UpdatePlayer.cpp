// 0042DF90 TCommunications_Handler::UpdatePlayer
// Com_hand.cpp lines 6001-6188
// Attempt log:
// try 1-10 (prior worker): broad decompiler-shaped reconstruction reached exact
// size but used placeholder log/error/chat/update call surfaces; switch topology,
// DirectPlay name record, and packet locals remained broadly unresolved.
// baseline (sa-ab44abb9-r1): canonicalized the player-option arrays and the
// period DirectPlay/name-record ownership; current mismatch is structural.
// probe 2: replaced placeholder log/error/chat/update calls with the exact
// TDebuggingLog, RGE_Comm_Error, FastSend, and NotifyWindow member surfaces;
// ordered call targets aligned, but the extra preserved-index/local basin made
// the frame and switch prologue worse.
// probes 3-8: tested delayed/register-qualified player-index lifetimes, a flat
// offset overlay, static Log syntax, and parameter-home reuse.  The separate
// natural size local gave the best early structural basin; parameter reuse with
// an index alias regressed the frame and was rolled back.
// probe 9: rewrote the HRESULT handling as the binary-backed signed nested
// decision tree (fatal low/high arms, invalid-player arm, success, unknown).
// This improved shape to 54.55% and edit similarity to 53.62%; direct free is
// still compiler-tail-merged (1 rebuilt site versus 4 original sites).
// probe 10: restored canonical nested COMMPLAYEROPTIONS ownership after the
// flat overlay diagnostic; emitted code was unchanged.
// probe 11: reordered the switch cases toward the original handler order;
// call-site alignment improved to 86.36%, but size grew by 36 bytes and the
// positional diff worsened, so restored the clean case order.
// probe 14 baseline: current canonical source measured diff 895, frame 0x10
// versus 0xC, and one rebuilt free versus four original free sites.
// probe 15: one natural release tail reached exact size and diff 874; it still
// merged all free calls and left the switch handler layout unresolved.
// probe 16: direct free/update returns raised size to 1000 and worsened diff;
// rolled back.
// probe 17: PDB-backed switch order 0,3,2,4,5,6,1 improved diff to 854 and
// shape to 64.44%, but expanded to five free calls and 1044 bytes.
// probes 18-19: split and then fall-through release labels; emitted code stayed
// at diff 850, with five free calls, so retained the simpler single-tail form.
// probe 20: reused the incoming player home for DirectPlay size with a saved
// index local; frame grew to 0x14 and diff regressed to 937, so rolled back.
// left in scratch: canonical typed behavior/call surface is reconstructed, but
// the VC5 frame/parameter-home reuse, switch handler placement, and four
// distinct free call sites remain structurally unresolved.
//
// current claim (sa-0a2444f7-r1): probes 1-21 tested local ownership, packet
// size-home use, guard polarity, HRESULT topology, case tails, copy locals,
// declaration order, and dcoID signedness.  The best clean source is the
// current typed form: size is a distinct local, the nonzero dcoID body is the
// positive arm, and fatal/unknown results use shared labels.
// BINARY NOTE: the original first GetPlayerName size pointer is the incoming
// player home ([entry ESP+4]); EBP still carries the player index.  Direct
// parameter-home reuse variants grew or changed the frame and were discarded.
// BINARY NOTE: the original no-dcoID test jumps forward to a cold log block;
// the positive guarded body recovers that branch polarity and keeps the tail
// close, but the VC5 local frame and HRESULT block order remain unresolved.
// Best final check: 968-byte rebuilt span, frame 0x10 versus 0xC, 713 strict
// differing bytes, 66.44% shape, 95.45% ordered-call alignment.
// Next leads: recover the parameter-home/index color without an extra local;
// then recover delayed cdecl cleanup and unknown/success/invalid/fatal block
// order.  Do not keep the parameter-alias experiments without a clean frame.
//
// current claim (sa-739dc223-r1): tested nine additional source hypotheses.
// Parameter-home reuse with explicit index locals made 0x14 frames and large
// structural regressions.  A block-scoped size local stayed in the same basin.
// A register format tail for COMPUTER/CLOSED also regressed the shape.  Four
// explicit result frees improved the raw diff to 710, but changed the CFG and
// was not retained.  The clean source below remains the best natural model.

extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog {
public:
    static void __cdecl Log(TDebuggingLog*, char*, ...);
};
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void ShowReturn(long, char*);
};
#endif // COM_HAND_TU_CONTEXT


struct IDirectPlay;
#if !defined(COM_HAND_TU_CONTEXT)
struct IDirectPlayVtbl {
    char gap_00[0x54];
    long (__stdcall* GetPlayerName)(IDirectPlay*, unsigned long, void*, unsigned int*);
};
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
struct IDirectPlay {
    IDirectPlayVtbl* vtbl;
};
#endif // COM_HAND_TU_CONTEXT

#define g_pDirectPlay (*(IDirectPlay**)0x0062C5EC)

#if !defined(COM_HAND_TU_CONTEXT)
struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    char* lpszShortName;
    char* lpszLongName;
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct MSGFORMAT_MISSING_PLAYER {
    unsigned char Command;
    unsigned char gap_01[3];
    unsigned int PlayerID;
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
enum PLAYERHUMANITY {
    ME_ABSENT = 0,
    ME_CLOSED = 1,
    ME_HUMAN = 2,
    ME_ELIMINATED = 3,
    ME_COMPUTER = 4,
    ME_CYBORG = 5,
    ME_VIEWONLY = 6
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS {
    unsigned char NeedsToBeSent;
    unsigned char gap_01[3];
    unsigned long LastSentTime;
    int ProgramState;
    unsigned long CurrentTurn;
    unsigned char TurnSpeedMsec;
    unsigned char gap_11[3];
    unsigned long dcoID[10];
    unsigned long AcknowledgeAfterMsec;
    unsigned char CommandTurnIncrement;
    unsigned char gap_41[3];
    int PlayerReady[10];
    unsigned long User1[10];
    unsigned long User2[10];
    unsigned long User3[10];
    unsigned long User4[10];
    unsigned long User5[10];
    unsigned long User6[10];
    unsigned long User7[10];
    int Humanity[10];
    unsigned char InvalidPlayer[10];
    unsigned char gap_1B6[2];
    unsigned long Initialized;
    unsigned long RandomSeed;
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    unsigned int HostPlayerNumber;
    int GameHasStarted;
    unsigned long DataSizeToFollow;
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct NAME {
    char Text[128];
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0000[0x12C8];
    NAME* FriendlyName;
    NAME* FormalName;
    char gap_12D0[0x14E0 - 0x12D0];
    RGE_Comm_Error* Err;
    char gap_14E4[0x1550 - 0x14E4];
    COMMPLAYEROPTIONS PlayerOptions;

    int IsPlayerHuman(unsigned int);
    long FastSend(unsigned long, void*, unsigned long, int, int);
    void NotifyWindow(unsigned long);
    void UpdatePlayer(unsigned int, int);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::UpdatePlayer(unsigned int player, int do_update)
{
    unsigned int dcoID = this->PlayerOptions.dcoID[player];
    unsigned int size;
    void* lpData;
    MSGFORMAT_MISSING_PLAYER m;

    switch (this->PlayerOptions.Humanity[player]) {
    case ME_ABSENT:
        TDebuggingLog::Log(L, (char*)0x582CC0, player);
        this->PlayerOptions.dcoID[player] = 0;
        this->PlayerOptions.PlayerReady[player] = 0;
        goto update;

    case ME_ELIMINATED:
        TDebuggingLog::Log(L, (char*)0x582CB0, player);
        this->PlayerOptions.dcoID[player] = 0;
        this->PlayerOptions.PlayerReady[player] = 0;
        goto update;

    case ME_HUMAN:
        TDebuggingLog::Log(L, (char*)0x582CA4, player);
        goto get_name_log;

    case ME_COMPUTER:
        TDebuggingLog::Log(L, (char*)0x582C94, player);
        goto closed_cleanup;

    case ME_CYBORG:
        TDebuggingLog::Log(L, (char*)0x582C88, player);
        goto get_name_log;

    case ME_VIEWONLY:
        this->PlayerOptions.PlayerReady[player] = 1;
        TDebuggingLog::Log(L, (char*)0x582C78, player);
        break;

    case ME_CLOSED:
        TDebuggingLog::Log(L, (char*)0x582BB0, player);
        goto closed_cleanup;

    default:
        strcpy(this->FriendlyName[player].Text, (char*)0x582BA8);
        TDebuggingLog::Log(L, (char*)0x582B80, player,
               this->PlayerOptions.Humanity[player]);
        return;
    }

get_name_log:
    if (dcoID != 0) {
        IDirectPlay* dp;
        IDirectPlayVtbl* dp_vtbl;

        dp = g_pDirectPlay;
        dp_vtbl = dp->vtbl;
        size = 0;
        dp_vtbl->GetPlayerName(dp, dcoID, 0, &size);
        lpData = calloc(size, 1);

        dp = g_pDirectPlay;
        dp_vtbl = dp->vtbl;
        long result = dp_vtbl->GetPlayerName(
            dp, dcoID, lpData, &size);
        this->Err->ShowReturn(result, (char*)0x582C68);

        if (result <= (long)0x8877001E) {
            if (result != (long)0x8877001E &&
                result != (long)0x80070057) {
                goto unknown_result;
            }
            goto fatal_result;
        } else if (result == (long)0x88770082) {
            goto fatal_result;
        } else if (result == (long)0x88770096) {
            TDebuggingLog::Log(L, (char*)0x582C28, dcoID);
            if (this->PlayerOptions.ProgramState == 3) {
                this->PlayerOptions.Humanity[player] = ME_HUMAN;
                if (this->IsPlayerHuman(player)) {
                    TDebuggingLog::Log(L, (char*)0x582C18);
                    TDebuggingLog::Log(L, (char*)0x582130, dcoID);
                    m.Command = '?';
                    m.PlayerID = dcoID;
                    TDebuggingLog::Log(L, (char*)0x582C04, dcoID, 8);
                    this->FastSend(0, &m, 8, 0, 0);
                    goto release_data;
                }
            }
            goto release_data;
        } else if (result == 0) {
            strcpy(this->FriendlyName[player].Text,
                   (char*)((DPNAME*)lpData)->lpszShortName);
            strcpy(this->FormalName[player].Text,
                   (char*)((DPNAME*)lpData)->lpszLongName);
            this->PlayerOptions.Humanity[player] = ME_HUMAN;
            goto release_data;
        } else {
            goto unknown_result;
        }

unknown_result:
        TDebuggingLog::Log(L, (char*)0x582C48);
        this->PlayerOptions.Humanity[player] = ME_ABSENT;
        this->PlayerOptions.dcoID[player] = 0;
        goto release_data;

fatal_result:
        TDebuggingLog::Log(L, (char*)0x582BE8, result);
        strcpy(this->FriendlyName[player].Text, (char*)0x582BE0);
        this->PlayerOptions.Humanity[player] = ME_ABSENT;
        goto release_data;

    }
no_dcoid:
    TDebuggingLog::Log(L, (char*)0x582BBC, player);
    return;

release_data:
    free(lpData);
    goto update;

closed_cleanup:
    this->PlayerOptions.dcoID[player] = 0;
    this->PlayerOptions.PlayerReady[player] = 1;
    goto update;

update:
    if (do_update != 0) {
        this->NotifyWindow(0x17A4);
    }
}
