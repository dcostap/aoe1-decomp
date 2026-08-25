# Translation-Unit Recovery Orchestration Plan

## Purpose

This document defines the remaining translation-unit recovery work.

Use it as the main scheduling and integration plan.

The project remains function-first and exact-first. The original executable remains the behavior oracle.

## Current baseline

Phase 1 baseline commit: `6dad5c81 Complete Phase 1 exact owner registration`.

| Measure | Current value |
|---|---:|
| Original PDB C/C++ modules | 224 |
| Modules with registered exact coverage | 224 |
|  |  |
| Registered groups | 239 |
| Registered exact owners | 2,980 |
| Matching normal functions | 4,483 |
| Scratch normal functions | 638 |
| Accepted-drift functions | 348 |
| Verified-logic functions | 21 |
| Registered flag errors | 0 |

The Phase 1 integration audit is current.

## Current integration backlog

| Category | Functions |
|---|---:|
| Grouped exact, not registered | 0 |
| Not included in a registered wrapper | 642 |
| Included, but expected symbol not emitted | 186 |
| Grouped-context mismatch | 504 |
| PDB source attributed to a header | 134 |
| PDB source missing | 37 |
| Total unregistered matching functions | 1,503 |

Phases 0 and 1 are complete. Phase 2 is next.

## Terms

### Matching-bank function

The function matched in its isolated build context.

This result is useful evidence. It does not prove authentic module integration.

### Grouped exact owner

The function matches inside its reviewed translation-unit wrapper.

Its boundary, relocations, direct targets, PDB symbol, source owner, and module flags also match.

### Registered group

The project records the wrapper, module flags, and grouped exact owners in `config/translation_units.json`.

Registration does not claim that every function in the original module is exact.

### Complete wrapper

The wrapper contains every normal function from one original PDB module in authentic source order.

It also contains required generated entries and tracked module flags.

### Fully exact module

Every normal function in the original PDB module is grouped exact.

## Governing rules

1. Work by original PDB module before tuning individual functions.
2. Assign one captain to one module.
3. Never assign two editors to one module.
4. The main agent owns config, source-bank moves, shared ABI, registration, metrics, and commits.
5. Captains do not edit config, tools, tests, metrics, or commits.
6. Use tracked module flags. Remove stale per-function overlays after grouped proof.
7. Never depend on ignored files under `build/` for a registered wrapper.
8. Preserve natural VC5-era C and C++ source.
9. Do not use fake slots, raw vptrs, manual vtables, inline assembly, or ABI stubs.
10. Compile registered wrappers from source. Do not trust cached objects as the only evidence.
11. Run narrow checks during active work.
12. Run consolidated checks once per integration wave.
13. Serialize all writes to `config/translation_units.json`.
14. Preserve unrelated shared-worktree changes.
15. Record facts separately from hypotheses.

## Worker contract

Use `openai-codex-secondary/gpt-5.6-luna` at `xhigh` unless the user changes the contract.

Use fresh context for independent module work.

Every captain must read:

- `LESSONS.md`
- `docs/agentic_matching_workflow.md`
- repository `AGENTS.md` files

Every captain must report:

- changed files;
- PDB module and source-order evidence;
- exact owners before and after;
- generated entries before and after;
- observed mismatches;
- flags used;
- validation commands and results;
- unresolved blockers;
- useful next approaches.

A documented unresolved result is valid.

## Phase overview

| Phase | Goal | Primary owner | Parallel work |
|---|---|---|---|
| 0 | Stabilize all registered wrappers | Main agent and two captains | Two wrapper repairs |
| 1 | Register current grouped-exact omissions | Main agent | No config workers |
| 2 | Complete missing wrapper sections | Module captains | Four independent tracks |
| 3 | Restore missing symbol emission | Module captains and main tooling | Module-sized waves |
| 4 | Resolve grouped-context mismatches | Matching workers | Independent functions or modules |
| 5 | Establish authentic `.cpp` ownership | Main tooling and auditors | Read-only evidence work |
| 6 | Consolidate and close the recovery pass | Main agent | No overlapping writers |

---

# Phase 0: Stabilize registered wrappers

## Goal

Every registered wrapper must compile from tracked source with its registered module flags.

## Completion evidence

