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

#include "../../include/victory_context.h"

void RGE_Victory_Conditions::save(int param_1) {
    float version = 1.0f;

    rge_write(param_1, &version, 4);
    rge_write(param_1, &this->list_num, 4);
    rge_write(param_1, &this->victory, 1);

    for (RGE_Victory_Entry* entry = this->victory_list; entry != 0; entry = entry->next) {
        long target_player_id;
        long target_obj_id;
        long version_field;

        if (entry->target_player != 0) {
            target_player_id = entry->target_player->id;
        } else {
            target_player_id = -1;
        }

        if (entry->this_obj != 0) {
            target_obj_id = entry->this_obj->id;
        } else {
            target_obj_id = -1;
        }

        if (entry->target_obj != 0) {
            version_field = entry->target_obj->id;
            target_player_id = entry->target_obj->owner->id;
        } else {
            version_field = -1;
        }

        rge_write(param_1, entry, 1);
        rge_write(param_1, &entry->obj_type, 4);
        rge_write(param_1, &target_player_id, 4);
        rge_write(param_1, &entry->x0, 4);
        rge_write(param_1, &entry->y0, 4);
        rge_write(param_1, &entry->x1, 4);
        rge_write(param_1, &entry->y1, 4);
        rge_write(param_1, &entry->number, 4);
        rge_write(param_1, &entry->count, 4);
        rge_write(param_1, &target_obj_id, 4);
        rge_write(param_1, &version_field, 4);
        rge_write(param_1, &entry->victory_group, 1);
        rge_write(param_1, &entry->ally_flag, 1);
        rge_write(param_1, &entry->state, 1);
    }

    rge_write(param_1, &this->tot_victory_points, 4);
    rge_write(param_1, &this->point_list_num, 4);

    for (RGE_Victory_Point_Entry* point = this->victory_point_list; point != 0; point = point->next) {
        rge_write(param_1, point, 1);
        rge_write(param_1, &point->state, 1);
        rge_write(param_1, &point->attribute, 4);
        rge_write(param_1, &point->amount, 4);
        rge_write(param_1, &point->points, 4);
        rge_write(param_1, &point->curr_points, 4);
        rge_write(param_1, &point->id, 1);
        rge_write(param_1, &point->group, 1);
        rge_write(param_1, &point->curr_attribute_amount, 4);
    }
}
