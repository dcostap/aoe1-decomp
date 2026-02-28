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

Status note: tvw_main parity landed in commit `ae7a1af` and merged via `3f871ae`; `TRIBE_Main_View.cpp` now carries fully verified implementations with no remaining TODO/STUB markers.

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

Status note: landed as commit `bd83ac2` and merged via `b143987`; `DriveInformation.cpp` now contains the full `file_stf` method set.

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

Status note: landed as commit `4bc150f` and merged via `d77da6e`.

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

Status note: landed as commit `d0231de` and merged via `73641fc`; `PathingSystem::printState` now calls `obj->logDebug(...)` directly.

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

Status note: landed as commit `2ff01c7` and merged via `0c9d7e4`.

## Task 148 — In-game screen: finish `TRIBE_Screen_Game` main-loop parity (constructor + runtime handlers)
- [ ] Assigned to agent
- [x] Finished
- Goal: complete remaining `TRIBE_Screen_Game` parity that directly affects in-game loop behavior (view wiring, per-player rebinding, pause/resume, and command panel refresh).
- Implement:
  - Audit `TRIBE_Screen_Game::TRIBE_Screen_Game` against `scr_game.cpp.decomp` and finish remaining constructor setup parity.
  - Complete parity for currently partial runtime methods:
    - `handle_game_update()` @ 0x00496800
    - `game_mode_changed()` @ 0x00498A10
    - `player_changed()` @ 0x00498A50
    - `handle_pause()` @ 0x004972A0
    - `handle_resume()` @ 0x004972F0
    - `setup_buttons()` @ 0x004996C0
- Where: `src/game/src/TRIBE_Screen_Game.cpp`.
- Source of truth: `src/game/decomp/scr_game.cpp.decomp` + `src/game/decomp/scr_game.cpp.asm`.
- Done when: the remaining TODO/STUB parity notes in `TRIBE_Screen_Game.cpp` are removed or replaced with verified markers, and build remains clean.

Status note: runtime parity completed in commit `d939366` and merged via `4c1f618`; `TRIBE_Screen_Game.cpp` no longer carries TODO/STUB markers for the scoped handlers.

---

## Task 149 — Multiplayer/lobby exit: implement `TRIBE_World::send_zone_score_info` parity (tworld)
- [ ] Assigned to agent
- [x] Finished
- Goal: restore the original zone-score packet build/send logic in `TRIBE_World` so lobby score reporting has a real source-of-truth implementation.
- Implement: `TRIBE_World::send_zone_score_info()` @ 0x00531350.
- Where:
  - Add method declaration to `src/game/include/TRIBE_World.h` (methods only; do not change member layout/size asserts).
  - Implement in `src/game/src/TRIBE_World.cpp`.
- Source of truth:
  - `src/game/decomp/tworld.cpp.decomp` + `src/game/decomp/tworld.cpp.asm` (function @ 0x00531350).
  - Call-site references: `tribegam.cpp` / `com_hand.cpp` / `scr_game.cpp` decomp+asm units that invoke `send_zone_score_info`.
- Done when: the method compiles/links and matches tworld control flow (`fill_in_score` + zone message send path); call-site wiring is tracked separately to keep pending tasks file-isolated.

Status note: implementation landed in commit `e5f4de9` and merged via `a000854`; `TRIBE_World::send_zone_score_info` is now fully verified in `TRIBE_World.cpp`.

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

Status note: recycle path landed in commit `1c23acc` and merged via `8a869bc`; `RGE_Master_Doppleganger_Object::make_new_obj(..., RGE_Static_Object*)` is marked fully verified.

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

Status note: constructor/list-allocation parity landed in commit `3e99c9f` and merged via `710a91d`; follow-up logging-handle parity is tracked separately (Task 173).

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

Status note: >8bpp shadow path landed in commit `27ac8f9` and merged via `4850aee`; the disabled `if (0 && pal != nullptr)` workaround is gone.

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

Status note: popup-help parity landed in commit `2240384` and merged via `4c85e3c`; `command_do_popup_help` is now wired and the temporary cfg-dump hook is retired.

## Task 154 — View follow-up: replace remaining `RGE_View` best-effort interaction blocks with strict parity
- [x] Assigned to agent
- [x] Finished
- Goal: remove high-risk “Best-effort transliteration” code still in core picking/outline paths, which can cause subtle UI/gameplay regressions.
- Implement (decomp-first, ASM-audit suspicious branches/signedness):
  - `RGE_View::view_function` parity.
  - `RGE_View::draw_object_outline` parity.
  - `RGE_View::draw_paint_brush` parity.
  - `RGE_View::Object_Was_Displayed` parity (remove the current hard stub).
- Where:
  - `src/game/src/view.cpp`
  - `src/game/include/RGE_View.h` (declarations only if needed; do not change layout asserts)
- Source of truth: `src/game/decomp/view.cpp.decomp` + `src/game/decomp/view.cpp.asm`
- Done when: the listed methods no longer carry “Best-effort transliteration” markers, `Object_Was_Displayed` is no longer a hard stub, and build remains clean.

Status note: landed in commit `d0ac1a7` and merged via `0b81364`; remaining view gaps are tracked in Task 174.

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

Status note: wrapper parity landed in commit `08294d8` and merged via `12277f7`; `RGE_Main_View.cpp` no longer contains best-effort TODO/STUB markers.

## Task 156 — Lobby/network follow-up: remove `RGE_Lobby::Init` best-effort player-enum shim
- [x] Assigned to agent
- [x] Finished
- Goal: replace the current diagnostics-only player enumeration in lobby connect flow with parity-correct behavior from the original executable.
- Implement:
  - Audit `RGE_Lobby::Init` connect/setup flow and remove the “Best-effort: enumerate players for diagnostics” shim.
  - Restore original success/failure handling around lobby connection + interface setup as shown in decomp/ASM.
- Where: `src/game/src/com_loby.cpp`
- Source of truth: `src/game/decomp/com_loby.cpp.decomp` + `src/game/decomp/com_loby.cpp.asm`
- Done when: the best-effort shim comment/behavior is gone, flow matches source-of-truth control flow, and build remains clean.

Status note: landed in commit `6700240` and merged via `650c9d3`.

## Task 157 — UI core follow-up: replace non-original `TPanel::draw_tree` helper with panel-system parity
- [x] Assigned to agent
- [x] Finished
- Goal: remove the current non-original draw-tree recursion helper and restore the original panel-system draw traversal behavior so visibility/activation/child ordering side effects match the EXE.
- Implement:
  - Audit `TPanel::draw_tree` against decomp/ASM expectations from the panel unit and connected draw/paint call sites.
  - Replace the current non-original gating/recursion helper with parity-correct control flow.
  - Keep this task isolated to panel code (do not edit basegame/tribegam call sites here).
- Where:
  - `src/game/src/TPanel.cpp`
- Source of truth:
  - `src/game/decomp/panel.cpp.decomp` + `src/game/decomp/panel.cpp.asm`
- Dependency note: should land before Tasks 160/161/162 so panel draw traversal semantics are stable for in-game HUD panel audits.
- Done when: the `TPanel::draw_tree` non-original TODO/STUB note is resolved with parity logic and build remains clean.

Status note: landed in commit `6d36f5e` and merged via `aaae6eb`.

## Task 158 — Random-map follow-up: replace non-original `rmm_smooth_elevation` stabilization pass
- [x] Assigned to agent
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

Status note: landed in commit `32d9708` and merged via `5ea04b4`.

## Task 159 — MP setup follow-up: retire temporary UI-control scaffolding comments/logic in `scr_mps_impl`
- [x] Assigned to agent
- [x] Finished
- Goal: ensure MP setup screen constructor/action paths no longer rely on temporary UI scaffolding assumptions and match `scr_mps` parity cleanly.
- Implement:
  - Audit the constructor/setup block around player/summary/settings controls and remove remaining temporary-scaffold behavior/comments that do not match source-of-truth.
  - Keep only real `scr_mps`-parity control creation and flow (settings button / dropdowns / summary updates).
  - Verify no stale fallback-only paths remain in the touched MP setup routines.
- Where: `src/game/src/scr_mps_impl.cpp`
- Source of truth: `src/game/decomp/scr_mps.cpp.decomp` + `src/game/decomp/scr_mps.cpp.asm`
- Done when: temporary-scaffold TODO/STUB note is resolved by parity-backed implementation and build remains clean.

Status note: landed in commit `fc35d6c` and merged via `68aec26`.

## Task 160 — In-game bottom panel parity: finish `TRIBE_Panel_Object` information/layout rendering
- [x] Assigned to agent
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
- Dependency note: complete Task 157 first so panel draw-tree traversal is parity-correct before panel-object draw/update auditing.
- Done when: panel-object TODO/STUB markers are resolved with parity-backed logic and build remains clean.

Status note: landed in commit `d118c33` and merged via `4ad20d5`.

## Task 161 — In-game inventory strip parity: finish `TRIBE_Panel_Inven` resource/icon rendering
- [x] Assigned to agent
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
- Dependency note: complete Task 157 first so panel draw-tree traversal is parity-correct before inventory draw/update auditing.
- Done when: inventory panel TODO/STUB markers are resolved with parity-backed logic and build remains clean.

Status note: landed in commit `747cb7d` and merged via `af6e8af`.

## Task 162 — Clock/population panel parity: finish `TRIBE_Panel_Time` + `TRIBE_Panel_Pop`
- [x] Assigned to agent
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
- Dependency note: complete Task 157 first so panel draw-tree traversal is parity-correct before clock/pop draw/update auditing.
- Done when: time/pop TODO/STUB markers are resolved with parity-backed logic and build remains clean.

Status note: landed in commit `171c456` and merged via `d3645b9`.

## Task 163 — Minimap visual parity: audit/fix `RGE_Diamond_Map` bitmap + paint pipeline
- [ ] Assigned to agent
- [x] Finished
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

Status note: retired as obsolete. `RGE_Diamond_Map.cpp` already carries full verified coverage across `set_bitmap`/`draw`/`draw_all`; remaining minimap symptoms are tracked under `TRIBE_Screen_Game` / main-view wiring tasks.

## Task 164 — World seam artifact parity: audit/fix terrain shape blit in `TShape`
- [x] Assigned to agent
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

Status note: landed in commit `3a26fde` and merged via `f3b8011`.

---

## Task 165 — Object command parity: de-stub `RGE_Static_Object` command responders used in gameplay loop
- [x] Assigned to agent
- [x] Finished
- Goal: remove empty/default command virtuals in `RGE_Static_Object` that can short-circuit in-game selection/command behavior for non-combat/static entities.
- Implement (decomp-first transliteration):
  - `RGE_Static_Object::do_command(...)`
  - `RGE_Static_Object::move_to(...)`
  - `RGE_Static_Object::work(...)`
  - `RGE_Static_Object::stop()`
  - `RGE_Static_Object::set_attack(...)`
  - `RGE_Static_Object::get_command_master(...)`
  - plus `notify_of_relation(...)` / `new_angle(...)` if they remain empty after parity audit.
- Where:
  - `src/game/src/RGE_Static_Object.cpp`
  - `src/game/include/RGE_Static_Object.h` (declarations only if required; do not change layout/vtable order)
- Source of truth: `src/game/decomp/stat_obj.cpp.decomp` + `src/game/decomp/stat_obj.cpp.asm`.
- Done when: these methods are no longer empty `{}` / `return nullptr` placeholders, match decomp control flow, and build remains clean.

Status note: landed in commit `27d4149` and merged via `6278b1c`; remaining non-command virtual gaps are tracked in Task 179.

## Task 166 — In-game control-flow parity in `tribegam`: ESC/menu path + DEBUGLOAD + handle_paint + lobby score call-site
- [x] Assigned to agent
- [x] Finished
- Goal: remove remaining non-original gameplay-loop control-flow in `TRIBE_Game` that affects in-game behavior and diagnostics paths.
- Implement:
  - Restore `TRIBE_Game::handle_key_down` ESC behavior to decomp parity (menu/dialog path), replacing the direct `start_menu()` fallback.
  - Retire `tribe_write_debugload_dump` + DEBUGLOAD branch stubs in load-game flow by matching `tribegam` source-of-truth behavior.
  - Restore `TRIBE_Game::handle_paint` control flow by removing the current non-original input-enable/draw-tree fallback sequence when it diverges from decomp message-paint behavior.
  - In `TRIBE_Game::quit_game`, wire the lobby branch to call `world->send_zone_score_info()` once Task 149 lands.
- Where: `src/game/src/tribegam.cpp` only.
- Source of truth: `src/game/decomp/tribegam.cpp.decomp` + `src/game/decomp/tribegam.cpp.asm` (plus call-site references to `send_zone_score_info`).
- Dependency note: Task 149 is now complete (`a000854`); this task owns the remaining `tribegam.cpp` call-site/control-flow parity.
- Done when: TODO/STUB notes in `tribegam.cpp` DEBUGLOAD path are removed, ESC fallback comment/path is gone, `handle_paint` matches source-of-truth control flow, and build remains clean.

Status note: landed in commit `6b0a4e9` and merged via `d9e4a26`; remaining user-command routing is tracked in Task 175.

## Task 167 — Basegame parity follow-up: finalize `setup()` failure-code mapping + de-stub input/audio helpers
- [x] Assigned to agent
- [x] Finished
- Goal: close remaining high-impact basegame parity debt affecting startup and in-game input/audio glue.
- Implement:
  - ASM-audit `RGE_Base_Game::setup()` failure branches and verify each `setup_*` failure maps to the original `error_code` values.
  - Resolve the current `// TODO: verify code` marker near `error_code = 0x14`.
  - Implement `RGE_Base_Game::get_mouse_pos(tagPOINT*)` from decomp/ASM (remove the current TODO: STUB body).
  - Implement `RGE_Base_Game::play_sound(long)` from decomp/ASM (remove the current TODO: STUB body).
  - Keep control-flow/cleanup ordering parity-correct for each failure path.
- Where: `src/game/src/basegame.cpp`.
- Source of truth: `src/game/decomp/basegame.cpp.decomp` + `src/game/decomp/basegame.cpp.asm`.
- Done when: the setup failure-code TODO verify marker is removed, `get_mouse_pos`/`play_sound` are no longer stubbed, and affected control flow matches decomp+asm.

Status note: landed in commit `9a373c8` and merged via `8bf5873`.

## Task 168 — Startup parity cleanup: remove non-original WinMain exception hook scaffolding
- [x] Assigned to agent
- [x] Finished
- Goal: align startup control flow with the original executable by removing non-original unhandled-exception hook scaffolding in `main.cpp`.
- Implement:
  - Audit `WinMain` startup sequence and remove/defer `SetUnhandledExceptionFilter(aoe_unhandled_exception_filter)` path if it is not present in source-of-truth.
  - Remove associated helper scaffolding only as required by parity.
  - Keep any retained custom debug instrumentation explicitly gated and minimal.
- Where: `src/game/src/main.cpp`.
- Source of truth: `src/game/decomp/main.cpp.decomp` + `src/game/decomp/main.cpp.asm`.
- Done when: the non-original startup hook TODO note is gone and `WinMain` startup flow matches decomp parity expectations.

Status note: landed in commit `d2e29f1` and merged via `a8e0a32`.

## Task 169 — Varargs safety: fix `logDebug(...)` forwarding chain in `rge_object_virtual_stubs.cpp`
- [x] Assigned to agent
- [x] Finished
- Goal: remove unsafe variadic forwarding in object virtual stubs where format arguments are dropped across class-layer `logDebug(...)` calls.
- Implement:
  - Audit every `logDebug(const char*, ...)` stub in `rge_object_virtual_stubs.cpp`.
  - Preserve variadic arguments correctly through forwarding (or route to a parity-correct implementation) instead of forwarding only the format string.
  - Keep signatures and vtable order unchanged.
- Where: `src/game/src/rge_object_virtual_stubs.cpp` (and declarations only if strictly required).
- Source of truth: vtable usage/call patterns in `src/game/decomp/pathsys.cpp.asm` and class units that consume `logDebug`.
- Done when: no `logDebug` stub drops variadic arguments, the file still links cleanly, and runtime debug-format calls are safe.

Status note: landed in commit `a262071` and merged via `b53220f`.

---

## Task 170 — Player command parity: de-stub core `TRIBE_Player` command issuers used by in-game view actions
- [x] Assigned to agent
- [x] Finished
- Goal: unblock core right-click/build command flow in single-player by replacing hard-fail `TRIBE_Player` command stubs currently reached by `TRIBE_Main_View`.
- Implement:
  - `TRIBE_Player::command_make_building(short,float,float)`.
  - `TRIBE_Player::command_attack_ground(float,float)`.
  - `TRIBE_Player::command_make_repair(RGE_Static_Object*)`.
  - `TRIBE_Player::command_make_unload(float,float)`.
- Where:
  - `src/game/src/TRIBE_Player.cpp`
  - `src/game/include/TRIBE_Player.h` (declarations only if required)
- Source of truth: `src/game/decomp/tplayer.cpp.decomp` + `src/game/decomp/tplayer.cpp.asm` (`command_make_building` / `command_attack_ground` / `command_make_repair` / `command_make_unload`).
- Dependency note: Task 111 is complete; this task removes the remaining command-layer hard-fail stubs now exercised by tvw_main actions.
- Done when: the four methods no longer return hardcoded failure, command emission matches decomp control flow, and build remains clean.

