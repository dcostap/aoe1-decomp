# taipbook.cpp source reunification

## Context

The PDB source is `C:\\msdev\\work\\age1_x1\\taipbook.cpp`. It owns five
normal functions. Their source-line bands and address sequence are:

| VA | PDB lines | bytes | owner |
| --- | ---: | ---: | --- |
| `004E68B0` | 23-24 | 18 | `TribeAIPlayBook::TribeAIPlayBook` |
| `004E6900` | 29-31 | 13 | `TribeAIPlayBook::convertTargetNameToIntType` |
| `004E6910` | 36-38 | 13 | `TribeAIPlayBook::convertTargetCharacteristicNameToIntType` |
| `004E6920` | 43-57 | 428 | `TribeAIPlayBook::convertUnitNameToIntType` |
| `004E6AD0` | 62-81 | 107 | `TribeAIPlayBook::convertUnitToIntType` |

The PDB symbols prove `TribeAIPlayBook` as the owning class. The constructor
calls `AIPlayBook::AIPlayBook`. The two forwarding methods call their direct
`AIPlayBook` targets. The unit-name method has six ordered `strcmp` handlers
and a direct base fallback. The unit classifier reads `master_obj->object_group`
and calls the virtual `RGE_Static_Object::weaponRange` slot at offset `0x10C`.
These calls and field offsets are the exact context anchors.

The nearby `004E68D0` vector-deleting destructor is compiler generated. It is
not a handwritten owner. The existing scalar-destructor scratch probe at
`004E68F0` remains outside this five-owner module set.

The module uses `config/flags/default.rsp`. No AIModule declaration is needed.

## Migration

`src/taipbook.cpp` now owns all five handwritten functions in PDB source order.
`include/taipbook.h` is the module-local compiler-facing header. It keeps only
the `AIPlayBook` and `TribeAIPlayBook` declarations. It includes the canonical
`stat_obj.h` header for the static-object ABI.

`convertUnitToIntType` reads `object_group` at the proven `master_obj + 0x14`
offset. The module does not declare a local static-object class, master-object
class, or vtable.

The old wrapper and five source-bank fragments were removed. The source has no
`.cpp` includes, context-selection macro, fallback declaration block, inline
assembly, fake virtual slot, or raw vtable field. The module uses direct source
ownership in `config/translation_units.json`, and
`config/source_modules/taipbook.json` records all five matching owners.

## Validation

The generated packet is
`build/tu_plans/taipbook_cpp/packet.{json,txt}`. Before migration it reported
five registered exact owners, 579 normal bytes, and zero positional differences.

The three permitted cached focused checks for `004E68B0`, `004E68D0`, and
`004E68F0` rejected missing or stale rebuilt artifacts. They did not rebuild.

The post-migration candidate proposal is
`build/candidate_tus/taipbook/proposal.json`. The candidate compiled all five
owners and reported `MATCH`, zero byte differences, zero relocation target
mismatches, and zero boundary escapes for every owner. Its reports are under
`build/candidate_tus/taipbook/`.
