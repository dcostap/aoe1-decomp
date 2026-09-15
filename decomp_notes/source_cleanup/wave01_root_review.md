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

## Owner 02: corrections approved and integrated

Corrected head: `832af7ebb31570c60cd3f8406bacfaa0300e9ac2`.
Root read the complete 583-line correction diff, including the updated module reports and owner ledger.
This review supplements the initial complete group review recorded above.

The correction restores `(unsigned char)land_zone` in `rmm_obj.cpp`.
The report now records the initial cast removal and its repair.
The terrain changes preserve the existing inner scope and statements while correcting brace placement and indentation.
The elevation call and three header declarations now use the requested presentation.
No blocking finding remains from source review. Compiler-output equality is not established by this review.

Root merged the complete group as `2d8e893b66ca6e229d82d6c44550684e1b0955b1` without conflicts.
This includes eight sources, seven changed headers, eight module reports, and the owner ledger.
The initial commits, correction commits, and worktrees remain preserved.

Sixteen wave modules are now integrated: eight action modules and eight random-map modules.
The eight screen modules remain with owner 03 for corrections and resource substitutions.
No new modules are assigned. No compilation, matching, audits, tests, builds, or games ran during this intake.
All integrated cleanup remains reviewed and unvalidated against the preserved pre-cleanup build.

## Owner 03: second intake

Delivered head: `a531f0475335977b8f2748e48bd1caa065978805`.
Root read the complete 1,508-line correction diff, including every changed report.
The 64 shared resource definitions match the root header exactly.
Source substitutions retain the reviewed resource values and lookup contexts.
The save-title expression retains its operand order. The settings header adds parameter names only.

The owner corrected expansion provenance and the Help notice role.
The campaign worker recorded the incorrect pilot citation and reported no writes to that worktree.
Root compared the campaign source and report against the worker's final commit; both match the integrated copies.
Thus, the reported add/add conflict did not omit content from the corrected worker report.

Root accepted these corrections, but returned two small items through owner run 3:

- Join two newly wrapped short campaign error-dialog calls.
- Correct the main-screen report field that labels the root resource commit as a worker-local commit.

No other source changes or new assignments are requested. Screen integration awaits those complete correction commits.
No compilation, matching, audits, tests, builds, or games ran during this intake.

## Owner 03: final source corrections accepted

Delivered head: `6ded709dd61101f5c49a354664c58afb52129de6`.
Root read the complete correction diff. Both short calls and the main-screen commit label are corrected.
However, the new owner ledger contains incorrect full hashes for three correction commits.
The final response lists the correct hashes; `git log` independently confirms them:

- `044b2398d580d86c2b7d78cf4ccbb5cbfc4115ce`.
- `a1fc267b6c29dd4eba5ad4e9045f7081294d6333`.
- `981b03543df1aff75666a5281a0e3850847d7d4a`.

Root returned only the owner ledger for correction in run 4. No worker or source changes are requested.
Screen integration still awaits that report correction. Wave 02 uses disjoint source and header assignments.
