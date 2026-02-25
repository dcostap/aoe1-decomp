# Multi-Agent Task Queue (AoE1 Decomp)

Date created: 2026-02-22

This file captures a set of **independent, queueable tasks** suitable for running in parallel across multiple agents.

Rules of engagement:
- Agents should **not run the EXE**; work should be decomp/ASM transliteration + compile-only verification.
- Prefer **decomp-first**, do **ASM audit** only when needed (signedness/struct layout/branch conditions).
- Avoid broad refactors; keep changes surgical and parity-focused.

---

## Task 1 — Finish core world save/load + end-condition logic
- [x] Finished
- Implement: `RGE_Game_World::load_world` (0x005420F0), `RGE_Game_World::load_game` (0x00542360), `RGE_Game_World::check_game_state` (0x005433C0)
- Where: src/game/src/RGE_Game_World.cpp, src/game/include/RGE_Game_World.h
- Source of truth: src/game/decomp/world.cpp.decomp + audit branches/reads in src/game/decomp/world.cpp.asm
- Done when: no TODO bodies for these three; load paths compile cleanly without new stubs.
- Status note: implemented and marked fully verified in code (recent merge `agent/world-save-load-end`, implement commit `ba9ba70`).

## Task 2 — Wire the minimap into the in-game screen (map_view is currently never created)
- [x] Finished
- Implement: constructor/initialization parity that allocates `map_view`, calls `RGE_Diamond_Map::setup`, `set_world`, `set_bitmap("map_bmp", 0xC4E1)`, `set_player`, and links `map_view->main_view`
- Where: src/game/src/TRIBE_Screen_Game.cpp
- Source of truth: src/game/decomp/scr_game.cpp.decomp (search for the TRIBE_Diamond_Map_View / RGE_Diamond_Map setup block)
- Done when: `runtime.map_view` is non-null in the real view path, and the existing `player_changed()` logic actually updates it.
- Status note: `runtime.map_view` now created as `TRIBE_Diamond_Map_View` and linked to main view (merge `agent/wire-minimap`, implement commit `8d9ed33`).

## Task 3 — Implement real multi-select picking (remove the last big view stub)
- [x] Finished
- Implement: `RGE_View::pick_multi` at 0x00535A80, plus the missing helper pipeline it relies on (`pick_objects`, `pick_multi_objects`, `Picked_Objects` layout/stride assumptions)
- Where: src/game/src/view.cpp (and any supporting declarations needed in src/game/include/RGE_View.h)
- Source of truth: src/game/decomp/view.cpp.decomp (pick_multi block) + verify any “picked object list stride” details in src/game/decomp/view.cpp.asm
- Done when: the `pick_multi` TODO/STUB block is gone and selection uses the decomp’s pick/weight logic (not `player->select_area` fallback).
- Status note: `pick_multi` + `pick_multi_objects` implemented and `Picked_Objects` restored (merge `agent/pick-multi-select`, implement commit `08eb00c`).

## Task 4 — Restore `_ASMSet_Shadowing` / surface-info glue used by rendering
- [x] Finished
- Implement: `_ASMSet_Shadowing` (and likely the related setters it implies) so view/shapes can apply the intended shadowing transforms
- Where: src/game/src/Drawarea.cpp (currently a no-op stub)
- Source of truth: src/game/decomp/bucket_056C.decomp + src/game/decomp/drawarea.cpp.decomp
- Done when: no-op stub is removed and the configured values are actually consumed by the draw/blit path (not just stored and unused).
- Status note: `_ASMSet_Shadowing` + `_ASMSet_ShadowingEx` restored and integrated with software renderer (merge `agent/restore-asm-shadowing`, implement commit `3ffcf60`).

## Task 5 — Restore training/research actions (unblocks core gameplay production)
- [x] Finished
- Implement: `TRIBE_Action_Make_Obj` + `TRIBE_Action_Make_Tech` (constructors, `update`, `stop`, `save`, etc.)
- Where: add/update sources under src/game/src for these classes; headers already exist:
  - src/game/include/TRIBE_Action_Make_Obj.h
  - src/game/include/TRIBE_Action_Make_Tech.h
  Then remove stubs in src/game/src/TRIBE_World_types.cpp (`do_command_make`, `do_command_research`).
- Source of truth: src/game/decomp/tact_mob.cpp.decomp, src/game/decomp/tact_tek.cpp.decomp, plus shared behavior from src/game/decomp/act_make.cpp.decomp
- Done when: the two command handlers no longer say TODO/STUB and they actually enqueue the action objects.
- Status note: action classes implemented and command handlers are now fully verified (merge `agent/restore-training-research-actions`, implement commit `5fac5b7`).

## Task 6 — Fix TRIBE object loading (required for correct saved-game/scenario object lists)
- [x] Finished
- Implement: `TRIBE_Combat_Object(fd, world, 1)` and `TRIBE_Building_Object(fd, world, 1)` load constructors + any immediate dependencies they require
- Where: new cpp(s) for these classes + update src/game/src/TRIBE_Object_List.cpp to match `TRIBE_Object_List::load` at 0x00511B00
- Source of truth: src/game/decomp/t_c_obj.cpp.decomp, src/game/decomp/t_b_obj.cpp.decomp, src/game/decomp/tobj_lst.cpp.decomp
- Done when: `TRIBE_Object_List::load` no longer punts to `RGE_Object_List::load` for `'F'/'P'`.
- Status note: compat shims replaced with real TRIBE load constructors and `TRIBE_Object_List::load` allocates real types (merge `agent/tribe-real-load-ctors`, implement commit `bc40d6b`).

## Task 7 — Message panel parity (used heavily by in-game UI/status)
- [x] Finished
- Implement: real `TMessagePanel::show_message2` (0x004793C0), `remove_message` (0x00479540), and `draw` (0x00479590)
- Where: src/game/src/TMessagePanel.cpp + any needed header fixes in src/game/include/TMessagePanel.h
- Source of truth: src/game/decomp/pnl_msg.cpp.decomp
- Done when: the current “minimal shim” TODO/STUBs are removed and TRIBE_Screen_Game message/score panels can rely on real behavior.
- Status note: restored rendering parity with fully verified markers (implement commit `50598b7`).

## Task 8 — Umbrella: retire `rge_object_virtual_stubs.cpp` by implementing real object virtuals
- [x] Finished
- [x] Assigned to agent
- Goal: keep this as a tracking umbrella so we don’t create overlapping “implement object virtuals” tasks.
- Implement: expand `RGE_Static_Object` virtual coverage (draw/update/command responders/etc.) so fewer calls land in placeholder behavior.
- Where: src/game/src/RGE_Static_Object.cpp and shrink/retire src/game/src/rge_object_virtual_stubs.cpp accordingly (only as real implementations land).
- Source of truth: src/game/decomp/stat_obj.cpp.decomp (+ ASM audit where signedness/offsets look sketchy).
- Done when: `rge_object_virtual_stubs.cpp` stops being a primary behavior path.
- Non-overlap note: do NOT include the following work in this umbrella (each is intentionally tracked separately):
  - Unique-id reassignment used during scenario object replacement.
  - `RGE_Moving_Object` movement/pathing glue.
  - `RGE_Combat_Object` combat mechanics (attack/damage/armor).
  - `RGE_Animated_Object` and `RGE_Missile_Object` parity.
  - `RGE_Doppleganger_Object` (fog-of-war ghost) parity.
- Status note: agent-run complete; remaining stub-retirement work is deferred to a follow-up umbrella focused on further shrinking `rge_object_virtual_stubs.cpp`.

---

## Task 9 — Replace TRIBE object load compat with real TRIBE load constructors
- [x] Assigned to agent
- [x] Finished
- Goal: remove the `*_Load_Compat` shim approach and restore the real TRIBE load constructor behavior so saved-game/scenario object lists deserialize with correct TRIBE-specific fields.
- Implement: `TRIBE_Combat_Object::TRIBE_Combat_Object(int fd, RGE_Game_World* world, int do_setup)` and `TRIBE_Building_Object::TRIBE_Building_Object(int fd, RGE_Game_World* world, int do_setup)` (names/params per decomp), then update `TRIBE_Object_List::load` to allocate the real types.
- Where: new src/game/src/TRIBE_Combat_Object.cpp + src/game/src/TRIBE_Building_Object.cpp (or integrate into existing TRIBE object translation unit if that’s the project pattern), plus src/game/src/TRIBE_Object_List.cpp.
- Source of truth: src/game/decomp/t_c_obj.cpp.decomp, src/game/decomp/t_b_obj.cpp.decomp, src/game/decomp/tobj_lst.cpp.decomp (+ ASM audit if sizes/offset reads look suspicious).
- Done when: `TRIBE_Object_List::load` uses real TRIBE constructors (no compat storage arrays) and the compat note is removed.
- Status note: real TRIBE load ctors are implemented and wired (merge `agent/tribe-real-load-ctors`, implement commit `bc40d6b`).

## Task 10 — Implement remaining software-renderer ASM “setters” used by the draw pipeline
- [x] Assigned to agent
- [x] Finished
- Goal: complete the remaining `_ASMSet_*` glue referenced by decomp/ASM so renderer state is parity-correct beyond shadowing.
- Implement: remaining functions from src/game/decomp/bucket_056C.decomp that correspond to exported helpers (e.g. `_ASMSet_Surface_Info` and any required companions), store their state in a parity struct, and wire it into the software draw path where applicable.
- Where: src/game/src/Drawarea.cpp (state + exports) plus whichever software-draw code consumes the state (likely shape drawing code).
- Source of truth: src/game/decomp/bucket_056C.decomp, src/game/decomp/drawarea.cpp.decomp, and call sites in src/game/decomp/view.cpp.decomp.
- Done when: no missing `_ASMSet_*` symbols for the render path, and state changes measurably affect the software draw behavior (without introducing new debug-only behavior).
- Status note: surface-info + color/xlate-table setters added and hooked up (merge `agent/asmset-renderer-state`, implement commit `9064cf5`).

## Task 11 — Minimap view wrapper parity (vw_dimap / tvw_dmap) and command forwarding
- [x] Assigned to agent
- [x] Finished
- Goal: remove remaining minimap view wrapper stubs and align minimap command behavior (click-to-move/work/do) with original.
- Implement: fill in `RGE_Diamond_Map_View` stubbed command handlers (`command_make_do/move/work`) and any other wrapper behavior required by the TRIBE minimap view path.
- Where: src/game/src/RGE_Diamond_Map_View.cpp and related headers under src/game/include; may also touch TRIBE_Diamond_Map_View glue if the TRIBE layer overrides behavior.
- Source of truth: src/game/decomp/vw_dimap.cpp.decomp, src/game/decomp/tvw_dmap.cpp.decomp, and the minimap setup/use sites in src/game/decomp/scr_game.cpp.decomp.
- Done when: minimap view wrapper no longer contains TODO/STUB blocks and minimap commands route into the same world/player command paths as the main view.
- Status note: `RGE_Diamond_Map_View` + `TRIBE_Diamond_Map_View` vw_dimap/tvw_dmap parity landed (including `command_make_do/move/work`) (merge `minimap diamond map view parity` / `c6c72a9`, implement commit `0492645`).

---

## Task 12 — Implement `RGE_Map::save` parity (saved-games + scenario map serialization)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the real map save path so `RGE_Game_World` save-game/scenario exports can serialize map state (tiles + visibility + random-map state) without relying on a stub.
- Implement: `RGE_Map::save(int fd)` (virtual) and any helper save routines it relies on (e.g. `save_map`, `scenario_save`, zone-map list save, unified visible map save, and version-gated tile packing).
- Where: src/game/src/RGE_Map.cpp (+ any needed declarations in src/game/include/RGE_Map.h).
- Source of truth: src/game/decomp/map.cpp.decomp @ 0x00457DF0 (and the nearby `save_map` / `scenario_save` blocks), audit suspicious packing/bit ops in src/game/decomp/map.cpp.asm.
- Done when: `RGE_Map::save` is no longer TODO/STUB, the helper calls compile/link cleanly, and the implementation matches decomp control-flow (including `save_game_version` branching and the sound-pointer-to-id rewrite behavior).
- Status note: `RGE_Map::save` implemented and ASM-audited (merge `agent/rge-map-save-parity`, implement commit `5968745`).

## Task 13 — Implement `TRIBE_Tech` text-file constructor (tech tree from data files)
- [x] Assigned to agent
- [x] Finished
- Goal: make the text tech-tree path usable (campaign/scenario + tech UI expectations) by restoring `TRIBE_Tech::TRIBE_Tech(char* filename)` parsing parity.
- Implement: full transliteration of `TRIBE_Tech::TRIBE_Tech(char*)` (file open, header parse, per-tech entry parse, underscore→space conversion, `getstring` usage, prereq/cost blocks, and help/page/hotkey ids).
- Where: src/game/src/TRIBE_Tech.cpp (+ any missing helper declarations in src/game/include/TRIBE_Tech.h).
- Source of truth: src/game/decomp/bucket_050B.decomp @ 0x0050BB84 (constructor) and @ 0x0050BF28 (destructor expectations); keep the existing binary-load constructor parity intact.
- Done when: the `// TODO(accuracy): implement full text file parsing.` note is removed, the constructor populates `tech_tree_num`/`tech_tree` identically to decomp (including bounds behavior), and `TRIBE_World::data_load_world` can create `TRIBE_Tech` from a loaded filename without falling back to an empty tree.
- Status note: text tech parsing restored via `bucket_050B` transliteration + `getstring` support (merge `agent/tribe-tech-text-ctor`, implement commit `7954169`).

## Task 14 — Restore `TRIBE_World` constructor parity (AI playbook allocation + loadPlays)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the original TRIBE world init that creates the TRIBE AI playbook and loads `data\\aoe.ply`, removing the current TODO(accuracy) gap.
- Implement: `TRIBE_World::TRIBE_World()` allocation of `TribeAIPlayBook` and `AIPlayBook::loadPlays("data\\aoe.ply")` (including correct storage into the base `RGE_Game_World` playbook member).
- Where: src/game/src/TRIBE_World.cpp (+ required includes/declarations for `TribeAIPlayBook` / `AIPlayBook` types).
- Source of truth: src/game/decomp/tworld.cpp.decomp @ 0x0052DF60, plus the underlying playbook units under src/game/decomp (AIPlayBook / AIModule blocks) as needed.
- Done when: the TRIBE_World constructor no longer has the TODO(accuracy) note for playbook creation, and the allocation/load call sequence matches the decomp (including null-check behavior).
- Status note: playbook init parity restored (alloc `TribeAIPlayBook` + `loadPlays("data\\aoe.ply")`) (merge `agent/restore-tribe-world-playbook`, implement commit `c444d6a`).

## Task 15 — Implement TRIBE cheat pipeline (`send_cheat` + `cheat`) and wire it to commands
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining TRIBE command-path stub for cheats and restore the original “cheat code” behaviors (gated by `RGE_Base_Game::allowCheatCodes`).
- Implement: `TRIBE_World::send_cheat(short)` and `TRIBE_World::cheat(short player_id, short cheat_id)` plus the missing call site in `TRIBE_Command::do_command_game_command` case 6.
- Where: src/game/src/TRIBE_World.cpp, src/game/include/TRIBE_World.h, and src/game/src/TRIBE_World_types.cpp.
- Source of truth: src/game/decomp/tworld.cpp.decomp @ 0x00530AC0 (send_cheat) and @ 0x00530AE0 (cheat); audit tricky branches in src/game/decomp/tworld.cpp.asm if needed.
- Done when: the `// TODO: STUB - TRIBE_World::cheat ...` block is removed, the game-command case dispatches to the real method, and the cheat function matches decomp call patterns (object lookup + `TRIBE_Command::command_make` / notification paths).
- Status note: cheat pipeline implemented and command dispatch wired (merge `agent/tribe-cheat-pipeline`, implement commit `dc4862e`).

## Task 16 — Finish `RGE_Panel_Tool_Box` parity (in-game tool panel buttons + key handling)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the partial/shim toolbox implementation so editor/toolbox mode changes and button-radio behavior match the original UI.
- Implement: full constructor parity (button setup, `set_text_info`, radio grouping via `set_radio_info`), `action` parity (button routing), and `key_down_action` parity for terrain/elevation tool behaviors.
- Where: src/game/src/RGE_Panel_Tool_Box.cpp (+ declarations in src/game/include/RGE_Panel_Tool_Box.h).
- Source of truth: src/game/decomp/rpnl_tbx.cpp.decomp @ 0x004898D0 (ctor), @ 0x00489E90 (dtor), plus src/game/decomp/rpnl_tbx.cpp.asm for any calling-convention/branch nuances.
- Done when: the three TODO/STUB notes in `RGE_Panel_Tool_Box.cpp` are removed and the code matches the decomp control flow (including the failure-path `error_code` behavior and button state/radio setup).
- Status note: toolbox ctor/dtor/action/key-down parity landed with fully verified markers (merge `Finish RGE_Panel_Tool_Box parity`, commit `6331dab`).

## Task 17 — RGE player lifecycle + notification parity (resign/state, relations, color table, cleanup)
- [x] Assigned to agent
- [x] Finished
- Goal: restore player-side parity that impacts in-game state changes (resign/game-status, diplomacy, selection groups) and reduce latent crash risk from partial destructor/cleanup behavior.
- Implement: missing `set_color_table` behavior on load, resign/game-status notifications via `rge_base_game`, relation-change propagation (including “notify all objects of relation change”), group-selection parity, and the remaining destructor cleanup paths (object lists/visible/doppleganger/VR list) using correct virtual destructors.
- Where: src/game/src/RGE_Player.cpp (+ any needed declarations in src/game/include/RGE_Player.h and related list/visible-map headers).
- Source of truth: src/game/decomp/player.cpp.decomp (+ audit in src/game/decomp/player.cpp.asm where signedness/offsets look suspicious) and TRIBE player overlays in src/game/decomp/tplayer.cpp.decomp where applicable.
- Done when: the key `// TODO(accuracy): ...` notes in `RGE_Player` load/destructor/resign/selection paths are eliminated, and the implementation compiles without introducing new linker-satisfaction stubs.
- Status note: load/destructor + status/notification parity restored (merge `agent/rge-player-lifecycle-notify-cleanup`, implement commit `484c077`).

---

## Task 18 — Retire temporary debug gates in game-start flow (object generation + game-screen transition)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining custom debug-only bypasses in the critical game-start path so control flow matches original parity.
- Implement:
  - `TRIBE_World::new_game`: remove the `DEBUGSKIPOBJGEN` gate and restore the unconditional `RGE_RMM_Object_Generator::generate()` call sequence per decomp.
  - `TRIBE_Game::start_game`: remove the `DEBUGBYPASSGAMESCREEN` bypass and restore the original `create_game_screen` transition behavior.
- Where: src/game/src/TRIBE_World.cpp, src/game/src/tribegam.cpp.
- Source of truth: src/game/decomp/tworld.cpp.decomp (new_game object-generation block) + src/game/decomp/tworld.cpp.asm as needed; src/game/decomp/tribegam.cpp.decomp + src/game/decomp/tribegam.cpp.asm (`start_game` @ 0x00525D20).
- Done when: the two `// TODO: STUB: Temporary debug gate...` blocks are removed and the surrounding control flow matches decomp (any remaining debug logging is either removed or fully gated behind `CUSTOM_DEBUG_ENABLED`).
- Status note: debug gates removed and original sequencing restored (merge `agent/retire-startflow-debug-gates`, commit `f185158`).

## Task 19 — Restore AVI/video callback pipeline used by `start_game` (and the post-video branches)
- [x] Assigned to agent
- [x] Finished
- Goal: re-enable the original intro/video-driven transition path (so `start_game(0)` reaches the game screen via video callbacks instead of a non-parity shim).
- Implement: transliterate the missing AVI decode/playback/callback flow in TRIBE game start, including restoring the currently stubbed branches for mission dialog and achievements/game-over.
- Where: src/game/src/tribegam.cpp (and any supporting AVI/video helper units it depends on).
- Source of truth: src/game/decomp/tribegam.cpp.decomp + src/game/decomp/tribegam.cpp.asm (noted stubbed branches include 0x00523C8D mission-dialog and 0x00523D0F achievements/game-over).
- Done when: the `// TODO: STUB: AVI playback/callback flow is not restored yet.` plus the two branch TODO/STUB notes are removed and the code compiles/link-clean without introducing new placeholder stubs.
- Status note: `start_video`/`stop_video` callback chain restored (MCI window playback), mission + achievements branches wired with new `TRIBE_Mission_Screen` / `TribeAchievementsScreen` (merge `restore AVI video callbacks`, commit `0fde90d`).

## Task 20 — In-game log/score UI parity (log scrollbar creation + message icon composition)
- [x] Assigned to agent
- [x] Finished
- Goal: eliminate remaining in-game screen UI shims so the log area and score panels behave like the original and don’t rely on “keep going on failure” fallbacks.
- Implement:
  - Remove the `TRIBE_Screen_Game` “accept null scrollbar and proceed anyway” fallback and ensure the screen creates/wires the log scrollbar exactly like the decomp.
  - Replace the score-panel `show_message2` type constant + icon selection/composition with exact parity (the remaining `pnl_msg.cpp`-driven behavior).
- Where: src/game/src/TRIBE_Screen_Game.cpp (and any underlying panel/scrollbar helpers needed).
- Source of truth: src/game/decomp/scr_game.cpp.decomp (log + score UI blocks) plus src/game/decomp/pnl_msg.cpp.decomp for the message/icon composition details.
- Done when: the log-scrollbar TODO/STUB note and the `// TODO(accuracy): Replace message-type constant...` note are removed and the implementation matches the decomp control flow.
- Status note: log scrollbar creation now hard-fails on error (no “proceed with null scrollbar”), and score icon composition parity landed (merge `agent/log-score-ui-parity`, commit `dfa0839`).

---

## Task 21 — Restore `TEasy_Panel` list + scrollbar infrastructure (unblocks multiple screens)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the shared list/scrollbar UI primitives so screen implementations can stop using placeholder text panels and TODO(accuracy) fallbacks.
- Implement:
  - `TEasy_Panel::create_list`, `TEasy_Panel::create_scrollbar`, `TEasy_Panel::create_auto_scrollbar` parity.
  - Core `TListPanel` behavior (line selection, text storage, click selection, keyboard navigation) and `TScrollBarPanel` behavior (page/line scroll, thumb position sync).
- Where: src/game/src/Panel_ez.cpp (TEasy_Panel helpers), src/game/src/Pnl_lst.cpp (TListPanel), src/game/src/Pnl_sbar.cpp (TScrollBarPanel), and fix call sites in:
  - src/game/src/scr_load_impl.cpp
  - src/game/src/scr_sels_impl.cpp
  - src/game/src/scr_vc* (victory conditions screen) and any other screen using `create_auto_scrollbar`.
