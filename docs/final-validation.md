# Final repository validation

Date: 2026-08-31

This report uses current source, headers, registry data, compiler flags, and the pinned VC5 toolchain.

## Translation units

The final audit compiled all 224 configured groups with one compiler job.
It checked 5,260 normal functions.

All 4,629 `matching` targets returned `MATCH` and `0.0000%`.
No exact target regressed.

Report:

`build/root-orchestration/final-validation/full-tu/report.json`

SHA-256:

`9e1badab92670bfc3fc1e41f65b787c68c36dee3297065d7b3f7125a38d2699f`

The report also records completed accepted drifts and unresolved categories:

- 255 grouped mismatches
- 206 observed accepted drifts
- 123 boundary problems
- 41 relocation problems
- four missing grouped symbols
- two accepted drifts without emitted grouped symbols

The four missing symbols are known unresolved declaration owners:

- `00406470 RGE_Action_Object::work2`
- `00406940 RGE_Action_Object::set_task`
- `00469000 TEasy_Panel::create_input`
- `004691C0 TEasy_Panel::create_edit`

The two non-emitted accepted drifts are `0043AA90` and `0043AAD0` in `Dib.cpp`.
They are completed reviewed results, not exact claims or matching debt.

## Owners and symbols

The matching-owner audit checked all 4,629 exact targets.
It found zero owner mismatches, zero class or free-function mismatches, and no repair items.

Report:

`build/root-orchestration/final-validation/matching-owners.json`

SHA-256:

`d458dafcddc8d60c1a63891fb91de46c47e73aa0116d7f4cce5e50c12f78a337`

The grouped symbol audit matched 4,627 owners and found zero mismatches.
Original FPO symbols are unavailable for `0041E7A0` and `0045D6C0`.
Their current grouped owner checks still pass through the function audit.

Report:

`build/root-orchestration/final-validation/symbols.json`

SHA-256:

`f617a0a55bed5f0d3255bac1611971c7fc7e0759144ecb2ca03671a3f8ab4fa0`

## Configuration and tests

Translation-unit configuration validation passed.
The validator also passed against all 224 final grouped objects.

The flag audit checked 224 modules and 5,260 functions.
It found zero blocking issues and 27 known nonblocking mixed-frame findings.

Report:

`build/root-orchestration/final-validation/flags.json`

SHA-256:

`fc0fdd36f09ff0cbedb7f697cbb093eb16f3ae425a529cd8ae9dadf1069bebea`

The full test suite passed:

- 278 tests
- 24 subtests

The compiler gate is open with no active compiler job after validation.

## Authoritative status

Current normal-source status:

- `matching`: 4,629
- `accepted_drift`: 239
- `verified_logic`: 17
- `scratch`: 375
- `unresolved`: 167
- `unclaimed`: 0
- `conflict`: 0

## Stale evidence

One generated target notebook is stale:

- `004AE070 save_victory_cond_in_scenario`

Its stored source fingerprint differs from current input.
No final claim uses that notebook.
The final grouped report supplies current fingerprints for all compiled groups.

## Open recovery limits

The review closed all scheduled investigations. Four repairs remain unsupported:

- One canonical `UnitAIModule` owner changes exact compiler context.
- Correct moving/action slots change exact `0045AA70` x87 operand order.
- Protected `ManagedArray<int>::resize` needs source-wide array access recovery.
- Nested panel enums change exact `00473C80` compiler context.

At this checkpoint, the repository kept all exact results and documented each
rejected trial. This is a historical result, not a rule that blocks later
canonical repairs. Stronger evidence can replace an exact result after a full
affected audit and semantic review.

The repository does not use raw vtables, fake volatility, symbol aliases, or
context macros.

## Worktree state

Five pre-existing function-note edits remain unstaged and preserved:

- `decomp_notes/functions/0041/00412240.md`
- `decomp_notes/functions/0042/00426FC0.md`
- `decomp_notes/functions/0042/00428DA0.md`
- `decomp_notes/functions/0042/00429D90.md`
- `decomp_notes/functions/004F/004F99B0.md`

No integration commit includes these edits.
