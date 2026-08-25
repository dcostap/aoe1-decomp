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

struct _iobuf;
typedef _iobuf FILE;

extern "C" int __cdecl fprintf(FILE* stream, const char* format, ...);
extern "C" long __cdecl time(long* value);
extern "C" void* __cdecl localtime(long* value);
extern "C" char* __cdecl asctime(void* value);

#ifndef TWORLD_PHASE2_CONTEXT
class RGE_Static_Object;

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~RGE_Scenario();
    char gap_04[0x100c];
    char* scenario_name; // +0x1010
};

class RGE_Player_Info;
class RGE_Sound;
class TSound_Driver;
class TCommunications_Handler;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE*);
protected:
    virtual unsigned char data_load_terrain_tables(char*);
public:
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
protected:
    virtual void data_load_players_type(short, short, FILE*);
public:
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short,
                               RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
protected:
    virtual unsigned char init_player_type(int, short, unsigned char);
public:
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
protected:
    virtual void master_player_init(int);
public:
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
protected:
    virtual unsigned char new_random_game(RGE_Player_Info&);
public:
    virtual void save(int);
protected:
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                       unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(char*, RGE_Player_Info*);
    virtual unsigned char load_scenario(RGE_Player_Info&);
    virtual void load_scenario1(int, RGE_Player_Info&);
    virtual void load_scenario2(int, RGE_Player_Info&);
    virtual void load_scenario3(int, RGE_Player_Info&);
    virtual void load_scenario4(int, RGE_Player_Info&);
    virtual void load_scenario5(int, RGE_Player_Info&);
    virtual void load_scenario6(int, RGE_Player_Info&);
    virtual void load_scenario7(int, RGE_Player_Info&);
    virtual void load_scenario8(int, RGE_Player_Info&);
public:
    virtual void logStatus(FILE*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual void setup_player_colors();
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char load_game(char*);
    virtual unsigned char new_game(RGE_Player_Info&, int);
    virtual unsigned char new_scenario(RGE_Player_Info&, int);
    virtual unsigned char save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual unsigned char save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(unsigned char);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual void scenario_init(RGE_Game_World*);

    char gap_04[0x38];
    short player_num; // +0x3C
    char gap_3E[0x1C];
    RGE_Scenario* scenario; // +0x5C
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int mapSize();
    int mapType();
    int victoryType();
};

extern TRIBE_Game* rge_base_game;

class TRIBE_World : public RGE_Game_World {
protected:
    virtual void logStatus(FILE* stream, int verbose);
};
#endif

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

        ((TRIBE_Game*)rge_base_game)->get_string(
            ((TRIBE_Game*)rge_base_game)->mapSize() + 0x2973,
            tempString, 0x100);
        fprintf(stream, "Map Size:                %s\n", tempString);

        ((TRIBE_Game*)rge_base_game)->get_string(
            ((TRIBE_Game*)rge_base_game)->mapType() + 0x296A,
            tempString, 0x100);
        fprintf(stream, "Map Type:                %s\n", tempString);

        ((TRIBE_Game*)rge_base_game)->get_string(
            ((TRIBE_Game*)rge_base_game)->victoryType() + 0x28A6,
            tempString, 0x100);
        fprintf(stream, "Victory Condition:       %s\n", tempString);
    }
}
