// 00480EC0 RGE_Random_Map_Module::randomize_stack (rmm_base.cpp:473-506)
// Attempt log:
// - Baseline retained the natural linked-list phases, but all local-node
//   addresses were one Map_Stack field below the original and the frame was
//   four bytes short.
// - Offset-view experiments using the y/prev fields improved byte metrics but
//   were compiler-steering artifacts, not plausible owning source; main-agent
//   audit restored ordinary Map_Stack elements and named collection cursors.
// - Directly passing param_1->next, a named/register init counter, an unused
//   volatile pad, and a 9-variant counter/outer-loop lab were codegen-neutral.
// - Final normalized source remains exact-size with all five calls aligned,
//   but returns to structural reconstruction (147-byte diff, 73.33% shape);
//   the frame is still 0x964 versus 0x968. Next work should recover the real
//   local declaration/layout context rather than reintroduce offset views.
// - A typed diagnostic state aggregate (outer count, collection offset, then
//   Map_Stack[100]) recovered the 0x968 frame and 95.12% shape/44-byte diff;
//   it was restored because PDB ownership presents separate locals and the
//   aggregate is not established as original source.
// - Moving declarations, naming bucket/node locals, inlining the bucket index,
//   and mirroring the stable same-TU module fields were codegen-neutral around
//   that aggregate. Remaining lead is a plausible separate-local layout that
//   preserves the arithmetic-before-node reload and callee-save coloring.
// - Main-agent audit replaced cross-element field-pointer stepping with
//   ordinary paired array indexing; `sub_stacks` remains the canonical owner.
// - Fresh pass: reusing the initialization cursor as a byte offset in the
//   ordinary array duplicated the prior offset-view basin and was restored.
// - A narrower diagnostic aggregate (`offset` plus `Map_Stack[100]`) recovered
//   the 0x968 frame, exact size, and 95.12% shape/44-byte diff, but selected
//   inverse EBX/EDI colors and hoisted the list-head reload; it is not retained.
// - Narrow volatile reread, explicit module alias, reference-parameter ABI,
//   scalar declaration order, and the PDB `char*` debug_rand declaration were
//   codegen-neutral. Two focused labs collapsed to duplicate groups; no exact.
// - Final fresh pass restores this clean named-array reconstruction; remaining
//   lead is the original local declaration/context that selects target register
//   coloring and delays the second `param_1->next` load.
// - wave21-01: a real offset local with a natural paired index loop was
//   codegen-neutral (frame 0x964, diff 145).
// - wave21-02: the proven polymorphic module field/vtable surface and donor
//   Windows/global headers were codegen-neutral around this function.
// - wave21-03: the binary-supported y/prev cursor overlay recovered exact size
//   and 91.46% shape (diff 47), but its 0x964 frame and decompiler-shaped view
//   are not retained as living source.
// - wave21-05: a named offset plus real Map_Stack[100] local state recovered
//   the 0x968 frame and 95.12% shape (diff 44); it remains diagnostic because
//   the local aggregate is not established as original ownership. Restored
//   canonical source; next lead is arithmetic-before-node reload and register
//   coloring, not synthetic padding.
// - sa854558ad_r1: binary-supported y/prev overlay plus a trailing scalar
//   reached exact frame/size and diff 44, but retained inverse EBX/EDI colors;
//   pointer scope/type, receiver aliases, declaration order, and an 8-variant
//   field-order lab were codegen-neutral. Restored the canonical array source.
// - sa854558ad_r1 final: the PDB char* debug_rand surface was retained in the
//   clean source; it did not move emitted code. Remaining gap is structural
//   receiver/cursor coloring and arithmetic-before-node scheduling.
// - orch-00480EC0-L: separate offset/outer locals with binary y-bucket views
//   did not improve the canonical frame or receiver coloring.
// - orch-00480EC0-L: typed aggregate/overlap source reached exact size and a
//   44-byte diff, but retained inverse EBX/EDI colors; restored as diagnostic.
// - orch-00480EC0-L: inline random bucket evaluation moved the block farther;
//   direct param_1->next and an explicit init cursor were codegen duplicates.
// - orch-00480EC0-L: adding donor-era <stdlib.h> context was codegen-neutral.
// - orch-00480EC0-L final: clean named Map_Stack[100] source remains in scratch;
//   unresolved lead is real local layout plus arithmetic-before-node scheduling.
// - orch2-480EC0-overlay: test the binary-backed typed overlap: sub_stacks[0].x
//   owns the collection byte offset, each sub_stacks[i].y is a bucket sentinel,
//   and sub_stacks[0].prev starts the paired collection cursors.
//   This restores the 0x968 frame and 237-byte size, reaching diff 44 / 95.12%
//   shape. The remaining drift is receiver/cursor coloring and random-call
//   scheduling, so keep this as the best binary-backed reconstruction.
// - close-480EC0-r1: rmm_base C++ debug_rand linkage and an explicit node reload
//   after bucket arithmetic were codegen-neutral; no ABI or scheduling gain.
// - close-480EC0-r1: canonical Map_Stack array ownership and typed pair cursors
//   widened the drift to 145 and reduced the frame to 0x964; restored the
//   canonical source below instead of retaining the binary overlay.
// - tu-rmmbase-480EC0: dossier and same-TU donors confirm the five-call set and
//   Map_Stack ownership. The clean typed array remains the best source model.
//   The binary field-pointer schedule would require the rejected overlay.
// - shardE-480EC0 wave: the typed overlap/aggregate recovered exact frame and
//   size with diff 44, but retained inverse receiver colors and random-call
//   scheduling. Separate cursor declarations, receiver alias, counter types,
//   and declaration order were duplicate or worse. Restored the clean named
//   Map_Stack array reconstruction; no evidence-backed exact lead remains.
// - sa9675-r1-480EC0: a typed diagnostic state with outer, byte offset, and
//   Map_Stack[100], plus `int r = (debug_rand(...) * 100) / 0x7FFF`, reached
//   exact size, CFG, and 100% block shape with a 10-byte diff. The remaining
//   bytes are only inverse EBX/EDI receiver, counter, and cursor colors.
//   Inline random evaluation, pending-pointer reloads, declaration order,
//   self aliases, and the init_stack reference ABI did not improve it.
//   Restored the clean named-array source because the aggregate is not proven
//   original ownership; the exact-size result is diagnostic evidence.
// - sa-2ff22d1e-r1: Reproduced that exact-size basin with an outer/offset/state
//   aggregate and a direct base cursor. The residual stayed at 10 bytes and
//   was a pure EBX/EDI recolor. Separate locals did not preserve the frame.
//   Restored this clean named-array source.
// - sa-5f352e47-r1: Natural typed member references with an outer/offset/state
//   aggregate reached 237 bytes, the 0x968 frame, and diff 98 / 87.06% shape.
//   Separate scalar locals reached diff 144. Both were diagnostic; the
//   aggregate and member-reference aliases are not proven original ownership.
//   Restored this clean Map_Stack array source and did not use raw cursors.
// - sa-f86eab16-r1: Natural typed prev-field cursors with a separate offset
//   scalar reached diff 142, but stayed in the 0x964 frame basin. A typed end
//   pointer, prev-only field spelling, declaration-order swap, and separate
//   outer/offset scalars were worse or codegen duplicates. The target's
//   persisted byte offset and +0x04 bucket receiver remain unrecoverable by a
//   policy-valid natural Map_Stack array source; restored this clean source.

