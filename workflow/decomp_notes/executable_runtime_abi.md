# Runtime declaration and ABI repairs

Base: `07a557c05`.
This follow-up is not yet approved for integration.
The complete closure must pass or receive complete behavior reviews.

## User direction: executable work

The user deferred further semantic reviews and selected executable completion as the current goal.
The registry now records these six unfinished functions as `scratch`:

```text
00435110 0045A500 0046B680 004C6DA0 005004C0 00532610
```

Their ledgers retain the known defects, open questions, and tested candidates.
Earlier matching-status statements in those ledgers describe historical states.
No behavior-equivalence approval follows from this status change.
The isolated `bestGroup` repair remains unintegrated.
Continue executable linking and runtime testing without further matching or accepted-drift review of these functions.

## Proven declaration repairs

### Executable follow-up: CRT and runtime data

The panel and tribe-game sources now use VC5 `<mbstring.h>` instead of invented double-underscore C identifiers.
The object-file C prefix already supplies one underscore.
Original CRT targets include `0054C8A0`, `0054C940`, `0054EC00..0054EF00`, and `0054F7E0`.
The first follow-up build compiles all 226 sources and reduces unresolved symbols from 278 to 267.
Report: `build/executable/20260906T031142181319Z/report.json`.

`game_globals.cpp` now defines the existing `TPanelSystem panel_system` object.
Original `00463BA0` calls `00463BB0`, then registers destructor wrapper `00463BD0` through `00463BC0`.
Both wrappers use object address `0062E870`; their direct targets are constructor `00463BE0` and destructor `00463C50`.
The compiler generates these startup and exit operations from the object definition.

The original mapped image supplies the following initial data.
Exact-reference anchors in `executable_build_evidence/checkpoint_vtables.json` identify the addresses.
Source declarations and memory-access widths identify the listed types.

| Definition | Original address | Initial value |
|---|---|---|
| `FILE* draw_log` | `005B2160` | null |
| `char draw_log_name[260]` | `00592A68` | all 260 bytes zero |
| `int do_draw_log` | `0062C498` | zero |
| `int safe_draw_log` | `00592A5C` | zero |
| `int do_fps_log` | `0062C52C` | zero |
| `FILE* fps_log` | `0062C530` | null |
| `int debugActions` | `0062C4C8` | zero |
| `long fog_next_shape` | `0086BBF0` | zero |
| `float g_time` | `0058EBCC` | `7.23f`, bytes `29 5C E7 40` |
| `int shape_version_110` | `0057FB58` | `0x30312E31`, bytes `31 2E 31 30` |
| `int startLoggingAI` | `0062C50C` | zero |

The `rgeLog` read at original `004E4B80+0124` names the same storage as `startLoggingAI`.
The caller now uses `startLoggingAI`; no duplicate variable or linker alias is added.
The base-game declaration also uses C++ linkage, consistent with the other callers.
The full build at `build/executable/20260906T032349113709Z/report.json` validates compilation of these additions.
It compiles all 226 sources and reports 222 unresolved symbols. Runtime tests remain unavailable before linking succeeds.

The preceding build, `20260906T031812810131Z`, failed to compile `game_globals.cpp`.
Its mixed include-path separators caused VC5 to process `game_globals.h` twice despite `#pragma once`.
Using the same forward-slash include form fixes the failure without changing the shared header.
Do not use that failed build's unresolved count as a progress measurement.

The same successful build includes 31 recovered play-file strings.
Their original addresses appear in `executable_build_evidence/play_file_strings.json`.
Original immediate operands in `00410220..00411340` identify the tokens and complete format strings, including trailing spaces.
The shared empty string also has prior exact-reference evidence.
`tests/test_executable_data.py` verifies every initializer, including its terminator, against the pinned original image.
All twelve focused executable-data, executable-build, and vtable tests pass.

The automated six-module check preserves all 426 matching targets.
Report: `build/audits/executable_crt_data_followup/report.json`.
No new semantic reviews were opened.

The next data pass reuses existing storage instead of defining duplicate aliases:

