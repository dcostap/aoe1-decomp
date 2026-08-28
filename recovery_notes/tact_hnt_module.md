# tact_hnt source module

## Candidate evidence

The earlier owner-header candidate reported these two rows as mismatches:

- `004CF090`: 98 differing bytes; original size 103, rebuilt size 55.
- `004CF300`: 1186 differing bytes; original and rebuilt size 1312.

Both rows had matching owner symbols, zero relocation target mismatches, and
zero boundary escapes. The merged source was then revalidated with the current
binary. Both owners report `MATCH`, `0.0000%`, correct boundaries, relocations,
and direct targets in the grouped module and in standalone checks.

Both rows now use `matching` status and remain registered exact owners.

The candidate also reported these exact owners:

- `004CF130`
- `004CF1C0`
- `004CF210`
- `004CF240`
- `004CFF20`
- `004CFF50`
- `004CFF90`
- `004D0080`

The compiler-generated destructor at `004CF100` matched. `004CF860` remains
`scratch`. `004CFFD0` remains `accepted_drift`.
