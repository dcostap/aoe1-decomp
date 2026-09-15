# Source cleanup report: `Chat.cpp`

## Delivery and scope

- Module: `src/Chat.cpp`.
- Branch: `cleanup/staging-20260915-191`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source commit: `727e0dc3aafccda192d514b899a28cd6717ac082`.
- Changed files: `src/Chat.cpp`; this report.
- Paired header: `include/chat.h` (read only).
- Registry: `config/functions/src/Chat.cpp.json`.
- Registry build profile: `gx_no_fpo`.

The source registry owns 11 functions. This cleanup restores procedure-scoped
PDB parameter names and replaces the proven `WM_USER` value. It keeps types,
calls, literals, scopes, storage, order, layouts, and ABI symbols unchanged.

## Evidence reviewed

I reviewed the source registry at:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Chat.cpp.json`

I reviewed the procedure-scoped PDB index at:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The PDB source path is `C:\msdev\work\age1_x1\Chat.cpp`. The PDB records
identify `this` in `ecx` for every function. The original PDB SHA-256 is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

I reviewed the registry-selected original packets for all 11 functions:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423C30_TChat.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423CD0_TChat.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423D00_AddChatMsg.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423DF0_GetChatMsg.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423E10_ClearChat.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423E50_MaxArraySize.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423E60_setWindowHandle.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423E70_setInChatGroup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423E90_inChatGroup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423EB0_StopSoundSystem.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423EC0_RestartSoundSystem.txt`

The behavior oracle is:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
- SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup build report is:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`

That report selects `config/flags/gx_no_fpo.rsp` for this module. Its prior
`src/Chat.cpp` SHA-256 is `78b5f223e0bce7adeab517b08436d6c9c16a4edce7d82ba6f539fd6fddf08e9c`.
The final source SHA-256 is
`754dcc1276b7a64af8d1843f199fb3e715341c6bd44d2f31471f3b4341c36aad`.

## Original-name recovery

The table covers every source function in the registry. All listed functions
have the owning `this` register in `ecx`. No function-static PDB records exist.
No named local PDB records exist beyond the stack parameters listed below.

| VA | Function | PDB source span | Scoped PDB names and review |
| --- | --- | --- | --- |
| `00423C30` | `TChat::TChat` | `Chat.cpp:20-35` | Stack `HostWndIn` (`void*`, `+0x4`); register `this`. Recovered `HostWndIn`. |
| `00423CD0` | `TChat::~TChat` | `Chat.cpp:38-42` | Register `this` only. No parameter or local rename. |
| `00423D00` | `TChat::AddChatMsg` | `Chat.cpp:45-87` | Stack `PlayerName` (`char*`, `+0x4`), `Text` (`char*`, `+0x8`), and `Local` (`unsigned char`, `+0xc`); register `this`. Recovered all three names. |
| `00423DF0` | `TChat::GetChatMsg` | `Chat.cpp:147-158` | Stack `lineno` (`int`, `+0x4`); register `this`. Recovered `lineno`. |
| `00423E10` | `TChat::ClearChat` | `Chat.cpp:161-174` | Register `this` only. No parameter or local rename. |
| `00423E50` | `TChat::MaxArraySize` | `Chat.cpp:185-189` | Register `this` only. No parameter or local rename. |
| `00423E60` | `TChat::setWindowHandle` | `Chat.cpp:192-198` | Stack `newHandle` (`void*`, `+0x4`); register `this`. Recovered `newHandle`. |
| `00423E70` | `TChat::setInChatGroup` | `Chat.cpp:202-208` | Stack `playerNum` (`int`, `+0x4`) and `status` (`int`, `+0x8`); register `this`. Recovered both names. |
| `00423E90` | `TChat::inChatGroup` | `Chat.cpp:211-217` | Stack `playerNum` (`int`, `+0x4`); register `this`. Recovered `playerNum`. |
| `00423EB0` | `TChat::StopSoundSystem` | `Chat.cpp:220-223` | Register `this` only. No parameter or local rename. |
| `00423EC0` | `TChat::RestartSoundSystem` | `Chat.cpp:226-231` | Stack `driver` (`TSound_Driver*`, `+0x4`); register `this`. Recovered `driver`. |

The recovered names retain the original PDB spelling, including `HostWndIn`,
`PlayerName`, `Text`, `Local`, `lineno`, `newHandle`, `playerNum`, `status`,
and `driver`. The source replaced these prior names:

- `host_wnd` with `HostWndIn`.
- `speaker`, `text`, and `taunt_id` with `PlayerName`, `Text`, and `Local`.
- `index` with `lineno` in `GetChatMsg`.
- `value` with `newHandle` in `setWindowHandle`.
- `index` and `value` with `playerNum` and `status` in `setInChatGroup`.
- `index` with `playerNum` in `inChatGroup`.
- `sound_driver` with `driver`.

No new parameter or local name was invented. The source keeps the existing
`int i` locals in the constructor and `ClearChat`. The scoped PDB index has no
named local record for either variable, so no local mapping was forced.

## Constants, resources, and comments

The source now uses `WM_USER` for the existing `0x400` message argument.
The pinned VC5 SDK header proves this value at:

- `C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H:1498`
- `#define WM_USER 0x0400`

The `00423D00_AddChatMsg.txt` packet shows the original `push 400h` before
`PostMessageA`. The replacement keeps the value and effective integer type.

The custom message value `0x17D5` remains numeric. Its receive paths are
`src/scr_mps.cpp` and `src/tribegam.cpp`. Both contain a `0x17D5` case for
chat notification. No approved shared symbol was found. The loop bounds,
array indices, `MaxArraySize` return value, and all other numeric values remain
unchanged.

This module has no resource lookup and no resource ID. No language DLL or
runtime resource file was inspected. No source comment was added.

## Shared requests and unresolved questions

Root owns `include/chat.h`. Please align its declaration parameter names with
the recovered PDB names. Do not change types, order, scope, or ABI:

```cpp
TChat(void* HostWndIn);
int AddChatMsg(char* PlayerName, char* Text, unsigned char Local);
char* GetChatMsg(int lineno);
void setWindowHandle(void* newHandle);
void setInChatGroup(int playerNum, int status);
int inChatGroup(int playerNum);
int RestartSoundSystem(TSound_Driver* driver);
```

This request changes declaration names only. It does not block this source
cleanup. The source has no unresolved PDB-backed parameter mapping.

Root may also review a shared name for custom message `0x17D5`. Evidence is
`TChat::AddChatMsg` posting the value and the chat cases in `scr_mps.cpp` and
`tribegam.cpp`. This worker leaves the value numeric and defines no duplicate.

## Code-generation risks and validation limits

The source changes parameter identifiers and replaces `0x400` with a VC5 SDK
macro that expands to `0x0400`. They do not change types, casts, declarations,
scopes, storage, evaluation order, control flow, calls, relocations, layouts,
or ABI symbols. The parameter names can change debug metadata. No comments or
line-dependent macros changed.

I reviewed the complete base-to-head diff and ran `git diff --check`.
Compilation, matching, audits, and tests were not run. No compiler, build,
matching check, audit, test, or game command was run for this assignment.
