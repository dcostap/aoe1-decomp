# Direct-target evidence pass

Base: `d849af481`. The user requested a pass over 10 scratch evidence gaps and 31 scratch target disagreements.
The selected addresses and complete direct-call lists are preserved with the experiment evidence.
No game was run. All binary access was static.

## Scope and diagnostic correction

The pass inspected all 41 diagnostic records, original direct-call instructions, and rebuilt COFF call relocations.
It compared complete direct-call lists before selecting source changes.
This was a target-identity pass, not a complete behavior approval for 41 large functions.
Indirect calls, argument values, memory effects, and other byte differences still require their normal reviews.

The strict checker compares instructions at the same byte offset.
A shifted body can place unrelated calls at that offset.
Therefore, a target disagreement does not alone prove a wrong source call.
The checker still rejects it for positional exactness. No masking rule was weakened.
The report now records `comparison_basis: same_instruction_offset`.
A regression test keeps reordered calls nonexact even when both bodies contain the same helper set.

## Original identity evidence

### Behavior

Original EXE calls supply destination addresses. Original PDB records supply names independently of rebuilt calls.
The identity manifest retains its original EXE, PDB, and VC5 library hash checks.
New records have no aliases. The existing CRT aliases retain the proof in `crt_reference_identity_review.md`.

Original public records establish these destinations:

| VA | Symbol |
|---|---|
| `00444850` | `TDrawArea::PtrClear(RECT*, int)` |
| `0047EE90` | `RESFILE_open_new_resource_file(char*, char*, char*, int)` |
| `0045E970` | `RGE_Moving_Object::doTrivialMove(float, float)` |
| `0046B6E0` | `PathingSystem::findTilePath` |
| `00445580` | `TDrawArea::OverlayMemCopy` |
| `00445250` | `TDrawArea::PtrSpanCopy` |
| `00526170` | `TRIBE_Game::load_game(char*)` |
| `005573B0` | CRT `_memmove` |
| `0056C680` | `_ASMSet_Shadowing` |
| `0056C6C0` | `_ASMSet_ShadowingEx` |
| `0056C720` | `_ASMSet_Surface_Info` |
| `0056C760` | `_ASMSet_Color_Xform` |
| `0056C780` | `_ASMGet_Color_Xform` |
| `0056C7A0` | `_ASMSet_Xlate_Table` |
| `0056C7C0` | `_ASMGet_Xlate_Table` |
| `0056C7E0` | `_ASMDraw_HLine` |
| `0056C9A0` | `_ASMDraw_Sprite` |

The manifest stores each complete decorated name, not the shortened table description.
Section 1 starts at `00401000`. Section 2 starts at `00563000`.
Add each PDB public offset to the corresponding original EXE section start.
The nine drawing exports also agree with the previously approved drawing dependency manifest.
They do not grant permission to preserve any other binary code.

### Source

The Dib private procedures need source repair, not aliases.
Original `S_LPROC32` records identify `xlatClut4` at `0043AA90` and `xlatRle8` at `0043AAD0`.
Both use type `0x2292`: void return, C near call, and argument list `0x2291`.
That list contains byte pointer, unsigned long, and byte pointer.
The previous source used unsigned int and int, respectively, and exposed both functions through a shared header.
The repaired source uses private static definitions and unsigned long size parameters.
The VC5 canonical names are `?xlatClut4@@YAXPAEK0@Z` and `?xlatRle8@@YAXPAEK0@Z`.
The manifest accepts only those names. It does not accept the previous incorrect parameter decoration.

Both integer types have 32-bit width on the pinned compiler.
The Clut4 loop uses the unsigned count only for zero testing and decrement.
The Rle8 helper does not read its size parameter.
Their existing accepted-drift behavior reviews remain applicable; this repair adds no body operation.

### Bytes

Dib state: `7e4ea178fa1752b71e573df763f309a8db29fb41661ef3760f8cff2684ca0de2`.
Run: `64e6dadb6798e5acfab55ad018c2365cbf9362bb411666ff7c57d0f0da69160b`.
The caller remains nonexact with 761 differences. No matching Dib neighbor regressed.
Both repaired helper bodies retain every emitted instruction byte.
The existing accepted-drift `xlatClut8` changes one SIB byte at +25.
Its load changes `[edx+esi]` to `[esi+edx]`; both use the default DS segment and scale one.
The address, read width, read order, registers, branches, flags, faults, and return remain equal.
This remains a completed accepted-drift result. No further byte tuning is required without new evidence.

### Integration

