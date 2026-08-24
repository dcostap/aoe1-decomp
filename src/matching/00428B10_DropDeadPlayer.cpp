// 00428B10 TCommunications_Handler::DropDeadPlayer(unsigned int,unsigned long)
// Source: Com_hand.cpp lines 2326-2408
// Attempt log:
// - Initial natural reconstruction from packet/decompiler, with local layout offsets.
// - Corrected RGE_Base_Game local stub for vptr: world pointer is emitted at +0x3F4 using gap[0x3F0] before the field.
// - The packet's msg_str+4 decompiler name was a stack-mapping artifact; source must pass msg_str directly so VC5 emits lea [esp+0Ch]. Exact match.

#include <stdio.h>

#if !defined(COM_HAND_TU_CONTEXT)
struct TDebuggingLog { void Log(char*, ...); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
struct TRIBE_World { void send_zone_score_info(); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
struct RGE_Base_Game { char gap[0x3F0]; TRIBE_World* world; virtual void vf0(); virtual void vf4(); virtual void vf8(); virtual void vfC(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C(); virtual void language(int, char*, int); };
#endif // COM_HAND_TU_CONTEXT

extern RGE_Base_Game* rge_base_game;

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap0[0xFC5];
    char TBuff[1];
    char gapFC6[0x10C8-0xFC6];
    unsigned int current_turn;
    char gap10CC[0x10E0-0x10CC];
    unsigned int Me;
    char gap10E4[0x12C8-0x10E4];
    char* FriendlyName;
    char gap12CC[0x12D8-0x12CC];
    unsigned short MaxGamePlayers;
    char gap12DA[0x13BC-0x12DA];
    int PlayerStopTurn[16];
    char gap13FC[0x1550-0x13FC];
    unsigned char NeedsToBeSent;
    char gap1551[3];
    unsigned int LastSentTime;
    int ProgramState;
    char gap155C[0x16FC-0x155C];
    unsigned char InvalidPlayer[16];
    char gap170C[0x174C-0x170C];
    int WasKicked[16];
    void NotifyWindowParam(int msg, int player);
    int IsPlayerHuman(unsigned int player);
    void InitPlayerInformation(unsigned int player, int human, char* status, char* info);
    void SetPlayerHumanity(unsigned int player, int human);
    void UpdatePlayers();
    int CalculatePlayerRange();
    void DropDeadPlayer(unsigned int player, unsigned long dpid);
};
#endif // COM_HAND_TU_CONTEXT


#define S(x) ((char*)(x))

void TCommunications_Handler::DropDeadPlayer(unsigned int player, unsigned long dpid)
{
    char msg_str[50];
    this->WasKicked[player] = 1;
    L->Log(S(0x5818B8), player, dpid);
    this->PlayerOptions.InvalidPlayer[player] = 0;
    if (player == 0) {
        L->Log(S(0x581894));
        this->UpdatePlayers();
        return;
    }
    if (player == this->Me) {
        L->Log(S(0x581888));
        this->NotifyWindowParam(0x17B2, this->Me);
        unsigned int i = 1;
        if (this->MaxGamePlayers >= 1) {
            do {
                this->WasKicked[i] = 1;
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        rge_base_game->world->send_zone_score_info();
        L->Log(S(0x580C4C));
        i = 1;
        if (this->MaxGamePlayers >= 1) {
            do {
                this->InitPlayerInformation(i, 0, S(0x580460), S(0x580460));
                i++;
            } while ((int)i <= (int)(unsigned int)this->MaxGamePlayers);
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->UpdatePlayers();
        return;
    }
    if (!this->IsPlayerHuman(player)) {
        this->NotifyWindowParam(0x17B5, player);
        L->Log(S(0x581854));
        this->InitPlayerInformation(player, 0, S(0x581830), S(0x58183C));
        this->UpdatePlayers();
        this->CalculatePlayerRange();
        return;
    }
    if ((int)this->PlayerOptions.ProgramState >= 5 && this->current_turn >= 6) {
        L->Log(S(0x581818));
        rge_base_game->language(0x4BD, msg_str, 0x32);
        sprintf(this->TBuff, msg_str, player, this->FriendlyName[player].Text);
        L->Log(this->TBuff);
        this->InitPlayerInformation(player, 0, S(0x581810), S(0x580460));
        this->SetPlayerHumanity(player, 0);
        this->UpdatePlayers();
        this->CalculatePlayerRange();
        if (this->PlayerStopTurn[player] != 0) return;
    } else {
        L->Log(S(0x5817EC));
        this->InitPlayerInformation(player, 0, S(0x581810), S(0x58183C));
        this->SetPlayerHumanity(player, 0);
        this->UpdatePlayers();
        this->CalculatePlayerRange();
    }
    this->NotifyWindowParam(0x17B3, player);
}
