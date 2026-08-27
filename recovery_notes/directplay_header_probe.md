# DirectPlay header probe

## Result

No canonical header change is made.

The pinned include path has an old DirectPlay header. It does not provide the
DirectPlay types used by `Com_loby.cpp` and `Com_hand.cpp`.

The pinned header is:

`C:\Program Files (x86)\DevStudio\VC\include\DPLAY.H`

The configured include paths are:

- `C:\Program Files (x86)\DevStudio\VC\Include`
- `C:\Program Files (x86)\DevStudio\VC\MFC\Include`

There is no `DPLOBBY.H` in either configured path. The pinned `DPLAY.H` has
308 lines, 10,913 bytes, SHA-256
`1f8918161fd2f2e0b0c1cac127d966cdf89c31b161fc3e5319123518a87f6c86`, and a
1994-1995 copyright. It has `DPCAPS` with seven fields and `DPSESSIONDESC`
with a 124-byte layout. Its only DirectPlay COM interface is `IDirectPlay`.
It declares `DirectPlayCreate` and `DirectPlayEnumerate`, but does not declare
`DPNAME`, `DPSESSIONDESC2`, `DPLCONNECTION`, `IDirectPlay2`, `IDirectPlay3`,
`IDirectPlayLobby`, `IDirectPlayLobby2`, or `DirectPlayLobbyCreateA`.

## Pinned compiler probes

All successful probes used the configured `CL.EXE`:

`C:\Program Files (x86)\DevStudio\VC\Bin\CL.EXE`

The compiler reports version `11.00.7022`. The probe environment came from
`tools/common.py::tool_env`, with the paths in `config/toolchain.json`. The
flags came from `config/flags/default.rsp`:

`/nologo /c /O2 /Oy`

The temporary probe sources and objects are under
`C:\Users\Darius\AppData\Local\Temp\pi-subagents\sa-3cc81ce3`.
They are not project sources.

- `dplay_iunknown_vc5_probe.cpp` compiled with return code 0. It used only
  `<windows.h>` and `<dplay.h>`. It checked `sizeof(IUnknown) == 4`,
  `sizeof(IDirectPlay) == 4`, `sizeof(DPCAPS) == 28`, and
  `sizeof(DPSESSIONDESC) == 124`. It called `IUnknown::QueryInterface`,
  `IUnknown::AddRef`, `IDirectPlay::Send`, and `DirectPlayCreate`.
- `lobby_vc5_probe.cpp` failed with return code 2 because `dplobby.h` was not
  found.
- `lobby_no_dplobby_vc5_probe.cpp` failed with return code 2. The compiler
  reported missing declarations for `DPNAME`, `DPSESSIONDESC2`,
  `DPLCONNECTION`, `IDirectPlay2`, `IDirectPlay3`, and `IDirectPlayLobby2`.
- `current_loby_real_vc5_probe.cpp` failed with return code 2 when it included
  `<dplay.h>` before `include/com_loby_context.h`. The compiler reported
  redefinitions of `_GUID` and `IUnknown`.
- `current_hand_real_vc5_probe.cpp` failed with return code 2 when it included
  `<dplay.h>` before `include/com_hand_context.h`. The compiler reported
  redefinitions of `IDirectPlay` and `DPCAPS`.

These results show that the current context headers cannot include the pinned
header directly. Removing the copied declarations would still leave the
required DirectPlay 2/3 and lobby declarations unavailable.

The current `com_hand_context.h` declares a 52-byte `DPCAPS`, while the PDB
records a 40-byte `DPCAPS`. The current global declaration uses
`IDirectPlay4A`, while the PDB method type and the original source use
`IDirectPlay3*`.

## PDB and binary evidence

`orig/age1_x1.pdb` and the shipped copy have the same SHA-256:
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
`cvdump -t orig/age1_x1.pdb` reports:

- `DPCAPS` has ten fields and size 40. The fields end at `dwTimeout`.
- `DPNAME` has size 16.
- `DPSESSIONDESC2` has size 80. Its name and password fields are pointer
  unions.
- `DPLCONNECTION` has size 40.
- `IUnknown` has size 4. Its three methods use `STD Near` CodeView method
  types.
- `IDirectPlay2` has a 32-entry vtable shape.
- `IDirectPlay3` has a 47-entry vtable shape and size 4.
- `IDirectPlayLobby` has a 14-entry vtable shape and size 4.
- `IDirectPlayLobby2` has a 15-entry vtable shape and size 4.
- The PDB method type for `TCommunications_Handler::GetDPInterface` returns
  `IDirectPlay3*`.
- PDB globals include `IID_IDirectPlay2`, `IID_IDirectPlay2A`,
  `IID_IDirectPlay3`, `IID_IDirectPlay3A`, `IID_IDirectPlayLobby`,
  `IID_IDirectPlayLobbyA`, `IID_IDirectPlayLobby2`, and
  `IID_IDirectPlayLobby2A`. No `IDirectPlay4` or `IDirectPlay4A` type or IID
  appears.

The original assembly gives the same interface identity. In
`orig/ghidra_decomp/com_hand.cpp.asm`, calls at `00426f54`, `00427071`, and
`00427536` use vtable offsets `0x44`, `0x64`, and `0x68`. These are
`IDirectPlay2/3::GetMessageCount`, `Receive`, and `Send` in the full DirectPlay
2/3 header. The pinned old `IDirectPlay` header places these methods at
`0x40`, `0x54`, and `0x5c` and does not declare the required interface.

In `orig/ghidra_decomp/com_loby.cpp.asm`, calls at `0042f4aa` and `0042f51a`
use lobby vtable offsets `0x20` and `0x30` for `GetConnectionSettings` and
`SetConnectionSettings`. Calls at `0042f53e` and `0042f60e` use DirectPlay
vtable offsets `0x0c` and `0x30` for `IDirectPlay2::Connect` and
`IDirectPlay2/3::EnumPlayers`.

## Historical header comparison

The local Microsoft VC98 pair is:

- `C:\msv6\VC98\Include\DPLAY.H`
- `C:\msv6\VC98\Include\DPLOBBY.H`

A probe that directly included these real files compiled with the pinned VC5
compiler. With `/Z7`, its CodeView records had the same key sizes and vtable
shapes as the PDB: 47 entries for `IDirectPlay3`, 15 for
`IDirectPlayLobby2`, and sizes 16, 40, 80, and 40 for `DPNAME`,
`DPLCONNECTION`, `DPSESSIONDESC2`, and `DPCAPS`.

This is compatibility evidence only. These VC98 files are not in the pinned
`INCLUDE` list and must not be copied into the project or treated as the
configured toolchain header.

The local project pair under
`C:\Projects\my_decomps\aoe1\src\third_party\directplay\Include` is newer
and declares `IDirectPlay4A`. It is not a match for this PDB, which has no
DirectPlay 4 type or IID.

No source or consumer-header edit was independently justified by these facts.
