// VA: 004848A0 RGE_RMM_Elevation_Generator::check_elevation
// Source: rmm_elev.cpp lines 100-153
// Attempt log:
// 1: initial reconstruction from packet/decompiler; wrong first-phase register topology and too-short text.
// 2: literal decompiler-style temporaries/order; too-short 0x10 frame due byte counter.
// 3: int local_10/row-count literal decompiler form even shorter/worse.
// 4: original-asm-inspired loop topology still too short/broad.
// 5: restore initial source as best behavioral baseline.
// 6: /Ob0, /O1, and /Gs flag probes did not reach original size/layout; removed flags.
// New claim: carry the second scan's row base plus x-offset across the row
// increment, matching the original `mov next_row; add offset` topology instead
// of recomputing the offset inside each cell LEA.
// Next ABI/layout probe: reuse the check_start_elevation sibling's byte-row
// ownership (`char**` plus byte row bases) instead of `int**`/`int*` aliases.
// Next liveness probe: model the binary-proven `count` stack local as the first
// scan's row counter, while keeping the second scan's byte result separate.
// Final source-width probe: use the period code's natural `long` coordinate,
// offset, and count locals throughout both scans instead of decompiler `int`s.
// Clean-source result: second-scan row-base carry is retained (408B boundary
// still lacks 11 effective bytes); first-scan row-base carry, result/row-count
// split, combined predicate, and inherited-class context were rolled back as
// worse or duplicate. No source-shape path reached the original first-scan
// stack homes.
// Left in scratch: behavior modeled, but first/second scan register topology and stack-slot layout remain broad.
// Continuation (sa-ab4dd300-r1): rmm_base/rmm_terr donors support the full
// inherited map-row and 24-byte tile surface; it compiled identically to the
// gap-only surface. A first-scan row_index and explicit self pointer were
// binary-motivated but formed a 370-byte-diff basin. Declaring the first
// row-pointer before its row base, while retaining byte-level tile access,
// improved the clean reconstruction to a 349-byte diff. Carrying the first
// row offset or swapping the second row-base/pointer order moved into broader
// structural basins; the latter reached 322 bytes but lost 13 bytes of code
// and kept the countdown in a register, so it was restored. Remaining gap is
// structural first-scan/second-countdown topology.
// Main-agent audit removed the diagnostic self alias and non-target padding
// helper; direct member ownership remains authoritative.
// Current claim: rechecked the full packet, dossier, same-TU donors, and ABI
// evidence. Prior bounded probes already exhausted first-scan row/count and
// second-scan liveness/layout families; no new source-supported lead justified
// replacing this readable 397-byte canonical reconstruction.
// Fresh worker (shardE-4848A0):
// - Baseline repeated the canonical typed two-scan source (397 bytes, diff 349).
// - Loading the second row base through row_ptr2 improved block/edit alignment
//   without changing size or strict diff; retained as a natural cursor form.
// - Reusing short-range names, hoisting first-scan declarations, and counted
//   while/for variants were duplicate or broader basins. Explicit radius-home
//   reuse was broader and was rolled back.
// - Reordering first row_ptr before row_offset was the best new lead: 394 bytes,
//   diff 323, shape 83.55%, with the oracle's saved-this, row-pointer, and
//   offset homes aligned. It still misses the count/y2/x2 home rotation and
//   remains structurally non-exact. A final index1 local probe broadened to 375
//   bytes and was rolled back.
// Paused: retain the readable row_ptr-before-offset reconstruction. Remaining
// blocker is the first-scan local-home rotation; no further blind variants fit
// the evidence budget.
// Fresh worker probes (orch-rmmelev-fresh-03):
// - Reusing the dead radius home for the first-scan clipped upper row bound
//   improved the diagnostic output to 398 bytes / 322 differing bytes, but
//   changed the prologue and remained a broad structural basin; rolled back.
// - Separate row_index declaration/scope and declaration-order variants were
//   exact-size or duplicate broad basins; none recovered the original
//   result/row-pointer/saved-this local rotation.
// - The typed Map_Stack/tile/base surface from the new same-TU two-byte stack
//   sibling is retained as canonical context; it is codegen-neutral here.
// Paused: clean source remains 397 bytes / 349 differing bytes. The remaining
// evidence-backed blocker is the first-scan local-window topology (original
// row counter [esp+10], result [esp+14], row pointer [esp+18], saved this
// [esp+1c], and offset [esp+20]) versus the natural compiler allocation;
// second-scan behavior and canonical map ownership are modeled.
// Revisit (sa-1f308ade-r1):
// - The clean typed baseline rebuilt to 394 bytes with 323 differing bytes.
// - Reusing the radius home, a byte result, or a separate row index alone
//   moved to broader structural basins and was rolled back.
// - A natural x2-before-y2 order reached 394 bytes and 320 differing bytes,
//   the best strict metric, but did not improve structural resynchronization.
// - A corrected row_index plus carried typed row-base form reached the exact
//   408-byte boundary and 348 differing bytes, with 88.96% shape, but its
//   local allocation remained farther from the oracle than the clean source.
// Retain the pinned clean source. The unresolved evidence-backed blocker is
// the first-scan register and local-home rotation, not map or terrain ownership.
// Revisit (sa-7c3536d6-r1):
// - The pinned source rebuilt unchanged at 394 bytes and 323 differing bytes.
// - Same-TU math/string headers plus x2-before-y2 ordering improved the
//   diagnostic result to 396 bytes and 313 differing bytes, but did not fix
//   the first local-home mismatch; this context lead was rolled back.
// - A for-header or function-scope first-row index reached 408 bytes but
//   entered the known broad 375/393-byte structural basins.
// - A row-base carry, including its corrected non-duplicated offset, was
//   broader and was rolled back.
// - The final policy-compliant source uses typed RGE_Tile rows and cells,
//   the reviewed terrain byte at offset +5, and no byte cursor. It rebuilt to
//   399 bytes and 374 differing bytes. No exact source lead was found.
// - Accepted drift: both scans use the same clipped inclusive bounds, initial
//   row read, next-row read before loop exit, and terrain/elevation predicates.
//   The second scan has the same byte-count wrap and return. This function has
//   no calls or writes. Remaining drift is private count, row, and pointer homes.
// Exact-finish audit (sa-a5e32b5c-r1):
// - Replaced the synthetic pure-generate base with the minimal period surface:
//   virtual base destructor, typed map pointer, RGE_Object_List destructor, and
//   the derived generate slot. The protected helper now matches the PDB owner
//   symbol IAEEEJJJEE.
// - A distinct first-scan index local recovered the original [esp+10] counter
//   home and improved the natural typed reconstruction to 403 bytes / 339
//   differing bytes. Typed narrow terrain/elevation bitfields and a block-scoped
//   second row scan remain policy-compliant.
// - Declaration, initializer, pointer-seed, predicate, and row-cursor alias
//   probes were duplicate or farther. Radius-home reuse changed the prologue
//   and widened the mismatch. No exact result was found.
// Exact-finish continuation (sa-c93cd21e-r1):
// - Typed row-base plus x1 inside each row changed the frame to 0x10 and
//   shortened the body. A named typed row offset kept the frame but widened
//   the body to 409 bytes / 385 differing bytes. Both forms were restored.
// - y2-before-x2, radius-home y2 reuse, while-form control flow, and bound
//   declaration order were duplicate or farther. The x2-before-y2 form is
//   retained. The base generate slot is authentic RMM context and codegen
//   neutral, so it remains in the local owner surface.
// - Final blocker remains the first-scan row-pointer spill and x2/y2 local
//   rotation. The typed map fields, clipped bounds, parameter homes, cleanup,
//   and early-failure order remain unchanged.

