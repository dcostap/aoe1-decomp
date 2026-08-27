# tact_hnt source module

## Candidate evidence

The owner-header candidate reported these two rows as mismatches:

- `004CF090`: 98 differing bytes; original size 103, rebuilt size 55.
- `004CF300`: 1186 differing bytes; original and rebuilt size 1312.

Both rows had matching owner symbols, zero relocation target mismatches, and
zero boundary escapes. The candidate did not prove exactness for either row.

Keep both rows in `scratch`. Do not promote them from the sound-header rebase.

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
