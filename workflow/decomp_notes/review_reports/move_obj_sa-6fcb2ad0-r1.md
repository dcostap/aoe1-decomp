# Independent review: `move_obj.cpp`

Reviewer: `sa-6fcb2ad0`
Worker: `sa-a01176f3`
Workflow: matching with reviewers
Worktree: `C:/Projects/my_decomps/aoe1_reviewer_wave_06`
Base commit: `544776da928a7dbff9c3802477732f19f965eb8f`

## Verdict

- Source retention: **APPROVE**, with all three functions left as `scratch`.
- Status promotion: **APPROVE no promotion**. No exact result or accepted-drift proof exists.
- Worker behavior handoff: **APPROVE after correction**.
- Byte and audit evidence: **APPROVE retention**.
- Experiment preservation: **APPROVE**.

This review accepts no compiler-facing source, header, flag, registry, or test
change. The current source has no diff in those paths from the reviewed base.

## Correction recheck

The worker correction event is `5e294c84a602a1ddd6ce71d876cabe41c58b3f606d2f21c5ec1c80e467ee23c0`.
The corrected `0045E970` note now records the proven stack slots and values:
the original stores and loads `world_z` at `[esp+28h]`, so snap delta-Z is
zero; the rebuild computes `world_z + velocity_z` at `[esp+24h]`, so its
snap delta-Z uses `velocity_z`. It also records the one non-padding boundary
escape.

The correction changed only
`workflow/decomp_notes/functions/0045/0045E970.md`. No source, header, flag,
registry, or test path changed. The prior correction request is closed.

## Scope and input identity

The three states use the same compiler fingerprint
`44a8a2883e996b238b841c3a9737140a77c0a1101e0bf1eb902566e8fcf1c346` and the
same `src/move_obj.cpp` hash
`ba6715d867700bf085d217a0d663cfa914dc58d185f6b14b2d40ceb1f23e8c62`.
The states are independent baseline states with no parents. Their recorded
headers, flags, toolchain, source, and symbol registry match the audit input.

The reviewed compiler-facing paths have no worktree diff:

- `src/move_obj.cpp`
- `include/move_obj.h`
- `config/functions/src/move_obj.cpp.json`
- `config/flags/`

The changed worker paths contain function notes and experiment records only.

## Behavior

### `0045D3D0` `teleport`

The original packet and PDB scope support the three float parameters, trail
option dispatch, narrow trail count, six ordered calls, virtual slots `+0x18`
and `+0xB4`, and the repeated low-count remainder addition. The source keeps
these effects. The source also keeps the original trail remainder update in the
non-positive count arm.

The remaining first hunk is source scheduling. The rebuild stores the loop
count before it loads the trail vtable. The original loads the vtable first.
This can change fault order for an invalid trail object. The worker correctly
did not call this accepted drift.

### `0045DB90` `doMove`

The original packet and PDB scope support the waiting call, target-radius
math, waypoint scans, retry path calls, movement updates, and 105 ordered
calls. The source uses the reviewed `Path` and moving-object declarations.
No runtime test is available, so this is static evidence, not a complete
runtime proof.

The four direct-target rows are code-position drift. They are not proof of a
wrong shared declaration. The source remains a supported scratch
reconstruction, but the call-surface and local-layout gap blocks exactness.

### `0045E970` `doTrivialMove`

The original packet and PDB scope support the movement flag, steering math,
collision paths, target check, path retry, waypoint snap, terrain update, and
83 ordered calls. The source uses reviewed typed declarations. No runtime test
is available.

The former worker note said that the source preserves a stale destination-Z
tail read. The emitted code does not support that statement:

- Original `0045F567` stores `this->world_z` at `[esp+28h]`.
- Original snap-tail `0045F706` loads `[esp+28h]`, then subtracts
  `this->world_z` at `0045F70A`. The snap path therefore uses zero delta-Z.
- Rebuilt `0045F586` loads `this->world_z`, `0045F58C` adds
  `this->velocity_z`, and `0045F59B` stores the result at `[esp+24h]`.