#include "..\\..\\include\\rmm_elev_context.h"

uchar RGE_RMM_Elevation_Generator::check_elevation(uchar elev, long x, long y, long radius, uchar terrain, uchar min_elev)
{
    long count = 0;
    if (radius > 0) {
        long x1;
        long y1;
        long x2;
        long y2;
        RGE_Tile** row_ptr;
        RGE_Tile* row;
        long index1;
        x1 = x - radius;
        y1 = y - radius;
        x2 = radius + x;
        y2 = y + radius;
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x2 >= this->map_width) {
            x2 = this->map_width - 1;
        }
        if (y2 >= this->map_height) {
            y2 = this->map_height - 1;
        }
        row_ptr = this->map_row_offset + y1;
        row = *row_ptr + x1;
        index1 = y1;
        for (; index1 <= y2; ++index1) {
            if (x1 <= x2) {
                RGE_Tile* cell = row;
                long xx = x1;
                do {
                    if (terrain == 0xFF || cell->terrain_type != terrain
                        || cell->height < min_elev) {
                        return 0;
                    }
                    ++xx;
                    ++cell;
                } while (xx <= x2);
            }
            ++row_ptr;
            row = *row_ptr + x1;
        }
    }

    {
    long x1 = x - 2;
    long y1 = y - 2;
    long x2 = x + 2;
    long y2 = y + 2;
    if (x1 < 0) {
        x1 = 0;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (x2 >= this->map_width) {
        x2 = this->map_width - 1;
    }
    if (y2 >= this->map_height) {
        y2 = this->map_height - 1;
    }

    RGE_Tile* row_base2;
    RGE_Tile** row_ptr2;
    row_ptr2 = this->map_row_offset + y1;
    // Keep the initial second-scan row load on the named row-table cursor.
    // The oracle loads the row pointer and its row address as separate values.
    row_base2 = *row_ptr2 + x1;
    if (y1 <= y2) {
        long rows_left = y2 - y1 + 1;
        do {
            if (x1 <= x2) {
                RGE_Tile* cell = row_base2;
                long cols_left = x2 - x1 + 1;
                do {
                    if (cell->height == elev) {
                        ++count;
                    }
                    ++cell;
                    --cols_left;
                } while (cols_left != 0);
            }
            ++row_ptr2;
            row_base2 = *row_ptr2 + x1;
            --rows_left;
        } while (rows_left != 0);
    }
    }

    return (uchar)count;
}