Status note: landed in commit `0a4db97` and merged via `8d6236d`; remaining production/research command stubs are tracked in Task 178.

## Task 171 — Player selection-command parity: restore `RGE_Player` selected-object analysis and `command_make_*` dispatch
- [x] Assigned to agent
- [x] Finished
- Goal: replace placeholder selected-object command dispatch in `RGE_Player` so movement/work/do commands use decomp-backed filtering/command emission rather than hardcoded success.
- Implement:
  - `RGE_Player::analyize_selected_objects()`.
  - `RGE_Player::command_make_move(RGE_Static_Object*,float,float)`.
  - `RGE_Player::command_make_work(RGE_Static_Object*,float,float)`.
  - `RGE_Player::command_make_do(RGE_Static_Object*,float,float)`.
- Where:
  - `src/game/src/RGE_Player.cpp`
  - `src/game/include/RGE_Player.h` (declarations only if required)
- Source of truth: `src/game/decomp/player.cpp.decomp` + `src/game/decomp/player.cpp.asm` (`analyize_selected_objects` and `command_make_*` paths through `get_selected_objects_to_command`).
- Done when: these methods are no longer empty/hardcoded-success placeholders, selected-object filtering + command forwarding match decomp control flow, and build remains clean.

Status note: implemented in commit `0f7632a` and merged via `33f83e9`.

## Task 172 — Placement geometry parity: implement `RGE_Master_Static_Object::alignment_box`
- [x] Assigned to agent
- [x] Finished
- Goal: remove the current zeroed fallback in `alignment_box` so wall/object placement outlines use real geometry extents in the main-view draw path.
- Implement: `RGE_Master_Static_Object::alignment_box(RGE_Game_World*,float,float,short*,short*,short*,short*,short*,short*,short*,short*)`.
- Where:
  - `src/game/src/RGE_Master_Static_Object.cpp`
  - `src/game/include/RGE_Master_Static_Object.h` (declarations only if required)
- Source of truth: `src/game/decomp/m_s_obj.cpp.decomp` + `src/game/decomp/m_s_obj.cpp.asm` (`alignment_box`, used by `TRIBE_Main_View::draw_wall_outline` and `RGE_View::draw_object_outline` call paths).
- Done when: zero-init fallback logic is removed, output coordinates follow decomp math/control flow, and outline consumers use parity-backed extents.

Status note: implemented in commit `253a895` and merged via `667528e` (later upstream sync merge `7a425fb`).

## Task 173 — World logging-handle parity: restore ctor/dtor log-file open/close in `RGE_Game_World`
- [x] Assigned to agent
- [x] Finished
- Goal: remove remaining constructor/destructor parity gaps around world log-file handles now that Task 151 constructor allocation parity is complete.
- Implement:
  - In `RGE_Game_World::RGE_Game_World()`, restore the decomp-backed log-file open behavior (`DVlogf` / related handle init) as applicable.
  - In `RGE_Game_World::~RGE_Game_World()`, restore matching close/cleanup behavior for world log handles.
  - Keep behavior parity-focused; do not introduce new logging formats or debug-only side paths.
- Where:
  - `src/game/src/RGE_Game_World.cpp`
  - `src/game/include/globals.h` and `src/game/src/globals.cpp` only if declarations/definitions are required for parity-correct handles.
- Source of truth: `src/game/decomp/world.cpp.decomp` + `src/game/decomp/world.cpp.asm` (ctor/dtor log-handle blocks noted in current TODO comments).
- Done when: ctor/dtor log-handle TODO parity notes are removed and lifecycle behavior matches decomp ordering.

Status note: implemented in commit `bdabd22` and merged via `a2d4d56`.

---

## Task 174 — View hot-path follow-up: finish remaining `RGE_View` parity debt (`Object_Was_Displayed` + partial lifecycle helpers)
- [x] Assigned to agent
- [x] Finished
- Goal: close the remaining `view.cpp` parity gaps still in single-player in-game render/selection hot paths.
- Implement:
  - Implement `RGE_View::Object_Was_Displayed(int,bool)` from source-of-truth (remove the current hard `return false` stub).
  - ASM-audit and finalize still-partial methods in this file that are hit during in-game rendering/input setup: ctor/dtor/setup/`Init_Tile_Edge_Tables`/`set_rect`/`set_focus`/`get_tile_mask_num`.
  - Remove/replace remaining "Partially verified" markers only when parity is actually validated.
- Where:
  - `src/game/src/view.cpp`
  - `src/game/include/RGE_View.h` (declarations only if required)
- Source of truth:
  - `src/game/decomp/view.cpp.decomp` + `src/game/decomp/view.cpp.asm`
  - Existing offsets already referenced in source comments: `0x00533510`, `0x00533760`, `0x00533940`, `0x00533AF0`, `0x00533F70`, `0x00533AC0`, `0x00538590`, plus the `Object_Was_Displayed` block near decomp line ~6975.
- Done when: `Object_Was_Displayed` is no longer stubbed, scoped partial markers are resolved with parity-backed logic, and build remains clean.

Status note: `Object_Was_Displayed` parity landed in commit `7f68a3e` and merged via `e671355`; remaining lifecycle partials are tracked as Task 181 to keep queue flow moving.

## Task 175 — In-game user-command parity: implement `TRIBE_Game::action_user_command` (pause/resume/out-of-sync/drop flow)
- [x] Assigned to agent
- [x] Finished
- Goal: restore gameplay/user-command routing in active matches so pause/resume and out-of-sync handling follow original control flow instead of a hard stub.
- Implement:
  - Transliterate `TRIBE_Game::action_user_command(unsigned long,unsigned long)` from source-of-truth (current implementation is `return 0;`).
  - In the same parity pass, audit the adjacent `TRIBE_Game::action_command`, `action_music_done`, `action_update`, and `action_mouse_move` stubs against source-of-truth/vtable dispatch expectations and either transliterate or convert to parity-correct base passthroughs.
  - Preserve program-mode branching and panel interactions (`quit_game`, popup dialogs, pause/resume routing, out-of-sync handling).
  - Keep behavior strictly parity-driven; no new UX branches.
- Where: `src/game/src/tribegam.cpp`
- Source of truth: `src/game/decomp/tribegam.cpp.decomp` + `src/game/decomp/tribegam.cpp.asm` (`action_user_command` @ `0x00529A70`, plus adjacent `action_*` dispatch slots in the same TU/vtable region).
- Done when: `action_user_command` is no longer stubbed, adjacent `action_*` stubs are parity-audited, and runtime command/music/update dispatch behavior matches source-of-truth.

Status note: `action_user_command` parity landed in commit `6b59bf1` and merged via `5a2e0a9`; remaining adjacent `action_*` stub retirement is tracked in Task 189.

## Task 176 — Object list hot-loop parity: finalize `RGE_Object_List::draw` + `update`
- [x] Assigned to agent
- [x] Finished
- Goal: harden frame-loop object traversal/render behavior by replacing remaining partial parity in object-list draw/update hot paths.
- Implement:
  - ASM-audit and finalize `RGE_Object_List::draw` (including fog-flag branches and color-table selection behavior).
  - Audit `RGE_Object_List::update` call flow and retire temporary debug-only instrumentation that is no longer needed after parity validation.
  - Keep behavior/source-of-truth parity exact; do not add fallback branches.
- Where: `src/game/src/RGE_Object_List.cpp`
- Source of truth: `src/game/decomp/obj_list.cpp.decomp` + `src/game/decomp/obj_list.cpp.asm` (`draw` @ `0x00463000`, `update` @ `0x00463210`).
- Done when: draw/update are parity-verified, partial marker is removed, and runtime loop behavior remains stable.

Status note: implemented in commit `72271fa` and merged via `a962963`.

## Task 177 — Action load parity follow-up: remove `RGE_Action::setup` fallback action-stack shim
- [x] Assigned to agent
- [x] Finished
- Goal: remove the non-parity fallback in action deserialization so action sub-list loading always follows source-of-truth flow.
- Implement:
  - Audit/implement strict parity in `RGE_Action::setup(int,RGE_Action_Object*)` where `sub_actions` are loaded.
  - Remove the current fallback branch that manually reads a short when `sub_actions == nullptr`; align with decomp-backed control flow.
  - Validate interaction with `RGE_Action::setup(RGE_Action_Object*)` and `create_action_list`.
- Where: `src/game/src/RGE_Action.cpp`
- Source of truth: `src/game/decomp/action.cpp.decomp` + `src/game/decomp/action.cpp.asm` (`setup(int,...)` @ `0x00407530`, `setup(...)` @ `0x00407680`, `create_action_list` @ `0x004076D0`).
- Done when: fallback shim is removed/replaced by parity logic and action load paths remain stable.

Status note: implemented in commit `a22c064` and merged via `567aca5`.

## Task 178 — TRIBE player production/research command parity tranche (build/train/research/task work)
- [x] Assigned to agent
- [x] Finished
- Goal: restore core single-player production/research/task command issuance paths currently stubbed in `TRIBE_Player`.
- Implement:
  - `buildObject`, `cancelBuild`, `registerBuild`.
  - `trainUnit`, `cancelTrain`, `registerTrain`.
  - `research`, `cancelResearch`, `registerResearch`.
  - `taskTrader`, `taskResourceGatherer`.
  - Keep command payload allocation/cleanup and player-AI checks consistent with source-of-truth.
- Where:
  - `src/game/src/TRIBE_Player.cpp`
  - `src/game/include/TRIBE_Player.h` (declarations only if required)
- Source of truth: `src/game/decomp/tplayer.cpp.decomp` + `src/game/decomp/tplayer.cpp.asm` (`buildObject` @ `0x00515130` through `taskResourceGatherer` @ `0x00515360`).
- Done when: listed methods no longer have empty stub bodies and production/research/task command issuance follows decomp control flow.

Status note: implemented in commit `2adef0e` and merged via `6afaca2`; remaining `TribeBuildAIModule` helper parity is tracked in Task 186.

## Task 179 — Static object movement/combat virtual parity tranche (post-Task-165 follow-up)
- [x] Assigned to agent
- [x] Finished
- Goal: continue de-stubbing `RGE_Static_Object` gameplay virtuals still returning hardcoded defaults in movement/combat command execution paths.
- Implement (decomp-first):
  - `attack(int,int)` + `attack(float,float,float,int)`.
  - `moveTo(int,int)`, `moveTo(int,float,int)`, `moveTo(float,float,float,float,int)`.
  - `transport(float,float,float,int)`.
  - `stopAction()`.
  - `canPath(int,float,float*,int,int,int)` and `canPath(XYZPoint,float,int,float*,int,int,int)`.
- Where:
  - `src/game/src/RGE_Static_Object.cpp`
  - `src/game/include/RGE_Static_Object.h` (declarations only if required)
- Source of truth: `src/game/decomp/stat_obj.cpp.decomp` + `src/game/decomp/stat_obj.cpp.asm` (function blocks in the `attack`/`moveTo`/`transport`/`stopAction`/`canPath` sections).
- Done when: listed methods are no longer hardcoded default returns and follow source-of-truth control flow.

Status note: implemented in commit `a1e077f` and merged via `6d49b98`; remaining static-object gameplay virtuals are tracked in Task 187.

## Task 180 — Virtual-forwarder retirement (hot-path slots): remove gameplay-critical forwarding from `rge_object_virtual_stubs`
- [x] Assigned to agent
- [x] Finished
- Goal: reduce reliance on linker-satisfaction forwarding stubs in per-frame object update/draw dispatch for non-static object classes.
- Implement:
  - Audit the vtable slots exercised by `RGE_Object_List` hot-loop dispatch (`draw`/`shadow_draw`/`normal_draw`/`update`) for `RGE_Animated_Object`, `RGE_Moving_Object`, `RGE_Action_Object`, and `RGE_Combat_Object`.
  - Replace forwarding-only stub bodies with parity-backed implementations in owning class translation units.
  - Remove/retire corresponding entries from `rge_object_virtual_stubs.cpp` for the scoped methods while keeping signatures/vtable order intact.
- Where:
  - `src/game/src/rge_object_virtual_stubs.cpp`
  - Owning class sources as required (`RGE_Animated_Object.cpp`, `RGE_Moving_Object.cpp`, `RGE_Action_Object.cpp`, `RGE_Combat_Object.cpp`).
- Source of truth:
  - `src/game/decomp/obj_list.cpp.decomp` + `.asm` (dispatch slots), plus class-specific decomp/ASM units (`anim_obj`, `m_obj`, `act_obj`, `c_obj`).
- Done when: scoped hot-path methods no longer route through forwarding TODO stubs and frame-loop behavior remains parity-backed.

Status note: implemented in commit `721ed20` and merged via `d7e739e`; remaining missile/dopple forwarder retirement is tracked in Task 190.

## Task 181 — View lifecycle parity tranche: finish remaining partial `RGE_View` hot-path methods
- [x] Assigned to agent
- [x] Finished
- Goal: close the remaining `view.cpp` lifecycle/render-support parity debt now that `Object_Was_Displayed` is de-stubbed.
- Implement:
  - ASM-audit and finalize: `RGE_View::RGE_View`, `~RGE_View`, `setup`, `Init_Tile_Edge_Tables`, `set_rect(long,long,long,long)`, `set_focus`, and `get_tile_mask_num`.
  - Remove/replace remaining "Partially verified" markers for these methods only when parity is actually validated.
  - Keep scope limited to lifecycle + mask-table behavior; do not modify pick/outline code already completed in Tasks 154/174.
- Where:
  - `src/game/src/view.cpp`
  - `src/game/include/RGE_View.h` (declarations only if required)
- Source of truth:
  - `src/game/decomp/view.cpp.decomp` + `src/game/decomp/view.cpp.asm`
  - Offsets: `0x00533510`, `0x00533760`, `0x00533940`, `0x00533AF0`, `0x00533F70`, `0x00533AC0`, `0x00538590`.
- Done when: the scoped methods are parity-verified and no longer marked partially verified.

Status note: implemented in commit `1154aa1` and merged via `5e8f189`.

## Task 182 — In-game screen runtime parity: finalize `TRIBE_Screen_Game` frame-update/player-rebind flow
- [x] Assigned to agent
- [x] Finished
- Goal: eliminate remaining "source-aligned slice" behavior in `TRIBE_Screen_Game` so per-frame HUD/view rebinding follows strict decomp/ASM parity.
- Implement:
  - Audit and finalize `TRIBE_Screen_Game::handle_game_update` (world/player/main_view rebinding, selection refresh, score display branch, redraw timing).
  - Audit and finalize `TRIBE_Screen_Game::player_changed` plus overlap/redraw helpers used by in-game dialogs/panels.
  - Remove temporary fallback behavior that was added to keep runtime alive (only where source-of-truth does not support it).
- Where:
  - `src/game/src/TRIBE_Screen_Game.cpp`
  - `src/game/include/TRIBE_Screen_Game.h` (declarations only if required)
- Source of truth: `src/game/decomp/scr_game.cpp.decomp` + `src/game/decomp/scr_game.cpp.asm` (`handle_game_update` block around `0x00496800`, `player_changed` block around `0x00498A50`).
- Done when: these runtime handlers are decomp/ASM-aligned and no longer described as source-aligned best-effort slices.

Status note: implemented in commit `413142e` and merged via `f5b0a81`; remaining command-panel refresh slice parity is tracked in Task 194.

## Task 183 — World tick parity: ASM-audit and finalize `RGE_Game_World::update`
- [x] Assigned to agent
- [x] Finished
- Goal: harden the core simulation tick used by SP gameplay by replacing temporary debug-era guards/logging with strict world update parity.
- Implement:
  - ASM-audit `RGE_Game_World::update` timing/cycle math (`DoCycle`, `old_time`, `world_time_delta`, pause/temp-pause, random-seed update).
  - Verify `commands->do_commands`, `scenario->update`, player loop/update ordering, and `check_game_state` sequencing against source-of-truth.
  - Retire narrow temporary debug logging/extra null-guard branches in this function where they diverge from original behavior.
- Where: `src/game/src/RGE_Game_World.cpp`
- Source of truth: `src/game/decomp/world.cpp.decomp` + `src/game/decomp/world.cpp.asm` (`RGE_Game_World::update` @ `0x00542ED0`).
- Done when: update tick ordering/branching is parity-backed and the function carries a fully verified marker.

Status note: implemented in commit `69db962` and merged via `a7621d5`.

## Task 184 — Base runtime dispatch parity: finalize `RGE_Base_Game` idle/user-command handlers
- [x] Assigned to agent
- [x] Finished
- Goal: ensure WM_TIMER/WM_COMMAND/WM_USERCOMMAND/music-done dispatch semantics match original behavior before reaching TRIBE-level action handlers.
- Implement:
  - ASM-audit and finalize `RGE_Base_Game::handle_idle`, `handle_user_command`, `handle_command`, and `handle_music_done`.
  - Verify return-value semantics (consumed vs not-consumed) and action dispatch calls (`action_user_command`, `action_command`, `action_music_done`) against source-of-truth.
  - Remove temporary debug instrumentation in these handlers where it is no longer needed after parity validation.
