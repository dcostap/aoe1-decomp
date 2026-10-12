# aiconmod.cpp source module

## PDB context

- PDB source: `C:\\msdev\\work\\age1_x1\\aiconmod.cpp`.
- The module has 19 normal owners and 4,997 normal bytes.
- Owners follow PDB source-line order from lines 36-599.
- The owning class is `ConstructionAIModule` for all 19 owners.
- The reviewed module header is `include/aiconmod.h`.
- The registered source uses `config/flags/gx.rsp`.
  The constructor and destructor require the `/GX` exception frame.
- The scalar deleting destructor at `0040AB90` is compiler generated. It has no
  PDB source line and is not a normal source owner.

Exact anchors are `0040AA90`, `0040ABB0`, `0040B120`, `0040B690`, and
`0040BBB0`. The address sequence also confirms the complete source order.

## Source result

The module has one compiler-facing source file: `src/aiconmod.cpp`. It contains
all 19 normal owners in PDB order. It has no wrapper source, `.cpp` include,
or context macro. The module uses one reviewed shared context header.

The registry still labels 17 owners as matching and two as accepted drift.
This re-review did not change those labels.

- `0040B1A0` `save` remains accepted drift. Static review found no behavior
  defect. Its 48 byte differences use different local stack offsets. See
  `workflow/decomp_notes/functions/0040/0040B1A0.md` for instruction evidence and
  unresolved runtime cases.
- `0040B980` `setReferencePoint` now builds to an exact 495-byte match. Its
  source uses two upper-bound scratch locals in comma operands. The source
  form needs root review. See
  `workflow/decomp_notes/functions/0040/0040B980.md` for instruction evidence and
  unresolved runtime cases.

The final module audit is
`build/drift-031-aiconmod/final-audit-final/report.json`. It compiled 19
owners with one job. It found 17 exact matches, one accepted-drift mismatch,
and one exact match that needs review. Four adjacent owners changed bytes or
relocation names; no exact regressions were reported. No linked-image or
runtime checks ran.

## Cross-module context

`aiconmod.h` also supplies the reviewed ConstructionAIModule surface to the
adjacent `aidipmod` module. It reuses the canonical `BaseItem`,
`ConstructionItem`, and `AIModule` declarations. The source module owns only
the 19 PDB owners listed in its metadata.
