// RGE_Victory_Conditions::save
// VA: 00531B70
// victory.cpp
// Attempt log:
// - Baseline: typed the victory entry, static object, player, and point record ownership and
//   used natural rge_write serialization loops. Calls, frame, and size were nearly exact;
//   the null-arm layout and float version-field model remained wrong.
// - Positive non-null arms for target_player/this_obj/target_obj recovered the original CFG
//   and left only the target-object version/owner hunk. Binary stores both target_obj->id and
//   the null sentinel as raw dwords, so version_field is a long, not a float.
// - A narrow volatile pointer lvalue for the second target_obj reread reproduces the original
//   reload and leaves 7 differing bytes (571-byte size, 0xC frame, 28/28 calls exact). A
//   volatile member and volatile pointer local were worse; comma/ordering variants were
//   emitted-code duplicates.
// - Paused after the bounded pass with the readable typed source retained. Remaining drift is
//   the localized VC5 order of the version-field store versus the proven target_obj reread.
// - Main-agent audit removed that fake-volatile reload control. Direct typed member access is
//   authoritative in the living source; the seven-byte result remains diagnostic only.
// - New worker restored the near-exact checkpoint, then rechecked a pure comma expression,
//   scoped target local, and nonvolatile address-taken aliases; each changed to the broad
//   432-byte basin. The exact 7-byte output still requires the prior fake-volatile reread,
//   so the direct typed serializer is retained.
// - Current worker rechecked a natural if-declaration, explicit file-handle alias,
//   ordinary member reference, CRT header context, and canonical virtual declarations;
//   all emitted the same 432-byte mismatch. Clean direct typed source restored.
// - Revisit restored the proven virtual surfaces for the victory conditions, player, and
//   static object types while keeping their observed offsets; this corrected the member ABI
//   spelling to UAEX without changing the 432-byte codegen basin. A post-ID typed alias was
//   also neutral, so the direct member expression remains the simplest source model.
// - This pass tested a period-plausible RGE_Object base for static-object id, a target local
//   before the id read, an opaque target_obj field, two split target_obj guards, an opaque
//   owner field, and opposite target-local use. The first, second, third, fifth, and sixth
//   probes duplicated the 432-byte basin. Split guards grew the body to 572 bytes. All were
//   restored. The oracle's extra target_obj reload still needs the rejected volatile probe.
// - BINARY NOTE: PDB assigns this body to victory.cpp lines 177-244, after the constructor
//   and destructor owners. The shared declaration leaves the 571-byte, 0xC-frame,
//   28-call candidate unchanged. The remaining mismatch is the target-object reread order.
// - Exact-finish probes tested a target pointer local, a nonvolatile base-id view, and a
//   member reference. Each preserved 571 bytes, 0xC frame, and 28 ordered writes, but none
//   reproduced the oracle's reload. The direct typed source is the smallest supported form.
// - Current shared-context validation is 568 bytes with a 432-byte mismatch. The target
//   block still caches the checked target_obj pointer instead of re-reading +0x28.
// - Fresh natural probes covered inline owner helpers, reversed target assignments, pointer
//   and object references, and target_obj[0].id. They preserved 28 ordered writes and the
//   0xC frame, but none preserved the oracle reload. All probes were restored.
// - Exact finish: PDB reports outfile as int and version as float. It reports three long
//   output locals as direct function children.
// - Moving the three output locals to function scope produced the first exact result.
//   It restored the target_obj reread and all later bytes.
// - An eight-case scope reduction showed that only target_obj needs function scope for
//   code generation. All three remain there because the PDB supports that source scope.
// - Declaration order and PDB names stayed exact. A standard-header lab produced one
//   code group, so no new header or compiler option remains.
// - Captain validation: caching the file handle and reusing the outfile parameter home for
//   target-player ID is supported by the original stack writes. It is codegen-neutral against
//   the 571-byte, 0xC-frame baseline. The authentic candidate remains 207 bytes different.

#include "../../include/victory_context.h"

void RGE_Victory_Conditions::save(int outfile) {
    long target_obj;
    float version = 1.0f;
    long this_obj;
    // BINARY NOTE: The executable reuses the outfile parameter home for target-player ID.
    int file_handle = outfile;

    rge_write(file_handle, &version, 4);
    rge_write(file_handle, &this->list_num, 4);
    rge_write(file_handle, &this->victory, 1);

    // BINARY NOTE: The stored count does not bound this walk. The linked chain controls writes.
    for (RGE_Victory_Entry* entry = this->victory_list; entry != 0; entry = entry->next) {
        if (entry->target_player != 0) {
            outfile = entry->target_player->id;
        } else {
            outfile = -1;
        }

        if (entry->this_obj != 0) {
            this_obj = entry->this_obj->id;
        } else {
            this_obj = -1;
        }

        if (entry->target_obj != 0) {
            target_obj = entry->target_obj->id;
            // BINARY NOTE: The executable rereads target_obj and does not test owner.
            // This preserves the fault order for malformed entries.
            outfile = entry->target_obj->owner->id;
        } else {
            target_obj = -1;
        }

        rge_write(file_handle, entry, 1);
        rge_write(file_handle, &entry->obj_type, 4);
        rge_write(file_handle, &outfile, 4);
        rge_write(file_handle, &entry->x0, 4);
        rge_write(file_handle, &entry->y0, 4);
        rge_write(file_handle, &entry->x1, 4);
        rge_write(file_handle, &entry->y1, 4);
        rge_write(file_handle, &entry->number, 4);
        rge_write(file_handle, &entry->count, 4);
        rge_write(file_handle, &this_obj, 4);
        rge_write(file_handle, &target_obj, 4);
        rge_write(file_handle, &entry->victory_group, 1);
        rge_write(file_handle, &entry->ally_flag, 1);
        rge_write(file_handle, &entry->state, 1);
    }

    rge_write(file_handle, &this->tot_victory_points, 4);
    rge_write(file_handle, &this->point_list_num, 4);

    // BINARY NOTE: point_list_num does not bound this walk. The linked chain controls writes.
    for (RGE_Victory_Point_Entry* point = this->victory_point_list; point != 0; point = point->next) {
        rge_write(file_handle, point, 1);
        rge_write(file_handle, &point->state, 1);
        rge_write(file_handle, &point->attribute, 4);
        rge_write(file_handle, &point->amount, 4);
        rge_write(file_handle, &point->points, 4);
        rge_write(file_handle, &point->curr_points, 4);
        rge_write(file_handle, &point->id, 1);
        rge_write(file_handle, &point->group, 1);
        rge_write(file_handle, &point->curr_attribute_amount, 4);
    }
}
