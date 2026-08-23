// 004E3E90 TribeInformationAIModule::numberAvailableStoragePits (taiinfmd.cpp:8079-8129)
// BINARY NOTE: The PDB-qualified owner is TribeInformationAIModule. The body
// runs from 004E3E90 through 004E3F7D; 004E3F80 starts numberAvailableGranaries.
// Attempt log:
// - baseline decompiler-shaped reconstruction: 109 differing bytes; calls/CFG
//   were complete but the zone methods were incorrectly modeled as int.
// - exact same-TU granaries donor supplied unsigned-char currentZone/lookupZone
//   returns with byte masks: 15 differing bytes, 238/238 bytes and all calls,
//   blocks, and widths aligned.
// - flat-vs-inherited class surface, named md alias, combined object guard,
//   top-declared object locals, proven polymorphic base surface, and reused
//   decompiler int role all emitted the same 15-byte register-coloring basin
//   (or regressed structurally for the md alias/positive outer guard).
// - sibling 00501B90's exhaustive register/source-shape work was not repeated;
//   its remaining md/product callee-save basin is consistent with this target's
//   unresolved this/md and second-object register swap.
// - Best retained reconstruction: canonical typed ownership and donor-backed
//   byte-return zone ABI; remaining drift is 15 register/address encoding bytes
//   (original this=EDI/md=ESI/obj2=ESI, rebuilt this=ESI/md=EDI/obj2=EDI).
// - Main-agent audit replaced the raw +0x1146C cast with the exact-donor-backed
//   TribeMainDecisionAIModule::tacticalAI member; codegen is unchanged.
// - Session probes: caching md for the age/first-object phase either regressed
//   broadly when used throughout or emitted the same 15-byte basin when its
//   lifetime was narrowed; restored the direct canonical source.
// - Session probes: donor declaration order, top-declared zone/object locals,
//   a register-qualified md alias, inherited AIModule/MainDecision object
//   surfaces, a named self alias, combined age decrement, and stdlib TU context
//   all emitted the same 238-byte/15-byte-drift basin (the md/this and second
//   object register swap remains). Restored the canonical typed source.
// - Fresh bounded pass: swapped top-level obj1/obj2 declarations; used a
//   canonical MainDecision base-typed md phase and base-typed md member; all
//   retained the same 238-byte/15-byte basin.
// - Reference and const md aliases worsened to a 184-byte diff with a frame;
//   both were restored. A 48-variant body/source-order lab and a 384-variant
//   class-surface lab (base/vtable/object/local declaration combinations)
//   found no exact result; every invariant-eligible group remained 238 bytes
//   with the same 15 register/address mismatches. The clean typed source is
//   retained; the remaining blocker is a stable VC5 this/md/second-object
//   allocator basin rather than behavior, layout, or call-set uncertainty.
// - wave20 bounded pass: target destructor, obj1/obj2 register hints, full
//   target size, full AIModule virtual slots, self alias, math.h context,
//   function-scope local declarations, and a scoped tacticalAI alias all
//   emitted the same 238-byte/15-byte basin. A four-variant canonical
//   AIModule/MainDecision virtual-surface lab produced two stable groups,
//   both with the same first mismatch at +3; no exact or structural lead.
// - Fresh bounded pass: a direct MainDecision-typed md widened the drift to
//   19 bytes; inherited MainDecision object surfaces gave 16 bytes. Explicit
//   MainDecision casts for both object calls stayed at 15 bytes with no code
//   movement. Restored the typed TribeMainDecision ownership.
// - Fresh context probes: stdlib/string and windows.h header pairs left the
//   same 238-byte/15-byte basin. VC5 rejects __restrict; no probe was kept.
// - Added the complete same-TU donor declaration tail from exact donor 004D9970
//   (the +0x1256C aiPlayer field) without changing the natural function body;
//   emitted code stayed at 238 bytes with the same 15-byte register basin.
// - Fresh nested-layout probe: the minimal typed MainDecision/build/
//   information/resource/tactical parent surface regressed to 18 bytes;
//   restore the exact 00501D70 nested shape before further comparison.
// - Full 00501D70 nested class surface, inherited MainDecision object calls,
//   and full informationAI size restored the 238-byte/15-byte basin. Adding
//   TacticalAIModule inheritance also stayed in that basin.
// - Inlining coordinate conversions and naming the final available count were
//   codegen duplicates. A phase-local decision alias widened the drift to 133
//   bytes and was restored. No localized liveness lead changed the stable
//   this=ESI/md=EDI/obj2=EDI allocator basin.
// - Current lease baseline reconfirmed the clean 238-byte basin.  The
//   remaining 15 bytes are the stable this/md/second-object register swap;
//   no new source or ABI lead is justified without repeating prior probes.
// - Reassessment probes: flat and non-polymorphic information surfaces,
//   collapsed/direct main-decision surfaces, complete inherited virtual slots,
//   polymorphic object layout, base-typed md, scoped/reused md locals, and
//   combined minimal class surfaces all reproduced the same 238-byte/15-byte
//   basin. Restored the canonical typed source; no new ABI or liveness lead.
// - Fresh worker pass: the authoritative check reconfirmed 238/238 bytes,
//   all eight calls, CFG, and the 15-byte register-coloring drift. Comparison
//   with sibling 00501B90 shows only shared VC5 md/this coloring evidence;
//   it does not justify a new natural source form for this target.
// - Revisit pass: split age_idx declaration/assignment and donor RGE method
//   declaration order both duplicated the 238-byte/15-byte register basin.
//   Restored the canonical typed source.
// - Fresh bounded pass: a full md alias regressed to 184 bytes; the narrow
//   Ghidra-shaped md alias duplicated the 238-byte/15-byte basin.
// - Fresh bounded pass: positive outer dropsites guards, the combined
//   Ghidra obj1/obj2 predicate, and top-declared locals regressed to a
//   172-byte structural basin. The plain non-polymorphic information surface
//   and a named storage-pit scalar both duplicated the stable basin.
// - Restored the pinned natural typed source. No exact or structural lead was
//   found; the remaining drift is the known 15-byte this/md/object2 coloring.
// - Exact transition (sa-98828d60-r1): inlining the final strategicNumber call
//   into the closestDropsiteValue comparison changed the 15-byte basin to an
//   exact 238-byte match. Restoring the named strategicN temporary returned
//   the 15-byte mismatch. Removing the explicit 1/0 ternary kept the match and
//   reduced the source to a direct boolean return.
// - BINARY NOTE: The shipped tail calls strategicNumber first, then reloads
//   closestDropsiteValue from this before the compare. The direct expression
//   is the smallest natural source that emits this=EDI and md=ESI without
//   dummy liveness, volatility, register hints, or no-effect expressions.

#include "../../include/information_dropsites_context.h"

int TribeInformationAIModule::numberAvailableStoragePits(int param_1)
{
    int age_idx = (int)(this->md->player->attributes[6]);
    age_idx--;

    if (age_idx < 0) {
        age_idx = 0;
    } else if (age_idx > 3) {
        age_idx = 3;
    }

    if (this->dropsitesByAge[param_1][age_idx] == 0) {
        return 0;
    }

    RGE_Static_Object* obj1 = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);

    if (obj1 != 0) {
        RGE_Static_Object* obj2 = this->md->object(this->closestDropsiteResourceID[param_1]);

        if (obj2 != 0) {
            int zone = obj1->currentZone() & 0xff;
            int y = (int)(obj2->world_y);
            int x = (int)(obj2->world_x);
            int lookup = obj1->lookupZone(x, y) & 0xff;

            if (zone != lookup) {
                return 0;
            }
        }
    }

    return this->closestDropsiteValue[param_1] >
           this->md->tacticalAI.strategicNumber(param_1 + 0xA3);
}
