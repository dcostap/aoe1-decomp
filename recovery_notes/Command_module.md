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

The pinned VC5 compiler builds the complete source. The direct module audit
found 16 exact registered owners. Their claims remain registered in the Command
translation-unit entry. The other 24 former matching-bank owners remain in the
module manifest as matching recovery status, but are not registered as exact
owners after source consolidation:

`00433D40`, `00434290`, `00434320`, `00434400`, `004348B0`, `004348F0`,
`00434920`, `00434A00`, `00434D40`, `00435020`, `00435060`, `004350A0`,
`00435110`, `00435320`, `00435420`, `00435620`, `00435810`, `00435900`,
`00435AE0`, `00435CD0`, `00435D90`, `00435EA0`, `004360D0`, `00436150`.

These are source-shape regressions from the former isolated owners. The merged
source preserves the reviewed behavior and call surfaces. Exact repair resumes
on the final source tree.

The seven accepted-drift bodies remain accepted drift. The four scratch bodies
remain scratch. The complete audit also reports the expected relocation and
boundary differences for those nonexact bodies. No new exact claim is made by
this migration.
