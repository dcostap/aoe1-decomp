// Attempt log for 004C8740 TRIBE_Building_Object::set_object_state
// try 1: natural reconstruction from packet/decompiler; compile required cast simplification, too small 336B.
// try 2: /Oy- probe; too small 352B.
// try 3: /O1 probe; too small 321B.
// try 4: reviewed state==2 entry/random/debug sequence; behavioral outline present.
// try 5: reviewed virtual call offsets; source uses casts and is not exact member-call surface.
// try 6: reviewed terrain rectangle FPU/ftol sequence; mostly omitted, major size gap.
// try 7: reviewed tech/sound cleanup state==3; omitted/placeholder.
// try 8: reviewed final base set_object_state order; approximate.
// try 9: attempted local type surface only; still behavioral scaffold.
// try 10: left in scratch; not exact-size.
// BLOCKER: rebuilt .text 336B vs original 791B; source is only partial scaffold missing terrain/tech/sound/helper call bodies and exact virtual/member-call surfaces. Not accepted_drift-safe.

typedef unsigned char uchar;
class ObjInfo { public: char pad10[0x10]; short icon; char pad18[0x44]; float sx; float sy; char pad64[0x108]; char on_complete; char gather_flag; char connect_flag; char pad16f; char play_anim; short terrain1; short terrain2; short tech; };
class Player { public: void* vt; char pad24[0x24]; void** objinfos; char pad28[0x18]; void* map1; char pad4a[0x1d6]; void* tech; };
class TRIBE_Building_Object { public: void** vt; char pad8[0x8-sizeof(void**)]; ObjInfo* info; Player* player; char pad10[0x25]; char field35; char pad36[2]; float x; float y; int z; int w; char pad4c[0x18c]; float build; char pad1e0[5]; char flag1e5; int field1e8; void set_object_state(uchar); void connect(); void base_set(uchar); };
extern int debug_random_on; extern "C" int debug_rand(char*,int); extern "C" void debug_srand(char*,int,int); extern "C" long __cdecl _ftol(void);
class BaseGame { public: void** vt; }; extern BaseGame* rge_base_game;
static char file[]="C:\\msdev\\work\\age1_x1\\t_b_obj.cpp";

void TRIBE_Building_Object::set_object_state(uchar state)
{
    bool did=false;
    if(state==2){
        int tmp=this->info->tech; this->build=(float)tmp;
        int r=debug_rand(file,0x12b); int old=debug_random_on; debug_random_on=0;
        if(this->info->on_complete && this->player && 0) { }
        debug_srand(file,0x135,r); debug_random_on=old;
        this->flag1e5=1; ((void (__stdcall*)(TRIBE_Building_Object*))this->vt[0x97])(this);
        if(this->info->play_anim) ((void (__stdcall*)(TRIBE_Building_Object*))this->vt[0x1b])(this); else { ((void (__stdcall*)(TRIBE_Building_Object*,Player*,int,int))this->vt[0x37])(this,this->player,1,-1); ((void (__stdcall*)(TRIBE_Building_Object*,Player*,int,int))this->vt[0x36])(this,this->player,0,-1); ((void (__stdcall*)(TRIBE_Building_Object*,int))this->vt[0x0e])(this,*(int*)((char*)this->info+0x18)); this->field35=this->info->gather_flag; if(this->info->connect_flag) connect(); }
        if(this->info->terrain1!=-1){ void* oi=this->player->objinfos[this->info->terrain1]; ((void (__stdcall*)(void*,Player*,int,int,int))(*(void***)oi)[6])(oi,this->player,(int)this->x,(int)this->y,this->z); }
        if(this->info->terrain2!=-1){ int a=(int)(this->y+this->info->sy-0.5); int b=(int)(this->x+this->info->sx-0.5); int c=(int)(this->y-this->info->sy); int d=(int)(this->x-this->info->sx); /* map terrain calls omitted */ }
        if(this->info->tech!=-1){ /* enable tech */ }
        /* game event */
        ((void (__stdcall*)(Player*,TRIBE_Building_Object*,float))(*(void***)this->player)[0x41])(this->player,this,this->build);
    }
    if(state==3 && *(char*)((char*)this+0x48)==2){ ((void (__stdcall*)(TRIBE_Building_Object*))this->vt[0x96])(this); did=true; }
    this->base_set(state);
    if(did){ /* cleanup tech/sounds */ }
}
