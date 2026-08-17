// 005454D0 RGE_Game_World::load_scenario7
// Attempt log:
// - Baseline used the ground-truth World, Player, Scenario, and Player_Info
//   surfaces with the scenario 1.08 call order.
// - The first header dword is next_object_id.  The nine-entry player hash
//   starts after that scalar.  The scenario-player count reuses hash[8].
// - Separate outer and inner object counts, saved player slots, and the
//   natural hash-plus-one iterators recovered the ordered 28-call set.
// - The final object record uses named x/y/z/id/master/state/angle fields.
//   Its widths are 4,4,4,4,2,1,4 bytes, as observed in the executable.
// - Final probe: frame and saved-register parity, 816 vs 812 bytes, 535
//   positional diff, 294 edit diff, and 88.41% shape similarity.  The first
//   remaining mismatch is the scenario-player-count stack home at 3269.
// - Main-agent source audit replaced the raw 0x886C10 macro with the established
//   world_update_counter symbol. The natural source now has a 0x48 frame.
// - Fresh baseline confirmed the typed global and natural compressed-header
//   guard, but emitted a 0x48 frame and 547-byte positional diff.
// - Function-scope buffer and int/char stream types, plus a volatile counter,
//   were codegen duplicates and were not retained as matching leads.
// - A named serialized scenario-player count restored the 0x4c frame and
//   improved the positional diff to 533 bytes; <= -1 remap guards improved it
//   to 297 bytes with the original legacy compare shape.
// - Same-TU save/read x/y/z order improved the best source to 295 bytes and
//   93.05% shape. Direct object-guard and players-array variants were tested,
//   then rolled back because they increased size or positional drift.
// - H1 duplicated the mapped and fallback scenario_load/postload calls, as in
//   exact same-TU loaders. This reduced the positional diff from 164 to 109.
// - H2 used direct indexed players[player_id] ownership for object creation.
//   This reduced the diff to 94 and recovered the object-record block.
// - H3 used the donor-backed final while loop. This reduced the size gap from
//   8 bytes to 2 and reduced the diff to 86.
// - H4 corrected GetPlayerPosture to its one-argument period ABI. The outer
//   loadAIInformation call supplies the separate -1 argument and produced an
//   exact 812-byte MATCH.
// - H5 tested natural new uchar[]/delete[]. VC5 emitted operator new/delete,
//   not the binary-proven malloc/free calls. Restored the exact C buffer form.
// - Final validation: 812/812 bytes, 0.0000%, 28 ordered calls, 23/23 safe
//   relocation matches, matching owner symbol, frame, and saved registers.
// Baseline: typed reconstruction of the scenario 1.08 loader. The scenario
// record widths follow the executable, including its narrow legacy fields.

extern "C" int world_update_counter;

typedef unsigned char uchar;

extern "C" void __cdecl rge_read_uncompressed(int, void*, int);
extern "C" void __cdecl rge_read(int, void*, int);
extern "C" int __cdecl rge_close(int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);

struct RGE_Player_Info {
    char gap_00[0x270];
    long player_id[9];
};

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
    virtual void sendGameOrder(void*, void*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual void make_scenario_obj(float, float, float, short, uchar, float);
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

    void load_scenario7(int, RGE_Player_Info&);
};

void RGE_Game_World::load_scenario7(int file, RGE_Player_Info& info)
{
    long count;
    long id;
    float obj_angle;
    uchar obj_state;
    short master_id;
    float world_x;
    float world_y;
    float world_z;
    long obj_id;
    long player_id_hash[9];
    int outer;
    int i;
    long next_object_id;
    int j;
    long scenario_player_count;
    void* buffer;

    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) {
        buffer = malloc(count);
        if (buffer == 0) {
            rge_close(file);
            return;
        }
        rge_read_uncompressed(file, buffer, count);
        free(buffer);
    }

    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this);
    this->scenario_make_map(file);

    int n = this->player_num;
    if (n > 0) {
        do {
            for (i = 0; i < 9; ++i) player_id_hash[i] = -1;
        } while (n > 10);
    }

    i = 0;
    if (n > 0) {
        long* ids = info.player_id;
        do {
            player_id_hash[*ids++] = i++;
        } while (i < n);
    }

    i = 0;
    if (n > 0) {
        do {
            this->players[i]->remake_visible_map();
            ++i;
        } while (i < this->player_num);
    }

    rge_read(file, &scenario_player_count, 4);
    i = 1;
    if (scenario_player_count > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i >= this->player_num || *map <= -1 ||
                this->players[*map] == 0) {
                this->players[0]->scenario_load(file, player_id_hash, 1.08f);
            } else {
                this->players[*map]->scenario_load(file, player_id_hash, 1.08f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_count);
    }

    outer = 0;
    if (scenario_player_count > 0) {
        long* map = player_id_hash;
        do {
            rge_read(file, &obj_id, 4);
            j = 0;
            if (obj_id > 0) {
                do {
                    rge_read(file, &world_x, 4);
                    rge_read(file, &world_y, 4);
                    rge_read(file, &world_z, 4);
                    rge_read(file, &id, 4);
                    rge_read(file, &master_id, 2);
                    rge_read(file, &obj_state, 1);
                    rge_read(file, &obj_angle, 4);
                    int player_id = *map;
                    if (player_id >= 0 && this->players[player_id] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = id;
                        this->players[player_id]->make_scenario_obj(
                            world_x, world_y, world_z, master_id, obj_state, obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    ++j;
                } while (j < obj_id);
            }
            ++outer;
            ++map;
        } while (outer < scenario_player_count);
    }

    this->next_object_id = next_object_id;
    rge_read(file, &scenario_player_count, 4);
    i = 1;
    if (scenario_player_count > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i >= this->player_num || *map <= -1 ||
                this->players[*map] == 0) {
                this->players[0]->scenario_postload(file, player_id_hash, 1.08f);
            } else {
                this->players[*map]->scenario_postload(file, player_id_hash, 1.08f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_count);
    }

    rge_close(file);
    i = 1;
    while (i < this->player_num) {
        if (i >= scenario_player_count) return;
        if (this->players[i] != 0 && player_id_hash[i] > -1) {
            int player_index = i - 1;
            this->players[player_id_hash[i]]->loadAIInformation(
                this->scenario->Get_BuildList(player_index, 1),
                this->scenario->Get_CityPlan(player_index, 1),
                this->scenario->Get_player_AI(player_index, 1),
                this->scenario->GetPlayerPosture(player_index), -1);
        }
        ++i;
    }
}
