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
- [ ] Finished
- [x] Assigned to agent
- Goal: keep this as a tracking umbrella so we don’t create overlapping “implement object virtuals” tasks.
- Implement: expand `RGE_Static_Object` virtual coverage (draw/update/command responders/etc.) so fewer calls land in placeholder behavior.
- Where: src/game/src/RGE_Static_Object.cpp and shrink/retire src/game/src/rge_object_virtual_stubs.cpp accordingly (only as real implementations land).
- Source of truth: src/game/decomp/stat_obj.cpp.decomp (+ ASM audit where signedness/offsets look sketchy).
- Done when: `rge_object_virtual_stubs.cpp` stops being a primary behavior path.
- Non-overlap note: do NOT add new “implement X object virtuals” work here if a dedicated task exists. Use:
  - Task 35 (unique id reassignment)
  - Task 42 (RGE_Moving_Object)
  - Task 44 (RGE_Combat_Object)
  - Task 45 (RGE_Animated_Object + RGE_Missile_Object)
  - Task 46 (RGE_Doppleganger_Object)
- Status note: `RGE_Static_Object` draw + LOS virtual coverage has progressed across multiple merges (e.g. `agent/rge-static-virtuals` / `397ebc9`, `agent/static-object-draw` / `a8cc4cd` + `0b75cd8`, `agent/rge-static-virtuals-los` / `09f8aa3`), but `src/game/src/rge_object_virtual_stubs.cpp` still exists and remains a major follow-up.

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
- [ ] Finished
- Goal: make the Single Player “Campaign” button follow original flow (people profiles → name selection screen/dialog) instead of a stub popup.
- Implement:
  - `RGE_Game_Info::get_people_list` parity (0x0044D850) so UI can query existing profiles.
  - Also implement the adjacent `RGE_Game_Info::get_campaign_list` (0x0044D8C0) and `RGE_Game_Info::get_scenario_list` (0x0044D940) helpers from the same decomp unit, since they share allocation/string-copy behavior and are typically needed immediately by follow-on campaign/scenario selection screens.
  - Implement `TRIBE_Screen_Name` and `TRIBE_Dialog_Name` (constructors, action handlers, list population, new/remove/ok/cancel, teardown).
  - Wire `TribeSPMenuScreen::action` campaign button to the restored flow (matching the decomp: choose `TRIBE_Screen_Name` when list non-empty, else show dialog).
- Where: src/game/src/gameinfo.cpp (+ declarations in src/game/include/RGE_Game_Info.h), plus new/updated screen units for `TRIBE_Screen_Name` / `TRIBE_Dialog_Name`, and src/game/src/Scr_sing_impl.cpp.
- Source of truth: src/game/decomp/gameinfo.cpp.decomp + src/game/decomp/gameinfo.cpp.asm (get_people_list/get_campaign_list/get_scenario_list), src/game/decomp/scr_sing.cpp.decomp (campaign button flow), src/game/decomp/scr_name.cpp.decomp (name screen), and dialog decomp (dlg_conf.cpp.decomp / dlg_list.cpp.decomp / pnl_dlg.cpp.decomp as required by name dialogs).
- Done when: the `Scr_sing_impl.cpp` campaign TODO(accuracy) note is removed, `RGE_Game_Info::get_people_list` exists and matches decomp allocation/free expectations (uses `getstring`), and the SP “Campaign” button transitions into the correct name selection UI via `panel_system`.

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
- [ ] Finished
- Goal: restore the Save Game UI flow (file name entry, existing saves list, delete, OK/cancel, optional quit-after-save) so in-game save operations use the original screen rather than stubs.
- Implement: full transliteration of `TribeSaveGameScreen` (ctor/dtor + action handlers + list refresh + file naming rules) including mode switching between “SaveGame” and any other enum modes.
- Where: add src/game/src/scr_save_impl.cpp (or the project’s matching pattern) and wire it to the existing header src/game/include/TribeSaveGameScreen.h.
- Source of truth: src/game/decomp/scr_save.cpp.decomp (ctor @ 0x004A71F0) + src/game/decomp/scr_save.cpp.asm for any subtle calling/branch behavior.
- Done when: the screen is fully implemented and remaining save-screen TODO(parity) markers are eliminated (notably: no `MessageBoxA` fallback and scenario-editor-open return path matches decomp).
- Status note: `scr_save_impl.cpp` now exists and implements the Save Game flow using real list/scrollbar helpers (merge `agent/savegame-screen-parity`, commit `598d9f9`), but still contains explicit TODO(parity) markers (commit `7470b61`).

