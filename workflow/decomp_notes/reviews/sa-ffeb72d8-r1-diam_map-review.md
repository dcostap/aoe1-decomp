# Independent review: `sa-ffeb72d8-r1-diam_map`

## Review identity and scope

- Workflow: matching with reviewers.
- Reviewer: `sa-3bac1f3e-r1`.
- Worker package: `workflow/decomp_notes/reviews/sa-ffeb72d8-r1-diam_map.md`.
- Reviewed worktree: `C:/Projects/my_decomps/aoe1_reviewer_wave_16`.
- Branch: `reviewer-wave-16`.
- Base: `420bec2d2954ba5772d1c790bd5bad68f6678f21`.
- Source scope: `src/diam_map.cpp`.
- Targets: `00436C30`, `00437760`, `00437EC0`, `004381D0`, `00438250`.
- Current source SHA-256: `bd83e71dd589cd062b0338dce97492e58f122b6c179c8cfbea5b272056ab4a30`.
- Flags: `config/flags/gx.rsp`, SHA-256 `3d3df63d7a3968452015f2f7f3c07539c01b27038bcd0d1236cbd4e22886425e`.
- Common final input fingerprint: `2e6211232ab50b81a8f01d74b27d9702dc742ba372972d7fff6b0a88e91bd7ae`.

The source, headers, flags, registry, inventory, and tests were not changed.
The worker package and the worker's modified function notes were read as inputs.

## Verdict summary

All five dispositions are **APPROVE, evidence-only**. This approves the
worker's preservation and scratch conclusions. It does not promote a status,
accept an exact result, or accept drift.

| VA | Function | Disposition | Source decision | Status decision |
|---|---|---|---|---|
| `00436C30` | `set_world` | APPROVE | Keep natural source | Keep `scratch` |
| `00437760` | `draw_tile` | APPROVE | Keep natural source | Keep `scratch` |
| `00437EC0` | `draw_visible_object` | APPROVE | Keep natural source | Keep `scratch` |
| `004381D0` | `draw_clipped_horz_line` | APPROVE | Keep natural source | Keep `scratch` |
| `00438250` | `draw_view_rect` | APPROVE | Keep natural source | Keep `scratch` |

No exact claim or accepted-drift claim is supported for any target.

## `00436C30` `set_world`

### Behavior

The source preserves world and map publication, old row-table cleanup,
allocation, image-line mapping, row-table stores, the second pass over rows,
view reset, and the redraw call. The original has a duplicated x87 row
quotient. The rebuild spills and reloads a quotient. This can change rounding
and map geometry. No runtime harness covered allocation failure, malformed map
sizes, or fault paths.

PDB scope supports `RGE_Game_World* world_in`, `float col_step`, `short
tot_draw_wid`, overlapping `short draw_wid` and `float tile_row`, and `short
line`. The original direct calls are `free`, `calloc`, four `__ftol` calls, and
virtual slot `+0x20`.

### Source

`RGE_Diamond_Map::set_world(RGE_Game_World*)` is the canonical owner in
`src/diam_map.cpp`. The source uses typed map and row structures. It has no
inline assembly, wrapper, or compiler-steering construct. The x87 expression
that selects the original extended-precision lifetime remains unknown.

### Bytes

The fresh final check is `MISMATCH`: 148 differing bytes in an exact 1081-byte
body, 96.0993% shape, an exact `0x10` frame, exact boundary, matching owner,
and 7/7 ordered calls. The first mismatch is `+0x14F`. The final event is
`c03b6a6b998441e6a39a7b273abfad60`, file
`5e410df02eb1b02f2d2263bebcdf03b16b8425324eb44dc5115cb46556a8772b.json`.

The baseline state is
`b9b77ffe50cbcef5fffca05f2736716f8059e0201da71323dd3acea6b56354b8`.
The rejected direct draw-step state is
`ac78879f4498d9fb207771ca75c975f8450b46deb87b8436ff9d527569f0bdb5`.
Its event is `fc0a3f92ee4f427f8d9e607f265a07d3`, file
`2d55f18874dff139e2292ca499c6adab5046fbb36a2251d210d50e273f058553.json`.
The rejected probe produced 715 differing bytes. The source was restored.

### Integration

Approve preservation only. Keep `scratch`. Do not promote the target or accept
the x87 difference as drift. Reopen only with period source or stronger x87
lifetime evidence.

## `00437760` `draw_tile`

### Behavior

The source preserves typed map and tile access, visibility gating, terrain
color selection, level-4 object color scanning, fog mode, and pixel writes.
The original has 12 calls: two `__ftol` calls and ten `SetPixel` calls. Width,
signedness, local homes, and the full scan CFG remain unproved for all inputs.
No runtime harness was run.

