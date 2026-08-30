# Function notes: 004847C0 `check_start_elevation`

Module notes: `decomp_notes/rmm_elev_natural_candidate.md`.

## Recovered attempt history

<!-- recovered:b2172716d1cfceca8e53 -->
### `target-session` `build/target_sessions/004847C0_check_start_elevation.json:1-112`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=141; shape=85.41666666666667: Current clean typed row-base source; establish authoritative baseline before fresh probes.
probe 2 liveness; result=MISMATCH; diff=190; shape=82.65306122448979: Probe direct row-index expression to test whether eliminating persistent row_ptr forces original row-pointer stack spill.
probe 4 liveness; result=MISMATCH; diff=141; shape=85.41666666666667: Probe reverse outer update statement order: increment row counter before row pointer to test VC5 spill and reload scheduling. [same emitted code as probe 1]
probe 6 liveness; result=MISMATCH; diff=147; shape=81.63265306122449: Probe volatile row-table pointer to test whether required memory liveness reproduces the oracle's row-pointer home and frees ECX for tile-byte masks.
probe 8 liveness; result=MISMATCH; diff=190; shape=82.65306122448979: Probe deriving each next row base from map_row_offset plus the reused row index, making row_ptr dead across the inner scan. [same emitted code as probe 2]
probe 10 liveness; result=MISMATCH; diff=185; shape=84.375: Probe hoisting the per-row column initializer before the nonempty-row guard, matching the oracle's pre-branch col home store and line band.
probe 12 liveness; result=MISMATCH; diff=215; shape=75.0: Diagnostic probe: volatile alias of row_ptr's proven stack home tests whether forced pointer reload yields the oracle's ECX-free tile mask and home rotation.
probe 14 variant; result=MISMATCH; diff=215; shape=75.0: variant lab build\variant_lab\004847C0_check_start_elevation\20260816_222337: 24 variants, 24 invariant-eligible, 0 exact
probe 15 control-flow; result=MISMATCH; diff=141; shape=85.41666666666667: Probe combining the row-pointer increment with the next-row dereference via *++row_ptr, testing VC5 update/load scheduling. [same emitted code as probe 4]
probe 18 baseline; result=MISMATCH; diff=141; shape=85.41666666666667: Fresh claim baseline: pinned natural typed row-base source before new outer-loop hypotheses. [same emitted code as probe 17]
probe 19 control-flow; result=MISMATCH; diff=172; shape=86.45833333333333: Hypothesis 1: express the reused x row counter as a natural for loop, matching the exact do_elevation_brush donor's outer induction form.
probe 21 liveness; result=MISMATCH; diff=141; shape=85.41666666666667: Hypothesis 2: copy the terrain byte at each outer-row iteration, so VC5 can materialize the observed predicate byte before the inner-range guard. [same emitted code as probe 18]
probe 23 other; result=MISMATCH; diff=191; shape=74.03846153846153: Hypothesis 3: use the period-style bounded row for with a local row index and direct typed map_row_offset[row] access, testing whether VC5 naturally reuses the x home and range home like do_elevation_brush.
probe 25 liveness; result=MISMATCH; diff=142; shape=80.20833333333333: Hypothesis 4: keep a separate long row counter while retaining the proven row_ptr/row_base carry, to test whether y1 coalesces into the dead range home without losing the original first-row setup.
probe 27 control-flow; result=MISMATCH; diff=172; shape=81.25: Hypothesis 5: combine the separate row local with a natural for loop, matching the donor's bounded outer loop while preserving the row-base cursor.
probe 29 layout; result=MISMATCH; diff=168; shape=78.78787878787878: Hypothesis 6: carry the row base without the x offset, then add the named offset only at cell formation, testing a natural separation of row ownership and column addressing.
probe 31 other; result=MISMATCH; diff=141; shape=85.41666666666667: Hypothesis 7: declare the initial row-table cursor before the x offset and row-counter setup, following the oracle's map-pointer scheduling. [same emitted code as probe 21]
probe 33 liveness; result=MISMATCH; diff=141; shape=85.41666666666667: Hypothesis 8: join upper-bound declarations with their initializers, testing whether VC5 changes the dead-range home selection without changing the period bound order. [same emitted code as probe 31]
probe 35 layout; result=MISMATCH; diff=168; shape=78.78787878787878: Hypothesis 9: type the carried row base as RGE_Tile* while preserving byte-level predicate access, testing the canonical inline tile stride as an allocation input. [same emitted code as probe 29]
probe 37 liveness; result=MISMATCH; diff=141; shape=85.41666666666667: Hypothesis 10: copy the clipped upper row bound into a short-lived end_y local before cursor setup, testing whether the original range-home store is a natural dead-local coalescing result. [same emitted code as probe 33]
probe 40 control-flow; result=MISMATCH; diff=147; shape=72.72727272727273: Hypothesis 1: follow the Ghidra-derived natural do-while with an explicit initial and post-row empty-range return, and form each row's first cell from *row_ptr + offset rather than carrying row_base into the inner scan.
probe 42 control-flow; result=MISMATCH; diff=147; shape=72.72727272727273: Hypothesis 2: implement the Ghidra natural source more literally: no carried row_base local, a per-row cell seed from *row_ptr + offset, and do-while termination checks. [same emitted code as probe 40]
probe 44 layout; result=MISMATCH; diff=147; shape=82.47422680412372: Hypothesis 3: retain the proven while CFG but remove the carried row_base value; seed each row's inner cell directly from the current row_ptr plus offset.
probe 46 liveness; result=MISMATCH; diff=141; shape=85.41666666666667: Hypothesis 4: reverse the natural row setup statements so row_ptr is assigned before reusing x for the outer row counter, testing the oracle's store-before-row-pointer-load schedule. [same emitted code as probe 39]
probe 47 liveness; result=MISMATCH; diff=213; shape=79.38144329896907: Hypothesis 5: join the proven offset declaration with its x0*24 initializer, testing whether VC5's local-home allocation moves y1 into the dead range slot while preserving the row-base loop.
probe 49 liveness; result=MISMATCH; diff=142; shape=80.20833333333333: Hypothesis 6: replace the reused x parameter as row counter with a separate long row local while retaining the canonical carried row base, testing whether the original y1/range home emerges from the changed liveness. [same emitted code as probe 25]
probe 52 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_161752: 36 variants, 36 invariant-eligible, 0 exact
probe 53 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_161851: 72 variants, 60 invariant-eligible, 0 exact
probe 54 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_161926: 216 variants, 180 invariant-eligible, 0 exact
probe 55 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162018: 60 variants, 60 invariant-eligible, 0 exact
probe 56 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162058: 6 variants, 6 invariant-eligible, 0 exact
probe 57 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162124: 6 variants, 6 invariant-eligible, 0 exact
probe 58 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162150: 9 variants, 9 invariant-eligible, 0 exact
probe 59 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162211: 2 variants, 2 invariant-eligible, 0 exact
probe 60 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162235: 2 variants, 2 invariant-eligible, 0 exact
probe 61 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162250: 64 variants, 64 invariant-eligible, 0 exact
probe 62 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162343: 2 variants, 2 invariant-eligible, 0 exact
probe 63 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162414: 3 variants, 3 invariant-eligible, 0 exact
probe 64 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162431: 512 variants, 512 invariant-eligible, 0 exact
probe 65 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162504: 1 variants, 1 invariant-eligible, 0 exact
probe 66 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162541: 2 variants, 2 invariant-eligible, 0 exact
probe 67 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162558: 2 variants, 2 invariant-eligible, 0 exact
probe 68 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162652: 2 variants, 2 invariant-eligible, 0 exact
probe 70 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162740: 3 variants, 3 invariant-eligible, 0 exact
probe 71 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162804: 2 variants, 1 invariant-eligible, 0 exact
probe 72 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_162819: 2 variants, 2 invariant-eligible, 0 exact
probe 74 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_165420: 9 variants, 7 invariant-eligible, 0 exact
probe 75 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_165726: 3 variants, 3 invariant-eligible, 0 exact
probe 76 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_165818: 2 variants, 2 invariant-eligible, 0 exact
probe 77 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_165939: 4 variants, 4 invariant-eligible, 0 exact
probe 78 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_170012: 3 variants, 3 invariant-eligible, 0 exact
probe 79 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_170042: 2 variants, 2 invariant-eligible, 0 exact
probe 80 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_170103: 3 variants, 3 invariant-eligible, 0 exact
probe 81 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_170148: 2 variants, 2 invariant-eligible, 0 exact
probe 82 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_170205: 3 variants, 3 invariant-eligible, 0 exact
probe 83 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_170244: 2 variants, 2 invariant-eligible, 0 exact
probe 85 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_172232: 3 variants, 3 invariant-eligible, 0 exact
probe 86 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_172401: 2 variants, 2 invariant-eligible, 0 exact
probe 87 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_172624: 1 variants, 1 invariant-eligible, 0 exact
probe 88 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_172743: 3 variants, 3 invariant-eligible, 0 exact
probe 89 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_172823: 8 variants, 8 invariant-eligible, 0 exact
probe 90 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_172843: 2 variants, 2 invariant-eligible, 0 exact
probe 91 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_172901: 2 variants, 2 invariant-eligible, 0 exact
probe 92 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_172940: 1 variants, 1 invariant-eligible, 0 exact
probe 93 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_173007: 4 variants, 4 invariant-eligible, 0 exact
probe 94 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_173029: 3 variants, 3 invariant-eligible, 0 exact
probe 96 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_173729: 96 variants, 96 invariant-eligible, 0 exact
probe 97 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_173842: 192 variants, 192 invariant-eligible, 0 exact
probe 98 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_173938: 32 variants, 32 invariant-eligible, 0 exact
probe 99 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_173956: 32 variants, 32 invariant-eligible, 0 exact
probe 100 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_174053: 32 variants, 32 invariant-eligible, 0 exact
probe 101 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_174151: 1 variants, 1 invariant-eligible, 0 exact
probe 102 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_174249: 48 variants, 48 invariant-eligible, 0 exact
probe 103 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_174303: 60 variants, 60 invariant-eligible, 0 exact
probe 104 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_174321: 120 variants, 120 invariant-eligible, 0 exact
probe 105 variant; result=MISMATCH; diff=141; shape=85.41666666666667: variant lab build\variant_lab\004847C0_check_start_elevation\20260817_174439: 240 variants, 240 invariant-eligible, 0 exact
probe 107 abi; result=MISMATCH; diff=141; shape=85.41666666666667: Compiler-object/PDB audit: rmm_elev.obj S_GPROC32 at 0001:000837C0 has type 0x1C33, __thiscall uchar with 5 long/uchar parameters. S_BPREL32 records only index1 and y1 locals; no row_ptr/cell locals. The oracle bytes prove x1 in EBX, row_ptr in y home, and y1 in range home, so optimized PDB local locations are incomplete/stale and cannot justify named-home aliases. [same emitted code as probe 106]
probe 108 flags; result=MISMATCH; diff=141; shape=85.41666666666667: Object metadata audit: rmm_elev.obj S_COMPILE reports Microsoft 32-bit C/C++ Optimizing Compiler 11.00, Pentium target, hardware FPU, near data/code. Executable FPO row for RVA 000847C0 is E0 bytes, Locals=1, Prolog=0, Use BP=Y, SEH=N, Params=14h. This supports /O2 /Oy, one real local dword, no hidden EBP frame, and no EH/alloca explanation. [same emitted code as probe 107]
probe 109 layout; result=MISMATCH; diff=141; shape=85.41666666666667: PDB type records prove canonical ABI/layout: RGE_Random_Map_Module is 48 bytes with map_row_offset at +0x10 as RGE_Tile**, map_width +0x14, map_height +0x18; RGE_Tile is 24 bytes with terrain_type 5-bit field at byte +5 and height bits at byte +5 bits 5-7. The target's byte +5, *24 stride, and this-relative offsets match these types; layout is not the blocker. [same emitted code as probe 108]
probe 110 context; result=MISMATCH; diff=141; shape=85.41666666666667: PDB module audit: rmm_elev.obj contributes a dedicated 0001:000837C0-0008389F E0-byte text span; cvdump -M112 -inll reports no inlinee lines. The target has zero calls and no inline sites, so TU helper/inlining context cannot explain the residual register/home rotation. [same emitted code as probe 109]
probe 112 layout; result=MISMATCH; diff=147; shape=80.20833333333333: Policy audit: replaced raw byte row/cell cursors and reused x parameter with typed RGE_Tile row/cell ownership and a named row counter; changed map to RGE_Map* and tile object tail to canonical RGE_Object_List.
probe 113 layout; result=MISMATCH; diff=147; shape=80.20833333333333: Canonical base ownership follow-up: typed stack_array/stack_offsets as Map_Stack pointers from inventory layout; no target-body cursor or ABI change expected. [same emitted code as probe 112]
probe 115 liveness; result=MISMATCH; diff=218; shape=71.875: Hypothesis 1: natural typed row ownership computes each cell from the row-table cursor inside the outer loop, removing the carried row_base lifetime without raw cursors or parameter reuse.
probe 117 control-flow; result=MISMATCH; diff=179; shape=79.38144329896907: Hypothesis 2: use a natural outer for loop with row and row-table cursor updates in the for increment, while retaining typed row_base ownership.
probe 118 liveness; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 3: name a separate clipped col_end value for the inner typed tile scan, giving the natural upper-bound lifetime its own local instead of reusing x1. [same emitted code as probe 116]
probe 119 control-flow; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 4: use a natural typed inner for loop whose increment list advances the column and cell together, instead of a do-while body update. [same emitted code as probe 118]
probe 120 liveness; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 5: spell the natural typed induction updates as prefix column increment followed by explicit one-element cell advance, preserving the observed increment-before-stride order. [same emitted code as probe 119]
probe 121 liveness; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 6: declare the row counter and typed row-table cursor at their first use after clipping, matching natural loop scope instead of function-scope uninitialized locals. [same emitted code as probe 120]
probe 122 liveness; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 7: bind the typed row_base at the first row-table dereference with an initializer, so its lifetime starts at loop setup. [same emitted code as probe 121]
probe 123 liveness; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 8: make the typed cell lifetime cover each outer row, then enter the nonempty-column guard, rather than declaring cell only inside the guard. [same emitted code as probe 122]
probe 124 control-flow; result=MISMATCH; diff=175; shape=71.1340206185567: Hypothesis 9: express the outer scan as a positive row guard with a natural do-while body, keeping typed row/cell ownership and no parameter reuse.
probe 125 abi; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 10: use the canonical RGE_Tile terrain/elevation bitfields, matching the proven byte-5 layout, and let VC5 lower field reads naturally. [same emitted code as probe 123]
probe 126 layout; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 11: express the canonical row-table seed as an indexed address (&map_row_offset[y0]) instead of pointer-plus-index. [same emitted code as probe 125]
probe 127 liveness; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 12: seed the typed row cursor from the named row counter, not the clipped y0 expression, to align its natural loop lifetime. [same emitted code as probe 126]
probe 128 liveness; result=MISMATCH; diff=182; shape=76.76767676767676: Hypothesis 13: remove the redundant row local and advance the clipped y0 variable directly through the typed outer scan, preserving canonical row-table ownership.
probe 131 layout; result=MISMATCH; diff=190; shape=83.6734693877551: Hypothesis 1: retain carried typed row_base but derive each row from canonical map_row_offset[index1], removing the explicit row-table cursor so VC5 can free ECX for the terrain predicate.
probe 133 liveness; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 2: declare the PDB-named index1 and y1 at function scope before bound temporaries, then carry index1 through the typed row_base scan, to test natural local declaration order. [same emitted code as probe 130]
probe 134 control-flow; result=MISMATCH; diff=177; shape=81.25: Hypothesis 3: mirror the exact sibling's natural top-tested for scan, placing index1 increment in the loop increment while retaining the carried typed row_base update in the body.
probe 136 liveness; result=MISMATCH; diff=162; shape=80.20833333333333: Hypothesis 4: initialize the PDB-like outer row local at declaration () before bound setup, testing whether VC5 then keeps row in the original x parameter home without steering.
probe 138 layout; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 5: initialize the clipped bound locals at declaration, with y1 before x1, to test the natural source initialization site shown by the PDB line bands. [same emitted code as probe 133]
probe 139 control-flow; result=MISMATCH; diff=177; shape=81.25: Hypothesis 6: update the carried row_base immediately after advancing the typed row-table pointer, then increment the top-tested row counter, to test the sibling-supported source statement order. [same emitted code as probe 134]
probe 141 context; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 7: restore the exact elevation-generator sibling header context with math.h and string.h, testing whether the original rmm_elev translation-unit front-end state changes this no-call function. [same emitted code as probe 138]
probe 143 liveness; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 8: declare the PDB-like outer row local before the typed row-table pointer, testing whether VC5 naturally assigns the row counter to ECX and spills row_ptr to the y home like the oracle. [same emitted code as probe 141]
probe 144 liveness; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 9: seed the canonical row-table cursor from the live outer row local rather than rereading y0, testing whether shared induction ownership recovers the oracle home rotation. [same emitted code as probe 143]
probe 146 layout; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 10: split typed row_base initialization into load then pointer addition, matching the oracle add-after-row-load schedule without introducing a raw cursor or alias. [same emitted code as probe 144]
probe 148 liveness; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis 11: scope the typed row counter, row_ptr, and carried row_base at the first loop block after clipping, matching the PDB line band where row traversal starts. [same emitted code as probe 146]
probe 159 control-flow; result=MISMATCH; diff=175; shape=71.875: Hypothesis: express the proved first-row setup and pre-guarded outer scan as if (index1 <= y1) do/while, preserving the shipped one-row-past dereference and natural typed rows.
probe 161 control-flow; result=MISMATCH; diff=191; shape=82.65306122448979: Hypothesis: mirror the exact rmm_elev check_elevation sibling's natural typed row source: seed row_ptr and row_base before index1, then use a counted outer for with row update in the body.
probe 163 context; result=MISMATCH; diff=147; shape=80.20833333333333: Hypothesis: restore the PDB-proven protected access for check_start_elevation, testing authentic owner decoration without changing the natural body. [same emitted code as probe 158]
probe 164 liveness; result=MISMATCH; diff=190; shape=83.33333333333333: Hypothesis: preserve clean while CFG but assign index1 after initial typed row loads; direct validation reached 225 bytes and 190 differing bytes, so restore.
probe 167 liveness; result=MISMATCH; diff=146; shape=85.41666666666667: Hypothesis: reuse the dead x parameter as the outer row index while retaining typed RGE_Tile row and cell ownership; test whether natural parameter-home reuse recovers the original row/index home rotation.
probe 168 liveness; result=MISMATCH; diff=146; shape=85.41666666666667: Hypothesis: remove the dead duplicate index1 local from the parameter-reuse form, leaving x as the sole outer row counter and preserving typed row/cell ownership. [same emitted code as probe 167]
```
<!-- end-recovered:b2172716d1cfceca8e53 -->

<!-- recovered:98b58b9def395d2c17bb -->
### `c63aa9654052` `src/scratch/004847C0_check_start_elevation.cpp:1-203`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004847C0 RGE_RMM_Elevation_Generator::check_start_elevation (224 bytes)
// Source: rmm_elev.cpp lines 64-95
//
// Checks that every 24-byte cell in the rectangle [x-range..x+range] x
// [y-range..y+range] (clamped to the map) has terrain bits matching `terrain`
// and elevation bits >= `elevation`. Returns 0 on the first mismatch.
//
// Attempt log:
// 1: natural indexed access this->tiles[row][col*24+5]; this spilled to ebp, tiles[row] recomputed per cell (201B).
//    -> switched to per-row cell pointer with 24-byte stride (count_map_tiles idiom).
// 2: pointer idiom; first hunk is y1/x1 compute order (orig computes y1 before x1, reusing edi=y).
// 3: y1-before-x1 fixed; still homes y1 in arg1 (orig: arg5) and loop setup lands after the
//    guard (orig hoists first-row setup before guard, short jg).
// 4: named `long offset = x0*24` local: worse (saved this early to [esp+10h], ecx stolen for x1).
// 5: named `char* row_base` local: shifted all register roles (x0=edi etc.), worse prologue.
// 6: explicit while loops with row_ptr + cell pointer (next-row base loaded at loop bottom).
//    -> exact 224B size, clean natural baseline (diff 148B / 66.07%, 170 equal bytes).
// 7: declare x1 before y1 (y1 last) but assign y1 before x1: identical codegen (0 bytes changed).
// 8: focused loop-shape lab (while/do/direct-row-base/preloaded-cell forms): no exact variant;
//    the best family used an inner nonempty-row guard (diff 144B, 160 equal bytes).
// 9: direct dword access to the proven dead `range` home improved stack-slot coloring but
//    emitted the same 144B family; volatile access added 3 bytes and was rolled back.
// 10: top-declared offset/row/row_ptr plus the natural inner guard reproduced the same 144B
//     family; preloading a named row base is the current natural source (diff 142B / 163 equal).
//
// Left in scratch: remaining drift is localized.
//  - +0025: y1 homed in arg1 [esp+18h]; original homes it in arg5 [esp+28h] (the dead `range`
//    param slot). Same-TU exact donor remove_area_from_lists (00484C80) needed explicit
//    `x = end; radius = start_y;` param reassignment to recover param-slot homes; this
//    function's range param is uchar, so a dword y1 store cannot reuse it via assignment.
//  - +0045..: loop shape: original peels first rowBase load before the outer guard and carries
//    rowBase+offset in eax (loaded via `add eax,[edi]` in the row_inc); rebuilt loads rowBase
//    at the outer-loop top and keeps rowPtr homed in a slot. y1 slot choice drives the other
//    slot rotations (row arg1->arg2, rowPtr arg2->arg5).
// Paused: exact matching budget exhausted. Current source keeps canonical named row-base
// ownership; remaining drift is the y1/row/row_ptr stack-home rotation and first-row setup.
// Subsequent claim evidence: restoring the exact sibling inherited map/TILE declaration
// surface was codegen-identical; using y0 directly, typed tile bitfields, predicate byte
// locals, and alternate natural declaration orders were either worse or duplicate.
// Keep this clean row-base source. The original keeps x1 in EBX/uses CL for the tile mask,
// while this basin spills x1 and uses BL; its y1/row/row_ptr home rotation remains unresolved.
// Main-agent audit retained canonical elevation-map ownership and replaced the
// residual char casts with a typed byte-row traversal.
// Continuation (sa-ab4dd300-r1): the exact rmm_base/rmm_elev/rmm_terr base and
// 24-byte tile declaration surface was restored; emitted code was identical.
// Deriving the initial row-table pointer from the named row counter was also
// identical. Reusing the now-dead x parameter as the outer row counter is a
// binary-supported stack-home hypothesis: it moves the row counter to arg[0]
// and improves the current reconstruction to 141 differing bytes / 84.38%
// shape. Reversing bound declaration/assignment order and late-declaring y1
// were neutral or worse; naming the tile byte regressed to 191 bytes.
// Keep the readable x-row-counter source; y1/row-pointer home rotation and
// the original CL-vs-BL predicate coloring remain unresolved.
// Current claim: x1-before-y1 initialization moved the first mismatch earlier
// and was rolled back; declaring bounds before row locals was codegen-identical.
// Inverting the natural all-good tile predicate was also identical, while an
// explicit initial empty-range return plus do/while row loop broadened the CFG.
// A four-variant bound-declaration lab reproduced only the 141-byte or worse
// 146-byte families; no y1 range-home rotation was found.
// Continuation (orch-rmmelev-01):
// 11: reusing x as clipped x1 with a separate row counter worsened to 214 bytes.
// 12: a for-header row increment improved late edit alignment but worsened strict
//     bytes to 172; the outer empty-range do/while reproduced the prior 169-byte
//     family and was rolled back.
// 13: the exact rmm_elev class/TU declarations and full tile/info surface were
//     restored; codegen was identical. Comma-grouped bound declarations were also
//     identical.
// 14: a typed row-pointer seed/base/cell surface lab found no new basin; the clean
//     141-byte row-base source remains best. Restore it before final validation.
// Left unresolved: original y1 uses the dead range home, x1 remains in EBX, and
// row_ptr is homed in the y parameter slot so ECX can mask the tile byte; current
// natural VC5 allocation rotates those homes/registers despite exact size, CFG
// counts, and canonical map-row ownership.
// Continuation (wave21-rmmelev-01):
// 15: an explicit initial empty-range return plus infinite outer loop with a
//     bottom success return broadened to 169 bytes; rolled back.
// 16: carrying the row-table pointer in the dead y parameter home was binary-
//     motivated but codegen-identical to the clean basin; rolled back.
// 17: a scoped col_end copy of x1 and 18: separate nested tile-failure guards
//     were both codegen-identical; no liveness/CFG change.
// 19: swapped the natural inner induction statements to `++col` then
//     `cell += 24`, matching the oracle's inc-before-add order. Strict diff
//     stayed 141, but shape improved 84.38% -> 85.42% and edit diff 95 -> 94;
//     retain this period-plausible source order.
// 20: an explicit next_row compare before writing the reused x home broadened
//     to 174 bytes / 73.00% shape; rolled back.
// 21: an address-taken y-home alias was codegen-identical to the clean basin;
//     rolled back. A nine-variant row-pointer type/expression lab (22) found
//     only the typed duplicate basin; dword/byte cross-type variants did not
//     compile. Remaining blocker is the original y1/range-home, row_ptr/y-home,
//     x1/EBX, and CL-vs-BL allocation rotation, not tile/map ownership.

// Continuation (sa-1b774ae7-r1):
// 23: moving the column initializer before the inner guard broadened to 185 bytes;
// rolled back. A natural row-base-before-counter update improved late alignment
// but broadened to 172 bytes; rolled back.
// 24: a focused 20-variant declaration/predicate lab found no exact group; the
// closest valid direct-predicate family remained 141 bytes. Invalid nested
// predicate forms that skip the required terrain==FF failure were not retained.
// 25: `register long x1` was codegen-identical. A natural long radius promotion
// worsened to 142 bytes; rolled back. A counted inner for-loop was same-size but
// no closer. Address-taking row_ptr through a typed pointer alias was duplicate.
// 26: function-scope column lifetime likewise broadened to 185 bytes; rolled back.
// Final blocker remains a VC5 allocation basin: original homes y1 in dead range,
// spills row_ptr to the y home, keeps x1 in EBX, and uses CL for the tile mask;
// the clean typed row-base source homes y1/x1 oppositely, keeps row_ptr in ECX,
// and uses BL. Exact size/CFG/canonical map ownership remain stable.
// Continuation (follow-4847C0-r1):
// 27: assigning the offset after the row seed worsened to 143 bytes; rolled back.
// 28: declaring the inner column before cell worsened to 144 bytes; rolled back.
// 29: carrying a typed RGE_Tile row base worsened to 146 bytes; rolled back.
// 30: an if-plus-do outer loop broadened to 169 bytes; rolled back.
// 31: carrying cell across rows worsened to 163 bytes and changed the prologue;
//     rolled back. 32: seeding row_ptr from y0 directly is codegen-identical.
// Clean source retained: natural typed byte-row ownership and while/do scan.
// Validation remains 224 bytes, 141 differing bytes, 85.42% shape. The blocker
// remains the original y1/range-home and row-pointer/byte-register allocation.
// Continuation (shardE-4847C0): promoting the uchar range parameter to long
// with an explicit 0xFF mask duplicated an earlier ABI probe and worsened the
// strict diff to 142 bytes; rolled back.

// Fresh reassessment: spelling the initial row seed with x0 * 24 instead of
// the named offset, and swapping the row-base/table local declarations, both
// rebuilt to the same 224-byte/141-difference code. Both were rolled back.

// Continuation (sa-0667dc43-r1):
// - Direct row indexing, next-row expression updates, a volatile row pointer,
//   and a volatile alias of the row-pointer home all moved away from the clean
//   basin (190, 190, 147/+6 bytes, and 215 differing bytes respectively).
// - Reversing the outer update order and combining the pointer increment with
//   its dereference were codegen-identical to the 141-byte clean basin.
// - Hoisting the column initializer before the inner guard worsened to 185
//   bytes. A 24-variant lab over row-pointer type, bound order, predicate
//   temporary, and update spelling found no exact result; the clean group
//   remained best at 141 differing bytes.
// Keep the pinned clean typed row-base source. The remaining evidence still
// points to the original y1/range-home, row-pointer/y-home, x1/EBX, and
// CL-vs-BL allocation rotation.
// Fresh reassessment (sa-30715b7c-r1):
// - A natural outer `for` with the reused x row counter worsened to 172 bytes.
// - A per-row terrain copy was codegen-identical to the clean source.
// - Direct typed row indexing was 191 bytes; a separate row local with the
//   carried row pointer was 142 bytes in its while form and 172 bytes as a for.
// - Splitting the row base from the offset was 168 bytes. Reordering the
//   initial cursor declaration, joining upper-bound initializers, and copying
//   y1 to an end_y local were all duplicate 141-byte codegen.
// - Typing the row base as RGE_Tile* repeated the 168-byte basin.
// Restore and retain the pinned natural source. The clean result remains
// 224 bytes with 141 differing bytes and 85.42% shape; no natural source
// recovered the y1/range-home and row-pointer/y-home rotation.

// Deeper local/row-ownership reassessment (sa-af6eaad7-r1):
// - Nine row-surface forms (named row table, indexed row pointer, named row,
//   top-scoped cell locals, and typed cell forms) produced the 224-byte/141-
//   difference basin. Typed row/cell ownership entered 190-191-byte basins.
// - Canonical RGE_Tile bitfields, sizeof(RGE_Tile) stride, full bound
//   initialization, register locals, row aliases, nested row scope, and
//   byte/char row-table member types produced no better policy-valid result.
// - An integer row cursor and an explicit y-parameter pointer cursor both
//   normalized to the clean basin. This does not prove a shipped raw cursor;
//   retain the reviewed typed row-table ownership.
// - A const row-table alias changed the prologue and reached 195 differences;
//   the plain typed member remained best. Ten new variant families exhausted
//   local-declaration and row-ownership leads without recovering the original
//   y1/range-home, row-pointer/y-home, x1/EBX, or CL/BL rotation.
// - Object audit confirms the five-parameter ABI, one local FPO word, no SEH,
//   no inline records, the 24-byte tile, and terrain bits at byte 5. PDB names
//   only index1 and y1, so its optimized local records are incomplete. Assembly
//   proves the remaining homes; extra aliases or raw cursors stay unjustified.

// Continuation (sa-644fc685-r1):
// - Directly deriving each cell from the typed row-table cursor shortened the
//   function and broadened the CFG; retain the carried row_base lifetime.
// - Natural outer for and positive-guarded do-while forms were farther from the
//   oracle. The ordinary top-tested while form remains the closest clean loop.
// - Separate clipped-bound aliases, late declarations, direct row indexing,
//   and scoped cell lifetimes were codegen-identical or worse. Prefix/suffix
//   and induction-update spellings were also duplicate codegen.
// - Canonical terrain/elevation bitfields at byte 5 are codegen-identical to
//   the explicit byte mask and shift. Keep the proven RGE_Tile field surface.
// - The remaining stack-home rotation requires the shipped parameter reuse and
//   raw byte cursor that policy removed. No natural typed lifetime recovered it.

// Policy audit:
// - The module owns an RGE_Map and typed RGE_Tile rows.
// - The scan uses typed row and tile pointers, not byte cursors.
// - The named row counter does not reuse an incoming parameter home.
//
// Continuation (sa-003282eb-r1):
// - Directly deriving each carried row from map_row_offset[index1] removed the
//   row-table local, but widened the result to 190 differing bytes. Restore it.
// - PDB-named index1/y1 declaration order and a scoped row traversal were
//   codegen-identical. The retained source uses index1 for the proven row local.
// - An outer for loop, declaration-time row initialization, and alternate row
//   update orders widened or changed the known loop basin. Restore the while.
// - Bound initializers, sibling math/string headers, row-pointer seed spelling,
//   split row_base arithmetic, and local declaration order were duplicates.
// - The unchanged validation remains 224 bytes, 147 differing bytes, 80.21%
//   shape, with zero calls and the canonical typed bitfield traversal.
// - The unresolved bytes are the shipped parameter-home and register rotation:
//   original y1/range home, row_ptr/y home, x1 in EBX, and terrain mask in CL.
//   Recreating that rotation needs the rejected parameter aliases or raw byte
//   cursor. Keep the natural typed source instead.
```
<!-- end-recovered:98b58b9def395d2c17bb -->
