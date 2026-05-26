// 004A0D80 TribeMPSetupScreen::init_vars - rough reconstruction
// Attempts:
// - Modeled large zero-initialization regions from packet (+0x478.., +0x5D0 family, +0x610.., +0x62c/+0x67c 20-pair block, +0x6cc..+0x740, +0x840..+0x88c) and broad game-settings initialization branches.
// - Exact match depends on preserving the original hand-unrolled stores and long sequence of RGE_Base_Game setters; this source is compact/behavioral and expected too small.
// - Current compile is .text 1248 vs original 1403. Missing exact game setter declarations/call addresses, line-ordered random/debug calls, and original store scheduling; not accepted-drift quality.
extern void* rge_base_game;
extern void* g_game_settings_62C4C0;
extern "C" int __cdecl debug_rand(char*, int); extern char s_C__msdev_work_age1_x1_scr_mps_cp[];
class Game { public:
 int randomGame(); int multiplayerGame(); int campaignGame(); int scenarioGame(); int getSomething();
 void setA(int); void setB(int); void setC(int); void setD(char*); void setE(int); void setF(int); void setG(int,int); void setH(int); void setI(int); void setJ(int); void setK(int); void setL(int); void setM(int); void setN(int); void setO(int); void setP(int); void setQ(int); void setR(int); void setS(int); void setT(int); void setU(int); void setV(int); void setW(int); void setX(int); void setY(int); void setZ(int,int); void setAA(int,int); void setAB(int,int); void virtual48(); };
class Settings { public: int isActive(); };
class TribeMPSetupScreen { public: char bytes[0x900]; void init_vars(); };
static Game* G(){ return (Game*)rge_base_game; }
void TribeMPSetupScreen::init_vars(){
    int i; int zero=0; int eight=8;
    *(int*)(bytes+0x478)=0; *(int*)(bytes+0x47c)=0; *(int*)(bytes+0x480)=0; *(int*)(bytes+0x484)=0; *(int*)(bytes+0x488)=0; *(int*)(bytes+0x48c)=0;
    for(i=0;i<8;i++){ *(int*)(bytes+0x5b0+i*4)=0; *(int*)(bytes+0x5d0+i*4)=0; *(int*)(bytes+0x5f0+i*4)=0; *(int*)(bytes+0x490+i*4)=0; *(int*)(bytes+0x4b0+i*4)=0; *(int*)(bytes+0x4d0+i*4)=0; *(int*)(bytes+0x4f0+i*4)=0; *(int*)(bytes+0x510+i*4)=0; *(int*)(bytes+0x530+i*4)=0; *(int*)(bytes+0x550+i*4)=0; }
    *(int*)(bytes+0x610)=0; *(int*)(bytes+0x614)=0; *(int*)(bytes+0x61c)=0; *(int*)(bytes+0x618)=0; *(int*)(bytes+0x620)=0; *(int*)(bytes+0x624)=0; *(int*)(bytes+0x628)=0;
    for(i=0;i<20;i++){ *(int*)(bytes+0x62c+i*4)=0; *(int*)(bytes+0x67c+i*4)=0; }
    for(i=0;i<13;i++) *(int*)(bytes+0x6cc+i*4)=0; *(int*)(bytes+0x71c)=0; for(i=0;i<8;i++) *(int*)(bytes+0x700+i*4)=0; *(int*)(bytes+0x720)=0; *(int*)(bytes+0x724)=0; *(int*)(bytes+0x72c)=0; *(int*)(bytes+0x730)=-1; *(int*)(bytes+0x734)=0; *(int*)(bytes+0x738)=0; *(int*)(bytes+0x73c)=0; bytes[0x740]=0;
    *(int*)(bytes+0x840)=G()->campaignGame(); *(int*)(bytes+0x844)=0; *(int*)(bytes+0x848)=0; *(int*)(bytes+0x850)=8; *(int*)(bytes+0x728)=8; *(int*)(bytes+0x84c)=0; *(int*)(bytes+0x854)=0; *(int*)(bytes+0x858)=0; *(int*)(bytes+0x85c)=0; for(i=0;i<8;i++) *(int*)(bytes+0x868+i*4)=0; *(int*)(bytes+0x888)=0; *(int*)(bytes+0x88c)=0;
    if(G()->multiplayerGame()){
        G()->setA(0); G()->setB(0); G()->setC(0); G()->setD((char*)0x592A40); G()->setE(3); G()->setF(3); G()->setG(0,0); G()->setH(1); G()->setI(1); G()->setJ(8); G()->setK(0); G()->setL(1); G()->setM(0); G()->setN(0); G()->setO(0); G()->setP(0); G()->setQ(0); G()->setR(1); G()->setS(0); G()->setT(0); G()->setU(0); G()->setV(G()->getSomething()); G()->setW(0); G()->setX(0); debug_rand(s_C__msdev_work_age1_x1_scr_mps_cp,0x243);
        for(i=0;i<8;i++){ bytes[0x860+i]=(char)(i+1); G()->setZ(i,(debug_rand(s_C__msdev_work_age1_x1_scr_mps_cp,0x248)&0xf)+1); G()->setAA(i,i); G()->setAB(i,i); }
        if(((Settings*)g_game_settings_62C4C0)->isActive()){ G()->setAB(0,1); G()->virtual48(); *(int*)(bytes+0x88c)=0; return; }
    } else if(!G()->randomGame()){
        G()->setE(3); int r=debug_rand(s_C__msdev_work_age1_x1_scr_mps_cp,0x26a)%10; int v=(r<2)?4:(r==2?3:(r==3?2:(r==4?1:((r==5||r==6||r==7)?r:(r!=8?8:0))))); G()->setF(v);
        G()->setG(0,0); G()->setJ(4); G()->setA(0); G()->setB(0); G()->setH(1); G()->setI(1); G()->setK(0); G()->setL(1); G()->setM(1); G()->setN(0); G()->setO(0); G()->setP(0); G()->setQ(0); G()->setV(G()->getSomething()); G()->setW(0);
    }
}
