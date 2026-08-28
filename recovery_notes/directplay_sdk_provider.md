# Approved DirectPlay SDK provider

Status: approved for `Com_hand.cpp` and `com_loby.cpp` recovery.

## Decision

Use these tracked headers:

- `third_party/directplay/include/dplay.h`
- `third_party/directplay/include/dplobby.h`
- `third_party/directplay/lib/x86/dplayx.lib`

Keep the pinned VC5 compiler. Add the third-party include directory only to
modules that require this SDK surface.

## Source and integrity

The tracked files are exact copies from `C:\msv6\VC98\Include`.

| File | SHA-256 |
| --- | --- |
| `dplay.h` | `a08ddd487773c5a078989e713bb59f7f4fd55c8f1822265f15bfa1f0f4a955de` |
| `dplobby.h` | `6e8029d35c4d514cad22871c447b4a221b0dbdf3f7b24607b162156388a70bb9` |
| `dplayx.lib` | `99ff5ab78c5189fb7090f8c2da08d0da1095833606ca422a051c83f988406739` |

Both files identify their Microsoft source period as 1997.

## ABI evidence

The PDB records `IDirectPlay2`, `IDirectPlay3`, `IDirectPlayLobby`, and
`IDirectPlayLobby2`. It does not record the later DirectPlay 4 or Lobby 3
interfaces. This fact selects the VC98 pair over the larger sibling-project
pair.

`Com_hand.cpp` also uses the old `IDirectPlay` interface for
`DirectPlayCreate`. Do not define `IDIRECTPLAY2_OR_GREATER` globally. The
approved header must emit both the old interface and the later interfaces.

The PDB marks five `IDirectPlay3` methods as non-pure virtual methods. The
approved header agrees. The later sibling header marks them as pure. This
metadata difference proves that the sibling header is not the period source.

A pinned VC5 probe compiled both approved headers. It confirmed the PDB record
sizes for `GUID`, `DPNAME`, `DPSESSIONDESC2`, `DPLCONNECTION`, and `DPCAPS`.

The emitted probe calls use these executable offsets:

- `IDirectPlay3A::EnumPlayers`: `+0x30`
- `IDirectPlayLobby2A::SetConnectionSettings`: `+0x30`
- `IDirectPlayLobby2A::SendLobbyMessage`: `+0x2C`

The callback type uses `const DPNAME*`. The API declarations use `WINAPI` and C
linkage. They produce the required standard imports and GUID names.

The game callback functions `EnumPlayersCallback2` and
`EnumPlayersCallbackLobby` use `DPNAME*` in the PDB. VC5 does not convert these
functions to the SDK callback type. Preserve their game signatures. Add an
explicit adaptation only at each SDK call site.

The original callback symbols are:

- `?EnumPlayersCallback2@@YGHKKPAUDPNAME@@KPAX@Z`
- `?EnumPlayersCallbackLobby@@YGHKKPAUDPNAME@@KPAX@Z`

The approved import library provides `_DirectPlayCreate@12` and
`_DirectPlayLobbyCreateA@20`. These names agree with the executable.

## Recovery rules

Remove all local DirectPlay record and interface copies from game headers.
Use the SDK callback types without replacement typedefs.

Use natural `new` and `delete`. Do not call allocator aliases.

Exact validation must check direct relocation targets. Relocation masking alone
is not sufficient.
