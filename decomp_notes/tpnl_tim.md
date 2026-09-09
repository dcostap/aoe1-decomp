# `tpnl_tim.cpp` source migration

## Ownership

- PDB source: `C:\\msdev\\work\\age1_x1\\tpnl_tim.cpp`
- Source order: constructor, destructor, `set_rect`, `startup`,
  `set_clock_type`, `get_clock_type`, `get_player_id`, `draw`,
  `get_true_render_rect`, `handle_idle`, and `render_to_image_buffer`.
- The scalar deleting destructor at `0051D890` is compiler generated.
- All eleven normal owners now have one compiler-facing source owner in
  `src/tpnl_tim.cpp`.

## Recovery state

The ten functions from `0051D790` through `0051E150` retain their reviewed
matching status. `0051E2B0 render_to_image_buffer` remains scratch because its
natural typed body is not byte exact. The migration does not add padding,
assembly, wrappers, or synthetic declarations to hide that result.

The source uses one module header for the reviewed panel, world, player, draw
area, and imported API declarations. It keeps the original timer, color,
formatting, image-cache, and redraw behavior.

The consolidated source passes the checker for the ten matching owners. This
includes the three exact bodies that were not registered in the old wrapper.
The checker reports the existing `0051E2B0` mismatch only for the scratch body.

## Open exactness issue

The last clean `render_to_image_buffer` body emits a `0x11c` frame and differs
by 439 positional bytes. The original body has a `0x114` frame. The current
source is the simplest typed reconstruction retained after prior ABI, layout,
local, and declaration-order probes. This source-shape migration does not
attempt byte tuning.

## Canonical owner validation

The panel header owns only `TRIBE_Panel_Time`. The source uses the canonical
panel, draw-area, base-game, player, world, color, and tribe-player owners.

The source uses the original game-time and image-cache field names. It uses
typed world-player indexing, the canonical color-table identifier, and the
canonical countdown and held-time fields. String literals remain in this
source owner only.

The canonical candidate module check was run with
`python tools/validate_candidate_tu.py --proposal build/candidate_tus/tpnl_tim_canonical/proposal.json --output-dir build/candidate_tus/tpnl_tim_canonical`.
All ten registered normal owners and the compiler-generated scalar deleting
destructor match. The observed `render_to_image_buffer` owner remains scratch:
it differs by 439 bytes and has a 0x11c frame versus the original 0x114 frame.

The source now uses natural `delete` for each draw-area allocation. The PDB
handle typedef and the `CreateRectRgn`/`DeleteObject` API use confirm
`image_clip_region` as `HRGN`. The source keeps the PDB type and owner-local
string literals.

The natural-delete and owner-local-literal candidate was also checked with
`python tools/validate_candidate_tu.py --proposal build/candidate_tus/tpnl_tim_canonical/proposal.json --output-dir build/candidate_tus/tpnl_tim_natural_owner_literals`.
It has the same ten exact normal owners, generated destructor match, and
439-byte scratch mismatch. No owner was demoted.

## Worker `corpus-52-tpnl-tim` closure

The worker rechecked `0051E2B0 render_to_image_buffer` from a fresh recorded
baseline. The target remains `MISMATCH`: 437 positional bytes, 923 rebuilt
bytes, a `0x11c` frame versus the original `0x114`, 26/26 ordered calls, and
seven bytes beyond the original boundary.

Natural width and height expression forms, explicit update forms, mixed
dimension types, function-scope dimensions, and a shared format local did not
improve the target. A 192-variant VC5 lab also swept 32 ambient declaration
counts. It produced only two code groups, all with the same 923-byte result.

Follow-up probes tested inline geometry, declaration order, mutable adjusted
dimensions, register qualifiers, and source-local ordering. They did not reach
the original frame. The popup donor at `0051D4F0` shows the same natural `0x11c`
frame drift.

The final audit used `python tools/audit_translation_unit_functions.py --group
tpnl_tim --jobs 1`. Its validation fingerprint is
`ac089509b0e56be8c8c44147e622ec06af3cdb979b37bafd13ca3d272ccd309b`. All ten
matching neighbors stayed exact. No compiler-facing source change or
exact-candidate patch is proposed. Durable state and event records are under
`decomp_notes/experiments/`; the function note has the four-part evidence
report and state IDs.