- `g_cut1` becomes `DAT_00575618`, the original float at `00575618`.
- `g_cut2` becomes `DAT_0057561c`, the original float at `0057561C`.
- `g_zero_double` becomes `DAT_00577a20`, the original zero double at `00577A20`.
- Campaign and game-info code share `version_marker` at original `005804A8`, with bytes `31 2E 30 30`.

`include/campaign.h` is the shared header changed by the marker repair.
The existing `DAT_00576D84` definition needs external linkage; its initializer remains unchanged.
The missing float at `00575078` has original bytes `00 00 80 3F` and now has value `1.0f`.
Two unit-AI logging strings at `0057F964` and `0057F980` also receive definitions and byte tests.
Their evidence extends `play_file_strings.json` to 33 strings.

The build at `build/executable/20260906T033234309577Z/report.json` compiles all 226 sources and reports 213 unresolved symbols.

### Function-local static storage

Positive procedure-scoped PDB records identify seven missing data symbols as function-local statics.
The source now restores those statics instead of adding false global definitions.

| Original storage | Owning function | Local declaration |
|---|---|---|
| `0086B250` | `0047E2A0 TTextPanel::get_text` | `static char empty_text` |
| `0086B24C` | `0047E2F0 TTextPanel::get_text2` | `static char empty_text` |
| `0086BCE0` | `0052A030 TRIBE_Game::game_over_msg` | `static char msg[256]` |
| `0062CF34` | `00431DD0 RGE_Communications_Queue::GetNextItemSingle` | `static void* retptr` |
| `0062CF38` | `00431E40 RGE_Communications_Queue::GetNextItemOrdered` | `static void* retptr` |
| `0062CF3C` | `00431D30 RGE_Communications_Queue::GetSpecificItem` | `static void* retptr` |
| `0062CF40` | `004319E0 RGE_Communications_Queue::ExpectedNextSequence` | `static unsigned char Count` |

Evidence command: `query_abi.py --va ADDRESS --limit 1` for each storage address.
The original mapped image contains zero bytes throughout each complete storage range.
The existing assignments and return paths remain in place.
`include/game_globals.h` no longer declares the two misplaced statics that it previously exposed.

Six separate global definitions use the existing declarations and original zero-initialized storage:
`DAT_0086b240` and `DAT_0086b244` are unsigned integers;
`DAT_0086b254` is the resource-file list head;
`DAT_0086bcac` has eight unsigned integers;
`DAT_0062D208` has nine longs; and `DAT_0062D230` is an unsigned long.
The source indexes the complete arrays; the original mapped ranges contain 32 and 36 zero bytes respectively.

The local-static build compiles all 226 sources and reports 200 unresolved symbols.
Report: `build/executable/20260906T133129363972Z/report.json`.

### Palette fading and command options

The palette-fade state at `0086B290..0086BAB3` contains 2,084 zero bytes in the original mapped image.
The source now defines its scalars, two 256-entry palettes, and draw-area pointer.
Original `004934AF` starts at `0086B2B0`; `004934E9` compares against `0086B6B0`, exactly 256 palette entries later.
The loop now uses its own array end, not the address of a separate array.
This prevents a new linker layout from changing the initialization range.
The following build compiles all 226 sources and reports 189 unresolved symbols:
`build/executable/20260906T133544838462Z/report.json`.

The next pass defines 29 runtime-option scalars from original data.
Addresses are recorded in `executable_build_evidence/runtime_scalar_data.json`.
The tests compare their complete initial bytes with the pinned image, including zero-filled storage.
The base-game option declarations now use C++ linkage, consistent with the other game callers.
The dialog and tribe-game declarations of `numberPathingIterations` also use C++ linkage.
Each formerly split C/C++ reference now selects one object, not an added alias.

The option-data build compiles all 226 sources and reports 153 unresolved symbols.
Report: `build/executable/20260906T134518535993Z/report.json`.

### Random log and shared runtime objects

