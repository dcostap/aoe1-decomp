# Timeline.cpp module merge

- PDB source: `C:\\msdev\\work\\age1_x1\\Timeline.cpp`.
- Source: `src/Timeline.cpp`.
- Header: `include/Timeline.h`.
- Packet: `build/tu_plans/Timeline_cpp/packet.json`.

## Translation-unit context

The PDB identifies `Timeline.cpp` and the source line bands 25-74, 79-85,
90-103, 108-148, 155-221, 227-320, 326-335, 340-378, 383-399, 404-431,
436-454, 459-494, and 499-530. The owner sequence is:

`0050D5B0`, `0050D7B0`, `0050D7E0`, `0050D830`, `0050D9A0`, `0050DB10`,
`0050DD30`, `0050DD70`, `0050DE00`, `0050DE50`, `0050DEF0`, `0050DF40`,
`0050DFD0`.

All 13 owners are `RGE_Timeline` members. The class layout is 0x14 bytes.
The event record is 0x30 bytes, and its `next` member is at offset 0x2c.
The player, world, master-object, and static-object declarations model the
observed fields and virtual call slots used by these owners.

The target address sequence and the exact anchors are proved by the PDB packet
and `orig/ghidra_decomp/timeline.cpp.asm`. The virtual vector deleting
destructor at `0050D790` is compiler-generated and has no ordinary owner.

## Source ownership

The source contains all 13 handwritten owners in PDB order. It uses one
module-local header and no wrapper, function-fragment include, context macro, or
fallback declaration. The four accepted-drift owners remain observed:
`0050D5B0`, `0050D7E0`, `0050DD70`, and `0050DFD0`. The other nine owners remain
registered matching owners.

## Recovery notes

The constructors, save, update, mock-update, list helpers, and event helpers
use the reviewed typed declarations. `RGE_Master_Static_Object::id` is modeled
at offset 0x10 for `add_delete` instead of using a raw offset expression.

`0050D5B0` retains the shipped target-player lookup behavior: the second object
lookup uses `target_player_id`, although the stream also contains `player_id`.
This is an `ORIGINAL BUG:` supported by the two reads and the second lookup in
the executable listing.

`0050DE00` retains the shipped target-ID lookup of the source object. This is an
`ORIGINAL BUG:` supported by the two calls to `find_id(this, object)` in the
executable listing.

## Validation and regressions

The pre-migration wrapper used `src/Timeline_tu.cpp`, included one fragment per
owner, and used `include/Timeline_context.h`. The migrated source uses
`src/Timeline.cpp` and `include/Timeline.h` under `config/flags/default.rsp`.

Candidate and grouped validation results are recorded below after the merged
source check. Registered exact owners require `MATCH`, `0.0000%`, correct
boundaries, relocations, and direct targets. Accepted-drift owners are not
registered exact claims.

- Candidate proposal: `build/candidate_tus/Timeline.json`.
- The candidate validator was attempted before the source-bank move. It rejected
  the proposal because the current canonical owner paths still pointed to the
  old fragments. The final source was then checked by the grouped audit.
- Group audit: `build/audits/Timeline_final`.

The final grouped audit compiled all 13 normal owners. The nine registered
matching owners remain `MATCH` with zero positional differences, zero
relocation-target mismatches, and zero boundary escapes. Their standalone
checks also report `Result: MATCH` and `0.0000%`.

The accepted-drift constructor `0050D5B0` remains a 16-byte mismatch
(3.3970%), with no relocation or boundary mismatch. `0050DD70` remains a
6-byte mismatch (4.4118%), with no relocation or boundary mismatch. `0050DFD0`
remains a 99-byte mismatch (99.0000%); its natural body has one fewer saved
register and does not preserve the original internal tail. These owners remain
observed and are not promoted by this structural migration.

The accepted-drift destructor `0050D7E0` now reports `MATCH` and `0.0000%` in
both grouped and standalone checks after removing the volatile alias. It is
still not registered exact. Main-agent ownership review is the blocker for any
status promotion because the accepted-drift source bank is closed without a
separate promotion decision.

The generated vector deleting destructor at `0050D790` remains compiler
generated and has no ordinary source owner. The grouped audit reported no
compile errors and no policy issues.
