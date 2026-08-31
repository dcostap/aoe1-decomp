# Final repository validation

Date: 2026-08-31

## Status

The registry contains 4,549 matching normal functions. It also contains 215
accepted-drift functions, 479 scratch functions, 167 unresolved functions, and
17 verified-logic functions.

Scratch fell from about 728 to 479 during this orchestration. Thus, 249
functions left scratch.

## Validation

The full test suite passed:

- 274 tests passed.
- 24 subtests passed.

The complete one-job translation-unit audit compiled all 224 configured groups.
It included 5,260 normal functions. All 4,549 matching targets produced
`MATCH`. The final report is in
`build/root-orchestration/final-validation/final-all-functions/`.

The matching-owner audit checked all 4,549 matching normal functions. It found
no owner mismatch, class/free mismatch, duplicate owner, or repair item. Its
reports are in `build/root-orchestration/final-validation/`.

The translation-unit metadata validation passed with build checks disabled.
The complete function audit supplied fresh grouped object checks instead of the
disposable default object directory.

The compiler gate is open. No compiler job remains active. The worktree is
clean after this report commit.

## Nonexact work

The final grouped audit also records current nonexact functions. These results
do not change reviewed statuses. Important unresolved shared blockers remain in
the function and module notes. They include incomplete virtual surfaces,
compiler-active declaration context, unproved access, and layout ownership.
