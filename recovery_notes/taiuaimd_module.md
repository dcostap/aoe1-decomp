# taiuaimd.cpp module recovery

## Module context

The PDB compiland is `C:\\msdev\\work\\age1_x1\\taiuaimd.cpp`.
The module has 63 normal owners from `00503BB0` through `00508660`.
Their source order follows the PDB line bands and address order in the module packet.

The compiler-facing source is `src/taiuaimd.cpp`.
The module declarations are in `include/taiuaimd.h`.
The header uses the canonical `aiuaimod.h` object and `UnitAIModule` surfaces.
The derived tribal classes add no data fields.
The source has one definition for each normal owner.
It has no source-bank include and no wrapper include.

The module also emits the expected compiler-generated destructor and vtable entries.
The nearby generated destructor VAs are not normal owners.
They remain compiler-generated entries.

## Natural module status

The natural source compiles all 63 normal owners with the pinned `/GX` module
flags. The grouped candidate check reports 54 of 55 matching owners as `MATCH`
with `0.0000%` difference.

Owner `00508320` remains scratch. Its canonical `ManagedArray<int>::resize`
definition is inline in the shared header. VC5 emits an 884-byte body instead
of the 600-byte original and crosses the original boundary.

The candidate also compiles all nine observed owners. Their source status stays
unchanged. A compiled match does not promote an observed owner.

Accepted drift owners:

- `005041C0` elephant `processNotify`.
- `00504750` ranged `processNotify`.
- `005059A0` priest `attackObject`.

Scratch owners:

- `00504480` lion `processNotify`.
- `00504E10` civilian `processNotify`.
- `00505B00` priest `bestUnitToHeal`.
- `00506C90` fishing ship `convertToLOSResourceType`.
- `00508140` tower `canAttackUnitAtNeutrality`.
- `00508320` building `processNotify`.

## Migration history

The old grouped wrappers supplied separate include and declaration points for each source bank.
The natural source supplies one module header and one source order.
VC5 changes several COMDAT bodies when these front-end contexts change.
The source module records the resulting status changes.

The natural source replaced the old grouped providers and layout aliases.
It uses the canonical object, player, world, visibility, and array surfaces.

The natural source also restores the shipped lion timeout branch, civilian
object-group test, priest important-object list, and soldier order guards.

## Source recovery notes

The source keeps period-plausible fields and virtual surfaces.
It keeps binary-required evaluation order and shipped behavior from the prior
source files. Visibility and healing scans use `VisibleUnitList` and
`VisibleUnitList_Size`.

The source uses direct canonical methods for world difficulty, player notify,
player queries, object action state, path checks, and group checks.
The old isolated fallback definition of `RGE_Game_World::object` was removed.

The old artifact logging macro was expanded at each call site.
The old soldier update macro now uses `taskedThisUpdate`.
These changes remove recovery macros from the compiler-facing source.

The source includes the generated module comments that record important binary facts.
Function-specific attempt history remains in those comments until later review.

## Integration handoff

The global `config/translation_units.json` registry still points to the old wrappers.
The main agent owns that shared file.
It must map all 63 owners to `src/taiuaimd.cpp` and set the module source.
It must remove the obsolete prefix and soldier groups.
