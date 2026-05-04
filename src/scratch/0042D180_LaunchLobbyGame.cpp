// 0042D180 TCommunications_Handler::LaunchLobbyGame (Com_hand.cpp:5332-5436, 329B)
// Left in scratch: 320/329 bytes match (~2.7% remaining). 
// Issues:
// - Frame size 0x54 instead of 0x58 (need 4 more bytes local allocation)
// - COM __stdcall Release: need `mov ecx,[eax]; push eax; call [ecx+8]` but getting
//   `mov edx,[ecx]; call [edx+8]` (missing push, different register)
// - `r` result variable causes extra `mov [esp+NN],eax` stores vs original `mov edi,eax`
// - Global access: getting `mov ecx,[addr]` (6B) vs `mov eax,[addr]` (5B)
// - Session info offset different due to frame layout
// Best path: variant_lab on frame size + COM call pattern + result variable removal
// FLAGS: /nologo /c /O2 /Oy

extern "C" void* g_prev_dp;             // [62C5ECh]
extern "C" void* g_log_obj;             // [62C4FCh]
extern "C" int g_dco_id;                // [62CF04h]
extern "C" void* rge_base_game;         // [62C574h]
extern "C" void __cdecl Log(void* L, const char* fmt, int val);

struct RGE_Lobby {
    unsigned char CheckForLobbyLaunch(void** pp);
    unsigned char GetSessionInfo(void* p);
    unsigned char GetPlayerInfo(char** pp);
    unsigned char IsThisHost();
};

struct DP_Obj {
    virtual void q() {}
    virtual void a() {}
    virtual unsigned long Release() { return 0; }
};

struct __declspec(novtable) CH {
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
    char _5[0x1558 - 0x14E8];
    int PState;
    char _6[0x1568 - 0x155C];
    int dcoID1;
    char _7[0x16D4 - 0x156C];
    int Humanity[20];

    void DebugSessionInfo(void*);
    void CommGetCaps();
    void DPlayGetSessionDesc();
    void SetMyPlayerName(char*);
    int AddSelfPlayer();
    void SetRandomSeed(int);
    void UpdatePlayers();

    int LaunchLobbyGame();
};

int CH::LaunchLobbyGame()
{
    void* np = 0;
    char session_buf[0x50];
    void* pn;
    int r;

    r = Lobby->CheckForLobbyLaunch(&np);
    if (r == 0) goto done;
    if (g_prev_dp) {
        r = ((DP_Obj*)g_prev_dp)->Release();
        Log(g_log_obj, "Release count = %d", r);
    }
    g_prev_dp = np;
    if (np == 0) return 0;
    r = Lobby->GetSessionInfo(session_buf);
    if (r) DebugSessionInfo(session_buf);
    CommGetCaps();
    Multiplayer = 1;
    DPlayGetSessionDesc();
    Lobby->GetPlayerInfo((char**)&pn);
    SetMyPlayerName((char*)pn);
    PState = 3;
    AddSelfPlayer();
    if (Lobby->IsThisHost()) {
        Me = 1;
        dcoID1 = g_dco_id;
        Humanity[Me] = 2;
        HaveHostInit = 1;
        PState = 3;
        SetRandomSeed(*(int*)((char*)rge_base_game + 0x28));
        GTDSerialNo = 0x7D1;
    }
    UpdatePlayers();
done:
    LobbyLaunched = r;
    return r;
}