- `World.cpp` uses a tracked authentic master-player surface.
- `Pnl_btn.cpp` uses a tracked natural panel context.
- `Drawarea.cpp` uses one authentic imported API surface.
- `zone_map.cpp` uses authentic map and save declarations.
- All 239 registered wrappers compile from tracked source.
- All 2,764 registered exact owners match from fresh grouped objects.
- Translation-unit structural validation passes.
- Registered flag blockers equal zero.
- The refreshed integration audit has no wrapper compile errors.
- Nine stale exact-owner claims were removed after fresh grouped proof.
- Two ambiguous strategy symbols now use PDB-qualified mappings.

## Tasks

1. Review the complete `World.cpp` diff.
2. Validate every existing `world_scenario_sparse` owner.
3. Review newly grouped-exact `World.cpp` functions.
4. Commit the reviewed `World.cpp` repair separately.
5. Review the complete `Pnl_btn.cpp` diff.
6. Confirm the wrapper no longer includes ignored build files.
7. Validate every existing `pnl_btn` owner.
8. Review newly grouped-exact `Pnl_btn.cpp` functions.
9. Commit the reviewed `Pnl_btn.cpp` repair separately.
10. Force-build every registered wrapper from tracked source.
11. Run translation-unit structural validation.
12. Run the registered flag audit.
13. Rerun the unregistered integration audit.
14. Record the refreshed baseline in this document.

## Exit gate

Phase 0 is complete only when:

- every registered wrapper compiles;
- no registered wrapper uses ignored context files;
- every prior registered owner remains exact;
- registered flag errors equal zero;
- the refreshed integration audit completes without comparison infrastructure errors.

---

# Phase 1: Register grouped-exact omissions

## Goal

Register every function that already matches in its current grouped object.

The current audit found 193 such functions across 27 registered groups.

## Method

1. Group omissions by registered wrapper.
2. Preserve wrapper include order.
3. Confirm each canonical source path.
4. Confirm each PDB module and decorated symbol.
5. Recheck bytes, boundaries, relocations, and direct targets.
6. Scan the complete source closure for prohibited source forms.
7. Audit module flags.
8. Build one reviewed proposal per affected group.
9. Merge all approved owner additions into one config update.
10. Check every added owner after the config update.
11. Restore the prior config if any owner fails.
12. Run structural tests once after the complete wave.

## Efficiency rules

- Compile each affected wrapper once per audit pass.
- Reuse one grouped object for all owner comparisons in that wrapper.
- Do not run one config write per owner.
- Do not launch workers for config-only omissions.
- Do not promote incidental observed matches without source review.

## Exit gate

Phase 1 is complete when a fresh audit reports zero `grouped_match_not_registered` entries.

---

# Phase 2: Complete missing wrapper sections

## Goal

Include every normal C/C++ function in its authentic original module wrapper.

The old audit found 642 matching functions absent from registered wrappers.

They belonged to 15 modules.

## Old module ranking

| Module | Missing functions |
|---|---:|
| `taitacmd.cpp` | 164 |
| `basegame.cpp` | 125 |
| `taiinfmd.cpp` | 73 |
| `player.cpp` | 62 |
| `com_obj.cpp` | 37 |
| `Command.cpp` | 36 |
| `Drawarea.cpp` | 33 |
| `scr_mps.cpp` | 24 |
| `World.cpp` | 23 |
| `tcommand.cpp` | 23 |
| `diam_map.cpp` | 15 |
| `tworld.cpp` | 12 |
| `zone_map.cpp` | 8 |
| `sprite.cpp` | 4 |
| `Dib.cpp` | 3 |

Refresh this ranking after Phase 0 and Phase 1.

## Captain assignment

Assign one captain per PDB module.

The captain owns:

- the module wrapper;
- target-specific context;
- module function files;
- one candidate proposal;
- module-local build evidence.

The captain does not own shared config or commits.

## Required captain result

A completed module proposal must contain:

- every normal module function;
- exact owners;
- observed nonexact owners;
- generated entries;
- exact decorated symbols where ambiguity exists;
- authentic PDB source order;
- tracked module flags;
- no duplicate compiler-facing source owner;
- no ignored build-context dependency.

A proven source prefix remains a valid checkpoint.

## Parallel tracks

Run at most one active captain in each track.

### Foundation track

