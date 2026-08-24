// 00545800 RGE_Game_World::load_scenario8
// Attempt log:
// 1: seeded from load_scenario2 reconstruction, adding v8 uncompressed header block and second pass load_scenario_info2 call.
// 2: ABI probe: Player has one unnamed virtual slot between the two scenario-info loaders; this gives the observed +0x68/+0x70 calls.
// 3: direct fields and serialization widths follow the sibling load_scenario5-7 family. Remaining drift is local frame/liveness shape.
// 4: restored the clean typed World/Player surface after raw cursor experiments; object records use 4,4,4,4,2,1,4 byte widths.
// 5: unresolved exactness is structural local coloring and source-line block layout; no call or cleanup mismatch remains.
// Source audit: named fields preserve the proven World offsets. The float angle and 32-bit object ids follow the scenario format.
// Main-agent audit removed stale raw-offset macros, stack-adjacent aliases, and
// the float-to-ID type pun. The separately read header owns next_object_id.
// 6: A scoped object-count local worsened the frame-independent structural diff; rolled back.
// 7: A separate object-count local with the prior index reused for the outer player loop improved shape to 83.07%.
// 8: Reusing the dead compressed-count local for the delayed next-object-id header kept the 0x4c frame and improved shape to 85.94%.
// 9: A typed player pointer local for the object guard restored the original saved-register prologue and reached the best natural diff (564 bytes); assignment-in-condition was worse and was rolled back.
// Left in scratch: ordered calls and frame match, but structural drift remains in the header-count home, mapped-player guard, and final setup block.
// 10: Separating the pre-scenario header dword into a named next-object-id local
// added stack pressure and worsened the frame; restored the clean reused-home
// candidate. The packet still proves a distinct semantic value, but this source
// shape is not codegen-compatible without a better lifetime model.
// 11: A named pointer-to-player-slot object guard improved resynchronization but
// added one byte and worsened positional diff; restored direct typed player use.
// 12: Binary-proven <= -1 guards in both info passes reduced positional diff to
// 382 bytes, but the cleaner direct object guard combination regressed to 716;
// restored the best natural clean candidate. No call or cleanup mismatch exists.
// 13: Removing the cleanup receiver local changed the call target surface and
// enlarged the footer; rolled back. The remaining blocker is structural local
// coloring and stack-home reuse, not behavior or ABI.
// 14: Adapted the exact load_scenario4 control-flow shape with a separate
// next-object value, scenario-player count, duplicated mapped/fallback calls,
// and direct object guards. This recovered the target body topology.
// 15: Restored the period one/two-argument Scenario helper ABI. Nested natural
// setup_ai argument evaluation recovered the original stack argument retention,
// frame, size, and all 812 bytes.
// 16: Replaced generic World and Player virtual placeholders with complete
// donor-backed period surfaces. The exact result and all 28 call identities
// remained unchanged.
// 17: Natural new[]/delete[] ownership preserves every instruction byte but
// changes the two direct symbols from proven malloc/free to operator new/delete.
// The current clean source keeps natural ownership per task policy; this is a
// documented four-byte control-target mismatch, not an exact promotion.
// Exact 812-byte evidence is retained in checker checkpoint probe-006-abi.

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" void __cdecl rge_read_uncompressed(int, void*, int);
extern "C" int __cdecl rge_close(int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);

extern long world_update_counter;

class RGE_Scenario { public: int GetPlayerPosture(int); char* Get_player_AI(int,int); char* Get_CityPlan(int,int); char* Get_BuildList(int,int); };
struct RGE_Static_Object;
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
    virtual void load_scenario2(int, RGE_Player_Info*);
    virtual void load_scenario3(int, RGE_Player_Info*);
    virtual void load_scenario4(int, RGE_Player_Info*);
    virtual void load_scenario5(int, RGE_Player_Info*);
    virtual void load_scenario6(int, RGE_Player_Info*);
    virtual void load_scenario7(int, RGE_Player_Info*);
    virtual void load_scenario8(int handle, RGE_Player_Info& info);
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
    char gap_6c[4];
    int scenario_object_id;
    unsigned char scenario_object_flag;
};

void RGE_Game_World::load_scenario8(int handle, RGE_Player_Info& info)
{
    long count;
    long next_object_id;
    long object_count;
    long obj_id;
    float obj_angle;
    unsigned char obj_state;
    short master_id;
    float world_z;
    float world_y;
    float world_x;
    long player_id_hash[9];
    long outer;
    long scenario_player_num;

    world_update_counter = 0;
    rge_read_uncompressed(handle, &count, 4);
    if (count > 0) {
        char* buf = (char*)malloc(count);
        if (buf == 0) { rge_close(handle); return; }
        rge_read_uncompressed(handle, buf, count);
        free(buf);
    }
    rge_read(handle, &next_object_id, 4);
    this->scenario_init(handle, this);
    this->scenario_make_map(handle);
    int n = this->player_num;
    if (n > 0) { do { for (int k = 0; k < 9; ++k) player_id_hash[k] = -1; } while (n > 10); }
    int i = 0;
    if (n > 0) { long* ids = info.player_id_hash; do { player_id_hash[*ids++] = i; ++i; } while (i < n); }
    i = 0;
    if (n > 0) { do { this->players[i]->remake_visible_map(); ++i; } while (i < this->player_num); }
    rge_read(handle, &scenario_player_num, 4);
    i = 1;
    if (scenario_player_num > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i < this->player_num && *map > -1 && this->players[*map] != 0) {
                this->players[*map]->scenario_load(handle, player_id_hash, 1.11f);
            } else {
                this->players[0]->scenario_load(handle, player_id_hash, 1.11f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_num);
    }
    outer = 0;
    if (scenario_player_num > 0) {
        long* map = player_id_hash;
        do {
            rge_read(handle, &object_count, 4);
            int j = 0;
            if (object_count > 0) {
                do {
                    rge_read(handle, &world_z, 4);
                    rge_read(handle, &world_y, 4);
                    rge_read(handle, &world_x, 4);
                    rge_read(handle, &obj_id, 4);
                    rge_read(handle, &master_id, 2);
                    rge_read(handle, &obj_state, 1);
                    rge_read(handle, &obj_angle, 4);
                    if (*map >= 0 && this->players[*map] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = obj_id;
                        this->players[*map]->make_scenario_obj(
                            world_z, world_y, world_x, master_id, obj_state, obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    ++j;
                } while (j < object_count);
            }
            ++outer;
            ++map;
        } while (outer < scenario_player_num);
    }
    this->next_object_id = next_object_id;
    rge_read(handle, &scenario_player_num, 4);
    i = 1;
    if (scenario_player_num > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i < this->player_num && *map > -1 && this->players[*map] != 0) {
                this->players[*map]->scenario_postload(handle, player_id_hash, 1.11f);
            } else {
                this->players[0]->scenario_postload(handle, player_id_hash, 1.11f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_num);
    }
    rge_close(handle);
    i = 1;
    if (this->player_num > 1) {
        do {
            if (i < scenario_player_num) {
                if (this->players[i] != 0 && player_id_hash[i] > -1) {
                    int s = i - 1;
                    this->players[player_id_hash[i]]->loadAIInformation(
                        this->scenario->Get_BuildList(s, 1),
                        this->scenario->Get_CityPlan(s, 1),
                        this->scenario->Get_player_AI(s, 1),
                        this->scenario->GetPlayerPosture(s), -1);
                }
            } else {
                return;
            }
            ++i;
        } while (i < this->player_num);
    }
}
