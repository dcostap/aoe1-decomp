# com_loby.cpp source module

`src/com_loby.cpp` owns all 13 normal PDB functions in source order.
The source includes the approved DirectPlay headers.
The module response file adds only the approved DirectPlay include directory.

The game header includes Windows scalar types and forward declarations.
It does not include the DirectPlay SDK headers.
The SDK headers define anonymous record typedefs.
The source includes them before the game header.
This order avoids a VC5 typedef conflict.

The PDB records `RGE_Lobby` as a 28-byte class.
It records protected members at offsets 0, 4, 8, 12, 16, 20, and 24.
The SDK records used by the module have these sizes:

- `DPNAME`: 16 bytes;
- `DPSESSIONDESC2`: 80 bytes;
- `DPLCONNECTION`: 40 bytes;
- `DPCAPS`: 40 bytes.

The source keeps the PDB callback signature with `DPNAME*`.
The SDK callback takes `const DPNAME*`.
A narrow `reinterpret_cast` adapts the callback at `EnumPlayers`.

The source uses byte-array ownership for variable SDK buffers.
It uses `new[]` and `delete[]` for those buffers.
It builds a typed fixed message header before copying it to the byte buffer.

The following eleven owners are exact.
They have matching boundaries, owners, relocations, and direct targets:

`0042F290`, `0042F300`, `0042F330`, `0042F370`, `0042F3A0`, `0042F640`,
`0042F660`, `0042F680`, `0042F6B0`, `0042F6C0`, and `0042F6D0`.

`0042F430 CheckForLobbyLaunch` is scratch.
The valid `void*` QueryInterface outputs add a 35-byte frame and body change.

`0042F830 SendZoneMessage` is scratch.
The natural typed-header and byte-array ownership form changes its body.

The focused candidate report is `build/candidate_tus/com_loby_natural/report.txt`.
It reports eleven exact owners and two honest scratch observations.
