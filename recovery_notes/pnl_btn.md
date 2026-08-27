# Pnl_btn.cpp recovery notes

## Translation-unit ownership

The PDB source map identifies `C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp` as the owner of 56 normal functions at `00471EC0` through `00473BE0`. The direct source order follows the PDB line bands from constructor lines 59-75 through `restart_sound_system` lines 1293-1297.

The module owns `TButtonPanel` and its `TPanel` base surface. The reviewed layout checks `sizeof(TPanel) == 0xF4` and `sizeof(TButtonPanel) == 0x2B8`. The class declaration keeps the observed virtual slots and direct helper ABI. The source has one compiler-facing owner in `src/pnl_btn.cpp`.

The address sequence and exact anchors are proved by the packet generated from the PDB map and by the existing exact owner checks. The source-line sequence is the packet order. The class owner is `TButtonPanel` for all 56 entries. Direct-call and virtual-call anchors remain in the recovered method declarations and existing exact checks.

## Reunification

The prior wrapper included 56 per-function fragments and selected alternate field names with `PNL_BTN_SHARED_CONTEXT`. The direct module now includes `include/pnl_btn.h` once and defines all 56 bodies in PDB order. The body sources retain the reviewed exact reconstructions. Local fallback class layouts and wrapper macros are removed.

The constructor, destructor, setup, accessors, state, input, drawing, notification, and sound bodies came from the prior per-function owners. The former scratch `draw` body remains observed scratch code. The former accepted-drift `set_radio_info` body remains accepted drift. No behavior correction was made during migration.

## Validation and regressions

Before migration, the registered wrapper check for `00472030` reported `MATCH` and `0.0000%`. The migration changes source ownership and TU context. Re-run the grouped module checks after integration. Any byte or boundary change is a structural migration regression, not evidence to restore wrappers or fragments.

The module packet reports 50 registered exact owners, 54 matching-bank owners,
one accepted-drift owner (`00472240`), and one scratch owner (`004728C0`). The
four formerly unregistered matching-bank owners are `00471EC0`, `00472690`,
`004727B0`, and `00473120`.

The post-migration direct-TU sweep checked 54 registered owners. It returned 49
`MATCH` results. Five owners differ: `00471EC0` has a constructor scheduling and
vptr-store drift; `00472690` calls `set_redraw` at `+0x20` instead of `+0xE0`;
`004727B0` stores to `active` at `+0x6C` instead of `+0x80`; `00473120` has
different inherited virtual targets; and `00473930` changes coordinate-load
order. All five are scratch. The direct entry removes them. Do not hide these
differences with wrappers, fragments, synthetic declarations, or manual vtables.

The orchestrator contract named in the assignment was not present at the requested path. The available workflow documents and generated PDB packet supplied the context evidence.
