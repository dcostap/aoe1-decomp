# New-map startup crash investigation

## Reproduction

Tested main commit `48e2aad22` through the desktop UI.
Built all 226 source modules with `python tools/build_executable.py`.
Compilation and linking succeeded without unresolved symbols.

Build directory: `build/executable/20260906T235619943798Z`.
Runtime directory: `build/runtime/map_debug_48e2aad22`.
EXE SHA-256: `6039ef9eccef85a9cb42ded6f5eac426a43e17058f9a8e0c0f41c19070f3c279`.

Used the installed x86 CDB debugger and Python desktop screenshots and clicks.
Selected Single Player, Random Map, then Start Game.
First run used four players, Large Continental, Moderate difficulty, and default resources.
CDB captured the first access violation and saved full process memory before terminating the process.

Local evidence directory: `build/crash/map_setup`.
It contains screenshots, debugger commands, logs, and full dumps.
These large local artifacts are not the only record of the conclusions below.

## First fault

The rebuilt fault address is `00446152`, inside `RGE_Master_Static_Object::setup(int, ...)`.
The linker map gives this owner entry as `00445CB0`.
Its original registry entry is `004524E0`.
The fault instruction reads `sprites[death_sound_num]` in the damage-sprite loop.

Registers: EDX=`0FE13110`, ECX=`00006341`, EIP=`00446152`.
The read address is `0FE2BE14`. The sprite index is 25409.
The loop index is seven. The object address is `02A281F0`.
This happens during world database loading, before random-map object placement.

The authoritative check for `004524E0` reports `Result: MATCH` and `0.0000%`.
Thus the fault does not establish a defect in this function's recovered instructions.

## Proven initializer defect

`src/game_globals.cpp` initializes `save_game_version` to `0.0f`.
The dump confirms zero at its rebuilt address, `005F9B98`.

Original instructions at `004527FF` load this global from original address `0058EBCC`.
The original EXE stores bytes `29 5C E7 40` there, or float `7.23f`.
The oracle file is:
`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.

The zero value selects old-format database reads.
In the static-object reader, it skips fourteen bytes of drawing fields before reading attributes.
This provides a concrete cause for the shifted data interpretation and invalid sprite index.
Do not add a sprite bounds check to conceal this initializer defect.

## Diagnostic intervention

A second run changed only process memory at the initial debugger break:
`ed 005f9b98 40e75c29`.
No source or executable file changed.
This run also enabled the launcher's `DWM8And16BitMitigation` compatibility setting.
Its default map was Large Highland, with four players and Moderate difficulty.
Thus it was not a controlled same-map comparison.

The run passed database loading and reached random-map object placement.
It then stopped at another access violation, rebuilt address `005149EC`.
The owner is `TRIBE_World::check_destructables`, entry `005149D0` in `src/tworld.cpp`.
Instruction: `mov ecx,[edx+24h]`, with EDX=`FFFFFFFF`, reading address `00000023`.
The stack includes player object creation and random-map object generation.
The object ID in EAX and EBX is `109`.

This confirms further progress, not complete gameplay correctness.
The second fault's cause remains unresolved.

## Next work

## Initializer history

Commit `5a65cf8a7` (2026-08-28), `Reunify World source module`, introduced the zero initializer.
It added `save_game_version` with a group of World process-global definitions.
The preceding World context headers only declared `extern float save_game_version`.

The migration note described source ownership and compilation checks.
It recorded no evidence for the initial value of this global.
The global-owner audit recorded the correct float type and original address, `0058EBCC`.
It did not record the original initial bytes.

Commit `0aa947077e` (2026-08-29), `Consolidate canonical global storage`, retained the zero value.
Ordinary blame points there because that commit changed line endings on this line.
The substantive introduction is the earlier migration commit.

The documented gap is initial-value verification during global storage recovery.
The history does not explain the author's reason for selecting zero.
The retained function checks did not validate the global's initial data.

## Repair follow-up

Repair the version initializer with the original bytes as evidence.
Audit the shared-global dependency closure before integration.
Build and repeat the same map settings without debugger memory changes.
Trace the invalid pointer in `TRIBE_World::check_destructables` from the second dump.
No source repair, registry promotion, or gameplay success is claimed by this investigation.