Original `debug_random_reset` at `00423010` clears one byte per 100-byte entry.
It starts at `005B2378` and stops at `0062C498`: 500,000 bytes, or 5,000 entries.
The existing source incorrectly stopped after 25 entries.
The source now clears all 5,000 entries and defines the complete zero-initialized log array.
The new test checks the original loop instructions, original storage bytes, source extent, and reset limit.
This is a behavior repair, not a byte-tuning change.
An earlier matching label did not establish the correct array extent.

Original `00421F08..00421F36` supplies the memory-counter order for the timing log.
The four zero-initialized counters occupy `0062C538..0062C547`.
Their source initializers now receive original-byte tests.

The DirectPlay application GUID, service GUID, and interface pointer use zero-initialized storage at
`0062CF48`, `0062CF58`, and `0062CF6C`.
The session constructor fills them from the communications handler before enumeration.
Further shared definitions restore the mouse pointer, clipping-list pointer, drawing log, palette counters, and UI flags.
Exact-reference addresses remain in `checkpoint_vtables.json`.
The original path-display object ID at `00584C58` is 83, not zero.

The shared-object build compiles all 226 sources and reports 133 unresolved symbols.
Report: `build/executable/20260906T135447099472Z/report.json`.

### Remaining declaration and data repairs

The view classes now inherit `TPanel::capture_mouse` instead of declaring nonexistent child methods.
Original calls at `0053A1BB`, `0053D46A`, `0053D670`, `0053E785`, and `0053F277` target `00466220`.
The editor now inherits `TEasy_Panel::setup_popup_help`; original `004ABEC9` targets `0046A360`.
Original `0050AF12` calls `TDebuggingLog::Log` at `00436610`.
The town-upgrade command now uses that method instead of an undefined free helper.
The executable filename check uses CRT `_pgmptr` from the pinned standard header, not an invented C++ global.
Shared header changes: `include/view.h`, `include/vw_dimap.h`, and `include/scr_sed.h`.

The game screen now uses the existing C-linkage `_bPlaying` declaration from `dsutil.h`.
Its `byte_62C584` reference now uses the existing `do_color_log` object at the same original address.
Both save-screen names now use one array at original `005843B8`.
`include/scr_game.h` no longer exposes those duplicate declarations.

The player-drop storage is one nine-element integer array at `0086BCA8`.
The earlier `DAT_0086bcac[8]` definition represented its last eight elements, not separate storage.
The source now resets `player_dropped[i + 1]`, alongside the corresponding player arrays.
The partial definition and declaration were removed from `game_globals.cpp` and `include/game_globals.h`.

The 64 pick records at `0087D4A0` occupy 768 zero-initialized bytes.
The 256 diagonal-distance entries at `0074D040` occupy 1,024 zero-initialized bytes; the path constructor fills them.
The four obstruction masks and shifts at `00584EF0` and `00584EF4` retain their original bytes.
Further display and runtime flags use the original values recorded in `runtime_scalar_data.json`.

This build compiles all 226 sources and reports 100 unresolved symbols:
`build/executable/20260906T140748523096Z/report.json`.

The next pass restores 29 UI and source-path strings listed in `executable_build_evidence/ui_strings.json`.
The tests compare each complete initializer with the original bytes.
The empty dropdown and log-text captions use the existing array at `00592A40`.
Original caption operands include `004742C3`, `004950EC`, and `004B2FE5`.
The editor's empty captions use that same storage.
The two game-screen source-path names now use one array at `0058637C`.
No duplicate empty-string or path-array definition is added.

The UI-string build compiles all 226 sources and reports 68 unresolved symbols:
`build/executable/20260906T141845215982Z/report.json`.

The game destructor had incorrectly named its configuration-dialog string `s_Game_Screen`.
Original `004954C8` passes `005842D8`, which contains `Config Dialog`.
The constructor and update path instead pass `Game Screen` at `005842CC`.
The destructor now uses a separate, correctly named configuration-dialog array.
This resolves the mixed-address warning in the earlier executable-build notes.

### Further static ownership and runtime storage