- Where: `src/game/src/basegame.cpp`
- Source of truth: `src/game/decomp/basegame.cpp.decomp` + `src/game/decomp/basegame.cpp.asm` (`handle_idle` @ `0x00420F60`, `handle_user_command` @ `0x004212E0`, `handle_command` @ `0x004213A0`, `handle_music_done` @ `0x004213C0`).
- Done when: these dispatch handlers are parity-verified and feed TRIBE action handlers with the original message semantics.

Status note: implemented in commit `2d35db9` and merged via `4b72373`.

## Task 185 — Player selection lifecycle parity follow-up (`RGE_Player` selection bookkeeping)
- [x] Assigned to agent
- [x] Finished
- Goal: remove the remaining partial parity in player selection bookkeeping that feeds view command routing.
- Implement:
  - Finalize `RGE_Player::select_one_object(RGE_Static_Object*, int)` parity (success/slot semantics, `param_2` behavior, and return contract).
  - Audit adjacent selection lifecycle helpers (`select_one_object`, `unselect_one_object`, `unselect_object`, `update_selected`, `get_selected_objects_to_command`) to ensure list/order/count behavior is source-accurate.
  - Keep this task selection-scope only; do not modify movement/work/do command emitters covered by Task 171.
- Where:
  - `src/game/src/RGE_Player.cpp`
  - `src/game/include/RGE_Player.h` (declarations only if required)
- Source of truth: `src/game/decomp/player.cpp.decomp` + `src/game/decomp/player.cpp.asm` (selection blocks spanning `0x00470D20`..`0x00471430` and `get_selected_objects_to_command` @ `0x004712F0`).
- Done when: selection lifecycle functions are parity-audited and the partial marker in the scoped selection path is removed.

Status note: implemented in commit `2d160e3` and merged via `5dfd716`.

## Task 186 — TRIBE player AI-build parity follow-up: replace temporary `TribeBuildAIModule` helper shims
- [x] Assigned to agent
- [x] Finished
- Goal: remove temporary local helper shims in `TRIBE_Player` cancel/register paths and restore real `TribeBuildAIModule` integration.
- Implement:
  - Transliterate/restore the missing `TribeBuildAIModule` methods used by `TRIBE_Player`: cancel/add hooks for build/train/research (`cancelBuildItem`, `addBuiltItem`, `cancelTrainUnit`, `addTrainedUnit`, `cancelResearch`, `addResearch`).
  - Replace the temporary `tribe_build_ai_*` shim helpers in `TRIBE_Player.cpp` with real calls to the restored module methods.
  - Keep command issuance behavior from Task 178 intact; this task is specifically about AI bookkeeping parity.
- Where:
  - `src/game/src/TRIBE_Player.cpp`
  - `src/game/include/TribeBuildAIModule.h`
  - Add/update `src/game/src/TribeBuildAIModule.cpp` (split only if source-of-truth requires additional TU(s)).
- Source of truth: `src/game/decomp/tplayer.cpp.decomp` + `src/game/decomp/tplayer.cpp.asm` for call sites, and `TribeBuildAIModule` source-of-truth units in `src/game/decomp/` for method bodies/signatures.
- Done when: the six `tribe_build_ai_*` temporary shims are gone and `TRIBE_Player` cancel/register paths use real `TribeBuildAIModule` methods.

Status note: implemented in commit `3c40130` and merged via `b5e2244`; remaining AI-module dependency parity work is tracked in Task 196.

## Task 187 — Static-object gameplay virtuals follow-up: de-stub remaining movement/work/path methods
- [x] Assigned to agent
- [x] Finished
- Goal: continue shrinking high-impact `RGE_Static_Object` default-return virtuals still reachable from command/action runtime paths.
- Implement (decomp-first):
  - De-stub the next gameplay tranche after Task 179: `moveAwayFrom`, `hunt`, `gather`, `convert`, `repair`, `build`, `trade`, `explore`, `enter`, `unload`, and `pause`.
  - Include the immediate pathing follow-ups still hardcoded in this block (`canBidirectionPath`, `canPathWithObstructions`, `canPathWithAdditionalPassability`) if needed by scoped methods.
  - Keep scope limited to this contiguous virtual block; do not touch forwarder retirement work in `rge_object_virtual_stubs.cpp`.
- Where:
  - `src/game/src/RGE_Static_Object.cpp`
  - `src/game/include/RGE_Static_Object.h` (declarations only if required)
- Source of truth: `src/game/decomp/stat_obj.cpp.decomp` + `src/game/decomp/stat_obj.cpp.asm` (post-Task-179 virtual block beginning at `moveAwayFrom`).
- Done when: the scoped methods are no longer hardcoded default returns and follow source-of-truth control flow.

Status note: implemented in commit `f209973` and merged via `6e26b7c`; remaining contiguous static-object virtual defaults are tracked in Task 195.

## Task 188 — Action-runtime parity follow-up: de-stub core `RGE_Action` virtual responders
- [x] Assigned to agent
- [x] Finished
- Goal: remove remaining base-action default responders that can short-circuit runtime behavior when specific action subclasses fall back to base methods.
- Implement:
  - Transliterate parity for `RGE_Action::stop`, `move_to`, `work`, `attack_response`, and `relation_response`.
  - Audit and complete `copy_obj` / `copy_obj_sprites` behavior where source-of-truth requires non-no-op state propagation.
  - Keep this task constrained to base action class behavior; do not overlap with action-list/load work already completed in Task 177.
- Where:
  - `src/game/src/RGE_Action.cpp`
  - `src/game/include/RGE_Action.h` (declarations only if required)
- Source of truth: `src/game/decomp/action.cpp.decomp` + `src/game/decomp/action.cpp.asm` (base action virtual responder block following `update`/`save`/`setup`).
- Done when: scoped base virtual responders are parity-backed and no longer trivial hardcoded returns/no-ops.

Status note: implemented in commit `3d7b445`.

## Task 189 — TRIBE game-loop action dispatch parity follow-up (`TRIBE_Game` runtime action stubs)
- [x] Assigned to agent
- [x] Finished
- Goal: retire the remaining hardcoded action-dispatch stubs in `TRIBE_Game` so in-game WM_* routed actions follow source-of-truth behavior end-to-end.
- Implement:
  - Transliterate and parity-audit `TRIBE_Game::action_update`, `action_mouse_move`, `action_command`, and `action_music_done` (currently hardcoded `return 0;`).
  - Audit adjacent runtime accessors used by this path (`get_view_panel`, `get_map_panel`) and wire them to parity-correct in-game panels where required by source-of-truth.
  - Keep scope on action dispatch/runtime panel access only; do not overlap with Task 182 screen internals.
- Where:
  - `src/game/src/tribegam.cpp`
  - `src/game/include/TRIBE_Game.h` (declarations only if required)
- Source of truth: `src/game/decomp/tribegam.cpp.decomp` + `src/game/decomp/tribegam.cpp.asm` (action/vtable block adjacent to `action_user_command` @ `0x00529A70`, plus related panel-accessor slots in the same TU).
- Done when: the scoped action/accessor methods are no longer hardcoded zero/null stubs and runtime dispatch behavior is parity-backed.

## Task 190 — Forwarder retirement follow-up: missile/dopple hot-loop virtual slots
- [x] Assigned to agent
- [x] Finished
- Goal: continue shrinking gameplay-critical forwarding stubs by retiring remaining projectile/doppleganger draw-slot forwarding still emitted from `rge_object_virtual_stubs.cpp`.
- Implement:
  - Add parity-backed owning-class implementations for `RGE_Missile_Object` and `RGE_Doppleganger_Object` draw slots used by object-list dispatch (`draw`, `shadow_draw`, `normal_draw`) where still routed through the stub TU.
  - Remove the corresponding forwarder entries from `rge_object_virtual_stubs.cpp` while preserving signatures/vtable order.
  - Keep this task constrained to missile/dopple forwarder retirement only.
- Where:
  - `src/game/src/rge_object_virtual_stubs.cpp`
  - `src/game/src/RGE_Missile_Object.cpp`
  - `src/game/src/RGE_Doppleganger_Object.cpp`
  - Relevant include declarations only if required (`src/game/include/RGE_Missile_Object.h`, `src/game/include/RGE_Doppleganger_Object.h`)
- Source of truth:
  - `src/game/decomp/obj_list.cpp.decomp` + `src/game/decomp/obj_list.cpp.asm` (virtual dispatch slots around `0x00463055`, `0x00463139`, `0x004631BA`)
  - `src/game/decomp/misl_obj.cpp.decomp` + `.asm`, `src/game/decomp/dpl_obj.cpp.decomp` + `.asm`
- Done when: scoped missile/dopple draw-slot methods no longer forward through `rge_object_virtual_stubs.cpp` and dispatch parity remains intact.

Status note: implemented in commit `2af58df` (direct on `master`).

## Task 191 — Master-derived factory parity follow-up (`RGE_Master_Derived_Stubs.cpp`)
- [x] Assigned to agent
- [x] Finished
- Goal: remove remaining base-forwarder object-factory behavior in master-derived classes so runtime spawning uses parity-correct class-specific creation logic.
- Implement:
  - Transliterate/restore class-specific `make_new_obj` behavior for `RGE_Master_Animated_Object` and `RGE_Master_Moving_Object` (currently forwarding to `RGE_Master_Static_Object::make_new_obj`).
  - Audit `RGE_Master_Doppleganger_Object::make_new_obj(RGE_Player*,float,float,float)` and `RGE_Master_Combat_Object::calc_base_damage_ability()` paths where current behavior is still generic/zero-return.
  - Keep scope to this TU and directly related declarations; do not overlap with Task 190 virtual-forwarder retirement.
- Where:
  - `src/game/src/RGE_Master_Derived_Stubs.cpp`
  - Relevant master-object headers under `src/game/include/` (declarations only if required)
- Source of truth:
  - `src/game/decomp/m_a_obj.cpp.decomp` + `.asm`
  - `src/game/decomp/m_m_obj.cpp.decomp` + `.asm`
  - `src/game/decomp/m_dg_obj.cpp.decomp` + `.asm`
  - `src/game/decomp/m_co_obj.cpp.decomp` + `.asm`
- Done when: scoped master-derived factory/combat methods are no longer base-forwarder/zero-return placeholders and match source-of-truth control flow.

## Task 192 — Out-of-sync diagnostics parity: restore `debug_random_write` / `dump_vismap_log`
- [x] Assigned to agent
- [x] Finished
- Assignment note: re-assigned to worker-5 (`aoe1_clone_5`)
- Status note: 82 lines — small task. Commit `d7272e3`.
- Goal: replace the remaining global no-op debug helpers used by out-of-sync handling with source-backed implementations so diagnostic artifacts are generated when debug toggles are enabled.
- Implement:
  - Transliterate `debug_random_write` and `dump_vismap_log` from source-of-truth instead of no-op TODO stubs.
  - Preserve existing runtime gating (`do_debug_random`) and call sites in multiplayer/out-of-sync flows.
  - Keep this task strictly to these two globals and required support declarations.
- Where:
  - `src/game/src/globals.cpp`
  - `src/game/include/globals.h` (declarations only if required)
  - Any directly required source-backed helper TU(s) under `src/game/src/` if needed for linkage
- Source of truth: source-backed implementations referenced by existing comments/callers (`src/game/decomp/visible.cpp.decomp` + `.asm`, plus related debug helper blocks in `basegame`/`tribegam` decomp where applicable).
- Done when: both functions are no longer TODO no-ops and emit parity-correct diagnostic output when the debug path is active.

## Task 193 — Main-view command pipeline audit: finalize `RGE_Main_View` input-to-command routing parity
- [x] Assigned to agent
- [x] Finished
- Assignment note: re-assigned to worker-5 (`aoe1_clone_5`)
- Status note: `command_make_move`, `pick_objects1`, `pick_best_target`, `command_place_multi_object` finalized. Commit `d4a9e27`.
- Goal: harden single-player input command routing by ASM-auditing `RGE_Main_View` command entrypoints used by right/left-click gameplay interactions.
- Implement:
  - Audit/finalize `command_make_do`, `command_make_move`, `command_make_work`, `command_place_object`, and `command_place_multi_object`.
  - Audit/finalize the pick/target helpers feeding these calls (`pick1`, `pick_objects1`, `pick_best_target`) for branch/return semantics.
  - Keep scope limited to `RGE_Main_View` command-path behavior; do not overlap with Task 182 `TRIBE_Screen_Game` rebinding work.
- Where:
  - `src/game/src/RGE_Main_View.cpp`
  - `src/game/include/RGE_Main_View.h` (declarations only if required)
- Source of truth: `src/game/decomp/vw_main.cpp.decomp` + `src/game/decomp/vw_main.cpp.asm` (command/pick blocks spanning `command_make_*` and `pick*` regions in the 0x0053E7F0..0x005405E0 range).
- Done when: scoped command-path functions are parity-audited against ASM and no longer rely on non-parity fallbacks.

## Task 194 — In-game screen parity follow-up: finalize remaining command-panel refresh slice in `TRIBE_Screen_Game`
- [x] Assigned to agent
- [ ] Finished
- Assignment note: worker-3 (`aoe1_clone_3`)
- Goal: close the remaining `TRIBE_Screen_Game` in-game parity gaps left after Task 182 (world-step/game-over branch, player-change civ-refresh branch, and command-panel refresh slice).
- Implement:
  - Transliterate the remaining world-step/game-over branch in `handle_game_update` (decomp block around `0x00496800`) currently marked TODO in code.
  - Transliterate the remaining civilization theme/picture refresh branch in `player_changed` (decomp block around `0x00498AD0`) currently marked TODO in code.
  - Audit/finalize the command-panel refresh helper currently marked source-aligned in `setup_buttons` (block around `0x004996C0`), including `player_changed`/`reset_buttons` interactions.
  - Remove the scoped TODO/source-aligned markers only after decomp/ASM-backed parity validation.
- Where:
  - `src/game/src/TRIBE_Screen_Game.cpp`
  - `src/game/include/TRIBE_Screen_Game.h` (declarations only if required)
- Source of truth: `src/game/decomp/scr_game.cpp.decomp` + `src/game/decomp/scr_game.cpp.asm` (remaining blocks around `0x00496800`, `0x00498AD0`, and `0x004996C0`).
- Done when: all three scoped `TRIBE_Screen_Game.cpp` TODO/source-aligned parity markers are removed and behavior is decomp/ASM-backed.

## Task 195 — Static-object virtual parity follow-up II: finish remaining contiguous default-return block
- [x] Assigned to agent
- [x] Finished
- Status note: completed by `worker-1` (`aoe1_clone_1`); task commit `0ea8ca9`, merged to master as `aae5756`.
- Goal: continue Task-187 follow-through by replacing the still-default contiguous `RGE_Static_Object` movement/work/path virtual block with source-backed parity implementations.
- Implement (decomp-first + ASM spot-audit):
  - Finalize the still-default methods in the `moveAwayFrom` contiguous block (`moveAwayFrom`, `hunt`, `gather`, `convert`, `repair`, `build`, `trade`, `explore`, `enter`, `unload`, `pause`).
  - Include immediate pathing continuations in the same block (`canBidirectionPath`, `canPathWithObstructions`, `canPathWithAdditionalPassability`) and any directly chained helpers if required by source-of-truth control flow.
  - Keep scope limited to this contiguous default-return tranche in `RGE_Static_Object.cpp`; do not overlap with forwarder retirement in `rge_object_virtual_stubs.cpp`.
- Where:
  - `src/game/src/RGE_Static_Object.cpp`
  - `src/game/include/RGE_Static_Object.h` (declarations only if required)
- Source of truth: `src/game/decomp/stat_obj.cpp.decomp` + `src/game/decomp/stat_obj.cpp.asm` (contiguous virtual block beginning at `moveAwayFrom` and its immediate pathing helpers).
- Done when: the scoped contiguous virtual block no longer uses hardcoded default returns except where explicitly proven by source-of-truth.

## Task 196 — TRIBE AI build-module dependency parity: retire helper stubs in `TribeBuildAIModule.cpp`
- [x] Assigned to agent
- [ ] Finished
- Status note: assigned to `worker-2` (`aoe1_clone_4`) for execution.
- Goal: remove helper-level TODO stubs currently short-circuiting AI build/train/research bookkeeping during in-game updates.
- Implement:
  - Replace local helper stubs with source-backed behavior: `tribe_build_ai_detask`, `tribe_build_ai_is_moveable`, `tribe_build_ai_clear_area`, `tribe_build_ai_remove_lot`, `tribe_build_ai_update_needed_resources`.
  - Remove/resolve the partial-parity notes in `addBuiltItem`, `cancelBuildItem`, `addTrainedUnit`, `cancelTrainUnit`, `addResearch`, and `cancelResearch` that are currently gated by these helpers.
  - Keep scope limited to `TribeBuildAIModule` and directly required declarations; do not modify `TRIBE_Player` command issuance flow (already finalized in Task 186).
- Where:
  - `src/game/src/TribeBuildAIModule.cpp`
  - `src/game/include/TribeBuildAIModule.h` (declarations only if required)
- Source of truth: `src/game/decomp/taibldmd.cpp.decomp` + `src/game/decomp/taibldmd.cpp.asm`, with call-site expectations from `src/game/decomp/tplayer.cpp.decomp`.
- Done when: the scoped helper TODO stubs are removed and the six add/cancel methods no longer carry partial-parity TODO markers.

