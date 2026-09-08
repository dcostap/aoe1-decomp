# Header routes and VC5 linker folding

## Behavior

No game was run. No game source or header body changed.
The reviewed base commit is `b9201cd69`.
This review establishes compiler routes. It does not promote source equivalence or approve aliases between different methods.

The 36 unresolved functions already have source in eight headers.
Their original linkage identities and complete local boundaries remain mandatory.
They contain only one to five bytes each, with 122 original bytes in total.

## Source and linker evidence

The VC5 verbose linker log explicitly reports `Selected symbol` and `Replaced symbol(s)` groups.
Each record contains the decorated symbol and input object name.
The ordinary map gives a replaced symbol the selected symbol's object owner.
That object need not emit the replaced symbol. This caused the previous selection gaps.

For example, the linker replaces `RGE_Static_Object::inAttackRange` from `act_obj.obj` with `AIModule::loadState` from `aibldmod.obj`.
Both map names then point to the same linked address and `aibldmod.obj`.
The compiler route remains `src/act_obj.cpp`. The shared address does not make the two source symbols interchangeable.

A controlled probe relinks the same verified objects with default settings and with `/OPT:NOICF`.
Without folding, all 34 previously unknown audit rows select objects that actually emit their named symbols.
The default relink preserves every non-resource section byte from the baseline image.
The resource section differs; this comparison is not a whole-image byte-equality claim.
Both probe images remain evidence only and were never executed.

The permanent build now requests `/VERBOSE` and hashes `link.log`.
The header audit verifies that hash before it reads replacement records.
It follows explicit replacement chains and checks the final map address and object owner.
It requires unique actual emissions for the original symbol and the selected physical symbol.
For folded proof, it also compares both object bodies with the linked bytes and rejects relocations.
Malformed, conflicting, cyclic, stale, or incomplete evidence remains unknown.
Address sharing alone is not proof.

## Routes and bytes

A fresh build and audit prove all 133 header selections: 132 local matches and the existing RESENDER difference.
All 36 previously unresolved entries have matching local emissions and proved routes.
Of these, 34 use explicit folding records; two use direct map selection.
The direct selections are `0041A530` and `0046ED40`.

The new routes use these unchanged natural source files:

| Emitter | Functions |
|---|---:|
| `src/act_obj.cpp` | 5 |
| `src/aiuaimod.cpp` | 1 |
| `src/ani_obj.cpp` | 17 |
| `src/basegame.cpp` | 3 |
| `src/com_addr.cpp` | 1 |
| `src/diam_map.cpp` | 2 |
| `src/m_an_obj.cpp` | 2 |
| `src/player.cpp` | 4 |
| `src/scenario.cpp` | 1 |

The eight changed registries belong to `aiuaimod.h`, `basegame.h`, `com_addr.h`, `m_s_obj.h`,
`panel.h`, `player.h`, `scenario.h`, and `stat_obj.h`.
Each entry keeps header ownership and names one existing compiler source and its original symbol.
No wrapper, duplicate body, forced emission, or alternative compiler flag was added.

## Integration

The 36 entries move from unresolved to scratch, not matching.
Registry totals are 4,722 matching, 287 accepted drift, 16 verified logic, 401 scratch, and zero unresolved.
No unclaimed function or ownership conflict remains.
The existing 45 matching-claim evidence gaps and two resize disagreements are separate problems.
The RESENDER constructor also remains nonmatching.

Baseline experiment: `header-folding-baseline`, state `2702cc19028ecf13ccf73240acb205f4c959b9a9c981320af3016206dcd75262`.
Event `52dc11962aca2d2b97d72c1ca0934840b28b116b96955ecb80c7ead132237242` preserves the complete evidence archive.
It includes the probe, link inputs, logs, maps, images, route table, and audit reports.
This preserves evidence separately from the source-integration decision.

## Final validation

Integrated state: `db9a2dd02b306b0e18134bebf50fbe8874e2d885ee69b4bbab900ed1b6af8792`.
The fresh build is `build/executable/header-routes-final/20260908T144209989056Z`.
All 226 C/C++ sources and the assembly source compile. The image links without unresolved symbols.
The entry point and all non-resource section addresses and bytes equal the previous integrated image.

The complete function audit compiles 225 modules and checks all 5,426 normal functions.
All 36 newly routed functions pass their local module checks.
The existing matching claims remain unchanged: 4,675 pass, 45 lack reference evidence, and two have resize disagreements.
The audit's nonzero exit remains intentional; those 47 claims do not count as validated matches.

Fresh standalone checks for `00405D20` and `00424E30` report `Result: MATCH` and `0.0000%`.
The final header audit reports 132 matching entries, one differing entry, and no unknown selection.
The linked audit remains at 6,846 passes, 5,237 unknowns, and zero failures.
The full test suite passes: 409 tests and 31 subtests.
Ownership checks, line endings, and `git diff --check` pass.
