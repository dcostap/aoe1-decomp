# Command.cpp source-module migration

- PDB source: `C:\\msdev\\work\\age1_x1\\Command.cpp`.
- Source: `src/Command.cpp`.
- Header: `include/Command.h`.
- Flags: `config/flags/default.rsp`.

## Source order

The module owns 51 normal functions in PDB source order from `00433D40` through
`00436150`. The compiler-generated vector deleting destructor at `00433D70` is
not a normal source owner.

The complete source keeps all 51 bodies in that order. It removes the old
wrapper, source-bank includes, fallback declarations, and context macros. The
header now owns the shared Command declarations and layouts.
The dispatcher uses typed packet views for its direct helper calls.
The shared three-byte `XYZBYTEPoint` record is published by the narrow
`include/command_waypoint.h` header. `Command.h` includes that header so
consumers can use the Command-owned record without importing this full packet
surface.

## ABI correction

The AI order packet uses fields at offsets `+1`, `+2`, `+4`, `+8`, `+C`,
`+10`, `+14`, `+18`, `+1C`, `+20`, `+24`, and `+25`. Its protocol size is
`0x28`. The dispatcher passes range, immediate, in-front, and priority in that
order. Type 7 dispatches through the slot-zero give-attribute virtual.

The master object layout now places `name` at `+8`, `object_group` at `+14`,
and the radii at `+30` and `+34`. The static-object work virtual and the
incorrect player virtual slot are removed. Logging uses the absolute
`0x62C4FC` logger and its direct `TDebuggingLog::Log` target. The destructor
uses the proven `free` target at `0054B7D0`.

## Migration check

The PDB records use fixed headers. Stop and Pause are two-byte headers. Order,
Formation, Group AI Order, and Group Waypoint have no typed tail member.
Command source locates serialized `RGE_Obj_Info` values after each typed header.

The complete grouped report at
`build/command_complete_audit/result_natural_records_final/report.json` checks all
51 normal owners. The registered report at
`build/candidate_tus/Command/report.json` has 20 exact owners. Every registered
owner reports `MATCH` and `0.0000%`.

The fresh natural-record build demotes these 15 rows to scratch:

`00433D40`, `004348B0`, `004348F0`, `00435020`, `00435060`, `004350A0`,
`00435110`, `00435320`, `00435420`, `00435620`, `00435810`, `00435900`,
`00435AE0`, `00435EA0`, and `00436150`.

The grouped report has a boundary escape for `00435320`, `00435620`, and
`00436150`. No row without fresh grouped exact evidence remains matching.

The module has 20 matching, 24 scratch, and seven accepted-drift owners. The
complete audit records each nonexact result.
