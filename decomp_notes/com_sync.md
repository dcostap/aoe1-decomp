# com_sync.cpp module

The natural owner source is `src/com_sync.cpp`. Its owner header is
`include/com_sync.h`, and its source-private dependencies use the canonical
headers for the communications handler, debug log, base game, path system,
player, visible map, and world.

The PDB module is `C:\\msdev\\work\\age1_x1\\com_sync.cpp`. The source order
runs from the constructor at `00432FF0` through `IsPlayerOutOfSync` at
`00433AD0`.

Owners `00432FF0`, `00433070`, `004330A0`, `00433180`, `00433290`, `00433450`,
`00433460`, `00433A90`, `00433AA0`, `00433AB0`, and `00433AC0` are exact under
the default response file. The grouped candidate returned `MATCH` for all 11
owners after the indexed-record rewrite. Each result has zero positional
difference, zero relocation target mismatches, zero boundary escapes, and the
qualified owner symbol. The rewritten constructor, destructor, and log scan
use indexed `CHECKSUMARRAY&` records. Their exact emitted bytes remain proved,
so no exact row was demoted.

`00433AD0 IsPlayerOutOfSync` remains scratch. The current natural source uses
indexed `CHECKSUMARRAY&` records and role-based local names. Its current result
is a 590-byte positional mismatch against the 610-byte original, with a 0x24
frame versus 0x28, eight aligned calls, zero relocation target mismatches, and
zero boundary escapes. It needs a separate matching pass.

The source uses the canonical `TCommunications_Handler` declaration from
`include/com_hand.h`. It has no context-selection macro, handler substitute,
raw object-layout carrier, partial SDK ABI, or source fragment include.

The checksum globals remain source-private. `DAT_0062D208` is a proven
nine-dword run at `0062D208`: `DoChecksum` writes player slots 1 through 8,
and `LogChecksums` reads slot 0 plus those eight slots. The values come from
the `long checksumVisible()` result. `DAT_0062D230` is one unsigned-long
unified checksum result. The generated global inventory names only the first
`DAT_0062D208` dword and the adjacent `DAT_0062D20C` dword; the executable
accesses prove the larger nine-dword extent used by this module.

The unrelated `0053D0D0 RGE_Visible_Map::checksumVisible` accepted-drift owner
remains in `src/visible.cpp` with its existing review note. This module change
does not alter that owner.

`register_candidate_tu.py --apply` could not run because the current global
configuration has unrelated existing owner-status and duplicate-owner blockers
in other modules. The Com Sync candidate itself validated before the focused
registration edit.

The focused grouped audit compiled all 12 module rows. The 11 registered rows
remain exact. The scratch row remains an unregistered grouped mismatch with the
same 590-byte difference. Its owner symbol, direct call targets, and boundary
remain valid.
