# Reference tooling validation

## Scope and inputs

Source base: `729d94ca0`.
This work changes validation tools, reviewed storage ranges, tests, and workflow documents.
It changes no game function, shared declaration, registry status, original file, or compiler flag.
No gameplay testing or older executable execution formed part of this work.

Build: `build/executable/20260908T114411000888Z`.
All 226 C/C++ sources and the active assembly source build successfully. The executable links without unresolved symbols.

Input hashes:

- EXE: `f0a0a3eca7485ecdc865dfa5ee9357919f0b91ca326aa0c5f8da082d13d73eb5`
- Map: `18c0633c370bb8384c0c257131c7da189759da5e3329679267cfa5084f58acb7`

The build report records these hashes and all compiled and preserved object hashes.
Reports below describe this source snapshot, not future registry claims.

## Direct-call validation repair

The former fallback comparison reduced different C++ methods to the same short name.
The exactness gate now uses independent original linkage names and retains owner and signature information.
Unknown or conflicting symbols prevent exactness. Nonzero direct target addends also require more evidence.

The regression test uses the original call at `004C9737` to `00430810`.
It rejects `RGE_Action_Object::copy_obj` and accepts the original combat-object symbol.
A fresh `check_function.py --va 004C9710 --no-history` reports `MATCH`, `0.0000%`, and 69 bytes.
The repaired game source predates this tooling work.

Local data-reference reports now state that linked storage and initial data remain separate checks.
This work does not turn masked data-address bytes into ownership proof.

## Full function audit

Report: `build/validation/translation_units/report.json`.
All 224 configured translation units compile. The audit checks 5,260 functions.

Of the 4,722 registry matching claims:

- 4,390 pass the stronger local check;
- 311 lack complete direct-target evidence; and
- 21 have explicit direct-symbol disagreements.

The command exits one because 332 exact claims are not currently established.
This is not a compiler failure or evidence that this tooling changed game behavior.
No status was automatically changed or silently approved.

Across all statuses, the audit reports 396 functions with incomplete direct-target evidence.
Most missing-reference observations concern `__ftol` (828) and `strstr` (147).
These are reference observations, not distinct function counts.
Establish independent helper identities instead of restoring short-name acceptance.

The 21 explicit disagreements among matching claims split into:

- 17 callers with CRT spelling differences, such as `__open` versus `_open`;
- `004B42E0`, whose call names `TPanel::action` instead of `TEasy_Panel::action`; and
- three callers with ManagedArray declaration differences: `004EA280`, `004EF4E0`, and `004F1090`.

The ManagedArray differences include const qualification on `contains` and public versus protected access on `resize`.
Review source structure and declarations against original evidence before changing those callers.
CRT spelling differences require explicit alias or owner evidence. They do not establish 17 behavior defects.
The linked-address audit and local symbol audit intentionally answer different questions.
Linker sharing can make different symbols reach the same address without proving the source owner correct.

Other full-audit categories remain visible in the report, including scratch boundaries, targets, and accepted drift.
Fourteen nonmatching registry entries produce local matches and still need source review before promotion.

## Unresolved emission results

Report: `build/validation/header_emissions.json`.

| Result | Entries |
| --- | ---: |
| All emitted copies match; map selects an emitting object | 96 |
| Selected emission with a differing copy | 1 |
| Original identity or linked selection remains unknown | 69 |

The differing entry is `00426450`, `RESENDER::RESENDER`, in `include/com_hand.h`.
Its real `com_hand.obj` emission has 30 bytes, with two differing bytes.
The original symbol and boundary checks pass. No relocation occurs in that body.
This report does not establish equal behavior or approve drift.

The 69 unknown entries split into:

- 33 Tech functions without independent original linkage identities; and
- 36 header functions whose map owner does not identify an object that emitted that symbol.

Identical-code folding is a possible explanation for the second group, not an approved ownership conclusion.
For example, `00405D20` names `inAttackRange@RGE_Static_Object`.
Its known emissions match, but the map names `aibldmod.obj`, which did not emit that symbol.
The tool leaves that selection unknown instead of choosing an object by byte similarity.

As a positive example, `00405D40`, `RGE_Static_Object::rateOfFire`, has six matching emitted copies.
The map selects `act_obj.obj` at `00405A70`.
Other copies occur in Ani_obj, Dpl_obj, Move_obj, Stat_obj, and T_tre_ob.

The registry remains unchanged. These results supply concrete emission evidence for later route integration.

## Linked-reference results

Report: `build/validation/linked_references.json`.

