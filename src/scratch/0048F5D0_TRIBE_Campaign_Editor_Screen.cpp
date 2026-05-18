// 0048F5D0 TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen
// Attempt log:
// try 1: natural constructor with /GX, base TScreenPanel ctor, zero member panel pointers, screen setup, child panel creation sequence, tab order, follow-up setup calls.
// try 2: fixed helper/member signatures for create_text/create_button/create_input/create_scroll_bar until source compiled.
// try 3: added virtual destructor surfaces on base/derived to trigger the original EH constructor prologue; prologue then matched through base ctor call.
// try 4: adjusted TScreenPanel visible base gap from 0x478 to 0x474 so derived fields begin at +0x478 with vptr accounted for.
// try 5: modeled vtable restore by natural derived virtual destructor declaration; relocation masked but store shape appears.
// try 6: modeled initial zero order for fields +0x47c,+0x484,+0x48c,+0x494,+0x488,+0x490,+0x498,+0x480,+0x49c,+0x4a4,+0x4a8,+0x4a0,+0x4c0,+0x4bc,+0x4ac,+0x4b0,+0x4b4,+0x4b8.
// try 7: modeled setup failure early return setting +0xd8 to 1.
// try 8: modeled all child panel creation calls with observed resource ids/positions and the scrollbar size expression (f8*30)/height.
// try 9: modeled hotkey writes to p4a4 +0x298/+0x29c and tab-list local with 8 panels.
// try 10: introduced local aliases for +0x48c/+0x490/+0x4bc to probe EBX/EBP/EDI preservation; register allocation got worse despite exact size.
// GIVEUP blockers: exact TScreenPanel/TEasy_Panel class surface and method overload signatures, original local-alias/register allocation (EBX=+48c, EBP=+490, EDI=+4bc), child creation helper prototypes/argument order, and vtable/base layout context. Current source is exact-sized but broad mismatch, not accepted drift.
// FLAGS: config/flags/0048F5D0_TRIBE_Campaign_Editor_Screen.rsp (/GX for original EH constructor prologue)

class TPanel { public: char gap[0x298]; int hotkey; int hotkey_mod; void set_active(); };
class TScreenPanel {
public:
    char base[0x474];
    TScreenPanel(char*);
    virtual ~TScreenPanel();
    int setup(void*, char*, int, int);
    void setup_shadow_area(int);
    void set_size(int,int);
    void* create_text(int, TPanel**, int,int,int,int,int,int,int,int,int);
    void* create_button(int, int,int,int,int,int,int,int,int,int);
    void* create_picture(int, TPanel**, int,int,int,int,int,int,int,int);
    void* create_scroll_bar(int, TPanel**, int,int,int,int,int,int);
    void* create_scroll_bar(int, void*, int,int,int,int,int);
    void* create_input(TPanel**, TPanel*, TPanel*, int);
    void tab_set(TPanel**, int);
    void add_panel(TPanel*);
};
class TRIBE_Campaign_Editor_Screen : public TScreenPanel {
public:
    unsigned char byte478; char gap479[3];
    TPanel *p47c,*p480,*p484,*p488,*p48c,*p490,*p494,*p498,*p49c,*p4a0,*p4a4,*p4a8,*p4ac,*p4b0,*p4b4,*p4b8,*p4bc,*p4c0;
    char rest[4];
    TRIBE_Campaign_Editor_Screen();
    virtual ~TRIBE_Campaign_Editor_Screen();
    void setup_buttons();
    void setup_campaigns();
    void setup_names();
};
struct Game { char gap[0x4c]; void* draw; };
extern Game* rge_base_game;

TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen() : TScreenPanel("Campaign Editor Screen")
{
    TPanel** campaign_list = &this->p48c;
    TPanel** name_list = &this->p490;
    TPanel** main_scroll = &this->p4bc;
    this->p47c=0; this->p484=0; *campaign_list=0; this->p494=0; this->p488=0; *name_list=0; this->p498=0; this->p480=0;
    this->p49c=0; this->p4a4=0; this->p4a8=0; this->p4a0=0; this->p4c0=0; this->p4bc=0;
    this->p4ac=0; this->p4b0=0; this->p4b4=0; this->p4b8=0;
    if (!this->setup(rge_base_game->draw, "scr4", 0xC386, 1)) { *(int*)((char*)this+0xd8)=1; return; }
    this->setup_shadow_area(0);
    this->set_size(0x280,0x1e0);
    this->create_text(0x2bc1,&this->p47c,10,10,0x26c,0x32,1,3,0,0,0);
    this->create_text(0x2bc2,&this->p480,0x14,0x28,0x104,0x14,4,0,0,0,0);
    this->create_scroll_bar(0x17c,main_scroll,0xc8,0x14,0x3c,0x17c,((*(int*)((char*)this+0xf8))*30)/(*(int*)((char*)this+0x18)),0xb);
    this->create_button(0x2bca,0x64,5,0,0,0x168,0x1e,0xb,1,1);
    this->create_input(&this->p49c,*main_scroll,(TPanel*)0,0x14);
    this->create_picture(0x2bc4,&this->p4a8,0,0x1a4,0x3c,0xc8,0x1e,0,0,0);
    this->create_picture(0x2bc5,&this->p4ac,0,0x118,0x104,0xa0,0x1e,0,0,0);
    this->create_picture(0x2bc6,&this->p4b0,0,0x1cc,0x104,0xa0,0x1e,0,0,0);
    this->create_text(0x2bc7,&this->p484,0x14,0x64,0xc8,0x14,4,0,0,0,0);
    this->create_scroll_bar((int)campaign_list,this,0x14,0x78,0x258,0x82,0xb);
    this->create_input(&this->p494,*campaign_list,(TPanel*)0,0x14);
    this->create_text(0x2bc8,&this->p488,0x14,0x118,0xc8,0x14,4,0,0,0,0);
    this->create_scroll_bar((int)name_list,this,0x14,0x12c,0x1f4,0x82,0xb);
    this->create_input(&this->p498,*name_list,(TPanel*)0,0x14);
    this->create_picture(0xfa1,&this->p4a0,0,0x14,0x1bd,0x118,0x1e,0,0,0);
    this->create_picture(0xfa2,&this->p4a4,0,0x154,0x1bd,0x118,0x1e,0,0,0);
    this->p4a4->hotkey = 0x1b; this->p4a4->hotkey_mod = 0;
    this->create_picture(0x2bd5,&this->p4b4,0,0x212,0x12c,0x5a,0x1e,0,0,0);
    this->create_picture(0x2bd6,&this->p4b8,0,0x212,0x154,0x5a,0x1e,0,0,0);
    TPanel* tabs[8];
    tabs[0]=*main_scroll; tabs[1]=this->p4a8; tabs[2]=*campaign_list; tabs[3]=this->p4ac; tabs[4]=this->p4b0; tabs[5]=*name_list; tabs[6]=this->p4a0; tabs[7]=this->p4a4;
    this->tab_set(tabs,8);
    this->add_panel(this->p49c);
    this->add_panel(*main_scroll);
    this->setup_buttons();
    this->setup_campaigns();
    (*name_list)->set_active();
    this->setup_names();
    this->byte478 = 0;
}
