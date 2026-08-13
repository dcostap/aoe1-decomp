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
// - New pass: a common fallback insertion block plus a named search successor
//   reduced the structural size to 274-275 bytes; the completed module layout
//   was neutral.  The final cdecl explicit-self Log surface produced 276 bytes,
//   75.47% shape, and 248 strict differing bytes.
// - Final source retains the natural typed list ownership and cdecl Log ABI;
//   it remains scratch because the frame is 0xC versus 0x8 and the compiler
//   colors the saved successor/search roles opposite the oracle.  Next lead is
//   a source-plausible lifetime reconstruction that yields EBP=next, ESI=search
//   and two stack homes, not more register qualifiers or blind variants.
// - This pass confirmed the variadic TDebuggingLog::Log member surface and
//   tested direct successor expressions, scoped search/search_next locals,
//   declaration order, guarded do/while, and a persistent outer next cursor.
// - The persistent next/current cursor is the best natural reconstruction:
//   274 bytes, 0xC frame, 78.10% shape, 240 strict differing bytes.  It is
//   retained because it mirrors the decompiler's pRVar7/pRVar3 lifetimes;
//   remaining gap is the real source context that removes one stack slot and
//   colors EBP as the successor while keeping ESI as the insertion search.
//
// Fresh bounded continuation (probes 6-10 for this claim):
// - Aligned the PDB-proven char* surfaces for debug_rand and variadic Log and
//   restored the canonical module field order.  The Log relocation became the
//   non-const member symbol, but emitted structure remained the 0xC-frame,
//   273-byte basin (243 strict differing bytes); retained as the ABI-correct
//   source surface.
// - A six-variant sort-shape lab (persistent cursor, top-tested cursor,
//   direct successor, do/while, and nested insertion forms) produced no
//   size/frame/call-set eligible candidate; the closest groups stayed in the
//   same nonexact basins.
// - A combined-predicate direct-successor while form improved shape to
//   86.24% and exact-block coverage to 49.04%, but grew to 289 bytes and 249
//   strict differing bytes; rolled back as codegen diagnostic evidence.
// - A pointer-to-pointer `link = &search->next` traversal was codegen
//   identical to the preceding direct form; no new lead.
// - The final source uses one outer cursor with a block-scoped current node,
//   matching the natural pRVar7/pRVar3 ownership.  It emits the same retained
//   273-byte result (0xC frame, 78.10% shape, 243 strict differing bytes).
//   The unresolved blocker is still VC5's local/register basin: the oracle
//   has EBX=sorted, EDI=current, EBP=successor, ESI=this/search and two stack
//   homes, while the clean rebuild keeps an extra slot and opposite colors.
// - Retry with the corrected typed class, nonvirtual destructor context,
//   schedule field, and char* logging ABI: a function-scope next with
//   current=next for-loop topology grew to 302 bytes and kept a 0xC frame;
//   rolled back.  The block-scoped current=next spelling emitted the same
//   273-byte code as the clean source, so no new register-home lead remains.
// - A scoped for-loop current with function-scope next improved shape to
//   86.24% and exact-block coverage to 49.04%, but grew to 289 bytes with a
//   0xC frame; rolled back as the same structural basin as the prior direct
//   successor retry.
// - tu-rmmbase-4808D0: dossier and same-TU donors confirm the nine calls and
//   typed list ABI. No new natural source lead removes the extra 0xC-frame
//   home; the clean list sort remains the retained reconstruction.
// - Shard E continuation: direct search->next, persistent current/next,
//   function-scope pointer declarations, and shared-tail control flow were
//   tested and rolled back. They stayed nonexact or worsened structural size.
//   Final validation restores the clean typed list sort; blocker remains the
//   0xC VC5 frame and opposite local/register basin versus the 0x8 oracle.

#include <stddef.h>

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(char* file, int line);

class TDebuggingLog {
public:
    void Log(char* msg, ...);
};

extern TDebuggingLog* L;

class RGE_Random_Map_Module;

class RGE_Random_Map_Module_List {
public:
    RGE_Random_Map_Module* module;       // +0x00
    RGE_Random_Map_Module_List* next;   // +0x04
};

class RGE_Random_Map_Module {
public:
    // The base vtable's slot zero is generate; the rmm_base destructor is a
    // nonvirtual helper despite its destructor-shaped symbol.
    virtual uchar generate();

    RGE_Random_Map_Module* parent;      // +0x04
    RGE_Random_Map_Module_List* list;   // +0x08
    void* map;                           // +0x0C
    void* map_row_offset;                // +0x10
    int map_width;                       // +0x14
    int map_height;                      // +0x18
    float schedule;                      // +0x1C
    unsigned char* search_map;           // +0x20
    unsigned char** search_map_rows;     // +0x24
    void* stack_array;                    // +0x28
    void* stack_offsets;                  // +0x2C

protected:
    float get_schedule();
};

uchar RGE_Random_Map_Module::generate()
{
    RGE_Random_Map_Module_List* sorted = 0;
    RGE_Random_Map_Module_List* cursor;

    cursor = this->list;
    for (;;) {
        RGE_Random_Map_Module_List* current = cursor;
        if (current == 0)
            break;

        cursor = current->next;
        if (sorted != 0) {
            if (current->module->get_schedule() >= sorted->module->get_schedule()) {
                RGE_Random_Map_Module_List* search = sorted;
                {
                    RGE_Random_Map_Module_List* search_next;
                    while ((search_next = search->next) != 0) {
                        if (current->module->get_schedule() < search_next->module->get_schedule())
                            break;
                        search = search_next;
                    }
                }
                current->next = search->next;
                search->next = current;
                continue;
            }
        }

        current->next = sorted;
        sorted = current;
    }

    this->list = sorted;
    L->Log("RGE_RANDOM_MAP_MODULE::map start",
           debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x8A));

    cursor = this->list;
    if (cursor == 0)
        return 1;

    while (cursor != 0) {
        if (cursor->module->generate() == 0)
            return 0;

        L->Log("RGE_RANDOM_MAP_MODULE::module completed with ret:",
               debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x8F));
        cursor = cursor->next;
    }

    return 1;
}
