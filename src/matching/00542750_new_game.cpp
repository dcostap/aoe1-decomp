// 00542750 new_game attempt
// Attempt log:
// - Baseline had the right frame and call count but used virtual diplomacy
//   methods, wrong Player_Info offsets, and the wrong Player vtable slots.
// - Restored direct set_relation/set_allied_victory calls, Player_Info
//   scenario/victory/map/campaign ownership, and the distinct +0x84/+0xfc
//   World fields. This brought the candidate to exact size and ordered calls.
// - Deferred the initial seed member store until after seed selection, swapped
//   new_map to width/height order, and passed the scenario string to the
//   two-argument load_scenario slot; these reconstructed the early blocks.
// - The executable passes the same language buffer for all three
//   loadAIInformation arguments. A local base-game pointer reproduces the
//   final get_string register schedule without changing behavior.
// - Final source normalization uses donor-backed World/Player method names
//   and declaration-only virtual padding; current default flags produce an
//   exact 1184-byte match.
// Source audit: the initial virtual call is the binary-proven
// RGE_Game_World::del_game_info slot (+0xB8); all World/Player/Base_Game
// slots are named from the ABI surface.  The typed image-address macros are
// retained only for proven singleton globals whose unresolved extern forms
// change VC5 address-load/relocation codegen; no manual vtable or inline asm
// steering is used.
extern int debug_rand(const char*, int);
extern void debug_srand(const char*, int, int);
extern void debug_random_reset();
extern void* calloc(unsigned int, unsigned int);
extern int sprintf(char*, const char*, ...);
class RGE_Base_Game;
class TDebuggingLog;
#define L (*(void**)0x62C4FC)
#define rge_base_game (*(RGE_Base_Game**)0x62C574)
#define world_update_counter (*(int*)0x886C10)
#define computerPlayerSetup ((int*)0x886C18)
#define debug_timeGetTime_cnt (*(int*)0x62C4EC)
#define debug_timeGetTime_time (*(int*)0x62C4F0)
#define all_cp (*(int*)0x62C51C)

class PathingSystem { public: void zeroObstructionMap(); };
#define pathSystem (*(PathingSystem*)0x74D440)
#define aiPathSystem (*(PathingSystem*)0x62F348)

class TDebuggingLog { public: void Log(const char*, ...); };
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
    int multiplayerGame(); int randomGame(); int campaignGame(); int singlePlayerGame(); float get_game_speed(); int playerTeam(int); int playerID(int);
};
class TCommunications_Handler { public: int GetRandomSeed(); int GetPlayerHumanity(int); };
class RGE_Command { public: char p0[0x14]; TCommunications_Handler* com_hand; };
class RGE_Map { public: void new_map(long,long); };
class RGE_Static_Object;
struct XYZBYTEPoint;
class RGE_Player_Info;
class RGE_Player { public:
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
 virtual void loadAIInformation(char*,char*,char*,int,int); // slot 11 (+0x2c)
 virtual void sendUnitAIOrder(int,int,int,int,int,float,float,float,float,int,int,int);
 virtual void processAIOrder(int,int,int,int,int,float,float,float,float,int,int,int);
 virtual void kickAI(int);
 virtual int strategicNumber(int);
 virtual void sendGameOrder(RGE_Static_Object*,RGE_Static_Object*,float,float);
 virtual void sendAddWaypointCommand(int,XYZBYTEPoint*,int);
 virtual void processAddWaypointCommand(int,XYZBYTEPoint*,int);
 virtual void sendPlayCommand(int,int*,int,int,int);
 virtual void sendPlayCommand(int,int,int);
 virtual int sendAICommand(int,int,int,int,int);
 virtual int objectCostByType(int);
 virtual void trackUnitGather(int,int,int);
 virtual RGE_Static_Object* make_scenario_obj(float,float,float,short,unsigned char,float);
 virtual void scenario_save(int);
 virtual void scenario_load(int,long*,float);
 virtual void scenario_postsave(int);
 virtual void scenario_postload(int,long*,float);
 virtual void load(int);
 virtual void add_attribute_num(short,float,unsigned char);
 virtual void update();
 virtual void update_dopplegangers();
 virtual void save(int);
 virtual void save2(int);
 virtual void save_info(int);
 virtual void random_start(); // slot 36 (+0x90)
 void set_relation(long, unsigned char);
 void set_allied_victory(unsigned char);
};
class RGE_Player_Info { public:
 char p0[0x294];
 short player_num_minus1;
 char gap296[2];
 char* scenario;
 void* map_info;
 short victory;
 short map_width;
 short map_height;
 char gap2a6[2];
 unsigned char campaign;
};

