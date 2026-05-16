// Attempt log for 004923C0 TribeMPCreateDialog::action
// try 1: natural reconstruction from packet/decompiler, /GX for new screen path; exact size but broad mismatch from offset 25.
// try 2: /Oy- + /GX probe; exact size but worse from offset 0.
// try 3: /O1 + /GX probe; too small 643B.
// try 4: reviewed button dispatch predicates; source follows observed action cases.
// try 5: reviewed currentLine strlen/registry call; high-level RegSetAscii likely wrong scheduling.
// try 6: reviewed TCPIP GUID compare; source loop differs from original rep cmpsb/local copy.
// try 7: reviewed CreateMultiplayerGame success/failure branch; broad structure plausible.
// try 8: reviewed new TribeMPSetupScreen EH state; local surface incomplete.
// try 9: reviewed fallback base action; declaration likely approximate.
// try 10: left in scratch; exact-size but broad mismatch.
// BLOCKER: exact 790B size, but source is behavioral scaffold with broad mismatch from early parameter/EH/local layout and later registry/GUID/new-screen scheduling. Not accepted_drift-safe.

typedef unsigned long ulong;
class TPanel { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void v28(); void set_help_info(long,long); };
class TEditPanel: public TPanel { public: int is_blank(); char* currentLine(); };
class TEasy_Panel: public TPanel { public: void popupOKDialog(long,int,long,int); long action(TPanel*,long,ulong,ulong); };
class TribeMPSetupScreen { public: TribeMPSetupScreen(); };
class TribeMPCreateDialog: public TEasy_Panel { public: char pad20[0x20-sizeof(TEasy_Panel)]; TPanel** pp; char pad24[0x40-0x24]; TEasy_Panel* parent; char pad44[0x498-0x44]; TEditPanel* edit; TPanel* cancel; TPanel* ok; long action(TPanel*,long,ulong,ulong); void set_curr_child(TPanel*); };
class BaseGame { public: void disable_input(); void draw_window(); void show_status_message(int,char*); }; extern BaseGame* rge_base_game;
class Regs { public: int RegSetAscii(int,char*,char*,int); }; extern Regs* Reg;
class Comm { public: char pad[0x12dc]; char guid[16]; int SetGameTitle(char*); int CreateMultiplayerGame(); }; extern Comm* comm;
class Log { public: void LogMsg(char*); }; extern Log* L;
class PanelSystem { public: int setCurrentPanel(char*,int); int destroyPanel(char*); }; extern PanelSystem panel_system;
extern "C" int (__stdcall* const WinExec)(char*,int);
extern "C" void* (__stdcall* const FindWindowA)(char*,char*);
extern "C" int (__stdcall* const SendMessageA)(void*,int,int,int);
static char tcpip[16];

long TribeMPCreateDialog::action(TPanel* panel,long a2,ulong a3,ulong a4)
{
    if (panel) {
        if ((panel==ok && a2==1) || (panel==edit && a2==0)) {
            if (edit->is_blank()) { set_curr_child(edit); return 1; }
            rge_base_game->disable_input();
            char* line=edit->currentLine(); Reg->RegSetAscii(1,"Default Age Of Empires MP Gamename",line,0);
            comm->SetGameTitle(edit->currentLine());
            L->LogMsg("$$$ CALLING CreateMultiplayerGame");
            panel_system.setCurrentPanel("Join Screen",0); rge_base_game->draw_window();
            int status = 0x4c2; for(int i=0;i<16;i++){ if(comm->guid[i]!=tcpip[i]) { status=0x4c2; goto st; }} status=0x4c3; st:
            rge_base_game->show_status_message(status,"scr3"); rge_base_game->draw_window(); WinExec("data\\closedpw.exe",0);
            TPanel* p=*pp; if(*(char*)((char*)p+0x478)==2 && *(char*)((char*)p+0x479)==2){ TPanel* q=*(TPanel**)((char*)p+0x18); q->v28(); }
            for(int j=0;j<9;j++) ((int*)((char*)comm+0x13c0))[j]=0;
            int okc=comm->CreateMultiplayerGame(); L->LogMsg("$$$ RETURNED FROM CreateMultiplayerGame");
            void* w=FindWindowA("closedpw","closedpw"); if(w) SendMessageA(w,0x10,0,0);
            if(okc){ TribeMPSetupScreen* s=new TribeMPSetupScreen; panel_system.setCurrentPanel("MP Setup Screen",0); panel_system.destroyPanel("Status Screen"); panel_system.destroyPanel("Create Dialog"); panel_system.destroyPanel("Join Screen"); return 1; }
            TEasy_Panel* parent=this->parent; panel_system.destroyPanel("Create Dialog"); panel_system.setCurrentPanel("Join Screen",0); panel_system.destroyPanel("Status Screen"); parent->popupOKDialog(0x25ad,0,0x1c2,0x64); return 1;
        }
        if ((panel==cancel && a2==1) || (panel==edit && a2==1)) { panel_system.setCurrentPanel("Join Screen",0); panel_system.destroyPanel("Create Dialog"); return 1; }
    }
    return TEasy_Panel::action(panel,a2,a3,a4);
}
