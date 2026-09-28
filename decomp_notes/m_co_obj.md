# m_co_obj.cpp source reunification

## Context

The PDB source is `C:\\msdev\\work\\age1_x1\\m_co_obj.cpp`.
The owner order follows the source lines 27-577.
The class owner is `RGE_Master_Combat_Object`.

The normal owner sequence is:

- `0044FE40`, `0044FEC0`, `0044FF30` constructors;
- `0044FFB0`, `00450170`, `00450450` setup overloads;
- `00450680` destructor;
- `004506D0`, `004507A0` factories;
- `00450810` copy;
- `00450A00`, `00450B40`, `00450D00` attribute updates;
- `00450E20` save;
- `00451000` base damage calculation.

`0044FEA0` is the compiler-generated vector deleting destructor. It has no
handwritten source owner.

## Reunified source

`src/m_co_obj.cpp` is the only compiler-facing source owner for all fifteen
normal VAs. `include/m_co_obj.h` owns the combat-master declarations and uses
the existing action-master declarations from `include/m_ac_obj.h`.

The old wrapper `src/m_co_obj_tu.cpp`, per-function includes, and per-function
fallback declarations are no longer used. The context audit found no source or
configuration consumer for `include/m_co_obj_context.h`. The canonical
`m_co_obj.h` and `com_obj.h` owners provide the complete combat declarations,
so the stale context was removed.

## Final review

The final single-job audit compiled all fifteen normal functions.
Thirteen matching functions passed.
The audit found one boundary problem and one accepted drift.

Report: `build/drift-036-m_co_obj/audit-final/report.json`.
Text report: `build/drift-036-m_co_obj/audit-final/report.txt`.
The audit did not change registry states.

### 00450450 `setup`

See `decomp_notes/functions/0045/00450450.md` for instruction-level behavior.
The original parser reuses argument and stack homes for five `%hd` outputs.
The old seven-byte source did not preserve those values after failed scans.
The current source initializes typed locals from those original home values.

The final object has 585 bytes. The original function has 557 bytes.
Strict diff is 542 bytes.
The group audit reports two boundary escapes.
This source is not ready for integration.
The boundary result is more important than its smaller raw byte mismatch.

The source keeps the unchecked sprite index, signed counts, allocation order,
ignored scan results, and return behavior.
The note cites the original instructions that prove each claim.

### 00451000 `calc_base_damage_ability`

See `decomp_notes/functions/0045/00451000.md` for instruction-level behavior.
The final object and original are both 188 bytes.
Strict diff is twelve bytes.
The difference is register allocation and instruction scheduling.
The PDB names the integer scratch value `tot_armor`.
The source now uses that name and the original field-read order.

The behavior review supports an accepted-drift proposal.
No registry status changed.
The full linked-image dependency audit did not run.

## Open work

Do not integrate the current `00450450` source.
Find a natural source form that preserves failed-scan fallbacks without
crossing its original boundary, or record the blocker for owner review.

No runtime test called either original function.
The review uses original instructions, PDB scopes, source layouts, and compiler
checks.
No full executable link or linked-image data audit ran.