PDB records identify `ddrval` and `err` as statics of `TDrawArea::Copy` at `0062E64C` and `0062E650`.
Both now belong to that function.
PDB also identifies three `TRIBE_Game` statics:

- `calc_timing_text::last_time`, unsigned long, at `0086BCD8`;
- `gameSummary::temp`, `char[1]`, at `0086BCA0`; and
- `handle_idle::last_wait_time`, int, at `0086BE04`.

The timing initializer now lets VC5 emit its guard instead of manually maintaining the byte at `0086BCD0`.
The original calls retain source-line arguments `0x7D4` and `0x7D6`.
The shared header no longer declares these function-owned objects or the compiler-owned guard.

The panel string buffer is 512 zero-initialized bytes at `0062E670`.
The session pointer at `0086B288` and write-error state at `0086B284` start at zero.
Compression starts enabled at `00585A6C`.
The repair-distance temporary, player debug flag, and reset state at `0086BC08`, `0086BC8C`, and `0086BE00` start at zero.
Rendering counters and pause/update flags use the addresses and values in `runtime_scalar_data.json`.
Original `004953EE` sets the pause flag; `004968FF` reads the enabled multi-update flag.
Original counter references include `004B956A`, `0053738C`, `005377E5`, `005377EB`, and `005380E5`.

The land generator reuses `DAT_00571ed0` instead of defining a second double at `00571ED0`.
Unit AI reuses `DAT_005758b0` instead of defining a second float named `SPEED_3`.

That build compiles all 226 sources and reports 45 unresolved symbols:
`build/executable/20260906T144947725191Z/report.json`.

### Runtime tables

PDB global records and array types establish these extents:

- `System_color_Table`: 21 eight-byte records at `005841E0`, type `0x2267`;
- `FacetSkipMask`: nine integers at `00584EF8`, type `0x128E`;
- `ObstructionMasks`: 192 unsigned longs at `00584F20`, type `0x1E86`; and
- four mouse tables: 40 records each, with 44 bytes per record, type `0x1469`.

All four original mouse-table size variables contain 40.
`runtime_tables.json` records each address, format, and extent.
The tests compare every source initializer byte with the original table.
These are data arrays, not copied game instructions.

The palette byte at `005841E5` belongs to `System_color_Table[0].green`.
The source now uses that field instead of a separate one-byte object.
`PAL_TABLE` now has one shared declaration in `include/Dib.h`.
`include/tribegam.h` checks the mouse-record size.
`include/game_globals.h` owns the shared table declarations.

The encryption lookup exposed a biased address, not an array start.
Original `00520FEB` indexes from `0058B760`, which lies inside preceding UI strings.
The 32-word table starts at `0058B860`; the next format string starts at `0058B8E0`.
The source now indexes the real table with `c - 0x40`.
The existing guard permits only `A` through `_`, so the lookup uses entries 1 through 31.

The table build compiles all 226 sources and reports 33 unresolved symbols:
`build/executable/20260906T151646533673Z/report.json`.
The first standalone table probe lacked a `MouseClickInfo` forward declaration.
After that declaration was added, all 24 focused tests passed.

### Allocation calls and private file state

Callers now use the real global `operator new` and `operator delete` functions through `<new.h>`.
No allocation wrapper or substitute implementation was added.
The original allocation and deletion entries remain `0054B6F0` and `0054B660`.
The earlier preserved allocation candidates supplied the tested call form.
Their known closure differences remain deferred; this change does not approve them.
Shared header changes are limited to `include/path.h` and `include/utmarray.h` for these calls.

PDB `cvdump -g` identifies the compressed-file state as file-static data, not shared integer globals.
`src/rge_fio.cpp` now owns the following objects:

| Address | Name | Type |
| --- | --- | --- |
| `0086B25C` | `compression_point` | int |
| `0086B260` | `current_handle` | int |
| `0086B264` | `flags` | unsigned char |
| `0086B268` | `point` | long |
| `0086B26C` | `compression_buffers` | unsigned char pointer |
| `0086B270` | `buffers` | unsigned char pointer |
| `0086B274` | `bl` | int |
| `0086B278` | `current` | unsigned char pointer |
| `0086B27C` | `file_size` | int |
| `0086B280` | `file_buffers` | unsigned char pointer |