## Task 29 — Implement End Screen parity (`TribeEndScreen`) and wire game-over transitions
- [x] Assigned to agent
- [ ] Finished
- Goal: restore the “End Screen” shown after a match/campaign scenario ends, including background selection and OK routing back to the correct next screen.
- Implement: transliterate `TribeEndScreen` ctor/dtor + action behavior, including setup background selection by resolution and creating picture/text/button panels.
- Where: add src/game/src/scr_end_impl.cpp (or equivalent) wired to src/game/include/TribeEndScreen.h, plus any minimal wiring in `TRIBE_Game`/world game-over path that instantiates the end screen.
- Source of truth: src/game/decomp/scr_end.cpp.decomp (ctor @ 0x004936D0) + src/game/decomp/scr_end.cpp.asm.
- Done when: `TribeEndScreen` exists in src, constructs successfully with no TODO/STUB blocks, and the game-over branch reaches it via `panel_system->setCurrentPanel` parity.

## Task 30 — Implement Achievements + Timeline screens parity (`TribeAchievementsScreen` + `Time_Line_Panel`)
- [x] Assigned to agent
- [ ] Finished
- Goal: restore the post-game achievements/statistics UI (including timeline view) so the “Achievements Screen” path is no longer a missing-screen hole.
- Implement:
  - Transliterate `TribeAchievementsScreen` ctor/dtor + action handlers (mode switching, back/ok/restart buttons, scrollbars for text areas, stat table fill).
  - Transliterate `Time_Line_Panel` and supporting `RGE_Timeline`/timeline-loading behaviors required by the screen.
- Where: new src/game/src/scr_ach_impl.cpp + src/game/src/timeline_impl.cpp (or equivalent), wired to existing headers src/game/include/TribeAchievementsScreen.h and src/game/include/Time_Line_Panel.h.
- Source of truth: src/game/decomp/scr_ach.cpp.decomp (ctor @ 0x0048D530), src/game/decomp/timeline.cpp.decomp (RGE_Timeline @ 0x0050D5B0) + corresponding `.asm` files.
- Done when: “Achievements Screen” can be constructed without stubs, the timeline panel allocates/loads correctly per decomp, and all code compiles/link-clean with no new placeholder forwarding stubs.
- Status note: a minimal `TribeAchievementsScreen` implementation was added to satisfy the `stop_video(video=4)` branch, but timeline/stat-table parity is still pending (merge `restore AVI video callbacks`, commit `0fde90d`).

---

## Task 31 — Restore `TEasy_Panel` popup dialog helpers (remove Win32 MessageBox shims)
- [ ] Assigned to agent
- [ ] Finished
- Goal: replace remaining Win32 `MessageBoxA` shims used by menu/screens with the original `TEasy_Panel` dialog flows.
- Implement: `TEasy_Panel::popupOKDialog` (0x00469EE0), `popupYesNoDialog` (0x0046A040), `popupYesNoCancelDialog` (0x0046A150).
- Where: src/game/src/Panel_ez.cpp (+ declarations in src/game/include/TEasy_Panel.h) and remove/update call-site shims including:
  - src/game/src/Scr_main_impl.cpp
  - src/game/src/scr_save_impl.cpp (currently has explicit TODO(parity) MessageBox fallbacks)
- Source of truth: src/game/decomp/panel_ez.cpp.decomp + src/game/decomp/panel_ez.cpp.asm.
- Done when: screens no longer rely on `MessageBoxA` for these dialog flows, and TODO markers/call sites are removed (including the save-screen TODO(parity) MessageBox fallbacks).

## Task 32 — Finish custom mouse pointer parity (basegame mouse-move path)
- [x] Assigned to agent
- [ ] Finished
- Goal: restore the original custom cursor behavior so the basegame mouse loop uses the same `in_game_mode → draw(0) vs Poll()` logic as the shipped game.
- Implement: `TMousePointer::in_game_mode` (0x0045B2C0), `TMousePointer::draw(int)` (0x0045BA60), and complete `TMousePointer::Poll` (0x0045C010) parity/wiring (including any required helpers like surfaces/cursor save-area paths).
- Where: src/game/src/Mouseptr.cpp, src/game/include/TMousePointer.h, and the call site TODO in src/game/src/basegame.cpp.
- Source of truth: src/game/decomp/mouseptr.cpp.decomp + src/game/decomp/mouseptr.cpp.asm, plus basegame.cpp.decomp for the call-site sequencing.
- Done when: the `basegame.cpp` TODO about `in_game_mode`/`draw(0)` vs `Poll()` is removed and the mouse pointer code matches the decomp control flow (no “return success but do nothing” helpers left in the hot path).