1. `basegame.cpp`
2. `player.cpp`
3. `World.cpp`
4. `tworld.cpp`
5. `zone_map.cpp`

These modules share game and world ABI surfaces. Keep them serial.

### AI track

1. `taitacmd.cpp`
2. `taiinfmd.cpp`

These modules share action, influence, group, and object-list surfaces.

### UI and render track

1. `Drawarea.cpp`
2. `scr_mps.cpp`
3. `diam_map.cpp`
4. `sprite.cpp`
5. `Dib.cpp`

Keep shared render declarations controlled within this track.

### Command and communications track

1. `Command.cpp`
2. `com_obj.cpp`
3. `tcommand.cpp`

Keep command identity and communications ABI changes serial.

## Main-agent integration

For each returned module:

1. Inspect the complete diff.
2. Reject broad or synthetic context.
3. Review shared ABI evidence.
4. Promote only fresh grouped matches.
5. Validate generated entries.
6. Run a registration dry run.
7. Apply approved config changes.
8. Check every new owner.
9. Commit only reviewed paths.
10. Refresh the module backlog.

## Exit gate

Phase 2 is complete when every normal `.c` or `.cpp` function appears in an authentic module wrapper.

A function can remain observed. It cannot remain outside its owning wrapper.

---

# Phase 3: Restore missing symbol emission

## Goal

Make VC5 naturally emit each expected function symbol from its authentic wrapper.

The current audit found 187 included source files whose expected symbols were absent.

These entries span 50 modules.

## Do not start with source tuning

First classify why the symbol is absent.

## Automated classifier

Build one generated packet per missing symbol.

The packet must include:

- VA and inventory name;
- expected decorated symbol;
- PDB module and line range;
- canonical source path;
- wrapper include position;
- preprocessed wrapper evidence;
- same-name symbols in the grouped object;
- isolated exact symbol metadata;
- relevant preprocessor conditions;
- current corpus classification;
- nearby generated entries.

## Classification classes

### Body excluded

The wrapper includes the file, but preprocessing removes the function body.

Action: repair the module context or conditional source.

### Wrong decorated symbol

VC5 emits a related symbol with the wrong class, overload, access, or calling convention.

Action: recover the authentic declaration and ownership.

### Unexpected inline emission

VC5 inlines the body and emits no required out-of-line symbol.

Action: recover the authentic inline declaration and natural use pattern.

### Missing template instantiation

The wrapper lacks the natural template use that causes emission.

Action: recover the authentic use or explicit period-plausible instantiation.

### Missing generated function

A constructor, destructor, vector helper, or COMDAT does not appear.

Action: recover natural lifetime, array ownership, deletion, or virtual use.

### Wrong translation-unit owner

Another original module should emit the symbol.

Action: send the entry to Phase 5.

### Wrong corpus class

The entry is generated, parent-owned, toolchain, or assembly code.

Action: propose reviewed corpus reclassification. Do not force ordinary source.

## Module work order

Start with modules that have large symbol sets.

Old leading sets were:

| Module | Missing symbols |
|---|---:|
| `stat_obj.cpp` | 23 |
| `move_obj.cpp` | 17 |
| `taiuaimd.cpp` | 16 |
| `victory.cpp` | 11 |
| `view.cpp` | 10 |
| `t_b_obj.cpp` | 10 |

Refresh this list before launch.

## Worker strategy

1. Assign one module captain first.
2. Repair shared module declarations once.
3. Preserve every existing exact owner.
4. Validate the complete grouped object.
5. Assign individual function workers only after correct symbol emission.

## Exit gate

Phase 3 is complete when every included normal source emits its expected symbol or has reviewed alternate ownership.

---

# Phase 4: Resolve grouped-context mismatches

## Goal

Make isolated exact functions remain exact inside their authentic module context.

The current audit found 526 grouped mismatches.

## Old mismatch distribution

| Grouped difference | Functions |
|---|---:|
| 0–1 bytes | 85 |
| 2–4 bytes | 90 |
| 5–16 bytes | 73 |
| 17–64 bytes | 90 |
| 65+ bytes | 188 |

Structural evidence included:

- 137 boundary failures;
- 20 relocation failures;
- 5 symbol-ownership failures.

Refresh these counts before assignment.

## Priority order