- Source of truth: src/game/decomp/panel_ez.cpp.decomp + src/game/decomp/panel_ez.cpp.asm (TEasy_Panel helpers, including `create_scrollbar` @ 0x00469910 and `create_auto_scrollbar` @ 0x00469A80), plus src/game/decomp/pnl_lst.cpp.decomp, src/game/decomp/pnl_scbr.cpp.decomp, and the screen decomp units (scr_load.cpp.decomp, scr_sels.cpp.decomp, scr_vc.cpp.decomp).
- Done when: `TEasy_Panel::create_scrollbar` is no longer a hard stub, `create_auto_scrollbar` no longer returns success with a null scrollbar, the TODO(accuracy) notes in `scr_load_impl.cpp`/`scr_sels_impl.cpp` are removed, and `TribeLoadSavedGameScreen` stops casting a `TTextPanel` into a `TListPanel`.
- Status note: list/scrollbar primitives + screen call sites were restored (`Panel_ez.cpp`, `Pnl_lst.cpp`, `Pnl_sbar.cpp`, `scr_load_impl.cpp`, `scr_sels_impl.cpp`) (merge `agent/restore-list-scrollbar`, commit `cf0b271`).

## Task 22 — Remove `tribegam` screen-switch shims by restoring full `TPanelSystem` lifecycle parity
- [x] Assigned to agent
- [x] Finished
- Goal: eliminate the custom `gCurrentScreen` / deferred-delete screen retirement logic and use the real `TPanelSystem::setCurrentPanel` + `destroyPanel` flow so screen transitions match original and don’t leak panels.
- Implement:
  - Restore `TRIBE_Game` / screen codepaths to use `panel_system->setCurrentPanel(...)` and `panel_system->destroyPanel(...)` exactly like the decomp.
  - Remove the non-original retirement buffer/overflow leak behavior once dtors and destroy paths are safe.
  - Add any missing named-panel lookup behavior needed by screens (so “return to Game Screen when present” works).
- Where: src/game/src/tribegam.cpp, src/game/src/TPanelSystem.cpp (and any dependent panel teardown helpers).
- Source of truth: src/game/decomp/tribegam.cpp.decomp (+ asm audit in src/game/decomp/tribegam.cpp.asm for edge-case branching) and `panel.cpp` behavior referenced by existing `TPanelSystem.cpp` comments.
- Done when: `tribegam.cpp` no longer contains the `gCurrentScreen/gRetiredScreens` shim machinery, the `// TODO: STUB: retire buffer overflow handling.` note is gone, and the `scr_load_impl.cpp` cancel-path TODO(accuracy) about returning to “Game Screen” is resolved using real panel-system behavior.
- Status note: screen lifecycle parity restored and shims removed across `tribegam.cpp` + `TPanelSystem.cpp` and multiple screens (merge `agent/remove-tribegam-shims`, commit `88e4a0a`).

## Task 23 — Restore single-player campaign entry: people list + name selection + campaign dialog/screen pipeline
- [x] Assigned to agent
- [x] Finished
- Goal: make the Single Player “Campaign” button follow original flow (people profiles → name selection screen/dialog) instead of a stub popup.
- Implement:
  - `RGE_Game_Info::get_people_list` parity (0x0044D850) so UI can query existing profiles.
  - Also implement the adjacent `RGE_Game_Info::get_campaign_list` (0x0044D8C0) and `RGE_Game_Info::get_scenario_list` (0x0044D940) helpers from the same decomp unit, since they share allocation/string-copy behavior and are typically needed immediately by follow-on campaign/scenario selection screens.
  - Implement `TRIBE_Screen_Name` and `TRIBE_Dialog_Name` (constructors, action handlers, list population, new/remove/ok/cancel, teardown).
  - Wire `TribeSPMenuScreen::action` campaign button to the restored flow (matching the decomp: choose `TRIBE_Screen_Name` when list non-empty, else show dialog).
- Where: src/game/src/gameinfo.cpp (+ declarations in src/game/include/RGE_Game_Info.h), plus new/updated screen units for `TRIBE_Screen_Name` / `TRIBE_Dialog_Name`, and src/game/src/Scr_sing_impl.cpp.
- Source of truth: src/game/decomp/gameinfo.cpp.decomp + src/game/decomp/gameinfo.cpp.asm (get_people_list/get_campaign_list/get_scenario_list), src/game/decomp/scr_sing.cpp.decomp (campaign button flow), src/game/decomp/scr_name.cpp.decomp (name screen), and dialog decomp (dlg_conf.cpp.decomp / dlg_list.cpp.decomp / pnl_dlg.cpp.decomp as required by name dialogs).
- Done when: the `Scr_sing_impl.cpp` campaign TODO(accuracy) note is removed, `RGE_Game_Info::get_people_list` exists and matches decomp allocation/free expectations (uses `getstring`), and the SP “Campaign” button transitions into the correct name selection UI via `panel_system`.
- Status note: campaign entry flow restored (SP menu → name screen/dialog) and `RGE_Game_Info` list helpers implemented (merge `agent/sp-campaign-entry`, implement commit `9f6ade8`).

## Task 24 — Restore localized victory-condition descriptions (UI + status text parity)
- [x] Assigned to agent
- [x] Finished
- Goal: replace the placeholder `VC cmd=...` formatting with the original localized condition description strings so victory-condition UI/messages match the shipped game.
- Implement: transliterate `RGE_Victory_Conditions::condition_description` to map `command`/group/state fields onto the original string-table ids/text and formatting.
- Where: src/game/src/RGE_Victory_Conditions.cpp.
- Source of truth: src/game/decomp/victory.cpp.decomp + src/game/decomp/victory.cpp.asm (condition_description @ 0x00532CC0), plus scr_vc.cpp.decomp only for screen-side expectations.
- Done when: the TODO(accuracy) note in `RGE_Victory_Conditions::condition_description` is removed and the function returns the same localized text the decomp indicates (not generic debug strings).
- Status note: `condition_description` restored and marked fully verified (merge `agent/restore-vc-condition-description`, commit `baacaeb`).

## Task 25 — Implement in-game chat sending pipeline (player → chat/comm → UI)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the missing chat-send behavior so MP/SP chat actions route through the original `TChat` pipeline (and can appear in the in-game log/UI where applicable).
- Implement:
  - `RGE_Player::sendChatMessage(int,int,char*)` parity, including routing through `TChat` and/or comm handler as appropriate.
  - Any supporting `TChat` methods that are currently missing or stubbed in src (constructor, `AddChatMsg`, clearing, and group logic as required by call sites).
- Where: src/game/src/RGE_Player.cpp, plus the `TChat` implementation unit(s).
- Source of truth: src/game/decomp/player.cpp.decomp + src/game/decomp/player.cpp.asm (sendChatMessage @ 0x0046F2A0), src/game/decomp/chat.cpp.decomp (TChat behavior), and the comm send path in src/game/decomp/com_hand.cpp.decomp + src/game/decomp/com_hand.cpp.asm (e.g. `TCommunications_Handler::SendChatMsgAll` call sites), plus screen call sites in scr_game.cpp.decomp/scr_mps.cpp.decomp.
- Done when: the TODO(accuracy) stub in `RGE_Player::sendChatMessage` is removed and the implementation compiles/link-clean without adding new “linker satisfaction” forwarding stubs.
- Status note: chat send pipeline restored end-to-end (`RGE_Player::sendChatMessage`, `TChat`, comm handler send path) (merge `agent/chat-send-pipeline`, commit `11ec416`).

## Task 26 — Multiplayer setup parity: ensure comm object exists and host-start flow is functional
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining MP setup stub so host start validation can proceed on real comm state rather than failing early due to missing comm handler.
- Implement:
  - Restore comm object creation/ownership so `TribeMPSetupScreen::startGame` never sees a null `comm_handler` when `multiplayerGame()!=0`.
  - Audit and restore the init path that populates `comm`/`TCommunications_Handler` for MP screens.
- Where: src/game/src/scr_mps_impl.cpp (startGame path) plus whichever TRIBE/Base_Game init unit owns `comm` creation.
- Source of truth: src/game/decomp/scr_mps.cpp.decomp (startGame @ 0x004A2060) and the corresponding ASM for any init ordering; also directplay glue under src/game/third_party/directplay if needed.
- Done when: the `// TODO: STUB: multiplayer comm object should always exist in this path.` line is removed and the MP start path compiles with real comm creation wired.
- Status note: MP setup now ensures comm exists via `reset_comm`/wiring (merge `agent/mp-setup-comm-init`, commit `6a697ca`).

## Task 27 — Restore encrypted command-line option parsing (pop limit) parity
- [x] Assigned to agent
- [x] Finished
- Goal: make `setup_cmd_options` match original behavior for the obfuscated pop-limit argument so command-line driven runs (testing, scenarios) honor the same options as the shipped game.
- Implement:
  - Transliterate `encrypt_codes(char* in, char* out, int max_len)`.
  - Restore the pop-limit parse in `TRIBE_Game::setup_cmd_options` that depends on `encrypt_codes(cmd_line, encstr, 0x200)` and then searches the decoded string.
  - Add/restore the required translation table used by `encrypt_codes` (the per-character mapping array referenced by decomp).
- Where: src/game/src/tribegam.cpp (and any shared table/constants in an appropriate translation unit), plus any needed declarations in src/game/include/TRIBE_Game.h.
- Source of truth: src/game/decomp/tribegam.cpp.decomp (encrypt_codes @ 0x00520FC0; setup_cmd_options @ 0x00521FA0) + src/game/decomp/tribegam.cpp.asm for signedness/branch confirmation.
- Done when: the `// TODO(accuracy): encrypt_codes for obfuscated pop limit argument` note is removed and the control flow/limits match the decomp (including max buffer sizes and termination behavior).
- Status note: `encrypt_codes` restored and `setup_cmd_options` pop-limit parsing wired; follow-up pointer alignment fix landed in the next merge (commits `79a33b0` + `d33220f`).

## Task 28 — Implement Save Game screen parity (`TribeSaveGameScreen`)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the Save Game UI flow (file name entry, existing saves list, delete, OK/cancel, optional quit-after-save) so in-game save operations use the original screen rather than stubs.
- Implement: full transliteration of `TribeSaveGameScreen` (ctor/dtor + action handlers + list refresh + file naming rules) including mode switching between “SaveGame” and any other enum modes.
- Where: add src/game/src/scr_save_impl.cpp (or the project’s matching pattern) and wire it to the existing header src/game/include/TribeSaveGameScreen.h.
- Source of truth: src/game/decomp/scr_save.cpp.decomp (ctor @ 0x004A71F0) + src/game/decomp/scr_save.cpp.asm for any subtle calling/branch behavior.
- Done when: the screen is fully implemented and remaining save-screen TODO(parity) markers are eliminated (notably: no `MessageBoxA` fallback and scenario-editor-open return path matches decomp).
- Status note: agent-run complete; remaining TODO(parity) items in `scr_save_impl.cpp` are:
  - Replace any remaining `MessageBoxA` calls with the restored `TEasy_Panel` popup dialog helpers.
  - Restore the “return to scenario editor / open editor after save” control flow to match decomp.

## Task 29 — Implement End Screen parity (`TribeEndScreen`) and wire game-over transitions
- [x] Assigned to agent
- [x] Finished
- Goal: restore the “End Screen” shown after a match/campaign scenario ends, including background selection and OK routing back to the correct next screen.
- Implement: transliterate `TribeEndScreen` ctor/dtor + action behavior, including setup background selection by resolution and creating picture/text/button panels.
- Where: add src/game/src/scr_end_impl.cpp (or equivalent) wired to src/game/include/TribeEndScreen.h, plus any minimal wiring in `TRIBE_Game`/world game-over path that instantiates the end screen.
- Source of truth: src/game/decomp/scr_end.cpp.decomp (ctor @ 0x004936D0) + src/game/decomp/scr_end.cpp.asm.
- Done when: `TribeEndScreen` exists in src, constructs successfully with no TODO/STUB blocks, and the game-over branch reaches it via `panel_system->setCurrentPanel` parity.
- Status note: `TribeEndScreen` ctor/dtor/action implemented and game-over path constructs + activates it (merge `agent/end-screen`, implement commit `812e018`).

## Task 30 — Implement Achievements + Timeline screens parity (`TribeAchievementsScreen` + `Time_Line_Panel`)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the post-game achievements/statistics UI (including timeline view) so the “Achievements Screen” path is no longer a missing-screen hole.
- Implement:
  - Transliterate `TribeAchievementsScreen` ctor/dtor + action handlers (mode switching, back/ok/restart buttons, scrollbars for text areas, stat table fill).
  - Transliterate `Time_Line_Panel` and supporting `RGE_Timeline`/timeline-loading behaviors required by the screen.
- Where: new src/game/src/scr_ach_impl.cpp + src/game/src/timeline_impl.cpp (or equivalent), wired to existing headers src/game/include/TribeAchievementsScreen.h and src/game/include/Time_Line_Panel.h.
- Source of truth: src/game/decomp/scr_ach.cpp.decomp (ctor @ 0x0048D530), src/game/decomp/timeline.cpp.decomp (RGE_Timeline @ 0x0050D5B0) + corresponding `.asm` files.
- Done when: “Achievements Screen” can be constructed without stubs, the timeline panel allocates/loads correctly per decomp, and all code compiles/link-clean with no new placeholder forwarding stubs.
- Status note: Achievements screen + timeline UI parity landed (`Time_Line_Panel.cpp` commit `1bcd8b7`, `TribeAchievementsScreen.cpp` parity fixes commit `a5b9cdf`); timeline backing (`RGE_Timeline.cpp`) already exists (commit `24765e4`).

---

## Task 31 — Replace remaining `MessageBoxA` screen shims with `TEasy_Panel` popup dialogs
- [x] Assigned to agent
- [x] Finished
- Goal: eliminate remaining Win32 `MessageBoxA` usage in *screen/UI* flows by routing through the already-restored `TEasy_Panel` popup dialogs.
- Implement: replace remaining `MessageBoxA` call sites in screen implementations with:
  - `TEasy_Panel::popupOKDialog` (0x00469EE0)
  - `TEasy_Panel::popupYesNoDialog` (0x0046A040)
  - `TEasy_Panel::popupYesNoCancelDialog` (0x0046A150)
- Where: remove/update screen call sites in:
  - src/game/src/scr_save_impl.cpp
  - src/game/src/scr_load_impl.cpp
  - src/game/src/scr_mps_impl.cpp
  - src/game/src/Scr_sing_impl.cpp
  (Scope note: error/fatal popups in low-level bootstrap/resource code like `main.cpp` / `Res_file.cpp` are out-of-scope unless explicitly desired.)
- Source of truth: src/game/decomp/panel_ez.cpp.decomp + src/game/decomp/panel_ez.cpp.asm.
- Done when: those four screen files no longer call `MessageBoxA` and any TODO(parity) “MessageBox fallback” notes are removed, with build staying clean.
- Status note: as of current `master`, the listed screen files no longer call `MessageBoxA`/`MessageBox` (verified via `git grep`). Remaining `MessageBoxA` usage is only in low-level bootstrap/resource code (`main.cpp`, `Res_file.cpp`), which this task explicitly scoped out.

## Task 32 — Finish custom mouse pointer parity (basegame mouse-move path)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the original custom cursor behavior so the basegame mouse loop uses the same `in_game_mode → draw(0) vs Poll()` logic as the shipped game.
- Implement: `TMousePointer::in_game_mode` (0x0045B2C0), `TMousePointer::draw(int)` (0x0045BA60), and complete `TMousePointer::Poll` (0x0045C010) parity/wiring (including any required helpers like surfaces/cursor save-area paths).
- Where: src/game/src/Mouseptr.cpp, src/game/include/TMousePointer.h, and the call site TODO in src/game/src/basegame.cpp.
- Source of truth: src/game/decomp/mouseptr.cpp.decomp + src/game/decomp/mouseptr.cpp.asm, plus basegame.cpp.decomp for the call-site sequencing.
- Done when: the `basegame.cpp` TODO about `in_game_mode`/`draw(0)` vs `Poll()` is removed and the mouse pointer code matches the decomp control flow (no “return success but do nothing” helpers left in the hot path).
- Status note: custom cursor parity restored (`in_game_mode`, `draw`, `Poll` + missing helper fixes) and basegame now uses the original `draw(0)` vs `Poll()` split (merge `agent/restore-custom-mouse-cursor`, commits `9539bc0` + `abb598e`).

## Task 33 — Restore screenshot support (Ctrl+F12)
- [x] Assigned to agent
- [x] Finished
- Goal: implement the original screenshot capture path so Ctrl+F12 uses the real engine snapshot behavior.
- Implement: `TDrawArea::take_snapshot` (0x004463B0) and ensure the Ctrl+F12 path in basegame calls it.
- Where: src/game/src/Drawarea.cpp, src/game/include/TDrawArea.h, and src/game/src/basegame.cpp.
- Source of truth: src/game/decomp/drawarea.cpp.decomp + src/game/decomp/drawarea.cpp.asm.
- Done when: the `basegame.cpp` TODO(accuracy) about `TDrawArea::take_snapshot` is removed and build is clean.
- Status note: `TDrawArea::take_snapshot` implemented and Ctrl+F12 path wired in basegame (merge `agent/restore-screenshots`, commit `b704b95`).

## Task 34 — Restore window resize handler parity in draw system
- [x] Assigned to agent
- [x] Finished
- Goal: restore `HandleSize` behavior so window resizing updates draw surfaces/layout like the original game.
- Implement: `TDrawSystem::HandleSize` (0x004433F0) and wire basegame handle_size to call it with the correct parameters.
- Where: src/game/src (wherever `TDrawSystem` is implemented today), src/game/include/TDrawSystem.h, and src/game/src/basegame.cpp.
- Source of truth: src/game/decomp/drawarea.cpp.decomp + src/game/decomp/drawarea.cpp.asm (HandleSize implementation details) and basegame.cpp.decomp (call site).
- Done when: the `basegame.cpp` TODO(accuracy) about `TDrawSystem::HandleSize(p1,p2,p3,p4)` is removed and build is clean.
- Status note: `TDrawSystem::HandleSize` restored and basegame `handle_size` now forwards to it (merge `agent/restore-resize-handler`, commits `90b818e` + `11d8e4d`).

## Task 35 — Implement unique-id reassignment used during scenario object replacement
- [x] Assigned to agent
- [x] Finished
- Goal: restore the original replacement semantics in `RGE_Game_World::addObject` so scenario object replacement reassigns unique ids exactly like the shipped game.
- Implement: `RGE_Static_Object::change_unique_id` (0x004C1CF0) and call it from the replacement path in `RGE_Game_World::addObject` when `scenario_object_flag` is set.
- Where: src/game/src/RGE_Static_Object.cpp, src/game/include/RGE_Static_Object.h, src/game/src/RGE_Game_World.cpp.
- Source of truth: src/game/decomp/stat_obj.cpp.decomp + src/game/decomp/stat_obj.cpp.asm (change_unique_id) and src/game/decomp/world.cpp.decomp (+ asm audit for the replacement branch).
- Done when: the `RGE_Game_World::addObject` TODO(accuracy) about `replaced->change_unique_id()` is removed and build is clean.
- Status note: replacement semantics restored and `change_unique_id()` implemented/used when `scenario_object_flag` is set (merge `agent/scenario-replace-unique-id`, commit `9182602`).

## Task 36 — Replace TRIBE player AI compat shim with real `TribeMainDecisionAIModule`
- [x] Assigned to agent
- [x] Finished
- Goal: remove `TribeMainDecisionAIModuleCompatShim` so TRIBE player AI uses the real module/vtable, preventing subtle AI dispatch mismatches.
- Implement: full ctor/dtor + required virtuals for `TribeMainDecisionAIModule`, and update `TRIBE_Player` to allocate/use it (removing the compat shim + reinterpret-cast allocation path).
- Where: new src file(s) under src/game/src + edits in src/game/src/TRIBE_Player.cpp and matching headers under src/game/include.
- Source of truth: src/game/decomp/TribeMainDecisionAIModule.decomp + src/game/decomp/TribeMainDecisionAIModule.asm, plus call sites in src/game/decomp/tplayer.cpp.decomp.
- Done when: the shim class is removed, `playerAI` is a real `TribeMainDecisionAIModule`, and build is clean without adding new “linker satisfaction” stubs.
- Status note: `TRIBE_Player` now allocates/uses a real `TribeMainDecisionAIModule` and the compat shim path is gone (commit `1b3f6f5`, merged via `baa935e`).

---

## Task 37 — Implement `AIPlayBook::loadPlays` full `.ply` parsing (remove current stub)
- [x] Assigned to agent
- [x] Finished
- Goal: stop treating `data\\aoe.ply` as “loaded” when parsing is stubbed, so playbook data structures are actually populated.
- Implement: full transliteration of `AIPlayBook::loadPlays(char*)` (file format parse + allocation + per-play setup).
- Where: src/game/src/AIPlayBook.cpp (+ any needed declarations in src/game/include/AIPlayBook.h).
- Source of truth: src/game/decomp/aipbook.cpp.decomp (loadPlays @ 0x00410220) + src/game/decomp/aipbook.cpp.asm.
- Done when: the `// TODO: STUB: Full .ply parsing...` note is removed, all parse branches/alloc/free match decomp, and build is clean.
- Status note: `AIPlayBook::loadPlays` full `.ply` parsing restored and the explicit stub marker removed (implementation/fix commit `baf6442`, merged via `603fda9`).

## Task 38 — Implement `RGE_Game_World::data_load_*` virtuals (currently hard stubs)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the data-loading virtuals so world initialization can load terrain/sprites/sounds/players/objects without “return 1” placeholders.
- Implement: `data_load_world`, `data_load_terrain_tables`, `data_load_players`, `data_load_objects`, `data_load_sounds`, `data_load_color_tables`, `data_load_sprites`, `data_load_players_type`, `data_load_effects`, `data_load_map`, `data_load_random_map`.
- Where: src/game/src/RGE_Game_World.cpp (+ declarations in src/game/include/RGE_Game_World.h if missing).
- Source of truth: src/game/decomp/world.cpp.decomp + src/game/decomp/world.cpp.asm (locate the `data_load_*` family by symbol/offset).
- Done when: the “Stub implementations” block is gone, each method matches decomp control flow, and build is clean.
- Status note: `data_load_*` family implemented (commit `6605a1a`, merged via `2d9afb0`).

