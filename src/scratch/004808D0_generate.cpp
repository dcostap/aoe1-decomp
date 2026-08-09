// VA: 004808D0, RGE_Random_Map_Module::generate, 269 bytes
// Source: rmm_base.cpp lines 106-149
// FLAGS: default
//
// Attempt log:
// - v1: Direct field access for schedule, separate search variable. 240 bytes.
//   push ecx / pop ecx instead of sub esp, 8 / add esp, 8.
//   Get_schedule inlined by VC5 (reads this->schedule at +0x1C directly).
//   Different register allocation (edi=sorted, edx=current vs original ebx=sorted, edi=current).
// - v2: get_schedule as extern "C" __fastcall (no body to prevent inlining).
//   VC5 still inlines because it sees the function just returns this->schedule.
// - v3: get_schedule through function pointer. Indirect call, not matching direct call.
// - v4: Different control flow variants for sort comparison. Same 240 bytes.
// - v5 (current): restore the period class surface: module entries are typed
//   RGE_Random_Map_Module pointers, get_schedule is a real member call, and
//   generate is virtual.  The previous void*/extern-C surface changed both
//   the four direct call relocations and the virtual-call load sequence.
// - v6: use the direct comparison expressions suggested by the original
//   right-to-left call order instead of two named float temporaries; the
//   compiler's temporary should be the one observed at [esp+10h].
// - v7: make the loop's saved successor a function-scope local, alongside the
//   sorted/current/search ownership pointers, rather than a block local.
//   Original asm carries next in EBP across insertion and keeps only the
//   explicit this home plus the FPU temporary on the stack.
// - v9: initialize sorted at its declaration, matching the natural source
//   idiom for the zero seed rather than a separate statement.
// - v10: rewrite the outer insertion pass as a natural for-loop with the
//   saved successor in the increment expression; the source line map groups
//   initialization, successor capture, and advancement under the same loop.
// - v11: declaration-order and register-qualifier labs were codegen-neutral;
//   all 20 variants stayed at 300 bytes with the same 0xC frame.
//
// What works:
// - Linked list insertion sort (descending by schedule value)
// - FPU comparisons for schedule ordering
// - Logging + module execution iteration
// - Multiple return paths (return 0 on module failure, return 1 on success/empty)
// - The overall algorithm and control flow matches
//
// Best current reconstruction: 300 bytes, 0xC frame, all 9 ordered calls and
// the direct FPU compare topology aligned; strict diff is 261 bytes. The
// remaining structural gap is the VC5 local/register basin: original uses
// EBX=sorted, EDI=current, EBP=next, ESI=this/search with two stack homes,
// while this natural spelling uses EBP=sorted, spills next, and reserves an
// extra 4-byte frame slot. Typed member calls fixed the prior call-target
// mismatch; the remaining virtual-call and logging relocations are equivalent
// direct/indirect sites under the checker.
// Paused after the default 10 meaningful hypotheses; next lead is a fresh
// period-plausible declaration/context reconstruction, not more register
// qualifiers or declaration-order permutations.

#include <stddef.h>

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(const char* file, int line);

class RGE_Random_Map_Module;

class RGE_Random_Map_Module_List {
public:
    RGE_Random_Map_Module* module;       // +0x00
    RGE_Random_Map_Module_List* next;   // +0x04
};

class RGE_Random_Map_Module {
public:
    char gap_04[4];                     // +0x04
    RGE_Random_Map_Module_List* list;   // +0x08

    virtual uchar generate();

protected:
    float get_schedule();
};

uchar RGE_Random_Map_Module::generate()
{
    RGE_Random_Map_Module_List* sorted = 0;
    RGE_Random_Map_Module_List* next;
    RGE_Random_Map_Module_List* current;
    RGE_Random_Map_Module_List* search;

    for (current = this->list; current != 0; current = next) {
        next = current->next;

        if (sorted != 0) {
            if (current->module->get_schedule() >= sorted->module->get_schedule()) {
                search = sorted;
                while (search->next != 0) {
                    if (current->module->get_schedule() < search->next->module->get_schedule())
                        break;
                    search = search->next;
                }
                current->next = search->next;
                search->next = current;
            } else {
                current->next = sorted;
                sorted = current;
            }
        } else {
            current->next = sorted;
            sorted = current;
        }
    }

    this->list = sorted;
    debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x8A);

    extern void* g_LogObj;
    extern void __fastcall Log(void* self, int, const char* msg, int val);
    Log(*(void**)0x62C4FC, 0, "RGE_RANDOM_MAP_MODULE::map start", 0);

    current = this->list;
    while (current != 0) {
        if (current->module->generate() == 0)
            return 0;

        debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x8F);
        Log(*(void**)0x62C4FC, 0, "RGE_RANDOM_MAP_MODULE::module completed with ret:", 0);
        current = current->next;
    }

    return 1;
}
