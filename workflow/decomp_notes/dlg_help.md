# dlg_help.cpp module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\dlg_help.cpp`.
- Source: `src/dlg_help.cpp`.
- Header: `include/dlg_help.h`.
- Manifest: `config/functions/src/dlg_help.cpp.json`.
- Flags: `config/flags/gx.rsp`.

## Context gate

- PDB source module: proved by the generated `dlg_help.cpp` module packet.
- Source lines and order: proved by the packet. The six normal owners span
  lines 57-238 in ascending source and address order.
- Owning class: proved by PDB symbols as `THelpDialog` for all six owners.
- Address sequence: proved by the packet:
  `0043E840`, `0043E8E0`, `0043E950`, `0043E9E0`, `0043ED40`, and `0043EE10`.
- Exact anchors: proved by the two constructor symbols, the EH-framed destructor,
  the protected `setup_help` symbol, the action calls, and the mouse handler's
  virtual forwarding call.
- Nearby generated owner: `0043E8C0` is the compiler-generated scalar deleting
  destructor. It has no handwritten source owner.

## Migration

The module now has one source file and one module-local header. The source keeps
all six handwritten definitions in PDB order. It has no wrapper, source-bank
include, fallback declaration, or context macro. The header owns the reviewed
panel hierarchy, virtual slots, fields, API declarations, and global surface.

The old wrapper, context header, and six per-function source files are removed.
The function registry names `src/dlg_help.cpp` and all six normal functions.

The four dialog child pointers use the proven `TTextPanel` and `TButtonPanel`
member types. This preserves the measured `THelpDialog` size and the observed
destruction order without manual vptr code.

## Validation and regressions

- Candidate proposal: `build/candidate_tus/dlg_help.json`.
- Candidate validation compares all five registered owners, the observed
  `setup_help` owner, and the generated deleting destructor.
- The five registered owners report `MATCH`, `0.0000%`, correct boundaries,
  relocations, and direct targets. The generated destructor also reports
  `MATCH` and `0.0000%`.
- `setup_help` reports `MISMATCH`, 432 positional bytes, 849 original bytes,
  and 839 rebuilt bytes. Its boundary and relocation targets match.
- Registered owners retain their prior `matching` status. `setup_help` retains
  `scratch` status until its geometry-home difference is resolved.

## Blockers

`setup_help` remains nonexact. The direct candidate reports a 432-byte strict
  difference after the natural geometry and call reconstruction. In the
  original, `[esp+24h]` is a reused home that holds final `dialog_x` values.
  `[esp+28h]` is a reused home for `top_candidate` and `parent_bottom`
  intermediates. Final `y` remains in `ECX`; it is not a separate spill home.
  Natural local variants did not reproduce this stack-home and register
  topology without unsupported compiler steering.

The scalar deleting destructor is generated and is not a normal source owner.

## Grouped compile debt

The destructor now uses the four source-owned fields proved by the binary:
`ok_button`, `encyclopedia_button`, `list`, and `title`, in that destruction
order. The geometry call uses the inherited `max_wid` and `max_hgt` fields at
the binary-proved `TPanel` offsets `+0xB0` and `+0xB8`. The help API declaration
uses a pointer-sized window handle.

The candidate compile reaches only protected `RGE_Base_Game::prog_window` at
source line 136. The central access agent must add the evidence-backed
`RGE_Base_Game` friend relation for `THelpDialog`. Do not replace this read
with a wrapper, raw offset, or unrelated global state. No `basegame.h` change
was made here. Representative registered-owner checks remain blocked by this
relation.

## Corpus-51 pass: `corpus-51-dlg-help`

- The current canonical source compiles without the old protected-access
  blocker. A clean baseline reports `MISMATCH`, 435 differing bytes, 839
  rebuilt bytes versus 849 original bytes, 27 calls, and frame `0xC`.