All 40 bytes of the original storage start at zero, including alignment bytes.
Pointer allocation, copying, and release now use pointer types instead of integer casts.
The original decoder public names are `_Inf32BufSize` and `_Inf32Decode`.
The C declarations therefore use `Inf32BufSize` and `Inf32Decode`, without an extra source underscore.
The original PDB names their library `c:\msdev\work\compress\compress.lib`.
Its members are `.\Inf32.obj` and `.\Release\Deflate.obj`.
No replacement compression implementation has been selected.

PDB also identifies `Res_Files` at `0086B254` and `resource_missing_flag` at `0086B258` as file-static objects.
They now belong to `src/Res_file.cpp`, rather than `game_globals.cpp` or `include/Res_file.h`.

That build compiles all 226 sources and reports 19 unresolved symbols:
`build/executable/20260906T153826134853Z/report.json`.
All 25 focused tests passed before this build.

### Drawing entrypoint declarations

The PDB public records name the drawing exports `_ASMSet_*`, `_ASMGet_*`, and `_ASMDraw_*`.
Their C source names must not contain an additional leading underscore.
`include/asm_draw.h` now owns one declaration for each used drawing entrypoint.
The former declaration in `include/color.h` was removed.
All drawing callers use the shared header.

Original `0056C720` loads seven stack arguments and returns without popping them.
Original `0056C760` takes an integer color value and repeats its low byte in a 32-bit mask.
The view now passes its integer transform mask and shape pointer directly, without false pointer/integer casts.
The shadowing entry at `0056C680` consumes four 32-bit mask/value words.
These declaration repairs do not supply or replace the assembly bodies.

The resulting build compiles all 226 sources and reports 16 unresolved symbols:
`build/executable/20260906T155449388467Z/report.json`.
The symbol audit reports zero possible declaration conflicts.
The remaining entries comprise ten assembly drawing functions and six compression functions.

The complete function sweep compiles all 224 registered modules and checks 5,260 normal functions.
It preserves 4,720 of the 4,731 targets then marked matching.
The eleven mismatching labels now read scratch, without a new semantic approval.
Sixteen other grouped targets report `Result: MATCH` and `0.0000%`.
Their complete candidates and closure results are preserved in
`workflow/decomp_notes/executable_build_evidence/runtime_data_operators_candidates.md`.
No source or compiler recipe changed after that sweep; only statuses and documentation changed.

The vtable check finds 207 emitted tables, 206 located originals, zero conflicts, and zero unresolved slots.
It skips no groups and finds no address conflicts.
The full function and vtable reports are preserved in the evidence directory.

### Remaining compression evidence

Original `deflate_buf_size` at `0054A610` returns `0x3817C`.
Original `Inf32BufSize` at `0054B0C5` returns `0xAD90`.
Original `deflate_deinit` at `0054A490` stores its state pointer at `00887A80`.
It then writes `0xABCD1234` at state offset `0x38178`. It does not free the state.
The game caller releases that allocation separately.

The meanings of the three integer initialization options remain unproved.
The existing names `level`, `method`, and `window_bits` are provisional, not a proved zlib mapping.
The game passes `75`, `2`, and `1`.
No compatible compression donor or replacement implementation has been approved.

The existing owners define these game helpers with C++ linkage:

- `debug_timeGetTime(char*, int)` returns `unsigned long`.
- `debug_rand(char*, int)` returns `int`.
- `addstring`, `getstring`, and `convert_us` use the declarations in `mystring.h`.
- `GetDXVersion` uses the declaration in `getdxver.h`.
- `rge_fake_open` and both `rge_open` overloads use the declarations in `rge_fio.h`.

Caller declarations now agree with those owners.
Two calls pass a read-only view filename array through an explicit const cast for the period debug API.
The debug API reads the filename; it does not change it.

