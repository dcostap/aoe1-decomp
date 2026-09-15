# Source-cleanup coordination: September 15

## Contract

The user approved one pilot before the larger cleanup wave.
The selected worker is `openai-codex-secondary/gpt-5.6-luna` with `xhigh` thinking.
The later wave limit is ten active workers. Only one worker may run in the pilot.

Follow `docs/source_cleanup.md`, `docs/source_comments.md`, and `docs/resource_ids.md`.
No worker builds, matching checks, audits, or tests run during this phase.
Source inspection, evidence extraction, fingerprint capture, and Git diff review remain permitted.
Reviewed cleanup remains unvalidated until the final validation stage.
Generated code and program data must remain unchanged; accepted drift is not an outcome for this wave.

## Preserved baseline

Pre-cleanup source commit: `6d46835cdc6e31ba879a2e6e31415327a7c7e341`.
Baseline branch: `baseline/source-cleanup-20260915`.

Existing selected build:
`build/executable/ai-rng-filename-repair/20260915T083203564911Z/`.

Executable SHA256:
`492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.

Pilot object `scr_load.obj` SHA256:
`3e7373df6a3d374f9297cccc81f9d28603debc123652ef62377bfe5e486f5082`.

The existing build directory was copied without rebuilding to:
`build/source-cleanup-20260915/preparation/baseline-build/`.

Pilot source, header, registry, flags, and toolchain configuration copies remain under:
`build/source-cleanup-20260915/preparation/pilot-before/`.

This is preserved existing build evidence, not a new compiler result.
Final validation must compare against this baseline as well as report original-executable matching results.

## Module inventory and scheduling

Everything found 225 natural source registry files under `config/functions/src`.
All 225 have entries in the retained build report.
Their recorded input fingerprints agree with the current files at preparation time.
This fingerprint inspection did not compile or test the source.

The module list and transitive header-consumer map are in:
`build/source-cleanup-20260915/preparation/plan.json`.
The map uses the retained compiler input manifests, not only a textual direct-include scan.
Helper: `build/prepare_source_cleanup.py`.

The map is a scheduling baseline. Recompute affected ownership after shared-header integration.
Shared definitions and `src/game_globals.cpp` require explicit coordinated assignments; they are not free extra edit scope.
Do not create or launch the remaining module workers before reviewing the pilot and adjusting guidance.

The registry assigns `include/vw_main.h` to both `src/vw_main.cpp` and `src/tvw_main.cpp`.
Treat that as a shared-ownership decision, not two independent header assignments.
The recorded graph also has high-fan-out headers: `game_globals.h` reaches 147 TUs and `basegame.h` reaches 113.
Do not promise ten-way concurrency when an assigned header requires those dependents to wait.
Registry header hints need review; they do not replace explicit editing ownership.

## Pilot assignment

Worker ID: `cleanup-pilot-scr-load`.
Branch: `cleanup/pilot-scr-load-20260915`.
Worktree: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/pilot-scr-load`.
The launch base is the preparation commit containing this assignment and the approved guidance.
The orchestrator records the exact commit and managed-agent ID after launch.

Owned paths:

- `src/scr_load.cpp`
- `include/scr_load.h`
- `include/resource_ids.h`, if new verified resource definitions are useful
- `decomp_notes/source_cleanup/pilot_scr_load.md`

The pilot may add a conventional resource-ID header because no other cleanup worker is active.
Other headers, sources, tools, configs, registries, assets, and generated inventories remain read-only.

The source has five registered matching functions:

- `0049DD40`: constructor
- `0049E0A0`: destructor
- `0049E150`: `fillList`
- `0049E2B0`: `handle_idle`
- `0049E2E0`: `action`

Those are pre-cleanup statuses, not permission to claim that edited source still matches.
The configured module flag profile is `gx`.

Recorded consumers of `include/scr_load.h`:

- `src/dlg_smsg.cpp`
- `src/scr_game.cpp`
- `src/scr_load.cpp`
- `src/scr_sing.cpp`
- `src/tpnl_btn.cpp`
- `src/tribegam.cpp`
- `src/tvw_dmap.cpp`

Do not launch dependent workers while the pilot owns that header.
Later consumers of a new resource header must start after its definitions are reviewed and integrated.

## Evidence supplied to the pilot