1. Symbol-ownership failures
2. Relocation-target failures
3. Boundary failures
4. Differences of four bytes or less
5. Differences of five through 64 bytes
6. Differences larger than 64 bytes

Byte count does not override structural evidence.

## Context-first rule

Do not assign a matching worker until the owning wrapper is complete and reproducible.

If many functions share one context defect, assign a module captain first.

## Matching-worker assignment

Assign one VA per worker.

Each assignment must include:

- authentic PDB module;
- wrapper and module flags;
- current grouped result;
- isolated exact result;
- boundary, relocation, and owner status;
- known shared context questions;
- useful prior attempts;
- exact donors and nearby functions.

Workers must perform sustained evidence-led work.

Do not set a fixed effort, probe, or hypothesis limit.

## Integration

1. Review the complete source diff.
2. Require an exact-finish retrospective.
3. Remove incidental codegen machinery.
4. Revalidate inside the authentic wrapper.
5. Promote only the smallest natural exact source.
6. Batch owner registrations by wrapper.
7. Run one config update per reviewed wave.

## Exit gate

Phase 4 is complete when no matching-bank function fails in its authentic grouped context.

Scratch and reviewed nonexact functions can remain explicit observed entries.

---

# Phase 5: Establish authentic `.cpp` ownership

## Goal

Find the original compiled `.cpp` owner for every header-attributed or unattributed normal function.

The old audit found:

- 134 header-attributed functions;
- 37 functions without PDB source attribution.

## Why this work exists

Headers are not translation units.

A header body exists in the executable because one original `.cpp` file emitted it.

The registry needs that original `.cpp` owner.

## Main tooling task

Extract a deterministic ownership map from the original PDB.

Map:

```text
function VA -> PDB module contribution -> original object -> original .cpp
```

Use:

- PDB DBI module records;
- section contributions;
- publics and decorated symbols;
- line records;
- COMDAT information where available;
- neighboring addresses;
- original object order evidence.

## Header-attributed functions

For each function:

1. Identify every original compiland that referenced the header.
2. Identify the compiland that contributed the selected executable symbol.
3. Map that compiland to its original `.cpp` module.
4. Confirm the candidate wrapper emits the exact decorated symbol.
5. Confirm bytes, boundary, relocations, and direct targets.
6. Register one canonical owner.
7. Reject duplicate owners from other wrappers.

Do not create fake header translation units.

## Functions without source lines

For each function:

1. Find its PDB module contribution.
2. Check FPO and public symbol records.
3. Check its executable section neighborhood.
4. Check direct calls and generated ownership.
5. Determine whether it is truly a normal function.

Possible reviewed outcomes are:

- original `.cpp` owner identified;
- compiler-generated;
- parent-owned fragment;
- toolchain-supplied;
- assembly or data-dispatch region;
- unresolved with explicit evidence.

## Human review

Use read-only auditors for ambiguous ownership cases.

Assign at most two named functions to one phase-readiness auditor.

The main agent makes every final ownership and corpus decision.

## Exit gate

Phase 5 is complete when every normal function has an authentic `.cpp` owner.

Every exception must have a reviewed non-normal corpus classification.

---

# Phase 6: Translation-unit campaign closeout

## Goal

Produce a reproducible, audited translation-unit recovery state.

## Tasks

1. Compile every registered wrapper from tracked source.
2. Validate every registered exact owner.
3. Validate every required generated entry.
4. Run the translation-unit flag audit.
5. Require zero registered flag errors.
6. Run translation-unit structural validation.
7. Run the full test suite.
8. Run `git diff --check`.
9. Regenerate source-module inventory.
10. Regenerate the status dashboard and project metrics.
11. Regenerate the unregistered integration audit.
12. Confirm no matching grouped owner is omitted.
13. Confirm no normal C/C++ function is outside its wrapper.
14. Confirm no registered wrapper depends on ignored files.
15. Commit generated tracked metrics only after review.

## Translation-unit acceptance state

- 224 original PDB C/C++ modules have authentic wrappers.
- Every normal C/C++ function appears in its owning wrapper.
- Every matching-bank function is grouped exact and registered.
- Every generated ownership claim is validated.
- Every header or unattributed function has reviewed ownership.
- Every remaining nonexact function is explicit observed work.
- Registered flag errors equal zero.
- The full test suite passes.
- The worktree is clean.

