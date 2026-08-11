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
// left in scratch: canonical typed behavior/call surface is reconstructed, but
// the VC5 frame/parameter-home reuse, switch handler placement, and four
// distinct free call sites remain structurally unresolved.

extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);

class TDebuggingLog {
public:
    static void __cdecl Log(TDebuggingLog*, char*, ...);
};
extern TDebuggingLog* L;

class RGE_Comm_Error {
public:
    void ShowReturn(long, char*);
};

struct IDirectPlay;
struct IDirectPlayVtbl {
    char gap_00[0x54];
    long (__stdcall* GetPlayerName)(IDirectPlay*, unsigned long, void*, unsigned int*);
};
struct IDirectPlay {
    IDirectPlayVtbl* vtbl;
};
#define g_pDirectPlay (*(IDirectPlay**)0x0062C5EC)

struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    char* lpszShortName;
    char* lpszLongName;
};

struct MSGFORMAT_MISSING_PLAYER {
    unsigned char Command;
    unsigned char gap_01[3];
    unsigned long PlayerID;
};

enum PLAYERHUMANITY {
    ME_ABSENT = 0,
    ME_CLOSED = 1,
    ME_HUMAN = 2,
    ME_ELIMINATED = 3,
    ME_COMPUTER = 4,
    ME_CYBORG = 5,
    ME_VIEWONLY = 6
};

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

struct NAME {
    char Text[128];
};

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

void TCommunications_Handler::UpdatePlayer(unsigned int player, int do_update)
{
    int dcoID = this->PlayerOptions.dcoID[player];
    void* lpData;
    MSGFORMAT_MISSING_PLAYER m;
    unsigned int size;

    switch (this->PlayerOptions.Humanity[player]) {
    case ME_ABSENT:
        TDebuggingLog::Log(L, (char*)0x582CC0, player);
        this->PlayerOptions.dcoID[player] = 0;
        this->PlayerOptions.PlayerReady[player] = 0;
        goto update;

    case ME_CLOSED:
        TDebuggingLog::Log(L, (char*)0x582BB0, player);
        goto closed_cleanup;

    case ME_HUMAN:
        TDebuggingLog::Log(L, (char*)0x582CA4, player);
        goto get_name_log;

    case ME_ELIMINATED:
        TDebuggingLog::Log(L, (char*)0x582CB0, player);
        this->PlayerOptions.dcoID[player] = 0;
        this->PlayerOptions.PlayerReady[player] = 0;
        goto update;

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

    default:
        strcpy(this->FriendlyName[player].Text, (char*)0x582BA8);
        TDebuggingLog::Log(L, (char*)0x582B80, player,
               this->PlayerOptions.Humanity[player]);
        return;
    }

get_name_log:
    if (dcoID == 0) {
        TDebuggingLog::Log(L, (char*)0x582BBC, player);
        return;
    }

    {
        IDirectPlay* dp;
        IDirectPlayVtbl* dp_vtbl;

        size = 0;
        dp = g_pDirectPlay;
        dp_vtbl = dp->vtbl;
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
                TDebuggingLog::Log(L, (char*)0x582C48);
                this->PlayerOptions.Humanity[player] = ME_ABSENT;
                this->PlayerOptions.dcoID[player] = 0;
                free(lpData);
                goto update;
            }
        } else {
            if (result != (long)0x88770082) {
                if (result == (long)0x88770096) {
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
                            free(lpData);
                            goto update;
                        }
                    }
                    free(lpData);
                    goto update;
                }
                if (result == 0) {
                    strcpy(this->FriendlyName[player].Text,
                           ((DPNAME*)lpData)->lpszShortName);
                    strcpy(this->FormalName[player].Text,
                           ((DPNAME*)lpData)->lpszLongName);
                    this->PlayerOptions.Humanity[player] = ME_HUMAN;
                    free(lpData);
                    goto update;
                }
                TDebuggingLog::Log(L, (char*)0x582C48);
                this->PlayerOptions.Humanity[player] = ME_ABSENT;
                this->PlayerOptions.dcoID[player] = 0;
                free(lpData);
                goto update;
            }
        }

        TDebuggingLog::Log(L, (char*)0x582BE8, result);
        strcpy(this->FriendlyName[player].Text, (char*)0x582BE0);
        this->PlayerOptions.Humanity[player] = ME_ABSENT;
        free(lpData);
        goto update;
    }

closed_cleanup:
    this->PlayerOptions.dcoID[player] = 0;
    this->PlayerOptions.PlayerReady[player] = 1;
    goto update;

update:
    if (do_update != 0) {
        this->NotifyWindow(0x17A4);
    }
}
