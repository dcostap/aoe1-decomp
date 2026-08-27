# TRIBE_Action_Hunt::update (004CF860)

- PDB source: `C:\\msdev\\work\\age1_x1\\tact_hnt.cpp`, lines 384-794.
- The address sequence and class owner prove this body belongs to `tact_hnt.cpp`.
- The natural source remains in `src/tact_hnt.cpp` at its PDB position.
- Status remains `scratch`.

## Current evidence

- The authentic module build emits 1587 bytes and a `0xC` frame.
- The clean reconstruction emits 53 of 54 calls in the expected grouped result.
- The grouped result has 1056 differing bytes.
- The prior isolated baseline had 54 of 54 calls but broad block movement.
- State routing, target ownership, floating globals, and gather transfer order
  follow the original assembly evidence.

## Open difference

The remaining difference is the merged state-12 to state-3 call and its block
layout. The source has no codegen-only forcing, byte filler, or wrapper context.
Resume matching with a new control-flow or compiler-context hypothesis.
