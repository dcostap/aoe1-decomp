# AI build-list categories

`BuildItem::buildCategory()` returns a small integer. `AIBuildList::loadBuildList` sets it from the
first letter of each line of a `.ai` or `.bld` file. `include/aiblditm.h` now names the values.

| Value | Letters | Macro | What the code does |
| --- | --- | --- | --- |
| 0 | B, A | `BUILD_CATEGORY_BUILDING` | A master-object ID is placed with the construction AI. An `A` line also reads a build cap. Only this category is checked against `typesToIgnore`. |
| 1 | R | `BUILD_CATEGORY_RESEARCH` | A research ID. It is checked with `researchAvailable` and `researchCost`. |
| 2 | U, T | `BUILD_CATEGORY_UNIT` | A master-object ID trained at `buildFrom`. A `T` line also reads a build cap. |
| 3 | L | `BUILD_CATEGORY_LOAD_BUILD_LIST` | Tactical update 13 takes the item and loads `<name>.bld` as the new build list. |
| 4 | C | `BUILD_CATEGORY_BLOCKING_RESEARCH` | Handled as research. When it is unavailable or unaffordable, `nextBuildableItem` returns 0 and stops at this item. |
| 5 | E | `BUILD_CATEGORY_ENABLE_ATTACK` | When it comes first, the AI calls `enableAttack(1)` and marks the item built. |
| 6 | G | `BUILD_CATEGORY_GATHERER_PERCENTAGE` | Sets strategic number `typeID + 0x9C` to `buildFrom`. `setStrategicNumber` clamps 0x9C to 0x9F to 0..100. |

Only category 6 has a developer name. `TribeBuildAIModule::insertGathererPercentage(rType,
percentage, ...)` inserts it. The other names are cleanup labels taken from the behavior above.
The `.ai` files in `XPack/data2` use `C` only for `Tool_Age`, `Bronze_Age`, and `Iron_Age` (IDs
101 to 103), so the C category acts as a gate before each age. Those files have no `L`, `E`, or `G`
lines.

The macros are used in these places:

- `buildCategory()` comparisons;
- the loader switch;
- the `category` parameter of `nextBuildableItem` and its callers;
- the category arguments of the `*ItemsOfType`, `allBuilt`, `buildItem`, and `insertItem` calls.

`aiuaimod.cpp` has a local named `category` near `desiredRelation`. It is not a build category and
stays as it is.

## `TribeBuildAIModule::insert` locals

This function had two mislabeled locals. The local named `flags` held 2 or 0 and was passed as the
`buildCategory` argument of `insertItem`. The local named `buildCategory` held a building master ID
and was passed as `buildFrom`.

The PDB gives this function one stack local, `buildCategory` at -8. The original code
(`004D57A0`) stores 2 or 0 in that slot and pushes it as the fourth `insertItem` argument. The
other value is held in `ebp`, so it has no PDB record. The locals are now `buildCategory` and
`buildFrom`.

`numberBuiltOrInProgressItemsOfType` also compared `type` with 0x67 and 0x44. Those values now use
the `MASTER_OBJECT_STORAGE_PIT1` and `MASTER_OBJECT_GRANARY` names.

Validation: a full translation-unit audit kept all 5,013 exact claims. 224 of 225 object payloads
equal the baseline. The one difference is `rmm_tdbc.obj`, from the earlier include change.