Final counts are 6,393 pass rows, 5,623 unknown rows, and one failed reference.
These are report rows, not function counts or a complete coverage claim.
The reviewed UnitAIModule table contributes 56 passing initial-pointer checks.

The failed reference belongs to compiler-generated `TRIBE_Main_View::~TRIBE_Main_View`, original entry `00495490`.
Its original five bytes are `e9 cb e2 09 00`: a direct jump to `RGE_View::~RGE_View` at `00533760`.
The rebuilt entry at `00484C80` instead jumps to `RGE_Main_View::~RGE_Main_View` at `005233F0`.
The expected rebuilt RGE_View destination is `005195C0`.

The intermediate rebuilt destructor adds a vptr write:

```text
005233F0  c701187f5500  mov dword ptr [ecx], 00557F18
005233F6  e9c561ffff    jmp 005195C0
```

The original `RGE_Main_View` destructor at `0053DB30` is also a five-byte direct jump to `00533760`.
Its bytes are `e9 2b 5c ff ff`.
The current source declares that destructor in `include/vw_main.h` and defines an empty body in `src/vw_main.cpp`.

This establishes a different target and an extra memory write. It is not an approved equivalent forwarding chain.
Review implicit destructor generation and the affected source closure before changing those files.
This tooling work does not repair or suppress the finding.

## Reviewed game-pointer storage

The unknown-target report identified 337 references to `0062C574`.
Independent original PDB evidence establishes its owner:

```text
S_GDATA32: [0004:000AD574], Type: 0x109D, rge_base_game
0x109D: LF_POINTER, NEAR32, element type 0x109C
0x109C: LF_CLASS, RGE_Base_Game
```

The original PE section mapping places that record at `0062C574`.
Its four initial bytes are zero.
The canonical pointer declaration and definition already exist in `include/game_globals.h` and `src/game_globals.cpp`.
The rebuilt map names `?rge_base_game@@3PAVRGE_Base_Game@@A` at `005F91B8`.

The reviewed range now checks those 337 references and the initial null pointer.
This reduced unknown rows from 5,960 to 5,623 without changing game source.
The earlier pass count was 6,055; the final count is 6,393. The existing failure remains visible.

The largest remaining unknown target is `0054B700`, with 341 aligned references.
The inventory names it `__ftol`, but that display name is not independent linkage proof.
Investigate the original helper and pinned CRT object before adding a reviewed symbol supplement.

## Broader initial-data audit

Report: `build/validation/global_initializers.json`.
The PDB-named primitive audit reports 124 equal records and no differing records.
It also reports 107 type/startup review cases, 60 unmapped names, and one invalid original section.
These limits remain explicit. No startup effects or complete data-layout proof is claimed.

## Older-build tools

The January index verifies the survey's executable and map hashes.
It records 6,766 symbol rows and 3,711 shared original linkage names.
This overlap includes library and compiler symbols, not only normal game functions.

Successful live counterpart queries:

- `004020C0`, `RGE_Action_Bird::set_state`;
- `004C9710`, `TRIBE_Building_Object::copy_obj`; and
- `0050C730`, a Tech display-name search that returns five candidates without claiming original identity.

The first two queries produce older and target disassembly with named references.
The movement query `0045E970` finds no exact named counterpart in this build.
That result does not prove the older build lacks related movement behavior.

Reports remain under `build/references/`.
The pinned manifest and source tools allow reproduction without retaining temporary disassembly as the only evidence.

## Final validation

- Full test suite: 392 passes and 31 passing subtests.
- Natural translation-unit registry validation: pass.
- Line-ending check and `git diff --check`: pass.
- Hash-checked vtable report: 207 definitions, 203 located tables, no conflicting definitions, and no unresolved-symbol slots.

The vtable report is `build/validation/vtables.json`.
Fewer usable exact anchors can reduce its location coverage under the stronger checks.
Its zero unresolved-symbol slots does not prove every virtual target or table boundary.
The separate reviewed UnitAIModule pointer checks provide the bounded 56-slot result described above.

The final local checks retain `004C9710` as `MATCH` and reject `004B42E0` with four differing call-address bytes.
The latter reports 528 equal-sized bytes and the wrong base-method symbol despite full instruction-shape and call-count alignment.

Two stale test counts required correction after the earlier ManagedArray resize classification change, commit `1d5ffd9d5`.
The tests still check every normal registry entry and reject duplicate ownership.

The audits intentionally do not report a clean recovery baseline.
Next work should establish missing CRT identities, review the explicit symbol disagreements, and resolve folded header selections.
Use the older-build queries and variant lab for source hypotheses. Do not suppress failed checks to restore old counts.
