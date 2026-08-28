# Act Attack module recovery

## Scope

`src/act_atak.cpp` owns the normal `Act_atak.cpp` bodies in PDB order.
It replaces the fragment wrapper and all per-function owners.

The PDB source path is `C:\msdev\work\age1_x1\Act_atak.cpp`.
`RGE_Action_Attack` owns the body sequence from `00401000` through `00401F00`.
`00401150` is a compiler-generated vector deleting destructor.

## Canonical dependencies

The module uses `act_atak.h` for derived action fields and virtual methods.
It uses `action.h` through that header for the base action owner.

It uses canonical action, combat, master, object, player, sprite, task, visible,
world, and Unit AI headers. It uses `rge_fio.h` for binary stream calls.

The source defines no local class, field overlay, virtual shim, or raw offset.
Combat and master conversions use their reviewed inheritance chains.

`do_attack` is private. Its PDB symbol is
`?do_attack@RGE_Action_Attack@@AAEXXZ`.
`ready_to_attack` remains protected.

## Focused candidate gate

Command:

`python tools/validate_candidate_tu.py --proposal build/act_atak_natural_proposal.json --output-dir build/candidate_tus/act_atak_natural`

The final report has five exact owner rows. Each has `MATCH`, `0.0000%`,
matching ownership, zero relocation mismatches, and zero boundary escapes:

- `00401000` file constructor;
- `004013A0` destructor;
- `004013B0` save;
- `00401540` stop; and
- `00401AD0` work.

The generated `00401150` row also matches exactly.

## Retained status

`00401170` and `004012B0` remain accepted drift. The migration does not reopen
their review status.

`004014B0`, `00401550`, `00401780`, `00401B30`, `00401EC0`, and `00401F00`
remain scratch. The focused candidate records their current mismatches.

`004014B0` and `00401B30` read canonical `UnitAIModule::currentOrderValue`.
The executable calls the const `currentOrder()` owner instead. The current
owner-only Unit AI header lacks that const declaration. These rows cannot claim
exactness until that ABI surface is published.

Do not restore the old local Unit AI or visible-map declarations. They target
the wrong direct symbols.
