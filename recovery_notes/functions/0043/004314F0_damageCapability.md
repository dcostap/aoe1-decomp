# Recovery journal: 004314F0 `damageCapability`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\com_obj.cpp`.
- Earlier recovery note: `recovery_notes/com_obj_module.md`.

## Translation-unit context

- PDB module: `C:\msdev\work\age1_x1\com_obj.cpp`.
- Natural owner: `src/com_obj.cpp`, `RGE_Combat_Object`.
- Target span: `004314F0-0043152D`, 63 bytes, 25 instructions.
- Original source lines: 1273-1282.
- The target overload takes `RGE_Static_Object*` and returns `float`.

## Current mismatch

- Baseline after source reunification: 65 rebuilt bytes and 58 differing bytes.
- The baseline saved `ebx` and used a 27-instruction form.
- The first mismatch was the extra local `target_master` pointer.
- Final output is 63 bytes with zero differing bytes.
- The fresh validation check is current and reports `MATCH`, `0.0000%`.
- The owner symbol matches `?damageCapability@RGE_Combat_Object@@UAEMPAVRGE_Static_Object@@@Z`.
- The focused check has zero boundary escapes and zero relocation target mismatches.
- Both direct virtual targets align at slots `+0xF0` and `+0x74`.

## Recovered attempt history

- Fresh baseline check: `MISMATCH`, 58 bytes, 89.2308 percent.
- Replaced the local master pointer with inline casts on both field uses.
- Final check: `MATCH`, 0 bytes, 0.0000 percent.
- Final shape is 25 instructions with 100 percent block coverage.
- Both virtual calls align at slots `+0xF0` and `+0x74`.
- The original assembly loads target owner and master fields after the first call.
- The final source preserves that order and uses the reviewed master layout.
- A fresh focused check on 2026-08-29 rebuilt the natural source and retained the
  same exact result.
- Complete current-TU validation covered all 50 normal owners and the nearby
  generated destructor. All 28 registered matching owners and the generated
  destructor matched. This target matched as an observed scratch owner.
- The complete validation had zero comparison errors, zero target relocation
  mismatches, and zero boundary escapes for this target.

## Rejected approaches

- A local `RGE_Master_Combat_Object* target_master` added two bytes and two instructions.
- Direct uncast fields do not compile because the shared base declares `master_obj`.
- No artificial source form was retained.

## Open questions

- The old fallback context typed `master_obj` as a combat master pointer.
- The natural shared header correctly types it as a static master pointer.
- Inline casts retain the old field access while preserving the shared header ABI.

## Next useful approaches

- Keep the exact source unless a source review finds a simpler equivalent.
- `com_obj` is not yet registered in `config/translation_units.json`, so the
  registered-group audit cannot select it. The complete current-TU validation
  used `build/com_obj_complete_natural_proposal.json` and the natural source.

## Worker updates

- 2026-08-29 wave21-com-obj: Recovered an exact natural body.
  The inline casts match the original field loads without local-register overhead.
