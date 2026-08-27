# tact_trd source module

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\tact_trd.cpp`.
- Source owner: `src/tact_trd.cpp`.
- Class owner: `TRIBE_Action_Trade`, derived from `RGE_Action`.
- Flags: `config/flags/004D2660_TRIBE_Action_Trade.rsp`.
- Context header: `include/tact_trd.h`.
- The PDB line bands and address order are:
  `42-47/004D2660`, `55-70/004D2710`, `77-91/004D27A0`,
  `98-103/004D27F0`, `109-128/004D2830`, `134-275/004D2880`,
  `281-626/004D2CB0`, `632-640/004D32C0`, `646-653/004D32F0`,
  `659-662/004D3330`, `669-690/004D3340`, and `697-727/004D33C0`.
- Exact anchors surround the unresolved body.  The constructor sequence starts
  at `004D2660`, and the helper sequence resumes at `004D32C0`.
- Inventory class references and the prior authentic wrapper identify the same
  virtual surfaces and field offsets.  No synthetic context owner is used.

## Ownership and status

The module has 12 normal owners and 3297 normal bytes.

- Matching: `004D2660`, `004D2710`, `004D27A0`, `004D27F0`, `004D2830`,
  `004D32C0`, `004D32F0`, `004D3330`, `004D3340`, `004D33C0`.
- Accepted drift: `004D2880 set_state`.
- Scratch: `004D2CB0 update`.
- `004D26E0` is a compiler-generated scalar deleting destructor.  It is not a
  handwritten owner and remains outside the source module function list.

## Migration record

The source now holds all 12 normal owners in PDB source order.  The old wrapper,
fragment includes, context macro, and fallback declarations were removed.
The direct exact-owner entries for `tact_trd` now point to `src/tact_trd.cpp`.

The prior grouped candidate check on the authentic wrapper reported:

- Ten matching owners: `MATCH`, 0 differing bytes each.
- Generated destructor: `MATCH`, 0 differing bytes.
- `set_state`: accepted-drift source was not emitted by the candidate comparator.
- `update`: `MISMATCH`, 982 bytes, with matching owner, relocations, and boundary.

The `update` scratch source retains the original frame note and prior evidence.
The `set_state` source retains its accepted-drift evidence.  This migration does
not promote or reopen either status.

## Cross-shard evidence

The neighboring action modules use the same reviewed `RGE_Action` and
`RGE_Action_Object` hierarchy.  The exact anchors in this module also use the
same `RGE_Action::save`, `set_state`, `RGE_Action_Move_To`, and object virtual
surfaces.  The source module metadata records the authentic PDB path, not a
folder-based donor claim.

## Reopening conditions

Reopen `update` only with new source, layout, control-flow, or compiler-context
evidence.  Reopen `set_state` only with evidence that changes its reviewed
localized equivalence or its direct call and relocation identity.
