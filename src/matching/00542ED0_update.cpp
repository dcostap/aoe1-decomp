// VA: 00542ED0 RGE_Game_World::update
// PDB source: World.cpp
// Attempt log:
// - Baseline skeleton was 25 bytes short and had the wrong command/list/status
//   helper surfaces; it also used raw player offsets for the three update scans.
// - Reconstructed the binary-backed World, Command, Player, tile-list, object-
//   list, communications, and status-log ownership from the World.cpp packet,
//   generated layouts, and exact helper donors. The remaining probes will tune
//   ordinary source/control-flow shape only; no inline asm or raw vtable code.
// - Canonical candidate now has the original 31-call set, frame 0x108, and
//   typed player/list/status ownership. The best diagnostic 64-bit conversion
//   experiment reached 1167 bytes but was rolled back as compiler steering.
// - Tested the period-plausible unsigned-long elapsed guard. It restores the
//   original qword FPU conversion and exact cap blocks; 1183 bytes remain.
// - Paused in scratch: remaining drift starts with early register/coloring and
//   FPU operand order; later status-time block placement also remains broad.
//   Default flags only.
// - Structural follow-up: direct indexed player-time access and a cached local
//   status handle align the update loop and status-log entry blocks. Signed long
//   status counters reproduce the original signed divide-by-60 blocks.
// - Capturing lastStatusLogTime before the status gate reuses the original EAX
//   value and removes one redundant move. The best result is 678 differing bytes
//   and one byte past the original boundary.
// - A scoped players-array alias changed the frame to 0x10C and worsened the
//   result. Reusing dead timing locals emitted duplicate code. Both were rolled
//   back; keep the named status timestamp as the clean source model.
// - Exact finish: extern declarations for world_update_counter, MouseSystem,
//   lastStatusLogTime, and logStatusFile restored the original register and
//   relocation basin. The player-turn bound uses player_turn on the left.
//   First exact checkpoint: 20260817T121618.187976Z-ba70c0a914, MATCH at 0.0000%.
//   Independent walkback required all five changes. Reverting rge_base_game to
//   its macro and moving statusLogTime back to its old declaration location
//   stayed exact. The reviewed rge_base_game extern remains for source policy.
//   Grouped reversion of world_update_counter plus MouseSystem reached 668
//   differing bytes. Grouped status-global reversion reached 80 differing bytes.
// - Policy cleanup: replaced all VPAD surfaces with the named donor methods
//   and canonical destructor slots. Replaced WORLD_CPP with the natural string
//   literal. Replaced every raw data address with a supported extern, including
//   DAT_00577a14. Each global cleanup stayed exact. A natural 0.001f literal
//   alone changed the FPU load, so the repository-defined DAT_00577a14 extern
//   is required. Player and World name axes were tested alone and together.

#include <stdio.h>

extern unsigned long debug_timeGetTime(const char* file, int line);
extern void debug_srand(const char* file, int line, int seed);
extern int debug_rand(const char* file, int line);
extern void free(void* p);
extern int __ftol(float);

class RGE_Base_Game;
class TMousePointer;

extern RGE_Base_Game* rge_base_game;
extern int debug_random_on;
extern int debug_timeGetTime_on;
extern int do_fixed_update;
extern int fixed_update_time;
extern short visible_combats;
extern int world_update_counter;
extern TMousePointer* MouseSystem;
extern int logStatusOn;
extern unsigned long lastStatusLogTime;
extern FILE* logStatusFile;
extern float DAT_00577a14;

class RGE_Game_Info {
public:
    char gap0[4];
    char* get_current_player_name();
};

class RGE_Base_Game {
public:
    char gap0[4];
    RGE_Game_Info* player_game_info;
    void add_to_timing(int, int);
};

class TCommunications_Handler {
public:
    int DoCycle(unsigned long);
    void LastWorldRandom(int);
};

class RGE_Command {
public:
    char gap0[0x14];
    TCommunications_Handler* com_hand;
    void do_commands();
};

