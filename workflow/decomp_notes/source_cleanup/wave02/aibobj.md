# `src/aibobj.cpp` cleanup

## Delivery

- Module: `src/aibobj.cpp`
- Header owner: `include/aibobj.h`, owner 06
- Branch: `cleanup/staging-20260915-49`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source cleanup commit: `3428f377ef82b12af699ea52799d64ca3616ae2b`
- Source correction commit: `ec0fe00806d16ad5a5257994a7622bb8c37d08b7`
- Final source commit: `ec0fe00806d16ad5a5257994a7622bb8c37d08b7`
- Report delivery is a separate documentation-only commit after this source commit.
- Changed files:
  - `src/aibobj.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/aibobj.md`

## Cleanup result

This cleanup restores procedure-scoped PDB names in all assigned definitions.
It also applies 1TBS braces to the source file. It adds no comments or constants.
It changes no resource lookup.

The source definitions now use the following recovered PDB names:

- `0040A060 BaseObject::BaseObject`: `gri`, `ci`, `ti`, `gi`, `nm`, `xs`, `ys`, `zs`, `xp`, `yp`, `zp`, `hp`, `minp`, `maxp`.
- `0040A130 BaseObject::BaseObject`: `bo`.
- `0040A240 BaseObject::BaseObject`: `bo`.
- `0040A370 operator==`, `0040A390 operator!=`, `0040A3B0 operator<`, `0040A3D0 operator>`: `one`, `two`.
- `0040A400 BaseObject::groupID`, `0040A420 BaseObject::inGroup`, `0040A460 BaseObject::addGroup`, `0040A4E0 BaseObject::removeGroup`: `v`.
- `0040A6A0` through `0040A6F0` position and size setters: `v`.
- `0040A700` through `0040A7E0` hit-point and state setters: `v`.
- `0040A7F0 BaseObject::setCurrentTargetPosition`: `x`, `y`, `z`.

The following source locals already had descriptive names and remain unchanged:
`n`, `i`, `new_array`, and `dst`. The scoped PDB records expose no named locals
for these procedures. They are not claimed as recovered names.

No new cleanup names were invented. The source keeps the existing field names,
function names, types, scopes, explicit `this->` uses, declarations, statement
order, calls, literals, and allocation behavior.

## PDB coverage

I inspected the procedure-scoped PDB entry for every one of the 54 registered
normal functions. All entries use module object `Release\\aibobj.obj` and source
path `C:\\msdev\\work\\age1_x1\\aibobj.cpp`.

