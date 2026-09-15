# Source cleanup report: `com_hand.cpp`

## Delivery

- Module: `src/com_hand.cpp`
- Branch: `cleanup/staging-20260915-221`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Initial delivery commit: `6d0a12480437318b0590c5f956844dcb3be8d30b`
- Changed files:
  - `src/com_hand.cpp`
  - `decomp_notes/source_cleanup/wave04/com_hand.md`
- Source SHA-256 after the initial cleanup:
  `93bebe0320eea974963fe83b619fb20b801aaff18cd17380d13cc7daeb82fc0a`
- Source SHA-256 after this correction:
  `d7187d12eff258db9dbf6c34585a7381b66cfeb7017b58341a4c66c9fb396df8`
- This correction applies 1TBS brace placement only. It does not change types,
  scopes, storage, expressions, control flow, calls, literals, or function
  boundaries.
- `include/com_hand.h` was read but not edited.

## Correction history

- The initial cleanup was delivered in commit
  `6d0a12480437318b0590c5f956844dcb3be8d30b`.
- This correction follows review feedback. It moves every function opening
  brace to the definition line and expands the resource lookup evidence.
- A follow-up correction moves the `if (InQ)` opening brace to the same line.
- The final correction commit is reported by the delivery response.

The source registry is `config/functions/src/com_hand.cpp.json`. It assigns 146
functions to this module. The registry and every assigned procedure were
queried. The source registry SHA-256 is
`a235a34e1c1a034ba06e0fa33e6e2dfb9ab8652db722d57d52ea45e781f77c2e`.

## Evidence inspected

I read the required source-cleanup, source-comments, resource-ID, ownership,
and testing guides. I ran each evidence-tool help command before use. I used
`query_abi.py` for every registry VA and inspected the procedure-scoped PDB
records for parameters, locals, registers, and function statics.

The PDB source path is `C:\msdev\work\age1_x1\Com_hand.cpp`. The scoped PDB
symbol inventory is the absolute main-root file
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`. Its
SHA-256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The generated clean summary is under the worker evidence directory at
`build/source-cleanup/com_hand-summary-clean.txt`.

The original executable behavior oracle is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

I also inspected the DirectPlay and VC5 headers needed to interpret the
parameter names. I did not change a header or copy an external asset.

## Original-name recovery

The PDB supplied reliable names for the assigned procedures. The cleanup
replaced decompiler placeholders and weak names with those spellings. This
includes communication buffers and IDs, player numbers, turn values, message
fields, DirectPlay objects, readiness data, GUID data, and retry state.
Examples include:

- `WaitingOnNamedInfo` and `WaitingOnInfo`: `PlayerNo`.
- `TCommunications_Handler` constructor: `WinHandle`, `MaxPlayers`,
  `ChatHandle`, and `AppGuid`.
- Command functions: `ExecuteOnTurn`, `command`, `nBytes`, `PFrom`,
  `Sequence`, and `ControlCommand`.
- Message receive functions: `Serialno`, `fromPlayer`, `CommBuff`,
  `dcoFromID`, `dcoReceiveID`, `fromHold`, `Content`, and `ContentSize`.
- Chat, player, GUID, and DirectPlay functions: `GamerID`, `DestPlayerNo`,
  `DestMap`, `PlayerNo`, `dpID`, `GameGuid`, `DPCaps`, `lpDP2`, `bEnable`,
  `pidID`, `lpName`, and `lpContext`.
- Retry and transmit functions: `serialno`, `toPlayer`, `OutCommBuff`,
  `FullLength`, `HeaderLength`, `txMsg`, `OutgoingCount`, and `SyncTurn`.

The PDB also identifies function-local names where the source had weak names.
The cleanup recovered `Now`, `LastAnyPlayerMessage`, `F`, `loopStartTime`,
`msg_str`, `sack`, `txpingpong`, `msg`, `NextSerialNumber`, `pdata`,
`alldone`, `i`, `dwCount`, `lpData`, `m`, and `DPCaps` where the storage and
source use were clear.

The PDB has reused stack homes in several procedures. For example,
`PreprocessMessages` reuses one home for `sack`, `txpingpong`, `msg`, and
`NextSerialNumber`; `SendSpeedChange` reuses a parameter home for `s`; and
`TXResendReply` reuses a home for `OutCommBuff` and `nosuch`. Where repeated
PDB names matched separate branch-scoped declarations and types, the source
uses those names. Other reused homes with uncertain declaration ownership were
left unchanged. No new declaration was added.

The PDB does not provide a source-owned replacement for some existing shared
buffers or loop locals. This includes `g_status_buffer`, `InContent`,
`InContentSize`, `dropcount`, the communication rate statics,
`comm_info_buffers`, `ready_player_buffer`, and several ordinary locals whose
PDB homes are optimized or reused. These names remain unchanged. The shared
definitions are owned by `src/game_globals.cpp`, outside this assignment.

The PDB records establish the original function boundaries and the `this`
register in `ecx` for member procedures. No calling convention, member layout,
virtual slot, or symbol identity changed.

## Constants, resources, and comments

No numeric constant changed. The existing `0x400` window message value remains
unchanged. The pinned VC5 `WINUSER.H` defines `WM_USER` as `0x0400`, but this
cleanup does not replace the literal. Existing DirectPlay, HRESULT, message,
and `COMMMESSAGES` values remain unchanged.

I inspected the base language DLL, the runtime expansion DLL, and the pinned
original expansion DLL. The source uses these eight IDs. IDs `0x04B5` through
`0x04B9` and `0x04BB` are not used by this module.

| ID | Base DLL: path; SHA-256; language; result | Runtime expansion DLL: path; SHA-256; language; result | Original expansion DLL: path; SHA-256; language; result | Use observed in this module |
| --- | --- | --- | --- | --- |
| `0x04B0` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`; `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`; `0x0409` (1033); text `Ready` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`; `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`; no matching language record; missing | `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`; `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`; no matching language record; missing | default waiting status |
| `0x04B1` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`; `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`; `0x0409` (1033); text `Computer` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`; `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`; no matching language record; missing | `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`; `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`; no matching language record; missing | computer player status |
| `0x04B2` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`; `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`; `0x0409` (1033); text `Empty` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`; `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`; no matching language record; missing | `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`; `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`; no matching language record; missing | absent or non-human status |
| `0x04B3` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`; `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`; `0x0409` (1033); text `Loading` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`; `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`; no matching language record; missing | `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`; `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`; no matching language record; missing | early-turn status |
| `0x04B4` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`; `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`; `0x0409` (1033); text `Waiting` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`; `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`; no matching language record; missing | `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`; `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`; no matching language record; missing | waiting-for-turn status |
| `0x04BA` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`; `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`; `0x0409` (1033); text `Player '%s' (%d) is not responding...` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`; `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`; no matching language record; missing | `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`; `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`; no matching language record; missing | timeout warning |
| `0x04BC` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`; `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`; `0x0409` (1033); text `Intentional drop of Ser#%d  Cmd=%d '%c' ` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`; `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`; no matching language record; missing | `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`; `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`; no matching language record; missing | intentional packet drop |
| `0x04BD` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`; `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`; `0x0409` (1033); text `Player %d - '%s' dropped/disconnected.` | `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`; `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`; no matching language record; missing | `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`; `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`; no matching language record; missing | dropped-player message |

