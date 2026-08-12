// VA: 00544B90 RGE_Game_World::load_scenario4
// Attempt log:
// initial rough reconstruction from packet: skip old header blob, load player mapping, remake visible maps, load per-player visibility/object data.
// modeled initial uncompressed count/blob skip with malloc failure closing file and returning.
// modeled player-id hash read, virtual pre-load calls, map array init to -1, player remap from player_info+0x270, and remake_visible_map pass.
// modeled per-player visibility load dispatch with fallback to player 0 and 1.04f argument.
// modeled nested object-count/object-record reads and guarded object load with temporary loading flag fields.
// modeled final close and post-remap player hook pass only roughly; UI/helper calls at tail remain speculative.
// baseline: rough source emitted 675 bytes vs original 721; structural call/slot gaps remained.
// probe 2 candidate: restored the World/Player ABI from the generated class donors, corrected scenario_init/scenario_make_map,
// scenario_load(+68), make_scenario_obj(+60), and loadAIInformation(+2c) surfaces, and modeled next_object_id/id ownership.
// probes 4-5: separate/scoped object-count locals perturbed the frame and prologue; restored the single natural count local.
// probe 8: a typed player-slot guard was emitted identically to the direct member form.
// probe 9: direct indexed receiver use improved the late register/liveness basin and shortened the candidate to 729 bytes.
// probe 11: a top-tested final while loop recovered the oracle's one bottom player-count backedge; current candidate is 723 bytes.
// current remaining drift: scenario-count/object-loop stack homes (+14 vs oracle +60), object-loop stack/index coloring, and a localized late schedule.
// probe 13: replaced the raw world counter address with its typed global declaration;
// the frame moved from 0x4c to 0x48 and the structural diff worsened, but the source
// now has no absolute-address macro. The typed serialization widths and virtual ABI
// remain unchanged.

extern int world_update_counter;

typedef unsigned char uchar;

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" void __cdecl rge_read_uncompressed(int, void*, int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
extern "C" int __cdecl rge_close(int);

struct RGE_Static_Object;
struct RGE_Player_Info { char gap_00[0x270]; long player_id[9]; };

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
    virtual void set_game_status(uchar);
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
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, uchar, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);

    void remake_visible_map();
};

class RGE_Game_World {
public:
    virtual uchar data_load_world(void*);
    virtual uchar data_load_terrain_tables(char*);
    virtual uchar data_load_players(char*);
    virtual uchar data_load_objects(char*);
    virtual uchar data_load_sounds(char*);
    virtual uchar data_load_color_tables(char*);
    virtual uchar data_load_sprites(char*);
    virtual void data_load_players_type(short, short, void*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short, void*, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual uchar init_player_type(int, short, uchar);
    virtual uchar init_player(int);
    virtual void load_player(int, uchar, short);
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
    virtual uchar new_random_game(RGE_Player_Info*);
    virtual void save(int);
    virtual void scenario_make_player(short, uchar, uchar, uchar, char*);
    virtual void scenario_make_map(int);
    virtual uchar load_scenario(RGE_Player_Info*);
    virtual uchar load_scenario(char*, RGE_Player_Info*);
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
    virtual uchar data_load(char*, char*);
    virtual uchar init(char*, void*, void*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual uchar update();
    virtual uchar get_game_state();
    virtual uchar check_game_state();
    virtual uchar load_world(int);
    virtual uchar load_game(char*);
    virtual uchar new_game(RGE_Player_Info*, int);
    virtual uchar new_scenario(RGE_Player_Info*, int);
    virtual uchar save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual uchar save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(uchar);
    virtual void scenario_init0(RGE_Game_World*);
    virtual void scenario_init(int, RGE_Game_World*);

    char gap_04[0x38];
    short player_num;
    char gap_3e[2];
    RGE_Player** players;
    char gap_44[0x18];
    RGE_Scenario* scenario;
    char gap_60[8];
    int next_object_id;
    char gap_6c[4];
    int scenario_object_id;
    uchar scenario_object_flag;

    void load_scenario4(int, RGE_Player_Info&);
};

void RGE_Game_World::load_scenario4(int file, RGE_Player_Info& info)
{
    int next_object_id;
    int count;
    int id;
    float obj_angle;
    uchar obj_state;
    short master_id;
    float world_z;
    float world_y;
    float world_x;
    long player_id_hash[9];
    int outer;
    int scenario_player_num;

    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) {
        void* p = malloc(count);
        if (p == 0) {
            rge_close(file);
            return;
        }
        rge_read_uncompressed(file, p, count);
        free(p);
    }

    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this);
    this->scenario_make_map(file);

    int n = this->player_num;
    if (n > 0) {
        do {
            for (int k = 0; k < 9; ++k) player_id_hash[k] = -1;
        } while (n > 10);
    }

    int i = 0;
    if (n > 0) {
        long* ids = info.player_id;
        do {
            player_id_hash[*ids++] = i;
            ++i;
        } while (i < n);
    }

    i = 0;
    if (n > 0) {
        do {
            this->players[i]->remake_visible_map();
            ++i;
        } while (i < this->player_num);
    }

    rge_read(file, &scenario_player_num, 4);
    i = 1;
    if (scenario_player_num > 1) {
        long* map = player_id_hash + 1;
        do {
            RGE_Player* player;
            if (i < this->player_num && *map > -1 &&
                (player = this->players[*map]) != 0) {
            } else {
                player = this->players[0];
            }
            player->scenario_load(file, player_id_hash, 1.04f);
            ++i;
            ++map;
        } while (i < scenario_player_num);
    }

    outer = 0;
    if (scenario_player_num > 0) {
        long* map = player_id_hash;
        do {
            rge_read(file, &count, 4);
            int j = 0;
            if (count > 0) {
                do {
                    rge_read(file, &world_x, 4);
                    rge_read(file, &world_y, 4);
                    rge_read(file, &world_z, 4);
                    rge_read(file, &id, 4);
                    rge_read(file, &master_id, 2);
                    rge_read(file, &obj_state, 1);
                    rge_read(file, &obj_angle, 4);
                    int player_id = *map;
                    if (player_id >= 0) {
                        RGE_Player** player_slot = this->players + player_id;
                        if (*player_slot != 0) {
                            this->scenario_object_flag = 1;
                            this->scenario_object_id = id;
                            (*player_slot)->make_scenario_obj(world_x, world_y, world_z, master_id, obj_state, obj_angle);
                            this->scenario_object_flag = 0;
                        }
                    }
                    ++j;
                } while (j < count);
            }
            ++outer;
            ++map;
        } while (outer < scenario_player_num);
    }

    this->next_object_id = next_object_id;
    rge_close(file);

    i = 1;
    while (i < this->player_num) {
        if (i >= scenario_player_num) return;
        if (this->players[i] != 0 && player_id_hash[i] > -1) {
            int player_index = i - 1;
            this->players[player_id_hash[i]]->loadAIInformation(
                this->scenario->Get_BuildList(player_index, 1),
                this->scenario->Get_CityPlan(player_index, 1),
                this->scenario->Get_player_AI(player_index, 1),
                this->scenario->GetPlayerPosture(player_index),
                -1);
        }
        ++i;
    }
}
