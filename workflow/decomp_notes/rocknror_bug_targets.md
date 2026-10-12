# RockNROR bug target ledger

Source: RockNROR 4.0.0.3 changelog (`RockNROR_README.txt`) and `RockNRorDoc`.
RockNROR is a closed-source fix mod. Its changelog is the only evidence for each defect.
The original executable is the behavior oracle.

## Workflow

1. One read-only subagent investigates one target. Model: `xiaomi/mimo-v2.6-flash`, thinking: high.
2. The main session validates each report fast. Outcome: accept or needs more research.
3. Accept means the report has source locations and a credible mechanism.
4. The main session adds the `//!` comments. Agents never edit source.
5. `//! @bug` needs proof. A quirk gets plain `//!` lines (see `workflow/docs/source_comments.md`).

## Status values

- `investigating` - an agent is on it
- `accepted` - report validated; comment added; location recorded
- `needs-more-research` - report is weak or wrong; queue a second agent
- `not-found` - no locatable code; keep the closest candidates in Notes
- `rejected` - not a real defect in original code

## Done before this ledger (3)

| ID | Target | Status | Location | Notes |
|----|--------|--------|----------|-------|
| D1 | Timer freeze at low game speeds | accepted | `src/world.cpp` (RGE_Game_World::update) | Truncating cast drops fractional ms; no remainder carry |
| D2 | Reveal map option skips players | accepted | `src/tribegam.cpp` (TRIBE_Game::create_game), `src/basegame.cpp` (RGE_Base_Game::set_player) | Applied once to non-computer players 1..N |
| D3 | "is scenario" flag lost on load | accepted | `src/tribegam.cpp` (TRIBE_Game::load_game) | Save file stores no scenario flag |

## Open targets (58)

