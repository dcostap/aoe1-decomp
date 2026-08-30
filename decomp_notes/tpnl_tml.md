# tpnl_tml.cpp module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\tpnl_tml.cpp`.
- Source: `src/tpnl_tml.cpp`.
- Header: `include/tpnl_tml.h`.
- Flags: `config/flags/gx.rsp`.

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

The header owns `Time_Line_Panel` and `Special_Events`. It includes the
canonical easy-panel provider. It forward declares its pointer-only Shape,
text-panel, history, player, and world types. The source imports their complete
canonical providers. It does not copy those classes.

The header relies on natural alignment. Size checks prove `Special_Events` is
`0xB0` and `Time_Line_Panel` is `0x52C`.

The source uses canonical `set_redraw`, Shape bounds, draw-system palette,
typed player indexing, TRIBE player history, color-table, and master-player
fields. It uses `new` and `delete` for `Special_Events` and typed deletion for
legend entries. It has no recovery experiment comments, raw player cursor,
absolute string address, C-style scalar or pointer cast, or byte alias.

## Prior state and expected migration effect

The packet reports 21 matching-bank owners, three scratch owners, and one
verified-logic owner. Natural source cleanup changed four former exact owners.
They are now scratch. The module has 17 matching owners, seven scratch owners,
and one verified-logic owner.

## Validation and regressions

Validation results are recorded here after direct translation-unit checks.
Grouped mismatches are not exactness or behavior claims.

- Generated packet: `build/source_reunification/terra_system/tpnl_tml_cpp/packet.{json,txt}`.
- Candidate proposal: `build/candidate_tus/tpnl_tml_canonical_panel/proposal.json`.
- Candidate validation: all 17 registered exact owners and generated owner
  `0051E770` match. Each match has zero differing bytes, no relocation-target
  mismatch, and no boundary escape.
- `0051E790` differs by 177 bytes, has one relocation-target mismatch, and
  has two boundary escapes after typed legend-entry deletion.
  `0051F4E0` differs by 120 bytes. `0051F560` differs by 123 bytes.
  `00520220` differs by 372 bytes. These owners are scratch.
- The verified constructor differs by 125 bytes. The other scratch owners
  differ by 725, 576, and 1340 bytes. `005204A0` has three boundary mismatches.
- The global flag audit reports pre-existing issues outside this module; no
  flag file was changed.

## Blockers

- The assigned `build/source_reunification/terra_system/orchestrator_contract.md`
  is absent from this checkout. The generated packet above is the available
  module packet.
- Seven scratch owners retain codegen, allocation, loop, frame, or
  relocation-target differences. This migration does not claim exactness for
  them.
