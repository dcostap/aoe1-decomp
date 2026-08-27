# tpnl_tml.cpp module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\tpnl_tml.cpp`.
- Source: `src/tpnl_tml.cpp`.
- Header: `include/tpnl_tml.h`.
- Flags: `config/flags/0051E860_create_timeline.rsp`.

## Context gate

- PDB source module: proved by the generated module packet as `tpnl_tml.cpp`.
- Source lines and order: proved by the packet. The 25 normal owners span lines
  98-1570 and remain in increasing address and source order in the module.
- Owning class: proved by PDB symbols as `Time_Line_Panel` for all 25 owners.
- Address sequence: proved by the packet: `0051E650`, `0051E790`, `0051E860`,
  `0051E9E0`, `0051EAB0`, `0051EB00`, `0051EC10`, `0051EDD0`, `0051EEE0`,
  `0051F0A0`, `0051F0D0`, `0051F100`, `0051F120`, `0051F310`, `0051F4E0`,
  `0051F560`, `0051F600`, `0051FA30`, `0051FA90`, `0051FD90`, `00520080`,
  `00520220`, `005204A0`, `00520AE0`, `00520D50`.
- Exact anchors: proved by the owner symbols, direct call targets, field
  offsets, and the original `tpnl_tml.cpp` assembly. Examples include the
  `TEasy_Panel` constructor and destructor calls, `TShape` bounds and draw
  calls, `TPanel` setup and draw slots, the `rge_base_game` world/font calls,
  and the draw-area lock, device-context, and palette calls.
- Nearby generated owner: `0051E770` scalar-deleting destructor. It remains
  compiler-generated and is not listed as a handwritten normal owner.

## Migration

The module has one source file and one module header. The source keeps all 25
handwritten definitions in PDB order. It has no wrapper, source-bank include,
function-fragment include, fallback class declaration, recovery context macro,
or helper macro. The prior focused files and `src/tpnl_tml_tu.cpp` are removed
after direct validation.

The header owns the complete period class and record declarations needed by the
module. The source keeps the reviewed panel, timeline, event, draw-area, shape,
world, player, and font surfaces. It does not add a global definition or change
a cross-shard declaration.

## Prior state and expected migration effect

The packet reports 21 matching-bank owners, three scratch owners, and one
verified-logic owner. The old registered group contains the 21 matching owners.
The merged source is a structural migration, not a codegen-tuning pass. Isolated
exact results do not claim exactness for the merged source.

The three scratch owners remain unresolved after migration unless fresh grouped
validation proves otherwise: `0051F600 calculate_icon_location`, `0051FD90
draw_special_events`, and `005204A0 draw_timeline`. The constructor remains in
`verified_logic` because its documented store and vtable schedule differs from
the executable.

## Validation and regressions

Validation results are recorded here after direct translation-unit checks.
Grouped mismatches are not exactness or behavior claims.

- Generated packet: `build/source_reunification/terra_system/tpnl_tml_cpp/packet.{json,txt}`.
- Candidate proposal: `build/candidate_tus/tpnl_tml.json`.
- Candidate validator: rejected all direct-source owners because its pre-
  migration gate requires `src/matching` source-bank includes. It did not
  replace registered build evidence.
- Grouped audit: `build/audits/tpnl_tml_migration_final/report.txt`.
- Grouped result: 25 owners compiled; 21 registered owner matches, three
  grouped mismatches, and one boundary report. The 21 registered owners remain
  exact after the module move.
- Exact grouped owners: `0051E790`, `0051E860`, `0051E9E0`, `0051EAB0`,
  `0051EB00`, `0051EC10`, `0051EDD0`, `0051EEE0`, `0051F0A0`, `0051F0D0`,
  `0051F100`, `0051F120`, `0051F310`, `0051F4E0`, `0051F560`, `0051FA30`,
  `0051FA90`, `00520080`, `00520220`, `00520AE0`, and `00520D50`.
- The constructor differs by 125 bytes in the merged context. The three
  unresolved scratch owners differ by 718, 576, and 1310 bytes respectively.
  `005204A0` also reports three boundary mismatches. These are recorded as
  migration regressions and do not change source status.
- A standalone rebuilt check of `0051E790` reports `Result: MATCH` and
  `0.0000%`.
- The global flag audit reports pre-existing issues outside this module; no
  flag file was changed.

## Blockers

- The assigned `build/source_reunification/terra_system/orchestrator_contract.md`
  is absent from this checkout. The generated packet above is the available
  module packet.
- The three scratch owners retain the prior broad VC5 frame, switch, local-home,
  and register-topology differences. This migration does not claim exactness for
  them.