No empty slot was reported for any listed ID. The two expansion extractions
reported no matching `RT_STRING` record for all listed IDs. The base extraction
reported language `0x0409` (1033) for all listed text entries.

The complete lookup path is an expansion override followed by a base fallback.
`TRIBE_Game::setup` first runs base setup. `RGE_Base_Game` sets
`string_dll_name` to `language.dll` and loads it into `StringTable` with
`LoadLibraryA`. `TRIBE_Game::setup` then sets the expansion name to
`languagex.dll`. A command-line `STRING=` option replaces that name before
`LoadLibraryA` loads it into `StringTableX`.

`TRIBE_Game::get_string` calls `LoadStringA(StringTableX, id, buffer,
buffer_size)` first. If that call returns zero, it calls
`RGE_Base_Game::get_string`. The base method calls
`LoadStringA(StringTable, id, buffer, buffer_size)`. The `com_hand.cpp` call
sites use `rge_base_game->get_string`, so the expansion override can supply a
localized string and the base `language.dll` supplies the fallback. Resource
text does not prove macro names, so no resource-ID declaration was invented or
requested.

No source comment was added. No assembly, binary dependency, layout, or source
owner changed.

## Header and shared-file requests

There is no header edit and no root-owned shared-file request. The recovered
parameter names may be applied to declarations by the header owner if a later
review requires declaration-name consistency. The request would be
name-only and would not change the ABI:

```cpp
TCommunications_Handler(void* WinHandle, unsigned char MaxPlayers,
                        TChat* ChatHandle, GUID AppGuid);
int AddCommand(unsigned long ExecuteOnTurn, void* command,
               unsigned long nBytes, int PFrom, unsigned char Sequence,
               int ControlCommand);
```

The source keeps declarations outside this assignment unchanged.

## Code-generation and scope review

The edit preserves all original types, declaration scopes, storage duration,
initialization points, explicit `this->` uses, casts, evaluation order, calls,
branches, logs, literals, and function boundaries. It adds no helper, wrapper,
macro, layout, or assembly. It does not alter the DirectPlay message formats or
resource lookup behavior.

I reviewed the complete assigned source diff. `git diff --check` passed.

Compilation, matching, audits, validation commands, tests, and games were not
run, as required by the wave procedure. The cleanup remains unvalidated until
the final comparison against the preserved pre-cleanup build.