---

# Post-integration project campaign

Phases 0 through 6 complete authentic translation-unit integration.

They do not complete all normal source, global data, linking, or executable reproduction.

Use Phases 7 through 15 after the translation-unit acceptance gate passes.

## Campaign overview

| Phase | Goal | Primary owner | Parallel work |
|---|---|---|---|
| 7 | Recheck all observed functions in authentic modules | Main agent | Grouped build sweeps |
| 8 | Close remaining normal-function recovery | Matching workers | Independent module-ready targets |
| 9 | Consolidate natural source files | Module captains | Independent modules |
| 10 | Recover canonical global program structure | Main agent and ABI captains | Independent data domains |
| 11 | Account for the non-normal corpus | Main agent and auditors | Corpus-specific audits |
| 12 | Build and link the complete executable | Main agent | Narrow linker investigations |
| 13 | Compare the complete executable | Main agent | Difference classification |
| 14 | Run differential behavior tests | Test captains | Independent behavior domains |
| 15 | Complete reproducibility and cleanup | Main agent | No overlapping writers |

---

# Phase 7: Recheck all observed functions

## Goal

Recompile every observed normal function inside its complete authentic module.

Complete wrappers can change declarations, inlining, EH, virtual dispatch, and generated ownership.

## Current upper bound

These values come from the baseline before completion of Phases 0 through 6.

| State | Functions |
|---|---:|
| Scratch | 638 |
| Accepted drift | 349 |
| Verified logic | 21 |
| Total currently nonexact | 1,008 |

Refresh these values before Phase 7 starts.

## Method

1. Group all observed functions by authentic wrapper.
2. Compile each wrapper once.
3. Compare every emitted observed symbol from that grouped object.
4. Recheck boundary, relocation, call, and symbol ownership.
5. Promote natural grouped matches.
6. Register promoted owners in module-sized waves.
7. Rank all remaining mismatches from fresh grouped evidence.

An authentic context change is valid new evidence for an accepted-drift recheck.

Do not reopen accepted drift without such specific new evidence.

## Exit gate

Phase 7 is complete when every observed normal function has a fresh complete-wrapper result.

No observed function can retain a result from an incomplete wrapper as its current evidence.

---

# Phase 8: Close remaining normal-function recovery

## Goal

Recover the remaining nonexact normal functions with complete module context.

## Priority order

1. Wrong calls, relocations, or ownership
2. Wrong boundaries, cleanup, or exception handling
3. Small structural differences
4. Large behavior-complete functions
5. Hard semantic reconstructions

## Worker method

Assign one VA per matching worker.

Every packet must include:

- complete authentic wrapper;
- module flags;
- latest grouped result;
- exact original boundary;
- relocation and direct-call differences;
- source ownership;
- prior attempts and blockers;
- exact donors and nearby functions.

Workers continue while useful evidence-led approaches remain.

Workers must not preserve codegen machinery after finding a natural exact form.

## Main-agent integration

1. Review source behavior and ABI.
2. Require a retrospective for exact finishes.
3. Revalidate inside the complete wrapper.
4. Promote and register in reviewed module waves.
5. Record unresolved semantic conclusions in assigned ledgers.

## Two acceptance levels

### Source-recovery acceptance

Every normal function is exact or has reviewed semantic status and explicit evidence.

### Binary-exact acceptance

Every normal function is exact at its authentic boundary and owner.

A byte-identical executable requires binary-exact acceptance.

---

# Phase 9: Consolidate natural source files

## Goal

Replace temporary wrappers and per-function includes with natural source files.

The target is approximately one compiler-facing source file per original PDB translation unit.

## Method

Process one module at a time.

1. Freeze the grouped object and owner report.
2. Merge bodies into authentic PDB source order.
3. Replace wrapper-only context with canonical includes.
4. Remove fallback class surfaces and alias macros.
5. Remove duplicate declarations and local ABI copies.
6. Preserve binary-supported comments and original bugs.
7. Compile the consolidated module with the same flags.
8. Compare every exact and generated entry.
9. Replace the wrapper only after complete grouped proof.
10. Remove obsolete per-function files in the same reviewed commit.

Git history remains the source for removed recovery experiments.

Do not retain thousands of files only to preserve investigation history.

## Parallel work

