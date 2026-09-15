# Wave 01 root review

## Owner 02: initial intake

Delivered head: `25842f4d4090bf3bde5dfad84afce012cfb0c738`.
Root read the complete 3,007-line source/header diff and all nine group/module reports.
Changed paths stay within the assignment. The group worktree was clean.
No compiler, build, matching, audit, test, or game ran during root review.

Root returned the group for corrections to the same owner, `sa-fb6be13a`, run 2.

- `rmm_obj.cpp::place_land_objects` removed an explicit unsigned-char cast while renaming `zone` to `land_zone`.
  Restore `(unsigned char)land_zone`; cast removal is outside this wave even when the type makes it redundant.
  Correct the report's claim that no cast or expression changed.
- `rmm_terr.cpp` retained next-line function braces instead of the requested 1TBS style.
  Correct brace placement and the unindented existing inner scope without changing tokens, scopes, or declarations.
- Several short header declarations remained unnecessarily wrapped.
  Join the cited short declarations without forcing genuinely long signatures onto one line.
- `rmm_elev.cpp` introduced unnecessary wrapping in a short `remove_stack_node` call.
  Return it to one line through the same source worker.

The owner must inspect full corrective diffs and preserve module-identifiable commits.
No part of this group is integrated into main yet. Generated-output equality remains unvalidated.

## Owner 01: approved integration

Delivered head: `0d815903dbb7702ffee3772fdb6821661bc8c350`.
Root read the complete 1,705-line source/header diff and all nine reports.
The changes preserve expression structure, casts, types, scopes, calls, and literals by source review.
PDB name mappings and unresolved records are documented. Header changes name parameters only.
No blocking finding remained. Root merged the complete group as `53a9226264941dee9ed76d60dd365cc760470d18`.
All eight action modules are integrated, reviewed, and unvalidated. No executable checks ran.

## Owner 03: initial intake and shared definitions

Delivered head: `44e79dd73b48bfd264c9a5c41cb5d5c1aadaf05b`.
Root read the complete 1,883-line source/header diff and all nine reports.
Root returned the group for report and presentation corrections through owner `sa-a7396334`, run 2.

- The owner ledger incorrectly says every requested ID is absent from both expansion DLLs.
  The module report correctly records expansion overrides and empty slots for several main-menu IDs.
- The campaign-editor report cites extraction files in the preserved pilot worktree.
  Identify the actual files and any out-of-scope writes; preserve prior evidence and correct the report.
- Apply 1TBS to the remaining join-screen constructors and remove the newly introduced short `setPlayerColor` wrap.
- Name `0x1D4F7` as `IDS_HELP_NOTICE`, not `IDS_HELP_DIALOG_TITLE`.
  The popup lookup supplies displayed dialog text; an internal buffer name does not establish a window-title role.

Root extends owner 03's editing scope to `include/scr_set_screen.h` for its two requested parameter-name changes only.
No other header ownership changes. Root continues to own `include/resource_ids.h`.

Root approved 64 distinct new resource definitions from the six module request tables.
The shared Close ID has one definition. Other mappings retain the requested names except `IDS_HELP_NOTICE` above.
The save-title expression must retain its existing arithmetic and use the named base only.

Root independently read all 64 IDs from the actual runtime PE files using the local string extractor.
The runtime hashes agree with the module reports:

- Base: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- Expansion: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.

Returned entries use language `0x0409`. ID `0x1D4F7` is absent from both runtime files; its exact text remains unknown.
IDs `0x2419` and `0x241C` have nonempty expansion overrides.
Expansion IDs `0x07D7`, `0x07D8`, `0x07DA`, `0x241B`, `0x2424`, and `0x2425` have empty slots.
ID `0x2424` also has an empty base slot. Other requested base IDs have the reported text.
The remaining requested expansion IDs are absent, not empty slots.

These definitions are descriptive cleanup names, not recovered original macros. They add no storage.
Source substitutions return through owner 03 and the same module workers after receipt of the shared header commit.
No source or report from owner 03 is integrated into main yet. Final generated-output validation remains deferred.