class RGE_Scenario;
class RGE_Sound;
class RGE_Game_World { public:
 virtual unsigned char data_load_world(void*);
 virtual unsigned char data_load_terrain_tables(char*);
 virtual unsigned char data_load_players(char*);
 virtual unsigned char data_load_objects(char*);
 virtual unsigned char data_load_sounds(char*);
 virtual unsigned char data_load_color_tables(char*);
 virtual unsigned char data_load_sprites(char*);
 virtual void data_load_players_type(short,short,void*);
 virtual void data_load_effects(char*);
 virtual void data_load_map(char*,char*,char*,char*,short,short,short,RGE_Sound**,char*);
 virtual void data_load_random_map(char*,char*,char*,char*);
 virtual unsigned char init_player_type(int,short,unsigned char);
 virtual unsigned char init_player(int);
 virtual void load_player(int,unsigned char,short);
 virtual void color_table_init(int);
 virtual void terrain_tables_init(int);
 virtual void init_sounds(int,void*);
 virtual void init_sprites(int);
 virtual void map_init(int,void*);
 virtual void effects_init(int);
 virtual void master_player_init(int);
 virtual void command_init(int,TCommunications_Handler*);
 virtual void world_init(int,void*,TCommunications_Handler*);
 virtual void setup_gaia();                    // slot 23 +0x5c
 virtual void setup_players(RGE_Player_Info*); // slot 24 +0x60
 virtual unsigned char new_random_game(RGE_Player_Info*); // slot 25 +0x64
 virtual void save(int);
 virtual void scenario_make_player(short,unsigned char,unsigned char,unsigned char,char*);
 virtual void scenario_make_map(int);
 virtual unsigned char load_scenario(char*, RGE_Player_Info*); // slot 30 +0x78
 virtual unsigned char load_scenario(RGE_Player_Info*); // slot 29 +0x74
 virtual void load_scenario1(int,RGE_Player_Info*);
 virtual void load_scenario2(int,RGE_Player_Info*);
 virtual void load_scenario3(int,RGE_Player_Info*);
 virtual void load_scenario4(int,RGE_Player_Info*);
 virtual void load_scenario5(int,RGE_Player_Info*);
 virtual void load_scenario6(int,RGE_Player_Info*);
 virtual void load_scenario7(int,RGE_Player_Info*);
 virtual void load_scenario8(int,RGE_Player_Info*);
 virtual void logStatus(void*,int);
 virtual ~RGE_Game_World();
 virtual void setup_player_colors();
 virtual void setup_player_colors(RGE_Player_Info*);
 virtual unsigned char data_load(char*,char*);
 virtual unsigned char init(char*,void*,TCommunications_Handler*);
 virtual void turn_sound_off(); // slot 46 +0xb8
 virtual void del_game_info();
 virtual unsigned char update();
 virtual unsigned char get_game_state();
 virtual unsigned char check_game_state();
 virtual unsigned char load_world(int);
 virtual unsigned char load_game(char*);
 virtual unsigned char new_game(RGE_Player_Info*,int);
 virtual unsigned char new_scenario(RGE_Player_Info*,int);
 virtual unsigned char save_game(char*);
 virtual void base_save(char*);
 virtual void base_save(int);
 int world_time; int old_world_time; int world_time_delta; char gap10[4]; int old_time; float game_speed; unsigned char temp_pause; unsigned char game_state; char gap1e[10];
 RGE_Map* map; char g2c[0x10]; short player_num; char g3e[2]; RGE_Player** players; char g44[0x14]; RGE_Command* commands; char g5c[0x1c]; int random_seed; short curr_player; char gap80[6]; float world_time_delta_seconds; char gap88[0x74]; int currentUpdateComputerPlayer; char rest[0x10];
 unsigned char new_game(RGE_Player_Info& info, int mode); int initializePathingSystem();
};

