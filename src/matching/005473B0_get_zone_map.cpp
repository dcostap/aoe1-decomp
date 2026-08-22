// VA: 005473B0 RGE_Zone_Map_List::get_zone_map(float *, long, int &)
// PDB source: zone_map.cpp lines 529-556
//
// Attempt log:
// - Baseline natural typed list scan/new/memcpy source: 281 B, 267 differing bytes;
//   VC5 peeled the first check_info call and emitted one extra call site.
// - Guarded while scan restored the original five-call topology and 266 B size:
//   37 differing bytes, with the first mismatch isolated to the hit-path epilogue.
// - Result-local/common-goto, named check result, direct constructor assignment,
//   destructor declaration, direct-return, and break/if-else variants did not
//   improve the 37-byte family; the named check result widened the body to 270 B.
// - Variant loop lab (while/for/do, default source context) found no size/call-set
//   eligible improvement. Restored the direct guarded-while source.
// - Final validated drift: rebuilt hit path restores EDI before storing the output
//   index and has a duplicated cleanup, while the original keeps EDI live and jumps
//   back to the shared epilogue at 00547485. Left in scratch; no inline asm or
//   compiler-only scaffolding retained.
// - This TU-aware pass tried a result/goto common label (including reversed hit
//   assignment order) and a break/post-loop hit branch; both were worse or kept
//   the same duplicated EH cleanup. Restored the guarded-while reconstruction.
// - Fresh same-TU layout/EH pass: the full RGE_Zone_Map field surface and
//   destructor ownership were compiled with the donor /GX context; both emitted
//   the same 37-byte family. Result/goto, explicit result, cold-label, comma,
//   old-count, and shared-array-return forms were diagnostic only; the clean
//   guarded-while allocation source remains the best natural reconstruction.
// FLAGS: config/flags/005473B0_get_zone_map.rsp (/GX with default /O2 /Oy)
// Main-agent audit retained the natural typed cache growth and nonvirtual
// zone-map lifetime surface; no EH-tail steering survives.
// - Follow-up donor pass confirmed the constructor-proven full zone-map layout
//   and same-TU list ownership; the first 183 bytes remain exact.
// - Hit return indexing through zone_map_index, initialized/shared result
//   locals, declaration-order changes, and separate index initialization all
//   emitted the same 266-byte family. An infinite-loop break widened the
//   structural drift to 197 bytes and was rolled back.
// - Typed lookup probe bound this->zone_maps[i] to a local RGE_Zone_Map*
//   before check_info and returned that pointer on a hit; it widened the
//   body to 269 bytes and lost early exact blocks. Restored the clean source.
// - Explicit found-label/common-result ordering, captured check_info result,
//   do-while scan, and removal of the outer count guard were tested; the first
//   and last emitted the same 266-byte family, while the captured/do-while
//   forms widened or duplicated the check. Restored the guarded while source.
// - This lease tested explicit result/goto forms, break/post-loop hit handling,
//   for-loop spelling, assignment-in-return, and declaration-order changes;
//   all natural direct-result forms stayed in the same 266-byte family.
// - A common pointer-array return using zone_map_index reached 247 bytes and
//   one return, but changed growth-path register scheduling and 73 strict bytes.
//   A common return using the scan index reached 247 bytes but drifted 158
//   bytes. Neither form is retained because the clean guarded-while source
//   preserves the original first 217 bytes and growth path.
// - Final lease probes restored the pinned clean source. The remaining 37-byte
//   drift is limited to the original shared hit-path EH teardown versus VC5's
//   duplicated direct-return cleanup. No exact natural source form was found.
// - Canonical ownership review: inventory/types/dumps/RGE_Zone_Map_List.txt
//   proves this class is 0xC bytes with RGE_Zone_Map** zone_maps at +0,
//   long zone_map_num at +4, and RGE_Map* map at +8. The exact same-TU
//   save/create/index functions confirm those types and ownership. The
//   constructor-proven RGE_Zone_Map surface below is the 0x51C allocation
//   owner. No declaration change is justified before further codegen work.
// - This pass tested a common return with a pre-scan zone_maps alias and a
//   common return through this->zone_maps[zone_map_index]. The alias form was
//   253 B with 221 differing bytes. The indexed common-return form was 247 B
//   with 74 differing bytes, but it changed the growth-path register schedule
//   from the first mismatch at 005473ED. Restored the pinned guarded-while
//   source; the 37-byte drift remains the best natural reconstruction.
// - Ownership gate rejected the exact local destructor definition because VA
//   005469C0 already owns that body in src/matching. It is not retained.
// - Declaration-only context probes using throw(), inline, implicit, and
//   __declspec(nothrow) destructor forms all stayed at the 37-byte family.
//   The exact shared EH cleanup needs the owned body to be visible in this TU.
//   NOTE: The historical single-owner context blocker is resolved by the
//   canonical zone_map translation-unit wrapper below.
// - Historical ownership audit: build_function.py compiled one source path
//   selected by VA; no repository tool mapped several VAs to one shared TU.
//   The exact neighboring create_zone_map source defined the 005469C0 destructor
//   locally, but that duplicate-owner pattern was rejected. The shared wrapper
//   below now compiles each VA-named owner once in one real translation unit.
// - Ten fresh context/ABI probes confirmed the boundary: inline destructor
//   bodies, generic helper bodies, and declaration-only forms remain 266 B /
//   37 bytes; an out-of-line empty/free/throw()/nothrow destructor before the
//   target method reached MATCH. Moving that definition after the method
//   returned to 266 B. A direct generated include also reached MATCH, but it
//   emitted a neighboring member symbol in the target TU without owner control.
//   The old one-source model was restored before the minimal wrapper was added.
// - Current lease evidence: function-local optimize("g", off), optimize("y", off),
//   inline_depth(0), stdio.h, memory.h, windows.h, constructor throw(), constructor
//   __declspec(nothrow), target __declspec(nothrow), and optimize("t", off) were
//   distinct tests. The flag/context probes either changed the frame/CFG or left
//   the same 266-byte / 37-byte family. Constructor and target exception contracts
//   did not select the original shared epilogue.
// - Diagnostic exact route: an out-of-line empty RGE_Zone_Map constructor body
//   before this method under inline_depth(0) produced MATCH / 0.0000%. A no-body
//   check_info declaration does not. An out-of-line check_info body before this
//   method also produced MATCH / 0.0000%. Both routes expose a preceding
//   RGE_Zone_Map member definition in the original zone_map.cpp translation unit.
// - Those direct constructor and check_info routes duplicated existing owners and
//   were not retained. An inline constructor body removed the constructor call
//   and produced 171 B. The old one-source model then restored the declaration-
//   only class: 266 B, 37 differing bytes, first mismatch at +0xD9.
// - Resolved the owner/context boundary with one canonical translation-unit
//   wrapper: `src/rge_zone_map_tu.cpp`. The manifest maps 005468C0, 005469C0,
//   00546E50, and this VA to that wrapper. The wrapper includes each existing
//   VA-named owner exactly once. `include/rge_zone_map_context.h` supplies the
//   shared class declarations. The build uses one `tu_zone_map.obj` for the
//   complete group, then extracts the requested symbol.
// - BINARY NOTE: a preceding real member body selects the original shared EH
//   epilogue. The prior constructor-only, destructor-only, and check_info-only
//   probes each reached MATCH, while the no-body control returned to 266 B / 37
//   bytes. The retained design uses the full proven zone_map.cpp owner group.
// - Ownership proof: the shared COFF object has one function symbol each for
//   the constructor, destructor, check_info, and get_zone_map. The four separate
//   VA object paths are not emitted by the grouped build. Final validation is
//   MATCH / 0.0000%, with five ordered calls and 247 bytes.
// - Follow-up audit rejected the earlier target-only wrapper: both its target
//   object and the 00546E50 object defined `check_info`. The grouped build now
//   emits only `build/obj/tu_zone_map.obj`; its COFF table contains one
//   `check_info` symbol and one `get_zone_map` symbol.

#include <stdlib.h>
#include <string.h>
#include "../../include/rge_zone_map_context.h"

RGE_Zone_Map* RGE_Zone_Map_List::get_zone_map(
    float* terrain_info, long terrain_info_num, int& zone_map_index)
{
    int i = 0;
    RGE_Zone_Map** new_zone_maps;

    if (this->zone_map_num > 0) {
        while (i < this->zone_map_num) {
            if (this->zone_maps[i]->check_info(terrain_info, terrain_info_num) != 0) {
                zone_map_index = i;
                return this->zone_maps[i];
            }
            i++;
        }
    }

    new_zone_maps = (RGE_Zone_Map**)calloc(this->zone_map_num + 1, 4);
    if (this->zone_maps != 0) {
        memcpy(new_zone_maps, this->zone_maps, this->zone_map_num * 4);
        free(this->zone_maps);
    }
    new_zone_maps[this->zone_map_num] =
        new RGE_Zone_Map(this->map, terrain_info, terrain_info_num);
    this->zone_maps = new_zone_maps;
    this->zone_map_num++;
    zone_map_index = this->zone_map_num - 1;
    return new_zone_maps[this->zone_map_num - 1];
}
