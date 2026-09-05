# Shape.cpp module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\Shape.cpp`.
- Source: `src/Shape.cpp`.
- Header: `include/Shape.h`.
- Flags: `config/flags/default.rsp`.

## Context gate

- PDB source module: proved by the PDB packet as `Shape.cpp`.
- Source lines and order: proved by the packet. The 26 normal owners span lines
  53-3243 and remain in increasing address and source order below.
- Owning class: proved by PDB symbols as `TShape` for all 26 owners.
- Address sequence: proved by the packet: `004B8B30`, `004B8B50`, `004B8DD0`,
  `004B8E40`, `004B8F90`, `004B8FB0`, `004B9040`, `004B9070`, `004B9140`,
  `004B9440`, `004B97F0`, `004B98E0`, `004B99F0`, `004B9AF0`, `004B9E20`,
  `004BA1C0`, `004BA550`, `004BA900`, `004BA9E0`, `004BAAF0`, `004BAC00`,
  `004BAF20`, `004BB280`, `004BB5E0`, `004BB770`, `004BB910`.
- Exact anchors: proved by the existing owner symbols, direct call targets,
  field offsets, and the original Shape.cpp assembly. Examples include the
  `TShape::Check_shape` call before each renderer, the `TDrawArea::AlignedWidth`
  call in the raster helpers, and the `ASM*` and `DClipInfo_List` calls in the
  two dispatchers.
- Nearby compiler-generated owners: none in the packet.

## Migration

The module has one source file and one module header. The source keeps all 26
normal definitions in PDB order. It has no wrapper, source-bank include,
function-fragment include, fallback class declaration, recovery context macro,
or helper macro. The old source-bank files are removed after this source is
validated. The module metadata records each prior source status.

The source keeps the reviewed typed Shape records, `TShape` layout, draw-area
layout, packed RLE ownership, and direct external call declarations. It does not
add a new global definition or change a cross-shard declaration.

`color_log` uses its canonical C++ declaration from `include/colorlog.h`.
The former local C-linkage declaration conflicted with the source-owned symbol
after the BaseGame friendship recovery.

## Prior state and expected migration effect

The prior `shape` translation-unit entry registered 11 owners. The module
packet reports 12 matching-bank owners and 14 scratch owners. The two matching
owners not in the old registered entry are `004B99F0` and `004BA9E0`. The merged
source is not byte-tuned during this structural migration. Isolated exact
results are not claims about the merged source.

The 14 scratch owners remain unresolved after migration unless fresh grouped
validation proves otherwise. Their open evidence is mainly VC5 local-home,
register, loop, and clipped-RLE topology. The source retains the simplest
reviewed typed reconstructions and does not retain raw address views, volatile
home forcing, inline assembly, or synthetic owners.

## Validation and regressions

Validation is recorded here after the direct translation-unit check. Grouped
mismatches are not exactness or behavior claims.

- Candidate proposal: `build/candidate_tus/Shape.json`.
- The candidate validator is a pre-migration gate. It rejected the post-move
  direct source because it expects each owner in a legacy source-bank include.
  It produced no report. The direct translation-unit validator passed after
  the source move.
- Grouped audit: `build/audits/Shape_migration_final/report.txt`.
- Grouped result: 26 owners compiled. The final rerun after source cleanup has
  11 registered owner matches, 12 grouped mismatches, and three boundary
  reports.
- Exact grouped owners: `004B8B30`, `004B8DD0`, `004B8E40`, `004B8F90`,
  `004B8FB0`, `004B9040`, `004B9070`, `004B97F0`, `004BA900`, `004BA9E0`,
  and `004BAAF0`.
- `004B99F0 shape_shadow_unclipped` differs by 73 bytes in the merged source.
  It is scratch. It was not a registered direct owner.
- The canonical Drawarea header changes `004BA9E0` by 98 bytes and `004BAAF0`
  by two bytes. Both are now scratch and no longer registered exact owners.
- Remaining grouped differences are recorded without status promotion. The
  largest strict differences are `004BB910` 1208 bytes, `004BAF20` 788 bytes,
  `004B9E20` 804 bytes, and `004BA1C0` 853 bytes.

## Blockers

- The assigned `build/source_reunification/terra_system/orchestrator_contract.md`
  and its Terra module packet are absent from this checkout. The generated
  `build/tu_plans/Shape_cpp/packet.{json,txt}` is the available module packet.
- The current source contains several unresolved clipped and dithered renderer
  reconstructions. Their prior notes identify broad VC5 frame, home, register,
  and RLE block differences. This migration does not claim exactness for them.

## ABI compile repair