- `00409FA0 BaseObject::BaseObject`: no stack symbols; `this` in `ecx`.
- `0040A060 BaseObject::BaseObject`: stack `gri:int`, `ci:int`, `ti:int`, `gi:int`, `nm:char*`, `xs:float`, `ys:float`, `zs:float`, `xp:float`, `yp:float`, `zp:float`, `hp:int`, `minp:int`, `maxp:int`; `this` in `ecx`.
- `0040A130 BaseObject::BaseObject`: stack `bo:BaseObject*`; `this` in `ecx`.
- `0040A240 BaseObject::BaseObject`: stack `bo:const BaseObject&`; `this` in `ecx`.
- `0040A350 BaseObject::~BaseObject`: no stack symbols; `this` in `ecx`.
- `0040A370 operator==`, `0040A390 operator!=`, `0040A3B0 operator<`, `0040A3D0 operator>`: stack `one:const BaseObject&`, `two:const BaseObject&`; no register symbols.
- `0040A3F0 BaseObject::numberGroups`: no stack symbols; `this` is `const BaseObject*` in `ecx`.
- `0040A400 BaseObject::groupID`: stack `v:int`; `this` is `const BaseObject*` in `ecx`.
- `0040A420 BaseObject::inGroup`: stack `v:int`; `this` is `const BaseObject*` in `ecx`.
- `0040A460 BaseObject::addGroup`: stack `v:int`; `this` in `ecx`.
- `0040A4E0 BaseObject::removeGroup`: stack `v:int`; `this` in `ecx`.
- `0040A560 BaseObject::categoryID`, `0040A570 BaseObject::typeID`: no stack symbols; `this` is `const BaseObject*` in `ecx`.
- `0040A580 BaseObject::gameID`: no stack symbols; `this` is `const BaseObject*` in `ecx`.
- `0040A590 BaseObject::name`: no stack symbols; `this` in `ecx`.
- `0040A5A0 BaseObject::xPosition`, `0040A5B0 BaseObject::yPosition`, `0040A5C0 BaseObject::zPosition`, `0040A5D0 BaseObject::xSize`, `0040A5E0 BaseObject::ySize`, `0040A5F0 BaseObject::zSize`: no stack symbols; `this` is `const BaseObject*` in `ecx`.
- `0040A600 BaseObject::hitPoints`, `0040A610 BaseObject::minHitPoints`, `0040A620 BaseObject::maxHitPoints`, `0040A630 BaseObject::busy`, `0040A640 BaseObject::currentTask`, `0040A650 BaseObject::currentTarget`, `0040A660 BaseObject::currentTargetType`: no stack symbols; `this` is `const BaseObject*` in `ecx`.
- `0040A670 BaseObject::currentTargetXPosition`, `0040A680 BaseObject::currentTargetYPosition`, `0040A690 BaseObject::currentTargetZPosition`: no stack symbols; `this` is `const BaseObject*` in `ecx`.
- `0040A6A0 BaseObject::setXPosition`, `0040A6B0 BaseObject::setYPosition`, `0040A6C0 BaseObject::setZPosition`, `0040A6D0 BaseObject::setXSize`, `0040A6E0 BaseObject::setYSize`, `0040A6F0 BaseObject::setZSize`: stack `v:float`; `this` in `ecx`.
- `0040A700 BaseObject::setHitPoints`, `0040A710 BaseObject::incrementHitPoints`, `0040A720 BaseObject::decrementHitPoints`, `0040A730 BaseObject::setMinHitPoints`, `0040A740 BaseObject::incrementMinHitPoints`, `0040A750 BaseObject::decrementMinHitPoints`, `0040A760 BaseObject::setMaxHitPoints`, `0040A770 BaseObject::incrementMaxHitPoints`, `0040A790 BaseObject::decrementMaxHitPoints`, `0040A7B0 BaseObject::setBusy`, `0040A7C0 BaseObject::setCurrentTask`, `0040A7D0 BaseObject::setCurrentTarget`, `0040A7E0 BaseObject::setCurrentTargetType`: stack `v:int`; `this` in `ecx`.
- `0040A7F0 BaseObject::setCurrentTargetPosition`: stack `x:float`, `y:float`, `z:float`; `this` in `ecx`.

The compiler-generated `0040A040 BaseObject::scalar deleting destructor`
was also inspected and left unchanged. It has stack `__flags:unsigned int` and
`this` in `ecx`. It has no handwritten source owner.

No reused stack-slot mapping was found. No assigned procedure has an unresolved
PDB parameter mapping. The PDB has no named local entries for the source locals
listed above.

## Evidence

- Procedure names, parameters, locals, and registers:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`, entries `00409FA0` through `0040A7F0`.
- Function ownership and status:
  `config/functions/src/aibobj.cpp.json`.
- Source ownership, line band, class layout, and prior migration notes:
  `workflow/decomp_notes/aibobj.md`.
- Original function packets and line records:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0040/` packets for `00409FA0` through `0040A7F0`.

No resource ID or string change was made. No resource extraction was needed.
No shared declaration request is pending. The header remains unchanged for owner 06.

The parameter and local renames preserve all types and storage. The brace moves
preserve executable structure. No change intentionally affects code generation,
object layout, ABI, call targets, or symbol identity. Debug line records can move
when source braces move.

## Validation status

I reviewed the complete Git diff and ran `git diff --check`.
Compilation, matching, audits, and tests were not run, as required for this wave.
No byte-equality or semantic-validation claim is made.

## Correction history

Root correction round 2 requested formatting only. I compacted the recovered
parameter constructor signature onto one line. This removes unnecessary wrapping
and follows the existing source style. No declaration, expression, or token
changed apart from whitespace and line breaks.

The source correction is commit
`ec0fe00806d16ad5a5257994a7622bb8c37d08b7`. The report update is a separate
documentation-only commit.