extern int __cdecl debug_rand(char* file, int line);

struct Map_Stack {
    long x;           // +0x00
    long y;           // +0x04
    float cost;       // +0x08
    float tot_cost;   // +0x0C
    Map_Stack* next;  // +0x10
    Map_Stack* prev;  // +0x14
};

class RGE_Random_Map_Module {
public:
    void init_stack(Map_Stack* stack);
    void add_stack_node(Map_Stack* stack, Map_Stack* node);
    void randomize_stack(Map_Stack* param_1);
};

void RGE_Random_Map_Module::randomize_stack(Map_Stack* param_1)
{
    Map_Stack sub_stacks[100];
    int i;

    for (i = 0; i < 100; i++) {
        init_stack(&sub_stacks[i]);
    }

    for (int outer = 2; outer != 0; outer--) {
        while (param_1->next != 0) {
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x1E8);
            r = (r * 100) / 0x7FFF;
            Map_Stack* node = param_1->next;
            add_stack_node(&sub_stacks[r], node);
        }

        int stack_index = 0;
        while (stack_index < 100) {
            Map_Stack* first = &sub_stacks[stack_index];
            Map_Stack* second = &sub_stacks[stack_index + 1];

            while (first->next != 0 || second->next != 0) {
                if (first->next != 0) {
                    add_stack_node(param_1, first->next);
                }
                if (second->next != 0) {
                    add_stack_node(param_1, second->next);
                }
            }

            stack_index += 2;
        }
    }
}