## Task 39 — Finish `RGE_Action_Object` + `RGE_Action_List` plumbing parity (action stack management)
- [x] Assigned to agent
- [x] Finished
- Goal: complete per-unit action-stack behavior so units can enqueue/dequeue actions and save/load action stacks correctly.
- Implement:
  - Fill in the remaining `RGE_Action_Object` methods from act_obj.cpp.decomp (command dispatch helpers, stack management, stop/work/move glue, save/rehook/copy, etc.).
  - Fill in the remaining `RGE_Action_List` methods from act_list.cpp.decomp (set_action variants, add/remove behaviors, create_action factories, response routing, save/rehook/copy).
  - Fix `RGE_Action_Object::create_action_list` to construct a real `RGE_Action_List` (remove current “zero-init + TODO ctor” workaround) once the constructor signature is known from decomp.
- Where: src/game/src/RGE_Action_Object.cpp, src/game/src/RGE_Action_List.cpp (+ headers under src/game/include).
- Source of truth: src/game/decomp/act_obj.cpp.decomp + src/game/decomp/act_obj.cpp.asm, src/game/decomp/act_list.cpp.decomp + src/game/decomp/act_list.cpp.asm.
- Done when: the transliteration covers the full decomp function set for both files (with `// Fully verified...` markers on finished functions) and build is clean.
- Status note: agent-run complete; remaining factory TODO: STUBs in `RGE_Action_List` relate to creating/wiring specific `RGE_Action_*` subclasses (and selecting them in `create_action`/`create_task_action`). Minor wiring fix: `RGE_Action_Object::move_to` fallback now instantiates `RGE_Action_Move_To` (commit `ad5e426`).

## Task 40 — Implement the 8 core `RGE_Action_*` subclasses (base unit behaviors)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the RGE action subclasses that drive the majority of unit behavior (attack/move/gather/enter/explore/bird/missile/transport).
- Implement: `RGE_Action_Attack`, `RGE_Action_Move_To`, `RGE_Action_Gather`, `RGE_Action_Enter`, `RGE_Action_Explore`, `RGE_Action_Bird`, `RGE_Action_Missile`, `RGE_Action_Transport`.
- Where: add new source files under src/game/src/ (one per class, matching the project’s naming conventions), using the existing headers under src/game/include/.
- Source of truth: src/game/decomp/act_atak.cpp.decomp, act_move.cpp.decomp, act_gath.cpp.decomp, act_entr.cpp.decomp, act_expl.cpp.decomp, act_bird.cpp.decomp, act_misl.cpp.decomp, act_tran.cpp.decomp (+ asm audits as needed).
- Done when: all eight classes compile/link, all transliterated functions have `// Fully verified...` markers, and no placeholder “return success” behavior remains in core update/stop/work paths.
- Dependency note: assumes the `RGE_Action_Object` + `RGE_Action_List` action-stack plumbing exists far enough for compilation and basic dispatch (action creation, set_action/add/remove, and save/rehook/copy basics).
- Status note: agent-run complete; follow-up work is split into per-action parity tasks (one core action class per task) plus action-factory wiring cleanups.

## Task 41 — Implement remaining TRIBE-specific action subclasses (`tact_*`) (AoE1 gameplay behaviors)
- [x] Assigned to agent
- [x] Finished
- Goal: restore TRIBE-only unit behaviors (build/convert/heal/hunt/repair/trade/artifact/wonder etc.) that extend the base RGE action system.
- Implement: `TRIBE_Action` + the action subclasses from the tact_*.decomp set, excluding the already-restored `TRIBE_Action_Make_Obj` and `TRIBE_Action_Make_Tech` actions.
- Where: add new source files under src/game/src/ for each class; use headers under src/game/include/.
- Source of truth: src/game/decomp/taction.cpp.decomp and src/game/decomp/tact_*.cpp.decomp (+ asm audits where needed).
- Done when: each class compiles/links, save/load/update/stop/work parity matches decomp, and the set has verified markers on completed transliterations.
- Status note: agent-run complete; remaining known TODO: STUB gaps are split into follow-up tasks focusing on repair/trade/wonder action parity.

## Task 42 — Implement missing `RGE_Moving_Object` methods (movement + pathing glue)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the “real movement object” behaviors so moving units can plan and execute movement (beyond load/setup).
- Implement: remaining `RGE_Moving_Object` methods from move_obj.cpp.decomp (movement updates, rotate/velocity helpers, findPath integration, save/copy/transform, exception path handling, etc.).
- Where: src/game/src/RGE_Moving_Object.cpp (+ declarations in src/game/include/RGE_Moving_Object.h).
- Source of truth: src/game/decomp/move_obj.cpp.decomp + src/game/decomp/move_obj.cpp.asm (ASM audit for signedness in angle/velocity math).
- Done when: move_obj.cpp.decomp function set is fully covered (verified markers on completed functions) and build is clean.
- Status note: agent-run complete; remaining higher-level movement/path execution parity is deferred to a dedicated follow-up focused on movement execution/canPath integration.

## Task 43 — Finish pathfinding: `PathingSystem` + `Path` algorithm and helper ops
- [x] Assigned to agent
- [x] Finished
- Goal: restore the actual pathfinding algorithm and the missing `Path` manipulation helpers so movement can compute real routes.
- Implement:
  - `PathingSystem::findPath` / internal path search, smoothing, open/closed management, obstruction/terrain exception behaviors.
  - `Path` operations (capacity growth, waypoint insertion/removal, current waypoint access, copy/clear, facet-to-next handling, etc.).
- Where: src/game/src/pathsys.cpp, src/game/src/Path.cpp (+ headers under src/game/include).
- Source of truth: src/game/decomp/pathsys.cpp.decomp + src/game/decomp/pathsys.cpp.asm, src/game/decomp/path.cpp.decomp + src/game/decomp/path.cpp.asm.
- Done when: the decomp function sets are implemented (verified markers on completed functions) and build is clean.
- Status note: pathfinding and Path helper coverage landed (implement commit `6a585fd`, merged via `cce049c`).

## Task 44 — Implement missing `RGE_Combat_Object` combat mechanics (attack/damage/armor)
- [x] Assigned to agent
- [x] Finished
- Goal: restore real combat behavior (damage, area attack, armor/weapon queries) instead of only having load/setup.
- Implement: the missing `RGE_Combat_Object` methods (attack/do_attack/damage/calc modifiers/save/update/stop + helpers) and any required master-combat helpers.
- Where: src/game/src/RGE_Combat_Object.cpp (+ declarations in src/game/include/RGE_Combat_Object.h).
- Source of truth: src/game/decomp/com_obj.cpp.decomp + src/game/decomp/com_obj.cpp.asm, and where needed src/game/decomp/m_co_obj.cpp.decomp (master-combat data expectations) plus related blocks in stat_obj/move_obj/ani_obj decomp units.
- Done when: combat methods match decomp control flow (verified markers on finished transliterations) and build is clean.
- Status note: core combat mechanics restored in `src/game/src/RGE_Combat_Object.cpp` (implement commit `e36ceb9`, merged via `c946c64`). Note: unrelated virtual forwarding stubs still exist in `src/game/src/rge_object_virtual_stubs.cpp`; this task only tracks the combat-mechanics portion.

## Task 45 — Implement remaining `RGE_Animated_Object` + `RGE_Missile_Object` methods
- [x] Assigned to agent
- [x] Finished
- Goal: remove reliance on `rge_object_virtual_stubs.cpp` for animated/missile behaviors and restore real update/save/transform logic.
- Implement: remaining `RGE_Animated_Object` functions from ani_obj.cpp.decomp and remaining `RGE_Missile_Object` functions from misl_obj.cpp.decomp.
- Where: src/game/src/RGE_Animated_Object.cpp, src/game/src/RGE_Missile_Object.cpp (+ headers under src/game/include).
- Source of truth: src/game/decomp/ani_obj.cpp.decomp + src/game/decomp/ani_obj.cpp.asm, src/game/decomp/misl_obj.cpp.decomp + src/game/decomp/misl_obj.cpp.asm.
- Done when: the missing virtuals stop routing through `rge_object_virtual_stubs.cpp` for these types and build is clean.
- Status note: agent-run complete; remaining missile-action gap is to implement `RGE_Action_Missile` parity and ensure missile-object init correctly wires/uses the action.

## Task 46 — Complete doppleganger (fog-of-war ghost) object parity
- [x] Assigned to agent
- [x] Finished
- Goal: restore the fog-of-war ghost object system so it can draw/update/save correctly instead of only loading.
- Implement: remaining `RGE_Doppleganger_Object` virtuals (draw/update/save/die/destroy/copy/rehook/new_sprite/check_damage_sprites, etc.) and any creator/helpers required.
- Where: src/game/src/RGE_Doppleganger_Object.cpp (+ possibly src/game/src/RGE_Doppleganger_Creator.cpp) and headers under src/game/include.
- Source of truth: src/game/decomp/dpl_obj.cpp.decomp + src/game/decomp/dpl_obj.cpp.asm, plus src/game/decomp/m_dg_obj.cpp.decomp if it contains master/variant behaviors.
- Done when: doppleganger no longer depends on stub forwarding for core virtuals and build is clean.
- Status note: doppleganger creator/object runtime parity restored (commit `2b96aa1`, merged via `a59a4b0`).

## Task 47 — Audit/restore `TShape` draw pipeline parity (replace current custom implementation)
- [x] Assigned to agent
- [x] Finished
- Goal: ensure software renderer shape drawing matches the original (control flow + blending/shadow/mirror/dither variants), not an approximation.
- Implement: decomp-first transliteration of the `shape.cpp.decomp` routine set into the project’s `TShape` implementation (including clipped/unclipped, mirror variants, shadowing/translucency, bounds, and span integration). If current code already covers a function, ASM-audit and adjust it to match decomp rather than refactoring.
- Where: src/game/src/TShape.cpp (+ any needed declarations in src/game/include/TShape.h).
- Source of truth: src/game/decomp/shape.cpp.decomp + src/game/decomp/shape.cpp.asm.
- Done when: the `shape.cpp.decomp` function set is present with verified markers on completed transliterations, and any non-parity custom code paths in `TShape.cpp` are removed or fully justified by decomp.
- Status note: shape draw pipeline parity landed (implement commit `da2b9e0`, merged via `94455e2`).

## Task 48 — Implement scenario system + fractal map generator (save/load + random-map terrain)
- [x] Assigned to agent
- [x] Finished
- Goal: restore scenario load/save and the fractal generator used by random maps.
- Implement: `RGE_Scenario` + `T_Scenario` methods (load/save/serialize helpers) and the `Fractal` implementation.
- Where: add new src/game/src/ translation units for scenario + fractal (or extend existing world/scenario units if that’s the established pattern), plus headers under src/game/include.
- Source of truth: src/game/decomp/scenario.cpp.decomp, src/game/decomp/tscenaro.cpp.decomp, src/game/decomp/fractal.cpp.decomp (+ asm audits as needed).
- Done when: scenario save/load code compiles/link-clean without stubs, fractal code exists, and completed transliterations have verified markers.
- Dependency note: scenario core + fractal coverage is needed before scenario editor screens can be restored, and it is also a practical prerequisite for finishing the remaining random-map generation parity beyond the currently-landed pieces.
- Status note: scenario save/load + `T_Scenario` transliterations landed (implement commit `8dade6e`, merged via `1e55d74`).

## Task 49 — Implement random map generation modules (`RMM_*` classes)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the random map generation pipeline (land/elevation/terrain/shallows/objects/etc.) so `new_game` can generate real maps without placeholder behavior.
- Implement: the missing `RGE_RMM_*` modules from the rmm_*.decomp set, focusing on the core pipeline classes:
  - `RGE_RMM_Controller`
  - `RGE_RMM_Land_Generator`
  - `RGE_RMM_Elevation_Generator`
  - `RGE_RMM_Terrain_Generator`
  - `RGE_RMM_Shallows_Generator`
  - `RGE_RMM_Object_Generator`
  (and any remaining helpers referenced by these units).
- Where: add new src/game/src/ translation units for the missing generator/controller classes (headers already exist under src/game/include).
- Source of truth: src/game/decomp/rmm_*.cpp.decomp (+ asm audits where suspicious).
- Done when: `RGE_Map`/`RGE_Game_World` can construct and run the full random-map module chain without placeholder behavior (compile/link clean; no “TODO/STUB” generators).
- Status note: core random-map generator chain landed (implement commit `2de750e`, merged via `57faada`).

## Task 50 — Implement base AI framework (`AIModule`, `BaseItem`, `BaseObject`, IDs/messages)
- [x] Assigned to agent
- [x] Finished
- Goal: umbrella tracking for the AI framework base; the real work is intentionally split into small, assignable units.
- Implement: transliterate and land the base AI framework primitives:
  - `AIModule` (src/game/decomp/aimodule.cpp.decomp + aimodule.cpp.asm)
  - `AIModuleID` + `AIModuleMessage` (src/game/decomp/AIModuleID.decomp/.asm + AIModuleMessage.decomp/.asm)
  - `BaseItem` (src/game/decomp/aibitm.cpp.decomp + aibitm.cpp.asm)
  - `BaseObject` (src/game/decomp/aibobj.cpp.decomp + aibobj.cpp.asm)
- Non-overlap note: do not implement the TRIBE decision AI modules (the tai*.decomp family) here; this task is only the shared AI framework base.
- Status note: AI framework base transliterations landed (`src/game/src/AIModule.cpp`, `AIModuleID.cpp`, `AIModuleMessage.cpp`, `BaseItem.cpp`, `BaseObject.cpp`) (implement commit `c1b4ac6`, merged via `904b732`).

---

## Task 57 — AI framework: implement `AIModule` (`aimodule.cpp.decomp`)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the base AI module vtable + state management used by most AI subsystems.
- Implement: decomp-first transliteration of the `AIModule` method set.
- Where: add src/game/src/AIModule.cpp (or the project’s established naming) and wire to existing header src/game/include/AIModule.h.
- Source of truth: src/game/decomp/aimodule.cpp.decomp + src/game/decomp/aimodule.cpp.asm.
- Done when: the `AIModule` virtuals exist with verified markers and downstream AI modules can derive/call without shim behavior.
- Status note: implemented in `src/game/src/AIModule.cpp` (commit `c1b4ac6`, merged via `904b732`).

## Task 58 — AI framework: implement `AIModuleID` + `AIModuleMessage`
- [x] Assigned to agent
- [x] Finished
- Goal: restore the message + identifier primitives used by AI module communication.
- Implement: transliterate `AIModuleID` + `AIModuleMessage` behavior (constructors, helpers, any serialization/compare routines present in the decomp dumps).
- Where: add src/game/src/AIModuleID.cpp and src/game/src/AIModuleMessage.cpp (or similar) and wire to existing headers under src/game/include/.
- Source of truth: src/game/decomp/AIModuleID.decomp + src/game/decomp/AIModuleID.asm, src/game/decomp/AIModuleMessage.decomp + src/game/decomp/AIModuleMessage.asm.
- Done when: both types link-clean with their decomp behaviors and AI module call sites no longer need placeholder logic.
- Status note: implemented in `src/game/src/AIModuleID.cpp` + `src/game/src/AIModuleMessage.cpp` (commit `c1b4ac6`, merged via `904b732`).

## Task 59 — AI framework: implement `BaseItem` (`aibitm.cpp.decomp`)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the AI base “item” type used throughout AI lists/collections.
- Implement: transliterate `BaseItem` ctor/dtor + any helpers from aibitm.cpp.decomp.
- Where: add src/game/src/BaseItem.cpp and wire to src/game/include/BaseItem.h.
- Source of truth: src/game/decomp/aibitm.cpp.decomp + src/game/decomp/aibitm.cpp.asm.
- Done when: `BaseItem` behavior matches decomp and builds without adding new stubs.
- Status note: implemented in `src/game/src/BaseItem.cpp` (commit `c1b4ac6`, merged via `904b732`).

## Task 60 — AI framework: implement `BaseObject` (`aibobj.cpp.decomp`)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the AI base “object” type used by AI module object tracking.
- Implement: transliterate `BaseObject` ctor/dtor + any helpers from aibobj.cpp.decomp.
- Where: add src/game/src/BaseObject.cpp and wire to src/game/include/BaseObject.h.
- Source of truth: src/game/decomp/aibobj.cpp.decomp + src/game/decomp/aibobj.cpp.asm.
- Done when: `BaseObject` behavior matches decomp and builds without adding new stubs.
- Status note: implemented in `src/game/src/BaseObject.cpp` (commit `c1b4ac6`, merged via `904b732`).

## Task 52 — Restore missing panel/widget classes used across menus/screens
- [x] Assigned to agent
- [x] Finished
- Goal: fill in UI panel classes that screens depend on (edit boxes, input panels, scrollable text, dialog panels, sliders, buttons).
- Implement: missing widget/panel behavior from decomp for:
  - `TInputPanel` (pnl_inp.cpp.decomp)
  - `TScrollTextPanel` (pnl_txt.cpp.decomp)
  - `THorizontalSliderPanel` (pnl_sld.cpp.decomp)
  - Continue `TEditPanel` parity (pnl_edit.cpp.decomp) and `TButtonPanel` parity (pnl_btn.cpp.decomp) where existing src still returns 0 in core handlers.
  - This task excludes: message panel (`TMessagePanel`) parity and list/scrollbar primitives (`TEasy_Panel::create_list/create_scrollbar/create_auto_scrollbar`, `TListPanel`, `TScrollBarPanel`).
- Where: add/update the panel translation units under src/game/src (existing examples include `Pnl_edit.cpp`, `TButtonPanel.cpp`, `TDialogPanel.cpp`).
- Source of truth: src/game/decomp/pnl_edit.cpp.decomp, pnl_inp.cpp.decomp, pnl_txt.cpp.decomp, pnl_dlg.cpp.decomp, pnl_sld.cpp.decomp, pnl_btn.cpp.decomp (+ asm audits as needed).
- Done when: these panels compile/link, no longer contain placeholder return-0 behavior in their core input paths, and completed transliterations have verified markers.
- Non-overlap note: this task explicitly excludes: `TMessagePanel` parity and list/scrollbar panel infrastructure (`TEasy_Panel` list/scrollbar helpers + `TListPanel`/`TScrollBarPanel`).
- Status note: agent-run complete; remaining widget parity gaps include `TEasy_Panel::create_edit` parity, removing best-effort screen selection-recovery hacks in load/select screens, and finishing `TButtonPanel` core input handler parity.

---

## Task 69 — Follow-up umbrella: retire `rge_object_virtual_stubs.cpp` further
- [ ] Assigned to agent
- [x] Finished
- Goal: continue shrinking/removing `src/game/src/rge_object_virtual_stubs.cpp` by implementing the real virtuals in their owning classes.
- Implement: prioritize stubs that are currently on hot paths (update/draw/command responders) and any that block other parity tasks.
- Where: src/game/src/rge_object_virtual_stubs.cpp, plus the real owners (e.g. src/game/src/RGE_Static_Object.cpp, RGE_Animated_Object.cpp, RGE_Moving_Object.cpp, etc.)
- Source of truth: the relevant `stat_obj.cpp.decomp`, `ani_obj.cpp.decomp`, `move_obj.cpp.decomp`, etc (+ ASM audits where suspicious).
- Done when: `rge_object_virtual_stubs.cpp` is reduced to a small set of unavoidable forwarders (or fully removed).

Status note: umbrella task retired for queue hygiene. Follow-up work is now tracked as scoped, file-isolated tasks (see new tasks added below) to avoid multi-agent conflicts.

## Task 70 — Finish `TRIBE_Game::quit_game` + `start_menu` parity (remove TODO: STUB in tribegam)
- [x] Assigned to agent
- [x] Finished
- Goal: eliminate the remaining `TRIBE_Game` “best-effort”/stubbed control-flow in `tribegam.cpp` and match the decomp branches (campaign, scenario editor, join screen, etc.).
- Where: src/game/src/tribegam.cpp
- Source of truth: src/game/decomp/tribegam.cpp.decomp + src/game/decomp/tribegam.cpp.asm (especially `quit_game` @ 0x00524150 and `start_menu` @ 0x00524030).
- Done when: the `// TODO: STUB` markers around quit/menu transitions are removed and the control flow matches the decomp.

Status note: quit/menu control-flow parity landed (implement commit `16cf874`, merged via `4cf5566`).

## Task 71 — TEasy_Panel follow-up: finish `create_edit` parity (remove EasyPseudoEditPanel stub)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the current `create_edit` best-effort behavior and restore the real edit panel construction/behavior used by Save/Scenario name entry.
- Where: src/game/src/Panel_ez.cpp (+ any required panel classes under src/game/src/)
- Source of truth: src/game/decomp/panel_ez.cpp.decomp (+ asm audit where sizing/flags look suspicious) and the real edit panel decomp unit (pnl_edit.cpp.decomp / pnl_inp.cpp.decomp where applicable).
- Done when: `TEasy_Panel::create_edit` no longer contains `// TODO: STUB` and uses the correct real panel types/flags.

Status note: `TEasy_Panel::create_edit` parity restored (commit `ae1c415`).

## Task 72 — Screen follow-up: remove “Best-effort current selection recovery” hacks
- [x] Assigned to agent
- [x] Finished
- Goal: eliminate the best-effort setup-id propagation/selection recovery hacks and match the screen decomp logic.
- Where: src/game/src/scr_load_impl.cpp, src/game/src/scr_sels_impl.cpp
- Source of truth: src/game/decomp/scr_load.cpp.decomp + src/game/decomp/scr_sels.cpp.decomp (+ asm audits as needed).
- Done when: the `// TODO(accuracy): Best-effort ...` markers are removed and the setup/state propagation matches decomp.

Status note: selection recovery hacks removed (commit `3b3f8f3`).

## Task 73 — Basegame follow-up: implement custom mouse pointer creation (remove TODO: STUB in setup_mouse)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the original “Custom Mouse” behavior by allocating/configuring `TMousePointer` in `RGE_Base_Game::setup_mouse`.
- Where: src/game/src/basegame.cpp (+ any required glue in src/game/src/Mouseptr.cpp)
- Source of truth: src/game/decomp/basegame.cpp.decomp + src/game/decomp/mouseptr.cpp.decomp (+ asm audits where needed).
- Done when: `RGE_Base_Game::setup_mouse` no longer has `// TODO: STUB` and the allocation/setup sequence matches decomp.

Status note: `setup_mouse` custom pointer creation restored (implement commit `80ce7f4`, merged via `71d6493`).

