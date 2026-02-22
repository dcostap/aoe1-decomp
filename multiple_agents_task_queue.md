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

## Task 8 — Remove “linker satisfaction” object virtual stubs by implementing real object virtuals
- [ ] Finished
- Implement: expand `RGE_Static_Object` virtual coverage (draw/update/command responders/etc.) so fewer calls land in placeholder behavior
- Where: src/game/src/RGE_Static_Object.cpp and shrink/retire src/game/src/rge_object_virtual_stubs.cpp accordingly (only as real implementations land)
- Source of truth: src/game/decomp/stat_obj.cpp.decomp (+ ASM audit where signedness/offsets look sketchy)
- Done when: high-frequency virtuals are decompiled for real and the stub file stops being a “primary behavior path.”
- Status note: `RGE_Static_Object` draw virtuals were implemented (merge `agent/rge-static-virtuals`, implement commit `397ebc9`), but `src/game/src/rge_object_virtual_stubs.cpp` still exists and remains a major follow-up.

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
- [ ] Finished
- Goal: remove remaining minimap view wrapper stubs and align minimap command behavior (click-to-move/work/do) with original.
- Implement: fill in `RGE_Diamond_Map_View` stubbed command handlers (`command_make_do/move/work`) and any other wrapper behavior required by the TRIBE minimap view path.
- Where: src/game/src/RGE_Diamond_Map_View.cpp and related headers under src/game/include; may also touch TRIBE_Diamond_Map_View glue if the TRIBE layer overrides behavior.
- Source of truth: src/game/decomp/vw_dimap.cpp.decomp, src/game/decomp/tvw_dmap.cpp.decomp, and the minimap setup/use sites in src/game/decomp/scr_game.cpp.decomp.
- Done when: minimap view wrapper no longer contains TODO/STUB blocks and minimap commands route into the same world/player command paths as the main view.