- Rebuilt `0045F704` loads `[esp+24h]`, then subtracts
  `this->world_z` at `0045F708`. The snap path therefore uses
  `this->velocity_z`.

The rebuilt path does not retain the original stale value or its zero delta.
This can change the speed multiplier and later speed state after a waypoint
snap. The worker correction event and updated note now record this fact.
The source can remain scratch. Further repair needs evidence for the original
stack-home and local lifetime, not an unsupported source workaround.

## Bytes and ownership

Fresh rebuilt checks used the pinned VC5 toolchain and the natural translation
unit. All three checks returned `MISMATCH`.

| VA | Result | Frame | Calls | Ownership and boundary | Blockers |
|---|---|---:|---:|---|---|
| `0045D3D0` | 491/491 bytes, 15 differences | `0x24` | 6/6 aligned | owner and boundary match | 2 safely masked relocations; first mismatch `+0xF5` |
| `0045DB90` | 3395/3543 bytes, 2977 differences | `0x18` | 105/105 aligned | owner matches; no boundary escape | 4 direct-target mismatches; first mismatch `+0x17` |
| `0045E970` | 3705/3704 bytes, 2792 differences | `0x2C` | 83/83 aligned | owner matches; **one non-padding byte escapes the boundary** | 4 direct-target mismatches and one boundary escape; first mismatch `+0x81` |

The four `doMove` direct-target rows are:

- `+0x268`: original `passable`; rebuilt `Path::currentWaypoint`.
- `+0x632`: original `Path::numberOfWaypoints`; rebuilt `_floor`.
- `+0xA5C`: original `findTilePath`; rebuilt `Path::numberOfWaypoints`.
- `+0xC9F`: original `Path::numberOfWaypoints`; rebuilt `Path::initToStart`.

The four `doTrivialMove` rows are the three `floor` calls replaced by
`Path::numberOfWaypoints`, `PathingSystem::passable`, and two
`Path::currentWaypoint` calls. These are positional relocation diagnostics in
the current mismatch. They block exactness.

The worker handoff says `doTrivialMove` has a matching boundary. The diff
record reports `expected_size_bytes: 3704`, `meaningful_size_bytes: 3705`,
`overflow_nonpadding_bytes: 1`, and `boundary_escape_offsets: [3702]`.
Correct that handoff text.

## Closure and integration

`build/sa-a01176f3-audit/report.txt` was compiled with the same input
fingerprint. It reports 51 owners, 45 matching rows, three accepted-drift
observations, two relocation problems, one grouped mismatch, and no compile
errors. The report shows no changed neighbor. The two relocation problems are
the target issues already recorded for `doMove` and `doTrivialMove`.

No source, header, flag, registry, or test integration is proposed. Keep all
three registry statuses at `scratch`. Do not promote any target from this
review.

## Experiment preservation

Preserve the three baseline states and all worker events:

- `52f487c2354ee6e2f320658c9137aace673b9a96b4aa911849de038ace662374`
  with run event `b3600d98b6ebb1350fc050b994e88410a77d4704072612906d1b6dfdd92bc2a2`.
- `7880319a283c100d074591b4fe51bdfa04bc684db77b6f68aa5746ca691fcd8b`
  with run event `9d74b029f57426ae53b0e63aab57ebb8bc1f5a0b7e1413fd794669fa0045b310`.
- `98211e73c018085e331a2aa9d865e77478f1f5c88d6e9d418cc43f3e61a8f593`
  with run event `d7d97c5c1848e11fd481062c771afcc58e88eaa3abb7653e5bd1c058b96e2438`.

Preserve the six worker event records, the three target diff objects, the
three rebuilt binary objects, and the audit object
`34416ae9f6c75599d6398bd9ab22a61ac348f91723cf0101a98b624528a48508`.
The content-addressed objects exist under
`workflow/decomp_notes/experiments/objects/`.

The correction request is closed by event
`5e294c84a602a1ddd6ce71d876cabe41c58b3f606d2f21c5ec1c80e467ee23c0`.
Restart only when new evidence supplies a supported local-home repair or
changes the reviewed compiler inputs.