## Task 197 — TRIBE AI decision-module full parity: orchestration + update + virtuals (`TribeMainDecisionAIModule.cpp`)
- [x] Assigned to agent
- [x] Finished
- Status note: worker-2 (`aoe1_clone_2`). Full orchestration/update/module-management replaced from stubs. Commit `f790188`.
- Goal: replace the hollow TribeMainDecisionAIModule with a source-backed implementation so the AI decision orchestrator actually invokes sub-module updates during the game tick. Currently **all 21 methods** are stubs returning 1 or doing nothing; the `update()` method (the main AI tick entry called from `TRIBE_Player::update()`) is completely empty — meaning AI opponents never make build/train/attack/research decisions.
- Implement (decomp-first from `taimdmd.cpp.decomp`, ~1535 lines):
  - **Core orchestration:** `TribeMainDecisionAIModule::update(int)` — this is the main AI tick that iterates sub-modules (build, strategy, tactical, resource, etc.) and drives all AI decision-making. This is the single most critical method for SP AI opponents.
  - **Module management:** `addModule`, `removeModule`, `findModule`, and the constructor/load-constructor that wires sub-module slots (build, strategy, tactical, information, construction, resource, diplomacy, emotional, research, trade modules).
  - **Process/filtering methods:** `filterOutMessage`, `canPerformAction`, and message dispatch to sub-modules.
  - **Logging/history virtuals:** `loggingHistory`, `toggleLogHistory`, `loggingCommonHistory`, `toggleLogCommonHistory`, `setLogHistory`, `setHistoryFilename`.
  - **State persistence:** `saveState`, `loadState` (if present in decomp).
  - Verify constructor/load-constructor state so offset-backed embedded-module storage remains layout-safe.
  - Keep scope to `TribeMainDecisionAIModule` only; do not overlap with `TribeBuildAIModule` helper work tracked in Task 196.
- Where:
  - `src/game/src/TribeMainDecisionAIModule.cpp`
  - `src/game/include/TribeMainDecisionAIModule.h` (declarations only if required)
