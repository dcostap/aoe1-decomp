// 00428B10 TCommunications_Handler::DropDeadPlayer(unsigned int,unsigned long)
// Source: Com_hand.cpp lines 2326-2408
// Attempt log:
// - Initial natural reconstruction from packet/decompiler, with local layout offsets.
// - The packet's msg_str+4 decompiler name was a stack-mapping artifact; source must pass msg_str directly so VC5 emits lea [esp+0Ch]. Exact match.

#include <stdio.h>
#include "../../include/com_hand_context.h"


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
        rge_base_game->get_string(0x4BD, msg_str, 0x32);
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