Shared main-tree root: `C:/Projects/my_decomps/aoe1_attempt3`.
Workers may read shared evidence there but must not edit that tree.
Use absolute paths if a lean worktree omits original assets or generated inventory.

- Original executable: `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
- Original PDB and generated reference data remain under the main tree's original/inventory paths.
- Procedure-scoped PDB packet: `build/source-cleanup-20260915/preparation/pilot-pdb.json`.
- Full PDB reference: `inventory/pdb/scoped_symbols.json`.
- Original-function reference packets: `inventory/functions/0049/` for the five assigned VAs.
- Actual base-language resource input: `runtime/language.dll`; record its hash and language when interpreting strings.
- Resource lookup tool: `tools/inspect_pe_strings.py`; invoke it from the worker checkout with an explicit DLL path.
- Pinned CRT/SDK include paths: `config/toolchain.json`.

The PDB names for `action` parameters include `fromPanel`, `actionIn`, `a1`, and `a2`.
Short original names such as `a1` and `a2` must not become invented descriptive names by preference.
The function's PDB records also show reused stack slots. Do not split or reshape current buffers to imitate those records.

## Intake and review

The worker commits its complete assigned changes and report, then stops editing.
The orchestrator reads the report and the entire worktree diff.
Corrections resume the same worker. Do not silently accept only selected hunks.
No automatic expansion to the larger wave follows completion.

Launch base: `ce65dc808eee23c3d07acb7a5c4366890b933da1`.
Managed agent: `sa-af9710e1`, using the exact model and thinking level above.
First pilot completed at `5bee68e147f3d70bf5aee0e4186a135e14a5ab7a`; its worktree and commit remain preserved.
It is not integrated. All other module assignments remain held.

The new worktree uses a limited checkout for source, headers, config, tools, guides, and relevant notes.
Its initial empty index was populated from the launch commit before the worker started.
The worker began with a clean index and worktree. Main-tree original assets were not changed.

## Fresh pilot after guidance review

The user requested a fresh worker and worktree, not corrections to the first pilot.
The revised guide requires PDB name recovery, separates resource purpose from text, and allows full assigned-file formatting.
It specifies 1TBS, relaxed wrapping, and snake_case for newly assigned variable names only.

- Base: `436d8cf3b02546b68e57e7f79e8c3b8dd1168936`.
- Branch: `cleanup/pilot2-scr-load-20260915`.
- Worktree: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/pilot2-scr-load`.
- Agent: `sa-06ce0e61`, fresh context, `openai-codex-secondary/gpt-5.6-luna`, `xhigh`.
- Owned source/header paths: the same three paths as the first pilot.
- Owned report: `decomp_notes/source_cleanup/pilot2_scr_load.md`.

Git diff confirmed unchanged source and headers between the first launch base and this base.
An interrupted initial checkout required a fresh-worktree index restore before launch.
No Git process remained when its stale index lock was removed. Launch status was clean.
No first-pilot worktree, original asset, or preserved build was changed.

The new worker must use the updated guidance and supplied evidence without copying the first pilot's result.
Compare complete results before any broader launch. Validation remains deferred.

### Fresh pilot intake

The worker completed and stopped. Its worktree status is clean.

- Source commit: `18d952270bcbd8354a567dc7078a647456f0030e`.
- Report commit and final HEAD: `7b6579796d9ec46a64ec007969af812ca21278b6`.

The orchestrator read the complete source/header diff and the complete new report.
The reported hashes agree with Git output. All four changed paths are assigned paths.

Compared with the first pilot, the fresh result:

- Retains the same PDB-backed parameter and local recoveries.
- Names both help IDs despite missing text, with separate evidence for their roles.
- Uses 1TBS function braces and joins the action signature and several short calls.
- Reports name-recovery coverage for all five functions and preserves unresolved storage mappings.
- Adds no redundant source comments and makes no visible structural changes.

Some calls remain wrapped, including the constructor's `setup` call and the saved-game path `sprintf` call.
The formatting is improved, but those are possible further presentation changes for user review.
The resource naming differs slightly from the first pilot; these are descriptive names, not recovered macro names.

Neither pilot is integrated. No compiler checks, builds, matching checks, audits, tests, or games ran during this intake.
Generated-output equality remains unvalidated. No broader worker launch is authorized by this result alone.