Accept the independent identities and supported private helper declarations.
Do not promote the 41 scratch functions merely because an evidence gap disappears.
The final checks below record actual results.

## Array repair experiments

### Behavior

Original public linkage proves protected `ManagedArray<int>::resize` at `004147A0`.
The public QAE spelling is not an alias for the original IAE spelling.
Several source callers manually repeat subscript growth checks or force a member-pointer call.
The pass tested natural subscript access and protected resize without those forced calls.

The broad rewrite is not approved as behavior-equal.
In particular, `numberSoldiersWithPriority` can move growth across count checks and repeated element reads.
That changes the proof requirements for empty lists, allocation failures, aliases, and fault order.
These concerns are separate from its byte score.

### Source

The first candidate keeps resize in the class. The second defines it after the template callers.
Neither uses assembly, wrappers, extra friends, noinline declarations, or compiler pragmas.
The saved full patch includes all changed caller modules, not only the target's compiler input set.
The first mechanical edit stopped on an expected occurrence-count mismatch before writing `taitacmd.cpp`.
The completed edit corrected that count before capture and compilation.

### Bytes

Baseline: `4c727662e8dbfd5a1dc5dbebc76169223362a332f81d17543d36d516a9b38561`.
In-class candidate: `f51dba9e36a45c50f2c6f15b4be7e09b1513761902f475abbb43178518de7cc8`.
Its run is `1e249eff41a7be09d417af59c10b0fa41476c623c0a634d404107000c458f446`.
Out-of-class candidate: `f7efb45fcd158785e607929b3afde4ebe51937ed89c4b6b4153ccfb2dc8c0a4f`.
Its run is `f43a0e8fa841f0ae0936597b2b4109275b5e809093fc2fdd7f5c982ce32a6e50`.
Both produce the same target bytes: 2,791 differences instead of 12 for `004FDE00`.
Both change `004EF4E0` and the previously exact `005004C0` in the tactical module.
The complete shared closure is checked separately.
That closure compiles 92 modules and checks 2,891 functions.
It reports five failed matching labels: `0045A030`, `0046B680`, `004EA280`, `004EF4E0`, and `005004C0`.
Restoring the array files in the same worktree restores the three previously passing owners.
Only the original `004EA280` and `004EF4E0` disagreements then remain in the four-module baseline check.
Baseline state: `2b6bd1cd4a90c69fc6bf582e25df639b85e53c0d6ae0db10e19a6cf0cefdf9cd`.
Baseline event: `d38265632c50e0c50be17ec9498511ec65ed02f530a2e48630a79462200f303d`.
The full patch and closure are preserved by event `e4957f16ff1e981e01c993fa8bc781958d8c8b7deae3b06d4d5e25000d2d9591`.

### Integration

Preserve both candidates and their full closure. Do not integrate the broad caller rewrite without the remaining semantic proof.
Do not hide the protected/public disagreement or add a forced call to recover a score.
A useful next step is a smaller source repair per caller, with explicit allocation and fault-order comparison.
The definition-placement result excludes that one hypothesis; it does not prove a general compiler-context explanation.

## Point-increment repair

### Behavior

Original `004DFB09` pushes the amount, `004DFB0A` pushes y, and `004DFB0B` pushes x.
The call at `004DFB0C` reaches `0044E600`, the three-argument point overload of `InfluenceMap::incrementValue`.
The receiver is the original influence map at `0086BC38`.
The amount is the tile's three-bit height times five. Its range is zero through 35.
The recovered source instead called the five-argument rectangle overload at `0044E680` with duplicated x and y.
That overload clamps coordinates and retains the original rectangle y-limit bug.
The point overload rejects coordinates outside its width and height instead.
Thus, substituting a one-cell rectangle was not a proved behavior-preserving replacement.

The repair removes the duplicated x and y arguments. It keeps the receiver, coordinates, amount, loop order, and surrounding calls.
The function remains scratch. Its other differences are not approved as behavior-equal.

### Source

Keep the normal named point-overload call in `src/taiinfmd.cpp`.
No cast, wrapper, declaration change, or scheduling local is needed.

### Bytes

State: `29d4f61758c1c7bb04b6e8745d9686c95ef713389a2f8dc7ff4bece556162a55`.
Run: `4d121dcb783821676a10b308cd9b81f28010d074c5c3422da56386e0d6c22982`.
The target has 3,148 differences, compared with 3,141 before the repair.
The module check finds no matching-neighbor regression.

### Integration

Accept the binary-supported call repair despite the worse byte score.
Do not promote this function or declare the whole influence-map algorithm verified.

