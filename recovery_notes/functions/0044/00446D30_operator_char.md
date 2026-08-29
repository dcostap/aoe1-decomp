# Recovery journal: 00446D30 `operator_char*`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dstring.cpp`.
- PDB source: `C:\msdev\work\age1_x1\dstring.cpp`.
- Earlier recovery note: `recovery_notes/dstring.md`.

## Translation-unit context

- PDB module: `dstring.cpp`, lines 204-206.
- Natural owner: `src/dstring.cpp`.
- Owning class: `DString`.
- Registered group: `dstring`, with 40 exact neighbors.
- Original body: `mov eax,[ecx]` followed by `ret`.
- `stringValue` is the first `DString` field.

## Current mismatch

The natural source reports `MATCH` and `0.0000%`. It has the correct three-byte
boundary and `??BDString@@QBEPADXZ` owner. It has no calls or relocations.

## Recovered attempt history


No function-specific cleanup block was mapped automatically. Review the earlier note and Git history before work.

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

### 2026-08-29 shared-worktree workflow trial

The first check exposed two tool defects, not a source mismatch.

- `extract_obj_function.py` could not select a conversion-operator symbol for a
  nonregistered grouped function.
- Owner validation did not recognize the VC5 `??B` conversion-operator encoding.

After those tool repairs, the unchanged natural body matched all three original
bytes. No source change or code-generation form was required.

The grouped report is under `build/audits/workers/self-trial/dstring/`.