| ID | Target | Status | Location | Notes |
|----|--------|--------|----------|-------|
| T1 | Building conversion CTD: lists not updated for both players | accepted | `src/t_b_obj.cpp` (TRIBE_Building_Object::change_ownership) | Missing remove/add_doppleganger_check for both owners; crash site unproven |
| T2 | CTD: AI villager task-switch for converted villagers | accepted | `src/taitacmd.cpp` (TribeTacticalAIModule::taskGatherer) | Unguarded rType index into arrays of 4; trigger unproven; see also addObject ordering at change_ownership |
| T3 | CTD: negative coordinates in invalid Move action | accepted | `src/act_move.cpp` (RGE_Action_Move_To::update) | Negative target wraps to byte; fault via get_zone_info; crash site unproven |
| T4 | CTD: kill* command with invalid player | accepted | `src/com_hand.cpp` (TCommunications_Handler::PreprocessMessages) | Unvalidated message index into PlayerHighSerialNumber[10]; "kill*" is the KILL-message path, not a cheat; trigger source unproven |
| T5 | CTD: random game with tech-tree-less civilization | accepted | `src/tworld.cpp` (TRIBE_World::new_game) | Missing `tribe_effect >= 0` guard; `effects[-1]` read |
| T6 | Fog crash on maps larger than 255x255 | accepted | `src/visible.cpp` (RGE_Unified_Visible_Map::Set_Map_Offsets) | 256-row table overflow into Map_Update_Suppresion; plain //! (limit) |
| T7 | Converted buildings invisible through fog | accepted | `src/t_b_obj.cpp` (TRIBE_Building_Object::change_ownership) | Same root as T1; missing registration kills the fog ghost for the ex-owner |
| T8 | Civilian count bug (resource 37) | accepted | `src/t_c_obj.cpp` (TRIBE_Combat_Object::change_ownership) | Transfer skips count update; same site covers T9 |
| T9 | Military count bug (resource 40) | accepted | `src/t_c_obj.cpp` (TRIBE_Combat_Object::change_ownership) | Same comment block as T8; resource 40 feeds largest army |
| T10 | Tree 393 invisible: wrong graphics | accepted | `src/m_s_obj.cpp` (RGE_Master_Static_Object::setup) | Data row 393 sprite null/empty; RockNROR copies from 391 (disasm-backed) |
| T11 | Discoveries count bug: AI wins too early | accepted | `src/tact_dar.cpp` (TRIBE_Action_Discovery_Artifact::check_objects) | No state/group filter; ghosts count; flags reset on rebuild; patched vector unproven |
| T12 | Human captures artefacts faster on first sight | accepted | `src/com_obj.cpp` (RGE_Combat_Object::update) | First-sight capture gate is human-only |
| T13 | Gaia player (0) alert sound wrong | accepted | `src/tplayer.cpp` (TRIBE_Player::notify) | Alert sound from attribute 26, no validation; gaia row leaves it 0 |
| T14 | Animals killed by animals lose food | accepted | `src/t_c_obj.cpp` (TRIBE_Combat_Object::produceWhenKilledBy) | Food kept only for killer group 4; area_attack zeroes always |
| T15 | Tech effect #6 (resource multiply) unsupported | accepted | `src/effects.cpp` (RGE_Effects::do_effect) | No case 6 in dispatch; plain //! (limitation) |
| T16 | Tech effect add/set armor-attack fails on missing class | accepted | `src/m_co_obj.cpp` (RGE_Master_Combat_Object::modify_delta) | No append path for armor/weapon entries |
| T17 | Tech effect "set" for attack/armor broken | accepted | `src/m_co_obj.cpp` (RGE_Master_Combat_Object::modify) | Set form indexes array by class number, not by type |
| T18 | Iron/post-iron civ bonus lost on upgraded units | accepted | `src/tscenaro.cpp` (T_Scenario::set_player_tech) | Age cascade runs upgrades before civ bonuses apply |
| T19 | AI alliance bloc vs human when no teams set | accepted | `src/taimdmd.cpp` (TribeMainDecisionAIModule::update) | Initial diplomacy bloc; world.cpp neutral init precondition | quirk |
| T20 | Farm hint and cursor wrong with villager selected | accepted | `src/tplayer.cpp` (TRIBE_Player::get_mouse_pointer_action_vars) | Full-hp gate drops farm context; retry shows no-selection hint |
| T21 | Fire galley icon and trainability after trireme | accepted | `src/scr_game.cpp` (TRIBE_Screen_Game::setup_buttons) | Slot overwrite, no collision check (calc_button_loc aliases ranges); which unit hides is data-dependent |
| T22 | HOME key jumps to random place | accepted | `src/tribegam.cpp` (TRIBE_Game::goto_notification_loc) | Ring never resets on load_game; unbounded recall; which sub-mechanism was fixed is unproven |
| T23 | Editor: temporary units become unselectable | accepted | `src/view.cpp` (RGE_View::pick_objects) | Negative-ID nodes dropped from picks; class 11/missiles are recyclable by design |
| T24 | Editor: unit status lost on scenario load | accepted | `src/tplayer.cpp` (TRIBE_Player::make_scenario_obj) | Status byte dropped (actions only); same defect in base copy at player.cpp:495 |
| T25 | Editor: wrong building set after civ change | accepted | `src/scr_sed.cpp` (TRIBE_Screen_Sed::set_player) | Civ change writes only PlCivilization; load applies no saved civ (scenario_make_player unused) |
| T26 | Editor: terrain change does not refresh view | accepted | `src/view.cpp` (RGE_View::do_paint case 9) | No immediate redraw vs cliff case; hidden terrains need forced rebuild | quirk |
| T27 | Stuck AI #1: missing unitId for unfinished buildings | accepted | `src/taibldmd.cpp` (TribeBuildAIModule::addItem) | gameStarted guard skips setGameID during play; rows keep gID -1 |
| T28 | Stuck AI #2: unfinished building destroyed | accepted | `src/taibldmd.cpp` (TribeBuildAIModule::removeBuiltItem) | built==1 gate misses dead unfinished sites; wonder latch blocks all building |
| T29 | Stuck AI #3: training building destroyed | accepted | `src/tact_mob.cpp` (TRIBE_Action_Make_Obj destructor) | No cancelTrain on delete; inProgress=1 sticks; contrast Make_Tech dtor; stop() also lacks cancelTrain |
| T30 | Stuck AI #4: panic mode floods strategy | accepted | `src/taitacmd.cpp` (TribeTacticalAIModule::checkForAttackResponseBuildInsertions) | Fixed list at strategy head eats the scan budget (SN 0x73) |
| T31 | Building history blocks rebuild | accepted | `src/taibldmd.cpp` (TribeBuildAIModule::removeBuiltItem) | Lot history never released on destroy; canPlace blocks the type; 2nd block in removeBuiltItem (T28 has 1st) |
| T32 | Repairmen stuck when path blocked | accepted | `src/tact_rep.cpp` (TRIBE_Action_Repair::set_state case 10) | Out-of-range abort → state 10 dead-end → reported done → stopObject; retry states 9/12 unreachable |
| T33 | Enemy detection ignores seen units | accepted | `src/com_obj.cpp` (RGE_Combat_Object::update) | Record positions freeze at first sight; GetVisibleUnits drops stale records |
| T34 | Targeting formula score / factor | accepted | `src/aidipmod.cpp` (DiplomacyAIModule::mostHated) | Missing *100 scale, binary-proven; same block as T35 |
| T35 | SNAttackWinningPlayer=0 subtracts score | accepted | `src/aidipmod.cpp` (DiplomacyAIModule::mostHated) | Zero falls into the subtract branch; shared site with T34 |
| T36 | AI targets ally and stays inactive | accepted | `src/aidipmod.cpp` (DiplomacyAIModule::mostHated) | Scan lacks ally filter; engine refuses the attack; 3rd defect in mostHated |
| T37 | More than one farmer per farm | accepted | `src/taiuaimd.cpp` (TribeCivilianUnitAIModule::processNotify) | Unit-level farm re-task bypasses the one-farmer guard in taiinfmd.cpp |
| T38 | Villager loses resources after farm build | accepted | `src/tact_bld.cpp` (TRIBE_Action_Build::update) | Farm branch arms timer=-1; carry discarded at act_gath.cpp:61; hits human builders too (no gate) |
| T39 | Bad gatherable target choice | accepted | `src/taiuaimd.cpp` (TribeCivilianUnitAIModule::convertToLOSResourceType) | Mixed match keys + need/age-blind fallback; RockNROR dispatch keys prove patch sites; exact gold path unproven |
| T40 | Priests stuck on enemy unfinished constructions | accepted | `src/tact_cnv.cpp` (TRIBE_Action_Convert::update) | Guard wants state == 2, selectors accept < 3; drop/re-pick loop |
| T41 | Unit group attacks own units | accepted | `src/aiuaimod.cpp` (UnitAIModule::processGroupNotify) | Notify caller saved as attacker unchecked; ally splash -> attack abort -> group loops forever |
| T42 | Target hesitation (2-priest trick) | accepted | `src/aiuaimod.cpp` (UnitAIModule::processNotify case 500) | Zero-damage target -> re-aim per event; 2 priests alternate -> action rebuild loop |
| T43 | AI units attack empty location | accepted | `src/aiuaimod.cpp` (UnitAIModule::update) | Frozen order-time coords + dead-target fallback walks to them; move vs literal attack hedged |
| T44 | AI ignores dead predator animals | accepted | `src/taiinfmd.cpp` (TribeInformationAIModule::importantResource) | Group 10 missing from registration; carcass bonus unreachable; T14 is the food-zeroing sibling |
| T45 | SNScalingFrequency minutes vs seconds | accepted | `src/taitacmd.cpp` (TribeTacticalAIModule::update) | sn[0x63] * 60000 on ms clock = minutes; RockNROR switches unit to seconds | quirk |
| T46 | DM AI builds too many farms | accepted | `src/taitacmd.cpp` (TribeTacticalAIModule::checkForBuildInsertion) | Only farm cap is sn[0xDC] row budget (8); no DM condition or need test; overflow unproven | quirk |
| T47 | Strategy dependency order for dynamic units | accepted | `src/taibldmd.cpp` (TribeBuildAIModule::initialize) | Stale load-time anchors + list shifts; Trireme splices before Iron Age entry and escapes the age gate |
| T48 | Save-game AI info loss | accepted | `src/taimdmd.cpp` (TribeMainDecisionAIModule load ctor) | firstUpdate not in save stream; load forces 0; pending init (dynamic items, learn path, bonus) skipped |
| T49 | AI flips diplomacy on ally attack (SN 215) | accepted | `src/taitacmd.cpp` (TribeTacticalAIModule::notify) | hitsByPlayer never resets; default-on flip (p[215]=1) to enemy after 3 hits |
| T50 | Range units retreat vs superior range | accepted | `src/taiuaimd.cpp` (TribeSoldierUnitAIModule::processNotify) | Shoot-then-back-off never reads target range; RockNROR adds the superior-range guard | quirk |
| T51 | Attack roundup targets non-visible units | accepted | `src/taitacmd.cpp` (TacticalAIGroup::task case 20) | Existence-only check; no visibility test in chain; dev-cheat origin |
| T52 | Combat tests blast radius == 0 not blast level | accepted | `src/t_c_obj.cpp` (TRIBE_Combat_Object::do_attack) | Radius test where blast level is correct; copies at com_obj gates and UI button |
| T53 | Id 0 vs -1 sentinel confusion | accepted | `src/tech.cpp` (TRIBE_Player_Tech::check_for_new_tech) | Zeroed pre_reqs slot reads as requirement on research 0; unused research fires (29: tower arrows) |
| T54 | Conversion resistance hardcoded per class | accepted | `src/tact_cnv.cpp` (TRIBE_Action_Convert::update) | Hard-coded ladder 4 Macedonian / 2 boats+priests / 8 chariots / 1 rest | quirk |
| T55 | Trading hardcoded to docks and gold | accepted | `src/tact_trd.cpp` (TRIBE_Action_Trade::update) | Drop-off credits gold only; 4 dock-only filters (tplayer/taiinfmd/taiuaimd/t_c_obj); cursor clause unresolved | quirk |
| T56 | Game speed locked to 1 / 1.5 / 2 | accepted | `src/scr_game.cpp` (TRIBE_Screen_Game::command_game_speed) | Fixed ladder + 3 dialog buttons; non-ladder speed makes keys no-op | quirk |
| T57 | Research cycles can freeze or crash | accepted | `src/tech.cpp` (TRIBE_Player_Tech::do_rev_tech) | Unguarded recursion before state change; scenario/world age-grant triggers; original behavior |
| T58 | Map dimensions limited to 255 | accepted | `include/basegame.h` (RGE_Game_Options) | Byte map sizes wrap above 255; pathsys 255x255 grids and byte coords cap too | quirk |