## Task 74 — Basegame follow-up: implement `setup_shapes` + `setup_blank_screen`
- [x] Assigned to agent
- [x] Finished
- Goal: remove placeholder returns in basegame setup so boot/menu paths rely on real setup logic.
- Where: src/game/src/basegame.cpp
- Source of truth: src/game/decomp/basegame.cpp.decomp (+ asm audit for call ordering).
- Done when: `setup_shapes` and `setup_blank_screen` no longer contain `// TODO: STUB` and match decomp control flow.

Status note: basegame setup shapes/blank-screen parity landed (implement commit `956834b`, merged via `0e2363f`).

## Task 75 — TRIBE_World follow-up: replace remaining TRIBE_World “stub virtuals” with real tworld.cpp parity
- [x] Assigned to agent
- [x] Finished
- Goal: remove reliance on base-call/default-return TRIBE_World overrides and match `tworld.cpp.decomp`.
- Where: src/game/src/TRIBE_World.cpp, src/game/src/TRIBE_World_types.cpp
- Source of truth: src/game/decomp/tworld.cpp.decomp + src/game/decomp/tworld.cpp.asm.
- Done when: the file-level `// TODO: STUB - Stub implementations for TRIBE_World virtual methods` note is no longer true and the relevant methods have verified markers.

Status note: TRIBE_World tworld parity landed (implement commit `16a5f08`) with follow-up offset fix (commit `557f58c`).

## Task 76 — Core actions: implement `RGE_Action_Attack` (act_atak)
- [x] Assigned to agent
- [x] Finished
- Goal: restore attack action parity.
- Where: src/game/src/RGE_Action_Attack.cpp (+ src/game/include/RGE_Action_Attack.h)
- Source of truth: src/game/decomp/act_atak.cpp.decomp + src/game/decomp/act_atak.cpp.asm.
- Done when: no placeholder update/stop/work behavior remains and functions have verified markers.

Status note: `RGE_Action_Attack` implemented (implement commit `265cef5`, merged via `c36e3ff`).

## Task 77 — Core actions: implement `RGE_Action_Gather` (act_gath)
- [x] Assigned to agent
- [x] Finished
- Goal: restore gather action parity.
- Where: src/game/src/RGE_Action_Gather.cpp (+ src/game/include/RGE_Action_Gather.h)
- Source of truth: src/game/decomp/act_gath.cpp.decomp + src/game/decomp/act_gath.cpp.asm.
- Done when: no placeholder update/stop/work behavior remains and functions have verified markers.
- Status note: implemented in commit `013aa34`.

## Task 78 — Core actions: implement `RGE_Action_Explore` (act_expl)
- [x] Assigned to agent
- [x] Finished
- Goal: restore explore action parity.
- Where: src/game/src/RGE_Action_Explore.cpp (+ src/game/include/RGE_Action_Explore.h)
- Source of truth: src/game/decomp/act_expl.cpp.decomp + src/game/decomp/act_expl.cpp.asm.
- Done when: no placeholder update/stop/work behavior remains and functions have verified markers.
- Status note: implemented in commit `013aa34`.

## Task 79 — Core actions: implement `RGE_Action_Bird` (act_bird)
- [x] Assigned to agent
- [x] Finished
- Goal: restore bird action parity.
- Where: src/game/src/RGE_Action_Bird.cpp (+ src/game/include/RGE_Action_Bird.h)
- Source of truth: src/game/decomp/act_bird.cpp.decomp + src/game/decomp/act_bird.cpp.asm.
- Done when: no placeholder update/stop/work behavior remains and functions have verified markers.
- Status note: implemented in commit `013aa34`.

## Task 80 — Core actions: implement `RGE_Action_Missile` (act_misl) + wire missile init
- [x] Assigned to agent
- [x] Finished
- Goal: restore missile action parity and remove the current base-action shell used for missile init.
- Where: src/game/src/RGE_Action_Missile.cpp (+ header), and update missile call sites (e.g. src/game/src/RGE_Missile_Object.cpp).
- Source of truth: src/game/decomp/act_misl.cpp.decomp + src/game/decomp/act_misl.cpp.asm.
- Done when: `RGE_Missile_Object` no longer uses a base `RGE_Action` shell for missile actions and TODO: STUB markers are removed.
- Status note: `RGE_Missile_Object::init_missile` now instantiates `RGE_Action_Missile` and enqueues it (no base-action shell). Remaining TODO in `RGE_Missile_Object` concerns the Combat master-based constructor path and is tracked separately.

## Task 81 — Action list factories: wire `RGE_Action_List::create_action` / `create_task_action` to real subclasses
- [x] Assigned to agent
- [x] Finished
- Goal: remove remaining `RGE_Action_List` factory TODO: STUBs and construct the correct action subclasses.
- Where: src/game/src/RGE_Action_List.cpp (+ headers)
- Source of truth: src/game/decomp/act_list.cpp.decomp + src/game/decomp/act_list.cpp.asm.
- Done when: factory methods create correct subclasses without TODO: STUB branches.
- Status note: factory wiring for core action types landed in commit `013aa34`.

## Task 82 — Core actions: finish `RGE_Action_Move_To` parity (act_move)
- [x] Assigned to agent
- [x] Finished
- Goal: replace the current move-to “minimal state machine” with full act_move parity.
- Where: src/game/src/RGE_Action_Move_To.cpp (+ src/game/include/RGE_Action_Move_To.h)
- Source of truth: src/game/decomp/act_move.cpp.decomp + src/game/decomp/act_move.cpp.asm.
- Done when: move-to update/stop/work/rehook/save behavior matches decomp and TODO: STUB markers are removed.
- Status note: implemented in commit `013aa34`.

## Task 83 — TRIBE actions: finish `TRIBE_Action_Repair` parity (tact_rep)
- [x] Assigned to agent
- [x] Finished
- Where: src/game/src/TRIBE_Action_Repair.cpp
- Source of truth: src/game/decomp/tact_rep.cpp.decomp + src/game/decomp/tact_rep.cpp.asm.
- Done when: the existing TODO: STUB note is removed and update/stop/work/save match decomp.

Status note: `TRIBE_Action_Repair` parity landed (implement commit `689510b`, merged via `8396656`).

## Task 84 — TRIBE actions: finish `TRIBE_Action_Trade` parity (tact_trd)
- [x] Assigned to agent
- [x] Finished
- Where: src/game/src/TRIBE_Action_Trade.cpp
- Source of truth: src/game/decomp/tact_trd.cpp.decomp + src/game/decomp/tact_trd.cpp.asm.
- Done when: the existing TODO: STUB note is removed and update/stop/work/save match decomp.

Status note: `TRIBE_Action_Trade` parity landed (implement commit `c6b62f6`, merged via `bbbcd75`).

## Task 85 — TRIBE actions: finish `TRIBE_Action_Wonder` parity (tact_wnd)
- [x] Assigned to agent
- [x] Finished
- Where: src/game/src/TRIBE_Action_Wonder.cpp
- Source of truth: src/game/decomp/tact_wnd.cpp.decomp + src/game/decomp/tact_wnd.cpp.asm.
- Done when: the existing TODO: STUB notes are removed and victory countdown/state behavior matches decomp.

Status note: `TRIBE_Action_Wonder` parity landed (implement commit `fcb716c`, merged via `83d7a49`).

## Task 86 — Core actions: finish `RGE_Action_Enter` parity (act_entr)
- [x] Assigned to agent
- [x] Finished
- Goal: replace the current minimal enter action behavior with full decomp parity.
- Where: src/game/src/RGE_Action_Enter.cpp (+ src/game/include/RGE_Action_Enter.h)
- Source of truth: src/game/decomp/act_entr.cpp.decomp + src/game/decomp/act_entr.cpp.asm.
- Done when: enter action update/stop/work/save/rehook paths match decomp and placeholder behavior is removed.

Status note: `RGE_Action_Enter` parity landed (implement commit `7cf3f6a`, merged via `a08d665`).

## Task 87 — Movement follow-up: finish missing `RGE_Moving_Object` high-level movement/path execution
- [x] Assigned to agent
- [x] Finished
- Goal: complete movement execution (update/canPath integration) now that pathfinding is implemented.
- Where: src/game/src/RGE_Moving_Object.cpp (+ header)
- Source of truth: src/game/decomp/move_obj.cpp.decomp + src/game/decomp/move_obj.cpp.asm.
- Done when: the remaining move_obj.cpp.decomp function set is covered with verified markers.

Status note: movement execution parity landed (implement commit `c3ed272`, merged via `b34c516`).

## Task 88 — UI widget follow-up: finish `TButtonPanel` handler parity (remove return-0 placeholders)
- [x] Assigned to agent
- [x] Finished
- Goal: remove remaining simplified/return-0 handlers in `TButtonPanel` and match pnl_btn decomp.
- Where: src/game/src/TButtonPanel.cpp
- Source of truth: src/game/decomp/pnl_btn.cpp.decomp + src/game/decomp/pnl_btn.cpp.asm.
- Done when: core input handlers no longer short-circuit with placeholder returns and finished functions have verified markers.

Status note: `TButtonPanel` handler parity landed (implement commit `ee454ed`, merged via `ced0b65`).

## Task 89 — Core actions: finish `RGE_Action_Transport` parity (act_tran)
- [x] Assigned to agent
- [x] Finished
- Goal: replace the current minimal transport action behavior with full decomp parity.
- Where: src/game/src/RGE_Action_Transport.cpp (+ src/game/include/RGE_Action_Transport.h)
- Source of truth: src/game/decomp/act_tran.cpp.decomp + src/game/decomp/act_tran.cpp.asm.
- Done when: transport action update/stop/work/save/rehook paths match decomp and placeholder behavior is removed.

Status note: `RGE_Action_Transport` parity landed (implement commit `5d3cd1b`, merged via `3e17505`).

## Task 53 — Implement dialog classes (`dlg_*.cpp.decomp`) used by menus and in-game UI
- [x] Assigned to agent
- [x] Finished
- Goal: restore the real dialog boxes (config/diplomacy/menu/about/help/list/message/send message/etc.) so screens don’t need Win32 shims.
- Implement: dialog classes from src/game/decomp/dlg_*.cpp.decomp (this is intentionally split-friendly: assign one dialog translation unit per agent).
- Where: add new src/game/src/ dialog translation units + headers under src/game/include.
- Source of truth: src/game/decomp/dlg_*.cpp.decomp (+ asm audits as needed).
- Done when: dialogs compile/link and can be constructed by screens without TODO/STUB shims.
- Dependency note: assumes the core widget panels (edit/input/scrolltext/dialog/slider/button) and the `TEasy_Panel` popup dialog helpers already exist, since many dialogs compose those building blocks.
- Status note: dialog translation units landed and compile/link clean (implement commit `5b846b7`, merged via `a0b390d`).

## Task 54 — Implement COM/networking primitives (`com_*.cpp.decomp`) needed by multiplayer
- [x] Assigned to agent
- [x] Finished
- Goal: restore the COM networking layer so comm handlers can serialize/receive commands without missing-class gaps.
- Implement: COM_Object plus the COM_* family used by the comm handler (address/session/lobby/server/sync/speed/error, etc.).
- Where: add new src/game/src/ translation units + headers under src/game/include.
- Source of truth: src/game/decomp/com_*.cpp.decomp (+ asm audits as needed).
- Done when: COM layer compiles/links and comm handler code can build without placeholder structs/types for COM objects.
- Status note: COM primitive translation units landed (`com_addr.cpp`, `com_err.cpp`, `com_loby.cpp`, `com_serv.cpp`, `com_sess.cpp`, `com_spd.cpp`, `com_sync.cpp`, etc.) (implement commit `b8be9d9`, merged via `434280f`).

---

## Task 90 — SP gameplay: restore TRIBE unit/building runtime creation (masters + ctors + setup)
- [x] Assigned to agent
- [x] Finished
- Goal: unblock real single-player gameplay by ensuring units/buildings created from master objects instantiate the correct TRIBE object types (not `RGE_Static_Object`) and run the correct setup paths.
- Implement (decomp-first transliteration):
  - `TRIBE_Combat_Object::TRIBE_Combat_Object(TRIBE_Master_Combat_Object*, RGE_Player*, float x, float y, float z, int do_setup)` @ 0x004CA0F0.
  - `TRIBE_Combat_Object::setup(TRIBE_Master_Combat_Object*, RGE_Player*, float x, float y, float z)` (protected virtual) @ 0x004CA300.
  - `TRIBE_Building_Object::TRIBE_Building_Object(TRIBE_Master_Building_Object*, RGE_Player*, float x, float y, float z, int unique_build_id, int do_setup, int unused?)` @ 0x004C7F50 (match signature/param order from decomp).
  - `TRIBE_Building_Object::TRIBE_Building_Object(TRIBE_Master_Building_Object*, RGE_Player*, float x, float y, float z, int do_setup)` @ 0x004C80B0.
  - `TRIBE_Building_Object::setup(TRIBE_Master_Building_Object*, RGE_Player*, float x, float y, float z)` (protected virtual) @ 0x004C83E0.
  - `TRIBE_Master_Combat_Object::make_new_obj(RGE_Player*, float x, float y, float z)` @ 0x0050F090.
  - `TRIBE_Master_Building_Object::make_new_obj(RGE_Player*, float x, float y, float z, int unique_build_id)` @ 0x0050E630.
  - `TRIBE_Master_Building_Object::make_new_obj(RGE_Player*, float x, float y, float z)` @ 0x0050E6B0.
- Where:
  - Constructors + setup: `src/game/src/TRIBE_Combat_Object.cpp`, `src/game/include/TRIBE_Combat_Object.h`, `src/game/src/TRIBE_Building_Object.cpp`, `src/game/include/TRIBE_Building_Object.h`.
  - Master creation wiring: `src/game/src/TRIBE_Master_Objects.cpp` (replacing the current forwarding-to-base behavior).
- Source of truth:
  - `src/game/decomp/t_c_obj.cpp.decomp` (+ `src/game/decomp/t_c_obj.cpp.asm` if any signedness/offsets look suspicious).
  - `src/game/decomp/t_b_obj.cpp.decomp` (+ `src/game/decomp/t_b_obj.cpp.asm`).
  - `src/game/decomp/tm_co_ob.cpp.decomp` and `src/game/decomp/tm_b_obj.cpp.decomp` for the master `make_new_obj` routines.
- Done when:
  - `TRIBE_Action_Make_Obj`’s call to `produced_master->make_new_obj(...)` can return a `TRIBE_Combat_Object` / `TRIBE_Building_Object` implementation (via the restored master virtuals) without relying on `RGE_Master_Static_Object::make_new_obj`.
  - The new constructors/setup methods are declared in headers and compile/link clean.
  - No new “linker satisfaction” stubs are added.

Status note: landed as Task90 implementation commit `dd2439d` and merged via `51adec2`.

## Task 91 — SP gameplay: restore RGE combat/missile runtime creation (recycle + masters + ctors + setup)
- [x] Assigned to agent
- [x] Finished
- Goal: restore projectile/combat instantiation used by the single-player simulation (combat objects and missiles must be constructible from masters, and master `make_new_obj` must create correct derived types).
- Implement (decomp-first transliteration):
  - `RGE_Game_World::recycle_object_in_to_game(unsigned char type)` @ 0x00546180.
  - `RGE_Master_Combat_Object::make_new_obj(RGE_Player*, float x, float y, float z)` @ 0x004506D0.
  - `RGE_Master_Missile_Object::make_new_obj(RGE_Player*, float x, float y, float z)` @ 0x00451770.
  - `RGE_Combat_Object::RGE_Combat_Object(RGE_Master_Combat_Object*, RGE_Player*, float x, float y, float z, int do_setup)` @ 0x0042F930.
  - `RGE_Combat_Object::setup(RGE_Master_Combat_Object*, RGE_Player*, float x, float y, float z)` (protected virtual) @ 0x0042FB40.
  - `RGE_Missile_Object::RGE_Missile_Object(RGE_Master_Combat_Object*, RGE_Player*, float x, float y, float z, int do_setup)` @ 0x0045A740.
  - `RGE_Missile_Object::setup(RGE_Master_Combat_Object*, RGE_Player*, float x, float y, float z)` (protected virtual) @ 0x0045A870.
- Where:
  - World recycle-in: `src/game/src/RGE_Game_World.cpp` (+ declaration in `src/game/include/RGE_Game_World.h` if missing).
  - Master make_new_obj: `src/game/src/RGE_Master_Derived_Stubs.cpp` (replace the current “forward to base static make_new_obj” behavior for Combat+Missile masters).
  - Ctors/setup: `src/game/src/RGE_Combat_Object.cpp`, `src/game/include/RGE_Combat_Object.h`, `src/game/src/RGE_Missile_Object.cpp`, `src/game/include/RGE_Missile_Object.h`.
- Source of truth:
  - `src/game/decomp/world.cpp.decomp` (recycle_object_in_to_game @ 0x00546180).
  - `src/game/decomp/m_co_obj.cpp.decomp` (master combat make_new_obj @ 0x004506D0).
  - `src/game/decomp/m_mi_obj.cpp.decomp` (master missile make_new_obj @ 0x00451770).
  - `src/game/decomp/com_obj.cpp.decomp` (combat ctor/setup @ 0x0042F930 / 0x0042FB40).
  - `src/game/decomp/misl_obj.cpp.decomp` (missile ctor/setup @ 0x0045A740 / 0x0045A870).
- Done when:
  - Combat/missile masters construct the correct derived object types (`RGE_Combat_Object` / `RGE_Missile_Object`) and use the correct setup routines.
  - The current TODO in `src/game/src/RGE_Missile_Object.cpp` about missing Combat master-based constructor path is removed (or is no longer true).
  - Build remains clean and no new placeholder stubs are introduced.

Status note: landed as Task 91 implementation commit `9dc5ff2` and merged via `d3ecb49`.

## Task 92 — SP gameplay: restore `RGE_Master_Static_Object` modify/copy/save (tech/upgrades)
- [x] Assigned to agent
- [x] Finished
- Goal: make technology and attribute modifications apply to master objects (HP/LOS/radius/etc.), enabling upgrades to affect single-player simulation.
- Implement (decomp-first transliteration):
  - `RGE_Master_Static_Object::copy_obj(RGE_Master_Static_Object* src)` @ 0x00453120.
  - `RGE_Master_Static_Object::modify(float value, unsigned char attr)` @ 0x004534A0.
  - `RGE_Master_Static_Object::modify_delta(float value, unsigned char attr)` @ 0x00453540.
  - `RGE_Master_Static_Object::modify_percent(float value, unsigned char attr)` @ 0x004535F0.
  - `RGE_Master_Static_Object::save(int fd)` @ 0x004536D0.
- Where:
  - `src/game/src/RGE_Master_Static_Object.cpp` (these functions are currently empty/no-op).
  - Ensure declarations/virtual overrides exist in `src/game/include/RGE_Master_Static_Object.h` (do not change member layout/size asserts).
- Source of truth:
  - `src/game/decomp/m_s_obj.cpp.decomp` (offsets above) + `src/game/decomp/m_s_obj.cpp.asm` if any field offsets look ambiguous.
- Done when:
  - The no-op bodies in `RGE_Master_Static_Object.cpp` are replaced with real transliterations.
  - Code compiles/link-clean and preserves all struct size/static_assert invariants.

Status note: landed as Task 92 implementation commit `2b569dd` and merged via `05d49d6`.

## Task 93 — SP in-game loop: restore `RGE_Base_Game::handle_paint` parity slice (render hot-path)
- [x] Assigned to agent
- [x] Finished
- Goal: bring the per-frame paint path closer to original so the single-player in-game loop can reliably render via the panel system without relying on the current “simplified” path.
- Implement: transliterate `RGE_Base_Game::handle_paint(void*, uint, uint, long)` @ 0x004213E0.
- Where: `src/game/src/basegame.cpp` (and only add minimal supporting helpers in existing draw/panel types if the decomp calls them).
- Source of truth: `src/game/decomp/basegame.cpp.decomp` (`handle_paint` @ 0x004213E0) + `src/game/decomp/basegame.cpp.asm` for any message/branch nuances.
- Done when:
  - The “Simplified” comment block in `RGE_Base_Game::handle_paint` is no longer true (control-flow matches decomp at a high level: paint gating, panel draw_tree/paint, mouse pointer draw sequencing, and surface/palette handling where applicable).
  - Build stays clean without introducing new placeholder stubs.

Status note: landed as Task 93 implementation commit `2d08055` and merged via `0f584ff`.

## Task 94 — Save/load support: eliminate `RGE_Action_List` fallback base-action shells (missing load ctors)
- [x] Assigned to agent
- [x] Finished
- Goal: make `RGE_Action_List::create_action` match `act_list.cpp` decomp parity (and stop fabricating base-action shells for unknown types).
- Implement:
  - Transliterate `RGE_Action_List::create_action(int fd, short action_type)` to match the switch map and return behavior in `src/game/decomp/act_list.cpp.decomp`.
  - Remove the current “unknown → allocate `RGE_Action` shell” fallback; on unknown types, return `nullptr` like the decomp.
  - Ensure the supported cases correctly deserialize by calling the proper `setup(fd, obj)` paths (or load constructors where they truly exist in the decomp).
- Where: `src/game/src/RGE_Action_List.cpp` plus the owning action class translation units under `src/game/src/` (and headers under `src/game/include/`).
- Source of truth: `src/game/decomp/act_list.cpp.decomp` + `src/game/decomp/act_list.cpp.asm` for the exact action-type switch map and construction pattern.
- Done when:
  - The `// TODO: STUB - not all action subclass load constructors are transliterated yet.` block in `RGE_Action_List::create_action` is removed.
  - The factory no longer allocates a base `RGE_Action` shell for unknown types.
  - For the action types present in the decomp switch, construction + load paths match the decomp.
  - Build remains clean and no new “linker satisfaction” stubs are introduced.

Status note: landed as Task 94 implementation commit `6af9972`.

## Task 95 — SP gameplay: implement `RGE_Action_Make` parity (act_make)
- [x] Assigned to agent
- [x] Finished
- Goal: replace the current placeholder/stub `RGE_Action_Make` implementation with real act_make parity so production/make actions behave correctly in-game and serialize cleanly.
- Implement:
  - Full decomp-first transliteration of `RGE_Action_Make` (ctor/setup/save/update/stop/work/move_to/target handling/state machine) from `act_make.cpp`.
  - Remove the remaining `// TODO: STUB` behavior currently living in `src/game/src/RGE_Action_Derived_Stubs.cpp` for `RGE_Action_Make`.
- Where:
  - Prefer creating a real translation unit `src/game/src/RGE_Action_Make.cpp` and removing/reducing `src/game/src/RGE_Action_Derived_Stubs.cpp` accordingly.
  - Header: `src/game/include/RGE_Action_Make.h` (add only method declarations; do not change layout/size asserts).
