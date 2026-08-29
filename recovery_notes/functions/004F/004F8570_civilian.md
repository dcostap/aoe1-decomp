# Recovery journal: 004F8570 `civilian`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:706ad31b97f3e4f3f033 -->
### `d050eea3c` `src/taitacmd.cpp:9015-9028`

Mapping: `ambiguous`. next mapped function definition is civilian at old line 9131.

```text
// diagnostic basin, but moved lea esi before the initial jle and lost blocks.
// Restored the clean do-while reconstruction; no structural lead remains.
// resumed claim: 22 distinct source, lifetime, control-flow, and context probes
// passed the 20-probe checkpoint.  Direct tasked-array member expressions
// reduced the diff from 645 to 637 bytes.  The period donor comparison spelling
// [non-comment lines omitted during migration]
// Structured first-pass continues reduced the best clean source to 618 bytes,
// [non-comment lines omitted during migration]
// it was not retained.  Top-tested loops, split guards, extra headers, scoped
// indices, and late labels were neutral or worse and were rolled back.
// Final unresolved facts: the original first-pass tail uses a positive near JL
// [non-comment lines omitted during migration]
// and an early found return for every clean source form tested.
```
<!-- end-recovered:706ad31b97f3e4f3f033 -->

<!-- recovered:ec90c200444fd95becad -->
### `6a2aef2e2` `src/taitacmd.cpp:7834-7851`

Mapping: `ambiguous`. next mapped function definition is civilian at old line 7936.

```text
// bounded-session result: scoped civilian-array pointers recovered the EBX/ESI/EDI
// ownership, separate first/second object locals recovered all four 0x10-byte
// Reversed capacity comparisons matched every resize branch.  The natural bounded
// Remaining localized leads are the four contains inner-loop register permutations,
// the first-pass near success jump/epilogue, and the distance-selection x87 tail.
// no inline asm; exact promotion remains unresolved.
// grew to 879/981B; an explicit positive bottom branch duplicated the clean
// 645B output.  The no-outer for and while forms reproduced the prior 605B
// recovered the target x87 compare block and reduced it to 636 bytes.
// with 25/25 ordered calls, a 0x10 frame, and 96.68% exact-block coverage.
// Separate second-pass index storage reached 616 bytes but lost exact blocks;
// backedge and a late first-found epilogue.  VC5 keeps an inverted JGE/JMP tail
// MANAGEDARRAY AUDIT: resize guards, contains bounds, inline growth, copies,
// publication, and value reads match the executable. No template change is
// required.
// late in the executable. Both read the same object ID after currentOrder. The
// first loop uses equivalent positive versus inverted tails and one count read.
// All 25 calls, x87 comparisons, array effects, and return values match.
```
<!-- end-recovered:ec90c200444fd95becad -->

<!-- recovered:2636b28c63a6df8d6b92 -->
### `947c55021709` `src/scratch/004F8570_civilian.cpp:1-26`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004F8570 TribeTacticalAIModule::civilian
// Attempt log:
// initial decompiler-style implementation with explicit expandable civilian array and tasked duplicate scan: same 573-byte size but broad mismatch from offset 2; rebuilt uses 0x0c frame, ESI this, EBX/EBP as byte-offset/count pair instead of original 0x08 frame with EBP as index.
// tried register int i; no codegen change.
// tried hoisted world/obj locals vs inline object lookup; hoisted locals required declarations before goto and did not improve register basin.
// tried for-loop topology instead of do/while; no codegen change.
// tried natural method calls for object/unitAI/currentOrder/distance; call set looks plausible but scheduling/register family remains broad.
// tried canonical inline ManagedArray growth and typed md/player/world ownership;
// this is the current source-shape hypothesis, not a compiler-steering variant.
// probe 2: canonical operator[] growth plus typed md->player->world reduced the
// rebuild to 606 bytes and restored the inline growth topology.
// probe 3: the inlined utmarray.h contains surface and MainDecision +f0 layout
// reached exact size/frame, 13 calls, and 93.9% shape similarity.
// probes 4-5: float/integer zero spelling and best-local declaration order were
// duplicate codegen; probe 6's natural bestDistance > dist spelling restored the
// original x87 compare family and moved to the exact-codegen stage.
// probes 7 and 9: copied the exact contains local/parameter source surface;
// duplicate. Probe 8 reordered ordinary entry initialization, giving the
// immediate zero store and 175-instruction body, but emitted the two entry
// stores in reverse order and left a six-byte tasked-scan register permutation.
// probe 10: ordinary civilians/task references around contains fixed that
// register permutation. Best current source is exact in size/frame/CFG/ordered
// calls with a 10-byte strict drift only in the two entry initialization stores:
// the oracle emits bestUnitID=-1 then bestUnitDistance=0, while this clean
// source spelling emits the same stores in the opposite order. Leaving in
// scratch after the bounded assignment; no inline asm or opaque scaffolding.
```
<!-- end-recovered:2636b28c63a6df8d6b92 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
