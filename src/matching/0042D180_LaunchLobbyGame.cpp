// 0042D180 TCommunications_Handler::LaunchLobbyGame (Com_hand.cpp:5332-5436, 329B)
// Attempt log:
//   baseline: typed lobby/handler reconstruction was 315B with the Release call using
//     thiscall lowering and the DebugSessionInformation relocation named incorrectly.
//   ABI: __stdcall IUnknown::Release plus the exact DebugSessionInformation target fixed
//     the indirect call shape and aligned all 13 ordered calls; 317B remained.
//   control-flow: stored IsThisHost() in MeHost before the host guard; size became exact.
//   layout: restored COMMPLAYEROPTIONS ownership for ProgramState, dcoID, and Humanity;
//     VC5 emitted the same bytes, confirming the named aggregate layout.
//   liveness: a value/reference alias of Me after `Me = 1` did not change codegen; the
//     reference form was retained because the original reload is binary-proven.
//   layout/context: typed random_game_seed and canonical COM/global surfaces were audited;
//     no codegen change. Pure IUnknown/IDirectPlay3 inheritance remained exact.
// Exact result: 329/329 bytes, 13/13 calls and all relocation identities aligned.
// Default flags only: /nologo /c /O2 /Oy.

extern "C" void* g_prev_dp;             // [62C5ECh]
extern "C" void* g_log_obj;             // [62C4FCh]
extern "C" int g_dco_id;                // [62CF04h]
#if !defined(COM_HAND_TU_CONTEXT)
#if !defined(COM_HAND_TU_CONTEXT)
extern "C" void __cdecl Log(void* L, const char* fmt, int val);
#endif // COM_HAND_TU_CONTEXT
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
struct RGE_Base_Game {
    virtual ~RGE_Base_Game();
    char gap_04[0x24];
    int random_game_seed;                // +0x28
};
#endif // COM_HAND_TU_CONTEXT


extern "C" RGE_Base_Game* rge_base_game; // [62C574h]

#if !defined(COM_HAND_TU_CONTEXT)
struct RGE_Lobby {
    unsigned char CheckForLobbyLaunch(void** pp);
    unsigned char GetSessionInfo(void* p);
    unsigned char GetPlayerInfo(char** pp);
    unsigned char IsThisHost();
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS {
    char gap_00[0x08];
    int ProgramState;                 // +0x08
    char gap_0C[0x14 - 0x0C];
    unsigned int dcoID[10];           // +0x14
    char gap_3C[0x184 - 0x3C];
    int Humanity[10];                 // +0x184
    char gap_1AC[0x1D0 - 0x1AC];
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct IUnknown {
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct IDirectPlay3 : IUnknown {
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct TCommunications_Handler {
    int opt;
    char* optd;
    int steps;
    char _0[0x1C - 0x0C];
    int MeHost;
    int HaveHostInit;
    char _1[0x10E0 - 0x24];
    int Me;
    int Multiplayer;
    char _2[0x1310 - 0x10E8];
    int LobbyLaunched;
    char _3[0x14CC - 0x1314];
    RGE_Lobby* Lobby;
    char _4[0x14E4 - 0x14D0];
    int GTDSerialNo;
    char _5[0x1550 - 0x14E8];
    COMMPLAYEROPTIONS PlayerOptions;

    void DebugSessionInformation(void*);
    void CommGetCaps();
    void DPlayGetSessionDesc();
    void SetMyPlayerName(char*);
    int AddSelfPlayer();
    void SetRandomSeed(int);
    void UpdatePlayers();

    int LaunchLobbyGame();
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::LaunchLobbyGame()
{
    void* np = 0;
    char session_buf[0x50];
    void* pn;
    int r;

    r = Lobby->CheckForLobbyLaunch(&np);
    if (r == 0) goto done;
    if (g_prev_dp) {
        r = ((IDirectPlay3*)g_prev_dp)->Release();
        Log(g_log_obj, "Release count = %d", r);
    }
    g_prev_dp = np;
    if (np == 0) return 0;
    r = Lobby->GetSessionInfo(session_buf);
    if (r) DebugSessionInformation(session_buf);
    CommGetCaps();
    Multiplayer = 1;
    DPlayGetSessionDesc();
    Lobby->GetPlayerInfo((char**)&pn);
    SetMyPlayerName((char*)pn);
    PlayerOptions.ProgramState = 3;
    AddSelfPlayer();
    MeHost = Lobby->IsThisHost();
    if (MeHost) {
        Me = 1;
        PlayerOptions.dcoID[1] = g_dco_id;
        // Preserve the executable's reload of Me after the adjacent option
        // store; a member reference is ordinary C++ and records that proven
        // source-level lifetime without raw offsets or volatility.
        unsigned int& me = this->Me;
        PlayerOptions.Humanity[me] = 2;
        HaveHostInit = 1;
        PlayerOptions.ProgramState = 3;
        SetRandomSeed(rge_base_game->random_game_seed);
        GTDSerialNo = 0x7D1;
    }
    UpdatePlayers();
done:
    LobbyLaunched = r;
    return r;
}
