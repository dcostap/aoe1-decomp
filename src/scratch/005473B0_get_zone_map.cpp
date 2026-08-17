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
//   BLOCKER: no valid single-owner exact form was found.
// - Ownership architecture audit: build_function.py compiles one source path
//   selected by VA; no repository tool maps several VAs to one shared TU, and
//   no source bank contains multiple `// VA:` owners. The exact neighboring
//   create_zone_map source defines the 005469C0 destructor locally, but that
//   is the same duplicate-owner pattern rejected here, not a valid precedent.
// - Ten fresh context/ABI probes confirmed the boundary: inline destructor
//   bodies, generic helper bodies, and declaration-only forms remain 266 B /
//   37 bytes; an out-of-line empty/free/throw()/nothrow destructor before the
//   target method reaches MATCH. Moving that definition after the method
//   returns to 266 B. A generated include before the method also reaches
//   MATCH, but still emits `??1RGE_Zone_Map@@QAE@XZ` in the target TU.
//   No policy-valid one-owner shared-TU route exists without build-tool and
//   source-bank restructuring. Restored the ownership-compliant baseline.

#include <stdlib.h>
#include <string.h>

class RGE_Map;

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    unsigned char* zone_map;
    unsigned char** zone_map_rows;
    unsigned char zone_info[257];
    char gap_50D[3];
    float* terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map* map;

    RGE_Zone_Map(RGE_Map* map, float* terrain_info, long terrain_info_num);
    ~RGE_Zone_Map();
    RGE_Zone_Map* check_info(float* terrain_info, long terrain_info_num);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;  // +0x00
    long zone_map_num;         // +0x04
    RGE_Map* map;              // +0x08

    RGE_Zone_Map* get_zone_map(float* terrain_info, long terrain_info_num,
                               int& zone_map_index);
};

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
