# December 1999 patch bug comments

## Scope and evidence

The user supplied the December 1999 Age of Empires 1.0c / Rise of Rome 1.0a readme.
Its fix list identifies research targets. It does not prove that every defect exists in this beta.
No patched executable was compared.

The behavior oracle is the repository's July 17, 1998 expansion beta:

`orig/empiresx.exe`

SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

`orig/_original_empiresx_from_beta_that_was_decompiled.exe` has the same hash.
`tools/extract_original_function.py` reads that copy through `config/binaries.json`.
The source is an expansion beta, not a base-game-only build.
See [the beta/release survey](beta_vs_retail_exe_survey.md) for build identity.

Investigation base: `6da185019aeedb1747dda2f46dfaf062a7437b20`.

The generated inventory supplied symbol and layout references.
Fresh disassembly from the original PE supplied instruction evidence.
Source comments describe confirmed mechanisms, not guessed patch implementations.

Confidence limits: the missing checks and cheat branches have original instruction support.
Their correspondence to the December 1999 fixes remains an interpretation of the supplied readme.
No ordinary-input exploit sequence or patched-build change was proved.

## Static evidence: converted dock

Changed owner: `src/tact_trd.cpp`, `TRIBE_Action_Trade::update` (`004D2CB0`).

An existing trade action stores its home dock in `target_obj2`.
The update removes missing objects and objects in state 7 or higher.
It does not reject a home dock whose owner changed.

The owner test at `004D2D29-004D2D41` applies to `target_obj`, the foreign trade dock.
It does not apply to `target_obj2`.
`set_state(8)` (`004D2880`) also retains the home dock when its master ID still matches `drop_site`.
The checks at `004D2AFC-004D2B14` do not read its owner.

After movement completes, the drop-off credits the boat's owner, not the dock's owner.
`004D3161-004D3167` loads the boat's owner.
`004D31AB-004D31B6` credits attribute 3, gold, through that player.
Thus, conversion can leave an existing route usable by the former dock owner.

The new `//! @bug` comment identifies the missing home-dock owner check.
This differs from the existing building-conversion list defect in `src/t_b_obj.cpp`.
No runtime conversion test ran.

## Static evidence: training at the wrong building

Changed owner: `src/tcommand.cpp`.

- `TRIBE_Command::do_command_make` (`00509980`).
- `TRIBE_Command::do_command_queue` (`0050A7B0`).

The ordinary interface filters units by `TRIBE_Master_Combat_Object::id_of_building_obj`.
See `TRIBE_Player::interface_item_avail` in `src/tplayer.cpp`.
The command execution paths do not repeat that check.

The direct path resolves `unit_id`, checks existing work, and creates the requested training action.
`005099DA-00509A21` checks work types 0x67 and 0x66, then passes the packet's `obj_id` to the constructor.
It does not compare the requested unit's required building with the actual building.

The queue path passes `train_id` to `add_to_production_queue` at `0050A7D0-0050A7D6`.
That function (`004C9870`) checks costs and stores queue entries, but does not check the required building.
`TRIBE_Action_Make_Obj::first_in_stack` (`004D0FC0`) checks the prototype and payment, not its production building.
`update` (`004D10F0`) uses the selected producer's work rate and the requested unit's build time.
Its placement path creates the requested unit through the owner's master-object table.

Two `//! @bug` comments identify the direct and queued acceptance paths.
This proves acceptance of a mismatched training order, not a specific mouse or keyboard exploit sequence.
Some cheats intentionally use `command_make` at a Town Center for special units.
Do not repair these paths as part of comment work.

The readme's broader building wording remains unproved for non-training construction orders.

## Confirmed: multiplayer cheat availability

Changed owner: `src/tribegam.cpp`, `TRIBE_Game::processCheatCode` (`00527A70`).

The function checks `allowCheatCodes` at `00527AFE`.
Its single-player block ends before the GAIA, STEROIDS, REVEAL MAP, and NO FOG branches.
Those branches have no single-player check.
This finding applies when the game enables cheats. It does not prove a bypass of the cheat setting.

| Command | Original string VA | Effect |
|---|---|---|
| GAIA | `0058C07C` | Selects local player 0 at `005281D9-005281E0` |
| STEROIDS | `0058C014` | Submits `command_quick_build` at `005283AB-005283C0` |
| REVEAL MAP | `0058BFEC` | Sends cheat 230 at `0052844A` |
| NO FOG | `0058BFE0` | Sends cheat 231 at `00528487` |

The original encoder at `00520FC0` reads its table at `0058B860`.
A PE inspection script encoded the four names and checked their original strings, including terminating zero bytes.
All four agreed.
`TRIBE_World::cheat` dispatches 230 to `set_map_visible(1)` and 231 to `set_map_fog(0)`.
The quick-build command changes the shared `quick_build` setting.

Plain `//!` comments record these pre-patch commands.
They do not label permitted cheats as unconditional engine defects.
STEROIDS availability alone does not prove the separate multiplayer cheating exploit described by the readme.
Its exploit mechanism remains open.

## Targets without new source comments

| Readme target | Finding and next step |
|---|---|
| Market tribute | The inspected dialog already requires a completed market. Research another path only with a demonstrated trigger. |
| Wall overrun | The inspected sender clamps coordinates to 0..255. The placement loop uses signed integers. Check the view's edge-coordinate path. |
| Deleted shallows | The editor directly deletes objects in `RGE_Main_View::mouse_left_up_action`. Establish the shallows data row and passability changes first. |
| Building through diagonal walls | Construction uses movement to the target and the task's work range. Prove the blocked-wall geometry and completion path. |
| Farm replenishment on S | The inspected stop chain contains no established food reset. Trace a farm's actual action and master data before adding a bug comment. |
| Anti-trainer technology | No specific earlier defect or later integrity check was established. The readme describes a class of hacks. |
| Multiplayer launch reliability | No specific launch defect was established. Packet and timing evidence must identify the failing path. |
| Palmyran tribute with Full Tech Tree | Attribute 46 supplies tribute cost. Establish the civilization effect and Full Tech Tree initialization order. |

The market finding has direct original instruction support.
`TribeDiplomacyDialog` (`0043C930`) passes master ID 0x54, `certain_state = 1`, and `object_state = 2`.
See `0043D537-0043D54F`.
`find_by_master_id` (`004634C0`) requires exact state equality at `00463550-00463561`.
An unfinished state-0 market alone cannot pass that dialog check.
The tribute executor does not check markets, but that fact alone does not prove the listed user-visible bug.

The Shang and Phoenician balance changes need original game-data evidence.
No balance values changed or received new comments.
The idle-villager key is an enhancement, not a bug target in this pass.

## Changed files and validation

- `src/tact_trd.cpp`: converted home-dock comment.
- `src/tcommand.cpp`: direct and queued training comments.
- `src/tribegam.cpp`: multiplayer cheat comments.
- `workflow/decomp_notes/december_1999_patch_bugs.md`: evidence and open targets.

The source diff adds only ten comment lines. It changes no executable statements or declarations.
The three source files contain no `__LINE__` or `__FILE__` use.
Their line endings remain LF.

Static PE extraction and the four-string inspection completed with exit code zero.
`git diff --check` passed. The complete source diff was reviewed.
Generated disassembly remains under `build/asm/orig_<VA>_<name>.txt`.
The string inspection script is `build/patch-readme-investigation/inspect_cheats.py`.
The addresses and conclusions above retain the useful evidence outside ignored build files.

Compilation, matching, registry audits, linked-image audits, automated tests, and gameplay tests were not run.
This pass does not claim fresh byte equality or runtime reproduction of the listed bugs.