Run independent module consolidations in parallel.

Serialize modules that share headers or global declarations.

## Exit gate

Phase 9 is complete when all 224 original modules use natural tracked source files.

No compiler-facing module can depend on wrapper-only or ignored context.

---

# Phase 10: Recover canonical global program structure

## Goal

Recover one coherent cross-module ABI and global data model.

Function bytes alone do not define the complete program.

## Required domains

- global variables;
- static data;
- string literals;
- vtables;
- RTTI;
- static constructors and destructors;
- callback tables;
- imported APIs;
- resources;
- cross-module class declarations.

## Method

1. Generate a complete non-function symbol inventory.
2. Assign one canonical source owner to each writable global.
3. Assign one canonical declaration to each shared symbol.
4. Recover array widths, field widths, alignment, and initialization order.
5. Recover class inheritance and virtual surfaces from grouped evidence.
6. Replace target-local ABI copies with reviewed shared declarations.
7. Validate every affected translation unit after each shared change.
8. Recover static initialization and shutdown order.

Avoid one large universal header.

Use small headers for proven shared domains.

## Exit gate

Phase 10 is complete when every linked data symbol has reviewed ownership and layout.

All 224 modules must compile against one coherent ABI surface.

---

# Phase 11: Account for the non-normal corpus

## Goal

Reproduce or supply every executable function outside the normal C/C++ corpus.

## Current classified corpus

| Corpus | Functions |
|---|---:|
| Padding-only | 185 |
| Compiler-generated | 193 |
| Parent-owned fragments | 15 |
| Toolchain-supplied | 1,519 |
| Named assembly | 13 |
| Assembly regions | 575 |
| Total | 2,500 |

Refresh these values before Phase 11 starts.

## Corpus rules

### Padding-only

Preserve reviewed bytes only where the complete body has no behavior.

### Compiler-generated

Require natural VC5 emission from authentic source and use context.

### Parent-owned fragments

Validate them as ranges within their owning normal function.

### Toolchain-supplied

Require the pinned VC5 toolchain, libraries, and linker inputs.

### Named assembly

Preserve reviewed original assembly ownership without converting it to ordinary source.

### Assembly regions

Recover region boundaries, codelets, dispatch data, and owning source or binary input.

## Exit gate

Phase 11 is complete when every executable function has one reproducible source category.

No ordinary source body can own a reviewed non-normal entry.

---

# Phase 12: Build and link the complete executable

## Goal

Produce one clean complete executable from tracked source and pinned inputs.

Exact function objects do not guarantee an exact executable.

## Required link evidence

- authentic object order;
- section order and alignment;
- COMDAT selection;
- linker flags;
- import layout;
- data layout;
- relocation layout;
- resources;
- executable headers;
- entry point and startup code.

## Method

1. Build all original modules from a clean directory.
2. Recover the authentic linker response and library order.
3. Produce a deterministic link map.
4. Link required resources and version data.
5. Record every non-source binary input.
6. Compare section layout before tuning metadata.
7. Resolve object-order and COMDAT differences from evidence.
8. Add one documented complete-build command.

## Exit gate

Phase 12 is complete when a clean tracked build produces a runnable complete executable.

The build must not depend on session artifacts or ignored recovery files.

---

# Phase 13: Whole-executable comparison

## Goal

Compare the rebuilt executable against the original at every important layer.

## Comparison layers

1. Executable headers and entry point
2. Section order, addresses, sizes, and hashes
3. Function addresses and bytes
4. Global data addresses and bytes
5. Imports and exports
6. Base relocations
7. Resources
8. Debug and build metadata

## Difference classes

Classify every difference as:

- source;
- compiler;
- linker;
- data;
- resource;
- toolchain;
- metadata.

Do not hide differences with broad masks.

Use relocation-aware views only for diagnosis.

## Exit gate

Binary-exact completion requires positional equality for the complete required executable image.

Any accepted metadata drift must have a narrow reviewed reason.

---

# Phase 14: Runtime differential validation

## Goal

Compare original and rebuilt behavior under the same controlled inputs.

## Behavior domains

- startup and shutdown;
- save and load;
- scenarios;
- AI;
- networking;
- rendering;
- sound;
- user interface;
- malformed input;
- original bugs and failure order.

## Method

