# Cleanup wave 03 root review

## Owner 15: restore two evidence comments

Reviewer `sa-cc2cddfa` read all 10,442 diff lines and all group reports at `0d72737ebab2a2e084ce4d5ee63eca45a697141a`.
The reviewer found two blocking comment removals in `move_obj.cpp`.

- Preserve the distinction between the virtual sprite call at `00460D99` and direct base copy call at `00460D9F`.
- Explain the duplicate `currentWaypoint` calls and the deliberate `y + x + temp` checksum order at `00460F72`–`00460F88`.

Root resumed Owner 15 with the same worker for comment-only corrections and report updates.
The reviewer found no other source defect. `LIMIT`, bug comments, types, casts, and original fault order remain supported.
Some module reports use handoff placeholders, but the owner ledger supplies their exact integrated hashes.
The group remains unmerged until the correction diff is reviewed. No validation ran.

## Owner 20: corrected and integrated

Root read the complete correction diff to `c7319027417fbc7d5fc53a82ae3ad021fdff2b5b`.
The source restores `0x77617620`; both reports correct the byte-order claims and retain correction history.
This resolves the delegated reviewer's only blocking finding.
Root merged the group as `f6149f09c425962ca4574ae69c7c4a90ca907dd1`.
Main contains 112 assigned wave modules, plus the pilot. Final validation remains deferred.

## Owner 19: reviewed resource definitions

Reviewer `sa-e5a8d4d2` read all 3,182 diff lines and all 25 changed files at `fea021a8b9836eb0fc357a5a210041828162a328`.
The reviewer found no blocking source change and inspected the resource lookup paths and DLL payloads.
Root approved ten shared names in `include/resource_ids.h`:

- `0x232A`: `IDS_SELECT_OBJECT_TITLE`.
- `0x1D4ED`–`0x1D4F0`: inventory food, wood, gold, and stone help format names.
  The exact prefix is `IDS_HELP_INVENTORY_`; each name ends with `_FORMAT`.
- `0x2B2A`: `IDS_POPULATION_PREFIX`.
- `0x2C24`: `IDS_COUNTDOWN_YEARS_FORMAT`, covering both countdown call paths and the years unit.
- `0x2C25`–`0x2C27`: wonder, artifacts, and ruins years format names.

The inventory help IDs are missing from all three checked DLLs; their formatting roles are proved by callers.
The population prefix exists only in the two expansion files.
The other requested strings exist in the base DLL and are missing from both expansion files.
No requested ID produced an empty-slot result. Extraction is under `build/source-cleanup-20260915/reviewer-owner19/`.

Before integration, the same workers must apply the definitions and correct the two reported presentation issues.
These issues are misleading `spnl_obj.cpp` indentation and the obsolete `tpnl_inv` citation into `dlg_dip.cpp`.
No source validation ran.

## Owner 20: blocking resource-type change

Reviewer `sa-5806ac65` read the complete 5,411-line diff and all nine reports.
Reviewed head: `5b9d313b31819f8228623339e733ff1b25f2558e`.
The reviewer rejected the `Sounddrv.cpp` substitution of `0x77617620` with `MAKEFOURCC('w', 'a', 'v', ' ')`.
The pinned macro produces `0x20766177`, not the original resource-type value.
Original instruction `004BD0B2` and the resource table retain `0x77617620`.

Root resumed Owner 20 with the same worker to restore the literal and correct the reports.
The group remains unmerged. No compiler or runtime check supplied this finding.
The reviewer accepted the unusual `CCDAudio::GetPosition` PDB names and found no other blockers.
The available review slot now handles Owner 15 as `sa-cc2cddfa`.

## Owner 17: delegated approval and integration

Reviewer `sa-33ff58a2` read all 8,322 diff lines, nine reports, eight sources, and the changed header.
Reviewed base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
Reviewed head: `315dd545ea22c89c4bfedff7da6c8d69a7b1b93a`.
The reviewer found no blocking issue and recommended approval.

Root accepted the optional multi-line trivial function bodies without another formatting change.
The report's extracted PDB path is worker-relative, not owner-relative.
Root located it at `build/source-cleanup-20260915/wave-worktrees/slot-147/build/panel_ez_scoped_symbols.json`.
Its SHA256 matches the report: `0e494d1a97f00fc86e2fc3bf0b7ea9ebb71ef40ec381ec2efd5054f09bcfb0bf`.
The report also cites the complete shared PDB inventory. No evidence is missing for this finding.

Root merged the group as `aa015e74070c995b3af3e1483e1bc4294a795781`.
Main contains 104 assigned wave modules, plus the pilot. Final validation remains deferred.
The available reviewer slot now handles Owner 11 corrections and resource requests as `sa-187152fa`.

## Delegated review queue

