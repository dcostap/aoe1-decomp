# Cleanup wave 04 root review

## Owner 28: delegated review started

- Delivered head: `180836230c0c7275581e3489e391546c0c320552`.
- Base: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Full diff: `build/source-cleanup-20260915/owner28-review.diff`, 4,674 lines.
- Reviewer: `sa-f1296ef0`, Sol medium, read only.

The assignment covers all eight sources, eight headers, and nine reports.
The requested age macros already exist in main, but not in the group's base header.
The reviewer must check the timeline caller role before recommending their use.
Option-label age uses in Owner 26 remain deferred; equal IDs do not establish equal caller roles.
The group remains unmerged. Compiler and runtime validation remain deferred.

## Owner 26: corrections and resource decisions

Reviewer `sa-e6faf4c1` read all 9,390 lines and all reports.
Diff SHA256: `3e5826f8f2ce24775c9db8e1094e413a8e1aeabaae6ac20a6b4bb5da014421b2`.
Root returned two blockers to the same workers:

- Restore the complete baseline nested scope for `tworld` case 101 before case 102.
- Restore the combined `int index, j;` declaration in `world::load_scenario6`.

The ledger must correct its full-restoration claim. The positional `scenario_make_player` mapping passed review.

Root broadens the new `0x2775` name to `IDS_FILE_NONE`, without a duplicate alias.
Scenario consumers use it for cinematic, bitmap, and city-plan defaults, not only AI files.
Owner 25 received the name correction. `0x277B` remains `IDS_AI_FILE_RANDOM`.

Root approved the payload-backed world resource definitions in `include/resource_ids.h`.
These include victory descriptions, map bases, format strings, Nomad, default, resource levels, and difficulty base.
Preserve all enum-offset arithmetic and format arguments. Reuse existing population and path-finding format names.
Difficulty reaches only `0x2BD0` through `0x2BD4`; the next two IDs mean Up and Down.
The resource-level offset overlaps `0x25E5`, which is also a format ID. Preserve the exact original expression.

Root defers the empty victory-log range and keeps its numeric base.
Root also defers the four option-age substitutions at `0x1069` through `0x106C`.
Existing `IDS_HELP_AGE_*` names describe another caller role; no duplicate numeric aliases will be added.
These deferred names do not block source integration.

Evidence uses runtime base SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
The pinned original corpus lacks the base language DLL. Payloads come from staged runtime evidence.
Runtime and original expansion files miss `0x2775` and `0x277B`; neither slot is empty.
Victory descriptions and the approved formats also use base fallback after expansion misses.
Expansion supplies the last four map types and Gigantic; base supplies the first five types and sizes.
Lookup checks expansion first, then base. A `STRING=` override remains unchecked.
Both groups remain unmerged and unvalidated pending correction review.

## Owner 25: corrections and resource decisions

Reviewer `sa-4261f9a4` read all 15,378 lines and all 25 changed files.
Diff SHA256: `4b7dba284edcb0d4ba6747ceffc877461ec449118c0b5d5d77699e4877aa369d`.
Two blockers remain. Root returned them to the same workers:

- Restore `TRIBE_Player::save` file-handle alias and parameter overwrite pattern, without changing baseline declaration or initialization positions.
- Join the `if (InQ)` opening brace in `com_hand.cpp` to follow 1TBS.

Original `00512250` keeps the output handle in EDI; `00512359` and `0051238C` overwrite the parameter slot.
The cleanup reversed those roles. The report must withdraw its identifier-only claim for that rejected version.

Root approved three unsuffixed hexadecimal macros as new cleanup names:

- `IDS_ERROR_SYNC`, `0x0966`: sync-error popup text in `tcommand`.
- `IDS_AI_FILE_NONE`, `0x2775`: ` <None> ` in AI file selection.
- `IDS_AI_FILE_RANDOM`, `0x277B`: `Random` for build-list, city-plan, and ruleset selection.

The `noneString` buffer is loaded but unused in the recovered `loadAIInformation` body. Preserve that behavior.
Runtime base supplies all three strings in language `0x0409`; both expansion DLLs miss all three IDs.
Runtime base SHA256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
The pinned original tree lacks the base DLL. Evidence is staged runtime data, not an original base-file claim.
Extraction is under `build/source-cleanup-20260915/reviewer-owner25/`.

Root rejects `IDS_CIVILIZATION_NAME_BASE` for `0x27F6` at this time.
Its arithmetic reaches empty `0x2803`, `Unknown` at `0x2804`, and `Tribe Name` at `0x2805`.
It reaches `Roman` at `0x2806`, not the full expansion civilization mapping. Preserve the literal and original arithmetic.
Root also defers the missing build-list range `0x26930` through `0x269AC`.
An unchecked `STRING=` override could supply that range. The checked DLLs do not prove its payloads.
Owner 26's reviewer received these shared decisions. The groups remain unmerged and unvalidated.

## Owner 26: delegated review started

- Delivered head: `5945b972778227cd419e66ae49f744e4cb2f5001`.
- Base: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Full diff: `build/source-cleanup-20260915/owner26-review.diff`, 9,390 lines.
- Reviewer: `sa-e6faf4c1`, Sol medium, read only.

The assignment covers all eight sources, eight headers, nine reports, and outstanding resource requests.
It specifically checks the restored world declarations and types, plus the corrected positional parameters in `tworld`.
Requests for `0x2775` and `0x277B` overlap Owner 25. Root will coordinate one shared definition per role.
The group remains unmerged. Compiler and runtime validation remain deferred.

## Owner 25: delegated review started

- Delivered head: `2f452e4958f5aa90f31de6ec64158ea71726bf82`.
- Base: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Full diff: `build/source-cleanup-20260915/owner25-review.diff`, 15,378 lines.
- Reviewer: `sa-4261f9a4`, Sol medium, read only.

The assignment covers all eight sources, eight headers, and nine reports.
It also covers the four shared resource requests at `0x0966`, `0x2775`, `0x277B`, and `0x27F6`.
The build-list name base remains unapproved without further evidence.
The group remains unmerged. Compiler and runtime validation remain deferred.

## Owner 23: delegated review started

- Base: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Delivered head: `96d0ebf773c0b852f9b6c93f5263b67253699717`.
- Full diff: `build/source-cleanup-20260915/owner23-review.diff`, 9,193 lines.
- Reviewer: `sa-75c8b6da`, Sol medium, read only.

The assignment covers eight sources, six changed headers, eight module reports, and the owner ledger.
It includes the unresolved `rect_wid` type and optimized stack-home mappings.
The reviewer must preserve baseline types and declarations unless reliable name evidence supports a rename.
Reviewer `sa-75c8b6da` approved the complete diff and all reports with no blockers.
Diff SHA256: `8a3927136786e0e7603577f8c3aa1564fc6ce44989af1b61bd67a0e271e90edb`.
Diff Git blob: `b8ff0f2e99b9e1940478da7098f55adbace87fa2`.
The review preserves `long rect_wid`; the PDB `int` record does not authorize a type change.
Unresolved optimized stack-home mappings remain documented without new declarations.
No assembly, helper, wrapper, or binary dependency changed.
No shared request remains open. Compiler and runtime validation remain deferred.
Root merged the group as `c05f1e3aa1be204644a1b0678bfccc6157ce4de8`.
Main contains 168 assigned modules plus the pilot: 169 of 225, approximately 75.1%.
