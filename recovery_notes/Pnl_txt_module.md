# Pnl_txt.cpp module merge

- PDB source: `C:\msdev\work\age1_x1\Pnl_txt.cpp`.
- Source: `src/Pnl_txt.cpp`.
- Header: `include/Pnl_txt.h`.
- Packet: `build/source_reunification/packet/Pnl_txt_cpp`.

## Source order

The source owns all 65 normal PDB owners in address and source order. The
nearby scalar deleting destructor at `0047C090` is compiler-generated and is
not a normal source owner.

The module header owns the panel, shape, scrollbar, text-node, and text-panel
layouts. The source contains the 65 bodies. It has one compiler-facing source
owner and no per-function includes, fallback declarations, context macros, or
wrapper source.

## Context evidence

The packet identifies the PDB source module and its line bands from
`Pnl_txt.cpp:73-1916`. The owner sequence runs from `0047BF40` through
`0047E410`, with the compiler-generated destructor at `0047C090` between the
constructor and destructor. The existing registered group was `Pnl_txt_cpp`;
its source now points directly to `src/Pnl_txt.cpp`.

## Pre-migration check

The authentic wrapper check covered 65 included normal functions. It reported
56 registered matches, three accepted-drift observations, three grouped
mismatches, two boundary problems, and one relocation problem. The known
observations were retained as source bodies. The current source records the
boundary-crossing `0047D9E0` row as scratch.

## Post-migration check

The direct source module compiled all 65 owners. The 56 registered owners
remain exact. The nine unregistered owners remain observations or known
nonexact owners. Their direct checks need temporary observed-owner support in
the current checker; the checker rejects symbols for unregistered module
members. The candidate-TU validator has the same limitation because it only
accepts old wrapper includes and matching-bank exact owners.

Observed direct checks from the rebuilt module gave these results:

- `0047C0B0`: `MISMATCH`, 95 positional bytes, 50 rebuilt bytes versus 106.
- `0047C640`: `MISMATCH`, 986 positional bytes, 1061 rebuilt bytes versus
  1064. The module field cleanup removed three emitted bytes.
- `0047CC10`: `MISMATCH`, 219 positional bytes, 181 rebuilt bytes versus 223.
- `0047CE70`: `MISMATCH`, 15 positional bytes, matching size and calls.
- `0047D2C0`: `MISMATCH`, 18 positional bytes, matching size and calls.
- `0047D760`: `MISMATCH`, 232 positional bytes, 636 rebuilt bytes versus 634;
  the rebuilt range crosses the original boundary.
- `0047D9E0`: `MISMATCH`, 523 positional bytes in the current audit; the
  rebuilt range crosses the original boundary. Its source status is scratch.
- `0047DD70`: `MISMATCH`, 184 positional bytes, 538 rebuilt bytes versus 541.
- `0047E2A0`: `MISMATCH`, 3 positional bytes, matching size and calls.

`0047DD70` remains accepted drift. The current direct comparison keeps the
first 321 bytes, size, frame, and all ten calls aligned. The residual is in
private registers and equivalent list-loop lowering. Both paths read the same
links and write the same node, links, count, redraw state, and return values.
No call, allocation, free, memory access, or fault order moves.

The direct all-owner comparison in `build/audits/Pnl_txt_direct_all.json`
reported 56 `MATCH` results and these nine known observations. It used the
compiled module object and explicit decorated symbols for the nine
unregistered members. The normal checker cannot perform these nine checks from
global config because it rejects symbols for unregistered members. The
candidate-TU validator has the same limitation because it only accepts old
wrapper includes and matching-bank exact owners.

The two matching owners with custom per-function flags, `0047C0B0` and
`0047CC10`, remain outside the default grouped exact-owner registration. Their
isolated custom-flag checks were not changed by this source move.
