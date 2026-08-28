# DirectPlay SDK headers

These files provide the approved period DirectPlay ABI.

The source files came from this local Microsoft VC98 include tree:

- `C:\msv6\VC98\Include\DPLAY.H`
- `C:\msv6\VC98\Include\DPLOBBY.H`

The files retain their Microsoft copyright notices. This repository does not
modify them.

## Pinned hashes

| File | SHA-256 |
| --- | --- |
| `include/dplay.h` | `a08ddd487773c5a078989e713bb59f7f4fd55c8f1822265f15bfa1f0f4a955de` |
| `include/dplobby.h` | `6e8029d35c4d514cad22871c447b4a221b0dbdf3f7b24607b162156388a70bb9` |
| `lib/x86/dplayx.lib` | `99ff5ab78c5189fb7090f8c2da08d0da1095833606ca422a051c83f988406739` |

## Selection evidence

Both headers identify their Microsoft source period as 1997.

The pinned VC5 header provides only the older DirectPlay surface. It does not
provide the required DirectPlay 2 and 3 types. Its include tree also has no
Lobby header.

The approved pair provides `IDirectPlay2`, `IDirectPlay3`,
`IDirectPlayLobby`, and `IDirectPlayLobby2`. These types agree with the PDB.
The later sibling-project pair also adds DirectPlay 4 and Lobby 3. The PDB does
not record those later interfaces. Therefore, this repository uses the smaller
VC98 pair.

A VC5 compile probe confirmed these record sizes:

- `GUID`: 16 bytes
- `DPNAME`: 16 bytes
- `DPSESSIONDESC2`: 80 bytes
- `DPLCONNECTION`: 40 bytes
- `DPCAPS`: 40 bytes

The probe also confirmed these virtual call offsets:

- `IDirectPlay3A::EnumPlayers`: `+0x30`
- `IDirectPlayLobby2A::SetConnectionSettings`: `+0x30`
- `IDirectPlayLobby2A::SendLobbyMessage`: `+0x2C`

These offsets agree with the PDB and executable. The SDK declarations also use
C linkage for GUIDs and DirectPlay API imports.

The PDB SDK callback type uses `const DPNAME*`. Two game callback functions use
`DPNAME*`. Their recovery must preserve the game signatures and adapt them at
the SDK call sites.

The import library is an exact copy from `C:\msv6\VC98\Lib\DPLAYX.LIB`.
It provides the required `_DirectPlayCreate@12` and
`_DirectPlayLobbyCreateA@20` imports.

Use these headers through an explicit module include path. Keep the VC5
compiler and standard include directories unchanged.
