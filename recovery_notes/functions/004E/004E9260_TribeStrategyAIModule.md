# Recovery journal: 004E9260 `TribeStrategyAIModule`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taistrmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taistrmd.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:5d93a23b5927847f55cf -->
### `d050eea3c` `src/taistrmd.cpp:1126-1129`

Mapping: `strong`. comment lies after mapped function TribeStrategyAIModule at old line 1071.

```text
// EH frame (/GX)
// [non-comment lines omitted during migration]
// Attempt log:
// (baseline) Natural virtual-destructor surface: real StrategyAIModule base
```
<!-- end-recovered:5d93a23b5927847f55cf -->

<!-- recovered:d098ac582e1d74a1226f -->
### `6a2aef2e2` `src/taistrmd.cpp:1026-1032`

Mapping: `strong`. comment lies after mapped function TribeStrategyAIModule at old line 974.

```text
// taistrmd.cpp
//
//   (vptr-only, virtual dtor), VictoryConditionRuleSystem member with virtual
//   dtor, and three IntArray members with inline delete+zero dtors. Empty
//   derived dtor body; VC5 auto-restores the TribeStrategyAIModule vftable,
//   destroys vcRules/idleRules/executingRules/vcRuleSet in reverse
//   declaration order (EH states 3/2/1/0), then calls ~StrategyAIModule.
```
<!-- end-recovered:d098ac582e1d74a1226f -->

