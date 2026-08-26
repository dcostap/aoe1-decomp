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
// 2026-08-02 Luna-513690 bounded pass (10 meaningful probes):
// - Fresh baseline rebuilt at 143B; first mismatch is the merged `movsx edi,word [esp+10h]`
//   versus original `mov edi,[esp+10h]` followed by `movsx eax,di`.
// - Raw/volatile dword aliases, direct parameter use, delayed locals, and separate assignment
//   either moved the load before the save pushes or reproduced the same merged basin.
// - Keeping `int p1` but indexing with `(short)p1` is the best new source basin: it restores
//   `movsx eax,di`, `ECX` master_objects addressing, exact LEA register choices, and the exact
//   helper-call body after the early three-byte drift. Best rebuilt size 146B (original 143B),
//   141 positional differing bytes, 22-byte edit/resync diff (15.07%), first mismatch +3.
// - Typed short local_4 and direct indexed WallHelper dispatch were retained; they emit the
//   expected stack/out-parameter and vslot body in the best basin. No exact match; not drift-safe.
// - Paused after budget: remaining blocker is compiler register/parameter-home allocation at
//   the short formal's first use; next lead is a fresh TU/source-context or ABI-surface review,
//   not another raw alias or parameter-width variant.
// 2026-08-02 Luna513690 exact recovery: replaced the parameter-slot/raw-alias experiment with
// a clean donor-shaped source: named master-object info, selected-object list/local_4, typed
// world command surface, and the natural seven-argument command_build_wall call. Exact 143B.

#include <stddef.h>
#include <stdlib.h>
extern "C" void __cdecl free(void*);

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual void make_new_obj(void*, float, float, float);
    virtual void make_new_master();
    virtual void check_placement(void*, float, float, int*, unsigned char,
                                  unsigned char, unsigned char, unsigned char,
                                  unsigned char, unsigned char);
    virtual void alignment(float*, float*, void*, unsigned char);
    virtual long calc_base_damage_ability(void*);
    virtual void play_command_sound();
    char gap[0x52];
    unsigned char flag52;
};

class RGE_Game_World;

class TRIBE_Command {
public:
    void command_build_wall(RGE_Static_Object** objects, short list_count,
                            short original_param, long p2, long p3, long p4,
                            long p5);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int a, b, c, d;
    long e, f, g;
    unsigned char h;
    unsigned char pad;
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x14];
    RGE_Game_World* world;

    unsigned char get_selected_objects_to_command(
        RGE_Static_Object***, short*, int, int, int, int);
};

class TRIBE_Player : public RGE_Player {
public:
    unsigned char command_make_wall(short, long, long, long, long);
};

class RGE_Game_World {
public:
    char gap[0x58];
    TRIBE_Command* commands;
};

#endif

unsigned char TRIBE_Player::command_make_wall(short type, long p2, long p3,
                                               long p4, long p5)
{
    short local_4;
    RGE_Static_Object** list;

    RGE_Master_Static_Object* info = this->master_objects[type];
    if (info != 0 && info->flag52 != 0) {
        if (get_selected_objects_to_command(&list, &local_4, 4, 4,
                                            -1, -1)) {
            this->master_objects[0x76]->play_command_sound();
            this->world->commands->command_build_wall(list, local_4, type,
                                                       p2, p3, p4, p5);
            free(list);
            return 1;
        }
    }
    return 0;
}
