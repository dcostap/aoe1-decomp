// VA: 0052E0B0 TRIBE_World::logStatus (358 B)
// PDB source: tworld.cpp
// Packet-grounded status logger: timestamp, player count, scenario name, and
// translated map/victory settings.
// Attempt log:
// - Reconstructed the proven clock/tempString stack window as `long clock`
//   followed by `char tempString[256]`; typed TRIBE_Game helpers plus the
//   inherited vslot +0x20 get_string restored all 16 ordered calls.
// - Removed the decompiler-only `scenario != 0` guard.  The oracle reads
//   scenario->scenario_name at +0x1010 directly, then tests that name; the
//   natural typed source is an exact 358-byte match.

#include <string.h>

typedef void FILE;
extern "C" int __cdecl fprintf(FILE* stream, const char* format, ...);
extern "C" long __cdecl time(long* value);
extern "C" void* __cdecl localtime(long* value);
extern "C" char* __cdecl asctime(void* value);

class RGE_Static_Object;

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~RGE_Scenario();
    char gap_04[0x100c];
    char* scenario_name; // +0x1010
};

class RGE_Game_World {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void logStatus(FILE* stream, int verbose);

    char gap_04[0x38];
    short player_num; // +0x3C
    char gap_3E[0x1C];
    RGE_Scenario* scenario; // +0x5C
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual char* get_string(int id, char* buffer, int size); // +0x20
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int mapSize();
    int mapType();
    int victoryType();
};

class TRIBE_World : public RGE_Game_World {
public:
    virtual void logStatus(FILE* stream, int verbose);
};

extern TRIBE_Game* rge_base_game;

void TRIBE_World::logStatus(FILE* stream, int verbose)
{
    long clock;
    char tempString[256];

    if (stream != 0 && verbose == 1) {
        fprintf(stream, "\n\n\n****************************************\n");

        time(&clock);
        fprintf(stream, "AI Log file for Game Started %s", asctime(localtime(&clock)));
        fprintf(stream, "Number Players:          %d\n", (int)this->player_num - 1);

        if (this->scenario->scenario_name != 0 &&
            strlen(this->scenario->scenario_name) != 0) {
            fprintf(stream, "Scenario:                %s\n", this->scenario->scenario_name);
            return;
        }

        rge_base_game->get_string(rge_base_game->mapSize() + 0x2973,
                                  tempString, 0x100);
        fprintf(stream, "Map Size:                %s\n", tempString);

        rge_base_game->get_string(rge_base_game->mapType() + 0x296A,
                                  tempString, 0x100);
        fprintf(stream, "Map Type:                %s\n", tempString);

        rge_base_game->get_string(rge_base_game->victoryType() + 0x28A6,
                                  tempString, 0x100);
        fprintf(stream, "Victory Condition:       %s\n", tempString);
    }
}