## Task 33 — Restore screenshot support (Ctrl+F12)
- [x] Assigned to agent
- [ ] Finished
- Goal: implement the original screenshot capture path so Ctrl+F12 uses the real engine snapshot behavior.
- Implement: `TDrawArea::take_snapshot` (0x004463B0) and ensure the Ctrl+F12 path in basegame calls it.
- Where: src/game/src/Drawarea.cpp, src/game/include/TDrawArea.h, and src/game/src/basegame.cpp.
- Source of truth: src/game/decomp/drawarea.cpp.decomp + src/game/decomp/drawarea.cpp.asm.
- Done when: the `basegame.cpp` TODO(accuracy) about `TDrawArea::take_snapshot` is removed and build is clean.

## Task 34 — Restore window resize handler parity in draw system
- [x] Assigned to agent
- [ ] Finished
- Goal: restore `HandleSize` behavior so window resizing updates draw surfaces/layout like the original game.
- Implement: `TDrawSystem::HandleSize` (0x004433F0) and wire basegame handle_size to call it with the correct parameters.
- Where: src/game/src (wherever `TDrawSystem` is implemented today), src/game/include/TDrawSystem.h, and src/game/src/basegame.cpp.
- Source of truth: src/game/decomp/drawarea.cpp.decomp + src/game/decomp/drawarea.cpp.asm (HandleSize implementation details) and basegame.cpp.decomp (call site).
- Done when: the `basegame.cpp` TODO(accuracy) about `TDrawSystem::HandleSize(p1,p2,p3,p4)` is removed and build is clean.

## Task 35 — Implement unique-id reassignment used during scenario object replacement
- [x] Assigned to agent
- [ ] Finished
- Goal: restore the original replacement semantics in `RGE_Game_World::addObject` so scenario object replacement reassigns unique ids exactly like the shipped game.
- Implement: `RGE_Static_Object::change_unique_id` (0x004C1CF0) and call it from the replacement path in `RGE_Game_World::addObject` when `scenario_object_flag` is set.
- Where: src/game/src/RGE_Static_Object.cpp, src/game/include/RGE_Static_Object.h, src/game/src/RGE_Game_World.cpp.
- Source of truth: src/game/decomp/stat_obj.cpp.decomp + src/game/decomp/stat_obj.cpp.asm (change_unique_id) and src/game/decomp/world.cpp.decomp (+ asm audit for the replacement branch).
- Done when: the `RGE_Game_World::addObject` TODO(accuracy) about `change_unique_id(replaced)` is removed and build is clean.

## Task 36 — Replace TRIBE player AI compat shim with real `TribeMainDecisionAIModule`
- [ ] Assigned to agent
- [ ] Finished
- Goal: remove `TribeMainDecisionAIModuleCompatShim` so TRIBE player AI uses the real module/vtable, preventing subtle AI dispatch mismatches.
- Implement: full ctor/dtor + required virtuals for `TribeMainDecisionAIModule`, and update `TRIBE_Player` to allocate/use it (removing the compat shim + reinterpret-cast allocation path).
- Where: new src file(s) under src/game/src + edits in src/game/src/TRIBE_Player.cpp and matching headers under src/game/include.
- Source of truth: src/game/decomp/TribeMainDecisionAIModule.decomp + src/game/decomp/TribeMainDecisionAIModule.asm, plus call sites in src/game/decomp/tplayer.cpp.decomp.
- Done when: the shim class is removed, `playerAI` is a real `TribeMainDecisionAIModule`, and build is clean without adding new “linker satisfaction” stubs.

---

