// VA: 00544300 RGE_Game_World::load_scenario1
// Source: World.cpp lines 2489-2604
// Attempt log:
// 1: broad reconstruction from packet: read rem/player data, rebuild player mapping, load object records, attach/initialize objects; compiles too small (624 vs 691) and class gap initially needed fixing.
// 2: tried /O1 /Oy flag probe; object shrank to 591 and failed configured size, flag removed.
// 3: reviewed packet line map: original has two nested object loops plus later player AI setup; current source only approximates both.
// 4: local player remap table behavior modeled loosely but original has repeated 9-dword fills and info+0x270 player order table.
// 5: object record read order modeled from asm locals, but exact object creation/vtable +60/+68 surfaces missing.
// 6: final AI setup calls through player manager (+5C) are approximated with get1 placeholders.
// 7: current source lacks exact stack/local layout at +14/+18/+1c... and many rge_read temporaries.
// 8: no custom flags retained; default still too small.
// 9: left in scratch pending real RGE_Game_World/RGE_Player/object load surfaces and exact local topology.
// 10: replaced decompiler-shaped helpers with the period World/Player/Scenario surfaces. The
//     binary reads x/y/z, object id, master id, state, and angle in the save_scenario order.
// 11: baseline has the right frame, size basin, and call count. The first structural lead is
//     the original direct +F4 scenario_init slot, uncached this->player_num loop bounds, and
//     the object guard's binary-proven players[i] test before the mapped-player call.
// 12: delayed player-count initialization after the header calls and moved one declaration-only
//     virtual slot before scenario_init; this aligned all 24 ordered calls and the +F4 slot.
// 13: a positive final `i < scenario_player_num` guard with an explicit return arm matched the
//     original late CFG and reduced the candidate to 697 bytes, six bytes over the target.
// 14: loading the remap index before the final guard caused extra scaled-address code; rolled back.
// 15: a remap-slot pointer emitted the same 697-byte code as the positive-guard candidate; rolled back.
// 16: initializing the scenario-load fallback player before its guard reached 691 bytes but changed
//     the load-loop CFG and moved the first mismatch earlier; rolled back to the 697-byte candidate.
// 17: duplicated the typed scenario_load call in mapped and fallback arms; VC5 merged the call and
//     matched the original fallback receiver block, reducing the best diff to 112 bytes.
// 18: mirrored same-TU loaders with a typed player-map pointer; emitted code was unchanged, so kept
//     the clearer period-plausible map ownership.
// Best retained reconstruction: 697 bytes, frame 0x60, all 24 calls and virtual slots aligned;
// remaining drift is late register coloring and one scaled-address expression in AI setup.

extern "C" void __cdecl rge_read(int file, void* data, int size);
extern "C" int __cdecl rge_close(int file);

class RGE_Game_World;
class RGE_Static_Object;

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
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, unsigned char, float);
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
    unsigned char gap_25B;
    short color[9];
    unsigned char gap_26E[2];
    long player_id_hash[9];
};

class RGE_Scenario {
public:
    int GetPlayerPosture(int);
    char* Get_player_AI(int, int);
    char* Get_CityPlan(int, int);
    char* Get_BuildList(int, int);
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
    virtual void load_scenario2(int, RGE_Player_Info*);
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
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0x18];
    RGE_Scenario* scenario;
    char gap_60[8];
    int next_object_id;
    int next_reusable_object_id;
    int scenario_object_id;
    unsigned char scenario_object_flag;

    void load_scenario1(int, RGE_Player_Info&);
};

void RGE_Game_World::load_scenario1(int file, RGE_Player_Info& info)
{
    long player_id_hash[9];
    int next_object_id;
    int scenario_player_num;
    int count;
    int object_id;
    float object_angle;
    unsigned char object_state;
    short master_id;
    float world_x;
    float world_y;
    float world_z;
    char rem[13];
    unsigned char player_id;
    unsigned char master_player_id;
    int i;
    int j;
    int player_num;

    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this);
    this->scenario_make_map(file);
    player_num = this->player_num;

    if (player_num > 0) {
        do {
            for (i = 0; i < 9; ++i) {
                player_id_hash[i] = -1;
            }
        } while (player_num > 10);
    }

    i = 0;
    if (i < player_num) {
        do {
            player_id_hash[info.player_id_hash[i]] = i;
            ++i;
        } while (i < player_num);
    }

    i = 0;
    if (i < this->player_num) {
        do {
            this->players[i]->remake_visible_map();
            ++i;
        } while (i < this->player_num);
    }

    rge_read(file, &scenario_player_num, 4);
    i = 0;
    if (i < scenario_player_num) {
        do {
            rge_read(file, &player_id, 1);
            rge_read(file, &master_player_id, 1);
            ++i;
        } while (i < scenario_player_num);
    }

    i = 0;
    if (i < scenario_player_num) {
        do {
            rge_read(file, &count, 4);
            j = 0;
            if (j < count) {
                do {
                    rge_read(file, &world_x, 4);
                    rge_read(file, &world_y, 4);
                    rge_read(file, &world_z, 4);
                    rge_read(file, &object_id, 4);
                    rge_read(file, &master_id, 2);
                    rge_read(file, &object_state, 1);
                    rge_read(file, &object_angle, 4);
                    if (i < this->player_num && player_id_hash[i] >= 0 &&
                        this->players[i] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = object_id;
                        this->players[player_id_hash[i]]->make_scenario_obj(
                            world_x, world_y, world_z, master_id, object_state, object_angle);
                        this->scenario_object_flag = 0;
                    }
                    ++j;
                } while (j < count);
            }
            ++i;
        } while (i < scenario_player_num);
    }

    this->next_object_id = next_object_id;
    rge_read(file, rem, 13);

    i = 1;
    if (i < scenario_player_num) {
        long* player_map = player_id_hash + 1;
        do {
            if (i < this->player_num && *player_map > -1 &&
                this->players[*player_map] != 0) {
                this->players[*player_map]->scenario_load(file, player_id_hash, 1.0f);
            } else {
                this->players[0]->scenario_load(file, player_id_hash, 1.0f);
            }
            ++i;
            ++player_map;
        } while (i < scenario_player_num);
    }

    rge_close(file);

    i = 1;
    if (this->player_num > 1) {
        do {
            if (i < scenario_player_num) {
                if (this->players[i] != 0) {
                    int player_index = i - 1;
                    this->players[player_id_hash[i]]->loadAIInformation(
                        this->scenario->Get_BuildList(player_index, 1),
                        this->scenario->Get_CityPlan(player_index, 1),
                        this->scenario->Get_player_AI(player_index, 1),
                        this->scenario->GetPlayerPosture(player_index), -1);
                }
            } else {
                return;
            }
            ++i;
        } while (i < this->player_num);
    }
}
