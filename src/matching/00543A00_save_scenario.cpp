// 00543A00 RGE_Game_World::save_scenario
// Attempt log:
// try 1: packet-grounded reconstruction of scenario save: derive .scn path, open, write version/header/player/world data, serialize per-player object lists excluding type 0x19, close, unlink on error. Helper-factored object serialization compiled too short (832B vs 1017B).
// try 2: expanded object serialization separately for both object lists to better match original repeated write blocks. Current source compiles too short (976B vs 1017B).
// try 3: temporary diagnostic extra writes reached byte compare, then removed. Diagnostic compare broad mismatch (81.1209% positional / 79.6460% edit); first mismatch at prologue/register allocation, rebuilt saves EBX and misses original EBP=this early pattern.
// try 4: modeled filename base copy up to '.', kill .scn via unlink, final open path via sprintf with base_game path +0xc17.
// try 5: modeled version write as TRIAL? 1.10 : 1.11 and base_game scenario header write.
// try 6: modeled scenario_data +0x68 write, info save at +0x5c, map save at +0x28, player count write.
// try 7: modeled pre-save loop over players 1..num_players-1 via virtual +0x64 and post-save loop via virtual +0x6c.
// try 8: modeled per-player count across two object lists +0x28/+0x2c excluding type 0x19, then write count.
// try 9: modeled repeated object serialization fields +0x38/+0x3c/+0x40/+0x04, type id +0x10, byte +0x48, and angle/sprite-direction fallback.
// probes 10-15: restored the real World/Scenario/Map/Player virtual surfaces and
//   object-node -> static-object -> master ownership; removed the per-player alias,
//   used the original do-copy filename loop and positive fd-success guard.
// probe 16: binary evidence showed the fourth serialized dword is the static
//   object's id (+0x04), not the object-node next pointer. This completed the
//   exact source shape while retaining ordinary typed C++ and no inline asm.
// Source audit: replaced the generated virtual-slot placeholders with the
// donor-backed World/Player/Map method names and restored the real base-game
// destructor surface; all serialized ownership remains typed and named.
// Result: MATCH (1017/1017 bytes, 0.0000%), default flags.

