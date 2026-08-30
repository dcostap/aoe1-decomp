# Function notes: 00436030 `command_add_waypoint`

## Recovered attempt history

<!-- recovered:e19d31d6efc038d31fed -->
### `target-session` `build/target_sessions/00436030_command_add_waypoint.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=2; shape=100.0: Fresh standalone baseline before waypoint relocation repair.
probe 2 abi; result=MATCH; diff=0; shape=100.0: Bound waypoint logging to the binary Log helper instead of the nonmatching TDebuggingLog_Log symbol.
```
<!-- end-recovered:e19d31d6efc038d31fed -->

<!-- recovered:6a570a2768117fe63264 -->
### `60ccce9b72be` `src/scratch/00436030_command_add_waypoint.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// RGE_Command::command_add_waypoint (__thiscall)
// VA: 00436030
// Command.cpp:2031-2070
// 155 bytes
//
// Attempt 3: Indexed loop and the binary Log helper.
```
<!-- end-recovered:6a570a2768117fe63264 -->