The View header is the canonical declaration owner for the shared drawing
globals. The PDB symbols prove `long SDI_Object_ID` and `long fog_next_shape`.
The Shape source now uses those declarations instead of duplicate local types.
Shape.h also publishes the PDB-proven C++ globals `shape_file_first`,
`Shape_Loads`, and `ASM_Fast_Count` for its consumers.

The full Shape source now compiles. `004B8B30`, `004B8E40`, and `004BA900`
remain `MATCH` with `0.0000%`. Existing scratch renderer differences remain
unchanged.

## Read-only closure audit at 20dea9ff

This section supersedes earlier baseline counts, not the recorded experiment history.
The worktree was clean at `20dea9ff68c62663f103246b6afa7210c1e8390d`.
No source, header, flag, or registry changed during this audit.

The live normal-corpus query returned 4,746 matching, 277 accepted drift,
17 verified logic, 220 scratch, and 166 unresolved functions.

Command:

```text
python tools/audit_translation_unit_functions.py --group shape --jobs 1 --output-dir build/audits/shape_readonly_20dea9ff
```

The audit compiled all 26 owners. All 11 exact owners returned `MATCH` with
zero differences, matching ownership, and no relocation or boundary problems.
`004B99F0` retained its accepted drift with two differing bytes.
The other 14 owners remain scratch. Three have boundary reports.

Report: `build/audits/shape_readonly_20dea9ff/report.json`.
Input fingerprint:
`d2a4bd1bcae4401cb95e10e49d3019f923f0f4f326226eb0be007cba39efa166`.

Protected exact owners:
`004B8B30`, `004B8DD0`, `004B8E40`, `004B8F90`, `004B8FB0`,
`004B9040`, `004B9070`, `004B97F0`, `004BA900`, `004BA9E0`, `004BAAF0`.

### Initial evidence map

This is a repair selection map, not a complete semantic approval.
Difference counts come from the fresh grouped audit.
Only the two row-start defects below received new instruction-level proof.
Other leads come from existing function notes and need independent review.

| VA | Differences | Evidence or next review |
| --- | ---: | --- |
| `004B8B50` | 561 | Preserve the corrected filename passed to `open`; review scheduling and the boundary overrun. |
| `004B9140` | 501 | Preserve the extended-skip payload advance; audit SHP and SLP command paths separately. |
| `004B9440` | 850 | Review clipping bounds and dispatch calls; prior source changes affected exact neighbors. |
| `004B98E0` | 255 | Prior notes identify setup read-order differences; no accepted-drift proof exists. |
| `004B9AF0` | 769 | Saved row start exists; compare clipped run endpoints and state transitions. |
| `004B9E20` | 799 | Confirmed defect: next row starts from the final write cursor. |
| `004BA1C0` | 821 | Saved row start exists; review shadow lookup order and clipped counts. Boundary report remains. |
| `004BA550` | 509 | Review mirrored bounds and dispatch arguments before local allocation. |
| `004BAC00` | 503 | Preserve the full-literal repair and separate row start; audit edge crossings. |
| `004BAF20` | 745 | Separate row start exists; audit reverse translated payload consumption. |
| `004BB280` | 773 | Separate row start exists; audit reverse shadow reads and writes. |
| `004BB5E0` | 241 | Prior notes place the first difference at coordinate setup `+0040`; review bounds. |
| `004BB770` | 394 | Fresh original extraction confirms separate row-start advancement; do not copy the old contrary claim. |
| `004BB910` | 1209 | Confirmed defect: `save_buffer = dst + width` loses the saved row start. |

### Confirmed shared mistake

Two reconstructions confuse the current write cursor with the saved row start.
This changes valid multirow output. It is not only a malformed-input fault issue.

For `004B9E20`, the executable saves the initial destination at `004B9E81`.
At `004BA18C`, it reloads that saved destination before adding pitch.
The current source instead adds pitch to the advanced `dst`.
The function note records a prior supported repair rejected for worse byte counts.
That rejection does not justify retaining incorrect row behavior.

For `004BB910`, `[esp+18h]` holds the saved destination, despite the listing's `width` label.
`004BB96D` initializes it. `004BBE0A` reloads it, and `004BBE1F` stores the next row start.
The intervening pixel loops change `ecx`, not this saved stack slot.
The current source instead saves the advanced `dst` plus pitch.
The pass-3 claim that the executable uses the final write cursor is incorrect.

Fresh extraction used `tools/extract_original_function.py --va` for
`004B9E20`, `004BB910`, and the donor `004BB770`.
The tool read the repository-local original executable.
The donor also reloads its saved row start at `004BB8E3` before adding pitch.
Do not infer stack-slot behavior from a decompiler variable name.

### Selected next repair and validation