- A natural y-geometry naming probe used separate `dialog_y`, `top_candidate`,
  and `parent_bottom` locals. It worsened the result to 436 bytes and was
  restored. A reversed first-guard operand probe emitted the same 435-byte
  result and was also restored.
- The complete `dlg_help` audit with `--jobs 1` keeps all five matching
  neighbors exact. `setup_help` remains scratch with two direct relocation
  target mismatches.
- The original geometry still proves width before xPosition, a reused
  `[esp+24h]` home for final `dialog_x`, and a reused `[esp+28h]` home for
  y intermediates. Final y remains in `ECX`. No unsupported stack or register
  steering is retained.

## Worker pass: `sa-33caa0a4-r1`

The fresh baseline remains `MISMATCH`, with 435 differing bytes and 839 rebuilt
bytes versus 849 original. It has the correct owner, boundary, frame, saved
registers, and 27-call count. The rebuilt direct targets at the first geometry
guard remain `xPosition` then `width`; the original uses `width` then
`xPosition`. The More Help call, string ownership, setup-failure edge, and
typed `bot_line` access remain behavior-supported.

A temporary `panel.h` declaration-order probe and a reverse-sum source probe
both reproduced the 435-byte baseline. A 20-variant local initialization and
geometry lab produced five groups, no exact result, and no invariant-eligible
lead. The header was restored. The one-job final audit reports five exact
neighbors and no closure regression. Keep `setup_help` as `scratch`; further
work needs new direct-call or reused-home evidence.

## Assignment pass: `sa-579ca768-r1`

The fresh static review confirms the complete natural body. It initializes all
four child pointers, copies the parent name, stores the page id, loads font 11,
calls setup, creates the text list, computes placement, creates optional More
Help and required OK controls, and sets current child and tab order. Setup
failure returns at `0043ED27`. Child allocation failures are not checked before
later dereferences, matching the original fault surface. No executable runtime
test was allowed.

The reviewed call and data identities are stable. Setup uses slot `+0x12C`,
text uses `+0x100`, buttons use `+0xE8`, and tab order uses `+0xC8`. More Help
uses language resource `0x243D`; OK uses `0xFA1`. The TTextPanel `bot_line`
field is at `+0xFE`. The original direct geometry calls at `0043EAD5` and
`0043EADE` are width then xPosition. The natural source emits xPosition then
width. Both accessors are reviewed `const long` direct symbols and read their
proven panel fields. PDB `dialog_x` and `panel_height` homes overlap parameter
homes, so they remain reused-home evidence only.

State `25d8556628a60784e92ec9b5998dd2e7d43bd55e657842866c3e1942ac8ebc62`
and event `685d9e96f64d1ede8402d1994eca92024d485606428ce47d44258f7fc0952518`
report `MISMATCH`, 435 differing bytes, 839 rebuilt versus 849 original,
27 calls, frame `0xC`, and two direct relocation target mismatches. The final
one-job audit is under
`build/audits/sa-579ca768-r1-dlg-help-final/report.txt`; all five neighboring
owners remain exact. Keep `setup_help` as `scratch`. No source change, exact
candidate, or accepted-drift proposal is retained.

## Assignment pass: `sa-f7ecb170-r1`

The fresh baseline and final recorded check remain `MISMATCH`, with 435
different bytes, 839 rebuilt bytes versus 849 original, 27 calls, frame `0xC`,
and two direct target mismatches. The original calls `width` then `xPosition`;
the natural source emits `xPosition` then `width`. Positive PDB geometry offsets
remain reused parameter homes. Runtime tests were not permitted.

A 48-variant natural Variant Lab sweep tested line-count width, geometry guard
operand order, a named width local, clamp form, y initialization, and parent
height expression. It produced six emitted groups, 40 frame/call-set eligible
variants, and no exact result. The natural source is unchanged. The one-job
audit is `build/audits/sa-f7ecb170-r1-dlg-help-final/report.txt`; five neighbors
remain exact and `setup_help` remains the only relocation problem. Preserve the
lab state and event. No exact or accepted-drift proposal is made.
