// RGE_Victory_Conditions::condition_description
// VA: 00532CC0
// Attempt log:
// - Baseline: reconstructed the binary-supported switch, typed entry/object/player/master
//   ownership, ten period strings, float-to-double varargs, and the getstring output slot.
//   Direct source was 532 bytes versus 479; the initial byte clear also missed the observed
//   whole-dword zero.
// - Whole-dword clear probe improved the direct source to 435 differing bytes; the PDB-sized
//   200-byte temporary still left a 0xC8 frame versus the original 0xCC.
// - A diagnostic 204-byte temporary recovered the original frame and 71.71% exact-block
//   coverage, but conflicts with the PDB's char[200] local and was not retained.
// - An explicit shared two-argument sprintf tail for cases 1/9 recovered exact size, call
//   count, and 100% call-site alignment (394 differing bytes); its generic format/argument
//   locals are compiler-steering scaffolding, so it was restored out of the living source.
// - Case-local destination/name/id declarations, return-type context, and typed shared-tail
//   target/index locals were codegen duplicates or worse.
// - Paused after 10 hypotheses: canonical direct switch source retained; remaining structural
//   gap is VC5 tail merging plus the jump-table/code-layout basin, with no call/ABI/layout
//   behavior defect. Best diagnostic checkpoint is probe-006-control-flow (394 bytes).
// - Main-agent audit removed the diagnostic +4 stack window and pointer-overlaid output slot.
//   The living source uses the declared text buffer and a separate result pointer.
// - New worker initialized a separate result pointer before the 200-byte buffer;
//   this recovered the original 0xCC frame and natural temp base, but the direct
//   switch still has one extra sprintf call from VC5 tail layout (433 bytes).
// - A shared text pointer was codegen-neutral. A behavior-correct common case-1/
//   case-9 tail using long varargs recovered exact size/frame/call count (394 bytes;
//   393 with proven absolute string addresses), but pointer-to-long argument
//   scaffolding is not retained as living source. Argument declaration reordering
//   was a duplicate; restore the clean typed direct switch.
// - Legacy sprintf format constness and return type were unchanged codegen.
// - &temp[0], an inlined two-argument helper, and a shared format pointer were
//   unchanged codegen. The clean typed direct switch remains the best source model.
// - Fresh worker evidence confirms case 6 pushes count before number; the source
//   now uses that binary-supported argument order. A stdio.h context was worse.
//   The remaining gap is the extra direct sprintf call for the two-argument
//   case-1/case-9 tail; no natural source form recovered that tail.
// - This claim re-established canonical ownership from the target dossier and
//   exact victory.cpp donors: the virtual member, entry offsets, player master
//   array, object master, and short player id agree with the surrounding exact
//   functions. No ABI or layout conflict was found.
// - A real union shared tail for cases 1 and 9 recovered exact size/frame and
//   all eight call sites (394 bytes; reversed case-1 assignments 392 bytes).
//   Reversing case-9 assignments reached 389 bytes and 96.05% shape, but the
//   generic union/format locals changed the proven argument setup. An argument
//   array, declaration-order change, int/long change, non-const format, and
//   direct all-long casts were duplicate or worse. These are diagnostic only.
// - Restored the natural direct switch. Final validation remains a 433-byte
//   mismatch with one extra direct sprintf; the best 389-byte shared-tail
//   probe is not retained as canonical source.
// - Exact translation-unit finish: the real earlier victory.cpp owner at
//   00532C50 selects the original switch-tail layout. The shared entry and
//   condition declarations keep both owners in one object. The unchanged
//   direct switch then matches all 479 bytes and eight calls. Target-only
//   compilation emits the prior extra-sprintf basin.
// - Exact-finish walkback: removing the earlier 00532C50 owner is not a valid
//   TU because the owner manifest requires that source exactly once. The
//   owner is therefore required context, not target-only scaffolding.
// - Exact-finish reduction: removing these duplicate local declarations and
//   using the reviewed shared victory header kept 479 bytes, the 0xCC frame,
//   and all eight ordered calls. This is the retained source form.

#include "../../include/victory_description_context.h"

char* RGE_Victory_Conditions::condition_description(RGE_Victory_Entry* entry) {
    char* description = 0;
    char temp[200];

    switch (entry->command) {
    case 0:
        sprintf(temp, "Capture %s", entry->this_obj->master_obj->name);
        break;
    case 1:
        sprintf(temp, "Create %d %s", entry->number,
            entry->target_player->master_objects[entry->obj_type]->name);
        break;
    case 8:
        sprintf(temp, "Create %d %s in area (%f, %f) - (%f, %f)",
            entry->number,
            entry->target_player->master_objects[entry->obj_type]->name,
            (double)entry->x0, (double)entry->y0,
            (double)entry->x1, (double)entry->y1);
        break;
    case 2:
        sprintf(temp, "Destroy %s", entry->this_obj->master_obj->name);
        break;
    case 3:
        sprintf(temp, "Destroy %d %s of player %d", entry->number,
            entry->target_player->master_objects[entry->obj_type]->name,
            entry->target_player->id);
        break;
    case 9:
        sprintf(temp, "Destroy all %s of player %d",
            entry->target_player->master_objects[entry->obj_type]->name,
            entry->target_player->id);
        break;
    case 4:
        sprintf(temp, "Bring %s to area (%f, %f) - (%f, %f)",
            entry->this_obj->master_obj->name,
            (double)entry->x0, (double)entry->y0,
            (double)entry->x1, (double)entry->y1);
        break;
    case 5:
        sprintf(temp, "Bring %s to %s",
            entry->this_obj->master_obj->name,
            entry->target_obj->master_obj->name);
        break;
    case 6:
        sprintf(temp, "aqquire %d of attribute %d", entry->count,
            entry->number);
        break;
    case 7:
        sprintf(temp, "explore %d percent of the map", entry->count);
        break;
    }

    getstring(&description, temp);
    return description;
}