unsigned char RGE_Game_World::new_game(RGE_Player_Info& info, int mode) {
    char randomString[256];
    int mapTeam;
    volatile unsigned char retval;
    int i,j, id1, id2;
    world_update_counter = 0;
    pathSystem.zeroObstructionMap();
    aiPathSystem.zeroObstructionMap();
    for (i=0;i<13;i++) computerPlayerSetup[i]=0;
    this->currentUpdateComputerPlayer = -1;
    this->del_game_info();
    debug_random_reset();
    debug_timeGetTime_cnt = 0; debug_timeGetTime_time = 0; this->game_state = 3; this->curr_player = mode;
    int initial_seed;
    if (rge_base_game->multiplayerGame()) initial_seed = this->commands->com_hand->GetRandomSeed();
    else { initial_seed = *(int*)((char*)rge_base_game+0x28); if (initial_seed == -1) initial_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x509); }
    this->random_seed = initial_seed;
    debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp",0x50c,this->random_seed); *(int*)((char*)rge_base_game+0x30)=this->random_seed;
    this->random_seed=debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x50f); ((TDebuggingLog*)L)->Log("World: new_game (rand=%d)",this->random_seed);
    this->player_num = info.player_num_minus1 + 1; this->map->new_map(info.map_width, info.map_height);
    this->random_seed=debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x516); ((TDebuggingLog*)L)->Log("  World: after_new_map (rand=%d)",this->random_seed);
    this->player_num = info.player_num_minus1 + 1; this->players=(RGE_Player**)calloc(4,(int)this->player_num); this->setup_gaia();
    this->random_seed=debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x520); ((TDebuggingLog*)L)->Log("  World: after_gaia (rand=%d)",this->random_seed);
    this->setup_players(&info);
    this->random_seed=debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x526); ((TDebuggingLog*)L)->Log("  World: after_players (rand=%d)",this->random_seed);
    for (i=1;i<9;i++) {
        int h=this->commands->com_hand->GetPlayerHumanity(i);
        if (h==2 || h==4) { int team=rge_base_game->playerTeam(i-1); if (team>1) for (j=1;j<9;j++) { int h2=this->commands->com_hand->GetPlayerHumanity(j); if ((h2==2||h2==4) && rge_base_game->playerTeam(j-1)==team) { id1=rge_base_game->playerID(i); id2=rge_base_game->playerID(j); if (id1!=id2) { this->players[id1]->set_relation(id2,0); this->players[id1]->set_allied_victory(1); } } } }
    }
    if (rge_base_game->randomGame() && !rge_base_game->campaignGame()) for (i=1;i<9;i++) { int h=this->commands->com_hand->GetPlayerHumanity(i); if (h==4 || all_cp==1 || (all_cp==2 && i>1)) if (rge_base_game->playerTeam(i-1)==1) for (j=1;j<9;j++) { int h2=this->commands->com_hand->GetPlayerHumanity(j); if ((h2==4||h2==2)) { id1=rge_base_game->playerID(i); id2=rge_base_game->playerID(j); if (id1!=id2) { this->players[id1]->set_relation(id2,1); this->players[id1]->set_allied_victory(1); } } } }
    this->world_time=0; this->old_world_time=0; this->world_time_delta=0; this->old_time=0;
    if (rge_base_game->singlePlayerGame()) this->game_speed = rge_base_game->get_game_speed(); else this->game_speed = 1.0f;
    this->temp_pause=0; this->world_time_delta_seconds=0;
    mapTeam = 0;
    if (info.scenario) { retval=this->load_scenario(info.scenario, &info); }
    else if (info.campaign) { retval=this->load_scenario(&info); } else { retval=this->new_random_game(&info); mapTeam=1; }
    this->initializePathingSystem();
    for (i=0;i<this->player_num;i++) if (this->players[i]) this->players[i]->random_start();
    if (retval) this->game_state=0;
    this->random_seed=debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x5b2); ((TDebuggingLog*)L)->Log("  World: end_of_new_game (rand=%d)",this->random_seed);
    RGE_Base_Game* base_game = rge_base_game;
    base_game->get_string(0x277b, randomString, 0x100);
    if (mapTeam==1) for (i=1;i<this->player_num;i++) if (this->players[i]) this->players[i]->loadAIInformation(randomString,randomString,randomString,0,info.victory);
    return retval;
}