## Task 37 — Implement `AIPlayBook::loadPlays` full `.ply` parsing (remove current stub)
- [ ] Assigned to agent
- [ ] Finished
- Goal: stop treating `data\\aoe.ply` as “loaded” when parsing is stubbed, so playbook data structures are actually populated.
- Implement: full transliteration of `AIPlayBook::loadPlays(char*)` (file format parse + allocation + per-play setup).
- Where: src/game/src/AIPlayBook.cpp (+ any needed declarations in src/game/include/AIPlayBook.h).
- Source of truth: src/game/decomp/aipbook.cpp.decomp (loadPlays @ 0x00410220) + src/game/decomp/aipbook.cpp.asm.
- Done when: the `// TODO: STUB: Full .ply parsing...` note is removed, all parse branches/alloc/free match decomp, and build is clean.
- Status note: Task 14 restored the call-site; this task restores the actual parser.

## Task 38 — Implement `RGE_Game_World::data_load_*` virtuals (currently hard stubs)
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore the data-loading virtuals so world initialization can load terrain/sprites/sounds/players/objects without “return 1” placeholders.
- Implement: `data_load_world`, `data_load_terrain_tables`, `data_load_players`, `data_load_objects`, `data_load_sounds`, `data_load_color_tables`, `data_load_sprites`, `data_load_players_type`, `data_load_effects`, `data_load_map`, `data_load_random_map`.
- Where: src/game/src/RGE_Game_World.cpp (+ declarations in src/game/include/RGE_Game_World.h if missing).
- Source of truth: src/game/decomp/world.cpp.decomp + src/game/decomp/world.cpp.asm (locate the `data_load_*` family by symbol/offset).
- Done when: the “Stub implementations” block is gone, each method matches decomp control flow, and build is clean.

## Task 39 — Finish `RGE_Action_Object` + `RGE_Action_List` plumbing parity (action stack management)
- [ ] Assigned to agent
- [ ] Finished
- Goal: complete per-unit action-stack behavior so units can enqueue/dequeue actions and save/load action stacks correctly.
- Implement:
  - Fill in the remaining `RGE_Action_Object` methods from act_obj.cpp.decomp (command dispatch helpers, stack management, stop/work/move glue, save/rehook/copy, etc.).
  - Fill in the remaining `RGE_Action_List` methods from act_list.cpp.decomp (set_action variants, add/remove behaviors, create_action factories, response routing, save/rehook/copy).
  - Fix `RGE_Action_Object::create_action_list` to construct a real `RGE_Action_List` (remove current “zero-init + TODO ctor” workaround) once the constructor signature is known from decomp.
- Where: src/game/src/RGE_Action_Object.cpp, src/game/src/RGE_Action_List.cpp (+ headers under src/game/include).
- Source of truth: src/game/decomp/act_obj.cpp.decomp + src/game/decomp/act_obj.cpp.asm, src/game/decomp/act_list.cpp.decomp + src/game/decomp/act_list.cpp.asm.
- Done when: the transliteration covers the full decomp function set for both files (with `// Fully verified...` markers on finished functions) and build is clean.

## Task 40 — Implement the 8 core `RGE_Action_*` subclasses (base unit behaviors)
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore the RGE action subclasses that drive the majority of unit behavior (attack/move/gather/enter/explore/bird/missile/transport).
- Implement: `RGE_Action_Attack`, `RGE_Action_Move_To`, `RGE_Action_Gather`, `RGE_Action_Enter`, `RGE_Action_Explore`, `RGE_Action_Bird`, `RGE_Action_Missile`, `RGE_Action_Transport`.
- Where: add new source files under src/game/src/ (one per class, matching the project’s naming conventions), using the existing headers under src/game/include/.
- Source of truth: src/game/decomp/act_atak.cpp.decomp, act_move.cpp.decomp, act_gath.cpp.decomp, act_entr.cpp.decomp, act_expl.cpp.decomp, act_bird.cpp.decomp, act_misl.cpp.decomp, act_tran.cpp.decomp (+ asm audits as needed).
- Done when: all eight classes compile/link, all transliterated functions have `// Fully verified...` markers, and no placeholder “return success” behavior remains in core update/stop/work paths.
- Dependency note: assumes Task 39 (action-stack plumbing) is far enough along for compilation and basic dispatch.

## Task 41 — Implement remaining TRIBE-specific action subclasses (`tact_*`) (AoE1 gameplay behaviors)
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore TRIBE-only unit behaviors (build/convert/heal/hunt/repair/trade/artifact/wonder etc.) that extend the base RGE action system.
- Implement: `TRIBE_Action` + the action subclasses from the tact_*.decomp set, excluding the already-restored make-object/make-tech actions from Task 5.
- Where: add new source files under src/game/src/ for each class; use headers under src/game/include/.
- Source of truth: src/game/decomp/taction.cpp.decomp and src/game/decomp/tact_*.cpp.decomp (+ asm audits where needed).
- Done when: each class compiles/links, save/load/update/stop/work parity matches decomp, and the set has verified markers on completed transliterations.

