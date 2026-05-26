// 004A81E0 TRIBE_Screen_Sed::TRIBE_Screen_Sed
// Attempt log:
// 1: broad reconstruction from packet: base screen ctor, member initialization, debug timers, graphics/view/panel allocations, scenario-file handling, setup calls and failure path.
// 2: fixed local stub declarations for panel/view/scenario helper calls and compiled with /GX; optimized /O2 body is only 1152 bytes vs original 1381, so reconstruction is too high-level/under-specified.
// 3: /Od /GX probe reaches exact 1381-byte size but is wrong debug-frame basin (EBP frame prologue, 85.2281% positional / 123.7509% edit) and was rolled back to /O2 /GX.
// 4: current behavior surface includes original major effects: TScreenPanel base ctor, vtable/member initialization, init_module_variables, debug_timeGetTime probes, global world age/state call, setup and failure d8 path, name compare for autosave-ish flag, UI panel allocations, scenario name handling, setup page calls, final scenario mode and game panel calls.
// 5: remaining gap is broad constructor/source-context mismatch: original is hand-scheduled VC5 /O2 EH constructor with 0x210 frame, two 260-byte stack buffers, precise allocation temp/EH states, inline string compare/copy loops and many concrete typed calls; current source collapses much of that through high-level/fake helper surfaces, leaving /O2 far under-size. Not accepted_drift-safe.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" int __cdecl stricmp(const char*, const char*);

class TScreenPanel { public: int fieldD8; TScreenPanel(char*); int setup(void*,int,int,int,int,void*,char*); };
class TObjectPanel { public: int fieldD8; int setup(int,int,int,int,int,void*,void*,char*); int link(int,int,int,int,int,int); };
class TView { public: int fieldD8; int setup(void*,void*,void*,void*,void*,void*,void*); };
class RGE_View { public: int fieldD8; int setup(int,int,int,int,int,void*,void*); void load_map(int,int); };
class PanelF4 { public: int fieldD8; int setup(void*,void*,void*,void*,void*,void*,void*); };
class ScenarioInfo { public: void setName(char*); int playerValid(int); };
class P5B8 { public: void set_line(int); };
class GamePanel { public: void a(int); void b(int); };
class Scenario { public: char gap[0x5c]; void* info; };
class World { public: char gap28[0x28]; void* thing28; char gap4c[0x4c-0x2c]; void* thing4c; char gap1ac[0x1ac-0x50]; void* thing1ac; char gapA20[0xA20-0x1B0]; void* thingA20; virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(int); void* make(int); };
extern World* g_world;
extern "C" unsigned long debug_timeGetTime(char*, int);

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char gap0[0x478-sizeof(TScreenPanel)];
    int field478; char gap47c[4]; void* selectedObj; void* destObj; float px1,py1,px2,py2; int field498; int field49c; char gap4a0[4]; int field4a4,field4a8,currentVictory,field4b0,field4b4; short field4b8; int field4bc; char flag4c0,flag4c1; char gap4c2[6]; TObjectPanel* main_view; TView* view2; RGE_View* view3; PanelF4* panel4;
    char gap4d8[0x5B8-0x4D8]; void* p5b8; char gap5bc[0x928-0x5BC]; Scenario* scenario; int t0,t1,t2,t3,t4,t5,t6;
    TRIBE_Screen_Sed(char* file, int mode);
    void init_module_variables(); int setup(int,int,int,int,int,void*,void*); void setup_popup_help(int); void init_view_stuff();
    void setup_multi_pages(int,int); void setup_player_pages(int,int); void setup_map_pages(int); void setup_victory_pages(int,int); void setup_diplomacy_pages(int,int); void set_player(int,int,int); void setup_tech_pages(int); void setup_unit_pages(int,int); void setup_options_page(int); void set_scenario_mode(int); void post_setup(void*); void final_setup(); void load_victory_cond_from_scenario();
};

