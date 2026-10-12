# Review: `src/map.cpp` worker `sa-c94ca0bf-map`

Workflow: matching with reviewers.

Reviewer: `sa-9e7f7a33`.

Base: `efb24b1c9eb0895730db5d5a444f7ed6cff2fe9d`.

Compiler-input fingerprint: `85f1eb3ed6d2f744b00f1c9433562f0cefb8f1b560a9dd81177af505b46d467b`.

## Verdict

**NEEDS_CORRECTION** for the worker handoff package. No source integration is
approved. No status promotion is approved. Keep all seven functions in
`scratch`.

The evidence states and run results are valid for preservation. The handoff
has one false candidate-path claim. The target-session files are empty and do
not record the fresh checks. Use the durable state and run event records as
the review authority.

## Scope and input review

The reviewed source is the clean `src/map.cpp` at the base commit. The source
hash in the recorded states is
`2288ba0cc672a4cf4d6e528a2cdbfc995842129409c0280f48a2805e4f6e00f21`.
The worker changed no source, header, registry, status, candidate, or test
file. The seven changed function notes describe the same natural source.

The seven target-session files have `probes: []`, empty `last_metric_summary`,
and empty `clean_baseline` objects. Their `updated_at` values are between
`16:14:24Z` and `16:14:27Z`. They are stale freshness indicators, not fresh
check records. The durable run events below contain the actual checks from
`16:15:35Z` through `16:17:20Z`.

## 00456170 `postclean_elevation`

### Behavior

Static evidence supports the map row table, 24-byte tile stride, elevation
byte, eight-neighbor checks, and one-level update. The source keeps the
observed no-call control flow. No runtime test covered malformed bounds,
negative or extreme elevations, or fault order.

### Source

PDB evidence supports the formal values, long index roles, short offsets, and
map/tile ownership. The source uses typed fields and natural loops. It has no
raw address, wrapper, artificial alias, or inline assembly. A different local
flag and home layout remains unresolved.

### Bytes

State `1560919b0d4b3fc93cfaadeb1b3f6551b4f0588ec22be5fd4d59719fb57f003d`.
Run event `757f7ae4b69f40cea0b06a97b2101815`.

The check reports 880 original bytes and 871 rebuilt bytes. It reports 719
strict differences, 72.85% shape similarity, and 35.40% exact-block coverage.
Both frames are `0x24`. Both call sets are empty. The owner and boundary match.
The target remains `MISMATCH`.

Check object: `055cbcde6709bca43c5503cbcc931a44dc0218e8af009357829331b62e242400`.
Closure report object: `93159d60ea300162ad4a52773476063c059f0a9c4f1d2b93fe3a2d66e547c909`.

### Integration

No source or accepted-drift proposal exists. Keep the function in `scratch`.
Preserve the state, run event, check, and closure objects. New work needs
source evidence for the byte flag, local-home reuse, or compiler context.

## 00457F80 `load_terrain_types`

### Behavior

Static evidence supports the typed parser, 19 tile records, sound lookup,
name copies, record publication, and file close. The source retains partial
conversion and unbounded-string fault risks. No malformed-input runtime test
covered these risks or their fault order.

### Source

PDB evidence supports the narrow parser fields, float fields, `FILE*`, and long
resource ID. The source uses typed `RGE_Tile_Set` and `RGE_TOB_Picts` ownership.
It does not retain the decompiler's unsafe stack overlays. The parser's local
homes still differ from the target.

### Bytes

State `5168fe6d3d87d15884198978ccc1cee2d9647845f5efd0b382c2f180765bc4b0`.
Run event `f641ea07469842b8940ae068899f7da0`.

The check reports 762 original bytes and 764 rebuilt bytes. It reports 331
strict differences, 77.08% shape similarity, and 9.66% exact-block coverage.
The frames are `0x5C` and `0x60`. All eight ordered calls align. The owner
matches. The rebuilt body escapes the target boundary by two bytes. The target
remains `MISMATCH`.

Check object: `42ec34efe86bc422c07265e034bcf6dd5d2afdfe08dbdba31319120b7aa7da2c`.
Closure report object: `3fb30b33d4f495c667412eb4d7d8d24df9f2ed61ded102c8cff9758d77fe52d9`.

### Integration

No source or accepted-drift proposal exists. Keep the function in `scratch`.
The partial-conversion and string-overflow paths block any future accepted-drift
claim until their memory effects and fault order are proved.

