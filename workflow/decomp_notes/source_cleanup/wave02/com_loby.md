# `com_loby.cpp` source-cleanup report

## Delivery

- Module: `src/com_loby.cpp`
- Branch: `cleanup/staging-20260915-103`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `371a67c44fa9287b9235eed340c0f611431ef87a`
- Registry: `config/functions/src/com_loby.cpp.json`
- Registry header: `include/com_loby.h`
- Build flags: `gx_directplay`
- Changed files: `src/com_loby.cpp` and this report.
- Header changes: none. Owner 12 owns `include/com_loby.h`.

The source cleanup covers all 13 registry functions:
`0042F290`, `0042F300`, `0042F330`, `0042F370`, `0042F3A0`, `0042F430`,
`0042F640`, `0042F660`, `0042F680`, `0042F6B0`, `0042F6C0`, `0042F6D0`,
and `0042F830`.

Evidence came from the registry-selected packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/`:

- `0042F290_RGE_Lobby.txt`
- `0042F300_RGE_Lobby.txt`
- `0042F330_ClearLobbyInfo.txt`
- `0042F370_IsLobbyLaunched.txt`
- `0042F3A0_EnumPlayersCallbackLobby.txt`
- `0042F430_CheckForLobbyLaunch.txt`
- `0042F640_IsThisHost.txt`
- `0042F660_GetPlayerInfo.txt`
- `0042F680_GetSessionInfo.txt`
- `0042F6B0_SendZoneHandshakeResponse.txt`
- `0042F6C0_GameIsOver.txt`
- `0042F6D0_ReceiveZoneMessages.txt`
- `0042F830_SendZoneMessage.txt`

The scoped PDB evidence is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The original executable is
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup output is under
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`.
It was not changed.

## Original-name recovery

I inspected the PDB parameters, locals, and registers for every assigned
function. Member functions use the PDB register name `this` in `ecx`.
The callback has no register record. The PDB has no function-static record.

| VA | Function | PDB records and source mapping |
| --- | --- | --- |
| `0042F290` | `RGE_Lobby::RGE_Lobby` | `Host` (`void*`, `+0x4`) replaced `hwnd`. |
| `0042F300` | `RGE_Lobby::~RGE_Lobby` | No stack parameter or local record. |
| `0042F330` | `ClearLobbyInfo` | No stack parameter or local record. |
| `0042F370` | `IsLobbyLaunched` | No stack parameter or local record. |
| `0042F3A0` | `EnumPlayersCallbackLobby` | `pidID` (`unsigned long`, `+0x4`) replaced `dpId`. `dwPlayerType` (`unsigned long`, `+0x8`), `lpName` (`DPNAME*`, `+0xc`), `dwFlags` (`unsigned long`, `+0x10`), and `lpContext` (`void*`, `+0x14`) already matched. |
| `0042F430` | `CheckForLobbyLaunch` | `direct_play` (`IDirectPlay3*&`, `+0x4`) replaced `dplay`. `dwSize` (`unsigned long`, `-0x4`) already matched. |
| `0042F640` | `IsThisHost` | No stack parameter or local record. |
| `0042F660` | `GetPlayerInfo` | `player_name` (`char**`, `+0x4`) replaced `out`. |
| `0042F680` | `GetSessionInfo` | `info` (`DPSESSIONDESC2&`, `+0x4`) replaced `out`. |
| `0042F6B0` | `SendZoneHandshakeResponse` | No stack parameter or local record. |
| `0042F6C0` | `GameIsOver` | No stack parameter or local record. |
| `0042F6D0` | `ReceiveZoneMessages` | `dwDataSize` (`unsigned long`, `-0x808`), `Data` (`char[2048]`, `-0x800`), and `dwRXFlags` (`unsigned long`, `-0x804`) matched. `Data` replaced the lowercase source name `data`. |
| `0042F830` | `SendZoneMessage` | `Data` (`char*`, `+0x4`) replaced `data`. `dwSize` (`unsigned long`, `+0x8`) replaced `dataSize`. `guid` (`_GUID`, `+0xc`) already matched. |

The forward declaration for `EnumPlayersCallbackLobby` now also uses the
PDB name `pidID`. Public symbols, function names, types, order, and ABI
signatures did not change.

## Locals and unresolved mappings

The PDB has no local records beyond `dwSize`, `dwDataSize`, `Data`, and
`dwRXFlags` listed above. It has no function-static records. Existing source
locals without PDB names remain unchanged. They are not claimed as recovered
original names:

- `CheckForLobbyLaunch`: `result` and `connectionBuffer`.
- `ClearLobbyInfo`: `pLobby` and `result`.
- `ReceiveZoneMessages`: `result`, `message`, `dwMessageType`, and `msgType`.
- `SendZoneMessage`: `total`, `message`, `header`, and `result`.

Exception-chain stack homes in the packets are compiler records, not source
locals. No reused stack-slot mapping was forced.

No source parameter or local with a PDB record remains unresolved. The header
still has older parameter spellings. Owner 12 should apply the request below.

## Constants, resources, and comments

No numeric constant changed. No constant or enum was added. The packets show
the existing values and uses:

- `0042F3A0` tests callback flags `0x10` and `8`.
- `0042F430` uses allocation size `0x29`, session flags `0x44`, and maximum players `9`.
- `0042F430` compares the DirectPlay error `0x887700F0`.
- `0042F6D0` uses receive size `0x800` and error `0x887700BE`.
- `0042F6D0` dispatches system message type minus `1` to cases `0` through `3`.
- `0042F830` uses message type `5` and header size `data size + 0x30`.

Existing `GUID_NULL` and `sizeof` expressions remain unchanged. No local
header gives these uses a proved replacement with the same type and value.

This module has no resource lookup or resource ID. It does not call a string
loader. The language files were not used for this module. No resource request
is open for `runtime/language.dll`, `runtime/languagex.dll`, or the pinned
expansion file.

No source comment was added or removed. The existing callback comment remains
because the callback cast preserves the non-const game callback type.

## Code-generation review

The source changes rename parameters and one local buffer to match PDB names.
They preserve declarations, types, scopes, storage, casts, evaluation order,
control flow, calls, literals, and explicit `this->` use. The short
`SendZoneMessage` signature is now on one line under the 1TBS formatting rule.

The edits do not change object layout, public symbol identity, function
boundaries, relocations, or direct call targets. Debug line records may move
because one declaration line was joined. No inline assembly, helper, wrapper,
or structural rewrite was added.

## Header and shared-file requests

Owner 12 controls `include/com_loby.h`. The header parameter names can be
updated without changing types, order, virtual slots, or ABI:

```cpp
RGE_Lobby(void* Host);
unsigned char CheckForLobbyLaunch(IDirectPlay3*& direct_play);
unsigned char GetPlayerInfo(char** player_name);
unsigned char GetSessionInfo(DPSESSIONDESC2& info);
long SendZoneMessage(char* Data, unsigned long dwSize, _GUID guid);
```

No root-owned header request exists. No `include/resource_ids.h` request
exists. No shared declaration outside `include/com_loby.h` is pending.

## Validation

I ran evidence inspection, hash checks, `git diff --check`, and full Git diff
review. I did not run compilation, matching, audits, builds, tests, games, or
executable validation.
