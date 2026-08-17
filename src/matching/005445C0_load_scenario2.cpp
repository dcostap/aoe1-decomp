// 005445C0 RGE_Game_World::load_scenario2
// Attempt log:
// 1: natural reconstruction from packet using byte-offset class surface; explicit __thiscall function-pointer casts are rejected by VC5 warning policy.
// 2: switched indirect calls to local virtual surfaces with dummy slots; compiles but broad mismatch, first diff stack frame 0x68 vs original 0x60.
// 3: remaining lead is local-slot coalescing/reuse: original reuses the same stack slots for object fields and loop/state values, and even reuses a dead incoming parameter slot for outer index.
// 4: restored the period ABI surfaces: scenario helpers take (player) or (player,mode),
//    Player scenario_load takes a float factor, and make_scenario_obj takes object state
//    plus float angle. Removed the decompiler's extra helper arguments/aliases and used
//    the initial 4-byte rem header for next_object_id.
// 5: nested loadAIInformation argument evaluation recovered the pre-pushed -1 and
//    reduced the candidate to 705 bytes; the final for-loop was closer at 702 bytes.
// 6: reading the first scenario-player byte through player_id_hash[8], keeping the
//    transient byte in master_player_id, and using direct players[mapped] access
//    recovered the exact object-record block and the 703-byte/148-byte-diff best.
// 7: exhausted source-shape probes; the remaining drift is structural local coloring:
//    frame 0x5c vs 0x60, first header-byte home, outer-index parameter-home reuse, the
//    final rem reread home, and the final short-player bound compare. Kept the typed,
//    period-plausible candidate in scratch rather than retaining compiler-only aliases.
// 8: replaced the raw world counter address with its typed global declaration; VC5
//    moved the local frame and worsened the structural diff, so no address macro remains.
// 9: C linkage for the typed counter had identical output and was discarded as a
//    context-only probe.
// 10: replaced the header type-pun with a named int and 13-byte remainder buffer;
//     the emitted code stayed in the same basin.
// 11: grouping those separate values in one record was a codegen duplicate.
//     Keep their stream ownership separate in the final typed source.
// 12: changed the final player-AI pass from a for loop to the natural do-while
//     shape shown by the original pre-check and bottom player-count compare.
// 13: spelled the scenario-player guard as `scenario_player_num <= j` so the
//     typed compare follows the original counter-left branch form.
//     It changed only two bytes without improving the metrics; restored `j >=`.
// 14: restored the distinct typed scenario-player byte local, matching the
//     original 0x60 frame and all object-record stack homes. Same-TU exact
//     donor evidence then selected duplicated scenario-load fallback calls and
//     the positive nested final guard with an explicit return arm. Replaced
//     generic virtual placeholders with the donor-backed period ABI surface.
//     Result: MATCH (700/700 bytes, 0.0000%), default flags.

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" int __cdecl rge_close(int);