`save_game_version` uses its existing C++ definition.
The original words at `0056E784` and `0056E788` are the binary32 values for `3.1f` and `2.2f`.
The build-AI loader now uses those literals instead of nonexistent global variables.

## SDK and CRT calls

Native SDK declarations replace invented import-pointer variables for:

- `GetTickCount`;
- `OutputDebugStringA`;
- `WinHelpA`; and
- `mixerSetControlDetails`.

The original absolute references identify the real import-table entries.
No replacement pointer variable or forwarding function is added.
`WinHelpA` receives the same window, command, and data values.
The keyword pointer uses the SDK's required `DWORD` cast.

The file helper uses the pinned `_getcwd`, `_splitpath`, `_chdir`, and `_chdrive` declarations.
Five callers now name `_open`, not the nonexistent `__open` source function.
The sound loader uses the standard `calloc` declaration.
The picture module uses the reviewed `Dib.h` signatures.
The draw-area module's two bitmap calls use C++ linkage.

## Inherited nonvirtual methods

Original call instructions prove these owners:

| Call VA | Target VA | Owner |
| --- | --- | --- |
| `00537AA7` | `00466840` | `TPanel::get_string` |
| `0053A313` | `00466350` | `TPanel::bound_point` |
| `0043157A` | `004C5E50` | `RGE_Static_Object::distance_to_object` |
| `004A87DF` | `00466840` | `TPanel::get_string` |
| `004A8807` | `00466840` | `TPanel::get_string` |
| `004A9123` | `00466870` | `TPanel::get_string` |

The corresponding child classes no longer declare nonexistent shadow methods.
The editor's long text-creation call explicitly names `TEasy_Panel`, as the original direct call does.
Its initial scenario mode now uses the existing `ScenarioModeMap` enumerator.

`RGE_Tile` uses its canonical struct tag.
The static-object frame query uses the existing four-reference method.
The view cursor and touched-object calls also use their existing reference methods.
The touched-object output is an integer ID, not a separate long-valued overload.

## AI reference arguments

PDB parameter records corroborate the existing natural owners and original stack effects:

| VA | Method | Reference parameters |
| --- | --- | --- |
| `004DCF10` | `objectToAttackByGroup` | `AttackState&` |
| `004DEE90` | `setupInfluenceMap` | three `XYPoint&` values |
| `004DFCE0` | `mapBound` | `XYPoint&` |
| `004DFD60` | `findObjectMemoryLimits` | two `int&` values |
| `004E0040` | `isNextTo` | two `XYPoint&` values |
| `004E2A00` | `findClosestDropsite` | `int&` dropsite ID |
| `004F8570` | `civilian` | `XYPoint&` |
| `005004C0` | `bestGroup` | `XYPoint&` |
| `00500670` | `readyAndIdleGroup` | `XYPoint&` |
| `00501260` | `selectBestCommander` | `ManagedArray<int>&` |
| `00501B90` | `numberAvailableStoragePits` | two `int&` counts |
| `00501C70` | `numberAvailableGranaries` | two `int&` counts |

The duplicate pointer overloads had no definitions.
The callers now bind the same local objects and members directly to the reference parameters.
The hidden structure-return argument for `findObjectMemoryLimits` remains unchanged.

Three gatherer-task locals held building counts but had object-pointer types.
The original callees write integer counts, not pointers.
Those locals now use `int`; their zero tests and initial values remain unchanged.

## Validation still required

The first runtime-declaration audit is `build/audits/executable_runtime_declarations/report.json`.
It found two matching differences and a view compile error from filename const qualification.
The const casts repair that compile error.

The first differences were:

- `004D4F80`: two getter calls exchange order, with one corresponding comparison change.
- `004E0FD0`: two stack-argument loads exchange order before an unsigned-byte sum.

These are not automatically approved by the checker's diagnostic labels.
The later reference repairs change the compiler context again.
Use `build/audits/executable_canonical_calls/report.json` for the current closure result.

## Follow-up results