## Getter-order experiments

### Behavior and source

The help and dropdown diagnostics pair pure geometry getters in reverse order.
The pass tested reversal of their normal commutative source operands.
It did not add scheduling locals or forced calls to change a score.

### Bytes

Help state: `089878a6b97aff38eabd6d6bc654bc3fd6de315cfc2c0249b8958d1722e1e8f9`.
Run: `47b30fcf610c9ef4503f27d53fedc5716a76a0d215b6e492a93bbbb3931d6bee`.
Dropdown state: `9757c47900d0b02e53c08451ab43e8587f28d039317c6b811ae9c3e98ac0c00a`.
Run: `50bede43f320e545b5709634a19525d843e8dfb00cef74d51540a29141fd77a1`.
Both produce unchanged target output, with 435 and 850 differences respectively.
Both module checks retain all matching neighbors.

### Integration

Preserve the equal-output findings and restore the original source operands.
The call-order diagnostics remain nonexact. This pass does not approve either whole function as accepted drift.

## Per-target findings

An offset-shift finding explains the reported pair, not every difference in that function.
Call-list equality is only triage evidence. These rows do not approve behavior or change status.

| VA | Finding and action |
|---|---|
| `0040F530` | All 21 direct targets remain present. The reported group-count call moved from +827 to +813. |
| `00414040` | `lookupObject` moved after expanded array allocation. Tested the shared natural-array repair; no isolated call replacement is justified. |
| `0042A800` | All 23 direct targets remain present. `GetPlayerName` occurs at +954, not the reported +1022. |
| `0043A660` | Proved and repaired the two private helper types. Caller remains scratch. |
| `0043C2B0` | All 42 direct targets remain present. `get_string` moved from +542 to +555. |
| `0043D8A0` | All 108 direct targets remain present. The resource checks and float conversions occur at shifted offsets. |
| `0043E9E0` | Adjacent width and x-position getters occur in reverse order. The operand-order probe leaves output unchanged. |
| `00444680` | Original public record proves `PtrClear`. No source-call replacement is needed. |
| `00445840` | Original public record proves `ASMDraw_HLine` for all four flagged calls. |
| `0045DB90` | Proved missing movement/path identities. Other same-offset call pairs remain nonexact. |
| `0045E970` | All 78 direct calls remain present after identity resolution. Floor and waypoint calls moved. |
| `0046B6E0` | All 70 direct targets remain present. Allocation and path cleanup occur at shifted offsets. |
| `004728C0` | All 20 direct targets remain present. Unlock moved from +431 to +444. |
| `00474880` | Two height/y-position getter pairs occur in reverse order. The operand-order probe leaves output unchanged. |
| `00496800` | All 82 direct targets remain present. Reset-clocks and mouse-owner calls moved. |
| `004996C0` | Source shares the final set-button operation through final_pic, final_frame, and final_type. Two fewer emitted calls do not prove missing buttons. |
| `004A16E0` | All 101 direct targets remain present. Get-ID and scenario-player calls moved. |
| `004A2D50` | Both service-error and bad-version source branches still call get_string, sprintf, and popupOKDialog. Shared emitted code explains the count reduction. |
| `004AE070` | Source shares selected-object and amount setter paths across switch cases. Lower static call counts do not prove missing scenario writes. |
| `004BA550` | Original public records prove all four reported drawing helpers. |
| `004DB290` | All 54 direct targets remain present. The first logger call moved from +501 to +526. |
| `004DDD40` | All 30 direct targets remain present. Lookup-zone moved from +744 to +754. |
| `004DEE90` | Repaired a real wrong overload: a rectangle increment replaced the original point increment. Other differences remain open. |
| `004F13F0` | Original resize calls expanded into allocator/copy/delete code. Included in the protected-array experiment. |
| `004F1600` | Explorer task remains present at +2232. Array expansion changes preceding offsets. |
| `004F4AA0` | Real protected/public resize identity error, plus changed inlining. Included in the shared experiment. |
| `004F62C0` | Current-action and unit-AI calls remain present at shifted offsets. One fewer float-conversion call still needs control-flow review. |
| `004F81A0` | Real protected/public resize identity error and changed inlining. Keep the existing loop-increment repair. |
| `004F87B0` | Unit-AI calls remain present. Array allocation expansion shifts their locations. |
| `004FBC30` | Two resize calls have wrong access decoration. Remove-group remains present at +1913. |
| `004FC500` | All 122 direct targets remain present. Allocation and zone calls moved. |
| `004FDE00` | One resize call has wrong access decoration. Both natural-array experiments remain nonexact. |
| `0051B190` | Original public record proves the color-transform helper. |
| `0051D4F0` | Original public record proves `PtrClear`. |
| `0051E2B0` | Original public record proves `PtrClear`. |
| `00521790` | Original public record proves all eight resource-file calls and the load-game target. |
| `00526E60` | All 93 direct targets remain present. Player-name retrieval moved from +1763 to +1754. |
| `0052EF30` | All 143 direct targets remain present after the existing CRT alias. Discovery and attribute calls moved. |
| `00534AE0` | Draw-view remains present at +1769. Also proved missing draw-area helper identities. |
| `00536B40` | Original public records prove all five reported drawing calls and PtrSpanCopy. |
| `0053E910` | All 42 direct targets remain present. Pause, selection, and mouse-release calls moved. |

