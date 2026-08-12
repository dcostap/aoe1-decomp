# Logic review: 00445D20 `TDrawArea::DrawBevel2`

## Phase transition

The main agent suspended ordinary exact matching after five claims, 30
meaningful probes, 46 checks, donor comparison, and a final source-plausibility
review. The candidate remains `src/scratch/00445D20_DrawBevel2.cpp`.

Current validated checker state:

- original/rebuilt size: 284/289 bytes;
- original/rebuilt frame: none / `0xC`;
- saved registers: `EBX`, `EBP`, `ESI`, `EDI` in both;
- calls: 8/8 in exact order;
- conditional branches: 4/4;
- strict difference: 264 bytes;
- workflow stage: structural reconstruction.

The exact blocker is stack-home and frame topology. The executable uses one
`push ecx` local and reuses incoming parameter homes for coordinate swaps. VC5
uses a normal local frame for the natural source. Prior donor-shaped and
block-local swap probes did not recover the executable topology.

The retained source uses the proven four-`long`, four-`unsigned char` ABI,
ordinary block-local swaps, named width and height values, and eight typed line
calls. The final normalization removed unconditional coordinate-copy artifacts
that existed only for compiler steering.

### Semantic questions at entry

1. Verify both coordinate swaps, including equal and reversed inputs.
2. Verify width and height arithmetic and overflow behavior.
3. Verify all eight line calls, their order, coordinates, and color roles.
4. Verify every conditional line gate and degenerate rectangle path.
5. Verify parameter widths, byte promotion, calling convention, and cleanup.
6. Verify alias, malformed-input, fault, and partial-effect order.

## Review rounds

No blind review has completed.

## Main-agent adjudication

Pending.

## Integrated changes

The main agent validated the normalized 289-byte source with all eight calls in
order before phase entry.

## Final decision

Pending blind review.
