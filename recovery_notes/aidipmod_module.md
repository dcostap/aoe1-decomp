# aidipmod.cpp source-module recovery

## PDB context

- PDB source: `C:\\msdev\\work\\age1_x1\\aidipmod.cpp`.
- The 21 normal owners use source lines 26-442 in PDB source order.
- The address sequence is `0040BEC0`, `0040BF40`, `0040BFF0`, `0040C000`,
  `0040C010`, `0040C0A0`, `0040C100`, `0040C190`, `0040C2B0`, `0040C3B0`,
  `0040C3F0`, `0040C420`, `0040C460`, `0040C4A0`, `0040C4D0`, `0040C5B0`,
  `0040C660`, `0040C6A0`, `0040C6E0`, `0040C730`, and `0040C780`.
- Exact anchors include the direct `AIModule` constructor call at `0040BEDA`,
  the `AIModule` destructor tail jump at `0040BFF6`, the `isEnemy` call at
  `0040C61B`, and the virtual `RGE_Player::isAlly` call in `0040C730`.
- `0040BF20` is the compiler-generated scalar deleting destructor. It is not a
  handwritten normal owner.

## Source ownership

`src/aidipmod.cpp` is the sole compiler-facing source owner. It contains all 21
normal definitions in PDB source order. `include/aidipmod.h` owns only
`DiplomacyAIModule`. It consumes canonical `MainDecisionAIModule`.

The source privately consumes the canonical Player, World, victory, and file
I/O providers. It has no local Main Decision, Player, World, or object layout.

The old wrapper and per-function fragments were structural owners only. The
migration removes them after the direct module entry points to `src/aidipmod.cpp`.

## Status

- 19 owners remain `matching`.
- `0040C100 stance` is `scratch`.
- `0040C5B0 mostLiked` remains `accepted_drift`.
- Its approved difference is a two-byte commutative address-formation swap.
  The behavior, size, branches, direct call, cleanup, and boundary remain equal.
- No source change attempts to force bytes or alter the accepted-drift state.

## Validation

The direct candidate validates 19 registered `MATCH`, `0.0000%` rows. It has
no comparison, ownership, relocation, or boundary error for a registered row.

`0040C100` differs by 19 bytes after canonical typed Player and World access.
It has correct ownership, relocations, and boundaries. The natural source is
kept. The matching claim is removed.

`0040C5B0` now emits `MATCH`, `0.0000%`. It remains accepted drift. This audit
does not reopen its reviewed status.