<!-- recovered:21691e2de335ca776d63 -->
### `target-session` `build/target_sessions/004E9260_TribeStrategyAIModule.json:1-97`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=4; shape=98.88888888888889: Canonical typed constructor with StrategyAIModule base, IntArray-like members, VictoryConditionRuleSystem, and three serialized array-add loops; establish current mismatch.
probe 2 liveness; result=MISMATCH; diff=20; shape=94.72222222222223: Use the first constructor parameter a as the serialized name-length destination and index, matching original entry-parameter address evidence at the name read.
probe 4 liveness; result=MISMATCH; diff=20; shape=94.72222222222223: Bind the serialized length as a reference alias to the first constructor parameter, testing parameter-home reuse without changing the natural later value variable.
probe 6 liveness; result=MISMATCH; diff=1040; shape=92.01101928374656: Keep a separate named length assignment after reading the serialized size into parameter a, testing whether VC5 preserves the target frame while using the proven parameter home.
probe 8 liveness; result=MISMATCH; diff=20; shape=94.72222222222223: Read serialized name length into parameter a, then route each array value through the preexisting length local to test whether an otherwise live local restores the original 0x10 frame and hidden-this home. [same emitted code as probe 4]
probe 10 liveness; result=MISMATCH; diff=4; shape=98.88888888888889: Move count and loop-index declarations before the serialized-name locals, testing declaration order as the source of the target's one-word hidden-this/home color. [same emitted code as probe 1]
probe 12 liveness; result=MISMATCH; diff=4; shape=98.88888888888889: Swap value and serialized-length declaration order, testing whether VC5 colors the hidden-this home independently from the unchanged loop bodies. [same emitted code as probe 10]
probe 14 liveness; result=MISMATCH; diff=4; shape=98.88888888888889: Combine the two serialized scalar declarations, testing whether VC5's front-end local grouping changes the hidden-this spill slot without changing behavior. [same emitted code as probe 12]
probe 16 context; result=MISMATCH; diff=4; shape=98.88888888888889: Add the period standard allocation header as a translation-unit context probe, testing whether VC5's front end changes the four local displacement bytes.
probe 18 context; result=MISMATCH; diff=4; shape=98.88888888888889: Add the period string header as a second translation-unit context probe, testing whether its declarations select the original local-home basin.
probe 19 liveness; result=MISMATCH; diff=1068; shape=93.0939226519337: Use parameter a for the serialized name size and a named rule-set buffer pointer, testing the natural source shape suggested by persistent EBP buffer ownership.
probe 21 context; result=MISMATCH; diff=4; shape=98.88888888888889: Add one neutral file-scope declaration, testing the documented old-MSVC front-end context axis for the four-byte displacement basin.
probe 23 liveness; result=MISMATCH; diff=19; shape=94.72222222222223: Limit the serialized name-length local to its two reads and terminator, then call loadRules with the direct member expression, testing lifetime-sensitive frame coloring.
probe 25 liveness; result=MISMATCH; diff=19; shape=94.72222222222223: Scope the serialized length through loadRules, testing the previously observed declaration-lifetime axis with the call inside the lifetime. [same emitted code as probe 23]
probe 27 variant; result=MISMATCH; diff=19; shape=94.72222222222223: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_154845: 12 variants, 4 invariant-eligible, 0 exact
probe 28 variant; result=MISMATCH; diff=19; shape=94.72222222222223: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_154917: 128 variants, 0 invariant-eligible, 0 exact
probe 29 variant; result=MISMATCH; diff=19; shape=94.72222222222223: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_154934: 1536 variants, 512 invariant-eligible, 0 exact
probe 30 liveness; result=MISMATCH; diff=23; shape=93.61111111111111: Use a two-element int value buffer with index zero for all three serialized rule values, testing the documented aggregate-local basin while preserving behavior and loop calls.
probe 32 abi; result=MISMATCH; diff=4; shape=98.88888888888889: Widen the serialized name length to unsigned int, testing width/signedness as a possible source of the identical-size displacement-only mismatch. [same emitted code as probe 14]
probe 34 abi; result=MISMATCH; diff=4; shape=98.88888888888889: Use period long for the serialized name length, testing signed 32-bit type spelling while preserving the proven read and index behavior. [same emitted code as probe 32]
probe 37 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_161104: 6 variants, 0 invariant-eligible, 0 exact
probe 38 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_161203: 72 variants, 17 invariant-eligible, 0 exact
probe 39 liveness; result=MISMATCH; diff=1040; shape=92.01101928374656: Natural parameter address-taking followed by a named length copy: test whether early a-home use preserves the original hidden-self and name-length stack colors without a raw alias. [same emitted code as probe 6]
probe 41 liveness; result=MISMATCH; diff=31; shape=86.66666666666667: Use the named value local as each rge_read destination instead of reading parameter a then copying; tests the natural value-home lifetime while keeping loop semantics typed.
probe 43 liveness; result=MISMATCH; diff=7; shape=98.05555555555556: Scope a fresh int value initialized from a inside each loop body; tests whether the original value home is loop-local rather than function-local.
probe 45 liveness; result=MISMATCH; diff=4; shape=98.88888888888889: Group the value/length and count/index declarations into two natural declaration statements; tests front-end local grouping without aliases or lifetime extension. [same emitted code as probe 38]
probe 48 control-flow; result=MISMATCH; diff=4; shape=98.88888888888889: Rewrite each counted for loop as explicit index initialization plus while and update; tests whether the original loop-index lifetime/control form selects the hidden frame color. [same emitted code as probe 45]
probe 50 liveness; result=MISMATCH; diff=777; shape=93.92265193370166: Initialize count before its serialized read; tests whether an early count lifetime/store changes the frame reservation, with no behavior change for valid input.
probe 52 liveness; result=MISMATCH; diff=19; shape=94.72222222222223: End the serialized name-length scope after its terminator and loadRules call; tests whether explicit block lifetime affects the original one-word frame reservation. [same emitted code as probe 25]
probe 54 context; result=MISMATCH; diff=4; shape=98.88888888888889: Add period stdlib declaration context before the target; tests whether allocator declarations alter the one-word home basin without changing source behavior. [same emitted code as probe 16]
probe 57 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_172911: 11 variants, 0 invariant-eligible, 0 exact
probe 58 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_172925: 132 variants, 17 invariant-eligible, 0 exact
probe 59 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_173038: 156 variants, 17 invariant-eligible, 0 exact
probe 60 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_173248: 360 variants, 42 invariant-eligible, 0 exact
probe 61 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_173413: 360 variants, 42 invariant-eligible, 0 exact
probe 62 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_173552: 456 variants, 58 invariant-eligible, 0 exact
probe 63 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_173724: 480 variants, 58 invariant-eligible, 0 exact
probe 64 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_173813: 528 variants, 58 invariant-eligible, 0 exact
probe 65 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_173938: 864 variants, 240 invariant-eligible, 0 exact
probe 66 variant; result=MISMATCH; diff=4; shape=98.88888888888889: variant lab build\variant_lab\004E9260_TribeStrategyAIModule\20260817_173948: 864 variants, 87 invariant-eligible, 0 exact
probe 68 context; result=MISMATCH; diff=20; shape=94.72222222222223: Natural parameter-home source with separate tempIntNum outer loop; tests original PDB name/value reuse plus original counted-loop local without aliases or steering. [same emitted code as probe 2]
probe 70 context; result=MISMATCH; diff=20; shape=94.72222222222223: Direct playerID-home reuse with period stdlib.h context; tests whether allocator declarations select the original 0x10 frame and homes.
probe 72 context; result=MISMATCH; diff=20; shape=94.72222222222223: Direct playerID-home reuse with period string.h context; tests string declarations as the original front-end basin.
probe 74 context; result=MISMATCH; diff=20; shape=94.72222222222223: Direct playerID-home reuse with period stdio.h file declarations; tests original file-header context.
probe 76 context; result=MISMATCH; diff=20; shape=94.72222222222223: Direct playerID-home reuse with period memory.h context; tests memory API declarations before the module.
probe 78 context; result=MISMATCH; diff=20; shape=94.72222222222223: Direct playerID-home reuse with the period stdlib/string/stdio/memory header set in original-like order.
probe 80 context; result=MISMATCH; diff=20; shape=94.72222222222223: Direct playerID-home reuse plus the full VictoryConditionRuleSystem declaration surface from preceding taistrmd.cpp donors.
probe 82 context; result=MISMATCH; diff=20; shape=94.72222222222223: Direct playerID-home reuse plus the full ManagedArray declaration surface from utmarray.h donors.
probe 84 context; result=MISMATCH; diff=20; shape=94.72222222222223: Direct playerID-home reuse with the exact VictoryConditionRuleSystem int sn[0xE2] layout and full preceding method declarations. [same emitted code as probe 80]
probe 86 context; result=MISMATCH; diff=4; shape=98.88888888888889: Clean local-name baseline with all period CRT headers and exact module class surfaces; tests the full natural TU declaration context without changing body semantics.
probe 89 abi; result=MISMATCH; diff=4; shape=98.88888888888889: Object/PDB audit: cvdump on original age1_x1.pdb module 0x47 (Release/taistrmd.obj) shows S_GPROC32 Cb=0x4CF, DebugStart=0, DebugEnd=0x4B8, this in ECX, playerID [BPREL +4], infile [BPREL +8], tempIntNum [BPREL -0x18], i [BPREL -0x1C], and tempInt reusing [BPREL +8]. No S_BLOCK32, S_INLINESITE, S_DEFRANGE, or inlinee records exist for this function. Its line table has all 30 target bands. This does not support an omitted natural local. [same emitted code as probe 88]
probe 90 abi; result=MISMATCH; diff=4; shape=98.88888888888889: FPO/COFF audit: original empiresx.exe PE FPO row at RVA 0x000E9260 is Proc=1231, Locals=28, Regs=4, Prolog=0, BP=Y, SEH=N, Params=8. Pinned VC5 current object dumpbin /fpo reports the identical row. Original PDB S_COMPILE identifies Microsoft 32-bit C/C++ Optimizing Compiler Version 11.00; config pins CL 11.00.7022 and /O2 /Oy /GX. Compiler version, EH frame, and object ABI are not the four-byte blocker. [same emitted code as probe 89]
probe 91 layout; result=MISMATCH; diff=4; shape=98.88888888888889: Type/ABI audit: original CodeView defines AIModule size 240, StrategyAIModule public base at offset 0 size 240, TribeStrategyAIModule size 1528 with fields at md 0xF0, name 0xF8, three ManagedArray<int> objects at 0x238/0x248/0x258, VictoryConditionRuleSystem at 0x268 size 908, difficulty at 0x5F4; ManagedArray<int> is 16 bytes and Waypoint is 16 bytes. Current object dependencies and relocations use the same Strategy ctor, Victory ctor, rge_read, new/delete, and EH handler. A sandbox compile replacing the 16-byte byte overlay with exact Waypoint fields and replacing Victory data[0x388] with CodeView-supported int sn[0xE2] produced byte-identical .text. Earlier recorded full period declaration context probe #86 was also the same 4-byte basin. [same emitted code as probe 90]
probe 92 liveness; result=MISMATCH; diff=4; shape=98.88888888888889: Home-color audit: authoritative checker has exactly four positional byte edits at +0x29, +0x16C, +0x179, +0x18E. Only immediate displacements differ: original hidden self store [esp+0x24] vs rebuilt [esp+0x20], and original serialized-name length parameter-home [esp+0x30]/[esp+0x3C] vs rebuilt local-home [esp+0x1C]/[esp+0x28]. All 28 ordered direct calls, relocation identities, branches, loops, size, FPO, and later code are exact. Natural Waypoint/Victory object types do not alter this. This is a one-word VC5 home-color basin, not a hidden API or compiler-version mismatch. [same emitted code as probe 91]
probe 94 abi; result=MISMATCH; diff=4; shape=98.88888888888889: CodeView symbol record audit: target constructor is S_GPROC32 [0001:000E8260], Cb=0x4CF, Type=0x16D0, DebugStart=0, DebugEnd=0x4B8. Child records are exactly six labels plus this, playerID, infile, tempIntNum, i, and tempInt. No S_BLOCK32, S_INLINESITE, S_DEFRANGE, or S_REGREL records occur under this procedure. Omitted optimized scopes cannot identify another natural local. [same emitted code as probe 93]
probe 95 abi; result=MISMATCH; diff=4; shape=98.88888888888889: CodeView line audit: original taistrmd.cpp line table has 30 address changes for this exact function, from line 1205 at 000E8260 through line 1243 at 000E8718. Every constructor phase has a line band: member reads, version guard, name length/name, loadRules, difficulty, and three rule loops. The line stream is not truncated at the four mismatches, so stale line coverage does not support a missing source block. [same emitted code as probe 94]
probe 96 context; result=MISMATCH; diff=4; shape=98.88888888888889: CodeView inline audit: cvdump -M47 -inll emits only the module header and no inlinee lines. The target S_GPROC32 has no inline-site children. All three ManagedArray add bodies are therefore ordinary front-end inline expansion visible through the line-1231 band, not an omitted inline scope that could reserve the missing word. [same emitted code as probe 95]
probe 97 flags; result=MISMATCH; diff=4; shape=98.88888888888889: FPO metadata hypothesis: original empiresx.exe FPO RVA 000E9260 has Proc=1231, Locals=28, Regs=4, Prolog=0, BP=Y, SEH=N, Params=8. The pinned VC5 object has the identical /fpo row. This rules out a different frame mode, EH switch, or compiler local-byte count as the four-byte cause. [same emitted code as probe 96]
probe 98 flags; result=MISMATCH; diff=4; shape=98.88888888888889: Compiler fingerprint hypothesis: original taistrmd.obj S_COMPILE reports Microsoft 32-bit C/C++ Optimizing Compiler Version 11.00, Pentium target, hardware FPU, NEAR code/data. The PE debug directory is linker 5.00 with NB10 PDB. The repository pins CL 11.00.7022 and the current object uses /O2 /Oy /GX. No compiler-version or target-CPU basin remains plausible. [same emitted code as probe 97]
probe 99 layout; result=MISMATCH; diff=4; shape=98.88888888888889: Type-record hypothesis: original CodeView defines StrategyAIModule as a public Strategy base over AIModule, both 240 bytes, and TribeStrategyAIModule as 1528 bytes. Its exact members are md 0xF0, current value 0xF4, name array 0xF8, arrays 0x238/0x248/0x258, VictoryConditionRuleSystem 0x268, and difficulty 0x5F4. The current source has the same offsets and allocation size. Wrong object layout cannot explain only home displacements. [same emitted code as probe 98]
probe 100 layout; result=MISMATCH; diff=4; shape=98.88888888888889: Subobject-type hypothesis: CodeView defines ManagedArray<int> as 16 bytes with four int/pointer fields, Waypoint as 16 bytes with float x/y/z and byte facet, and VictoryConditionRuleSystem as 908 bytes with int sn[226] after its vptr. Sandbox VC5 builds that use exact Waypoint members and int sn[226] instead of byte overlays have byte-identical 1232-byte .text sections. These natural type corrections do not move the four homes. [same emitted code as probe 99]
probe 101 abi; result=MISMATCH; diff=4; shape=98.88888888888889: COFF dependency hypothesis: current object symbol table has the exact target constructor decoration HH@Z, exact StrategyAIModule(void*,int) base constructor, VictoryConditionRuleSystem default constructor, direct rge_read, operator_new/delete, derived loadRules/setDifficultyLevel, and C++ frame handler. The checker masks 35 relocations safely and reports 28/28 ordered calls with zero replacements. No wrong helper convention or import/direct-call identity remains. [same emitted code as probe 100]
probe 102 abi; result=MISMATCH; diff=4; shape=98.88888888888889: Boundary/metadata hypothesis: original PE places the FPO row at RVA 0xE9260 and the next row at 0xE9730, giving the exact 1231-byte constructor boundary. Its debug directory uses NB10 age1_x1.pdb and its .text section has no COFF line table or relocations. The PDB Cb and PE FPO agree with the checker boundary. There is no stale boundary or parent-owned fragment. [same emitted code as probe 101]
probe 103 liveness; result=MISMATCH; diff=4; shape=98.88888888888889: Parameter-home hypothesis: original instructions use entry+4 playerID storage for name length and each serialized rule value; PDB names playerID at BPREL +4 and records tempInt at the reused +8 home. The clean source instead gives the name length a natural local, while preserving exact rule-value loop storage. Directly reusing playerID, as the binary suggests, removes the 0x10 frame word and worsens the result to the known 20-byte basin. No natural parameter alias explains both original homes. [same emitted code as probe 102]
probe 105 layout; result=MISMATCH; diff=28; shape=86.11111111111111: Apply completed source-gate model: real AIModule base, typed md, Waypoint, int sn[226], natural name padding, inherited AIModuleMessage virtual surface, and named PDB locals without parameter-home reuse.
probe 106 liveness; result=MISMATCH; diff=28; shape=86.11111111111111: Use PDB local declaration order tempIntNum, i, tempInt while retaining named parameters and typed source-gate model; test natural lifetime and frame topology. [same emitted code as probe 105]
probe 108 liveness; result=MISMATCH; diff=31; shape=86.66666666666667: Natural separate count local for all three list counts; preserve PDB names and direct read/add calls. Test whether original local_18 is a distinct count lifetime.
probe 109 liveness; result=MISMATCH; diff=31; shape=86.66666666666667: Separate count local with declaration order i, count, tempIntNum, tempInt; test VC5 local-home coloring against original count at local_18 and index at local_1c. [same emitted code as probe 108]
probe 110 liveness; result=MISMATCH; diff=31; shape=91.38888888888889: Block-local count lifetimes around each read/add scan; test whether original local_18 is a reused scoped count while PDB tempIntNum and i remain named.
probe 112 liveness; result=MISMATCH; diff=31; shape=86.66666666666667: Declare separate list count after the name load and methods; test whether late count lifetime preserves the parameter-home name length while supplying the original local slot. [same emitted code as probe 109]
probe 114 liveness; result=MISMATCH; diff=31; shape=86.66666666666667: Separate semantic nameLength from PDB tempIntNum list counts; test natural distinct count lifetime against original local_18 and retain direct reads/add. [same emitted code as probe 112]
probe 116 liveness; result=MISMATCH; diff=28; shape=86.11111111111111: Move PDB-named tempIntNum, i, tempInt declarations to constructor entry without parameter aliases; test declaration lifetime/order as source evidence. [same emitted code as probe 107]
probe 118 control-flow; result=MISMATCH; diff=28; shape=86.11111111111111: Natural while-loop spelling for each serialized rule scan; test loop form against PDB line bands and VC5 backedge layout while keeping direct read/add. [same emitted code as probe 116]
probe 120 control-flow; result=MISMATCH; diff=28; shape=86.11111111111111: Guarded do-while scans preserve observed top count test and bottom index test; test explicit source CFG against PDB line bands. [same emitted code as probe 118]
probe 122 abi; result=MISMATCH; diff=28; shape=86.11111111111111: Explicit int casts at ManagedArray<int>::add call sites; test whether natural value-width spelling controls the inline value home.
probe 124 liveness; result=MISMATCH; diff=28; shape=86.11111111111111: Local ManagedArray<int>& alias for the first add only; diagnostic test of receiver liveness and value-home scheduling, not a retained steering form. [same emitted code as probe 120]
probe 126 liveness; result=MISMATCH; diff=28; shape=86.11111111111111: Reorder PDB-named local declarations to tempInt, tempIntNum, i; test VC5 home coloring without changing read/add semantics. [same emitted code as probe 124]
probe 128 liveness; result=MISMATCH; diff=37; shape=90.55555555555556: Scoped for-header i declarations with braces after VC5 scope collision; test natural per-scan index lifetimes versus original shared PDB i.
probe 130 control-flow; result=MISMATCH; diff=28; shape=86.11111111111111: Use post-increment i++ in all scans; test VC5 update expression spelling while preserving PDB i and direct add. [same emitted code as probe 126]
probe 131 abi; result=MISMATCH; diff=28; shape=86.11111111111111: Specialize ManagedArray<int>::add parameter to int instead of dependent T; test canonical specialized method surface without generic method broadening. [same emitted code as probe 130]
probe 137 liveness; result=MISMATCH; diff=20; shape=94.72222222222223: Restored the historical 0x10-frame source and reused constructor parameter a for the serialized name length, testing whether the original parameter-home name access can coexist with the natural extra value local. [same emitted code as probe 68]
probe 138 liveness; result=MISMATCH; diff=1040; shape=92.01101928374656: Added a semantic length local after reading the serialized name count through parameter a, testing whether a natural value copy can preserve both the original parameter-home destination and the original 0x10 frame. [same emitted code as probe 39]
probe 139 liveness; result=MISMATCH; diff=29; shape=86.11111111111111: Used only the constructor parameter a for the serialized name length and all three list counts, with one index and one tempInt local matching the PDB names; removed synthetic count/value locals to test the original parameter-home model.
probe 141 liveness; result=MISMATCH; diff=4; shape=98.88888888888889: Kept the canonical typed/source-gate declarations but tested the historical four-local shape: value and length before loadRules, then count and i, with playerID reused for list values.
probe 142 liveness; result=MISMATCH; diff=4; shape=98.88888888888889: Moved count and index declarations before the name-length locals while keeping the same source operations; test declaration order as the remaining stack-home coloring axis. [same emitted code as probe 141]
probe 143 liveness; result=MISMATCH; diff=20; shape=94.72222222222223: Applied the Ghidra-supported local roles: playerID is the serialized name/value home, tempIntNum is the per-list count, i is the loop index, and tempInt receives each value before ManagedArray::add.
probe 144 control-flow; result=MISMATCH; diff=20; shape=94.72222222222223: Mirrored the original Ghidra CFG with count read, zero index, positive guard, do-while body, and bottom index compare for all three lists. [same emitted code as probe 143]
probe 145 control-flow; result=MISMATCH; diff=20; shape=94.72222222222223: Changed all three list scans to natural while loops with explicit initialization and increment, testing loop-form control over the frame allocation in the Ghidra-supported parameter-home source. [same emitted code as probe 144]
probe 146 liveness; result=MISMATCH; diff=20; shape=94.72222222222223: Moved the Ghidra-named tempIntNum, i, and tempInt declarations to constructor entry, testing declaration scope and allocation order without changing the canonical parameter reuse or list CFG. [same emitted code as probe 145]
probe 147 liveness; result=MISMATCH; diff=33; shape=91.11111111111111: Scoped one count local around each list scan while retaining the shared i/tempInt and playerID homes, testing whether natural count lifetimes force the original extra frame word.
probe 150 baseline; result=MISMATCH; diff=15; shape=91.94444444444444: Fresh baseline after the authentic taistrmd.cpp prefix and shared PDB-backed declarations were installed; establishes current stack-home drift before schedule work.
probe 151 liveness; result=MATCH; diff=0; shape=100.0: Use tempInt for each list count and reuse tempIntNum for each serialized value after the name phase. This follows the original stack homes: count at entry -24 and values at the dead playerID home +4.
probe 152 liveness; result=MISMATCH; diff=1; shape=100.0: Replace compiler-chosen home reuse with the PDB/Ghidra-supported source roles: playerID is the serialized name and value temporary, tempInt is each list count, and tempIntNum is the shared outer index.
probe 153 liveness; result=MISMATCH; diff=23; shape=93.61111111111111: Keep tempIntNum for the name-length phase, use tempInt as each count and i as the index, then explicitly reuse dead playerID for serialized list values. This tests the natural parameter reuse without changing the exact terminator schedule.
probe 154 liveness; result=MISMATCH; diff=5; shape=96.66666666666667: Exact-finish walkback: revert only the first list to tempIntNum as count and tempInt as value. This tests whether the first role swap is independently required.
probe 155 liveness; result=MISMATCH; diff=5; shape=96.66666666666667: Exact-finish walkback: revert only the second list to tempIntNum as count and tempInt as value. This tests whether the second role swap is independently required.
probe 156 liveness; result=MISMATCH; diff=5; shape=98.61111111111111: Exact-finish walkback: revert only the third list to tempIntNum as count and tempInt as value. This tests whether the third role swap is independently required.
```
<!-- end-recovered:21691e2de335ca776d63 -->

<!-- recovered:e7b900cd44400e4d8bdb -->
### `ed6df8bdb667` `src/scratch/004E9260_TribeStrategyAIModule.cpp:1-109`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004E9260 TribeStrategyAIModule::TribeStrategyAIModule
// taistrmd.cpp
//
// Attempt log:
// source-gate pass: replaced the synthetic TribeStrategyAIModule base gap with
// the real 0xF0 AIModule base, typed md, Waypoint, and sn[226]. The AIModule
// message slots now use AIModuleMessage*, and StrategyAIModule inherits them.
// Removed explicit name padding and the parameter-home a/value temporaries.
// The direct rge_read calls and ManagedArray<int>::add behavior remain.
// Validation after the grouped source-gate changes: 28-byte mismatch, 0x0C
// rebuilt frame, 28 calls, and exact 1231-byte size. The prior four-byte source
// was metric-closer but used synthetic layout and parameter-home aliases.
// baseline reset: canonical StrategyAIModule(void*,int) ABI, virtual derived
// construction, real ManagedArray<int> members, and the period inline add
// implementation. Earlier work used an int-typed base shim and a macro-expanded
// duplicate scan; those produced the wrong constructor relocation and a
// pointer-walk/boolean CFG rather than the donor's indexed ManagedArray scan.
// parameter-home probe: reusing the dead first constructor parameter for the
// serialized name length and rule values reduced the mismatch from 31 bytes to
// 7 bytes and aligned all three indexed add loops.
// frame probes: explicit/scoped value locals, top-of-function declarations,
// address-taken aliases, and an explicit self pointer all collapsed back to a
// 0xC frame and a 20-byte displacement-only drift; these were diagnostic and
// were rolled back.
// left in scratch: best canonical source is the parameter-home/ManagedArray
// reconstruction (7 bytes, 0x10 frame). Remaining drift is the original
// compiler's one-word local-frame reservation around the name-length home.
// same-TU context check: the full AIModule/StrategyAIModule virtual surface
// was added from the class reference. It was a codegen duplicate and is kept
// as the period-plausible declaration context.
// this session: reconfirmed the typed constructor and stack map. The remaining
// seven bytes are local-home displacements at the serialized name/value phase;
// prior parameter-home and liveness basins remain worse at 20 bytes.
// direct reuse of the first parameter for the name length was tested from the
// dossier's entry-relative +4 address evidence; it removed the one-word frame
// reservation and worsened the result to 20 bytes, so the clean local remains.
// scoped the name-length local through loadRules only; VC5 shrank the frame to
// 0xC and worsened the mismatch to 19 bytes, so this lifetime variant was
// restored. The unresolved lead remains the original parameter-home hunk.
// continuation: a local serialized value plus parameter-home name/loop reads
// reached the same 7-byte basin; an address-taken value pointer was a codegen
// duplicate. A four-way /GX variant lab confirmed the local-name form is the
// best invariant-preserving source; parameter-name forms either lose the frame
// slot or retain the same later drift. Restored this clean typed source.
// this session: parameter-home length/value reuse plus one named serialized
// value local fell to a 0xC frame and the prior 20-byte basin; restored.
// moving count/index declarations to function entry, then declaring length
// with them, produced the same 7-byte codegen and no new stack layout.
// a declaration-order lab produced only the known 11-byte and 20-byte groups;
// a debug-context flag lab lacked the EH frame and was not a valid lead.
// left in scratch: clean typed constructor remains 7 bytes off in seven
// stack-home displacement bytes at the length and add-value temporary sites.
// explicit function-level value local reached a 4-byte diff and exact loop
// bodies, but moved the base self-home and name-length homes by one word.
// loop-scoped value locals were a codegen duplicate of the clean source.
// a two-element value-buffer diagnostic reached 2 bytes but changed the
// base self-home and one indexed name terminator byte; it was not plausible.
// new focused labs: combined /GX with /Zd, /Zi, and /Z7; varied the indexed
// terminator spelling; all produced the same two-byte aggregate candidate.
// Moving ManagedArray::add outside the class, changing its inline spelling,
// reducing the base virtual surface, adding likely CRT headers, moving local
// declarations, and using pointer/reference self aliases did not fix the home.
// Pair structs behave like int[2]; scalar chains collapse to the 0xC frame.
// Risky VC5 optimization flags produced no exact invariant-preserving group.
// The remaining fact is one uncolored frame word: natural parameter reuse has
// the correct physical hidden-self home but a 0xC frame, while an 8-byte value
// aggregate restores 0x10 and moves that hidden home to the loop-index slot.
// final unresolved pass: 20 meaningful probes retained this clean source at
// 4 differing displacement bytes, with 28 calls, size, and 0x10 frame exact.
// BINARY NOTE: the original reads the name length and each rule value through
// the entry +4 constructor-parameter home. Direct parameter reuse loses one
// frame word and gives a 20-byte mismatch. Local-name, type, scope, header,
// ambient-declaration, and flag probes found no exact source basin.
// LIKELY INTENT: the shipped source reused parameter a as a wire temporary;
// the clean local form remains the smallest period-plausible source here.
// Object audit: original and current FPO, 0x10 frame, calls, EH metadata, ABI,
// compiler, and boundaries match. PDB has no block, inline, or range records
// beyond its named reused homes. No object evidence supports an alias for the
// remaining four stack displacements.
// continuation: PDB confirms playerID, infile, tempIntNum, i, and tempInt.
// It has no block records for these locals. The original has separate count,
// index, value, and hidden-self homes, while clean source keeps named locals
// and lets VC5 reuse dead homes naturally.
// continuation probes: separate count locals restored the 0x10 frame but made
// the name-length home local and worsened the result to 31 bytes. Scoped counts
// improved shape but kept that 31-byte basin. Entry declarations, while and
// guarded do-while scans, post-increment, local declaration orders, an int
// add parameter, casts, and one receiver alias did not change the clean 28-byte
// output. Scoped for-header indexes worsened it to 37 bytes. All probes were
// rolled back. Final validation remains 28 bytes, exact size, and 28 calls.
// Accepted-drift audit: do not promote. The executable has a 0x10 frame, while
// this rebuild has 0x0C. rge_read receives addresses of tempIntNum and tempInt.
// The frame mismatch changes those external writable addresses and malformed-
// input fault context, despite the aligned call sequence and equal code size.
// continuation: Ghidra's local roles support reusing playerID for the name and
// list-value reads, with one count, one index, and one tempInt local. That
// source shape rebuilt with a 0x0C frame and a 20-byte mismatch. A four-local
// value/length/count/index variant reached the prior 4-byte basin, but moved
// the hidden-self and name homes and is not retained as the clean source.
// continuation: declaration order, declaration scope, for/while/do-while
// forms, entry declarations, and scoped count locals did not improve the
// parameter-home basin. Restore the typed clean source after each diagnostic.
// canonical source-module pass: one shared PDB-backed AIModule, StrategyAI,
// ManagedArray, VictoryConditionRuleSystem, Waypoint, and TribeStrategy type
// removes all prefix redefinitions. Every preceding exact owner remains exact
// in the ordered /GX build. This surface with natural new[]/delete[] restores
// the original 0x10 frame and reduces this target from 28 differing bytes to 15. The complete
// prefix emits the same 15-byte result, so prior function bodies add no further
// codegen change. The open difference is stack-home rotation after loadRules.
```
<!-- end-recovered:e7b900cd44400e4d8bdb -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
