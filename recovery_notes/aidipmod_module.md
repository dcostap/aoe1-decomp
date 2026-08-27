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
normal definitions in PDB source order. It uses the reviewed `AIModule`, player,
world, and virtual-call declarations from `include/aiconmod_context.h`. The
module-local `MainDecisionAIModule` declaration preserves its proven player
member at offset `+0xF0`.

The old wrapper and per-function fragments were structural owners only. The
migration removes them after the direct module entry points to `src/aidipmod.cpp`.

## Status

- 20 owners remain `matching`.
- `0040C5B0 mostLiked` remains `accepted_drift`.
- Its approved difference is a two-byte commutative address-formation swap.
  The behavior, size, branches, direct call, cleanup, and boundary remain equal.
- No source change attempts to force bytes or alter the accepted-drift state.

## Validation

The pre-migration grouped wrapper produced `MATCH` for all 20 registered owners
and the accepted-drift result for `0040C5B0`. Reunified validation must repeat
these checks after the direct source-owner update.