## Out of scope

- empires.dat data errors: villager work rates, blast level defaults, missing tech-tree disable effects.
- RockNROR-only features: gates, multi-queue, custom civs, tilesets, triggers, RPG mode.
- Windows 10 slowdown: OS issue.
- SLP display limit for shortcut numbers 11-20: graphics limit.

## Research queue

Separate questions found during validation. Not changelog bugs.

| ID | Question | Status | Notes |
|----|----------|--------|-------|
| R1 | `unified_map_offsets` is declared `[1024]` in `src/game_globals.cpp:175`; the binary proves 256 entries ending at `Map_Update_Suppresion` (`0x886C08`) | needs-more-research | Rebuild exactness risk. `workflow/decomp_notes/dat_cleanup.md:273` and `workflow/decomp_notes/functions/0053/0053C920.md` disagree on the extent |

## Run book

- Batch request JSON: `build/subagent_batch.json` (all 58, wrapped in a `batch` key).
- Generator: `build/make_subagent_batch.py`.
- Exact model id: `openrouter/xiaomi/mimo-v2.6-flash` (provider prefix is required).
- Wave 1 (T1-T20): batch `batch-6e0f203b`, complete. 20 of 20 accepted.
- Wave 2 (T21-T40): batch `batch-d55b0274`, complete. 20 of 20 accepted (T39 partial, hedged).
- Wave 3 (T41-T58): HOLD per user. Do not launch without a new request. Rows are `queued`.
- Wave split uses `agents[:20]`, `agents[20:40]`, `agents[40:]`.