typedef unsigned char byte;
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl unlink(const char*);
extern "C" int __cdecl rge_open(const char*, int, int);
extern "C" void __cdecl rge_write_uncompressed(int, const void*, int);
extern "C" void __cdecl rge_write(int, const void*, int);
extern "C" void __cdecl rge_close(int);
extern int rge_write_error;
class TCommunications_Handler;
class RGE_Game_World;
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[8];
    char* path;
    byte check_prog_argument(char*);
    void write_scenario_header(int);
};
extern RGE_Base_Game* rge_base_game;
class RGE_Master_Static_Object {
public:
    char gap00[4];
    byte master_type;
    char gap05[0x0b];
    short id;
};
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    char gap0c[0x29];
    byte facet;
    char gap36[2];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    byte object_state;
    char gap49[0x53];
    float angle;
};
struct RGE_Object_Node { RGE_Static_Object* object; RGE_Object_Node* next; };
struct RGE_Object_List { char gap[4]; RGE_Object_Node* list; };
class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(byte);
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
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, byte, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    char gap04[0x24];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
};
class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int);
    virtual void load_random_map(char*, char*, char*, char*);
    virtual byte do_terrain_brush(long, long, long, byte);
    virtual byte do_terrain_brush_stroke(long, long, long, long, long, byte);
    virtual byte do_elevation_brush(long, long, long, byte);
    virtual byte do_elevation_brush_stroke(long, long, long, long, long, byte);
    virtual byte do_cliff_brush(long, long, byte, byte);
    virtual byte do_cliff_brush_stroke(long, long, long, long, byte, byte);
    virtual void map_generate(void*, RGE_Game_World*, void*, byte*);
    virtual void map_generate2(RGE_Game_World*, long, long, byte, long);
    virtual void save(int);
    void scenario_save(int);
};
class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int);
};
class RGE_Game_World {
public:
    virtual byte data_load_world(void*);
    virtual byte data_load_terrain_tables(char*);
    virtual byte data_load_players(char*);
    virtual byte data_load_objects(char*);
    virtual byte data_load_sounds(char*);
    virtual byte data_load_color_tables(char*);
    virtual byte data_load_sprites(char*);
    virtual void data_load_players_type(short, short, void*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short, void*, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual byte init_player_type(int, short, byte);
    virtual byte init_player(int);
    virtual void load_player(int, byte, short);
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
    virtual byte new_random_game(void*);
    virtual void save(int);
    virtual void scenario_make_player(short, byte, byte, byte, char*);
    virtual void scenario_make_map(int);
    virtual byte load_scenario(void*);
    virtual byte load_scenario(char*, void*);
    virtual void load_scenario1(int, void*);
    virtual void load_scenario2(int, void*);
    virtual void load_scenario3(int, void*);
    virtual void load_scenario4(int, void*);
    virtual void load_scenario5(int, void*);
    virtual void load_scenario6(int, void*);
    virtual void load_scenario7(int, void*);
    virtual void load_scenario8(int, void*);
    virtual void logStatus(void*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(void*);
    virtual byte data_load(char*, char*);
    virtual byte init(char*, void*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual byte update();
    virtual byte get_game_state();
    virtual byte check_game_state();
    virtual byte load_world(int);
    virtual byte load_game(char*);
    virtual byte new_game(void*, int);
    virtual byte new_scenario(void*, int);
    virtual byte save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual byte save_scenario(char* name);
    char gap04[0x24];
    RGE_Map* map;
    char gap2c[0x10];
    short player_num;
    RGE_Player** players;
    char gap44[0x18];
    RGE_Scenario* scenario;
    char gap60[8];
    int next_object_id;
};

byte RGE_Game_World::save_scenario(char* name)
{
    char scenario_name[300]; char kill_name[300];
    int scenario_player_num = (short)this->player_num;
    int i; float obj_angle; int count;
    char* p = name; int n = 0;
    do { kill_name[n++] = *p++; } while (*p != '.');
    kill_name[n] = 0;
    sprintf(scenario_name, "%s%s.scn", rge_base_game->path + 0xc17, kill_name);
    unlink(scenario_name);
    sprintf(scenario_name, "%s%s", rge_base_game->path + 0xc17, name);
    int fd = rge_open(scenario_name, 0x8301, 0x180);
    if (fd != -1) {
        rge_write_error = 0;
        if (rge_base_game->check_prog_argument("TRIAL") == 1) rge_write_uncompressed(fd, "1.10", 4);
        else rge_write_uncompressed(fd, "1.11", 4);
        rge_base_game->write_scenario_header(fd);
        rge_write(fd, &this->next_object_id, 4);
        this->scenario->save(fd);
        this->map->scenario_save(fd);
        rge_write(fd, &scenario_player_num, 4);
        for (i = 1; i < (short)this->player_num; ++i) this->players[i]->scenario_save(fd);
        for (i = 0; i < (short)this->player_num; ++i) {
            count = 0;
            RGE_Object_Node* o = this->players[i]->objects->list;
            while (o) { if (o->object->master_obj->master_type != 0x19) ++count; o = o->next; }
            o = this->players[i]->sleeping_objects->list;
            while (o) { if (o->object->master_obj->master_type != 0x19) ++count; o = o->next; }
            rge_write(fd, &count, 4);
            o = this->players[i]->objects->list;
            while (o) {
                if (o->object->master_obj->master_type != 0x19) {
                    rge_write(fd, &o->object->world_x, 4); rge_write(fd, &o->object->world_y, 4); rge_write(fd, &o->object->world_z, 4); rge_write(fd, &o->object->id, 4); rge_write(fd, &o->object->master_obj->id, 2); rge_write(fd, &o->object->object_state, 1);
                    if (o->object->master_obj->master_type > 0x1e && o->object->master_obj->master_type < 0x5a) obj_angle = o->object->angle; else obj_angle = (float)o->object->facet;
                    rge_write(fd, &obj_angle, 4);
                }
                o = o->next;
            }
            o = this->players[i]->sleeping_objects->list;
            while (o) {
                if (o->object->master_obj->master_type != 0x19) {
                    rge_write(fd, &o->object->world_x, 4); rge_write(fd, &o->object->world_y, 4); rge_write(fd, &o->object->world_z, 4); rge_write(fd, &o->object->id, 4); rge_write(fd, &o->object->master_obj->id, 2); rge_write(fd, &o->object->object_state, 1);
                    if (o->object->master_obj->master_type > 0x1e && o->object->master_obj->master_type < 0x5a) obj_angle = o->object->angle; else obj_angle = (float)o->object->facet;
                    rge_write(fd, &obj_angle, 4);
                }
                o = o->next;
            }
        }
        rge_write(fd, &scenario_player_num, 4);
        for (i = 1; i < (short)this->player_num; ++i) this->players[i]->scenario_postsave(fd);
        rge_close(fd);
        if (rge_write_error) { unlink(scenario_name); return 0; }
        return 1;
    }
    return 0;
}
