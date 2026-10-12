# `aimdmod.cpp` source-module migration

## Ownership

- PDB source: `C:\\msdev\\work\\age1_x1\\aimdmod.cpp`.
- Source: `src/aimdmod.cpp`.
- Header: `include/aimdmod.h`.
- Flags: `config/flags/gx.rsp` (`/O2 /Oy /GX`).
- The module owns 20 normal functions in PDB source order:
  `0040CDF0`, `0040CE90`, `0040D020`, `0040D090`, `0040D0A0`, `0040D180`,
  `0040D250`, `0040D2C0`, `0040D2D0`, `0040D3B0`, `0040D480`, `0040D580`,
  `0040D660`, `0040D760`, `0040D780`, `0040D9D0`, `0040DB20`, `0040DB40`,
  `0040DB50`, and `0040DC30`.
- All owners are `MainDecisionAIModule` members. The module uses the binary-backed
  `AIModule` base at `+0x00`, `player` at `+0xF0`, and the four-word object
  array at `+0xF4`.
- The nearby `0040CE70` vector-deleting destructor is compiler-generated and
  has no standalone source owner.

## Authentic context

- The PDB line bands are 34-35, 43-52, 57-58, 63, 69-77, 82-87, 92-94,
  99-101, 106-116, 121-131, 137-148, 153-163, 169-180, 185-187, 194-213,
  219-235, 240-243, 248-250, 255-265, and 270-295.
- The address sequence follows those bands and remains contiguous through the
  normal owner ranges, with the compiler-generated entry at `0040CE70` before
  the first constructor.
- Exact anchors include the `AIModule::AIModule` call at `0040CEC2` for the
  load constructor, the `rge_read` calls at `0040CF04` and `0040CF2E`, the
  `RGE_Game_World::object` calls in the query methods, the virtual
  `MainDecisionAIModule::canPerformAction` call in `0040D780`, and the
  `AIModule::logCommonHistory` call in `0040DB20`.
- The source has one compiler-facing owner and no source-bank `.cpp` includes,
  context-selection macros, or fallback declaration blocks.
- The module keeps the existing grouped `/GX` flags. Per-function records mix
  default flags and `/GX` overlays, so the repository flag audit reports that
  one module flag set is not proved.

## Recovery state

The natural source module keeps ten `matching` owners and ten `scratch`
owners. The current grouped compile emits exact code for `0040CDF0`. Its old
verified-logic ledger remains useful historical evidence.

The former `src/aimdmod_tu.cpp` wrapper and source-bank owner fragments were
replaced by the one source module. The former context header was renamed to the
module-owned `include/aimdmod.h` header and its context guard was removed.

## Historical migration validation

The pre-migration wrapper recorded exact grouped results for the 19 matching
owners and an observed mismatch for the verified-logic constructor. The final
source-module grouped results are recorded below after the focused audit:

- `audit_translation_unit_functions.py --group aimdmod` compiled one authentic
  source module and included all 20 normal owners.
- The 19 registered matching owners returned `MATCH`, with zero byte
  differences, zero relocation-target mismatches, and zero boundary escapes.
- `0040CDF0` returned a 106-byte mismatch against its 113-byte original. Its
  owner symbol was correct, with zero relocation-target mismatches and zero
  boundary escapes. This is the known VC5 exception-frame difference from its
  verified-logic ledger, not a status promotion.
- A focused `check_function.py --va 0040CE90 --rebuild` check returned
  `Result: MATCH` and `0.0000%`. A standalone check for `0040CDF0` cannot select
  one constructor from the complete TU because both overloaded constructors
  are defined; the grouped audit selected its exact decorated symbol.

These results predate the natural `ManagedArray` and canonical-owner repair.

The repository-wide strict source-module inventory was also attempted. It is
blocked by pre-existing duplicate compiler ownership in `taiuaimd.cpp` and
`aiuaimod.cpp` (`taiuaimd_preditor_prefix` and `aiuaimod_prefix`). No aimdmod
entry caused that failure.

## Canonical engine dependencies

`aimdmod.h` includes only canonical `AIModule` and `ManagedArray` providers.
It forward declares its pointer types. `aimdmod.cpp` privately includes the
canonical Player, World, object, master-object, Unit AI, and file-I/O headers.

The source uses the PDB field `player` at `+0xF0`. It has no `game` alias. It
uses `ManagedArray` methods and indexing. It has no manual array allocation,
capacity expansion, or parameter type alias.

This natural source change demoted `0040CE90`, `0040D0A0`, `0040D2D0`,
`0040D480`, `0040D580`, `0040D660`, `0040D780`, `0040D9D0`, `0040DB50`, and
`0040DC30` to scratch. The current grouped audit compiled all 20 normal rows.
It reports `MATCH`, `0.0000%` for the other ten rows, including `0040CDF0`.
Each registered row has the correct owner, symbol, boundary, and relocations.