- Source of truth:
  - `src/game/decomp/act_make.cpp.decomp` (+ `src/game/decomp/act_make.cpp.asm` for any tricky branches/signedness).
  - Shared expectations via `src/game/decomp/action.cpp.decomp` / `src/game/decomp/act_list.cpp.decomp` only where needed for base behavior.
- Done when:
  - `RGE_Action_Make::~RGE_Action_Make` and `RGE_Action_Make::save` are no longer stub-forwarders.
  - The class behavior matches the decomp control flow closely enough that it can run in the SP world update loop without falling back to base `RGE_Action` behavior.
  - Build stays clean with no new placeholder stubs.

Status note: landed as Task 95 implementation commit `77ac370` and merged via `4013868`.

---

## Task 96 — UI: implement `TPanelSystem::DisableIME` parity (panel)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining `TPanelSystem::DisableIME` stub so focus/IME behavior matches the original panel system.
- Implement: `TPanelSystem::DisableIME()` @ 0x004644E0.
- Where: `src/game/src/TPanelSystem.cpp` (and only add includes/glue needed for the `_ImmAssociateContext@8` call).
- Source of truth: `src/game/decomp/panel.cpp.decomp` + `src/game/decomp/panel.cpp.asm` (DisableIME @ 0x004644E0).
- Done when:
  - The `// TODO: STUB` body is removed.
  - The implementation matches the ASM sequence (guard on IME context member, call `_ImmAssociateContext(AppWnd, 0)`, store the returned context, clear the active IME context member).
  - Build remains clean and no new placeholder stubs are introduced.

Status note: landed as commit `e2e43ab` and merged via `c545537`.

## Task 97 — Resources: implement `RESFILE_build_res_file` parity (res_file)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the original “build resource file” pipeline so the engine can create/update `.rm` resource packs from a build file when needed.
- Implement: `RESFILE_build_res_file(char* path, char* resource_dir, char* tag)` @ 0x0047F5C0.
- Where: `src/game/src/Res_file.cpp` (+ `src/game/include/Res_file.h` only if declarations are missing; do not change struct layouts).
- Source of truth: `src/game/decomp/res_file.cpp.decomp` + `src/game/decomp/res_file.cpp.asm` (RESFILE_build_res_file @ 0x0047F5C0).
- Done when:
  - `Res_file.cpp` no longer contains the `RESFILE_build_res_file` TODO stub.
  - The function matches decomp control flow (file naming, temp files, header/type/id directories, error paths) closely enough to compile/link clean.
  - Build remains clean without adding new “linker satisfaction” stubs.

Status note: landed as commit `be39813` and merged via `affb79e`.

## Task 98 — Checksums: implement `RGE_Player` checksum helpers (player)
- [x] Assigned to agent
- [x] Finished
- Goal: restore per-player checksum computation needed by world/basegame checksum aggregation and comm sync.
- Implement (decomp-first transliteration):
  - `RGE_Player::get_checksum()` @ 0x0046FF40.
  - `RGE_Player::get_checksums(long& cs1, long& cs2, long& cs3)` @ 0x0046FF60.
  - `RGE_Player::create_checksum()` @ 0x0046FF90.
- Where: `src/game/src/RGE_Player.cpp` (+ `src/game/include/RGE_Player.h` only if method declarations are missing; do not change member layout/size asserts).
- Source of truth: `src/game/decomp/player.cpp.decomp` + `src/game/decomp/player.cpp.asm` (offsets above).
- Done when:
  - The three methods exist, compile, and match the decomp’s control flow (including the `checksum_created_this_update` gating).
  - Callers in basegame/comms can use these without falling back to “return 0” behavior.

Status note: landed as Task 98 implementation commit `95b7e88` and merged via `7e9143b`.

## Task 99 — Checksums: implement `RGE_Base_Game` checksum aggregation (basegame)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the basegame checksum helpers that aggregate per-player checksums (used by comm sync and debug checksum logging).
- Implement (decomp-first transliteration):
  - `RGE_Base_Game::GetChecksum(long player_index_or_special)` @ 0x00422920.
  - `RGE_Base_Game::GetWorldChecksums(long& out1, long& out2, long& out3)` @ 0x00422960.
  - `RGE_Base_Game::GetWorldChecksum()` @ 0x00422A10.
- Where: `src/game/src/basegame.cpp` (+ `src/game/include/RGE_Base_Game.h` only if declarations are missing; do not change member layout/size asserts).
- Source of truth: `src/game/decomp/basegame.cpp.decomp` + `src/game/decomp/basegame.cpp.asm` (offsets above).
- Done when:
  - The three methods compile/link cleanly.
  - Behavior matches decomp (special player index handling in `GetChecksum`, per-player iteration in world helpers).
  - Dependency note: requires Task 98 (player checksum helpers) to be complete first.

Status note: landed as commit `eb6c5b0` and merged via `5c03eb7` (follow-up dedup/cleanup landed in `3f01e5e` / `7094cbe`).

## Task 100 — MP sync: implement `RGE_Communications_Synchronize::DoChecksum` parity (com_sync)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the real checksum collection/logging behavior used by the comm-sync layer (even if MP gameplay isn’t the primary target, this keeps shared code paths parity-correct).
- Implement: `RGE_Communications_Synchronize::DoChecksum(unsigned long comm_turn)` @ 0x00433290.
- Where: `src/game/src/com_sync.cpp`.
- Source of truth: `src/game/decomp/com_sync.cpp.decomp` + `src/game/decomp/com_sync.cpp.asm` (DoChecksum @ 0x00433290).
- Done when:
  - The `// TODO: STUB - Full checksum computation...` block is removed.
  - Control flow matches decomp (turn gating, `CheckTurn += 4`, calls into basegame checksum helpers, logging behavior).
  - Dependency note: requires Task 98 + Task 99 to be complete first.

Status note: landed as commit `e62d64d` and merged via `6ddb644`.

## Task 101 — SP campaign flow: finish `TRIBE_Screen_Campaign_Selection` parity (scr_cams)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining scaffolding in the campaign-selection screen so it loads campaign/scenario lists and starts the game with real defaults.
- Implement:
  - Finish `startGame` parity @ 0x00491350 (remove the “VictoryDefault/DefaultResources/DefaultAge are 0” scaffold and match the original option-setting sequence).
  - Remove the campaign list “Loading placeholder” stub and replace it with the real behavior used by the decomp.
- Where: `src/game/src/TRIBE_Screen_Campaign_Selection.cpp` (+ header only if missing declarations; do not change layouts).
- Source of truth: `src/game/decomp/scr_cams.cpp.decomp` + `src/game/decomp/scr_cams.cpp.asm` (fillCampaigns @ 0x004911A0, fillScenarios @ 0x00491290, startGame @ 0x00491350).
- Done when:
  - The two `// TODO: STUB` markers in `TRIBE_Screen_Campaign_Selection.cpp` are removed.
  - `cams_startGame` / list population match decomp control flow closely enough to compile/link clean.

Status note: landed as commit `f65d843` and merged via `0c42cb5`.

## Task 102 — MP networking: remove remaining GTD “best-effort” stubs in `TCommunications_Handler`
- [x] Assigned to agent
- [x] Finished
- Goal: eliminate the two remaining “best-effort” GTD behaviors so guaranteed-delivery packet flow matches `com_hand.cpp` decomp.
- Implement (decomp-first transliteration):
  - In `TCommunications_Handler::PreprocessMessages(...)` @ 0x00427600: replace the “unknown sender → best-effort ack” scaffold with the decomp’s real behavior.
  - In `TCommunications_Handler::CommOut(...)` @ 0x0042B270: replace the “single recipient by DPID” best-effort mapping with the decomp’s real recipient resolution.
- Where: `src/game/src/com_hand.cpp`.
- Source of truth: `src/game/decomp/com_hand.cpp.decomp` + `src/game/decomp/com_hand.cpp.asm` (PreprocessMessages @ 0x00427600, CommOut @ 0x0042B270).
- Done when:
  - The two `// TODO: STUB` markers in `com_hand.cpp` are removed.
  - Behavior matches decomp control flow closely enough to compile/link clean.

Status note: landed as commit `88ab5b2` and merged via `52622b8`.

## Task 103 — Rendering: finish `RGE_Color_Table` parity (color)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining “best-effort” implementation note and restore full `color.cpp` parity so color translation/shadow tables and serialization behavior match the original engine.
- Implement: complete the remaining `RGE_Color_Table` methods present in `color.cpp` (constructors, destructor, `save(int fd)`, and any helper routines referenced by call sites).
- Where: `src/game/src/RGE_Color_Table.cpp` (+ `src/game/include/RGE_Color_Table.h` only if declarations are missing; do not change member layout/size asserts).
- Source of truth: `src/game/decomp/color.cpp.decomp` + `src/game/decomp/color.cpp.asm`.
- Done when:
  - The file-level `// TODO(accuracy)` note is no longer true (remaining methods are transliterated, and completed methods have verified markers).
  - Build remains clean without adding new placeholder stubs.

Status note: landed as commit `dc8ceb3` and merged via `f94db69`.

## Task 104 — UI follow-up: remove remaining `Panel_ez.cpp` “best-effort” blocks (prepare_for_close/draw_background)
- [x] Assigned to agent
- [x] Finished
- Goal: finish the remaining `TEasy_Panel` parity so screens relying on TEasy_Panel behave consistently and the file no longer needs “best-effort” caveats.
- Implement: audit and transliterate the remaining sections guarded by TODO(accuracy) in `Panel_ez.cpp`, especially:
  - `prepare_for_close` behavior.
  - The remaining boot→main-menu-path helper logic still marked best-effort.
  - `TEasy_Panel::draw_background` behavior.
- Where: `src/game/src/Panel_ez.cpp`.
- Source of truth: `src/game/decomp/panel_ez.cpp.decomp` + `src/game/decomp/panel_ez.cpp.asm`.
- Done when: the TODO(accuracy) markers in `Panel_ez.cpp` are removed (or replaced with fully verified markers) and build remains clean.

Status note: landed as commit `6b82a05` and merged via `d5064b0`.

## Task 105 — UI follow-up: finish `TInputPanel` TODO(accuracy) blocks (pnl_inp)
- [x] Assigned to agent
- [x] Finished
- Goal: remove remaining “best-effort transliteration” sections in `TInputPanel` so input handling matches decomp precisely.
- Implement: audit and finish the methods currently tagged TODO(accuracy) in `src/game/src/Pnl_inp.cpp` (offsets are already referenced inline in the file).
- Where: `src/game/src/Pnl_inp.cpp`.
- Source of truth: `src/game/decomp/pnl_inp.cpp.decomp` + `src/game/decomp/pnl_inp.cpp.asm`.
- Done when: all TODO(accuracy) markers in `Pnl_inp.cpp` are removed (or replaced with fully verified markers) and build remains clean.

Status note: landed as commit `0a94237` and merged via `d8ec0f5`.

## Task 106 — UI follow-up: finish `TEditPanel` TODO(accuracy) blocks (pnl_edit)
- [x] Assigned to agent
- [x] Finished
- Goal: remove remaining “best-effort transliteration” sections in `TEditPanel` so edit behavior matches decomp precisely.
- Implement: audit and finish the methods currently tagged TODO(accuracy) in `src/game/src/Pnl_edit.cpp` (offsets are already referenced inline in the file).
- Where: `src/game/src/Pnl_edit.cpp`.
- Source of truth: `src/game/decomp/pnl_edit.cpp.decomp` + `src/game/decomp/pnl_edit.cpp.asm`.
- Done when: all TODO(accuracy) markers in `Pnl_edit.cpp` are removed (or replaced with fully verified markers) and build remains clean.

Status note: landed as commit `4c25053` and merged via `5231468`.

## Task 107 — UI follow-up: finish `Pnl_txt.cpp` credits-related TODO(accuracy) blocks (scr_cred)
- [x] Assigned to agent
- [x] Finished
- Goal: eliminate the remaining credits-screen “best-effort” code paths by matching the original credits text logic.
- Implement: audit and finish the `Pnl_txt.cpp` methods currently tagged TODO(accuracy) (they reference `scr_cred.cpp` offsets inline).
- Where: `src/game/src/Pnl_txt.cpp`.
- Source of truth: `src/game/decomp/scr_cred.cpp.decomp` + `src/game/decomp/scr_cred.cpp.asm` (and `src/game/decomp/pnl_txt.cpp.decomp`/`.asm` where needed for the underlying panel behavior).
- Done when: the TODO(accuracy) markers in `Pnl_txt.cpp` are removed (or replaced with fully verified markers) and build remains clean.

Status note: landed as commit `fa9531a` and merged via `ee8167d`.

---

## Task 108 — UI/screen: restore `TRIBE_Mission_Screen` parity (mission dialog)
- [x] Assigned to agent
- [x] Finished
- Goal: replace the current best-effort mission dialog screen so the post-intro mission/instructions screen matches decomp behavior and screen teardown is safe.
- Implement:
  - Full transliteration of `TRIBE_Mission_Screen::TRIBE_Mission_Screen(char*, unsigned char, TPicture*)` @ 0x004B8100.
  - Full transliteration of `TRIBE_Mission_Screen::~TRIBE_Mission_Screen()` @ 0x004B87D0.
  - Implement `action(...)` and any other non-trivial overrides in the `scr_vc.cpp` unit needed for correct OK/continue behavior.
- Where: `src/game/src/TRIBE_Mission_Screen.cpp` (+ add missing method declarations in `src/game/include/TRIBE_Mission_Screen.h` if required; do not change member layout/size asserts).
- Source of truth: `src/game/decomp/scr_vc.cpp.decomp` + `src/game/decomp/scr_vc.cpp.asm` (TRIBE_Mission_Screen @ 0x004B8100).
- Done when:
  - The file-level TODO(accuracy) note in `TRIBE_Mission_Screen.cpp` is removed.
  - Constructor/dtor/action match decomp control flow closely enough to compile/link clean.

Status note: landed as commit `f9df2c3` and merged via `b769918`.

## Task 109 — UI widget: finish remaining `TButtonPanel` TODO(accuracy) parity (pnl_btn)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining “best-effort” `TButtonPanel` behaviors so radio/check/button state changes match the original.
- Implement: audit and finish the specific methods still tagged TODO(accuracy) in `src/game/src/TButtonPanel.cpp` (e.g. `set_radio_button` behavior and any adjacent state/flag logic).
- Where: `src/game/src/TButtonPanel.cpp`.
- Source of truth: `src/game/decomp/pnl_btn.cpp.decomp` + `src/game/decomp/pnl_btn.cpp.asm` (and `src/game/decomp/tpnl_btn.cpp.decomp`/`.asm` where those overrides apply).
- Done when:
  - TODO(accuracy) markers in `TButtonPanel.cpp` are removed (or replaced with fully verified markers).
  - Build remains clean and behavior matches decomp control flow.

Status note: landed as commit `41086c5` and merged via `a6bb22f`.

## Task 110 — In-game view: implement `RGE_Main_View` parity (vw_main)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the original “main view” wrapper over `RGE_View` (auto-scroll + key-scroll + scroll-view glue) as a prerequisite for replacing temporary in-game view scaffolding.
- Implement (decomp-first transliteration of the unit):
  - `RGE_Main_View::RGE_Main_View()` @ 0x0053DAB0.
  - `RGE_Main_View::handle_idle()` @ 0x0053DB40.
  - `RGE_Main_View::do_auto_scroll()` @ 0x0053DBA0.
  - `RGE_Main_View::handle_keys()` (and helpers it calls) from `vw_main.cpp`.
  - Scroll-view virtuals (`start_scroll_view`, `handle_scroll_view`, `end_scroll_view`) and any other overrides present in the decomp unit.
- Where:
  - Add `src/game/src/RGE_Main_View.cpp`.
  - Add method declarations to `src/game/include/RGE_Main_View.h` as needed (do not change member layout/size asserts).
- Source of truth: `src/game/decomp/vw_main.cpp.decomp` + `src/game/decomp/vw_main.cpp.asm`.
- Done when: `RGE_Main_View` can be instantiated and linked cleanly with its decomp behaviors (no placeholder stubs added).

Status note: vw_main parity landed as commits `8c1bedd` and `89afb33` (now in `master`).

## Task 111 — In-game view: implement `TRIBE_Main_View` parity (tvw_main)
- [x] Assigned to agent
- [x] Finished
- Goal: restore TRIBE-specific main-view behaviors used by placement/outline/mouse command logic.
- Implement (decomp-first transliteration of the unit):
  - Key TRIBE overrides in `tvw_main.cpp` (e.g. `draw_multi_object_outline`, `command_place_object`, `command_place_multi_object`, mouse up actions) and any helpers they rely on (wall outline / line of walls placement).
- Where:
  - Add `src/game/src/TRIBE_Main_View.cpp`.
  - Update `src/game/include/TRIBE_Main_View.h` with method declarations required by the transliteration (do not change member layout/size asserts).
- Source of truth: `src/game/decomp/tvw_main.cpp.decomp` + `src/game/decomp/tvw_main.cpp.asm`.
- Dependency note: requires Task 110 (`RGE_Main_View`) to be complete first.
- Done when: `TRIBE_Main_View` compiles/links and matches the decomp control flow for the implemented overrides.

Status note: tvw_main parity landed as commits `0bc6a38` + `ae7a1af`, merged via `3f871ae`.

## Task 112 — Main menu: implement `TRIBE_Credits_Screen` and stop using stub credits panel
- [x] Assigned to agent
- [x] Finished
- Goal: remove the main-menu credits stub panel and use the real `TRIBE_Credits_Screen` so credits flow matches the original.
- Implement:
  - Transliterate `TRIBE_Credits_Screen` from `scr_cred.cpp` (constructor/dtor + idle/action + any draw/setup logic needed for correct playback).
  - Update the main menu key handler so pressing `C` opens the real `TRIBE_Credits_Screen` instead of `create_stub_screen(... "Credits (Stub)")`.
- Where:
  - Add `src/game/src/TRIBE_Credits_Screen.cpp` (new translation unit).
  - Update `src/game/src/Scr_main_impl.cpp` (credits hotkey path only; avoid touching the MP/editor stub screens in this task to keep scope tight).
- Source of truth: `src/game/decomp/scr_cred.cpp.decomp` + `src/game/decomp/scr_cred.cpp.asm` (primary), plus `src/game/decomp/scr_main.cpp.decomp` for the main menu dispatch expectations.
- Done when:
  - The credits hotkey no longer routes through `MainMenuStubScreen`.
  - `TRIBE_Credits_Screen` compiles/links and can be constructed without introducing new placeholder stubs.

Status note: landed as commit `c6224e5` and merged via `4a283d4`.

## Task 113 — Actions: remove `RGE_Action_Object::move_to` TODO(accuracy) by matching `act_obj` decomp
- [x] Assigned to agent
- [x] Finished
- Goal: eliminate the remaining best-effort `move_to` action creation path so move commands create the correct action type and serialize consistently.
- Implement: decomp-first transliteration of `RGE_Action_Object::move_to(...)` (and any adjacent helpers it needs) so it matches `act_obj.cpp` behavior.
- Where: `src/game/src/RGE_Action_Object.cpp`.
- Source of truth: `src/game/decomp/act_obj.cpp.decomp` + `src/game/decomp/act_obj.cpp.asm` (and `src/game/decomp/act_move.cpp.decomp` / `.asm` if construction signature details are ambiguous).
- Done when:
  - The two TODO(accuracy) markers in `RGE_Action_Object::move_to` are removed.
  - The implementation matches decomp control flow and build remains clean.

Status note: landed as commit `9c79aa1` and merged via `0a24787`.

## Task 114 — MP/COM: remove `TCommunications_Handler::UpdatePlayer` TODO(accuracy) (name refresh)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining best-effort DirectPlay name refresh logic and match the original `com_hand.cpp` behavior.
- Implement: audit and adjust `TCommunications_Handler::UpdatePlayer(uint id, int timeout)` name refresh branch to match the decomp (buffer sizing, structure interpretation, null/empty behavior, and whether names are refreshed unconditionally).
- Where: `src/game/src/com_hand.cpp`.
- Source of truth: `src/game/decomp/com_hand.cpp.decomp` + `src/game/decomp/com_hand.cpp.asm`.
- Done when: the TODO(accuracy) marker in `UpdatePlayer` is removed (or replaced with a fully verified marker) and build remains clean.

Status note: landed as commit `cf94c50` and merged via `ae5be41`.

## Task 115 — In-game screen: retire `GameViewPanel` scaffolding from `TRIBE_Screen_Game`
- [x] Assigned to agent
- [x] Finished
- Goal: stop routing in-game rendering/input through the temporary `GameViewPanel` base and use the real view pipeline (`RGE_Main_View`/`TRIBE_Main_View`) for parity.
- Implement:
  - Update `TRIBE_Screen_Game` so its “main view” is a `TRIBE_Main_View` (not a bare `RGE_View`) and stop inheriting from `GameViewPanel` once equivalent behavior exists.
  - Keep the implementation parity-first: transliterate the relevant setup/teardown from `scr_game.cpp`.
- Where: `src/game/src/TRIBE_Screen_Game.cpp` (+ `src/game/include/TRIBE_Screen_Game.h` if inheritance/decls need to change; do not change member layout/size asserts).
- Source of truth: `src/game/decomp/scr_game.cpp.decomp` + `src/game/decomp/scr_game.cpp.asm`, plus Task 110/111 sources for main-view behavior.
- Dependency note: requires Task 110 + Task 111 to be complete first.
- Done when:
  - `TRIBE_Screen_Game` no longer relies on `GameViewPanel` for its core view behavior.
  - Build remains clean and no new placeholder stubs are introduced.

Status note: landed as commit `fddf946` and merged via `5bbd320`.

---

## Task 116 — MP UI: implement `TribeMPStartupScreen` + `TribeJoinScreen` (+ `TribeMPCreateDialog`) parity
- [x] Assigned to agent
- [x] Finished
- Goal: replace the current main-menu MP “stub screen” flow with the real MP Startup + Join + Create dialog screens so MP UI transitions and session browsing are parity-correct.
- Implement (decomp-first transliteration):
  - `TribeMPStartupScreen::TribeMPStartupScreen()` @ 0x0049F370.
  - `TribeMPStartupScreen::~TribeMPStartupScreen()` @ 0x0049F890.
  - `TribeMPStartupScreen::handle_idle()` @ 0x0049F9A0.
  - `TribeMPStartupScreen::action(...)` @ 0x0049F9D0.
  - `TribeMPStartupScreen::fillList()` @ 0x0049FED0.
  - `TribeJoinScreen::TribeJoinScreen()` @ 0x00491650.
  - `TribeJoinScreen::~TribeJoinScreen()` @ 0x00491990.
  - `TribeJoinScreen::handle_idle()` @ 0x00491A80.
  - `TribeJoinScreen::handle_user_command(...)` @ 0x00491B20.
  - `TribeJoinScreen::fillList()` @ 0x00491C70.
  - `TribeJoinScreen::action(...)` @ 0x00491E20.
  - `TribeMPCreateDialog::TribeMPCreateDialog(TPanel*)` @ 0x004920C0.
  - `TribeMPCreateDialog::~TribeMPCreateDialog()` @ 0x00492330.
  - `TribeMPCreateDialog::action(...)` @ 0x004923C0.
