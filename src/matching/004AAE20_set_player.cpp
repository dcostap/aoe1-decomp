// 004AAE20 TRIBE_Screen_Sed::set_player
// Attempt log:
// 1: natural reconstruction from packet/Ghidra with exact member offsets and direct member calls.

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::set_player(short player, uchar update, uchar refresh)
{
    char str[30];
    long oldp = this->player_num - 1;
    if (oldp < 0) oldp = 0;

    rge_base_game->get_player()->unselect_object();

    if (update) {
        int v;
        v = atoi(this->player_inven_input[0]->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Food(oldp, v);
        *(float*)*(int*)((char*)this->world->players[this->player_num] + 0x50) = (float)v;

        v = atoi(this->player_inven_input[1]->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Wood(oldp, v);
        *(float*)(*(int*)((char*)this->world->players[this->player_num] + 0x50) + 4) = (float)v;

        v = atoi(this->player_inven_input[2]->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Stone(oldp, v);
        *(float*)(*(int*)((char*)this->world->players[this->player_num] + 0x50) + 8) = (float)v;

        v = atoi(this->player_inven_input[3]->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Gold(oldp, v);
        *(float*)(*(int*)((char*)this->world->players[this->player_num] + 0x50) + 12) = (float)v;

        ((RGE_Scenario*)this->world->scenario)->SetPlayerName(oldp, this->player_inven_input[4]->currentLine());
        ((RGE_Scenario*)this->world->scenario)->Set_player_Type(oldp, this->player_setting_drop[0]->currentLineNumber());
        ((RGE_Scenario*)this->world->scenario)->Set_player_Civ(oldp, this->player_setting_drop[1]->currentLineNumber() + 1);
        ((RGE_Scenario*)this->world->scenario)->Set_player_AI(oldp, this->AiRules->currentLine(0));
        ((RGE_Scenario*)this->world->scenario)->Set_BuildList(oldp, this->BuildList->currentLine(0));
        ((RGE_Scenario*)this->world->scenario)->Set_CityPlan(oldp, this->CityLayout->currentLine(0));
    }

    long p = player - 1;
    this->player_num = player;
    if (player != 0) {
        this->player_list->set_line(p);
        rge_base_game->set_player(player);
        if (refresh == 1) {
            int v;
            v = ((T_Scenario*)this->world->scenario)->Get_player_Food(p);
            sprintf(str, (char*)0x584610, v);
            this->player_inven_input[0]->set_text(str);
            v = ((T_Scenario*)this->world->scenario)->Get_player_Wood(p);
            sprintf(str, (char*)0x584610, v);
            this->player_inven_input[1]->set_text(str);
            v = ((T_Scenario*)this->world->scenario)->Get_player_Stone(p);
            sprintf(str, (char*)0x584610, v);
            this->player_inven_input[2]->set_text(str);
            v = ((T_Scenario*)this->world->scenario)->Get_player_Gold(p);
            sprintf(str, (char*)0x584610, v);
            this->player_inven_input[3]->set_text(str);
            this->player_inven_input[4]->set_text(((RGE_Scenario*)this->world->scenario)->GetPlayerName(p));
            this->player_setting_drop[0]->setCurrentLineNumber(((RGE_Scenario*)this->world->scenario)->Get_player_Type(p));
            this->player_setting_drop[1]->setCurrentLineNumber(((RGE_Scenario*)this->world->scenario)->Get_player_Civ(p) - 1);

            v = this->AiRules->get_line(((RGE_Scenario*)this->world->scenario)->Get_player_AI(p, 0));
            if (v == -1) {
                this->AiRules->append_line(((RGE_Scenario*)this->world->scenario)->Get_player_AI(p, 0), 0);
                v = this->AiRules->get_line(((RGE_Scenario*)this->world->scenario)->Get_player_AI(p, 0));
            }
            this->AiRules->setCurrentLineNumber(v);

            v = this->BuildList->get_line(((RGE_Scenario*)this->world->scenario)->Get_BuildList(p, 0));
            if (v == -1) {
                this->BuildList->append_line(((RGE_Scenario*)this->world->scenario)->Get_BuildList(p, 0), 0);
                v = this->BuildList->get_line(((RGE_Scenario*)this->world->scenario)->Get_BuildList(p, 0));
            }
            this->BuildList->setCurrentLineNumber(v);

            v = this->CityLayout->get_line(((RGE_Scenario*)this->world->scenario)->Get_CityPlan(p, 0));
            if (v == -1) {
                this->CityLayout->append_line(((RGE_Scenario*)this->world->scenario)->Get_CityPlan(p, 0), 0);
                v = this->CityLayout->get_line(((RGE_Scenario*)this->world->scenario)->Get_CityPlan(p, 0));
            }
            this->CityLayout->setCurrentLineNumber(v);
        }
    }
}
