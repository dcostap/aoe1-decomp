// VA: 0050A1D0 TRIBE_Command::do_command_game
// Source: tcommand.cpp lines 531-665
// Attempt log:
// 1: broad natural switch reconstruction from packet; models simple command cases and restart/new-game cleanup path approximately; compiles too small (640 vs 661).
// 2: tried /GX because original has SEH/EH prologue; no size/prologue change in this harness, flag removed.
// 3: added explicit large temp char buffer size 264 to try original 0x108 local frame; object size unchanged, compiler optimized frame differently.
// 4: made temp buffer touched to force local frame materialization; object size unchanged.
// 5: tried /O1 /Oy flag probe; object shrank to 559 and failed configured size, flag removed.
// 6: reviewed original: true function has compiler EH/SEH registration around a local dialog object construction; current fake ctor surface cannot trigger same cleanup state.
// 7: simple command cases modeled but broad restart/new-game cleanup block call surface still approximate.
// 8: switch dispatch range/type likely correct, but case numbering/call declarations are still speculative.
// 9: final state remains too small (640 vs 661); no accepted drift possible.
// 10: left in scratch pending real type/ctor surfaces for dialog/status objects and exact EH-producing source shape.

struct TRIBE_Command_Game { unsigned char opcode0; unsigned char type; short a; short b; char gap6[2]; int c; short d; };

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern "C" int __cdecl ftol_float(float);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" void __cdecl free_mem(void*);
extern "C" void __cdecl some_global_423030();
extern "C" void __cdecl some_global_53D200();

#define g_game (*(Game**)0x0062C574)
#define g_flag_62C564 (*(int*)0x0062C564)
#define g_ptr_62C4D0 (*(int*)0x0062C4D0)
#define g_actionFile (*(void**)0x0062C4CC)
#define g_ptr_886C58 (*(void**)0x00886C58)
#define g_ptr_62E638 (*(void**)0x0062E638)
#define g_obj_62E870 (*(Dialog*)0x0062E870)
#define g_obj_62C4C0 (*(Helper**)0x0062C4C0)

class Player { public: int computerPlayer(); void m470BB0(int); void m470BE0(short,int); void m4705E0(); virtual void v00(); char pad[0x74]; virtual void vf78(short,int,int); };
class PlayerSlot { public: char gap[0x40]; Player** players; char gap2[0x38]; short current; };
class World { public: virtual void v00(); char gap[0x3C]; virtual void vf40(int,int,int,int,int); };
class Game { public: char gap0[0x48]; void* screen; char gap1[0x95C]; int field_9A8; void m521620(int); void m524640(char*); void m526DC0(); void m422FF0(); void m420360(); };
class Dialog { public: void m463E60(const char*, int); int m463D00(); void m464060(const char*); };
class Helper { public: int m42CAF0(); };
class Screen { public: void m443CB0(int); };
class Thing { public: int m468340(); void m469EE0(int,int,int,int); };

class TRIBE_Command {
public:
    virtual void v00();
    char gap[4];
    PlayerSlot* slot;
    void do_command_game(TRIBE_Command_Game* cmd);
};

void TRIBE_Command::do_command_game(TRIBE_Command_Game* cmd)
{
    char buf[264];
    buf[0] = 0;
    switch (cmd->type) {
    case 0:
        this->slot->players[cmd->a]->m470BB0(cmd->b & 0xff);
        break;
    case 1: {
        int x = ftol_float(*(float*)&cmd->c);
        this->slot->players[cmd->a]->m470BE0(cmd->b, x);
        g_game->m521620(1);
        break;
    }
    case 2:
        g_game->m524640((char*)cmd->c);
        break;
    case 3: {
        g_flag_62C564 = 1;
        void* p = operator new(0x47c);
        if (p) { /* dialog ctor omitted */ }
        g_obj_62E870.m463E60((const char*)0x00588BD0, 0);
        g_game->m521620(1);
        if (g_ptr_62C4D0) {
            some_global_423030();
            some_global_53D200();
            if (g_actionFile) { free_mem(g_actionFile); g_actionFile = 0; }
            if (g_ptr_886C58) { free_mem(g_ptr_886C58); g_ptr_886C58 = 0; }
            if (g_ptr_62E638) { free_mem(g_ptr_62E638); g_ptr_62E638 = 0; }
        }
        sprintf(buf, (const char*)0x00588BC0, g_obj_62C4C0->m42CAF0());
        g_game->m524640(buf);
        this->slot->players[this->slot->current]->m4705E0();
        g_game->m526DC0();
        {
            int t = g_obj_62E870.m463D00();
            if (t) {
                ((Screen*)g_game->screen)->m443CB0(((Thing*)t)->m468340());
                g_game->m422FF0();
                g_game->m420360();
                ((Thing*)t)->m469EE0(0x966,0,0x1c2,100);
            }
        }
        g_obj_62E870.m464060((const char*)0x00588BD0);
        break;
    }
    case 4:
        this->slot->players[cmd->a]->vf78(cmd->b, cmd->c, 0);
        break;
    case 5:
        g_game->field_9A8 = cmd->a;
        break;
    case 6:
        this->slot->players[0]->m470BE0(cmd->a, cmd->b & 0xff);
        break;
    case 7:
        // notification through player owner UI
        break;
    default:
        break;
    }
}
