// 00542750 new_game attempt
// rough natural source from packet; unresolved broad layout/codegen drift expected.
#define VPAD1(n) virtual void v##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##a)
#define VPAD4(n) VPAD2(n) VPAD2(n##b)
#define VPAD8(n) VPAD4(n) VPAD4(n##c)
#define VPAD16(n) VPAD8(n) VPAD8(n##d)
#define VPAD32(n) VPAD16(n) VPAD16(n##e)
#define VPAD64(n) VPAD32(n) VPAD32(n##f)

extern int debug_rand(const char*, int);
extern void debug_srand(const char*, int, int);
extern void debug_random_reset();
extern void* calloc(unsigned int, unsigned int);
extern int sprintf(char*, const char*, ...);
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
class RGE_Base_Game { public: VPAD8(0) virtual void language(int, char*, int); int multiplayerGame(); int randomGame(); int campaignGame(); int singlePlayerGame(); float get_game_speed(); int playerTeam(int); int playerID(int); };
class TCommunications_Handler { public: int GetRandomSeed(); int GetPlayerHumanity(int); };
class CommHolder { public: char p0[0x14]; TCommunications_Handler* handler; };
class RGE_Map { public: void new_map(long,long); };
class RGE_Player { public: VPAD16(0) VPAD16(16) VPAD4(32) virtual void d36(); virtual void set_relation(int,int); virtual void set_allied_victory(int); VPAD16(39) VPAD16(55) VPAD8(71) VPAD8(79) VPAD1(87) VPAD1(88) VPAD1(89) virtual void update(); virtual void start1(int*,int*,int*,int,int); };
class RGE_Player_Info { public: char p0[0x294]; short player_num_minus1; int rand_field; short map_x; short map_y; short map_type; short victory; char p2a6[2]; unsigned char flag2a8; };

class RGE_Game_World { public:
 VPAD16(0) VPAD4(16) VPAD2(20) VPAD1(22)
 virtual void gaia_init();                    // slot 23 +0x5c
 virtual void players_init(RGE_Player_Info*); // slot 24 +0x60
 virtual unsigned char default_map(RGE_Player_Info*); // slot 25 +0x64
 VPAD1(26) VPAD1(27) VPAD1(28)
 virtual unsigned char scenario_make_map(RGE_Player_Info*); // slot 29 +0x74
 virtual unsigned char random_map(RGE_Player_Info*); // slot 30 +0x78
 VPAD8(31) VPAD4(39) VPAD2(43) VPAD1(45)
 virtual void setup_noarg(); // slot 46 +0xb8
 char g04[0x24]; RGE_Map* map; char g2c[0x10]; short player_num; char g3e[2]; RGE_Player** players; char g44[0x14]; CommHolder* comm; char g5c[0x1c]; int random_seed; short curr_player; char g7e[0x7E]; int field84; char rest[0x10];
 unsigned char new_game(RGE_Player_Info& info, int mode); int initializePathingSystem();
};

unsigned char RGE_Game_World::new_game(RGE_Player_Info& info, int mode) {
    char randomString[256];
    int team;
    volatile unsigned char retval;
    int i,j, id1, id2;
    world_update_counter = 0;
    pathSystem.zeroObstructionMap();
    aiPathSystem.zeroObstructionMap();
    for (i=0;i<13;i++) computerPlayerSetup[i]=0;
    this->field84 = -1;
    this->setup_noarg();
    debug_random_reset();
    debug_timeGetTime_cnt = 0; debug_timeGetTime_time = 0; this->g04[0x19] = 3; this->curr_player = mode;
    if (rge_base_game->multiplayerGame()) this->random_seed = this->comm->handler->GetRandomSeed();
    else { this->random_seed = *(int*)((char*)rge_base_game+0x28); if (this->random_seed == -1) this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x509); }
    debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp",0x50c,this->random_seed); *(int*)((char*)rge_base_game+0x30)=this->random_seed;
    this->random_seed=debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x50f); ((TDebuggingLog*)L)->Log("World: new_game (rand=%d)",this->random_seed);
    this->player_num = info.player_num_minus1 + 1; this->map->new_map(info.map_y, info.map_x);
    this->random_seed=debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x516); ((TDebuggingLog*)L)->Log("  World: after_new_map (rand=%d)",this->random_seed);
    this->player_num = info.player_num_minus1 + 1; this->players=(RGE_Player**)calloc(4,(int)this->player_num); this->gaia_init();
    this->random_seed=debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x520); ((TDebuggingLog*)L)->Log("  World: after_gaia (rand=%d)",this->random_seed);
    this->players_init(&info);
    this->random_seed=debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x526); ((TDebuggingLog*)L)->Log("  World: after_players (rand=%d)",this->random_seed);
    for (i=1;i<9;i++) {
        int h=this->comm->handler->GetPlayerHumanity(i);
        if (h==2 || h==4) { team=rge_base_game->playerTeam(i-1); if (team>1) for (j=1;j<9;j++) { int h2=this->comm->handler->GetPlayerHumanity(j); if ((h2==2||h2==4) && rge_base_game->playerTeam(j-1)==team) { id1=rge_base_game->playerID(i); id2=rge_base_game->playerID(j); if (id1!=id2) { this->players[id1]->set_relation(id2,0); this->players[id1]->set_allied_victory(1); } } } }
    }
    if (rge_base_game->randomGame() && !rge_base_game->campaignGame()) for (i=1;i<9;i++) { int h=this->comm->handler->GetPlayerHumanity(i); if (h==4 || all_cp==1 || (all_cp==2 && i>1)) if (rge_base_game->playerTeam(i-1)==1) for (j=1;j<9;j++) { int h2=this->comm->handler->GetPlayerHumanity(j); if ((h2==4||h2==2)) { id1=rge_base_game->playerID(i); id2=rge_base_game->playerID(j); if (id1!=id2) { this->players[id1]->set_relation(id2,1); this->players[id1]->set_allied_victory(1); } } } }
    this->g04[0]=0; this->g04[4]=0; this->g04[8]=0; this->g04[0x10]=0;
    if (rge_base_game->singlePlayerGame()) { float gs = rge_base_game->get_game_speed(); *(float*)&this->g04[0x14]=gs; } else *(int*)&this->g04[0x14]=0x3f800000;
    this->g04[0x18]=0; this->field84=0;
    if (info.rand_field) { retval=this->random_map(&info); }
    else if (info.flag2a8) { retval=this->scenario_make_map(&info); } else { retval=this->default_map(&info); team=1; }
    this->initializePathingSystem();
    for (i=0;i<this->player_num;i++) if (this->players[i]) this->players[i]->update();
    if (retval) this->g04[0x19]=0;
    this->random_seed=debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp",0x5b2); ((TDebuggingLog*)L)->Log("  World: end_of_new_game (rand=%d)",this->random_seed);
    rge_base_game->language(0x277b, randomString, 0x100);
    if (team==1) for (i=1;i<this->player_num;i++) if (this->players[i]) this->players[i]->start1((int*)&randomString[0],(int*)&randomString[4],(int*)&randomString[8],0,info.victory);
    return retval;
}
