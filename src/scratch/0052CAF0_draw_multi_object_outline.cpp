// 0052CAF0 draw_multi_object_outline - reconstruction attempt
// Notes:
// - Packet shows this is mostly grid-line rasterization for a dragged multi-object placement rectangle.
// - Modeled selection-area/mouse-pick setup, start/end row/col derivation, and diagonal vs non-diagonal draw_wall_outline loops.
// - Exact source likely had many hand-written branch families for 8 directions; this compact helper version is behavior-shaped but expected too small.
// Attempts:
// - Initial source failed on VC5 `__thiscall` function pointer syntax; switched the raw rge_base_game mouse-position vtable probe to cdecl just to compile.
// - Moved dc/dr declarations above early goto to satisfy VC5 skipped-initialization rules.
// - Compiled .text is 912 vs original 1385: broad missing branch-unrolled path structure, exact temp stack topology, and original's many early-return epilogues.
// - Adjacent scratch draw_wall_outline/command_place_multi_object are only rough stubs, so no reliable donor surface exists locally.
// - Not accepted-drift quality.
struct Point { int x; int y; };
struct PickInfo { float x; float y; char pad[0x20]; };
extern void* rge_base_game;
extern "C" int __cdecl _ftol(float);
class DrawArea { public: void SetClipRect(void*); };
class DB { public: void** table; };
class TRIBE_Main_View {
public:
    void* vptr; char pad04[0x1c]; DrawArea* area; char rect[0x68]; int scroll_y; int scroll_x; char pad94[0x6c]; DB* db;
    virtual int dummy00(); virtual int dummy04(); virtual int dummy08(); virtual int dummy0c(); virtual int dummy10(); virtual int dummy14(); virtual int dummy18(); virtual int dummy1c(); virtual int dummy20(); virtual int dummy24(); virtual int dummy28(); virtual int dummy2c(); virtual int dummy30(); virtual int dummy34(); virtual int dummy38(); virtual int dummy3c(); virtual int dummy40(); virtual int dummy44(); virtual int dummy48(); virtual int dummy4c(); virtual int dummy50(); virtual int dummy54(); virtual int dummy58(); virtual int dummy5c(); virtual int dummy60(); virtual int dummy64(); virtual int dummy68(); virtual int dummy6c(); virtual int dummy70(); virtual int dummy74(); virtual int dummy78(); virtual int dummy7c(); virtual int dummy80(); virtual int dummy84(); virtual int dummy88(); virtual int dummy8c(); virtual int dummy90(); virtual int dummy94(); virtual int dummy98(); virtual int dummy9c(); virtual int dummya0(); virtual int dummya4(); virtual int dummya8(); virtual int dummyac(); virtual int dummyb0(); virtual int dummyb4(); virtual int dummyb8(); virtual int hit(int,int);
    int get_selection_area(int*,int*,int*,int*,void*,int); unsigned char pick1(unsigned char,int,int,int,PickInfo*,int,int); void fixup_pick_info(PickInfo*); void draw_wall_outline(int,int,void*,int); void draw_multi_object_outline();
};
static int iabs(int x){ return x<0?-x:x; }
static int edge(int a,int b,int c,int d){ return (a==b || a==c)?2:(d?1:0); }
void TRIBE_Main_View::draw_multi_object_outline(){
    short id = *(short*)((char*)rge_base_game+0x3fc); if(id==(short)-1) return;
    void* master = this->db->table[id]; if(!master) return;
    this->area->SetClipRect(&this->rect);
    int sc=0,sr=0,ec=0,er=0; int dc=0, dr=0; PickInfo pick;
    if(!this->get_selection_area(&sc,&sr,&ec,&er,master,0)){
        Point pt; ((void(__cdecl*)(void*,Point*))(*(void***)rge_base_game)[0x8b])(rge_base_game,&pt);
        if(!this->hit(pt.y,pt.x)) goto out;
        if(this->pick1(0x28,0,pt.y-this->scroll_y,pt.x-this->scroll_x,&pick,0,1)!=0x33) goto out;
        this->fixup_pick_info(&pick); sc=ec=_ftol(pick.x); sr=er=_ftol(pick.y);
    }
    dc=ec-sc; dr=er-sr;
    if(iabs(dc)==iabs(dr)){
        int stepx=(dc>=0)?1:-1, stepy=(dr>=0)?1:-1; int c=sc,r=sr;
        for(;;){ this->draw_wall_outline(r,c,master,2); if(c==ec) break; c+=stepx; r+=stepy; }
        goto out;
    }
    if(iabs(dc)>iabs(dr)){
        int cmin=sc<ec?sc:ec, cmax=sc<ec?ec:sc; int rmin=sr<er?sr:er, rmax=sr<er?er:sr;
        for(int c=cmin;c<=cmax;c++) this->draw_wall_outline(sr,c,master,edge(c,cmin,cmax,1));
        for(int r=rmin;r<=rmax;r++) this->draw_wall_outline(r,ec,master,edge(r,rmin,rmax,1));
    } else {
        int cmin=sc<ec?sc:ec, cmax=sc<ec?ec:sc; int rmin=sr<er?sr:er, rmax=sr<er?er:sr;
        for(int r=rmin;r<=rmax;r++) this->draw_wall_outline(r,sc,master,edge(r,rmin,rmax,1));
        for(int c=cmin;c<=cmax;c++) this->draw_wall_outline(er,c,master,edge(c,cmin,cmax,1));
    }
out:
    this->area->SetClipRect(0);
}
