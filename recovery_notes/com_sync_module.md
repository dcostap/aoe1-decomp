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
owners. Each result has zero positional difference, zero relocation target
mismatches, zero boundary escapes, and the qualified owner symbol.

`00433AD0 IsPlayerOutOfSync` remains scratch. The current natural source keeps
its typed checksum records and separate diagnostic flow. It is not an exact
owner and needs a separate matching pass.

The source uses the canonical `TCommunications_Handler` declaration from
`include/com_hand.h`. It has no context-selection macro, handler substitute,
raw object-layout carrier, partial SDK ABI, or source fragment include.

The unrelated `0053D0D0 RGE_Visible_Map::checksumVisible` accepted-drift owner
remains in `src/visible.cpp` with its existing review note. This module change
does not alter that owner.

`register_candidate_tu.py --apply` could not run because the current global
configuration has unrelated existing owner-status and duplicate-owner blockers
in other modules. The Com Sync candidate itself validated before the focused
registration edit.