TRIBE_Screen_Sed::TRIBE_Screen_Sed(char* file, int mode) : TScreenPanel((char*)0x584414)
{
    char name[260];
    char temp_name[260];
    this->fieldD8 = 0;
    this->field478 = 0;
    this->field4a4 = 0; this->field4a8 = 0; this->currentVictory = 2;
    this->field4b0 = 0; this->field4b4 = 0; this->field4b8 = 1; this->field4bc = 0;
    this->selectedObj = 0; this->destObj = 0; this->field49c = 0; this->flag4c0 = 0; this->flag4c1 = 0;
    *(int*)this = 0x5739C0;
    this->init_module_variables();
    this->t0 = debug_timeGetTime((char*)0x586CB0,0x117);
    this->t1 = 1000;
    this->t2 = debug_timeGetTime((char*)0x586CB0,0x11a);
    this->t4 = this->t5 = this->t3 = this->field498 = 0;
    g_world->f3(7);
    if (!this->setup(mode,0,0,0x90,0x90,(void*)1,(void*)1)) { this->fieldD8 = 1; return; }
    sprintf(name,(char*)0x586CA0, ((char*)g_world->thing1ac));
    if (file && strcmp(file,name)==0) this->flag4c0 = 1;
    if (!this->TScreenPanel::setup(g_world->thing4c,0,0xC387,1,0,(void*)0x586C98,(char*)0)) { this->fieldD8 = 1; return; }
    this->setup_popup_help(0);
    TObjectPanel* p = new TObjectPanel;
    this->main_view = p;
    if (!p || p->fieldD8) { this->fieldD8 = 1; return; }
    if (!p->setup((int)this->gap0,0,0,0,0xA1,this,g_world->thing28,(char*)0x586334)) { this->fieldD8 = 1; return; }
    TView* v = new TView;
    this->view2 = v;
    if (!v || v->fieldD8) { this->fieldD8 = 1; return; }
    if (!v->setup(g_world->thingA20,0,0,0,(void*)0xA1,this,g_world->thing28)) { this->fieldD8 = 1; return; }
    v->setup((void*)0x586C8C,(void*)0xC4E1,0,0,0,0,0);
    this->main_view->link((int)this->view2, -1, -1, 0,0,0);
    void* made = g_world->make(0xb);
    RGE_View* rv = new RGE_View;
    this->view3 = rv;
    if (!rv || rv->fieldD8) { this->fieldD8 = 1; return; }
    if (!rv->setup(0,0,0,0,0,this->main_view,g_world->thing28)) { this->fieldD8 = 1; return; }
    PanelF4* f = new PanelF4;
    this->panel4 = f;
    if (!f || f->fieldD8) { this->fieldD8 = 1; return; }
    if (!f->setup(0,0,0,0,0,this,g_world->thing28)) { this->fieldD8 = 1; return; }
    this->init_view_stuff();
    if (file && *file) {
        if (stricmp(file,(char*)0x586104)==0 || stricmp(file,(char*)0x586C84)!=0) {
            char* pch=file; int i=0; while (*pch!='.') temp_name[i++]=*pch++; temp_name[i]=0;
            sprintf(file,(char*)0x586840,temp_name);
            ((ScenarioInfo*)this->scenario->info)->setName(file);
        }
        int idx=0; while (((ScenarioInfo*)this->scenario->info)->playerValid(idx)) { if (++idx>=8) break; }
        ((P5B8*)this->p5b8)->set_line(idx-1);
        this->final_setup();
    } else {
        this->setup_multi_pages(0,1); this->setup_multi_pages(1,1); ((P5B8*)this->p5b8)->set_line(1); this->final_setup();
    }
    this->post_setup(this->panel4);
    this->load_victory_cond_from_scenario();
    this->setup_player_pages(1,0); this->setup_map_pages(1); this->setup_victory_pages(1,0); this->setup_diplomacy_pages(1,0); this->set_player(1,0,0); this->setup_tech_pages(1); this->setup_unit_pages(1,0); this->setup_options_page(1);
    this->set_scenario_mode(-1);
    ((GamePanel*)*(void**)((char*)this->scenario+0x28))->a(1);
    ((GamePanel*)*(void**)((char*)this->scenario+0x28))->b(0);
}