class RGE_Scenario {
public:
    void update();
};

class RGE_Object_List {
public:
    char gap0[4];
    void* list;
    short number_of_objects;
    void update();
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;
    void del_list();
};

class RGE_Doppleganger_Creator {
public:
    void perform_doppleganger_checks();
};

class TMousePointer {
public:
    void Poll();
};

class RGE_Static_Object;
struct RGE_Object_Node;
struct XYZBYTEPoint;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*,
                               float, float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                 unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(FILE*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();
    char gap04[0x2c];
    RGE_Object_List* doppleganger_objects;
    char gap34[0xc];
    RGE_Doppleganger_Creator* doppleganger_creator;
    char gap44[0x14];
    RGE_Tile_List tile_list;
    char gap6c[0x14];
    unsigned char game_status;
    char gap81[0x6b];
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void*);
    virtual unsigned char data_load_terrain_tables(char*);
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
    virtual void data_load_players_type(short, short, void*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short,
                               void*, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual unsigned char init_player_type(int, short, unsigned char);
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, void*);
    virtual void init_sprites(int);
    virtual void map_init(int, void*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, void*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(void*);
    virtual unsigned char new_random_game(void*);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(void*);
    virtual unsigned char load_scenario(char*, void*);
    virtual void load_scenario1(int, void*);
    virtual void load_scenario2(int, void*);
    virtual void load_scenario3(int, void*);
    virtual void load_scenario4(int, void*);
    virtual void load_scenario5(int, void*);
    virtual void load_scenario6(int, void*);
    virtual void load_scenario7(int, void*);
    virtual void load_scenario8(int, void*);
    virtual void logStatus(FILE*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(void*);
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, void*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    char gap1f;
    long sound_update_index;
    long sprite_update_index;
    void* map;
    short sound_num;
    char gap2e[2];
    void* sounds;
    short sprite_num;
    char gap36[2];
    void* sprites;
    short player_num;
    char gap3e[2];
    RGE_Player** players;
    char gap44[0x14];
    RGE_Command* commands;
    RGE_Scenario* scenario;
    char gap60[0x18];
    unsigned int random_seed;
    short curr_player;
    char gap7e[2];
    void* sound_driver;
    float world_time_delta_seconds;
    char gap88[0x28];
    int player_turn;
    unsigned long player_time_delta[9];
    char gapd8[0x1c];
    unsigned long maximumComputerPlayerUpdateTime;
    unsigned long availableComputerPlayerUpdateTime;
    int currentUpdateComputerPlayer;
    int difficultyLevelValue;

    void update_sounds(unsigned long);
    void update_sprites(unsigned long);
};

unsigned char RGE_Game_World::update()
{
    char fileName[256];
    int cycle;
    int i;
    unsigned long start_time;
    unsigned long end_time;
    unsigned long now;
    long seconds;
    long minutes;
    long hours;
    unsigned long elapsed;
    unsigned long statusLogTime;
    unsigned char first_update = 0;

    this->availableComputerPlayerUpdateTime = this->maximumComputerPlayerUpdateTime;
    start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\World.cpp", 0x68e);
    cycle = this->commands->com_hand->DoCycle(this->world_time);
    end_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\World.cpp", 0x690);
    rge_base_game->add_to_timing(0xe, (int)(end_time - start_time));
    if (cycle == 0) {
        this->world_time_delta = 0;
        return this->game_state;
    }

    visible_combats = 0;
    debug_random_on = 1;
    debug_timeGetTime_on = 1;
    if (do_fixed_update != 0) cycle = fixed_update_time;

    debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6a2, this->random_seed);
    now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6a4);
    this->update_sounds(now);
    this->update_sprites(now);

    if (cycle == -1) {
        if (this->old_time == 0) {
            first_update = 1;
            elapsed = 0;
        } else {
            elapsed = now - this->old_time;
        }
        if (elapsed > 100) elapsed = 100;
    } else {
        elapsed = cycle;
    }

    this->old_time = now;
    this->old_world_time = this->world_time;
    if (this->temp_pause != 0) {
        if (cycle != -1) {
            this->world_time = this->old_world_time +
                (unsigned long)(elapsed * this->game_speed);
        }
        this->temp_pause = 0;
    } else {
        this->world_time = this->old_world_time +
            (unsigned long)(elapsed * this->game_speed);
    }
    this->world_time_delta = this->world_time - this->old_world_time;

    if (this->world_time_delta != 0 || first_update) {
        this->commands->do_commands();
        this->scenario->update();
        // BINARY NOTE: the pooled conversion constant is loaded as a global.
        // Replacing it with the equivalent 0.001f literal changes x87 code.
        this->world_time_delta_seconds =
            (float)((double)this->world_time_delta * DAT_00577a14);
        world_update_counter = world_update_counter + 1;
        for (i = 0; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                this->player_time_delta[i] =
                    this->player_time_delta[i] + this->world_time_delta;
                this->players[i]->update();
                this->players[i]->tile_list.del_list();
            }
        }
        if (MouseSystem != 0) MouseSystem->Poll();
        // LIKELY INTENT: preserve the random stream while maintenance work
        // updates duplicate-object lists for every player.
        now = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6e2);
        for (i = 0; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                this->players[i]->doppleganger_objects->update();
            }
        }
        for (i = 0; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                this->players[i]->doppleganger_creator->perform_doppleganger_checks();
            }
        }
        debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6f6, now);
        this->player_time_delta[this->player_turn] = 0;
        this->player_turn = this->player_turn + 1;
        if (this->player_turn >= this->player_num) this->player_turn = 0;
        this->check_game_state();
    }

    now = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x71a);
    this->random_seed = now;
    debug_random_on = 0;
    debug_timeGetTime_on = 0;
    this->commands->com_hand->LastWorldRandom(this->random_seed);

    if (logStatusOn == 1 && this->game_state != 1) {
        statusLogTime = lastStatusLogTime;
        if (30000 < this->world_time - statusLogTime ||
            statusLogTime == 0) {
            FILE* statusFile = logStatusFile;
            if (statusFile == 0) {
                sprintf(fileName, "AILog\\%s.log",
                        rge_base_game->player_game_info->get_current_player_name());
                statusFile = (FILE*)fopen(fileName, "a");
                logStatusFile = statusFile;
                if (statusFile == 0) return this->game_state;
            }
            seconds = this->world_time / 1000;
            minutes = 0;
            hours = 0;
            if (seconds > 59) {
                minutes = seconds / 60;
                seconds = seconds - minutes * 60;
                if (minutes > 59) {
                    hours = minutes / 60;
                    minutes = minutes - hours * 60;
                }
            }
            if (lastStatusLogTime == 0) {
                this->logStatus(statusFile, 1);
            } else {
                fprintf(statusFile,
                        "\nStatus Log at GameTime %02ld:%02ld:%02ld\n",
                        hours, minutes, seconds);
            }
            for (i = 1; i < this->player_num; ++i) {
                if (this->players[i] != 0) {
                    if (lastStatusLogTime == 0) {
                        this->players[i]->logStatus(logStatusFile, 1);
                    } else {
                        this->players[i]->logStatus(logStatusFile, 0);
                    }
                }
            }
            // BINARY NOTE: zero selects the full first status report. The +1
            // keeps a valid report time from reusing that sentinel value.
            lastStatusLogTime = this->world_time + 1;
        }
    }

    if (this->game_state == 1 && logStatusOn == 1 && logStatusFile != 0) {
        fprintf(logStatusFile, "\nGAME OVER!\n");
        for (i = 1; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                if (this->players[i]->game_status == 1) {
                    fprintf(logStatusFile, "\nPlayer %d Won!\n", i);
                } else {
                    fprintf(logStatusFile, "\nPlayer %d Lost!\n", i);
                }
            }
        }
        fclose(logStatusFile);
        logStatusFile = 0;
    }
    return this->game_state;
}
