// 00544880 RGE_Game_World::load_scenario3
// Attempt log:
// 1: natural reconstruction from asm/decompiler with exact stack locals/order and raw virtual calls.
// 2: fixed compile type errors by using long* for player_id_hash walks and local load_factor for 1.04f.
// 3: raw cdecl virtual macros for RGE_Game_World load calls compiled but added explicit this pushes and stack cleanup.
// 4: replaced RGE_Game_World +0x70/+0xF4 raw macros with real virtual declarations/padding; recovered the thiscall virtual-call family and improved positional diff to 37.468%.
// 5: modeled player_num/player array/scenario/object flag/object id offsets from original asm (+0x3C/+0x40/+0x5C/+0x74/+0x70).
// 6: modeled player_id_hash[9] initialization; compiler emits rep stosd but stack frame still 0x5C vs original 0x64.
// 7: tried adding unused pad locals for the missing 8 bytes; VC5 optimized them away, no change.
// 8: modeled nested read loops and player create/load/setup virtual call slots +0x60/+0x68/+0x2C with raw helpers; behavior paths present but stack/call surface not exact.
// 9: no inline asm or custom flags tried.
// 10: left in scratch: frame/local placement and late player virtual call surfaces remain broad mismatch, not accepted_drift.
// 11: replaced cdecl vtable macros with the donor-backed Player virtual ABI;
//     slot +0x60 takes six typed object fields, +0x68 takes file/map/factor,
//     and +0x2c takes the five setup fields.  Scenario posture takes one arg.
// 12: corrected the fallback comparison to `*map <= -1`; this matched the
//     original jle form and restored all 25 direct-call relocation identities.
// 13: final validation retained the 0x64 stack frame and all 29 ordered calls.
// 14: matched the World.cpp resource donor's function-scope buffer; emitted code
//     was unchanged, so the simpler block-scoped allocation remains canonical.
// 15: removed the redundant scenario-player bound from the final cleanup loop;
//     VC5 emitted the same CFG because the early return already proves the bound.
// 16: grouped the next-object header and trailing read buffer in a typed record;
//     emitted code was unchanged, so separate named stream values remain cleaner.
// 17: read the first scenario-player byte through player_id_hash[8]; shape moved
//     only +0.34 points with no positional gain, so this was not retained.
// 18: used distinct typed player_id and master_player_id byte locals, as suggested
//     by the scenario header read pattern. Frame moved to 0x60, diff to 82, and
//     shape to 84.01%; this is the retained best source for this session.
// 19: tested `scenario_player_num <= i` for the final return guard, matching the
//     original compare operand order; it changed two bytes but gave no positional
//     gain and reduced shape, so the original `i >= scenario_player_num` spelling
//     remains retained.
// 20: separated the initial compressed-size count from the per-player object
//     record count.  This restored the original 0x64 frame and shifted the
//     object-record locals to their binary-proven +4 stack homes; diff fell to 47.
// 21: duplicated the direct scenario_load call in the mapped and fallback arms,
//     matching the exact load_scenario2 donor. This reduced the diff from 47 to 22
//     bytes and recovered the direct fallback receiver shape.
// 22: changed the final scenario-player test to a positive arm with an explicit
//     else return, again matching the exact donor. This removed the extra late
//     compare and produced a 782-byte exact MATCH.
// 23: replaced generic virtual padding with the complete donor-backed period
//     World and Player surfaces. The exact 782-byte result was unchanged, so the
//     real declarations are retained. The first four-byte value owns
//     next_object_id. Object records use x/y/z/id/master/state/angle.

typedef unsigned char uchar;
extern "C" void __cdecl rge_read_uncompressed(int file, void* dst, int size);
extern "C" void __cdecl rge_read(int file, void* dst, int size);
extern "C" int __cdecl rge_close(int file);
extern "C" void* __cdecl malloc(unsigned int size);
extern "C" void __cdecl free(void* ptr);
extern "C" int world_update_counter;

struct RGE_Static_Object;

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
class RGE_Scenario {
public:
    int GetPlayerPosture(int p);
    char* Get_player_AI(int p, int one);
    char* Get_CityPlan(int p, int one);
    char* Get_BuildList(int p, int one);
};
class RGE_Player_Info {
public:
    char name[9][65];
    char type[9];
    char tribe[9];
    uchar gap_25b;
    short color[9];
    uchar gap_26e[2];
    long player_id[9];
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
    char gap_6c[4];
    int scenario_object_id;
    uchar scenario_object_flag;
    void load_scenario3(int file, RGE_Player_Info& info);
};

void RGE_Game_World::load_scenario3(int file, RGE_Player_Info& info)
{
    uchar player_id;
    uchar master_player_id;
    long scenario_player_num;
    long next_object_id;
    long count;
    long object_count;
    long id;
    float obj_angle;
    uchar obj_state;
    short master_id;
    float world_z;
    float world_y;
    float world_x;
    char rem[13];
    long player_id_hash[9];
    int outer;

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
            for (int k = 0; k < 9; k++) player_id_hash[k] = -1;
        } while (n > 10);
    }
    int i = 0;
    if (n > 0) {
        long* ids = info.player_id;
        do {
            player_id_hash[*ids++] = i;
            i++;
        } while (i < n);
    }
    i = 0;
    if (n > 0) {
        do {
            this->players[i]->remake_visible_map();
            i++;
        } while (i < this->player_num);
    }
    rge_read(file, &scenario_player_num, 4);
    i = 0;
    if (scenario_player_num > 0) {
        do {
            rge_read(file, &player_id, 1);
            rge_read(file, &master_player_id, 1);
            i++;
        } while (i < scenario_player_num);
    }
    outer = 0;
    if (scenario_player_num > 0) {
        long* map = player_id_hash;
        do {
            rge_read(file, &object_count, 4);
            int j = 0;
            if (object_count > 0) {
                do {
                    rge_read(file, &world_z, 4);
                    rge_read(file, &world_y, 4);
                    rge_read(file, &world_x, 4);
                    rge_read(file, &id, 4);
                    rge_read(file, &master_id, 2);
                    rge_read(file, &obj_state, 1);
                    rge_read(file, &obj_angle, 4);
                    int pid = *map;
                    if (pid >= 0 && this->players[pid] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = id;
                        this->players[pid]->make_scenario_obj(
                            world_z, world_y, world_x, master_id, obj_state,
                            obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    j++;
                } while (j < object_count);
            }
            outer++;
            map++;
        } while (outer < scenario_player_num);
    }
    this->next_object_id = next_object_id;
    rge_read(file, rem, 13);
    i = 1;
    if (scenario_player_num > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i >= this->player_num || *map <= -1 || this->players[*map] == 0) {
                this->players[0]->scenario_load(file, player_id_hash, 1.04f);
            } else {
                this->players[*map]->scenario_load(file, player_id_hash, 1.04f);
            }
            i++;
            map++;
        } while (i < scenario_player_num);
    }
    rge_close(file);
    i = 1;
    if (this->player_num > 1) {
        do {
            if (i < scenario_player_num) {
                if (this->players[i] != 0 && player_id_hash[i] > -1) {
                    int idx = i - 1;
                    this->players[player_id_hash[i]]->loadAIInformation(this->scenario->Get_BuildList(idx,1), this->scenario->Get_CityPlan(idx,1), this->scenario->Get_player_AI(idx,1), this->scenario->GetPlayerPosture(idx), -1);
                }
            } else {
                return;
            }
            i++;
        } while (i < this->player_num);
    }
}