1. Build deterministic test inputs.
2. Record original outputs and side effects.
3. Run the rebuilt executable with the same environment.
4. Compare files, logs, state, packets, images, and failures.
5. Minimize each difference before source changes.
6. Preserve original faults and malformed-input behavior.

Runtime tests supplement binary evidence. They do not replace it.

## Exit gate

All supported behavior domains must pass their differential suites.

Every remaining difference needs a reviewed limitation.

---

# Phase 15: Final reproducibility and cleanup

## Goal

Deliver a clean, understandable, and reproducible source-recovery project.

## Final requirements

- one-command clean build;
- pinned compiler, linker, libraries, and flags;
- no ignored build dependencies;
- no duplicate source owners;
- natural module source files;
- canonical shared headers;
- current metrics and inventories;
- complete ownership reports;
- passing tests;
- clean worktree;
- documented remaining differences.

## Cleanup rules

Remove obsolete recovery scaffolding after its replacement passes complete validation.

Send untracked cleanup artifacts to the Windows Recycle Bin.

Keep durable evidence in source notes, ledgers, manifests, and commits.

## Final project acceptance

The project is complete when its declared source-recovery and executable-reproduction goals both pass.

If binary identity remains incomplete, state the exact remaining difference classes.

---

# Wave cadence

Use this cycle for every integration wave.

## 1. Freeze inputs

- Record current config commit.
- Record active agents.
- Record affected wrappers and shared files.
- Prevent overlapping assignments.

## 2. Assign work

- One captain per module.
- One matching worker per VA.
- Keep shared ABI tracks serial.
- Count queued agents against the concurrency ceiling.

## 3. Review returns

- Inspect complete diffs.
- Confirm assigned scope.
- Validate claims locally.
- Reject synthetic context.
- Preserve unrelated edits.

## 4. Integrate source

- Apply source-bank moves centrally.
- Apply shared ABI changes centrally.
- Update proposals centrally.
- Do not write config yet.

## 5. Validate the wave

- Validate each affected wrapper.
- Audit flags.
- Check generated entries.
- Run targeted owner checks.

## 6. Update config once

- Merge approved groups and owners.
- Preserve config order.
- Check every added owner.
- Roll back on any failure.

## 7. Close the wave

- Run structural tests.
- Run affected tests.
- Run `git diff --check`.
- Commit explicit reviewed paths.
- Refresh the current backlog.

# Progress metrics

Track these values after every phase and major wave.

| Metric | Meaning |
|---|---|
| Registered wrapper compile errors | Registered groups that do not rebuild from tracked source |
| Grouped exact omissions | Current grouped matches absent from owner config |
| Functions outside wrappers | Matching C/C++ functions absent from owning wrappers |
| Missing emitted symbols | Included normal sources without expected grouped symbols |
| Grouped mismatches | Isolated matches that fail in authentic context |
| Header ownership unresolved | Header-attributed functions without `.cpp` ownership |
| Missing source ownership | Functions without PDB source or reviewed corpus class |
| Registered exact owners | Exact functions with approved authentic TU context |
| Scratch normal functions | Remaining unresolved normal functions |
| Fully exact modules | Original modules whose normal functions all match |
| Registered flag errors | Blocking flag issues in current registered groups |

# Immediate execution schedule

## Completed Phase 0 work

1. Integrated the `World.cpp` repair.
2. Integrated the `Pnl_btn.cpp` repair.
3. Integrated the `Drawarea.cpp` repair.
4. Integrated the `zone_map.cpp` repair.
5. Force-built all 239 registered wrappers.
6. Validated all 2,764 registered exact owners.
7. Corrected stale exact claims and ambiguous symbol mappings.
8. Refreshed the integration audit and this plan.

## Next main-agent work

1. Build the Phase 1 owner-addition plan.
2. Review all grouped-exact omissions.
3. Apply one consolidated registration wave.
4. Start Phase 2 module tracks.
5. Build the Phase 3 symbol classifier while captains run.
6. Build the Phase 5 PDB compiland mapper while captains run.
7. Start Phase 4 workers only for modules with complete wrappers.

# Plan maintenance

The main agent updates this document after each completed phase.

Do not change phase gates to hide unresolved evidence.

Update counts only from fresh generated reports.

Keep historical detail in commits, module source notes, and review ledgers.
