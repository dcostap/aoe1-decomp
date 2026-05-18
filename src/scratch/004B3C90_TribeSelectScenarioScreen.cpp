// 004B3C90 TribeSelectScenarioScreen::TribeSelectScenarioScreen
// Attempt log:
// try 1: natural constructor with /GX. Models base ctor, init_vars, multiplayer-dependent background setup, panel creation chain, option controls, and final setup calls. Exact-sized but broad mismatch (63.6684% positional / 48.5009% edit).
// try 2: added virtual destructor surfaces on TPanel/TScreenPanel/derived to trigger original EH constructor prologue; prologue matches through init_vars.
// try 3: modeled multiplayerGame() choice of scr2/scr3 and setup resource id 0xc384/0xc385.
// try 4: modeled setup failure early return setting +0xd8=1.
// try 5: modeled title, scenario scroll/list, input, label, help text, empty-button, and picture/control creation calls with observed ids and coordinates.
// try 6: modeled list rectangle fields +0x484/+0x488/+0x48c/+0x490 and scroll size formula using +0x14 and +0xf4.
// try 7: modeled vcall text/range/font/set_active/set_positioning calls at observed vtable-ish offsets.
// try 8: modeled color/positioning call using bytes +0x320..+0x325.
// try 9: modeled hotkey writes at panel +0x298/+0x29c and final state +0x4a8=1.
// try 10: used goto done common failure tail and natural final setup calls fillScenarios/setupButtons/setupDesc/setupList/add_panel; still broad helper/register/order mismatch.
// GIVEUP blockers: exact TEasy/TScreenPanel helper overload surfaces and arg order, original EBX background-string allocation vs rebuilt EDI, precise field layout around +0x478..+0x4d0, and vcall slot declarations for panel methods. No inline asm used; no accepted_drift proposal.
// FLAGS: config/flags/004B3C90_TribeSelectScenarioScreen.rsp (/GX for original EH constructor prologue)

class TPanel { public: char gap[0x298]; int hotkey; int hotkey_mod; virtual ~TPanel(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void set_active(int); virtual void set_positioning(int,int,int,int,int,int,int,int,int,int,int,int,int); void set_text(int); void set_font(int,int); void set_scroll(int); void set_range(int,int); };
class TScreenPanel {
public:
    char base[0x474];
    TScreenPanel(char*);
    virtual ~TScreenPanel();
    int setup(void*, int, char*, int);
    void setup_shadow_area(int);
    void set_size(int,int);
    int create_text(int,TPanel**,int,int,int,int,int,int,int,int,int);
    int create_text2(int,TPanel**,int,int,int,int,int,int,int,int,int);
    int create_scroll(TPanel**,int,int,int,int,int);
    int create_input(TPanel**,TPanel*,int);
    int create_picture(int,TPanel**,int,int,int,int,int,int,int,int);
    int create_button(char*,TPanel**,int,int,int,int,int,int,int,int,int);
    void add_panel(TPanel*);
};
struct Game { char gap[0x4c]; void* draw; int multiplayerGame(); };
extern Game* rge_base_game;
extern char scr2[]; extern char scr3[]; extern char empty_button[];
class TribeSelectScenarioScreen: public TScreenPanel {
public:
    TPanel *title,*desc,*title2,*list,*input,*label,*label2,*help,*button,*buttonIn,*prev,*next,*hidden;
    int x,y,w,h;
    int a8,b0,b4,b8,bc;
    TribeSelectScenarioScreen(); virtual ~TribeSelectScenarioScreen();
    void init_vars(); void fillScenarios(); void setupButtons(); void setupDesc(); void setupList();
};

TribeSelectScenarioScreen::TribeSelectScenarioScreen() : TScreenPanel("Select Scenario Screen")
{
    this->init_vars();
    char* bg = rge_base_game->multiplayerGame() ? scr3 : scr2;
    if (!this->setup(rge_base_game->draw, 0, bg, rge_base_game->multiplayerGame() ? 0xc385 : 0xc384)) { *(int*)((char*)this+0xd8)=1; return; }
    this->setup_shadow_area(0);
    this->set_size(0x280,0x1e0);
    if (!this->create_text(0x25fa,&this->title,0x14,0x0a,0x258,0x1e,1,1,0,0,0)) goto done;
    this->x=0x14; this->y=0x46; this->w=0x258; this->h=0x107;
    if (!this->create_scroll(&this->list,this->x,this->y,this->w,this->h,0x0b)) goto done;
    this->list->set_scroll((*(int*)((char*)this+0x14)) * (this->w - 0x3c) / (*(int*)((char*)this+0xf4)));
    this->list->set_text(0x25fd);
    if (!this->create_input(&this->input,this->list,0x14)) goto done;
    this->input->set_range(-1,-1);
    if (!this->create_text(0x25fe,&this->desc,this->x,this->y-0x14,0x12c,0x14,4,0,0,0,0)) goto done;
    if (!this->create_text(0x25ff,&this->label,this->x+this->w-0xdc,this->y-0x14,0xc8,0x14,4,0,0,0,0)) goto done;
    this->label->set_font(3,2);
    this->b4 = this->h + this->y + 0x19; this->b0=this->x; this->b8=this->w; this->bc=0x3c;
    if (!this->create_text(0x2600,&this->label2,this->b0,this->b4-0x14,0x190,0x14,4,0,0,0,0)) goto done;
    if (!this->create_button(empty_button,&this->button,this->b0,this->b4,this->b8,this->bc,0x0b,0,0,1,1)) goto done;
    this->button->set_positioning(3, (unsigned char)*(char*)((char*)this+0x320), (unsigned char)*(char*)((char*)this+0x321), (unsigned char)*(char*)((char*)this+0x322), (unsigned char)*(char*)((char*)this+0x323), (unsigned char)*(char*)((char*)this+0x324), (unsigned char)*(char*)((char*)this+0x325),0,0,0,0,0,0);
    if (!this->create_input(&this->buttonIn,this->button,0x14)) goto done;
    this->buttonIn->set_range(0x7532,-1);
    if (!this->create_picture(0xfa1,&this->prev,0,0x46,0x1b8,0xf0,0x1e,0,0,0)) goto done;
    this->prev->set_range(0x7531,-1);
    if (!this->create_picture(0xfa2,&this->next,0,0x14a,0x1b8,0xf0,0x1e,0,0,0)) goto done;
    this->next->set_range(0x7532,-1);
    this->next->hotkey=0x1b; this->next->hotkey_mod=0;
    if (!this->create_picture(0x3ea,&this->hidden,0,0,0,0,0,0,-1,-1)) goto done;
    this->hidden->set_active(1);
    this->hidden->set_positioning(9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
    this->fillScenarios();
    this->a8=1;
    this->setupButtons();
    this->setupDesc();
    this->setupList();
    this->add_panel(this->list);
done:
    ;
}