- Where:
  - Add `src/game/src/TribeMPStartupScreen.cpp`.
  - Add `src/game/src/TribeJoinScreen.cpp` (may include `TribeMPCreateDialog` too, since it lives in `scr_cj`).
  - Update headers only for missing method declarations:
    - `src/game/include/TribeMPStartupScreen.h`
    - `src/game/include/TribeJoinScreen.h`
    - `src/game/include/TribeMPCreateDialog.h`
    (Do not change member layout/size asserts.)
- Source of truth: `src/game/decomp/scr_mp.cpp.decomp` + `src/game/decomp/scr_mp.cpp.asm`, `src/game/decomp/scr_cj.cpp.decomp` + `src/game/decomp/scr_cj.cpp.asm`.
- Done when:
  - New translation units compile/link cleanly without introducing new placeholder stubs.
  - `TribeMPStartupScreen` can construct/destroy and its `action()` can construct the join screen and create-dialog per decomp.

Status note: landed as commit `8f02236` (now in `master`).

## Task 117 — Scenario editor UI: implement `TRIBE_Screen_Sed_Menu` + `TRIBE_Screen_Sed_Open` + `TRIBE_Campaign_Editor_Screen` parity
- [x] Assigned to agent
- [x] Finished
- Goal: restore the pre-editor “Scenario Builder” screen flow so menu/open/campaign-editor transitions match original behavior.
- Implement (decomp-first transliteration):
  - `TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu()` @ 0x004B2EF0.
  - `TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu()` @ 0x004B3110.
  - `TRIBE_Screen_Sed_Menu::handle_idle()` @ 0x004B31A0.
  - `TRIBE_Screen_Sed_Menu::action(...)` @ 0x004B31D0.
  - `TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open()` @ 0x004B33D0.
  - `TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open()` @ 0x004B36A0.
  - `TRIBE_Screen_Sed_Open::fillList()` @ 0x004B3740.
  - `TRIBE_Screen_Sed_Open::action(...)` @ 0x004B38A0.
  - `TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen()` @ 0x0048F5D0.
  - `TRIBE_Campaign_Editor_Screen::~TRIBE_Campaign_Editor_Screen()` @ 0x0048FA40.
  - And the helper routines in `scr_cam` that it relies on (e.g. list/dropdown fill and campaign load/save glue).
- Where:
  - Add `src/game/src/TRIBE_Screen_Sed_Menu.cpp`.
  - Add `src/game/src/TRIBE_Screen_Sed_Open.cpp`.
  - Add `src/game/src/TRIBE_Campaign_Editor_Screen.cpp`.
  - Update headers only for missing method declarations:
    - `src/game/include/TRIBE_Screen_Sed_Menu.h`
    - `src/game/include/TRIBE_Screen_Sed_Open.h`
    - `src/game/include/TRIBE_Campaign_Editor_Screen.h`
    (Do not change member layout/size asserts.)
- Source of truth: `src/game/decomp/scr_sedm.cpp.decomp` + `src/game/decomp/scr_sedm.cpp.asm`, `src/game/decomp/scr_sedo.cpp.decomp` + `src/game/decomp/scr_sedo.cpp.asm`, `src/game/decomp/scr_cam.cpp.decomp` + `src/game/decomp/scr_cam.cpp.asm`.
- Done when: all three screens compile/link cleanly and their action/transition logic matches the decomp control flow.

Status note: landed as commit `4bf9d4a` and merged via `16d59e0` (follow-up wrapper fix in `1438141`).

## Task 118 — Scenario editor core: implement `TRIBE_Screen_Sed` parity (scr_sed)
- [x] Assigned to agent
- [ ] Finished
- Goal: restore the full in-editor runtime so scenario edit mode uses the same map/view initialization, editor tools, and save prompts as the original.
- Implement: decomp-first transliteration of the `scr_sed.cpp` unit, starting with:
  - `TRIBE_Screen_Sed::TRIBE_Screen_Sed(char*, int)` @ 0x004A81E0.
  - Then complete the remaining non-trivial editor behaviors required for a compile/link-clean TU (handle idle, action routing, command handlers, save/open flows).
- Where: add `src/game/src/TRIBE_Screen_Sed.cpp` (+ update `src/game/include/TRIBE_Screen_Sed.h` with method declarations as needed; do not change member layout/size asserts).
- Source of truth: `src/game/decomp/scr_sed.cpp.decomp` + `src/game/decomp/scr_sed.cpp.asm`.
- Dependency note: depends on Task 110 + Task 111 (main view types) and Task 117 (menu/open screens) for a clean end-to-end screen flow.
- Done when: `TRIBE_Screen_Sed` compiles/links cleanly and its constructor/setup matches the decomp control flow (view + minimap + message panel setup).

Status note: base implementation landed as `7839d26` with ctor parity fixes in `c53563d`, but the file still contains multiple `// TODO: STUB (partial)` blocks; remaining work is still pending.

## Task 119 — UI/screen: implement `TRIBE_Screen_Info` parity (scr_info)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the generic “info / timed auto-close” screen used by multiple flows (auto-close timer, click/keypress close, and close transition logic).
- Implement:
  - `TRIBE_Screen_Info::TRIBE_Screen_Info(char*, char*, long, ulong)` @ 0x0049D550.
  - `TRIBE_Screen_Info::~TRIBE_Screen_Info()` @ 0x0049D600.
  - `TRIBE_Screen_Info::handle_idle()` @ 0x0049D610.
  - `TRIBE_Screen_Info::key_down_action(...)` @ 0x0049D690.
  - `TRIBE_Screen_Info::mouse_left_down_action(...)` @ 0x0049D6B0.
  - `TRIBE_Screen_Info::action(...)` @ 0x0049D6C0.
  - `TRIBE_Screen_Info::close_screen()` @ 0x0049D6E0.
- Where:
  - Add `src/game/src/TRIBE_Screen_Info.cpp`.
  - Update `src/game/include/TRIBE_Screen_Info.h` only for missing method declarations (do not change member layout/size asserts).
- Source of truth: `src/game/decomp/scr_info.cpp.decomp` + `src/game/decomp/scr_info.cpp.asm`.
- Done when: `TRIBE_Screen_Info` compiles/links cleanly and close behavior matches the decomp control flow.

Status note: landed as commit `1a26e24` and merged via `2f34d37`.

## Task 120 — UI/screen: implement `TribeSelectTribeScreen` parity (scr_trb)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the civilization/tribe selection screen so SP and scenario flows can select a tribe with correct UI and button routing.
- Implement (decomp-first transliteration):
  - `TribeSelectTribeScreen::TribeSelectTribeScreen()` @ 0x004B75A0.
  - `TribeSelectTribeScreen::~TribeSelectTribeScreen()` @ 0x004B7DF0.
  - `TribeSelectTribeScreen::action(...)` @ 0x004B7EE0.
  - `TribeSelectTribeScreen::fillTribeText(int)` @ 0x004B7F70.
  - `TribeSelectTribeScreen::tribeName(int)` @ 0x004B8070.
- Where:
  - Add `src/game/src/TribeSelectTribeScreen.cpp`.
  - Update `src/game/include/TribeSelectTribeScreen.h` only for missing method declarations (do not change member layout/size asserts).
- Source of truth: `src/game/decomp/scr_trb.cpp.decomp` + `src/game/decomp/scr_trb.cpp.asm`.
- Done when: the screen compiles/links cleanly and the UI creation/action routing matches decomp control flow.

Status note: landed as commit `e403e34` and merged via `d327b1c`.

## Task 121 — MP UI: implement `TRIBE_Screen_Disconnect` parity (disconnect screen)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the multiplayer disconnect screen so MP teardown paths don’t rely on missing/stub behavior.
- Implement:
  - `TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect(int)` @ 0x004A61A0.
  - `TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect()` @ 0x004A6290.
  - `TRIBE_Screen_Disconnect::set_text(char*)` @ 0x004A62F0.
  - `TRIBE_Screen_Disconnect::set_text(long)` @ 0x004A6310.
  - `TRIBE_Screen_Disconnect::action(...)` @ 0x004A6330.
  - `TRIBE_Screen_Disconnect::handle_idle()` @ 0x004A63C0.
- Where:
  - Add `src/game/src/TRIBE_Screen_Disconnect.cpp`.
  - Update `src/game/include/TRIBE_Screen_Disconnect.h` only for missing method declarations (do not change member layout/size asserts).
- Source of truth: `src/game/decomp/scr_mps.cpp.decomp` + `src/game/decomp/scr_mps.cpp.asm` (disconnect block near the end of the unit).
- Done when: the disconnect screen compiles/links cleanly and action/idle match the decomp control flow.

Status note: landed as commit `bd665f3` and merged via `29a0d2e`.

## Task 122 — Save UI: remove `scr_save_impl` scenario-editor TODO(parity) (activate real `TRIBE_Screen_Sed_Open`)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining save-screen TODO that notes the original constructs/activates `TRIBE_Screen_Sed_Open` directly.
- Implement: update the scenario-editor-related save path so it constructs/activates `TRIBE_Screen_Sed_Open` per the original flow (and removes the TODO marker).
- Where: `src/game/src/scr_save_impl.cpp`.
- Source of truth: `src/game/decomp/scr_save.cpp.decomp` + `src/game/decomp/scr_save.cpp.asm` (and `src/game/decomp/scr_sedo.cpp.decomp` for how the open screen is created/activated).
- Dependency note: requires Task 117 (`TRIBE_Screen_Sed_Open`) to exist.
- Done when: the TODO(parity) marker in `scr_save_impl.cpp` is removed and build remains clean.

Status note: landed as commit `bf35ea5` and merged via `4530bb0`.

## Task 123 — Main menu: stop using MP/editor stub screens in `Scr_main_impl` (after real screens land)
- [x] Assigned to agent
- [x] Finished
- Goal: retire the remaining main-menu “stub screen” usages for MP Startup and Scenario Editor Menu once the real screens exist.
- Implement:
  - Replace the MP Startup stub creation with constructing/activating `TribeMPStartupScreen`.
  - Replace the Scenario Editor Menu stub creation with constructing/activating `TRIBE_Screen_Sed_Menu`.
  - Keep this task focused: do not touch the credits stub path here (Task 112 owns credits).
- Where: `src/game/src/Scr_main_impl.cpp`.
- Source of truth: `src/game/decomp/scr_main.cpp.decomp` + `src/game/decomp/scr_main.cpp.asm` (main menu action dispatch), plus Task 116/117 sources for screen creation expectations.
- Dependency note: requires Task 116 and Task 117 to be complete first.
- Done when: MP Startup + Scenario Editor menu no longer route through `create_stub_screen(...)` and build remains clean.

Status note: MP Startup screen routing landed with Task 116 (`8f02236`), and scenario-editor menu routing landed with Task 117 (`4bf9d4a`).

## Task 124 — Rendering/view: implement missing `RGE_View` selection + draw pipeline helpers required by main views
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining `RGE_View` “missing pipeline” gaps so `RGE_Main_View`/`TRIBE_Main_View` can rely on original selection display + draw/update behavior.
- Implement (decomp-first transliteration of the missing methods from `view.cpp.decomp`):
  - `RGE_View::update_display_selected_objects()`.
  - `RGE_View::display_object_selection(int, int, int, int)`.
  - `RGE_View::delete_surfaces()` and `RGE_View::create_surfaces()`.
  - `RGE_View::calc_draw_vars()`.
  - `RGE_View::draw_object_outline()` and `RGE_View::draw_paint_brush()`.
  - `RGE_View::get_tile_screen_coords(...)`, `get_center_screen_pos(...)`, `get_start_coords(...)`, `get_center_coords(...)`, `get_tile_sizes(...)`.
  - The missing `RGE_View::view_function(...)` dispatcher (the code currently notes it’s not transliterated yet).
- Where:
  - `src/game/src/view.cpp`.
  - `src/game/include/RGE_View.h` for method declarations only (do not change member layout/size asserts).
- Source of truth: `src/game/decomp/view.cpp.decomp` + `src/game/decomp/view.cpp.asm`.
- Dependency note: intended as a prerequisite for Task 110/111/115 view-pipeline work; coordinate if another agent is actively modifying `view.cpp`.
- Done when: the missing-method gap is closed (methods exist, compile/link cleanly) and `RGE_View` no longer references an unimplemented `view_function()` in its core interaction paths.

Status note: landed as commit `b173887` and merged via `f8a401b`.

## Task 125 — Main menu error: implement `TRIBE_Screen_Main_Error` parity (scr_main)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the main-menu error screen used for fatal/error message flows.
- Implement:
  - `TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error()` @ 0x0049F0D0.
  - `TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error()` @ 0x0049F240.
  - `TRIBE_Screen_Main_Error::set_text(char*)` @ 0x0049F2B0 and `set_text(long)` @ 0x0049F2D0.
  - `TRIBE_Screen_Main_Error::action(...)` @ 0x0049F2F0.
  - `TRIBE_Screen_Main_Error::handle_idle()` @ 0x0049F340.
- Where:
  - Add `src/game/src/TRIBE_Screen_Main_Error.cpp`.
  - Update `src/game/include/TRIBE_Screen_Main_Error.h` only for missing method declarations (do not change member layout/size asserts).
- Source of truth: `src/game/decomp/scr_main.cpp.decomp` + `src/game/decomp/scr_main.cpp.asm`.
- Done when: the screen compiles/links cleanly and its setup/action/idle match decomp control flow.

Status note: landed as commit `b727be4` and merged via `36d5cff`.

## Task 126 — Main menu follow-up: remove remaining `Scr_main_impl.cpp` TODO(accuracy) markers (no new UX)
- [x] Assigned to agent
- [x] Finished
- Goal: eliminate the remaining best-effort TODO(accuracy) notes in the main menu implementation by matching `scr_main` decomp control flow exactly.
- Implement: adjust only the TODO(accuracy) blocks (e.g. setup tuple selection and current-child/tab-order behavior) so they match decomp; do not add new screens/features.
- Where: `src/game/src/Scr_main_impl.cpp`.
- Source of truth: `src/game/decomp/scr_main.cpp.decomp` + `src/game/decomp/scr_main.cpp.asm`.
- Dependency note: will conflict with Task 112/123 if run concurrently; schedule after those land.
- Done when: all TODO(accuracy) markers in `Scr_main_impl.cpp` are removed (or replaced with verified markers) and build remains clean.

Status note: landed as commit `180de8c` and merged via `0b7bedb`.

---

## Task 127 — UI core: implement `TPanel::set_overlapped_redraw` + tab-order parity (panel.cpp)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining core-panel stubs so overlapped redraw invalidation and keyboard tab navigation behave like the original.
- Implement (decomp-first transliteration):
  - `TPanel::set_overlapped_redraw(TPanel*, TPanel*, RedrawMode)` @ 0x00464F20.
  - `TPanel::set_tab_order(TPanel**, short)` @ 0x00466600.
  - `TPanel::set_tab_order(TPanel*, TPanel*)` @ 0x00466650.
- Where:
  - `src/game/src/TPanel.cpp`.
  - `src/game/include/TPanel.h` only if method declarations are missing (do not change member layout/size asserts).
- Source of truth: `src/game/decomp/panel.cpp.decomp` + `src/game/decomp/panel.cpp.asm`.
- Done when: the two TODO stubs in `TPanel.cpp` are removed and build remains clean.

Status note: landed as commit `a7a2dab` and merged via `eb5101c`.

## Task 128 — World save/init: implement remaining `RGE_Game_World` serialization + init stubs (world.cpp)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the original world save/init virtuals so save-game + scenario serialization and scenario bootstrap don’t rely on placeholders.
- Implement (decomp-first transliteration):
  - `RGE_Game_World::load_player(int, uchar, short)` @ 0x00542060.
  - `RGE_Game_World::save(int)` @ 0x00543540.
  - `RGE_Game_World::save_game(char*)` @ 0x00543770.
  - `RGE_Game_World::base_save(int)` @ 0x00543850.
  - `RGE_Game_World::base_save(char*)` @ 0x005439C0.
  - `RGE_Game_World::save_scenario(char*)` @ 0x00543A00.
  - `RGE_Game_World::scenario_init(int, RGE_Game_World*)` @ 0x00541B60.
  - `RGE_Game_World::scenario_init(RGE_Game_World*)` @ 0x00541BC0.
  - `RGE_Game_World::logStatus(FILE*, int)` @ 0x00540A10 (decomp shows this as an intentional no-op).
  - `RGE_Game_World::get_scenario_info(char*)` @ 0x00545CE0 (decomp shows return-null behavior for base type).
- Where: `src/game/src/RGE_Game_World.cpp` (+ header `src/game/include/RGE_Game_World.h` only if required for declarations).
- Source of truth: `src/game/decomp/world.cpp.decomp` + `src/game/decomp/world.cpp.asm`.
- Done when: the `// TODO: implement` stubs for these methods are removed (or replaced with fully verified markers) and save paths compile/link cleanly.

Status note: landed as commit `9a78af4` and merged via `0157a15`.

## Task 129 — UI widget: finish `TDropDownPanel::get_line(char*)` parity (pnl_drop)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining dropdown text-lookup stub so dropdowns can map selected text to list lines correctly.
- Implement: `TDropDownPanel::get_line(char*)` @ 0x004753C0 by calling through to the list panel’s `TTextPanel::get_line(char*)` (already implemented).
- Where: `src/game/src/Pnl_drop.cpp`.
- Source of truth: `src/game/decomp/pnl_drop.cpp.decomp` + `src/game/decomp/pnl_drop.cpp.asm`.
- Done when: the TODO stub in `TDropDownPanel::get_line(char*)` is removed and build remains clean.

Status note: landed as commit `a2de119` and merged via `9f2d724`.

## Task 130 — Debug logging: implement `write_draw_log` + `write_draw_log2` parity (basegame.cpp)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the original draw-log helpers used by view/sprite codepaths (normally gated by globals), removing the current no-op stubs.
- Implement:
  - `write_draw_log(char*)` @ 0x0041B620.
  - `write_draw_log2(char*)` @ 0x0041B650.
- Where:
  - `src/game/src/debug_helpers.cpp`.
  - Add/verify required globals (`draw_log`, `draw_log_name`, `do_draw_log`, `safe_draw_log`) in `src/game/include/globals.h` + `src/game/src/globals.cpp` if missing.
- Source of truth: `src/game/decomp/basegame.cpp.decomp` + `src/game/decomp/basegame.cpp.asm`.
- Done when: the two TODO stub bodies in `debug_helpers.cpp` are removed and the functions match the decomp control flow.

Status note: landed as commit `80f0c6d` and merged via `1178e9d`.

## Task 131 — Debug rendering: implement `color_log` parity (colorlog)
- [x] Assigned to agent
- [x] Finished
- Goal: restore the original “color log” helper used by some save/render debug paths (typically gated behind `do_color_log`).
- Implement: `color_log(uchar, uchar, int)` @ 0x00424810.
- Where: either implement directly in `src/game/src/debug_helpers.cpp` (keeping the exported signature) or add a dedicated TU (project-consistent choice), ensuring there is exactly one definition.
- Source of truth: `src/game/decomp/colorlog.cpp.decomp` + `src/game/decomp/colorlog.cpp.asm`.
- Done when: `debug_helpers.cpp` no longer has a TODO stub for `color_log` and build remains clean.

Status note: landed as commit `ebb2d4d` and merged via `cbbe5d1`.

## Task 132 — Cleanup: delete `GameViewPanel` scaffolding (non-original)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the temporary, non-original `GameViewPanel` renderer now that the real view/screen pipeline has landed.
- Implement:
  - Remove `src/game/src/GameViewPanel.cpp` and `src/game/include/GameViewPanel.h`.
  - Verify there are no remaining references; if any exist, update call sites to use the real panels/views instead.
- Where: delete the two files above (and any trivial include cleanups required).
- Done when: build remains clean and no code references `GameViewPanel`.

Status note: landed as commit `64366b5` and merged via `35f6c81`.

## Task 133 — Audio utils: implement `WaveCreateFile` parity (dsutil)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining WAV-write stub so any tooling paths that emit WAV data don’t hard-fail.
- Implement: `WaveCreateFile(...)` @ 0x00448080.
- Where: `src/game/src/Dsutil.cpp`.
- Source of truth: `src/game/decomp/dsutil.cpp.asm` (Ghidra decomp notes this function failed; ASM is required source of truth here) + any partial context in `src/game/decomp/dsutil.cpp.decomp`.
- Done when: the stub body is replaced with a parity implementation and build remains clean.

Status note: landed as commit `85f79e8` and merged via `34e38c8`.

---

## Task 134 — Basegame CD gating: implement `RGE_Base_Game::check_for_cd` (+ `playerHasCD`) parity
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining basegame CD verification stub so SP/MP startup uses the original gating rules (`verify_cd`, `CDPath`, `vol_name`, and max-players-per-CD logic).
- Implement (decomp-first transliteration):
  - `RGE_Base_Game::check_for_cd(int)` @ 0x0041FC90.
  - `RGE_Base_Game::playerHasCD(int)` @ 0x004224A0 (required dependency called by `check_for_cd`).
- Where:
  - `src/game/src/basegame.cpp`.
  - `src/game/include/RGE_Base_Game.h` for method declarations (do not change member layout/size asserts).
  - `src/game/include/globals.h` + `src/game/src/globals.cpp` only if missing globals referenced by the decomp (`force_cd`, etc).
- Source of truth: `src/game/decomp/basegame.cpp.decomp` + `src/game/decomp/basegame.cpp.asm`.
- Non-overlap note: conflicts with other tasks that edit `basegame.cpp`; schedule accordingly.
- Done when: `RGE_Base_Game::check_for_cd` is no longer a stub (`return 1`) and matches the decomp control flow (including the multiplayer “humanity” count branch).

Status note: landed as commit `feca2ad` and merged via `170e451`.

