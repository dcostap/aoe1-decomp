// VA: 0042D590 TCommunications_Handler::CreateMultiplayerGame
// Source: Com_hand.cpp lines 5584-5666
// Attempt log:
//   baseline: raw-offset session setup with exact size/frame/call count, but the
//     ApplicationGUID loads were hoisted ahead of the original constant stores (203B).
//   ABI: corrected DPSESSIONDESC2, ShowReturn(char*), and SetRandomSeed(int) surfaces;
//     call identities remained aligned while the descriptor schedule stayed unchanged.
//   layout: typed the ApplicationGUID aggregate and copied it into the local descriptor;
//     this recovered the descriptor/Open tail to a 47B mismatch.
//   liveness: a Me value/reference alias was insufficient; a diagnostic volatile reread
//     recovered the original indexed Humanity store and exact size, leaving 31B.
//   liveness: pinning HostPlayerNumber before the reread reduced the gap to 13B. Pinning
//     the dcoID store as well recovered the original `this` preload and exact bytes.
// Exact result: 386/386 bytes, 105/105 instructions, 12/12 ordered calls, default flags.
// Main-agent audit removed the exact-only volatile/raw-offset steering candidate.
// The living source below uses the canonical communications/player-option ownership.

typedef unsigned long ulong;

#if !defined(COM_HAND_TU_CONTEXT)
struct GUID {
    ulong Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TChat { public: void ClearChat(void); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error { public: void ShowReturn(long result, char* msg); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x24];
    long random_game_seed;
};
#endif // COM_HAND_TU_CONTEXT


#pragma pack(push, 1)
#if !defined(COM_HAND_TU_CONTEXT)
struct DPSESSIONDESC2 {
    ulong dwSize;              // +00
    ulong guidInstance_Data1;  // +04
    unsigned char pad_08[0x18 - 0x08];
    GUID guidApplication;      // +18
    ulong dwMaxPlayers;        // +28
    ulong one;                 // +2C
    const unsigned short* title;// +30
    unsigned char pad_34[0x50 - 0x34];
};
#endif // COM_HAND_TU_CONTEXT
#pragma pack(pop)

#if !defined(COM_HAND_TU_CONTEXT)
struct IUnknown {
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct IDirectPlay3 : IUnknown {
    virtual long __stdcall AddPlayerToGroup() = 0;
    virtual long __stdcall Close() = 0;
    virtual long __stdcall CreateGroup() = 0;
    virtual long __stdcall CreatePlayer() = 0;
    virtual long __stdcall DeletePlayerFromGroup() = 0;
    virtual long __stdcall DestroyGroup() = 0;
    virtual long __stdcall DestroyPlayer() = 0;
    virtual long __stdcall EnumGroupPlayers() = 0;
    virtual long __stdcall EnumGroups() = 0;
    virtual long __stdcall EnumPlayers() = 0;
    virtual long __stdcall EnumSessions() = 0;
    virtual long __stdcall GetCaps() = 0;
    virtual long __stdcall GetGroupData() = 0;
    virtual long __stdcall GetGroupName() = 0;
    virtual long __stdcall GetMessageCount() = 0;
    virtual long __stdcall GetPlayerAddress() = 0;
    virtual long __stdcall GetPlayerCaps() = 0;
    virtual long __stdcall GetPlayerData() = 0;
    virtual long __stdcall GetPlayerName() = 0;
    virtual long __stdcall GetSessionDesc() = 0;
    virtual long __stdcall Initialize() = 0;
    virtual long __stdcall Open(DPSESSIONDESC2*, unsigned long) = 0;
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
extern IDirectPlay3* DAT_0062c5ec;
#endif // COM_HAND_TU_CONTEXT
extern RGE_Base_Game* rge_base_game;
extern long DAT_0062CF04;

#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS {
    char gap_00[8];
    int ProgramState;
    int game_state;
    char gap_10[4];
    unsigned int dcoID[10];
    char gap_3C[4];
    unsigned char player_mode;
    char gap_41[0x184 - 0x41];
    int Humanity[10];
    char gap_1AC[0x1C4 - 0x1AC];
    int HostPlayerNumber;
    char gap_1C8[8];
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0000[0x18];
    TChat* Chat;
    int HaveHostInit;
    int session_active;
    char gap_0024[0x10C8 - 0x24];
    int connection_state;
    char gap_10CC[0x10E0 - 0x10CC];
    int Me;
    int Multiplayer;
    char gap_10E8[0x11FA - 0x10E8];
    unsigned short session_title[0x6F];
    unsigned short MaxGamePlayers;
    char gap_12DA[0x12EC - 0x12DA];
    GUID ApplicationGUID;
    char gap_12FC[0x14E0 - 0x12FC];
    RGE_Comm_Error* Err;
    int GTDSerialNo;
    char gap_14E8[0x1550 - 0x14E8];
    COMMPLAYEROPTIONS PlayerOptions;

    long CreateDirectPlayConversation(void);
    void DebugSessionInformation(DPSESSIONDESC2* desc);
    void SetRandomSeed(int seed);
    int AddSelfPlayer(void);
    long CommGetCaps(void);
    long DPlayGetSessionDesc(void);
    void UpdatePlayers(void);
    void NotifyWindow(int msg);
    int CreateMultiplayerGame(void);
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::CreateMultiplayerGame(void)
{
    DPSESSIONDESC2 dSess2;
    int one = 1;

    this->Multiplayer = one;
    this->session_active = 0;
    this->PlayerOptions.player_mode = 2;
    this->connection_state = 4;
    this->PlayerOptions.game_state = 4;
    this->Chat->ClearChat();

    long result = this->CreateDirectPlayConversation();
    this->Err->ShowReturn(result, "CreateDirectPlayConversation");

    this->HaveHostInit = one;
    { ulong* p = (ulong*)&dSess2; int i; for (i = 0x14; i != 0; --i) *p++ = 0; }

    dSess2.dwMaxPlayers = this->MaxGamePlayers;
    dSess2.dwSize = 0x50;
    dSess2.one = one;
    dSess2.guidApplication = this->ApplicationGUID;
    dSess2.guidInstance_Data1 = 0x44;
    dSess2.title = (unsigned short*)this->MyGameTitle;

    this->DebugSessionInformation(&dSess2);

    result = DAT_0062c5ec->Open(&dSess2, 2);
    this->Err->ShowReturn(result, "DirectPlay Open Create");

    if (result != 0) {
        if (result == (long)0x887700AA) {
            this->NotifyWindow(0x17AE);
            return 0;
        }
        this->PlayerOptions.ProgramState = one;
        return 0;
    }

    this->SetRandomSeed(rge_base_game->random_game_seed);
    this->AddSelfPlayer();
    this->CommGetCaps();
    this->DPlayGetSessionDesc();
    this->Me = one;
    this->PlayerOptions.HostPlayerNumber = one;
    this->PlayerOptions.dcoID[this->Me] = DAT_0062CF04;
    this->PlayerOptions.Humanity[this->Me] = 2;
    this->session_active = one;
    this->PlayerOptions.ProgramState = 3;
    this->GTDSerialNo = 0x7D1;
    this->UpdatePlayers();
    return one;
}
