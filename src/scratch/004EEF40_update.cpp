// VA: 004EEF40 TribeTacticalAIModule::update
// PDB source: taitacmd.cpp
// Attempt log:
// - broad reconstruction from packet: periodic decay/clamp, reset counters, diplomacy/player-list maintenance, per-player stance assignment, final update helper.
// - default /O2 compiles but .text is 880 bytes vs target 1421, too short for extraction; helper surfaces and array-growth topology are substantially under-modeled.
// - tried /Od diagnostically: extracts at target size but 87.54% positional diff from offset 0 due EBP/debug frame, so not viable for original optimized function.
// - restored default flags. Give-up: requires faithful full source reconstruction of diplomacy helper calls, dynamic-array append/copy blocks, and exact per-player conditional chain; no accepted_drift proposed.

extern void* operator new(unsigned int);
extern void operator delete(void*);

struct World { char gap0[4]; int tick; char gap8[0x3c-8]; short player_count; char gap3e[0x4a-0x3e]; short my_player; };
struct Game { char gap0[0x3c]; World* world; };
struct Player { char gap0[0xf0]; Game* game; char gapf4[0x9dc-0xf4]; int diplomacy[1]; };
struct Diplomacy { int a(int,int,int,int); int b(int,int); int c(int); int d(int); int e(int); int f(int); int g(int,int); int h(int); int i(int); int set(int,int); };
struct AI {
    char gap0[0xf0]; Player* player; char gapf4[0x1d4-0xf4]; int v1; char gap1d8[0x1fc-0x1d8]; int v2; char gap200[0x208-0x200]; int threshold; int v20c; int v210; char gap214[0x300-0x214]; int v300; char gap304[4]; int dv1; int dv2; char gap310[0x320-0x310]; int interval; char gap324[0x384-0x324]; int a384; char gap388[0x394-0x388]; int a394; char gap398[0x484-0x398]; int a484; char gap488[0x4a0-0x488]; int a4a0; char gap4a4[0xd1c-0x4a4]; int last_tick; int* mostLiked; int likedCount; char gapd30[4]; int likedCap; int* mostHated; int hatedCount; char gapd40[4]; int hatedCap; char gapd48[0x14]; int tempCount;
    void action(int); void finish(); int update(int);
};
static int contains(int* a,int n,int cap,int v){ for(int i=0;i<n && i<cap;i++) if(a[i]==v) return 1; return 0; }
static void append(int** pa,int* pn,int* pc,int v){ int n=*pn; if(n>*pc-1){ int nc=n+1; int* q=(int*)operator new(nc*4); if(q){ for(int i=0;i<*pc && i<nc;i++) q[i]=(*pa)[i]; operator delete(*pa); *pa=q; *pc=nc; }} (*pa)[(*pn)++]=v; }

int AI::update(int)
{
    Player* p=player; World* w=p->game->world; int zero=0;
    int scale=interval*3; scale*=5; scale*=5; scale*=5; scale*=5; scale<<=5;
    if ((unsigned)(w->tick-last_tick) > (unsigned)scale) {
        v2 += dv2; if (v2<0) v2=0;
        v1 += dv1; if (v1<0) v1=0;
        if (v1>v2) v1=v2; if (v2<v1) v2=v1;
        v20c <<= 1; if(v20c<0) v20c=0; if(v20c>100) v20c=100;
        v210 <<= 1; if(v210<0) v210=0; if(v210>100) v210=100;
        v300 <<= 1; if(v300<0) v300=0; if(v300>100) v300=100;
        last_tick=w->tick;
    }
    tempCount=0; *(int*)((char*)p+0xde0)=0;
    unsigned q=(unsigned)(((double)(unsigned)w->tick)*0.004); if(q>= (unsigned)0) action(2);
    Diplomacy* d=(Diplomacy*)((char*)p+0x9dc);
    int mostLiked=d->a(a384,a394,a484,a4a0); int mostHated=d->b(a384,a394);
    likedCount=0; append(&mostLiked?&this->mostLiked:&this->mostLiked,&likedCount,&likedCap,mostLiked);
    hatedCount=0; append(&this->mostHated,&hatedCount,&hatedCap,w->my_player); if(mostLiked!=mostHated) append(&this->mostHated,&hatedCount,&hatedCap,mostHated);
    for(int i=1;i<w->player_count;i++) {
        if(i==w->my_player) continue;
        if(i==mostLiked) { if(!d->h(i) && d->d(i) && d->set(i,0)>74) d->g(i,1); }
        else if(i==mostHated) { if(!d->i(i) && d->d(i) && d->set(i,2)>74) d->g(i,1); }
        else if(d->set(i,2)>threshold && d->d(i) && !d->i(i)) d->g(i,0);
        else if(!d->e(i) && d->d(i)) d->g(i,1);
    }
    finish(); tempCount=0; return 1;
}