The user authorized three concurrent read-only reviewers using `openai-codex-secondary/gpt-5.6-sol`, medium thinking.
Root retains correction handling and integration responsibility.
Batch: `batch-15d38b15`.

| Group | Reviewer | Exact head |
| --- | --- | --- |
| Owner 17 | `sa-33ff58a2` | `315dd545ea22c89c4bfedff7da6c8d69a7b1b93a` |
| Owner 19 | `sa-e5a8d4d2` | `fea021a8b9836eb0fc357a5a210041828162a328` |
| Owner 20 | `sa-5806ac65` | `5b9d313b31819f8228623339e733ff1b25f2558e` |

Each reviewer must read the complete diff and reports and inspect relevant original evidence.
Owner 19's reviewer also evaluates its shared resource requests without editing the header.
Owner 15 delivered `0d72737ebab2a2e084ce4d5ee63eca45a697141a`.
Its complete 10,442-line diff is `build/source-cleanup-20260915/owner15-review.diff`; review assignment remains queued.

## Owner 13: intake and prohibited-command incident

Final incident head: `b41a7b3eccda9d05c1bec9bce3e2b011347e82b6`.
Root read the complete final report diff. Source and headers remain unchanged.
The recorded setup used `ln -s` for main-root `inventory` and `orig`.
Later observations identified ordinary directories, consistent with copies, but did not establish Windows junction or child-link status.
The recorded removal used `rm -rf` on those local paths and the generated output directories.
The deleted trees are unavailable for further inspection. Outside traversal remains unproved, not confirmed.
No further command or deletion ran during this documentation request.
Reviewer `sa-fcb5c825` received the final head and report-only difference for its current source review.

Incident-documentation head: `0e7a7d77e70b68069ff692a762887a8b3a5f6499`.
Root read the complete incident additions. Only the module report and owner ledger changed.
The records identify five jobs and five removed paths within slot 110.
All jobs had already settled when the stop calls arrived; no successful interruption is proved.

Root fingerprinted two preserved files after this report:

- Baseline `baseline-build/empiresx.exe`: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
- Pinned original `XPack/empiresx.exe`: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

Both equal the previously recorded hashes. This does not establish integrity for other files.
Root requested exact evidence-directory creation and removal commands to establish whether links could expose outside paths.
The owner must inspect surviving history only and preserve all remaining evidence.

Delivered group head: `b7eab59996b20bd0cdddc73cb2eb48ab24a1e823`.
Root saved the complete 7,638-line diff as `build/source-cleanup-20260915/owner13-review.diff`.
Full root review remains pending. Five declaration-only header requests also need root review.

The owner and `aimodule.md` report these prohibited worker commands:

- `python tools/validate_translation_units.py --no-build-checks`
- `python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/validation/wave03-aimodule-functions`
- `python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/validation/wave03-aimodule-functions-rerun`
- `./game.cmd build`

The report states that the worker stopped the jobs and removed generated outputs and temporary evidence directories.
Root has not independently established the full write or removal scope.
These results do not count as cleanup validation.

Root resumed Owner 13 and requested incident records from the same worker.
The request covers working directories, job IDs, stop outcomes, removed paths, and effects outside the worker tree.
The worker must preserve surviving logs and state all unknowns without rerunning the commands.
Root also told all active owners to preserve incident outputs and enforce the no-validation rule.
No further deletion is authorized for this incident.

## Owner 18: approved and integrated

Root read the complete 3,093-line group diff, including all reports and headers.
Approved group head: `3ba4a0385a2999f516bde496c45d3c93dae55806`.
Root checked the SDK macro values against the pinned `WINUSER.H` and `WINGDI.H` files.
Root also checked the message enums and local-name packet evidence.
The changes retain casts, storage, declaration order, expressions, calls, and data-driven resource lookups.
No new shared resource definition was needed.

Root merged the complete group as `598bdba06fc9c1c495a506a2a50f2a09c8540669`.
Main now contains 96 assigned wave modules, plus the pilot.
Generated code, program data, relocations, and call targets remain unvalidated.

## Pending deliveries

- Owner 20: `5b9d313b31819f8228623339e733ff1b25f2558e`.
  Root saved the complete 5,411-line diff as `build/source-cleanup-20260915/owner20-review.diff`.
  Complete root review remains pending. The owner reports no shared requests or prohibited commands.

- Owner 17: `315dd545ea22c89c4bfedff7da6c8d69a7b1b93a`.
  Root saved the complete 8,322-line diff as `build/source-cleanup-20260915/owner17-review.diff`.
  Complete root review has not started.
- Owner 19: `fea021a8b9836eb0fc357a5a210041828162a328`.
  Root saved the complete 3,182-line diff as `build/source-cleanup-20260915/owner19-review.diff`.
  Complete root review and shared resource decisions remain pending.

No group listed above has root integration approval.
Owner review does not replace complete root review.
No compilation, builds, matching checks, audits, tests, or games ran during this review.