extern int world_update_counter;
class RGE_Static_Object;
class RGE_Scenario {
public:
    int GetPlayerPosture(int);
    char* Get_player_AI(int, int);
    char* Get_CityPlan(int, int);
    char* Get_BuildList(int, int);
};
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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual void* make_scenario_obj(float, float, float, short, unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    void remake_visible_map();
};
class RGE_Player_Info {
public:
    char name[9][65];
    char type[9];
    char tribe[9];
    unsigned char gap_25b;
    short color[9];
    unsigned char gap_26e[2];
    long player_id_hash[9];
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
    virtual void data_load_map(char*, char*, char*, char*, short, short, short, void*, char*);
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
    virtual void command_init(int, void*);
    virtual void world_init(int, void*, void*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info*);
    virtual unsigned char new_random_game(RGE_Player_Info*);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char, unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(RGE_Player_Info*);
    virtual unsigned char load_scenario(char*, RGE_Player_Info*);
    virtual void load_scenario1(int, RGE_Player_Info*);
    virtual void load_scenario2(int, RGE_Player_Info& info);
    virtual void load_scenario3(int, RGE_Player_Info*);
    virtual void load_scenario4(int, RGE_Player_Info*);
    virtual void load_scenario5(int, RGE_Player_Info*);
    virtual void load_scenario6(int, RGE_Player_Info*);
    virtual void load_scenario7(int, RGE_Player_Info*);
    virtual void load_scenario8(int, RGE_Player_Info*);
    virtual void logStatus(void*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, void*, void*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char load_game(char*);
    virtual unsigned char new_game(RGE_Player_Info*, int);
    virtual unsigned char new_scenario(RGE_Player_Info*, int);
    virtual unsigned char save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual unsigned char save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(unsigned char);
    virtual void scenario_init0();
    virtual void scenario_init(RGE_Game_World*);
    virtual void scenario_init(int, RGE_Game_World*);
    char gap_04[0x38];
    short player_num;
    char gap_3e[2];
    RGE_Player** players;
    char gap_44[0x18];
    RGE_Scenario* scenario;
    char gap_60[8];
    int next_object_id;
    int next_reusable_object_id;
    int scenario_object_id;
    unsigned char scenario_object_flag;
};

void RGE_Game_World::load_scenario2(int handle, RGE_Player_Info& info)
{
    long player_id_hash[9];
    int next_object_id;
    char rem[13];
    int obj_id;
    float world_x;
    float world_y;
    float world_z;
    short master_id;
    unsigned char obj_state;
    float obj_angle;
    int count;
    int scenario_player_num;
    unsigned char player_id;
    unsigned char master_player_id;

    world_update_counter = 0;
    rge_read(handle, &next_object_id, 4);
    this->scenario_init(handle, this);
    this->scenario_make_map(handle);

    int player_num = this->player_num;
    if (player_num > 0) {
        do { for (int k = 0; k < 9; k++) player_id_hash[k] = -1; } while (player_num > 10);
    }
    int i = 0;
    if (player_num > 0) {
            long* p = &info.player_id_hash[0];
        do { int idx = *p++; player_id_hash[idx] = i; i++; } while (i < player_num);
    }
    int j = 0;
    if (player_num > 0) {
        do { this->players[j]->remake_visible_map(); j++; } while (j < this->player_num);
    }

    rge_read(handle, &scenario_player_num, 4);
    j = 0;
    if (scenario_player_num > 0) { do { rge_read(handle, &player_id, 1); rge_read(handle, &master_player_id, 1); j++; } while (j < scenario_player_num); }

    int outer = 0;
    if (scenario_player_num > 0) {
        long* map = player_id_hash;
        do {
            rge_read(handle, &count, 4);
            j = 0;
            if (count > 0) {
                do {
                    rge_read(handle, &world_z, 4);
                    rge_read(handle, &world_y, 4);
                    rge_read(handle, &world_x, 4);
                    rge_read(handle, &obj_id, 4);
                    rge_read(handle, &master_id, 2);
                    rge_read(handle, &obj_state, 1);
                    rge_read(handle, &obj_angle, 4);
                    int mapped = *map;
                    if (mapped >= 0 && this->players[mapped] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = obj_id;
                        this->players[mapped]->make_scenario_obj(world_z, world_y, world_x, master_id, obj_state, obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    j++;
                } while (j < count);
            }
            outer++; map++;
        } while (outer < scenario_player_num);
    }

    this->next_object_id = next_object_id;
    rge_read(handle, rem, 13);
    j = 1;
    if (scenario_player_num > 1) {
        long* map = &player_id_hash[1];
        do {
            if (j < this->player_num && *map > -1 && this->players[*map] != 0) {
                this->players[*map]->scenario_load(handle, player_id_hash, 1.03f);
            } else {
                this->players[0]->scenario_load(handle, player_id_hash, 1.03f);
            }
            j++; map++;
        } while (j < scenario_player_num);
    }

    rge_close(handle);
    j = 1;
    if (this->player_num > 1) {
        do {
            if (j < scenario_player_num) {
                if (this->players[j] != 0 && player_id_hash[j] > -1) {
                    int s = j - 1;
                    this->players[player_id_hash[j]]->loadAIInformation(
                        this->scenario->Get_BuildList(s, 1),
                        this->scenario->Get_CityPlan(s, 1),
                        this->scenario->Get_player_AI(s, 1),
                        this->scenario->GetPlayerPosture(s), -1);
                }
            } else {
                return;
            }
            ++j;
        } while (j < this->player_num);
    }
}
