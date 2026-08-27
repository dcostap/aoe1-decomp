# `taiinfmd.cpp` module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\taiinfmd.cpp`.
- Source: `src/taiinfmd.cpp`.
- Header: `include/taiinfmd.h`.
- Flags: `config/flags/004D6BB0_TribeInformationAIModule.rsp`.
- Normal owners: 123.
- Address range: `004D6AD0` to `004E4790`.

## Module migration

The source follows the PDB owner order from lines 103 through 8574. It has one
compiler-facing source owner and one module-local header. The old wrapper,
fragment includes, fallback declarations, context macro, and per-function
source owners were removed.

The source module manifest records all 123 normal owners. It preserves the
prior source-bank status: 98 matching, 9 accepted drift, and 16 scratch.
Compiler-generated entries `004D6B20`, `004D7050`, `004DE980`, and `004DE9D0`
remain outside the normal owner manifest.

The merged source retains 58 exact registered owners. Owner `004E0FD0` has an
11-byte merged-context regression. It is not in the direct exact-owner entry.

## Context evidence

The original PDB module is `taiinfmd.cpp`. Its source order is the address
sequence listed in the generated packet. The class owner is
`TribeInformationAIModule`, with the first two static initializers and the
constructor/destructor band preceding its methods. The original FPO dump and
nearby compiler-generated entries provide the boundary and ownership anchors.
The module header keeps the reviewed `InformationAIModule`, `ManagedArray`,
`InfluenceMap`, world/player, record, and `TribeInformationAIModule` layouts.

## Validation

The consolidated source compiles with the pinned VC5 compiler and the module
response file. Migration changes the complete source context, so old exact
results from isolated fragment owners are not claims about the merged source.
Run the registered translation-unit checks after each source-shape repair.

A clean compile reported one existing uninitialized-local warning in the
recovered `loadLearnInfo` path. No inline assembly or synthetic owner is used.

## Cross-shard blocker

`src/information_dropsites_tu.cpp` still names the deleted taiinfmd fragment
files and uses `include/taiinfmd_prefix_context.h`. This wrapper is outside the
assigned direct module entry. The parent integration pass must remove or
repoint it before a repository-wide source build.