## Task 42 — Implement missing `RGE_Moving_Object` methods (movement + pathing glue)
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore the “real movement object” behaviors so moving units can plan and execute movement (beyond load/setup).
- Implement: remaining `RGE_Moving_Object` methods from move_obj.cpp.decomp (movement updates, rotate/velocity helpers, findPath integration, save/copy/transform, exception path handling, etc.).
- Where: src/game/src/RGE_Moving_Object.cpp (+ declarations in src/game/include/RGE_Moving_Object.h).
- Source of truth: src/game/decomp/move_obj.cpp.decomp + src/game/decomp/move_obj.cpp.asm (ASM audit for signedness in angle/velocity math).
- Done when: move_obj.cpp.decomp function set is fully covered (verified markers on completed functions) and build is clean.

## Task 43 — Finish pathfinding: `PathingSystem` + `Path` algorithm and helper ops
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore the actual pathfinding algorithm and the missing `Path` manipulation helpers so movement can compute real routes.
- Implement:
  - `PathingSystem::findPath` / internal path search, smoothing, open/closed management, obstruction/terrain exception behaviors.
  - `Path` operations (capacity growth, waypoint insertion/removal, current waypoint access, copy/clear, facet-to-next handling, etc.).
- Where: src/game/src/pathsys.cpp, src/game/src/Path.cpp (+ headers under src/game/include).
- Source of truth: src/game/decomp/pathsys.cpp.decomp + src/game/decomp/pathsys.cpp.asm, src/game/decomp/path.cpp.decomp + src/game/decomp/path.cpp.asm.
- Done when: the decomp function sets are implemented (verified markers on completed functions) and build is clean.

## Task 44 — Implement missing `RGE_Combat_Object` combat mechanics (attack/damage/armor)
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore real combat behavior (damage, area attack, armor/weapon queries) instead of only having load/setup.
- Implement: the missing `RGE_Combat_Object` methods (attack/do_attack/damage/calc modifiers/save/update/stop + helpers) and any required master-combat helpers.
- Where: src/game/src/RGE_Combat_Object.cpp (+ declarations in src/game/include/RGE_Combat_Object.h).
- Source of truth: src/game/decomp/com_obj.cpp.decomp + src/game/decomp/com_obj.cpp.asm, and where needed src/game/decomp/m_co_obj.cpp.decomp (master-combat data expectations) plus related blocks in stat_obj/move_obj/ani_obj decomp units.
- Done when: combat methods match decomp control flow (verified markers on finished transliterations) and build is clean.

## Task 45 — Implement remaining `RGE_Animated_Object` + `RGE_Missile_Object` methods
- [ ] Assigned to agent
- [ ] Finished
- Goal: remove reliance on `rge_object_virtual_stubs.cpp` for animated/missile behaviors and restore real update/save/transform logic.
- Implement: remaining `RGE_Animated_Object` functions from ani_obj.cpp.decomp and remaining `RGE_Missile_Object` functions from misl_obj.cpp.decomp.
- Where: src/game/src/RGE_Animated_Object.cpp, src/game/src/RGE_Missile_Object.cpp (+ headers under src/game/include).
- Source of truth: src/game/decomp/ani_obj.cpp.decomp + src/game/decomp/ani_obj.cpp.asm, src/game/decomp/misl_obj.cpp.decomp + src/game/decomp/misl_obj.cpp.asm.
- Done when: the missing virtuals stop routing through `rge_object_virtual_stubs.cpp` for these types and build is clean.

## Task 46 — Complete doppleganger (fog-of-war ghost) object parity
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore the fog-of-war ghost object system so it can draw/update/save correctly instead of only loading.
- Implement: remaining `RGE_Doppleganger_Object` virtuals (draw/update/save/die/destroy/copy/rehook/new_sprite/check_damage_sprites, etc.) and any creator/helpers required.
- Where: src/game/src/RGE_Doppleganger_Object.cpp (+ possibly src/game/src/RGE_Doppleganger_Creator.cpp) and headers under src/game/include.
- Source of truth: src/game/decomp/dpl_obj.cpp.decomp + src/game/decomp/dpl_obj.cpp.asm, plus src/game/decomp/m_dg_obj.cpp.decomp if it contains master/variant behaviors.
- Done when: doppleganger no longer depends on stub forwarding for core virtuals and build is clean.