## 00458350 `load_border_types`

### Behavior

Static evidence supports the typed border parser, 19 by 12 picture grid,
sound lookup, name copies, animation fields, and file close. Partial scans,
string overflow, timing faults, and fault order were not runtime-tested.

### Source

PDB evidence supports the narrow parser fields, float fields, `FILE*`, and long
resource ID. The source uses `RGE_TOB_Picts` and `RGE_Border_Set` ownership. It
keeps distinct parser fields instead of unsafe decompiler stack overlays.

### Bytes

State `2a0a9ea9d909fa6be18fc4c0d497d9f58bbfccee0417c8106f26a138ea65df1a`.
Run event `f04dfac405234f54bfaedf7ec923f05c`.

The check reports 679 original bytes and 673 rebuilt bytes. It reports 492
strict differences, 84.58% shape similarity, and 19.16% exact-block coverage.
Both frames are `0x58`. All seven ordered calls align. The owner and boundary
match. The target remains `MISMATCH`.

Check object: `3bbe9ac9a2eb1147266de7b0f7d4cfd7bd610610e5c6f160734448d76d7befc8`.
Closure report object: `380cd32e72d783cfd0cfa2297b60f6e33ed860dbc92e93ff21bcca155b1cd8fc`.

### Integration

No source or accepted-drift proposal exists. Keep the function in `scratch`.
New work needs evidence for the row-anchor and parser-local allocation.

## 00458820 `create_terrain_object`

### Behavior

Static evidence supports old-object cleanup, the compatible-object scan, the
placement mode, density loop, random calls, and ten ordered calls. Random
placement, object-list mutation, and object fault paths were not runtime-tested.

### Source

PDB evidence supports the formal names and types, float coordinates, short
`end_i`, and byte placement flag. The source uses typed map, tile, object-node,
player, master-object, and terrain-set ownership. The adjacent object-table
cursor is binary-supported. No raw virtual-table code or wrapper is present.

### Bytes

State `28e522f6837525875d4ca43f80bffabf780f345811e3c926a87fc4d10dc8843c`.
Run event `3ab1e91b8dbb4a27ab584e2b0a3d12e6`.

The check reports 794 original bytes and 759 rebuilt bytes. It reports 683
strict differences, 85.48% shape similarity, and 58.51% exact-block coverage.
Both frames are `0x10`. All ten ordered calls align. The owner and boundary
match. The target remains `MISMATCH`.

Check object: `504010b0c35f66847f4aeb7cefbef9d2d3a56de9253379c5a62c3ac81f7b24b7`.
Closure report object: `9e17cc59a2022e3478d44e58235631088d37fd3712be561ba2fc59e0aaf5c29d`.

### Integration

No source or accepted-drift proposal exists. Keep the function in `scratch`.
New work needs evidence for initial register allocation and replacement-scan
topology.

## 00458B40 `clear_terrain_object`

### Behavior

Static evidence supports the tile object-list walk, inclusive keep range,
terrain-object scan, virtual deletion, destruction, placement test, and seven
ordered calls. List mutation and virtual cleanup paths were not runtime-tested.
The target's post-placement list-node reload remains a behavior-sensitive
question.

### Source

PDB evidence supports `gworld`, the short row and column formals, the three
integer flags, `list`, and `next_list`. The source uses typed object and master
ownership and a bottom-tested scan. It does not use raw virtual-table code.

### Bytes

State `90bd4456aafc2c94c36f6980a71494a18ea6e4ddecc2d43825f152c0bd29ad45`.
Run event `31b85216cf5e464b923ce72154ff9eb9`.

The check reports 321 original bytes and 343 rebuilt bytes. It reports 322
strict differences, 78.40% shape similarity, and 5.13% exact-block coverage.
Neither object has a frame. All seven ordered calls align. The owner matches.
The rebuilt body escapes the target boundary by 22 bytes. The target remains
`MISMATCH`.

Check object: `7157d3607d4ed3dd8fe94525615490e18f6206b1b09086f90107fc2039c9c251`.
Closure report object: `6f256f66c62a77b4fe52c0bb35499c2c1b9329185680e98efe02dabaa0e7f8e8`.

### Integration