PDB scope supports short `col` and `row`, int `fog`, unsigned-byte
`override_color`, long `x` and `y`, an `RGE_Tile*`, an unsigned-byte `color`,
an `RGE_Map_Tile_Row*`, and an unsigned-byte `terrain`.

### Source

The natural owner and signature are correct. The source uses typed map, tile,
terrain, player, and row-table surfaces. It has no wrapper or codegen scaffold.
The node-scan source remains behavior-supported, but its register coloring and
CFG do not match the oracle.

### Bytes

The fresh final check is `MISMATCH`: 1009 differing bytes in an exact 1145-byte
body, 80.2111% shape, exact `0x1C` frame, exact boundary, matching owner, and
12/12 ordered calls. The first mismatch is `+0x5`. The final event is
`584aa309c00540d3bdc258fe7cf06aff`, file
`97733680a538216c8c45ec5cf826a30f58a3011a76882eac2f6ba3e73ee09078.json`.

The baseline state is
`b3251d4ef234dcd4a615c44553c9a2c355e1010cc24e906b687ca10cbd8c2456`.
The rejected node-break state is
`289c97c0608e2bcf6d73509b7404f3cda951b905f2839e821957beb621f5d003`.
Its event is `5078126b27904e3db87df564bbe1d880`, file
`586b8272e5949fd7253fb7357d80081d0587cabbe1d4c4ccad211befaf659f19.json`.
The rejected probe produced 1162 differing bytes. The source was restored.

### Integration

Approve preservation only. Keep `scratch`. Do not promote or accept drift.
Reopen with stronger evidence for parameter and local homes or scan-loop
source.

## `00437EC0` `draw_visible_object`

### Behavior

The source preserves tile testing, world-coordinate conversion, visibility
masks, object-level selection, color selection, doppelganger handling, and
virtual `draw_object` arguments. The original has four calls: two `__ftol`
calls and two virtual slot `+0xEC` calls. The rebuild has three calls. VC5
folds one mode-2 call into the shared path. Complete call topology is not
proved equivalent. No runtime harness was run.

PDB scope supports `RGE_Static_Object* game_obj`, two unsigned-byte colors,
short `row` and `col`, and the `RGE_Diamond_Map*` receiver. The source has no
persistent object, map, or player writes.

### Source

The protected virtual owner and current typed object, map, player, and
doppelganger fields are supported. The switch source is natural. An explicit
level-if probe did not recover the separate call block and made the result
worse.

### Bytes

The fresh final check is `MISMATCH`: 336 differing bytes in a 392-byte rebuild
versus 397 original bytes, 66.6667% shape, no frame, matching saved registers,
matching owner and boundary, and 3/4 aligned calls. The first mismatch is
`+0x0A`. The final event is `88843637380c4b8c872bfd392096fe60`, file
`d40d6fa64dfe049f33a87119f4e668c02b4b56cf091c5067b7d5caa9f24f2d25.json`.

The baseline state is
`8d3a2071e07384409e835e4bd48edd0c4a9acb8cc0f5a69af9bd73de2b6cc4b9`.
The rejected level-if state is
`7a258b18d64cc9be57f9e9ce08ca9e5cc08ad6db63b1103bd14cfccf4ffe2b4d`.
Its event is `f3952290878145f58c0cd7e91efe3961`, file
`9a6df4bb7cb9a1936dbb95bfa9027992b9c2b29c818e02f050d9b1305c2802ea.json`.
The rejected probe produced 341 differing bytes. The source was restored.

### Integration

Approve preservation only. Keep `scratch`. Do not promote or accept drift.
Reopen with new ABI or period-source evidence for the separate virtual call
sites and register homes.

## `004381D0` `draw_clipped_horz_line`

### Behavior

The source preserves signed clipping, short truncation, receiver and
image-line access order, and the direct `TDrawArea::DrawHorzLine` call. It has
no persistent writes. The original has one aligned direct call. No runtime
harness was run.

PDB scope supports short `x`, `y`, and `len`, unsigned-byte `color`,
`RGE_Map_Image_Line* image_line`, and the `__thiscall` receiver. Reviewed
layouts support `pnl_x`, `render_area`, `start_x`, and `line_len`.

### Source

The direct canonical source is natural and has no assembly or register hint.
The original opening register map loads `image_line` into `ESI` before saving
`EDI` and keeps `pnl_x` in `EDI`. VC5 selects the reverse natural basin. The
fault-order difference is not accepted as equivalent.

### Bytes

The fresh final check is `MISMATCH`: 40 differing bytes in an exact 123-byte
body, 95.6522% shape, no frame, exact saved registers and boundary, matching
owner, and one aligned direct call. The first mismatch is `+0x3`. The final
event is `7fcca73eb93046959979e93b84d37fc9`, file
`1f72c6efddbdd279861195c30b4b3a7d84dc8393381633327b77e4e66a29f043.json`.