## Retained closure and additional exact result

The complete object comparison checks all configured owners, including equal-score changes.
It finds eight changed owner records:

- `00438820` and `00438AA0`: unchanged instructions; only the compiler's SrcXTbl suffix changes.
- `00439E50`: now exact through all 544 bytes; reviewed and promoted to matching.
- `0043A660`: unchanged instructions; the two repaired private helper names replace the wrong names.
- `0043AA60`: the reviewed, behavior-equal SIB change described above.
- `0043AA90` and `0043AAD0`: unchanged instructions with corrected private linkage and size types.
- `004DEE90`: the retained point-overload repair.

Both SrcXTbl symbols start at offset zero in their BSS section, with a declared size of 5,120 bytes.
The source still defines one table. No table read or write changes.
The renamed suffix is not a new storage owner or a cross-function symbol alias.

The `DibReadBitmapInfo` source uses ordinary Win32 bitmap structures, documented API calls, and period-style bitmap macros.
It has no wrapper, forced emission, assembly, or fake volatile object.
Its fresh standalone result is `MATCH`, `0.0000%`, with correct ownership, boundaries, relocations, and all ten calls aligned.
The existing candidate remains preserved as `00439E50_pre_target_pass_candidate.patch`.
The canonical candidate now contains the complete retained patch, not the rejected array rewrite.

No previously passing matching owner regresses in the retained changes.
The array closure is separate rejected evidence; its failures are not hidden by the retained results.

The rejected closure's map change uses different byte registers for two OR results and their stores.
The path decrement changes register allocation, adds an EDI save, and retains the same packed-field address calculation.
The best-group change reverses adjacent id and assistGroupID getter calls.
These observations do not establish a new behavior defect in those unchanged source bodies.
They remain repair leads, not reasons to add compensating source or approve the broad array rewrite.

## Final validation

- All 41 selected functions have zero direct-target evidence unknowns.
- Their primary categories are now 32 positional target disagreements, seven other mismatches, and two boundary problems.
- All ten initial evidence gaps are resolved. Other differences still prevent their promotion.
- Fourteen previously unvalidated matching claims now pass, in addition to the new Dib promotion.
- Of 4,887 matching labels, 4,854 pass. Thirty-one evidence gaps and the two original resize disagreements remain.
- All 225 audit modules compile. The exact-claim gate intentionally remains nonzero for those 33 old claims.
- The executable build compiles 226 C/C++ sources and one assembly source, then links without unresolved symbols.
- Linked references: 6,853 passes, 5,269 unknowns, zero failures. Unknowns remain unproved, not passes.
- Header emissions: 132 matching selections, one existing RESENDER difference, zero unknown selections.
- Tests: 413 passed and 31 subtests passed. Registry validation, line endings, and diff checks pass.

Final registry totals: 4,887 matching, 287 accepted drift, 16 verified logic, and 236 scratch.
No unresolved, unclaimed, or conflicting ordinary function remains.

Final build: `build/executable/target-pass-complete/20260908T163118033781Z`.
Final reports: `build/target-pass-complete/`.
Final source receipt: `40495926dbf4d40ac56891f43dabae3c16398c6bb79140e759df9b85503e4597`.
Archive event: `0e8de46680cc38d9685da40bd9f609dd38141d74f143f2b4fae306f350d0789d`.
It preserves the PDB dumps, all 41 call investigations, candidate inputs, full rejected closure, final objects, image, maps, logs, and tests.
The store check verifies ten states, twelve events, 154 referenced objects, parent records, and reachable base commits.
The status-only promotion changes no object content except COFF timestamps across all 225 audit objects.
The full owner comparison confirms the same eight changed records against the original baseline.

The isolated workspace and all build outputs remain available. No game was run. No commit was pushed.