No source or accepted-drift proposal exists. Keep the function in `scratch`.
The handoff claims that
`workflow/decomp_notes/candidates/0045/00458B40_exact_candidate.patch` is preserved.
Direct file inspection found no such file. Git history also contains no such
path. Do not treat that candidate as preserved. A historical or stale claim
must be corrected. The fresh target result is not an exact candidate.

## 00459060 `tile_map_coords`

### Behavior

Static evidence supports the tile-local coordinate mapping, period x87 switch,
two float outputs, and known tile cases. Unordered comparisons, NaN inputs,
and extended-precision rounding outside the checked instruction paths remain
unknown. No runtime test covered these cases.

### Source

PDB evidence supports short coordinates, `RGE_Tile*`, two float outputs, and
double `z`. The source uses typed fields and the known raw-y comparisons. It
keeps no forced register, floating temporary, wrapper, or inline assembly.

### Bytes

State `914d07b63a3f72c306ea8bf246b5bfce16eb092f755e3dea6e3cd2a0c7b60124`.
Run event `cd4a581ed37541f0a4a2d7dfab955002`.

The check reports 754 original bytes and 754 rebuilt bytes. It reports 338
strict differences, 93.18% shape similarity, and 80.00% exact-block coverage.
Both frames are `0x10`. Both call sets are empty. The owner and boundary match.
The target remains `MISMATCH`.

Check object: `6bfaa0afef5d0c11ca6f623f847e708dcfedef1b015ba48ffe51b180b161e6af`.
Closure report object: `5c2ab0b6dc93647ea034f7cb6cb2e0a73759f189c2889ef7c0f0845ba7a8723a`.

### Integration

No source or accepted-drift proposal exists. Keep the function in `scratch`.
The x87 expression and jump-table source remain open. Do not promote this
function from byte similarity alone.

## 00459A90 `set_terrain`

### Behavior

Static evidence supports terrain validation, rectangle swaps and clamps,
eligible tile updates, object rebuild, border recomputation, and redraw. The
source preserves high terrain bits and the old terrain argument. Invalid
coordinates and malformed map state were not runtime-tested.

### Source

PDB evidence supports separate map row and column formals, byte terrain and set
flags, and the typed row and byte cursor pattern. The source uses canonical tile
and terrain-set ownership. It has no unsupported alias or raw offset.

### Bytes

State `4b5278d684ab6c15afbb3e51793cb0ed5dcf413fd994a2c3dde3fb16f542e0bf`.
Run event `4be2a788fb4e4522b5f734397cbf6d84`.

The check reports 649 original bytes and 644 rebuilt bytes. It reports 485
strict differences, 72.25% shape similarity, and 37.02% exact-block coverage.
Both frames are `0x14`. All three ordered calls align. The owner and boundary
match. The target remains `MISMATCH`.

Check object: `0c9808d51899bd74ebd84a35d1f2151c1f41479d2014ec76417c96692c5a1663`.
Closure report object: `bb93e6c285621970b850eecc80a3d2bea03459c07d74f3223376331d5a1e8cc9`.

### Integration

No source or accepted-drift proposal exists. Keep the function in `scratch`.
Earlier notes describe a behavior-equal natural source, but this worker did not
submit an accepted-drift proposal. Do not infer status from those older notes.

## Closure and preservation

Every fresh check used `--closure --jobs 1` with the same compiler-input
fingerprint. The closure compiled 64 normal owners. It reported 52 matching
owners, 12 nonmatching owners, and zero compile errors. Its category counts
were 52 matching results, five grouped mismatches, four accepted-drift
observations, and three boundary problems.

The seven closure owner code and relocation manifests reconcile with no change
outside the assigned target results. This supports a no-regression finding.
It does not prove target behavior or accepted drift. The target rows have
`owner_status: match` but `matching_anywhere: false`. Boundary escapes occur
at 00457F80 and 00458B40. No target has a `MATCH` result.

Preserve all seven states, seven run events, target checks, closure reports,
owner manifests, rebuilt objects, and source diffs. The declared 00458B40
candidate is not available for preservation. Preserve the correction finding
instead.

## Integration decision and corrections

Source acceptance: **reject**. The clean typed source is plausible, but the
worker submitted no source proposal, exact result, or accepted-drift proof.

Status: **keep `scratch`** for all seven functions.

Experiment preservation: **approve** the recorded states and run evidence.
The orchestrator must preserve their event and object records before worktree
reuse.

Requested corrections:

1. Correct the handoff. Remove the claim that the 00458B40 candidate exists.
   Add a durable finding that the file and Git history path are absent.
