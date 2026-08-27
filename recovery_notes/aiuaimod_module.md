# aiuaimod.cpp source module

## PDB context

- PDB source: `C:\\msdev\\work\\age1_x1\\aiuaimod.cpp`.
- The module has 114 normal owners.
- The normal owner byte total is 27,557 bytes.
- The source follows PDB line order and ascending address order.
- The owning class is `UnitAIModule` for all 114 owners.
- The module header proves the 0x134-byte `UnitAIModule` layout.
- The source uses `/O2 /Oy /GX` from `00412F00_UnitAIModule.rsp`.

## Source result

The module now has one compiler-facing source file: `src/aiuaimod.cpp`.
It contains all 114 normal owners in PDB order.
It has no wrapper source or `.cpp` include.
The module header is `include/aiuaimod.h`.

The prior source banks supplied 104 matching owners, seven scratch owners, and
three accepted-drift owners. The migration keeps these statuses.

The accepted-drift owners are:

- `00413150` `save`: 30 bytes differ in the attacking-unit grow loop.
- `00414D40` `order`: status remains accepted drift from the prior source.
- `0041A020` `purgeNotifyQueue`: three loop-tail bytes differ.

The scratch owners are:

- `00413AB0` `update`
- `00414040` `updateGroup`
- `00414800` `selectNewPlayPhase`
- `004151B0` `bestUnitToAttack`
- `00416F30` `intelligentEvasiveMoveTo`
- `00417B50` `processOrder`
- `004180C0` `processNotify`

These owners remain observed, not exact claims.

## Migration check

The direct module object emits 114 defined `UnitAIModule` owner symbols.
The 103 prior registered exact owners remain byte exact after relocation checks.
The seven scratch owners and three accepted-drift owners remain nonexact.
The unregistered `004195F0` `processIdle` owner also differs in the direct TU.
Its source-bank status remains `matching` until the coordinator reviews the
natural module context.

## Generated and no-line entries

The scalar deleting destructor at `00413070` is compiler generated.
It is not a normal PDB owner.
The `004138B0` `canConvert` code has no PDB source line.
Neither entry has a source definition in this module.
The compiler emits all 114 normal owner symbols from the direct source.

## Validation

The direct source compiles with the pinned VC5 compiler and module response file.
The worker did not change global translation-unit registration.
The coordinator must retarget the old wrapper registrations to this module source.
Fresh grouped checks are required after that config change.
