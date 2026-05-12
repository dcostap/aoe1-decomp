// VA: 0042D590 TCommunications_Handler::CreateMultiplayerGame
// Source: Com_hand.cpp lines 5584-5666
// Attempt log:
// 1: natural raw-offset reconstruction with DPSESSIONDESC2 local; compiler hoisted ApplicationGUID loads before memset and delayed MeHost store.
// 2: use volatile MeHost store/ApplicationGUID reads and source order matching original session descriptor fill; MeHost fixed but descriptor stores still rescheduled.
// 3: fill descriptor through raw dword pointer in original offset order; constants still delayed after argument push and app loads use direct addressing.
// 4: revert to compact struct field form with nonvolatile ApplicationGUID pointer; worsened to 50.5% positional.
// 5: restore volatile ApplicationGUID pointer best (~47.7% positional), leave broad descriptor-fill scheduling unresolved.
// Left in scratch: behavior modeled, but descriptor-fill scheduling diverges (ApplicationGUID loads/constants and push timing), shifting the DirectPlay/Open/error-success tail. Not accepted_drift.

typedef unsigned long ulong;

class TChat { public: void ClearChat(void); };
class RGE_Comm_Error { public: void ShowReturn(long result, const char* msg); };
class RGE_Base_Game { public: char gap_00[0x28]; long random_game_seed; };

#define g_pDirectPlay (*(void**)0x0062C5EC)
#define rge_base_game (*(RGE_Base_Game**)0x0062C574)
#define DAT_0062CF04 (*(long*)0x0062CF04)

#define STR_DP_CREATE_CONV ((const char*)0x00582A00)
#define STR_DP_OPEN_CREATE ((const char*)0x005829F0)

#pragma pack(push, 1)
struct DPSESSIONDESC2_LOCAL {
    ulong dwSize;              // +00
    ulong guidInstance_Data1;  // +04
    unsigned char pad_08[0x18 - 0x08];
    ulong app0;                // +18
    ulong app1;                // +1C
    ulong app2;                // +20
    ulong app3;                // +24
    ulong dwMaxPlayers;        // +28
    ulong one;                 // +2C
    const unsigned short* title;// +30
    unsigned char pad_34[0x50 - 0x34];
};
#pragma pack(pop)

class TCommunications_Handler {
public:
    long CreateDirectPlayConversation(void);
    void DebugSessionInformation(DPSESSIONDESC2_LOCAL* desc);
    void SetRandomSeed(long seed);
    int AddSelfPlayer(void);
    long CommGetCaps(void);
    long DPlayGetSessionDesc(void);
    void UpdatePlayers(void);
    void NotifyWindow(int msg);
    int CreateMultiplayerGame(void);
};

#define FIELD_DWORD(off) (*(long*)((char*)this + (off)))
#define FIELD_BYTE(off) (*(unsigned char*)((char*)this + (off)))
#define FIELD_WORD(off) (*(unsigned short*)((char*)this + (off)))
#define FIELD_DWORD_VOL(off) (*(volatile long*)((char*)this + (off)))

int TCommunications_Handler::CreateMultiplayerGame(void)
{
    DPSESSIONDESC2_LOCAL dSess2;
    int one = 1;

    FIELD_DWORD(0x10E4) = one;
    FIELD_DWORD(0x20) = 0;
    FIELD_BYTE(0x1590) = 2;
    FIELD_DWORD(0x10C8) = 4;
    FIELD_DWORD(0x155C) = 4;
    ((TChat*)FIELD_DWORD(0x18))->ClearChat();

    long result = this->CreateDirectPlayConversation();
    ((RGE_Comm_Error*)FIELD_DWORD(0x14E0))->ShowReturn(result, STR_DP_CREATE_CONV);

    FIELD_DWORD_VOL(0x1C) = one;
    { ulong* p = (ulong*)&dSess2; int i; for (i = 0x14; i != 0; --i) *p++ = 0; }

    volatile long* app = (volatile long*)((char*)this + 0x12EC);
    dSess2.dwMaxPlayers = FIELD_WORD(0x12D8);
    dSess2.dwSize = 0x50;
    dSess2.one = one;
    dSess2.app0 = app[0];
    dSess2.guidInstance_Data1 = 0x44;
    dSess2.app1 = app[1];
    dSess2.app2 = app[2];
    dSess2.title = (const unsigned short*)((char*)this + 0x11FA);
    dSess2.app3 = app[3];

    this->DebugSessionInformation(&dSess2);

    void* dp = g_pDirectPlay;
    typedef long (__stdcall* OpenFn)(void* self, DPSESSIONDESC2_LOCAL* desc, unsigned long flags);
    result = ((OpenFn)(*(void***)dp)[0x60 / 4])(dp, &dSess2, 2);
    ((RGE_Comm_Error*)FIELD_DWORD(0x14E0))->ShowReturn(result, STR_DP_OPEN_CREATE);

    if (result != 0) {
        if (result == (long)0x887700AA) {
            this->NotifyWindow(0x17AE);
            return 0;
        }
        FIELD_DWORD(0x1558) = one;
        return 0;
    }

    this->SetRandomSeed(rge_base_game->random_game_seed);
    this->AddSelfPlayer();
    this->CommGetCaps();
    this->DPlayGetSessionDesc();
    FIELD_DWORD(0x10E0) = one;
    FIELD_DWORD(0x1714) = one;
    FIELD_DWORD(0x1568) = DAT_0062CF04;
    FIELD_DWORD(0x16D4 + FIELD_DWORD(0x10E0) * 4) = 2;
    FIELD_DWORD(0x20) = one;
    FIELD_DWORD(0x1558) = 3;
    FIELD_DWORD(0x14E4) = 0x7D1;
    this->UpdatePlayers();
    return one;
}