2. Mark the seven empty target-session files as stale metadata. Use each
   state ID and run event ID above as the fresh-result identity.
3. Refresh any dashboard that still reads `target-session` freshness fields.
   Do not replace the durable event results with empty target-session data.
4. If a later worker submits accepted drift, prove ABI, memory effects, calls,
   cleanup, exceptions, faults, and fault order. Cover malformed parser input,
   string overflow, object-list mutation, invalid bounds, and x87 unordered
   cases. No such proposal is approved by this review.

Restart review when the handoff and durable references are corrected. No new
compiler probe is required for these reporting corrections.

## R2 recheck

Worker `sa-c94ca0bf-map` supplied an evidence-only correction. The correction
events are `a368f88eaacb40feafb7f258aeccb084`,
`85e7ddcdfe96476389de7d67bc188a99`, `79c617aae84b4060800a717fff3eddcc`,
`4546a2f2f975435e8cc81764c05af7ba`, `5100ea2fe68c43ba88f9daab3442ef5b`,
`25a2695caa574167957f100465f26df0`, and
`11d43fbad0034e9f8dd5a4dd448b0801`. They attach the correction handoff
object `204110232ff3c4e21763c2ef6b995309e54f3b4b2c6cb5c962d5c9ae653076ee`.

The current function notes label all seven target-session files as stale
metadata. The `0045A030` note now calls the old work a historical experiment.
Direct inspection finds no `00458B40` candidate file, tracked path, or
reachable history path. The candidate-absence object is
`f1a507298325b671fdd3c9db327e347858bfe612da19146545accd66d205a8a5`.

Independent checks confirm that all seven durable states use base
`efb24b1c9`, source hash
`2288ba0cc672a4cf4d6e528a2cdbfc995842129409c0280f48a2805e4f6e00f21`, and
compiler fingerprint
`85f1eb3ed6d2f744b00f1c9433562f0cefb8f1b560a9dd81177af505b46d467b`.
Each durable run event points to the correct target state and reports the
same mismatch as the original review. Independent SHA-256 checks confirm all
seven closure report objects listed above. The durable events and closure
files are authoritative.

One supporting-artifact defect remains. The correction handoff lists an
incorrect closure hash for `00458B40`: it gives
`6f256f66c62a77b4fe52c0bb35499c2c1b9329185680e98efe51b180b161e6af8e8`.
The run event `31b85216cf5e464b923ce72154ff9eb9` and its closure report give
the correct hash:
`6f256f66c62a77b4fe52c0bb35499c2c1b9329185680e98efe02dabaa0e7f8e8`.
The bad list entry does not change the authoritative run or closure file, but
it is an invalid durable reference in the supporting handoff.

No prohibited source, header, flag, registry, inventory, oracle, or test file
changed. No compiler probe ran. The correction resolved the candidate and
freshness objections, but the closure-list typo needs correction.

**R2 verdict: NEEDS_CORRECTION.** Keep all seven functions in `scratch`.
Do not integrate source or status changes. Correct the one `00458B40` closure
hash, then request a final evidence-only recheck. No new compiler probe is
needed.

## R3 recheck

Worker correction event `31e520e77d7b4dd5890ab19f7fce82c5` points to the new
correction handoff object
`3c28a7a23ab9900f0bb578aac0eba003da23bac24b793967a22e15de79980aa1`.
The current correction handoff and main handoff use the authoritative
`00458B40` closure hash
`6f256f66c62a77b4fe52c0bb35499c2c1b9329185680e98efe02dabaa0e7f8e8`.
The wrong hash no longer occurs in either handoff. The authoritative object
exists at `workflow/decomp_notes/experiments/objects/6f/` and matches the on-disk
`build/experiment_runs/3f374fb135154ffcb42be0e34b02bbf5/closure/report.json`.

The wrong hash remains once in this report as the historical R2 correction
finding. It is not an active evidence reference.

The seven target states, run events, stale-session labels, candidate-absence
finding, and closure results remain unchanged. No source, header, flag,
registry, inventory, oracle, or test path changed. No compiler probe ran.

**Final verdict: APPROVE the evidence-only correction.** This approval does
not approve source integration or a status change. Keep all seven functions in
`scratch`. Preserve the corrected handoff, correction event, durable states,
run events, closure objects, and this report. No further reviewer correction
is required.
