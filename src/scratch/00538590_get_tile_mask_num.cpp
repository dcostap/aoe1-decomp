// VA: 00538590 RGE_View::get_tile_mask_num
// PDB: view.cpp:4394-4439
// attempt 1: direct eight-neighbor reconstruction; right size but x/y register coloring swapped.
// attempt 2: decompiler-shaped scalar locals and fixed-address row pointer macro; still swapped x/y registers.
// attempt 3: introduce explicit col/row locals to probe VC5 register coloring; no change.
// attempt 4: mark col/row register locals; no change (and register parameters forced /O1 frame when paired with /O1 probe).
// attempt 5: use explicit negated OR boundary predicate like decompiler/original source; changed compares but not register coloring.
// attempt 6: swapped col/row local definitions as a register-allocation probe; load order moved but semantics wrong.
// attempt 7: swapped locals with row-first guard fixed initial load order but made body x/y swapped.
// attempt 8: keep a first-param guard temp while restoring col/row semantics; no register change.
// attempt 9: keep swapped local names but use row=first-arg as x and col=second-arg as y; behavior/call-free effects correct but VC5 still chooses first arg in EDX and second in EAX.
// tried fixed-address macro vs extern row array; macro reduced relocation noise but not register coloring.
// tried negated-OR guard, explicit locals, register locals, swapped local names, and /O1 probe; /O1 made an EBP frame and was discarded.
// left in scratch: remaining mismatch is broad x/y register coloring, external
// row-table relocation/context, and common-tail placement. The retained source
// uses the canonical typed extern row table (no absolute-address macro) and the
// natural interior/edge if/else; current default build is 398 bytes, 308
// positional bytes, 83.87% shape, with call-free behavior/layout reconstructed.
// probe 10: replace the legacy absolute map macro with the canonical typed row-table declaration.
// probe 11: remove row/col aliases and use the formal parameters directly.
// probe 12: register-qualified coordinate parameters — codegen duplicate; rolled back.
// probe 13: explicit common-tail goto for the binary-proven central-path jump.
// probe 14: positive interior block first, explicit goto, then boundary block; no change.
// continuation probes (sa-f0a10d2b-r1): row/col alias initialization order,
// same-TU polymorphic RGE_View/TPanel layout, nested positive guards, and
// first-formal register qualification all emitted the same 398-byte basin.
// Named central row-pointer locals worsened to 397 bytes and were rolled back.
// Variant labs over common-tail wrappers, row-table declarations, indexed vs
// pointer-add cell access, and algebraically reordered row expressions found
// no exact or size-matching candidate. A deliberately transposed access form
// did flip the entry colors but changed the physical neighbor orientation and
// is diagnostic only.
// continuation probe: an explicit jump from the final interior mask test to
// the shared return tail emitted the same 398-byte code; restored clean source.
// continuation probe (orch-538590-a): an explicit jump after the arms was a
// codegen duplicate and kept the 398-byte duplicated epilogue.
// continuation probe (orch-538590-a): a separate complementary edge guard
// reached the exact 382-byte size, but expanded CFG drift to 362 bytes and
// lost the strong central/body islands; restored the canonical if/else.
// left in scratch: canonical typed row-table source remains 398 bytes with
// 308 positional-byte drift (+16 tail), first mismatch at entry parameter
// coloring; original also retains a shared late return tail that VC5 does not
// select from the tested natural source forms.
// matching pass sa-092c01cf-r1: baseline rechecked at 398 bytes, 308 differing
// bytes, 83.87% shape, and no calls. Restored clean source after every probe.
// The absolute row-table plus swapped semantic aliases improved shape to
// 92.74% and exact blocks to 95%, but produced 399 bytes and transposed the
// proven coordinate ownership, so it was discarded. A common-tail goto was a
// codegen duplicate. Hoisting the x stride added 61 bytes. A pointer-to-pointer
// global added an EBP frame and 55 bytes. All four decompiler locals, a Windows
// SDK include, reordered guards, and a guarded done label were codegen-neutral
// or worse. No natural exact candidate was found; retain the canonical source.
// matching pass sa-3bf37621-r1: named col/row, bounds, and mask-number locals
// preserve the caller's (col,row,width,height,mask) ownership. This source
// compiles to the same clean basin as the pinned candidate.

extern unsigned long* unified_map_offsets[];

class RGE_View {
public:
    char gap_000[0x1A0];
    unsigned char EdgeNumber[0x100]; // +0x1A0

    int get_tile_mask_num(int col, int row, int map_width, int map_height,
                          unsigned long mask);
};

int RGE_View::get_tile_mask_num(int col, int row, int map_width,
                                int map_height, unsigned long mask)
{
    unsigned int mask_number = 0;

    if (0 < col && 0 < row && col < map_width - 1 && row < map_height - 1) {
        if ((unified_map_offsets[row - 1][col] & mask) == 0)
            mask_number = 0x80;
        if ((unified_map_offsets[row][col + 1] & mask) == 0)
            mask_number |= 0x40;
        if ((unified_map_offsets[row + 1][col] & mask) == 0)
            mask_number |= 0x20;
        if ((unified_map_offsets[row][col - 1] & mask) == 0)
            mask_number |= 0x10;
        if ((unified_map_offsets[row - 1][col + 1] & mask) == 0)
            mask_number |= 0x08;
        if ((unified_map_offsets[row + 1][col + 1] & mask) == 0)
            mask_number |= 0x04;
        if ((unified_map_offsets[row + 1][col - 1] & mask) == 0)
            mask_number |= 0x02;
        if ((unified_map_offsets[row - 1][col - 1] & mask) == 0)
            mask_number |= 0x01;
    } else {
        if (0 < col && (unified_map_offsets[row][col - 1] & mask) == 0)
            mask_number = 0x10;
        int max_col = map_width - 1;
        if (col < max_col && (unified_map_offsets[row][col + 1] & mask) == 0)
            mask_number |= 0x40;
        if (0 < row && (unified_map_offsets[row - 1][col] & mask) == 0)
            mask_number |= 0x80;
        int max_row = map_height - 1;
        if (row < max_row && (unified_map_offsets[row + 1][col] & mask) == 0)
            mask_number |= 0x20;
        if (0 < col) {
            if (0 < row && (unified_map_offsets[row - 1][col - 1] & mask) == 0)
                mask_number |= 0x01;
            if (row < max_row && (unified_map_offsets[row + 1][col - 1] & mask) == 0)
                mask_number |= 0x02;
        }
        if (col < max_col) {
            if (0 < row && (unified_map_offsets[row - 1][col + 1] & mask) == 0)
                mask_number |= 0x08;
            if (row < max_row && (unified_map_offsets[row + 1][col + 1] & mask) == 0)
                mask_number |= 0x04;
        }
    }

    return this->EdgeNumber[mask_number];
}
