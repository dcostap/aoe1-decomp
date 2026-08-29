# Recovery journal: 004CB8B0 `useSameZoneDropsite`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_c_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_c_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_c_obj_module.md`.

## Translation-unit context

- PDB module: `t_c_obj.cpp`; source order is `1193-1202`.
- Owning class: `TRIBE_Combat_Object`; the natural source owner is
  `src/t_c_obj.cpp`.
- Original body range: `004CB8B0-004CB8C6` (23 bytes).
- Exact anchors: load `this->master_obj` at `+0x8`, sign-extend
  `object_group` at `+0x14`, reject groups `0x15` and `2`, then return one.

## Current mismatch

- Fresh baseline (`probe-001-baseline`, 2026-08-29): 26 rebuilt bytes,
  9 differing bytes, and a 3-byte size overrun. The owner symbol matched.
- Final checks (`probe-002-control-flow` and `probe-003-validation`,
  2026-08-29): `MATCH`, `0.0000%`;
  23/23 bytes, 10/10 instructions, no calls, no frame, and no relocations.
- Final boundary and owner are exact: `004CB8B0-004CB8C6`,
  `?useSameZoneDropsite@TRIBE_Combat_Object@@UBEEXZ`.

## Recovered attempt history

- The natural expression `return group != 0x15 && group != 2` preserved the
  predicates but emitted true-path branches and 26 bytes.
- The natural explicit rejection form now matches:
  `if (group == 0x15 || group == 2) return 0; return 1;`.
- The old standalone donor used the same control-flow form, but did not prove
  the natural translation-unit owner. The fresh check proves that owner.

## Rejected approaches

- Keep the direct boolean return rejected. It is behavior-equivalent but has a
  different branch layout and size.

## Open questions

- No matching blocker remains. The original source spelling is not recovered,
  but the natural field type and exact emitted code are established.

## Next useful approaches

- Preserve the explicit rejection form. Re-run the assigned translation-unit
  audit if any neighboring owner changes.

## Worker updates

- 2026-08-29 `wave10-tcobj`: Rebuilt current owner validation. The explicit
  rejected-group branch order gives an exact natural match. The full TU audit
  reports 19 registered-owner matches, including this target.
