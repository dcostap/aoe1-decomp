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
fallback declaration. Three accepted-drift owners remain observed:
`0050D5B0`, `0050D7E0`, and `0050DD70`. `0050DFD0` is scratch because its
natural code has broad control-flow and call-surface drift. The other nine
owners remain registered matching owners.

`scenario.h` now includes `Timeline.h` instead of carrying a second partial
`RGE_Timeline` declaration. This gives scenario code the same canonical class
ownership without creating another compiler-facing owner.

## Recovery notes

The source now includes the canonical object-list, player, static-object,
master-object, world, and file-I/O headers. `Timeline.h` owns only the timeline
record and class declarations. The event record uses its natural field order;
its ABI checks still prove size 0x30 and `next` at offset 0x2c. The canonical
headers provide the player, world, master-object, static-object, and object-list
layouts used by this module. `RGE_Master_Static_Object::id` is modeled at offset
0x10 for `add_delete` instead of using a raw offset expression.

`0050D5B0` retains the shipped target-player lookup behavior: the second object
lookup uses `target_player_id`, although the stream also contains `player_id`.
This is an `ORIGINAL BUG:` supported by the two reads and the second lookup in
the executable listing.

`0050DE00` retains the shipped target-ID lookup of the source object. This is an
`ORIGINAL BUG:` supported by the two calls to `find_id(this, object)` in the
executable listing.

`0050D5B0` remains accepted drift. The fresh grouped candidate has the original
471-byte boundary, matching owner symbol, zero relocation-target mismatches,
and zero boundary escapes. All 18 direct calls, six conditional branches, two
unconditional branches, and the saved-register set match. The 16 differing
bytes start only in the final link/index update at offset `+0x19D`; the source
and executable perform the same pointer stores, count update, loop test, and
return. This is a narrow register and instruction-order difference.

`0050DD70` remains accepted drift. The fresh grouped candidate has the original
136-byte boundary, matching owner symbol, zero relocation-target mismatches,
and zero boundary escapes. All three `calloc` calls, three conditional
branches, three returns, and the saved-register set match. The six differing
bytes only reorder the new node's time store, next-pointer store, and stack
cleanup in the append path. The list topology, count update, and return paths
remain the same.

## Validation and regressions

The pre-migration wrapper used `src/Timeline_tu.cpp`, included one fragment per
owner, and used `include/Timeline_context.h`. The migrated source uses
`src/Timeline.cpp` and `include/Timeline.h` under `config/flags/default.rsp`.

Candidate and grouped validation results are recorded below after the merged
source check. Registered exact owners require `MATCH`, `0.0000%`, correct
boundaries, relocations, and direct targets. Accepted-drift owners are not
registered exact claims.

- Candidate proposal: `build/Timeline_polish_proposal.json`.
- Candidate report: `build/candidate_tus/Timeline_polish/report.txt`.
- The candidate compiles all 13 normal owners and the generated destructor in
  one direct module source. It selects the overloaded constructors and `add`
  with their decorated symbols.

The fresh grouped candidate compiled all 13 normal owners and the generated
destructor. Eight of the nine registered matching owners report `MATCH` with
zero positional differences, zero relocation-target mismatches, and zero
boundary escapes. `0050DE50` retains matching status, but canonical provider
composition causes a 12-byte register and instruction-order regression
(8.0537%) with zero relocation-target mismatches and zero boundary escapes. The
generated destructor reports `MATCH` and `0.0000%`.

The `0050DE50` regression changes no call target, branch count, boundary, or
relocation target. Keep its source natural and its reviewed matching status.
Exact repair remains open after this provider cleanup.

The accepted-drift constructor `0050D5B0` remains a 16-byte mismatch
(3.3970%), with no relocation or boundary mismatch. `0050DD70` remains a
6-byte mismatch (4.4118%), with no relocation or boundary mismatch.

`0050DFD0` is now scratch. The fresh candidate compares the 100-byte original
with a 94-byte natural body and reports 99 differing bytes (99.0000%). The
original saves only `esi` and `edi`, while the rebuilt body also saves `ebx`.
The original has seven conditional branches and one unconditional branch; the
rebuilt body has six conditional branches and no unconditional branch. The
original has an internal self-call at `+0x4D`; the rebuilt body calls the named
`sub` symbol at `+0x46`. The natural body does not preserve the original
internal tail or its duplicated null-test/list-walk shape. Calls, cleanup, and
the final count decrement alone do not prove equivalence for this broad drift.
Keep the natural body, but do not call it accepted drift.

The accepted-drift destructor `0050D7E0` reports `MATCH` and `0.0000%` in the
fresh grouped candidate. It remains an observed accepted-drift row and is not
registered as an exact owner. A later ownership decision can promote it with a
matching source-module status and registered decorated symbol.

The generated vector deleting destructor at `0050D790` remains compiler
generated and has no ordinary source owner. The grouped audit reported no
compile errors and no policy issues.
