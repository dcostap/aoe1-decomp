// VA: 004300F0 RGE_Combat_Object::attack
// Attempt log:
// - Initial natural missile-spawn source from packet asm/decompiler compiled but used too-small FPU body until math intrinsics were visible.
// - Added if-positive body with direct returns; got correct sub esp,8 prologue and 305-byte function size, but FPU scheduling still broad drift (~45% edit diff).
// - Tried explicit rx/ry locals before trig; size matched but compiler used MOV stores and different x87 stack order versus original fld/mov/fld-st3 pattern.
// - Canonicalized the missile factory to RGE_Player::master_objects (+0x24) and
//   RGE_Master_Static_Object::make_new_obj; this is codegen-neutral but matches
//   the ground-truth owner/table surface.
// - Modeled the proven Master_Static->Animated->Moving->Action->Combat and
//   Static->Animated->Moving->Action->Combat base sizes with named inherited
//   fields; emitted code remained in the same basin.
// - Inline range and radius-local variants were structural regressions. The
//   retained range declaration is before trig because PDB line 339 begins at
//   radius_y; it gives 303 emitted bytes, 260 strict differing bytes, 75.93%
//   shape, and all 3 ordered calls aligned.
// - A no-destructor vtable-surface diagnostic was codegen-neutral under the proven
//   inheritance surface and was rolled back. The remaining mismatch is the
//   radius/trig x87 schedule: original starts `fld radius_y`, spills only
//   radius_x, then uses `fld st3`; no inline asm or fake volatility retained.
// - Corrected the factory ABI to return RGE_Static_Object* and modeled the
//   proven RGE_Master_Combat_Object size as 0x148. Two radius temporaries are
//   assigned before trig, with the ordered sqrt/range expression deferred to
//   the init_missile argument. This emitted 285 bytes (283 strict diff),
//   structurally worse than the inherited 303-byte candidate; all calls stay
//   aligned and the ABI/layout corrections are retained as canonical source.
// - Separate declaration/assignment for both radius temporaries was a
//   codegen duplicate. Current source keeps the natural initialized order.
// - Direct master_obj accesses removed the early EDI save and made the guard
//   block exact; the deferred-range form was 289 bytes and 276-byte diff.
// - Keeping the natural range temporary before angle/trig with those direct
//   accesses restored 305 bytes, 178-byte diff, 75.93% shape, and exact guard
//   and tail blocks. The first hunk now differs only at radius load scheduling:
//   rebuilt MOVs radius_y to a stack home, while original starts FLD radius_y.
// - A short-lived radius-master alias and direct radius expression were
//   codegen duplicates or slightly worse. Rolled both back. Current source
//   retains direct master_obj ownership, initialized radius locals, and the
//   pre-trig range lifetime; no compiler-steering source was retained.
// - Tried the audit's natural radius_x-first range expression, with direct
//   radius_y terms and no cast. It grew to 309 bytes and diff 257; the first
//   hunk moved to the angle loads. Restored the clean 305-byte source.
// - Worker probes restored the pinned 305-byte source after testing direct
//   radius expressions, radius_x-only and delayed-assignment locals, range
//   declaration order, inline range evaluation, direct factory ownership,
//   direct angle reads, and implicit trig casts. The best source remains
//   305 bytes with 178 strict differing bytes, exact guard/tail blocks, and
//   all three ordered calls aligned. Direct radius order was codegen-neutral;
//   only-radius and delayed-assignment forms were worse. Inline range fell to
//   289 bytes; direct factory ownership was a duplicate. The binary-proven
//   DAT_0056f4ac spelling changed the basin to 303 bytes and was rolled back.
// - Revisit probes tested natural radius declaration/assignment forms, local
//   scope and order, operand order, const locals, angle aliases, range placement
//   between trig calls, split radius-distance math, and - -6.0f spelling.
//   Same-TU 0042FF50 proves a sibling x87 basin with function-scope c/s/range,
//   but that shape forces this target to a 0xC frame and 259 bytes. The clean
//   target source remains the typed 0x8-frame, 305-byte form at 178-byte diff.
// - Accepted-drift audit: do not promote this candidate. The changed x87
//   radius, sqrt, sin, and cos schedule can change extended-precision rounding.
//   Those values become missile coordinates and range arguments. Matching call
//   targets and body size do not prove equivalent published projectile state.
// - Session sa-9268378f follow-up: ten fresh hypotheses left the clean source
//   unchanged. Inline range fell to 289 bytes and 276 diff bytes. A radius_y-only
//   local gave 179 diff bytes; radius_x-only gave 180. Fully direct radius and
//   angle expressions fell to 232 bytes. A double range gave 310 bytes and a
//   0xC frame. Volatile radius_y gave 181 diff bytes and was rejected as steering.
//   Function-scope radius locals, a typed missile factory return, and double angle
//   locals were codegen duplicates at 178 diff bytes. DAT_0056f4ac restored the
//   original constant relocation but fell to 303 bytes and 260 diff bytes.
//   The original still keeps a distinct x87 stack order from +0x19 through the
//   first call. The three call sites, guard, tail, size, and frame remain aligned.
// - Continuation audit: same-TU sibling-shaped function/block c/s/range forms
//   stayed at 259 bytes with a 0xC frame and 272-274 diff bytes. A late direct
//   radius range expression reached 176 diff bytes and first mismatch +0x1A,
//   but shape fell to 75.00% and the x87 topology remained different. Radius_y
//   late and function-scope c/s inline-range forms were worse. Keep the clean
//   178-diff source, not the metric-only 176-diff form.
// - Structured context labs found no exact lead. Ambient declarations tested
//   64 states. Standard header combinations tested 16 states. VC5 risky and
//   small flag labs tested 768 states each. The best invariant group was 305
//   bytes, frame 0x8, three aligned calls, and 174 diagnostic diff bytes from
//   the lab template. It did not reduce the x87 mismatch and used diagnostic
//   context, so it was not retained. Donor-supported hp and computerPlayer
//   declarations were codegen duplicates or worse. Numeric #line mapping had
//   no effect; alternate #line source filenames failed under VC5.

class RGE_Combat_Object;
class RGE_Missile_Object;
class RGE_Static_Object;
class RGE_Player;
class RGE_Object_List;

#include "../com_obj_phase2_context.h"

#include <math.h>
#pragma intrinsic(cos)
#pragma intrinsic(sin)
#pragma intrinsic(sqrt)

unsigned char RGE_Combat_Object::attack(float x, float y, float z, RGE_Combat_Object* target)
{
    short missile_id = this->master_obj->missile_id;
    if (missile_id >= 0) {
        float radius_y = this->master_obj->radius_y;
        float radius_x = this->master_obj->radius_x;
        float range = (float)sqrt(radius_y * radius_y + radius_x * radius_x) +
            this->master_obj->weapon_range + 6.0f;
        float angle1 = this->angle;
        float angle2 = this->angle;
        float c = (float)cos(angle1);
        RGE_Player* owner = this->owner;
        RGE_Master_Static_Object* entry = owner->master_objects[missile_id];
        float s = (float)sin(angle2);

        RGE_Missile_Object* missile = (RGE_Missile_Object*)entry->make_new_obj(owner,
            this->world_x + c * this->master_obj->weapon_offset_y - s * this->master_obj->weapon_offset_x,
            this->world_y + s * this->master_obj->weapon_offset_y + c * this->master_obj->weapon_offset_x,
            this->world_z + this->master_obj->weapon_offset_z);

        missile->init_missile(target, x, y, z,
            range);
        this->notify(this->id, this->id, 0x200, 0x258, -1, 0);
        return 1;
    }
    return 0;
}
