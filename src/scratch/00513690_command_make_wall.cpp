// VA: 00513690 TRIBE_Player::command_make_wall
// PDB: tplayer.cpp lines 1140-1156 (143 bytes, 59 asm lines)
// Default flags: /nologo /c /O2 /Oy
// No inline asm/hacks.
//
// Prior attempts summary:
// - Many variants before this pass tried int formal, short casts, raw indexed load, register p1,
//   frame struct, dword alias, p1 short/no-p1, self alias, separate masters local, widened
//   TRIBE_Command declarations, volatile/dword aliases, and real TRIBE_Command member call.
// - Best kept state uses real TRIBE_Command member call: exact size 143, edit diff 18.8811%,
//   but broad positional drift from early parameter/register encoding.
// - Key stubborn mismatch: original loads DWORD param_1 into EDI after pushes, then `movsx eax,di`
//   and uses ECX for master_objects base. VC5 for the natural short formal merges to
//   `movsx edi,word [esp+10h]` and uses EAX as master_objects base. Int formal gets a very good
//   body/edit diff but moves the parameter load before saved-register pushes, so not kept.
//
// Current Boss retry (10+ focused probes):
// 1: Revalidated baseline: exact size, 70.6294% positional / 18.8811% edit, first mismatch +3.
// 2: Int formal param_1: edit diff improved to 13.9860% and LEA regs/body very close, but prologue
//    becomes `push ecx; mov eax,[esp+8]; push esi; ... push edi`, first mismatch +1.
// 3: Int formal plus `self=this` alias: no change from int-formal prologue family.
// 4: Short formal with `int p1 = *(int*)&param_1` and `(short)p1` index: worsened to first mismatch +1.
// 5: Same dword alias without short cast in index: still worse (82.5% positional / 19.58% edit).
// 6: get_selected_objects second parameter declared `void*` and passed `&local_4`: no change.
// 7: Moved `local_4` declaration before p1: no change.
// 8: Used int `list_num` local/out parameter instead of `local_4`: no change.
// 9: Widened command_build_wall original_param to int: no change.
// 10: Named/register `masters` local: no change.
// 11: Removed p1 local and used `(int)param_1` directly: worsened to first mismatch +1.
// 12: Used `short p1 = param_1`: worsened to first mismatch +1.
// GIVEUP: no exact match. Not proposing accepted_drift; remaining differences are systematic
// prologue/register-allocation and argument-setup encoding, not a tightly localized equivalent drift.
// 2026-05-26 Boss retry: 10 more honest probes. Tried int formal with/without short cast,
// short formal plus dword/word parameter aliases, stack-store p1 temp, register/volatile p1,
// named masters local before p1, int local_4/list_count, widened command_build_wall args,
// and direct dword reload of param_1 for the wall arg. Best remains the prior kept short-formal
// baseline (143B, 70.6294% positional / 18.8811% edit, first mismatch +3). Int-formal body
// has lower edit diff (13.9860%) but wrong prologue (`mov eax,[esp+8]` before saved pushes).
// Not accepted_drift: drift starts in prologue/register allocation and affects argument setup.

#include <stddef.h>
#include <stdlib.h>
extern "C" void __cdecl free(void*);
class RGE_Master_Static_Object; class RGE_Game_World; class RGE_Static_Object; class TRIBE_Command { public: void command_build_wall(RGE_Static_Object** objects, short list_count, short original_param, long p2,long p3,long p4,long p5); };
class RGE_Player { public: void* vtable_ptr; int a,b,c,d; long e,f,g; unsigned char h; unsigned char pad; short master_object_num; RGE_Master_Static_Object** master_objects; char gap_28[0x14]; RGE_Game_World* world; unsigned char get_selected_objects_to_command(RGE_Static_Object***, short*, int,int,int,int); };
class TRIBE_Player: public RGE_Player { public: unsigned char command_make_wall(short,long,long,long,long); };
class __declspec(novtable) WallHelper { public: virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0; virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0; virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void clear_wall_data()=0; };
unsigned char TRIBE_Player::command_make_wall(short param_1,long param_2,long param_3,long param_4,long param_5)
{
    short list_num;
    int p1 = param_1;
    RGE_Master_Static_Object* obj = this->master_objects[p1];
    if (obj && *(char*)((char*)obj + 0x52)) {
        void* local_4;
        if (this->get_selected_objects_to_command((RGE_Static_Object***)&param_1, (short*)&local_4, 4, 4, -1, -1)) {
            WallHelper* helper = *(WallHelper**)((char*)this->master_objects + 0x1D8);
            helper->clear_wall_data();
            TRIBE_Command* cmd = *(TRIBE_Command**)((char*)this->world + 0x58);
            cmd->command_build_wall((RGE_Static_Object**)(long)param_1, *(short*)&local_4, (short)p1, param_2,param_3,param_4,param_5);
            free((void*)(long)param_1);
            return 1;
        }
    }
    return 0;
}