## Task 47 — Audit/restore `TShape` draw pipeline parity (replace current custom implementation)
- [ ] Assigned to agent
- [ ] Finished
- Goal: ensure software renderer shape drawing matches the original (control flow + blending/shadow/mirror/dither variants), not an approximation.
- Implement: decomp-first transliteration of the `shape.cpp.decomp` routine set into the project’s `TShape` implementation (including clipped/unclipped, mirror variants, shadowing/translucency, bounds, and span integration). If current code already covers a function, ASM-audit and adjust it to match decomp rather than refactoring.
- Where: src/game/src/TShape.cpp (+ any needed declarations in src/game/include/TShape.h).
- Source of truth: src/game/decomp/shape.cpp.decomp + src/game/decomp/shape.cpp.asm.
- Done when: the `shape.cpp.decomp` function set is present with verified markers on completed transliterations, and any non-parity custom code paths in `TShape.cpp` are removed or fully justified by decomp.

## Task 48 — Implement scenario system + fractal map generator (save/load + random-map terrain)
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore scenario load/save and the fractal generator used by random maps.
- Implement: `RGE_Scenario` + `T_Scenario` methods (load/save/serialize helpers) and the `Fractal` implementation.
- Where: add new src/game/src/ translation units for scenario + fractal (or extend existing world/scenario units if that’s the established pattern), plus headers under src/game/include.
- Source of truth: src/game/decomp/scenario.cpp.decomp, src/game/decomp/tscenaro.cpp.decomp, src/game/decomp/fractal.cpp.decomp (+ asm audits as needed).
- Done when: scenario save/load code compiles/link-clean without stubs, fractal code exists, and completed transliterations have verified markers.

## Task 49 — Implement random map generation modules (`RMM_*` classes)
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore the random map generation pipeline (land/elevation/terrain/shallows/objects/etc.) so `new_game` can generate real maps without placeholder behavior.
- Implement: the `RMM_*` modules from the rmm_*.decomp set (base/controller/land/elevation/terrain/shallows/objects + any additional rmm units present in decomp like cliffs/database controllers).
- Where: add new src/game/src/ files for each module; use headers under src/game/include.
- Source of truth: src/game/decomp/rmm_*.cpp.decomp (+ asm audits where suspicious).
- Done when: all modules compile/link and random-map generation can proceed without TODO/STUB blocks.

## Task 50 — Implement base AI framework (`AIModule`, `BaseItem`, `BaseObject`, IDs/messages)
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore the shared AI framework that TRIBE AI modules build on.
- Implement: AIModule, BaseItem, BaseObject, AIModuleID, AIModuleMessage (and any small helpers/types they require).
- Where: add new src/game/src/ files + headers under src/game/include.
- Source of truth: src/game/decomp/aimodule.cpp.decomp, src/game/decomp/aibitm.cpp.decomp, src/game/decomp/aibobj.cpp.decomp, src/game/decomp/AIModuleID.decomp, src/game/decomp/AIModuleMessage.decomp.
- Done when: AI framework compiles/links cleanly and downstream TRIBE AI module builds no longer require shim types.

## Task 51 — Implement remaining TRIBE AI modules (excluding Task 36)
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore the rest of TRIBE’s decision modules so AI can do build/strategy/resource/tactical/information behaviors.
- Implement: TRIBE AI modules from the tai*.decomp set excluding `TribeMainDecisionAIModule` (Task 36), e.g. build/strategy/resource/tactical/information and any required connectors/rules modules.
- Where: add new src/game/src/ files + headers under src/game/include.
- Source of truth: src/game/decomp/taibldmd.cpp.decomp, taiconmd.cpp.decomp, taicrule.cpp.decomp, taiinfmd.cpp.decomp, tairesmd.cpp.decomp, taistrmd.cpp.decomp, taitacmd.cpp.decomp, taiuaimd.cpp.decomp (+ asm audits as needed).
- Done when: each module compiles/links, has verified markers on completed transliterations, and TRIBE_Player can wire AI callbacks beyond just construction.
- Dependency note: expects Task 50 to land first.

