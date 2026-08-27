# taiuaimd.cpp module recovery

## Module context

The PDB compiland is `C:\\msdev\\work\\age1_x1\\taiuaimd.cpp`.
The module has 63 normal owners from `00503BB0` through `00508660`.
Their source order follows the PDB line bands and address order in the module packet.

The compiler-facing source is `src/taiuaimd.cpp`.
The module declarations are in `include/taiuaimd.h`.
The header extends `include/taiuaimd_context.h` with module-local class surfaces.
The source has one definition for each normal owner.
It has no source-bank include and no wrapper include.

The module also emits the expected compiler-generated destructor and vtable entries.
The nearby generated destructor VAs are not normal owners.
They remain compiler-generated entries.

## Status before migration

The module packet records 55 matching owners, three accepted-drift owners, and five scratch owners.
This migration keeps those statuses.
It does not promote an observed owner.

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

## Migration regressions

The old grouped wrappers supplied separate include and declaration points for each source bank.
The natural source supplies one module header and one source order.
VC5 changes several COMDAT bodies when these front-end contexts change.
This is a source-shape migration result, not a status change.

The natural compile emits every one of the 63 normal symbols.
The current natural object changes these observed body sizes against the old grouped object:

- `005041C0` elephant `processNotify`: 304 bytes instead of 272 bytes.
- `005048D0` ranged-2 `processNotify`: 752 bytes instead of 656 bytes.
- `00505820` priest constructor: 112 bytes instead of 336 bytes.
- `00505A30` priest `canConvert`: 192 bytes instead of 176 bytes.
- `00505DD0` priest `processNotify`: 544 bytes instead of 512 bytes.
- `00506320` trade ship `processNotify`: 1008 bytes instead of 944 bytes.
- `005066D0` trade ship `processIdle`: 272 bytes instead of 256 bytes.
- `005068B0` transport `processNotify`: 544 bytes instead of 448 bytes.
- `00506A70` transport `processIdle`: 272 bytes instead of 256 bytes.
- `00506CC0` fishing `processNotify`: 608 bytes instead of 544 bytes.
- `00507A30` artifact `processNotify`: 1184 bytes instead of 1088 bytes.

Other body sections also have alignment-size changes.
A fresh authoritative check is required after the main agent registers this source.
The migration does not claim fresh exactness for any owner.

## Source recovery notes

The source keeps the existing period-plausible typed fields and virtual surfaces.
It keeps binary-required evaluation order and shipped behavior from the prior source files.
The priest heal tables use the reviewed module globals directly.
The old isolated fallback definition of `RGE_Game_World::object` was removed.
The module now uses the declared external method surface.

The old artifact logging macro was expanded at each call site.
The old soldier update macro now uses its direct proven address store.
These changes remove recovery macros from the compiler-facing source.

The source includes the generated module comments that record important binary facts.
Function-specific attempt history remains in those comments until later review.

## Integration handoff

The global `config/translation_units.json` registry still points to the old wrappers.
The main agent owns that shared file.
It must map all 63 owners to `src/taiuaimd.cpp` and set the module source.
It must remove the obsolete prefix and soldier groups.
