# aiuaimod.cpp source module

## PDB context

- PDB source: `C:\\msdev\\work\\age1_x1\\aiuaimod.cpp`.
- The module has 114 normal owners.
- The normal owner byte total is 27,557 bytes.
- The source follows PDB line order and ascending address order.
- The owning class is `UnitAIModule` for all 114 owners.
- The module header proves the 0x134-byte `UnitAIModule` layout.
- The source uses `/O2 /Oy /GX` from `00412F00_UnitAIModule.rsp`.

`include/ai_play_phase_command.h` owns the PDB-proven 0x10
`AIPlayPhaseCommand` record. Its PDB fields are protected. The module header
consumes its public accessors without a local copy.
`include/ai_play_phase_trigger.h` owns the PDB-proven 0x14
`AIPlayPhaseTrigger` record. Its PDB fields are protected. The
`PAVAIPlayPhaseTrigger` return from `AIPlayPhase::trigger` proves its class
identity. The module uses its public accessors without a local copy.

## Unit AI root virtual prefix

PDB field list `0x28CE` defines the public virtual prefix in this order:
destructor, `save`, `load`, `owner`, `order`, and `notify`. `notify` is
`int (int, int, int, long, long, long)` at vslot `+0x14`.

The prior three-int `notify` declaration is not a real overload. It appears in
no PDB UnitAIModule method, source definition, or function inventory. Do not
restore it for caller convenience.

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

## `004195F0` repair evidence

PDB assigns `004195F0` to `UnitAIModule::processIdle(int)` at lines 5255
through 5282. Its decorated symbol is `?processIdle@UnitAIModule@@MAEHH@Z`.
The original boundary is `004195F0` through `00419641`, 82 bytes.

The original expression order is:

1. `processRetryableOrder()` through virtual slot `+0xDC`.
2. `bestUnitToAttack(1, 0, 0)` through virtual slot `+0x30`.
3. `attackObject(index, 1)` through virtual slot `+0x5C`.

The current private placeholders emit three wrong direct targets and a 78-byte
body. A scratch-only natural replacement with the three canonical virtual calls
emits the exact 82-byte, 33-instruction body under the authentic `/O2 /Oy /GX`
translation-unit context. The focused result is `MATCH` with zero target
relocations.

Do not edit AIUA yet. `00413070` deleting-destructor ownership and natural
emission remain a separate gate. One future sole editor must apply both
source-supported repairs, then run the full AIUA group.

## `00413070` emission hold

`00413070` is compiler generated. It has no PDB source line or handwritten
source owner. The original boundary is `00413070` through `0041308D`, 30 bytes.
The defined body is `??_GUnitAIModule@@UAEPAXI@Z`. It calls `00413090`, then
calls `0054B660` when the deleting flag has bit one set. It returns `this` with
`ret 4`.

The original vtable at `0056EAD8` has this thunk in slot zero. VC5 uses weak
`??_EUnitAIModule@@UAEPAXI@Z` only as the vector-deleting identity. The
validator must compare the defined `??_G` fallback body.

Current AIUA uses `__declspec(novtable)` and manual delayed vptr stores. Its
object emits no `??_G`, `??_E`, or `??_7UnitAIModule@@6B@Z`. Removing those
forms would naturally emit the thunk and vtable, but would change the proven
constructor and destructor vptr order. It is not an exact source repair.

Do not add a dummy reference or standalone generated body. AIUA stays held.

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