## Task 52 — Restore missing panel/widget classes used across menus/screens
- [ ] Assigned to agent
- [ ] Finished
- Goal: fill in UI panel classes that screens depend on (edit boxes, input panels, scrollable text, dialog panels, sliders, buttons).
- Implement: `TEditPanel`, `TInputPanel`, `TScrollTextPanel`, `TDialogPanel`, `THorizontalSliderPanel`, and restore `TButtonPanel` parity (many handlers currently return 0).
- Where: add/update src/game/src/ panel units (likely `Pnl_edit.cpp`, `Pnl_inp.cpp`, `Pnl_txt.cpp`, `Pnl_dlg.cpp`, `Pnl_sld.cpp`, and `TButtonPanel.cpp`) plus headers under src/game/include.
- Source of truth: src/game/decomp/pnl_edit.cpp.decomp, pnl_inp.cpp.decomp, pnl_txt.cpp.decomp, pnl_dlg.cpp.decomp, pnl_sld.cpp.decomp, pnl_btn.cpp.decomp (+ asm audits as needed).
- Done when: these panels compile/link, no longer contain placeholder return-0 behavior in their core input paths, and completed transliterations have verified markers.
- Non-overlap note: this task explicitly excludes list/scrollbar/message panel work already tracked by Tasks 7 and 21.
- Status note: `TDialogPanel` landed (src/game/src/TDialogPanel.cpp) alongside list-dialog plumbing (`TListDialog`, `RGE_Dialog_List`) (commit `6331dab`). Remaining: edit/input/scroll-text/slider panels + full `TButtonPanel` parity.

## Task 53 — Implement dialog classes (`dlg_*.cpp.decomp`) used by menus and in-game UI
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore the real dialog boxes (config/diplomacy/menu/about/help/list/message/send message/etc.) so screens don’t need Win32 shims.
- Implement: dialog classes from src/game/decomp/dlg_*.cpp.decomp (split across agents by dialog if needed).
- Where: add new src/game/src/ dialog translation units + headers under src/game/include.
- Source of truth: src/game/decomp/dlg_*.cpp.decomp (+ asm audits as needed).
- Done when: dialogs compile/link and can be constructed by screens without TODO/STUB shims.
- Dependency note: expects Task 52’s widget panels and Task 31’s popup helpers to exist where referenced.
- Status note: list dialog foundations exist (`TListDialog`, `RGE_Dialog_List`), but the `dlg_*.cpp.decomp` dialog set is still not implemented.

## Task 54 — Implement COM/networking primitives (`com_*.cpp.decomp`) needed by multiplayer
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore the COM networking layer so comm handlers can serialize/receive commands without missing-class gaps.
- Implement: COM_Object plus the COM_* family used by the comm handler (address/session/lobby/server/sync/speed/error, etc.).
- Where: add new src/game/src/ translation units + headers under src/game/include.
- Source of truth: src/game/decomp/com_*.cpp.decomp (+ asm audits as needed).
- Done when: COM layer compiles/links and Task 26’s MP comm init no longer needs fallback null-path handling due to missing types.

## Task 55 — Implement scenario editor screens (`scr_sed*`) (large, split-friendly)
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore the scenario editor screens and helpers so editor mode isn’t a missing-screen hole.
- Implement: `TRIBE_Screen_Sed` + related open/menu screens (scr_sed/scr_sed2/scr_sedo/scr_sedm).
- Where: add new src/game/src/ screen translation units + headers under src/game/include.
- Source of truth: src/game/decomp/scr_sed.cpp.decomp, scr_sed2.cpp.decomp, scr_sedo.cpp.decomp, scr_sedm.cpp.decomp.
- Done when: all editor screens compile/link and can be instantiated via the panel system without stubs.

## Task 56 — Implement shared utility classes used broadly (AI + screens)
- [ ] Assigned to agent
- [ ] Finished
- Goal: restore utility/data-structure code that many subsystems rely on (strings, arrays, trig helpers, campaign, influence map).
- Implement: `DString`, `UTMArray`, trig helpers, `Campaign`, `InfluenceMap` (and any small helpers they require).
- Where: add new src/game/src/ translation units + headers under src/game/include.
- Source of truth: src/game/decomp/dstring.cpp.decomp, utmarray.cpp.decomp, trig.cpp.decomp, campaign.cpp.decomp, infmap.cpp.decomp.
- Done when: these units compile/link cleanly and downstream modules stop carrying local string/array workarounds.
