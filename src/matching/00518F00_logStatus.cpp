// VA 00518F00 TRIBE_Player::logStatus
// tplayer.cpp:4744-4805
// Attempt log:
// 1: Direct source from packet/decompiler, preserving sequential fprintf/call pattern.
// 2: Recovered the canonical TRIBE_Player owner and shared tplayer ABI. The
//    virtual owner, frame, calls, and all 994 bytes now match the target.

#include "../../include/tplayer_context.h"

typedef struct _iobuf FILE;
extern "C" int __cdecl fprintf(FILE*, const char*, ...);

void TRIBE_Player::logStatus(FILE* f, int verbose)
{
    char tempString[256];
    if (f == 0)
        return;

    fprintf(f, "Player %d:\n", (int)this->id);
    if (verbose == 1) {
        rge_base_game->get_string((int)this->civ_id + 0x27f6, tempString, 0x100);
        if (this->ai == 0) {
            fprintf(f, "  Human Player, %s.\n", tempString);
        } else {
            fprintf(f, "  Computer Player, %s.\n", tempString);
            fprintf(f, "  Build List:      %s.\n", ((TribeBuildAIModule*)((char*)this->ai + 0x104))->buildListName());
            fprintf(f, "  City Plan:       %s.\n", ((TribeConstructionAIModule*)((char*)this->ai + 0x6C4))->constructionPlanName());
            fprintf(f, "  VC File:         %s.\n", ((TribeStrategyAIModule*)((char*)this->ai + 0x10E74))->ruleSetName());
        }
    }

    fprintf(f, "  Points:\n");
    fprintf(f, "    Combat         %d.\n", this->victory->get_victory_points_group(0));
    fprintf(f, "    Economy        %d.\n", this->victory->get_victory_points_group(1));
    fprintf(f, "    Religion       %d.\n", this->victory->get_victory_points_group(2));
    fprintf(f, "    Science        %d.\n", this->victory->get_victory_points_group(3));
    fprintf(f, "    Survival       %d.\n", this->victory->get_victory_points_id(0x16));
    fprintf(f, "    Wonder         %d.\n", this->victory->get_victory_points_id(0x17));
    fprintf(f, "      Total:       %d.\n", this->victory->get_victory_points());
    fprintf(f, "  Population:      %d.\n", (int)this->res->pop);
    fprintf(f, "  Kills:           %d.\n", this->victory->get_attribute_id(0));
    fprintf(f, "  Kill Ratio:      %d.\n", this->victory->get_attribute_id(2));
    fprintf(f, "  Razings:         %d.\n", this->victory->get_attribute_id(1));
    fprintf(f, "  Food:            %d.\n", (int)this->res->food);
    fprintf(f, "  Gold:            %d.\n", (int)this->res->gold);
    fprintf(f, "  Stone:           %d.\n", (int)this->res->stone);
    fprintf(f, "  Wood:            %d.\n", (int)this->res->wood);
    fprintf(f, "  Technology:      %d.\n", this->victory->get_attribute_id(0x11));
    fprintf(f, "  Exploration:     %d.\n", this->victory->get_attribute_id(7));

    if (this->ai != 0) {
        fprintf(f, "Build AI: last=%s, last2=%s, Progress=%d/%d.\n",
                ((TribeBuildAIModule*)((char*)this->ai + 0x104))->currentBuildItemRequested(),
                ((TribeBuildAIModule*)((char*)this->ai + 0x104))->lastBuildItemRequested(),
                ((TribeBuildAIModule*)((char*)this->ai + 0x104))->numberItemsIntoBuildList(),
                ((TribeBuildAIModule*)((char*)this->ai + 0x104))->buildListLength());
        fprintf(f, "Civilians: Total=%d, Exp(%d/%d), Gat(%d/%d), Res(%d,%d,%d,%d).\n",
                ((TribeTacticalAIModule*)((char*)this->ai + 0x1146C))->numberCivilians(),
                ((TribeTacticalAIModule*)((char*)this->ai + 0x1146C))->numberCivilianExplorers(),
                ((TribeTacticalAIModule*)((char*)this->ai + 0x1146C))->desiredNumberCivilianExplorers(),
                ((TribeTacticalAIModule*)((char*)this->ai + 0x1146C))->numberGatherers(),
                ((TribeTacticalAIModule*)((char*)this->ai + 0x1146C))->desiredNumberGatherers(),
                ((TribeTacticalAIModule*)((char*)this->ai + 0x1146C))->neededResource(0),
                ((TribeTacticalAIModule*)((char*)this->ai + 0x1146C))->neededResource(1),
                ((TribeTacticalAIModule*)((char*)this->ai + 0x1146C))->neededResource(2),
                ((TribeTacticalAIModule*)((char*)this->ai + 0x1146C))->neededResource(3));
        fprintf(f, "Number Soldiers=%d.\n", ((TribeTacticalAIModule*)((char*)this->ai + 0x1146C))->numberSoldiers());
    }
}
