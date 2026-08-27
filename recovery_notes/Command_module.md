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

## Migration check

The pinned VC5 compiler builds the complete source. The direct module audit
found 18 exact owners. Their claims remain registered in the Command module
translation-unit entry. The other 22 former matching-bank owners remain in the
module manifest as matching recovery status, but are not registered as exact
owners after source consolidation:

`00433D40`, `00434290`, `00434320`, `00434400`, `00434920`, `00434A00`,
`00434D40`, `00435020`, `00435060`, `004350A0`, `00435110`, `00435320`,
`00435420`, `00435620`, `00435810`, `00435900`, `00435AE0`, `00435CD0`,
`00435D90`, `00435EA0`, `004360D0`, `00436150`.

These are source-shape regressions from the former isolated owners. The merged
source preserves the reviewed behavior and call surfaces. Exact repair resumes
on the final source tree.

The seven accepted-drift bodies remain accepted drift. The four scratch bodies
remain scratch. The complete audit also reports the expected relocation and
boundary differences for those nonexact bodies. No new exact claim is made by
this migration.
