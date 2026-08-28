# airesmod canonical dependencies

`ResourceAIModule` has PDB base `AIModule` and size `0x10C`. Its `md` field is
only a `MainDecisionAIModule` pointer.

`include/airesmod.h` includes canonical `aimodule.h` and `airesitm.h`. It owns
only `ResourceAIModule`. It has no local Main Decision or Resource Item layout.

The direct VC5 candidate has 24 exact owners. Each reports `MATCH`, `0.0000%`.
The constructor remains scratch. It differs by 13 bytes with valid ownership,
relocations, and boundaries.