## Task 135 — Basegame player switching: implement `RGE_Base_Game::set_player` parity (clear map view info)
- [x] Assigned to agent
- [x] Finished
- Goal: match the original player-switch behavior (bounds check + clear map view info), removing the now-stale TODO in the implementation.
- Implement: `RGE_Base_Game::set_player(short)` @ 0x00420150.
- Where: `src/game/src/basegame.cpp`.
- Source of truth: `src/game/decomp/basegame.cpp.decomp` + `src/game/decomp/basegame.cpp.asm`.
- Dependency note: `RGE_Map::clear_map_view_info()` already exists in `src/game/src/RGE_Map.cpp`; just call it per decomp.
- Non-overlap note: conflicts with other tasks that edit `basegame.cpp`; schedule accordingly.
- Done when: `set_player` checks `world != nullptr` and `param_1 < world->player_num` and then calls `world->map->clear_map_view_info()`.

Status note: landed as commit `b021996` and merged via `c4ff834`.

## Task 136 — File/STF: implement `DriveInformation` parity (file_stf)
- [ ] Assigned to agent
- [x] Finished
- Goal: restore the missing `DriveInformation` helper used by basegame startup and file utilities (drive enumeration + cwd tracking).
- Implement (decomp-first transliteration from `file_stf.cpp`):
  - Free helpers: `driveAsLetter(int)` @ 0x00449750, `driveAsInt(char)` @ 0x00449760.
  - `DriveInformation::DriveInformation()` @ 0x00449770.
  - `initialDrive/initialDriveAsLetter/initialDirectory` @ 0x004497C0/0x004497D0/0x004497E0.
  - `currentDrive/currentDriveAsLetter/currentDirectory` @ 0x004497F0/0x00449800/0x00449810.
  - `numberDrives/validDrive/checkDrives` @ 0x00449820/0x00449830/0x00449840.
  - File-count helpers: `numberOfFilesWithFilename` @ 0x004498A0, `numberOfFilesWithAttribute` @ 0x00449910, `numberOfFilesWithFilenameOrAttribute` @ 0x00449990.
  - Drive/cwd helpers: `resetCurrentDriveAndDirectory/resetCurrentDrive/resetCurrentDirectory` @ 0x00449A20/0x00449A40/0x00449A50.
  - `changeDrive/changeDirectory/updateDirectory` @ 0x00449A60/0x00449A90/0x00449AC0.
- Where:
  - Add a new TU `src/game/src/DriveInformation.cpp` (preferred) or place into the most appropriate existing TU if that’s the codebase pattern.
  - Add method declarations to `src/game/include/DriveInformation.h` (do not change member layout/size asserts).
- Source of truth: `src/game/decomp/file_stf.cpp.decomp` + `src/game/decomp/file_stf.cpp.asm`.
- Done when: the methods compile/link cleanly, and callers can construct `DriveInformation` without new stubs.

Status note: landed as commit `bd83ac2` and merged via `b143987`.

## Task 137 — DIB blit pipeline: implement `DibBlt`/`TransDibBlt`/`TileDibBlt` (+ palette mapping) and restore `TPicture::Draw` parity
- [x] Assigned to agent
- [x] Finished
- Goal: remove the non-original `TPicture::Draw` >8bpp fallback and use the original DIB blit helpers for correct clip/scale/transparency behavior.
- Implement (decomp-first transliteration):
  - `DibBlt(...)` @ 0x00438820.
  - `TransDibBlt(...)` @ 0x00438AA0.
  - `ClipDibBlt(...)` @ 0x00438E80.
  - `TileDibBlt(...)` @ 0x004390A0.
  - `DibMapToPalette(...)` @ 0x0043A660.
  - Update `TPicture::Draw(...)` @ 0x0046E2D0 to match `picture.cpp.decomp` (call `TransDibBlt` when `TransInfo` exists; otherwise `DibBlt`).
  - If `TPicture::Tile(...)` exists in code, ensure it routes to `TileDibBlt(...)` per `picture.cpp.decomp` @ 0x0046E370.
- Where:
  - `src/game/src/Dib.cpp` (add the missing functions; keep existing palette loader unless it conflicts).
  - `src/game/src/Picture.cpp` (replace the custom blit body with the decomp’s call pattern).
- Source of truth:
  - `src/game/decomp/dib.cpp.decomp` + `src/game/decomp/dib.cpp.asm`.
  - `src/game/decomp/picture.cpp.decomp` + `src/game/decomp/picture.cpp.asm`.
- Done when: the TODO in `Picture.cpp` about >8bpp conversion is gone and `TPicture::Draw` control flow matches the decomp.

Status note: landed as commit `d68ac23` and merged via `2f16354`.

## Task 138 — MP setup (scr_mps): implement `updateSummary` + finish `fillPlayers/setupSinglePlayerPlayers` parity (remove TODOs)
- [ ] Assigned to agent
- [x] Finished
- Goal: remove the remaining TODO/assumption blocks in MP Setup so scenario metadata and summary UI update match the original.
- Implement (decomp-first transliteration):
  - `TribeMPSetupScreen::updateSummary()` @ 0x004A4190.
  - `TribeMPSetupScreen::fillPlayers()` @ 0x004A37D0.
  - `TribeMPSetupScreen::setupSinglePlayerPlayers()` @ 0x004A5210.
- Where:
  - `src/game/src/scr_mps_impl.cpp`.
  - Update `src/game/include/TribeMPSetupScreen.h` only for missing declarations (do not change member layout/size asserts).
- Source of truth: `src/game/decomp/scr_mps.cpp.decomp` + `src/game/decomp/scr_mps.cpp.asm`.
- Done when: the three TODO markers currently in `scr_mps_impl.cpp` are removed and build remains clean.

Status note: landed as commit `abe1991` and merged via `28931b8`.

## Task 139 — Main menu cleanup: remove dead stub-screen helper and stale TODO notes (no new UX)
- [x] Assigned to agent
- [x] Finished
- Goal: delete remaining main-menu scaffolding comments/helpers that are no longer used now that the real screens exist.
- Implement:
  - Remove the unused `create_stub_screen(...)` helper from `Scr_main_impl.cpp` (it is defined but no longer referenced anywhere).
  - Remove the now-stale TODO/STUB comments about “dialog and target screens are currently stubs” if those code paths are now implemented.
- Where: `src/game/src/Scr_main_impl.cpp`.
- Source of truth: `src/game/decomp/scr_main.cpp.decomp` + `src/game/decomp/scr_main.cpp.asm` (ensure you don’t change runtime behavior; this is cleanup only).
- Done when: `Scr_main_impl.cpp` contains no stub-screen helper or stale TODO/STUB comments and build remains clean.

Status note: landed as commit `ece7d0b` and merged via `a0d4de2`.

---

## Task 140 — Startup: implement `GetDXVersion` (platform + version outputs) parity enough to remove stub
- [ ] Assigned to agent
- [x] Finished
- Goal: remove the current `GetDXVersion` hardcoded stub so callers receive plausible platform/version outputs per the original.
- Implement: `GetDXVersion(ulong* dx_version, ulong* dx_platform)` @ 0x0044DAC0.
- Where: `src/game/src/getdxver.cpp`.
- Source of truth: `src/game/decomp/getdxver.cpp.decomp` + `src/game/decomp/getdxver.cpp.asm`.
- Scope note: start by matching the OS/platform gating (Win9x vs NT) and set outputs consistently with the decomp’s early-return paths; only expand into the DirectDraw/DirectPlay probing if required for build-parity (avoid new stubs).
- Done when: the `dx_platform` TODO is removed, outputs are set by real logic (not constants), and build remains clean.

Status note: landed as commit `a295543` and merged via `8031000`.

## Task 141 — Startup constants: fix `mouse_scroll_max_dist` / `key_scroll_max_dist` bit-pattern parity (main)
- [x] Assigned to agent
- [x] Finished
- Goal: match the original initialization which stores integer `0x54` into these float fields (decomp shows `1.17709e-43`, i.e. float bit-pattern `0x00000054`).
- Implement: replace the current `84.0f` assignments with a bitwise store of `0x54` into both float fields.
- Where: `src/game/src/main.cpp`.
- Source of truth: `src/game/decomp/main.cpp.decomp` (search for `mouse_scroll_max_dist` / `key_scroll_max_dist`) + `src/game/decomp/main.cpp.asm` if needed.
- Done when: the TODO marker is removed and the two fields are initialized via bit-pattern parity (use `memcpy` or equivalent to avoid UB).

Status note: landed as commit `50c5ef4` and merged via `de775c9`.

## Task 142 — Resources: implement `RESFILE_Decommit_Mapped_Memory` parity (VirtualFree MEM_DECOMMIT)
- [x] Assigned to agent
- [x] Finished
- Goal: replace the current no-op with the original behavior so mapped resource pages can be decommitted when requested.
- Implement: `RESFILE_Decommit_Mapped_Memory(uchar* ptr, int size)` @ 0x0047F590.
- Where: `src/game/src/Res_file.cpp`.
- Source of truth: `src/game/decomp/res_file.cpp.decomp` + `src/game/decomp/res_file.cpp.asm`.
- Done when: function calls `VirtualFree(ptr, size, 0x4000)` when `ptr != nullptr && size > 0`, returns the API result, otherwise returns 0.

Status note: landed as commit `0eb1ec4` and merged via `e315130`.

## Task 143 — Spanlist: add missing `TSpan_List_Manager` methods (DeleteSpan/Subtract/Merge/PointVisible)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the “additional methods when needed” TODO and restore the spanlist API used by visibility/clip logic.
- Implement (decomp-first transliteration):
  - `TSpan_List_Manager::SubtractMiniList(VSpanMiniList*, int, int)` @ 0x004BE240.
  - `TSpan_List_Manager::DeleteSpan(int, int, int)` @ 0x004BE290.
  - `TSpan_List_Manager::PointVisible(int, int)` @ 0x004BE5B0.
  - `TSpan_List_Manager::Merge_n_Align(TSpan_List_Manager*, TSpan_List_Manager*)` @ 0x004BE5F0.
- Where:
  - `src/game/src/spanlist.cpp`.
  - Add method declarations to `src/game/include/TSpan_List_Manager.h` (methods only; do not change member layout/size asserts).
- Source of truth: `src/game/decomp/spanlist.cpp.decomp` + `src/game/decomp/spanlist.cpp.asm`.
- Done when: the TODO marker in `spanlist.cpp` is removed/replaced and all four methods compile/link cleanly.

Status note: landed as commit `e78d303` and merged via `fcfbb51`.

---

## Task 144 — UI: fix `Time_Line_Panel::set_back_color` parity (no redraw side effects)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining “partial” mismatch so `set_back_color` matches the decomp exactly (no extra invalidation/side effects).
- Implement: `Time_Line_Panel::set_back_color(int fill_back, uchar back_color)` @ 0x0051F100.
- Where: `src/game/src/Time_Line_Panel.cpp`.
- Source of truth: `src/game/decomp/tpnl_tml.cpp.decomp` + `src/game/decomp/tpnl_tml.cpp.asm`.
- Done when: the function only stores the two fields and returns (no `set_redraw(...)` call), and build remains clean.

Status note: landed as commit `5aa6480` and merged via `8528fd6`.

## Task 145 — Startup: remove `main.cpp` GUID init “ASSUMPTION” by ASM-auditing the initializer block
- [ ] Assigned to agent
- [x] Finished
- Goal: eliminate the remaining GUID init assumption by matching the original assembly initialization exactly.
- Implement: audit the GUID values initialized in `main.cpp` (comment references ASM init @ 0x00454C17) and adjust the C++ constants/stores to match.
- Where: `src/game/src/main.cpp`.
- Source of truth: `src/game/decomp/main.cpp.asm` (GUID init block near 0x00454C17) + `src/game/decomp/main.cpp.decomp`.
- Done when: the GUID init comment no longer says ASSUMPTION, values/stores match ASM, and build remains clean.

Status note: landed as commit `4bc150f` (GUID init constants ASM-verified).

## Task 146 — Pathing: fix `RGE_Moving_Object::logDebug` virtual signature (printf-style varargs) parity
- [ ] Assigned to agent
- [x] Finished
- Goal: match the real vtable slot signature used by `PathingSystem::printState` so we don’t rely on unsafe function-pointer casts.
- Implement:
  - Update the virtual declaration for the vtable slot used at offset `0x144` to a printf-style varargs signature.
  - Update any forwarding stubs/derived overrides to match the signature so the project still links cleanly.
  - Optional: simplify `PathingSystem::printState` to call `obj->logDebug("...", ...)` directly once the signature is correct.
- Where:
  - Header(s): `src/game/include/RGE_Moving_Object.h` (and any base/derived headers if the virtual is inherited).
  - Implementations/stubs: `src/game/src/rge_object_virtual_stubs.cpp` only as needed for linkage.
  - Call site: `src/game/src/pathsys.cpp` (`PathingSystem::printState`).
- Source of truth: `src/game/decomp/pathsys.cpp.asm` @ 0x0046D784..0x0046D79C (vtable call pattern) + `src/game/decomp/pathsys.cpp.decomp`.
- Done when: the header signature matches the ASM reality, `printState` no longer needs a manual vtable-cast to call the logger, and build remains clean.

Status note: landed as commit `d0231de` and merged via `73641fc`.

## Task 147 — Basegame: de-stub the option-setter block + resolve remaining ASM-parity TODOs in `setup_fonts`
- [ ] Assigned to agent
- [x] Finished
- Goal: remove the remaining “TODO: STUB - Stubs for now” block marker and fix the last ASM-parity TODO note so basegame initialization is fully parity-backed.
- Implement:
  - Audit the `RGE_Base_Game::set*` option setters (the big setter block right after the destructor) against `basegame.cpp.decomp` and correct any subtle parity issues (sizes, string copy semantics, bit packing).
  - Remove/replace the “TODO: STUB - Stubs for now” marker once the block matches the decomp.
  - Resolve the `setup_fonts` `TODO(asm-parity)` note (line-height formula) by auditing `basegame.cpp.asm` stack-var mapping and updating the metric fields to match.
- Where: `src/game/src/basegame.cpp`.
- Source of truth: `src/game/decomp/basegame.cpp.decomp` + `src/game/decomp/basegame.cpp.asm`.
- Done when: those TODO markers are removed/replaced with verified markers where appropriate, and build remains clean.

Status note: landed as commit `2ff01c7` (basegame setters + setup_fonts parity).

## Task 148 — In-game screen: finish `TRIBE_Screen_Game` constructor resource/panel parity (remove “partial” notes)
- [ ] Assigned to agent
- [x] Finished
- Goal: complete the remaining constructor setup parity so all in-game UI panels/resources created in the original are created/initialized here too.
- Implement: audit the `TRIBE_Screen_Game::TRIBE_Screen_Game` constructor against `scr_game.cpp.decomp` and update the resource/panel creation blocks currently labeled “partial”.
- Where: `src/game/src/TRIBE_Screen_Game.cpp`.
- Source of truth: `src/game/decomp/scr_game.cpp.decomp` + `src/game/decomp/scr_game.cpp.asm`.
- Done when: the “partial” parity notes are removed (or replaced with verified markers), and build remains clean.

Status note: landed as commits `2286ee1` + `d939366`, merged via `4c1f618`.

---

## Task 149 — Multiplayer/lobby exit: implement `TRIBE_World::send_zone_score_info` parity (tworld)
- [ ] Assigned to agent
- [x] Finished
- Goal: restore the original lobby-launched quit-game score reporting (currently skipped in `TRIBE_Game::quit_game`).
- Implement: `TRIBE_World::send_zone_score_info()` @ 0x00531350.
- Where:
  - Add method declaration to `src/game/include/TRIBE_World.h` (methods only; do not change member layout/size asserts).
  - Implement in `src/game/src/TRIBE_World.cpp`.
  - Remove the “not yet transliterated” skip comment in `src/game/src/tribegam.cpp` inside `TRIBE_Game::quit_game` once the call is safe.
- Source of truth:
  - `src/game/decomp/tworld.cpp.decomp` + `src/game/decomp/tworld.cpp.asm` (function @ 0x00531350).
  - Call site reference: `src/game/decomp/tribegam.cpp.decomp` / `.asm` (`TRIBE_Game::quit_game` @ 0x00524150).
- Done when: the method compiles/links, `quit_game` calls it instead of skipping, and build remains clean.

Status note: landed as commit `e5f4de9` (`send_zone_score_info` parity wired into `quit_game`).

## Task 150 — Objects: implement doppleganger recycle path in `RGE_Master_Doppleganger_Object::make_new_obj` (m_dg_obj)
- [ ] Assigned to agent
- [x] Finished
- Goal: remove the remaining intentional parity defer so doppleganger objects recycle from the world’s reusable pool when enabled.
- Implement: `RGE_Master_Doppleganger_Object::make_new_obj(RGE_Player*, float, float, float, RGE_Static_Object*)` @ 0x004512D0.
- Where: `src/game/src/RGE_Master_Derived_Stubs.cpp` (and any required declarations in the relevant headers; do not change member layout/size asserts).
- Source of truth: `src/game/decomp/m_dg_obj.cpp.decomp` + `src/game/decomp/m_dg_obj.cpp.asm`.
- Notes:
  - Decomp shows a recycle path guarded by `this->field_0xa4 != 0` that calls `RGE_Game_World::recycle_object_in_to_game(param_1->world, this->field_0x4)` and then calls the recycled object’s vfunc at `+0x1EC` with `(this, player, x, y, z, existing_obj)`.
  - If recycle returns null, fall back to allocating a new `RGE_Doppleganger_Object` as currently.
- Done when: the “intentionally deferred” note is removed, recycle path matches decomp control flow, and build remains clean.

Status note: landed as commit `1c23acc`.

## Task 151 — World init: implement `RGE_Game_World::RGE_Game_World()` constructor parity (allocate object arrays + reusable lists)
- [ ] Assigned to agent
- [x] Finished
- Goal: match the original world constructor so core pointers/arrays/lists are allocated and defaults (game_state, random_seed, etc.) match the EXE.
- Implement: `RGE_Game_World::RGE_Game_World()` @ 0x00540750.
- Where: `src/game/src/RGE_Game_World.cpp` (+ header `src/game/include/RGE_Game_World.h` only if required for declarations).
- Source of truth: `src/game/decomp/world.cpp.decomp` + `src/game/decomp/world.cpp.asm`.
- Key parity requirements (see decomp for exact values/order):
  - Allocate `objectsValue` (max 10000) and `negativeObjectsValue` (max 1000) and assign `VIS_UNIT_objectsValue`.
  - Initialize `maximumComputerPlayerUpdateTime`, `availableComputerPlayerUpdateTime`, `currentUpdateComputerPlayer`, `difficultyLevelValue`.
  - Set `game_state = 2`, `random_seed = 0xE`, `curr_player = 1`, `next_reusable_object_id = -1`, and other scalar defaults per decomp.
  - Allocate all `reusable_*_objects` lists as `RGE_Object_List` instances.
  - Ensure the destructor path frees/deletes these allocations per decomp (avoid leaks/double-frees).
- Done when: ctor/dtor match the decomp’s allocation/initialization behavior closely enough that reusable-object APIs can be used without null-guards, and build remains clean.

Status note: landed as commit `3e99c9f`.

---

## Task 152 — Rendering follow-up: restore `TDrawArea::DrawShadowBox` >8bpp parity (remove disabled branch workaround)
- [ ] Assigned to agent
- [x] Finished
- Goal: remove the current forced-disabled >8bpp palette-remap branch and replace it with a decomp/ASM-backed implementation so menu/game shadowing is stable and parity-correct.
- Implement:
  - Audit `TDrawArea::DrawShadowBox` >8bpp path against source-of-truth and restore the intended behavior for 16/32bpp surfaces.
  - Eliminate the `if (0 && pal != nullptr)` workaround and replace it with real control flow.
  - Verify interaction with `RGE_Color_Table` runtime tables (including `id`/amount usage) so shadow intensity is deterministic.
- Where:
  - `src/game/src/Drawarea.cpp`
  - `src/game/src/RGE_Color_Table.cpp` (only if required by parity audit)
- Source of truth:
  - `src/game/decomp/drawarea.cpp.decomp` + `src/game/decomp/drawarea.cpp.asm`
  - `src/game/decomp/color.cpp.decomp` + `src/game/decomp/color.cpp.asm` (for table semantics used by shadowing)
- Done when: the disabled workaround is gone, `DrawShadowBox` is parity-implemented for active bpp modes, and build remains clean.

Status note: landed as commit `27ac8f9`.

## Task 153 — UI follow-up: finish `TEasy_Panel` popup-help/action parity and remove temporary cfg-dump hook
- [ ] Assigned to agent
- [x] Finished
- Goal: retire remaining non-original fallback behavior in `TEasy_Panel` that can mask UI regressions (popup-help action shim + temporary cfg dump instrumentation).
- Implement:
  - Replace the current `TEasy_Panel::action` “clear-only help mode” fallback with decomp-faithful `command_do_popup_help` routing behavior.
  - Remove or properly gate the temporary `scr1_cfg_dump.txt` dump hook in `TEasy_Panel::setup`.
  - Keep debug logging only where it has durable diagnostic value and matches project debug conventions.
- Where: `src/game/src/Panel_ez.cpp`
- Source of truth: `src/game/decomp/panel_ez.cpp.decomp` + `src/game/decomp/panel_ez.cpp.asm`
- Done when: the popup-help fallback TODO is removed/replaced by parity behavior, temporary dump hook is retired, and build remains clean.
- Status note: popup-help routing parity + cfg-dump cleanup landed (merge `agent/task-153-popup-help-action`, integration commit `4c85e3c`).

## Task 154 — View follow-up: replace remaining `RGE_View` best-effort interaction blocks with strict parity
- [ ] Assigned to agent
- [x] Finished
- Goal: remove high-risk “Best-effort transliteration” code still in core picking/outline paths, which can cause subtle UI/gameplay regressions.
- Implement (decomp-first, ASM-audit suspicious branches/signedness):
  - `RGE_View::view_function` parity.
  - `RGE_View::draw_object_outline` parity.
  - `RGE_View::draw_paint_brush` parity.
- Where:
  - `src/game/src/view.cpp`
  - `src/game/include/RGE_View.h` (declarations only if needed; do not change layout asserts)
- Source of truth: `src/game/decomp/view.cpp.decomp` + `src/game/decomp/view.cpp.asm`
- Done when: the listed methods no longer carry “Best-effort transliteration” markers and build remains clean.
- Status note: view interaction parity pass landed (merge `agent/task-154-view-strict-parity`, implement commit `d0ac1a7`).

