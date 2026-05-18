// VA 00518F00 TRIBE_Player::logStatus
// tplayer.cpp:4744-4805
// Attempt log:
// 1: Direct source from packet/decompiler, preserving sequential fprintf/call pattern.

typedef void FILE;
extern "C" int __cdecl fprintf(FILE*, const char*, ...);

class RGE_Base_Game_00518F00 { public: virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C(); virtual void get_string(int, char*, int); };
extern RGE_Base_Game_00518F00* rge_base_game;

class RGE_Victory_Conditions_00518F00 {
public:
    int get_victory_points_group(int);
    int get_victory_points_id(int);
    int get_victory_points();
    int get_attribute_id(int);
};
class BuildAI_00518F00 { public: char* buildListName(); int buildListLength(); int numberItemsIntoBuildList(); char* lastBuildItemRequested(); char* currentBuildItemRequested(); };
class ConstAI_00518F00 { public: char* constructionPlanName(); };
class StratAI_00518F00 { public: char* ruleSetName(); };
class TactAI_00518F00 { public: int neededResource(int); int desiredNumberGatherers(); int numberGatherers(); int desiredNumberCivilianExplorers(); int numberCivilianExplorers(); int numberCivilians(); int numberSoldiers(); };
struct MainAI_00518F00 { char gap[1]; };
struct Res_00518F00 { float food; float wood; float stone; float gold; char gap10[0x1C]; float pop; };

class TRIBE_Player_00518F00 {
public:
    char gap_00[0x34];
    RGE_Victory_Conditions_00518F00* victory;
    char gap_38[0x12];
    short player_id;
    char gap_4C[4];
    Res_00518F00* res;
    char gap_54[0xB1];
    unsigned char civ_id;
    char gap_106[0x132];
    MainAI_00518F00* ai;
    void logStatus(FILE* f, int verbose);
};

void TRIBE_Player_00518F00::logStatus(FILE* f, int verbose)
{
    char tempString[256];
    if (f == 0)
        return;

    fprintf(f, "Player %d:\n", (int)this->player_id);
    if (verbose == 1) {
        rge_base_game->get_string((int)this->civ_id + 0x27f6, tempString, 0x100);
        if (this->ai == 0) {
            fprintf(f, "  Human Player, %s.\n", tempString);
        } else {
            fprintf(f, "  Computer Player, %s.\n", tempString);
            fprintf(f, "  Build List:      %s.\n", ((BuildAI_00518F00*)((char*)this->ai + 0x104))->buildListName());
            fprintf(f, "  City Plan:       %s.\n", ((ConstAI_00518F00*)((char*)this->ai + 0x6C4))->constructionPlanName());
            fprintf(f, "  VC File:         %s.\n", ((StratAI_00518F00*)((char*)this->ai + 0x10E74))->ruleSetName());
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
                ((BuildAI_00518F00*)((char*)this->ai + 0x104))->currentBuildItemRequested(),
                ((BuildAI_00518F00*)((char*)this->ai + 0x104))->lastBuildItemRequested(),
                ((BuildAI_00518F00*)((char*)this->ai + 0x104))->numberItemsIntoBuildList(),
                ((BuildAI_00518F00*)((char*)this->ai + 0x104))->buildListLength());
        fprintf(f, "Civilians: Total=%d, Exp(%d/%d), Gat(%d/%d), Res(%d,%d,%d,%d).\n",
                ((TactAI_00518F00*)((char*)this->ai + 0x1146C))->numberCivilians(),
                ((TactAI_00518F00*)((char*)this->ai + 0x1146C))->numberCivilianExplorers(),
                ((TactAI_00518F00*)((char*)this->ai + 0x1146C))->desiredNumberCivilianExplorers(),
                ((TactAI_00518F00*)((char*)this->ai + 0x1146C))->numberGatherers(),
                ((TactAI_00518F00*)((char*)this->ai + 0x1146C))->desiredNumberGatherers(),
                ((TactAI_00518F00*)((char*)this->ai + 0x1146C))->neededResource(0),
                ((TactAI_00518F00*)((char*)this->ai + 0x1146C))->neededResource(1),
                ((TactAI_00518F00*)((char*)this->ai + 0x1146C))->neededResource(2),
                ((TactAI_00518F00*)((char*)this->ai + 0x1146C))->neededResource(3));
        fprintf(f, "Number Soldiers=%d.\n", ((TactAI_00518F00*)((char*)this->ai + 0x1146C))->numberSoldiers());
    }
}
