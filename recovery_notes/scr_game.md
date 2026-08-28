# `scr_game.cpp` source-module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\scr_game.cpp`.
- The module has 96 normal owners in PDB order, from lines 201 to 5941.
- The owner range contains 36,932 normal bytes.
- The compiler-facing owner is `src/scr_game.cpp`.
- Shared declarations are in `include/scr_game.h`.

The module now uses one source file. It no longer uses the old wrapper,
fragment `.cpp` includes, context macros, or fallback class declarations.

The source keeps the reviewed owner bodies and direct field names. It keeps
binary-supported packed palette storage and narrow ABI forms where the source
bodies prove them. The module uses `config/flags/004982E0_action.rsp`.

The migration is structural. Exact owners can regress when the compiler sees
one natural source file instead of the old prefix wrapper. The final grouped
check records the post-migration result. Recheck exact owners after later
source recovery changes.

The focused grouped audit compiled all 96 owners. It kept 49 exact owners.
It kept 41 registered exact owners and found eight exact owners that remain
unregistered. It reported these 47 regressions:

- `00493D60`, `00495AE0`, `00496550`, `00496700`, `00496800`, `004970A0`.
- `00497440`, `00498A10`, `00498A50`, `004992E0`, `004993B0`, `00499680`.
- `004996C0`, `0049A8A0`, `0049AB60`, `0049ADA0`, `0049B080`, `0049B910`.
- `0049BAF0`, `0049BCA0`, `0049BDB0`, `0049BEA0`, `0049BF50`, `0049C010`.
- `0049C0B0`, `0049C1B0`, `0049C230`, `0049C280`, `0049C300`, `0049C650`.
- `0049C770`, `0049C800`, `0049C920`, `0049C970`, `0049CA10`, `0049CA80`.
- `0049CAF0`, `0049CB90`, `0049CC20`, `0049CCB0`, `0049CE40`, `0049CEC0`.
- `0049D090`, `0049D100`, `0049D1B0`, `0049D370`, `0049D440`.

The full result is in `build/audit_scr_game_registered/report.txt` during this
build. It shows relocation errors for `00493D60`, `00496800`, and `004996C0`.
It shows boundary errors for `00498A50`, `00499680`, `0049ADA0`, `0049BAF0`,
`0049C300`, `0049C800`, `0049CA80`, `0049CB90`, `0049CC20`, `0049CCB0`,
`0049CE40`, `0049CEC0`, `0049D090`, and `0049D440`.

`0049D440 any_selected_have_action` was previously registered exact. Its
merged result differs by 60 bytes and crosses two boundary bytes. The direct
entry and module status now record it as scratch.

## Provider composition

`include/scr_game.h` now uses the `Pnl_scr`, `pnl_btn`, `tpnl_btn`,
`diam_map`, and `tvw_dmap` providers. It no longer defines Panel, button,
or Diamond Map classes.

The PDB size check confirms `sizeof(TRIBE_Screen_Game) == 0x7C4`.
The screen keeps all 96 normal `scr_game.cpp` bodies.

Earlier focused checks matched `004954A0`, `004959A0`, `00497210`,
and `0049D530`. The canonical audit below supersedes this older summary.

## Canonical-provider audit

The 2026-08-28 canonical audit compiled all 96 module bodies. It matched 59.
It found 29 mismatches and eight comparison errors.

The audit source is `build/candidate_tus/scr_game_canonical_audit.json`.
The report is `build/candidate_tus/scr_game_canonical_audit/report.txt`.

The following former matching rows are now scratch:

- `00497330`, `00498A10`, `004992E0`, `0049AB60`, `0049B560`.
- `0049BAF0`, `0049BD20`, `0049BD70`, `0049BDB0`, `0049BEA0`.
- `0049BF50`, `0049C010`, `0049C230`, `0049C540`, `0049C650`.
- `0049C800`, `0049C890`, `0049CAF0`, `0049CCB0`, `0049CEA0`.
- `0049CEC0`, `0049CFF0`, `0049D090`, `0049D100`, `0049D1B0`, `0049D200`.

The provider changes removed copied foreign layouts and raw source forms.
They did not establish new exact claims.

## Source cleanup audit

The source cleanup removed opaque globals, raw palette writes, C-style casts,
and cursor loops. It kept the existing exact rows except `0049A8A0`.

The `scr_game_source_cleanup_audit` observed `0049A8A0` as a 76-byte mismatch.
It also found one direct-target mismatch. Its status is now `scratch`.