## Task 155 — View wrapper follow-up: remove remaining `RGE_Main_View.cpp` best-effort parity debt
- [ ] Assigned to agent
- [x] Finished
- Goal: finish parity in `RGE_Main_View` so scrolling/interaction wrappers do not rely on unresolved best-effort approximations.
- Implement:
  - Audit every method in `RGE_Main_View.cpp` still marked “Best-effort transliteration” and replace with decomp/ASM-correct control flow.
  - Ensure any helper interactions with `RGE_View` remain consistent with current main-view call patterns.
- Where:
  - `src/game/src/RGE_Main_View.cpp`
  - `src/game/include/RGE_Main_View.h` (declarations only if needed; do not change layout asserts)
- Source of truth: `src/game/decomp/vw_main.cpp.decomp` + `src/game/decomp/vw_main.cpp.asm`
- Done when: no remaining best-effort markers in `RGE_Main_View.cpp` for implemented methods, and build remains clean.
- Status note: main-view wrapper parity follow-up landed (merge `agent/task-155-main-view-followup`, implement commit `08294d8`).

## Task 156 — Lobby/network follow-up: remove `RGE_Lobby::Init` best-effort player-enum shim
- [ ] Assigned to agent
- [x] Finished
- Goal: replace the current diagnostics-only player enumeration in lobby connect flow with parity-correct behavior from the original executable.
- Implement:
  - Audit `RGE_Lobby::Init` connect/setup flow and remove the “Best-effort: enumerate players for diagnostics” shim.
  - Restore original success/failure handling around lobby connection + interface setup as shown in decomp/ASM.
- Where: `src/game/src/com_loby.cpp`
- Source of truth: `src/game/decomp/com_loby.cpp.decomp` + `src/game/decomp/com_loby.cpp.asm`
- Done when: the best-effort shim comment/behavior is gone, flow matches source-of-truth control flow, and build remains clean.
- Status note: lobby launch flow parity restored (merge `agent/task-156-lobby-init-parity`, implement commit `6700240`).

## Task 157 — UI core follow-up: replace non-original `TPanel::draw_tree` helper with panel-system parity
- [ ] Assigned to agent
- [x] Finished
- Goal: remove the current non-original draw-tree recursion helper and restore the original panel-system draw traversal behavior so visibility/activation/child ordering side effects match the EXE.
- Implement:
  - Audit `TPanel::draw_tree` against decomp/ASM expectations from the panel unit and connected draw/paint call sites.
  - Replace the current non-original gating/recursion helper with parity-correct control flow.
  - Verify related callers in screen/basegame paint path still route correctly after the change.
- Where:
  - `src/game/src/TPanel.cpp`
  - `src/game/src/basegame.cpp` or `src/game/src/tribegam.cpp` only if call-site alignment is required by parity audit.
- Source of truth:
  - `src/game/decomp/panel.cpp.decomp` + `src/game/decomp/panel.cpp.asm`
  - Related call-site references in `src/game/decomp/basegame.cpp.decomp` / `tribegam.cpp.decomp`.
- Done when: the `TPanel::draw_tree` non-original TODO/STUB note is resolved with parity logic and build remains clean.
- Status note: draw-tree panel traversal parity landed (merge `agent/task-157-draw-tree-parity`, implement commit `6d36f5e`).

## Task 158 — Random-map follow-up: replace non-original `rmm_smooth_elevation` stabilization pass
- [ ] Assigned to agent
- [x] Finished
- Goal: remove the non-original elevation smoothing shim in the random-map database controller and restore source-of-truth terrain/elevation transition behavior.
- Implement:
  - Audit the random-map elevation/tile-type transition sequence where `rmm_smooth_elevation` is used.
  - Replace/remove the non-original smoothing pass with decomp/ASM-backed logic from the correct RMM modules/controller path.
  - Confirm terrain/tile-type seams are handled by original logic, not post-hoc smoothing.
- Where:
  - `src/game/src/TRIBE_RMM_Database_Controller.cpp`
  - Any required `rmm_*` generator source files directly referenced by the audited flow.
- Source of truth:
  - `src/game/decomp/TRIBE_RMM_Database_Controller`-related decomp/ASM units in `src/game/decomp/`
  - Core random-map modules: `src/game/decomp/rmm_*.cpp.decomp` + corresponding `.asm`.
- Done when: the non-original smoothing TODO/STUB note is removed/replaced by parity-backed behavior and build remains clean.
- Status note: non-original elevation smoothing pass removed in favor of parity flow (merge `agent/task-158-rmm-smooth-elevation`, implement commit `32d9708`).

## Task 159 — MP setup follow-up: retire temporary UI-control scaffolding comments/logic in `scr_mps_impl`
- [ ] Assigned to agent
- [x] Finished
- Goal: ensure MP setup screen constructor/action paths no longer rely on temporary UI scaffolding assumptions and match `scr_mps` parity cleanly.
- Implement:
  - Audit the constructor/setup block around player/summary/settings controls and remove remaining temporary-scaffold behavior/comments that do not match source-of-truth.
  - Keep only real `scr_mps`-parity control creation and flow (settings button / dropdowns / summary updates).
  - Verify no stale fallback-only paths remain in the touched MP setup routines.
- Where: `src/game/src/scr_mps_impl.cpp`
- Source of truth: `src/game/decomp/scr_mps.cpp.decomp` + `src/game/decomp/scr_mps.cpp.asm`
- Done when: temporary-scaffold TODO/STUB note is resolved by parity-backed implementation and build remains clean.
- Status note: temporary MP setup scaffolding retired (merge `task 159 MP setup scaffolding cleanup`, implement commit `fc35d6c`).

## Task 160 — In-game bottom panel parity: finish `TRIBE_Panel_Object` information/layout rendering
- [ ] Assigned to agent
- [x] Finished
- Goal: restore object-info panel behavior in-game so selected-unit/building details, stats, and icon regions render with original parity (eliminates one major source of “missing bottom panel” visuals).
- Implement:
  - Complete `TRIBE_Panel_Object` constructor/startup/draw/update behavior from source-of-truth (do not leave partial placeholders).
  - Ensure selected object state transitions (unit/building/no-selection) and cached fields refresh exactly as decomp/ASM flow dictates.
  - Keep existing memory layout/vtable intact; declarations-only header edits allowed.
- Scope guard (independence): touch only panel-object files; do **not** modify `TRIBE_Screen_Game.cpp` in this task.
- Where:
  - `src/game/src/TRIBE_Panel_Object.cpp`
  - `src/game/include/TRIBE_Panel_Object.h` (declarations only if required)
- Source of truth: `src/game/decomp/tpnl_obj.cpp.decomp` + `src/game/decomp/tpnl_obj.cpp.asm`
- Done when: panel-object TODO/STUB markers are resolved with parity-backed logic and build remains clean.

Status note: landed as commit `d118c33` and merged via `4ad20d5`.

## Task 161 — In-game inventory strip parity: finish `TRIBE_Panel_Inven` resource/icon rendering
- [ ] Assigned to agent
- [x] Finished
- Goal: restore inventory/resource strip rendering in-game so the bottom UI no longer appears partially blank/incomplete.
- Implement:
  - Complete `TRIBE_Panel_Inven` setup/draw/update logic from source-of-truth (resource entries, icon handling, redraw conditions).
  - Verify player-switch and redraw behavior follows original control flow (no ad-hoc refresh hacks).
  - Keep member layout untouched; header edits declarations-only.
- Scope guard (independence): only inventory panel files; do **not** modify `TRIBE_Panel_Object.cpp` or `TRIBE_Screen_Game.cpp`.
- Where:
  - `src/game/src/TRIBE_Panel_Inven.cpp`
  - `src/game/include/TRIBE_Panel_Inven.h` (declarations only if required)
- Source of truth: `src/game/decomp/tpnl_inv.cpp.decomp` + `src/game/decomp/tpnl_inv.cpp.asm`
- Done when: inventory panel TODO/STUB markers are resolved with parity-backed logic and build remains clean.
- Status note: inventory strip parity landed (merge `agent/task-161-inven-strip`, implement commit `747cb7d`).

## Task 162 — Clock/population panel parity: finish `TRIBE_Panel_Time` + `TRIBE_Panel_Pop`
- [ ] Assigned to agent
- [x] Finished
- Goal: restore top/bottom HUD counters (clock/population) so game HUD text blocks are fully painted and synchronized with player/world state.
- Implement:
  - Complete `TRIBE_Panel_Time` parity for startup, clock mode/format handling, and draw/update cadence.
  - Complete `TRIBE_Panel_Pop` parity for player binding, population/max-pop updates, and rendering behavior.
  - Keep rendering and redraw triggers faithful to decomp/ASM (no periodic-force-redraw hacks).
- Scope guard (independence): only time/pop panel files; do **not** modify `TRIBE_Screen_Game.cpp`.
- Where:
  - `src/game/src/TRIBE_Panel_Time.cpp`
  - `src/game/src/TRIBE_Panel_Pop.cpp`
  - corresponding headers for declarations only if required
- Source of truth:
  - `src/game/decomp/tpnl_tim.cpp.decomp` + `src/game/decomp/tpnl_tim.cpp.asm`
  - `src/game/decomp/tpnl_pop.cpp.decomp` + `src/game/decomp/tpnl_pop.cpp.asm`
- Done when: time/pop TODO/STUB markers are resolved with parity-backed logic and build remains clean.
- Status note: time/pop panel parity landed (merge `agent/task-162-clock-pop-parity`, implement commit `171c456`).

## Task 163 — Minimap visual parity: audit/fix `RGE_Diamond_Map` bitmap + paint pipeline
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore in-game minimap rendering/parity (background image, explored overlays, object dots, and view rectangle) to remove “missing/minimal minimap” behavior.
- Implement:
  - Audit `set_bitmap`, `draw`, and `draw_all` paths for parity-correct bitmap ownership/loading and repaint behavior.
  - Verify explored-tile/object plotting and viewport rectangle drawing match source-of-truth control flow.
  - Fix only minimap module logic; avoid unrelated UI composition edits.
- Scope guard (independence): touch minimap view files only; do **not** modify `TRIBE_Screen_Game.cpp` unless strictly required by parity call signatures.
- Where:
  - `src/game/src/RGE_Diamond_Map.cpp`
  - `src/game/include/RGE_Diamond_Map.h` (declarations only if required)
- Source of truth: `src/game/decomp/diam_map.cpp.decomp` + `src/game/decomp/diam_map.cpp.asm`
- Done when: minimap parity issues are resolved in-module, TODO markers (if any) are closed, and build remains clean.

## Task 164 — World seam artifact parity: audit/fix terrain shape blit in `TShape`
- [ ] Assigned to agent
- [x] Finished
- Goal: eliminate black outline seams between isometric terrain cells by restoring terrain-shape draw parity in the shape renderer.
- Implement:
  - Audit terrain-related `TShape` draw/span/color-key paths used by ground tiles in 8-bit and 32-bit display paths.
  - Compare suspicious blend/skip conditions against ASM (signedness, run-length decode, transparency handling) and correct parity mismatches.
  - Keep changes constrained to shape rendering code; do not add non-original smoothing/fill hacks.
- Scope guard (independence): only shape renderer files; avoid `view.cpp` edits in this task to prevent overlap with existing view-focused work.
- Where:
  - `src/game/src/TShape.cpp`
  - `src/game/include/TShape.h` (declarations only if required)
- Source of truth: `src/game/decomp/shape.cpp.decomp` + `src/game/decomp/shape.cpp.asm`
- Done when: terrain seam artifact parity fix is in place without hacks and build remains clean.
- Status note: terrain seam outline parity landed (merge `task 164 TShape terrain seam parity fix`, implement commit `3a26fde`).

---

## Task 165 — Static-object command parity: de-stub command responder virtuals in `RGE_Static_Object`
- [x] Finished
- Goal: remove linker-satisfaction command responder behavior in core static-object gameplay paths so command dispatch no longer dead-ends at placeholder returns.
- Implement: de-stub `RGE_Static_Object` command responder virtuals and wire parity control flow from decomp/ASM.
- Where:
  - `src/game/src/RGE_Static_Object.cpp`
  - `src/game/include/RGE_Static_Object.h` (declarations only if required)
- Source of truth: `src/game/decomp/stat_obj.cpp.decomp` + `src/game/decomp/stat_obj.cpp.asm`
- Done when: the targeted command responder methods no longer rely on placeholder stub behavior and build remains clean.
- Status note: landed (merge `task 165 static object command parity`, implement commit `27d4149`).

## Task 166 — TRIBE game-loop control-flow parity cleanup in `tribegam.cpp`
- [x] Finished
- Goal: remove non-original in-game control-flow fallbacks from TRIBE game runtime loop handlers and align key dispatch paths with source-of-truth.
- Implement:
  - restore base-handler parity for `handle_key_down` / `handle_paint` vtable-forwarded paths.
  - remove non-original DEBUGLOAD helper stub path and keep scoped debug dump behavior in parity branch.
  - restore lobby quit branch zone-score send call path.
- Where: `src/game/src/tribegam.cpp`
- Source of truth: `src/game/decomp/tribegam.cpp.decomp` + `src/game/decomp/tribegam.cpp.asm`
- Done when: non-original fallback branches in the scoped control-flow paths are retired and build remains clean.
- Status note: landed (merge `agent/task-166-tribegam-control-flow`, implement commit `6b0a4e9`).

## Task 167 — Base-game startup parity: finalize setup failure-code flow and helper de-stubs
- [x] Finished
- Goal: harden startup failure signaling and remove remaining basegame helper stubs in the setup path.
- Implement:
  - finalize setup failure-code propagation in `RGE_Base_Game::setup` call chain.
  - replace remaining helper placeholders required by startup/control flow.
- Where:
  - `src/game/src/basegame.cpp`
  - `src/game/include/RGE_Base_Game.h` (declarations only if required)
- Source of truth: `src/game/decomp/basegame.cpp.decomp` + `src/game/decomp/basegame.cpp.asm`
- Done when: setup failure codes and touched helper behaviors follow source-of-truth control flow and build remains clean.
- Status note: landed (merge `agent/task-167-basegame-parity`, implement commit `9a373c8`).

## Task 168 — Startup parity cleanup: remove non-original WinMain exception hook
- [x] Finished
- Goal: remove non-original startup exception handling behavior from WinMain path and align startup control flow with source-of-truth.
- Implement: retire the custom WinMain exception hook and keep only parity-backed startup/error flow.
- Where: `src/game/src/main.cpp`
- Source of truth: `src/game/decomp/main.cpp.decomp` + `src/game/decomp/main.cpp.asm`
- Done when: WinMain startup flow no longer contains the non-original exception hook and build remains clean.
- Status note: landed (merge `Task 168 startup parity cleanup`, implement commit `d2e29f1`).

## Task 169 — Virtual-stub logging parity: fix variadic forwarding in `logDebug` bridge
- [x] Finished
- Goal: preserve variadic argument formatting when forwarding derived `logDebug(...)` calls through object virtual forwarding stubs.
- Implement: correct varargs forwarding so formatted messages survive through the forwarding bridge.
- Where: `src/game/src/rge_object_virtual_stubs.cpp`
- Source of truth: call signatures in headers + runtime behavior expected by debug log call sites.
- Done when: forwarded `logDebug` calls retain argument formatting correctly and build remains clean.
- Status note: landed (merge `agent/task-169-logdebug-forwarding for Task 169`, implement commit `a262071`).

## Task 170 — TRIBE_Player command issuer parity for in-game main-view commands
- [x] Finished
- Goal: restore command emission parity in `TRIBE_Player` so key in-game issued commands no longer hard-fail through stub returns.
- Implement:
  - `command_make_building`
  - `command_attack_ground`
  - `command_make_repair`
  - `command_make_unload`
- Where: `src/game/src/TRIBE_Player.cpp`
- Source of truth: `src/game/decomp/tplayer.cpp.decomp` + `src/game/decomp/tplayer.cpp.asm`
- Done when: scoped command issuer methods are parity-backed (no hard-fail placeholder returns) and build remains clean.
- Status note: landed (merge `agent/task170-player-command-parity`, implement commit `0a4db97`).

---

## Task 171 — View visibility parity: implement `RGE_View::Object_Was_Displayed` for in-view multi-select
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore visibility-filtered unit selection behavior used by TRIBE main-view double-click selection.
- Implement:
  - Transliterate `RGE_View::Object_Was_Displayed(long object_id, int param_2)` from source-of-truth.
  - Audit `TRIBE_Main_View::mouse_left_dbl_click_action` call-site behavior and make only minimal parity fixes if required.
- Scope guard (independence): touch `view.cpp` (and `TRIBE_Main_View.cpp` only if strictly required by parity call-site behavior).
- Where:
  - `src/game/src/view.cpp`
  - `src/game/src/TRIBE_Main_View.cpp` (only if required)
  - corresponding headers for declarations only if required
- Source of truth:
  - `src/game/decomp/view.cpp.decomp` + `src/game/decomp/view.cpp.asm`
  - call-site context in `src/game/decomp/tvw_main.cpp.decomp` (`Object_Was_Displayed` usage)
- Done when: the hardcoded `return false` stub is gone, function follows decomp-backed logic, and visible same-type double-click selection path compiles cleanly.

## Task 172 — TRIBE_Game runtime hook parity: restore panel accessors + gameplay notification routing
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore core TRIBE game hooks used during in-game runtime updates so panel lookups and world-driven notifications work in single-player gameplay.
- Implement:
  - `TRIBE_Game::get_view_panel` @ 0x00523450.
  - `TRIBE_Game::get_map_panel` @ 0x005234A0.
  - `TRIBE_Game::gameSummary` @ 0x00529570.
  - Notification parity slice in `TRIBE_Game::notification` @ 0x00524D70 for in-game world-driven events (at minimum the artifact/ruin hold/loss notification path used by `TRIBE_World::check_game_state`).
- Scope guard (independence): this task is limited to `tribegam.cpp` runtime hook/notification logic; do **not** include `processCheatCode` or MP options send/receive in this task.
- Where:
  - `src/game/src/tribegam.cpp`
  - `src/game/include/TRIBE_Game.h` (declarations only if required)
- Source of truth: `src/game/decomp/tribegam.cpp.decomp` + `src/game/decomp/tribegam.cpp.asm`
- Done when: panel accessor stubs are removed, `gameSummary` follows source behavior, notification routing for the scoped cases is parity-backed, and build remains clean.

## Task 173 — In-game UI main-loop parity phase 1: expand `TRIBE_Screen_Game::handle_game_update`
- [ ] Assigned to agent
- [ ] Finished
- Goal: close major runtime parity debt in `handle_game_update` so in-game UI update cadence follows decomp flow rather than the current minimal slice.
- Implement:
  - Add update-interval throttling and timing-driven redraw cadence from decomp.
  - Restore score/age refresh timing checks and main/map redraw scheduling logic that currently does not run.
  - Restore scoped game-over/pause UI transition handling present in the 0x00496800 flow, without introducing non-original shortcuts.
- Scope guard (independence): touch `TRIBE_Screen_Game.cpp` only; do **not** modify `tribegam.cpp` in this task.
- Where: `src/game/src/TRIBE_Screen_Game.cpp`
- Source of truth: `src/game/decomp/scr_game.cpp.decomp` + `src/game/decomp/scr_game.cpp.asm` (`handle_game_update` @ 0x00496800)
- Done when: `handle_game_update` is no longer a narrow slice and includes the decomp-backed update cadence branches for the scoped behavior, with clean build.

## Task 174 — Static-object gameplay command parity phase 1: replace core command no-op stubs
- [ ] Assigned to agent
- [ ] Finished
- Goal: remove the highest-impact no-op command responders in `RGE_Static_Object` so player-issued object commands stop collapsing to immediate failures.
- Implement (decomp-first, ASM-audit suspicious branches):
  - command responders near the command-virtual block (`attack` overloads, `moveTo` overloads, `gather`, `repair`, `build`, `trade`, `explore`, `enter`, `unload`, `transport`, `stopAction`, `pause`).
  - supporting command-state checks needed by those methods (`can_attack`, `inAttackRange`) for consistent behavior.
- Scope guard (independence): touch only static-object implementation/declarations; do **not** edit `rge_object_virtual_stubs.cpp` in this task.
- Where:
  - `src/game/src/RGE_Static_Object.cpp`
  - `src/game/include/RGE_Static_Object.h` (declarations only if required)
- Source of truth: `src/game/decomp/stat_obj.cpp.decomp` + `src/game/decomp/stat_obj.cpp.asm`
- Done when: listed methods no longer hard-return placeholder values, and compile remains clean without new fallback stubs.

## Task 175 — Animated-object parity phase 1: retire forwarding stubs for core command overrides
- [ ] Assigned to agent
- [ ] Finished
- Goal: reduce runtime dependence on `rge_object_virtual_stubs.cpp` by implementing real `RGE_Animated_Object` command override behavior for core gameplay commands.
- Implement:
  - Transliterate core `RGE_Animated_Object` command override methods currently forwarded in stub file (attack/move/work command family and related pause/stop behavior where present in decomp).
  - Remove only the corresponding forwarding entries from `rge_object_virtual_stubs.cpp` once real implementations exist.
- Scope guard (independence): this task is `RGE_Animated_Object`-only; do **not** edit `RGE_Moving_Object` or `RGE_Static_Object` command logic here.
- Where:
  - `src/game/src/RGE_Animated_Object.cpp`
  - `src/game/src/rge_object_virtual_stubs.cpp`
  - `src/game/include/RGE_Animated_Object.h` (declarations only if required)
- Source of truth:
  - `src/game/decomp/ani_obj.cpp.decomp`
  - `src/game/decomp/RGE_Animated_Object.decomp`
  - `src/game/decomp/m_an_obj.cpp.decomp`
  - corresponding ASM exports in `src/game/decomp/*.asm`
- Done when: scoped animated-object command overrides are real implementations (not forwarding stubs), matching decomp control flow and compiling cleanly.

## Task 176 — World runtime parity follow-up: restore missing `RGE_Game_World` constructor/destructor log lifecycle
- [ ] Assigned to agent
- [ ] Finished
- Goal: close the remaining explicit parity gaps in `RGE_Game_World` runtime lifecycle that are still annotated as TODO in constructor/destructor paths.
- Implement:
  - restore constructor-side `DVlogf`/status-file open behavior per source-of-truth.
  - restore destructor-side close behavior for world log/status handles.
  - keep error handling parity-consistent and avoid adding non-original silent fallbacks.
- Scope guard (independence): touch only `RGE_Game_World` lifecycle code; do **not** modify TRIBE-layer world logic in this task.
- Where: `src/game/src/RGE_Game_World.cpp`
- Source of truth: `src/game/decomp/world.cpp.decomp` + `src/game/decomp/world.cpp.asm` (constructor/destructor sections)
- Done when: the two existing explicit parity TODO notes in `RGE_Game_World.cpp` are resolved and build remains clean.
