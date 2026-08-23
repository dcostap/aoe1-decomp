// VA: 005414A0 RGE_Game_World::data_load_effects
// FLAGS: /GX required for original SEH/new/ctor cleanup basin
//
// === ACCEPTED_DRIFT ===
// Persistent VC5 tail-merge optimization mismatch, same accepted no-op join-test
// artifact as sibling World/tworld init helpers.
//
// The original (88 bytes, World.cpp:605-607) has the clean ideal form:
//   - EH prologue, operator_new(0xC), test+je null | non-null call ctor | null xor eax
//   - Common tail: load SEH, store effects, restore SEH, pop esi, add esp, ret
//
// All natural source shapes produce one of two undesirable codegen families:
//
// Family A — Sunk-store (23.86% positional diff, first mismatch @50):
//   The store to this->effects is sunk into the non-null branch only. The null branch
//   has a partial/broken epilogue after the ret. Produced by direct new-expression
//   assignment, local+member, pointer-to-member, raw-offset write, volatile member,
//   do/while, empty-if, and all "no explicit else" forms.
//
// Family B — Join test (15.9-18.2% positional diff, first mismatch @67):
//   The store stays common but VC5 inserts a 4-byte test+je/jne at the join point.
//   The 4 bytes overrun the 21 available tail bytes, truncating add_esp/ret.
//   Produced by explicit if/else with stores in both branches, goto-based join,
//   if-with-store-only, and if(e==0){e=0;} patterns.
//
// Best result (72 matching bytes, 14.8% diff): volatile local variable:
//   RGE_Effects* volatile e = new RGE_Effects(filename);
//   this->effects = (RGE_Effects*)e;
//   Eliminates test+je at join but adds 8 bytes of store/read through the param
//   slot (mov [esp+18h],eax / mov edx,[esp+18h] / mov [esi+4Ch],edx).
//
// Attempted axes (all ~17 variants tested):
//   - Direct one-liner, local+member, ptr-to-member, raw offset, member data ptr
//   - Explicit if/else, goto-based join, ternary, assignment-in-condition
//   - Volatile local, volatile field, volatile cast to store target
//   - Empty if/else, if-without-else, if(e==0){e=0;}, if(e){;}
//   - do/while(0), separate-declaration variants
//   - try/catch (71% diff - completely different EH structure)
//   - effects_init (00541C90) has EXACT same 88B pattern and EXACT same issue
//   - Flag variants with /GX+/Oa+/Ow (no improvement on best families)
//
// Accepted drift: the kept common-tail source has the same behavior/register/memory/stack
// effects as the original except for a dead zero-displacement `test eax,eax; jne +0`
// inserted at the join, shifting the epilogue into padding. No source/flag combination
// produced exact match without worse behavioral/codegen changes.
// Full canonical World.cpp context emits the same reviewed drift bytes.

#include "../../include/world_scenario_context.h"

void RGE_Game_World::data_load_effects(char* filename) {
    RGE_Effects* e;
    e = new RGE_Effects(filename);
    if (e == 0) {
        e = 0;
    }
    this->effects = e;
}
