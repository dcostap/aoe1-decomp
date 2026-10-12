# spanlist.cpp module migration

The module now owns all 29 normal PDB functions in source order.

Twenty-three functions are exact owners. The composed grouped build reported
`MATCH` and zero byte drift for each exact owner.

The current nonexact results include:

- `004BDEA0 AddShape`: current source-bank result needs a typed selected-shape
  walk. The migration keeps its accepted source shape.
- `004BE090 AddLine_Align`: scratch after the fresh grouped build reported 184
  differing bytes and one boundary escape.
  The five AddSpan calls and loop behavior remain aligned.
- `004BE1F0 AddMiniList`: scratch. The old source swapped its span fields.
  The repaired source uses Y_delta as the sentinel and calls AddSpan with
  X_start, X_end, and Y_delta in that order.
- `004BEAD0 DecodeLine`: 12 differing bytes in the focused grouped build.
  The node walk, byte updates, and count behavior remain aligned.
- `004BEB10 take_snapshot`: scratch after the fresh grouped build reported 351
  differing bytes. Its calls and frame match, but its return and block shape
  do not.
  The file, palette, scanline, overlay, and cleanup behavior remain aligned.

The final grouped reconciliation promotes `004BE4B0 DeleteShape`. It reports
`MATCH`, `0.0000%`, with valid ownership, boundaries, and relocations.

`004BDB00 AddSpan` remains scratch. The current source is a natural typed
reconstruction. The focused grouped build reports 589 differing bytes and a
922-byte rebuild against the 916-byte original.

The migration removes the source-bank fragments and the wrapper. `drawarea.h`
owns the shared span declarations. `spanlist.h` consumes the canonical
Drawarea and Shape headers. The composed fanout retained 48/48 Drawarea and
23/23 spanlist exact owners. Shape retained 10/11 checked owners;
`004BAAF0` remains scratch for its documented two-byte difference.

The fresh grouped audit is `build/audit_accepted_drift_final2/report.txt`. It confirms
that `004BE090` has the owning symbol but escapes its original boundary, so it
is not accepted drift. It also confirms that `004BEB10` has 14 aligned calls and
no relocation or boundary mismatch, but its 351-byte difference includes a
return and block-shape change. `004BDEA0 AddShape` and `004BEAD0 DecodeLine`
remain accepted drift. The final reconciliation supersedes the earlier
`004BE4B0` drift result.

## Wave20 reconciliation

The typed `004BE1F0 AddMiniList` body now matches all 71 bytes. The sequential
audit also disproves the stale `004BE4B0 DeleteShape` exact claim by three
bytes. The module retains 23 matching, four scratch, and two accepted-drift
owners. All 23 registered owners match.

## Reviewed durable test: branch-test-03-spanlist

The test preserved baselines for `AddSpan`, `AddLine_Align`, and `take_snapshot`.
It also preserved two separate receiver-alias variants for `AddLine_Align`.
Both aliases emit the same target bytes as baseline and do not change other compiled owners.
The aliases add redundant source without a demonstrated correctness or simplicity benefit; neither is integrated.
All five states and their referenced evidence survive in `workflow/decomp_notes/experiments/`.
No game source, header, registry, or compiler flag changed.
The worker confirmed the linked-worktree guard fix through direct runs in its assigned worktree.

## Worker sa-510f5e48 AddLine_Align pass

The natural source stayed unchanged. Two Variant Lab runs tested 432 and 864
natural combinations. Both found zero exact variants and no changed owners.
The final target remains 339 bytes versus 337, with 184 differences, five
aligned calls, and a two-byte boundary escape. The one-job spanlist audit is
`build/sa-510f5e48-spanlist-final/report.txt`. `take_snapshot` and the 23 exact
owners remain unchanged.

## Worker drift-017-spanlist accepted-drift re-review

The worker reviewed `AddShape`, `DeleteShape`, `DecodeLine`, and `take_snapshot`
against original instruction streams. Target notes cite the instruction evidence.
No behavior defect was proved. Runtime tests and a whole-executable dependency
audit did not run.

`AddShape` now captures `Height` before the mirror branch. The loops still read
`info->Height` after each `AddSpan` call. This source shape follows the original
shared initial load and the exact `AddShape_Align` donor. It produces 252 bytes
and 186 strict differences, with no boundary escape. The previous natural form
produced 259 bytes and crossed the original boundary.

The source also expresses `DecodeLine` as a head-loaded `while` loop. It emits
the same 58-byte body as the previous source. It preserves unchecked x writes,
inclusive byte addition, next-link order, and node count.

Final target states and run events:

- `AddShape`: state `88fd2fef826f4d9cbf82ff122988b7bb746082fe685e4fbadd76c1a6638b3127`;
  event `7dfeb3badcb478ac4e5e82bce9e18722ff6624470912300bf81b7f943535e254`.
- `DeleteShape`: state `abe9dc679ccedcba06305c60280086c023a74d37021d79658dea613de4accc98`;
  event `451c098abea2661188d94d528deea263b1065b2446b34a04b463de6651a61883`.
- `DecodeLine`: state `2b910546a3ec8a133f71065f2f9f190b423a443b0ec6e9470909b4b134abef3d`;
  event `0bbda8ee7d5acf16e15d4da46bd13964b07a39eebfc189cdaf6638603cf42143`.
- `take_snapshot`: state `b9a4af2eaf7fda83c0b4939209791bdb0ea68c1286ac80d30255e32f1e35cc63`;
  event `8e1ac333414baa45e83228d73a98fe48c44b7edf9f85ef20aa129878fa74b599`.

The final `--jobs 1` module audit is
`build/validation/drift-017-spanlist-final-20260928/report.txt`.
It compiled all 29 normal owners. It found 23 matching results, four accepted-drift
observations, and two new-verified-logic observations. The four targets remain
in `hold_accepted_drift`; registry statuses are unchanged. No status approval,
staging, commit, or integration occurred.

## Current hackathon result: 2026-10-03

`004BEAD0 DecodeLine` remains scratch because unchecked writes can affect its exchanged saved-register homes.
Four new probes and 12 lab forms emitted the same 58-byte body with 12 differences.
The fresh 29-owner audit preserves all 23 matching claims. Source and registry are unchanged.
The target note supersedes older accepted-drift claims for this function.
