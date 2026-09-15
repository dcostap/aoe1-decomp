# `src/tplayer.cpp` cleanup report

## Scope

This cleanup changes only `src/tplayer.cpp`.

The source now uses supported PDB names for parameters and locals. It does not change function names, types, scopes, calls, or data flow.

Key recoveries include:

- `TRIBE_Player` and `TRIBE_Gaia` file, world, player, and scenario names.
- Cost, availability, interface, and command names such as `obj_id`, `list`, `list_num`, and `attribute_needed`.
- Random-start locals `w2`, `h2`, `w`, and `h1`.
- AI names `bL`, `cP`, `rS`, `mood`, `mapType`, `buildLists`, `mostBuiltUnit2`, `callerID`, and `recipientID`.
- Mouse result names `Obj_id`, `newFacet`, `text_id`, `ObjectType`, `ObjPlayer`, `MstrObjId`, `MaxHp`, `RtClickTable`, and `thisObj`.
- All 16 civilization setup functions now use `b`, `mapType`, `gameType`, and `mapSize`.
- Status, achievement, victory, attribute, and Gaia wrapper names from the PDB.

The build-list selection array is now named `buildLists`. The old `weights` name was not supported by the PDB.

## PDB evidence

The procedure-scoped extraction is in:

- `build/tplayer_evidence/pdb_records.txt`

It contains 106 procedure records. The records cover all 103 source definitions in this file. The extra records are overloaded procedures and compiler-generated scalar deleting destructors.

I inspected these source procedure groups:

- `TRIBE_Player` constructors and destructor; `make_scenario_obj`, `save`, `update`, `update_dopplegangers`, `scenario_save`, `scenario_load`, `load`, and `load_master_object`.
- `tech_cost`, `obj_cost`, `find_obj`, `make_new_object`, and the three interface availability functions.
- All command functions, including both `command_trade_attribute` overloads.
- Object and technology cost, payment, reimbursement, technology, and population functions.
- `random_start`, object and research cost wrappers, availability wrappers, AI status, AI control, logging, and AI command functions.
- Object registration, build, train, research, trader, gatherer, and diplomacy functions.
- `loadAIInformation`, `notify`, `notifyAI`, `intelligentCivSelection`, and `intelligentBuildListAndRulesSelection`.
- `setupEgyptian`, `setupGreek`, `setupBabylonian`, `setupAssyrian`, `setupMinoan`, `setupHittite`, `setupPhoenician`, `setupSumerian`, `setupPersian`, `setupShang`, `setupYamato`, `setupChoson`, `setupRoman`, `setupCarthaginian`, `setupPalmyran`, and `setupMacedonian`.
- `logStatus`, `trackUnitGather`, `get_achievement`, `load_victory`, `new_victory`, `add_attribute_num`, `analyize_selected_objects`, and `get_mouse_pointer_action_vars`.
- Both `TRIBE_Gaia` constructors, destructor, `save`, `update`, `load_master_object`, `random_start`, and `TRIBE_Player::scenario_postload`.

Evidence hashes:

- Base source blob: `bd436aa1bd57a02ca1c26ab69a5e3ce63aced680`.
- Cleaned source blob: `31f7862b3b78d76f7fa056bcee982c71d958d1ba`.
- PDB extraction: `e83eecb60607fac8ad2196b27e97f085b7c9567a85907bdfea0a8a78248b5f45`.
- Runtime language extraction: `a3543469d765ba433b3d06ef6eb5c0c462a8cd12055a1b206d6f0db7a151cd6d`.
- Runtime `language.dll` hash recorded in the extraction: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.

## Resource requests

The resource evidence is in `build/tplayer_evidence/runtime_language_tplayer_ids.json`. It uses `language.dll`, resource type `RT_STRING`, language `0x0409`.

Please review these additions in the root-owned `include/resource_ids.h`:

| Proposed name | ID or range | Evidence and use |
|---|---:|---|
| `IDS_TPLAYER_NONE` | `0x2775` | Payload ` <None> `. Loaded into `noneString` by `loadAIInformation`. |
| `IDS_TPLAYER_RANDOM` | `0x277B` | Payload `Random`. Compared with build-list, city-plan, and ruleset inputs. |
| `IDS_CIVILIZATION_NAME_BASE` | `0x27F6` | `master_player_id + 0x27F6` loads civilization names for IDs `0x27F7` through `0x2806`. |
| `IDS_BUILD_LIST_NAME_BASE` | `0x26930` | `selectedBuildList + 0x26930` loads build-list names. IDs `0x26930` through `0x269AC` have no payload in the inspected resource. |

The civilization range contains Egyptian, Greek, Babylonian, Assyrian, Minoan, Hittite, Phoenician, Sumerian, Persian, Shang, Yamato, Choson, an empty entry, `Unknown`, `Tribe Name`, and an empty entry. The empty payloads remain explicit in the evidence.

No resource symbol was added in this worker tree because the root owns `include/resource_ids.h`.

## Header requests

Please review these requests in the owning changes:

- `include/resource_ids.h`: add the four proposed resource names above.
- `include/tplayer.h`: add parameter names that match the cleaned definitions where useful. Keep all declaration types and signatures unchanged.
- `include/tplayer.h` and the first `TRIBE_Player` constructor: the PDB record also reports a stack name `reallyLoadAI`, but the source and header expose a three-argument constructor. This was not forced into the signature. It needs owner review against the ABI evidence.

## Unresolved evidence

The PDB reports reused stack homes. I did not force uncertain names into declarations.

In `get_mouse_pointer_action_vars`, the PDB reports `RtClickTable` with an `int` type at a reused stack home. The source keeps the proven table-pointer type.

The PDB reports overlapping cost-wrapper locals and does not expose every decompiler temporary. The source keeps existing types, scopes, and declarations for those uncertain cases.

## Validation

Per the wave procedure, no build, compiler check, matching check, audit, test, or game run was performed.

The source diff was reviewed with `git diff --check`.
