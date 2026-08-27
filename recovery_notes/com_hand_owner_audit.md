# Com_hand owner audit

Status: held. This note records evidence only. It does not approve a
`Com_hand` source module.

## Source ownership

- The PDB map assigns the normal range `00425750` through `0042F270` to
  `C:\msdev\work\age1_x1\Com_hand.cpp`.
- The PDB names the owner class `TCommunications_Handler` for this range.
- `NotifyWindow(COMMMESSAGES)` and
  `NotifyWindowParam(COMMMESSAGES, long)` use the decorated `COMMMESSAGES`
  type. `com_err.cpp` also uses that type in its `NotifyWindowParam` method.
- The binary proves the application message values below. It does not prove a
  declaration file or one translation-unit owner for the enum. Do not keep the
  current fragment-local partial enums as a canonical owner.

| Message | Value |
| --- | ---: |
| `COMM_PAUSE` | `0x17A2` |
| `COMM_RESUME` | `0x17A3` |
| `COMM_UPDATE_PLAYERS` | `0x17A4` |
| `COMM_UPDATE_PARAMS` | `0x17A6` |
| `COMM_LAUNCH_GAME` | `0x17A7` |
| `COMM_HOST_BUSY` | `0x17A8` |
| `COMM_HOST_EXITED` | `0x17A9` |
| `COMM_PLAYER_KICKED` | `0x17AA` |
| `COMM_NO_NEW_PLAYERS` | `0x17AB` |
| `COMM_NO_LINK` | `0x17AE` |
| `COMM_SYNC_ERROR` | `0x17B0` |
| `COMM_HOST_CHANGED` | `0x17B1` |
| `COMM_PLAYER_DROPPED` | `0x17B2` |
| `COMM_OTHER_PLAYER_DROPPED` | `0x17B3` |
| `COMM_PLAYER_RESIGNED` | `0x17B4` |
| `COMM_PLAYER_DEFEATED` | `0x17B5` |
| `COMM_PLAYER_SERVICE_ERROR` | `0x17B7` |
| `COMM_PLAYER_ID_SET` | `0x17B8` |
| `COMM_CANCEL_GAME` | `0x17B9` |
| `COMM_SHARED_DATA_SENT` | `0x17BB` |
| `COMM_NO_OTHER_HUMANS` | `0x17BC` |
| `COMM_PLAYER_NOT_RESPONDING` | `0x17BD` |

The packet records have generated PDB type evidence. Keep these names and
sizes when the owner is rebuilt:

- `MSGFORMAT_ONTURN`: `0x04`.
- `MSGFORMAT_SPEEDCHANGE`: `0x04`.
- `MSGFORMAT_ACKNOWLEDGE_GUARANTEED`: `0x08`.
- `MSGFORMAT_MISSING_PLAYER`: `0x08`.
- `MSGFORMAT_RESEND`: `0x08`.
- `MSGFORMAT_ALL_DONE`, `MSGFORMAT_LATENCY`, and
  `MSGFORMAT_KILL_PLAYER`: `0x0C` each.
- `MSGFORMAT_HEADER_GUARANTEED`: `0x0C`.
- `MSGFORMAT_CHECKSUM`: `0x24`.
- `MSGFORMAT_SETREADYOPTIONS`: `0x28`.
- `MSGFORMAT_CHAT`: `0x114`.

The `MSGFORMAT_*` layouts are in `inventory/types/dumps`. The packet command
bytes are binary facts, not a proved enum owner: `>`, `D`, `K`, `C`, `S`, `Q`,
`M`, `P`, `U`, `W`, and `+` occur in the Com_hand send paths.

The `DPSYS_*` values in `EvaluateSystemMessage` belong to the DirectPlay SDK
surface, not to a new Com_hand enum. The binary uses `0x0003`, `0x0005`,
`0x0007`, `0x0021`, `0x0031`, `0x0101`, `0x0102`, `0x0103`, `0x0104`,
`0x0105`, `0x0107`, `0x0108`, and `0x0109` for the shown system-message
cases.

## Global ownership

- `0062C4FC` is the shared `TDebuggingLog* L` receiver. Com_hand assembly
  calls `TDebuggingLog::Log` through this value. The PDB symbol is
  `__cdecl TDebuggingLog::Log(char*, ...)`. Use the reviewed `L` declaration
  and `include/debuglog.h`; do not add static, free, or fixed-arity logger
  aliases.
