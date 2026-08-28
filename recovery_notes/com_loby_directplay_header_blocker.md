# com_loby DirectPlay header blocker

Status: SDK provider approved; module recovery pending.

The approved provider is documented in
`recovery_notes/directplay_sdk_provider.md`. The earlier candidates below
remain evidence only.

No VC98 header was added to the pinned VC5 include set. No VC98 build was run
for this hold. The hashes below record evidence only. They do not approve use.

## Requested VC98 headers

| Path | SHA-256 | Status |
| --- | --- | --- |
| `C:\msv6\VC98\Include\DPLAY.H` | `a08ddd487773c5a078989e713bb59f7f4fd55c8f1822265f15bfa1f0f4a955de` | Unapproved; not used |
| `C:\msv6\VC98\Include\DPLOBBY.H` | `6e8029d35c4d514cad22871c447b4a221b0dbdf3f7b24607b162156388a70bb9` | Unapproved; not used |

## Same-era sibling-project SDK headers

These headers came from the sibling `aoe1` and `aoe1_static_recomp` projects.
They carry the 1997 DirectPlay SDK surface. They remain unapproved and unused.

| Path | SHA-256 | Status |
| --- | --- | --- |
| `C:\Projects\my_decomps\aoe1\src\third_party\directplay\Include\dplay.h` | `a9a1618db5d14cc018da5c9091dd7c6e1e220c0ea564f8530eab2c11175d6dba` | Unapproved; not used |
| `C:\Projects\my_decomps\aoe1\src\third_party\directplay\Include\dplobby.h` | `dc483b3595e404bcb74044514dcf22e0311f7716761d7a182246cebbc5691bbb` | Unapproved; not used |
| `C:\Projects\my_decomps\aoe1_static_recomp\src\third_party\directplay\Include\dplay.h` | `a9a1618db5d14cc018da5c9091dd7c6e1e220c0ea564f8530eab2c11175d6dba` | Unapproved; not used |
| `C:\Projects\my_decomps\aoe1_static_recomp\src\third_party\directplay\Include\dplobby.h` | `dc483b3595e404bcb74044514dcf22e0311f7716761d7a182246cebbc5691bbb` | Unapproved; not used |

## Historical comparison

`C:\msv42\INCLUDE\DPLAY.H` was also found. It is not a sibling-project
header. Its SHA-256 is
`521cd84acbde05b00dff61dca26a23d68cdc87bb4bc5c368b8d7d466d2bbdf21`.
It is unapproved and unused.

## Vtable slot blocker

The target uses `IDirectPlay3::EnumPlayers` at slot `+0x30`.
The target uses `IDirectPlayLobby::SetConnectionSettings` at slot `+0x30`.
The target uses `IDirectPlayLobby::SendLobbyMessage` at slot `+0x2C`.

The pinned VC5 legacy `IDirectPlay` header places `EnumPlayers` at `+0x34`.
Its `EnableNewPlayers` method causes this slot difference. The modern VC98
headers provide the target slot order, but their use remains unapproved.

## Rejected local ABI provider

Commit `cef3346dd` is evidence only. Do not integrate it.

The PDB proves the required DirectPlay record layouts, inheritance, and virtual
slot counts. It does not prove SDK source ownership, the `GUID` and `DPID`
aliases, callback typedef names, or the `DirectPlayLobbyCreateA` prototype.

The candidate callback type also differs from the PDB interface type. The PDB
type uses `const DPNAME*`. The candidate type uses `DPNAME*`.

The candidate object emits C++ names for DirectPlay GUIDs and
`DirectPlayLobbyCreateA`. The target uses C symbols and the import
`_DirectPlayLobbyCreateA@20`.

The source calls local `operator_new` and `operator_delete` aliases. The target
calls the standard C++ operators `??2@YAPAXI@Z` and `??3@YAXPAX@Z`.

Focused checks masked these relocation target differences. Therefore, their
reported byte matches do not meet the direct-target exactness rule.

The approved SDK provider resolves the external ownership boundary. A new
module candidate must still fix the source and linkage issues above.