The baseline state is
`749468c887f4973c343dc4586932cbbf083ea511e008d4f8a9b8fcae9396b3ea`.
No new source state was recorded for this target. The worker states that all
forms were restored before handoff.

### Integration

Approve preservation only. Keep `scratch`. Do not promote or accept drift.
Reopen with period source or compiler-context evidence for the opening
`ESI`/`EDI` allocation.

## `00438250` `draw_view_rect`

### Behavior

The source preserves narrow view-coordinate arithmetic, map bounds, viewport
rectangle publication, and clipped outline drawing. The original has 13 calls,
including the two initial coordinate conversions, repeated conversions, one
`get_max_size`, and pixel or horizontal-line writes. Out-of-range values and
fault paths were not covered by a runtime harness.

PDB scope supports short `row`, `vwid`, and `vhgt`. The original reads the
cached view row after the initial conversion and uses a separate minimum row
for projection. Reusing those values would change behavior, so the retained
source keeps them separate.

### Source

The virtual owner and typed map/view fields are supported. The retained short
coordinate forms follow the proven low-word arithmetic. A direct line-bound
probe removed a temporary but worsened the result and was restored. No padding,
assembly, or opaque boundary filler remains.

### Bytes

The fresh final check is `MISMATCH`: 670 differing bytes in a 741-byte rebuild
versus a 732-byte original, 94.7368% shape, exact `0x10` frame, matching owner,
and 13/13 aligned calls. The first mismatch is `+0x21`. The rebuilt body
crosses the original boundary by 9 bytes. The audit records two boundary
escapes. The final event is `49cf5346e52d45b78ce96fc5fefe1098`, file
`2b280b69210bd179393832bce96e29377406a4e61c19580728e9122482c1896e2.json`.

The baseline state is
`da5edbe2f5f08730979ee6110653063a826457bcefaaf512cfadbb48fd035a2a`.
The rejected direct line-bound state is
`4290f8dae8d1598a545627fd38a611119e58be31a5d20470f241d79e0aa81185`.
Its event is `4fc9726074c94e7ea756a68a465588f1`, file
`e0fb441e55bbb4005837d46e5c471971ce1e93d1c58b2128a6f17bf2246b2a02.json`.
The rejected probe produced 675 differing bytes. The source was restored.

### Integration

Approve preservation only. Keep `scratch`. Do not promote a boundary-crossing
candidate. Reopen with new source evidence for the converted-coordinate home
and original boundary.

## Experiment preservation audit

The five baseline states and four rejected-probe states are present. Each
probe state differs from its baseline in `src/diam_map.cpp` only. Base commit,
external prerequisites, response file, and non-source inputs remain equal.
The clipped-line target has no new probe state, as stated in the worker
package.

The 14 listed run events are present. Their referenced content-addressed
objects exist and pass SHA-256 checks. No invalid or equal-output event is
listed for this assignment. The source hash in every baseline state matches
the restored live source. Every rejected probe has a distinct source hash and
was restored before final validation.

## Complete 27-function audit

Command:

```text
python tools/audit_translation_unit_functions.py --group diam_map --jobs 1 \
  --output-dir build/sa-ffeb72d8-r1-diam_map/reviewer-audit
```

Result: compile succeeded. Fingerprint:
`2e6211232ab50b81a8f01d74b27d9702dc742ba372972d7fff6b0a88e91bd7ae`.
All 27 normal functions were checked.

- `MATCH`: `00436830`, `00436930`, `004369C0`, `00437070`, `00437090`,
  `004370C0`, `00437120`, `004372C0`, `004374C0`, `00437620`, `00437660`,
  `004376D0`, `00437C20`, `00437CC0`, `00438060`, `00438630`, `00438670`,
  `00438720`, `004387C0`, `004387D0`.
- Existing accepted-drift observations: `00436A10` diff 359 and `00438530`
  diff 10. No status change was proposed.
- Grouped mismatches: `00436C30` diff 148, `00437760` diff 1009,
  `00437EC0` diff 336, and `004381D0` diff 40.
- Boundary problem: `00438250` diff 670 with two reported boundary escapes.

No exact neighbor changed. No closure owner requires integration.

## Validation and blockers

Authoritative checks used `check_function.py --rebuild --detail concise
--call-map` for all five targets. The outputs reproduce the package's final
metrics, owner matches, call facts, and boundary facts. The complete audit was
also rebuilt with one job and the package fingerprint.

No runtime harness was supplied or run. Malformed inputs, allocation failures,
out-of-range values, and fault order outside the inspected assembly remain
unknown where stated above. These unknowns block exact or accepted-drift
claims, but they do not block evidence-only preservation.

No correction request is required for this package. The reviewer approves the
worker's source, status, and preservation decisions within the stated scope.