- `0062C5EC` is the persistent DirectPlay interface value. `CreateDirectPlayConversation`
  creates a temporary `IDirectPlay*`, then queries `IID_IDirectPlay3A` into
  this value. `GetDPInterface` returns `IDirectPlay3*`. The canonical stored
  type is therefore `IDirectPlay3*`, with inherited `IDirectPlay2` calls.
- `0062CF04` is the shared local DirectPlay player ID (`DPID`, four bytes).
  `AddSelfPlayer` passes its address to `CreatePlayer`; send, receive, name,
  caps, and destroy paths use the same value. It is not a communications
  object or a second player index.
- The Com_hand binary also uses `0062C5D0`, `0062CEF0`, `0062CF10`,
  `0062CF14`, `0062CF18`, `0062CF1C`, `0062CF20`, `0062CF24`, `0062CF28`,
  `0062CF2C`, `0062CF30`, `0062C5E4`, `0062C5E8`, `0062C5A8`, `0062C5B0`,
  `0062C5B4`, `0062C5B7`, `0062C5B8`, `0062C5F0`, `0062C6F0`, `0062C6F4`, and
  `0062C7F0`. The binary proves their addresses and local effects. It does
  not prove their source declarations or a shared public owner. Keep these
  unpromoted until that evidence exists.

## DirectPlay and Lobby types

PDB type evidence gives these canonical surfaces:

- `IDirectPlay` derives from `IUnknown`.
- `IDirectPlay2` derives from `IUnknown`.
- `IDirectPlay3` derives from `IDirectPlay2`.
- `IDirectPlayLobby` derives from `IUnknown`.
- `IDirectPlayLobby2` derives from `IDirectPlayLobby`.
- `RGE_Lobby` is `0x1C` bytes. Its fields are
  `IDirectPlayLobby* glpDPL` at `+0x04`, `IDirectPlayLobby2* glpDPL2` at
  `+0x08`, `IDirectPlay2* glpDP` at `+0x0C`, and `DPLCONNECTION*` at `+0x10`.
- `_GUID` is `0x10` bytes: one `unsigned long`, two `unsigned short` values,
  and eight bytes.
- `DPNAME` is `0x10` bytes with size, flags, short-name, and long-name fields.
- `DPSESSIONDESC2` is `0x50` bytes. Its GUIDs start at `+0x08` and `+0x18`.
  Its session and password pointers are at `+0x30` and `+0x34`.
- `DPLCONNECTION` is `0x28` bytes. Its session descriptor and player name
  pointers are at `+0x08` and `+0x0C`. Its service-provider GUID starts at
  `+0x10`.
- `DPCAPS` is `0x28` bytes with ten four-byte fields.

The exact Com_hand vtable calls are inherited DirectPlay2 slots: CreatePlayer
`+0x18`, EnumPlayers `+0x30`, GetCaps `+0x38`, GetMessageCount `+0x44`,
GetPlayerCaps `+0x4C`, GetPlayerName `+0x54`, GetSessionDesc `+0x58`, Open
`+0x60`, Receive `+0x64`, Send `+0x68`, SetPlayerData `+0x74`, and
SetPlayerName `+0x78`. These slots do not make `IDirectPlay4A` a valid PDB
owner.

## Hard blockers

- The pinned VC5 `DPLAY.H` is the 1994-95 DirectPlay1 header. It has no
  `IDirectPlay2`, `IDirectPlay3`, `DPSESSIONDESC2`, `DPNAME`, or
  `DPLCONNECTION` surface. The pinned include tree has no DirectPlay Lobby
  header.
- `IDirectPlay4A` is absent from the PDB type inventory. The current
  `include/directplay4a_context.h` is a local partial interface and is not a
  canonical owner.
- `include/com_hand_context.h` has duplicate partial COM vtables, fake
  descriptor fields, duplicate logger overloads, and aliases for the same
  globals. Do not promote it.
- The Microsoft 1997 `DPLAY.H` and `DPLOBBY.H` copies under `C:\msv6\VC98\Include`
  confirm supplemental field and slot evidence only. They are not approved
  build inputs and were not included or compiled for this audit.
- No exact source module can be built from the current pinned inputs without
  either an approved DirectX SDK exception or a reviewed canonical local
  declaration surface. This audit does not grant that exception.
