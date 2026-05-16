// Attempt log for 004A63D0 TRIBE_Screen_Name::TRIBE_Screen_Name
// try 1: natural constructor reconstruction; initial compile needed TEasy_Panel ctor and base inheritance fixes.
// try 2: corrected local class surfaces; compiles but too small 640B vs 737B.
// try 3: /GX probe; unchanged too small 640B.
// try 4: /Oy- probe; too small 608B.
// try 5: /O1 probe; too small 583B.
// try 6: reviewed ctor/base/EH: likely missing real TScreenPanel/TEasy_Panel constructor context and vtable/EH shape.
// try 7: reviewed create_text/list/button argument constants; behavioral order follows packet.
// try 8: reviewed cancel button field stores at +298/+29c; kept.
// try 9: reviewed missing virtual frame setup call for extra button; source lacks exact method surface.
// try 10: left in scratch; scaffold too small, not exact-size.
// BLOCKER: rebuilt .text 640B vs original 737B; missing exact base-constructor/declaration context, EH state, and final virtual button frame setup call shape. Not accepted_drift-safe.

class TPanel { public: void set_help_info(long,long); };
class TScreenPanel: public TPanel { public: TScreenPanel(char*); };
class TEasy_Panel: public TScreenPanel { public: TEasy_Panel(char* s):TScreenPanel(s){} int setup(void*,int,char*,int,int,int,int,int,int,int); void setup_shadow_area(int); void set_ideal_size(long,long); int create_text(TPanel*,void*,int,long,long,long,long,long,long,long,long); int create_list(TPanel*,void*,long,long,long,long,long); int create_auto_scrollbar(void*,TPanel*,long); int create_button(TPanel*,void*,int,long,long,long,long,long,long,long); };
class TRIBE_Screen_Name: public TEasy_Panel { public: char pad[0x478-sizeof(TEasy_Panel)]; TPanel* title; TPanel* name_label; TPanel* list; TPanel* scroll; TPanel* new_btn; TPanel* remove_btn; TPanel* ok_btn; TPanel* cancel_btn; TPanel* extra_btn; int field49c; TRIBE_Screen_Name(); void init_vars(); void init_names(); void load_names(); };
class Game { public: char pad[0x4c]; void* draw; }; extern Game* rge_base_game;
static char s_title[]="Name Selection Screen"; static char s_scr2[]="scr2";

TRIBE_Screen_Name::TRIBE_Screen_Name(): TEasy_Panel(s_title)
{
    *(void**)this=(void*)0x573640;
    init_vars();
    if (!setup(rge_base_game->draw,0,s_scr2,0xC384,1,0,0,0,0,1)) { *(int*)((char*)this+0xd8)=1; return; }
    setup_shadow_area(0);
    set_ideal_size(0x280,0x1e0);
    if (!create_text(this,&title,0x29fe,0x14,0x14,0x258,0x1e,1,1,0,0)) return;
    if (!create_text(this,&name_label,0x29ff,0x3c,0x50,0x8c,0x14,4,0,0,0)) return;
    if (!create_list(this,&list,0x3c,0x64,0x14a,0x12c,0xb)) return;
    if (!create_auto_scrollbar(&scroll,list,0x14)) return;
    scroll->set_help_info(0x765c,-1);
    if (!create_button(this,&new_btn,0x2a00,0,0x190,0x64,0xb4,0x1e,0,0)) return;
    new_btn->set_help_info(0x765d,-1);
    if (!create_button(this,&remove_btn,0x2a01,0,0x190,0x8c,0xb4,0x1e,0,0)) return;
    remove_btn->set_help_info(0x765e,-1);
    if (!create_button(this,&ok_btn,0x0fa1,0,0x46,0x1b8,0xf0,0x1e,0,0)) return;
    ok_btn->set_help_info(0x7531,-1);
    if (!create_button(this,&cancel_btn,0x0fa2,0,0x14a,0x1b8,0xf0,0x1e,0,0)) return;
    cancel_btn->set_help_info(0x7532,-1);
    *(int*)((char*)cancel_btn+0x298)=0x1b;
    *(int*)((char*)cancel_btn+0x29c)=0;
    if (!create_button(this,&extra_btn,0x3ea,0,0,0,0,0,-1,-1)) return;
    init_names();
    load_names();
    field49c=0;
}