Repair `004B9E20` first. Keep a saved row start separate from `dst`.
Advance the saved pointer by pitch, then use it for the next row.
Do not change packet decoding, table access, shared types, or compiler flags in this repair.
Then repair the same row-start error in `004BB910` as a separate change.

Direct callers are `004B9440 shape_draw` and `004BB5E0 shape_dither`, respectively.
Both callees and callers belong to `src/Shape.cpp`.
Validate each target and all 26 Shape owners after each change.
Inspect caller argument setup and all changed compiled owners.
Preserve exact candidates if they change another owner.
Do not restore a proved row defect merely because the strict difference count increases.

Use two-row literal, fill, and skip tests with both orientations.
Include left-edge and right-edge clipping, empty rows, and translated-table overlap.
Compare write addresses, payload advances, table reads, calls, and fault order.
The analytical counterexamples are recorded in the two function notes.
They were not executed in this audit.

No tracked candidate patches were found under `decomp_notes/candidates/004B/`.
Prior rejection evidence remains in the function notes.
ManagedArray remains paused. No exact promotion or accepted-drift approval is claimed.

## Retained row repairs and executable tests

Both selected row repairs are now retained in `src/Shape.cpp`.
No shared header, registry entry, compiler flag, or ManagedArray source changed.

| VA | Baseline differences | Final differences | Final size |
| --- | ---: | ---: | ---: |
| `004B9E20` | 799 | 796 | 886 |
| `004BB910` | 1209 | 1248 | 1313 |

The larger dither difference count does not justify restoring wrong row behavior.
Both targets remain scratch. Their complete semantic equivalence is not proved.

The first repair audit is `build/audits/shape_color_row_repair/report.json`.
Its input fingerprint is
`dc2067905885688b8c31e5231c87911f4916e5f5334eab1749075df9e010fae6`.

The final audit is `build/audits/shape_row_repairs_final/report.json`.
Its input fingerprint is
`9234e216394e2457d256f5276c7c3fd7655de8dd40bf76f5783f3729a17d5af2`.
All 11 exact owners remain exact. The accepted-drift owner remains unchanged.
Only the two repaired targets changed their grouped audit metrics.

A full object-section comparison found two additional compiler effects:

- `004BB280` changed six equivalent SIB encodings. Its function note proves equality to the previous reconstruction.
- `004B9140` retained identical bytes. Its jump-table label changed from `$L25190` to `$L25191`.
  Both labels resolve to offset 632 in section 28 of their respective objects.
  All other relocation targets remain unchanged.

Every other registered function section retained its bytes and relocation target names.
Thus the source repairs did not hide an unexplained neighbor change behind unchanged difference counts.
The direct callers also retained their bytes and relocation targets.

### Native binary probe

The retained test consists of `tests/run_shape_row_probe.py` and `tests/shape_row_probe.cpp`.
It runs extracted original instructions and audited rebuilt object bodies in a native x86 process.
The pinned VC5 toolchain builds only the test driver.
The test does not copy decoder source or change game declarations.

The driver redirects only `AlignedWidth` and `memset` calls.
Its pitch stub reads the proven `TDrawArea::Pitch` field at offset `0x20`.
Its fill calls use the VC5 CRT. These substitutions limit the proof.
The test does not claim original CRT fault behavior or arbitrary-input equivalence.

Commands:

```text
python tests/run_shape_row_probe.py --object build/audits/shape_readonly_20dea9ff/objects/shape.obj --output-dir build/shape_row_probe/baseline
python tests/run_shape_row_probe.py --object build/audits/shape_row_repairs_final/objects/shape.obj --output-dir build/shape_row_probe/repaired
```

The baseline fails 248 of 320 cases: 128 translated cases and 120 dither cases.
The repaired object passes all 320 cases.
Each run saves `result.txt`, `compile.txt`, and input hashes in `inputs.json`.
The baseline command returns one, as expected for the negative control.

The cases cover two visible rows, both orientations, horizontal and vertical clipping,
literal packets, fill packets, transparent skips, empty rows, mixed packets, and table/output overlap.
They compare return values and complete destination, source, and table buffers.
They do not measure read order or prove equal faults for malformed memory.

### Repository tests

`python -m unittest discover -s tests` ran 269 tests with four failures.
The failures concern unchanged inputs outside this repair:

- a status label in `decomp_notes/functions/0041/00410220.md`;
- a required phrase missing from `agent_roles/orchestrator.md`;
- a header-module count assertion expecting 17 instead of 16;
- a registry-module count assertion expecting 242 instead of 241.

The affected note, role document, registry, and test assertions were not changed.
No unrelated test or policy edit is included to hide these failures.
The authoritative project counts remain unchanged.
