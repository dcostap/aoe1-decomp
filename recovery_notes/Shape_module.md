# Shape.cpp module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\Shape.cpp`.
- Source: `src/Shape.cpp`.
- Header: `include/Shape.h`.
- Flags: `config/flags/default.rsp`.

## Context gate

- PDB source module: proved by the PDB packet as `Shape.cpp`.
- Source lines and order: proved by the packet. The 26 normal owners span lines
  53-3243 and remain in increasing address and source order below.
- Owning class: proved by PDB symbols as `TShape` for all 26 owners.
- Address sequence: proved by the packet: `004B8B30`, `004B8B50`, `004B8DD0`,
  `004B8E40`, `004B8F90`, `004B8FB0`, `004B9040`, `004B9070`, `004B9140`,
  `004B9440`, `004B97F0`, `004B98E0`, `004B99F0`, `004B9AF0`, `004B9E20`,
  `004BA1C0`, `004BA550`, `004BA900`, `004BA9E0`, `004BAAF0`, `004BAC00`,
  `004BAF20`, `004BB280`, `004BB5E0`, `004BB770`, `004BB910`.
- Exact anchors: proved by the existing owner symbols, direct call targets,
  field offsets, and the original Shape.cpp assembly. Examples include the
  `TShape::Check_shape` call before each renderer, the `TDrawArea::AlignedWidth`
  call in the raster helpers, and the `ASM*` and `DClipInfo_List` calls in the
  two dispatchers.
- Nearby compiler-generated owners: none in the packet.

## Migration

The module has one source file and one module header. The source keeps all 26
normal definitions in PDB order. It has no wrapper, source-bank include,
function-fragment include, fallback class declaration, recovery context macro,
or helper macro. The old source-bank files are removed after this source is
validated. The module metadata records each prior source status.

The source keeps the reviewed typed Shape records, `TShape` layout, draw-area
layout, packed RLE ownership, and direct external call declarations. It does not
add a new global definition or change a cross-shard declaration.

## Prior state and expected migration effect

The prior `shape` translation-unit entry registered 11 owners. The module
packet reports 12 matching-bank owners and 14 scratch owners. The two matching
owners not in the old registered entry are `004B99F0` and `004BA9E0`. The merged
source is not byte-tuned during this structural migration. Isolated exact
results are not claims about the merged source.

The 14 scratch owners remain unresolved after migration unless fresh grouped
validation proves otherwise. Their open evidence is mainly VC5 local-home,
register, loop, and clipped-RLE topology. The source retains the simplest
reviewed typed reconstructions and does not retain raw address views, volatile
home forcing, inline assembly, or synthetic owners.

## Validation and regressions

Validation is recorded here after the direct translation-unit check. Grouped
mismatches are not exactness or behavior claims.

- Candidate proposal: `build/candidate_tus/Shape.json`.
- The candidate validator is a pre-migration gate. It rejected the post-move
  direct source because it expects each owner in a legacy source-bank include.
  It produced no report. The direct translation-unit validator passed after
  the source move.
- Grouped audit: `build/audits/Shape_migration_final/report.txt`.
- Grouped result: 26 owners compiled. The final rerun after source cleanup has
  11 registered owner matches, 12 grouped mismatches, and three boundary
  reports. The prior 004BAAF0 grouped result was a 2-byte mismatch before this
  migration; the final direct source now matches it.
- Exact grouped owners: `004B8B30`, `004B8DD0`, `004B8E40`, `004B8F90`,
  `004B8FB0`, `004B9040`, `004B9070`, `004B97F0`, `004BA900`, `004BA9E0`,
  and `004BAAF0`.
- Remaining grouped differences are recorded without status promotion. The
  largest strict differences are `004BB910` 1208 bytes, `004BAF20` 788 bytes,
  `004B9E20` 804 bytes, and `004BA1C0` 853 bytes.

## Blockers

- The assigned `build/source_reunification/terra_system/orchestrator_contract.md`
  and its Terra module packet are absent from this checkout. The generated
  `build/tu_plans/Shape_cpp/packet.{json,txt}` is the available module packet.
- The current source contains several unresolved clipped and dithered renderer
  reconstructions. Their prior notes identify broad VC5 frame, home, register,
  and RLE block differences. This migration does not claim exactness for them.
