# aiconmod.cpp source module

## PDB context

- PDB source: `C:\\msdev\\work\\age1_x1\\aiconmod.cpp`.
- The module has 19 normal owners and 4,997 normal bytes.
- Owners follow PDB source-line order from lines 36-599.
- The owning class is `ConstructionAIModule` for all 19 owners.
- The reviewed module header is `include/aiconmod.h`.
- The registered source uses `config/flags/0040AA90_ConstructionAIModule.rsp`.
  The constructor and destructor require the `/GX` exception frame.
- The scalar deleting destructor at `0040AB90` is compiler generated. It has no
  PDB source line and is not a normal source owner.

Exact anchors are `0040AA90`, `0040ABB0`, `0040B120`, `0040B690`, and
`0040BBB0`. The address sequence also confirms the complete source order.

## Source result

The module has one compiler-facing source file: `src/aiconmod.cpp`. It contains
all 19 normal owners in PDB order. It has no wrapper source, `.cpp` include,
or context macro. The module uses one reviewed shared context header.

The prior source banks supplied 17 matching owners and two accepted-drift
owners. The migration keeps these states:

- `0040B1A0` `save`: VC5 places the three private scalar temporaries in
  different stack homes. The 67 writes, values, widths, list traversal,
  boundaries, memory effects, fault order, and return value remain equal.
- `0040B980` `setReferencePoint`: VC5 places two private upper-bound
  temporaries in different stack homes. The x/y calculations, predicates,
  list edits, calls, cleanup, and 495-byte boundary remain equal.

These are localized code-generation differences. They do not change behavior.

## Cross-module context

`aiconmod.h` also supplies the reviewed ConstructionAIModule surface to the
adjacent `aidipmod` module. It reuses the canonical `BaseItem` and `AIModule`
declarations and retains only the narrow PDB-proven player and world views.
The source module owns only the 19 PDB owners listed in its metadata.
