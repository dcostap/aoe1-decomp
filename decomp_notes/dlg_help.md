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
