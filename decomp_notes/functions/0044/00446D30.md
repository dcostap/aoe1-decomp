# Function notes: 00446D30 `operator_char*`

Module notes: `decomp_notes/dstring.md`.

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

## Worker updates

### 2026-08-29 shared-worktree workflow trial

The first check exposed two tool defects, not a source mismatch.

- `extract_obj_function.py` could not select a conversion-operator symbol for a
  nonregistered grouped function.
- Owner validation did not recognize the VC5 `??B` conversion-operator encoding.

After those tool repairs, the unchanged natural body matched all three original
bytes. No source change or code-generation form was required.

The grouped report is under `build/audits/workers/self-trial/dstring/`.