- Source of truth: `src/game/decomp/taimdmd.cpp.decomp` + `src/game/decomp/taimdmd.cpp.asm`, plus class-level info in `src/game/decomp/TribeMainDecisionAIModule.decomp` + `.asm`.
- Context: The AI decision pipeline is: `TRIBE_Player::update()` → `playerAI->update(0)` → `TribeMainDecisionAIModule::update()` → sub-module updates. Without this method implemented, AI opponents sit idle in SP.
- Done when: `TribeMainDecisionAIModule::update()` orchestrates sub-module ticks per source-of-truth, and all scoped methods match decomp control flow. The sub-modules themselves may still be stubs (they're tracked in Tasks 196, 201–209), but the orchestration/dispatch logic must be real.

## Task 198 — Base-game in-match options/cheat dispatch parity (`basegame.cpp`)
- [x] Assigned to agent
- [x] Finished
- Status note: re-assigned to worker-4 (`aoe1_clone_4`). Landed at commit `5701b85`.
- Goal: restore base-game handlers currently left as empty/constant-return shims so in-match command flow is source-backed before TRIBE-layer handling.
- Implement:
  - Transliterate and parity-audit `RGE_Base_Game::notification`, `send_game_options`, `receive_game_options`, `gameSummary`, and `processCheatCode`.
  - Wire return/side-effect semantics to match existing call sites in the runtime message/command path.
  - Keep scope limited to these methods; do not overlap with `TRIBE_Game` action dispatch work tracked in Task 189.
- Where:
  - `src/game/src/basegame.cpp`
  - `src/game/include/RGE_Base_Game.h` (declarations only if required)
- Source of truth: `src/game/decomp/basegame.cpp.decomp` + `src/game/decomp/basegame.cpp.asm` (method bodies by symbol/offset).
- Done when: the scoped methods are no longer empty/constant-return shims and compile/link cleanly.

## Task 199 — Forwarder retirement tranche III: animated-object gameplay virtuals
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-1 (`aoe1_clone_1`)
- Status note: animated-object tranche (`draw_front_frame`, `draw_back_frame`, `draw_frame`, `check_damage_sprites`, `rehook`, `new_sprite`, `add_overlay_sprite`, `remove_overlay_sprite`) moved to owning class and forwarders removed (merge `agent/task-199-anim-virtuals`, commit `aa1d448`).
- Goal: continue shrinking `rge_object_virtual_stubs.cpp` by retiring a contiguous animated-object gameplay virtual tranche used in frame update/draw paths.
- Implement:
  - Move one contiguous animated-object tranche from forwarders into owning implementations (e.g., `draw_front_frame`, `draw_back_frame`, `draw_frame`, `check_damage_sprites`, `rehook`, `new_sprite`, `add_overlay_sprite`, `remove_overlay_sprite`) per source-of-truth.
  - Remove corresponding entries from `rge_object_virtual_stubs.cpp` while preserving signatures and vtable ordering.
  - Keep scope limited to this animated-object tranche only; do not touch missile/dopple slots (Task 190 complete) or static-object movement block (Task 195).
- Where:
  - `src/game/src/rge_object_virtual_stubs.cpp`
  - `src/game/src/RGE_Animated_Object.cpp`
  - `src/game/include/RGE_Animated_Object.h` (declarations only if required)
- Source of truth: `src/game/decomp/anim_obj.cpp.decomp` + `src/game/decomp/anim_obj.cpp.asm`, plus dispatch context in `src/game/decomp/obj_list.cpp.decomp` + `.asm`.
- Done when: the scoped animated-object tranche no longer routes through `rge_object_virtual_stubs.cpp` and build remains clean.

## Task 200 — TRIBE player tech-tree safety-gap parity (`TRIBE_Player.cpp`)
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-2 (`aoe1_clone_4`)
- Status note: tech_abling/rev_tech finalized with ASM-backed parity and temporary-safe guard removed (merge `agent/task-200-tech-tree-safety-gap`, commit `0e89851`).
- Goal: remove the remaining temporary-safe tech-tree guard path in runtime tech enable/revoke flow so single-player progression logic is source-backed.
- Implement:
  - ASM-audit and finalize `TRIBE_Player::tech_abling` and adjacent `rev_tech` runtime flow around the current temporary-safe comment.
  - Validate constructor/load-time assumptions required by this runtime path so behavior does not rely on silent fallback guards.
  - Keep scope limited to the tech-tree runtime toggling path; do not overlap with AI-build hook parity tracked in Task 186/196.
- Where:
  - `src/game/src/TRIBE_Player.cpp`
  - `src/game/include/TRIBE_Player.h` (declarations only if required)
- Source of truth: `src/game/decomp/tplayer.cpp.decomp` + `src/game/decomp/tplayer.cpp.asm` (blocks around `0x00513DA0` and `0x00513DD0`, plus immediate setup dependencies).
- Done when: the temporary-safe note is removed and scoped tech enable/revoke behavior is parity-backed.

## Task 201 — AI module: implement base `BuildAIModule` parity (aibldmod.cpp.decomp)
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-3 (`aoe1_clone_3`)
- Status note: `BuildAIModule` transliteration implemented with full parity, header layout corrected for `sizeof == 0x5BC` (merge `agent/task-201-buildaimodule-base`, commit `0973441`).
- Goal: implement the base `BuildAIModule` class — the parent of `TribeBuildAIModule` — so AI build-decision dispatch has a real base-class implementation instead of missing/unresolved methods. This is a prerequisite for the AI build pipeline to function correctly.
- Implement (decomp-first from `aibldmod.cpp.decomp`, ~1562 lines):
  - Constructor, destructor, load-constructor.
  - `update()` — base build-module tick (called from the decision orchestrator).
  - Item management: `addBuildItem`, `removeBuildItem`, `findBuildItem`, `getBuildItemList`.
  - Build-request evaluation methods: `evaluateBuildRequest`, `prioritizeBuildItems`.
  - State persistence: `save`, `load` if present.
  - Any virtual methods that `TribeBuildAIModule` expects to call via `BuildAIModule::method()`.
- Where:
  - Add `src/game/src/BuildAIModule.cpp` (new file).
  - Update `src/game/include/BuildAIModule.h` (method declarations only if required; do not change member layout).
  - Add the new .cpp to `build.bat`.
- Source of truth: `src/game/decomp/aibldmod.cpp.decomp` + `src/game/decomp/aibldmod.cpp.asm`, plus class info in `src/game/decomp/BuildAIModule.decomp`.
- Non-overlap: do NOT touch `TribeBuildAIModule.cpp` (Task 196) or `TribeMainDecisionAIModule.cpp` (Task 197).
- Done when: `BuildAIModule` compiles/links cleanly with all decomp-backed methods and `TribeBuildAIModule` can call parent methods without unresolved symbols.

## Task 202 — AI module: implement `ConstructionAIModule` + `TribeConstructionAIModule` parity
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-2 (`aoe1_clone_4`)
- Status note: `ConstructionAIModule.cpp` and `TribeConstructionAIModule.cpp` implemented with header updates and TribeMainDecisionAI wiring. Commit `5ff8583`.
- Goal: implement the construction AI sub-module pair so AI opponents can prioritize and manage building construction during gameplay. Currently neither the base nor TRIBE override class has a .cpp implementation.
- Implement (decomp-first, ~1600 lines total):
  - **Base `ConstructionAIModule`** from `aiconmod.cpp.decomp` (~1105 lines): constructor, destructor, `update()`, construction item management, build-site evaluation, priority methods.
  - **`TribeConstructionAIModule`** from `taiconmd.cpp.decomp` (~496 lines): constructor, destructor, `update()` override with AoE1-specific construction logic, any TRIBE-specific evaluation or priority methods.
- Where:
  - Add `src/game/src/ConstructionAIModule.cpp` (new file).
  - Add `src/game/src/TribeConstructionAIModule.cpp` (new file).
  - Update `src/game/include/ConstructionAIModule.h` and `src/game/include/TribeConstructionAIModule.h` (declarations only if required; do not change member layout).
  - Add both new .cpp files to `build.bat`.
- Source of truth: `src/game/decomp/aiconmod.cpp.decomp` + `.asm`, `src/game/decomp/taiconmd.cpp.decomp` + `.asm`, plus class-level info in `src/game/decomp/ConstructionAIModule.decomp` and `src/game/decomp/TribeConstructionAIModule.decomp`.
- Non-overlap: do NOT touch any other AI module .cpp files.
- Done when: both classes compile/link cleanly, `update()` methods match source-of-truth control flow, and construction AI can be wired into the decision module sub-module array.

## Task 203 — AI module: implement `ResourceAIModule` + `TribeResourceAIModule` + `DiplomacyAIModule` parity
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-4 (`aoe1_clone_2`)
- Status note: `ResourceAIModule`, `TribeResourceAIModule`, and `DiplomacyAIModule` implemented (merge `agent/task-203-ai-modules`, commit `2e2c843`).
- Goal: implement three smaller AI sub-modules in one task: resource management AI (base + TRIBE override) and diplomacy AI (base only). These feed into the main decision module's sub-module array for resource allocation and diplomatic stance decisions.
- Implement (decomp-first, ~1586 lines total):
  - **Base `ResourceAIModule`** from `airesmod.cpp.decomp` (~646 lines): constructor, destructor, `update()`, resource tracking/evaluation methods.
  - **`TribeResourceAIModule`** from `tairesmd.cpp.decomp` (~256 lines): constructor, destructor, `update()` override with AoE1-specific resource logic.
  - **`DiplomacyAIModule`** from `aidipmod.cpp.decomp` (~684 lines): constructor, destructor, `update()`, diplomacy evaluation/stance methods.
- Where:
  - Add `src/game/src/ResourceAIModule.cpp` (new file).
  - Add `src/game/src/TribeResourceAIModule.cpp` (new file).
  - Add `src/game/src/DiplomacyAIModule.cpp` (new file).
  - Update respective headers under `src/game/include/` (declarations only if required; do not change member layout).
  - Add all three new .cpp files to `build.bat`.
- Source of truth: `src/game/decomp/airesmod.cpp.decomp` + `.asm`, `src/game/decomp/tairesmd.cpp.decomp` + `.asm`, `src/game/decomp/aidipmod.cpp.decomp` + `.asm`, plus class-level `.decomp` files for each class.
- Non-overlap: do NOT touch any other AI module .cpp files.
- Done when: all three classes compile/link cleanly with source-backed `update()` methods and can be wired into the decision module sub-module array.

## Task 204 — AI module: implement `TribeStrategyAIModule` parity (taistrmd.cpp.decomp)
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-1 (`aoe1_clone_1`)
- Status note: `StrategyAIModule.cpp` + `TribeStrategyAIModule.cpp` added. Commit `113afcc`.
- Goal: implement the strategy AI sub-module so AI opponents can make age-advancement, long-term planning, and strategy-level decisions during SP gameplay. The base `StrategyAIModule` is tiny (39 lines, mostly virtual stubs) and should be included.
- Implement (decomp-first, ~3337 lines total):
  - **Base `StrategyAIModule`** from `aistrmod.cpp.decomp` (~39 lines): constructor, destructor, virtual stubs.
  - **`TribeStrategyAIModule`** from `taistrmd.cpp.decomp` (~3298 lines): constructor, destructor, `update()` with age-advancement logic, strategy evaluation, resource allocation priorities, and all helper methods referenced by the update tick.
- Where:
  - Add `src/game/src/StrategyAIModule.cpp` (new file — may be very small).
  - Add `src/game/src/TribeStrategyAIModule.cpp` (new file — main implementation).
  - Update respective headers under `src/game/include/` (declarations only if required; do not change member layout).
  - Add both new .cpp files to `build.bat`.
- Source of truth: `src/game/decomp/aistrmod.cpp.decomp` + `.asm`, `src/game/decomp/taistrmd.cpp.decomp` + `.asm`, plus class-level `.decomp` files.
- Non-overlap: do NOT touch any other AI module .cpp files.
- Done when: `TribeStrategyAIModule::update()` matches source-of-truth control flow and compiles/links cleanly.

## Task 205 — AI support modules: implement `EmotionalAIModule` + `ResearchAIModule` + `TradeAIModule` parity
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-2 (`aoe1_clone_2`)
- Status note: 3 AI support module .cpp files added. Commit `c17cc45`.
- Goal: implement three smaller AI sub-modules that feed into the main decision module's sub-module array: emotional state tracking, research prioritization, and trade evaluation.
- Implement (decomp-first, ~1449 lines total):
  - **`EmotionalAIModule`** from `aiemomod.cpp.decomp` (~633 lines): constructor, destructor, `update()`, emotional state tracking/evaluation methods.
  - **`ResearchAIModule`** from `airchmod.cpp.decomp` (~727 lines): constructor, destructor, `update()`, research priority/evaluation methods.
  - **`TradeAIModule`** from `aitrdmod.cpp.decomp` (~89 lines): constructor, destructor, `update()`, trade evaluation (very small module).
- Where:
  - Add `src/game/src/EmotionalAIModule.cpp` (new file).
  - Add `src/game/src/ResearchAIModule.cpp` (new file).
  - Add `src/game/src/TradeAIModule.cpp` (new file).
  - Update respective headers under `src/game/include/` (declarations only if required; do not change member layout).
  - Add all three new .cpp files to `build.bat`.
- Source of truth: `src/game/decomp/aiemomod.cpp.decomp` + `.asm`, `src/game/decomp/airchmod.cpp.decomp` + `.asm`, `src/game/decomp/aitrdmod.cpp.decomp` + `.asm`, plus class-level `.decomp` files.
- Non-overlap: do NOT touch any other AI module .cpp files.
- Done when: all three classes compile/link cleanly with source-backed `update()` methods.

## Task 206 — AI items: implement `BuildItem` + `ConstructionItem` + `ResearchItem` + `TechItem` parity
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-3 (`aoe1_clone_3`)
- Status note: 4 AI item .cpp files added (BuildItem, ConstructionItem, ResearchItem, TechItem), headers updated. Commit `d3b427f`.
- Goal: implement the four AI item data classes used by AI modules to track build orders, construction jobs, research queues, and tech targets. These are data structures consumed by `BuildAIModule`, `ConstructionAIModule`, `ResearchAIModule`, and the strategy module.
- Implement (decomp-first, ~1755 lines total):
  - **`BuildItem`** from `aiblditm.cpp.decomp` (~618 lines): constructor, destructor, item state, priority, cost evaluation, save/load.
  - **`ConstructionItem`** from `aiconitm.cpp.decomp` (~315 lines): constructor, destructor, construction state tracking.
  - **`ResearchItem`** from `airesitm.cpp.decomp` (~504 lines): constructor, destructor, research progress/priority tracking.
  - **`TechItem`** from `aitchitm.cpp.decomp` (~318 lines): constructor, destructor, tech availability tracking.
- Where:
  - Add `src/game/src/BuildItem.cpp` (new file).
  - Add `src/game/src/ConstructionItem.cpp` (new file).
  - Add `src/game/src/ResearchItem.cpp` (new file).
  - Add `src/game/src/TechItem.cpp` (new file).
  - Update respective headers under `src/game/include/` if they exist (declarations only; do not change member layout). If no header exists, create minimal ones following the project pattern.
  - Add all four new .cpp files to `build.bat`.
- Source of truth: `src/game/decomp/aiblditm.cpp.decomp` + `.asm`, `src/game/decomp/aiconitm.cpp.decomp` + `.asm`, `src/game/decomp/airesitm.cpp.decomp` + `.asm`, `src/game/decomp/aitchitm.cpp.decomp` + `.asm`.
- Non-overlap: do NOT touch any AI module .cpp files.
- Done when: all four item classes compile/link cleanly with source-backed constructors, state methods, and save/load matching decomp control flow.

## Task 207 — AI module: implement `TribeTacticalAIModule` parity — Part 1 (core lifecycle + group management)
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-4 (`aoe1_clone_4`)
- Status note: `TacticalAIModule.cpp`, `TacticalAIGroup.cpp`, `TribeTacticalAIModule.cpp` added. Part 2 methods marked TODO. Commit `6719e50`.
- Goal: implement the first half of the tactical AI module — the largest single AI TU at ~20,813 lines of decomp. This Part 1 focuses on the core lifecycle (constructor, destructor, update tick) and group management methods. Part 2 will be created after Part 1 completes to handle the remaining combat targeting/resolution methods.
- Implement (decomp-first from `taitacmd.cpp.decomp`, first ~half of the file):
  - **Base `TacticalAIModule`** from `aitacmod.cpp.decomp` (~39 lines): constructor, destructor, virtual stubs (tiny base).
  - **`TacticalAIGroup`** — if referenced by tactical methods, transliterate from the related decomp. Check `src/game/include/TacticalAIGroup.h` for the class layout.
  - **`TribeTacticalAIModule` Part 1:** constructor, destructor, load-constructor, `update()` (the main tactical tick), group lifecycle methods (`addGroup`, `removeGroup`, `findGroup`, `getGroup`, `createGroup`), and immediate helper methods called by `update()`.
  - If the decomp file is too large, prioritize: constructor → update → group management → save/load. Mark remaining methods with `// TODO: Part 2` comments.
- Where:
  - Add `src/game/src/TacticalAIModule.cpp` (new file — may be very small base).
  - Add `src/game/src/TacticalAIGroup.cpp` (new file if TacticalAIGroup has its own TU in decomp).
  - Add `src/game/src/TribeTacticalAIModule.cpp` (new file — main implementation).
  - Update respective headers under `src/game/include/` (declarations only; do not change member layout).
  - Add all new .cpp files to `build.bat`.
- Source of truth: `src/game/decomp/aitacmod.cpp.decomp` + `.asm`, `src/game/decomp/taitacmd.cpp.decomp` + `.asm`, `src/game/decomp/TacticalAIGroup.decomp` + `.asm`, `src/game/decomp/TribeTacticalAIModule.decomp` + `.asm`.
- Non-overlap: do NOT touch any other AI module .cpp files.
- Done when: `TribeTacticalAIModule` constructor, `update()`, and group management methods compile/link cleanly and match source-of-truth control flow. Remaining combat methods may be marked TODO for Part 2.

## Task 208 — AI module: implement `TribeInformationAIModule` parity — Part 1 (core lifecycle + scouting)
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-5 (`aoe1_clone_5`)
- Status note: `InformationAIModule.cpp` + `TribeInformationAIModule.cpp` added. Part 2 methods marked TODO. Commit `9e76b50`.
- Goal: implement the first half of the information/scouting AI module (~10,885 lines of decomp total). This Part 1 focuses on the core lifecycle and primary scouting/intelligence methods. Part 2 will be created after Part 1 completes.
- Implement (decomp-first from `taiinfmd.cpp.decomp`, first ~half of the file):
  - **Base `InformationAIModule`** from `aiinfmod.cpp.decomp` (~39 lines): constructor, destructor, virtual stubs (tiny base).
  - **`TribeInformationAIModule` Part 1:** constructor, destructor, load-constructor, `update()` (the main information tick), primary scouting/exploration methods, and immediate helper methods called by `update()`.
  - If the decomp file is too large, prioritize: constructor → update → core scouting helpers → save/load. Mark remaining methods with `// TODO: Part 2` comments.
- Where:
  - Add `src/game/src/InformationAIModule.cpp` (new file — may be very small base).
  - Add `src/game/src/TribeInformationAIModule.cpp` (new file — main implementation).
  - Update respective headers under `src/game/include/` (declarations only; do not change member layout).
  - Add both new .cpp files to `build.bat`.
- Source of truth: `src/game/decomp/aiinfmod.cpp.decomp` + `.asm`, `src/game/decomp/taiinfmd.cpp.decomp` + `.asm`, plus class-level `.decomp` files.
- Non-overlap: do NOT touch any other AI module .cpp files.
- Done when: `TribeInformationAIModule` constructor, `update()`, and core scouting methods compile/link cleanly and match source-of-truth control flow. Remaining methods may be marked TODO for Part 2.

## Task 209 — Unit AI: implement Tribe unit AI module dispatch + all unit-type AI module stubs
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-3 (`aoe1_clone_3`)
- Status note: `TribeUnitAIModules.cpp` + `TribeUnitAIModuleTypes.cpp` added, 15 type headers updated, `TRIBE_Combat_Object::initUnitAI` wired. Commit `b1ce3b7`.
- Goal: implement the unit-level AI dispatch module and all 15 unit-type-specific AI module constructors/destructors. The dispatch module (`taiuaimd.cpp.decomp`, ~4273 lines) routes AI decisions to the correct unit-type module based on unit class. The 15 unit-type modules are each only ~25 lines (constructor/destructor pairs with minimal logic).
- Implement (decomp-first, ~4648 lines total):
  - **Unit AI dispatch module** from `taiuaimd.cpp.decomp` (~4273 lines): unit-type routing logic, module creation factory, update dispatch to type-specific handlers.
  - **All 15 unit-type AI modules** (~25 lines each): `TribeSoldierUnitAIModule`, `TribeRangedUnitAIModule`, `TribeRangedUnitAIModule2`, `TribeCivilianUnitAIModule`, `TribeBuildingUnitAIModule`, `TribePriestUnitAIModule`, `TribeTowerUnitAIModule`, `TribeElephantUnitAIModule`, `TribeFishingShipUnitAIModule`, `TribeTradeShipUnitAIModule`, `TribeTransportShipUnitAIModule`, `TribeLionUnitAIModule`, `TribePreditorUnitAIModule`, `TribeHuntedAnimalUnitAIModule`, `TribeArtifactUnitAIModule`.
  - These tiny modules can be grouped into one .cpp file or split into individual files — follow whatever pattern keeps `build.bat` manageable.
- Where:
  - Add `src/game/src/TribeUnitAIModules.cpp` (new file for the dispatch module — or name per the decomp TU).
  - Add individual .cpp files for each unit-type module, or group them into `src/game/src/TribeUnitAIModuleTypes.cpp`.
  - Update respective headers under `src/game/include/` (declarations only; do not change member layout). Headers already exist for all 15 types (e.g., `TribeSoldierUnitAIModule.h`, etc.) plus `TribeUnitAIModules.h`.
  - Add all new .cpp files to `build.bat`.
- Source of truth: `src/game/decomp/taiuaimd.cpp.decomp` + `.asm`, plus each unit-type's `.decomp` + `.asm` file (e.g., `TribeSoldierUnitAIModule.decomp`).
- Non-overlap: do NOT touch `UnitAIModule.cpp` (already fully verified) or any other AI module .cpp files.
- Done when: the dispatch module routes unit AI correctly per source-of-truth, all 15 unit-type modules compile/link cleanly, and `build.bat` includes all new files.

## Task 210 — AI playbook data: implement `AIPlay` group/phase/command/trigger support classes
- [x] Assigned to agent
- [x] Finished
- Assignment note: worker-1 (`aoe1_clone_1`)
- Status note: `AIPlayData.cpp` added with all 6 play data classes. Commit `2eb1aaa`.
- Goal: implement the AI playbook data structure support classes that define AI play scripts loaded by `AIPlayBook::loadPlays`. These classes represent the structured play definitions (groups of phases with commands and triggers) that drive strategic AI behavior.
- Implement: check which of these classes already have implementations vs need new .cpp files:
  - `AIPlay` (from `src/game/include/AIPlay.h`)
  - `AIPlayGroup` (from `src/game/include/AIPlayGroup.h`)
  - `AIPlayPhase` (from `src/game/include/AIPlayPhase.h`)
  - `AIPlayPhaseCommand` (from `src/game/include/AIPlayPhaseCommand.h`)
  - `AIPlayPhaseTrigger` (from `src/game/include/AIPlayPhaseTrigger.h`)
  - `AIPlayStatus` (from `src/game/include/AIPlayStatus.h`)
  - Related: `Item_Avail` (from `src/game/include/Item_Avail.h`), `Trade_Avail` (from `src/game/include/Trade_Avail.h`)
  - Check `aipbook.cpp.decomp` and `taipbook.cpp.decomp` for any methods belonging to these classes that are not yet implemented.
  - If these classes are trivial data structures (just constructors/destructor/accessors), they may already be inlined or handled through existing playbook code. Verify and implement only what's missing.
- Where:
  - Add new .cpp files as needed under `src/game/src/`.
  - Update headers only for missing method declarations (do not change member layout).
  - Add any new .cpp files to `build.bat`.
- Source of truth: `src/game/decomp/aipbook.cpp.decomp` + `.asm`, `src/game/decomp/taipbook.cpp.decomp` + `.asm`, `src/game/decomp/AIPlayBook.decomp`, `src/game/decomp/TribeAIPlayBook.decomp`, plus individual class `.decomp` files if they exist.
- Non-overlap: do NOT touch `AIPlayBook.cpp` or `TribeAIPlayBook.cpp` (already implemented).
- Done when: all AI play data classes compile/link cleanly and the playbook system can instantiate complete play structures.

## Task 211 — CRITICAL: Technology effects system parity — `RGE_Effects::do_effect()` + `RGE_Player` effect helper methods

- [x] Finished
- [x] Assigned to agent
- Assignment note: worker-6 (`aoe1_clone_6`)
- Status note: `RGE_Effects::do_effect()` filled (6 cases), 5 `RGE_Player` methods added + `RGE_Master_Static_Object::make_available`. Commit `6ca1802`.

### Priority: P0 — This is the #1 non-AI gameplay blocker. Without this, researching technologies does NOTHING (no stat changes, no unit upgrades, no age advancement effects).

### Problem
`RGE_Effects::do_effect(short, RGE_Player*)` at line 75 of `src/game/src/RGE_Effects.cpp` is completely empty `{}`. This is the virtual base method that applies technology effect commands to a player. When a technology finishes researching, the call chain is:
1. `TRIBE_Action_Make_Tech` completes → `TRIBE_Player_Tech::research()` → `TRIBE_Tech::do_tech()` → `TRIBE_Effects::do_effect()`
2. `TRIBE_Effects::do_effect()` (in `TRIBE_World_types.cpp` line 4224) handles command type `'f'` (tech enable/disable) then calls `RGE_Effects::do_effect()` for all other command types.
3. `RGE_Effects::do_effect()` is **empty** → attribute modifications, unit availability, object copies are ALL silently dropped.

### What to implement

#### Part A: `RGE_Effects::do_effect()` in `src/game/src/RGE_Effects.cpp`
Decomp: `src/game/decomp/effects.cpp.decomp` @ offset 0x004495C0 (lines 256-318).

The method iterates `effects[param_1].effect_list[]` and switches on `command`:
- Case 0 (`'\0'`): calls `param_2->modify_tobj(change_num1, change_num2, change_amount, (uchar)change_num3)`
- Case 1 (`'\x01'`): if `change_num1 >= 0`: if `change_num2 == 0` calls `param_2->new_attribute_num(change_num1, change_amount)`, else calls the player's virtual method at vtable offset 0x78 with args `(change_num1, change_amount, 0)`. **NOTE**: vtable offset 0x78 = the 30th virtual entry on `RGE_Player`. Check `src/game/include/RGE_Player.h` to identify which virtual method this is (likely `add_attribute_num` or a resource modification method). If the virtual at that offset doesn't exist yet, investigate `src/game/decomp/player.cpp.asm` at offset 0x004495C0 to confirm.
- Case 2 (`'\x02'`): if `change_num1 >= 0` calls `param_2->make_available(change_num1, (uchar)change_num2)`
- Case 3 (`'\x03'`): calls `param_2->copy_obj(change_num1, change_num2)`
- Case 4 (`'\x04'`): calls `param_2->modify_tobj_delta(change_num1, change_num2, change_amount, (uchar)change_num3)`
- Case 5 (`'\x05'`): calls `param_2->modify_tobj_percent(change_num1, change_num2, change_amount, (uchar)change_num3)`

`RGE_Player::new_attribute_num(short, float)` is ALREADY implemented at line 740 of `RGE_Player.cpp`.

#### Part B: Missing `RGE_Player` methods in `src/game/src/RGE_Player.cpp`
These 5 methods are called by `do_effect()` and do NOT exist yet. All are in `src/game/decomp/player.cpp.decomp`:

1. **`RGE_Player::make_available(short param_1, uchar param_2)`** @ offset 0x004707D0 (decomp line ~1911). Simple: if `master_objects[param_1]` is not null, call `master_objects[param_1]->make_available(param_2)`.

2. **`RGE_Player::modify_tobj(short param_1, short param_2, float param_3, uchar param_4)`** @ offset 0x00470810 (decomp line ~2429). If `param_1 < 0`, iterates ALL master objects matching `object_group == param_2` and calls virtual method at vtable offset 0x08 on master and vtable offset 0x48 on each runtime object. If `param_1 >= 0`, applies to the single master object at index `param_1`. The virtual calls are `set_attribute`-type methods on master/runtime objects — use the ASM (`player.cpp.asm` @ 0x00470810) to confirm the exact vtable offsets and map them to the correct virtual method names in `RGE_Master_Static_Object.h` and `RGE_Static_Object.h`.

3. **`RGE_Player::modify_tobj_delta(short param_1, short param_2, float param_3, uchar param_4)`** @ offset 0x00470940 (decomp line ~2484). Same pattern as `modify_tobj` but calls vtable offset 0x0C on master and 0x4C on runtime objects (delta/add mode).

4. **`RGE_Player::modify_tobj_percent(short param_1, short param_2, float param_3, uchar param_4)`** @ offset 0x00470A40 (decomp line ~2540). Same pattern, vtable offset 0x10 on master and 0x50 on runtime objects (percent/multiply mode).

5. **`RGE_Player::copy_obj(short param_1, short param_2)`** @ offset 0x00470B40 (decomp line ~2596). Copies master_objects[param_2]'s data onto master_objects[param_1] and all its runtime instances. Calls vtable offset 0x04 on master and 0x58 on runtime objects.

### Files to modify
- `src/game/src/RGE_Effects.cpp` — implement `do_effect()` body (replace the empty `{}`)
- `src/game/src/RGE_Player.cpp` — add 5 new method implementations
- `src/game/include/RGE_Player.h` — add method declarations for the 5 new methods (do NOT change member variables or virtual order)
- `src/game/include/RGE_Effects.h` — only if `do_effect` declaration needs fixing (it's already declared as virtual)

### Source of truth
- `src/game/decomp/effects.cpp.decomp` + `effects.cpp.asm`
- `src/game/decomp/player.cpp.decomp` + `player.cpp.asm`

### Non-overlap
- Do NOT touch `TRIBE_World_types.cpp` (TRIBE_Effects::do_effect and do_tech_effect are already correct there).
- Do NOT touch `TRIBE_Player.cpp` (handled by Task 200).

### Done when
- `RGE_Effects::do_effect()` has the full 6-case switch statement matching the decomp.
- All 5 player methods are implemented with full parity from the decomp.
- The vtable virtual calls in modify_tobj/modify_tobj_delta/modify_tobj_percent/copy_obj are resolved to named method calls (not raw pointer arithmetic).
- Project compiles and links cleanly with `build.bat`.

## Task 212 — Master combat object sound parity: implement `play_command_sound` / `play_move_sound`

- [x] Finished
- [x] Assigned to agent
- Assignment note: worker-6 (`aoe1_clone_6`)
- Status note: `play_command_sound`/`play_move_sound` + full `RGE_Master_Action_Object` audit (destructor, copy_obj, modify*, save, make_new_obj, etc.). Commit `e4f7653`.

### Problem
Unit command acknowledgment sounds (the voice line when you click a unit / tell it to move) are completely silent. The `play_command_sound()` and `play_move_sound()` methods are empty stubs throughout the object hierarchy.

### What to implement

The decomp shows that the **only non-trivial implementations** are on `RGE_Master_Combat_Object`:

**`RGE_Master_Combat_Object::play_command_sound()`** — from `src/game/decomp/m_ac_obj.cpp.decomp` line ~614:
```
if (this->command_sound != NULL) {
    RGE_Sound::play(this->command_sound, 1);
}
```

**`RGE_Master_Combat_Object::play_move_sound()`** — from `src/game/decomp/m_ac_obj.cpp.decomp` line ~632:
```
if (this->move_sound != NULL) {
    RGE_Sound::play(this->move_sound, 1);
}
```

All base-class versions (`RGE_Master_Static_Object`, `RGE_Master_Moving_Object`, `RGE_Animated_Object`) are **intentionally empty** in the original binary — do NOT add code to those.

The runtime object hierarchy (`RGE_Action_Object`, `TRIBE_Building_Object`) delegates to the master object through virtual dispatch. Check that the existing forwarder chain correctly routes to the master's implementation. The decomp shows `TRIBE_Building_Object::play_command_sound()` does a virtual dispatch call through the master pointer — verify this works in the current code.

### Additional methods from m_ac_obj.cpp.decomp
The `m_ac_obj.cpp.decomp` file is 648 lines. Beyond the sound methods, audit ALL functions in this decomp and check which ones are already implemented vs still stubs. Implement any remaining missing methods. Key functions to check:
- Constructor(s) and destructor
- `setup()` method
- `save()` method
- Any attribute modification virtuals (`set_attribute`, `add_attribute`, etc.)
- `make_available()` on master combat object
- `copy_obj()` on master combat object

### Files to modify
- `src/game/src/RGE_Master_Static_Object.cpp` — if master combat methods are here, OR
- `src/game/src/RGE_Master_Derived_Stubs.cpp` — if derived master methods are here
- Check which file currently has `RGE_Master_Combat_Object` method implementations and add the sound methods there
- `src/game/include/RGE_Master_Combat_Object.h` — add declarations if missing (do NOT change member layout)
- Possibly `src/game/src/rge_object_virtual_stubs.cpp` — if runtime object forwarders need fixing (only touch the sound-related entries)

### Source of truth
- `src/game/decomp/m_ac_obj.cpp.decomp` + `m_ac_obj.cpp.asm`

### Non-overlap
- Do NOT touch `RGE_Effects.cpp` or `RGE_Player.cpp` (Task 211).
- Do NOT touch `TRIBE_Master_Objects.cpp` (TRIBE master objects are separate).
- Be careful with `rge_object_virtual_stubs.cpp` — only modify the `play_command_sound` / `play_move_sound` entries.

### Done when
- `RGE_Master_Combat_Object::play_command_sound()` and `play_move_sound()` have real implementations matching decomp.
- All other non-trivial methods from `m_ac_obj.cpp.decomp` are implemented.
- Runtime objects correctly delegate sound calls to their master objects.
- Project compiles and links cleanly with `build.bat`.

## Task 213 — AI module: implement `TribeTacticalAIModule` parity — Part 2 (combat targeting + resolution)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `13c52c3` (641 insertions). Tactical Part 2 scaffolding and group callbacks.
- Assignment note: worker-3 (`aoe1_clone_3`)
- Goal: implement the second half of the tactical AI module (~10,000+ remaining lines from `taitacmd.cpp.decomp`). Part 1 (Task 207) landed constructor, update(), group lifecycle, and save/load skeleton. Part 2 covers combat targeting, attack resolution, retreat/flee logic, and remaining helper methods marked `// TODO: Part 2`.
- Implement (decomp-first from `taitacmd.cpp.decomp`, second half):
  - All methods currently marked `// TODO: Part 2` in `TribeTacticalAIModule.cpp`.
  - Combat targeting methods: target selection, attack group formation, threat assessment.
  - Resolution/response methods: retreat, flee, regroup, notify callbacks.
  - Any `TacticalAIGroup` methods marked TODO from Part 1 (load-constructor body, `save`, `notify`, `doSomething`, commander callbacks).
- Where:
  - `src/game/src/TribeTacticalAIModule.cpp` (extend existing file)
  - `src/game/src/TacticalAIGroup.cpp` (extend existing file)
  - Update headers only for missing declarations.
- Source of truth: `src/game/decomp/taitacmd.cpp.decomp` + `.asm`, `src/game/decomp/TacticalAIGroup.decomp` + `.asm`.
- Non-overlap: do NOT touch any other AI module .cpp files.
- Done when: all `// TODO: Part 2` markers removed, all methods from `taitacmd.cpp.decomp` implemented, compile/link clean.

## Task 214 — AI module: implement `TribeInformationAIModule` parity — Part 2 (map analysis + enemy tracking)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `79a0e56` (1665 insertions). Full Part 2 implementation.
- Assignment note: worker-6 (`aoe1_clone_6`)
- Goal: implement the second half of the information AI module (~5,400+ remaining lines from `taiinfmd.cpp.decomp`). Part 1 (Task 208) landed constructor, update(), and core scouting helpers. Part 2 covers map analysis, enemy base detection, resource mapping, and remaining helper methods marked `// TODO: Part 2`.
- Implement (decomp-first from `taiinfmd.cpp.decomp`, second half):
  - All methods currently marked `// TODO: Part 2` in `TribeInformationAIModule.cpp`.
  - Map analysis methods: terrain evaluation, zone classification, resource mapping.
  - Enemy tracking: base detection, military strength estimation, technology scouting.
  - Any remaining save/load state methods from Part 1 that were deferred.
- Where:
  - `src/game/src/TribeInformationAIModule.cpp` (extend existing file)
  - Update headers only for missing declarations.
- Source of truth: `src/game/decomp/taiinfmd.cpp.decomp` + `.asm`.
- Non-overlap: do NOT touch any other AI module .cpp files.
- Done when: all `// TODO: Part 2` markers removed, all methods from `taiinfmd.cpp.decomp` implemented, compile/link clean.

## Task 215 — TRIBE AI build-module dependency parity: retire helper stubs in `TribeBuildAIModule.cpp`
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `bbe3146` (342 insertions). Helper stubs replaced with source-backed implementations.
- Assignment note: worker-1 (`aoe1_clone_1`)
- Goal: remove helper-level TODO stubs currently short-circuiting AI build/train/research bookkeeping during in-game updates. (Retried from stale Task 196.)
- Implement:
  - Replace local helper stubs with source-backed behavior: `tribe_build_ai_detask`, `tribe_build_ai_is_moveable`, `tribe_build_ai_clear_area`, `tribe_build_ai_remove_lot`, `tribe_build_ai_update_needed_resources`.
  - Remove/resolve the partial-parity notes in `addBuiltItem`, `cancelBuildItem`, `addTrainedUnit`, `cancelTrainUnit`, `addResearch`, and `cancelResearch` that are currently gated by these helpers.
  - Keep scope limited to `TribeBuildAIModule` and directly required declarations; do not modify `TRIBE_Player` command issuance flow.
- Where:
  - `src/game/src/TribeBuildAIModule.cpp`
  - `src/game/include/TribeBuildAIModule.h` (declarations only if required)
- Source of truth: `src/game/decomp/taibldmd.cpp.decomp` + `.asm`.
- Done when: all TODO stubs in `TribeBuildAIModule.cpp` are replaced with source-backed implementations and compile/link cleanly.

## Task 216 — In-game screen parity follow-up: finalize remaining `TRIBE_Screen_Game` TODO blocks
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `26f9b1d` (462 insertions). handle_game_update, player_changed, and setup_buttons finalized.
- Assignment note: worker-4 (`aoe1_clone_4`)
- Goal: close the remaining `TRIBE_Screen_Game` in-game parity gaps (retried from stale Task 194): world-step/game-over branch, player-change civ-refresh branch, and command-panel refresh slice.
- Implement:
  - Transliterate the remaining world-step/game-over branch in `handle_game_update` (decomp block around `0x00496800`) currently marked TODO.
  - Transliterate the remaining civilization theme/picture refresh branch in `player_changed` (decomp block around `0x00498AD0`) currently marked TODO.
  - Audit/finalize the command-panel refresh helper in `setup_buttons` (block around `0x004996C0`).
  - Remove scoped TODO markers only after decomp/ASM-backed parity validation.
- Where:
  - `src/game/src/TRIBE_Screen_Game.cpp`
  - `src/game/include/TRIBE_Screen_Game.h` (declarations only if required)
- Source of truth: `src/game/decomp/scr_game.cpp.decomp` + `src/game/decomp/scr_game.cpp.asm`.
- Done when: all three scoped TODO markers are removed and behavior is decomp/ASM-backed.

## Task 217 — AI module TODO cleanup: retire remaining stubs in ConstructionAIModule + TribeConstructionAIModule + BuildAIModule
- [x] Assigned to agent
- [ ] Finished
- Assignment note: worker-2 (`aoe1_clone_2`)
- Goal: replace all remaining TODO stubs in the construction and build AI modules with source-backed implementations from the decomp.
- Where: `ConstructionAIModule.cpp`, `TribeConstructionAIModule.cpp`, `BuildAIModule.cpp`
- Source of truth: `aiconmod.cpp.decomp`, `taiconmd.cpp.decomp`, `aibldmod.cpp.decomp` + `.asm` files.
- Non-overlap: do NOT touch `TribeBuildAIModule.cpp` (Task 215).
- Done when: all `// TODO` markers in the three scoped files replaced with source-backed implementations and compile/link clean.

## Task 218 — TRIBE_Player massive parity tranche: civ setup + commands + tech helpers (~5500 lines of decomp gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `351bb90` (1989 insertions). 41 method declarations added to header, 1948 lines of implementations.
- Assignment note: worker-2 (`aoe1_clone_2`)
- Goal: close the ~5500-line gap between `tplayer.cpp.decomp` (6343 lines) and `TRIBE_Player.cpp` (828 lines). This covers 36 missing methods including all 15 civilization setup methods, 6 command methods, and 15 tech/research/trade helpers.
- Implement (decomp-first from `tplayer.cpp.decomp`):
  - **Civilization setup (15 methods):** `setupAssyrian`, `setupBabylonian`, `setupCarthaginian`, `setupChoson`, `setupEgyptian`, `setupGreek`, `setupHittite`, `setupMacedonian`, `setupMinoan`, `setupPalmyran`, `setupPersian`, `setupPhoenician`, `setupRoman`, `setupShang`, `setupSumerian`, `setupYamato`. These set civ-specific bonuses/modifiers.
  - **Command methods (6):** `command_building_cancel`, `command_building_make_obj`, `command_building_make_tech`, `command_delete_object`, `command_trade_attribute`, `find_obj`.
  - **Tech/research helpers (15):** `check_tech_cost`, `pay_tech_cost`, `tech_cost`, `researchAvailable`, `researchCost`, `researchEverAvailable`, `researchState`, `objectAvailable`, `interface_item_avail`, `interface_tech_avail`, `interface_trade_avail`, `get_achievement`, `intelligentBuildListAndRulesSelection`, `intelligentCivSelection`.
- Where:
  - `src/game/src/TRIBE_Player.cpp` (extend existing file)
  - `src/game/include/TRIBE_Player.h` (declarations only)
- Source of truth: `src/game/decomp/tplayer.cpp.decomp` + `tplayer.cpp.asm`.
- Non-overlap: do NOT touch `TRIBE_Player_Tech.cpp` or `RGE_Player.cpp`.
- Done when: all 36 missing methods implemented from decomp, compile/link clean. This is a large task — expect 1500+ lines of new code.

## Task 219 — TRIBE_Screen_Game massive parity tranche: fill the 7400-line decomp gap
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `8d44734` (1204 insertions). Command/button/input routing + UI message paths implemented. Remaining sections marked TODO Part 2.
- Assignment note: worker-6 (`aoe1_clone_6`)
- Goal: close the ~7400-line gap between `scr_game.cpp.decomp` (9061 lines) and `TRIBE_Screen_Game.cpp` (1638 lines). This covers the bulk of in-game UI handling: button/panel setup, minimap interactions, unit command routing, chat, diplomacy panel, and achievement display.
- Implement (decomp-first from `scr_game.cpp.decomp`):
  - Enumerate ALL functions in `scr_game.cpp.decomp` that are NOT yet in `TRIBE_Screen_Game.cpp`.
  - Prioritize by: button/panel setup methods > command routing > chat/diplomacy > achievement display.
  - Each function should be transliterated from the decomp with `// Fully verified` markers.
- Where:
  - `src/game/src/TRIBE_Screen_Game.cpp` (extend existing file)
  - `src/game/include/TRIBE_Screen_Game.h` (declarations only)
- Source of truth: `src/game/decomp/scr_game.cpp.decomp` + `scr_game.cpp.asm`.
- Non-overlap: do NOT touch `RGE_Main_View.cpp` (Task 193 handled command pipeline).
- Done when: the implementation gap is cut by at least 3000 lines (half the gap). Mark any remaining unimplemented methods with `// TODO: Part 2` comments.

## Task 220 — RGE_Player parity tranche: fill remaining ~2500-line decomp gap
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `109f835` (249 insertions). RGE_Player methods implemented.
- Assignment note: worker-5 (`aoe1_clone_5`)
- Goal: close the ~2500-line gap between `player.cpp.decomp` (4242 lines) and `RGE_Player.cpp` (1760 lines). This covers base player methods for object management, attribute handling, diplomacy state, and save/load.
- Implement (decomp-first from `player.cpp.decomp`):
  - Enumerate ALL functions in `player.cpp.decomp` that are NOT yet in `RGE_Player.cpp`.
  - Transliterate each from the decomp.
  - Focus on: object management (create/destroy master/runtime objects), attribute helpers, diplomacy state, save/load methods.
- Where:
  - `src/game/src/RGE_Player.cpp` (extend existing file)
  - `src/game/include/RGE_Player.h` (declarations only)
- Source of truth: `src/game/decomp/player.cpp.decomp` + `player.cpp.asm`.
- Non-overlap: do NOT touch `TRIBE_Player.cpp` (Task 218).
- Done when: all missing methods from `player.cpp.decomp` implemented, compile/link clean.

## Task 221 — TRIBE_Game parity tranche: fill remaining ~5600-line decomp gap (tribegam.cpp)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `52d46ba` (355 insertions). TRIBE_Game methods implemented.
- Assignment note: worker-1 (`aoe1_clone_1`)
- Goal: close the ~5600-line gap between `tribegam.cpp.decomp` (8725 lines) and `tribegam.cpp` (3057 lines). This covers game setup, save/load, campaign flow, multiplayer setup, and cheat processing.
- Implement (decomp-first from `tribegam.cpp.decomp`):
  - Enumerate ALL functions in `tribegam.cpp.decomp` that are NOT yet in `tribegam.cpp`.
  - Prioritize: game setup/initialization > save/load game > campaign management > multiplayer setup.
  - Each function should be transliterated from the decomp.
- Where:
  - `src/game/src/tribegam.cpp` (extend existing file)
  - `src/game/include/TRIBE_Game.h` (declarations only)
- Source of truth: `src/game/decomp/tribegam.cpp.decomp` + `tribegam.cpp.asm`.
- Done when: the implementation gap is cut by at least 2500 lines. Mark any remaining unimplemented methods with `// TODO` comments.

## Task 222 — com_hand.cpp communication handler parity (~5500-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `258dbb0` (3807 insertions, 70 new wrappers). com_hand.cpp now 6084 lines. Gap cut by 2500+ lines.
- Assignment note: worker-3 (`aoe1_clone_3`)
- Goal: close the ~5500-line gap between `com_hand.cpp.decomp` (8394 lines) and `com_hand.cpp` (2889 lines). The communication handler routes player commands (move, attack, build, etc.) to the game engine. This is critical game infrastructure.
- Implement (decomp-first from `com_hand.cpp.decomp`):
  - Enumerate ALL functions in `com_hand.cpp.decomp` that are NOT yet in `com_hand.cpp`.
  - Focus on: command dispatch (the big switch statement that routes command types), multiplayer sync, command serialization/deserialization, queue management.
  - Each function should be transliterated from the decomp with `// Fully verified` markers.
  - This is a LARGE task — aim for 1500+ lines of new code.
- Where:
  - `src/game/src/com_hand.cpp` (extend existing file)
  - Any relevant headers in `src/game/include/` (declarations only)
- Source of truth: `src/game/decomp/com_hand.cpp.decomp` + `com_hand.cpp.asm`.
- Non-overlap: do NOT touch `basegame.cpp`, `tribegam.cpp`, or any player files.
- Done when: the implementation gap is cut by at least 2500 lines. Mark any remaining methods with `// TODO` comments.

## Task 223 — RGE_Static_Object massive parity tranche (~3800-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `ad94e29` (610 insertions). RGE_Static_Object missing methods implemented.
- Assignment note: worker-4 (`aoe1_clone_4`)
- Goal: close the ~3800-line gap between `stat_obj.cpp.decomp` (7238 lines) and `RGE_Static_Object.cpp` (3429 lines). RGE_Static_Object is the base class for all game objects (buildings, trees, resources, etc.). Its virtual methods drive core gameplay.
- Implement (decomp-first from `stat_obj.cpp.decomp`):
  - Enumerate ALL functions in `stat_obj.cpp.decomp` that are NOT yet in `RGE_Static_Object.cpp`.
  - Focus on: virtual method implementations (save/load, attribute getters/setters, damage/heal, garrison, selection), constructor/destructor parity, and utility methods.
  - Each function should be transliterated from the decomp with `// Fully verified` markers.
  - Also check if any methods are in `rge_object_virtual_stubs.cpp` that should be moved to the proper file.
- Where:
  - `src/game/src/RGE_Static_Object.cpp` (extend existing file)
  - `src/game/include/RGE_Static_Object.h` (declarations only)
- Source of truth: `src/game/decomp/stat_obj.cpp.decomp` + `stat_obj.cpp.asm`.
- Non-overlap: do NOT touch `RGE_Moving_Object.cpp`, `TRIBE_Combat_Object.cpp`, or any derived object files.
- Done when: all missing methods from `stat_obj.cpp.decomp` implemented, compile/link clean.

## Task 224 — basegame.cpp parity tranche: game init/shutdown + remaining methods (~4800-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `fc72998` (1204 insertions via CODEX CLI). basegame.cpp gap significantly reduced. Codex performed full review pass with 5+3 sub-agents.
- Assignment note: worker-5 (`aoe1_clone_5`) — **CODEX CLI TEST** (first codex exec dispatch)
- Goal: close the ~4800-line gap between `basegame.cpp.decomp` (7841 lines) and `basegame.cpp` (2979 lines). The base game class handles initialization, shutdown, main loop timing, world creation, and game state management.
- Implement (decomp-first from `basegame.cpp.decomp`):
  - Enumerate ALL functions in `basegame.cpp.decomp` that are NOT yet in `basegame.cpp`.
  - Focus on: game initialization sequence, world creation/destruction, main loop update, timing/speed control, debug methods.
  - Each function should be transliterated from the decomp.
- Where:
  - `src/game/src/basegame.cpp` (extend existing file)
  - `src/game/include/RGE_Base_Game.h` (declarations only)
- Source of truth: `src/game/decomp/basegame.cpp.decomp` + `basegame.cpp.asm`.
- Done when: the implementation gap is cut by at least 2000 lines.

## Task 225 — RGE_Main_View + view.cpp parity tranche (~4800-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `91bd511` (670 insertions). view.cpp + supporting files expanded. Gap still ~4100.
- Assignment note: worker-1 (`aoe1_clone_1`)
- Goal: close the ~4800-line gap between `view.cpp.decomp` (7696 lines) and the view implementation files (~2877 lines). The view system handles scrolling, zooming, rendering delegation, and input routing.
- Implement (decomp-first from `view.cpp.decomp`):
  - Enumerate ALL functions in `view.cpp.decomp` that are NOT yet in `view.cpp` or `RGE_Main_View.cpp`.
  - Focus on: scroll/zoom methods, rendering coordination, input event routing, minimap interaction.
  - Each function should be transliterated from the decomp.
- Where:
  - `src/game/src/view.cpp` and/or `src/game/src/RGE_Main_View.cpp` (extend existing)
  - Any relevant headers (declarations only)
- Source of truth: `src/game/decomp/view.cpp.decomp` + `view.cpp.asm`.
- Done when: the implementation gap is cut by at least 2000 lines.

## Task 226 — RGE_Map parity tranche: terrain + pathfinding helpers (~1800-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `e0b2d70` (350 insertions). RGE_Map terrain/elevation/tile/pathfinding helpers implemented.
- Goal: close the ~1800-line gap between `map.cpp.decomp` (4507 lines) and `RGE_Map.cpp` (2680 lines). The map system handles terrain data, tile queries, elevation, and pathfinding support.
- Implement (decomp-first from `map.cpp.decomp`):
  - Enumerate ALL functions in `map.cpp.decomp` that are NOT yet in `RGE_Map.cpp`.
  - Focus on: terrain query methods, elevation helpers, tile-to-world coordinate conversions, pathfinding support methods.
- Where:
  - `src/game/src/RGE_Map.cpp` (extend existing file)
  - `src/game/include/RGE_Map.h` (declarations only)
- Source of truth: `src/game/decomp/map.cpp.decomp` + `map.cpp.asm`.
- Done when: all missing methods implemented, compile/link clean.

## Task 227 — TRIBE_Screen_Sed scenario editor parity tranche (~5700-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `f166adf` (6090 insertions!). TRIBE_Screen_Sed went from 203→6293 lines. Nearly entire editor implemented. Self-reviewed due to 429 quota on sub-agents.
- Goal: close the ~5700-line gap between `scr_sed.cpp.decomp` (5907 lines) and `TRIBE_Screen_Sed.cpp` (203 lines). The scenario editor is nearly empty — this task creates the bulk of it.
- Implement (decomp-first from `scr_sed.cpp.decomp`):
  - Enumerate ALL functions in `scr_sed.cpp.decomp`.
  - Focus on: editor initialization, terrain painting, unit/building placement, trigger setup, save/load scenario.
  - Each function should be transliterated from the decomp.
  - This is a LARGE task — expect 2000+ lines of new code.
- Where:
  - `src/game/src/TRIBE_Screen_Sed.cpp` (extend existing file)
  - `src/game/include/TRIBE_Screen_Sed.h` (declarations only)
- Source of truth: `src/game/decomp/scr_sed.cpp.decomp` + `scr_sed.cpp.asm`.
- Done when: the implementation gap is cut by at least 3000 lines.

## Task 228 — TribeUnitAIModule massive parity: unit AI decision-making (~10000-line gap across 2 decomps)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `26ba310` (814 insertions). UnitAIModule + TribeUnitAIModuleTypes expanded. Still massive gap remaining (~9000+ lines). TODO markers on deep parity paths.
- [ ] Finished
- Goal: close the massive gap in the unit AI module system. Two decomps feed this module: `aiuaimod.cpp.decomp` (6558 lines) maps to `TribeUnitAIModules.cpp` (59 lines) and `UnitAIModule.cpp` (340 lines); `taiuaimd.cpp.decomp` (4273 lines) maps to `TribeUnitAIModuleTypes.cpp` (155 lines). Combined gap is ~10000 lines. This controls individual unit AI decisions (attack, gather, explore, flee, etc.).
- Implement (decomp-first):
  - Start with `aiuaimod.cpp.decomp` → populate `TribeUnitAIModules.cpp` or `UnitAIModule.cpp` with all missing functions.
  - Then `taiuaimd.cpp.decomp` → populate `TribeUnitAIModuleTypes.cpp` with all missing unit type AI methods.
  - Focus on: unit behavior state machines, target selection, action prioritization, flee/attack/gather decision logic.
  - Each function should be transliterated from the decomp with `// Fully verified` markers.
  - This is a MASSIVE task — aim for 3000+ lines of new code.
- Where:
  - `src/game/src/TribeUnitAIModules.cpp` and/or `src/game/src/UnitAIModule.cpp`
  - `src/game/src/TribeUnitAIModuleTypes.cpp`
  - Relevant headers in `src/game/include/`
- Source of truth: `src/game/decomp/aiuaimod.cpp.decomp` + `taiuaimd.cpp.decomp` + `.asm` counterparts.
- Non-overlap: do NOT touch TribeTacticalAIModule, TribeInformationAIModule, TribeStrategyAIModule, or any screen/player files.
- Done when: the combined implementation gap is cut by at least 4000 lines. Mark any remaining methods with `// TODO` comments.

## Task 229 — Game object hierarchy parity: combat + building objects (~5300-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `7f36898` (697 net insertions, 947 added / 250 moved from TRIBE_World_types). TRIBE_Combat_Object + TRIBE_Building_Object expanded. RGE_Combat_Object untouched — gap remains there.
- Goal: close the gap in the core game object hierarchy — combat objects and building objects. These are critical gameplay classes:
  - `com_obj.cpp.decomp` (2012 lines) → `RGE_Combat_Object.cpp` (555 lines) = gap ~1460
  - `t_c_obj.cpp.decomp` (2198 lines) → `TRIBE_Combat_Object.cpp` (127 lines) = gap ~2070
  - `t_b_obj.cpp.decomp` (1934 lines) → `TRIBE_Building_Object.cpp` (165 lines) = gap ~1770
  Combined gap: ~5300 lines.
- Implement (decomp-first):
  - For each decomp file, enumerate ALL functions not yet in the impl.
  - Focus on: damage/heal/attack logic, armor calculations, building construction/research/queue, garrison, projectile spawning.
  - Each function should be transliterated from the decomp with `// Fully verified` markers.
- Where:
  - `src/game/src/RGE_Combat_Object.cpp`, `src/game/src/TRIBE_Combat_Object.cpp`, `src/game/src/TRIBE_Building_Object.cpp`
  - Relevant headers in `src/game/include/`
- Source of truth: `src/game/decomp/com_obj.cpp.decomp` + `t_c_obj.cpp.decomp` + `t_b_obj.cpp.decomp` + `.asm` counterparts.
- Non-overlap: do NOT touch RGE_Static_Object, RGE_Moving_Object, RGE_Master_* files, or any AI/screen/player files.
- Done when: combined gap cut by at least 3000 lines.

## Task 230 — World system parity: RGE_Game_World + TRIBE_World (~5100-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `dfc9def` (~99 insertions). Only helper wrappers added. Gap mostly remains (~5000 lines). Needs follow-up with explicit function list.
- [ ] Finished
- Goal: close the gap in the world simulation system:
  - `world.cpp.decomp` (5804 lines) → `RGE_Game_World.cpp` (2631 lines) = gap ~3170
  - `tworld.cpp.decomp` (3630 lines) → `TRIBE_World.cpp` (1711 lines) = gap ~1920
  Combined gap: ~5100 lines. The world classes manage all game entities, spawning, object lists, and simulation ticking.
- Implement (decomp-first):
  - For each decomp, enumerate ALL missing functions.
  - Focus on: world update/tick, entity spawn/despawn, object lookup, scenario load integration, player world state.
  - Each function should be transliterated from the decomp.
- Where:
  - `src/game/src/RGE_Game_World.cpp` and `src/game/src/TRIBE_World.cpp`
  - Relevant headers in `src/game/include/`
- Source of truth: `src/game/decomp/world.cpp.decomp` + `tworld.cpp.decomp` + `.asm` counterparts.
- Non-overlap: do NOT touch RGE_Map, basegame, TRIBE_Player, scenario, or any screen/AI files.
- Done when: combined gap cut by at least 3000 lines.

## Task 231 — TribeStrategyAIModule parity (~2270-line gap)
- [x] Assigned to agent
- [ ] Finished
- Status note: **INCOMPLETE** — commit `02ddab7` only added 5 lines (ASM audit note). Gap still ~2264 lines. Needs re-dispatch with explicit function list.
- [ ] Finished
- Goal: close the gap in the AI strategy module: `taistrmd.cpp.decomp` (3298 lines) → `TribeStrategyAIModule.cpp` (1029 lines) = gap ~2270. This module controls high-level AI strategy decisions (when to attack, when to build up, tech priorities, etc.).
- Implement (decomp-first from `taistrmd.cpp.decomp`):
  - Enumerate ALL functions in `taistrmd.cpp.decomp` not yet in `TribeStrategyAIModule.cpp`.
  - Focus on: strategy selection, resource evaluation, military strength assessment, tech tree prioritization, age-up decisions.
  - Each function should be transliterated from the decomp.
- Where:
  - `src/game/src/TribeStrategyAIModule.cpp`
  - `src/game/include/TribeStrategyAIModule.h`
- Source of truth: `src/game/decomp/taistrmd.cpp.decomp` + `taistrmd.cpp.asm`.
- Non-overlap: do NOT touch TribeTacticalAIModule, TribeInformationAIModule, UnitAIModule, or any non-AI files.
- Done when: gap cut by at least 1500 lines.

## Task 232 — Scenario data system parity: scenario + tscenaro (~3690-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `1ce6f68` (688 net insertions). scenario.cpp→977 lines, tscenaro.cpp→971 lines. Moved duplicate code from TRIBE_World_types.cpp.
- [ ] Finished
- Goal: close the gap in scenario data handling (NOT the editor UI — that's Task 227):
  - `scenario.cpp.decomp` (2903 lines) → `scenario.cpp` (739 lines) = gap ~2164
  - `tscenaro.cpp.decomp` (2045 lines) → `tscenaro.cpp` (522 lines) = gap ~1523
  Combined gap: ~3690 lines. These files handle scenario loading, saving, trigger evaluation, and data serialization.
- Implement (decomp-first):
  - Enumerate ALL missing functions in both decomps.
  - Focus on: scenario load/save, trigger system, victory conditions, diplomacy setup, initial resource config.
  - Each function should be transliterated from the decomp.
- Where:
  - `src/game/src/scenario.cpp` and `src/game/src/tscenaro.cpp`
  - Relevant headers in `src/game/include/`
- Source of truth: `src/game/decomp/scenario.cpp.decomp` + `tscenaro.cpp.decomp` + `.asm` counterparts.
- Non-overlap: do NOT touch TRIBE_Screen_Sed, scr_sed, or any screen/AI/player files.
- Done when: combined gap cut by at least 2500 lines.

## Task 233 — Panel system parity: text panels, buttons, dropdowns (~5900-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `7385f1e` (268 insertions). Only helper wrappers added. Gap mostly remains (~5600 lines). Needs follow-up with explicit function list.
- [ ] Finished
- Goal: close the gap in the UI panel system (core widgets):
  - `pnl_txt.cpp.decomp` (2861 lines) → `Pnl_txt.cpp` (229 lines) = gap ~2632
  - `pnl_btn.cpp.decomp` (1915 lines) → no full impl yet = gap ~1915
  - `pnl_drop.cpp.decomp` (1396 lines) → `Pnl_drop_btn.cpp` (43 lines) = gap ~1353
  Combined gap: ~5900 lines. These are the fundamental UI widgets used across all game screens.
- Implement (decomp-first):
  - For each decomp, enumerate ALL missing functions.
  - Focus on: text rendering/layout, button click handlers, dropdown menu logic, selection state, scrolling.
  - Each function should be transliterated from the decomp.
- Where:
  - `src/game/src/Pnl_txt.cpp`, `src/game/src/Pnl_drop_btn.cpp`, and a new or existing button panel file
  - Relevant headers in `src/game/include/`
- Source of truth: `src/game/decomp/pnl_txt.cpp.decomp` + `pnl_btn.cpp.decomp` + `pnl_drop.cpp.decomp` + `.asm` counterparts.
- Non-overlap: do NOT touch Panel_ez.cpp, Pnl_edit.cpp, Pnl_inp.cpp, or any screen/game logic files.
- Done when: combined gap cut by at least 3000 lines.

## Task 234 — Drawarea + shape rendering parity (~3690-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `bb105cb` (542 insertions). Drawarea expanded but TShape was not touched. Gap partially closed.
- [ ] Finished
- Goal: close the gap in the rendering pipeline:
  - `drawarea.cpp.decomp` (3940 lines) → `Drawarea.cpp` (2033 lines) = gap ~1907
  - `shape.cpp.decomp` (3837 lines) → `TShape.cpp` (2061 lines) = gap ~1776
  Combined gap: ~3690 lines. These handle tile rendering, sprite compositing, and shape/graphics management.
- Implement (decomp-first):
  - For each decomp, enumerate ALL missing functions.
  - Focus on: draw routines, clipping, sprite blitting, terrain tile rendering, coordinate transforms.
  - Each function should be transliterated from the decomp.
- Where:
  - `src/game/src/Drawarea.cpp` and `src/game/src/TShape.cpp`
  - Relevant headers in `src/game/include/`
- Source of truth: `src/game/decomp/drawarea.cpp.decomp` + `shape.cpp.decomp` + `.asm` counterparts.
- Non-overlap: do NOT touch view.cpp, Panel files, or any game logic files.
- Done when: combined gap cut by at least 2500 lines.

## Task 235 — RGE Action system parity: action objects across 8 decomps (~3260-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `e33e78c` (126 insertions). Only RGE_Action constructors + RGE_Action_Attack constructors added. Most of the 3260-line gap remains.
- Goal: close the gap across the entire RGE action system — these are the fundamental unit action classes:
  - `action.cpp.decomp` (871) → `RGE_Action.cpp` (332) = gap ~539
  - `act_obj.cpp.decomp` (1165) → `RGE_Action_Object.cpp` (622) = gap ~543
  - `act_list.cpp.decomp` (1142) → `RGE_Action_List.cpp` (484) = gap ~658
  - `act_atak.cpp.decomp` (1167) → `RGE_Action_Attack.cpp` (550) = gap ~617
  - `act_move.cpp.decomp` (604) → `RGE_Action_Move_To.cpp` (321) = gap ~283
  - `act_gath.cpp.decomp` (829) → `RGE_Action_Gather.cpp` (672) = gap ~157
  - `act_entr.cpp.decomp` (582) → `RGE_Action_Enter.cpp` (310) = gap ~272
  - `act_misl.cpp.decomp` (677) → `RGE_Action_Missile.cpp` (486) = gap ~191
  Combined gap: ~3260 lines.
- Implement (decomp-first): For each decomp, enumerate ALL missing functions. Focus on: action execution logic, target validation, state transitions, attack/gather/move completion callbacks.
- Where: `src/game/src/RGE_Action*.cpp` files + relevant headers
- Source of truth: corresponding `.decomp` + `.asm` files in `src/game/decomp/`
- Non-overlap: do NOT touch any TRIBE_* files, player files, or screen files.
- Done when: combined gap cut by at least 2000 lines.

## Task 236 — Multiplayer screens parity: scr_mps (~2150-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `f80e7da` (488 insertions to scr_mps_impl.cpp). Multiplayer command handling + setup methods implemented.
- Goal: close the gap in multiplayer screen handling: `scr_mps.cpp.decomp` (4742) → `scr_mps_impl.cpp` (2592) = gap ~2150. Handles multiplayer lobby, game creation, player slots, and network setup.
- Implement (decomp-first from `scr_mps.cpp.decomp`): Enumerate ALL functions not yet in `scr_mps_impl.cpp`. Focus on: player slot management, game creation/join, network setup, chat, ready state.
- Where: `src/game/src/scr_mps_impl.cpp` + relevant headers
- Source of truth: `src/game/decomp/scr_mps.cpp.decomp` + `scr_mps.cpp.asm`.
- Non-overlap: do NOT touch TRIBE_Screen_Game, TRIBE_Screen_Sed, com_hand, or any AI files.
- Done when: gap cut by at least 1500 lines.

## Task 237 — RGE_Moving_Object + master object parity (~3300-line gap)
- [x] Assigned to agent
- [ ] Finished
- Goal: close the gap in the object hierarchy middle layers:
  - `move_obj.cpp.decomp` (3485) → `RGE_Moving_Object.cpp` (2068) = gap ~1420
  - `m_s_obj.cpp.decomp` (1906) → `RGE_Master_Static_Object.cpp` (1100) = gap ~806
  - `m_co_obj.cpp.decomp` (1081) → find/create matching impl = gap ~1081
  Combined gap: ~3300 lines. Moving objects handle pathfinding movement, master objects handle type definitions.
- Implement (decomp-first): For each decomp, enumerate ALL missing functions. Focus on: movement interpolation, path following, speed, master type init, attribute tables.
- Where: `src/game/src/RGE_Moving_Object.cpp`, `src/game/src/RGE_Master_Static_Object.cpp`, and matching combat master file + headers
- Source of truth: corresponding `.decomp` + `.asm` counterparts.
- Non-overlap: do NOT touch RGE_Static_Object, TRIBE_* object files, or any screen/AI files.
- Done when: combined gap cut by at least 2000 lines.

## Task 238 — Command system parity: command.cpp + tcommand.cpp (~4570-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `9b08e9e` (107 insertions). tcommand.cpp created with 7 TRIBE_Command methods. command.cpp not touched — still has full 2482-line gap.
- Goal: close the gap in the command/order dispatch system:
  - `command.cpp.decomp` (2482) → no impl yet = gap ~2482
  - `tcommand.cpp.decomp` (2087) → no impl yet = gap ~2087
  Combined gap: ~4570 lines. Handles command queue, order serialization, and multiplayer command sync.
- Implement (decomp-first): Create impl files if needed. Focus on: command creation, queuing, execution dispatch, serialization for multiplayer.
- Where: Create/extend `src/game/src/command.cpp` and `src/game/src/tcommand.cpp` + headers
- Source of truth: corresponding `.decomp` + `.asm` counterparts.
- Non-overlap: do NOT touch com_hand.cpp, basegame, or any screen/AI/player files.
- Done when: combined gap cut by at least 3000 lines.

## Task 239 — Panel_ez + panel system base parity (~4250-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `35be8b9` (233 insertions). Panel_ez setters/getters + TEasy panel APIs + TPanelSystem::EnableIME. Gap remains large.
- Goal: close the gap in the panel system foundation:
  - `panel_ez.cpp.decomp` (3517) → `Panel_ez.cpp` (1712) = gap ~1805
  - `panel.cpp.decomp` (4154) → also maps to `Panel_ez.cpp` = gap ~2442
  Combined unique gap: ~4250 lines. Panel_ez is the base class for ALL UI panels.
- Implement (decomp-first): Audit which functions from both decomps map to Panel_ez.cpp. Focus on: panel layout, child management, draw dispatch, input routing, focus handling.
- Where: `src/game/src/Panel_ez.cpp` + relevant headers
- Source of truth: `src/game/decomp/panel_ez.cpp.decomp` + `panel.cpp.decomp` + `.asm` counterparts.
- Non-overlap: do NOT touch Pnl_txt, Pnl_drop, Pnl_edit, Pnl_inp, or any screen/game files.
- Done when: gap cut by at least 2500 lines.

## Task 240 — Gameinfo + span list + DIB parity (~3270-line gap)
- [x] Assigned to agent
- [x] Finished
- Status note: landed as commit `aaec660` (2280 insertions). Dib.cpp +1449, gameinfo.cpp +398, spanlist.cpp +528. Met 2000-line target.
- Goal: close the gap in utility/infrastructure systems:
  - `gameinfo.cpp.decomp` (1695) → `gameinfo.cpp` (651) = gap ~1044
  - `spanlist.cpp.decomp` (1649) → `spanlist.cpp` (554) = gap ~1095
  - `dib.cpp.decomp` (2011) → `Dib.cpp` (845) = gap ~1166
  Combined gap: ~3305 lines.
- Implement (decomp-first): For each decomp, enumerate ALL missing functions. Focus on: game info accessors, span list operations, DIB creation/blitting/conversion.
- Where: `src/game/src/gameinfo.cpp`, `src/game/src/spanlist.cpp`, `src/game/src/Dib.cpp` + headers
- Source of truth: corresponding `.decomp` + `.asm` files.
- Non-overlap: do NOT touch Drawarea, Panel, or any game logic files.
- Done when: combined gap cut by at least 2000 lines.

## Task 241 — TShape rendering parity (~1776-line gap)
- [x] Assigned to agent (worker-1, clone_1)
- [x] Finished
- Status note: landed as commit `81ecd19` (34 insertions). Only TShape ctor + shape_bounds added. Severely under-delivered: 1742-line gap remains.
- Goal: close the gap in shape/sprite rendering: `shape.cpp.decomp` (3837) → `TShape.cpp` (2061) = gap ~1776. TShape handles sprite loading, frame management, and rendering.
- Implement (decomp-first from `shape.cpp.decomp`): Enumerate ALL missing functions. Focus on: sprite frame loading, animation, rendering, palette handling.
- Where: `src/game/src/TShape.cpp` + `src/game/include/TShape.h`
- Source of truth: `src/game/decomp/shape.cpp.decomp` + `shape.cpp.asm`.
- Non-overlap: do NOT touch Drawarea, view, or any game logic files.
- Done when: gap cut by at least 1200 lines.

## Task 242 — Fractal map + diamond map + pathsys parity (~3280-line gap)
- [x] Assigned to agent (worker-2, clone_2)
- [x] Finished
- Status note: landed as commit `400aaad` (31 insertions). pathsys +20, RGE_Diamond_Map +11 only. Under-delivered: 3249-line gap remains.
- Goal: close the gap in map generation/pathfinding infrastructure:
  - `fractal.cpp.decomp` (1704) → `fractal.cpp` (871) = gap ~833
  - `diam_map.cpp.decomp` (1664) → no impl yet = gap ~1664
  - `pathsys.cpp.decomp` (2246) → `pathsys.cpp` (1464) = gap ~782
  Combined gap: ~3280 lines. These handle terrain generation, diamond tile mapping, and pathfinding.
- Implement (decomp-first): For each decomp, enumerate ALL missing functions. Create diam_map impl if needed.
- Where: `src/game/src/fractal.cpp`, new file for diam_map, `src/game/src/pathsys.cpp` + headers
- Source of truth: corresponding `.decomp` + `.asm` files.
- Non-overlap: do NOT touch RGE_Map, view, or any game logic files.
- Done when: combined gap cut by at least 2000 lines.

## Task 243 — scr_sed2 scenario editor part 2 parity (~3930-line gap)
- [x] Assigned to agent (worker-3, clone_3)
- [x] Finished
- Status note: landed as commit `4a709b1` (3946 insertions!). Full TRIBE_Screen_Sed2.cpp created. Outstanding delivery.
- Goal: close the gap in the second half of scenario editor: `scr_sed2.cpp.decomp` (3930) → no impl yet = gap ~3930. This is the terrain painting, trigger editing, and object placement portion of the editor.
- Implement (decomp-first from `scr_sed2.cpp.decomp`): Create impl file, enumerate ALL functions, transliterate them.
- Where: Create `src/game/src/TRIBE_Screen_Sed2.cpp` or similar + headers
- Source of truth: `src/game/decomp/scr_sed2.cpp.decomp` + `scr_sed2.cpp.asm`.
- Non-overlap: do NOT touch TRIBE_Screen_Sed.cpp (that's the first part, already implemented), or any game logic files.
- Done when: gap cut by at least 2500 lines.

## Task 244 — Visible resource manager + information map parity (~2100-line gap)
- [x] Assigned to agent (worker-1, clone_1)
- [ ] Finished
- Goal: close the gap in visibility/exploration systems:
  - `visible.cpp.decomp` (1215) → `Visible_Resource_Manager.cpp` (219) = gap ~996
  - `infmap.cpp.decomp` (1103) → no impl yet = gap ~1103
  Combined gap: ~2100 lines. Visible_Resource_Manager tracks explored/unexplored tiles; infmap handles AI information mapping.
- Implement (decomp-first): For each decomp, enumerate ALL missing functions. Create infmap impl if needed.
- Where: `src/game/src/Visible_Resource_Manager.cpp`, new file for infmap + headers
- Source of truth: corresponding `.decomp` + `.asm` files.
- Non-overlap: do NOT touch RGE_Visible_Map.cpp, view.cpp, or any screen/AI files.
- Done when: combined gap cut by at least 1500 lines.

## Task 245 — Music + sound driver + mouseptr parity (~2140-line gap)
- [x] Assigned to agent (worker-4, clone_4)
- [x] Finished
- Status note: landed as commit `8383f58` (27 insertions). Only Mouseptr::Shutdown_Mouse added. Severely under-delivered: 2130-line gap remains.
- Goal: close the gap in audio/input infrastructure:
  - `music.cpp.decomp` (1307) → `music.cpp` (711) = gap ~596
  - `sounddrv.cpp.decomp` (1366) → `Sounddrv.cpp` (862) = gap ~504
  - `mouseptr.cpp.decomp` (1285) → `Mouseptr.cpp` (740) = gap ~545
  Combined gap: ~1645 (plus partial undercounts). Also add `com_spd.cpp.decomp` (913) → `com_spd.cpp` (395) = gap ~518.
  Total gap: ~2160 lines.
- Implement (decomp-first): For each decomp, enumerate ALL missing functions. Focus on: MIDI playback, DirectSound wrappers, cursor management, speed settings.
- Where: respective `.cpp` files + headers
- Source of truth: corresponding `.decomp` + `.asm` files.
- Non-overlap: do NOT touch any game logic, AI, or screen files.
- Done when: combined gap cut by at least 1500 lines.

## Task 246 — Pnl_edit + Pnl_inp parity (~1430-line gap)
- [x] Assigned to agent (worker-6, clone_6)
- [x] Finished
- Status note: landed as commit `f44afc7` (75 insertions to Pnl_edit.cpp). Under-delivered: 1359-line gap remains.
- Goal: close the gap in text input/edit panels:
  - `pnl_edit.cpp.decomp` (1582) → `Pnl_edit.cpp` (658) = gap ~924
  - `pnl_inp.cpp.decomp` (1343) → `Pnl_inp.cpp` (833) = gap ~510
  Combined gap: ~1434 lines. These handle text editing, input validation, and clipboard.
- Implement (decomp-first): For each decomp, enumerate ALL missing functions. Focus on: text cursor, selection, clipboard, validation callbacks.
- Where: `src/game/src/Pnl_edit.cpp`, `src/game/src/Pnl_inp.cpp` + headers
- Source of truth: corresponding `.decomp` + `.asm` files.
- Non-overlap: do NOT touch Panel_ez, Pnl_txt, Pnl_drop, or any screen/game files.
- Done when: combined gap cut by at least 1000 lines.

## Task 247 — tribegam.cpp TRIBE game implementation parity (~5347-line gap)
- [x] Assigned to agent (worker-2, clone_2)
- [ ] Finished
- Goal: close the massive gap in TRIBE game core: tribegam.cpp.decomp (8725) -> tribegam.cpp (3378) = gap ~5347. This is the central TRIBE game class — save/load, game tick, player management, victory conditions.
- Implement (decomp-first from tribegam.cpp.decomp): Enumerate ALL missing functions. Focus on the largest blocks: save/load game state, game tick processing, player init, victory/diplomacy logic, achievement tracking.
- Where: `src/game/src/tribegam.cpp` + `src/game/include/TRIBE_Game.h`
- Source of truth: `src/game/decomp/tribegam.cpp.decomp` + `tribegam.cpp.asm`.
- Non-overlap: do NOT touch basegame.cpp, TRIBE_Player.cpp, or screen files.
- Done when: gap cut by at least 3000 lines. This is a large task — prioritize completeness.

## Task 248 — basegame.cpp core game parity part 2 (~3804-line gap)
- [x] Assigned to agent (worker-3, clone_3)
- [ ] Finished
- Goal: close the remaining gap in the base game class: basegame.cpp.decomp (7841) -> basegame.cpp (4037) = gap ~3804. RGE_Base_Game is the parent of TRIBE_Game, handles game loop, timing, world setup.
- Implement (decomp-first from basegame.cpp.decomp): Enumerate ALL missing functions systematically. Focus on: game loop callbacks, world init/shutdown, timing, messaging, player slots.
- Where: `src/game/src/basegame.cpp` + `src/game/include/RGE_Base_Game.h`
- Source of truth: `src/game/decomp/basegame.cpp.decomp` + `basegame.cpp.asm`.
- Non-overlap: do NOT touch tribegam.cpp, command.cpp, or screen files.
- Done when: gap cut by at least 2500 lines.

## Task 249 — Scenario + TRIBE scenario parity (~3000-line gap)
- [x] Assigned to agent (worker-4, clone_4)
- [ ] Finished
- Goal: close the gap in scenario management:
  - scenario.cpp.decomp (2903) -> scenario.cpp (977) = gap ~1926
  - tscenaro.cpp.decomp (2045) -> tscenaro.cpp (971) = gap ~1074
  Combined gap: ~3000 lines. These handle scenario file I/O, player setup, triggers, objectives.
- Implement (decomp-first): For each decomp, enumerate ALL missing functions. Focus on: scenario save/load, player config, trigger evaluation, map setup.
- Where: `src/game/src/scenario.cpp`, `src/game/src/tscenaro.cpp` + headers
- Source of truth: corresponding `.decomp` + `.asm` files.
- Non-overlap: do NOT touch scr_sed, scr_sed2, or any screen files.
- Done when: combined gap cut by at least 2000 lines.

## Task 250 — TShape sprite rendering continuation (~1745-line gap)
- [x] Assigned to agent (worker-6, clone_6)
- [ ] Finished
- Goal: Task 241 only added 34 lines. This continuation must close the real gap: shape.cpp.decomp (3837) -> TShape.cpp (2092) = gap ~1745. TShape handles SLP sprite loading, frame rendering, palette application, shadow drawing.
- Implement (decomp-first from shape.cpp.decomp): Enumerate EVERY missing function. There should be 20+ unimplemented functions. Focus on: SLP frame decoding, draw methods, palette transforms, outline rendering, shadow methods.
- Where: `src/game/src/TShape.cpp` + `src/game/include/TShape.h`
- Source of truth: `src/game/decomp/shape.cpp.decomp` + `shape.cpp.asm`.
- Non-overlap: do NOT touch Drawarea, Dib, or any game logic files.
- Done when: gap cut by at least 1200 lines. ALL rendering functions must be transliterated.

## Task 251 — RMM random map generators parity (~2100-line gap)
- [ ] Assigned to agent
- [ ] Finished
- Goal: close the gap in random map generation subsystem:
  - rmm_elev.cpp.decomp (1177) -> RGE_RMM_Elevation_Generator.cpp (289) = gap ~888
  - rmm_terr.cpp.decomp (826) -> no impl yet = gap ~826
  - rmm_cntr.cpp.decomp (735) -> RGE_RMM_Controller.cpp (324) = gap ~411
  Combined gap: ~2125 lines. These generate terrain elevation, terrain types, and coordinate random map creation.
- Implement (decomp-first): For each decomp, enumerate ALL missing functions. Create rmm_terr impl if needed.
- Where: `src/game/src/RGE_RMM_Elevation_Generator.cpp`, new file for rmm_terr, `src/game/src/RGE_RMM_Controller.cpp` + headers
- Source of truth: corresponding `.decomp` + `.asm` files.
- Non-overlap: do NOT touch RGE_RMM_Object_Generator, fractal, or any game logic files.
- Done when: combined gap cut by at least 1500 lines.

## Task 252 — command.cpp RGE command system parity (~2482-line gap)
- [ ] Assigned to agent
- [ ] Finished
- Goal: Task 238 only added 107 lines to tcommand.cpp but left command.cpp untouched. Close the remaining gap: command.cpp.decomp (2482) -> command.cpp (essentially empty beyond stubs). RGE_Command handles all game commands — move, attack, build, research, etc.
- Implement (decomp-first from command.cpp.decomp): Enumerate ALL missing functions. Focus on: command dispatch, move commands, attack commands, build commands, formation commands, trade commands.
- Where: `src/game/src/command.cpp` + `src/game/include/RGE_Command.h` (or similar headers)
- Source of truth: `src/game/decomp/command.cpp.decomp` + `command.cpp.asm`.
- Non-overlap: do NOT touch tcommand.cpp (already done), com_hand.cpp, or any action files.
- Done when: gap cut by at least 1800 lines.
