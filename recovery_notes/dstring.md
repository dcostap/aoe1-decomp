# dstring.cpp source reunification

The module source follows the PDB owner order from lines 31 through 451.
The source uses one compiler-facing owner for all 50 normal functions.

The source came from the existing owner files. The migration removes the wrapper,
fragment includes, repeated fallback class declarations, and context macro.

## Validation record

Before migration, the packet reported 22 registered exact owners and 25 matching
source-bank owners. The remaining 25 owners were scratch.

A fresh grouped compile after migration preserved exact output for these 23 owners:

- 004465D0, 00446620, 00446690, 00446700
- 00446D40, 00446D50, 00446DE0, 00446E00, 00446E90
- 004470B0, 004470C0
- 00447400, 00447410, 00447420, 00447460
- 004474E0, 00447520, 004475A0
- 004475D0, 00447620, 004476A0, 004476F0, 00447760

Each result reported `Result: MATCH`, `0.0000%`, the expected owner symbol,
matching boundaries, and matching relocation targets.

The migration changed two former matching source entries to scratch. Their fresh
results were:

- 00446FD0 nextWord: same 222-byte span, 4 differing bytes, 1.8018 percent.
  The checker reported `REGISTER_MAP_CONFLICT` and first mismatch `+002D`.
- 00447140 subString: same 169-byte span, 1 differing byte, 0.5917 percent.
  The checker reported `REGISTER_MAP_CONFLICT` and first mismatch `+004D`.

The two owners remain in the module source and metadata. They are not registered
as exact translation-unit owners until fresh evidence supports that claim.

The 25 original scratch owners remain scratch. The source now has 23 matching and
27 scratch owners. Custom response files remain because they are reviewed build
inputs, not duplicate source owners.

## ABI repair

The local `istream` model now declares `get` as protected. The extraction
operator is its friend, so VC5 emits the canonical target
`?get@istream@@IAEAAV1@PADHH@Z`.

The operator declaration stays at its PDB source position. Its definition and
the local stream model follow `word`. VC5 changes `word`'s register map when
the protected stream model appears earlier. This placement keeps all 23 exact
anchors unchanged.

The repaired source uses conventional `this->stringValue[index]` indexing.
The original decorated targets for `get`, both DString assignments,
`operator[]`, and `operator char*` are recorded in
`config/original_symbol_overrides.txt`.

The source uses ordinary typed stream state fields. It has no explicit
alignment padding.