The campaign repair removes a duplicate fixed-argument `_open` declaration and names the real CRT `_tell` function.
The targeted campaign audit preserves all nine matching functions.
Its report is `build/audits/executable_canonical_campaign/report.json`.

The complete executable build compiles all 226 sources.
The link still fails with 278 unresolved symbols, down from 333.
The link-symbol audit reports zero possible declaration conflicts.
This heuristic result does not prove that every declaration is correct.
Build: `build/executable/20260906T015558855844Z/report.json`.

The shared closure finds sixteen formerly matching functions with byte differences.
Individual reviews now approve ten functions as accepted drift:

```text
004B98E0 004BA9E0 004BAAF0 004C3B30
004D4F80 004E0FD0 004FB550 00540010
00519F40 0053E340
```

Their deterministic `workflow/logic_reviews/<VA>.md` ledgers contain the behavior proofs.
The reviews cover address encodings, coordinate calculation, getter order, instruction scheduling, and private stack homes.
No function body changed during these reviews.
Three functions have demonstrated fault-order differences and are not approved:

```text
00435110 005004C0 00532610
```

Their ledgers give instruction-level memory examples with different first fault addresses.
Those examples are derived from disassembly, not claimed executed tests.
These functions require supported behavior repairs, not metric-only byte tuning.

Two functions have equal ordinary arithmetic but unresolved stack-capacity requirements:

```text
0045A500 0046B680
```

Their ledgers give stack-boundary examples where one frame fits and the other does not.
These are instruction-level examples, not claimed Windows runtime tests.
The map review confirms the complete terrain and border arithmetic, including unchanged x87 operations and widths.
The path review confirms the complete byte-address calculation and count update.
Neither review silently excludes stack exhaustion from an unconditional fault-equivalence claim.

One function still needs a complete floating-point exception review:

```text
004C6DA0
```

Its ledger derives both x87 value sequences and the equal finite numerical result.
It also records the original conversion and rounding helpers' control-word behavior.
The subtraction order changes, and the earlier rounding wrappers have exceptional return paths.
The proof must establish the reachable exception-mask states before approval.

The same source state makes four accepted-drift functions exact:
`00435020`, `004421F0`, `004B99F0`, and `004D5F00`.
Each standalone check reports `Result: MATCH` and `0.0000%`.
Their registry statuses remain unchanged until integration review finishes.
Each target's deterministic candidate path contains the complete source patch from `07a557c05`.
The affected owners are the ten approved functions and six unapproved functions listed above.

Durable closure, campaign, build, and unresolved-symbol reports are under
`workflow/decomp_notes/executable_build_evidence/canonical_calls/`.
No runnable executable exists yet.

## Review validation

`build/audits/executable_reviewed_runtime_drift/report.json` checks five modules and 505 functions.
It observes the seven selected drift results and retains 413 matching results.
Its three matching regressions are the already pending `004C6DA0`, `005004C0`, and `0053E340`.
The build-AI getter-order review uses `build/audits/executable_reviewed_build_ai_drift/report.json`.
That audit compiles the module and retains all 22 matching functions.
It observes the approved getter-order drift without another matching regression.
Translation-unit validation without build checks passes.
All eleven executable-build and vtable tests pass.
`git diff --check` passes.

The durable `canonical_calls/reviews/` directory contains original bytes, rebuilt bytes, and complete checker reports for the reviewed targets.
These files supplement the written proofs; they do not replace source ownership or direct-target checks.

The UI follow-up uses `build/audits/executable_reviewed_ui_drift/report.json`.
Both modules compile; all 28 matching functions remain matching.
The audit observes the two new approvals without any matching regression in those modules.
Translation-unit validation without build checks also passes.
Its ledgers cover both coordinate blocks in `0053E340` and every changed drawing block in `00519F40`.
The mouse review preserves arbitrary frame-output bits when the original frame query leaves an output unchanged.

The `taskTrain` stack-map output includes names from other functions in its translation unit.
Do not use those names as procedure-scoped evidence.
The review instead calculates both stack homes from the actual entry pushes and checks every use.
